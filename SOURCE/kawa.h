#ifndef _KAWA_H_
#define _KAWA_H_

// hawk.c 
extern	char	start_flag;	// 自動スタートフラグ 

// toggles.c 
extern	signed	char	yn_sts;		// -1:スリープ0:選択中1:はい2:いいえ
extern			char	hawk_setting;	// 目押しランプ設定中 
extern	signed	char	mr_light[3][21];	// ミニリール光るの 
extern	void	set_mesp_val(int, int, int);
extern	signed	char	mesp_sts;	// -1:スリープ0:稼動中
// ドラムコロコロ用 
typedef struct {
	char	req;
	char	drum_no;
	char	item_no;
	char	direc;
} ROLL_DRUM;
extern	ROLL_DRUM	r_drum;


// flash.c 
extern	char	flash_no;		// フラッシュ番号 

// detect.c 
extern	short	det_val[3][3];	// [次から三つ][プレイ数／払出し枚数] 
extern	void	call_detect_result(void);
extern	char	result_call;

// unlock.c
extern	char	rankin_no;		// ランキング順位 0~9：順位 それ以上：ランク外 

// cross.c 
/*
short	bingo_poll[3][4];// 子役フラグ成立数 [率][役] *
/*	率：	0-低確立中	1-高確率中	2-ＢＩＧ中
	役：	0-15枚もの	1-10or8枚	2-第一回胴もの	3-再遊戯
*/
//short	bingo_get[3][4];// 子役ゲット数 [率][役] *
extern	short	cross_poll[4];
extern	short	cross_get[4];
extern	short	playnum_cross;	// プレイ回数［］ *
extern	short	replaynum_cross;
extern	short	det_play_num;	// 設定判別モードでの判別プレイ数 
extern	short	out_koya_coin;	// 設定判別モードでの小役総払出し枚数 
extern	short	detplay_get_num;// 判別プレイでの小役獲得回数 

// title.c 
void	t_option(WINDOW *);
extern	char	quitflag;
extern	char	retryflag;

// submenu.c 
short	submenu_drv(void);	// メニューパネルドライバ 
void	init_kawas(int);	// 川上側の変数初期化等 
void	make_setting_data(SETTING_DATA *);		// 設定セーブ用データ作成 
void	restore_setting_data(SETTING_DATA *);	// 設定セーブ用データ展開 
void	retry_initial(void);	// やり直し用イニシャライズ 

extern	WINDOW	*mesp_p;	// メッセージパネル用 
typedef	struct	{
	short	u,v;
	short	u0, v0;
	short	tw, th;
	short	cx, cy;
	short	mode;
	short	page;
	short	rate;
}	TEX_INF;
//	ポリの常習メンバ	
typedef	struct {
	TEX_INF		tp;
	POLY_FT4	*pp;
	short		x, y;
	short		w, h;
	short		r,g,b;
}	POL_MEMB;
//	指カーソル	
typedef	struct {
	POL_MEMB	pm;
	short		dx, dy;	// 目的地 
	short		vx, vy;	// 速度 
}	F_CUR;
typedef	struct	{
	F_CUR		fcur;
	SPRITE_OBJECT	*lrcur;
	int			work[8];
	short		step;
	signed char	titleF;
	signed char	exitF;
	signed char	loadF;
	signed char	cp_fir;			// サブメニューＣＰ 
	signed char	cp_ddw;			// データ表示ウィンドウＣＰ 
	signed char	cp_cfg;			// コンフィグＣＰ 
	signed char	cp_aut;			// オート設定ＣＰ 
	signed char	cp_flg;			// フラグ設定ＣＰ 
	signed char	cp_opt;			// オプションＣＰ 
	signed char	cp_mem;			//  
	char		cp_sts;			// ステータスウィンドウ番号 
	char		cur_win;		// カレントウィンドウ 
	char		sethawk;		// 目押しランプ設定中フラグ 
	signed char	cash_rate;		// 換金率×１０ 
}	SUBMENU;
extern	SUBMENU	*swp;		// サブメニュー総合データワーク 


extern	char	push_type;

#endif
