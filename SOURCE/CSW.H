
#ifndef _CSW_H_

#define _CSW_H_

//	各種ｄｅｆｉｎｅフラグ
//	0:Off 1:On	
//	個人的なデバッグスイッチをいれる
#define HIGH_LOT	0

#define	OBJ_ALLOC		//	動的にメモリを使用
//#define	XA_CUT
#define DEBUG_BACK	0	//	0=黒  1=緑
//#define MOVIE_CUT		//	ムービーをカットする
//#define ENDIN_G

#define	CD_MASTER		//	マスターＣＤを焼くときに付ける

#ifdef	CD_MASTER		//	＊＊マスターＣＤ専用＊＊＊＊＊＊＊＊＊＊＊ 

#define	CD_WRITE		//	ＣＤを焼くときに付ける
#define	READ_MODE	0	//	0:絶対セクタ 1:ファイル名
#define	DEBUG_MODE	0	//	全体のデバッグフラグ 0=OFF 1=ON

#else	//	＊＊通常使用＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊ 

//#define	CD_WRITE		//	ＣＤを焼くときに付ける

#ifdef	CD_WRITE		//	ＣＤ
	#define	READ_MODE	0	//	0:絶対セクタ 1:ファイル名
#else
	#define	READ_MODE	2	//	0:絶対セクタ 1:ファイル名 2:DOSファイル
	#define	DOS_READ		//	READ_MODEに関係無くDOS-FILEを読む
#ifndef MOVIE_CUT
#define MOVIE_CUT
#endif

#endif

#define	DEBUG_MODE	1	//	全体のデバッグフラグ 0=OFF 1=ON

#if		DEBUG_MODE==1	//	

#ifndef	CD_WRITE
#define DEBUG_POLL		//	デバッガー用（ＣＤ焼きの時ははずす）
#endif
#define	DEBUG_FONT		//	fontprint関連
//#define DEBUG_FRAM		//	フレームバッファを見る
//#define DEBUG_LINE		//	処理棒の表示
//#define	DEBUG_POLY

#endif	//	DEBUG_MODE==1	//	

#endif

#endif


