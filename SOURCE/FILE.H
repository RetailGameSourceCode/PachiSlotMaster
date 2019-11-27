/*=============================================================
 *
 *	リードファイルＩＤ
 *
 *=============================================================*/

#ifndef _FILE_H_

#define _FILE_H_


/*-------------------------------------------------------------
 *　ファイルのID番号です
 *	この順番を変えるときは注意必要
 *	FILE.Cの定義順位に合わせてください
 *	データリードはこの番号で行います
 *-------------------------------------------------------------*/
/*	ファイル情報テーブル	*/
typedef struct{
#if READ_MODE==0
	int		fpos;	/*ファイル先頭絶対セクタ位置*/
	u_long	size;	/*ファイルサイズ*/
#else
	char	*fname;	/*ファイル名*/
#endif
} FILE_INFO;


enum fnum {
	//	Kawakami files start 
	F_SELECT,		//	セレクト関連 
	F_SUBMENU,		// サブメニュー関連 
	//	Kawakami files end 

	//	teya file start
	FONT_TIM_N,		/*	フォント	*/
	KAP_A_TIC_N,
	BIN_A_TIC_N,
	KAPS_TIC_N,
	BINS_TIC_N,

	K_SELECT_VB_N,
	K_SELECT_VH_N,
	K_SELECT_SEQ_N,
	OPENING_VB_N,
	OPENING_VH_N,
	OPENING_SEQ_N,

	//	iteya file end

};

extern	FILE_INFO fileinfo[];

#endif	/*_FILE_H_*/


