/*===================================================
	select.h
	
	ＴＥＮ	パチスロコレクション
	機種選択画面など	select.cのヘッダ
	
						作ってる人		T. Kawakami
						作り出した日	28th Oct. '98
====================================================*/
#ifndef	_SELECT_H
#define	_SELECT_H

#define	MES_L		 (32 + OX)	//	メッセージウィンドウ 
#define	MES_U		 (16 + OY)
#define	MACH_L		 (40 + OX)	//	台イメージ 
#define	MACH_U		 (45 + OY)
#define	LOGO_L		(160 + OX)	//	ロゴ 
#define	LOGO_U		 (42 + OY)
#define	P_MACH_L	(160 + OX)	//	機種選択時確率表パネル 
#define	P_MACH_U	(108 + OY)
#define	C_TWIN_L	 (16 + OX)	//	ツインカーソル 
#define	C_TWIN_U	(104 + OY)
#define	P_MODE_L	(160 + OX)	//	モード選択パネル 
#define	P_MODE_U	 (92 + OY)
#define	P_RATE_L	(160 + OX)	//	確率設定パネル 
#define	P_RATE_U	 (60 + OY)
#define	P_SOUND_L	(160 + OX)	//	サウンドパネル 
#define	P_SOUND_U	(107 + OY)
#define	P_HELP_L	 (32 + OX)	//	ヘルプパネル	
#define	P_HELP_U	(204 + OY)
#define	P_RESET_L	(180 + OX)	// 小役カウンタ状態設定パネル 
#define	P_RESET_U	(100 + OY)

#define	PRI_BACK	16
#define	PRI_CLOUD	15
#define	PRI_LOGO	13
#define	PRI_MAC		11
#define	PRI_MES		 9
#define	PRI_MODE	 7
#define	PRI_RATE	 5
#define	PRI_CUR		 1

#define	CLOUD_MAX		5	/*	雲の数	*/

char	bgm_max[MACHINE_MAX] = {5, 7,};	//	ＢＧＭの数	
char	se_max[MACHINE_MAX] = {9, 9,};	//	ＳＥの数	

/*	全体的な情報	*/
typedef	struct	{
	int			work[8];	//	好きに	
	signed char	scrmode;	/*	画面状態	*/
	signed char	gamemode;	/*	ゲームモード	*/
	signed char	mach_n;		/*	機械番号	*/
	signed char	rate_n;		//	確率番号	
	signed char	chg_scr;	//	画面切替え中	
	signed char	chg_menu;	//	画面内切替え中	
}	SELECT_STS;

/*	画面状態	*/
enum DMODE {
	SEL_MACHINE,	/*	機種選択	*/
	SEL_MODE,		/*	モード選択	*/
	SEL_RATE,		/*	確率選択	*/
	SEL_SOUND,		/*	サウンド	*/
	SEL_RESET,		// 小役カウンタリセット確認 
	SEL_OK,			/*	確認	*/
	SEL_RATE_CHK,	//	設定選択（設定判別）	
	SEL_NUM,		//	確率設定	
	SEL_CHKTYPE,	// 設定判別法選択 
	SEL_SOUNDLOAD,	// サウンドデータロード中 
	SEL_MAX,
};

//	メッセージパネル	
typedef	struct	{
	FRAMES		frames;	//	枠	
	POL_MEMB	mes_str[2][2];	//	文字列用[左右][上下] 
	short		x, y;
}	MESWIN_OBJ;

//	ヘルプパネル	
typedef	struct	{
	FRAMES		frames;
	POL_MEMB	str[2];
	POL_MEMB	but[4];
	short		x, y;
}	PANEL_HELP;

//	サウンド画面全般	
typedef	struct	{
	FRAMES		frames;
	POL_MEMB	blank;
	POL_MEMB	upstr;
	POL_MEMB	title[2];
	POL_MEMB	cursor;
	POL_MEMB	string[2][2];
	POL_MEMB	se_name[2];
	POL_MEMB	bgm_name[2];
	short		x, y;
	short		w, h;
	short		cur_p;			//	カーソル位置	
	short		snd_n[2];		//	実番号	
	short		disp_n[2];		//	表示	
	short		count[2];		//	カウンタ	
}	PANEL_SOUND;

//	レートパネル	
typedef	struct	{
	FRAMES		frames;		//	枠	
	POL_MEMB	hstr[3];	//	行項目	
	POL_MEMB	vstr;		//	列項目	
	POL_MEMB	blank;		//	無地用	
	POL_MEMB	cursor;		//	カーソル	
	short		x, y;
	short		w, h;
	short		bonus_n;
}	PANEL_RATE;

/*	台ポリステータス	*/
typedef struct	{
	POL_MEMB	pm;
}	MACHINE;

/*	ロゴポリステータス	*/
typedef struct	{
	POL_MEMB	pm;
	short		sts;
}	LOGO;

typedef	struct	{
	FRAMES		frames;
	POL_MEMB	m_clmW[GMODE_MAX];	//	モード選択項目 
	short		x, y;
	short		w, h;
}	MODE_PANEL;

//	ツインカーソル	
typedef struct {
	POL_MEMB	pm;
	short		anm;
	short		count;
}	T_CUR;

/*	雲ポリ	*/
typedef struct {
	POL_MEMB	pm;
	short		ow, oh;
	short		vx, vy;	//	速度 
}	CLOUD;

//	確率文字列	
typedef	struct	{
//	SPRITE_OBJECT	pm[5];
	POL_MEMB	pm[5];
}	RATE_N;

#endif
