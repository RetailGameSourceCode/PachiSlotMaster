#include "common.h"
#include "libmcrd.h"
#include "work.h"
//#include "sys_ico.h"
#include "kap_ico.h"
#include "bin_ico.h"
#include "title.h"
#include "submenu.h"

//		swp->secp = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, 8 + FNT_W * 15, 176 + 8, 15, datasave);

char slf=0; //ロードされたか？
char slc;	// セーブかロードか？ 0=LOAD
char aul_ok;
char memc_unfm=0;

int mc_mode=0;
char slpad_m=0;
#if 0
struct DIRENTRY {
name[20]	ファイル名
attr		属性（ファイルシステムに依存）
size		ファイルサイズ（バイト単位）
*next		次のファイルエントリ（ユーザ用）
head		先頭セクタ
system[4]	システム予約
}
#endif
struct DIRENTRY dirent[15];
struct DIRENTRY dirent2[15];

long alf;
long alf2;

#define OT_CRSL (50)
/* スィッチ・コメントの(n)は推奨 */
#define FORMATAUTOSAVE	(1)		/* (1)フォーマット後オートセーブ */
#define BLOCKFULLTEST	(1)		/* (1)ブロックがないかどうか最初にチェック */
#define IFEXISTDELETE	(0)		/* (0)存在するときわざわざ消す？ */

#define SVDT_VERSION	(0x02)	/* セーブデータバージョン */

/* ============================================ */
#define MCRD_PORT (0x00)	/* 使用するポート */
#define MCRD_SIZE (8192)	/* カードのサイズ */
#define MCRD_SECT (128)		/* カードの１セクタサイズ */

#define FILES 3
#define ICONS 3
typedef struct {			/*ヘッダー部分*/
	char magic[2];			/*常に'SC'*/
	char type[1];			/*アイコンイメージ数,0x11/0x12/0x13*/
	char slot[1];			/*スロット数（ブロック数）*/
	char string[64];		/*文書名*/
	char pad[28];			/*ダミー（all zoro）*/
	u_char clut[32];			/*アイコンclut*/
	u_char icon[ICONS][128];	/*アイコンpixel*/
} MCRDHEAD;

typedef struct {			/*ヘッダー部分*/
	char magic[2];			/*常に'SC'*/
	char type[1];			/*アイコンイメージ数,0x11/0x12/0x13*/
	char slot[1];			/*スロット数（ブロック数）*/
	char string[64];		/*文書名*/
	char pad[28];			/*ダミー（all zoro）*/
	u_char clut[32];			/*アイコンclut*/
	u_char icon[128];	/*アイコンpixel*/
} MCRDHEAD1;


static MCRDHEAD mcrdhead={	/*カードヘッダー*/
	{'S','C',},				/*常に'SC'*/
	{0x13,},				/*アイコンイメージ数,0x11/0x12/0x13*/
	{0x01,},				/*スロット数（ブロック数）*/
	{"パチスロマスター　ＳａｍｍｙＳＰ　トータルデータ　　　　　　　　",},	/*文書名*/
//	{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",},	/*文書名*/
//	{"　　　　　　　　　　　　　　　　",},	/*文書名*/
	{0},					/*ダミー（all zoro）*/

	{						/*アイコンclut*/
	0x00,0x00,0xA9,0x00,
	0x67,0x00,0xAA,0x00,
	0xFF,0x4F,0x84,0x00,
	0xBF,0x37,0xA6,0x00,
	0x0A,0x05,0x7D,0x0E,
	0x6D,0x09,0xD2,0x05,
	0x17,0x02,0xFF,0x12,
	0xDF,0x12,0x96,0x01,

	},{

	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0xA2,0xEC,
	0xCE,0x2A,0x00,0x00,
	0x00,0x20,0x4C,0x64,
	0xDD,0xCD,0x02,0x00,
	0x00,0xC2,0x46,0x64,
	0xDD,0xDE,0x2C,0x00,
	0x00,0xDA,0x6D,0xD6,
	0xDD,0xED,0xAD,0x00,
	0x00,0xCC,0xFF,0xFC,
	0xCC,0xFF,0xCF,0x00,
	0x00,0xED,0xDD,0xDC,
	0xCD,0xDE,0xDF,0x00,
	0x00,0xED,0xFD,0xDE,
	0xEF,0xFD,0xDE,0x00,
	0x00,0xDC,0xEF,0xFD,
	0xDE,0xEF,0xCE,0x00,
	0x00,0xDA,0xEF,0xFD,
	0xDE,0xEF,0xAD,0x00,
	0x00,0xC2,0xED,0xEE,
	0xEE,0xDE,0x2C,0x00,
	0x00,0x20,0xDC,0xEE,
	0xEE,0xCD,0x02,0x00,
	0x00,0x00,0xA2,0xEC,
	0xCE,0x2A,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x50,
	0x01,0x00,0x00,0x00,
	0x00,0x00,0x00,0xCA,
	0x79,0x00,0x00,0x00,
	0x00,0x00,0xA0,0xDD,
	0x9F,0x07,0x00,0x00,
	0x00,0x00,0xD0,0x99,
	0xFD,0x0C,0x00,0x00,
	0x00,0x00,0xD7,0x99,
	0xFD,0x59,0x00,0x00,
	0x00,0x00,0xD8,0x99,
	0xFD,0x79,0x00,0x00,
	0x00,0x00,0xDA,0x99,
	0xFD,0x79,0x00,0x00,
	0x00,0x00,0xDA,0x99,
	0xFD,0x79,0x00,0x00,
	0x00,0x00,0x98,0x99,
	0xF9,0x79,0x00,0x00,
	0x00,0x00,0xC5,0x99,
	0xFD,0x09,0x00,0x00,
	0x00,0x00,0xB0,0x99,
	0xFD,0x0C,0x00,0x00,
	0x00,0x00,0x80,0xD9,
	0xCF,0x07,0x00,0x00,
	0x00,0x00,0x00,0xFA,
	0x8C,0x00,0x00,0x00,
	0x00,0x00,0x00,0x50,
	0x01,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x10,
	0x02,0x00,0x00,0x00,
	0x00,0x00,0x00,0xD7,
	0xAF,0x00,0x00,0x00,
	0x00,0x00,0x10,0xFD,
	0xCD,0x0A,0x00,0x00,
	0x00,0x00,0xD0,0xDF,
	0x99,0x1C,0x00,0x00,
	0x00,0x00,0xD0,0xDF,
	0x99,0x7C,0x00,0x00,
	0x00,0x00,0xD1,0xDF,
	0x99,0x8C,0x00,0x00,
	0x00,0x00,0xD2,0xDF,
	0x99,0xAC,0x00,0x00,
	0x00,0x00,0xD2,0xDF,
	0x99,0xAC,0x00,0x00,
	0x00,0x00,0xD1,0x9F,
	0x99,0x8C,0x00,0x00,
	0x00,0x00,0x90,0x9F,
	0x99,0x5C,0x00,0x00,
	0x00,0x00,0xB0,0x9F,
	0xC9,0x0C,0x00,0x00,
	0x00,0x00,0x50,0xFC,
	0xCC,0x08,0x00,0x00,
	0x00,0x00,0x00,0xC8,
	0xAF,0x00,0x00,0x00,
	0x00,0x00,0x00,0x10,
	0x02,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	}
};

char strings[2][64]={
	{"パチスロマスター　かっぱっぱ　　　Ｎｏ．　　　　　　　　　　　回",},	/*文書名*/
	{"パチスロマスター　Ｂｉｎ貧神さま　Ｎｏ．　　　　　　　　　　　回",},	/*文書名*/
};

static MCRDHEAD1 mcrdhead1={	/*カードヘッダー*/
	{'S','C',},				/*常に'SC'*/
	{0x11,},				/*アイコンイメージ数,0x11/0x12/0x13*/
	{0x01,},				/*スロット数（ブロック数）*/
	{"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",},	/*文書名*/
	{0},					/*ダミー（all zoro）*/

	{						/*アイコンclut*/
	0x00,0x00,0xA9,0x00,
	0x67,0x00,0xAA,0x00,
	0xFF,0x4F,0x84,0x00,
	0xBF,0x37,0xA6,0x00,
	0x0A,0x05,0x7D,0x0E,
	0x6D,0x09,0xD2,0x05,
	0x17,0x02,0xFF,0x12,
	0xDF,0x12,0x96,0x01,

	},{

	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0xA2,0xEC,
	0xCE,0x2A,0x00,0x00,
	0x00,0x20,0x4C,0x64,
	0xDD,0xCD,0x02,0x00,
	0x00,0xC2,0x46,0x64,
	0xDD,0xDE,0x2C,0x00,
	0x00,0xDA,0x6D,0xD6,
	0xDD,0xED,0xAD,0x00,
	0x00,0xCC,0xFF,0xFC,
	0xCC,0xFF,0xCF,0x00,
	0x00,0xED,0xDD,0xDC,
	0xCD,0xDE,0xDF,0x00,
	0x00,0xED,0xFD,0xDE,
	0xEF,0xFD,0xDE,0x00,
	0x00,0xDC,0xEF,0xFD,
	0xDE,0xEF,0xCE,0x00,
	0x00,0xDA,0xEF,0xFD,
	0xDE,0xEF,0xAD,0x00,
	0x00,0xC2,0xED,0xEE,
	0xEE,0xDE,0x2C,0x00,
	0x00,0x20,0xDC,0xEE,
	0xEE,0xCD,0x02,0x00,
	0x00,0x00,0xA2,0xEC,
	0xCE,0x2A,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,
	}
};



static char mcrd_filename[3][21]={	/*カードファイル名*/
{
	"BISLPS-01927SYSTEM  ",
//	"BISLPS-01234ABCDEFGH",
},
{
	"BISLPS-01927K       ",
//	"BISLPS-01234ABCDEFGH",
},
{
	"BISLPS-01927B       ",
//	"BISLPS-01234ABCDEFGH",
},
};

static char mcrd_filenames[21]={	/*カードファイル名*/
	"*                   ",
};

/* ============================================ */
//static int w_sel;
//static int w_pos;
//static int sv_s;
#if 0
struct	_SVLD_MES{
	WINDOW	*wp;
	int		counter;
};
typedef	struct	_SVLD_MES	SVLD_MES;
SVLD_MES	*slm = NULL;

enum {
	FID_NAME0,
	FID_NAME1,
	FID_NAME2,
	FID_STAGE,
	FID_DAY,
	FID_MSG,
	FID_MAX,
};
static int f_id[FID_MAX];

/* ============================================ */

#define SYS_SAVE	(128)
#define KAP_SAVE	(1)
#define BIN_SAVE	(2)
#endif

typedef struct {	/* ファイル情報 */
	int f;			/* data exist 1:kappa 2:binbin 128:system*/
} SVLDINFO;

typedef struct {	/* メモリーカード内容 */
	MCRDHEAD head;	/* ファイルヘッダ */
	short rnd;		/* ファイル復活防止用 */
	short cnt;		/* ファイル復活防止用 */
	SVLDINFO info;	/* ファイル情報 */
	SAVE1 game_lst;	/* データ */
	short sum;		/* チェックサム(全体) */
} SVLDDATA0;


typedef struct {	/* メモリーカード内容 */
	MCRDHEAD1 head;	/* ファイルヘッダ */
	short rnd;		/* ファイル復活防止用 */
	short cnt;		/* ファイル復活防止用 */
	SVLDINFO info;	/* ファイル情報 */
	SAVE2 game_lst;	/* データ */
	short sum;		/* チェックサム(全体) */
} SVLDDATA1;


static SVLDDATA0 *sv0=NULL; /* データ内容ワーク */
static SVLDDATA1 *sv1=NULL; /* データ内容ワーク */

static int exist;	 /* ファイル存在 */
u_long cmds;
u_long result=100;
u_long result2=32;	/* ＭＣＲＤ返り値用 */


static SVLDINFO *inf;
static int sys_p;
static char inf_max;

/* ============================================ */
/* ============================================ */
/* ============================================ */
#define FCMAX 4	/* ラインカーソル使用ＰＯＬＹ数 */
static LINE_F3  *f3[FCMAX];
static int cursolf;
static void cursol_init(void)
{	/* ラインカーソルの初期化 */
	int i;

	if (!cursolf) {
		for (i=0;i<FCMAX;i++) {
			f3[i]=line_f3_make();
			get_polylst(f3[i])->pri=OT_CRSL;
			setRGB0(f3[i],200,200,0);
		}
		cursolf=1;
	}
}

static void cursol_drv(int sc_csl)
{	/* ラインカーソル表示更新 */
	int i,j,r;
	static int xywh[5]={ /* x,y,w,h,yofs */
		18-160-4,78-120,(16*9)+4,20,32,
	};
	if (cursolf) for (j=0;j<2;j++) {
		i=j*2;
		setXY3(f3[i],	xywh[0]+j,		  xywh[1]		 -j+xywh[4]*sc_csl,
						xywh[0]+xywh[2]-j,xywh[1]		 -j+xywh[4]*sc_csl,
						xywh[0]+xywh[2]-j,xywh[1]+xywh[3]+j+xywh[4]*sc_csl);
		setXY3(f3[i+1],	xywh[0]+xywh[2]-j,xywh[1]+xywh[3]+j+xywh[4]*sc_csl,
						xywh[0]+j,		  xywh[1]+xywh[3]+j+xywh[4]*sc_csl,
						xywh[0]+j,		  xywh[1]		 -j+xywh[4]*sc_csl);
	}
}

static void cursol_kill(void)
{	/* ラインカーソルの終了 */
	int i;
	if (cursolf) {
		for (i=0;i<FCMAX;i++) poly_kill(f3[i]);
	}
	cursolf=0;
}

/* ============================================ */
/* セレクト用カーソル */
static LINE_F3  *f2[FCMAX];
static int cursolf2;
static void cursol_init2(void)
{	/* ラインカーソルの初期化 */
	int i;

	if	(!cursolf2) {
		for (i=0;i<FCMAX;i++) {
			f2[i]=line_f3_make();
			get_polylst(f2[i])->pri=OT_CRSL;
			setRGB0(f2[i],200,200,0);
		}
		cursolf2=1;
	}
}

static void cursol_drv2(int sel)
{	/* ラインカーソル表示更新 */
	int i,j,r;
	static int xywh[5]={ /* x,y,w,h,xofs */
		28,78,(16*3)+4,20,56,
	};
	if	(cursolf2) {
	 for (j=0;j<2;j++) {
		i=j*2;
		setXY3(f2[i],	xywh[0]+j		 +sel*xywh[4],xywh[1]		 -j,
						xywh[0]+xywh[2]-j+sel*xywh[4],xywh[1]		 -j,
						xywh[0]+xywh[2]-j+sel*xywh[4],xywh[1]+xywh[3]+j);
		setXY3(f2[i+1],	xywh[0]+xywh[2]-j+sel*xywh[4],xywh[1]+xywh[3]+j,
						xywh[0]+j		 +sel*xywh[4],xywh[1]+xywh[3]+j,
						xywh[0]+j		 +sel*xywh[4],xywh[1]		 -j);
	 }
	}
}
static void cursol_kill2(void)
{	/* ラインカーソルの終了 */
	int i;
	if	(cursolf2) for (i=0;i<FCMAX;i++) poly_kill(f2[i]);
	cursolf2=0;
}

/* ============================================ */
char meminit=0;
static void w_mcrdinit()
{	/* mcrd使用開始 */
	if(!meminit){
		MemCardStart(); /* mcrd稼動開始 */
		meminit=1;
	}
}

static void w_mcrdend()
{	/* mcrd終了 */
	if(meminit){
		MemCardStop();	/* mcrd停止 */
		meminit=0;
	}
}


//	メモリカード使用開始処理
void w_init(void)
{
	w_mcrdinit();	/* mcrd使用開始 */
}

//	メモリカード使用終了処理
void w_exit(void)
{
	w_mcrdend();	/* mcrd終了 */
}

/* =====================================================================
   ===================================================================== */
/* =====================================================================
   ===================================================================== */

/* ============================================ */
/* sequence                                     */
/* ============================================ */

void sl_wait(int wt)
{
	char slb;
	slb=slpad_m;
	slpad_m=0;
	pad_toreruyo(1);
	wait2(wt);
	slpad_m=slb;

}


char yes_no_chk(void)
{
	char ck;
	char css=0;
	wind_w=0;
	pad_toreruyo(1);
	call_yn_panel(16,64);
	while(yn_sts!=0) sl_wait(1);
	sl_wait(60);
	pad_toreruyo(0);
	while(yn_sts==0){
		css=(css+1)%60;
		if(!css){
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			if(result!=McErrNotFormat){
				pad_toreruyo(1);
				save_data_clear();
				del_yn_panel();
				while(yn_sts!=-1)	sl_wait(1);
				sl_wait(60);
				wind_w=0;
				return(2);
			}
		}
		wait(1);
	}
	pad_toreruyo(1);
	if(yn_sts==1){
		ck=1;
		_SE_OK
	}
	else{
		ck=0;
		_SE_CANCEL
	}
	del_yn_panel();
	while(yn_sts!=-1) sl_wait(1);
	sl_wait(60);
	wind_w=0;
	return (ck);
}


char sv_b[4][15];

void save_data_clear(void)
{
	memset(&mc_data, 0,sizeof(M_CARD));	//	トータルデータのクリア
//	wait(30);
	memset(&dirent, 0,sizeof(struct DIRENTRY));	//	トータルデータのクリア
//	wait(30);
	memset(&dirent2, 0,sizeof(struct DIRENTRY));	//	トータルデータのクリア
//	wait(30);
	check_cardf=0;
	result=100;
	result2=99;
	memc_unfm=0;
//	slpad_m=1;
}


void save_data_set(void)
{
	int lp,lp2,lp3;
	int chk;
	int gd=0;

	for(lp2=0;lp2<3;lp2++){
		for(lp=0;lp<15;lp++){
			 sv_b[lp2][lp]=0;
		}
	}
	for(lp=0;lp<15;lp++)	 sv_b[3][lp]=0xFF;
	alf2=0;
	memset(&mc_data, 0,sizeof(M_CARD));	//	トータルデータのクリア

	for(lp=0;lp<alf;lp++){
		chk=0;
		for(lp2=0;lp2<12;lp2++){
			if(dirent[lp].name[lp2]!=mcrd_filename[0][lp2]) chk=1;
		}
		if(chk==0){ /* セーブデータ有り*/
			switch(dirent[lp].name[12]){
				case 'S':
					mc_data.max_total+=1;
					sv_b[0][lp]=1;
					sv_b[1][lp]=' ';
					sv_b[2][lp]='0';
					sv_b[3][lp]=0;
	bcopy((char *)&dirent[lp],(char *)&dirent2[0],sizeof(struct DIRENTRY));
				break;
				case 'K':
					mc_data.max_kapp+=1;
					sv_b[0][lp]=2;
					sv_b[1][lp]=dirent[lp].name[13];
					sv_b[2][lp]=dirent[lp].name[14];
					if(dirent[lp].name[13]!=' ') sv_b[3][lp]=10;
					else						sv_b[3][lp]=0;
					sv_b[3][lp]+=dirent[lp].name[14]-'0';
				break;
				case 'B':
					mc_data.max_kami+=1;
					sv_b[0][lp]=3;
					sv_b[1][lp]=dirent[lp].name[13];
					sv_b[2][lp]=dirent[lp].name[14];
					if(dirent[lp].name[13]!=' ') sv_b[3][lp]=10;
					else						sv_b[3][lp]=0;
					sv_b[3][lp]+=dirent[lp].name[14]-'1';
				break;
			}
/*			sv_b[1][lp]=dirent[lp].name[13];
			sv_b[2][lp]=dirent[lp].name[14];
			if(dirent[lp].name[13]!=' ') sv_b[3][lp]=10;
			sv_b[3][lp]+=dirent[lp].name[14]-'0';
*/
		}else{
			mc_data.max_hoka+=(dirent[lp].size/MCRD_SIZE);
					sv_b[0][lp]=4;
		}
	}
	for(lp=0;lp<15;lp++)	mc_data.card_use[lp]=0;

	if(mc_data.max_total){
		mc_data.card_use[0]=1;
	}
	if(mc_data.max_kami){
		for(lp=0;lp<mc_data.max_kami;lp++){
			mc_data.card_use[mc_data.max_total+lp]=3;
		}
		lp2=0;
		for(lp=0;lp<alf;lp++){
			if(sv_b[0][lp]==3){
bcopy((char *)&dirent[lp],(char *)&dirent2[mc_data.max_total+lp2],sizeof(struct DIRENTRY));
			lp2+=1;
			}
		}
	}
	if(mc_data.max_kapp){
		for(lp=0;lp<mc_data.max_kapp;lp++){
		 mc_data.card_use[mc_data.max_total+mc_data.max_kami+lp]=2;
		}
		lp2=0;
		for(lp=0;lp<alf;lp++){
			if(sv_b[0][lp]==2){
bcopy((char *)&dirent[lp],(char *)&dirent2[mc_data.max_total+mc_data.max_kami+lp2],sizeof(struct DIRENTRY));
				lp2+=1;
			}
		}
	}
	if(mc_data.max_hoka){
		for(lp=0;lp<mc_data.max_hoka;lp++) mc_data.card_use[14-lp]=4;
	}
	mc_data.max_aki=15-(mc_data.max_hoka+mc_data.max_total+mc_data.max_kami+mc_data.max_kapp);
}

//	簡単なチェックのみ
static int chk_mcard(void)
{
	u_long results;

	MemCardExist(MCRD_PORT);		/* PORT 0 */
	MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
	MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
	MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
	MemCardExist(MCRD_PORT);		/* PORT 0 */
	MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
	return (result);

}


char sy=0;
static int check_cards2(int type)
{
	int ret=0;
	int lp;
	int lp2;
	static int ret2;


	MemCardExist(MCRD_PORT);		/* PORT 0 */
	MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
	if(result2==result)	return(0);
	if(memc_unfm==1){
		if(result!=McErrCardNotExist)
		return;
	}

	switch(result){
		case McErrNewCard :		/*新規カード（カードが交換された） */
			slpad_m=1;
			save_data_clear();
			mc_mess_(DEF_MEM00); /*メモリカードを調べています*/
			sl_wait(2);
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			if(result==McErrNone){
				result2=result;
				MemCardGetDirentry(MCRD_PORT,mcrd_filenames,&dirent[0],&alf,0,15);
				save_data_set();
				check_cardf=1;
				ret=0;
				sl_wait(120);
				return(ret);
			}
			sl_wait(120);
		break;
		case McErrNone:			/*接続されている */
			save_data_clear();
			mc_mess_(DEF_MEM00); /*メモリカードを調べています*/
			sl_wait(2);
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			if(result==McErrNone){
				sl_wait(120);
				result2=result;
				MemCardGetDirentry(MCRD_PORT,mcrd_filenames,&dirent[0],&alf,0,15);
				save_data_set();
				check_cardf=1;
				return(ret);
			}
			sl_wait(120);
		break;
		case McErrCardNotExist:	/*接続されていない */
			slpad_m=1;
			mc_mess_(DEF_MEM02); /*メモリカードがささっていません*/
			sl_wait(60);
			save_data_clear();
			ret=-1;
			return(ret);
		break;
		case McErrCardInvalid:	/*不良カード */
			/* 詳細情報の取得 */
			save_data_clear();
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			ret=-1;
		break;
	}

	alf=0;
	alf2=0;
/*エラー詳細*/
	result2=result;
	switch(result){
		case McErrNone: /* 接続されている */
			check_cardf=0;
			mc_mess_(DEF_MEM00); /*メモリカードを調べています*/
			sl_wait(120);
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			MemCardGetDirentry(MCRD_PORT,mcrd_filenames,&dirent[0],&alf,0,15);
			save_data_set();
			check_cardf=1;
			return(ret);
		break;
		case McErrCardNotExist:	/* 接続されていない */
			slpad_m=1;
			mc_mess_(DEF_MEM02); /*メモリカードがささっていません*/
			sl_wait(60);
			save_data_clear();
			ret=-1;
			return(ret);
		break;
		case McErrCardInvalid:	/* 不良カード */
			mc_mess_(DEF_MEM01);
			sl_wait(4);
			save_data_clear();
			ret=-1;
		break;
		case McErrNewCard: 		/* 新規カード（カードが交換された） */
			slpad_m=1;
			save_data_clear();

			mc_mess_(DEF_MEM00); /*メモリカードを調べています*/
			sl_wait(120);
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
			MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
			result2=result;
			if(result==McErrNone){
				MemCardGetDirentry(MCRD_PORT,mcrd_filenames,&dirent[0],&alf,0,15);
				save_data_set();
				check_cardf=1;
				ret=0;
				return(ret);
			}
		break;
		case McErrNotFormat:	/* フォーマットされていない */
			mc_mess_(DEF_MEM03);	/*メモリカードがフォーマットされていません*/
			for(lp2=0;lp2<40;lp2++){
				if(!(lp2%8)){
					MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
					MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
					if(result!=McErrNotFormat){
						save_data_clear();
						slpad_m=1;
						return;
					}
				}
				sl_wait(1);
			}
			if(!slc){	/* ロードの時 */
				mc_mess_(DEF_MEM29);	/*セーブデータがありません*/
				sl_wait(2);
				memc_unfm=1;
				return;
			}
			slpad_m=0;
			mc_mess_(DEF_MEM04);	/*メモリカードをフォーマットしますか？*/
			ret=yes_no_chk();
			if(ret){
				if(ret==2){	//	カード抜かれた
					slpad_m=1;
					save_data_clear();
					return;
				}
				mc_mess_(DEF_MEM19);	/*フォーマットしています*/
				for(lp2=0;lp2<40;lp2++){
					if(!(lp2%8)){
						MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
						MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
						if(result!=McErrNotFormat){
							save_data_clear();
							slpad_m=1;
							return;
						}
					}
					sl_wait(1);
				}
				ret=MemCardFormat(MCRD_PORT);		/* フォーマット */
				if(ret==McErrNone){
					mc_mess_(DEF_MEM18);	/*メモリカードをフォーマットしました*/
					sl_wait(100);
				}else{
					mc_mess_(DEF_MEM30); /*フォーマットを失敗しました*/
					sl_wait(60);
					mc_mess_(DEF_MEM13);	/*メモリカードを入れ替えて下さい*/
					sl_wait(4);
				}
				slpad_m=1;
				save_data_clear();
				ret=-1;
			}else{	//	フォーマットしない 
				slpad_m=1;
				mc_mess_(DEF_MEM13);	/*メモリカードを入れ替えて下さい*/
				sl_wait(2);
				memc_unfm=1;
			}
		break;
	}

	return(ret);
}

static int check_cards(int type)
{
	int buf;
	buf=slpad_m;
	slpad_m=0;
	pad_toreruyo(1);
	check_cards2(type);
	pad_toreruyo(0);
	if(slpad_m==0) slpad_m=buf;
}

/* ============================================ */
//char sy=0;
int check_cardf;
int _card_seq_check(int init)
{
	int i,r,ret=0,chk,chk2;
	int mdd;
	static int seq;

	sy=(sy+1)%30;
	if(sy)	return;

	if(mc_mode==1){
		pad_toreruyo(1);
		seq=0;
		mc_mode=2;
		slpad_m=1;
		save_data_clear();
		mc_mess_(DEF_MEM00); /*メモリカードを調べています*/
		sl_wait(4);
		check_cards(0);
		return;
	}
	chk=check_cards(1);
	if(mc_mode>3){
		slpad_m=0;
		mdd=mc_mode-4;
		if(!mdd){	/* トータル */
			sv0  = memalloc((((sizeof(SVLDDATA0)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT), (void**)&sv0);
		}else{		/* プレイ */
			sv1 = memalloc((((sizeof(SVLDDATA1)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT), (void**)&sv1);
		}
		if(slc){
			save_main(mdd);
		}
		else{
			load_main(mdd);
		}
		if(!mdd){	/* トータル */
			memfree((void**)&sv0);
		}else{		/* プレイ */
			memfree((void**)&sv1);
		}
		mc_mode=2;
		slpad_m=1;
	}

	return(ret);
}


int card_seq_check(int init)
{
	if(mc_mode){
		w_init();
		wind_w=1;
		_card_seq_check(init);
		wind_w=0;
		w_exit();
	}
}

u_long (*sv_clt[2][7])={
{
	mck_coup_clt,
	mck_hyou_clt,
	mck_kapp_clt,
	mck_kyur_clt,
	mck_moon_clt,
	mck_sake_clt,
	mck_seve_clt,
},
{
	mcb_binb_clt,
	mcb_cher_clt,
	mcb_fuku_clt,
	mcb_kodu_clt,
	mcb_seve_clt,
	mcb_suzu_clt,
	mcb_yama_clt,
},
};

u_long (*sv_pxl[2][7])={
{
	mck_coup_pxl0000,
	mck_hyou_pxl0000,
	mck_kapp_pxl0000,
	mck_kyur_pxl0000,
	mck_moon_pxl0000,
	mck_sake_pxl0000,
	mck_seve_pxl0000,
},
{
	mcb_binb_pxl0000,
	mcb_cher_pxl0000,
	mcb_fuku_pxl0000,
	mcb_kodu_pxl0000,
	mcb_seve_pxl0000,
	mcb_suzu_pxl0000,
	mcb_yama_pxl0000,
},
};



// 0=SYSTEM 1=GAME
int uwagaki;
void save_main(int mode)
{
	int ret;
	int lp,lp2;
	int chk,chk2;
	char zck;
	char mcrd_filename2[21];
	char *cpxl;
	short *cpxls;
	u_long results;
	char nans[4]={"００"};
	char nans2[4]={"　　"};
	char kais[10]={"０００００"};
	char kais2[10]={"　　　　　"};
	char car[20]={"０１２３４５６７８９"};
	char nobk[15];
	char nobkc;
	int pln;

	if(check_cards(1)) return;

	if(!mode){ /*システムデータ*/
		mc_mess_(DEF_MEM06); /*トータルデータをセーブします*/
		sl_wait(10);

		bcopy((char *)&mcrdhead,(char *)&sv0->head,sizeof(MCRDHEAD));
		sv0->info.f=mode;	/* セーブファイルの種類 */
		bcopy((char *)&tot,(char *)&sv0->game_lst,sizeof(SAVE1));

		sv0->rnd=rnd(0xFFFF);			/* ファイル復活防止用 */
		sv0->cnt++;				/* ファイル復活防止用 */
		sv0->sum=sv0->rnd;

		if(check_cards(1)){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		if((0<mc_data.card_use[uwagaki]) && (mc_data.card_use[uwagaki]<4)){
		//	上書き 
			ret=MemCardDeleteFile(MCRD_PORT,dirent2[uwagaki].name);
			if(ret){
				mc_mess_(DEF_MEM31); /*セーブ失敗*/
				sl_wait(120);
				save_data_clear();
				return;
			}
		}

		ret=MemCardCreateFile(MCRD_PORT,&mcrd_filename[0][0],1);
		if(ret){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		MemCardWriteFile(MCRD_PORT,&mcrd_filename[0][0],(long *)sv0,0,
			(((sizeof(SVLDDATA0)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT));
		MemCardSync(0,&cmds,&result);			/* mcrd結果を取得 */
		if(result){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		mc_mess_(DEF_MEM15); /*トータルデータをセーブしました*/
		sl_wait(120);
		MemCardGetDirentry(MCRD_PORT,mcrd_filenames,&dirent[0],&alf,0,15);
		if(ret!=McErrNone){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		save_data_set();

	}else{	/*プレイデータ */
		mc_mess_(DEF_MEM08); /*プレイデータをセーブします*/
		sl_wait(10);

		for(lp=0;lp<21;lp++)
			mcrd_filename2[lp]=mcrd_filename[1+MACINE][lp];
/* 1:トータル
   2:かっぱ
   3:びんびん */
		if((0<mc_data.card_use[uwagaki]) && (mc_data.card_use[uwagaki]<4)){
		/* 上書き */
			ret=MemCardDeleteFile(MCRD_PORT,dirent2[uwagaki].name);
			if(ret){
				mc_mess_(DEF_MEM31); /*セーブ失敗*/
				sl_wait(120);
				save_data_clear();
				return;
			}
			ret = MemCardGetDirentry(MCRD_PORT,mcrd_filenames,&dirent[0],&alf,0,15);
			if(ret!=McErrNone){
				mc_mess_(DEF_MEM31); /*セーブ失敗*/
				sl_wait(120);
				save_data_clear();
				return;
			}
			save_data_set();
		}
// alf=使用総ファイル数 
		chk2=0;
		nobkc=0;
		for(lp2=0;lp2<alf;lp2++){
			if(mc_data.card_use[lp2]==(2+MACINE)){
				if(dirent2[lp2].name[13]!=' ') chk=10;
				else						chk=0;
				if(dirent2[lp2].name[14]==' ') chk=0;
				else	chk+=(dirent2[lp2].name[14]-0x30);
				nobk[nobkc]=chk;
				nobkc+=1;
			}
		}
		if(nobkc){
			for(lp=1;lp<16;lp++){
			chk=0;
				for(lp2=0;lp2<nobkc;lp2++){
					if(nobk[lp2]==lp) chk+=1;
				}
				if(!chk) goto SAVSS;
			}
		}else{
			lp=1;
		}
SAVSS:
/*	"BISLPS-01927B       ",  */
//		cpxl=(char *)&strings[MACINE][0];
//		for(lp=0;lp<64;lp++,cpxl++)	mcrdhead1.string[lp]=*cpxl;

		if(lp<10){
			mcrd_filename2[13]=' ';
			nans[0]=nans2[0];
			nans[1]=nans2[1];
		}
		else{
			mcrd_filename2[13]='1';
			nans[0]=car[2];
			nans[1]=car[3];
		}
		mcrd_filename2[14]='0'+(lp%10);
		nans[2]=car[((lp%10)*2)];
		nans[3]=car[((lp%10)*2)+1];

//		cpxl=(char *)nans;
//		for(lp=40;lp<44;lp++,cpxl++)	mcrdhead1.string[lp]=*cpxl;

		zck=0;
		play_num+=1;
		mcrd_filename2[15]=	'0'+(play_num/10000);
		if(mcrd_filename2[15]=='0')	mcrd_filename2[15]==' ';
		else						zck=1;
		mcrd_filename2[16]=	'0'+((play_num/1000)%10);
		if((mcrd_filename2[16]=='0')&&(zck==0))	mcrd_filename2[16]==' ';
		else										zck=1;

		mcrd_filename2[17]=	'0'+((play_num/100)%10);
		if((mcrd_filename2[17]=='0')&&(zck==0))	mcrd_filename2[17]==' ';
		else										zck=1;

		mcrd_filename2[18]=	'0'+((play_num/10)%10);
		if((mcrd_filename2[18]=='0')&&(zck==0))	mcrd_filename2[18]==' ';
		else										zck=1;

		mcrd_filename2[19]=	'0'+(play_num%10);
		play_num-=1;

		cpxl=(char *)(sv_clt[MACINE][2]);
		for(lp=0;lp<32;lp++,cpxl++)		mcrdhead1.clut[lp]=*cpxl;
		cpxl=(char *)(sv_pxl[MACINE][2]);
		for(lp=0;lp<128;lp++,cpxl++)	mcrdhead1.icon[lp]=*cpxl;
		cpxl=(char *)&strings[MACINE][0];
		for(lp=0;lp<64;lp++,cpxl++)	mcrdhead1.string[lp]=*cpxl;
		cpxl=(char *)nans;
		for(lp=40;lp<44;lp++,cpxl++)	mcrdhead1.string[lp]=*cpxl;

		pln=0;
		zck=0;
		pln=play_num;
		if((pln/10000)){
			kais[0]=car[((pln/10000)*2)];
			kais[1]=car[((pln/10000)*2)+1];
			pln=pln%10000;
			zck=1;
		}else{
			if(!zck){
				kais[0]=kais2[0];
				kais[1]=kais2[1];
			}
		}
		if((pln/1000)){
			kais[2]=car[((pln/1000)*2)];
			kais[3]=car[((pln/1000)*2)+1];
			pln=pln%1000;
			zck=1;
		}else{
			if(!zck){
				kais[2]=kais2[0];
				kais[3]=kais2[1];
			}
		}

		if((pln/100)){
			kais[4]=car[((pln/100)*2)];
			kais[5]=car[((pln/100)*2)+1];
			pln=pln%100;
			zck=1;
		}else{
			if(!zck){
				kais[4]=kais2[0];
				kais[5]=kais2[1];
			}
		}

		if((pln/10)){
			kais[6]=car[((pln/10)*2)];
			kais[7]=car[((pln/10)*2)+1];
			zck=1;
		}else{
			if(!zck){
				kais[6]=kais2[0];
				kais[7]=kais2[1];
			}
		}
		pln=pln%10;
		kais[8]=car[((pln)*2)];
		kais[9]=car[((pln)*2)+1];

		cpxl=(char *)kais;
		for(lp=52;lp<62;lp++,cpxl++)	mcrdhead1.string[lp]=*cpxl;

		bcopy((char *)&mcrdhead1,(char *)&sv1->head,sizeof(MCRDHEAD1));
		sv1->info.f=mode;	/* セーブファイルの種類 */
		bcopy((char *)&kbr,(char *)&sv1->game_lst,sizeof(SAVE2));

		if(chk_mcard()){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		ret=MemCardCreateFile(MCRD_PORT,mcrd_filename2,
				(sizeof(SVLDDATA1)+MCRD_SIZE-1)/MCRD_SIZE);
		if(ret!=McErrAlreadyExist){
			if(ret){
				mc_mess_(DEF_MEM31); /*セーブ失敗*/
				sl_wait(120);
				save_data_clear();
				return;
			}
		}

		sv1->rnd=rnd(0xFFFF);			/* ファイル復活防止用 */
		sv1->cnt++;				/* ファイル復活防止用 */
		sv1->sum=sv1->rnd;

		if(chk_mcard()){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		MemCardWriteFile(MCRD_PORT,mcrd_filename2,(long *)sv1,0,
			((sizeof(SVLDDATA1)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT);
		MemCardSync(0,&cmds,&result);			/* mcrd結果を取得 */
		if(result){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}

		ret = MemCardGetDirentry(MCRD_PORT,mcrd_filenames,&dirent[0],&alf,0,15);
		if(ret!=McErrNone){
			mc_mess_(DEF_MEM31); /*セーブ失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		mc_mess_(DEF_MEM17); /*プレイデータをセーブしました*/
		sl_wait(120);
		save_data_set();
	}
}



int load_main(int mode)
{
	int ret;
	int lp,lp2;
	int chk,chk2;
	char mcrd_filename2[21];
	char *cpxl;
	u_long results=0;

	if(check_cards(1)) return;

	if(!mode){ /*システムデータ*/
		mc_mess_(DEF_MEM07); /*トータルデータをロードします*/
		sl_wait(120);

		if(chk_mcard()){
			mc_mess_(DEF_MEM32); /*ロード失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		MemCardReadFile(MCRD_PORT,mcrd_filename[0],(long *)sv0,0,(((sizeof(SVLDDATA0)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT));
		/* mcrdファイル読み込み */
		MemCardSync(0,&cmds,&result);			/* mcrd結果を取得 */
		if(result){
			mc_mess_(DEF_MEM32); /*ロード失敗*/
			sl_wait(120);
			return;
		}
		if(sv0->sum!=sv0->rnd){
			/*壊れている*/
			mc_mess_(DEF_MEM11); /*ロード失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		bcopy((char *)&sv0->game_lst,(char *)&tot,sizeof(SAVE1));
		mc_mess_(DEF_MEM14); /*トータルデータをロードしました*/
		sl_wait(120);
		aul_ok=1;
	}
	else{	/*プレイデータ */

		mc_mess_(DEF_MEM09); /*プレイデータをロードします*/
		sl_wait(2);
		if(chk_mcard()){
			mc_mess_(DEF_MEM32); /*ロード失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}

   	   	/* mcrdファイル読み込み */
		ret = MemCardReadFile(MCRD_PORT,dirent2[uwagaki].name,(long *)sv1,0,(((sizeof(SVLDDATA1)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT));
		MemCardSync(0,&cmds,&result);			/* mcrd結果を取得 */
		if(result){
			mc_mess_(DEF_MEM32); /*ロード失敗*/
			sl_wait(120);
			return;
		}
		if(sv1->sum!=sv1->rnd){
			/* チェックサムの計算 */
			/*壊れている*/
			mc_mess_(DEF_MEM11); /*ロード失敗*/
			sl_wait(120);
			save_data_clear();
			return;
		}
		bcopy((char *)&sv1->game_lst,(char *)&kbr,sizeof(SAVE2));
		restore_setting_data(&settei_data);
		mc_mess_(DEF_MEM16); /*プレイデータをロードしました*/
		sl_wait(120);
		swp->loadF=1;
		slf=1;
	}
}

int	opmes;
void auto_loads(void)
{
	u_long results;
	u_long ret;
	struct DIRENTRY direntry;

	aul_ok=0;
	MemCardExist(MCRD_PORT);		/* PORT 0 */
	MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
	MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
	MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
	MemCardAccept(MCRD_PORT);		/* mcrd状態を取得 */
	MemCardSync(0,&cmds,&result);	/* mcrd結果を取得 */
	if(result) return;
	ret = MemCardGetDirentry(MCRD_PORT,mcrd_filename[0],&direntry,&alf,0,1);
	if(!ret){	//	正常終了 
		if(alf){	//	ファイル有り 
			/* オートロードメッセージ*/
			opmes = ffnt_open(0-(16*8),-16,16*16, 32*2, (u_short *)fnt_data + STR_MEM33);
			ffnt_color(opmes, 0x80, 0x40, 0x40);
			sl_wait(4);
			MemCardReadFile(MCRD_PORT,mcrd_filename[0],(long *)sv0,0,(((sizeof(SVLDDATA0)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT));
			/* mcrdファイル読み込み */
			MemCardSync(0,&cmds,&result);			/* mcrd結果を取得 */
			if(result){
				ffnt_close(opmes);
				return;
			}
			if(sv0->sum!=sv0->rnd){	/* 壊れてる */
				ffnt_close(opmes);
				return;
			}
			bcopy((char *)&sv0->game_lst,(char *)&tot,sizeof(SAVE1));
			ffnt_close(opmes);
			aul_ok=1;
		}
	}
}

void auto_load(void)
{
	w_init();
	sv0=memalloc((((sizeof(SVLDDATA0)+MCRD_SECT-1)/MCRD_SECT)*MCRD_SECT), (void**)&sv0);
	auto_loads();
	memfree((void**)&sv0);
	w_exit();
}

