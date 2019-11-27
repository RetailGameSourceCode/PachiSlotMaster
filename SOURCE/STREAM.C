
#include "common.h"
#include "work.h"

#ifdef dsdsa
#define IS_RGB24		0
#if IS_RGB24 == 1
#define PPW				3/2
#define MODE			3
#else
#define PPW				1
#define MODE			2
#endif
#endif

static int ppw;
#define PPW			ppw

#define SS_END_FRAME	0xffffffff
#define SS_OFFX			0
#define SS_OFFY			0
#define OFY				0
#define bound(val, n)	((((val) - 1) / (n) + 1) * (n))
#define bound16PPW(val)	(bound((val), 16 * PPW))
#define bound16(val)	(bound((val), 16))
typedef struct {
		u_long		*vlcbuf[2];
		int			vlcid;
//		u_short		*imgbuf;
		u_long		*imgbuf;
		RECT		rect[2];
		int			rectid;
		RECT		slice;
		int			isdone;
}DECENV;
static DECENV		HnStrDec;

#define	RING_ADDR	((0x80200000)-(0x0020000)-(0x0010000))
#define	VLC0_ADDR	(RING_ADDR-(0x0010000))
#define	VLC1_ADDR	(RING_ADDR-(0x0020000))
#define	IMG0_ADDR	(VLC1_ADDR-(0x0008000))
#define	IMG1_ADDR	(VLC1_ADDR-(0x0010000))

//static u_short		*HnImgBuff = (u_short*)(SS_TEX_ADRS + (320 / 2 * 256 * 8));
#define SS_RING_CELL	(32)
#define SS_RING_LEN		(SS_RING_CELL * SECTOR_SIZE)


#define STR_MEM

#ifdef STR_MEM
#if 1
static void		*HnStrRing=NULL;
static void		*HnVlcBuf0=NULL;
static void		*HnVlcBuf1=NULL;
static void		*HnImgBuff=NULL;
#endif
#if 0
static u_long		*HnStrRing=NULL;
static u_long		*HnVlcBuf0=NULL;
static u_long		*HnVlcBuf1=NULL;
static u_short		*HnImgBuff=NULL;
#endif
#else
static u_long		*HnStrRing = (u_long *)(RING_ADDR);
static u_long		*HnVlcBuf0 = (u_long *)(VLC0_ADDR);
static u_long		*HnVlcBuf1 = (u_long *)(VLC1_ADDR);
static u_short		*HnImgBuff = (u_short*)(IMG1_ADDR);
#endif

static int			HnRewindSwitch;
static int			HnIsFirstSlice;

static u_long	sframe;			// 開始フレーム
static u_long	eframe;			// 終了フレーム
static u_char	is24bit;		// １：24ビットで描画、０：16ビットで描画

/*	int			SS_str_anim(MOVIE_FILE_INFO *); */
//int SS_str_anim(MOVIE_FILE_INFO *mv);
char movie_on=0;



int			HnGetCdLoc(CdlLOC *loc, char *name);
static void	SS_str_clear(void);
static		HnStrSetDefDecEnv(DECENV *dec, int x0, int y0, int x1, int y1);
static		HnStrSystemInit(CdlLOC *loc, void (*decCallback)(), int (*strCallback)());
static void	HnDecCallback(void);
static		HnStrKickCDROM(CdlLOC *loc);
static		HnStrNextVlc(DECENV *dec);
static		u_long *HnStrGetNextRing(DECENV *dec);
static		HnStrSync(DECENV *dec, int mode);
static		HnDbgCdpSector(void);



//=== ムービーファイル情報の構造体 ===
typedef struct {
	char	*fnam;					// CD-ROM内ファイル名( ディレクトリは M_movie で合成 )
//	int		fpos;					// CD-ROM絶対セクタＩＤ
	int		is24bit;				// １：２４ビットモード再生時、０：１６ビットモード
	u_long	sframe;					// 開始フレーム
	u_short	eframe;					// 終了フレーム－３(※1996.08.19マスター内容確認書 数フレーム残す)
	short	posX, posY;				// ＶＲＡＭ上の座標
	int		scrWidth, scrHeight;	// 解像度ＸＹ
	short	volumes;					// 開始時音量( 終了時に音量をフェードアウト )
	u_short	vol_start_frame;		// 音量開始フレーム指定
	char	warikomi;				// TRUE:割り込みキーで終了する
	u_short	fps;					// [フレーム数／秒]
	u_long	sector_per_frame;		// [セクタ数/フレーム]( トレースして、一番大きな値 )
	char	DispModeChangeSTART;	// 描画モードを変更して、ムービーを再生する場合のスィッチ
	char	DispModeChangeEND;		// 終了後に描画モードが変更になる場合のスィッチ
	char	end_frame_stop;			// 終了後に、最終フレームデータを止め絵として使用
} MOVIE_FILE_INFO;


int HnGetCdLoc(CdlLOC *loc, char *name)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	CdlFILE			file, *stat;
	int				ret;

	stat = CdSearchFile(&file, name);
	if(stat == 0)ret = -1;
	else{
		loc->minute = file.pos.minute;
		loc->second = file.pos.second;
		loc->sector = file.pos.sector;
		ret = 0;
	}
	return(ret);
#endif
}


int SS_str_anim(MOVIE_FILE_INFO *mv)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	CdlFILE			file;
	static CdlLOC	loc;
//	u_char			param[8];
	int				id;
	DISPENV			disp;
	DRAWENV			draw;
	int				ret = 0;

	sframe=mv->sframe;
	eframe=mv->eframe;
	is24bit=mv->is24bit;
	if(is24bit)	ppw=(3/2);
	else		ppw=1;

#ifdef STR_MEM
	HnStrRing	= (u_long*)memalloc(SS_RING_LEN*8,(void**)&HnStrRing);
 	HnVlcBuf0	= (u_long*)memalloc(0x0010000,(void**)&HnVlcBuf0);
 	HnVlcBuf1	= (u_long*)memalloc(0x0010000,(void**)&HnVlcBuf1);
	HnImgBuff	= (u_short*)memalloc(0x0010000,(void**)&HnImgBuff);
#endif
	SetDispMask(0);
	SS_str_clear();
	DrawSync(0);
	VSync(4);
	HnIsFirstSlice = 1;

	if(HnGetCdLoc(&loc,mv->fnam) != 0)return(-1);

	SsSetSerialVol( SS_SERIAL_A/* CD入力 */,127, 127);

	HnStrSetDefDecEnv(&HnStrDec, SS_OFFX * PPW, SS_OFFY, SS_OFFX * PPW, 240 + SS_OFFY);
	HnStrSystemInit(&loc, HnDecCallback, 0);
	HnStrNextVlc(&HnStrDec);
	while(1){
		DecDCTin(HnStrDec.vlcbuf[HnStrDec.vlcid], is24bit+2);
		DecDCTout(HnStrDec.imgbuf, bound16PPW(HnStrDec.slice.w) * bound16(HnStrDec.slice.h) / 2);
		HnStrNextVlc(&HnStrDec);
		HnStrSync(&HnStrDec,0);
//		wait(1);
		pad_read();
		VSync(4);
		id = HnStrDec.rectid? 0 : 1;
		SetDefDispEnv(&disp, HnStrDec.rect[id].x, HnStrDec.rect[id].y, HnStrDec.rect[id].w, HnStrDec.rect[id].h);          
		id = id? 0 : 1;
		SetDefDrawEnv(&draw, HnStrDec.rect[id].x, HnStrDec.rect[id].y, HnStrDec.rect[id].w, HnStrDec.rect[id].h);          
		if(is24bit){
			disp.isrgb24 = is24bit;
			disp.disp.w = disp.disp.w * 2 / 3;
		}
		PutDispEnv(&disp);
		PutDrawEnv(&draw);
		SetDispMask(1);
		if(HnRewindSwitch == 1)break;

		if(mv->warikomi){
			if((pad_cnt & PADR_RIGHT) || (pad_cnt & PAD_START))	break;
//			if(pad_cnt & PAD_START) break;
		}
	}
	wait(1);

    CdControl(CdlStop, 0, 0);
    DecDCToutCallback(0);
    CdDataCallback(0);
    CdReadyCallback(0);

#ifdef STR_MEM
	memfree((void**)&HnImgBuff);
	memfree((void**)&HnVlcBuf1);
	memfree((void**)&HnVlcBuf0);
	memfree((void**)&HnStrRing);
#endif
    return(ret);
#endif
}


static void SS_str_clear(void)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	RECT			rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = 480;
	rect.h = 240;
	ClearImage(&rect, 0, 0, 0);
	rect.x = 0;
	rect.y = 240;
	rect.w = 480;
	rect.h = 240;
	ClearImage(&rect, 0, 0, 0);
	DrawSync(0);
#endif
}


static  HnStrSetDefDecEnv(DECENV *dec, int x0, int y0, int x1, int y1)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	dec->vlcbuf[0] = (u_long *)HnVlcBuf0;
	dec->vlcbuf[1] = (u_long *)HnVlcBuf1;
	dec->vlcid = 0;
	dec->imgbuf = (u_long *)HnImgBuff;

	dec->rectid = 0;
	dec->isdone = 0;
	setRECT(&dec->rect[0], x0, y0, x1, y1);
	setRECT(&dec->rect[1], x1, y1, x1, y1);
	setRECT(&dec->slice, x0, y0 + OFY, 16 * PPW, y1);
#endif
}


static  HnStrSystemInit(CdlLOC *loc, void (decCallback)(), int (strCallback)())
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	u_long			*addr=(u_long*)HnStrRing;

	DecDCTReset(0);
	HnRewindSwitch = 0;
	DecDCToutCallback(decCallback);
	StSetRing(addr, SS_RING_CELL);
	StSetStream(is24bit, 1, 0xffffffff, 0, 0);
	HnStrKickCDROM(loc);
#endif
}


static void HnDecCallback(void)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	int				id;
	int				mod;
	extern StCdIntrFlag;

	if(is24bit){
		if(StCdIntrFlag){
			StCdInterrupt();
			StCdIntrFlag = 0;
		}
	}
	LoadImage(&HnStrDec.slice, (u_long *)HnStrDec.imgbuf);
	if(HnIsFirstSlice && (mod = HnStrDec.rect[HnStrDec.rectid].w % (16 * PPW))){
		HnStrDec.slice.x += mod * PPW;
		HnIsFirstSlice = 0;
	}
	else{
		HnStrDec.slice.x += 16 * PPW;
		HnIsFirstSlice = 0;
	}
	if(HnStrDec.slice.x < HnStrDec.rect[HnStrDec.rectid].x + HnStrDec.rect[HnStrDec.rectid].w){
		DecDCTout(HnStrDec.imgbuf, bound16PPW(HnStrDec.slice.w) * bound16(HnStrDec.slice.h) / 2);
	}
	else{
		HnStrDec.isdone = 1;
		HnIsFirstSlice  = 1;
		HnStrDec.rectid = HnStrDec.rectid? 0 : 1;
		id = HnStrDec.rectid;
		HnStrDec.slice.x = HnStrDec.rect[id].x;
		HnStrDec.slice.y = HnStrDec.rect[id].y + OFY;
	}
#endif
}


static HnStrKickCDROM(CdlLOC *loc)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	while(CdControl(CdlSeekL,(u_char*)loc, 0) == 0);
    while(CdRead2(CdlModeStream | CdlModeSpeed | CdlModeRT) == 0);
#endif
}


static HnStrNextVlc(DECENV *dec)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	int				cnt = WAIT_TIME;
	u_long			*next;

	while((next = HnStrGetNextRing(dec)) == 0){
		if(--cnt == 0){
			return(0);
		}
	}
	dec->vlcid = dec->vlcid? 0 : 1;
	DecDCTvlc(next, dec->vlcbuf[dec->vlcid]);
	StFreeRing(next);
	return(0);
#endif
}



static u_long *HnStrGetNextRing(DECENV *dec)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	u_long			*addr;
	StHEADER		*sector;
	int				cnt = WAIT_TIME;
	static int		width = 0;
	static int		height = 0;
	RECT			rect;

	while(StGetNext(&addr,(u_long**) & sector)){
		if(--cnt == 0){
			return(0);
		}
	}
	if(sector->frameCount >= eframe-1){
		HnRewindSwitch = 1;
	}
	if(width != sector->width || height != sector->height){
		/* SS_str_clear(); */
		width = sector->width;
		height = sector->height;
	}
	dec->rect[0].w = dec->rect[1].w = width * PPW;
	dec->rect[0].h = dec->rect[1].h = height;
	dec->slice.h = height;

	return(addr);
#endif
}


static HnStrSync(DECENV *dec, int mode)
{
#ifndef MOVIE_CUT		//	ムービーをカットする
	volatile u_long	cnt = WAIT_TIME;
	int				id;

	while(dec->isdone == 0){
		if(--cnt == 0){
			dec->isdone = 1;
			dec->rectid = dec->rectid? 0 : 1;
			id = dec->rectid;
			dec->slice.x = dec->rect[id].x;
			dec->slice.y = dec->rect[id].y;
		}
	}
	dec->isdone = 0;
#endif
}

int str_title(void)
{
#ifndef MOVIE_CUT		//	ムービーをカットする 
	MOVIE_FILE_INFO	move_title_ = {
		"\\MOVIE\\TITLE.STR;1",	// file name 
//		ATITLE_STR_N,		// 絶対セクタ 
		FALSE,			// ２４ｂｉｔ描画 
		1,			// 開始フレーム 
		734-1, /*BLACK_OUT 1700*/	// 終了フレーム 
		0,0,			// Ｘ，Ｙ座標 
		320, 240,		// 表示領域 
		0,			// 開始時のボリューム 
		1,			// 音量設定開始フレーム 
		TRUE,			// キー割り込みで終了？ 
		15,				// [フレーム数/秒] 
		15,				// [セクタ数/フレーム] 
		FALSE,			// 再生開始時、描画モード切り替え 
		FALSE,			// 再生終了時、描画モード切り替え 
		FALSE,			// 最終フレームデータを止め絵として使用 
	};

	SS_str_anim(&move_title_);
#endif
}

void movie_main(int no)
{
#ifndef MOVIE_CUT		//	ムービーをカットする

	int	(*str_pt[])(void)={
		str_title,		//	タイトル 
	};
	movie_on=1;
	VSync(4);
	(*str_pt[0])();
	VSync(4);
	movie_on=0;
#endif
}

