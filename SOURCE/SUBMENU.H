/*===================================================
	submenu.h
	
	ＴＥＮ	パチスロコレクション
	サブメニュー	のヘッダ
	
						作ってる人		T. Kawakami
						作り出した日	23st Nov. '98
====================================================*/

#ifndef _SUBMENU_H_
#define _SUBMENU_H_

#define	MENU_LEFT	-128
#define	MENU_TOP	 -96

typedef	struct	{
	int			moji_id[2];
	int			moji_max, spr_num, pol_num;
	void		*pp[4];
	SPRITE_OBJECT	*sp[24];
	u_short		str[16];
}	AWAY_COLUMN;

//extern	SUBMENU		*swp;
extern	signed char	submenu_sts;		// サブメニューステップ 
extern	char		submenu_tim_loaded;	// サブメニュー部材ロード 

#define	SUBM_INIT		10
#define	SUBM_DISPOSE	SUBM_INIT		+10
#define	SUBM_NORMAL		SUBM_DISPOSE	+10
#define	SUBM_CHILD		SUBM_NORMAL		+10
#define	SUBM_LIGHT		SUBM_CHILD		+10

#define	MENU_NORMAL		10
#define	MENU_EXIT		MENU_NORMAL 	+10

#define	ITEMN_SUB	10
#define	ITEMN_MDL	3
#define	ITEMN_DDW	4
#define	ITEMN_AUT	4
#define	ITEMN_OPT	4

#define	ITEMN_HAWK		6
#define	ITEMN_UNLOCK	5
#define	ITEMN_DETECT	8
//#define	ITEMN_CROSS		8
#define	ITEMN_CROSS		7
#define	ITEMN_REACH		2
#define	ITEMN_FLASH		3


// title.c
extern	void	keyconfig(WINDOW *);


//	submenu.c 
extern	short	flg_tex_data[15][4];
extern	short	opt_item[];
extern	char	cp_sm;

void	medal(WINDOW *);
void	datadispwin(WINDOW *);
void	setflag(WINDOW *);
void	autoset(WINDOW *);
void	config(WINDOW *);
void	option(WINDOW *);
void	review_panel(WINDOW *);
void	panel_exit(WINDOW *);
void	init_kawas(int);
void	panel_exit_retry(WINDOW *);
void	sethawk(WINDOW *);
//	status.c 
void	status_1(WINDOW *);
void	status_2(WINDOW *);
void	status_3(WINDOW *);
void	disp_bonusd(WINDOW *);
void	disp_away(WINDOW *);
void	disp_graph(WINDOW *);
void	make_sts_panel(char, char);
//	hawk.c 
extern	char	reel_ptrn[][7];

short	hawkmenu_drv(void);
void	panel_hawk(WINDOW *);

// unlock.c
void	panel_unlock(WINDOW *);
// detect.c 
extern	void	detect_result(WINDOW *wp);
void	panel_detect(WINDOW *);

// toggles.c 
void	dispose_all_toggles(void);
void	mes_panel(WINDOW *);
void	onoff_panel(WINDOW *);
void	set_reach_cursol(SPRITE_OBJECT **, int);

// cross.c 
void	panel_cross(WINDOW *);

// reach.c 
void	panel_reach(WINDOW *);


// flash.c 
void	panel_flash(WINDOW *);

// iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya 
// iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya 
// iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya 
// iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya iteya 


typedef	struct	{
	char	card_use[15];	// カード使用状況 
/*									 0:未使用	1:トータルデータ
									 2:かっぱ	3:神様
									 4:他ゲーム	*/
	char	max_total;		// トータルデータ数 
	char	max_kapp;		// かっぱデータ数 
	char	max_kami;		// 神様データ数 
	char	max_aki;		// 空きデータ数 
	char	max_hoka;		// 他ゲームデータ数 
}	M_CARD;


extern M_CARD	mc_data;
extern void mc_mess_(int no);

#define DEF_MEM00	(0)				/*メモリカードを調べています*/
#define DEF_MEM10	(DEF_MEM00+1)	/*上書きしますよろしいですか？*/
#define DEF_MEM07	(DEF_MEM00+2)	/*トータルデータをロードします*/
#define DEF_MEM14	(DEF_MEM00+3)	/*トータルデータをロードしました*/
#define DEF_MEM06	(DEF_MEM00+4)	/*トータルデータをセーブします*/
#define DEF_MEM15	(DEF_MEM00+5)	/*トータルデータをセーブしました*/
#define DEF_MEM09	(DEF_MEM00+6)	/*プレイデータをロードします*/
#define DEF_MEM16	(DEF_MEM00+7)	/*プレイデータをロードしました*/
#define DEF_MEM08	(DEF_MEM00+8)	/*プレイデータをセーブします*/
#define DEF_MEM17	(DEF_MEM00+9)	/*プレイデータをセーブしました*/
#define DEF_MEM04	(DEF_MEM00+10)	/*メモリカードをフォーマットしますか？*/
#define DEF_MEM18	(DEF_MEM00+11)	/*メモリカードをフォーマットしました*/
#define DEF_MEM19	(DEF_MEM00+12)	/*メモリカードを抜かないでください*/
#define DEF_MEM20	(DEF_MEM00+13)	/*セーブするデータを選んで下さい*/
#define DEF_MEM21	(DEF_MEM00+14)	/*　*/
#define DEF_MEM22	(DEF_MEM00+15)	/*トータルデータに上書きされます*/
#define DEF_MEM23	(DEF_MEM00+16)	/*プレイデータに上書きされます*/
#define DEF_MEM24	(DEF_MEM00+17)	/*新規ファイルを作ります*/
#define DEF_MEM26	(DEF_MEM00+18)	/*ロードするデータを選んで下さい*/
#define DEF_MEM34	(DEF_MEM00+19)	/*トータルデータはすでに読み込まれています*/

#define DEF_MEM01	(20)	/*メモリカードが壊れています*/
#define DEF_MEM02	(DEF_MEM01+1)	/*メモリカードがささっていません*/
#define DEF_MEM05	(DEF_MEM01+2)	/*メモリカードがいっぱいです*/
#define DEF_MEM11	(DEF_MEM01+3)	/*データが壊れています*/
#define DEF_MEM12	(DEF_MEM01+4)	/*ほかのゲームで使われています*/
#define DEF_MEM13	(DEF_MEM01+5)	/*メモリカードを入れ替えてください*/
#define DEF_MEM03	(DEF_MEM01+6)	/*メモリカードがフォーマットされていません*/
#define DEF_MEM25	(DEF_MEM01+7)	/*トータルデータは１つしかセーブきません*/
#define DEF_MEM27	(DEF_MEM01+8)	/*トータルデータは１つしかありません*/
#define DEF_MEM29	(DEF_MEM01+9)	/*セーブデータがありません*/
#define DEF_MEM30	(DEF_MEM01+10)	/*フォーマットに失敗しました*/
#define DEF_MEM31	(DEF_MEM01+11)	/*セーブに失敗しました*/
#define DEF_MEM32	(DEF_MEM01+12)	/*ロードに失敗しました*/
#define DEF_MEM35	(DEF_MEM01+13)	/*トータルデータはありません*/
#define DEF_MEM36	(DEF_MEM01+14)	/*プレイデータはありません*/
#define DEF_MEM37	(DEF_MEM01+15)	/*プレイデータではありません*/

extern	char	u_cfset[];
extern	char	d_cfset;
extern	char	c_cfset;
extern	char	h_cfset[];

#endif



