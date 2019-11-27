
#ifndef _KAPBIN_H_

#define _KAPBIN_H_

//extern void BACK_LAMP_OUT(void); 

//extern char	sta[3][7];
//extern char	tei_kou;
//extern char	win_deru_ok;
//extern char	med_kau;
extern char	aupd;
extern char	stpl[3];
extern char cyuusengo;
extern char imano_harai;
extern char	no_start;

extern char rep_step[5];
extern char rep_no;
extern char ran_f;
extern char pan_f;
extern char bb_kitakana;
extern void replay_master(int mode);
extern int set_qes_master(int mode);
extern int set_cross_master(int mode);
extern void mes_deru(int mes_no,int mode);
extern void S_RAM_CLEAR(short);
extern void pflg_set_2(void);


//extern char	stp_reel_buf[3];
struct _GAME_WK{
	char	lot_point;
	char	tori;
	char	tei_kou;
	char	win_deru_ok;
	char	med_kau;
//ＡＵＴＯＳＴＯＰフラグ
	char au_step;
	char au_suberi;

	char	sta[3][7];
	char	stp_reel_buf[3];
};
typedef struct _GAME_WK GAME_WK;

extern GAME_WK gwk;


#define lot_point		gwk.lot_point
#define tori			gwk.tori
#define tei_kou			gwk.tei_kou
#define win_deru_ok		gwk.win_deru_ok
#define med_kau			gwk.med_kau
#define au_step			gwk.au_step
#define au_suberi		gwk.au_suberi
#define sta				gwk.sta
#define stp_reel_buf	gwk.stp_reel_buf


struct _DATA_TORU{
	int		d_ransu;
	char	d_ppoi;
	char	d_tbl_c;
	char	nyuuu;
};
typedef struct _DATA_TORU DATA_TORU;
DATA_TORU dtt;

#define	d_ransu	dtt.d_ransu
#define	d_ppoi	dtt.d_ppoi
#define	d_tbl_c	dtt.d_tbl_c
#define	nyuuu	dtt.nyuuu

extern void shira_yobu(void);

extern void pflg_set_(void);


extern void slot_main(void);
extern void I_INTR(void);

//void M_PRG_START(void);
//void M_PRG_START1(void);


extern char __PIC1[];
extern char __PIC2[];

//; 図柄１群 
extern char __CHERRY[];
extern char __FRUIT1[];
extern char __FRUIT2[];
extern char __REPLAY[];
extern char __JAC[];
extern char __FRUIT[];
extern char __SRB[];
extern char __BT_CHERRY[];

//; 図柄２群 
extern char __BB1[];
extern char __BB2[];
extern char __RB1[];
extern char __RB2[];
extern char __BB[];
extern char __RB[];
extern char __BNSPT[];


//	かっぱっぱ 
//;	*************************************************
//;	*	図柄データ定義				*
//;	*************************************************
//;
#define KAP__PIC1	(0x1F)	//0001 1111B	//; 図柄１群
#define KAP__PIC2	(0x0F)	//00001111B	//; 図柄２群
//
//; 図柄１群
//
#define KAP_CHERRY	(0x01)	//0000 0001B	//; (ﾁｪﾘｰ･-･-)
#define KAP_FRUIT1	(0x02)	//0000 0010B	//; (酒･酒･酒)
#define KAP_FRUIT2	(0x04)	//0000 0100B	//; (胡瓜･胡瓜･胡瓜)
#define KAP_REPLAY	(0x08)	//0000 1000B	//; (月･月･月)
#define KAP_JAC		(0x10)	//0001 0000B	//; (かっぱ･月･月)
#define KAP_FRUIT	(0x06)	//0000 0110B	//; (酒･酒･酒)、(胡瓜･胡瓜･胡瓜)
//
//; 図柄２群
//
#define KAP_BB1		(0x01)	//0000 0001B	//; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
#define KAP_BB2		(0x02)	//0000 0010B	//; (かっぱ･かっぱ･かっぱ)
#define KAP_RB1		(0x04)	//0000 0100B	//; (BAR･BAR･BAR)
#define KAP_RB2		(0x08)	//0000 1000B	//; (BAR･BAR･かっぱ)
#define KAP_BB		(0x03)	//0000 0011B	//; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)、
											//; (かっぱ･かっぱ･かっぱ)
#define KAP_RB		(0x0C)	//0000 1100B	//; (BAR･BAR･BAR)、(BAR･BAR･かっぱ)


//	ここからびんびん
////;	*************************************************
////;	*	図柄データ定義				*
////;	*************************************************
////;
#define BIN__PIC1	(0x3F)	//EQU	0011 1111B	//; 図柄１群
#define BIN__PIC2	(0x07)	//EQU	00000111B	//; 図柄２群
////; 図柄１群
#define BIN_FRUIT1  (0x01)	//EQU	00000001B	//; (山･山･山)
#define BIN_FRUIT2  (0x02)	//EQU	00000010B	//; (こづち･こづち･こづち)
#define BIN_REPLAY  (0x04)	//EQU	00000100B	//; (ｽｽﾞ･ｽｽﾞ･ｽｽﾞ)
#define BIN_CHERRY  (0x08)	//EQU	00001000B	//; (ﾁｪﾘｰ･－･－)
#define BIN_SRB     (0x10)	//EQU	00010000B	//; (こづち･こづち･BAR)
#define BIN_JAC     (0x20)	//EQU	00100000B	//; (ﾁｪﾘｰ･ｽｽﾞ･ｽｽﾞ)

#define BIN_FRUIT	(0x03)	//EQU	00000011B
//							////; (山･山･山)、(こづち･こづち･こづち)

#define BIN_BT_CHERRY	(3)	//EQU	3		//; (ﾁｪﾘｰ･－･－)　ビット番号
////; 図柄２群

#define BIN_BB1     (0x01)	//EQU	00000001B	//; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
#define BIN_BB2     (0x02)	//EQU	00000010B	//; (福の神･福の神･福の神)
#define BIN_RB      (0x04)	//EQU	00000100B	//; (BAR･BAR･BAR)
//
#define BIN_BB		(0x03)	//EQU	00000011B
//							////; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)、(福の神･福の神･福の神)

#define BIN_BNSPT	(3)		//EQU	3		//; 図柄２群使用ビット数

//	合わせた物
//;	*************************************************
//;	*	図柄データ定義				*
//;	*************************************************

#define _PIC1	__PIC1[MACINE]
#define _PIC2	__PIC2[MACINE]

//; 図柄１群 
#define CHERRY	__CHERRY[MACINE]
#define FRUIT1	__FRUIT1[MACINE]
#define FRUIT2	__FRUIT2[MACINE]
#define REPLAY	__REPLAY[MACINE]
#define JAC		__JAC[MACINE]
#define FRUIT	__FRUIT[MACINE]
#define SRB	__SRB[MACINE]
#define BT_CHERRY __BT_CHERRY[MACINE]

//; 図柄２群 
#define BB1		__BB1[MACINE]
#define BB2		__BB2[MACINE]
#define RB1		__RB1[MACINE]
#define RB2		__RB2[MACINE]
#define BB		__BB[MACINE]
#define RB		__RB[MACINE]
#define BNSPT	__BNSPT[MACINE]


//	かっぱっぱ 
//;	*************************************************
//;	*	遊技状態定義				*
//;	*************************************************
//;
#define KAP__RP		(1)	//00000001B	//; 再遊技作動時
#define KAP_BT_RP	(0)				//; 再遊技作動時（ビット番号）
//
#define KAP__RB		(2)	//00000010B	//; 役物連続作動装置作動時
#define KAP_BT_RB	(1)				//; 役物連続作動装置作動時（ビット番号）
//
#define KAP__BB		(4)	//00000100B	; 役物連続作動増加装置作動時
#define KAP_BT_BB	(2)				//; 役物連続作動増加装置作動時（ビット番号）
//
#define KAP__BNS	(6)	//00000110B	; ボーナスゲーム
//
#define KAP__JAC	(2)	//00000010B	; 役物遊技時

//	びんびん 
//;	************************************************* 
//;	*	遊技状態定義				* 
//;	************************************************* 

#define BIN__RP		(1)	//00000001B	//; 再遊技作動時 
#define BIN_BT_RP	(0)				//; 再遊技作動時（ビット番号） 
 
#define BIN__RB		(2)	//00000010B	//; 役物連続作動装置作動時 
#define BIN_BT_RB	(1)				//; 役物連続作動装置作動時（ビット番号） 
 
#define BIN__BB		(4)	//00000100B	//; 役物連続作動増加装置作動時 
#define BIN_BT_BB	(2)				//; 役物連続作動増加装置作動時 
									//（ビット番号） 

#define BIN__BB1	(8)	//00001000B	//; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)入賞による 
									//;;役物連続作動増加装置作動時 
#define BIN_BT_BB1	(3)				//; (ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)入賞による 
									//;;役物連続作動増加装置作動時 
									//（ビット番号） 

#define BIN__BB2	(0x10)	//00010000B	//; (福の神･福の神･福の神)入賞による 
										//;;役物連続作動増加装置作動時 
#define BIN_BT_BB2	(4)					//; (福の神･福の神･福の神)入賞による 
										//;役物連続作動増加装置作動時（ビット番号)
#define BIN__BNS	(0x06)	//00000110B	//; ボーナスゲーム 
#define BIN__JAC	(2)		//00000010B	//; 役物遊技時 

//	合わせた物 
//;	************************************************* 
//;	*	遊技状態定義				* 
//;	************************************************* 
#define _RP		(1)
#define BT_RP	(0)
#define _RB		(2)
#define BT_RB	(1)
#define _BB		(4)
#define BT_BB	(2)
#define _BNS	(6)
#define _JAC	(2)
#define _BB1	(8)
#define BT_BB1	(3)
#define _BB2	(0x10)
#define BT_BB2	(4)




//	かっぱっぱ 
//;	*************************************************
//;	*	入賞回数・遊技回数定義			*
//;	*************************************************
//;
#define KAP_J_WIN			(8)		//; 役物連続作動装置作動時の役物入賞回数
#define KAP_J_MAX			(12)	//; 役物連続作動装置作動時の役物遊技回数
#define KAP_B_WIN			(3)		//; 役物連続作動増加装置作動時の
									//;;役物連続作動装置入賞回数
#define KAP_B_MAX			(30)	//; 役物連続作動増加装置作動時の
									//;;一般遊技回数

//	びんびん 
//;	************************************************* 
//;	*	入賞回数・遊技回数定義			* 
//;	************************************************* 
//; 
#define BIN_J_WIN	(8)		//; 役物連続作動装置作動時の役物入賞回数 
#define BIN_J_MAX	(12)		//; 役物連続作動装置作動時の役物遊技回数 
#define BIN_B_WIN	(3)		//; 役物連続作動増加装置作動時の 
							//;;役物連続作動装置入賞回数 
#define BIN_B_MAX	(30)		//; 役物連続作動増加装置作動時の 
							//;;一般遊技回数 
#define BIN_BBCHG	(6)		//; 役物連続作動増加装置作動時の効果音切り替え 
							//	回数 




//	かっぱっぱ
//;	*********************************************************
//;	*  	各種ランプ・効果音出力要求  番号定義		*
//;	*********************************************************
//;
//; （１）遊技待機時の出力要求
#define KAP_SET_SAVER		1
//
//; （２）役物連続作動増加装置入賞時の出力要求１(ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
#define KAP_SET_BBHIT1		2
//
//; （３）役物連続作動増加装置入賞時の出力要求２(かっぱ･かっぱ･かっぱ)
#define KAP_SET_BBHIT2		3
//
//; （４）役物連続作動増加装置作動時の出力要求
#define KAP_SET_BB			4
//
//; （５）役物連続作動増加装置作動終了時の出力要求
#define KAP_SET_BBEND		5
//
//; （６）役物連続作動装置作動時の出力要求
#define KAP_SET_RB			6
//
//; （７）役物連続作動装置作動終了時の出力要求
#define KAP_SET_RBEND		7
//
//; （８）再遊技作動時の出力要求
#define KAP_SET_REPLAY		8
//
//; （９）入賞期待時の出力要求
#define KAP_SET_WBLSTART		9
//
//; （１０）入賞期待終了時の出力要求
#define KAP_SET_WBLEND		10
//
//; （１１）遊技メダル投入時の出力要求
#define KAP_SET_INCO		11
//
//; （１２）回胴回転不可時の出力要求
#define KAP_SET_WAIT		12
//
//; （１３）回胴回転開始時の出力要求
#define KAP_SET_START		13
//
//; （１４）停止ボタン受付時の出力要求
#define KAP_SET_STOP		14
//
//; （１５）回胴停止時の出力要求
#define KAP_SET_R_STOP		15
//
//; （１６）入賞による遊技メダル払出し開始時の出力要求
#define KAP_SET_PAYSTART		16
//
//; （１７）入賞による遊技メダル払出し終了時の出力要求
#define KAP_SET_PAYEND		17
//
//; （１８）入賞による遊技メダル１枚払出し時の出力要求
#define KAP_SET_PAY		18
//
//; （１９）回胴回転停止時（点滅パターンａ）の出力要求
#define KAP_SET_R3_STOP1		19
//
//; （２０）回胴回転停止時（点滅パターンｂ）の出力要求
#define KAP_SET_R3_STOP2		20
//
//; （２１）回胴回転停止時（点滅パターンｃ）の出力要求
#define KAP_SET_R3_STOP3		21
//
//; （２２）遊技メダル払出エラー発生時の出力要求
#define KAP_SET_ALARM		22
//
//; （２３）遊技メダル払出エラー解除時の出力要求
#define KAP_SET_ACLEAR		23



//	ビンビン神様 
//;	*********************************************************
//;	*  	各種ランプ・効果音出力要求  番号定義		*
//;	*********************************************************
//;
//; （１）遊技メダル払出エラー発生時の出力要求
#define BIN_SET_ALARM	1
//
//; （２）(ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)入賞による役物連続作動増加装置作動時の出力要求
//;;      （役物連続作動増加装置作動時の一般遊技回数が残り７回の遊技終了まで）
#define BIN_SET_BB1		2
//
//; （３）(福の神･福の神･福の神)入賞による役物連続作動増加装置作動時の出力要求
//;;      （役物連続作動増加装置作動時の一般遊技回数が残り７回の遊技終了まで）
#define BIN_SET_BB2		3
//
//; （４）役物連続作動増加装置作動時の出力要求
//;;      （役物連続作動増加装置作動時の一般遊技回数が残り７回の遊技終了から
//;;       役物連続作動増加装置作動終了時まで）
#define BIN_SET_BB3		4
//
//; （５）役物連続作動装置作動時の出力要求
#define BIN_SET_RB		5
//
//; （６）入賞による遊技メダル払出し開始時の出力要求
#define BIN_SET_PAYSTART		6
//
//; （７）役物連続作動増加装置入賞時の出力要求１(ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
#define BIN_SET_BBHIT1		7
//
//; （８）役物連続作動増加装置入賞時の出力要求２(福の神･福の神･福の神)
#define BIN_SET_BBHIT2		8
//
//; （９）役物連続作動増加装置作動終了時の出力要求
#define BIN_SET_BBEND		9
//
//; （１０）役物連続作動装置作動終了時の出力要求
#define BIN_SET_RBEND		10
//
//; （１１）再遊技作動時の出力要求
#define BIN_SET_REPLAY		11
//
//; （１２）入賞期待時の出力要求１（入賞期待時の出力要求２～５以外の時）
#define BIN_SET_WBLSTART		12
//
//; （１３）入賞期待時の出力要求２
//;;（右回胴回転中の中央ライン(福の神･福の神)表示時）
#define BIN_SET_WBLSTART1		13
//
//; （１４）入賞期待時の出力要求３
//;;（左回胴チェリー否表示及び右回胴回転中の上段ライン(ｾﾌﾞﾝ･ｾﾌﾞﾝ)表示時）
#define BIN_SET_WBLSTART2		14
//
//; （１５）入賞期待時の出力要求４
//;;（右回胴回転中の上段ライン(福の神･福の神)表示時）
#define BIN_SET_WBLSTART3		15
//
//; （１６）入賞期待時の出力要求５
//;;（左回胴チェリー否表示及び右回胴回転中の下段ライン(BAR･BAR)表示時）
#define BIN_SET_WBLSTART4		16
//
//; （１７）入賞期待終了時の出力要求
#define BIN_SET_WBLEND		17
//
//; （１８）遊技メダル投入時の出力要求
#define BIN_SET_INCO		18
//
//; （１９）回胴回転不可時の出力要求
#define BIN_SET_WAIT		19
//
//; （２０）回胴回転開始時の出力要求
#define BIN_SET_START		20
//
//; （２１）停止ボタン受付時の出力要求
#define BIN_SET_STOP		21
//
//; （２２）回胴停止時の出力要求
#define BIN_SET_R_STOP		22
//
//; （２３）入賞による遊技メダル払出し終了時の出力要求
#define BIN_SET_PAYEND		23
//
//; （２４）入賞による遊技メダル１枚払出し時の出力要求
#define BIN_SET_PAY		24
//
//; （２５）遊技メダル払出エラー解除時の出力要求
#define BIN_SET_ACLEAR		25







#endif
