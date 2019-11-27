/*=============================================================
 *
 *	汎用関数
 *
 *=============================================================*/
#include "common.h"
#include "work.h"

void first_data(void);

int mem_cnt;
void *anm_adr,*atime_adr;

#ifdef DEBUG_FLAG
 int dbg_fnt_flg;
#endif

/*=============================================================
 *
 *	ループ関数
 *
 *=============================================================*/
void loop_func(void)
{

		/*必要なときだけ呼ぶもの*/
		switch(func_mode)
		{
		}

		/*常に呼ぶもの*/
	//	wfadel_inout();	/*輝度変化によるフェード*/
	//	wfadec_inout();	/*カラーフェード*/
	//	colchg_job();	/*カラーチェンジ処理*/
	//	win_move_wt();	//
		sound_driver();	/*サウンド*/

		cd_read_fast();	/*ＣＤリード*/


	return;
}



/*=============================================================
 *
 *
 *=============================================================*/
void boot_init(void)
{
}


/*=============================================================
 *
 *
 *=============================================================*/
void start_init(void)
{

}



/*=============================================================
 *	一度読み込めばいい物をセットします
 *
 * in:	void
 *
 * out:	void
 *
 *=============================================================*/
void first_data(void)
{
 RECT vadr;

}


/*-------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/



/*=============================================================
 *
 *  ＴＩＭ、ＰＸＬ、ＣＬＴをフレームバッファへ転送します
 *
 * in:
 *		u_short *adr	転送元メインメモリアドレス
 *		int load_type	1 : １個分だけ転送	//	１～
 *						0 : すべて転送
 *=============================================================*/
void tim_load(u_short *adr, int load_type)
{
#define TIM_HEADER 0x0010
#define CLT_HEADER 0x0011
#define PXL_HEADER 0x0012
	register int clt_sw;
	register int lp;
	RECT rct;
	GsIMAGE stim;

	clt_sw=0;
//	if(load_type>=900){
//		adr+=2500;
//		load_type-=900;
//	}


	if(load_type!=0){
		for(lp=1;lp<load_type;lp++){
			switch(*adr){
				case TIM_HEADER:
				case PXL_HEADER:
					adr+=2;	/* ヘッダのスキップ(4byte) */
					GsGetTimInfo((u_long *)adr, &stim);
					adr += stim.pw*stim.ph +6+2;	/* 次のブロックまで進める */
					if((stim.pmode>>3)&0x01)
					{	/* CLUTがあれば転送 */
						adr += stim.cw*stim.ch +6;
					}
					break;
				case CLT_HEADER:
					clt_sw=1;
					adr += 6;		/* (id,flg,bnum)のスキップ(12byte) */
					adr++;
					adr++;
					rct.w = *adr;
					adr++;
					rct.h = *adr;
					adr++;
				//	LoadImage(&rct,(u_long *)adr);
				//	while(DrawSync(1)!=0);
					adr += rct.w*rct.h;
				break;
				default:
					return;
			}
		}
	}
	do{
		switch(*adr){
			case TIM_HEADER:
				adr+=2;	/* ヘッダのスキップ(4byte) */
				GsGetTimInfo((u_long *)adr, &stim);
				adr += stim.pw*stim.ph +6+2;	/* 次のブロックまで進める */

				rct.x=stim.px;

				rct.y=stim.py;
				rct.w=stim.pw;
				rct.h=stim.ph;
				LoadImage(&rct,stim.pixel);
				if((stim.pmode>>3)&0x01)
				{	/* CLUTがあれば転送 */
					rct.x=stim.cx;
					rct.y=stim.cy;
					rct.w=stim.cw;
					rct.h=stim.ch;
					LoadImage(&rct,stim.clut);
					while(DrawSync(1)!=0);
					adr += stim.cw*stim.ch +6;
				}
				break;
			case CLT_HEADER:
				clt_sw=1;
			case PXL_HEADER:
				adr += 6;		/* (id,flg,bnum)のスキップ(12byte) */
				rct.x = *adr;
				adr++;
				rct.y = *adr;
				clt_sw=0;
				adr++;
				rct.w = *adr;
				adr++;
				rct.h = *adr;
				adr++;
				LoadImage(&rct,(u_long *)adr);
				while(DrawSync(1)!=0);
				adr += rct.w*rct.h;
				break;
			default:
				return;
		}
	}while(load_type==0);
}




