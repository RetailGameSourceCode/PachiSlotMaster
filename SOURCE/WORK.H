
#ifndef _WORK_H_

#define _WORK_H_

/* オーダリングテーブル */
extern	GsOT ot[2];
extern	GsOT_TAG ottag[2][OT_SIZE];

/* GPUパケット領域の定義 *******************************/
extern	PACKET	gpu_packet[2][PACKETMAX*24];

extern int actframe;	//	アクティブなバッファへのポインタ
extern int	draw_flag;	//	描画許可フラグ
extern int	draw_rq;	//	描画許可フラグ
extern u_long vcount;	//	ＶＳＹＮＣカウント
extern int func_mode;
extern int disp_mode;
extern int	mal_chk;
extern int	mal_cnt;
extern int mem_cnt;			//	MALLOCで使用

extern char chk;
#endif


