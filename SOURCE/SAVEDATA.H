#ifndef _SAVE_DATA_H_
#define _SAVE_DATA_H_

struct _LAMP_DATA{
	char	lamp;	//	ランプの種類 
	char	time;	//	表示時間 
	char	rpt;	//	リピート回数 
	char	point;	//	現在のポイント 
	short	light;	//	光ってるランプ位置 
//	char	*adrs;	// 停止位置決定用テーブル選択抽選用確率１テーブル  
};
typedef struct _LAMP_DATA LAMP_DATA;

// kawakami add 1/18 ↓ 
typedef	struct {
	short	dai_zero;	// zero_y 
	char	hawkd;		// hawkd_flag 
	char	sw_conf;	// sw_config 
	char	reel_sp;	// reel_speed 
	char	zoom_l;		// zoom_level 
	char	det_flg[3];	// detect_level_flg 
	signed char	haw_p[3];
}	SETTING_DATA;		// 9 bytes 
// kawakami add 1/18 ↑ 

//	トータルデータ
struct _SAVE_1{
	char	mono_flag;		// 音声出力フラグ	0: ステレオ 1:モノラル 
	char	vib_flag;		// バイブレーションスイッチ 
	char	volume;			// 音声出力量 0～255 
	char	pad_mode;		//	パッドの操作形態選択 ０～３ (０がデフォルト) 
	short	bb_best[2][10];
// kawakami add 1/18 ↓ 
	SETTING_DATA	copy_sav[6];
	// 0:k-unlock replay	1:k-detect setting	2:k-crosscounter
	// 3:k-hawkeye			4:b-unlock replay	5:b-hawkeye
// kawakami add 1/18 ↑ 
};
typedef struct _SAVE_1 SAVE1;

struct	_BONUS_DATA	{	// 実戦データ構造体 
	short	game_n;		// ゲーム番号 
	short	money;		// 投資金額 
	char	item;		// 役 
};
typedef	struct	_BONUS_DATA	BONUS_DATA;

#define mono_flag	tot.mono_flag
#define vib_flag	tot.vib_flag
#define volume		tot.volume
#define pad_mode	tot.pad_mode
#define bb_best		tot.bb_best
#define	copy_sav	tot.copy_sav	// kawakami add 1/18 


struct _SAVE_2{
//; 設定値 
char _NB_RANK;		//	DEFS	1	; 設定値データ（１－６） 
short _NB_RANKB;		//	DEFS	1	; 設定値データ（０｜１） 

//; 遊技状態
char _FL_GAME_STS;	//	DEFS	1	; 遊技状態フラグ 
char IN_PORT[6];	//EQU	080H		; 入力ポート　０ 
char OUT_PORT[8];	//EQU	080H		; 出力ポート　０ 
char SOUND_PORT;	//EQU	0FF18H		; 効果音番号　出力ポート 

//	ORG	8000H
//; 入力データ 
char	_PT_IN0_OLD	;	//DEFS	1	; 入力ポート０レベルデータ 
char	_PT_IN0_UP	;	//DEFS	1	; 入力ポート０立ち上がりデータ 
char	_PT_IN0_DOWN;	//DEFS	1	; 入力ポート０立ち下がりデータ 
char	_PT_IN1_OLD	;	//DEFS	1	; 入力ポート１レベルデータ 
char	_PT_IN1_UP	;	//DEFS	1	; 入力ポート１立ち上がりデータ 
char	_PT_IN2_OLD	;	//DEFS	1	; 入力ポート２レベルデータ 
char	_PT_IN2_UP	;	//DEFS	1	; 入力ポート２立ち上がりデータ 

//; 表示 
char	_FL_LED_CHANGE;		//DEFS	1	; 表示切替えフラグ 
char	_NB_COUNT_LED1;		//DEFS	1	; 回数表示データ１ 
char	_NB_COUNT_LED2;		//DEFS	1	; 回数表示データ２ 
char	_NB_CREDIT_LED;		//DEFS	1	; 遊技メダル貯留枚数表示データ 
//	0x800D 
char	_NB_PAY_LED;		//DEFS	1	; 遊技メダル払出し枚数表示データ 
LAMP_DATA	_WK_FLASH_LP;	//DEFS	5	; 上部ランプ制御データ 
LAMP_DATA	_WK_EFFECT_LP;	//DEFS	5	; 効果ランプ制御データ 
LAMP_DATA	_WK_BACK_LP;	//DEFS	5	; バックランプ制御データ 
char	_FL_WBL;			//DEFS	1	; 入賞期待表示フラグ 
char	_FL_STOP_LP;		//DEFS	1	; 回胴停止フラグ 
char	_WK_WIN_LP;			//DEFS	1	; 入賞時有効ラインランプ点滅データ 
short	_WK_WINBACK_LP[2];	//DEFS	2	; 入賞時バックランプ点滅データ 

//	21
short	_PT_OUT[9];	//DEFS	1		; 出力ポート０データ

//	30 
//; ２バイトタイマ 
short	TM2_NUM[5];		//; ２バイトタイマ数
//	40 
//; １バイトタイマ 
char	TM1_NUM[9];		//; １バイトタイマ数

//; 回胴 
//	50 
char	_WK_REEL[3][8];	//DEFS	8		; 全回胴制御データ

//; 遊技メダルカウンタ 
char	_CT_MEDAL[2];		//DEFS	1		; 遊技メダル投入信号出力回数

//; 遊技メダル枚数 
//	76 
char	_NB_PLAY_MEDAL;	//DEFS	1		; 遊技メダル枚数データ
char	_NB_PAY_MEDAL;		//DEFS	1		; 遊技メダル払出し枚数データ
char	_NB_REP_MEDAL;		//DEFS	1		; 自動投入遊技メダル枚数データ


//; 電断 
//short	_WK_SUM_CHK;	//DEFS	1		; ＲＡＭチェックサムデータ
//short	_BF_STACK[2];	//DEFS	2		; スタックポインタ一時保存バッファ

//; 入賞・作動フラグ
char	_FL_WIN;		//DEFS	1		; 入賞フラグ
char	_FL_ACTION;		//DEFS	1		; 作動フラグ

//; 抽選 
//	84 
char	_CT_IN_OUT[2];	//DEFS	2		; 差枚数カウンタ

//	0x8062
u_short	_BF_RAND1;	//DEFS	2		; 一般遊技図柄抽選用乱数保存バッファ
u_short	_BF_RAND2;	//DEFS	2		; 役物遊技図柄抽選用乱数保存バッファ

//	90 
char	_FL_PIC[6];

char _NB_SSPRD[5];
//#define _NB_SSPRD kbr._NB_SSPRD
//#define	_NB_STOP_ORDER	_NB_SSPRD[0]	//DEFS	1		; 回胴停止順番データ 
//#define	_NB_STOP_REEL	_NB_SSPRD[1]	//DEFS	1		; 停止回胴番号データ 
//#define	_BF_PICTURE		_NB_SSPRD[2]	//DEFS	1		; 回胴停止受付時図柄番号保存用バッファ 
//#define	_NB_REJECT		_NB_SSPRD[3]	//DEFS	1		; 蹴飛ばしコマ数データ 
//#define	_FL_STOP_PNT	_NB_SSPRD[4]	//DEFS	1		; 停止可能位置フラグ 


//	99
char	_WK_REEL_PIC1[7];	//DEFS	7		; 回胴図柄データ１（７図柄分）
char	_WK_REEL_PIC2[7];	//DEFS	7		; 回胴図柄データ２（７図柄分）

char	_WK_ALL_PIC1;		//DEFS	1		; 停止図柄データ１（全有効ライン）
char	_WK_ALL_PIC2;		//DEFS	1		; 停止図柄データ２（全有効ライン）
char	_WK_STOP_PIC1[5];	//DEFS	5		; 停止図柄データ１（各有効ライン）
char	_WK_STOP_PIC2[5];	//DEFS	5		; 停止図柄データ２（各有効ライン）


//char	_BF_STOP_CTL;	//DEFS	2	; 停止位置決定用テーブル保存用バッファ
char	*_BF_STOP_CTL;	//DEFS	2	; 停止位置決定用テーブル保存用バッファ


//; 役物連続作動装置及び役物連続作動増加装置用カウンタ
char	_CT_BONUS_PLAY;	//DEFS	1	; 役物連続作動装置作動時の役物遊技回数
char	_CT_BONUS_WIN;	//DEFS	1	; 役物連続作動装置作動時の役物入賞回数
char	_CT_BIG_PLAY;	//DEFS	1	; 役物連続作動増加装置作動時の一般遊技回数
char	_CT_BIG_WIN;	//DEFS	1	; 役物連続作動増加装置作動時の
//									;;役物連続作動装置入賞回数
int gsound_;
char	torikoboshi;
char	nisemono;
short	bb_shot_coin;
char bonus_data_p;	// 実戦データへのポインタ
char au_te;
char au_se;
char au_sp;
short	zero_y;
char	zoom_level;
u_int	game_time;
int		out_coin_nrb;		// 総払い出し枚数 *
short bb_toushi_coin;
short bb_rb_getget;
char ototoka;
char bb_ima;
char rb_ima;
char bb_imaowatta;
char muriyari_ateru;
char pikapika;

// 川上さん用 // 川上さん用 // 川上さん用 // 川上さん用 // 川上さん用 //
short	thousand_num;	// 千円単位の区切り数 
short	next_thousand;	// 次の千円当りプレイ数算出のトリガライン 

int		bb_gc_last_t;	// 実戦値で使うbb中ゲットコインのトータル 
int		bb_tc_last_t;	// 理論値で使うbb中投資コインのトータル 
int		rb_tc_t;		// ＲＢ中投資コイントータル 

short	p_per_t_ir;		// 千円当りのプレイ数（リプレイ込み） 
short	p_per_t_nr;		// 千円当りのプレイ数（リプレイぬき） 

char	mode_game;		// ゲームモード0:攻略　1:リプレイはずし～ 
char	machine_no;		// 機械番号	0:かっぱ 
//char	bingo_rate;		// 確率設定 0～5 6:ユーザ設定
int		user_rate[2];	// ユーザ設定 [0]BB用[1]RB用 10～999 
short	use_money;		// 投資金額（単位：千円） 
short	bruse_money;		// 投資金額（単位：千円） 
u_short	hand_medal;		// 手持ちメダル枚数 *
//char	in_medal;		// 機械内のストックメダル枚数（上限：５０枚） 

char	sw_config;		// コンフィグフラグ
/*				下位から	4.1ウェイト、成立フラグ表示、リーチ目ランプ表示
							取りこぼしコメント表示、台情報表示、ミニリール表示
							滑りコマ数表示、インフォメーションウィドウ表示	*/
char	reel_speed;		// リールスピード	0～4 * 
char	auto_cfg;		// オートプレイ設定 

char	auto_on;		// オートプレイ中？ 
char	auto_point;		// オートプレイの実行地点 
char	bingo_flag;		// 当たりフラグ 
char	play_mode;		/* パチスロのゲームモード	0:通常
													1:ＢＢＪＡＣ以外
													2:ＪＡＣ        */
char	st_back[7][50];
char	st_back_p;
int		play_num;		// プレイ回数 *
int		use_coin;		// 総コイン投入枚数 * 
int		out_coin;		// 総払い出し枚数 *
short	bingo_n_bb;		// ＢＩＧ回数 *
short	bingo_n_rb;		// ＲＥＧ回数 *
char	bb_firstend;	// １度目のＢＢが終わったか 

short	bb_getcoin_max;	// ＢＢベストゲット *
short	bb_getcoin_min;	// ＢＢワーストゲット *
short	bb_getcoin_last;// 前回のＢＩＧゲット枚数 
int		bb_getcoin_total;//ＢＢトータルゲット*
int		brb_total_toushi;// ＢＢ／ＲＢ中のトータル賭けコイン 
short	bonus_interval[4][3];//ボーナス間インターバルプレイ数 *
/*					第一添字：	0-Ｂ→Ｂ	1-Ｂ→Ｒ	2-Ｒ→Ｂ	3:Ｒ→Ｒ
					第二添字：	0-最小	1-最大	2-カウント用*/
short	aft_play_brb;	// 前回のＢＢもしくはＲＢからのプレイ数 *
short	aft_play_bb;	// 前回のＢＢからのプレイ数 *
short	aft_play_rb;	// 前回のＲＢからのプレイ数 *

short	replay_num;		// 総リプレイ回数 *

BONUS_DATA	bonus_data[10];	// 実戦データ 
signed	char	medal_wave[200];	// グラフの高さデータ 
int			wave_buf[50];		// グラフデータのバッファ 
int			wave_max;			// wave_bufのプレイ開始からの最大絶対値 
char		grp_xp;				// medal_waveのどこを使用するか指すか 
char		wavebuf_p;			// バッファのどこを使うかのポインタ 
char		bufp_max;			// x-fsに基くバッファ使用数 
//short		grp_x_fs;
int			grp_y_fs;

short	playnum_rate[3];// プレイ回数［低／高／ＢＢ］ *
short	bingo_poll[3][4];// 子役フラグ成立数 [率][役] *

short	big_koyakup_last[4];	// 前回ＢＩＧ終了時までののＢＩＧ中小役成立数 
short	big_koyakug_last[4];	// 前回ＢＩＧ終了時までののＢＩＧ中小役取得数 

/*	率：	0-低確立中	1-高確率中	2-ＢＩＧ中
	役：	0-15枚もの	1-10or8枚	2-第一回胴もの	3-再遊戯
*/
short	bingo_get[3][4];// 子役ゲット数 [率][役] *
short	bonusin_total;	// 累積ボーナスゲームプレイ数 * 
char	bonusin_max;	// 最大ボーナスゲームプレイ数 * 
char	bonusin_min;	// 最小ボーナスゲームプレイ数 * 
char	bonusin_shot;	// １回のボーナスゲームプレイ数 * 

int		battle_data[2];		// 実戦値／理論値 

short	ranking[2][10];		// BIGボーナス獲得枚数ランキング[機種][順位] 

char	reach_me;			// ボーナスフラグ	0:ＢＩＧ1:ＲＥＧ2:なし 
char	ouch_flag;			// ちゃんと抽選するフラグ ;
char	never_bingo_flag;	// 絶対当選しないフラグ 

char	hawkd_flag;			// 目押しランプ表示スイッチ(bit) 
signed	char	hawk_pos[3];		// 目押しランプ位置 

char	rate_rndcst;

SETTING_DATA	settei_data;	// 設定データ 

};
typedef struct _SAVE_2 SAVE2;

SAVE1 tot;	//	トータルセーブデータ 
SAVE2 kbr;
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#define _NB_RANK kbr._NB_RANK	//	DEFS	1	; 設定値データ（１－６）
#define _NB_RANKB kbr._NB_RANKB	//	DEFS	1	; 設定値データ（１－６）
#define  _FL_GAME_STS  kbr._FL_GAME_STS	//	DEFS	1	; 遊技状態フラグ

#define IN_PORT		kbr.IN_PORT	//EQU	080H		; 入力ポート　０ 
#define IN0_PORT	IN_PORT[0]	//EQU	080H		; 入力ポート　０ 
#define IN1_PORT	IN_PORT[1]	//EQU	081H		; 入力ポート　１ 
#define IN2_PORT	IN_PORT[2]	//EQU	082H		; 入力ポート　２ 
#define IN3_PORT	IN_PORT[3]	//EQU	083H		; 入力ポート　３ 

#define OUT_PORT	kbr.OUT_PORT	//EQU	080H		; 出力ポート　０ 
#define OUT0_PORT	OUT_PORT[0]	//EQU	080H		; 出力ポート　０ 
#define OUT1_PORT	OUT_PORT[1]	//EQU	081H		; 出力ポート　１ 
#define OUT2_PORT	OUT_PORT[2]	//EQU	082H		; 出力ポート　２ 
#define OUT3_PORT	OUT_PORT[3]	//EQU	083H		; 出力ポート　３ 
#define OUT4_PORT	OUT_PORT[4]	//EQU	084H		; 出力ポート　４ 
#define OUT5_PORT	OUT_PORT[5]	//EQU	085H		; 出力ポート　５ 
#define OUT6_PORT	OUT_PORT[6]	//EQU	086H		; 出力ポート　６ 
#define OUT7_PORT	OUT_PORT[7]	//EQU	087H		; 出力ポート　７ 
#define OUT8_PORT	OUT_PORT[8]	//EQU	088H		; 出力ポート　８ 
#define SOUND_PORT	kbr.SOUND_PORT	//EQU	0FF18H		; 効果音番号　出力ポート 



#define	_PT_IN0_OLD	 kbr._PT_IN0_OLD	//DEFS	1	; 入力ポート０レベルデータ
#define	_PT_IN0_UP	 kbr._PT_IN0_UP		//DEFS	1	; 入力ポート０立ち上がりデータ
#define	_PT_IN0_DOWN kbr._PT_IN0_DOWN	//DEFS	1	; 入力ポート０立ち下がりデータ
#define	_PT_IN1_OLD	 kbr._PT_IN1_OLD	//DEFS	1	; 入力ポート１レベルデータ
#define	_PT_IN1_UP	 kbr._PT_IN1_UP		//DEFS	1	; 入力ポート１立ち上がりデータ
#define	_PT_IN2_OLD	 kbr._PT_IN2_OLD	//DEFS	1	; 入力ポート２レベルデータ
#define	_PT_IN2_UP	 kbr._PT_IN2_UP		//DEFS	1	; 入力ポート２立ち上がりデータ

#define _FL_LED_CHANGE	kbr._FL_LED_CHANGE	//DEFS	1		; 表示切替えフラグ
#define TM2_NUM			kbr.TM2_NUM		//; ２バイトタイマ数
#define	_TM2_AUTOSTOP	TM2_NUM[0]	//DEFS	2	; 回胴自動停止時間 
#define	_TM2_HE_CHK		TM2_NUM[1]	//DEFS	2	; 遊技メダル払出装置作動時間 
#define	_TM2_REPLAY_ML	TM2_NUM[2]	//DEFS	2	; 遊技メダル自動投入待機時間 
#define	_TM2_GAME		TM2_NUM[3]	//DEFS	2	; 最短遊技時間 
#define	_TM2_BACK_OFF	TM2_NUM[4]	//DEFS	2	; 遊技待機時の表示待機時間 
 


#define	_TM1_NUM	9		//; １バイトタイマ数
#define	TM1_NUM kbr.TM1_NUM		//; １バイトタイマ数
#define	_TM1_BET_ML		TM1_NUM[0]	//DEFS	1	; 遊技メダル投入待機時間
#define	_TM1_OUT_CNT	TM1_NUM[1]	//DEFS	1	; 外部信号出力時間
#define	_TM1_STOP		TM1_NUM[2]	//DEFS	1	; 回胴停止受付待機時間
#define	_TM1_CREDIT		TM1_NUM[3]	//DEFS	1	; 遊技メダル貯留枚数加算待機時間
#define	_TM1_PAY		TM1_NUM[4]	//DEFS	1	; 遊技メダル払出センサーチェック時間
#define	_TM1_WIN_LP		TM1_NUM[5]	//DEFS	1	; 入賞ライン点滅時間
#define	_TM1_RESET		TM1_NUM[6]	//DEFS	1	; 外部打止め解除信号入力時間
#define	_TM1_MEDAL1		TM1_NUM[7]	//DEFS	1	; 遊技メダル投入センサー１通過チェック時間
#define	_TM1_MEDAL2		TM1_NUM[8]	//DEFS	1	; 遊技メダル投入センサー２通過チェック時間

#define _CT_MEDAL		kbr._CT_MEDAL		//DEFS	1		; 遊技メダル投入信号出力回数
#define	_CT_MEDAL_IN	_CT_MEDAL[0]	//DEFS	1		; 遊技メダル投入信号出力回数
#define	_CT_MEDAL_OUT	_CT_MEDAL[1]	//DEFS	1		; 遊技メダル払出信号出力回数

#define _NB_PLAY_MEDAL	kbr._NB_PLAY_MEDAL	//DEFS	1		; 遊技メダル枚数データ
#define _NB_PAY_MEDAL	kbr._NB_PAY_MEDAL	//DEFS	1		; 遊技メダル払出し枚数データ
#define _NB_REP_MEDAL	kbr._NB_REP_MEDAL	//DEFS	1		; 自動投入遊技メダル枚数データ

#define _WK_SUM_CHK	kbr._WK_SUM_CHK

#define	_FL_WIN kbr._FL_WIN		//DEFS	1		; 入賞フラグ
#define	_FL_ACTION kbr._FL_ACTION		//DEFS	1		; 作動フラグ
#define _CT_IN_OUT	kbr._CT_IN_OUT	//DEFS	2		; 差枚数カウンタ

#define	_BF_RAND1	kbr._BF_RAND1	//DEFS	2		; 一般遊技図柄抽選用乱数保存バッファ
#define	_BF_RAND2	kbr._BF_RAND2	//DEFS	2		; 役物遊技図柄抽選用乱数保存バッファ


#define	_WK_REEL		kbr._WK_REEL	//DEFS	8		; 全回胴制御データ  

#define	_NB_COUNT_LED1	kbr._NB_COUNT_LED1	//DEFS	1	; 回数表示データ１  
#define	_NB_COUNT_LED2	kbr._NB_COUNT_LED2	//DEFS	1	; 回数表示データ２  
#define	_NB_CREDIT_LED	kbr._NB_CREDIT_LED	//DEFS	1	; 遊技メダル貯留枚数表示データ  
#define	_NB_PAY_LED		kbr._NB_PAY_LED		//DEFS	1	; 遊技メダル払出し枚数表示データ  

#define _WK_FLASH_LP	kbr._WK_FLASH_LP	//DEFS	5	; 上部ランプ制御データ  
#define _WK_EFFECT_LP	kbr._WK_EFFECT_LP	//DEFS	5	; 効果ランプ制御データ  
#define _WK_BACK_LP		kbr._WK_BACK_LP		//DEFS	5	; バックランプ制御データ  

#define _FL_WBL			kbr._FL_WBL	//DEFS	1	; 入賞期待表示フラグ  
#define _FL_STOP_LP		kbr._FL_STOP_LP	//DEFS	1	; 回胴停止フラグ  
#define _WK_WIN_LP		kbr._WK_WIN_LP		//DEFS	1	; 入賞時有効ラインランプ点滅データ  
#define _WK_WINBACK_LP	kbr._WK_WINBACK_LP	//DEFS	2	; 入賞時バックランプ点滅データ  

#define	_PT_OUT		kbr._PT_OUT		//DEFS	1		; 出力ポート０データ 
#define	_PT_OUT0	_PT_OUT[0]	//DEFS	1		; 出力ポート０データ 
#define	_PT_OUT1	_PT_OUT[1]	//DEFS	1		; 出力ポート１データ 
#define	_PT_OUT2	_PT_OUT[2]	//DEFS	1		; 出力ポート２データ 
#define	_PT_OUT3	_PT_OUT[3]	//DEFS	1		; 出力ポート３データ 
#define	_PT_OUT4	_PT_OUT[4]	//DEFS	1		; 出力ポート４データ 
#define	_PT_OUT5	_PT_OUT[5]	//DEFS	1		; 出力ポート５データ 
#define	_PT_OUT6	_PT_OUT[6]	//DEFS	1		; 出力ポート６データ 
#define	_PT_OUT7	_PT_OUT[7]	//DEFS	1		; 出力ポート７データ 
#define	_PT_OUT8	_PT_OUT[8]	//DEFS	1		; 出力ポート８データ 


#define _NB_SSPRD kbr._NB_SSPRD
#define	_NB_STOP_ORDER	_NB_SSPRD[0]	//DEFS	1		; 回胴停止順番データ
#define	_NB_STOP_REEL	_NB_SSPRD[1]	//DEFS	1		; 停止回胴番号データ
#define	_BF_PICTURE		_NB_SSPRD[2]	//DEFS	1		; 回胴停止受付時図柄番号保存用バッファ
#define	_NB_REJECT		_NB_SSPRD[3]	//DEFS	1		; 蹴飛ばしコマ数データ
#define	_FL_STOP_PNT	_NB_SSPRD[4]	//DEFS	1		; 停止可能位置フラグ

#define _BF_STOP_CTL	kbr._BF_STOP_CTL
#define 	_CT_BONUS_PLAY	kbr._CT_BONUS_PLAY
#define 	_CT_BONUS_WIN	kbr._CT_BONUS_WIN
#define 	_CT_BIG_PLAY	kbr._CT_BIG_PLAY
#define 	_CT_BIG_WIN		kbr._CT_BIG_WIN

#define _WK_REEL_PIC1 kbr._WK_REEL_PIC1	//DEFS	7	; 回胴図柄データ１（７図柄分）
#define _WK_REEL_PIC2 kbr._WK_REEL_PIC2	//DEFS	7	; 回胴図柄データ２（７図柄分）

#define	_WK_ALL_PIC1 kbr._WK_ALL_PIC1	//DEFS	1	; 停止図柄データ１（全有効ライン）
#define _WK_ALL_PIC2 kbr._WK_ALL_PIC2	//DEFS	1	; 停止図柄データ２（全有効ライン）
#define _WK_STOP_PIC1 kbr._WK_STOP_PIC1	//DEFS	5	; 停止図柄データ１（各有効ライン）
#define _WK_STOP_PIC2 kbr._WK_STOP_PIC2	//DEFS	5	; 停止図柄データ２（各有効ライン）

///////////////////////////////////////////////////////////////////////////
#define	_FL_PIC kbr._FL_PIC
#define	_FL_PUL_PIC1	_FL_PIC[0]	//DEFS	1 		; 引込み図柄データ１
#define	_FL_REJ_PIC1	_FL_PIC[1]	//DEFS	1 		; 蹴飛ばし図柄データ１
#define	_FL_PUL_PIC2	_FL_PIC[2]	//DEFS	1 		; 引込み図柄データ２
#define	_FL_REJ_PIC2	_FL_PIC[3]	//DEFS	1 		; 蹴飛ばし図柄データ２
#define	_FL_PUL_PIC1_	_FL_PIC[4]	//DEFS	1 		; 引込み図柄データ１
#define	_FL_REJ_PIC1_	_FL_PIC[5]	//DEFS	1 		; 蹴飛ばし図柄データ１

#define	gsound_		kbr.gsound_
#define	torikoboshi		kbr.torikoboshi
#define	bb_shot_coin	kbr.bb_shot_coin
#define	nisemono	kbr.nisemono
#define  bonus_data_p kbr.bonus_data_p
#define  au_te kbr.au_te
#define  au_se kbr.au_se
#define  au_sp kbr.au_sp
#define  st_back kbr.st_back
#define  st_back_p kbr.st_back_p
#define  zero_y kbr.zero_y
#define  zoom_level kbr.zoom_level
#define  game_time kbr.game_time
#define  out_coin_nrb kbr.out_coin_nrb
#define bb_toushi_coin		kbr.bb_toushi_coin
#define bb_rb_getget		kbr.bb_rb_getget
#define ototoka		kbr.ototoka
#define bb_ima		kbr.bb_ima
#define rb_ima		kbr.rb_ima
#define bb_imaowatta	kbr.bb_imaowatta
#define muriyari_ateru	kbr.muriyari_ateru
#define pikapika	kbr.pikapika

//	川上さん用

#define	thousand_num		kbr.thousand_num
#define	next_thousand		kbr.next_thousand
#define	p_per_t_ir			kbr.p_per_t_ir
#define	p_per_t_nr			kbr.p_per_t_nr

#define	mode_game			kbr.mode_game
#define	machine_no			kbr.machine_no
#define	bingo_rate			_NB_RANK
#define	user_rate			kbr.user_rate
#define	bruse_money			kbr.bruse_money
#define	use_money			kbr.use_money
#define	hand_medal			kbr.hand_medal
//#define	in_medal			_NB_CREDIT_LED
#define	sw_config			kbr.sw_config
#define	reel_speed			kbr.reel_speed
#define	auto_cfg			kbr.auto_cfg
#define	auto_point			kbr.auto_point
#define	auto_on				kbr.auto_on
#define	bingo_flag			kbr.bingo_flag
#define	play_mode			kbr.play_mode
#define	play_num			kbr.play_num
#define	use_coin			kbr.use_coin
#define	out_coin			kbr.out_coin
#define	bingo_n_bb			kbr.bingo_n_bb
#define	bingo_n_rb			kbr.bingo_n_rb
#define	bb_getcoin_max		kbr.bb_getcoin_max
#define	bb_getcoin_min		kbr.bb_getcoin_min
#define	bb_getcoin_last		kbr.bb_getcoin_last
#define	bb_getcoin_total	kbr.bb_getcoin_total
#define	bonus_interval		kbr.bonus_interval
#define	aft_play_brb		kbr.aft_play_brb
#define	aft_play_bb			kbr.aft_play_bb
#define	aft_play_rb			kbr.aft_play_rb
#define	replay_num			kbr.replay_num

#define	bonus_data			kbr.bonus_data
#define	medal_wave			kbr.medal_wave
#define	wave_max			kbr.wave_max

#define	playnum_rate		kbr.playnum_rate
#define	bingo_poll          kbr.bingo_poll
#define	bingo_get           kbr.bingo_get
#define	bonusin_total       kbr.bonusin_total
#define	bonusin_max         kbr.bonusin_max
#define	bonusin_min         kbr.bonusin_min
#define	bonusin_shot        kbr.bonusin_shot
#define	battle_data			kbr.battle_data

#define	wave_buf			kbr.wave_buf
#define	wave_max			kbr.wave_max
#define	grp_xp				kbr.grp_xp
#define	wavebuf_p			kbr.wavebuf_p
#define	bufp_max			kbr.bufp_max
#define	grp_x_fs			kbr.grp_x_fs
#define	grp_y_fs			kbr.grp_y_fs

#define	reach_me			kbr.reach_me
#define	graph_data			kbr.graph_data
#define	ouch_flag			kbr.ouch_flag

#define	ranking				kbr.ranking
#define	never_bingo_flag	kbr.never_bingo_flag

#define	MACINE	machine_no
#define	hawkd_flag			kbr.hawkd_flag
#define	hawk_pos			kbr.hawk_pos

#define	bb_gc_last_t		kbr.bb_gc_last_t
#define	bb_tc_last_t		kbr.bb_tc_last_t
#define	rb_tc_t				kbr.rb_tc_t
#define	big_koyakup_last	kbr.big_koyakup_last
#define	big_koyakug_last	kbr.big_koyakug_last

#define	settei_data			kbr.settei_data
#define	rate_rndcst			kbr.rate_rndcst
#define	bb_firstend			kbr.bb_firstend

#endif

