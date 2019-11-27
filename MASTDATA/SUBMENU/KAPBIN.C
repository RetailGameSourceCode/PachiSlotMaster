#include "common.h"
#include "work.h"
//#include "z80.h"
#include "sldata.h"
#include "teisu.h"


char	stp_reel_buf[3];

char	tei_kou;
char	win_deru_ok;
char	sta[3][7];

char	z_a,z_ab;
char	z_f,z_af;
char	z_b,z_bb;
char	z_c,z_cb;
char	z_d,z_db;
char	z_e,z_eb;
char	z_h,z_hb;
char	z_l,z_lb;

int z_ai;
int z_bc,z_de,z_hl;
int z_bcb,z_deb,z_hlb;
int swk;

char	*pusha[20];
char	pushd[2][20];
char	p_p,wk,cy;

KETOBASHI_SEL *khl,*khl_b,*khlb[5],*khl_wk;

char	*af,*afb,*af_b;
char	*bc,*bcb,*bc_b;
char	*de,*deb,*de_b;
char	*hl,*hlb,*hl_b;
char	*awk;

int *hli,*dei,*iwk;


#define _EXX_	exx_();
void exx_(void)
{
	khl_wk=khl;	khl=khl_b;	khl_b=khl_wk;
	awk=bc;		bc=bc_b;	bc_b=awk;
	awk=de;		de=de_b;	de_b=awk;
	awk=hl;		hl=hl_b;	hl_b=awk;
	wk=z_b;		z_b=z_bb;	z_bb=wk;
	wk=z_c;		z_c=z_cb;	z_cb=wk;
	wk=z_d;		z_d=z_db;	z_db=wk;
	wk=z_e;		z_e=z_eb;	z_eb=wk;
	wk=z_h;		z_h=z_hb;	z_hb=wk;
	wk=z_l;		z_l=z_lb;	z_lb=wk;
	swk=z_bc;	z_bc=z_bcb;	z_bcb=swk;
	swk=z_de;	z_de=z_deb;	z_deb=swk;
	swk=z_hl;	z_hl=z_hlb;	z_hlb=swk;
}

#define _EX_DE_HL_ _ex_de_hl__();
void _ex_de_hl__(void)
{
	awk=hl;		hl=de;		de=awk;
	iwk=hli;	hli=dei;	dei=iwk;
}

void push_(char **ad,char *dl,char *dr)
{
	pusha[p_p]=*ad;
	pushd[0][p_p]=*dl;
	pushd[1][p_p]=*dr;
	p_p+=1;
#ifdef DEBUG_FONT
	if(p_p==20)	DEB_STOP2(p_p);
#endif
}

void pop_(char **ad,char *dl,char *dr)
{
#ifdef DEBUG_FONT
	if(p_p==0)	DEB_STOP2(p_p);
#endif
	p_p-=1;
	*ad=pusha[p_p];
	*dl=pushd[0][p_p];
	*dr=pushd[1][p_p];
}


#define DI hd_inter=0;
#define EI hd_inter=1;


//void SS_DATA_SET(void); 
//void SS_DATA_SET(char data ,char *HL,char *BC); 
//void MS_STOP_LED(void); 
void MS_STOP_LED(char	data);
void M_MAIN(void);

void MS_CREDIT_CHK(void);
void MS_HPERR_SET(void);
void MS_HOPPER_CHK(void);

void IS_LPSD_OUT(void);
char S_IN0_CHK(char chk);
void S_RAM_CLEAR(short);
void N_POWER_DOWN(void);
void I_WATCH_ERROR(void);
void I_INTR(void);
void SS_ERROR_STOP(char);
void IS_IN_READ(void);
void IS_LEVEL_UP(void);
void IS_TIME_COUNT(void);
void IS_REEL_CTL(int);
void IS_PULSE_OUT(int no);
void IS_COUNTER_OUT(void);
void M_POWER_ON(void);
void MS_RAM_CHK(void);
void MS_PCT_ON(void);
void MS_RANK_SET(void);
void MS_RKER_CHK(void);
void MS_BB_SET(void);
char MS_RAM_SET(void);
void MS_GAME_SET(char);
int MS_JAC_CHK(void);
void MS_BET_IN(char);
int MS_MEDAL_INC(void);
char MS_CREDIT_DEC(void);
void MS_CANCEL_CHK(void);
void MS_1MEDAL_PAY(void);
void MS_INSERT_CHK(void);
int MS_START_CHK(void);
void MS_IN_OUT_DOWN(void);
void MS_AUTO_IN(void);
void MS_SCOUNT_OUT(void);
int MS_WAIT_CHK(void);
void MS_REEL_READY(void);
void MS_REEL_START(char);
int MS_RLERR_CHK(void);
int MS_RLFIX_CHK(void);
int MS_STOP_CHK(void);
int MS_RLSTP_CHK(void);
void MS_WIN_JUDGE(void);
void MS_LINE_JUDGE(int tbl,int line);
void MS_WIN_PAY(void);
void MS_IN_OUT_UP(void);
void MS_GAME_CHK(void);
void MS_ALL_LOT(void);
void MS_JAC_LOT(void);
void MS_LOT_SET(void);
void MS_BB_LOT(void);
//	これは展開するので未使用とする 
//void MS_LOT_JUDGE(void); 
//	やっぱり要ります・・・  
int MS_LOT_JUDGE(void);

void MS_INSIDE_LOT(void);
void MS_FRUIT_LOT(void);
void  MS_NORMAL_LOT(void);
void MS_RLSTOP_SET(void);
void MS_HIT_SET(void);
void MS_BNSCT_DSP(void);
void IS_POWERON_RET(void);
//void IS_LAMP_OUT(int); 
void IS_LED_OUT(int led);
void IS_LINE_OUT(void);
void MS_PIC_CTL(void);
int MS_RLDAT_SET(char);
void MS_CREJ_CTL(void);
//void MS_REJPUL1_CTL(int lp_max ,char *z_hl); 
void MS_REJPUL1_CTL(int tbl);
void MS_REJPUL2_CTL(void); 
//void MS_REJPUL2_CTL(char kai,char zz_c,int tbl);
void MS_REJ2_CTL(void);
void MS_REJ3_CTL(void);
void MS_PUL_CTL(void);
char MS_SPPOINT_SET(void);
void MS_STOPPIC_SET(void);
void MS_RANK_DSP(void);

void S_LPSD_SET(char data);
void SS_LPSD_SET(char data);

void FLASH_LAMP_OUT(void);
void EFFECT_LAMP_OUT(void);
void BACK_LAMP_OUT(void);
short MS_STOPSW_CHK(void);
char MS_SENSOR_CHK(void);
void M_PRG_START(void);
void M_PRG_START1(void);

void slot_main(void)
{
	M_PRG_START();
}

///////////////////////////////////////////////////////////////////////////  

///////////////////////////////////////////////////////////////////////////  

///////////////////////////////////////////////////////////////////////////  
//;************************************************************************  
//;*	管理番号      : S-0300-001					*  
//;*	機能	      : プログラム開始					*  
//;*	ﾓｼﾞｭｰﾙ名      : M_PRG_START					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :							*  
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					*  
//;*	使用ﾓｼﾞｭｰﾙ    : MS_RAM_CHK,MS_PCT_ON,MS_RANK_SET		*  
//;*		      : M_POWER_ON（ジャンプ）,MS_RKER_CHK,MS_BB_SET	*  
//;*		      : M_MAIN（ジャンプ）				*  
//;************************************************************************  
//;  
//M_PRG_START:  

void M_PRG_START(void)
{

#if 0
	z80_LD	(Z80_AF,0x801C);
	z80_LD	(Z80_BC,0x801C);
	z80_LD	(Z80_DE,0x801C);
	z80_LD	(Z80_HL,0x00801C);

	while(1){
#ifdef	DEBUG_FONT
		FntPrint(dbg_flg.fnt[0],"\n");
//		FntPrint(dbg_flg.fnt[0],"A  = %x\n",&((Z80_MC *)z80f)->A);  
//		FntPrint(dbg_flg.fnt[0],"F  = %x\n",&((Z80_MC *)z80f)->F);  
//		FntPrint(dbg_flg.fnt[0],"AF = %x\n",&((Z80_MS *)z80f)->AF);  

//		FntPrint(dbg_flg.fnt[0],"B  = %x\n",&((Z80_MC *)z80f)->B);  
//		FntPrint(dbg_flg.fnt[0],"C  = %x\n",&((Z80_MC *)z80f)->C);  
//		FntPrint(dbg_flg.fnt[0],"BC = %x\n",&((Z80_MS *)z80f)->BC);  
		FntPrint(dbg_flg.fnt[0],"ADR = %x\n",(int *)&M_PRG_START);
#endif
		wait(1);
	}

#endif 
//	ここらへんは何もしてないに等しいです。 
//	LD	SP,@STACK1		; 仮スタックポインタ  セット   
//	IM	0				; 割り込みモード０  セット   
//	JP	M_PRG_START1		; <続き>  
	M_PRG_START1();//		; <続き>  
//  
}

//	ORG	0008H  
//;************************************************************************  
//;*	管理番号      : S-0303-001					*  
//;*	機能	      : ワーク・テーブルのアドレスセット		*  
//;*	ﾓｼﾞｭｰﾙ名      : S_ADDR_SET					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : HL = ワーク・テーブルのアドレス			*  
//;*		      : A  = オフセット					*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :	HL = HL + A					*  
//;*	保護ﾚｼﾞｽﾀ     :							*  
//;*	破壊ﾚｼﾞｽﾀ     :	A,HL						*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  

void S_ADDR_SET(void)
{
//	ADD	A,L  
//	LD	L,A			; ＬレジスタにＡレジスタを加算  
//	RET	NC			; キャリーあり？．．ＮＯ   
//	INC	H			; Ｈレジスタに１加算  
//  
//	RET  
}

//	ORG	0010H  
//;************************************************************************  
//;*	管理番号      : S-0304-001					*  
//;*	機能	      : 入力ポート０レベルチェック			*  
//;*	ﾓｼﾞｭｰﾙ名      : S_IN0_CHK					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : B = チェック入力				*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Zflag OFF = 入力あり				*  
//;*		      : A = 入力ビット					*  
//;*		      : Cflag OFF					*  
//;*	保護ﾚｼﾞｽﾀ     :	B						*  
//;*	破壊ﾚｼﾞｽﾀ     :	A						*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  
//;  
char S_IN0_CHK(char chk)
{
	char z_a;
//	LD	A,(_PT_IN0_OLD)  
	z_a=_PT_IN0_OLD;
//	AND	B			; 入力ポート０レベルチェック  
	z_a&=chk;
//  
//	RET  
	return(z_a);
}

//  
//	ORG	0018H  
//;************************************************************************  
//;*	管理番号      : S-0305-001					*  
//;*	機能	      : ＲＡＭ初期化					*  
//;*	ﾓｼﾞｭｰﾙ名      : S_RAM_CLEAR					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : HL = ＲＡＭ初期化テーブル			*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :							*  
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  

void S_RAM_CLEAR(short data)
{
	int lp;

//	LD	E,(HL)  
//	INC	HL  
//	LD	D,(HL)			; ＲＡＭ初期化先頭アドレス　セット  
//	INC	HL  
//  
//	LD	B,(HL)			; ＲＡＭ初期化範囲下位桁　セット  
//	INC	HL  
//  
//	JR	S_RAM_CLEAR1		; <続き>  
//;************************************************************************  
//;*	管理番号      : S-0305-001					*  
//;*	機能	      : ＲＡＭ初期化  （続き）				*  
//;*	ﾓｼﾞｭｰﾙ名      : S_RAM_CLEAR					*  
//;************************************************************************  
//;  
//S_RAM_CLEAR1:  
//	LD	C,(HL)			; ＲＡＭ初期化範囲上位桁　セット  
//  
//	LD	A,B  
//	AND	A			; ＲＡＭ初期化範囲下位桁＝０？  
//	JR	Z,S_RAM_CLEAR2		;   ＹＥＳ  
//  
//	INC	C			; ＲＡＭ初期化範囲上位桁　＋１  
//  
//	XOR	A  
//S_RAM_CLEAR2:  
//	LD	(DE),A			; ＲＡＭ初期化  
//	INC	DE			; 次のＲＡＭアドレス　セット  
//	DJNZ	S_RAM_CLEAR2		; ２５６バイト分終了？．．ＮＯ  
//  
//	DEC	C			; 全バイト終了？  
//	JR	NZ,S_RAM_CLEAR2		;   ＮＯ  
// 
//	RET  

	switch(data){
		case 1:	//	TBL_RAM_CLEAR1 
		case 2:	//	TBL_RAM_CLEAR2 
		break;
		case 4:	//	TBL_RAM_CLEAR4 
		_NB_PAY_LED=0xFF;
		_WK_FLASH_LP.lamp=0; 	_WK_FLASH_LP.time=0;	_WK_FLASH_LP.rpt=0;
		_WK_FLASH_LP.point=0;	_WK_FLASH_LP.light=0;
		_WK_EFFECT_LP.lamp=0;	_WK_EFFECT_LP.time=0;	_WK_EFFECT_LP.rpt=0;
		_WK_EFFECT_LP.point=0;	_WK_EFFECT_LP.light=0;
		_WK_BACK_LP.lamp=0;		_WK_BACK_LP.time=0;		_WK_BACK_LP.rpt=0;
		_WK_BACK_LP.point=0;	_WK_BACK_LP.light=0;
		_FL_WBL=0;
		_FL_STOP_LP=0;
		_WK_WIN_LP=0;
		_WK_WINBACK_LP[0]=0;
		_WK_WINBACK_LP[1]=0;
		for(lp=0;lp<9;lp++)	_PT_OUT[lp]=0;
		for(lp=0;lp<5;lp++)	TM2_NUM[lp]=0;
		for(lp=0;lp<9;lp++)	TM1_NUM[lp]=0;		//; １バイトタイマ数 
		for(lp=0;lp<8;lp++){
			_WK_REEL[0][lp]=0;
			_WK_REEL[1][lp]=0;
			_WK_REEL[2][lp]=0;
		}
		_CT_MEDAL[0]=0;
		_CT_MEDAL[1]=0;
		_NB_PLAY_MEDAL=0;
		_NB_PAY_MEDAL=0;
		_NB_REP_MEDAL=0;
		_WK_SUM_CHK=0;
		_BF_STACK[0]=0;
		_BF_STACK[1]=0;
		_FL_WIN=0;
		_FL_ACTION=0;
		_CT_IN_OUT[0]=0;
		_CT_IN_OUT[1]=0;
		case 3:	//	TBL_RAM_CLEAR3 
		_BF_RAND1=0;
		_BF_RAND2=0;
		for(lp=0;lp<4;lp++)	_FL_PIC[lp]=0;
		for(lp=0;lp<5;lp++)	 _NB_SSPRD[lp]=0;
		for(lp=0;lp<7;lp++)	_WK_REEL_PIC1[lp]=0;
		for(lp=0;lp<7;lp++)	_WK_REEL_PIC2[lp]=0;
		_WK_ALL_PIC1=0;
		_WK_ALL_PIC2=0;
		for(lp=0;lp<5;lp++)	_WK_STOP_PIC1[lp]=0;
		for(lp=0;lp<5;lp++)	_WK_STOP_PIC2[lp]=0;

		_BF_STOP_CTL=0;
		_CT_BONUS_PLAY=0;
		_CT_BONUS_WIN=0;
		_CT_BIG_PLAY=0;
		_CT_BIG_WIN=0;

		break;
	}

	DI
	I_INTR();
	EI

}

//	ORG	0020H  
//;************************************************************************  
//;*	管理番号      : S-0306-001					*  
//;*	機能	      : 遊技メダルブロッカーＯＦＦ			*  
//;*	ﾓｼﾞｭｰﾙ名      : S_BLOCKER_OFF					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :	HL						*  
//;*	破壊ﾚｼﾞｽﾀ     :							*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  
//;  
void S_BLOCKER_OFF(void)
{
//	PUSH	HL  
//	LD	HL,_PT_OUT1		; 遊技メダルブロッカー  ＯＦＦ <返却状態>  
//	RES	4,(HL)  
	_PT_OUT1&=((0x01<<4)^0xFF);
//	JR	S_BLOCKER_OFF1		; <続き>  
//;************************************************************************  
//;*	管理番号      : S-0306-001					*  
//;*	機能	      : 遊技メダルブロッカーＯＦＦ  （続き）		*  
//;*	ﾓｼﾞｭｰﾙ名      : S_BLOCKER_OFF					*  
//;************************************************************************  
//;  
//S_BLOCKER_OFF1:  
//	LD	L,LOW _PT_OUT7 
//	RES	6,(HL)			; 遊技メダル投入表示ランプ消灯　セット  
	_PT_OUT7&=((0x01<<6)^0xFF);

//	POP	HL  

//	RET  
}


//	ORG	0028H  
//;************************************************************************  
//;*	管理番号      : S-0307-001					*  
//;*	機能	      : 遊技メダルブロッカーＯＮ			*  
//;*	ﾓｼﾞｭｰﾙ名      : S_BLOCKER_ON					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :	HL						*  
//;*	破壊ﾚｼﾞｽﾀ     :							*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  
//;  
void S_BLOCKER_ON(void)
{
//	PUSH	HL  
//	LD	HL,_PT_OUT1		; 遊技メダルブロッカー  ＯＮ <通過状態>  
//	SET	4,(HL)  
	_PT_OUT1=_PT_OUT1|(0x01<<4);

//	JR	S_BLOCKER_ON1		; <続き>  
//;************************************************************************  
//;*	管理番号      : S-0307-001					*  
//;*	機能	      : 遊技メダルブロッカーＯＮ  （続き）		*  
//;*	ﾓｼﾞｭｰﾙ名      : S_BLOCKER_ON					*  
//;************************************************************************  
//;  
//S_BLOCKER_ON1:  
//	LD	L,LOW _PT_OUT7  
//	SET	6,(HL)			; 遊技メダル投入表示ランプ点灯　セット  
	_PT_OUT7=_PT_OUT7|(0x01<<6);
//	POP	HL  

//	RET  
}

//	ORG	0030H  
//;************************************************************************  
//;*	管理番号      : S-0308-001					*  
//;*	機能	      : ウォッチドッグクリア				*  
//;*	ﾓｼﾞｭｰﾙ名      : S_WATCH_CLEAR					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :	HL						*  
//;*	破壊ﾚｼﾞｽﾀ     :							*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  
//;  
void S_WATCH_CLEAR(void)
{
//	PUSH	HL  
//	LD	HL,0FF22H  
//	LD	(HL),0			; ウォッチドッグ停止  
//	JR	S_WATCH_CLEAR1		; <続き>  

//;************************************************************************  
//;*	管理番号      : S-0308-001					*  
//;*	機能	      : ウォッチドッグクリア  （続き）			*  
//;*	ﾓｼﾞｭｰﾙ名      : S_WATCH_CLEAR					*  
//;************************************************************************  
//;  
//S_WATCH_CLEAR1:  
//	LD	(HL),80H		; ウォッチドッグ起動  
//	POP	HL  
//  
//	RET  
//  
//	DEFS	3			; // 未使用  
//  
//	PAGE  

}

//	ORG	0038H  
//;************************************************************************  
//;*	管理番号      : S-0309-001					*  
//;*	機能	      : 各種ランプ・効果音データセット１		*  
//;*	ﾓｼﾞｭｰﾙ名      : S_LPSD_SET					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : （A = 各種ランプ・効果音出力要求）		*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :	BC,DE,HL					*  
//;*	破壊ﾚｼﾞｽﾀ     :							*  
//;*	使用ﾓｼﾞｭｰﾙ    : SS_LPSD_SET					*  
//;************************************************************************  

void S_LPSD_SET(char data)
{
//	PUSH	HL  
//	PUSH	DE  
//	PUSH	BC  
//  
	DI				//; 割り込み禁止  
//  
//	CALL	SS_LPSD_SET		; 各種ランプ・効果音データセット２  
	SS_LPSD_SET(data);		//; 各種ランプ・効果音データセット２  
//  
	EI				//; 割り込み許可  
//  
//	POP	BC  
//	POP	DE  
//	POP	HL  
//  
//	RET  
//  
}
//  
//;************************************************************************  
//;*	管理番号      : S-0310-001					*  
//;*	機能	      : 電断処理					*  
//;*			（ＮＭＩ）					*  
//;*	ﾓｼﾞｭｰﾙ名      : N_POWER_DOWN					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :	A,BC,DE,HL,BC',DE',HL'				*  
//;*	破壊ﾚｼﾞｽﾀ     :							*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  
//;  
void N_POWER_DOWN(void)
{
//	PUSH	AF			; ＡＦレジスタ退避  
//  
//	XOR	A  
//	LD	(0FF22H),A		; ウォッチドッグ停止  
//	LD	(0FF30H),A		; 割り込み停止  
//  
//	LD	A,I			; 電断時の割り込み禁止／許可状態　保存  
//	PUSH	AF			; // Ｆレジ　BIT2 ON   割り込み許可  
//					; //              OFF  割り込み禁止  
//	PUSH	BC  
//	PUSH	DE  
//	PUSH	HL  
//	EXX  
//	PUSH	BC  
//	PUSH	DE  
//	PUSH	HL			; 使用レジスタ退避（ＡＦレジスタ以外）  
//  
//	LD	(_BF_STACK),SP		; スタックポインタ保存  
//  
//	LD	HL,_FL_GAME_STS  
//	SET	6,(HL)			; 電断処理済みフラグ　セット  
//  
//	XOR	A  
//	LD	DE,_WK_SUM_CHK  
//	LD	(DE),A			; チェックサム　クリア  
//  
//	LD	HL,@RAM  
//	LD	BC,2  
//N_POWER_DOWN1:  
//	ADD	A,(HL)			; ＲＡＭチェックサム算出  
//	INC	HL			;;(8000H - 81FFH)  
//	DJNZ	N_POWER_DOWN1		; ２５６バイト算出終了？．．ＮＯ  
//  
//	DEC	C			; 全バイト算出終了？  
//	JR	NZ,N_POWER_DOWN1	;   ＮＯ  
//  
//	NEG				; ２の補数データにする  
//					;;（加算後０になる値）  
//	LD	(DE),A			; チェックサム　セット  
//  
//	LD	A,1  
//	LD	(0FF14H),A		; ＲＡＭ書き込み禁止  
//  
//N_POWER_DOWN2:  
//	JR	N_POWER_DOWN2		; リセット待ち  

}
//  
//	DEFS	7			; // 未使用  

//	ORG	00A4H  
//;************************************************************************  
//;*	管理番号      : S-0311-001					*  
//;*	機能	      : ウォッチドッグ処理				*  
//;*			（ＰＣＴ０）					*  
//;*	ﾓｼﾞｭｰﾙ名      : I_WATCH_ERROR					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :	E = エラー表示データ（下位桁）			*  
//;*	保護ﾚｼﾞｽﾀ     :							*  
//;*	破壊ﾚｼﾞｽﾀ     :	E						*  
//;*	使用ﾓｼﾞｭｰﾙ    : SS_ERROR_STOP（ジャンプ）			*  
//;************************************************************************  
//;  
//	なぜか、どこでもつかってない？  
void I_WATCH_ERROR(void)
{
//	LD	E,4FH			; ”Ｅ３”表示要求  セット  
//	JR	SS_ERROR_STOP  
}


//	ORG	00A8H  
//;************************************************************************  
//;*	管理番号      : S-0312-001					*  
//;*	機能	      : 割り込み処理					*  
//;*			（ＰＣＴ１）					*  
//;*	ﾓｼﾞｭｰﾙ名      : I_INTR						*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :	E = エラー表示データ（下位桁）			*  
//;*	保護ﾚｼﾞｽﾀ     :	A,BC,DE,HL					*  
//;*	破壊ﾚｼﾞｽﾀ     :							*  
//;*	使用ﾓｼﾞｭｰﾙ    : SS_ERROR_STOP（ジャンプ）,IS_IN_READ		*  
//;*		      : IS_TIME_COUNT,S_ADDR_SET,IS_REEL_CTL		*  
//;*		      : IS_COUNTER_OUT,IS_LPSD_OUT			*  
//;************************************************************************  
//;  
//	毎Ｓｙｎｃ割り込んでくる 
void I_INTR(void)
{
	int i,lp;

	if(hd_inter){
		hd_inter=2;

#ifdef  IRANAI
//	PUSH	AF			; レジスタ　退避  
//	PUSH	BC  
//	PUSH	DE  
//	PUSH	HL  
//  
//	LD	HL,8  
//	ADD	HL,SP  
//	LD	E,(HL)  
//	INC	HL  
//	LD	D,(HL)			; 戻り番地セット  
//	LD	HL, - PRG_END		; // プログラム最終アドレス  セット  
//	ADD	HL,DE			; 戻り番地正常？  
//	JR	NC,I_INTR1		; 　ＹＥＳ  
//  
//	LD	E,4FH			; ”Ｅ３”表示要求  セット  
//	JR	SS_ERROR_STOP  
#endif
//I_INTR1:  
//	ボタン入力受付判定 
//	PAD_READに当たる部分 
//	CALL	IS_IN_READ		; 入力ポート０～２読み込み  
	IS_IN_READ();		//; 入力ポート０～２読み込み  
//  
//	CALL	IS_TIME_COUNT		; タイマ計測  
	IS_TIME_COUNT();		//; タイマ計測  
//  
//	LD	C,3			; 回胴番号　セット  
//I_INTR2:  
//	LD	HL,_WK_REEL1 - 8  
//	LD	A,C  
//	ADD	A,A  
//	ADD	A,A  
//	ADD	A,A			; 回胴制御データＲＡＭ  
//					;;アドレス要求　セット  
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット  
//  
//	CALL	IS_REEL_CTL		; 回胴駆動制御  
	IS_REEL_CTL(2);		//; 回胴駆動制御  
	IS_REEL_CTL(1);		//; 回胴駆動制御  
	IS_REEL_CTL(0);		//; 回胴駆動制御  
//  
//	DEC	C			; 全回胴終了？  
//	JR	NZ,I_INTR2		;   ＮＯ  
//  
//	CALL	IS_COUNTER_OUT		; 外部信号出力  
	IS_COUNTER_OUT();			//; 外部信号出力  
//  
//	CALL	IS_LPSD_OUT		; ランプ（ＬＥＤ）表示・効果音出力  
	IS_LPSD_OUT();			//; ランプ（ＬＥＤ）表示・効果音出力  


//	LD	HL,_PT_OUT8  
//	LD	BC,9*100H OR @OUT8_PORT  
//I_INTR3:  
//	LD	A,(HL)  
//	OUT	(C),A			; 出力ポート（０～８）出力  
//	DEC	HL  
//	DEC	C			; 次の出力ポートアドレス　セット  
//	DJNZ	I_INTR3			; 出力終了？．．ＮＯ  

	for(lp=0;lp<8;lp++)	OUT_PORT[lp]=_PT_OUT[lp];

//  
//	POP	HL			; レジスタ復帰  
//	POP	DE  
//	POP	BC 
//  
//	LD	A,1  
//	LD	(0FF34H),A		; 割り込み許可  
//  
//	POP	AF  
	EI
	}
//	RET  
}


//;************************************************************************  
//;*	管理番号      : S-0313-001					*  
//;*	機能	      : 復帰不可能エラー処理				*  
//;*	ﾓｼﾞｭｰﾙ名      : SS_ERROR_STOP					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : E = エラー表示データ（下位桁）			*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :	E						*  
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,D,HL					*  
//;*	使用ﾓｼﾞｭｰﾙ    : 						*  
//;************************************************************************  
//;  
//	ハードウェアエラーなのでゲームにはいらない 
void SS_ERROR_STOP(char data)
{
	while(1){
#ifdef	DEBUG_FONT
		FntPrint(dbg_flg.fnt[0],"\nSTOP HARD WARE ERROR!!!!!!!!!!!!!!\n");
		FntPrint(dbg_flg.fnt[0],"ERR = %x\n",data);
#endif
		wait(1);
	}

	DI				//; 割り込み禁止  
//  
//	XOR	A  
//	LD	BC,9*100H OR @OUT0_PORT  
//SS_ERROR_STOP1:  
//	OUT	(C),A			; 出力ポート（０～８）ＯＦＦ  
//	INC	C			; 次の出力ポートアドレス　セット  
//	DJNZ	SS_ERROR_STOP1		; 出力終了？．．ＮＯ  
//  
//	LD	A,@SD_CLEAR0		; 効果音全ﾁｬﾝﾈﾙｸﾘｱ要求　セット  
//	LD	(@SOUND_PORT),A		; 効果音データ　出力  
//  
//	LD	A,10000000B  
//	OUT	(@OUT4_PORT),A		; サウンドデータラッチ　ＯＮ  
//  
//	XOR	A  
//	OUT	(@OUT4_PORT),A		; サウンドデータラッチ　ＯＦＦ  
//  
//	LD	D,79H			; エラー表示（上位桁）　セット  
//	LD	HL,201H  
//	LD	C,@OUT4_PORT  
//SS_ERROR_STOP2:  
//	OUT	(C),A			; ＬＥＤデジット  ＯＦＦ  
//  
//	DEC	C			; // C = @OUT3_PORT  
//	OUT	(C),D			; エラー上位桁表示出力  
//  
//	INC	C			; // C = @OUT4_PORT  
//	OUT	(C),H			; ＬＥＤデジット２  ＯＮ  
//  
//SS_ERROR_STOP3:  
//	DJNZ	SS_ERROR_STOP3		; 表示ウエイト終了？．．ＮＯ  
//  
//	OUT	(C),A			; ＬＥＤデジット  ＯＦＦ  
//  
//	DEC	C			; // C = @OUT3_PORT  
//	OUT	(C),E			; エラー下位桁表示出力  
//  
//	INC	C			; // C = @OUT4_PORT  
//	OUT	(C),L			; ＬＥＤデジット１  ＯＮ  
//  
//SS_ERROR_STOP4:  
//	DJNZ	SS_ERROR_STOP4		; 表示ウエイト終了？．．ＮＯ  
//  
//	JR	SS_ERROR_STOP2  
}

//;************************************************************************  
//;*	管理番号      : S-0314-001					*  
//;*	機能	      : 各種ランプ・効果音データセット２		*  
//;*	ﾓｼﾞｭｰﾙ名      : SS_LPSD_SET					*  
//;*	入力ﾊﾟﾗﾒｰﾀ    : A = 各種ランプ・効果音出力要求			*  
//;*	出力ﾊﾟﾗﾒｰﾀ    :							*  
//;*	保護ﾚｼﾞｽﾀ     :							*  
//;*	破壊ﾚｼﾞｽﾀ     :	A,C,DE,HL					*  
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET,SS_DATA_SET				*  
//;************************************************************************  

void SS_LPSD_SET(char data)
{
	char z_a,z_b,z_c,z_d;
	z_a=data;
//	AND	A			; 出力要求あり？  
//	RET	Z			;   ＮＯ  
	if(z_a==0)	return;
//  
//	LD	HL,TBL_LPSD_REQ - 4  
//	ADD	A,A			; 各種ランプ・効果音出力要求  
//	ADD	A,A			;;テーブル　セット  
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット  

//	EX	DE,HL  
//  
//	LD	A,(DE)  
//	AND	A			; 上部ランプ出力要求？  
//	JR	Z,SS_LPSD_SET1		;   ＮＯ  
	if(TBL_LPSD_REQ[MACINE][data-1][0]){
//  
//; 上部ランプ表示処理  
//  
//	LD	HL,TBL_FLASH_DATA - 2	; 上部ランプ検索テーブル　セット  
//	LD	C,LOW _WK_FLASH_LP;				// 上部ランプ制御データＲＡＭアドレス下位　セット  
//	CALL	SS_DATA_SET		; チャンネルデータセット  
//			↓ 
		_WK_FLASH_LP.lamp=TBL_LPSD_REQ[MACINE][data-1][0];
		_WK_FLASH_LP.time=1;
		_WK_FLASH_LP.rpt=0;
		_WK_FLASH_LP.point=0;
		_WK_FLASH_LP.light=0;
	}
SS_LPSD_SET1: 
//	INC	DE  
//	LD	A,(DE)  
//	AND	A			; 効果ランプ出力要求？  
//	JR	Z,SS_LPSD_SET2		;   ＮＯ  
	if(TBL_LPSD_REQ[MACINE][data-1][1]){

//; 効果ランプ表示処理  
//  
//	LD	HL,TBL_EFFECT_DATA - 2	; 効果ランプ検索テーブル　セット  
//	LD	C,LOW _WK_EFFECT_LP	; 効果ランプ制御データＲＡＭアドレス下位　セット  
//	CALL	SS_DATA_SET		; チャンネルデータセット  
//			↓ 
		_WK_EFFECT_LP.lamp=TBL_LPSD_REQ[MACINE][data-1][1];
		_WK_EFFECT_LP.time=1;
		_WK_EFFECT_LP.rpt=0;
		_WK_EFFECT_LP.point=0;
		_WK_EFFECT_LP.light=0;
	}
//SS_LPSD_SET2:  
//	INC	DE  
//	LD	A,(DE)  
//	AND	A			; バックランプ出力要求？  
//	JR	Z,SS_LPSD_SET3		;   ＮＯ  
	if(TBL_LPSD_REQ[MACINE][data-1][2]){
//  
//; バックランプ表示処理  
//  
//	LD	HL,TBL_BACK_DATA - 2	; バックランプ検索テーブル　セット  
//	LD	C,LOW _WK_BACK_LP	; バックランプ制御データＲＡＭアドレス下位　セット  
//	CALL	SS_DATA_SET		; チャンネルデータセット  
//			↓ 
		_WK_BACK_LP.lamp=TBL_LPSD_REQ[MACINE][data-1][2];
		_WK_BACK_LP.time=1;
		_WK_BACK_LP.rpt=0;
		_WK_BACK_LP.point=0;
		_WK_BACK_LP.light=0;
	}
//SS_LPSD_SET3:  
//	INC	DE  
//	LD	A,(DE)  
//	AND	A			; 効果音出力要求？  
//	RET	Z			;   ＮＯ  
	if(TBL_LPSD_REQ[MACINE][data-1][3]==0)	return;

//; 効果音出力処理  
//	LD	(@SOUND_PORT),A		; 効果音データ　出力  
	SOUND_PORT=TBL_LPSD_REQ[MACINE][data-1][3];	//	音楽ならす番号 
	if(!MACINE){
		switch(SOUND_PORT){
			case KAP_SD_CLEAR0:	//; 効果音全チャンネルクリア  
				game_seq_stop();
			break;
			case KAP_SD_BBEND:	_GSEQ5	//; 役物連続作動増加装置作動終了音  
			break;
			case KAP_SD_START:	_GSE_REEL_START		//; 回胴回転開始音  
			break;
			case KAP_SD_INCO:	_GSE_MEDAL_IN		//; 遊技メダル投入音  
			break;
			case KAP_SD_STOP:	_GSE_REEL_STOP_IN	//; 回胴停止受付音  
			break;
			case KAP_SD_R_STOP:	_GSE_REEL_STOP		//; 回胴停止音  
			break;
			case KAP_SD_WAIT:	_GSE_WAIT			//; 回胴回転不可音  
			break;
			case KAP_SD_PAY:	_GSE_MEDAL_OUT		//; 遊技メダル払出音  
			break;
			case KAP_SD_CLEAR1:		//; 効果音５チャンネルクリア  
			break;
			case KAP_SD_WBL:	_GSE_REECHI			//; 役物連続作動装置・役物連続作動増加装置入賞期待音  
			break;
			case KAP_SD_REPLAY:	_GSE_REPLAY			//; 再遊技作動音  
			break;
			case KAP_SD_BB:		_GSEQ3	//; 役物連続作動増加装置作動音  
			break;
			case KAP_SD_RB:		_GSEQ4	//; 役物連続作動装置作動音  
			break;
			case KAP_SD_BBHIT1:	_GSEQ1	//; 役物連続作動増加装置入賞音１  
			break;
			case KAP_SD_BBHIT2:	_GSEQ2	//; 役物連続作動増加装置入賞音２  
			break;
			case KAP_SD_ALARM:	//; 動作異常警報音  
			break;
		}
	}
	else{
		switch(SOUND_PORT){
			case	BIN_SD_CLEAR0:	//; 効果音全チャンネルクリア 
				game_seq_stop();
			break;
			case	BIN_SD_BBEND:	_GSEQ7	//; 役物連続作動増加装置作動終了音 
			break;
			case	BIN_SD_START:	_GSE_REEL_START	//; 回胴回転開始音 
			break;
			case	BIN_SD_INCO:	_GSE_MEDAL_IN//; 遊技メダル投入音 
			break;
			case	BIN_SD_STOP	:	_GSE_REEL_STOP_IN//; 回胴停止受付音 
			break;
			case	BIN_SD_R_STOP:	_GSE_REEL_STOP	//; 回胴停止音 
			break;
			case	BIN_SD_WAIT	:	_GSE_WAIT		//; 回胴回転不可音 
			break;
			case	BIN_SD_PAY:	_GSE_MEDAL_OUT	//; 遊技メダル払出音 
			break;
			case	BIN_SD_CLEAR1:	//; 効果音５チャンネルクリア 
			break;
			case	BIN_SD_WBL:	_GSE_REECHI	//; 役物連続作動装置・役物連続作動増加装置入賞期待音 
			break;
			case	BIN_SD_REPLAY:	_GSE_REPLAY	//; 再遊技作動音 
			break;
			case	BIN_SD_BB1:	_GSEQ3	//; 役物連続作動増加装置作動音１ 
			break;
			case	BIN_SD_BB2:	_GSEQ4	//; 役物連続作動増加装置作動音２ 
			break;
			case	BIN_SD_BB3:	_GSEQ5	//; 役物連続作動増加装置作動音３ 
			break;
			case	BIN_SD_RB:	_GSEQ6	//; 役物連続作動装置作動音 
			break;
			case	BIN_SD_BBHIT1:	_GSEQ1	//; 役物連続作動増加装置入賞音１ 
			break;
			case	BIN_SD_BBHIT2:	_GSEQ2	//; 役物連続作動増加装置入賞音２ 
			break;
			case	BIN_SD_ALARM:	//; 動作異常警報音 
			break;
		}
	}


//	LD	A,(_PT_OUT4)  
//	SET	7,A  
//	OUT	(@OUT4_PORT),A		; サウンドデータラッチ　ＯＮ  
	OUT4_PORT=(_PT_OUT4|0x80);

//	RES	7,A  
//	OUT	(@OUT4_PORT),A		; サウンドデータラッチ　ＯＦＦ  
	OUT4_PORT=(_PT_OUT4&((0x01<<7)^0xFF));	//	あんまり意味はない 
								//	一回だけならすってことです。 

//	RET  
}	//	void SS_LPSD_SET(void)	//////////////////////////////////////////  


//;************************************************************************  
//;*	管理番号	: S-0315-001										*  
//;*	機能		: チャンネルデータセット							*  
//;*	ﾓｼﾞｭｰﾙ名	: SS_DATA_SET										*  
//;*	入力ﾊﾟﾗﾒｰﾀ	: A = 各種ランプデータ番号							*  
//;*				: HL = 各種ランプ検索テーブル						*  
//;*				: C = 各種ランプ制御データＲＡＭアドレス下位		*  
//;*	出力ﾊﾟﾗﾒｰﾀ	:													*  
//;*	保護ﾚｼﾞｽﾀ	:													*  
//;*	破壊ﾚｼﾞｽﾀ	: A,BC,HL											*  
//;*	使用ﾓｼﾞｭｰﾙ	: S_ADDR_SET										*  
//;************************************************************************  
//;  
#if 0
void SS_DATA_SET(char data ,int *HL,LAMP_DATA *BC)
{
//	LD	B,HIGH @RAM		; <ＲＡＭ上位アドレス> 
//	LD	(BC),A			; データ番号  セット 
	BC->lamp=data;
// 
//	ADD	A,A 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	INC	BC 
//	LD	A,1 
//	LD	(BC),A			; 長さデータ初期値（＝１）  セット 
	BC->time=1;

// 
//	INC	BC 
//	LD	A,(HL) 
//	LD	(BC),A			; 実行アドレス下位  セット 
	*BC=*HL;
// 
//	INC	BC 
//	INC	HL 
//	LD	A,(HL) 
//	LD	(BC),A			; 実行アドレス上位  セット 
// 
//	RET 
}
#endif
// 
//	PAGE 
//;********************************************************************** 
//;*	管理番号      : S-0316-001										* 
//;*	機能	      : 入力ポート０～２読み込み						* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_IN_READ										* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :													* 
//;*	保護ﾚｼﾞｽﾀ     :	DE												* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,HL											* 
//;*	使用ﾓｼﾞｭｰﾙ    : IS_LEVEL_UP										* 
//;********************************************************************** 
//	ボタン入力受付判定 
short pad_pat_data[4][5]={
	{PADR_U,PADR_D,(PADL_D|PADL_U),PAD_R1,PAD_R2},
	{PADR_U,PADR_D,(PADL_D|PADL_U),PAD_R2,PAD_R1},
	{PADL_U,PADR_U,(PADL_D|PADR_D),PAD_R1,PAD_R2},
	{PADR_U,PADR_D,(PADL_U|PAD_R1),PADL_D,PAD_R2},
};

#define PAD_PAY	pad_pat_data[pad_mode][0]
#define PAD_CST	pad_pat_data[pad_mode][1]
#define PAD_STL	pad_pat_data[pad_mode][2]
#define PAD_1BE	pad_pat_data[pad_mode][3]
#define PAD_3BE	pad_pat_data[pad_mode][4]

char	nimai=0;
void IS_IN_READ(void)
{
//; 入力ポート０ (@IN0_PORT)		　　　	     ACTIVE  
IN0_PORT=IN0_POSI^0xff;
IN1_PORT=IN1_POSI^0xff;
IN2_PORT=IN2_POSI^0xff;
	if((pad_beta&PAD_R1)&&(pad_beta&PAD_R2)){
			IN0_PORT^=(0x01<<1);	//２枚投入ボタンスイッチ  
			nimai=1;
	}else{
		if(nimai){
			if((!(pad_beta&PAD_R1))&&(!(pad_beta&PAD_R2))){
				nimai=0;
			}else{
				IN0_PORT^=(0x01<<1);	//２枚投入ボタンスイッチ  
			}
		}else{
			if(pad_beta&PAD_1BE){
				IN0_PORT^=(0x01<<0);	//１枚投入ボタンスイッチ  
			}else{
				if(pad_beta&PAD_3BE){	//３枚投入ボタンスイッチ  
					if((_NB_CREDIT_LED!=0)&&(_NB_CREDIT_LED!=0xFF)){
						IN0_PORT^=(0x01<<2);	//３枚投入ボタンスイッチ  
					}else{
						if(!(_FL_GAME_STS&(0x01<<5))){
							IN1_PORT^=(0x01<<4);	//遊技メダル投入センサー１（先）  
							IN1_PORT^=(0x01<<5);	//遊技メダル投入センサー２（後）  
						}
					}
				}
			}
		}
	}

//	if(pad_beta&PAD_L2)		IN0_PORT^=(0x01<<3);	//遊技メダル払出センサー信号  

	if(pad_beta&PAD_PAY)		IN0_PORT^=(0x01<<4);	//精算ボタンスイッチ  

	if((!(pad_beta&PAD_L1))&&(pad_beta&PAD_STL))
				IN0_PORT^=(0x01<<5);	//回胴回転始動装置スイッチ  

//	if(pad_beta&PADL_D)		IN0_PORT^=(0x01<<6);	//設定用キースイッチ  
//	if(pad_beta&PADL_D)		IN0_PORT^=(0x01<<7);	//打止解除スイッチ  

//; 入力ポート１ (@IN1_PORT)		　　　	     ACTIVE  
//	if(pad_beta&PADR_R)		IN1_PORT^=(0x01<<0);	//自動払戻切替スイッチ  
//	if(pad_beta&PADR_R)		IN1_PORT^=(0x01<<1);	//エラー解除スイッチ  
//	if(pad_beta&PADR_R)		IN1_PORT^=(0x01<<2);	//打止切替スイッチ  
//	if(pad_beta&PADR_R)		IN1_PORT^=(0x01<<3);	//設定ボタンスイッチ  
	if((_PT_OUT1&(0x01<<4))){
#if	DEBUG_MODE==1
		if(pad_trg&PAD_L2){
#else
		if(pad_cnt&PAD_L2){
#endif
			IN1_PORT^=(0x01<<4);	//遊技メダル投入センサー１（先）  
			IN1_PORT^=(0x01<<5);	//遊技メダル投入センサー２（後）  
		}
	}
//	if(pad_beta&PADR_R)		IN1_PORT^=(0x01<<6);	//未使用  
//	if(pad_beta&PADR_R)		IN1_PORT^=(0x01<<7);	//外部打止め解除信号  

//; 入力ポート２ (@IN2_PORT)		　　　	     ACTIVE  
//	if(pad_beta&PAD_L1)		IN2_PORT^=(0x01<<0);	//第１回胴センサー  
//	if(pad_beta&PAD_L1)		IN2_PORT^=(0x01<<1);	//第２回胴センサー  
//	if(pad_beta&PAD_L1)		IN2_PORT^=(0x01<<2);	//第３回胴センサー  
//	if(pad_beta&PAD_L1)		IN2_PORT^=(0x01<<3);	//未使用  
//	if(pad_beta&PAD_L1)		IN2_PORT^=(0x01<<4);	//未使用  
	if(pad_beta&PADR_L)		IN2_PORT^=(0x01<<5);	//本体停止ボタン第１回胴  
	if(pad_beta&PAD_CST)	IN2_PORT^=(0x01<<6);	//本体停止ボタン第２回胴  
	if(pad_beta&PADR_R)		IN2_PORT^=(0x01<<7);	//本体停止ボタン第３回胴  


//	LD	HL,_PT_IN0_OLD 
//	LD	BC,@IN0_POSI*100H +@IN0_PORT	; 入力ポート０正論理ビットデータ・ 
//										;;入力ポート０アドレス　セット 
//	CALL	IS_LEVEL_UP					; 入力ポートレベルデータ・ 
//										;;立ち上がりデータセット 
//	LD	A,D 
//	AND	E 
//	LD	(HL),A							; 入力ポート０  
//										;;立ち下がりデータセット 
//	INC	HL 
//	LD	B,@IN1_POSI			; 入力ポート１正論理ビットデータ　セット 
//	CALL	IS_LEVEL_UP			; 入力ポートレベルデータ・ 
//						;;立ち上がりデータセット 
//	LD	B,@IN2_POSI			; 入力ポート２正論理ビットデータ　セット 
//	CALL	IS_LEVEL_UP			; 入力ポートレベルデータ・ 
//						;;立ち上がりデータセット 
//	RET 

	IS_LEVEL_UP();	//	まとめて３つしています 

}

//;****************************************************************************** 
//;*	管理番号	: S-0317-001												* 
//;*	機能		: 入力ポートレベルデータ・立ち上がりデータセット			* 
//;*	ﾓｼﾞｭｰﾙ名	: IS_LEVEL_UP												* 
//;*	入力ﾊﾟﾗﾒｰﾀ	: B = 入力ポート正論理ビットデータ							* 
//;*				: C = 入力ポートアドレス									* 
//;*				: HL = 入力ポートデータＲＡＭアドレス						* 
//;*	出力ﾊﾟﾗﾒｰﾀ	: C = 入力ポートアドレス									* 
//;*				: D = 前回の入力ポートレベルデータ							* 
//;*				: E = 今回と前回の入力ポートレベル変化ビットデータ			* 
//;*				: HL = 入力ポートデータＲＡＭアドレス						* 
//;*	保護ﾚｼﾞｽﾀ	: B															* 
//;*	破壊ﾚｼﾞｽﾀ	: A,C,DE,HL													* 
//;*	使用ﾓｼﾞｭｰﾙ	:															* 
//;****************************************************************************** 

void IS_LEVEL_UP(void)
{
	char	z_a,z_d,z_e;

//	HL=_PT_IN0_OLD 
//	C=IN0_PORT 

//	IN	A,(C) 
	z_a=IN0_PORT;
//	LD	D,(HL)			; 前回の入力ポートレベルデータ　セット 
	z_d=_PT_IN0_OLD;
//	LD	(HL),A			; 入力ポートレベルデータ　セット 
	_PT_IN0_OLD=z_a;

//	XOR	D 
//	LD	E,A			; 今回と前回の入力ポートレベル変化 
//					;;ビットデータ  セット 
	z_e=(z_a^z_d);
//	LD	A,D 
	z_a=z_d;
//	XOR	B 
	z_a=z_a^IN0_POSI;
//	AND	E 
	z_a=(z_a&z_e);
//	INC	HL			; // HL = _PT_IN?_UP 
//	LD	(HL),A			; 入力ポート立ち上がり 
//						;;データ　セット 
	_PT_IN0_UP=z_a;
//	INC	HL 
//	INC	C			; 次の入力ポートアドレス　セット 
// 

//	LD	A,D 
	z_a=(z_d&z_e);
//	AND	E 
//	LD	(HL),A							; 入力ポート０  
	_PT_IN0_DOWN=z_a;


	z_a=IN1_PORT;
	z_d=_PT_IN1_OLD;
	_PT_IN1_OLD=z_a;
	z_e=(z_a^z_d);
	z_a=z_d;
	z_a=z_a^IN1_POSI;
	z_a=(z_a&z_e);
	_PT_IN1_UP=z_a;

	z_a=IN2_PORT;	//	普段は０？  
	z_d=_PT_IN2_OLD;
	_PT_IN2_OLD=z_a;
	z_e=(z_a^z_d);
	z_a=z_d;
	z_a=z_a^IN2_POSI;
	z_a=(z_a&z_e);
	_PT_IN2_UP=z_a;

//	RET 
}


//;************************************************************************ 
//;*	管理番号      : S-0318-001					* 
//;*	機能	      : タイマ計測					* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_TIME_COUNT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
//; ２バイトタイマ計測 
// 
//	時限処理 
void IS_TIME_COUNT(void)
{
	int i;
//	回胴自動停止時間の判定 
//	LD	HL,_TM2_AUTOSTOP 
//	LD	B,@TM2_NUM		; ２バイトタイマ数  セット 
//IS_TIME_COUNT1: 
	for(i=0;i<_TM2_NUM;i++){

//	LD	E,(HL)			; タイマ値読み込み 
//	INC	HL 
//	LD	D,(HL) 
// 
//	LD	A,D 
//	OR	E			; タイマ値＝０？ 
//	JR	Z,IS_TIME_COUNT2	; 　ＹＥＳ 
	if(TM2_NUM[i]){
// 
//	DEC	DE			; タイマ値１減算 
//	LD	(HL),D 
//	DEC	HL 
//	LD	(HL),E 
//	INC	HL 
	TM2_NUM[i]-=1;
	}
//IS_TIME_COUNT2: 
//	INC	HL			; 次のタイマアドレス　セット 
//	DJNZ	IS_TIME_COUNT1		; ２バイトタイマ計測終了？．．ＮＯ 
	}
// 
//; １バイトタイマ計測 
// 
//	LD	B,@TM1_NUM		; １バイトタイマ数  セット 
//IS_TIME_COUNT3: 
	for(i=0;i<_TM1_NUM;i++){
		if(TM1_NUM[i]){
//	LD	A,(HL) 
//	AND	A			; タイマ値＝０？ 
//	JR	Z,IS_TIME_COUNT4	; 　ＹＥＳ 
// 
//	DEC	(HL)			; タイマ１減算 
			TM1_NUM[i]-=1;
		}
//IS_TIME_COUNT4: 
//	INC	HL			; 次のタイマアドレス　セット 
//	DJNZ	IS_TIME_COUNT3		; １バイトタイマ計測終了？．．ＮＯ 
	}
// 
//	RET 
}

// 
//	PAGE 
//;************************************************************************ 
//;*	管理番号      : S-0319-001					* 
//;*	機能	      : 回胴駆動制御					* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_REEL_CTL					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : C = 回胴番号					* 
//;*			HL = 回胴制御データＲＡＭアドレス		* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :	C						* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : IS_PULSE_OUT,S_ADDR_SET				* 
//;************************************************************************ 
//; 
//; # = 制御中の回胴番号 (= 3,2,1) 
//; 
void IS_REEL_CTL(int no)
{
	char z_a,z_b,z_c;

//	LD	D,H 
//	LD	E,L			; // DE = _WK_REEL# + 0 
// 
//; 停止中（状態＝０） 
// 
//	LD	A,(HL)			; // HL = _WK_REEL# + 0 
	z_a=_WK_REEL[no][0];
//	AND	A			; 停止中？ 
//	RET	Z			; ＹＥＳ 
	if(z_a==0)	return;

//; 加速中（状態＝１） 
//	DEC	A			; 加速中？ 
	z_a-=1;
//	JR	NZ,IS_REEL_CTL2		;   ＮＯ 
	if(z_a)	goto IS_REEL_CTL2;

// 
//	INC	HL			; // HL = _WK_REEL# + 1 
//	DEC	(HL)			; 加速時パルスカウンタ  －１ 
//	_WK_REEL[no][1]--; 
//	RET	NZ			; カウント終了？．．ＮＯ 
//	if(_WK_REEL[no][1])	return; 

//	DEC	HL			; // HL = _WK_REEL# + 0 
//	CALL	IS_PULSE_OUT		; 回胴駆動パルスセット 
	IS_PULSE_OUT(no);		//; 回胴駆動パルスセット 
// 
//	INC	HL 
//	INC	HL			; // HL = _WK_REEL# + 2 
//	DEC	(HL)			; 加速カウンタ　－１ 
	_WK_REEL[no][2]--;
//	JR	Z,IS_REEL_CTL1		; カウント終了？．．ＹＥＳ 
	if(!_WK_REEL[no][2])	goto IS_REEL_CTL1;

// 
//	LD	A,(HL)			; // HL = _WK_REEL# + 2 
//	LD	HL,TBL_PULSE_UP - 1 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	LD	A,(HL)			; 加速カウント値　取り出し 
//	z_a=TBL_PULSE_UP[_WK_REEL[no][2]]; 
// 
//	INC	DE			; // DE = _WK_REEL# + 1 
//	LD	(DE),A			; 加速時パルスカウンタ　セット 
//	_WK_REEL[no][1]=z_a; 
// 
//	RET 
	return;
// 
IS_REEL_CTL1:
//	LD	A,2			; // DE = _WK_REEL# + 0 
//	LD	(DE),A			; 定速状態　セット 
	_WK_REEL[no][0]=2;
// 
//	RET 
	return;
// 
//; 定速中（状態＝２） 
// 
IS_REEL_CTL2:
	z_a--;
//	DEC	A			; 定速中？ 
//	JR	NZ,IS_REEL_CTL5		;   ＮＯ 
	if(z_a)	goto IS_REEL_CTL5;

//	CALL	IS_PULSE_OUT		; 回胴駆動パルスセット 
	IS_PULSE_OUT(no);		//; 回胴駆動パルスセット 
// 
//	LD	A,(_PT_IN2_UP) 
//	LD	B,C 
	z_a=_PT_IN2_UP;
	z_b=z_c;
IS_REEL_CTL3:
//	RRCA				; 制御回胴の回胴センサー？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
	z_b-=1;
//	DJNZ	IS_REEL_CTL3		;   ＮＯ 
	if(z_b)	goto IS_REEL_CTL3;
// 
//	INC	HL 
//	INC	HL 
//	INC	HL			; // HL = _WK_REEL# + 3 
// 
//	JR	NC,IS_REEL_CTL4		; 回胴センサー通過？．．ＮＯ 
	if(!(z_a&(0x01<<no)))	goto IS_REEL_CTL4;
// 
//	LD	(HL),0FFH		; 回胴センサー通過フラグ　セット 
//	_WK_REEL[no][3]=0xFF; 

//	INC	HL			; // HL = _WK_REEL# + 4 

//	LD	(HL),20		 	; １図柄のステップ数  セット 
//	_WK_REEL[no][4]=20;	//	あまり意味はない。  

//	INC	HL			; // HL = _WK_REEL# + 5 
//					; // B = 0 
//	LD	(HL),B			; 図柄番号０  セット 
//	_WK_REEL[no][5]=0; 
// 
//	RET 
	return;
// 
IS_REEL_CTL4:
//	INC	HL			; // HL = _WK_REEL# + 4 
//	DEC	(HL)			; １図柄のステップ数　－１ 
//	_WK_REEL[no][4]-=1; 
//	RET	NZ			; １図柄分動いた？．．ＮＯ 
//	if(_WK_REEL[no][4])	return; 

// 
//	LD	(HL),19		 	; １図柄のステップ数  セット 
//	_WK_REEL[no][4]=19; 
//	INC	HL			; // HL = _WK_REEL# + 5 
//	INC	(HL)			; 図柄番号　＋１ 
//	_WK_REEL[no][5]+=1;	//	これを入れたらだめです 

// 
//	RET 
	return;
// 
//; 減速開始（状態＝３） 
// 
IS_REEL_CTL5:
//	DEC	A			; 減速開始？ 
	z_a--;
//	JR	NZ,IS_REEL_CTL7		;   ＮＯ 
	if(z_a)	goto IS_REEL_CTL7;

//	CALL	IS_PULSE_OUT		; 回胴駆動パルスセット 
//	IS_PULSE_OUT(no);		//; 回胴駆動パルスセット 

// 
//	LD	A,4  
	z_a=4;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	PUSH	HL			; // HL = _WK_REEL# + 4 
// 
//	DEC	(HL)			; １図柄のステップ数　－１ 
//	_WK_REEL[no][4]-=1; 
//	JR	NZ,IS_REEL_CTL6		; １図柄分動いた？．．ＮＯ 

//	if(_WK_REEL[no][4]) goto IS_REEL_CTL6; 
// 
//	LD	(HL),19		 	; １図柄のステップ数  セット 
//	_WK_REEL[no][4]=19; 

//	INC	HL			; // HL = _WK_REEL# + 5 
//	INC	(HL)			; 図柄番号　＋１ 

	z_a=_WK_REEL[no][5];
// 
//	LD	A,(HL) 
//	SUB	21			; 図柄番号２０以下？ 
//	JR	C,IS_REEL_CTL6		;   ＹＥＳ 

	if(_WK_REEL[no][5]<21)	goto IS_REEL_CTL6;

// 
//	LD	(HL),A			; 図柄番号修正（０～２０） 
// 
//	JR	NZ,IS_REEL_CTL6		; 図柄番号０に修正？．．ＮＯ 
// 
//	DEC	HL			; // HL = _WK_REEL# + 4 
//	INC	(HL)			; １図柄のステップ数修正 
//	_WK_REEL[no][5]=0;	//	入れたらだめ！ 
//	_WK_REEL[no][4]=20; 

// 
IS_REEL_CTL6:
//	POP	HL 
//	LD	A,(HL)			; // HL = _WK_REEL# + 4 
//	CP	17			; 停止開始ステップ？ 
//	RET	NC			; 　ＮＯ 
//	z_a=_WK_REEL[no][4]; 
//	if(z_a>=17)	return; 

// 
//	INC	HL			; // HL = _WK_REEL# + 5 
//	LD	A,(HL) 

	z_a=_WK_REEL[no][5];
//	INC	HL			; // HL = _WK_REEL# + 6 
//	CP	(HL)			; 停止図柄位置？ 
//	RET	NZ			; 　ＮＯ 
	if((z_a-_WK_REEL[no][6])!=0)	return;	//	停止図柄か？ 

//	if(z_a!=10)	return;	//	停止図柄か？ 


//		ここから				///////////////////////////////////////////// 
//	LD	L,LOW _PT_OUT0 - 1 
//	LD	A,C			; 回胴番号　セット	C=no 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	LD	A,(HL) 
//	OR	0FH 
//	LD	(HL),A			; 減速時パルスデータ  セット 
//					;;（４相ＯＮ） 
//			ここまでが　↓　これ	///////////////////////////////////////// 
	_PT_OUT[no]=(_PT_OUT[no]|0x0F);

// 
//	EX	DE,HL			; // HL = _WK_REEL# + 0 
//	LD	(HL),4			; 減速状態　セット 

	_WK_REEL[no][0]=4;

//	INC	HL			; // HL = _WK_REEL# + 1 
//	LD	(HL),214		; 減速時パルスカウンタ　セット 
//	_WK_REEL[no][1]=214; 
// 
//	RET 
	return;
// 
//; 減速中（状態＝４） 
// 
IS_REEL_CTL7:
//	INC	HL			; // HL = _WK_REEL# + 1 
//	DEC	(HL)			; 減速時パルスカウンタ  －１ 
	_WK_REEL[no][1]-=1;
//	RET	NZ			; カウント終了？．．ＮＯ 

//	if(_WK_REEL[no][1])	return; 

// 
//	LD	L,LOW _PT_OUT0 - 1 
//	LD	A,C			; 回胴番号　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	LD	A,(HL) 
//	AND	0F0H 
//	LD	(HL),A			; 駆動パルス　クリア 
	_PT_OUT[no]=(_PT_OUT[no]&0xF0);

// 
//	XOR	A			; // DE = _WK_REEL# + 0 
//	LD	(DE),A			; 停止状態　セット 
	_WK_REEL[no][0]=0;
// 
//	RET 
}
// 
//	PAGE 
//;************************************************************************ 
//;*	管理番号      : S-0320-001					* 
//;*	機能	      : 回胴駆動パルスセット				* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_PULSE_OUT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : C = 回胴番号					* 
//;*			HL = 回胴制御データＲＡＭアドレス		* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :	C,HL						* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET					* 
//;************************************************************************ 
//; 
//; # = 制御中の回胴番号 (= 3,2,1) 
//; 
void IS_PULSE_OUT(int no)
{
//	PUSH	HL 
// 
//	LD	A,7 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//					; // HL = _WK_REEL# + 7 
//	INC	(HL)			; 回胴駆動パルスデータ検索用 
	_WK_REEL[no][7]+=1;

//		ここから				///////////////////////////////////////////// 
//	LD	A,(HL)			;;カウンタ　＋１ 
//	AND	111B 

//	LD	HL,TBL_REEL_PULSE 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	LD	B,(HL)			; 回胴駆動パルスデータ　取り出し 
//	wk=TBL_REEL_PULSE[(_WK_REEL[no][7]&=0x07)]; 
// 
//	LD	HL,_PT_OUT0 - 1 
//	LD	A,C			; 回胴番号　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	LD	A,(HL) 
//	AND	0F0H 
//	OR	B 
//	LD	(HL),A			; 回胴駆動パルスデータ　セット 
//		ここまで	↓　これ	//////////////////////////////////////////// 

	_PT_OUT[no]=((_PT_OUT[no]&0xF0)|(TBL_REEL_PULSE[(_WK_REEL[no][7]&=0x07)]));
// 
//	POP	HL 
// 
//	RET 
}


//;************************************************************************ 
//;*	管理番号      : S-0321-001					* 
//;*	機能	      : 外部信号出力					* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_COUNTER_OUT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
void IS_COUNTER_OUT(void)
{
	char	wk=0;

//	 
//; 遊技メダル投入信号及び遊技メダル払出信号　出力 
// 
//	LD	HL,_TM1_OUT_CNT 
//	LD	A,(HL) 
//	AND	A			; 外部信号出力時間終了？ 
//	RET	NZ			; 　ＮＯ 
	if(!_TM1_OUT_CNT){
// 
//	LD	(HL),@TM_COUNT		; 外部信号出力時間　セット 
		_TM1_OUT_CNT=TM_COUNT;

// 
//	LD	BC,200H			; // B = 2 (IN & OUT) , C = 0 
//	LD	L,LOW _CT_MEDAL_IN 	; // HL = _CT_MEDAL_IN 
//IS_COUNTER_OUT2: 
//	LD	A,(HL) 
//	AND	A			; 外部信号出力要求あり？ 
//	JR	Z,IS_COUNTER_OUT3	; 　ＮＯ 
		if(!_CT_MEDAL_IN){
// 
//	DEC	(HL) 
			_CT_MEDAL_IN-=1;
			wk=0x10;
//	SET	6,C			; 該当する出力データビット　ＯＮ 

		}
		if(!_CT_MEDAL_OUT){
			_CT_MEDAL_OUT-=1;
			wk=(wk|0x20);
		}

//IS_COUNTER_OUT3: 
//	RRC	C 
//	INC	HL			; 次の出力データＲＡＭアドレス　セット 
//					; // HL = _CT_MEDAL_OUT 
//	DJNZ	IS_COUNTER_OUT2		; 出力データ数終了？．．ＮＯ 

// 
//	LD	L,LOW _PT_OUT0 
//	LD	A,C 
//	OR	11001111B 
//	AND	(HL)			; 出力ビットＯＮ／ＯＦＦの反転 
//	XOR	C 
//	LD	(HL),A			; 遊技メダル投入信号及び遊技メダル 
//					;;払出信号出力データ　セット 
	_PT_OUT0=(_PT_OUT0^(wk|0xCF));
	}
//	RET 
}
// 
//	PAGE 
//;************************************************************************ 
//;*	管理番号      : S-0300-001					* 
//;*	機能	      : プログラム開始  （続き）			* 
//;*	ﾓｼﾞｭｰﾙ名      : M_PRG_START					* 
//;************************************************************************ 
//; 
//M_PRG_START1: 

void M_PRG_START1(void)
{

//; ＲＯＭのサムチェック 
// 
//	XOR	A; 
//	LD	HL,M_PRG_START; 
//	あんまり意味無いけど覚えておくように 

//	LD	BC,1CH 

// 
//////////////////////////////////////////// 
//	ＲＯＭのチェックなのでいらない　ここから 
//M_PRG_START2: 
//	ADD	A,(HL)			; ＲＯＭチェックサム算出 
//	INC	HL			;;(0000H - 1BFFH) 
//	DJNZ	M_PRG_START2		; ２５６バイト算出終了？．．ＮＯ 
// 
//	DEC	C			; 全バイト算出終了？ 
//	JR	NZ,M_PRG_START2		;   ＮＯ 
// 
//	AND	A			; ＲＯＭチェックサム正常？ 
//	JR	Z,M_PRG_START4		;   ＹＥＳ 
// 
//M_PRG_START3: 
//	JR	M_PRG_START3    	; 無限ループ（ＲＯＭ異常） 
// 
//	ＲＯＭのチェックなのでいらない　ここまで 
//////////////////////////////////////////// 
//; ＣＰＵ・周辺デバイス初期設定 
// 
//M_PRG_START4: 
//	LD	HL,TBL_AMUSE_SET	; ＬＥ１０８０Ａ初期化 
//							;;テーブル  セット 
//	LD	B,29				; 設定数　セット 
//	LD	D,0FFH 
//M_PRG_START5: 
//	LD	E,(HL) 
//	INC	HL 

//	LD	A,(HL)			; // DE = アドレス(FF14H)＜ＲＡＭ領域 
//	INC	HL 

//	LD	(DE),A			; データセット 
							//	ＲＡＭ領域に書き込み・・・ 
							//	この時点でＡは０  
							// 
//	DJNZ	M_PRG_START5		; 設定終了？．．ＮＯ 

//; 効果音消音 
// 
//	LD	A,@SD_CLEAR0		; 効果音全ﾁｬﾝﾈﾙｸﾘｱ要求　セット 
// 
//	LD	(@SOUND_PORT),A		;;効果音データ　出力 
	SOUND_PORT=SD_CLEAR0;

//	LD	A,10000000B 
//	OUT	(@OUT4_PORT),A		; サウンドデータラッチ　ＯＮ 
	OUT4_PORT=0x80;
// 
//	XOR	A 
//	OUT	(@OUT4_PORT),A		; サウンドデータラッチ　ＯＦＦ 
	OUT4_PORT=0;
// 
//; 設定値変更・ＲＡＭ初期化・電断復帰の各モード選択 
// 
//	IN	A,(@IN0_PORT) 
//	BIT	6,A			; 設定用キースイッチＯＮ？ 
//	JR	Z,M_PRG_START7		; 　ＮＯ 

#if HIGH_LOT
//	_NB_RANK=6;
#endif
	if(!(IN0_PORT&0x40))	goto M_PRG_START7;


//	LD	SP,@STACK		; スタックポインタ　セット 
// 
//	LD	HL,_NB_RANK 
//	LD	A,(HL) 
//	DEC	A 
//	CP	6			; 設定値　正常範囲？ 
//	JR	C,M_PRG_START6		; 　ＹＥＳ 

//	_NB_RANK=6;
	if(_NB_RANK<6)	goto M_PRG_START6;

//	LD	A,(TBL_INIT_RANK) 
//	LD	(HL),A			; 設定値（自動）　セット 
	_NB_RANK=TBL_INIT_RANK;

M_PRG_START6:
//	CALL	MS_RAM_CHK		; ＲＡＭチェック・初期化 
// 
//	CALL	MS_PCT_ON		; ＰＣＴ０／ＰＣＴ１タイマ起動 
//	MS_PCT_ON();		//; ＰＣＴ０／ＰＣＴ１タイマ起動 
// 
	EI				//; 割り込み許可 
// 
//	CALL	MS_RANK_SET		; 設定値変更 
	MS_RANK_SET();		//; 設定値変更 
// 
	DI				//; 割り込み禁止 
// 
//	CALL	MS_RAM_CHK		; ＲＡＭチェック・初期化 
// 
//	JR	M_PRG_START8 
	goto M_PRG_START8;
M_PRG_START7:
//	IN	A,(@IN1_PORT) 
//	BIT	3,A			; 設定ボタンスイッチ　ＯＮ？ 
//	JR	Z,M_POWER_ON		; 　ＮＯ 
//	LD	SP,@STACK		; スタックポインタ　セット 
// 
//	CALL	MS_RKER_CHK		; 設定値エラーチェック 
// 
//	CALL	MS_RAM_CHK		; ＲＡＭチェック・初期化 
	MS_RAM_CHK();		//; ＲＡＭチェック・初期化 
// 
//	CALL	MS_PCT_ON		; ＰＣＴ０／ＰＣＴ１タイマ起動 
// 
M_PRG_START8:

	EI				//; 割り込み許可 
// 
//	CALL	MS_BB_SET		; 役物連続作動増加装置作動終了後の設定 
	MS_BB_SET();
 
//	I_INTR();	//	わりこませる前に、一度通して、初期化する  
//	drum_spin();	//	ドラムの回転制御  
//	lamp_on_off(); 
	slot_data_read();

	hd_inter=1;
	I_INTR();	//	わりこませる前に、一度通して、初期化する  
	wait(2);
//	_NB_RANK=6;


	while(1){
		M_MAIN();
//		FntPrint(dbg_flg.fnt[0],"\nIKETERU ! \n"); 
		wait(1);
	}

	hd_inter=0;
}

//;************************************************************************ 
//;*	管理番号      : S-0301-001					* 
//;*	機能	      : 電断復帰					* 
//;*	ﾓｼﾞｭｰﾙ名      : M_POWER_ON					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	E = エラー表示データ（下位桁）			* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL,BC',DE',HL'				* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_RKER_CHK,S_RAM_CLEAR,MS_PCT_ON,MS_BB_SET	* 
//;*		      : SS_ERROR_STOP（ジャンプ）			* 
//;************************************************************************ 
//; 
void M_POWER_ON(void)
{
//	LD	A,(_FL_GAME_STS) 
//	AND	01000000B		; 電断処理済み？ 
//	JR	Z,M_POWER_ON3		; 　ＮＯ 
// 
//	LD	HL,(_BF_STACK) 
//	LD	DE,81C2H		; // @STACK - 62 
//	SBC	HL,DE			; 保存スタックのアドレス範囲外？ 
//	JR	C,M_POWER_ON3		;   ＹＥＳ 
// 
//	XOR	A 
//	LD	HL,@RAM 
//	LD	BC,2 
//M_POWER_ON1: 
//	ADD	A,(HL)			; ＲＡＭチェックサム算出 
//	INC	HL			;;(8000H - 81FFH) 
//	DJNZ	M_POWER_ON1		; ２５６バイト算出終了？．．ＮＯ 
// 
//	DEC	C			; 全バイト算出終了？ 
//	JR	NZ,M_POWER_ON1		;   ＮＯ 
// 
//	AND	A			; ＲＡＭチェックサム正常？ 
//	JR	NZ,M_POWER_ON3		;   ＮＯ 
// 
//	LD	SP,(_BF_STACK)	 	; スタックポインタ復帰 
// 
//	CALL	MS_RKER_CHK		; 設定値エラーチェック 
// 
//	LD	HL,TBL_RAM_CLEAR1	; 電断復帰時のＲＡＭ初期化用 
//							;;テーブル　セット 
//	RST	S_RAM_CLEAR		; ＲＡＭ初期化 <808FH - 81BFH> 
	S_RAM_CLEAR(1);		//; ＲＡＭ初期化 <808FH - 81BFH> 
	bzero(kbr,sizeof(SAVE2));

// 
//	CALL	MS_PCT_ON		; ＰＣＴ０／ＰＣＴ１タイマ起動 
// 
//	CALL	MS_BB_SET		; 役物連続作動増加装置作動終了後の設定 
	MS_BB_SET();		//; 役物連続作動増加装置作動終了後の設定 
// 
//	IN	A,(@IN0_PORT) 
//	LD	(_PT_IN0_OLD),A		; 入力ポート０レベルデータ　セット 
	_PT_IN0_OLD=IN0_PORT;

// 
//	IN	A,(@IN1_PORT) 
//	LD	(_PT_IN1_OLD),A		; 入力ポート１レベルデータ　セット 
	_PT_IN1_OLD=IN1_PORT;
// 
//	IN	A,(@IN2_PORT) 
//	LD	(_PT_IN2_OLD),A		; 入力ポート２レベルデータ　セット 
	_PT_IN2_OLD=IN2_PORT;
// 
//	LD	HL,_FL_GAME_STS 
//	SET	1,(HL)			; 連続音復帰要求フラグ　セット 
//	RES	6,(HL)			; 電断処理済みフラグ　クリア 
	_FL_GAME_STS=(_FL_GAME_STS|(0x01<<1));
	_FL_GAME_STS&=((0x01<<6)^0xFF);

//	POP	HL			; 使用レジスタ復帰（ＡＦレジスタ以外） 
//	POP	DE 
//	POP	BC 
//	EXX 
//	POP	HL 
//	POP	DE 
//	POP	BC 
// 
//	POP	AF			; 電断時の割り込み禁止／許可状態　復帰 
//					; // Ｆレジ　BIT2 ON   割り込み許可 
//					; //              OFF  割り込み禁止 
//	JP	PO,M_POWER_ON2		; 割り込み許可？．．ＮＯ 
// 
//	POP	AF			; ＡＦレジスタ復帰 
// 
	EI				//; 割り込み許可 
// 
//	RETN 
// 
//M_POWER_ON2: 
//	POP	AF			; ＡＦレジスタ復帰 
//	RETN 
// 
//; 電断エラー 
// 
//M_POWER_ON3: 
//	LD	E,06H			; ”Ｅ１”表示要求  セット 
//	JP	SS_ERROR_STOP 

}


//;************************************************************************ 
//;*	管理番号      : S-0302-001					* 
//;*	機能	      : 遊技進行メイン					* 
//;*	ﾓｼﾞｭｰﾙ名      : M_MAIN						* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_STOP_LED,S_RAM_CLEAR,MS_RAM_SET,MS_GAME_SET	* 
//;*		      : MS_BNSCT_DSP,S_BLOCKER_ON,S_LPSD_SET		* 
//;*		      : MS_RANK_DSP,S_WATCH_CLEAR,MS_HOPPER_CHK		* 
//;*		      : MS_CREDIT_CHK,MS_CANCEL_CHK,MS_INSERT_CHK	* 
//;*		      : MS_START_CHK,S_BLOCKER_OFF,MS_AUTO_IN		* 
//;*		      : MS_SCOUNT_OUT,MS_RKER_CHK,MS_ALL_LOT		* 
//;*		      : MS_WAIT_CHK,MS_REEL_READY,MS_REEL_START		* 
//;*		      : MS_HIT_SET,MS_RLSTOP_SET,MS_RLERR_CHK		* 
//;*		      : MS_RLFIX_CHK,MS_STOP_CHK,MS_PIC_CTL		* 
//;*		      : MS_RLSTP_CHK,MS_WIN_JUDGE,MS_WIN_PAY		* 
//;*		      : MS_GAME_CHK					* 
//;************************************************************************ 
// 
//; 遊技初期化 

void M_MAIN(void)
{
	win_deru_ok=1;

//	LD	B,0011 1000B		; 停止ボタンＬＥＤ点灯要求　セット 
	z_b=0x38;
//	CALL	MS_STOP_LED		; 停止ボタンＬＥＤ表示 
	MS_STOP_LED(z_b);		//; 停止ボタンＬＥＤ表示 

//	LD	HL,@TM_BACK_OFF 
//	LD	(_TM2_BACK_OFF),HL	; 遊技待機時の表示待機時間　セット  
	_TM2_BACK_OFF=TM_BACK_OFF;	//	タイマ初期化 TM_BACK_OFF=31990  

//	ここからいらない 
// 
//	LD	HL,TBL_RAM_CLEAR2	; 遊技開始時のＲＡＭ初期化用 
//					;;テーブル　セット 
//	RST	S_RAM_CLEAR		; ＲＡＭ初期化 <808FH - 81E9H> 
	S_RAM_CLEAR(2);		//; ＲＡＭ初期化 <808FH - 81E9H> 

#if 0
	while(1){
#ifdef	DEBUG_FONT
	FntPrint(dbg_flg.fnt[0],"\nMEDAL MAX %d\n",_NB_PLAY_MEDAL);
#endif
		wait(1);
	}
#endif
	DI				//; 割り込み禁止 

//	LD	HL,81EAH		; ＲＡＭ初期化先頭アドレス　セット 
//	LD	BC,22*100H		; ＲＡＭ初期化範囲　セット 
//					; < 割り込み時最大スタック使用量＋２バイト > 
//M_MAIN1: 
//	LD	(HL),C			; ＲＡＭ初期化 <81EAH - 81FFH> 
//	INC	HL			; 次のＲＡＭアドレス　セット 
//	DJNZ	M_MAIN1			; ＲＡＭ初期化終了？．．ＮＯ 
// 
	EI				//; 割り込み許可 

//	ここまでいらない 


//	CALL	MS_RAM_SET		; ＲＡＭ初期データセット 
	z_c=MS_RAM_SET();		//; ＲＡＭ初期データセット 

//	CALL	MS_GAME_SET		; 遊技開始セット  
	MS_GAME_SET(z_c);		//; 遊技開始セット  

//	CALL	MS_BNSCT_DSP	; 遊技回数表示  
	MS_BNSCT_DSP();			//; 遊技回数表示 


//	LD	A,(_FL_ACTION) 
	z_a=_FL_ACTION;
//	RRCA				; 再遊技作動時？ 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
//	JR	C,M_MAIN5		;   ＹＥＳ  
		goto M_MAIN5;
	}
	else	z_a=(z_a>>1);

//; 再遊技作動時以外の遊技メダル投入、回胴回転始動装置　受付処理 

//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 
	S_BLOCKER_ON();		//; 遊技メダルブロッカーＯＮ<通過状態> 

M_MAIN2:
//;	遊技待機時の表示処理  

	if(!MACINE){	//	かっぱ 
//	LD	A,(_WK_BACK_LP) 
	z_a=_WK_BACK_LP.lamp;
//	CP	@BLP_SAVER		; バックランプ(ﾊﾟﾀｰﾝ2)出力中？ 
//	JR	Z,M_MAIN3		;   ＹＥＳ 
	if((z_a==BLP_SAVER))	goto M_MAIN3;

//	LD	HL,(_TM2_BACK_OFF) 
//	LD	A,H 
//	OR	L			; 遊技待機表示時間？ 
//	JR	NZ,M_MAIN3		;   ＮＯ 
		if(_TM2_BACK_OFF)	goto M_MAIN3;

//	LD	A,@SET_SAVER		; 遊技待機時の出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
		z_a=SET_SAVER;
		S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

	}else{	//	ビンビン 
//	LD	HL,(_TM2_BACK_OFF) 
//	LD	A,H 
	z_a=_TM2_BACK_OFF;
//	OR	L			; 遊技待機表示時間？ 
//	JR	NZ,M_MAIN3		;   ＮＯ 
		if(z_a)	goto M_MAIN3;

//	LD	HL,_WK_BACK_LP 
//	LD	(HL),A			; バックランプ表示要求　クリア 
		_WK_BACK_LP.lamp=z_a;
//	LD	L,LOW _PT_OUT7 
//	RES	7,(HL)			; バックランプ消灯　セット 
		_PT_OUT7&=((0x01<<7)^0xFF);
//	INC	HL			; // HL = _PT_OUT8 

//	LD	(HL),A 
		_PT_OUT8=z_a;
	}

M_MAIN3:
//	CALL	MS_RANK_DSP		; 設定値表示 
	MS_RANK_DSP();		//; 設定値表示 

M_MAIN4:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
//	S_WATCH_CLEAR();	//	; ウォッチドッグクリア 
// 
//	CALL	MS_HOPPER_CHK		; 遊技メダル払出センサーチェック 
	MS_HOPPER_CHK();		//; 遊技メダル払出センサーチェック 

//	CALL	MS_CREDIT_CHK		; 投入ボタンチェック 
	MS_CREDIT_CHK();			//; 投入ボタンチェック 

//	CALL	MS_CANCEL_CHK		; 精算ボタンチェック 
	MS_CANCEL_CHK();			//; 精算ボタンチェック 

//	CALL	MS_INSERT_CHK		; 遊技メダル投入チェック 
	MS_INSERT_CHK();			//; 遊技メダル投入チェック 

//	LD	A,(_NB_PLAY_MEDAL) 
	z_a=_NB_PLAY_MEDAL;
//	AND	A			; 遊技メダルなし？ 
//	JR	Z,M_MAIN2		;   ＹＥＳ 
#ifdef	DEBUG_FONT
	FntPrint(dbg_flg.fnt[0],"\nMEDAL MAX %d\n",_NB_PLAY_MEDAL);
#endif
	wait(1);
	if(!z_a)	goto M_MAIN2;

//	CALL	MS_START_CHK	//; 回胴回転始動装置チェック 
//	MS_START_CHK();			//; 回胴回転始動装置チェック 
//							//; （ハードウェア乱数読み込み・保存） 
//	JR	NC,M_MAIN4		; 受付？．．ＮＯ 
	if(!MS_START_CHK())	goto M_MAIN4;

//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 

//	JR	M_MAIN7 
	goto M_MAIN7;

//; 再遊技作動時の遊技メダル投入処理 
M_MAIN5:
//	CALL	MS_AUTO_IN		; 遊技メダル自動投入 
	MS_AUTO_IN();			//; 遊技メダル自動投入 

//; 再遊技作動時の回胴回転始動装置  受付処理 
M_MAIN6:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
//	CALL	MS_HOPPER_CHK		; 遊技メダル払出センサーチェック 
	MS_HOPPER_CHK();				//; 遊技メダル払出センサーチェック 

//	CALL	MS_START_CHK		; 回胴回転始動装置チェック 
//								; // （ハードウェア乱数読み込み・保存） 
//	JR	NC,M_MAIN6		; 受付？．．ＮＯ 
	if(!MS_START_CHK())	goto M_MAIN6;

//; 抽選 
M_MAIN7:
	win_deru_ok=0;
//	CALL	MS_SCOUNT_OUT		; 外部信号出力要求 
	MS_SCOUNT_OUT();				//; 外部信号出力要求 

//	CALL	MS_RKER_CHK		; 設定値エラーチェック 
	MS_RKER_CHK();			//; 設定値エラーチェック 

//	CALL	MS_ALL_LOT		; 抽選 
	MS_ALL_LOT();			//; 抽選 

//; 回胴回転待機 
// 
M_MAIN8:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	CALL	MS_WAIT_CHK		; 最短遊技時間チェック 
//							; // （回胴回転不可音・ウエイト表示） 
//	JR	NC,M_MAIN8			; 回胴回転許可？．．ＮＯ 
	wait(1);
	if(!MS_WAIT_CHK())	goto M_MAIN8;

//; 回胴回転開始 
// 
//	CALL	MS_REEL_READY		//; 回胴回転開始準備 
	MS_REEL_READY();			//; 回胴回転開始準備 

	play_num+=1;

//	LD	A,11100000B		; 全回胴回転ビット  セット 


//M_MAIN9: 
//	CALL	MS_REEL_START		//; 回胴回転開始 
	MS_REEL_START(0xE0);		//; 回胴回転開始 
// 
//	LD	B,00111000B			//; 停止ボタンＬＥＤ点灯要求　セット 
//	CALL	MS_STOP_LED		//; 停止ボタンＬＥＤ表示 
	MS_STOP_LED(0x38);		//; 停止ボタンＬＥＤ表示 

//; 回胴回転中  
M_MAIN10:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 

	MS_HIT_SET();		//; 入賞期待時の出力セット 


// 
//	CALL	MS_RLSTOP_SET		; 回胴停止時の出力セット 

	MS_RLSTOP_SET();		//; 回胴停止時の出力セット 

// 
//	CALL	MS_RLERR_CHK		; 回胴回転エラーチェック 
//	要らないのでは？？ 

//	MS_RLERR_CHK();		//; 回胴回転エラーチェック 
//	JR	C,M_MAIN9		; 回胴再起動？．．ＹＥＳ 
// 
//	CALL	MS_RLFIX_CHK		; 回胴定速チェック 
//	要らないのでは？？ 
//	MS_RLFIX_CHK();		//; 回胴定速チェック 
//	JR	NC,M_MAIN10		; 定速？．．ＮＯ 
	if(!MS_RLFIX_CHK()) goto M_MAIN10;

//	CALL	MS_STOP_CHK	 	; 回胴停止受付チェック 

	if(MS_STOP_CHK()){ 		//; 回胴停止受付チェック OK 
//	CALL	C,MS_PIC_CTL		; 回胴停止受付？．．ＹＥＳ 
//ddddddddddddddddd
		MS_PIC_CTL();				//; 回胴停止受付？．．ＹＥＳ 
//									; 図柄組合せ制御 
	}
 
//	CALL	MS_RLSTP_CHK		; 全回胴停止チェック 
//	JR	NZ,M_MAIN10		; 全回胴停止？．．ＮＯ 

//	FntPrint(dbg_flg.fnt[0],"\nSTOP REEL %d\n",_NB_STOP_REEL);

	wait(1);
	if(MS_RLSTP_CHK())	goto M_MAIN10;
//	wait(1);

//; 入賞判定 
//	ここまで正常！ 
// 
//	CALL	MS_WIN_JUDGE		; 入賞判定 
	MS_WIN_JUDGE();		//; 入賞判定 

//	CALL	MS_WIN_PAY		; 入賞による遊技メダル払出し 
		MS_WIN_PAY();		//; 入賞による遊技メダル払出し 

//	CALL	MS_GAME_CHK		; 遊技終了チェック 

	MS_GAME_CHK();		//; 遊技終了チェック 

//	JP	M_MAIN	//	永久ループ大作戦 



//	DEB_STOP2(p_p);

}


//;************************************************************************ 
//;*	管理番号      : S-0322-001					* 
//;*	機能	      : ＲＡＭチェック・初期化				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RAM_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	E = エラー表示データ（下位桁）			* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : SS_ERROR_STOP（ジャンプ）			* 
//;************************************************************************ 

void MS_RAM_CHK(void)
{

//	POP	DE			; 戻り番地  退避 
// 
//	LD	HL,8001H		; ＲＡＭ初期化先頭アドレス  セット 
//	LD	BC,01FFH		; ＲＡＭ初期化範囲  セット 
//MS_RAM_CHK1: 
//	LD	A,55H			; チェックデータ　書き込み 
//	LD	(HL),A 
//	CP	(HL)			; 01010101B チェック　正常？ 
//	JR	NZ,MS_RAM_CHK2		; 　ＮＯ 
// 
//	CPL				; チェックデータ　書き込み 
//	LD	(HL),A 
//	SUB	(HL)			; 1010 1010B チェック　正常？ 
//	JR	NZ,MS_RAM_CHK2		; 　ＮＯ 
// 
//	LD	(HL),A			; 初期化 
//	INC	HL 
//	DEC	BC 
//	LD	A,B 
//	OR	C			; チェック終了？ 
//	JR	NZ,MS_RAM_CHK1		;   ＮＯ 
// 
//	PUSH	DE			; 戻り番地  復帰 
// 
//	LD	HL,0FFFH 
//	LD	(_NB_COUNT_LED1),HL	; 回数表示ＬＥＤ１、２　消灯 
	_NB_COUNT_LED1=0xFF;
	_NB_COUNT_LED2=0x0F;

// 
//	RET 
// 
//MS_RAM_CHK2: 
//	LD	E,5BH			; ”Ｅ２”表示要求  セット 
//	JP	SS_ERROR_STOP 
// 
}

//	PAGE 
//;************************************************************************ 
//;*	管理番号      : S-0323-001					* 
//;*	機能	      : ＰＣＴ０／ＰＣＴ１タイマ起動			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_PCT_ON					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
void MS_PCT_ON(void)
{
//	LD	A,80H 
//	LD	(0FF22H),A		; ウォッチドッグ起動 <ＰＣＴ０> 
//	LD	(0FF30H),A		; 割り込み起動 <ＰＣＴ１> 
// 
//	RET 

}

//;************************************************************************ 
//;*	管理番号      : S-0324-001					* 
//;*	機能	      : 設定値変更					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RANK_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_WATCH_CLEAR					* 
//;************************************************************************ 
//; 
void MS_RANK_SET(void)
{
	char z_a,z_b,z_c,z_d,z_e;


//	LD	DE,_NB_CREDIT_LED 
//	LD	A,0FFH 
//	LD	(DE),A			; 遊技メダル貯留枚数表示  消灯 
	_NB_CREDIT_LED=0xFF;

//	LD	HL,_NB_RANK 
//	LD	B,(HL)			; 設定値　取り出し 
	z_b=_NB_RANK;

//	INC	DE			; // DE = _NB_PAY_LED 
//	LD	L,LOW _PT_IN1_UP 
MS_RANK_SET1:
//	LD	A,B 
	z_a=z_b;
//	OR	0F0H 
	z_a=(z_a|0xF0);
//	LD	(DE),A			; 設定値表示 
	_NB_PAY_LED=z_a;

MS_RANK_SET2:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 

//	LD	A,(_PT_IN0_UP) 
//  	BIT	5,A			; 回胴回転始動装置スイッチ　ＯＮ？ 
	z_a=_PT_IN0_UP;
//	JR	NZ,MS_RANK_SET3		; 　ＹＥＳ 
	if((z_a&(0x01<<5)))	goto MS_RANK_SET3;

//	BIT	3,(HL)			; 設定ボタンスイッチ　ＯＮ？ 
//	JR	Z,MS_RANK_SET2		; 　ＮＯ 
	if(!(_PT_IN1_UP&(0x01<<3)))	goto MS_RANK_SET2;


//	RES	3,(HL)			; 設定ボタンスイッチ立ち上がり 
//						;;データ　クリア 
	_PT_IN1_UP&=((0x01<<3)^0xFF);
//	INC	B			; 設定値　＋１ 
	z_b+=1;
//	LD	A,6 
	z_a=6;
//	CP	B			; 設定値  ＞　６？ 
//	JR	NC,MS_RANK_SET1		; 　ＮＯ 
	if(z_a>=z_b)	goto MS_RANK_SET1;

//	LD	B,1			; 設定値　＝　１ 
	z_b=1;
//	JR	MS_RANK_SET1 
	goto MS_RANK_SET1;

MS_RANK_SET3:
//	LD	A,0F0H 
	z_a=0xF0;
//	LD	(DE),A			; 設定値表示  クリア 
	_NB_PAY_LED=z_a;
MS_RANK_SET4:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 

//	LD	A,(_PT_IN0_DOWN) 
	z_a=_PT_IN0_DOWN;
//	BIT	6,A			; 設定用キースイッチ　ＯＦＦ？ 
//	JR	Z,MS_RANK_SET4		; 　ＮＯ 
	if(!(z_a&(0x01<<6)))	goto MS_RANK_SET4;

//	LD	L,LOW _NB_RANK 
//	LD	(HL),B			; 設定値　セット 
	_NB_RANK=z_b;

//	XOR	A 
	z_a=0;
//	LD	(DE),A			; 遊技メダル払出し枚数表示  クリア 
	_NB_PAY_LED=z_a;
//	DEC	DE			; // DE = _NB_CREDIT_LED 
//	LD	(DE),A			; 遊技メダル貯留枚数表示　クリア 
	_NB_CREDIT_LED=z_a;
//	RET 

}
// 

//;************************************************************************ 
//;*	管理番号      : S-0325-001					* 
//;*	機能	      : 設定値エラーチェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RKER_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	E = エラー表示データ（下位桁）			* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,E						* 
//;*	使用ﾓｼﾞｭｰﾙ    : SS_ERROR_STOP（ジャンプ）			* 
//;************************************************************************ 
//; 
void MS_RKER_CHK(void)
{
//	char z_a; 
	short z_a;

//	LD	A,(_NB_RANK) 
	z_a=_NB_RANK;
//	DEC	A 
	z_a-=1;
//	CP	6			; 設定値　正常範囲？ 
//	RET	C			; 　ＹＥＳ 
	if(z_a<6)	return;


//	LD	E,7DH			; ”Ｅ６”表示要求  セット 
//	JP	SS_ERROR_STOP 
	SS_ERROR_STOP(0x7D);

}


//;************************************************************************ 
//;*	管理番号      : S-0326-001					* 
//;*	機能	      : 役物連続作動増加装置作動終了後の設定		* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_BB_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
void MS_BB_SET(void)
{
	char z_a,z_b;
//	IN	A,(@IN1_PORT) 
	z_a=IN1_PORT;
//	AND	0000 0101B		; // b0 = 自動払戻切替スイッチ 
	z_a&=0x05;
//	LD	B,A			; // b2 = 打止切替スイッチ 
	z_b=z_a;
//	LD	HL,_FL_GAME_STS 
//	LD	A,(HL) 
	z_a=_FL_GAME_STS;
//	AND	1111 1010B 
	z_a&=0xFA;
//	OR	B 
	z_a=(z_a|z_b);
//	LD	(HL),A			; 役物連続作動増加装置作動終了後の設定 
	_FL_GAME_STS=z_a;

//	RET 

}

//;************************************************************************ 
//;*	管理番号      : S-0327-001					* 
//;*	機能	      : ＲＡＭ初期データセット				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RAM_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	C = 前回遊技の遊技メダル枚数			* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
char MS_RAM_SET(void)
{
	char z_a,z_b,z_c;
//; 
//; 停止図柄データ初期データ　セット 
//; 
//	LD	BC,12 
//	LD	HL,TBL_INIT_PIC 
//	LD	DE,_WK_ALL_PIC1 
//	LDIR				; 停止図柄データ初期値　セット 
	_WK_ALL_PIC1	=TBL_INIT_PIC[MACINE][0];	//; 停止図柄データ１（全有効ライン）  
	_WK_ALL_PIC2	=TBL_INIT_PIC[MACINE][1];	//; 停止図柄データ２（全有効ライン）  
	_WK_STOP_PIC1[0]=TBL_INIT_PIC[MACINE][2];	//; 停止図柄データ１（各有効ライン）  
	_WK_STOP_PIC1[1]=TBL_INIT_PIC[MACINE][3];	//; 停止図柄データ１（各有効ライン）  
	_WK_STOP_PIC1[2]=TBL_INIT_PIC[MACINE][4];	//; 停止図柄データ１（各有効ライン）  
	_WK_STOP_PIC1[3]=TBL_INIT_PIC[MACINE][5];	//; 停止図柄データ１（各有効ライン）  
	_WK_STOP_PIC1[4]=TBL_INIT_PIC[MACINE][6];	//; 停止図柄データ１（各有効ライン）  
	_WK_STOP_PIC2[0]=TBL_INIT_PIC[MACINE][7];	//; 停止図柄データ２（各有効ライン）  
	_WK_STOP_PIC2[1]=TBL_INIT_PIC[MACINE][8];	//; 停止図柄データ２（各有効ライン）  
	_WK_STOP_PIC2[2]=TBL_INIT_PIC[MACINE][9];	//; 停止図柄データ２（各有効ライン）  
	_WK_STOP_PIC2[3]=TBL_INIT_PIC[MACINE][10];	//; 停止図柄データ２（各有効ライン）  
	_WK_STOP_PIC2[4]=TBL_INIT_PIC[MACINE][11];	//; 停止図柄データ２（各有効ライン）  


//; 
//; その他初期データ　セット 
//; 
//	LD	HL,_FL_STOP_LP 
//	LD	(HL),1110 0000B		; 回胴停止フラグ初期化 
	_FL_STOP_LP=0xE0;

//	LD	L,LOW _FL_GAME_STS 
//	RES	5,(HL)			; 遊技メダル限界フラグ　クリア 
//	SET	7,(HL)			; 減算修正許可フラグ　セット 
	_FL_GAME_STS=(_FL_GAME_STS&((0x01<<5)^0xFF));
	_FL_GAME_STS=(_FL_GAME_STS|0x80);
//					; // BC = 0 
//	LD	(_BF_STOP_CTL),BC	; 停止位置決定用テーブル 
//							;;保存用バッファ　クリア  
	_BF_STOP_CTL=0;

//	LD	L,LOW _NB_PLAY_MEDAL	; // B = 0 
//	LD	C,(HL)			; // （前回遊技の遊技メダル枚数　保存） 
	z_c=_NB_PLAY_MEDAL;
//	LD	(HL),B			; 遊技メダル枚数  クリア 
	_NB_PLAY_MEDAL=0;

//	LD	L,LOW _NB_STOP_ORDER	; // B = 0 
//	LD	(HL),B			; 回胴停止順番　クリア  
	_NB_STOP_ORDER = 0;	 // B = 0  

//	RET 
	return(z_c);
}

//;************************************************************************ 
//;*	管理番号      : S-0328-002					* 
//;*	機能	      : 遊技開始セット					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_GAME_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : C = 前回遊技の遊技メダル枚数			* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :	C						* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,DE,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_LPSD_SET					* 
//;************************************************************************ 
//; 
void MS_GAME_SET(char data)
{
	char z_a,z_b,z_c,z_d,z_e;

	z_c=data;
//	LD	HL,_FL_WIN 
//	LD	A,(HL) 
	z_a=_FL_WIN;
//	LD	(HL),0			; 入賞フラグ  クリア 
	_FL_WIN=0;

//	ここは、してることは同じＢＩＮの方がアセンブラ的に速いだけ 
	if(!MACINE){	//	カッパ 
//	LD	DE,_FL_ACTION 
//	RRCA				; 再遊技表示？ 
		if((z_a&0x01))	z_a=((z_a>>1)|0x80);
		else{
			z_a=(z_a>>1);
//	JR	NC,MS_GAME_SET1		;   ＮＯ 
			goto MS_GAME_SET1;
		}
	}else{	//	ビンビン 
//HL=_FL_WIN 
//	EX	DE,HL 
//DE=_FL_WIN 
//	INC	DE			; // DE = _FL_ACTION 
//DE=_FL_ACTION 
//	BIT	@BT_RP,A		; 再遊技表示？ 
//	JR	Z,MS_GAME_SET1		;   ＮＯ 
		if(!(z_a&(0x01<<BT_RP)))	goto MS_GAME_SET1;
	}
//; 再遊技作動開始条件  セット 
//	LD	HL,@TM_REPLAY1 
//	LD	(_TM2_REPLAY_ML),HL	; 遊技メダル自動投入 
//							;;待機時間　セット 
	_TM2_REPLAY_ML=TM_REPLAY1;

	replay_num+=1;	// 総リプレイ回数 

//	LD	A,C			; // （前回遊技の遊技メダル枚数） 
	z_a=z_c;
//	LD	(_NB_REP_MEDAL),A	; 自動投入遊技メダル枚数　セット  
	_NB_REP_MEDAL=z_a;

//	LD	A,@SET_REPLAY		; 再遊技作動時の出力要求　セット 
	z_a=SET_REPLAY;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 
// 
//	EX	DE,HL			; // HL = _FL_ACTION 
//	SET	@BT_RP,(HL)		; 再遊技作動フラグ  セット 
	_FL_ACTION=(_FL_ACTION|(0x01<<BT_RP));

//	RET 
	return;
// 
//; 役物連続作動装置作動開始条件  セット 
// 
MS_GAME_SET1:
//	DE=_FL_ACTION 

//	ここは、してることは同じＢＩＮの方がアセンブラ的に速いだけ 
	if(!MACINE){
//	RRCA				; ＲＢ入賞？ 
		if((z_a&0x01))	z_a=((z_a>>1)|0x80);
		else{
			z_a=(z_a>>1);
//	JR	NC,MS_GAME_SET2		;   ＮＯ  
			goto MS_GAME_SET2;		//;   ＮＯ  
		}
	}else{
//	BIT	@BT_RB,A		; ＲＢ入賞？ 
//	JR	Z,MS_GAME_SET2		;   ＮＯ 
		if(!(z_a&(0x01<<BT_RB)))	goto MS_GAME_SET2;		//;   ＮＯ  
	}

//	LD	L,LOW _PT_OUT0		; 役物連続作動装置本当たり信号出力ＯＮ 
//	SET	6,(HL) 
	bingo_n_rb+=1;		// ＲＥＧ回数 

	if(bonus_interval[1][2]>bonus_interval[1][0])	bonus_interval[1][0]=bonus_interval[1][2];
	if(bonus_interval[1][2]<bonus_interval[1][1])	bonus_interval[1][1]=bonus_interval[1][2];
	bonus_interval[1][2]=0;

	if(bonus_interval[3][2]>bonus_interval[3][0])	bonus_interval[3][0]=bonus_interval[3][2];
	if(bonus_interval[3][2]<bonus_interval[3][1])	bonus_interval[3][1]=bonus_interval[3][2];
	bonus_interval[3][2]=0;

	_PT_OUT0=(_PT_OUT0|((0x01)<<6));

//	LD	L,LOW _PT_OUT2 
//	SET	5,(HL)			; 遊技状態表示ランプ１点灯　セット 
	_PT_OUT2=(_PT_OUT2|((0x01)<<5));

//	LD	HL,@J_WIN*100H OR @J_MAX; =448 ＲＢ作動時の役物入賞回数  セット 
//HL=080C 
//	LD	(_CT_BONUS_PLAY),HL	; ＲＢ作動時の役物遊技回数　セット 
	_CT_BONUS_PLAY=J_MAX;
	_CT_BONUS_WIN=J_WIN;

//	LD	A,@SET_RB		; 役物連続作動装置作動時の 
//						;;出力要求　セット 
	z_a=SET_RB;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

//	EX	DE,HL			; // HL = _FL_ACTION 
//	SET	@BT_RB,(HL)		; 役物連続作動装置作動フラグ  セット 
	_FL_ACTION=(_FL_ACTION|(0x01<<BT_RB));

//	RET 
	return;
// 
//; 役物連続作動増加装置作動開始条件  セット 
// 
MS_GAME_SET2:
	if(!MACINE){
//	RRCA				; ＢＢ入賞？ 
		if((z_a&0x01))	z_a=((z_a>>1)|0x80);
		else{
			z_a=(z_a>>1);
//	RET	NC			;   ＮＯ 
			return;
		}
// 
//	LD	L,LOW _PT_OUT0		; 役物連続作動増加装置 
//	SET	7,(HL)			;;本当たり信号出力ＯＮ 
	_PT_OUT0=(_PT_OUT0|0x80);

//	LD	L,LOW _PT_OUT2 
//	SET	6,(HL)			; 遊技状態表示ランプ２点灯　セット 
	_PT_OUT2=(_PT_OUT2|(0x01<<6));
// 
//	LD	HL,@B_WIN*100H OR @B_MAX;  ＢＢ作動時の一般遊技回数　セット 
//	LD	(_CT_BIG_PLAY),HL	; ＢＢ作動時のＲＢ入賞回数  セット 
	_CT_BIG_PLAY=B_MAX;
	_CT_BIG_WIN	=B_WIN;

//	LD	A,@SET_BB		; 役物連続作動増加装置作動時の 
//					;;出力要求　セット 
	z_a=SET_BB;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

//					; // DE = _FL_ACTION 
//	LD	A,@_BB			; 役物連続作動増加装置 
	z_a=_BB;
//	LD	(DE),A			;;作動フラグ  セット 
	_FL_ACTION=z_a;
// 
	}else{
//	BIT	@BT_BB,A		; ＢＢ入賞？ 
//	RET	Z			;   ＮＯ 
	if((z_a&(0x01<<BT_BB))==0)	return;

//	LD	L,LOW _PT_OUT0		; 役物連続作動増加装置 
//	SET	7,(HL)			;;本当たり信号出力ＯＮ 
	_PT_OUT0=(_PT_OUT0|0x80);

//	LD	L,LOW _PT_OUT2 
//	SET	7,(HL)			; 遊技状態表示ランプ３点灯　セット 
//	SET	6,(HL)			; 遊技状態表示ランプ２点灯　セット 
	_PT_OUT2=(_PT_OUT2|(0x80|0x40));

//	LD	HL,@B_WIN*100H OR @B_MAX;  ＢＢ作動時の一般遊技回数　セット 

//	LD	(_CT_BIG_PLAY),HL	; ＢＢ作動時のＲＢ入賞回数  セット 
	_CT_BIG_PLAY=B_MAX;
	_CT_BIG_WIN=B_WIN;
//					; // DE = _FL_ACTION 
//	LD	(DE),A			; 役物連続作動増加装置作動フラグ  セット 
	_FL_ACTION=z_a;

//	BIT	@BT_BB1,A 
	if((z_a&(0x01<<BT_BB1))){
//	LD	A,@SET_BB1		; 役物連続作動増加装置作動時の 
		z_a=SET_BB1;
//					;;出力要求１　セット 
//	JR	NZ,MS_GAME_SET3		; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)入賞？．．ＹＥＳ 

		goto MS_GAME_SET3;		//; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)入賞？．．ＹＥＳ 
	}
//	z_a=SET_BB1; 
//	INC     A			; 役物連続作動増加装置作動時の 
//						;;出力要求２　セット 
//						; // A = @SET_BB2  
	z_a=SET_BB2;
MS_GAME_SET3:
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 
// 
//	RET 
	}
}


//;************************************************************************ 
//;*	管理番号      : S-0329-001					* 
//;*	機能	      : ボーナスゲームチェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_BNS_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : Zflag OFF = ボーナスゲーム			* 
//;*		      : Zflag ON = その他				* 
//;*		      : A = ボーナスゲームビット			* 
//;*	保護ﾚｼﾞｽﾀ     : 						* 
//;*	破壊ﾚｼﾞｽﾀ     : A						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 

char MS_BNS_CHK(void)
{
	z_a=_FL_ACTION;
//	LD	A,(_FL_ACTION) 
//	AND	@_BNS		; ボーナスゲームチェック  
	z_a&=_BNS;
	if(z_a)	return(0);
	else	return(1);
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0330-001					* 
//;*	機能	      : 遊技メダル払出センサーチェック			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_HOPPER_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	保護ﾚｼﾞｽﾀ     : 						* 
//;*	破壊ﾚｼﾞｽﾀ     : A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_WATCH_CLEAR,S_IN0_CHK,S_BLOCKER_OFF		* 
//;*			MS_HPERR_SET,S_BLOCKER_ON			* 
//;************************************************************************ 
//; 
void MS_HOPPER_CHK(void)
{
#if 0

	char z_a,z_b,z_c;

//	LD	DE,_TM1_PAY 
//	LD	A,@TM_HOPPER4		; 遊技メダル払出センサー 
	z_a=TM_HOPPER4;
//	LD	(DE),A			;;チェック時間　セット 
	_TM1_PAY=z_a;		//; 遊技メダル払出センサー 

//	LD	HL,_PT_OUT1 
//	LD	C,(HL)			; 遊技ﾒﾀﾞﾙ払出ｾﾝｻｰﾁｪｯｸ前遊技ﾒﾀﾞﾙ 
//						;;ﾌﾞﾛｯｶｰ状態一時保存 
	z_c=_PT_OUT1;

MS_HOPPER_CHK1:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
//	S_WATCH_CLEAR();		//; ウォッチドッグクリア 
// 
//	LD	B,0000 1000B		; 遊技メダル払出センサー信号 
//						;;チェック要求 
	z_b=0x08;
//	RST	S_IN0_CHK		; 入力ポート０レベルチェック 
//	JR	Z,MS_HOPPER_CHK2	; 遊技メダル払出センサーＯＮ？．．ＮＯ 
	if(S_IN0_CHK(z_b)==0)	goto MS_HOPPER_CHK2;

//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 

//	LD	L,LOW _FL_GAME_STS	; 回胴回転始動装置 
//	RES	3,(HL)			;;受付許可フラグ　クリア 
	_FL_GAME_STS&=((0x01<<3)^0xFF);

//	LD	A,(DE)			; // DE = _TM1_PAY 
	z_a=_TM1_PAY;
//	AND	A				; チェック時間終了？ 
//	JR	NZ,MS_HOPPER_CHK1	;   ＮＯ 
	if(z_a) goto MS_HOPPER_CHK1;

//	ハードウェアーエラー処理なので省きます 
//	LD	D,0DCH			; ”ＨＣ”表示要求　セット 
//	CALL	MS_HPERR_SET		; 遊技メダル払出エラーセット 
MS_HOPPER_CHK2:
//	BIT	4,C			; 遊技ﾒﾀﾞﾙ払出ｾﾝｻｰﾁｪｯｸ前遊技ﾒﾀﾞﾙ 
//					;;ﾌﾞﾛｯｶｰ状態確認要求　セット 
//	RET	Z			; 遊技ﾒﾀﾞﾙﾌﾞﾛｯｶｰＯＮ？．．ＮＯ 
	if((z_c&(0x01<<4))==0)	return

//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 

	S_BLOCKER_ON();		//; 遊技メダルブロッカーＯＮ<通過状態> 
//	RET 
#endif
}


//;************************************************************************ 
//;*	管理番号      : S-0331-001					* 
//;*	機能	      : 遊技メダル払出エラーセット			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_HPERR_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : D = エラー表示データ				* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	保護ﾚｼﾞｽﾀ     : D						* 
//;*	破壊ﾚｼﾞｽﾀ     : A,B,E,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_LPSD_SET,S_WATCH_CLEAR			* 
//;************************************************************************ 
//; 
void MS_HPERR_SET(void)
{
//	LD	HL,_WK_FLASH_LP		; エラー発生時の 
//	LD	B,(HL)			;;上部ランプ表示　退避 
// 
//	LD	L,LOW _NB_PAY_LED 
//	LD	E,(HL)			; 遊技メダル払出し枚数表示  退避 
// 
//	LD	(HL),D			; エラー表示  セット 
// 
//	LD	A,@SET_ALARM		; 遊技メダル払出エラー発生時の 
//					;;出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
// 
//MS_HPERR_SET1: 
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	A,(_PT_IN1_UP) 
//	AND	00001010B		; エラー解除？ 
//	JR	Z,MS_HPERR_SET1		; 　ＮＯ 
//					; // HL = _NB_PAY_LED 
//	LD	(HL),E			; 遊技メダル払出し枚数表示  復帰 
// 
//	LD	A,@SET_ACLEAR		; 遊技メダル払出エラー解除時の 
//					;;出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
// 
//; 遊技メダル払出エラー発生時の上部ランプ・効果ランプ・効果音復帰 
//#ifdef KAPPA 
//	LD	A,B 
//	LD	B,@SET_RB		; 役物連続作動装置作動時の 
//					;;出力要求　セット 
//	CP	@FLP_RB			; ＲＢ作動時？ 
//	JR	Z,MS_HPERR_SET2		;   ＹＥＳ 
// 
//	LD	B,@SET_BB		; 役物連続作動増加装置作動時の 
//					;;出力要求　セット 
//	CP	@FLP_BB			; ＢＢ作動時？ 
//	JR	Z,MS_HPERR_SET2		;   ＹＥＳ 
// 
//	LD	B,@SET_PAYSTART		; 入賞による遊技メダル払出し 
//					;;開始時の出力要求　セット 
//	CP	@FLP_PAY		; 入賞による遊技メダル払出し時？ 
//	RET	NZ			;   ＮＯ 
// 
//MS_HPERR_SET2: 
//	LD	A,B 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
//#else if BINBIN 
//	LD	A,B			; エラー発生時の上部ランプ表示　復帰 
//	LD	DE,@ERREC_LP		; エラー復帰時の出力番号　セット 
//	LD	B,@ERREC_CT		; エラー復帰時の出力番号検索数　セット 
// 
//MS_HPERR_SET2: 
//	INC	D			; 復帰用出力要求番号　セット 
//	INC	E			; 上部ランプ出力要求番号　セット 
// 
//	DEC	B			; 上部ランプ表示なし？ 
//	RET	Z			;   ＹＥＳ 
// 
//	CP	E			; 上部ランプパターン出力中？ 
//	JR	NZ,MS_HPERR_SET2	;   ＮＯ 
// 
//	LD	A,D			; 復帰する出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
// 
//#endif 
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0332-001					* 
//;*	機能	      : 投入ボタンチェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_CREDIT_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_STOPSW_CHK,MS_SENSOR_CHK,S_IN0_CHK		* 
//;*		      : MS_JAC_CHK,S_BLOCKER_OFF,MS_BET_IN,S_BLOCKER_ON	* 
//;************************************************************************ 

//	決定的にここがおかしい！12/07 
void MS_CREDIT_CHK(void)
{

	char z_a,z_b,z_c,z_d,z_e;
//	LD	HL,_FL_GAME_STS 
//	BIT	4,(HL)			; 遊技メダル貯留装置使用時？  
//	RET	NZ			;   ＮＯ 
	if((_FL_GAME_STS&(0x01<<4)))	return;

//	CALL	MS_STOPSW_CHK		; 停止ボタンチェック  
//	RET	NZ			; 停止ボタン　操作中？．．ＹＥＳ  
	if(MS_STOPSW_CHK())	return;

//	CALL	MS_SENSOR_CHK		; 遊技メダル投入センサーチェック  
//	RET	NZ			; 入力あり？．．ＹＥＳ  

	if(MS_SENSOR_CHK())	return;

//	LD	B,00110000B		; 回胴回転始動装置・精算ボタン 
//						;;スイッチ　チェック要求 
//	RST	S_IN0_CHK		; 入力ポート０レベルチェック 
//	RET	NZ				; その他の入力あり？．．ＹＥＳ  
	if(S_IN0_CHK(0x30))	return;

//;	投入ボタンチェック 
// 
//	LD	DE,(_PT_IN0_OLD)	; // D = (_PT_IN0_UP), E = (_PT_IN0_OLD) 
	z_d=_PT_IN0_UP;
	z_e=_PT_IN0_OLD;
//	LD	A,D 
	z_a=z_d;
//	XOR	E 
	z_a^=z_e;
//	AND	0000 0111B		; 投入ボタン継続操作中？ 
	z_a&=0x07;
//	RET	NZ			;　 ＹＥＳ  
	if(z_a) return;

//	LD	A,D			; // D = (_PT_IN0_UP) 
	z_a=z_d;
//	AND	0000 0111B 
	z_a&=0x07;
//	LD	BC,3			; // B = 0,C = 3 
	z_b=0;
	z_c=3;
MS_CREDIT_CHK1:
//	INC	B			; 投入ボタン要求枚数　セット  
	z_b+=1;
//	RRCA 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
		goto MS_CREDIT_CHK2;
//	JR	C,MS_CREDIT_CHK2	; 投入ボタン入力あり？．．ＹＥＳ  
	}
	else	z_a=(z_a>>1);

//	DEC	C 
	z_c-=1;
//	RET	Z			; すべての投入ボタンチェックした？．．ＹＥＳ  
	if(z_c==0)	return;
//	JR	MS_CREDIT_CHK1 
	goto MS_CREDIT_CHK1;

MS_CREDIT_CHK2:

//	CALL	MS_JAC_CHK		; 役物遊技チェック 
//	JR	Z,MS_CREDIT_CHK3	; 役物遊技時？．．ＮＯ 

	if(MS_JAC_CHK())	goto MS_CREDIT_CHK3;

//	LD	B,1			; 投入ボタン要求枚数＝１枚　セット 
	z_b=1;

MS_CREDIT_CHK3:
//	LD	DE,_NB_PLAY_MEDAL 
//	LD	A,(DE) 
	z_a=_NB_PLAY_MEDAL;
//	CP	B					; 遊技ﾒﾀﾞﾙ枚数＝投入ﾎﾞﾀﾝ要求枚数？  
//	RET	Z			;   ＹＥＳ 
	if((z_a-z_b)==0)	return;

//	JR	C,MS_CREDIT_CHK4	; 遊技ﾒﾀﾞﾙ枚数＞投入ﾎﾞﾀﾝ要求枚数？．．ＮＯ  
	if(z_a<z_b)	goto MS_CREDIT_CHK4;

//;	遊技メダル枚数＞投入ボタン要求枚数　時の処理 

//	BIT	7,(HL)			; 減算修正許可フラグあり？ 
//					; // HL = _FL_GAME_STS 
//	RET	Z			;   ＮＯ 
	if((_FL_GAME_STS&(0x01<<7))==0)	return;

//	RES	3,(HL)			; 回胴回転始動装置 
//						;;受付許可フラグ　クリア 
//	RES	5,(HL)			; 遊技メダル限界フラグ　クリア 
	_FL_GAME_STS&=((0x01<<3)^0xFF);
	_FL_GAME_STS&=((0x01<<5)^0xFF);

//	LD	L,LOW _NB_CREDIT_LED	; // A = 遊技メダル枚数 
//	ADD	A,(HL)			; 貯留枚数加算 
	z_a+=_NB_CREDIT_LED;
//	DAA	//	１０進に補正 
//	LD	(HL),A 
	_NB_CREDIT_LED=z_a;
//	XOR	A			; // DE = _NB_PLAY_MEDAL 
	z_a=0;
//	LD	(DE),A			; 遊技メダル枚数　クリア  
//					; // 投入要求枚数＝投入ボタン要求枚数  
	_NB_PLAY_MEDAL=z_a;
//	JR	MS_CREDIT_CHK5 
	goto MS_CREDIT_CHK5;

//;	遊技メダル枚数＜投入ボタン要求枚数　時の処理  

MS_CREDIT_CHK4:
//	LD	A,(_NB_CREDIT_LED) 
	z_a=_NB_CREDIT_LED;
//	AND	A			; 遊技メダル貯留枚数あり？  
//	RET	Z			; 　ＮＯ  
	if(z_a==0)	return;

//	RES	3,(HL)			; 回胴回転始動装置 
//						;;受付許可フラグ　クリア 
//						; // HL = _FL_GAME_STS 
	_FL_GAME_STS&=((0x01<<3)^0xFF);

//	LD	A,B			; // B = 投入ボタン要求枚数 
	z_a=z_b;

//	DE=_NB_PLAY_MEDAL  
//	HL=_FL_GAME_STS 
//	EX	DE,HL 
//	DE=_FL_GAME_STS 
//	HL=_NB_PLAY_MEDAL  

//	SUB	(HL)			; // HL = _NB_PLAY_MEDAL 
	z_a=z_a-_NB_PLAY_MEDAL;
//	LD	B,A			; 投入要求枚数＝投入ボタン要求枚数 
//					;;              －  遊技メダル枚数 
	z_b=z_a;
//	LD	L,LOW _NB_CREDIT_LED 

//	CP	(HL)			; 遊技ﾒﾀﾞﾙ貯留枚数＞投入要求枚数？ 
//	JR	C,MS_CREDIT_CHK5	;   ＹＥＳ 
	if(z_a<_NB_CREDIT_LED)	goto MS_CREDIT_CHK5;

//	LD	B,(HL)			; 投入要求枚数＝遊技メダル貯留枚数 
	z_b=_NB_CREDIT_LED;
//;	貯留投入 
MS_CREDIT_CHK5:
//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 
// 
//	CALL	MS_BET_IN		; 貯留投入 
	MS_BET_IN(z_b);		//; 貯留投入 

//	CALL	MS_JAC_CHK		; 役物遊技チェック 
	if(!MS_JAC_CHK())	return;
//	RET	NZ			; 役物遊技時？．．ＹＥＳ 

//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 
	S_BLOCKER_ON();			//; 遊技メダルブロッカーＯＮ<通過状態> 

//	RET 
}



//;************************************************************************ 
//;*	管理番号      : S-0333-001										* 
//;*	機能	      : 停止ボタンチェック								* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_STOPSW_CHK									* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Zflag OFF = 本体停止ボタンＯＮ（操作中）		* 
//;*			      :	Cflag OFF										* 
//;*			      : A = 本体停止ボタンデータ(XXX00000B)				* 
//;*	保護ﾚｼﾞｽﾀ     :													* 
//;*	破壊ﾚｼﾞｽﾀ     :	A												* 
//;*	使用ﾓｼﾞｭｰﾙ    : 												* 
//;************************************************************************ 
//; 
//	ドラム停止ボタンのチェック 
short MS_STOPSW_CHK(void)
{
//	if(pad_cnt&PADR_L)	_PT_IN2_OLD|=0x80; 
//	if(pad_cnt&PADR_U)	_PT_IN2_OLD|=0x40; 
//	if(pad_cnt&PADR_R)	_PT_IN2_OLD|=0x20; 

//	LD	A,(_PT_IN2_OLD) 
//	CPL 
//	AND	11100000B		; 停止ボタンチェック 
	return((_PT_IN2_OLD^0xFF)&0xE0);

//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0334-001					* 
//;*	機能	      : 遊技メダル投入センサーチェック			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_SENSOR_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : Zflag OFF = 遊技メダル投入センサー入力あり	* 
//;*		          : A = 遊技メダル投入センサーデータ(00XX0000B)	* 
//;*	保護ﾚｼﾞｽﾀ     : 						* 
//;*	破壊ﾚｼﾞｽﾀ     : A						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
char MS_SENSOR_CHK(void)
{
//	if(pad_cnt&PADR_D)		_PT_IN1_OLD|=0x30; 
//	else					_PT_IN1_OLD&=0xCF; 
//	LD	A,(_PT_IN1_OLD) 
//	CPL 
//	AND	00110000B		; 遊技メダル投入センサーチェック 
// 
//	RET 
	return((_PT_IN1_OLD^0xFF)&0x30);

}

//;************************************************************************ 
//;*	管理番号      : S-0335-001					* 
//;*	機能	      : 役物遊技チェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_JAC_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : Zflag OFF = 役物遊技				* 
//;*		      : Zflag ON = その他の遊技				* 
//;*	保護ﾚｼﾞｽﾀ     : 						* 
//;*	破壊ﾚｼﾞｽﾀ     : A						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 

int MS_JAC_CHK(void)
{
//	LD	A,(_FL_ACTION) 
//	AND	@_JAC			; 役物遊技チェック 
//	RET 
	z_a=_FL_ACTION;
	z_a&=_JAC;
	if(z_a)	return(0);
	else	return(1);
}

//;************************************************************************ 
//;*	管理番号      : S-0336-001					* 
//;*	機能	      : 貯留投入					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_BET_IN					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : B = 投入要求枚数				* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_WATCH_CLEAR,MS_MEDAL_INC,MS_CREDIT_DEC	* 
//;************************************************************************ 

void MS_BET_IN(char data)
{
	char z_a,z_b;

	z_b=data;
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
MS_BET_IN1:

//	LD	A,(_TM1_BET_ML) 
	z_a=_TM1_BET_ML;
//	AND	A			; 遊技メダル投入待機時？ 
//	JR	NZ,MS_BET_IN		; 　ＹＥＳ 
	if(z_a)	goto MS_BET_IN1;

//	CALL	MS_MEDAL_INC		; 遊技メダル１枚加算 
	MS_MEDAL_INC();		//; 遊技メダル１枚加算 

//	CALL	MS_CREDIT_DEC		; 遊技メダル貯留枚数１枚減算 
	z_a=MS_CREDIT_DEC();		//; 遊技メダル貯留枚数１枚減算 
//	DE=_NB_CREDIT_LED 

//	LD	A,@TM_BET_IN 
//	LD	(_TM1_BET_ML),A		; 遊技メダル投入待機時間  セット 
	_TM1_BET_ML=TM_BET_IN;

//	DJNZ	MS_BET_IN		; 投入要求枚数投入終了？．．ＮＯ 
	z_b-=1;
	if(z_b)	goto MS_BET_IN1;
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0337-001					* 
//;*	機能	      : 遊技メダル１枚加算				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_MEDAL_INC					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Zflag ON = 遊技メダル限界			* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,C,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_LPSD_SET,S_ADDR_SET,S_BLOCKER_OFF		* 
//;************************************************************************ 
//; 
//	完璧 12/12
int MS_MEDAL_INC(void)
{
	char z_a,z_c,z_d;

//	XOR	A 
	z_a=0;
//	LD	HL,_WK_WIN_LP 
//	LD	(HL),A			; 入賞時有効ラインランプ 
//						;;点滅データ　クリア 
	_WK_WIN_LP=z_a;
//	INC	HL			; // HL = _WK_WINBACK_LP 
//	LD	(HL),A			; 入賞時バックランプ９点滅 
//						;;データ　クリア 
	_WK_WINBACK_LP[0]=z_a;
//	INC	HL			; // HL = _WK_WINBACK_LP+1 
//	LD	(HL),A			; 入賞時バックランプ１～８点滅 
//						;;データ　クリア 
	_WK_WINBACK_LP[1]=z_a;
//	LD	(_NB_PAY_LED),A		; 遊技メダル払出し枚数表示　クリア 
	_NB_PAY_LED=z_a;

//	LD	A,@SET_INCO		; 遊技メダル投入時の 
//						;;出力要求  セット 
	z_a=SET_INCO;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 
// 
//	LD	L,LOW _NB_PLAY_MEDAL 
//	INC	(HL)			; 遊技メダル枚数　＋１ 
	_NB_PLAY_MEDAL+=1;

//	LD	A,(HL)			; // HL = _NB_PLAY_MEDAL 
//	LD	C,A			; // 遊技メダル枚数一時保存 
	z_a=_NB_PLAY_MEDAL;
	z_c=z_a;
//	LD	HL,TBL_LINE_LP - 1	; 有効ラインランプ点灯 
//							;;テーブル要求　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 

//	LD	DE,_PT_OUT5 
	DI				//; 割り込み禁止 
//	LD	A,(DE) 
//	AND	1110 0000B 
	z_a=_PT_OUT5&0xE0;
//	OR	(HL) 
	z_a=(z_a|TBL_LINE_LP[_NB_PLAY_MEDAL-1]);
//	LD	(DE),A			; 有効ラインランプ点灯 
	_PT_OUT5=z_a;

	EI				//; 割り込み許可 

//	LD	HL,_NB_REP_MEDAL	; 遊技メダル自動投入時の 
//	LD	D,(HL)				;;遊技メダル限界枚数  セット 
	z_d=_NB_REP_MEDAL;

//	LD	A,(_FL_ACTION) 
	z_a=_FL_ACTION;
//	BIT	@BT_RP,A		; 再遊技作動時？ 
//	JR	NZ,MS_MEDAL_INC1	;   ＹＥＳ 

	if((z_a&(0x01<<BT_RP)))	goto MS_MEDAL_INC1;

//	LD	D,3			; 遊技メダル限界枚数３枚  セット 
	z_d=3;

//	AND	@_JAC			; 役物遊技時？ 
	z_a&=_JAC;
//	JR	Z,MS_MEDAL_INC1		; 　ＮＯ 
	if(!z_a)	goto MS_MEDAL_INC1;
// 
//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 
// 
//	LD	D,1			; 遊技メダル限界枚数１枚  セット 
	z_d=1;
MS_MEDAL_INC1:
//	LD	A,C			; // C = (_NB_PLAY_MEDAL) 
	z_a=z_c;
//	CP	D			; 遊技メダル枚数限界？ 
//	RET	NZ			; 　ＮＯ <ゼロフラグ　ＯＦＦ> 
	if(z_a!=z_d)		return(0);

//	LD	L,LOW _FL_GAME_STS 
//	SET	5,(HL)			; 遊技メダル限界フラグ　セット 

	_FL_GAME_STS=_FL_GAME_STS|(0x01<<5);
//	RET				; <ゼロフラグ　ＯＮ> 

	return(1);
}

//;************************************************************************ 
//;*	管理番号      : S-0338-001											* 
//;*	機能	      : 遊技メダル貯留枚数１枚減算							* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_CREDIT_DEC										* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 													* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : A = 遊技メダル貯留枚数表示データ					* 
//;*				  : DE = 遊技メダル貯留枚数表示データＲＡＭアドレス		* 
//;*	保護ﾚｼﾞｽﾀ     : 													* 
//;*	破壊ﾚｼﾞｽﾀ     : A,DE												* 
//;*	使用ﾓｼﾞｭｰﾙ    : 													* 
//;************************************************************************ 
//; 
char MS_CREDIT_DEC(void)
{
	char z_a;
//	LD	DE,_NB_CREDIT_LED 
//	LD	A,(DE)  
	z_a=_NB_CREDIT_LED;
//	SUB	1			; 遊技メダル貯留枚数　－１ 
	z_a-=1;
//	DAA				; １０進変換 
//	LD	(DE),A 
	_NB_CREDIT_LED=z_a;
// 
//	RET 
	return (z_a);
}

//;************************************************************************ 
//;*	管理番号      : S-0339-001					* 
//;*	機能	      : 精算ボタンチェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_CANCEL_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_JAC_CHK,MS_STOPSW_CHK,S_IN0_CHK,S_BLOCKER_ON	* 
//;*		      : S_BLOCKER_OFF,MS_1MEDAL_PAY,MS_CREDIT_DEC	* 
//;************************************************************************ 

void MS_CANCEL_CHK(void)
{
	char z_a,z_b,z_c,z_d;
	short z_de;

//	CALL	MS_JAC_CHK		; 役物遊技チェック 
//	MS_JAC_CHK();	//		; 役物遊技チェック 
//	RET	NZ					; 役物遊技時？．．ＹＥＳ 
	if(!MS_JAC_CHK())	return;

//	CALL	MS_STOPSW_CHK		; 停止ボタンチェック 
//	RET	NZ			; 停止ボタン　操作中？．．ＹＥＳ 
	if(MS_STOPSW_CHK())	return;

//	LD	B,0010 0111B		; 回胴回転始動装置・投入ボタン 
//							;;スイッチ　チェック要求 
	z_b=0x27;
//	RST	S_IN0_CHK		; 入力ポート０レベルチェック 
//	RET	NZ			; その他の入力あり？．．ＹＥＳ 
	if(S_IN0_CHK(z_b))	return;

//	LD	HL,_PT_IN0_UP 
//	BIT	4,(HL)			; 精算ボタンスイッチ　ＯＮ？ 
//	RET	Z			; 　ＮＯ  
	if((_PT_IN0_UP&(0x01<<4))==0)	return;

//	RES	4,(HL)			; 精算ボタンスイッチ立ち上がり 
//						;;データ　クリア 
	_PT_IN0_UP&=((0x01<<4)^0xFF);
//; 精算ボタン受付 

//	LD	L,LOW _FL_GAME_STS	; 回胴回転始動装置 
//	RES	3,(HL)				;;受付許可フラグ　クリア 
	_FL_GAME_STS&=((0x01<<3)^0xFF);

//	LD	DE,_NB_CREDIT_LED 
//	z_de=_NB_CREDIT_LED; 

//	BIT	4,(HL)			; 遊技メダル貯留装置使用時？ 
//	JR	Z,MS_CANCEL_CHK1	; 　ＹＥＳ 
	if((_FL_GAME_STS&(0x01<<4))==0)	goto MS_CANCEL_CHK1;

//; 遊技メダル貯留装置否使用時から使用時への切替え 

//	RES	4,(HL)			; 遊技メダル貯留装置否使用フラグ  クリア 
	_FL_GAME_STS&=((0x01<<4)^0xFF);

//	XOR	A			; // DE = _NB_CREDIT_LED 
	z_a=0;
//	LD	(DE),A			; 遊技メダル貯留枚数表示　クリア 
	_NB_CREDIT_LED=z_a;

//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 
	S_BLOCKER_ON();		//; 遊技メダルブロッカーＯＮ<通過状態> 
//	RET 
	return;

//; 遊技メダル貯留装置使用時から否使用時への切替え 
// 
MS_CANCEL_CHK1:
//	SET	4,(HL)			; 遊技メダル貯留装置否使用フラグ　セット  
//	RES	7,(HL)			; 減算修正許可フラグ　クリア  
	_FL_GAME_STS=_FL_GAME_STS|(0x01<<4);
	_FL_GAME_STS&=((0x01<<7)^0xFF);

//	LD	A,(DE)			; // DE = _NB_CREDIT_LED 
	z_a=_NB_CREDIT_LED;
//	AND	A			; 遊技メダル貯留枚数あり？ 

//	JR	NZ,MS_CANCEL_CHK2	; 　ＹＥＳ 
	if(z_a)	goto MS_CANCEL_CHK2;

//; 遊技メダル貯留枚数なしの場合 

//	DEC	A			; // A = 0FFH , DE = _NB_CREDIT_LED 
	z_a=0xFF;
//	LD	(DE),A			; 遊技メダル貯留枚数表示　消灯 
	_NB_CREDIT_LED=z_a;

//	BIT	5,(HL)			; 遊技メダル限界時？ 
//	RET	Z			;   ＮＯ 
	if((_FL_GAME_STS&(0x01<<5))==0)	return;

//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 

//	RET 
	return;
// 
//; 遊技メダル貯留枚数ありの場合 
// 
MS_CANCEL_CHK2:
//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();		//; 遊技メダルブロッカーＯＦＦ<返却状態> 
MS_CANCEL_CHK3:
//	CALL	MS_1MEDAL_PAY		; 遊技メダル１枚払出し 
	MS_1MEDAL_PAY();			//; 遊技メダル１枚払出し 


//	CALL	MS_CREDIT_DEC		; 遊技メダル貯留枚数１枚減算 
	z_a=MS_CREDIT_DEC();

//	wait(1);
//	AND	A			; 遊技メダル貯留枚数あり？ 
//	JR	NZ,MS_CANCEL_CHK3	; 　ＹＥＳ 
	if(z_a)	goto MS_CANCEL_CHK3; //ＹＥＳ 

//	DEC	A			; // A = 0FFH , DE = _NB_CREDIT_LED 
	z_a=0xFF;
//	LD	(DE),A			; 遊技メダル貯留枚数表示　消灯 
	_NB_CREDIT_LED=z_a;

//	LD	A,(_FL_GAME_STS) 
//	BIT	5,A			; 遊技メダル限界時？ 
//	RET	NZ			;   ＹＥＳ 
	if((_FL_GAME_STS&(0x01<<5)))	return;

//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 
	S_BLOCKER_ON();			//; 遊技メダルブロッカーＯＮ<通過状態> 

//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0340-001					* 
//;*	機能	      : 遊技メダル１枚払出し				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_1MEDAL_PAY					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_WATCH_CLEAR,S_IN0_CHK,MS_HPERR_SET		* 
//;************************************************************************ 
//; 
//	機械的なことだからいらない？ 
//	要るとしたら、メダル払い出し音をここで鳴らすくらいか？ 
void MS_1MEDAL_PAY(void)
{
	char z_a,z_b,z_c,z_d;

	hand_medal+=1;
_MS_1MEDAL_PAY:

//	LD	HL,@TM_HOPPER3 
//	LD	(_TM2_HE_CHK),HL	; 遊技メダル払出装置 
//							;;作動時間  セット 
	_TM2_HE_CHK=TM_HOPPER3;

//	LD	HL,_PT_OUT1 
//	SET	7,(HL)			; 遊技メダル払出装置作動開始 
	_PT_OUT1=_PT_OUT1|(0x01<<7);

//; 遊技メダル払出センサー信号ＯＦＦ時の処理 

MS_1MEDAL_PAY1:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	BC,(_TM2_HE_CHK) 
//	LD	A,B 
//	OR	C			; 遊技メダル払出装置作動時間超過？ 
//	JR	Z,MS_1MEDAL_PAY3	; 　ＹＥＳ 
//	if(!_TM2_HE_CHK)	goto MS_1MEDAL_PAY3; 
// 
//	LD	B,00001000B		; 遊技メダル払出センサー信号 
//						;;チェック要求 
//	z_b=0x80; 
//	RST	S_IN0_CHK		; 入力ポート０レベルチェック 
//	z_a=S_IN0_CHK(z_b); 
//	JR	Z,MS_1MEDAL_PAY1	; 遊技メダル払出センサー通過開始？．．ＮＯ 
//	if(!z_a)	goto MS_1MEDAL_PAY1; 
// 
//; 遊技メダル払出センサー信号ＯＦＦ→ＯＮ時の処理 
// 
//	LD	DE,_TM1_PAY 
//	LD	A,@TM_HOPPER1		; 遊技メダル払出センサー 
//	z_a=TM_HOPPER1; 
//	LD	(DE),A			;;チェック時間　セット 
//	_TM1_PAY=z_a; 

	_SE_RET_MEDAL

	if(rnd(3)==1)	wait(3);
	else			wait(5);

//; 遊技メダル払出センサー信号ＯＮ時の処理 
// 
MS_1MEDAL_PAY2:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	BC,(_TM2_HE_CHK) 
//	LD	A,B 
//	OR	C			; 遊技メダル払出装置作動時間超過？ 
//	JR	Z,MS_1MEDAL_PAY3	; 　ＹＥＳ 
//	if(!_TM2_HE_CHK)	goto MS_1MEDAL_PAY3; 
// 
//	LD	A,(DE)			; // DE = _TM1_PAY 
//	z_a=_TM1_PAY; 
//	AND	A			; 遊技メダル詰まり？ 
//	JR	Z,MS_1MEDAL_PAY4	; 　ＹＥＳ 
//	if(!z_a)	goto MS_1MEDAL_PAY4; 

//	LD	B,00001000B		; 遊技メダル払出センサー信号 
//						;;チェック要求 

//	z_b=0x80; 
//	RST	S_IN0_CHK		; 入力ポート０レベルチェック 
//	z_a=S_IN0_CHK(z_b);		//; 入力ポート０レベルチェック 
//	JR	NZ,MS_1MEDAL_PAY2	; 遊技メダル払出センサー通過終了？．．ＮＯ 
//	if(z_a)	goto MS_1MEDAL_PAY2; 

//; 遊技メダル払出センサー信号ＯＮ→ＯＦＦ時の処理 

//	LD	A,(DE)			; // DE = _TM1_PAY 
//	z_a=_TM1_PAY; 
//	CP	@TM_HOPPER2		; 遊技メダル払出し無効？ 
//	JR	NC,MS_1MEDAL_PAY1	;   ＹＥＳ 
//	if(z_a>=TM_HOPPER2)	goto MS_1MEDAL_PAY1; 
// 
//					; // HL = _PT_OUT1 
//	RES	7,(HL)			; 遊技メダル払出装置作動停止 

	_PT_OUT1&=((0x01<<7)^0xFF);

//	RET 
	return;
//; 遊技メダル払出エラー処理 
MS_1MEDAL_PAY3:
//	LD	D,0DAH			; ”ＨＥ”表示要求  セット 
//	z_d=0xDA; 
//	JR	MS_1MEDAL_PAY5 
//	goto MS_1MEDAL_PAY5; 
MS_1MEDAL_PAY4:
//	LD	D,0DBH			; ”ＨＰ”表示要求　セット 
//	z_d=0xDB; 
MS_1MEDAL_PAY5:
//					; // HL = _PT_OUT1 
//	RES	7,(HL)			; 遊技メダル払出装置作動停止 
//	_PT_OUT1&=((0x01<<7)^0xFF); 
// 
//	CALL	MS_HPERR_SET		; 遊技メダル払出エラーセット 
//	MS_HPERR_SET();		//; 遊技メダル払出エラーセット 
//	JR	_MS_1MEDAL_PAY 
//	goto _MS_1MEDAL_PAY; 
// 
}

//;************************************************************************ 
//;*	管理番号      : S-0341-001					* 
//;*	機能	      : 遊技メダル投入チェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_INSERT_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,C,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_SENSOR_CHK,S_WATCH_CLEAR,MS_MEDAL_INC	* 
//;*		      : S_BLOCKER_OFF,S_LPSD_SET,S_BLOCKER_ON		* 
//;************************************************************************ 
//; 
//	後でＰＡＤ整理時にまとめる 
void MS_INSERT_CHK(void)
{
	char z_a;

//	LD	HL,_PT_OUT1 
//	BIT	4,(HL)			; 遊技メダルブロッカーＯＦＦ？ 
//	RET	Z			; 　ＹＥＳ 
	if((_PT_OUT1&(0x01<<4))==0){
		return;
	}
//	CALL	MS_SENSOR_CHK		; 遊技メダル投入センサーチェック 
//	RET	Z			; 通過あり？．．ＮＯ 
	if(MS_SENSOR_CHK()==0)	return;


//; 遊技メダル投入センサー通過チェック開始 
// 
//	LD	L,LOW _FL_GAME_STS	; 回胴回転始動装置 
//	RES	3,(HL)				;;受付許可フラグ　クリア 

	_FL_GAME_STS&=((0x01<<3)^0xFF);

//	CP	00010000B		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ１通過開始？ 
//	JP	NZ,MS_INSERT_CHK10	;   ＮＯ <遊技メダル不正通過> 

//; 遊技メダル投入センサー１通過処理 

//	LD	L,LOW _TM1_MEDAL1	; 遊技メダル投入センサー１ 
//	LD	(HL),@TM_INSERT1	;;通過チェック時間  セット 
// 
//MS_INSERT_CHK1: 
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	CALL	MS_SENSOR_CHK		; 遊技メダル投入センサーチェック 
//	CP	00110000B		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ１・２通過？ 
//	JR	Z,MS_INSERT_CHK2	; 　ＹＥＳ 
// 
//	CP	00000000B		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ信号ＯＦＦ？ 
//	RET	Z			;   ＹＥＳ 
// 
//	CP	00010000B		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ１通過中？ 
//	JR	NZ,MS_INSERT_CHK10	;   ＮＯ <遊技メダル不正通過> 
// 
//	LD	A,(HL)			; // HL = _TM1_MEDAL1 
//	AND	A			; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ１通過時間超過？ 
//	JR	Z,MS_INSERT_CHK8	;   ＹＥＳ <遊技メダル滞留> 
// 
//	JR	MS_INSERT_CHK1 
// 
//; 遊技メダル投入センサー１・２通過処理 
// 
//MS_INSERT_CHK2: 
//	LD	L,LOW _TM1_MEDAL2	; 遊技メダル投入センサー２ 
//	LD	(HL),@TM_INSERT3	;;通過チェック時間  セット 
// 
//MS_INSERT_CHK3: 
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	CALL	MS_SENSOR_CHK		; 遊技メダル投入センサーチェック 
//	CP	00100000B		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ２通過開始？ 
//	JR	Z,MS_INSERT_CHK4	;   ＹＥＳ 
// 
//	CP	00110000B		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ１・２通過中？ 
//	JR	NZ,MS_INSERT_CHK10	;   ＮＯ <遊技メダル不正通過> 
// 
//	LD	A,(HL)			; // HL = _TM1_MEDAL2 
//	CP	@TM_INSERT2		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ２通過時間超過？ 
//	JR	C,MS_INSERT_CHK8	;   ＹＥＳ <遊技メダル滞留> 
// 
//	LD	A,(_TM1_MEDAL1) 
//	AND	A			; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ１通過時間超過？ 
//	JR	Z,MS_INSERT_CHK8	;   ＹＥＳ <遊技メダル滞留> 
// 
//	JR	MS_INSERT_CHK3 
// 
//; 遊技メダル投入センサー２通過処理 
// 
//MS_INSERT_CHK4: 
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	CALL	MS_SENSOR_CHK		; 遊技メダル投入センサーチェック 
// 
//	JR	Z,MS_INSERT_CHK5	; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ通過終了？．．ＹＥＳ 
// 
//	CP	00100000B		; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ２通過中？ 
//	JR	NZ,MS_INSERT_CHK10	;   ＮＯ <遊技メダル不正通過> 
// 
//	LD	A,(HL)			; // HL = _TM1_MEDAL2 
//	AND	A			; 遊技ﾒﾀﾞﾙ投入ｾﾝｻｰ２通過時間超過？ 
//	JR	Z,MS_INSERT_CHK8	;   ＹＥＳ <遊技メダル滞留> 
// 
//	JR	MS_INSERT_CHK4 
// 
//; 遊技メダル通過セット 
// 
//MS_INSERT_CHK5: 
//	LD	L,LOW _FL_GAME_STS 

//	RES	7,(HL)			; 減算修正許可フラグ　クリア 
	_FL_GAME_STS&=((0x01<<7)^0xFF);
//	BIT	5,(HL)			; 遊技メダル限界？ 
//	JR	NZ,MS_INSERT_CHK6	; 　ＹＥＳ 

	if((_FL_GAME_STS&(0x01<<5))) goto MS_INSERT_CHK6;

//	CALL	MS_MEDAL_INC		; 遊技メダル１枚加算 
//	RET	NZ			; 遊技メダル限界？．．ＮＯ 

	if(hand_medal)	hand_medal-=1;
	else			return;

	use_coin+=1;
	if(!MS_MEDAL_INC())	return;
//jjjjjjjjjjjj
//	LD	HL,_FL_GAME_STS 
//	BIT	4,(HL)			; 遊技メダル貯留装置使用時？ 
//	JR	Z,MS_INSERT_CHK7	; 　ＹＥＳ 
	if((_FL_GAME_STS&(0x01<<4))==0) goto MS_INSERT_CHK7;

//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 

//	RET 

	return;

MS_INSERT_CHK6:
//	LD	A,@SET_INCO		; 遊技メダル投入時の 
//						;;出力要求  セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 

	S_LPSD_SET(SET_INCO);		//; 各種ランプ・効果音データセット１ 

//	LD	L,LOW _NB_CREDIT_LED 
//	LD	A,(HL) 
//	ADD	A,1 
//	DAA	//	１０進補正 
//	LD	(HL),A			; 遊技メダル貯留枚数　＋１ 
	_NB_CREDIT_LED++;

MS_INSERT_CHK7:
//	LD	L,LOW _NB_CREDIT_LED 
//	LD	A,(HL) 
	z_a=_NB_CREDIT_LED;

//	CP	50H 			; 遊技メダル貯留枚数限界？ 
//	RET	C			; 　ＮＯ 
	if(z_a<50)	return;

//	LD	(HL),50H		; 遊技メダル貯留枚数５０枚　セット 
	_NB_CREDIT_LED=50;

//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	return;

//	RET 
// 
//; 遊技メダル投入エラー処理（遊技メダル滞留） 
// 
MS_INSERT_CHK8: 
//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
//	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 
//	LD	L,LOW _NB_PAY_LED 
//	LD	C,(HL)			; 遊技メダル払出し枚数表示  退避 

//	LD	(HL),0CAH		; ”ＣＥ”表示  セット 

// 
//MS_INSERT_CHK9: 
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	CALL	MS_SENSOR_CHK		; 遊技メダル投入センサーチェック 
// 
//	JR	NZ,MS_INSERT_CHK9	; 遊技メダル滞留解除？．．ＮＯ 
// 
//	LD	(HL),C			; 遊技メダル払出し枚数表示  復帰 
// 
//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 
//	S_BLOCKER_ON();//		; 遊技メダルブロッカーＯＮ<通過状態> 
//	RET 
//	return; 
// 
//; 遊技メダル投入エラー処理（遊技メダル不正通過） 
//	いらね 
MS_INSERT_CHK10: 
//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
//	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 
// 
//	LD	L,LOW _NB_PAY_LED 
//	LD	C,(HL)			; 遊技メダル払出し枚数表示  退避 
// 
//	LD	(HL),0CBH		; ”ＣＰ”表示  セット 
// 
//MS_INSERT_CHK11: 
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	A,(_PT_IN1_UP) 
//	AND	00001010B		; エラー解除？ 
//	JR	Z,MS_INSERT_CHK11	; 　ＮＯ 
// 
//	LD	(HL),C			; 遊技メダル払出し枚数表示  復帰 
// 
//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 
//	S_BLOCKER_ON();//		; 遊技メダルブロッカーＯＮ<通過状態> 
// 
//	RET 

}

//;************************************************************************ 
//;*	管理番号      : S-0342-001					* 
//;*	機能	      : 回胴回転始動装置チェック			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_START_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Cflag ON = 受付					* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,E,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_STOPSW_CHK,S_IN0_CHK,MS_IN_OUT_DOWN		* 
//;************************************************************************ 
//; 
int MS_START_CHK(void)
{
	char z_a,z_b,z_c,z_d,z_e;
	short bak;
	u_short ra1,ra2;
	int cary;
	cary=0;
//	CALL	MS_STOPSW_CHK		; 停止ボタンチェック 
//	JR	NZ,MS_START_CHK2	; 停止ボタン　操作中？．．ＹＥＳ 
//							; （キャリーフラグ  ＯＦＦ） 
	if(MS_STOPSW_CHK())	goto MS_START_CHK2;

//	LD	B,0001 0111B		; 精算ボタン・投入ボタン 
//						;;スイッチ　チェック要求 
	z_b=0x17;

//	RST	S_IN0_CHK		; 入力ポート０レベルチェック 
//	JR	NZ,MS_START_CHK2	; その他の入力あり？．．ＹＥＳ 
//							; （キャリーフラグ  ＯＦＦ） 
	if(S_IN0_CHK(z_b))	goto MS_START_CHK2;

// 
//	LD	HL,(_PT_IN0_OLD)	; // H = (_PT_IN0_UP),L = (_PT_IN0_OLD) 
//	LD	A,H 
	z_a=_PT_IN0_UP;
//	XOR	L 
	z_a^=_PT_IN0_OLD;
//	BIT	5,A			; 回胴回転始動装置ｽｲｯﾁ継続ON状態？ 
//	JR	NZ,MS_START_CHK2	;   ＹＥＳ <キャリーフラグ  ＯＦＦ> 
	if((z_a&0x20))	goto MS_START_CHK2;
// 
//	LD	HL,_FL_GAME_STS		; 回胴回転始動装置 
//	SET	3,(HL)			;;受付許可フラグ　セット  
	_FL_GAME_STS=(_FL_GAME_STS|(0x01<<3));
// 
//	LD	L,LOW _PT_IN0_UP 
//	BIT	5,(HL)			; 回胴回転始動装置スイッチ　ＯＮ？ 
//	RET	Z			;   ＮＯ 
	if((_PT_IN0_UP&(0x01<<5))==0)	return(cary);

// 
//	LD	L,LOW _NB_PLAY_MEDAL	; 遊技メダル投入枚数　セット 
//	LD	E,(HL) 
	z_e=_NB_PLAY_MEDAL;
MS_START_CHK1:
//	CALL	MS_IN_OUT_DOWN		; 投入時の差枚数カウンタ更新 
	MS_IN_OUT_DOWN();			//; 投入時の差枚数カウンタ更新 
//	DEC	E 
	z_e-=1;
//	JR	NZ,MS_START_CHK1	; 投入枚数分終了？．．ＮＯ 
	if(z_e)	goto MS_START_CHK1;

//; 回胴回転始動装置受付（ハードウェア乱数読み込み） 
// 
//	LD	BC,1100 0000B*100H OR @IN3_PORT 
// 
	DI				//; 割り込み禁止 
// 
//	IN	L,(C) 
//	INC	C 
//	IN	A,(C)			; ハードウェア乱数１読み込み 
//	OR	B			; ハードウェア乱数１ 
//					;;上位２ビット　ＯＮ 
//	LD	H,A 
// 
//	LD	(_BF_RAND1),HL		; 一般遊技図柄抽選用乱数保存<49152 - 65535> 
	ra1=rnd(16383);
	ra2=rnd(16383);
	_BF_RAND1=((ra1+ra2)/2)+49152;

//	INC	C 
//	IN	L,(C) 
//	INC	C 
//	IN	A,(C)			; ハードウェア乱数２読み込み 
//	OR	B			; ハードウェア乱数２ 
//					;;上位２ビット ＯＮ 
//	LD	H,A 
// 
//	LD	(_BF_RAND2),HL		; 役物遊技図柄抽選用乱数保存<49152 - 65535> 
	ra1=rnd(16383);
	ra2=rnd(16383);
	_BF_RAND2=((ra1+ra2)/2)+49152;

	EI				//; 割り込み許可 
// 
//	SCF				; キャリーフラグ  ＯＮ 
// 
	cary=1;
MS_START_CHK2:
//	LD	HL,_FL_GAME_STS		; 回胴回転始動装置 
//	RES	3,(HL)			;;受付許可フラグ　クリア 
	_FL_GAME_STS&=((0x01<<3)^0xFF);

//	RET 
	return(cary);
}

//;************************************************************************ 
//;*	管理番号      : S-0343-001										* 
//;*	機能	      : 投入時の差枚数カウンタ更新						* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_IN_OUT_DOWN									* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	保護ﾚｼﾞｽﾀ     : 												* 
//;*	破壊ﾚｼﾞｽﾀ     : A,BC,HL											* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET										* 
//;************************************************************************ 
//; 
void MS_IN_OUT_DOWN(void)
{
	char z_a,z_b,z_c,z_d,z_h,z_l;
	short z_bc,z_hl,z_de;

//	LD	A,(_FL_ACTION) 
	z_a=_FL_ACTION;
//	AND	@_BNS OR @_RP		; ボーナスゲームか再遊技作動時？ 
	z_a&=(_BNS | _RP);
//	RET	NZ			; 　ＹＥＳ 
	if(z_a)	return;

//	LD	HL,TBL_IN_OUT - 1	; 傾斜値データテーブル　セット 
//	LD	A,(_NB_RANK)		; 設定値　セット 
	z_a=_NB_RANK;

//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	LD	C,(HL)			; 傾斜値　セット 
	z_c=TBL_IN_OUT[MACINE][z_a-1];

//	LD	B,0 
	z_b=0;
	z_bc=(z_c<<8);
	z_bc&=0xFF00;

//	LD	HL,(_CT_IN_OUT)		; 差枚数カウンタ　セット 
//	LD	A,H 
	z_hl=(_CT_IN_OUT[1]<<8);
	z_hl=(_CT_IN_OUT[0]&0xFF)|(z_hl&0xFF00);
	z_a=_CT_IN_OUT[1];
//	CPL		//	BIT反転したものとAND?? 
	z_a^=0xFF;
//	AND	A	//	?? キャリ=0 
//	z_a&=z_a; 
//	SBC	HL,BC			; 差枚数カウンタ　－　傾斜値 
	z_hl=z_hl-z_bc;
//	OR	H 
	z_a=(z_a|((z_hl)&0x00FF));
//	RLCA				; 差枚数カウンタ範囲外？ 
	if((z_a&0x80)){
		z_a=((z_a<<1)|0x01);
		cy=1;
//	JR	C,MS_IN_OUT_DOWN1	; 　ＮＯ 
		goto MS_IN_OUT_DOWN1;
	}
	else{
		z_a=(z_a<<1);
		cy=0;
	}
//	LD	HL,8000H		; 差枚数カウンタの最小値　セット 
	z_hl=0x8000;

MS_IN_OUT_DOWN1:
//	LD	(_CT_IN_OUT),HL		; 差枚数カウンタ更新 
	_CT_IN_OUT[0]=(z_hl&0x00FF);
	_CT_IN_OUT[1]=((z_hl>>8)&0x00FF);

//	RET 

}

//;************************************************************************ 
//;*	管理番号      : S-0344-001					* 
//;*	機能	      : 遊技メダル自動投入				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_AUTO_IN					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_WATCH_CLEAR,MS_MEDAL_INC			* 
//;************************************************************************ 
//; 
//	再遊技時の処理 
void MS_AUTO_IN(void)
{
	short bak1,bak2;

MS_AUTO_IN1:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	HL,(_TM2_REPLAY_ML) 
//	LD	A,H 
//	OR	L			; 遊技メダル自動投入待機時？ 
//	JR	NZ,MS_AUTO_IN		; 　ＹＥＳ 
	if(_TM2_REPLAY_ML)	goto MS_AUTO_IN1;

//	LD	HL,_PT_OUT2 
//	SET	4,(HL)				; 再遊技表示ランプ点灯　セット 
	_PT_OUT2=(_PT_OUT2|(0x01<<4));

//	CALL	MS_MEDAL_INC	; 遊技メダル１枚加算 
//	RET	Z					; 遊技メダル限界？．．ＹＥＳ 
	if(MS_MEDAL_INC())		return; //; 遊技メダル１枚加算 

//	LD	HL,@TM_REPLAY2 
//	LD	(_TM2_REPLAY_ML),HL	; 遊技メダル自動投入 
//						;;待機時間  セット 
	_TM2_REPLAY_ML=TM_REPLAY2;
//	JR	MS_AUTO_IN 
	goto MS_AUTO_IN1;

}


//;************************************************************************ 
//;*	管理番号      : S-0345-001					* 
//;*	機能	      : 外部信号出力要求				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_SCOUNT_OUT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	E = エラー表示データ（下位桁）			* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,E,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_JAC_CHK,SS_ERROR_STOP（ジャンプ）		* 
//;************************************************************************ 

void MS_SCOUNT_OUT(void)
{
	char	z_a,z_b,z_c,z_d;
//	char	bak; 
// 
//; 遊技メダル投入枚数チェック 
// 
//	LD	B,1			; 遊技メダルチェック数１枚　セット 
	z_b=1;
// 
//	CALL	MS_JAC_CHK		; 役物遊技チェック 
//	JR	NZ,MS_SCOUNT_OUT1	; 役物遊技時？．．ＹＥＳ 
	if(!MS_JAC_CHK())	goto MS_SCOUNT_OUT1;
//	LD	B,3			; 遊技メダルチェック数３枚　セット 
	z_b=3;
MS_SCOUNT_OUT1:
//	LD	A,(_NB_PLAY_MEDAL) 
	z_a=_NB_PLAY_MEDAL;
//	DEC	A 
	z_a-=1;
//	CP	B			; 遊技メダル枚数正常範囲？ 
//	JR	C,MS_SCOUNT_OUT2	;   ＹＥＳ 
	if(z_a<z_b)	goto MS_SCOUNT_OUT2;

//	エラー処理・・・ 
// 
//	LD	E,66H			; ”Ｅ４”表示要求  セット 
//	JP	SS_ERROR_STOP 
// 
//; 遊技メダル投入信号回数　セット 
// 
MS_SCOUNT_OUT2:
//	LD	HL,_FL_ACTION 
//	BIT	@BT_RP,(HL)		; 再遊技作動時？ 
//	RET	NZ			; 　ＹＥＳ 
	if(MACINE){	//	ビンビンのみの処理 
		if((_FL_ACTION&(0x01<<BT_RP)))	return;
	}

//	LD	HL,_CT_MEDAL_IN 

//	INC	A			; // A = (_NB_PLAY_MEDAL) 
	z_a+=1;
//	ADD	A,A 
	z_a+=z_a;
	DI				//; 割り込み禁止 

//	ADD	A,(HL) 
	z_a+=_CT_MEDAL_IN;

//	LD	(HL),A			; 遊技メダル投入信号 
//						;;出力回数  セット 
	_CT_MEDAL_IN=z_a;
	EI				//; 割り込み許可 
//	RET 

}


//;************************************************************************ 
//;*	管理番号      : S-0346-001					* 
//;*	機能	      : 最短遊技時間チェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_WAIT_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Cflag ON = 回胴回転許可				* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_LPSD_SET					* 
//;************************************************************************ 
//; 
//	LD	(_TM2_GAME),HL		; 最短遊技時間  セット 
int MS_WAIT_CHK(void)
{
	short wk1,wk2,z_a,z_hl;

//	LD	HL,(_TM2_GAME) 
//	LD	A,H 
	z_a=_TM2_GAME&0x00FF;
//	OR	L			; 最短遊技時間経過？ 
	z_a=(z_a|((_TM2_GAME>>8)&0x00FF));
	z_hl=_TM2_GAME;

//	LD	HL,_PT_OUT1 
//	JR	NZ,MS_WAIT_CHK1		; 　ＮＯ 
	if(FLG_41W){
		if(z_a) goto MS_WAIT_CHK1;
	}
//	RES	5,(HL)			; ウエイト表示ランプ消灯　セット 
	_PT_OUT1&=((0x01<<5)^0xFF);

//	LD	HL,@TM_GAME 
//	LD	(_TM2_GAME),HL		; 最短遊技時間  セット 
//	4.1秒適用
#if	DEBUG_MODE==1
	_TM2_GAME=2;
#else
//	if(FLG_41W)	
	_TM2_GAME=TM_GAME;
//	else		_TM2_GAME=2;
#endif
//	SCF				; キャリーフラグ　ＯＮ 
	return(1);
//	RET 

MS_WAIT_CHK1:
//	LD	A,(HL)			; // HL = _PT_OUT1 
	z_a=_PT_OUT1;
//	AND	0010 0000B		; ウエイト表示ランプ点灯中？ 
	z_a&=0x20;
//	RET	NZ			;   ＹＥＳ <キャリーフラグ  ＯＦＦ> 
	if(z_a)	return(0);
// 
//	SET	5,(HL)			; ウエイト表示ランプ点灯　セット 
	_PT_OUT1=(_PT_OUT1|(0x01<<5));

//	LD	A,@SET_WAIT		; 回胴回転不可時の出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(SET_WAIT);

//	AND	A			; キャリーフラグ  ＯＦＦ 
	return(0);
// 
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0347-001					* 
//;*	機能	      : 回胴回転開始準備				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_REEL_READY					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_LPSD_SET,S_ADDR_SET				* 
//;************************************************************************ 
//; 
//; # = 制御中の回胴番号 (= 3,2,1) 
//; 
void MS_REEL_READY(void)
{
	int lp;
//	LD	A,@SET_START		; 回胴回転開始時の出力要求　セット 
//	RST	S_LPSD_SET			; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(SET_START);			//; 各種ランプ・効果音データセット１ 
// 
//	LD	B,3			; 回胴数  セット 
//	LD	HL,_WK_REEL1 + 7 
//MS_REEL_READY1: 
//	INC	(HL) 
//	INC	(HL) 
//	INC	(HL) 
//	INC	(HL)			; 回胴駆動パルスデータ 
//						;;検索用カウンタ　＋４ 
//	RES	0,(HL)			; 回胴回転開始時の励磁出力１相　セット 
// 
//	LD	A,_WK_REEL2 - _WK_REEL1	; // A = 8 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	DJNZ	MS_REEL_READY1		; 全回胴終了？．．ＮＯ 

//	for(lp=0;lp<3;lp++){ 
//		_WK_REEL2[lp][7]=0; 
//	} 


// 
//	LD	HL,@TM_AUTOSTOP 
//	LD	(_TM2_AUTOSTOP),HL	; 回胴自動停止時間　セット 
	_TM2_AUTOSTOP=TM_AUTOSTOP;

//	RET 
}
// 
//	PAGE 
//;************************************************************************ 
//;*	管理番号      : S-0348-001					* 
//;*	機能	      : 回胴回転開始					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_REEL_START					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : A = 回転開始回胴(XXX00000B)			* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
//; # = セット中の回胴番号 (= 3,2,1) 
//; 
void MS_REEL_START(char dt)
{
	int lp,z_a,z_b,z_c;

	z_a=dt;
//	LD	HL,_WK_REEL3 
//	LD	DE,_WK_REEL2-_WK_REEL1	; // E = 8 , D = 0 
//	LD	BC,0301H		; 回胴数 セット 
//					; // C = 1 
	DI				//; 割り込み禁止 
	z_b=3;
	z_c=1;
MS_REEL_START1:
//	RLCA				; 回転開始回胴？ 
	lp=z_b-1;
	if((z_a&0x80)){
		z_a=((z_a<<1)|0x01);
		cy=1;
	}
	else{
		z_a=(z_a<<1);
		cy=0;
		goto MS_REEL_START2;
	}
//	JR	NC,MS_REEL_START2	; 　ＮＯ 
// 
//	PUSH	HL			; // HL = _WK_REEL# + 0 
//	LD	(HL),C			; 加速状態　セット 
	_WK_REEL[lp][0]=1;
//	INC	HL			; // HL = _WK_REEL# + 1 
//	LD	(HL),C			; 回胴駆動パルス出力時間　初期化 
	_WK_REEL[lp][1]=4;
//	INC	HL			; // HL = _WK_REEL# + 2 
//	LD	(HL),18 + 1		; 加速時の回胴駆動パルス切替え回数　セット 
	_WK_REEL[lp][2]=19;	//	意味なし 
//	INC	HL			; // HL = _WK_REEL# + 3 
//	LD	(HL),D			; 定速時の回胴センサー通過フラグ　初期化 
	_WK_REEL[lp][3]=0;
//	INC	HL			; // HL = _WK_REEL# + 4 
//	LD	(HL),20			; １図柄のステップ番号　初期化 
	_WK_REEL[lp][4]=20;
//	INC	HL			; // HL = _WK_REEL# + 5 
//	LD	(HL),D			; 図柄番号（通過位置用）　初期化 
//	_WK_REEL[lp][5]=0; 

//	POP	HL 
// 
MS_REEL_START2:
//	AND	A			; <キャリーフラグ　ＯＦＦ> 
//	SBC	HL,DE			; 次の回胴制御データＲＡＭアドレス　セット 
//	DJNZ	MS_REEL_START1		; 全回胴セット終了？．．ＮＯ 
	z_b-=1;
	if(z_b)	goto MS_REEL_START1;
// 
	EI				//; 割り込み許可 
// 
//	RET 
}

// 
//	PAGE 
//;************************************************************************ 
//;*	管理番号      : S-0349-001										* 
//;*	機能	      : 回胴回転エラーチェック							* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RLERR_CHK									* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Cflag ON = 回胴再起動							* 
//;*		      : A = 再起動回胴ビット								* 
//;*	保護ﾚｼﾞｽﾀ     :													* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL										* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET										* 
//;************************************************************************ 
//; 
//; # = チェック中の回胴番号 (= 1,2,3) 
//; 
int MS_RLERR_CHK(void)
{
#if 0
	char z_a,z_b,z_c,z_d,z_e;
	int lp;
//	LD	HL,_WK_REEL1 
//	LD	DE,_WK_REEL2-_WK_REEL1	; // DE = 8 
//	LD	BC,0320H			; 回胴数及び左回胴ビット  セット 
	z_b=3;
	z_c=20;
	lp=0;
MS_RLERR_CHK1:

//	LD	A,(HL)			; // HL = _WK_REEL# + 0 
	z_a=_WK_REEL[lp][0]
//	CP	2			; 回胴定速回転中？ 
//	JR	NZ,MS_RLERR_CHK2	; 　ＮＯ 
	if(!(z_a-2))	goto MS_RLERR_CHK2; //ＮＯ 

//	PUSH	HL 
//	LD	A,5			; 図柄番号（通過位置用） 
//					;;要求  セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	LD	A,(HL)			; // HL = _WK_REEL# + 5 
//	POP	HL 
//	CP	23			; 回胴センサー通過済み？ 
//					; （23 = １回胴図柄数＋経験的安全値） 
// 
//	JR	C,MS_RLERR_CHK2		; 　ＹＥＳ 
// 
//	LD	A,C			; 再起動回胴ビット　セット 
// 
//	SCF				; キャリーフラグ  ＯＮ 
// 
//	RET 
// 
MS_RLERR_CHK2:
//	SLA	C			; 次回胴の回胴ビット  セット 
//	ADD	HL,DE 
//	DJNZ	MS_RLERR_CHK1		; 全回胴終了？．．ＮＯ 
	}	//	for end  
// 
//	RET				; <キャリーフラグ  ＯＦＦ> 
#endif
}

//;************************************************************************ 
//;*	管理番号      : S-0350-001					* 
//;*	機能	      : 回胴定速チェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RLFIX_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Cflag ON = 回胴停止可能（全回胴センサー通過）	* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,DE,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
int MS_RLFIX_CHK(void)
{
//	LD	HL,_WK_REEL1 + 3  
//	LD	DE,_WK_REEL2-_WK_REEL1	; // DE = 8 
//	LD	A,(HL) 
//	ADD	HL,DE			; // HL = _WK_REEL2 + 3 
//	AND	(HL) 
//	ADD	HL,DE			; // HL = _WK_REEL3 + 3 
//	AND	(HL)			; 全回胴センサー通過？ 
//	RET	Z			;   ＮＯ <キャリーフラグ  ＯＦＦ> 
//	if(!Z80_FZ){ 
//	関数がまだない！ 
//	SCF				; キャリーフラグ　ＯＮ 
//	} 
	if(!_WK_REEL[0][3])	return(0);
	if(!_WK_REEL[1][3])	return(0);
	if(!_WK_REEL[2][3])	return(0);

	return (1);
//	RET 

}


//;************************************************************************ 
//;*	管理番号      : S-0351-001					* 
//;*	機能	      : 回胴停止受付チェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_STOP_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Cflag ON=回胴停止受付				* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_IN0_CHK,MS_STOPSW_CHK,MS_STOP_LED,S_LPSD_SET	* 
//;************************************************************************ 

int MS_STOP_CHK(void)
{
	char z_a,z_b,z_c,z_d,z_e;

//	LD	A,(_TM1_STOP) 
//	AND	A			; 回胴停止受付待ち？ 
//	RET	NZ			;   ＹＥＳ < キャリーフラグ　ＯＦＦ > 
	if(_TM1_STOP)	return(0);
// 
//; 自動停止判断
// 
//	LD	HL,(_TM2_AUTOSTOP) 
//	LD	A,H 
//	OR	L			; 回胴自動停止時間？ 
// 
// 
//	LD	HL,_FL_STOP_LP 
// 
//	JR	NZ,MS_STOP_CHK2		; 　ＮＯ 
	if(_TM2_AUTOSTOP)	goto MS_STOP_CHK2;

//	LD	BC,320H			; 回胴数及び左回胴ビット　セット 
	z_b=3;
	z_c=0x20;
MS_STOP_CHK1:
//	LD	A,C 
	z_a=z_c;
//	AND	(HL)			; 回胴回転中？ 
	z_a&=_FL_STOP_LP;
//	JR	NZ,MS_STOP_CHK5		; 　ＹＥＳ 
	if(z_a)	goto MS_STOP_CHK5;

//	SLA	C			; 次の回胴ビット  セット 
	z_c=z_c<<1;
//	DJNZ	MS_STOP_CHK1		; 全回胴終了？．．ＮＯ 
	z_b--;
	if(z_b)	goto MS_STOP_CHK1;
// 
//	AND	A			; キャリーフラグ  ＯＦＦ 
	return(0);
// 
//	RET 
// 
//; 停止ボタン判断 
// 
MS_STOP_CHK2:
//	LD	B,0011 0111B		; 回胴回転始動装置・精算ボタン・ 
//							;;投入ボタンスイッチチェック要求 
//	RST	S_IN0_CHK		; 入力ポート０レベルチェック 
//	JR	NZ,MS_STOP_CHK4		; その他の入力あり？．．ＹＥＳ 
	if(S_IN0_CHK(0x37))	goto MS_STOP_CHK4;

// 
//	LD	A,(HL)			; // HL = _FL_STOP_LP 
	z_a=_FL_STOP_LP;
// 
//	CPL 
	z_a^=0xFF;
//	LD	B,A 
	z_b=z_a;
// 
//	CALL	MS_STOPSW_CHK		; 停止ボタンチェック 
	z_a=MS_STOPSW_CHK();		//; 停止ボタンチェック 

//	AND	B			; 受付済み停止ボタン操作中？ 
	z_a&=z_b;
//	JR	NZ,MS_STOP_CHK4		;　 ＹＥＳ 
	if(z_a)	goto MS_STOP_CHK4;
// 
//	LD	DE,(_PT_IN2_OLD)	; // D = (_PT_IN2_UP), E = (_PT_IN2_OLD) 
	z_d=_PT_IN2_UP;
	z_e=_PT_IN2_OLD;
//	LD	A,D 
	z_a=z_d;
//	XOR	E 
	z_a^=z_e;
//	CPL 
	z_a^=0xFF;
//	AND	11100000B		; 停止ボタン継続操作中？ 
	z_a&=0xE0;
//	JR	NZ,MS_STOP_CHK4		;　 ＹＥＳ 
	if(z_a)	goto MS_STOP_CHK4;
// 
//	LD	A,D			; // D = (_PT_IN2_UP) 
	z_a=z_d;

//	AND	(HL)			; // HL = _FL_STOP_LP 
	z_a&=_FL_STOP_LP;
//	LD	D,A			; 停止ボタン受付フラグ　セット 
	z_d=z_a;
//	LD	BC,320H			; 回胴数及び左回胴ビット　セット 
	z_b=0x03;
	z_c=0x20;
MS_STOP_CHK3:
//	LD	A,C 
	z_a=z_c;
//	AND	D			; 停止ボタン受付？ 
	z_a&=z_d;
//	JR	NZ,MS_STOP_CHK5		;   ＹＥＳ 
	if(z_a) goto MS_STOP_CHK5;
// 
//	SLA	C			; 次の回胴ビット　セット 
	z_c=z_c<<1;
//	DJNZ	MS_STOP_CHK3		; 全回胴終了？．．ＮＯ 
	z_b--;
	if(z_b)	goto MS_STOP_CHK3;

// 
//	LD	A,(HL)			; // HL = _FL_STOP_LP 
	z_a=_FL_STOP_LP;
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	CPL 
	z_a^=0xFF;
//	AND	0011 1000B 
	z_a&=0x38;
//	LD	B,A 
	z_b=z_a;
//	LD	A,(HL)			; // HL = _FL_STOP_LP 
	z_a=_FL_STOP_LP;
//	RLCA 
	if((z_a&0x80))	z_a=((z_a<<1)|0x01);
	else			z_a=(z_a<<1);
//	RLCA 
	if((z_a&0x80))	z_a=((z_a<<1)|0x01);
	else			z_a=(z_a<<1);
//	RLCA 
	if((z_a&0x80))	z_a=((z_a<<1)|0x01);
	else			z_a=(z_a<<1);
//	AND	00000111B 
	z_a&=0x07;
//	OR	B 
	z_a=(z_a|z_b);
// 
//	LD	B,A			; 停止ボタンＬＥＤ点灯要求　セット 
	z_b=z_a;
//	CALL	MS_STOP_LED		; 停止ボタンＬＥＤ表示 
	MS_STOP_LED(z_b);		//; 停止ボタンＬＥＤ表示 

// 
//	AND	A			; キャリーフラグ  ＯＦＦ 
	return(0);
// 
//	RET 
// 
MS_STOP_CHK4:

//	LD	B,0011 1000B		; 停止ボタンＬＥＤ点灯要求　セット 
	z_b=0x38;
//	CALL	MS_STOP_LED		; 停止ボタンＬＥＤ表示 
	MS_STOP_LED(z_b);			//; 停止ボタンＬＥＤ表示 
// 
//	AND	A			; キャリーフラグ  ＯＦＦ 
	return(0);
// 
//	RET 
// 
//; 停止受付処理 
// 

MS_STOP_CHK5:
//	LD	A,C			; 回胴ビット　セット 
	z_a=z_c;

//	XOR	(HL)			; // HL = _FL_STOP_LP 
	z_a^=_FL_STOP_LP;
//	LD	(HL),A			; 回胴停止フラグ　セット 
	_FL_STOP_LP=z_a;
// 
//	LD	L,LOW _NB_STOP_ORDER 
//	INC	(HL)			; 回胴停止順番　＋１ 
//	INC	HL				; // HL = _NB_STOP_REEL 
	_NB_STOP_ORDER++;

//	LD	A,4 
	z_a=4;
//	SUB	B 
	z_a-=z_b;
//	LD	(HL),A			; 停止回胴番号　セット 
	_NB_STOP_REEL=z_a;
// 
//	LD	B,0011 1000B		; 停止ボタンＬＥＤ点灯要求　セット 
	z_b=0x38;
//	CALL	MS_STOP_LED		; 停止ボタンＬＥＤ表示 
	MS_STOP_LED(z_b);			//; 停止ボタンＬＥＤ表示 
// 
//	LD	A,@TM_STOPWAIT 
//	LD	(_TM1_STOP),A		; 回胴停止受付待機時間　セット 
	_TM1_STOP=TM_STOPWAIT;
// 
//	LD	A,@SET_STOP		; 停止ボタン受付時の 
//						;;出力要求  セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１  

	S_LPSD_SET(SET_STOP);		//; 各種ランプ・効果音データセット１ 

//	SCF				; キャリーフラグ  ＯＮ 
	return(1);
// 
//	RET 

}

//;************************************************************************ 
//;*	管理番号      : S-0352-001					* 
//;*	機能	      : 全回胴停止チェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RLSTP_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	Zflag ON = 全回胴停止				* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,DE,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
int MS_RLSTP_CHK(void)
{
//	LD	HL,_WK_REEL1 
//	LD	DE,_WK_REEL2-_WK_REEL1	; // DE = 8 
//	LD	A,(HL) 
//	ADD	HL,DE			; // HL = _WK_REEL2 + 0 
//	OR	(HL) 
//	ADD	HL,DE			; // HL = _WK_REEL3 + 0 
//	OR	(HL)			; 全回胴停止チェック 
	if(_WK_REEL[0][0])	return (1);
	if(_WK_REEL[1][0])	return (1);
	if(_WK_REEL[2][0])	return (1);

	return (0);

//	RET				; ゼロフラグ　ＯＮ／ＯＦＦ 
}

//;************************************************************************ 
//;*	管理番号      : S-0353-001					* 
//;*	機能	      : 入賞判定					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_WIN_JUDGE					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_BNS_CHK,MS_LINE_JUDGE,S_RAM_CLEAR		* 
//;*		      : S_WATCH_CLEAR					* 
//;************************************************************************ 

void MS_WIN_JUDGE(void)
{
	int		z_hl,lp;

//	LD	HL,TBL_WIN_CTL1		; 役物連続作動増加装置未作動時  
//							;;一般遊技入賞処理テーブル　セット  
	z_hl=1;

//	CALL	MS_BNS_CHK		; ボーナスゲームチェック  
//	JR	Z,MS_WIN_JUDGE1		; ボーナスゲーム？．．ＮＯ  
	if(MS_BNS_CHK())	goto MS_WIN_JUDGE1;

//	LD	HL,TBL_WIN_CTL2		; 役物連続作動増加装置作動時  
//							;;一般遊技入賞処理テーブル　セット  
	z_hl=2;
		if(!MACINE){
//	CP	@_BB			; 役物遊技時？  
//	JR	Z,MS_WIN_JUDGE1		;   ＮＯ  
		if(!(z_a-_BB))	goto MS_WIN_JUDGE1;

		}else{
//	AND	@_JAC			; 役物遊技時？  
//	JR	Z,MS_WIN_JUDGE1		;   ＮＯ  
		if(!(z_a&_JAC))	goto MS_WIN_JUDGE1;
		}
//	LD	HL,TBL_WIN_CTL3		; 役物遊技入賞処理テーブル　セット 

	z_hl=3;

//	通常遊技時　
MS_WIN_JUDGE1:
//	LD	A,(_NB_PLAY_MEDAL) 
	z_a=_NB_PLAY_MEDAL;
//	ADD	A,A 
	z_a+=z_a;
//	DEC	A 
	z_a-=1;
//	LD	B,A			; 有効ライン数  セット 
	z_b=z_a;
MS_WIN_JUDGE2:
//	PUSH	HL 
//	CALL	MS_LINE_JUDGE			; １ライン入賞判定 
	MS_LINE_JUDGE(z_hl,z_b);		//; １ライン入賞判定 
//	POP	HL 
// 
//	DJNZ	MS_WIN_JUDGE2		; 全有効ライン終了？．．ＮＯ 
	z_b-=1;
	if(z_b)	goto MS_WIN_JUDGE2;

//	LD	A,(_FL_WIN) 
//	BIT	@BT_BB,A		; ＢＢ入賞？ 
//	JR	Z,MS_WIN_JUDGE3		;   ＮＯ 
	if(!(_FL_WIN&(0x01<<BT_BB)))	goto MS_WIN_JUDGE3;
// 
	DI				//; 割り込み禁止 

	bingo_n_bb+=1;	// ＢＩＧ回数 

	if(bonus_interval[0][2]>bonus_interval[0][0])	bonus_interval[0][0]=bonus_interval[0][2];
	if(bonus_interval[0][2]<bonus_interval[0][1])	bonus_interval[0][1]=bonus_interval[0][2];
	bonus_interval[0][2]=0;

	if(bonus_interval[2][2]>bonus_interval[2][0])	bonus_interval[2][0]=bonus_interval[2][2];
	if(bonus_interval[2][2]<bonus_interval[2][1])	bonus_interval[2][1]=bonus_interval[2][2];
	bonus_interval[2][2]=0;



//	LD	HL,TBL_RAM_CLEAR3	; 役物連続作動増加装置入賞時の 
//							;;ＲＡＭ初期化テーブル　セット 
//	RST	S_RAM_CLEAR		; ＲＡＭ初期化 <8062H - 808EH> 
	S_RAM_CLEAR(3);		//; ＲＡＭ初期化 <8062H - 808EH> 
// 
	EI				//; 割り込み許可 

MS_WIN_JUDGE3:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	A,(_WK_FLASH_LP) 
	z_a=_WK_FLASH_LP.lamp;
//	CP	@FLP_BBHIT1		; 
//	JR	NC,MS_WIN_JUDGE3	; 　ＹＥＳ 
//	ちょっと怪しいのでチェック！！ 

//	if(z_a>=FLP_BBHIT1)	goto MS_WIN_JUDGE3;	// 　ＹＥＳ 

//	RET 
}


//;************************************************************************ 
//;*	管理番号      : S-0354-001					* 
//;*	機能	      : １ライン入賞判定				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_LINE_JUDGE					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : B = 判定ライン番号				* 
//;*		          : HL = 入賞処理テーブル				* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : E = エラー表示データ（下位桁）			* 
//;*	保護ﾚｼﾞｽﾀ     : B						* 
//;*	破壊ﾚｼﾞｽﾀ     : A,C,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : SS_ERROR_STOP（ジャンプ）,S_LPSD_SET,S_ADDR_SET	* 
//;************************************************************************ 

void MS_LINE_JUDGE(int tbl,int line)
{
	char	_tbs;
	char	wk_stop;
	char	_rej;
	int lp;

	char z_a,z_b,z_c,z_d;

//char TBL_WIN_CTL1[2][7+4+1][7]	//参考 
	char tbs[3][2]={
		{ 0,7},
		{ 7,4},
		{11,1},
	};

//	_b=1|3|5 
	z_b=line;

	_tbs=tbs[tbl-1][0];
//	LD	C,(HL)			; 判定図柄数  セット 
	z_c=tbs[tbl-1][1];	//	チェックするテーブル数  
//	INC	HL 
	lp=0;
MS_LINE_JUDGE1:
//	LD	A,B			; 判定ライン番号  セット 
	z_a=z_b;
//	ADD	A,(HL) 

//	LD	D,HIGH @RAM		; <ＲＡＭ上位アドレス> 
//	LD	E,A 
//	DE=

//	INC	HL 
//	LD	A,(DE)			; 停止図柄データ　セット 

	if(TBL_WIN_CTL1[MACINE][_tbs+lp][0]==1)	z_a=_WK_STOP_PIC1[z_a-1];
	else									z_a=_WK_STOP_PIC2[z_a-1];

//	AND	(HL)			; 入賞、又は表示あり？ 
	z_a&=TBL_WIN_CTL1[MACINE][_tbs+lp][1];

//	JR	Z,MS_LINE_JUDGE3	;   ＮＯ 
	if(!z_a)	goto MS_LINE_JUDGE3;

//	LD	C,A			; 入賞図柄データ　セット 
	z_c=z_a;

	if(!(_FL_ACTION&_JAC)){
	if(z_a&FRUIT1){
		bingo_get[tei_kou][0]+=1;
	}
	if(z_a&FRUIT2){
		bingo_get[tei_kou][1]+=1;
	}
	if(z_a&CHERRY){
		bingo_get[tei_kou][2]+=1;
	}
	if(z_a&REPLAY){
		bingo_get[tei_kou][3]+=1;
	}
	}

//	INC	HL 

//	LD	E,(HL) 

//	LD	A,(DE)			; 蹴飛ばし図柄データ　セット 
	if(TBL_WIN_CTL1[MACINE][_tbs+lp][2]==1)	z_a=_FL_REJ_PIC1;
	else									z_a=_FL_REJ_PIC2;

//	AND	C 
	z_a&=z_c;
//	LD	E,6DH			; ”Ｅ５”表示要求  セット 
//	JP	NZ,SS_ERROR_STOP	; 蹴飛ばし図柄が入賞？．．ＹＥＳ 
	z_a=0;

//	if(z_a)	SS_ERROR_STOP(0x6D);	//	エラー？ 

//	INC	HL 
//	LD	E,LOW _FL_WIN 
//	LD	A,(DE) 
	z_a=_FL_WIN;
//	OR	(HL) 
	z_a=(z_a|TBL_WIN_CTL1[MACINE][_tbs+lp][3]);
//	LD	(DE),A			; 入賞フラグ  セット 
	_FL_WIN=z_a;

//	INC	HL 
//	LD	A,(HL)			; 入賞時の出力要求　セット 
	z_a=TBL_WIN_CTL1[MACINE][_tbs+lp][4];
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

//	INC	HL 
//	LD	A,(HL)			; １ラインの遊技メダル払出し枚数  セット 
	z_a=TBL_WIN_CTL1[MACINE][_tbs+lp][5];

//	INC	HL 
//	LD	C,(HL)			; バックランプ入賞ライン表示 
//						;;サーチポインタ　セット 
	z_c=TBL_WIN_CTL1[MACINE][_tbs+lp][6];

//	LD	HL,_NB_PAY_MEDAL	; その他のラインの  
//	ADD	A,(HL)			;;遊技メダル払出し枚数を加算 
	z_a+=_NB_PAY_MEDAL;
//	CP	15			; 遊技メダル払出し合計１５枚以上？ 
//	JR	C,MS_LINE_JUDGE2	; 　ＮＯ 
	if(z_a<15)	goto MS_LINE_JUDGE2;
//	LD	A,15			; 遊技メダル払出し合計１５枚に補正 
	z_a=15;
MS_LINE_JUDGE2:
//	LD	(HL),A			; 遊技メダル払出し枚数　セット 
	_NB_PAY_MEDAL=z_a;
//	LD	A,B			; 判定ライン番号  セット 
	z_a=z_b;
//	LD	HL,TBL_WIN_LINE-1	; 有効ラインランプ入賞ライン 
//							;;表示テーブル要求　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	LD	A,(HL) 
	z_a=TBL_WIN_LINE[z_a-1];
//	LD	HL,_WK_WIN_LP 
//	OR	(HL)			; 入賞時有効ラインランプ 
	z_a=(z_a|_WK_WIN_LP);
//	LD	(HL),A			;;点滅データ　セット 
	_WK_WIN_LP=z_a;

//	LD	HL,TBL_WINBACK_LINE-2	; バックランプ入賞ライン表示 
//								;;テーブル要求　セット 
//	LD	A,B						; 判定ライン番号　セット 
	z_a=(z_b-1);
//	ADD	A,A 
	z_a+=z_a;
//	ADD	A,C						; バックランプ入賞ライン表示 
//								;;サーチポインタ加算 
	z_a+=z_c;
//	RST	S_ADDR_SET				; ワーク・テーブルのアドレスセット 

//	LD	A,(HL)			; バックランプ９点滅用 
	z_a=TBL_WINBACK_LINE[z_a];
//							;;データ　セット 
//	INC	HL 
//	LD	C,(HL)			; バックランプ１～８点滅用 
//						;;データ　セット 
	z_c=TBL_WINBACK_LINE[z_a+1];
//	LD	HL,_WK_WINBACK_LP 
//	OR	(HL) 
	z_a=(z_a|_WK_WINBACK_LP[0]);
//	LD	(HL),A			; 入賞時バックランプ９点滅 
//						;;データ　セット 
	_WK_WINBACK_LP[0]=z_a;
//	LD	A,C 
	z_a=z_c;
//	INC	HL 
//	OR	(HL) 

	z_a=(z_a|_WK_WINBACK_LP[1]);
//	LD	(HL),A			; 入賞時バックランプ１～８点滅 
//						;;データ　セット 
	_WK_WINBACK_LP[1]=z_a;
	return;

MS_LINE_JUDGE3:
//	LD	A,6			; 次の入賞図柄判定要求　セット 
	z_a=6;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	DEC	C			; 判定終了？ 
	lp++;
	z_c-=1;
//	JR	NZ,MS_LINE_JUDGE1	;   ＮＯ 
	if(z_c)	goto MS_LINE_JUDGE1;
//	RET 
	if(_FL_PUL_PIC1)	torikoboshi=1;
	else				torikoboshi=0;

}

//;************************************************************************ 
//;*	管理番号      : S-0355-001					* 
//;*	機能	      : 入賞による遊技メダル払出し			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_WIN_PAY					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_BNS_CHK,S_LPSD_SET,MS_IN_OUT_UP		* 
//;*		      : S_WATCH_CLEAR,MS_1MEDAL_PAY			* 
//;************************************************************************ 

void MS_WIN_PAY(void)
{
	char z_a;
	if(!MACINE){	//	かっぱ 
//; 上部ランプ・効果ランプ表示及び遊技メダル払出信号回数セット 
// 
//	LD	HL,_NB_PLAY_MEDAL	; 遊技メダル枚数　セット 
//	LD	BC,_FL_WIN 
//	LD	A,(BC) 
		z_a=_FL_WIN;
//	RRCA				; 再遊技表示？ 
		if((z_a&0x01)){
			z_a=((z_a>>1)|0x80);
			goto MS_WIN_PAY1;
//	JR	C,MS_WIN_PAY1		;   ＹＥＳ 
		}
		else{
			z_a=(z_a>>1);
		}
//	INC	HL			; 遊技メダル払出し枚数　セット 
//					; // HL = _NB_PAY_MEDAL 
	}

//	}else{	//	びんびん 
//	LD	HL,_NB_PAY_MEDAL	; 遊技メダル払出し枚数　セット 
//
//	}
//	LD	A,(HL) 

		z_a=_NB_PAY_MEDAL;
//	AND	A			; 遊技メダル払出しあり？ 

//	RET	Z			;   ＮＯ 
	if(z_a==0)	return;

//	CALL	MS_BNS_CHK		; ボーナスゲームチェック 
//	JR	NZ,MS_WIN_PAY1		; ボーナスゲーム？．．ＹＥＳ 
	if(!MS_BNS_CHK())	goto	MS_WIN_PAY1;

//	LD	A,@SET_PAYSTART		; 入賞による遊技メダル払出し 
//							;;開始時の出力要求　セット 
//	RST	S_LPSD_SET			; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(SET_PAYSTART);		//; 各種ランプ・効果音データセット１ 

MS_WIN_PAY1:
//	LD	DE,_CT_MEDAL_OUT 
// 
	DI				//; 割り込み禁止 
// 
//	LD	A,(DE) 
//	ADD	A,(HL) 
//	ADD	A,(HL) 
//	LD	(DE),A			; 遊技メダル払出信号回数　セット 
// 
	EI				//; 割り込み許可 
// 
	if(!MACINE){	//	かっぱ 
//	LD	A,(BC)			; // BC = _FL_WIN 
	z_a=_FL_WIN;
//	RRCA				; 再遊技表示？ 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
//	RET	C			; 　ＹＥＳ 
		return;
	}
	else{
		z_a=(z_a>>1);
	}

//; 遊技メダル払出しモード選択 
//	LD	L,LOW _FL_GAME_STS 
//	BIT	4,(HL)			; 遊技メダル貯留装置否使用時？ 
//	JR	NZ,MS_WIN_PAY4		; 　ＹＥＳ 
		if((_FL_GAME_STS&0x10))	goto MS_WIN_PAY4;
	}
MS_WIN_PAY2:
	if(!MACINE){
//	LD	A,(_NB_CREDIT_LED) 
	z_a=_NB_CREDIT_LED;
//	CP	50H			; 遊技メダル貯留枚数限界？ 
//	JR	NC,MS_WIN_PAY4		; 　ＹＥＳ 
	if(z_a>=50)	goto MS_WIN_PAY4;

//; 遊技メダル貯留枚数５０枚未満の時は遊技メダル貯留装置に加算 
// 
//	CALL	MS_IN_OUT_UP		; 払出し時の差枚数カウンタ更新 
	MS_IN_OUT_UP();		//; 払出し時の差枚数カウンタ更新 
// 
//	LD	HL,_TM1_CREDIT		; 遊技メダル貯留枚数 
//	LD	(HL),@TM_CREDIT		;;加算待機時間　セット 
	_TM1_CREDIT=TM_CREDIT;

	}else{
//; 遊技メダル払出しモード選択 
//	CALL	MS_IN_OUT_UP		; 払出し時の差枚数カウンタ更新 
	MS_IN_OUT_UP();		//; 払出し時の差枚数カウンタ更新 

//	LD	HL,_FL_GAME_STS 
//	BIT	4,(HL)			; 遊技メダル貯留装置否使用時？ 
//	JR	NZ,MS_WIN_PAY4		; 　ＹＥＳ 
	if((_FL_GAME_STS&0x10))	goto MS_WIN_PAY4;

//	LD	A,(_NB_CREDIT_LED) 
	z_a=_NB_CREDIT_LED;
//	CP	50H			; 遊技メダル貯留枚数限界？ 
//	JR	NC,MS_WIN_PAY4		; 　ＹＥＳ 
		if(z_a>=50)	goto MS_WIN_PAY4;

//; 遊技メダル貯留枚数５０枚未満の時は遊技メダル貯留装置に加算 
// 
//	LD	L,LOW _TM1_CREDIT	; 遊技メダル貯留枚数 
//	LD	(HL),@TM_CREDIT		;;加算待機時間　セット 
	_TM1_CREDIT=TM_CREDIT;
	}

MS_WIN_PAY3:
	if(!MACINE){
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	A,(HL)			; // HL = _TM1_CREDIT 
	z_a=_TM1_CREDIT;
//	AND	A			; 遊技メダル貯留枚数加算待ち？ 
//	JR	NZ,MS_WIN_PAY3		;   ＹＥＳ 
	if(z_a)	goto MS_WIN_PAY3;

//	LD	L,LOW _NB_CREDIT_LED 
//	LD	A,(HL) 
//	ADD	A,1 
//	DAA 
//	LD	(HL),A			; 遊技メダル貯留枚数　＋１ 
	_NB_CREDIT_LED+=1;
// 
//	LD	A,@SET_PAY		; 入賞による遊技メダル１枚 
//						;;払出し時の出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(SET_PAY);		//; 各種ランプ・効果音データセット１ 
// 
//	INC	HL			; // HL = _NB_PAY_LED 
//	LD	A,(HL) 
//	ADD	A,1 
//	DAA 
//	LD	(HL),A			; 遊技メダル払出し枚数表示　＋１ 
	_NB_PAY_LED+=1;
// 
//	LD	L,LOW _NB_PAY_MEDAL 
//	DEC	(HL)			; 遊技メダル払出し枚数　－１ 
	_NB_PAY_MEDAL-=1;
//	JR	NZ,MS_WIN_PAY2		; 遊技メダル払出し終了？．．ＮＯ 
	if(_NB_PAY_MEDAL)	goto MS_WIN_PAY2;
// 
//	JR	MS_WIN_PAY5 
		goto MS_WIN_PAY5;
	}else{	// びんびん  
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 
//	LD	A,(HL)			; // HL = _TM1_CREDIT 
	z_a=_TM1_CREDIT;
//	AND	A			; 遊技メダル貯留枚数加算待ち？ 
//	JR	NZ,MS_WIN_PAY3		;   ＹＥＳ 
	if(z_a)	goto MS_WIN_PAY3;		//;   ＹＥＳ 

//	LD	L,LOW _NB_CREDIT_LED 
//	LD	A,(HL) 
//	ADD	A,1 
//	DAA 
//	LD	(HL),A			; 遊技メダル貯留枚数　＋１ 
	_NB_CREDIT_LED+=1;
// 
//	JR	MS_WIN_PAY5 
	goto MS_WIN_PAY5;

	}

// 
//; 遊技メダル払出装置からの遊技メダル払出し 
// 
MS_WIN_PAY4:
	if(!MACINE){
//	CALL	MS_IN_OUT_UP		; 払出し時の差枚数カウンタ更新 
	MS_IN_OUT_UP();		//; 払出し時の差枚数カウンタ更新 
// 
//	CALL	MS_1MEDAL_PAY	//; 遊技メダル１枚払出し 
	MS_1MEDAL_PAY();		//; 遊技メダル１枚払出し 
// 
//	LD	A,@SET_PAY			; 入賞による遊技メダル１枚 
//							;;払出し時の出力要求　セット 
//	RST	S_LPSD_SET			; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(SET_PAY);	//; 各種ランプ・効果音データセット１ 

//	LD	HL,_NB_PAY_LED 
//	LD	A,(HL) 
//	ADD	A,1 
//	DAA 
//	LD	(HL),A			; 遊技メダル払出し枚数表示　＋１ 
	_NB_PAY_LED+=1;
// 
//	LD	L,LOW _NB_PAY_MEDAL 
//	DEC	(HL)			; 遊技メダル払出し枚数　－１ 
	_NB_PAY_MEDAL-=1;
	out_coin+=1;		// 総払い出し枚数 

//	JR	NZ,MS_WIN_PAY4		; 遊技メダル払出し終了？．．ＮＯ 
		if(_NB_PAY_MEDAL)	goto MS_WIN_PAY4;
// 
	}else{	//びんびん 
//; 遊技メダル払出装置からの遊技メダル払出し 
		MS_1MEDAL_PAY();		//; 遊技メダル１枚払出し 
	}

MS_WIN_PAY5:
	if(!MACINE){

//	CALL	MS_BNS_CHK		; ボーナスゲームチェック 
//	RET	NZ			; ボーナスゲーム？．．ＹＥＳ 
		if(!MS_BNS_CHK())	return;

//	LD	A,@SET_PAYEND		; 入賞による遊技メダル払出し終了時 
//							;;の出力要求　セット 
//	RST	S_LPSD_SET			; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(SET_PAYEND);	//; 各種ランプ・効果音データセット１ 

	}else{	//	びんびん 
//	LD	A,@SET_PAY		; 入賞による遊技メダル１枚 
	z_a=SET_PAY;
//						;;払出し時の出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);
// 
//	LD	HL,_NB_PAY_LED 
//	LD	A,(HL) 
//	ADD	A,1 
//	DAA 
//	LD	(HL),A			; 遊技メダル払出し枚数表示　＋１ 
	_NB_PAY_LED+=1;
// 
//	LD	L,LOW _NB_PAY_MEDAL 
//	DEC	(HL)			; 遊技メダル払出し枚数　－１ 
	_NB_PAY_MEDAL-=1;
	out_coin+=1;		// 総払い出し枚数 
	if(_FL_ACTION&(0x01<<BT_BB)){	//	ＢＢ作動中
		bb_getcoin_total+=1;
		bb_shot_coin+=1;
	}
//	JR	NZ,MS_WIN_PAY2		; 遊技メダル払出し終了？．．ＮＯ 
	if(_NB_PAY_MEDAL)	goto MS_WIN_PAY2;
// 
//	LD	A,(_WK_FLASH_LP)	; 遊技メダル払い出し時の上部ランプ 
//							;;パターン確認要求　セット 
	z_a=_WK_FLASH_LP.lamp;
//	CP	@FLP_PAY			; パターン出力中？ 
//	RET	NZ					;   ＮＯ  
	if(!(z_a-FLP_PAY))	return;

//	LD	A,@SET_PAYEND		; 入賞による遊技メダル払出し終了時 
//					;;の出力要求　セット 
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(SET_PAYEND);

//	RET 
	}
}


//;************************************************************************* 
//;*	管理番号      : S-0356-001					 * 
//;*	機能	      : 払出し時の差枚数カウンタ更新 			 * 
//;*	ﾓｼﾞｭｰﾙ名      : MS_IN_OUT_UP					 * 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						 * 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 						 * 
//;*	保護ﾚｼﾞｽﾀ     : 						 * 
//;*	破壊ﾚｼﾞｽﾀ     : A,HL						 * 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_BNS_CHK					 * 
//;************************************************************************* 
//; 
void MS_IN_OUT_UP(void)
{
	char	z_a;

//	CALL	MS_BNS_CHK		; ボーナスゲームチェック 
//	RET	NZ			; ボーナスゲーム？．．ＹＥＳ 
	if(!MS_BNS_CHK())	return;

//	LD	HL,_CT_IN_OUT + 1 
//	LD	A,(HL) 
	z_a=_CT_IN_OUT[1];
//	CPL 
	z_a^=0xFF;
//	INC	(HL)			; 差枚数カウンタ　＋１ 
	_CT_IN_OUT[1]+=1;
//	AND	(HL) 
	z_a&=_CT_IN_OUT[1];
//	RLCA				; 差枚数カウンタ範囲外？ 
	if((z_a&0x80))	z_a=((z_a<<1)|0x01);
	else{
		z_a=(z_a<<1);
//	RET	NC			; 　ＮＯ 
		return;
	}

//	LD	(HL),7FH 
	_CT_IN_OUT[1]=0x7F;
//	DEC	HL 
//	LD	(HL),0FFH		; 差枚数カウンタに最大値　セット 
	_CT_IN_OUT[0]=0xFF;
// 
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0357-002					* 
//;*	機能	      : 遊技終了チェック				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_GAME_CHK					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_LPSD_SET,S_WATCH_CLEAR,MS_1MEDAL_PAY		* 
//;*		      : MS_CREDIT_DEC,S_RAM_CLEAR,M_MAIN（ジャンプ）	* 
//;************************************************************************ 
//; 
void MS_GAME_CHK(void)
{
	char z_a,z_b,z_c,z_d;

//	LD	HL,_FL_ACTION 
//	LD	A,(HL) 
	z_a=_FL_ACTION;

//	RRCA				; 再遊技作動時？ 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
	}
	else{
		z_a=(z_a>>1);
//	JR	NC,MS_GAME_CHK1		;   ＮＯ 
		goto MS_GAME_CHK1;
	}

//; 再遊技作動終了処理 
//					; // HL = _FL_ACTION 
//	LD	(HL),0			; 再遊技作動フラグ  クリア 
	_FL_ACTION=0;
//	LD	L,LOW _PT_OUT2 
//	RES	4,(HL)			; 再遊技表示ランプ消灯　セット 
	_PT_OUT2&=((0x01<<4)^0xFF);

//	RET 
	return;
// 
MS_GAME_CHK1:
//	RRCA				; ＲＢ作動時？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,MS_GAME_CHK6		;   ＮＯ 
		goto MS_GAME_CHK6;
	}

//; 役物連続作動装置作動時の役物遊技回数チェック 

//	LD	L,LOW _CT_BONUS_WIN 

//	LD	A,(_WK_WIN_LP) 
//	AND	100B			; 役物入賞あり？ 
	z_a=_WK_WIN_LP&0x04;
//	JR	Z,MS_GAME_CHK3		;   ＮＯ 
	if(!z_a)	goto MS_GAME_CHK3;

//	DEC	(HL)			; ＲＢ作動時の役物入賞回数　－１ 
	_CT_BONUS_WIN-=1;

//	JR	Z,MS_GAME_CHK4		; 役物入賞回数終了？．．ＹＥＳ 
	if(!_CT_BONUS_WIN)	goto MS_GAME_CHK4;

MS_GAME_CHK3:
//	DEC	HL			; // HL = _CT_BONUS_PLAY 
//	DEC	(HL)			; ＲＢ作動時の役物遊技回数　－１ 
	_CT_BONUS_PLAY-=1;
//	RET	NZ			; 役物遊技回数終了？．．ＮＯ 
	if(_CT_BONUS_PLAY)	return;

//; 役物連続作動装置作動終了処理 
MS_GAME_CHK4:
//	LD	L,LOW _PT_OUT0		; 役物連続作動装置 
//	RES	6,(HL)				;;本当たり信号出力　ＯＦＦ 
	_PT_OUT0&=((0x01<<6)^0xFF);

//	LD	L,LOW _PT_OUT2 
//	RES	5,(HL)			; 遊技状態表示ランプ１消灯　セット 
	_PT_OUT2&=((0x01<<5)^0xFF);

//	LD	L,LOW _FL_ACTION	; 役物連続作動装置 
//	RES	@BT_RB,(HL)		;;作動フラグ  クリア 
	_FL_ACTION&=((0x01<<BT_RB)^0xFF);

//	BIT	@BT_BB,(HL)		; ＢＢ作動時？ 
//	JR	NZ,MS_GAME_CHK5		;   ＹＥＳ 
	if((_FL_ACTION&(0x01<<BT_BB)));	goto MS_GAME_CHK5;

//	LD	HL,0FFFH 
//	LD	(_NB_COUNT_LED1),HL	; 回数表示ＬＥＤ１、２　消灯  
	_NB_COUNT_LED1=0xFF;
	_NB_COUNT_LED2=0x0F;

//	LD	A,@SET_RBEND		; 役物連続作動装置作動終了時の 
//							;;出力要求　セット 
	aft_play_rb=0;	// 前回のＲＢからのプレイ数  
	z_a=SET_RBEND;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

//	RET 
	return;
//; 役物連続作動増加装置作動時の役物連続作動装置作動終了処理 
// 
MS_GAME_CHK5:
	if(!MACINE){
//	LD	L,LOW _CT_BIG_WIN 
//	DEC	(HL)			; ＢＢ作動時のＲＢ入賞回数　－１ 
	_CT_BIG_WIN-=1;
//	JR	Z,MS_GAME_CHK7		; 入賞回数３回終了？．．ＹＥＳ 
	if(!_CT_BIG_WIN) goto MS_GAME_CHK7;
//	DEC	HL			; // HL = _CT_BIG_PLAY 
//	LD	A,(HL)			; ＢＢ作動時の一般遊技回数　セット 
	z_a=_CT_BIG_PLAY;
//	AND	A			; 遊技回数終了？ 
//	JR	Z,MS_GAME_CHK7		; 　ＹＥＳ 
	if(!z_a) goto MS_GAME_CHK7;
//	LD	A,@SET_BB		; 役物連続作動増加装置作動時の 
//						;;出力要求　セット 
	z_a=SET_BB;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 
// 
		return;
	}else{	//	びんびん 


//HL=_FL_ACTION 

//	LD	C,(HL)			; 作動フラグ　退避 
	z_c=_FL_ACTION;
//	LD	L,LOW _CT_BIG_WIN 
//	DEC	(HL)			; ＢＢ作動時のＲＢ入賞回数　－１ 
	_CT_BIG_WIN-=1;
//	JR	Z,MS_GAME_CHK7		; 入賞回数終了？．．ＹＥＳ 
	if(!_CT_BIG_WIN)	goto MS_GAME_CHK7;

//	DEC	HL			; // HL = _CT_BIG_PLAY 
//	LD	A,(HL)			; ＢＢ作動時の一般遊技回数　セット 
	z_a=_CT_BIG_PLAY;
//	AND	A			; 遊技回数終了？ 
//	JR	Z,MS_GAME_CHK7		; 　ＹＥＳ 
	if(!z_a)	goto MS_GAME_CHK7;
// 
//	LD	B,@SET_BB1		; 役物連続作動増加装置作動時の 
//					;;出力要求１　セット 
	z_b=SET_BB1;
//	BIT	@BT_BB1,C		; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)確認要求セット 
//	JR	NZ,MS_GAME_CHK16	; 確認要求図柄によるＢＢ作動時？ＹＥＳ 
	if((z_c&(0x01<<BT_BB1))) goto MS_GAME_CHK16;

//	INC	B			; 役物連続作動増加装置作動時の 
//					;;出力要求２　セット 
//					; // B = @SET_BB2 
	z_b=SET_BB2;
MS_GAME_CHK16:
//	CP	@BBCHG+1		; ＢＢ作動音３に切り替え？ 
//					; // A = (_CT_BIG_PLAY) 
//	JR	NC,MS_GAME_CHK18	;   ＮＯ 
	if(z_a>=(BBCHG+1))	goto MS_GAME_CHK18;

MS_GAME_CHK17:
//	LD	B,@SET_BB3		; 役物連続作動増加装置作動時の 
//						;;出力要求３　セット 
	z_b=SET_BB3;
MS_GAME_CHK18:
//	LD	A,B 
	z_a=z_b;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 
// 
//	RET 
	return;
	}
MS_GAME_CHK6:
//	RRCA				; ＢＢ作動時？ 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
	}
	else{
		z_a=(z_a>>1);
//	RET	NC			;   ＮＯ 
		if(!((_FL_ACTION&(0x01<<BT_BB)) || (_FL_ACTION&(0x01<<BT_RB)))){
			if(use_coin>out_coin)	medal_wave[play_num]=use_coin-out_coin;
			else					medal_wave[play_num]=out_coin-use_coin;
			play_num+=1;	// プレイ回数  
			aft_play_bb+=1;	// 前回のＢＢからのプレイ数  
			aft_play_rb+=1;	// 前回のＲＢからのプレイ数  
			bonus_interval[0][2]+=1;
			bonus_interval[1][2]+=1;
			bonus_interval[2][2]+=1;
			bonus_interval[3][2]+=1;

		}
		return;
	}

//; 役物連続作動増加装置遊技回数チェック 
// 
//	LD	L,LOW _CT_BIG_PLAY 
//	DEC	(HL)			; ＢＢ作動時の一般遊技回数　－１ 
	_CT_BIG_PLAY-=1;
	bonusin_total+=1;	// 累積ボーナスゲームプレイ数 
	bonusin_shot+=1;	// １回のボーナスゲームプレイ数 

	if(!MACINE){
//	RET	NZ			; 遊技回数終了？．．ＮＯ 
		if(_CT_BIG_PLAY)	return;
	}else{
//	LD	A,(HL) 
		z_a=_CT_BIG_PLAY;
	}

//	LD	L,LOW _FL_WIN 
//	BIT	@BT_RB,(HL)		; ＲＢ入賞？ 
//	RET	NZ			;   ＹＥＳ 
	if((_FL_WIN&(0x01<<BT_RB)))	return;

	if(MACINE){
//	CP	@BBCHG			; ＢＢ作動音３に切り替え？ 
//					; // A = (_CT_BIG_PLAY) 
//	JR	Z,MS_GAME_CHK17		;   ＹＥＳ 
		if(z_a==BBCHG)	goto MS_GAME_CHK17;

//	AND	A 
//	RET	NZ			; 遊技回数終了？．．ＮＯ 
		if(z_a) return;
	}

//;  役物連続作動増加装置作動終了処理 
MS_GAME_CHK7:
//	XOR	A 
	z_a=0;
//	LD	(_FL_ACTION),A		; 作動フラグ  クリア 
	_FL_ACTION=z_a;
	aft_play_bb=0;
	if(bonusin_shot>bonusin_max)	bonusin_max=bonusin_shot;
	if(bonusin_shot<bonusin_min)	bonusin_min=bonusin_shot;
	bonusin_shot=0;

	if(bb_shot_coin>bb_getcoin_max)	bb_getcoin_max=bb_shot_coin;
	if(bb_shot_coin<bb_getcoin_min)	bb_getcoin_min=bb_shot_coin;
	bb_shot_coin=0;
	bonus_interval[0][2]=0;
	bonus_interval[1][2]=0;

//	LD	(_NB_PAY_LED),A		; 遊技メダル払出し枚数表示　クリア 
	_NB_PAY_LED=z_a;
// 
//	LD	HL,0FFFH 
//	LD	(_NB_COUNT_LED1),HL	; 回数表示ＬＥＤ１、２　消灯 
	_NB_COUNT_LED1=0xFF;
	_NB_COUNT_LED2=0x0F;

//	LD	(_WK_WIN_LP),A		; 入賞時有効ラインランプ 
//							;;点滅データ　クリア 
	_WK_WIN_LP=z_a;

//	LD	HL,_PT_OUT5 
	DI				//; 割り込み禁止 
//	LD	A,(HL) 
//	AND	1110 0000B 
	z_a=_PT_OUT5;
	z_a&=0xE0;
//	LD	(HL),A			; 有効ラインランプ消灯　セット 
	_PT_OUT5=z_a;

	EI				//; 割り込み許可 

//	LD	L,LOW _PT_OUT2 
	if(!MACINE){
//	RES	6,(HL)			; 遊技状態表示ランプ２消灯　セット 
		_PT_OUT2&=((0x01<<6)^0xFF);
	}else{
//	RES	6,(HL)			; 遊技状態表示ランプ２、３消灯　セット 
		_PT_OUT2&=((0x01<<6)^0xFF);
//	RES	7,(HL) 
		_PT_OUT2&=((0x01<<7)^0xFF);
	}
// 
//	LD	A,@SET_BBEND		; 役物連続作動増加装置作動終了時の 
//					;;出力要求　セット 
	z_a=SET_BBEND;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 

	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

MS_GAME_CHK8:
//	RST 	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 	S_WATCH_CLEAR();		//; ウォッチドッグクリア 
// 
//	LD	A,(_WK_FLASH_LP)	; ＢＢ作動終了時の上部ランプ 
//							;;パターン確認要求　セット 
	z_a=_WK_FLASH_LP.lamp;
//	CP	@FLP_BBEND		; 上部ランプ(ﾊﾟﾀｰﾝ9)出力中？ 
//	JR	Z,MS_GAME_CHK8		;   ＹＥＳ 

//	if((z_a==FLP_BBEND))	goto MS_GAME_CHK8;

// 
//	LD	L,LOW _PT_OUT0		; 役物連続作動増加装置 
//	RES	7,(HL)				;;本当たり信号出力　ＯＦＦ 
	_PT_OUT0&=((0x01<<7)^0xFF);

//; 役物連続作動増加装置作動終了後のモード選択 
// 
//	LD	L,LOW _FL_GAME_STS 
//	BIT	0,(HL)			; 自動精算？ 
//	JR	Z,MS_GAME_CHK10		; 　ＮＯ 
	if(!(_FL_GAME_STS&0x01))	goto MS_GAME_CHK10;

//	BIT	4,(HL)			; 遊技メダル貯留装置使用時？ 
//	JR	NZ,MS_GAME_CHK10	; 　ＮＯ 
	if((_FL_GAME_STS&(0x01<<4)))	goto MS_GAME_CHK10;

//; 自動精算 
MS_GAME_CHK9:
//	LD	A,(_NB_CREDIT_LED) 
	z_a=_NB_CREDIT_LED;
//	AND	A			; 遊技メダル貯留枚数あり？ 
//	JR	Z,MS_GAME_CHK10		; 　ＮＯ 
	if(!z_a)	goto MS_GAME_CHK10;

//	CALL	MS_1MEDAL_PAY		; 遊技メダル１枚払出し 
	EI

	MS_1MEDAL_PAY();		//; 遊技メダル１枚払出し 

//	CALL	MS_CREDIT_DEC		; 遊技メダル貯留枚数１枚減算 
	MS_CREDIT_DEC();		//; 遊技メダル貯留枚数１枚減算 

//	JR	MS_GAME_CHK9 
	goto MS_GAME_CHK9;

//; 打ち止め 

MS_GAME_CHK10:
#if 0
//	LD	HL,_FL_GAME_STS 
//	BIT	2,(HL)			; 打ち止め自動解除？ 
//	JR	Z,MS_GAME_CHK14		; 　ＹＥＳ 
	if(!(_FL_GAME_STS&0x04))	goto MS_GAME_CHK14;

//	LD	L,LOW _NB_COUNT_LED1 
//	LD	(HL),0EEH		; 打ち止め表示　セット 
	_NB_COUNT_LED1=0xEE;

//	LD	L,LOW _TM1_RESET 
#endif
MS_GAME_CHK11:
#if 0
//	LD	(HL),@TM_RESET		; 外部打止め解除信号 
//							;;入力時間  セット 
	_TM1_RESET=TM_RESET;
#endif
MS_GAME_CHK12:
#if 0
//	RST 	S_WATCH_CLEAR		; ウォッチドッグクリア 
// 	S_WATCH_CLEAR();		//; ウォッチドッグクリア 
// 
//	LD	A,(_PT_IN0_UP) 
	z_a=_PT_IN0_UP;
//	RLCA				; 打止解除スイッチ  ＯＮ？ 
	if((z_a&0x80)){
		z_a=(z_a<<1)|0x01;
//	JR	C,MS_GAME_CHK13		;   ＹＥＳ 
		goto MS_GAME_CHK13;
	}
	else{
		z_a=z_a<<1;
	}

//	LD	A,(_PT_IN1_UP) 
	z_a=_PT_IN1_UP;
//	AND	0000 1010B		; ｴﾗｰ解除ｽｲｯﾁ,設定ﾎﾞﾀﾝｽｲｯﾁ  ＯＮ？ 
	z_a&=0x0A;
//	JR	NZ,MS_GAME_CHK13	; 　ＹＥＳ 
	if(z_a)	goto MS_GAME_CHK13;

//	LD	A,(_PT_IN1_OLD) 
	z_a=_PT_IN1_OLD;
//	RLCA				; 外部打止め解除信号入力あり？ 
	if((z_a&0x80)){
		z_a=(z_a<<1)|0x01;
//	JR	C,MS_GAME_CHK11		; 　ＮＯ 
		goto MS_GAME_CHK11;
	}
	else{
		z_a=z_a<<1;
	}

//	LD	A,(HL)			; // HL = _TM1_RESET 
	z_a=_TM1_RESET;
//	AND	A			; 外部打止め解除信号入力時間終了？ 
//	JR	NZ,MS_GAME_CHK12	;   ＮＯ 
	if(z_a)	goto MS_GAME_CHK12;
// 

#endif
MS_GAME_CHK13:
//	LD	L,LOW _NB_COUNT_LED1 
//	LD	(HL),0FFH		; 回数表示ＬＥＤ１　消灯 
//	_NB_COUNT_LED1=0xFF;

//; 役物連続作動増加装置作動終了時のＲＡＭ初期化 
MS_GAME_CHK14:
//	LD	SP,@STACK		; スタックポインタ　セット 
// 
//	LD	HL,TBL_RAM_CLEAR2	; 役物連続作動増加装置作動終了時の 
//							;;ＲＡＭ初期化テーブル　セット 
//	RST	S_RAM_CLEAR			; ＲＡＭ初期化 <808FH - 81E9H> 
	S_RAM_CLEAR(2);			//; ＲＡＭ初期化 <808FH - 81E9H> 

	DI				//; 割り込み禁止 

//	LD	HL,_FL_GAME_STS //	これの次が_WK_REEL#(==HL+1) 
//	LD	A,(HL) 
	z_a=_FL_GAME_STS;
//	AND	0001 0101B 
	z_a&=0x15;
//	LD	(HL),A			; 遊技状態フラグ不必要 
//						;;ビット　クリア 
	_FL_GAME_STS=z_a;

//	LD	HL,TBL_RAM_CLEAR4	; 役物連続作動増加装置作動終了時の 
//							;;ＲＡＭ初期化テーブル　セット 
//	RST	S_RAM_CLEAR			; ＲＡＭ初期化 <800DH - 808EH> 
	S_RAM_CLEAR(4);			//; ＲＡＭ初期化 <800DH - 808EH> 

//	LD	HL,81EAH		; ＲＡＭ初期化先頭アドレス　セット 
//	LD	BC,22*100H		; ＲＡＭ初期化範囲　セット 
//					; < 割り込み時最大スタック使用量＋２バイト > 
//MS_GAME_CHK15: 
//	LD	(HL),C			; ＲＡＭ初期化 <81EAH - 81FFH> 
//	INC	HL			; 次のＲＡＭアドレス　セット//HL=_WK_REEL# 
//	DJNZ	MS_GAME_CHK15		; ＲＡＭ初期化終了？．．ＮＯ 
// 
	EI				//; 割り込み許可 
// 
//	JP	M_MAIN 
}
// 
//;************************************************************************ 
//;*	管理番号      : S-0500-001					* 
//;*	機能	      : 抽選						* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_ALL_LOT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_JAC_CHK,MS_JAC_LOT,MS_BB_LOT,MS_INSIDE_LOT	* 
//;*		      : MS_NORMAL_LOT					* 
//;************************************************************************ 

//	一番はじめの抽選
//	jjjjjjjjjjjjjjjjjjjjjjjjjjjjj
void MS_ALL_LOT(void)
{

//	CALL	MS_JAC_CHK		; 役物遊技チェック 
//	JR	Z,MS_ALL_LOT1		; 役物遊技時？．．ＮＯ  

//	p_p=0;

	if(MS_JAC_CHK())	goto MS_ALL_LOT1;

//	CALL	MS_JAC_LOT		; 役物遊技図柄抽選 
	MS_JAC_LOT();		//; 役物遊技図柄抽選 
//	RET 
	return;

//; 一般遊技図柄抽選用確率テーブルセット 

MS_ALL_LOT1:
//	LD	HL,TBL_PIC_LOT - @LOT_MEDAL - @LOT_RANK 

//	HL=TBL_PIC_LOT[MACINE][_NB_PLAY_MEDAL-1][_NB_RANK-1][] 
//	LD	DE,@LOT_MEDAL		; 一般遊技図柄抽選用 
//							;;確率テーブル  セット 
//	LD	A,(_NB_PLAY_MEDAL) 
//	LD	B,A			; 遊技メダル枚数　読み込み 
//MS_ALL_LOT2: 
//	ADD	HL,DE			; 遊技メダル枚数に応じた 
//						;;テーブル変更 
//	DJNZ	MS_ALL_LOT2		; 変更終了？．．ＮＯ 
//	LD	E,@LOT_RANK		; // D = 0 
//	LD	A,(_NB_RANK) 
//	LD	B,A				; 設定値　読み込み 
//MS_ALL_LOT3: 
//	ADD	HL,DE				; 設定値に応じたテーブル変更 
//	DJNZ	MS_ALL_LOT3		; 変更終了？．．ＮＯ 

// 
//	ここからＨＬ・ＤＥ・ＢＣ・キャリはグローバル変数内に入れて操作していく  
// 
	hli=&_TBL_PIC_LOT[0];
	tei_kou=0;

//	START START START START START 

//	EX	DE,HL		// HL=_TBL_PIC_LOT[] 
	_EX_DE_HL_

//	LD	HL,(_BF_RAND1)		; 一般遊技図柄抽選用乱数読み込み<49152 - 65535> 
	z_hl=_BF_RAND1;
//	LD	A,(_FL_ACTION) 
	z_a=_FL_ACTION;

//#ifdef KAPPA	//	両機種とも同じ 
//	CP	@_BB			; ＢＢ作動時？  
//#else if BINBIN 
//	AND	@_BB			; ＢＢ作動時？  
//#endif 
	if(!MACINE){
		if(!(z_a-_BB))	goto MS_ALL_LOT4;
	}
	else{
		z_a&=_BB;
//	JR	Z,MS_ALL_LOT4		;   ＮＯ 
		if(!z_a)	goto MS_ALL_LOT4;
	}

//	CALL	MS_BB_LOT			; 役物連続作動増加装置作動時 
	tei_kou=2;
	MS_BB_LOT();	//		; 役物連続作動増加装置作動時 
//	RET 
		return;
MS_ALL_LOT4:
//	LD	A,(_FL_PUL_PIC2) 
//	_FL_PUL_PIC2|=BB;

	z_a=_FL_PUL_PIC2;

//	AND	@BB OR @RB		; 内部中遊技？ 
	z_a&=(BB|RB);
//	JR	Z,MS_ALL_LOT5		;   ＮＯ 
	if(!z_a)	goto MS_ALL_LOT5;

//	ここがＢＢフラグとかの立ってるときの抽選場所
//	CALL	MS_INSIDE_LOT		; 内部中遊技図柄抽選 
#ifdef DEBUG_FONT
//	DEB_STOP3(0xFFFFFF);
#endif
		MS_INSIDE_LOT();//		; 内部中遊技図柄抽選 
	return;
//	RET 

//	通常時の抽選
MS_ALL_LOT5:
//	CALL	MS_NORMAL_LOT		; 役物連続作動増加装置未作動時 
//kokokara1
	MS_NORMAL_LOT();	//		; 役物連続作動増加装置未作動時 
//								;;一般遊技図柄抽選 
//	RET 
}


//;************************************************************************ 
//;*	管理番号      : S-0501-001					* 
//;*	機能	      : 役物遊技図柄抽選				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_JAC_LOT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_LOT_SET					* 
//;************************************************************************ 

void MS_JAC_LOT(void)
{
	int		wk1,wk2;

//	LD	C,@NM_JHIT		; 役物当選用図柄データ番号　セット  
	z_c=NM_JHIT;

//	LD	HL,(_BF_RAND2)		; 役物遊技図柄抽選用乱数読み込み<49152 - 65535>  
	z_hl=_BF_RAND2;
//	LD	DE,(TBL_JAC_LOT)	; 役物遊技図柄抽選用確率 
	z_de=TBL_JAC_LOT;

//							;;テーブル  セット 
//	ADD	HL,DE			; 役物当選？ 
//	JR	C,MS_JAC_LOT1		; 　ＹＥＳ 
	z_hl+=z_de;
	if(z_hl>65535){
		goto MS_JAC_LOT1;
	}
//#ifdef KAPPA 
//	INC	C			; はずれ用図柄データ番号　セット 
//					; // C = @NM_JHIT+1 
//#else if BINBIN 
//	DEC	C			; はずれ用図柄データ番号　セット 
//					; // C = @NM_JHIT-1 
//#endif 
	if(!MACINE)	z_c+=1;
	else		z_c-=1;

MS_JAC_LOT1:
//	LD	B,4			; 図柄データ保存数  セット 
	z_b=4;
//	CALL	MS_LOT_SET		; 引込み・蹴飛ばし図柄データ保存 
	MS_LOT_SET();//		; 引込み・蹴飛ばし図柄データ保存 
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0502-001					* 
//;*	機能	      : 引込み・蹴飛ばし図柄データ保存			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_LOT_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : C = 図柄データ番号				* 
//;*			      : B = 図柄データ保存数				* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET					* 
//;************************************************************************ 
//; 

void MS_LOT_SET(void)
{
	int lp;

#if 0
//	LD	A,C 
	z_a=z_c;

//	ADD	A,A			; // 2A 
	z_a+=z_a;
//	ADD	A,A			; // 4A 
	z_a+=z_a;

//	LD	HL,TBL_PICTURE_SET - 4	; 引込み・蹴飛ばし図柄テーブル要求　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	S_ADDR_SET();//		; ワーク・テーブルのアドレスセット 
//		TBL_PICTURE_SET[MACINE][z_c-1]; 
	hl=&TBL_PICTURE_SET[MACINE][z_c-1][0];

//	LD	DE,_FL_PUL_PIC1 
	de=&_FL_PUL_PIC1;

//	LD	C,B 
	z_c=z_b;
//	LD	B,0 
	z_b=0;
//	LDIR				; 引込み・蹴飛ばし図柄データ　セット 
	do{
		de[0]=hl[0];
		de=&de[1];
		hl=&hl[1];
		z_c-=1;
	}while(z_c);
#endif

	for(lp=0;lp<z_b;lp++){
		_FL_PIC[lp]=TBL_PICTURE_SET[MACINE][z_c-1][lp];
	}
	if(!(_FL_ACTION&_JAC)){
	if(_FL_PUL_PIC1&FRUIT1){
		bingo_poll[tei_kou][0]+=1;
	}
	if(_FL_PUL_PIC1&FRUIT2){
		bingo_poll[tei_kou][1]+=1;
	}
	if(_FL_PUL_PIC1&CHERRY){
		bingo_poll[tei_kou][2]+=1;
	}
	if(_FL_PUL_PIC1&REPLAY){
		bingo_poll[tei_kou][3]+=1;
	}
	playnum_rate[tei_kou]+=1;
	}
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0503-001										* 
//;*	機能	      : 役物連続作動増加装置作動時一般遊技図柄抽選		* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_BB_LOT										* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : （ HL = 乱数(C000H～FFFFH) ）					* 
//;*			      : DE = 確率テーブル								* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	保護ﾚｼﾞｽﾀ     : HL												* 
//;*	破壊ﾚｼﾞｽﾀ     : BC,DE											* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_LOT_JUDGE,MS_LOT_SET							* 
//;************************************************************************ 

void MS_BB_LOT(void)
{
	char wk;
//	EX	DE,HL 
	_EX_DE_HL_

//	LD	BC,@LOT_BB 
//	ADD	HL,BC				; 役物連続作動増加装置作動時 
//							;;一般遊技確率テーブル  セット 
	hli=&hli[12];

//	EX	DE,HL 
	_EX_DE_HL_

//	LD	BC,@BB_PLAY*100H OR @NM_BBPLAY	; 役物連続作動装置及び 
//						;;一般入賞図柄抽選要求　セット 
//						; <B = 抽選図柄数、C = 図柄データ番号> 
	z_b=BB_PLAY;
	z_c=NM_BBPLAY;

//	CALL	MS_LOT_JUDGE			; 抽選判定  
	MS_LOT_JUDGE();	//			; 抽選判定 

//	LD	B,4				; 図柄データ保存数  セット 
	z_b=4;
//	CALL	MS_LOT_SET			; 引込み・蹴飛ばし図柄データ保存 
	MS_LOT_SET();	//			; 引込み・蹴飛ばし図柄データ保存 

//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0504-001										* 
//;*	機能	      : 抽選判定										* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_LOT_JUDGE									* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : HL = 抽選基準数									* 
//;*		          : DE = 確率テーブル								* 
//;*		          : B = 抽選図柄数									* 
//;*		          : C = 図柄データ番号								* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : Cflag ON = 当たり								* 
//;*		          : Cflag OFF = はずれ								* 
//;*		          : HL = 抽選基準数									* 
//;*		          : DE = 確率テーブル								* 
//;*		          : C = 図柄データ番号								* 
//;*	保護ﾚｼﾞｽﾀ     : 												* 
//;*	破壊ﾚｼﾞｽﾀ     : A,BC,DE,HL										* 
//;*	使用ﾓｼﾞｭｰﾙ    : 												* 
//;************************************************************************ 

int MS_LOT_JUDGE(void)
{
	int lp;
	lp=0;
MS_LOT_JUDGE_1:

//	PUSH	BC 
	push_(&bc,&z_b,&z_c);

//	LD	A,(DE) 
//	z_a=de[0];

//	LD	C,A			; 確率データ（下位桁）  セット  
//	INC	DE 
//	LD	A,(DE) 
//	LD	B,A			; 確率データ（上位桁）  セット  
	z_bc=*dei;

//	INC	DE 
	dei+=1;
//	ADD	HL,BC			; 当選？ 
	z_hl+=z_bc;
//	POP	BC 
	pop_(&bc,&z_b,&z_c);

//	RET	C			;   ＹＥＳ <キャリーフラグ>  
	if(z_hl>65535){
		cy=1;
		return(1);
	}

//	INC	C			; 図柄データ番号  ＋１  
	z_c+=1;
//	DJNZ	MS_LOT_JUDGE		; 抽選図柄数終了？．．ＮＯ  
	z_b-=1;

	if(z_b)	goto MS_LOT_JUDGE_1;

//	RET				; <キャリーフラグ　ＯＦＦ> 
	cy=0;
	return(0);
}

//;************************************************************************ 
//;*	管理番号      : S-0505-001					* 
//;*	機能	      : 内部中遊技図柄抽選				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_INSIDE_LOT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : （ HL = 乱数(C000H～FFFFH) ）			* 
//;*		      :	（ DE = 確率テーブル ）				* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	B						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_FRUIT_LOT,MS_LOT_SET				* 
//;************************************************************************ 

void MS_INSIDE_LOT(void)
{
//	CALL	MS_FRUIT_LOT		; 一般入賞図柄抽選 
	MS_FRUIT_LOT();//		; 一般入賞図柄抽選 

//	LD	B,2			; 図柄データ保存数  セット 
//	CALL	MS_LOT_SET		; 引込み・蹴飛ばし図柄データ保存 
	z_b=2;
	MS_LOT_SET();	//		; 引込み・蹴飛ばし図柄データ保存 

//	RET 

}


//;************************************************************************ 
//;*	管理番号	: S-0506-001										* 
//;*	機能		: 一般入賞図柄抽選									* 
//;*	ﾓｼﾞｭｰﾙ名	: MS_FRUIT_LOT										* 
//;*	入力ﾊﾟﾗﾒｰﾀ	: （HL = 抽選基準数）								* 
//;*				: DE = 確率テーブル									* 
//;*	出力ﾊﾟﾗﾒｰﾀ	: Cflag ON = 当たり									* 
//;*				: Cflag OFF = はずれ								* 
//;*				: HL = 抽選基準数									* 
//;*				: DE = 確率テーブル									* 
//;*				: C = 図柄データ番号								* 
//;*	保護ﾚｼﾞｽﾀ	: HL												* 
//;*	破壊ﾚｼﾞｽﾀ	: A,BC,DE											* 
//;*	使用ﾓｼﾞｭｰﾙ	: MS_LOT_JUDGE										* 
//;************************************************************************ 

void MS_FRUIT_LOT(void)
{

//	LD	A,(_CT_IN_OUT + 1) 
	z_a=_CT_IN_OUT[1];
//	RLCA					; 差枚数カウンタは正？ 
	if((z_a&0x80)){
		z_a=(z_a<<1)|0x01;
	}
	else{
		z_a=(z_a<<1);
		goto MS_FRUIT_LOT1;
//	JR	NC,MS_FRUIT_LOT1		; 　ＹＥＳ 
	}

//	LD	BC,@LOT_IN_OUT 
	z_bc=LOT_IN_OUT ;

//	EX	DE,HL 
	_EX_DE_HL_

//	ADD	HL,BC				; 低期待値・高期待値テーブル切替え 
	hli=&hli[6];
	tei_kou=1;
//	EX	DE,HL 
	_EX_DE_HL_

#ifdef DEBUG_FONT
//	DEB_KA(0x1234);
#endif
MS_FRUIT_LOT1:
//	LD	BC,@NB_FRUIT*100H OR @NM_FRUIT	; 抽選要求　セット  
//						; <B = 抽選図柄数、C = 図柄データ番号>  
	z_b=NB_FRUIT;
	z_c=NM_FRUIT;

//	CALL	MS_LOT_JUDGE			; 抽選判定 

	MS_LOT_JUDGE();				//; 抽選判定 

//	RET					; <キャリーフラグ> 
}


//;************************************************************************ 
//;*	管理番号      : S-0507-001					* 
//;*	機能	      : 役物連続作動増加装置未作動時一般遊技図柄抽選	* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_NORMAL_LOT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : （ HL = 乱数(C000H～FFFFH) ）			* 
//;*		      : （ DE = 確率テーブル ）				* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	BC						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_FRUIT_LOT,MS_LOT_JUDGE,MS_LOT_SET		* 
//;************************************************************************ 
//; 

void MS_NORMAL_LOT(void)
{

//	CALL	MS_FRUIT_LOT			; 一般入賞図柄抽選  
	MS_FRUIT_LOT();	//			; 一般入賞図柄抽選   

//	JR	C,MS_NORMAL_LOT1 		; 当選？．．ＹＥＳ  
	if(cy)	goto MS_NORMAL_LOT1;


//	LD	BC,@NB_BONUS*100H OR @NM_BONUS	; 役物連続作動増加装置及び  
//										;;役物連続作動装置抽選要求　セット  
//										; <B = 抽選図柄数、C = 図柄データ番号>  
//	CALL	MS_LOT_JUDGE	; 抽選判定  
	z_b=NB_BONUS;
	z_c=NM_BONUS;
	MS_LOT_JUDGE();			//; 抽選判定  
	if(cy)	goto MS_NORMAL_LOT1;

//	LD	C,@NM_NFAIL			; はずれ用図柄データ番号　セット  

	z_c=NM_NFAIL;

MS_NORMAL_LOT1: 

//	LD	B,4						; 図柄データ保存数  セット 
//	CALL	MS_LOT_SET			; 引込み・蹴飛ばし図柄データ保存  
	z_b=4;
//kokokara1
	MS_LOT_SET();

//	RET  
}


//;************************************************************************ 
//;*	管理番号      : S-0600-001					* 
//;*	機能	      : 図柄組合せ制御					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_PIC_CTL					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL,HL',DE'				* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_RLDAT_SET,S_ADDR_SET,MS_CREJ_CTL,MS_REJ3_CTL	* 
//;*		      : MS_PUL_CTL,MS_REJ2_CTL,MS_SPPOINT_SET		* 
//;*		      : MS_STOPPIC_SET					* 
//;************************************************************************ 
//; 

//	ここが重要！これができないとドラムが止まらない！！ 
//	はやく直す！！！12/02 
//	停止	12/23 直さなくては！！！
void MS_PIC_CTL(void)
{
	int lp1;

//	LD	A,5			; 図柄番号（通過位置用） 
//					;;要求　セット 
//	CALL	MS_RLDAT_SET		; 回胴情報データセット 
//
//	LD	A,(HL)			; // HL = _WK_REEL# + 5 (#=1,2,3) 
	z_a=_WK_REEL[_NB_STOP_REEL-1][5];

//	CP	21			; 図柄番号（通過位置用） ＞ ２０？ 
//	JR	C,MS_PIC_CTL1		;   ＮＯ 
	if(z_a<21)	goto MS_PIC_CTL1;

//
//	SUB	21			; 図柄番号修正（０～２０） 
	z_a-=21;
MS_PIC_CTL1:
//	LD	L,LOW _NB_STOP_REEL 
//	LD	B,(HL)			; 停止回胴番号　セット 
	z_b=_NB_STOP_REEL;

//
//	INC	HL			; // HL = _BF_PICTURE 
//	LD	(HL),A			; 回胴停止受付時図柄番号　保存 
	_BF_PICTURE=z_a;

//	INC	HL			; // HL = _NB_REJECT 
//	LD	(HL),0			; 蹴飛ばしコマ数　クリア 
	_NB_REJECT=0;
//	INC	HL			; // HL = _FL_STOP_PNT 
//	LD	(HL),1111 1000B		; 停止可能位置フラグ初期化 
	_FL_STOP_PNT=0xF8;

//	LD	HL,TBL_PICTURE_ARG - 27	; 回胴図柄配列テーブル要求　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	XOR	A 
//	LD	DE,27 
//MS_PIC_CTL2: 
//	ADD	A,5			; 停止回胴に応じて 
//	ADD	HL,DE			;;回胴図柄配列テーブルをずらす 
//	DJNZ	MS_PIC_CTL2		; ずらし終了？．．ＮＯ 
// 
//	EXX				; <表レジスタ　→　裏レジスタ> 
// 
//	LD	HL,TBL_LINE_SEARCH - 5	; 有効ライン検索テーブル 
//					;;要求  セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	EX	DE,HL 
//	EXX				; <裏レジスタ　→　表レジスタ> 
// 
//	LD	A,2			; 回胴図柄配列テーブル数　セット 
//	LD	DE,_WK_REEL_PIC1 
//MS_PIC_CTL3: 
//	LD	C,7			; // B=0 
//	LDIR				; 回胴図柄データ　セット 
// 
//	LD	C,81 - 7 
//	ADD	HL,BC			; 次の回胴図柄配列テーブル　セット 
//	DEC	A			; 回胴図柄データ１、２セット終了？ 
//	JR	NZ,MS_PIC_CTL3		;   ＮＯ 

	for(lp1=0;lp1<7;lp1++){
		_WK_REEL_PIC1[lp1]=TBL_PICTURE_ARG[MACINE][_NB_STOP_REEL-1][_BF_PICTURE+lp1];
		_WK_REEL_PIC2[lp1]=TBL_PICTURE_ARG[MACINE][(_NB_STOP_REEL-1)+3][_BF_PICTURE+lp1];
	}
	stp_reel_buf[_NB_STOP_REEL-1]=_BF_PICTURE;

#if 0
	wait(1);
	while(1){
		if(pad_cnt & PAD_L2)	break;
			FntPrint(dbg_flg.fnt[0],"P1=%x P2=%x\n",_WK_REEL_PIC1[0],_WK_REEL_PIC2[0]);
			FntPrint(dbg_flg.fnt[0],"P1=%x P2=%x\n",_WK_REEL_PIC1[1],_WK_REEL_PIC2[1]);
			FntPrint(dbg_flg.fnt[0],"P1=%x P2=%x\n",_WK_REEL_PIC1[2],_WK_REEL_PIC2[2]);
			FntPrint(dbg_flg.fnt[0],"P1=%x P2=%x\n",_WK_REEL_PIC1[3],_WK_REEL_PIC2[3]);
			FntPrint(dbg_flg.fnt[0],"P1=%x P2=%x\n",_WK_REEL_PIC1[4],_WK_REEL_PIC2[4]);
			FntPrint(dbg_flg.fnt[0],"P1=%x P2=%x\n",_WK_REEL_PIC1[5],_WK_REEL_PIC2[5]);
			FntPrint(dbg_flg.fnt[0],"P1=%x P2=%x\n",_WK_REEL_PIC1[6],_WK_REEL_PIC2[6]);
		wait(1);
	}
	wait(2);
#endif

//	DE'=TBL_LINE_SEARCH[_NB_STOP_REEL-1][0] 
	de_b=&TBL_LINE_SEARCH[_NB_STOP_REEL-1][0];

//	CALL	MS_CREJ_CTL		; チェリー蹴飛ばし制御 
//	hhhhhhhhh
	MS_CREJ_CTL();

//	CALL	MS_REJ3_CTL		; 第３停止時の蹴飛ばし制御 
	MS_REJ3_CTL();

//	CALL	MS_PUL_CTL		; 引込み制御 
	MS_PUL_CTL();

//	CALL	MS_REJ2_CTL		; 第２停止時の蹴飛ばし制御 
	MS_REJ2_CTL();

//	CALL	MS_SPPOINT_SET		; 停止位置  セット 
	MS_SPPOINT_SET();

//	CALL	MS_STOPPIC_SET		; 停止図柄  セット 
	MS_STOPPIC_SET();

//	RET
}

//;************************************************************************ 
//;*	管理番号      : S-0601-001					* 
//;*	機能	      : 回胴情報データセット				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RLDAT_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : A = 回胴情報検索番号				* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	HL = 回胴制御データＲＡＭアドレス		* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET					* 
//;************************************************************************ 
//; 

int MS_RLDAT_SET(char data)
{
	int i;

//	LD	HL,_WK_REEL1 - 8	; 指定の回胴制御データ 
//							;;ＲＡＭアドレス要求　セット 
//	RST	S_ADDR_SET			; ワーク・テーブルのアドレスセット 
//	LD	A,(_NB_STOP_REEL)	; 停止回胴番号  セット 
//	ADD	A,A			; //  * 8  (8=_WK_REEL2-_WK_REEL1) 
//	ADD	A,A 
//	ADD	A,A 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	RET  

	i=_NB_STOP_REEL-1;
	return (i);
}

//;************************************************************************ 
//;*	管理番号      : S-0602-001					* 
//;*	機能	      : チェリー蹴飛ばし制御				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_CREJ_CTL					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_REJPUL1_CTL					* 
//;************************************************************************ 
//; 
#define _TBL_CHERRY_REJ	(0)
#define _TBL_ETC_REJ	(1)
#define _TBL_ALL_PUL	(2)
#define _TBL_EXT_REJ	(3)


void MS_CREJ_CTL(void)
{
//	LD	A,(_NB_STOP_REEL) 
	z_a=_NB_STOP_REEL;
//	DEC	A			; 左回胴？ 
	z_a-=1;
//	RET	NZ			;   ＮＯ 
	if(z_a)	return;

//	LD	HL,TBL_CHERRY_REJ	; チェリー蹴飛ばし 
//							;;制御テーブル  セット 
//	LD	B,1					; 制御回数  セット  
	z_b=1;
	MS_REJPUL1_CTL(_TBL_CHERRY_REJ);	//		; 抽選図柄引込み・蹴飛ばし制御 

//	RET 
}

//;************************************************************************** 
//;*	管理番号	: S-0603-001											* 
//;*	機能		: 抽選図柄引込み・蹴飛ばし制御							* 
//;*	ﾓｼﾞｭｰﾙ名	: MS_REJPUL1_CTL										* 
//;*	入力ﾊﾟﾗﾒｰﾀ	: HL= 引込み・蹴飛ばし制御テーブル  	    			* 
//;*				: B = 制御回数											* 
//;*	出力ﾊﾟﾗﾒｰﾀ	:														* 
//;*	保護ﾚｼﾞｽﾀ	:	C,HL												* 
//;*	破壊ﾚｼﾞｽﾀ	:	A,B,DE												* 
//;*	使用ﾓｼﾞｭｰﾙ	: MS_REJPUL2_CTL,S_ADDR_SET								* 
//;************************************************************************** 
//; 

void MS_REJPUL1_CTL(int tbl)
{
	int lp;

	lp=0;
MS_REJPUL1_CTL1:
	switch(tbl){
		case _TBL_CHERRY_REJ:
			khl=&TBL_CHERRY_REJ[MACINE];
		break;

		case _TBL_ETC_REJ:
			khl=&TBL_ETC_REJ[MACINE][lp];
		break;

		case _TBL_EXT_REJ:
			khl=&TBL_EXT_REJ[MACINE][lp];
		break;

		case _TBL_ALL_PUL:
			khl=&TBL_ALL_PUL[MACINE][lp];
		break;
	}

//	PUSH	HL 
//	PUSH	BC 
	push_(&bc,&z_b,&z_c);

//	LD	D,HIGH @RAM		; <ＲＡＭ上位アドレス> 
//	LD	E,(HL) 
	de=khl->keru;

//	INC	HL 
//	LD	A,(DE) 
//	LD	C,A			; 抽選時引込み・蹴飛ばし 
//					;;図柄データ  セット 
	z_a=*de;
	z_c=z_a;
//	CALL	MS_REJPUL2_CTL		; 引込み・蹴飛ばし制御 
	MS_REJPUL2_CTL();
	pop_(&bc,&z_b,&z_c);
//	POP	BC 
//	POP	HL 

//	LD	A,11			; 次の制御テーブル要求　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	DJNZ	MS_REJPUL1_CTL		; 制御回数終了？．．ＮＯ 
	z_b-=1;
	lp+=1;
	if(z_b)	goto MS_REJPUL1_CTL1;
//	RET 
}

//;************************************************************************** 
//;*	管理番号      : S-0604-001											* 
//;*	機能	      : 引込み・蹴飛ばし制御								* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_REJPUL2_CTL										* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : DE'= 有効ライン検索テーブル							* 
//;*		          : HL = 引込み・蹴飛ばし制御テーブル					* 
//;*		          : C  = 引込み・蹴飛ばし図柄データ						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 													* 
//;*	保護ﾚｼﾞｽﾀ     : DE'													* 
//;*	破壊ﾚｼﾞｽﾀ     : A,BC,DE,HL,HL',BC'									* 
//;*	使用ﾓｼﾞｭｰﾙ    : 													* 
//;************************************************************************** 
//	pppppppppppppp
void MS_REJPUL2_CTL(void)
{
	char	lin[5];

	lin[0]=khl->line1;
	lin[1]=khl->line2;
	lin[2]=khl->line3;
	lin[3]=khl->line4;
	lin[4]=khl->line5;

//; 
//;    全有効ライン一括判定 
//; 
//	LD	D,HIGH @RAM		; <ＲＡＭ上位アドレス> 
//	LD	E,(HL)			; // DE = _WK_ALL_PIC# 
	de=khl->stop1;		//	ここが後々・・・アドレス変換
	z_d=0x80;

	debs2=_WK_ALL_PIC1;
	debs3=_WK_ALL_PIC2;

//	LD	A,(DE)			; // A = 停止図柄データ（全有効ライン用） 
	z_a=*de;

//	AND	C			; // C = 引込み・蹴飛ばし図柄データ 
	z_a&=z_c;

//	INC	HL			; // (HL) = 制御図柄 
//	AND	(HL)			; 全有効ライン上に制御図柄あり？ 
	z_a&=khl->all;
//	RET	Z			;   ＮＯ 
	if(!z_a)	return;

//; 
//;    各有効ライン判定 
//; 
//	LD	A,(_NB_REJECT) 
	z_a=_NB_REJECT;
//	CP	4			; 蹴飛ばしコマ数限界？ 
	if(z_a<4)	cy=1;
	else		cy=0;
//	RET	NC			;   ＹＥＳ 
	if(!cy)	return;

//	LD	E,A			; 蹴飛ばしコマ数　セット 
	z_e=z_a;

//	INC	HL 
//	LD	A,(HL)			; // A = 回胴図柄ＲＡＭアドレス下位 
//	INC	HL 
//	EXX				; <表レジスタ　→　裏レジスタ> 
	_EXX_
//	LD	B,HIGH @RAM		; <ＲＡＭ上位アドレス> 
//	LD	C,A			; 回胴図柄データ　セット 
	bc=khl_b->reel;
//	EXX				; <裏レジスタ　→　表レジスタ> 
	_EXX_

//	LD	A,(HL)			; // A = 停止図柄ＲＡＭアドレス下位 
//	INC	HL 
// 
//	EXX				; <表レジスタ　→　裏レジスタ> 
	_EXX_
//	LD	H,HIGH @RAM		; <ＲＡＭ上位アドレス> 
//	LD	L,A			; 停止図柄データ  セット 
//	EXX				; <裏レジスタ　→　表レジスタ> 
	hl=khl_b->stop2;
	_EXX_

//BC'=_WK_REEL_PIC1[0]////////////////
//DE'=TBL_LINE_SEARCH[_NB_STOP_REEL-1][0];////////////////
//HL'=_WK_STOP_PIC1[0]////////////////


// 
//	LD	A,(HL)			; 引込み・蹴飛ばしフラグ　セット 
	z_a=khl->keru_f;
//	INC	HL 
	hl=&lin[0];

//	CP	1111 1000B		; 蹴飛ばし制御？ 
	if(z_a<0xF8)	cy=1;
	else			cy=0;
//	JR	Z,MS_REJPUL2_CTL1	;   ＹＥＳ 
	if(!(z_a-0xF8)){
		debs1=1;
		goto MS_REJPUL2_CTL1;	//	蹴飛ばし
	}
//	LD	E,0FFH			; 蹴飛ばしコマ数　無効化 
	z_e=0xFF;
	//	引き込み 
	debs1=0;
MS_REJPUL2_CTL1: 
//	LD	A,(_FL_STOP_PNT) 
	z_a=_FL_STOP_PNT;

//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80); 
	else			z_a=(z_a>>1); 
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80); 
	else			z_a=(z_a>>1); 
//	RRCA 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
		cy=1;
	}
	else{
		z_a=(z_a>>1);
		cy=0;
	}

//	LD	B,A			; 停止可能位置データ  セット 
	z_b=z_a;

//	LD	A,5			; 制御コマ数  セット 
	z_a=5;
MS_REJPUL2_CTL2: 
//	PUSH	AF			; 制御コマ数　退避 
	push_(&af,&z_a,&cy);

//BC'=_WK_REEL_PIC1[0]////////////////
//DE'=TBL_LINE_SEARCH[_NB_STOP_REEL-1][0];////////////////
//HL'=_WK_STOP_PIC1[0]////////////////

//	EXX				; <表レジスタ　→　裏レジスタ> 
	_EXX_

//	これがＰＵＳＨされる 
//BC=_WK_REEL_PIC1[0]////////////////
//DE=TBL_LINE_SEARCH[_NB_STOP_REEL-1][0];////////////////
//HL=_WK_STOP_PIC1[0]////////////////

//	PUSH	HL			; 停止図柄データ　退避 
	push_(&hl,&z_h,&z_l);
//	PUSH	DE			; 有効ライン検索テーブル　退避 
	push_(&de,&z_d,&z_e);
//	PUSH	BC			; 回胴図柄データ　退避 
	push_(&bc,&z_b,&z_c);
//	EXX				; <裏レジスタ　→　表レジスタ> 

	_EXX_

//	SRL	B			; 蹴飛ばし位置？ 
	if((z_b&0x01)){
		z_b=(z_b>>1);
		z_b&=0x7F;
		cy=1;	//	キャリが立つ 
	}
	else{
		z_b=(z_b>>1);
		cy=0;	//	キャリが立たない 
		z_b&=0x7F;
	}
//	JR	NC,MS_REJPUL2_CTL6	;   ＹＥＳ 
	if(!cy)	goto MS_REJPUL2_CTL6;

//	PUSH	HL			; 引込み・蹴飛ばし制御テーブル　退避 
	push_(&hl,&z_h,&z_l);
//	PUSH	BC			; 蹴飛ばし位置データ　退避 
	push_(&bc,&z_b,&z_c);

//	LD	A,(_NB_PLAY_MEDAL) 
	z_a=_NB_PLAY_MEDAL;
//	ADD	A,A 
	z_a+=z_a;
//	DEC	A 
	z_a-=1;
//	LD	B,A			; 有効ライン数  セット 
	z_b=z_a;
MS_REJPUL2_CTL3: 

//	EXX				; <表レジスタ　→　裏レジスタ> 
	_EXX_

//BC=_WK_REEL_PIC1[0]//////////////// 7 
//DE=TBL_LINE_SEARCH[_NB_STOP_REEL-1][0];//////////////// 5 
//HL=_WK_STOP_PIC1[0]//////////////// 5 

//	LD	A,(DE)			; 有効ライン検索データ  セット 
	z_a=*de;

//	INC	DE		; 有効ライン検索テーブル　＋１ 
	de+=1;

//	ADD	A,C 
//	z_a+=z_c;
//	LD	C,A 
//	z_c=z_a;
	if(z_a==0xFE)	bc-=2;
	else			bc+=z_a;

//	LD	A,(BC)			; 有効ラインに応じた回胴図柄データ　セット 
	z_a=*bc;
//	AND	(HL)			; （回胴図柄）AND（停止図柄） 
//	if(hl==&_WK_STOP_PIC1[0])	DEB_STOP3(0xF0F0);	OK
	z_a=(z_a&*hl);
//	INC	L			; 次の停止図柄データＲＡＭアドレス　セット 
	hl+=1;
//	EXX				; <裏レジスタ　→　表レジスタ> 
	_EXX_
//	AND	(HL)			; （回胴図柄）AND（停止図柄） 
//						;; AND（制御図柄） 
	z_a&=*hl;
//	if(z_a==BIN_CHERRY)	DEB_STOP3(0xF0F0);
//	AND	C			; 引込み・蹴飛ばし？ 
	z_a=(z_a&z_c);
//	JR	Z,MS_REJPUL2_CTL4	;   ＮＯ 
	if(!z_a)	goto MS_REJPUL2_CTL4;

//	INC	E			; 蹴飛ばしコマ数　＋１ 
	z_e+=1;
//	LD	A,E 
	z_a=z_e;
//	CP	5			; 蹴飛ばしコマ数限界チェック 
	if(z_a<5)	cy=1;
	else		cy=0;

//	JR	MS_REJPUL2_CTL5		; <限界　＝　キャリーフラグＯＦＦ> 
	goto MS_REJPUL2_CTL5;
MS_REJPUL2_CTL4: 
//	INC	HL			; 次ラインの制御図柄　セット 
	hl+=1;
//	DJNZ	MS_REJPUL2_CTL3		; 有効ライン数終了？．．ＮＯ 
	z_b-=1;
	if(z_b) goto MS_REJPUL2_CTL3;
MS_REJPUL2_CTL5: 
//	POP	BC			; 蹴飛ばし位置データ　復帰 
	pop_(&bc,&z_b,&z_c);
//	POP	HL			; 引込み・蹴飛ばし制御テーブル　復帰 
	pop_(&hl,&z_h,&z_l);
MS_REJPUL2_CTL6: 
//	RR	D			; 引込み・蹴飛ばし位置  セット 
	if(cy){
		if((z_d&0x01))	cy=1;
		else			cy=0;
		z_d=(z_d>>1);
		z_d=(z_d|0x80);
	}else{
		if((z_d&0x01))	cy=1;
		else			cy=0;
		z_d=(z_d>>1);
	}

//	DEB_STOP3(z_d);

//	EXX				; <表レジスタ　→　裏レジスタ> 
	_EXX_
//	POP	BC			; 回胴図柄データ　復帰 
	pop_(&bc,&z_b,&z_c);
//	INC	C			; 次コマの回胴図柄　セット 

	bc+=1;

//	POP	DE			; 有効ライン検索テーブル　復帰 
	pop_(&de,&z_d,&z_e);
//	POP	HL			; 停止図柄データ　復帰 
	pop_(&hl,&z_h,&z_l);
//	EXX				; <裏レジスタ　→　表レジスタ> 
	_EXX_
//	POP	AF			; 制御コマ数　復帰 
	pop_(&af,&z_a,&cy);
//	DEC	A			; 制御コマ数　－１ 
	z_a-=1;
//	JR	NZ,MS_REJPUL2_CTL2	; 制御コマ数終了？．．ＮＯ 
	if(z_a)	goto MS_REJPUL2_CTL2;
//	LD	A,D 
	z_a=z_d;

//	AND	1111 1000B		; 引込み・蹴飛ばしあり？ 
	z_a=(z_a&0xF8);
//	RET	Z			;   ＮＯ 
	if(!z_a)	return;

//	DEC	HL 
	hl-=1;
//	XOR	(HL)			; 停止可能位置データ  セット 
	z_a=(z_a^*hl);

//	LD	HL,_FL_STOP_PNT 
	hl=&_FL_STOP_PNT;
//	AND	(HL) 
	z_a=(z_a&_FL_STOP_PNT);
//	LD	(HL),A			; 停止可能位置フラグ  セット 
	_FL_STOP_PNT=z_a;

//	LD	BC,500H			; 制御コマ数  セット 
//					;;蹴飛ばしコマ数　クリア 
	z_b=5;
	z_c=0;
MS_REJPUL2_CTL7: 
//	RLCA				; 停止可能位置？ 
	if((z_a&0x80)){
		z_a=((z_a<<1)|0x01);
		cy=1;
	}
	else{
		cy=0;
		z_a=(z_a<<1);
		z_a&=0xFE;
	}
//	JR	C,MS_REJPUL2_CTL8	;   ＹＥＳ 
	if(cy)	goto MS_REJPUL2_CTL8;

//	INC	C			; 蹴飛ばしコマ数　＋１ 
	z_c+=1;
	DEB_STOP2(12345);
MS_REJPUL2_CTL8: 
//	DJNZ	MS_REJPUL2_CTL7		; 制御コマ数終了？．．ＮＯ 
	z_b-=1;
	if(z_b)	goto MS_REJPUL2_CTL7;
//	DEC	HL			; // HL = _NB_REJECT 
	hl=&_NB_REJECT;
//	LD	(HL),C			; 蹴飛ばしコマ数　セット 
	*hl=z_c;
//	RET 
// 
}


//;************************************************************************  
//;*	管理番号      : S-0605-001					* 
//;*	機能	      : 第３停止時の蹴飛ばし制御			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_REJ3_CTL					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_REJPUL1_CTL					* 
//;************************************************************************ 
//; 
void MS_REJ3_CTL(void)
{
//	LD	A,(_NB_STOP_ORDER)  
	z_a=_NB_STOP_ORDER;
//	CP	3			; 第３停止時？  
//	RET	NZ			;   ＮＯ  
	if(z_a!=3)	return;

//	LD	HL,TBL_ETC_REJ		; 第３停止時の  
//							;;蹴飛ばし制御テーブル  セット  
//	LD	B,2					; 制御回数  セット  
	z_b=2;
//	CALL	MS_REJPUL1_CTL		; 抽選図柄引込み・蹴飛ばし制御   

	MS_REJPUL1_CTL(_TBL_ETC_REJ);//		; 抽選図柄引込み・蹴飛ばし制御  

//	RET  
}


//;************************************************************************ 
//;*	管理番号      : S-0606-001					* 
//;*	機能	      : 引込み制御					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_PUL_CTL					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_REJPUL1_CTL					* 
//;************************************************************************ 

void MS_PUL_CTL(void)
{
//	LD	HL,TBL_ALL_PUL		; 引込み制御テーブル  セット 
//	LD	B,2					; 制御回数  セット 
	z_b=2;
//	CALL	MS_REJPUL1_CTL		; 抽選図柄引込み・蹴飛ばし制御 

	MS_REJPUL1_CTL(_TBL_ALL_PUL);//		; 抽選図柄引込み・蹴飛ばし制御 

//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0607-001					* 
//;*	機能	      : 第２停止時の蹴飛ばし制御			* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_REJ2_CTL					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_REJPUL1_CTL					* 
//;************************************************************************ 

void MS_REJ2_CTL(void)
{

//	LD	A,(_FL_STOP_LP) 
	z_a=_FL_STOP_LP;
//	AND	1110 0000B 
	z_a&=0xE0;
//	CP	0010 0000B		; 左回胴のみ回転中？ 
//	RET	NZ			;   ＮＯ 
	if((z_a-0x20)!=0)	return;

//	LD	HL,TBL_EXT_REJ		; 第２停止時の 
//							;;蹴飛ばし制御テーブル  セット 
	if(!MACINE){
//	LD	B,1			; 制御回数  セット 
		z_b=1;
	}else{
//	LD	B,2			; 制御回数  セット 
		z_b=2;
	}
//	CALL	MS_REJPUL1_CTL		; 抽選図柄引込み・蹴飛ばし制御 

	MS_REJPUL1_CTL(_TBL_EXT_REJ);//		; 抽選図柄引込み・蹴飛ばし制御 

//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0608-001					* 
//;*	機能	      : 停止位置セット					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_SPPOINT_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :	B = ずらしコマ数（１～５）			* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET,MS_RLDAT_SET				* 
//;************************************************************************ 
//	付け足しの処理  

char TBL_STOP_CTLX[22];

void tbl_stop_ctlx(int zh,int zb)
{
	int lp;

	lp=0;
//	for(lp=0;lp<22;lp++){
		switch(zh){
			case 1:
				de=&TBL_STOP_CTL1[MACINE][zb][lp];
			break;
			case 2:
				de=&TBL_STOP_CTL2[MACINE][zb][lp];
			break;
			case 3:
				de=&TBL_STOP_CTL3[MACINE][zb][lp];
			break;
			case 4:
				de=&TBL_STOP_CTL4[MACINE][zb][lp];
			break;
			case 5:
				de=&TBL_STOP_CTL5[MACINE][zb][lp];
			break;
			case 6:
				de=&TBL_STOP_CTL6[MACINE][zb][lp];
			break;
			case 7:
				de=&TBL_STOP_CTL7[MACINE][zb][lp];
			break;
			case 8:
				de=&TBL_STOP_CTL8[MACINE][zb][lp];
			break;
			case 9:
				de=&TBL_STOP_CTL9[MACINE][zb][lp];
			break;
			case 10:
				de=&TBL_STOP_CTL10[MACINE][zb][lp];
			break;
			case 11:
				de=&TBL_STOP_CTL11[MACINE][zb][lp];
			break;
			case 12:
				de=&TBL_STOP_CTL12[MACINE][zb][lp];
			break;
			case 13:
				de=&TBL_STOP_CTL13[MACINE][zb][lp];
			break;
			case 14:
				de=&TBL_STOP_CTL14[MACINE][zb][lp];
			break;
		}
//	}
}

//; 
//	最優先課題！！！！！！！ 
//	pppppppppppppppppp
char MS_SPPOINT_SET(void)
{
	int lp;
	STOP_SEL	*hlw;

//	LD	HL,(_BF_STOP_CTL) 

	hl=_BF_STOP_CTL;

//	LD	A,H 
//	OR	L			; 停止位置決定用テーブル使用？ 
//	JR	NZ,MS_SPPOINT_SET6	;   ＹＥＳ 

	if(hl)		goto MS_SPPOINT_SET6;

//	LD	A,(_FL_STOP_LP) 
//	AND	1110 0000B 
	z_a=(_FL_STOP_LP&0xE0);
//	CP	11000000B		; 左回胴が第１停止？ 
//	JP	NZ,MS_SPPOINT_SET14	;   ＮＯ 
	if((z_a-0xC0))	goto MS_SPPOINT_SET14;

//	左回胴から止まったときの処理 
// 
//; 停止位置決定用テーブル使用時の停止位置決定 
//; 左回胴が最初に止まります 
//; ［停止位置決定用テーブル選択］ 
// 
//	LD	HL,TBL_STOP_SELECT	; 当選図柄別停止位置決定用テーブル 
//							;;検索テーブル　セット 
	lp=0;
	hlw=&TBL_STOP_SELECT[MACINE][lp];
MS_SPPOINT_SET1:
//	LD	B,(HL)			; 検索する引込み図柄 
//						;;データ１　セット 
	z_b=hlw->serch1;
//	INC	HL 
//	LD	C,(HL)			; 検索する引込み図柄 
//					;;データ２　セット 
	z_c=hlw->serch2;

//	INC	HL 
//	LD	E,(HL) 
//	INC	HL 
//	LD	D,(HL)			; 停止位置決定用テーブル選択抽選用 
//	INC	HL				;;確率テーブル　セット 
//	hlw=&TBL_STOP_SELECT[MACINE][lp];
//	tbl=&hlw.stop;
	de=hlw->stop;
	lp+=1;
	hlw=&TBL_STOP_SELECT[MACINE][lp];

//	LD	A,(_FL_PUL_PIC1)	; 引込み図柄データ１　読み込み 
	z_a=_FL_PUL_PIC1;
//	CP	B			; 検索内容一致？ 
//	JR	NZ,MS_SPPOINT_SET1	;   ＮＯ 
	if((z_a-z_b))	goto MS_SPPOINT_SET1;

//	一致しました！ 
//	LD	A,(_FL_PUL_PIC2)	; 引込み図柄データ２　読み込み 
	z_a=_FL_PUL_PIC2;
//	SUB	C			; 検索内容一致？ 
//	JR	NZ,MS_SPPOINT_SET1	;   ＮＯ 
	z_a-=z_c;
	if(z_a)	goto MS_SPPOINT_SET1;


//	DE=	*tbl=TBL_STOP_SELECT[MACINE][lp];	<<現状 
//	EX	DE,HL			; 停止位置決定用テーブル選択抽選用 
//						;;確率テーブル　決定 
	_EX_DE_HL_

//	HL=	*tbl=TBL_STOP_SELECT[MACINE][lp];	<<現状 
//; ［左回胴時の制御］ 

//	LD	E,(HL) 
//	INC	HL			; 停止位置決定用テーブル初期値 
//	LD	D,(HL)		;;一時保存 
	z_de=hl[0];	//	TBL_STOP_CTLx<の番号保存 

	tbl_stop_ctlx(z_de,0);


//	LD	B,A			; パターン番号初期値　セット 
//					; //A = 0 
	z_a=0;
	z_b=z_a;
///////////////////////////////////////////////////// 
//	Ｒレジスタの内容なんかわかるか！ボケ！！代わりに乱数！ 
//	LD	A,R			; Ｒレジスタ読み込み 
//	OR	1000 0000B 
	z_a=rnd(0xFF);
	z_a=(z_a|0x80);	//＜１２８をたしとく 

MS_SPPOINT_SET2:
//	INC	HL			; テーブル選択抽選確率データ　セット 
	hl=&hl[1];
//	INC	B			; テーブルパターン番号　＋１ 
	z_b++;
//	ADD	A,(HL)			; テーブルパターン当選？ 
	z_ai=z_a;
	z_ai=z_a+hl[0];
	z_a=z_a+hl[0];

//	JR	NC,MS_SPPOINT_SET2	;   ＮＯ 
	if(z_ai>=0xFF)	goto MS_SPPOINT_SET2;

MS_SPPOINT_SET3:
//	LD	H,D			; 停止位置決定用テーブル初期値 
//	LD	L,E			;;一時取り出し 
	hl=de;	//	TBL_STOP_CTLx<の番号保存 

MS_SPPOINT_SET4:
//	LD	A,22			; テーブルパターン移行要求　セット 
//	z_a=22;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	DJNZ	MS_SPPOINT_SET4		; テーブルパターン選択終了？．．ＮＯ 
//	LD	B,(HL)			; 選択指定テーブルパターン番号　セット 

	push_(&de,&z_d,&z_e);
	tbl_stop_ctlx(z_de,z_b-1);
	hl=de;
	pop_(&de,&z_d,&z_e);

	z_b=hl[0];

//	INC	HL 
//		HL=TBL_STOP_CTLX[1];	<<現状ここ 
	hl=&hl[1];

//	PUSH	HL 
	push_(&hl,&z_h,&z_l);

//	LD	A,(_BF_PICTURE)		; 回胴停止受付時図柄番号に 
//							;;応じたデータ要求　セット 
	z_a=_BF_PICTURE;

//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
	hl=&hl[z_a];
//	LD	A,(HL) 
	z_a=hl[0];
//	POP	HL 
	pop_(&hl,&z_h,&z_l);

//	CP	1100 1000B		; 指定テーブルへ移行？ 
//	JR	NC,MS_SPPOINT_SET3	;   ＹＥＳ 
	if(z_a>=0xC8)	goto MS_SPPOINT_SET3;

//	LD	(_BF_STOP_CTL),HL	; 停止位置決定用テーブル　セット 

//	超重要!!!!!!!!!!!!!!!!  
	_BF_STOP_CTL=hl;	//	アドレスの代わりにデータを入れる 

//	LD	BC,500H 
	z_b=5;
	z_c=0;
MS_SPPOINT_SET5:

//	SUB	40 
	if(z_a<40)	cy=1;
	else		cy=0;
	z_a-=40;
//	RR	C			; テーブルによる停止指定位置ビット　セット 
	if(cy){
		if(z_c&0x01)	cy=1;
		else			cy=0;
		z_c=((z_c>>1)|0x80);
	}
	else{
		if(z_c&0x01)	cy=1;
		else			cy=0;
		z_c=(z_c>>1);
	}
//	DJNZ	MS_SPPOINT_SET5		; 停止指定位置ビットセット終了？．．ＮＯ 
	z_b-=1;
	if(z_b)	goto MS_SPPOINT_SET5;

//	LD	A,(_FL_STOP_PNT) 
	z_a=_FL_STOP_PNT;
//	AND	C			; テーブル停止指定位置に停止可能？ 
	z_a&=z_c;

//	JR	NZ,MS_SPPOINT_SET16	;   ＹＥＳ 
	if(z_a)	goto MS_SPPOINT_SET16;

//	JR	MS_SPPOINT_SET15 
	goto MS_SPPOINT_SET15;

// 左回胴第一停止時の 
//; ［中回胴の制御］  
MS_SPPOINT_SET6:

//	LD	A,(_NB_STOP_REEL) 
	z_a=_NB_STOP_REEL;
//	CP	2			; 中回胴停止時？ 
//	JR	NZ,MS_SPPOINT_SET9	;   ＮＯ 
	if(z_a!=2)	goto MS_SPPOINT_SET9;

//	テーブル使用 中回胴制御
//					; // HL = (_BF_STOP_CTL) 
//	LD	A,(_BF_PICTURE)		; 回胴停止受付時図柄番号に 
//							;;応じたデータ要求　セット 
	z_a=_BF_PICTURE;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
	hl+=z_a;
//	LD	A,(HL)			; 停止位置決定用テーブル　セット 
	z_a=*hl;

MS_SPPOINT_SET7:
//	SUB	40			; データ修正 
	if(z_a<40)	cy=1;
	else		cy=0;
	z_a-=40;

	if(!cy)	goto MS_SPPOINT_SET7;
//	JR	NC,MS_SPPOINT_SET7	; 修正終了？．．ＮＯ 
//	ADD	A,40 
	z_a+=40;

//	LD	BC,500H			; コマ数　セット 

	z_b=5;
	z_c=0;
MS_SPPOINT_SET8:
//	SUB	8 
	if(z_a<8)	cy=1;
	else		cy=0;
	z_a-=8;
//	RR	C			; テーブルによる停止指定位置ビット　セット 
	if(cy){
		if(z_c&0x01)	cy=1;
		else			cy=0;
		z_c=((z_c>>1)|0x80);
	}
	else{
		if(z_c&0x01)	cy=1;
		else			cy=0;
		z_c=(z_c>>1);
	}

//	DJNZ	MS_SPPOINT_SET8		; 停止指定位置ビットセット終了？．．ＮＯ 
	z_b-=1;
	if(z_b)	goto MS_SPPOINT_SET8;

//	LD	A,(_FL_STOP_PNT) 
	z_a=_FL_STOP_PNT;
//	AND	C			; テーブル停止指定位置に停止可能？ 
	z_a&=z_c;
//	JR	NZ,MS_SPPOINT_SET16	;   ＹＥＳ 
	if(z_a)	goto MS_SPPOINT_SET16;

//	JR	MS_SPPOINT_SET15 
	goto	MS_SPPOINT_SET15;

// 左回胴第一停止時の 
//; ［右回胴の制御］  
MS_SPPOINT_SET9:
//	LD	E,0000 0100B		; テーブル停止指定位置検索ビット 
//						;;初期値　セット 
	z_e=0x04;
MS_SPPOINT_SET10:
//	LD	BC,4			; 即止め用ずらしｺﾏ数初期値及び停止 
//						;;可能位置検索ビット初期値　セット 
	z_b=0;
	z_c=4;
MS_SPPOINT_SET11:
//	LD	A,B 
	z_a=z_b;
//	CP	5			; ５コマ分検索終了？ 
//	JR	Z,MS_SPPOINT_SET13	;   ＹＥＳ 
	if(z_a==5)	goto MS_SPPOINT_SET13;

//	LD	A,(_BF_PICTURE)		; 回胴停止受付時図柄番号　取り出し 
	z_a=_BF_PICTURE;
//	ADD	A,B			; 停止図柄番号  セット 
	z_a+=z_b;
//	CP	21			; 停止図柄番号  ＞　２０？ 
//	JR	C,MS_SPPOINT_SET12	; 　ＮＯ 
	if(z_a<21)	goto	MS_SPPOINT_SET12;

//	SUB	21			; 停止図柄番号修正（０～２０） 
	z_a-=21;

MS_SPPOINT_SET12:
//	INC	B			; ずらしコマ数　＋１ 
	z_b+=1;
//	SLA	C			; 停止可能位置検索ビット　セット 
	if((z_c&0x80))	cy=1;
	else			cy=0;
	z_c=(z_c<<1);
	z_c&=0xFE;


//	LD	HL,(_BF_STOP_CTL)	; 停止位置決定用テーブル　取り出し 
	hl=_BF_STOP_CTL;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
	//	HL=TBL_STOP_CTLX[1+_BF_PICTURE];	<<いまここ 
	hl=&hl[z_a];
//	LD	A,(HL) 
	z_a=hl[0];

//	AND	E			; テーブル停止指定位置？ 
	z_a&=z_e;
//	JR	Z,MS_SPPOINT_SET11	;   ＮＯ 
	if(!z_a)	goto MS_SPPOINT_SET11;

//	LD	A,(_FL_STOP_PNT) 
	z_a=_FL_STOP_PNT;
//	AND	C			; 停止可能位置？ 
	z_a&=z_c;
//	JR	NZ,MS_SPPOINT_SET20	;   ＹＥＳ 
	if(z_a)	goto MS_SPPOINT_SET20;
MS_SPPOINT_SET13:
//	SRL	E			; テーブル停止指定位置検索ビット　セット 
	if((z_e&0x01)){
		z_e=(z_e>>1);
		cy=1;
		z_e&=0x7F;
	}
	else{
		z_e=(z_e>>1);
		z_e&=0x7F;
		cy=0;
		goto MS_SPPOINT_SET10;
	}
//	JR	NC,MS_SPPOINT_SET10	; 停止指定位置検索終了？．．ＮＯ 

//	JR	MS_SPPOINT_SET18 
	goto MS_SPPOINT_SET18;

//; 即止め時及び最大引込み時の停止位置決定 
/////////////////////////////////////////////////////////////////////
MS_SPPOINT_SET14:

//	LD	A,(_FL_PUL_PIC1) 
	debs4=_FL_PUL_PIC1;
	debs5=_FL_PUL_PIC2;

	z_a=_FL_PUL_PIC1;
//	AND	@_PIC1			; 図柄１群当選？ 
	z_a&=_PIC1;
//	JR	NZ,MS_SPPOINT_SET18	;   ＹＥＳ 
	if(z_a)	goto MS_SPPOINT_SET18;

//	LD	A,(_FL_PUL_PIC2) 
	z_a=_FL_PUL_PIC2;

//	AND	@_PIC2			; 図柄２群当選？ 
	z_a&=_PIC2;
//	JR	NZ,MS_SPPOINT_SET18	;   ＹＥＳ 
	if(z_a)	goto MS_SPPOINT_SET18;

//; ［即止め時の停止位置決定］ 

MS_SPPOINT_SET15:
//	LD	A,(_FL_STOP_PNT)	; 停止可能位置フラグ　セット 
	z_a=_FL_STOP_PNT;

MS_SPPOINT_SET16:
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	LD	B,0			; 即止め用ずらしコマ数 
//					;;初期値　セット 
	z_b=0;
MS_SPPOINT_SET17:
//	INC	B			; ずらしコマ数　＋１ 
	z_b+=1;
//	RRCA				; 停止可能位置？ 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
	}
	else{
		z_a=(z_a>>1);
//	JR	NC,MS_SPPOINT_SET17	;   ＮＯ 
		goto MS_SPPOINT_SET17;
	}

//	JR	MS_SPPOINT_SET20 
	goto MS_SPPOINT_SET20;

//; ［最大引込み時の停止位置決定］ 
MS_SPPOINT_SET18:
//	LD	A,(_FL_STOP_PNT)	; 停止可能位置フラグ　セット 
	z_a=_FL_STOP_PNT;
//	LD	B,6			; 最大引込み用ずらしコマ数初期値  セット 
	z_b=6;

MS_SPPOINT_SET19:
//	DEC	B			; ずらしコマ数　－１ 
	z_b-=1;
//	RLCA				; 停止可能位置？ 
	if((z_a&0x80)){
		z_a=((z_a<<1)|0x01);
		cy=1;
	}
	else{
		z_a=(z_a<<1);
		cy=0;
	}
//	JR	NC,MS_SPPOINT_SET19	;   ＮＯ 
	if(!cy)	goto MS_SPPOINT_SET19;
MS_SPPOINT_SET20:
//	XOR	A			; 回胴駆動状態番号要求　セット 
	z_a=0;
//	CALL	MS_RLDAT_SET		; 回胴情報データセット 
	z_h=MS_RLDAT_SET(z_a);		//; 回胴情報データセット 
								//	z_hl=回胴停止番号(_WK_REEL[z_hl][z_a]) 
	hl=&_WK_REEL[z_h][z_a];

//	PUSH	HL 
	push_(&hl,&z_h,&z_l);
//	LD	A,6			; 図柄番号（停止位置用）要求　セット 
	z_a=6;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	HL=_WK_REEL[z_h][6] 
	hl=&_WK_REEL[z_h][z_a];

//	LD	A,(_BF_PICTURE)		; 回胴停止受付時図柄番号　取り出し 
	z_a=_BF_PICTURE;
//	ADD	A,B			; 停止図柄番号  セット 
	z_a+=z_b;
//	CP	21			; 停止図柄番号  ＞　２０？ 
//	JR	C,MS_SPPOINT_SET21	; 　ＮＯ 
	if(z_a<21)	goto MS_SPPOINT_SET21;
// 
//	SUB	21			; 停止図柄番号修正（０～２０） 
	z_a-=21;

MS_SPPOINT_SET21:
//	LD	(HL),A			; 図柄番号（停止位置用）  セット 
	_WK_REEL[z_h][6]=z_a;

//	POP	HL 
	pop_(&hl,&z_h,&z_l);
//	LD	(HL),3			; 回胴減速開始状態  セット 
	_WK_REEL[z_h][0]=3;	//	HL=_NB_STOP_REEL 
//	RET 

}


//;************************************************************************ 
//;*	管理番号      : S-0609-001					* 
//;*	機能	      : 停止図柄セット					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_STOPPIC_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : B = ずらしコマ数（１～５）			* 
//;*		          : DE'= 有効ライン検索テーブル			* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL,DE'					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET					* 
//;************************************************************************ 
//kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk 
//ちゃんと作れ！ 

//	一カ所でしか使われていません 
void MS_STOPPIC_SET(void)
{
//	char z_a,z_b,z_c,z_d;
//	char z_ab,de_po,de_po2,hl_po,hl_po2;
//	char z_az,z_azz;
//	裏DE=TBL_LINE_SEARCH[_NB_STOP_REEL-1][0] 

//	p_p=0;

//	de_b=&TBL_LINE_SEARCH[_NB_STOP_REEL-1][0];

//	LD	A,B						; ずらしコマ数に応じた回胴図柄デー  
	z_a=z_b;
//	LD	HL,_WK_REEL_PIC1 - 1	;;タ１ＲＡＭアドレス要求　セット  
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット  
//HL=_WK_REEL_PIC1[z_az-1]; 
	hl=&_WK_REEL_PIC1[z_a-1];

//	EX	DE,HL 
	_EX_DE_HL_

//	awk=hl;
//	hl=de;
//	de=awk;

//		DE=_WK_REEL_PIC1[z_a-1]; //	現状 

//	LD	HL,_WK_STOP_PIC1	; 停止図柄データ１ＲＡＭアドレス　セット  

	hl=&_WK_STOP_PIC1[0];

//		HL=_WK_STOP_PIC1[0]  
//	LD	BC,0			; 停止図柄データ（全有効ライン）　クリア   
	z_b=0;
	z_c=0;

//	LD	A,(_NB_PLAY_MEDAL) 
	z_a=_NB_PLAY_MEDAL;

//	ADD	A,A 
	z_a+=z_a;
//	DEC	A			; 有効ライン数  セット 
	z_a-=1;	//	z_a=1|3|5 

//	ループの頂点
MS_STOPPIC_SET1:
//	PUSH	AF 
	push_(&af,&z_a,&z_f);

//	PUSH	HL 
	push_(&hl,&z_h,&z_l);

//		HL=_WK_STOP_PIC1[hl_po] 
//		DE=_WK_REEL_PIC1[z_az-1]; //	現状
//		DE'=TBL_LINE_SEARCH[_NB_STOP_REEL][u_de]
//	EXX				; <表レジスタ　→　裏レジスタ> 

	_EXX_

//		DE=TBL_LINE_SEARCH[_NB_STOP_REEL][de_po]
//		DE'=_WK_REEL_PIC1[z_az-1]; //	現状
//		HL'=_WK_STOP_PIC1[0] 

//	LD	A,(DE)		; 有効ライン対応データ  セット 
	z_a=de[0];
//	INC	DE			; 有効ライン検索テーブル　＋１ 
	de=&de[1];

//	EXX				; <裏レジスタ　→　表レジスタ> 
	_EXX_

//		DE=_WK_REEL_PIC1[z_az-1]; 			//	現状
//		DE'=TBL_LINE_SEARCH[_NB_STOP_REEL-1][de_po]
//		HL=_WK_STOP_PIC1[0] 

//	ADD	A,E 
//	LD	E,A			; 有効ラインに応じた 

	if(z_a==0xFE)	de=&de[-2];
	else			de=&de[z_a];

//	LD	A,(DE)		;;回胴図柄データ１　セット 
	z_a=de[0];

//	AND	(HL)			; （回胴図柄データ１）AND（停止図柄データ１） 
	z_a&=hl[0];
//	LD	(HL),A			; 停止図柄データ１（各有効ライン）　セット 
	hl[0]=z_a;

//	OR	B 

	z_a=(z_a|z_b);

//	LD	B,A			; 停止図柄データ１（全有効ライン）一時保存 
	z_b=z_a;

//	PUSH	DE 
	push_(&de,&z_d,&z_e);

//	LD	A,7 
	z_a=7;

//	ADD	A,E			; 回胴図柄データ２ＲＡＭアドレス 
//	LD	E,A			;;（下位）　セット 
	de=&de[z_a];

//	LD	A,5			; 停止図柄データ２（各有効ライン） 
//					;;ＲＡＭアドレス要求　セット 
	z_a=5;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
//	S_ADDR_SET();//		; ワーク・テーブルのアドレスセット 

	hl=&hl[z_a];


//	LD	A,(DE)			; 有効ラインに応じた 
//					;;回胴図柄データ２　セット 
	z_a=de[0];

//	AND	(HL)			; （回胴図柄データ２）AND（停止図柄データ２） 
	z_a&=hl[0];
//	LD	(HL),A			; 停止図柄データ２（各有効ライン）　セット 
	hl[0]=z_a;

//	OR	C 
	z_a=(z_a|z_c);
//	LD	C,A			; 停止図柄データ２（全有効ライン）一時保存 
	z_c=z_a;
//	POP	DE 
	pop_(&de,&z_d,&z_e);

//	POP	HL			; 次ラインの停止図柄データ１（各有 
	pop_(&hl,&z_h,&z_l);
//	INC	HL			;;効ライン）ＲＡＭアドレス　セット 
//		HL=_WK_STOP_PIC1[hl_po+1] 
	hl=&hl[1];

//	POP	AF 
	pop_(&af,&z_a,&z_f);

//	DEC	A			; 有効ライン数　－１ 
	z_a-=1;
//	JR	NZ,MS_STOPPIC_SET1	; 有効ライン分終了？．．ＮＯ 
	if(z_a)	goto MS_STOPPIC_SET1;


//	LD	L,LOW _WK_ALL_PIC1 
//	hl=&_WK_ALL_PIC1;
//	LD	(HL),B			; 停止図柄データ１（全有効ライン）　セット 
//	hl[0]=z_b;
//	INC	HL			; // HL = _WK_ALL_PIC2 
//	hl=&hl[1];
//	LD	(HL),C			; 停止図柄データ２（全有効ライン）　セット 
//	hl[0]=z_c;
//	RET 
	_WK_ALL_PIC1=z_b;
	_WK_ALL_PIC2=z_c;
}



//;************************************************************************ 
//;*	管理番号      : S-0700-001					* 
//;*	機能	      : ランプ（ＬＥＤ）表示・効果音出力		* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_LPSD_OUT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    :	IS_LED_OUT,IS_LINE_OUT,IS_LAMP_OUT		* 
//;*		      : IS_POWERON_RET					* 
//;************************************************************************ 

void IS_LPSD_OUT(void)
{
	char	wk=0,cy2;
	char z_a,z_b,z_c,z_d;
	short z_hl,z_de;

//	XOR	A 
	z_a=0;
//	OUT	(@OUT3_PORT),A				; 出力ポート３  ＯＦＦ 
//	OUT	(@OUT4_PORT),A				; 出力ポート４  ＯＦＦ 

	OUT3_PORT=z_a;
	OUT4_PORT=z_a;

// 
//; 表示切替え 
// 
//	LD	HL,_FL_LED_CHANGE 
//	LD	A,(HL) 
	z_a=_FL_LED_CHANGE;
//	CP	2 
//	RRA 
	if(z_a<2){
		cy=1;
		z_a=(z_a>>1)|0x80;
	}
	else{
		z_a=z_a>>1;
	}

//	LD	(HL),A					; 表示切替えフラグ  セット 
	_FL_LED_CHANGE=z_a;

// 
//	AND	0111 1111B 
	z_a&=0x7F;
//	LD	L,LOW _PT_OUT4 
//	LD	(HL),A					; ＬＥＤデジットデータ  セット 
	_PT_OUT4=z_a;

//	LD	DE,_NB_PAY_LED 

//	RRCA						; 出力パターン１？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
		goto IS_LPSD_OUT1;
	}
// 
//; 出力パターン１ 
//; 	遊技メダル払出枚数表示ＬＥＤ下位桁 
//; 	入賞ライン表示（有効ラインランプ、バックランプ） 
//							; // DE = _NB_PAY_LED 
//	LD	A,(DE)					; 遊技メダル払出枚数表示ＬＥＤ 
	z_a=_NB_PAY_LED;
//								;;下位桁表示要求  セット 
//	CALL	IS_LED_OUT			; ＬＥＤ表示 
	IS_LED_OUT(z_a);			//; ＬＥＤ表示 
// 
//	CALL	IS_LINE_OUT			; 入賞ライン表示 
	IS_LINE_OUT();				//; 入賞ライン表示 
// 
//	LD	HL,_FL_GAME_STS 
//	BIT	3,(HL)					; 回胴回転始動装置受付許可？ 
//	RET	Z					;   ＮＯ 
	if((_FL_GAME_STS&(0x01<<3))==0)	return;
// 
//	LD	L,LOW _PT_OUT3 
//	SET	7,(HL)					; ドット表示  セット 
	_PT_OUT3=(_PT_OUT3|(0x01<<7));
// 
//	RET 
	return;
// 
IS_LPSD_OUT1:
//	RRCA						; 出力パターン２？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,IS_LPSD_OUT2				;   ＮＯ 
		goto IS_LPSD_OUT2;
	}
// 
//; 出力パターン２ 
//; 	遊技メダル払出枚数表示ＬＥＤ上位桁 
// 
//	LD	A,(DE)					; // DE = _NB_PAY_LED 
	z_a=_NB_PAY_LED;
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA						; 遊技メダル払出枚数表示ＬＥＤ 
//								;;上位桁表示要求  セット 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	CALL	IS_LED_OUT				; ＬＥＤ表示 
	IS_LED_OUT(z_a);//				; ＬＥＤ表示 
// 
//	RET 
// 
	return;
IS_LPSD_OUT2:
//	DEC	DE					; // DE = _NB_CREDIT_LED 
//	RRCA						; 出力パターン３？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,IS_LPSD_OUT3				;   ＮＯ 
		goto IS_LPSD_OUT3;
	}
// 
//; 出力パターン３ 
//; 	遊技メダル貯留枚数表示ＬＥＤ下位桁 
//							; // DE = _NB_CREDIT_LED 
//	LD	A,(DE)					; 遊技メダル貯留枚数表示ＬＥＤ 
//							;;下位桁表示要求  セット 
//	CALL	IS_LED_OUT				; ＬＥＤ表示 
	IS_LED_OUT(_NB_CREDIT_LED);//				; ＬＥＤ表示 
// 
//	RET 
	return;

IS_LPSD_OUT3:
//	RRCA						; 出力パターン４？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,IS_LPSD_OUT4				;   ＮＯ 
		goto IS_LPSD_OUT4;
	}
// 
//; 出力パターン４ 
//; 	遊技メダル貯留枚数表示ＬＥＤ上位桁 
// 
//	LD	A,(DE)					; // DE = _NB_CREDIT_LED 
	z_a=_NB_CREDIT_LED;
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA						; 遊技メダル貯留枚数表示ＬＥＤ 
//							;;上位桁表示要求  セット 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	CALL	IS_LED_OUT				; ＬＥＤ表示 
	IS_LED_OUT(z_a);//				; ＬＥＤ表示 
// 
//	RET 
// 
	return;
IS_LPSD_OUT4:
//	LD	E,LOW _NB_COUNT_LED1			; // D = HIGH @RAM 
//	RRCA						; 出力パターン５？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,IS_LPSD_OUT5				;   ＮＯ 
		goto IS_LPSD_OUT5;
	}
//; 出力パターン５ 
//; 	回数表示ＬＥＤ１下位桁 
//; 	上部ランプ 
// 
//	LD	A,(DE)					; 回数表示ＬＥＤ１ 
//								;;下位桁表示要求  セット 
	z_a=_NB_COUNT_LED1;
//	CALL	IS_LED_OUT			; ＬＥＤ表示 
	IS_LED_OUT(z_a);				//; ＬＥＤ表示 

//	LD	L,LOW _WK_FLASH_LP			; 上部ランプ制御データＲＡＭ 
//									;;アドレス下位　セット 
//	LD	BC,LOW _PT_OUT6				; 出力ポート６データ保存ビット及び 
//									;;ＲＡＭアドレス下位　セット 
//	CALL	IS_LAMP_OUT				; 各種ランプ表示 
//	IS_LAMP_OUT(_WK_FLASH_LP ,&_PT_OUT6);	//	; 各種ランプ表示 
	FLASH_LAMP_OUT();

// 
//	RET 
	return;
// 
IS_LPSD_OUT5:
//	LD	E,LOW _NB_COUNT_LED1			; // D = HIGH @RAM 
//	RRCA						; 出力パターン６？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,IS_LPSD_OUT6				;   ＮＯ 
		goto IS_LPSD_OUT6;
	}

//; 出力パターン６ 
//; 	回数表示ＬＥＤ１上位桁 
//; 	効果ランプ 
// 
//	LD	A,(DE)					; // DE = _NB_COUNT_LED1 
	z_a=_NB_COUNT_LED1;
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA						; 回数表示ＬＥＤ１ 
//								;;上位桁表示要求  セット 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);

//	CALL	IS_LED_OUT				; ＬＥＤ表示 
	IS_LED_OUT(z_a);//				; ＬＥＤ表示 

//	LD	L,LOW _WK_EFFECT_LP			; 効果ランプ制御データＲＡＭ 
//							;;アドレス下位　セット 
//	LD	BC,0001 1111B*100H OR LOW _PT_OUT5	; 出力ポート５データ保存ビット及び 
//							;;ＲＡＭアドレス下位　セット 
//	CALL	IS_LAMP_OUT				; 各種ランプ表示 
//	IS_LAMP_OUT(_WK_EFFECT_LP ,&_PT_OUT5);//				; 各種ランプ表示 
	EFFECT_LAMP_OUT();

// 
//	RET 
	return;
// 
IS_LPSD_OUT6:
//	LD	E,LOW _NB_COUNT_LED1			; // D = HIGH @RAM 
//	INC	DE					; // DE = _NB_COUNT_LED2 
//	RRCA						; 出力パターン７？  
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,IS_LPSD_OUT7				;   ＮＯ 
		goto IS_LPSD_OUT7;
	}
// 
//; 出力パターン７ 
//; 	回数表示ＬＥＤ２ 
//; 	バックランプ 
//							; // DE = _NB_COUNT_LED2 
//	LD	A,(DE)					; 回数表示ＬＥＤ２ 
//							;;表示要求　セット 
	z_a=_NB_COUNT_LED2;
//	CALL	IS_LED_OUT				; ＬＥＤ表示 
	IS_LED_OUT(z_a);//				; ＬＥＤ表示 

//	LD	L,LOW _WK_BACK_LP		; バックランプ制御データＲＡＭ 
//								;;アドレス下位　セット 
//	LD	BC,LOW _PT_OUT8			; 出力ポート８データ保存ビット及び 
//								;;ＲＡＭアドレス下位　セット 
//	CALL	IS_LAMP_OUT			; 各種ランプ表示 
//	IS_LAMP_OUT(_WK_BACK_LP ,&_PT_OUT8);//			; 各種ランプ表示 
	BACK_LAMP_OUT();

//	RET 
	return;
// 
IS_LPSD_OUT7:
//; 出力パターン８ 
//	INC	DE					; // DE = _NB_COUNT_LED2 
//	CALL	IS_POWERON_RET	; 連続音・上部ランプ・効果ランプ 
	IS_POWERON_RET();//		; 連続音・上部ランプ・効果ランプ 
//							;;電断復帰処理 
//	RET 
}

//;********************************************************************** 
//;*	管理番号      : S-0701-001										* 
//;*	機能	      : ＬＥＤ表示										* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_LED_OUT										* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : A = ＬＥＤ表示データ							* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :													* 
//;*	保護ﾚｼﾞｽﾀ     :													* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,HL											* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET										* 
//;********************************************************************** 

void IS_LED_OUT(int led)
{
//	未
//	AND	0FH 
//	led&=0x0F; 
//	LD	HL,TBL_SEG_DATA 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット   
//	S_ADDR_SET();//		; ワーク・テーブルのアドレスセット   
//	LD	A,(HL)			; ＬＥＤセグメントデータの取り出し   
//	LD	(_PT_OUT3),A		; ＬＥＤセグメントデータ　セット 
//	_PT_OUT3=TBL_SEG_DATA[led];	//; ＬＥＤセグメントデータ　セット 
	_PT_OUT3=led;	//	そのまま出るように出力を変える 
//	RET 
}

//;************************************************************************ 
//;*	管理番号      : S-0702-001					* 
//;*	機能	      : 入賞ライン表示					* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_LINE_OUT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 

void IS_LINE_OUT(void)
{
	char z_a,z_b,z_c;

//	LD	HL,_TM1_WIN_LP 
//	LD	A,(HL) 
	z_a=_TM1_WIN_LP;
//	AND	A			; 点灯／消灯　切替え？ 
//	RET	NZ			; 　ＮＯ 
	if(z_a)	return;

//	LD	A,(_WK_WIN_LP) 
	z_a=_WK_WIN_LP;
//	AND	A			; 入賞あり？ 
//	RET	Z			; 　ＮＯ 
	if(!z_a)	return;

//	LD	(HL),@TM_LP105		; 入賞ライン点滅時間　セット 
	_TM1_WIN_LP=TM_LP105;

//	LD	L,LOW _PT_OUT5 
//	XOR	(HL)			; 点灯／消灯　切替え 
	z_a^=_PT_OUT5;
//	LD	(HL),A			; 有効ラインランプ 
//						;;点滅表示　セット 
	_PT_OUT5=z_a;

//	LD	A,(_WK_BACK_LP) 
	z_a=_WK_BACK_LP.lamp;
//	AND	A			; バックランプ表示要求あり？ 
//	RET	NZ			;   ＹＥＳ 
	if(z_a)	return;

//	LD	BC,(_WK_WINBACK_LP) 
	z_b=_WK_WINBACK_LP[1];
	z_c=_WK_WINBACK_LP[0];
//	LD	A,C 
	z_a=z_c;
//	LD	L,LOW _PT_OUT7 
//	XOR	(HL)			; 点灯／消灯　切替え 
	z_a^=_PT_OUT7;
//	LD	(HL),A			; バックランプ９  
//						;;点滅表示　セット 
	_PT_OUT7=z_a;

//	LD	A,B 
	z_a=z_b;
//	INC	HL			; // HL = _PT_OUT8 
//	XOR	(HL)			; 点灯／消灯　切替え 
	z_a^=_PT_OUT8;
//	LD	(HL),A			; バックランプ１～８  
//					;;点滅表示　セット 
	_PT_OUT8=z_a;
//	RET 
}


//;************************************************************************ 
//;*	管理番号      : S-0703-001					* 
//;*	機能	      : 各種ランプ表示					* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_LAMP_OUT					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : L = 各種ランプ制御データＲＡＭアドレス下位	* 
//;*		      :	B = 出力ポートデータ保存ビット			* 
//;*		      :	C = 出力ポートデータＲＡＭアドレス下位		* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :	BC						* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,DE,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : 						* 
//;************************************************************************ 
//; 
///////////////////////////////////////////////////////////////////// 
//	大幅に変更します 
///////////////////////////////////////////////////////////////////// 
//	一から起こす部分 
void BACK_LAMP_OUT(void)
{
#if 0
//	IS_LAMP_OUT(_WK_BACK_LP ,&_PT_OUT8);	//; 各種ランプ表示  
	_WK_BACK_LP.lamp=TBL_LPSD_REQ[MACINE][data-1][2];
	_WK_BACK_LP.time=1;
	_WK_BACK_LP.rpt=0;
	_WK_BACK_LP.point=0;
	_WK_BACK_LP.light=0;
#endif
	char	dataL,dataR;
//	data=(TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point]; 

	if(_WK_BACK_LP.lamp){	//	０の時は表示なし 
		_WK_BACK_LP.time--;
		if(!_WK_BACK_LP.time){	//	表示時間終了？ 
			if(!MACINE){
			dataL=(TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point];
			dataR=(TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point+1];
			}else{
			dataL=(B_TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point];
			dataR=(B_TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point+1];
			}
			if(dataL==BLP_END){	//	全表示終了 
				_WK_BACK_LP.lamp=0;
				_WK_BACK_LP.time=0;
				_WK_BACK_LP.rpt=0;
				_WK_BACK_LP.point=0;
				_WK_BACK_LP.light=0;
				_PT_OUT8=0;
			}else{
#define LP_COUNT	(0xFC)		//; リピート回数  
#define LP_REPEAT	(0xFD)		//; リピート（回数制限付繰り返し）  
#define LP_LOOP		(0xFE)		//; 繰り返し  
#define BLP_END		(0xFF)		//; バックランプ表示終了（全点灯）  
#define LP_END		(0x00)		//; 上部ランプ・効果ランプ表示終了（全消灯）  
#define BLP9_OFF	(0x40)		//; バックランプデータ使用時バックランプ９消灯データ  
#define BLP9_ON		(0xC0)		//; バックランプデータ使用時バックランプ９点灯データ  
				if(dataL==LP_COUNT){	//	ループ回数のセット 
					_WK_BACK_LP.rpt=dataR;
					_WK_BACK_LP.point+=2;
				}
				if(dataL==LP_REPEAT){	//	回数制限付きループ 
					_WK_BACK_LP.rpt--;
					if(!_WK_BACK_LP.rpt){	//	ループ終了 
						_WK_BACK_LP.point+=2;
					}
					else{
						_WK_BACK_LP.point=(_WK_BACK_LP.point+1)-dataR;
					}
				}
				if(dataL==LP_LOOP){		//	無限ループ 
					if(dataR){	//	戻り値有り 
						_WK_BACK_LP.point=(_WK_BACK_LP.point+1)-dataR;
					}
					else{	//	先頭へ戻る 
						_WK_BACK_LP.point=0;
					}
				}
				if(dataL==BLP_END){		//	結局終わりなのです 
					_WK_BACK_LP.lamp=0;
					_WK_BACK_LP.time=0;
					_WK_BACK_LP.rpt=0;
					_WK_BACK_LP.point=0;
					_WK_BACK_LP.light=0;
					_PT_OUT8=0;
				}
				else{
					if(!MACINE){
					dataL=(TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point];
					dataR=(TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point+1];
					}
					else{
					dataL=(B_TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point];
					dataR=(B_TBL_BACK_DATA[_WK_BACK_LP.lamp])[_WK_BACK_LP.point+1];
					}
					_WK_BACK_LP.time=dataL&0x3F;
					_WK_BACK_LP.light=dataR;
					if((dataL&0x80))	_WK_BACK_LP.light=(_WK_BACK_LP.light|0x0100);
					else				_WK_BACK_LP.light&=0xFF;
					_PT_OUT8=_WK_BACK_LP.light;
					_WK_BACK_LP.point+=2;
				}
			}
		}
	}
}

void EFFECT_LAMP_OUT(void)
{
#if 0
//	IS_LAMP_OUT(_WK_EFFECT_LP ,&_PT_OUT5);	//; 各種ランプ表示  
	_WK_EFFECT_LP.lamp=TBL_LPSD_REQ[MACINE][data-1][1];
	_WK_EFFECT_LP.time=1;
	_WK_EFFECT_LP.rpt=0;
	_WK_EFFECT_LP.point=0;
	_WK_EFFECT_LP.light=0;
#endif
	char	dataL,dataR;
//	data=(TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point]; 

	if(_WK_EFFECT_LP.lamp){	//	０の時は表示なし 
		_WK_EFFECT_LP.time--;
		if(!_WK_EFFECT_LP.time){	//	表示時間終了？ 
			if(!MACINE){
			dataL=(TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point];
			dataR=(TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point+1];
			}else{
			dataL=(B_TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point];
			dataR=(B_TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point+1];
			}
			if(dataL==LP_END){	//	全表示終了 
				_WK_EFFECT_LP.lamp=0;
				_WK_EFFECT_LP.time=0;
				_WK_EFFECT_LP.rpt=0;
				_WK_EFFECT_LP.point=0;
				_WK_EFFECT_LP.light=0;
				_PT_OUT5&=0x1F;
			}else{
				if(dataL==LP_COUNT){	//	ループ回数のセット 
					_WK_EFFECT_LP.rpt=dataR;
					_WK_EFFECT_LP.point+=2;
				}
				if(dataL==LP_REPEAT){	//	回数制限付きループ 
					_WK_EFFECT_LP.rpt--;
					if(!_WK_EFFECT_LP.rpt){	//	ループ終了 
						_WK_EFFECT_LP.point+=2;
					}
					else{
						_WK_EFFECT_LP.point=(_WK_EFFECT_LP.point+1)-dataR;
					}
				}
				if(dataL==LP_LOOP){		//	無限ループ 
					if(dataR){	//	戻り値有り 
						_WK_EFFECT_LP.point=(_WK_EFFECT_LP.point+1)-dataR;
					}
					else{	//	先頭へ戻る 
						_WK_EFFECT_LP.point=0;
					}
				}
				if(dataL==LP_END){		//	結局終わりなのです 
					_WK_EFFECT_LP.lamp=0;
					_WK_EFFECT_LP.time=0;
					_WK_EFFECT_LP.rpt=0;
					_WK_EFFECT_LP.point=0;
					_WK_EFFECT_LP.light=0;
					_PT_OUT5&=0x1F;
				}
				else{
					if(!MACINE){
					dataL=(TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point];
					dataR=(TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point+1];
					}else{
					dataL=(B_TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point];
					dataR=(B_TBL_EFFECT_DATA[_WK_EFFECT_LP.lamp])[_WK_EFFECT_LP.point+1];
					}
					_WK_EFFECT_LP.time=dataL;
					_WK_EFFECT_LP.light=dataR;
					_WK_EFFECT_LP.light&=0xFF;
					_WK_EFFECT_LP.point+=2;
				}
			}
		}
		_PT_OUT5=(_PT_OUT5|_WK_EFFECT_LP.light);
	}
}

void FLASH_LAMP_OUT(void)
{
#if 0
//	IS_LAMP_OUT(_WK_FLASH_LP ,&_PT_OUT6);	//; 各種ランプ表示  
	_WK_FLASH_LP.lamp=TBL_LPSD_REQ[MACINE][data-1][1];
	_WK_FLASH_LP.time=1;
	_WK_FLASH_LP.rpt=0;
	_WK_FLASH_LP.point=0;
	_WK_FLASH_LP.light=0;
#endif
	char	dataL,dataR;
//	data=(TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point]; 

	if(_WK_FLASH_LP.lamp){	//	０の時は表示なし 
		_WK_FLASH_LP.time--;
		if(!_WK_FLASH_LP.time){	//	表示時間終了？ 
			if(!MACINE){
			dataL=(TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point];
			dataR=(TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point+1];
			}else{
			dataL=(B_TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point];
			dataR=(B_TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point+1];
			}
			if(dataL==LP_END){	//	全表示終了 
				_WK_FLASH_LP.lamp=0;
				_WK_FLASH_LP.time=0;
				_WK_FLASH_LP.rpt=0;
				_WK_FLASH_LP.point=0;
				_WK_FLASH_LP.light=0;
				_PT_OUT6=0;
			}else{
				if(dataL==LP_COUNT){	//	ループ回数のセット 
					_WK_FLASH_LP.rpt=dataR;
					_WK_FLASH_LP.point+=2;
				}
				if(dataL==LP_REPEAT){	//	回数制限付きループ 
					_WK_FLASH_LP.rpt--;
					if(!_WK_FLASH_LP.rpt){	//	ループ終了 
						_WK_FLASH_LP.point+=2;
					}
					else{
						_WK_FLASH_LP.point=(_WK_FLASH_LP.point+1)-dataR;
					}
				}
				if(dataL==LP_LOOP){		//	無限ループ 
					if(dataR){	//	戻り値有り 
						_WK_FLASH_LP.point=(_WK_FLASH_LP.point+1)-dataR;
					}
					else{	//	先頭へ戻る 
						_WK_FLASH_LP.point=0;
					}
				}
				if(dataL==LP_END){		//	結局終わりなのです 
					_WK_FLASH_LP.lamp=0;
					_WK_FLASH_LP.time=0;
					_WK_FLASH_LP.rpt=0;
					_WK_FLASH_LP.point=0;
					_WK_FLASH_LP.light=0;
					_PT_OUT6=0;
				}
				else{
					if(!MACINE){
					dataL=(TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point];
					dataR=(TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point+1];
					}else{
					dataL=(B_TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point];
					dataR=(B_TBL_FLASH_DATA[_WK_FLASH_LP.lamp])[_WK_FLASH_LP.point+1];
					}
					_WK_FLASH_LP.time=dataL;
					_WK_FLASH_LP.light=dataR;
					_WK_FLASH_LP.point+=2;
					_PT_OUT6=_WK_FLASH_LP.light;
				}
			}
		}
	}
}


#if 0
void IS_LAMP_OUT(int type)
{
	LAMP_DATA	*data;
	char		*out;

//	LD	H,HIGH @RAM 
//	LD	A,(HL) 
//	AND	A			; 表示要求あり？ 
//	RET	Z			;   ＮＯ 
	if(data->lamp==0)	return;
// 
//	INC	HL			; // HL = _WK_????_LP + 1 
//	DEC	(HL)			; 表示時間終了？ 
//	RET	NZ			;   ＮＯ 
	data->time--;
	if(data->time){
// 
//	INC	HL			; // HL = _WK_????_LP + 2 
//	LD	E,(HL) 
//	INC	HL			; // HL = _WK_????_LP + 3 
//	LD	D,(HL)			; 表示データアドレス  セット 
// 
//IS_LAMP_OUT1: 
//	LD	A,(DE) 
//	AND	A			; 上部ﾗﾝﾌﾟ又は効果ﾗﾝﾌﾟの表示終了？ 
//					; A = @LP_END ? 
//	JR	NZ,IS_LAMP_OUT2		;   ＮＯ 
	if(!(*data->adrs))
// 
//; 上部ランプ・効果ランプ表示終了（全消灯） 
// 
//	DEC	HL 
//	DEC	HL 
//	DEC	HL			; // HL = _WK_???_?? + 0 
//	LD	(HL),A			; 表示要求  クリア 
	data->lamp=0;


//	JR	IS_LAMP_OUT9 
// 
//IS_LAMP_OUT2: 
//	INC	A			; バックランプの表示終了処理？ 
//	JR	NZ,IS_LAMP_OUT3		;   ＮＯ 
// 
//; バックランプ表示終了（全点灯） 
// 
//	LD	(_WK_BACK_LP),A		; 表示要求  クリア 
//	LD	L,LOW _PT_OUT7 
//	SET	7,(HL)			; バックランプ９点灯　セット 
//	CPL				; バックランプ１～８点灯　セット 
//					; // A = 11111111B 
//	JR	IS_LAMP_OUT9 
// 
//IS_LAMP_OUT3: 
//	INC	A			; 表示繰り返し？ 
//	JR	NZ,IS_LAMP_OUT5		;   ＮＯ 
// 
//; 表示繰り返し・リピート 
// 
//IS_LAMP_OUT4: 
//	EX	DE,HL 
//	INC	HL 
	data->adrs++;
//	LD	A,(HL) 
//	INC	HL 
//	LD	H,(HL) 
//	LD	L,A			; 戻り実行アドレス  取り出し 
//	EX	DE,HL 
//	JR	IS_LAMP_OUT1 
// 
//IS_LAMP_OUT5: 
//	INC	A			; 表示リピート？ 
//	JR	NZ,IS_LAMP_OUT6		;   ＮＯ 
// 
//; リピート回数減算 
// 
//	INC	HL			; // HL = _WK_???_?? + 4 
//	DEC	(HL)			; リピート回数　－１ 
//	DEC	HL			; // HL = _WK_???_?? + 3 
//	JR	NZ,IS_LAMP_OUT4		; リピート終了？．．ＮＯ 
// 
//	INC	DE 
//	INC	DE 
//	INC	DE			; 次の表示データアドレス　セット 
//	JR	IS_LAMP_OUT1 


// 
//IS_LAMP_OUT6: 
//	INC	A			; 表示データ？ 
//	JR	NZ,IS_LAMP_OUT7		;   ＹＥＳ 
// 
//; リピート回数　セット 
// 
//	INC	HL			; // HL = _WK_???_?? + 4 
//	INC	DE 
//	LD	A,(DE) 
//	LD	(HL),A			; リピート回数　セット 
//	INC	DE 
//	DEC	HL			; // HL = _WK_???_?? + 3 
// 
//; 表示データ　セット 
// 
//IS_LAMP_OUT7: 
//	LD	A,(DE) 
//	PUSH	AF			; 表示データフラグ待避 
//	AND	00111111B		; 表示時間データ　セット 
//	INC	DE 
//	INC	DE 
//						; // HL = _WK_???_?? + 3 
//	LD	(HL),D			; 実行アドレス（上位）　セット 
//	DEC	HL				; // HL = _WK_???_?? + 2 
//	LD	(HL),E			; 実行アドレス（下位）　セット 
//	DEC	HL				; // HL = _WK_???_?? + 1 
//	LD	(HL),A			; 表示時間データ  セット 
// 
//	POP	AF			; 表示データフラグ復帰 
//	AND	11000000B		; バックランプの表示処理？ 
//	JR	Z,IS_LAMP_OUT8		;   ＮＯ 
// 
//	AND	10000000B		; バックランプ９データ取り出し 
//	LD	L,LOW _PT_OUT7 
//	RES	7,(HL) 
//	OR	(HL)			; 表示データ　セット 
//	LD	(HL),A			; 出力ポートデータ　セット 
// 
//IS_LAMP_OUT8: 
//	DEC	DE 
//	LD	A,(DE)			; 出力データ取り出し 
// 
//; 表示出力　セット 
// 
//IS_LAMP_OUT9: 

//	LD	E,A 
// 
//	LD	L,C			; // H = HIGH @RAM 
//	LD	A,(HL) 
//	AND	B 
//	OR	E			; 表示データ　セット 
//	LD	(HL),A			; 出力ポートデータ　セット 
// 
//	RET 
	}	//	if end 
}
#endif

//;************************************************************************ 
//;*	管理番号      : S-0704-001					* 
//;*	機能	      : 連続音・上部ランプ・効果ランプ電断復帰処理	* 
//;*	ﾓｼﾞｭｰﾙ名      : IS_POWERON_RET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : SS_LPSD_SET					* 
//;************************************************************************ 

void IS_POWERON_RET(void)
{
	char z_a,z_b,z_c,z_d,z_e;

	if(!MACINE){
//	LD	HL,_FL_GAME_STS 
//	BIT	1,(HL)			; 連続音復帰要求あり？ 
//	RET	Z			;   ＮＯ 
	if((_FL_GAME_STS&(0x01<<1))==0)	return;

//	RES	1,(HL)			; 連続音復帰要求フラグ　クリア 
	_FL_GAME_STS&=((0x01<<1)^0xFF);

//	LD	B,@SET_ALARM		; 遊技メダル払出エラー時の 
//							;;出力要求　セット 
	z_b=SET_ALARM;
//	LD	A,(_WK_FLASH_LP) 
	z_a=_WK_FLASH_LP.lamp;
//	CP	@FLP_ALARM		; 上部ランプ(ﾊﾟﾀｰﾝ1)出力中？ 
//	JR	Z,IS_POWERON_RET1	;   ＹＥＳ 
	if(z_a==FLP_ALARM)	goto IS_POWERON_RET1K;

//	LD	B,@SET_BB		; 役物連続作動増加装置作動時の 
//					;;出力要求　セット 
	z_b=SET_BB;
//	CP	@FLP_BB			; 上部ランプ(ﾊﾟﾀｰﾝ8)出力中？ 
//	JR	Z,IS_POWERON_RET1	;   ＹＥＳ 
	if((z_a-FLP_BB)==0)	goto IS_POWERON_RET1K;
//	LD	B,@SET_RB		; 役物連続作動装置作動時の 
//						;;出力要求　セット 
	z_b=SET_RB;
//	CP	@FLP_RB			; 上部ランプ(ﾊﾟﾀｰﾝ6)出力中？ 
//	RET	NZ			;   ＮＯ 
	if(z_a!=FLP_RB)	return;

IS_POWERON_RET1K: 
//	LD	A,B 
	z_a=z_b;
//	CALL	SS_LPSD_SET		; 各種ランプ・効果音データセット２   
	SS_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット２ 
//	RET 
	}
	else{	//	びんびん 

//	LD	HL,_FL_GAME_STS 
//	BIT	1,(HL)			; 連続音復帰要求あり？ 
//	RET	Z			;   ＮＯ 
	if((_FL_GAME_STS&(0x01<<1))==0)	return;

//	RES	1,(HL)			; 連続音復帰要求フラグ　クリア 
	_FL_GAME_STS&=((0x01<<1)^0xFF);

//	LD	A,(_WK_FLASH_LP)	; 電断時の上部ランプ表示　セット 
	z_a=_WK_FLASH_LP.lamp;
//	LD	DE,@POWON_LP		; 電断復帰時の出力要求番号　セット 
//	LD	B,@POWON_CT		; 電断復帰時の出力要求番号検索数　セット 
	z_d=0x01;
	z_e=0x00;
	z_b=POWON_CT;
IS_POWERON_RET1: 
//	INC	D			; 復帰用出力要求番号　セット 
	z_d+=1;
//	INC	E			; 上部ランプ出力要求番号　セット 
	z_e+=1;

//	DEC	B			; 上部ランプ表示なし？ 
	z_b-=1;
//	RET	Z			;   ＹＥＳ 
	if(!z_b)	return;

//	CP	E			; 上部ランプパターン出力中？ 
//	JR	NZ,IS_POWERON_RET1	;   ＮＯ 
	if((z_a-z_e)!=0)	goto IS_POWERON_RET1;

//	LD	A,D			; 復帰する出力要求　セット 
	z_a=z_d;
//	CALL	SS_LPSD_SET		; 各種ランプ・効果音データセット２ 
	SS_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット２ 

//	RET 
	}
}

//;********************************************************************** 
//;*	管理番号      : S-0705-001										* 
//;*	機能	      : 停止ボタンＬＥＤ表示							* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_STOP_LED										* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : B = 停止ボタンＬＥＤ点灯ビットデータ			* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :													* 
//;*	保護ﾚｼﾞｽﾀ     :	B												* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,DE											* 
//;*	使用ﾓｼﾞｭｰﾙ    : 												* 
//;********************************************************************** 

void MS_STOP_LED(char	data)
{
	char z_a,z_b;
	z_b=data;

//	LD	DE,_PT_OUT7 
//	LD	A,(DE) 
//	AND	0011 1111B 
	z_a=_PT_OUT7&0x3F;
//	CP	B			; 停止ボタンＬＥＤ表示切り替え？ 
//	RET	Z			;   ＮＯ 
	if((z_a-z_b)==0)	return;
	DI				//; 割り込み禁止 

//	LD	A,(DE) 
	z_a=_PT_OUT7;
//	AND	1100 0000B 
	z_a&=0xC0;
//	OR	B 
	z_a=(z_a|z_b);
//	LD	(DE),A			; 停止ボタンＬＥＤ表示 
	_PT_OUT7=z_a;

	EI				//; 割り込み許可 
//	RET 
}

//;********************************************************************** 
//;*	管理番号      : S-0706-001										* 
//;*	機能	      : 遊技回数表示									* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_BNSCT_DSP									* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :													* 
//;*	保護ﾚｼﾞｽﾀ     :													* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,BC,HL											* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET										* 
//;********************************************************************** 

void MS_BNSCT_DSP(void)
{
	char z_a,z_b,z_c;

	if(!MACINE){	//かっぱ 
//	LD	BC,(_CT_BIG_PLAY)	; ＢＢ作動時のＲＢ入賞回数  セット 
		z_b=_CT_BIG_WIN;
		z_c=_CT_BIG_PLAY;
//	LD	A,(_FL_ACTION)		; ＢＢ作動時の一般遊技回数　セット 
		z_a=_FL_ACTION;
//	CP	@_BB				; ＢＢ作動時の一般遊技時？ 
//	JR	Z,MS_BNSCT_DSP1		;   ＹＥＳ 
		if(!(z_a-_BB))	goto MS_BNSCT_DSP1;
//	LD	HL,_CT_BONUS_WIN 
//	LD	C,(HL)			; ＲＢ作動時の役物入賞回数  セット 
		z_c=_CT_BONUS_WIN;
//	CP	@_BB OR @_RB		; ＢＢ作動時のＲＢ作動時？ 
//	JR	Z,MS_BNSCT_DSP1		; 　ＹＥＳ 
		if((z_a==(_BB|_RB)))	goto MS_BNSCT_DSP1;
//	AND	@_RB			; ＲＢ作動時？ 
		z_a&=_RB;
//	RET	Z			;   ＮＯ 
		if(z_a==0)	return;
//	LD	B,0EH			; ”ｂ.”表示要求　セット 
		z_b=0x0E;
	}else{	//	びんびん 
//	CALL	MS_BNS_CHK		; ボーナスゲーム？ 
//	RET	Z			;   ＮＯ 
	if(MS_BNS_CHK())	return;

//	LD	BC,(_CT_BIG_PLAY)	; ＢＢ作動時の遊技回数及びＢＢ 
//							;;作動時のＲＢ入賞回数  セット 
	z_b=_CT_BIG_WIN;
	z_c=_CT_BIG_PLAY;

//	RRCA 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else			z_a=(z_a>>1);
//	RRCA				; ＢＢ作動時の一般遊技？ 
	if((z_a&0x01))	z_a=((z_a>>1)|0x80);
	else{
		z_a=(z_a>>1);
//	JR	NC,MS_BNSCT_DSP1	; 　ＹＥＳ 
		goto MS_BNSCT_DSP1;
	}
// 
//	LD	HL,_CT_BONUS_WIN 
//	LD	C,(HL)			; ＲＢ作動時の役物入賞回数  セット 
	z_c=_CT_BONUS_WIN;
//	RRCA				; ＢＢ作動時？ 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
//	JR	C,MS_BNSCT_DSP1		; 　ＹＥＳ 
		goto MS_BNSCT_DSP1;
	}else			z_a=(z_a>>1);
//	LD	B,0EH			; ”ｂ.”表示要求　セット 
	z_b=0x0E;
	}
MS_BNSCT_DSP1:
//	LD	A,C 
	z_a=z_c;
//	LD	HL,TBL_BONUS_DSP - 1	; 遊技回数表示テーブル要求　セット 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 

//	z_c=TBL_BONUS_DSP[z_a-1];
	z_c=z_a;

//	LD	C,(HL) 
//	LD	(_NB_COUNT_LED1),BC	; 回数表示ＬＥＤ１、２表示　セット 
	_NB_COUNT_LED1=z_c;
	_NB_COUNT_LED2=z_b;
//	RET 
}


//;************************************************************************ 
//;*	管理番号      : S-0707-001					* 
//;*	機能	      : 設定値表示					* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RANK_DSP					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    :							* 
//;*	保護ﾚｼﾞｽﾀ     :							* 
//;*	破壊ﾚｼﾞｽﾀ     :	A,B,HL						* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_BNS_CHK,S_BLOCKER_OFF,S_WATCH_CLEAR		* 
//;*		      : S_BLOCKER_ON					* 
//;************************************************************************ 

void MS_RANK_DSP(void)
{
	char z_a,z_b;

//	CALL	MS_BNS_CHK		; ボーナスゲームチェック 
//	RET	NZ			; ボーナスゲーム？．．ＹＥＳ 
	if(!MS_BNS_CHK())	return;

//	LD	HL,_PT_IN0_UP 
//	BIT	6,(HL)			; 設定用キースイッチＯＮ？ 
//	RET	Z			; 　ＮＯ 
	if((_PT_IN0_UP&(0x01<<6))==0)	return;
// 
//	RST	S_BLOCKER_OFF		; 遊技メダルブロッカーＯＦＦ<返却状態> 
	S_BLOCKER_OFF();//		; 遊技メダルブロッカーＯＦＦ<返却状態> 

//	LD	L,LOW _NB_PAY_LED 
//	LD	B,(HL)			; 遊技メダル払出し枚数表示　保存 
	z_b=_NB_PAY_LED;
//	LD	A,(_NB_RANK) 
	z_a=_NB_RANK;
//	OR	0F0H 
	z_a=(z_a|0xF0);
//	LD	(HL),A			; 設定値表示  
	_NB_PAY_LED=z_a;

//; ランク表示 
// 
MS_RANK_DSP1:
//	RST	S_WATCH_CLEAR		; ウォッチドッグクリア  
//		S_WATCH_CLEAR();//		; ウォッチドッグクリア  
// 
//	LD	A,(_PT_IN0_DOWN) 
	z_a=_PT_IN0_DOWN;
//	BIT	6,A			; 設定用キースイッチＯＮ？ 
//	JR	Z,MS_RANK_DSP1		; 　ＹＥＳ 
	if(!(z_a&(0x01<<6)))	goto MS_RANK_DSP1;
// 
//	LD	(HL),B			; 遊技メダル払出し枚数表示  復帰 
	_NB_PAY_LED=z_b;

//	RST	S_BLOCKER_ON		; 遊技メダルブロッカーＯＮ<通過状態> 
	S_BLOCKER_ON();//		; 遊技メダルブロッカーＯＮ<通過状態> 

//	RET 
}


//;********************************************************************** 
//;*	管理番号      : S-0708-002										* 
//;*	機能	      : 入賞期待時の出力セット							* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_HIT_SET										* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 												* 
//;*	保護ﾚｼﾞｽﾀ     : 												* 
//;*	破壊ﾚｼﾞｽﾀ     : A,HL											* 
//;*	使用ﾓｼﾞｭｰﾙ    : MS_BNS_CHK,S_LPSD_SET							* 
//;********************************************************************** 

void MS_HIT_SET(void)
{
	int lp,hlp,dep;
	char z_a,z_b,z_c;
//	CALL	MS_BNS_CHK		; ボーナスゲームチェック 
//	RET	NZ			; ボーナスゲーム？．．ＹＥＳ 
	if(!MS_BNS_CHK())	return;

//	LD	A,(_NB_STOP_ORDER) 
	z_a=_NB_STOP_ORDER;

//	CP	2			; 第２、又は第３停止時？ 
//	RET	C			;   ＮＯ 
	if(z_a<2)	return;	//	左ボタンならリターン 

//	LD	HL,_FL_WBL 
//	JR	Z,MS_HIT_SET1		; 第２停止？．．ＹＥＳ 
	if(z_a==2)	goto MS_HIT_SET1;

//; 第３停止時の処理 
//	LD	A,(HL)			; // HL = _FL_WBL 
	z_a=_FL_WBL;
//	AND	A			; 入賞期待時の表示あり？ 
//	RET	Z			;   ＮＯ 
	if(z_a==0)	return;
// 
//	LD	(HL),0			; 入賞期待表示フラグ　クリア 
	_FL_WBL=0;
//	LD	A,(_WK_EFFECT_LP)	; 入賞期待時の効果ランプ 
//							;;パターン確認要求　セット 
	z_a=_WK_EFFECT_LP.lamp;
//	CP	@ELP_WBL			; 効果ランプ(ﾊﾟﾀｰﾝ3)出力中？ 
//	RET	NZ					;   ＮＯ 
	if((z_a!=ELP_WBL))	return;

//	LD	A,@SET_WBLEND		; 入賞期待時の出力終了要求　セット 
	z_a=SET_WBLEND;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 
	return;
//	RET 
//; 第２停止時の処理 
// 
MS_HIT_SET1:
//	LD	A,(_TM1_STOP) 
	z_a=_TM1_STOP;
//	AND	A			; 回胴停止受付待ち？ 
//	RET	NZ			;   ＹＥＳ 
	if(z_a)	return;

//	LD	A,(HL)			; // HL = _FL_WBL 
	z_a=_FL_WBL;
//	AND	A			; 入賞期待時の表示済み？ 
//	RET	NZ			;   ＹＥＳ 
	if(z_a){
		return;
	}

	if(!MACINE){	//	かっぱ 
//	LD	A,(_WK_ALL_PIC2) 
	z_a=_WK_ALL_PIC2;
//	AND	@BB OR @RB		; 当該図柄表示？ 
	z_a&=(BB | RB);

//	RET	Z			;   ＮＯ 
	if(z_a==0)	return;
// 
//	LD	(HL),0FFH		; 入賞期待表示フラグ　セット 
	_FL_WBL=0xFF;
// 
//	LD	A,@SET_WBLSTART		; 入賞期待時の出力要求  セット 
	z_a=SET_WBLSTART;
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 
//	RET 
	return;

	}else{	//	びんびん 

//	LD	L,LOW _WK_ALL_PIC2 
//	LD	A,(HL)			; 停止図柄データ２（全有効ライン）　セット 
	z_a=_WK_ALL_PIC2;
//	AND	@BB OR @RB		; 当該図柄表示？ 
	z_a&=(BB | RB);
//	RET	Z			;  ＮＯ 
	if(z_a==0)	return;

//	LD	A,@SET_WBLSTART		; 入賞期待時の出力要求　セット 
	z_a=SET_WBLSTART;
//	DEC	HL			; 停止図柄データ１（全有効ライン）　セット 
//					; // HL = _WK_ALL_PIC1 
//	BIT	@BT_CHERRY,(HL)		; チェリー表示？ 
//	JR	NZ,MS_HIT_SET5		;   ＹＥＳ 
	if((_WK_ALL_PIC1&(0x01<<BT_CHERRY)))	goto MS_HIT_SET5;

//	LD	L,LOW _FL_STOP_LP	; 回胴停止フラグ　セット 
//	BIT	7,(HL)				; 右回胴回転中？ 
//	JR	Z,MS_HIT_SET5		;   ＮＯ 
	if(!(_FL_STOP_LP&0x80))	goto MS_HIT_SET5;

//	LD	DE,TBL_HIT_SET-1	; 入賞期待表示パターンテーブル　セット 
//	LD	L,LOW _WK_STOP_PIC2-1 
	hlp=-1;
	dep=-1;
MS_HIT_SET2:
//	INC	HL			; // HL = _WK_STOP_PIC2+0～+4 
	hlp++;
//	LD	A,(HL)			; 停止図柄データ２（各有効ライン）　セット 
	z_a=_WK_STOP_PIC2[hlp];

//	LD	B,@BNSPT		; ボーナス図柄数　セット 
	z_b=BNSPT;
MS_HIT_SET3:
//	INC	DE 
	dep++;
//	RRCA				; 当該図柄検索終了？ 
	if((z_a&0x01)){
		z_a=((z_a>>1)|0x80);
//	JR	C,MS_HIT_SET4		;   ＹＥＳ 
		goto MS_HIT_SET4;
	}
	else	z_a=(z_a>>1);

//	DJNZ	MS_HIT_SET3		; 次のライン？．．ＮＯ 
	z_b-=1;
	if(z_b)	goto MS_HIT_SET3;

//	JR	MS_HIT_SET2 
	goto MS_HIT_SET2;


MS_HIT_SET4:
//	LD	A,(DE)			; 出力要求番号　セット 
	z_a=TBL_HIT_SET[dep];
MS_HIT_SET5:
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

//	LD	L,LOW _FL_WBL 
//	LD	(HL),0FFH		; 入賞期待表示フラグ　セット 
	_FL_WBL=0xFF;
// 
//	RET 
	}
}


//;************************************************************************ 
//;*	管理番号      : S-0709-002					* 
//;*	機能	      : 回胴停止時の出力セット				* 
//;*	ﾓｼﾞｭｰﾙ名      : MS_RLSTOP_SET					* 
//;*	入力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	出力ﾊﾟﾗﾒｰﾀ    : 						* 
//;*	保護ﾚｼﾞｽﾀ     : 						* 
//;*	破壊ﾚｼﾞｽﾀ     : A,B,DE,HL					* 
//;*	使用ﾓｼﾞｭｰﾙ    : S_ADDR_SET,S_LPSD_SET				* 
//;************************************************************************ 

void MS_RLSTOP_SET(void)
{
	int z_a,z_b,lp,hlp;

	lp=3;
//	LD	B,00001000B		; 回胴ビット　セット 
	z_b=0x08;
//	LD	HL,_WK_REEL1 - 8	; 回胴制御データＲＡＭアドレス 
//					;;初期値　セット 
MS_RLSTOP_SET1:
//	SRL	B			; 全回胴チェック終了？ 
	lp--;
	if((z_b&0x01)){
		z_b=z_b>>1;
		cy=1;
		z_b&=0x7F;
	}
	else{
		z_b=z_b>>1;
		z_b&=0x7F;
		cy=0;
	}

//	RET	C			;   ＹＥＳ 
	if(cy)	return;

//	LD	A,_WK_REEL2-_WK_REEL1	; 次の回胴制御データＲＡＭアドレス 
//								;;要求　セット 
//								; // A = 8 
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
// 
//	LD	A,(HL)			; // HL = _WK_REEL# + 0 
	z_a=_WK_REEL[lp][0];
//	CP	4			; 回胴４相励磁中？ 
//	JR	NZ,MS_RLSTOP_SET1	;   ＮＯ 
	if((z_a-4)!=0)	goto MS_RLSTOP_SET1;

//	LD	DE,_FL_STOP_LP 
//	LD	A,(DE) 
	z_a=_FL_STOP_LP;
//	AND	B			; 回胴停止音出力済み？ 
	z_a&=z_b;
	if(z_a)	goto MS_RLSTOP_SET1;   //ＹＥＳ 
//	JR	NZ,MS_RLSTOP_SET1	;   ＹＥＳ 

//	LD	A,(DE)			; // DE = _FL_STOP_LP 
	z_a=_FL_STOP_LP;
//	OR	B 
	z_a=(z_a|z_b);
//	LD	(DE),A			; 回胴停止フラグ　セット 
	_FL_STOP_LP=z_a;

//	LD	A,@SET_R_STOP		; 回胴停止時の出力要求　セット 
	z_a=SET_R_STOP;
//	RST	S_LPSD_SET			; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);		//; 各種ランプ・効果音データセット１ 

	if(!MACINE){
//	LD	A,(_NB_STOP_ORDER) 
	z_a=_NB_STOP_ORDER;
//	CP	3			; 第３停止？ 
//	RET	C			;   ＮＯ 
	if(z_a<3)	return;

//	LD	L,LOW _WK_ALL_PIC2	; // H = HIGH @RAM 
//	LD	A,(HL) 
	z_a=_WK_ALL_PIC2;
//	AND	@BB OR @RB		; 図柄２群入賞？ 
	z_a&=(BB | RB);
//	JR	Z,MS_RLSTOP_SET2	;   ＮＯ 
	if(!z_a)	goto MS_RLSTOP_SET2;
// 
//	LD	L,LOW _PT_OUT2 
//	RES	7,(HL)			; 遊技状態表示ランプ３消灯　セット 
	_PT_OUT2&=((0x01<<7)^0xFF);
//	RET 
	return;
MS_RLSTOP_SET2:
//	DEC	HL			; // HL = _WK_ALL_PIC1 
//	LD	A,(HL) 
	z_a=_WK_ALL_PIC1;
//	LD	L,LOW _FL_PUL_PIC1 
//	AND	(HL)			; 図柄１群入賞？ 
	z_a&=_FL_PUL_PIC1;
//	RET	NZ			;   ＹＥＳ 
	if(z_a)	return;

//	LD	A,(_FL_PUL_PIC2) 
	z_a=_FL_PUL_PIC2;
//	AND	@BB OR @RB		; 内部中遊技？ 
	z_a&=(BB | RB);
//	JR	Z,MS_RLSTOP_SET3	;   ＮＯ 
	if(!z_a) goto MS_RLSTOP_SET3;
// 
//	LD	L,LOW _PT_OUT2 
//	SET	7,(HL)			; 遊技状態表示ランプ３点灯  セット 
	_PT_OUT2=(_PT_OUT2|(0x01<<7));
// 
MS_RLSTOP_SET3:
//	LD	HL,(_BF_STOP_CTL) 
//	LD	A,H 
//	OR	L			; 左回胴第１停止？ 
//	RET	Z			;   ＮＯ 
	if(_BF_STOP_CTL==0)	return;

//	LD	HL,TBL_RLST_LOT - 1	; 回胴回転停止時の出力パターン 
//					;;決定用抽選確率テーブル　セット 
	hlp=0;
//	LD	A,(_TM1_STOP) 
	z_a=_TM1_STOP;

//	CP	@TM_SHIFT_START2 + 1	; 回胴回転停止時の出力抽選する？ 
//	RET	NC			;   ＮＯ 
	if(z_a>=(TM_SHIFT_START2+1))	return;

//	CP	@TM_SHIFT_START1 + 1	; 回胴停止受付から１５４ｍｓ経過？ 
//	JR	NC,MS_RLSTOP_SET4	;   ＮＯ 
	if(z_a>=(TM_SHIFT_START1+1))	goto MS_RLSTOP_SET4;

//	LD	A,4 
	z_a=4;
//	RST	S_ADDR_SET		; ワーク・テーブルのアドレスセット 
	hlp=1;
MS_RLSTOP_SET4:
//	LD	A,R			; Ｒレジスタ読み込み 
	z_a=rnd(0xFF);
//	OR	1000 0000B 
	z_a=(z_a|0x80);
//	LD	B,2 
	z_b=2;
	lp=-1;
MS_RLSTOP_SET5:
	lp+=1;
//	INC	HL			; <(HL) = 回胴回転停止時の出力パターン抽選置数> 
//						HL=TBL_RLST_LOT[hlp][0] 
//	ADD	A,(HL) 
	z_ai=z_a;
	z_ai+=TBL_RLST_LOT[hlp][lp];
	z_a+=TBL_RLST_LOT[hlp][lp];
//	INC	HL			; <(HL) = 回胴回転停止時（パターン別）の出力要求> 
	lp+=1;
//	JR	C,MS_RLSTOP_SET6	; 回胴回転停止時の出力当選？．．ＹＥＳ 
	if(z_ai<0x80)	goto MS_RLSTOP_SET6;
	z_b-=1;
	if(z_b)	goto MS_RLSTOP_SET5;
//	DJNZ	MS_RLSTOP_SET5		; 回胴回転停止時の出力の抽選終了？．．ＮＯ 
//	RET 
	return;

MS_RLSTOP_SET6:
//	LD	A,(HL)			; 回胴回転停止時の出力要求　セット 
	z_a=TBL_RLST_LOT[hlp][lp];
//	RST	S_LPSD_SET		; 各種ランプ・効果音データセット１ 
	S_LPSD_SET(z_a);	//; 各種ランプ・効果音データセット１ 
//	RET 
	}
}


