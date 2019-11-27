/*
*	サウンド関係
*	ＳＥ		内臓（ＶＨ＋ＶＢ）
*
*/
//#define SOUND_DEB		//	ＳＥのデバッグ

#include "common.h"
#include "work.h"

#include "kaps.hd"
#include "bins.hd"

#include "kapseq.hd"
#include "binseq.hd"

#include "snd_dat.c"	/*サウンドの指定データ*/

#ifdef	SOUND_DEB
static void joy_se(void);
static int flg = 0;
#endif

#if 1
void	*vh_adr,*vb_adr,*seq_adr;
short	vabid=0;		/* vab id */
char	vab_no=0;
#endif

void *sstbl_adr;

u_char	se_vh_adr[VH_SE_SIZE];
void	*se_vb_adr;	/*	システムＳＥ用 */
short	se_vabid=0;				/* vab id */
char	se_vab_no=0;			/* vab no */ 

short	game_vabid=0;				/* vab id */
char	game_vab_no=0;			/* vab no */ 
u_char	game_vh[6688];

short	game_sndid=0;				/* vab id */
char	game_snd_no=0;			/* vab no */ 
u_char	game_snd[9250];

u_char g_seq[12600];
short gseq_acs_num;
short gseq_no=-1;
int gseq_on=0;	//	シーケンス関係使ってる？


short vabid;		/* vab id */
short voice_no=0;
short seq_acs_num;
short seq_no=-1;
int seq_on=0;	//	シーケンス関係使ってる？

//XA_TBL *xa_pt;


void vol_set_five(void)
{

	if(!mono_flag)	SsSetStereo();
	else			SsSetMono();
	SsSepSetVol(gseq_acs_num,0,volume,volume);

}

char vol_bak;

void vol_okaeri(void)
{
	if(volume==0){
		volume=vol_bak;
		vol_set_five();
	}
}



void vol_kill(void)
{
	vol_bak=volume;
	if(au_sp==0)	volume=volume;
	else			volume=0;

	vol_set_five();
}

//=============================================================
//	汎用効果音ＳＥを鳴らします
//in:	ＳＥ番号
//=============================================================
short se_start(enum se_num num)
{
 SE_TBL *se;
 short ret;

	se = &se_tbl[num];
	ret = SsUtKeyOn(se_vabid,se->prog,se->tone,se->note,0,volume,volume);
	return ret;
}

void se_stop(void)
{
	SsUtAllKeyOff(0);
}

void se_vab_set(void *vh,void *vb,int no)
{
	if(se_vab_no!=no){
		if(se_vab_no!=0)	se_vab_end();
		se_vab_no=no;

		memcpy(&se_vh_adr[0],vh,VH_SE_SIZE);	//	ＶＨは固定メモリへ 

		/*SE (open vab head) */
		do{
			se_vabid = SsVabOpenHead((u_char*)se_vh_adr, -1);
		}while(se_vabid == -1);

		/*SE (音源データを転送する)*/
		while (SsVabTransBody ((u_char*)vb, se_vabid) != se_vabid);

		/*SE (転送終了を待つ)*/
		SsVabTransCompleted (SS_WAIT_COMPLETED);
	}
}

void se_vab_end(void)
{
	if(se_vab_no){
		se_vab_no=0;
		SsUtAllKeyOff(0);
		SsVabClose(se_vabid);	/* close vab data */
	}
}



//=============================================================
//	ゲーム中効果音ＳＥを鳴らします
//in:	ＳＥ番号
//=============================================================
/*	ゲーム中のＳＥ用ＶＨは固定されたメモリに持っておく */
void game_vab_set(int no)
{
	u_short	SND_FILE[2]={KAPS_TIC_N,BINS_TIC_N};
	u_int s_r[2][7]={
	{VB_KAPAPA1,VH_KAP_SE,VH_KAP_SE_SIZE,
		VH_KAPAPA1,VH_KAPAPA1_SIZE,TIC_KAPSEQ,TIC_KAPSEQ_SIZE},
	{VB_BINBIN1,	VH_BIN_SE,	VH_BIN_SE_SIZE,
		VH_BINBIN1,	VH_BINBIN1_SIZE,	TIC_BINSEQ,	TIC_BINSEQ_SIZE},
	};
	void	*game_snd_adr=NULL;

	if(game_vab_no!=no){
		if(game_vab_no!=0)	game_vab_end();
		game_vab_no=no;
		/*SE & SEQ (file load)*/
		game_snd_adr = datafile_read(SND_FILE[MACINE],NULL);
		memcpy(&game_vh[0],game_snd_adr+s_r[MACINE][1],s_r[MACINE][2]);
		memcpy(&game_snd[0],game_snd_adr+s_r[MACINE][3],s_r[MACINE][4]);
		memcpy(&g_seq[0],(game_snd_adr+s_r[MACINE][5]),s_r[MACINE][6]);

		do{
			game_vabid = SsVabOpenHead((u_char *)game_vh, -1);
		}while(game_vabid == -1);
		/*SE (音源データを転送する)*/
		while (SsVabTransBody ((u_char*)game_snd_adr, game_vabid) != game_vabid);
		/*SE (転送終了を待つ)*/
		SsVabTransCompleted (SS_WAIT_COMPLETED);

		game_snd_no=no+1;
		do{	//	ＳＥＱ用ＶＡＢ
			game_sndid = SsVabOpenHead((u_char *)game_snd, -1);
		}while(game_sndid == -1);

		/*SE (音源データを転送する)*/
		while (SsVabTransBody ((u_char*)(game_snd_adr+s_r[MACINE][0]), game_sndid) != game_sndid);
		/*SE (転送終了を待つ)*/
		SsVabTransCompleted (SS_WAIT_COMPLETED);

		memfree((void**)&game_snd_adr);
	}
}

short gvoice[8];
short gse_start(enum gse_num num)
{
	SE_TBL *se;
	if((auto_on_s==0) || ((auto_on_s==1) && (au_sp==0))){
	se = &gse_tbl[num];
	gvoice[num] = SsUtKeyOn(game_vabid,se->prog,se->tone,se->note,0,volume,volume);
	return gvoice[num];
	}
}

void gse_stop(int no)
{
	short ret;
	ret = SsUtKeyOff(gvoice[no],game_vabid,no,0,0);
}

void game_vab_end(void)
{
	if(game_vab_no){
		game_vab_no=0;
		SsUtAllKeyOff(0);	//	とりあえず全部止める 
		SsVabClose(game_sndid);	/* close vab data */
		SsVabClose(game_vabid);	/* close vab data */
	}
}


//=============================================================
//=============================================================
//	ＳＥのＶＡＢの開放
//=============================================================

void vab_set(int vh_num, int vb_num)
{
	/*SE (file load)*/
	vh_adr = datafile_read(vh_num,NULL);	/* VH */
	vb_adr = datafile_read(vb_num,NULL);	/* VB */
	/*SE (open vab head) */
	do{
		vabid = SsVabOpenHead((u_char*)vh_adr, -1);
	}while(vabid == -1);

	/*SE (音源データを転送する)*/
	while (SsVabTransBody ((u_char*)vb_adr, vabid) != vabid);

	/*SE (転送終了を待つ)*/
	SsVabTransCompleted (SS_WAIT_COMPLETED);
	memfree((void**)&vb_adr);
}

void vab_end(void)
{
	SsUtAllKeyOff(0);
	memfree((void**)&vh_adr);
	SsVabClose(vabid);	/* close vab data */
}



/* 一般用ＳＥＱ（タイトル・セレクト） */
void seq_set(int vh_num,int vb_num,int seq_num,short try)
{
	if(seq_no!=seq_num){
		seq_stop();
		seq_no=seq_num;
		vab_set(vh_num,vb_num);
		seq_adr = datafile_read(seq_num,NULL);	//サウンド
		seq_acs_num = SsSeqOpen(seq_adr,vabid);
		SsSeqPlay(seq_acs_num,SSPLAY_PLAY,try);
		SsSepSetVol(seq_acs_num,0,SEQ_VOL,SEQ_VOL);
		seq_on=1;
	}else{
		SsSepSetVol(seq_acs_num,0,SEQ_VOL,SEQ_VOL);
	}
}



//	シーケンス関係
void seq_stop(void)
{
	if(seq_on){
		SsSeqStop(seq_acs_num);
		SsSeqClose(seq_acs_num);	//seqクリア
		vab_end();
		memfree((void**)&seq_adr);			//seqメモリ解放
		seq_on=0;
		seq_no=-1;
	}
}




/* ゲーム中ＳＥＱサウンド ******************************************/
void game_seq_set(int seq_num,short try)
{
//	かなり特化したルーティンになってますので参考にしないように 
	u_long seq_tbl[2][7]={
		{SEQ_KAPAPA1,SEQ_KAPAPA2,SEQ_KAPAPA3,SEQ_KAPAPA4,
					SEQ_KAPAPA5,SEQ_KAPAPA5,SEQ_KAPAPA5,},
		{SEQ_BINBIN1,SEQ_BINBIN2,SEQ_BINBIN3,SEQ_BINBIN4,
					SEQ_BINBIN5,SEQ_BINBIN6,SEQ_BINBIN7,},
	};

	if(seq_num<7){
		gsound_=seq_num+1;

		if(gseq_no!=seq_num){
			game_seq_stop();
			gseq_no=seq_num;

			gseq_acs_num = SsSeqOpen((u_long *)(g_seq+seq_tbl[MACINE][seq_num]),game_sndid);

			if(!mono_flag)	SsSetStereo();
			else			SsSetMono();

			if(try==0)	try=SSPLAY_INFINITY;
			SsSeqPlay(gseq_acs_num,SSPLAY_PLAY,try);
			SsSepSetVol(gseq_acs_num,0,volume,volume);
			gseq_on=1;
		}
		else{
			SsSepSetVol(gseq_acs_num,0,volume,volume);
		}
	}
}

/* 終了 */
void game_seq_stop(void)
{
	if(gseq_on){
		SsSeqStop(gseq_acs_num);
		SsSeqClose(gseq_acs_num);	//seqクリア
		gseq_on=0;
		gseq_no=-1;
		gsound_=0;
	}
}


//=============================================================
//	サウンド初期化関数
//
//	CdInitの後に呼ぶこと
//
//=============================================================
#define	REV_DEPT 10

char sstbl_tbl[SS_SEQ_TABSIZ*2*1];

void sound_init(void)
{
    register int i;

	seq_on=0;	//	シーケンスの使用状況

	/*SE (Ss initial)*/
//	sstbl_adr = memalloc(SS_SEQ_TABSIZ*1*1, (void**)&sstbl_adr);
//	sstbl_adr = memalloc(SS_SEQ_TABSIZ*1*1, (void**)&sstbl_adr);
	SsInit();		/* reset sound */
//	SsSetTableSize(sstbl_adr,1,1);	//メモリアドレス,最大オープン数,seq_only
	SsSetTableSize((char *)&sstbl_tbl,2,1);	//メモリアドレス,最大オープン数,seq_only

	SsSetTickMode(SS_NOTICK/*SS_TICK60*/);

	/*メインボリューム*/
	SsSetMVol(0x30,0x30);	/*中間(40)よりちょっと下*/

	/* XA CD 入力 ON */
	SsSetSerialAttr(SS_SERIAL_A, SS_MIX, SS_SON);

	/*SE (start sound system) */
	SsStart2();

	/*リバーブ開始*/
//	SsUtSetReverbType(SS_REV_TYPE_ROOM);
	SsUtSetReverbType(SS_REV_TYPE_OFF);


//	SsUtReverbOn();
	wait(60);		/* wait for ﾉｲｽﾞ防止の為 */
//	SsUtSetReverbDepth(REV_DEPT,REV_DEPT);


#if 1
	vh_adr=NULL;
	vb_adr=NULL;
#endif
	sstbl_adr=NULL;

	seq_adr=NULL;
//	se_vh_adr=NULL;
	se_vb_adr=NULL;

}

/*
*	サウンド終了処理
*/
void sound_quit(void)
{
	/*SE (end process)*/
	SsUtReverbOff();
	SsVabClose(game_vabid);	/* close vab data */
	SsVabClose(se_vabid);	/* close vab data */
	SsEnd();		/* sound system end */
	SsQuit();
}


/*	周期関数（ＷＡＩＴに入れる）*/
void sound_driver(void)
{
#ifdef	SOUND_DEB
		joy_se();
#endif
}


/*
 * Sound Vsync callback
 */
void sound_vsync(void)
{
	/*SE */
	SsSeqCalledTbyT();
}

#ifdef	SOUND_DEB
/*	ＳＥの開始（テスト）*/
static void joy_se(void)
{
	static short se_no = 0;

	FntPrint("SE NO.(%d)\n", se_no);

	if(pad_trg & PAD_L1)
	{
		if(se_no == 6 )		se_no=0;
		else				se_no++;
switch(se_no){
case 0:
 _GSEQ1
break;
case 1:
_GSEQ2
break;
case 2:
_GSEQ3
break;
case 3:
_GSEQ4
break;
case 4:
_GSEQ5
break;
case 5:
_GSEQ6
break;
case 6:
_GSEQ7
break;
}

	}
	else if(pad_trg & PAD_L2)
	{
		if(se_no == 0 )		se_no=6;
		else				se_no--;
switch(se_no){
case 0:
 _GSEQ1
break;
case 1:
_GSEQ2
break;
case 2:
_GSEQ3
break;
case 3:
_GSEQ4
break;
case 4:
_GSEQ5
break;
case 5:
_GSEQ6
break;
case 6:
_GSEQ7
break;
}



//		se_stop();		/*効果音ＳＴＯＰ*/
//		if(!se_no)	se_no=SE_ERROR;
//		else		se_no--;
//		se_start(se_no);
	}
}
#endif



void seq_fadeout(int frame)
{	/* ＳＥＱのフェードアウト */
	SsSeqSetDecrescendo(seq_acs_num,-255,frame);
}

