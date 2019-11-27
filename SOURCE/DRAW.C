#include "common.h"
#include "work.h"

//OBJECT_TREE *objtree_top;	//	オブジェリストトップ
//OBJECT_TREE *objtree_last;	//	オブジェリストラスト
short dispx0,dispx1;		//	Displayのx,yチェック用
short dispy0,dispy1;		//	(Spriteのクリッピング等に使用)

#if 0
/* PCファイル書き込み(リトライなし) */
int SS_pcf_write2(char *name, char *buff, int len)
{
	int				hdl, rel, ret;

	while(1){
		ret = hdl = PCcreat(name, 0);
		if(hdl == -1)break;
		rel = PCwrite(hdl, buff, len);
		ret = PCclose(hdl);
		if (rel != len)ret = -1;
		else ret = 0;
		break;
	}

	return(ret);
}


void	*SS_TEX_ADRS;

void SS_snap_shot(void)
{
	static int		sn = 0;
	int				i;
	RECT			rect;
	u_char			fn[256];
	char			hd[] = {
		0x10,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
		0x0c,0x58,0x02,0x00,0x00,0x03,0x00,0x00,
		0x40,0x01,0xf0,0x00
	};
	draw_rq=1;

	SS_TEX_ADRS=memalloc(153620, (void**)&SS_TEX_ADRS);

	do{
		sprintf(fn, "\\SNAP\\SNAP%d.TIM", sn++);
		rect.x = 0;
		rect.y = 0 * 240;
		rect.w = 320;
		rect.h = 240;
		for(i = 0; i < 20; i++)((u_char *)SS_TEX_ADRS)[i] = hd[i];
		StoreImage(&rect, (u_long *)(SS_TEX_ADRS + 20));
		DrawSync(0);
		i = SS_pcf_write2(fn, SS_TEX_ADRS, 320 * 240 * 2 + 20);
	}while(i != 0);
	draw_rq=0;
	memfree((void**)&SS_TEX_ADRS);

}



#if 0
void SS_snap_shot(void)
{
	static int		sn = 0;
	int				i;
	RECT			rect;
	u_char			fn[256];
	char			hd[] = {
		0x10,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
		0x0c,0x58,0x02,0x00,0x00,0x03,0x00,0x00,
		0x40,0x01,0xf0,0x00
	};
	draw_rq=1;

	SS_TEX_ADRS=memalloc(153620, (void**)&SS_TEX_ADRS);

	do{
		sprintf(fn, "\\SNAP\\SNAP%d.TIM", sn++);
		rect.x = 0;
		rect.y = 0 * 240;
		rect.w = 320;
		rect.h = 240;
		for(i = 0; i < 20; i++)((u_char *)SS_TEX_ADRS)[i] = hd[i];
		StoreImage(&rect, (u_long *)(SS_TEX_ADRS + 20));
		DrawSync(0);
		i = SS_pcf_write(fn, SS_TEX_ADRS, 320 * 240 * 2 + 20);
	}while(i != 0);
	draw_rq=0;
	memfree((void**)&SS_TEX_ADRS);
}
#endif


#endif

	char	wi;
int dsafa=0;
extern signed char	submenu_sts;		// サブメニューステップ 
extern void IS_LPSD_OUT(void);
//	オブジェクト（スプライト等）描画
void draw(void)
{

//	animobj_anim();

	if(!draw_rq){
#if 1
		if(submenu_sts){
			wi=(wi+1)%3;
			if(wi)	return;
		}
#endif
//	それぞれのＯＴへの登録 *
#ifdef DEBUG_LINE
		func_line();
#endif
//		仮の物なので、本番でははずす。

		ffnt_draw((void *)&ot[actframe],FFNT_ALL,10);
		sprobj_draw();
		poly_draw();
		dobj_draw();

//		win_draw();

#ifdef DEBUG_LINE
		func_line();
#endif
		draw_flag = 0;
		dsafa++;
		while(DrawSync(1)!=0);	//	今フレーム分の描画終了待ち

#ifdef DEBUG_LINE
		func_line();
#endif
#ifdef	DEBUG_FONT
		//	各々のＯＢＪがどれだけ登録されているか表示
FntPrint(dbg_flg.fnt[0],"BYOUGA=%d\n",dsafa);
/*		if(spr_cnt)		FntPrint(dbg_flg.fnt[0],"SPRITE=%d\n",spr_cnt);
		if(f3_cnt)		FntPrint(dbg_flg.fnt[0],"F3    =%d\n",f3_cnt);
		if(f4_cnt)		FntPrint(dbg_flg.fnt[0],"F4    =%d\n",f4_cnt);
		if(g3_cnt)		FntPrint(dbg_flg.fnt[0],"G3    =%d\n",g3_cnt);
		if(g4_cnt)		FntPrint(dbg_flg.fnt[0],"G4    =%d\n",g4_cnt);
		if(ft3_cnt)		FntPrint(dbg_flg.fnt[0],"FT3   =%d\n",ft3_cnt);
		if(ft4_cnt)		FntPrint(dbg_flg.fnt[0],"FT4   =%d\n",ft4_cnt);
		if(gt3_cnt)		FntPrint(dbg_flg.fnt[0],"GT3   =%d\n",gt3_cnt);
		if(gt4_cnt)		FntPrint(dbg_flg.fnt[0],"GT4   =%d\n",gt4_cnt);
		if(pol_cnt)		FntPrint(dbg_flg.fnt[0],"POLY  =%d\n",pol_cnt);
		if(spra_cnt)	FntPrint(dbg_flg.fnt[0],"ANIM  =%d\n",spra_cnt);
/**/
		//	PACKETをどれぐらい使用しているか調べる(deb)
	//	FntPrint(dbg_flg.fnt[0],"PACKET=%d\n",(((long)GsGetWorkBase()-(long)gpu_packet[actframe])/24));
#endif
		draw_flag = 1;
	}
//	if(pad_cnt&PADR_RIGHT)	SS_snap_shot();
}

void wait2(int time)
{
	int lp;
	for(lp=0;lp<time;lp++)	wait(1);

}

extern void drum_light3(void);

void wait(int time)
{
#ifdef DEBUG_POLL
//		pollhost();	/*ＣＤ焼く時は必ず外して！*/
#endif

//		pad_read();

//		wfadel_inout();	/*輝度変化によるフェード*/
//		wfadec_inout();	/*カラーフェード*/
//		colchg_job();	/*カラーチェンジ処理*/
//		win_move_wt();	//
//		sound_driver();	/*サウンド*/

//	pad_read();
//	pad_callback();
		if(auto_on_s==0){
			ffnt_drv();		/* ＦＦＮＴ表示更新ドライバ */
			window_drv();
			toggles_drv();
			ffnt_drv();		/* ＦＦＮＴ表示更新ドライバ */
		}
		drum_light3();
		draw();			/* 描画 */
//		vsc = VSync(1);
		switch(time){
			case 0:
			case 1:
				VSync(0);
			break;
			default:
				VSync(time);
			break;
		}
}

void wait_nw(int time)
{
	char bk;
	bk=draw_rq;
	draw_rq=1;
	wait(time);
//	draw_rq=0;
	draw_rq=bk;

}

#ifdef dfdsfsdfsd
#ifdef OBJ_ALLOC
/*===================================================================
 *　オブジェクト管理バッファのメモリを割り当てます
 *
 * in : void
 * out: OBJECT_TREE * スプライトオブジェクトのポインタ
 *
 *=================================================================*/
OBJECT_TREE *objtree_alloc(void)
{
	return (OBJECT_TREE *)memalloc(sizeof(OBJECT_TREE));
}
#endif
#endif

