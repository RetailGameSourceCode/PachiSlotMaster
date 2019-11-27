//#ifndef _TEST_WORK_C_
//#define _TEST_WORK_C_
/*=============================================================
 *	子プロから参照される外部変数
 *=============================================================*/

#include "common.h"

/* オーダリングテーブル */

GsOT ot[2];
GsOT_TAG ottag[2][OT_SIZE];

/* GPUパケット領域の定義 */
PACKET	gpu_packet[2][PACKETMAX*24];

int actframe;		/*	アクティブなバッファへのポインタ */
int	draw_flag;		/*	描画許可フラグ*/
int	draw_rq;		/*	描画許可フラグ*/
u_long vcount;		/*	ＶＳＹＮＣカウント*/
int func_mode;		/*	現在のゲームモード*/
int disp_mode;		/*	画面のモード*/
int	mal_chk;
int	mal_cnt;
int mem_cnt;	//	MALLOCで使用

//	汎用ＯＢＪ

/* その他... */

char chk;

//SAVE2 tot;	//	トータルセーブデータ
//SAVE2 kbr;	//	筐体別セーブデータ

