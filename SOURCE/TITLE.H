/*===================================================
	select.h
	
	ＴＥＮ	パチスロコレクション
	タイトル関連のヘッダ
	
						作ってる人		T. Kawakami
						作り出した日	19th Nov. '98
====================================================*/
#ifndef	_TITLE_H
#define	_TITLE_H

#define FNT_W	16
#define FNT_H	16

#define	NUMS_U	676
#define	NUMS_V	16

#define	OX	-160
#define	OY	-120

#define	SHADE_W		0x50
#define	SHADE_L		(0x80 - SHADE_W)

#define	MOVE_SYNC		1	//	各種項目移動シンク数	
#define	CHG_SYNC		10	//	項目縦切り替りシンク数	
#define	H_CHG_SYNC		4	//	項目横切り替りシンク数	

#define	KAPP	0
#define	KAMI	1

#define	MACHINE_MAX		2	/*	機種数	*/
#define	RMODE_MAX		8	/*	確率設定モード数	*/
#define	GMODE_MAX		8	/*	プレイモード数	*/

#define	PLAY_MAX 	10000	// 最大プレイ数 

extern	char	fade_cur;

enum B_COLS {	//	ボタンカラーパレット	
	B_RED, B_GREEN, B_BLUE, B_PINK,
};
enum COLORS {	//	文字カラーパレット	
	C_WHITE,
	C_RED,
	C_BLUE,
	C_YELLOW,
	C_GRAY,
	C_GREEN,
};

/*	ゲームモード定義	*/
enum GMODE {
	MODE_NORM,		/*	攻略プレイ	*/
	MODE_UNLOCK,	/*	リプレイはずし	*/
	MODE_CHECK,		/*	設定判別	*/
	MODE_CROSS,		/*	クロスカウンター	*/
	MODE_REACH,		/*	リーチ目研究	*/
	MODE_HAWKEYE,	/*	目押し練習	*/
	MODE_SOUND,		/*	サウンドミュージアム	*/
	MODE_FLASH,		/*	フラッシュミュージアム	*/
	MODE_MAX,
};

/*	TIMファイル関連	*/
enum F_N {
	F_LOGO_KAMI,	//	かみさまロゴ 	
	F_MAC_KAMI,	//	かみさま台 	
	F_LOGO_D,	//	複合ロゴ 	
	F_LOGO_KAPP,	//	かっぱロゴ 	
	F_MAC_KAPP,	//	かっぱ台 	
	F_STR_LOAD,	//	ローディング 	
	
	F_CLOUD1,	//	雲１ 	
	F_CLOUD2,	//	雲２ 	
	F_CLOUD3,	//	雲３ 	
	F_CLOUD4,	//	雲４ 	
	F_CLOUD5,	//	雲５	
	F_STR_MES_L,	//	メッセージ長い方	
	F_STR_NUM,	//	数字	
	F_STR_SOU,	//	サウンド用文字	
	F_STR_MOD,	//	モードメニュー	
	F_STR_MES_S,	//	メッセージ短い方	
	F_STR_RAT_V,	//	レート縦	
	F_STR_RAT_H,	//	レート横	
	F_STR_HELP,	//	サウンド横	
	F_BRD_MOD_L,	//	モード枠	
	F_BRD_MOD_H,	//	メッセージ枠	
	F_CUR_V,	//	縦カーソル	
	F_CUR_H,	//	横カーソル	
	F_CUR_T,	//	Tカーソル	
	F_CUR_F,	//	指	
	F_BUTT,	//	ボタン	
	F_BGM_NAME,	//	ＢＧＭ名前	
	F_SE_NAME,	//	ＳＥ名前	
	F_RESET,	// リセット／ランダム 
	F_CHKTYPE,	// 設定判別タイプ 
	
	F_TITLE_ITEM,	// タイトルメニュー文字列 
	
	TIM_F_MAX,
};

#define	F_ZERO	F_SELECT	// 川上が使用するファイルの先頭番号 
#define	F_MAX	F_SUBMENU	// 同末尾番号 


typedef	struct	{
	short	x, y;		/*	テクスチャ位置	*/
	short	w, h;		/*	テクスチャサイズ	*/
	short	cx, cy;		/*	CLUT位置	*/
	short	mode;		/*	色モード	*/
}	TIM_INF;

extern	short	bonus_rate[MACHINE_MAX][RMODE_MAX][2];
extern	TIM_INF	timinf[TIM_F_MAX];
typedef struct	{	//	枠の群体	
	POL_MEMB	frame[8];
}	FRAMES;

extern	POLY_FT4	*loading_p;

typedef struct {	// 目押しパネル設定用 
			char	tgl_bup;		// トグルスイッチバックアップ	
	signed	char	cur_drum;       // カレントドラム				
	signed	char	reel_bup[3];    // 初期リール位置				
	signed	char	cur_reel[3];    // カレントリール位置			
//			char	on_flg[3];		// 表示フラグ 
} HAWK_SET;




extern	void	set_8wvals(SPRITE_OBJECT **, int, int, int);
extern	void	titlepanel(WINDOW *);
extern	void	datasave(WINDOW *);
extern	void	p_ranking(WINDOW *);
extern	void	call_yn_panel(short, short);
extern	void	del_yn_panel(void);
extern	int		call_mes_panel(short, short, short);
extern	int		del_mes_panel(void);
extern	void	dispose_mes_win(void);
extern	void	dispose_yn_win(void);

char	detect_level_flg[3];	// 設定判別モード専用フラグ 
/*						[0]	ＢＩＧ抽選するしないフラグ 
						[1]	ＲＥＧ抽選するしないフラグ 
						[2]	設定判別表表示フラグ 
*/

void	keyconfig(WINDOW *);

enum {
	SM_NONE,
	P_FIRST,
	SM_SUBMENU,
	SM_MEDAL,
	SM_DDWIN,
	SM_HAWKEYE,
	SM_3D,
	SM_SETFLAG,
	SM_REVIEW,
	SM_AUTO,
	SM_CONFIG,
	SM_SAVE,
	SM_OPTION,
	SM_EXIT,
	SM_STS1,
	SM_STS2,
	SM_STS3,
	SM_K_CONF,
	SM_2START,
	HP_FIRST,
	HP_FLAG,
	HP_HAWK,
	HP_CONFIG,
	HP_OPTION,
	HP_EXIT,
	HP_FSET,
	UP_FIRST,
	UP_HAWK,
	UP_CONFIG,
	UP_CONFIGSAVE,
	UP_OPTION,
	UP_RETRY,
	UP_EXIT,
	DP_FIRST,
	DP_RESULT,
	DP_CHK,
	DP_KOYARST,
	DP_CONFIG,
	TP_NONE,
	TP_MAIN,
	TP_RANKING,
	TP_K_CONF,
	TP_OPTION,
	CP_MAIN,
	CP_CONFIG,
	CP_RES0,
	CP_RES1,
	RP_MAIN,
	FP_MAIN,
};


#endif
