
#ifndef _COMMON_H_

#define _COMMON_H_

//
//	共通定義ヘッダ
//
#include <sys/types.h>
#include <sys/file.h>
#include <r3000.h>
#include <asm.h>
#include <kernel.h>
#include <libapi.h>
#include <libpad.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libcd.h>
#include <libgs.h>
#include <libsn.h>
#include <libspu.h>
#include <libsnd.h>
#include <stdlib.h>
#include <libmath.h>
#include <limits.h>
#include <setjmp.h>
#include <libpress.h>

#include "csw.h"		/*コンパイルスイッチ*/

#define	TRUE	1		/*真*/
#define	FALSE	0		/*偽*/
#define	NO_SET	(255)	/*マイナス*/

/*ＧＰＵパケットの数*/
#define	PACKETMAX 10000

/*オーダリングテーブル(OT)の定義*/
#define	OT_LENGTH 10			/*128段階*/
#define	OT_SIZE (1<<OT_LENGTH)

/* 画面情報*/
#define DSPW	320	/*画面横サイズ*/
#define DSPH	240	/*画面縦サイズ*/
#define CELWX	16	/*マップ横セルサイズ（ドット）*/
#define CELWY	16	/*マップ縦セルサイズ（ドット）*/

#define	DSPX0	0	//	表示領域	Ｘ座標０ 
#define	DSPX1	0	//	表示領域	Ｘ座標１ 
#define	DSPY0	0	//	表示領域	Ｙ座標０ 
#define	DSPY1	240	//	表示領域	Ｙ座標１ 
#define	DSPM	(GsNONINTER|GsOFSGPU)	//	DISPLAY	MODE 
#define	DSPM_INTER	(GsINTER|GsOFSGPU)		//	DISPLAY	MODE 
#define	DSPD	1	//	画面のディザリング	0:OFF 1:ON 
#define	DSPV	0	//	VRAM-MODE	0:16bit 1:24bit 


//	ゲームモード

#define	MODE_NOP	0
#define	MODE_MOVIE	1
#define	MODE_OPEN	2
#define	MODE_TITLE	3
#define	MODE_SELECT	4
#define	MODE_GAME	5
#define	MODE_SAVE	6
#define	MODE_LOAD	7

//	LIBGS.H	に準拠
#define GsRETV		(1<<22)	// Ｖ反転 
#define GsRETH		(1<<23)	// Ｈ反転 
#define GsCLUT4		(0<<24)	//   ４ｂｉｔＴＩＭ用 
#define GsCLUT8		(1<<24)	//   ８ｂｉｔＴＩＭ用 
#define GsCLUTD		(2<<24)	// ２４ｂｉｔＴＩＭ用 


#define	BG_R 0

#if		DEBUG_BACK==1
#define	BG_G 127
#else
#define	BG_G 0
#endif

#define	BG_B 0

//	スプライト関連
#define	OBJ_KIL		0
#define	OBJ_SPR		1
#define	OBJ_F3		2
#define	OBJ_F4		3
#define	OBJ_G3		4
#define	OBJ_G4		5
#define	OBJ_FT3		6
#define	OBJ_FT4		7
#define	OBJ_GT3		8
#define	OBJ_GT4		9
#define	OBJ_POLY	10
#define	OBJ_SPRANM	11


/*アニメーション*/
#define ANM_END				0x7fff
#define ANIM_TIME_OF		0x8001	/* 表示時間 */
#define ANIM_FLG_OF			0x8002	/* 返値指定 */
#define ANIM_JMP_OF			0x8003	/* ジャンプ指定 */
#define ANIM_END			0x8004	/* アニメーション終わり */
#define ANIM_DON			0x8005	/* 表示ＯＮ */
#define ANIM_DOFF			0x8006	/* 表示ＯＦＦ */
#define ANIM_RPTCNT_OF		0x8007	/* 繰り返し回数指定 */
#define ANIM_RPT_OF			0x8008	/* 繰り返し位置指定 */
#define ANIM_HATTRAND_OF	0x8009	/* attribute highへのAND */
#define ANIM_HATTROR_OF		0x800a	/* attribute highへのOR */
#define ANIM_LATTRAND_OF	0x800b	/* attribute lowへのAND */
#define ANIM_LATTROR_OF		0x800c	/* attribute lowへのOR */
#define	ANIM_SCALEXP_OF		0x800d	/* スケールＸへの足し込み */
#define	ANIM_SCALEYP_OF		0x800e	/* スケールＹへの足し込み */
#define	ANIM_SCALEX_OF		0x800f	/* スケールＸへの代入 */
#define	ANIM_SCALEY_OF		0x8010	/* スケールＹへの代入 */
#define	ANIM_SCALEXYP_OF	0x8011	/* スケールＸＹへの足し込み */
#define	ANIM_SCALEXY_OF		0x8012	/* スケールＹＹへの代入 */
#define	ANIM_ROTATEP_OF		0x8013	/* ローテートへの足し込み */
#define	ANIM_ROTATE_OF		0x8014	/* ローテートへの代入 */
#define	ANIM_ROTON			0x8015	/* 回転拡大ＯＮ */
#define	ANIM_ROTOFF			0x8016	/* 回転拡大ＯＦＦ */
#define	ANIM_LON			0x8017	/* 輝度変化ON */
#define	ANIM_LOFF			0x8018	/* 輝度変化OFF */
#define	ANIM_RGB_OF			0x8019	/* 輝度指定 */
#define	ANIM_RGBP_OF		0x801A	/* 輝度変化 r,g,b  */
#define	ANIM_RP_OF			0x801B	/* 輝度変化 r */
#define	ANIM_GP_OF			0x801C	/* 輝度変化 g */
#define	ANIM_BP_OF			0x801D	/* 輝度変化 b */
#define	ANIM_X_OF			0x801E	/* Ｘへのセット*/
#define	ANIM_Y_OF			0x801F	/* Ｙへのセット*/
#define	ANIM_MX_OF			0x8020	/* ＭＸへのセット*/
#define	ANIM_MY_OF			0x8021	/* ＭＹへのセット*/
#define	ANIM_XY2MXY			0x8022	/* ＸＹをＭＸＭＹへセット*/
#define	ANIM_XP_OF			0x8023	/* Ｘへの足し込み*/
#define	ANIM_YP_OF			0x8024	/* Ｙへの足し込み*/
#define	ANIM_MXP_OF			0x8025	/* ＭＸへの足し込み*/
#define	ANIM_MYP_OF			0x8026	/* ＭＹへの足し込み*/
#define	ANIM_RNDTIME_OF		0x8027	/* 乱数で表示時間セット 上限|ofs (8bit|8bit)*/
#define	ANIM_SE_OF			0x8028	/* ＳＥのセット*/
#define	ANIM_SESTOP			0x8029	/* ＳＥのストップ*/

#include "file.h"		//	ファイル管理 
#include "cd.hd"		//	絶対セクタ用 
#include "first.hd"		//	文字用 

#include "savedata.h"		//	セーブデータ
#include "teisu.h"		//	カッパッパ ＋ビンビン
#include "kapbin.h"		//	カッパッパ ＋ビンビン

#include "moji.h"		//	文字データ（変更しない場合ずっと持っておく）
						//	変更有りの場合は、各所でインクルードする事！ 
#include "func.h"		//	ファイル管理 
#include "debug.h"		//	デバッグ関数 
#include "dosfile.h"	//	DOS-FILEを読み込む 
#include "cdread.h"		//	ＣＤ読み込み 
#include "snd_dat.h"	//	音楽データ名 
#include "sound.h"		//	音楽管理 
#include "typedef.h"	//	構造体一覧 
#include "pad.h"		//	パッド関数 
#include "draw.h"		//	描画関数 
#include "sprite.h"		//	通常スプライト 
#include "init.h"		//	初期化関数 
#include "memory.h"		//	メモリ管理 
#include "add.h"		//	計算式  
#include "game.h"		//	ゲーム本体  
#include "gameread.h"	//	ゲームデータ読み込み 
#include "dobj.h"		//	３ＤＯＢＪ作成 
#include "hard.h"		//	機械部分作成管理 
#include "window.h"		//	簡易ウィンドウ用
#include "kkffnt.h"		//	フォント
#include "stream.h"		//	ムービー
#include "saveload.h"		//	ムービー
#include "kawa.h"

#endif

