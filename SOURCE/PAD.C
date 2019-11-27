#include "common.h"
#include "work.h"

/*-------------------------------------------------------------------------------*/
/* プロトタイプ宣言 */
void	pad_callback(void);
u_short	pad_read(void);
void	pad_shibireru(void);
void	pad_shibirenai(void);
void	pad_init(void);
void	pad_stop(void);

/*-------------------------------------------------------------------------------*/
/* グローバル変数 */
static u_char	bb0[34], bb1[34];
static int		initial = 0;
static u_char	shibire[6];
static u_char	align[6] = {0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF};
static int		initlevel;
u_long			Paddata[4];
short			Padbuf[16];

#ifdef EXCHENGE_PAD
//	ＰＡＤのボタン機能変更用 
short pad_use_data[PAD_USE_MAX]={
		CON_UP		,
		CON_DOWN	,
		CON_LEFT	,
		CON_RIGHT	,
		CON_SANKAKU	,
		CON_PEKE	,
		CON_SHIKAKU	,
		CON_MARU	,
		CON_L1		,
		CON_L2		,
		CON_R1		,
		CON_R2		,
		CON_SEL		,
		CON_START	,
};
short pad_use[PAD_USE_MAX];
#endif

/*-------------------------------------------------------------------------------*/
void pad_callback(void)
{
	if(pad_toreru) return;

	initlevel = PadGetState(0);
	if(initlevel == PadStateFindPad)initial = 0;
	/* シビレル制御 */
	if(!initial){
		if(initlevel == PadStateFindCTP1){
			initial = 1;
		}
		else if(initlevel == PadStateStable){
			if(PadSetActAlign(0, align))initial = 1;
		}
	}
}


/*-------------------------------------------------------------------------------*/
u_short pad_get(long id)
{
	u_long			ret = 0;
	int				mode, port;

	port = id * 0x10;
	/* 接続情報 */
	if(initlevel == PadStateDiscon)return;
	if(PadInfoMode(port, InfoModeCurExID, 0)){
		mode = PadInfoMode(port, InfoModeCurExID, 0);
	}
	else{
		mode = PadInfoMode(port, InfoModeCurID, 0);
	}
	/* ボタン押下情報取得 */
	switch(mode) {
		case 0x4:	/* デジタルコントローラ */
			switch(id){
				case 0:
					ret = ~(*(bb0 + 3) | *(bb0 + 2) << 8);
				break;
				case 1:
					ret = ~(*(bb1 + 3) | *(bb1 + 2) << 8);
				break;
			}
		break;
		case 0x7:	/* アナログコントローラ */
#if 0
			switch(id){
				case 0:
					if(~(*(bb0 + 2)) & 0x02)		*(bb0 + 3) &= ~(1 << 6);
					if(~(*(bb0 + 2)) & 0x04)		*(bb0 + 3) &= ~(1 << 5);
					if(*(bb0 + 6) - 128 < -96)		*(bb0 + 2) &= ~(1 << 7);
					else if(*(bb0 + 6) - 128 > 96)	*(bb0 + 2) &= ~(1 << 5);
					if(*(bb0 + 7) - 128 < -96)		*(bb0 + 2) &= ~(1 << 4);
					else if(*(bb0 + 7) - 128 > 96)	*(bb0 + 2) &= ~(1 << 6);
					ret = ~(*(bb0 + 3) | *(bb0 + 2) << 8);
				break;
				case 1:
					if(~(*(bb1 + 2)) & 0x02)		*(bb1 + 3) &= ~(1 << 6);
					if(~(*(bb1 + 2)) & 0x04)		*(bb1 + 3) &= ~(1 << 5);
					if(*(bb1 + 6) - 128 < -96)		*(bb1 + 2) &= ~(1 << 7);
					else if(*(bb1 + 6) - 128 > 96)	*(bb1 + 2) &= ~(1 << 5);
					if(*(bb1 + 7) - 128 < -96)		*(bb1 + 2) &= ~(1 << 4);
					else if(*(bb1 + 7) - 128 > 96)	*(bb1 + 2) &= ~(1 << 6);
					ret = ~(*(bb1 + 3) | *(bb1 + 2) << 8);
				break;
			}
#endif
		break;
	}
	return(ret);
}


/*-------------------------------------------------------------------------------*/
/* パッド入力 */
char pad_toreru;

void pad_toreruyo(char data)
{
	if(data){
	pad_beta=0;
	pad_rpt=0;
	pad_cnt=0;
	pad_trg=0;
	}
	pad_toreru=data;
}

u_short pad_read(void)
{
	int				lp;
	u_long			pd;
	static u_char	padcrosstable[] = {0, 2, 7, 4, 3, 5, 6, 1, 8, 9, 10, 11, 12, 13, 14, 15};

	if(pad_toreru) return;

	Paddata[BETA] = pad_get(0);			//	PAD読み取り
	Paddata[RPT] = Paddata[CNT] = Paddata[TRG] = 0;
	for(lp = 0, pd = 1; lp < 16; lp++, pd = (pd << 1)){
		if(Paddata[BETA] & pd){
			if(Padbuf[lp] == 0)Paddata[CNT] |= pd;
			else if(Padbuf[lp] > 20)Paddata[RPT] |= pd;
			if(!(Padbuf[lp] % 20))Paddata[TRG] |= pd;
			if(Padbuf[lp] < 32000)Padbuf[lp]++;
			else Padbuf[lp] = 1;
		}
		else{
			Padbuf[lp] = 0;
		}
	}
	return(Paddata[BETA]);
}


/*-------------------------------------------------------------------------------*/
extern char mes_deteimasuka;
void pad_shibireru(void)
{
	int				port = 0;

	if((auto_on==1) && (au_sp)) return;
	if(mes_deteimasuka){
		pad_shibirenai();
		return;
	}
	if(pikapika){
		pad_shibirenai();
		return;
	}
	if(vib_flag){
		if(PadInfoMode(port, InfoModeCurExID, 0)){
			shibire[0] = 0x01;
			shibire[1] = 0xff;
		}
		else{
			shibire[0] = 0x01 << 6;
			shibire[1] = 0x01;
		}
	}
}


/*-------------------------------------------------------------------------------*/
void pad_shibirenai(void)
{
	int				port = 0;

	if(vib_flag){
		if(PadInfoMode(port, InfoModeCurExID, 0)){
			shibire[0] = 0x00;
			shibire[1] = 0x00;
		}
		else{
			shibire[0] = 0x01 << 6;
			shibire[1] = 0x00;
		}
	}
}


/*-------------------------------------------------------------------------------*/
void pad_init(void)
{
	int				i;

	bzero(bb0, sizeof(bb0));
	bzero(bb1, sizeof(bb1));
	PadInitDirect(bb0, bb1);
	PadSetAct(0x00, &shibire[0], 2);
	PadStartCom();
	initial = 0;
	PadSetActAlign(0, align);
	pad_shibirenai();
	pad_read();
	pad_toreru=0;
	pikapika=0;

#ifdef EXCHENGE_PAD
	for(i=0;i<PAD_USE_MAX;i++)	pad_use[i]=pad_use_data[i];
#endif

}

/*-------------------------------------------------------------------------------*/
void pad_stop(void)
{
	StopPAD();
}



