
#ifndef _SOUND_H_

#define _SOUND_H_

#define	SEQ_INFI SSPLAY_INFINITY
#define	SEQ_SHOT 1

#define	SEQ_VOL	127

#define	_SE_CUR1		se_start(SE_CUR1);		//・カーソル移動音 
#define	_SE_SUR2		se_start(SE_SUR2);		//・カーソル移動音（はで） 
#define	_SE_OK			se_start(SE_OK);		//・決定音 
#define	_SE_POINT_UP	se_start(SE_POINT_UP);	//・ポイントUP音 
#define	_SE_CANCEL		se_start(SE_CANCEL);	//・キャンセル音 
#define	_SE_SUB_MENU	se_start(SE_SUB_MENU);	//・サブメニュー音 
#define	_SE_INFO		se_start(SE_INFO);		//・インフォメーション表示音 
#define	_SE_BAD			se_start(SE_BAD);		//・残念メッセージ表示音 
#define	_SE_RET_MEDAL	se_start(SE_RET_MEDAL);	//・払い出しメダルの生音 
#define	_SE_HAPPYOU		se_start(SE_HAPPYOU);	//・結果発表ジングル 
#define	_SE_ERROR		se_start(SE_ERROR);		//・実機エラー音（ループ） 


#define	_GSE_MEDAL_IN		gse_start(SE_MEDAL_IN);		//・メダル投入音 
#define	_GSE_REEL_START		gse_start(SE_REEL_START);	//・リールスタート音 
#define	_GSE_WAIT			gse_start(SE_WAIT);			//・ウエイト音 
#define	_GSE_REEL_STOP_IN	gse_start(SE_REEL_STOP_IN);	//・リール停止受付音 
#define	_GSE_REEL_STOP		gse_start(SE_REEL_STOP);	//・リール停止音 
#define	_GSE_MEDAL_OUT		gse_start(SE_MEDAL_OUT);	//・メダル払い出し音 
#define	_GSE_REPLAY			gse_start(SE_REPLAY);		//・リプレイ音 
#define	_GSE_REECHI			gse_start(SE_REECHI);		//・リーチ音 

//	ゲーム中の使用状態
#define _GSEQ1	game_seq_set(0,1);	//binbin1.seq	(BIGファンファーレ セブン） 
#define _GSEQ2	game_seq_set(1,1);	//binbin2.seq	(BIGファンファーレ 福の神） 
#define _GSEQ3	game_seq_set(2,0);	//binbin3.seq	( 小役ゲーム中BGM セブン） 
#define _GSEQ4	game_seq_set(3,0);	//binbin4.seq	( 小役ゲーム中BGM 福の神） 
#define _GSEQ5	game_seq_set(4,0);	//binbin5.seq	( 小役ゲーム中BGM 残り６ゲーム） 
#define _GSEQ6	game_seq_set(5,0);	//binbin6.seq	( JACゲーム中BGM） 
#define _GSEQ7	game_seq_set(6,1);	//binbin7.seq	( BIG終了BGM） 

#define _GSEQ1K	game_seq_set(0,1);	//binbin1.seq	(BIGファンファーレ セブン） 
#define _GSEQ2K	game_seq_set(1,1);	//binbin2.seq	(BIGファンファーレ 福の神） 
#define _GSEQ3K	game_seq_set(2,0);	//binbin3.seq	( 小役ゲーム中BGM セブン） 
#define _GSEQ4K	game_seq_set(3,0);	//binbin4.seq	( 小役ゲーム中BGM 福の神） 
#define _GSEQ5K	game_seq_set(4,1);	//binbin5.seq	( 小役ゲーム中BGM 残り６ゲーム） 


//	一回だけ演奏する
#define _GSEQ1S	game_seq_set(0,1);	//binbin1.seq	(BIGファンファーレ セブン） 
#define _GSEQ2S	game_seq_set(1,1);	//binbin2.seq	(BIGファンファーレ 福の神） 
#define _GSEQ3S	game_seq_set(2,1);	//binbin3.seq	( 小役ゲーム中BGM セブン） 
#define _GSEQ4S	game_seq_set(2,1);	//binbin4.seq	( 小役ゲーム中BGM 福の神） 
#define _GSEQ5S	game_seq_set(2,1);	//binbin5.seq	( 小役ゲーム中BGM 残り６ゲーム） 
#define _GSEQ6S	game_seq_set(3,1);	//binbin6.seq	( JACゲーム中BGM） 
#define _GSEQ7S	game_seq_set(4,1);	//binbin7.seq	( BIG終了BGM） 


#define OPN_SEQ	seq_set(OPENING_VH_N,OPENING_VB_N,OPENING_SEQ_N,0);	// OPならす 
#define SEL_SEQ	seq_set(K_SELECT_VH_N,K_SELECT_VB_N,K_SELECT_SEQ_N,0);	// セレクト 

#define OPN_SEQ_END	seq_stop();	// OP止る 
#define SEL_SEQ_END	seq_stop();	// セレクト画面 

extern void vol_set_five(void);
extern void seq_stop(void);
extern void seq_set(int vh_num,int vb_num,int seq_num,short try);
void game_seq_set(int seq_num,short try);
void game_seq_stop(void);

extern void vol_okaeri(void);
extern void vol_kill(void);

void sound_init(void);
void sound_quit(void);
void sound_driver(void);
void sound_vsync(void);	/* callback for VSync */

short se_start(enum se_num num);
void se_stop(void);

short gse_start(enum gse_num num);
void gse_stop(int no);


#if 0
void vab_set(int vh_num, int vb_num);
#endif

//void se_vab_set(int vh_num, int vb_num,int no);
void se_vab_set(void *vh, void *vb,int no);
void se_vab_end(void);

void game_vab_set(int no);
void game_vab_end(void);

void seq_fadeout(int frame); /* ＳＥＱのフェードアウト */
void vab_end(void);

#if 0
extern void	*vh_adr,*vb_adr,*sstab_adr,*seq_adr;
extern short	vabid;
extern char		vab_no;
#endif

extern void *sstbl_adr;

extern u_char	se_vh_adr[];
extern void *se_vb_adr;		/*	システムＳＥ用 */
extern short	se_vabid;				/* vab id */
extern char		se_vab_no;				/* vab no */ 

extern short	seq_acs_num;

#endif

