/*===================================================
	window.c
	
	射手矢さんライブラリ上での簡易矩形取扱い関連
		８dot×８dot以上の大きさであること
	
						作ってる人		T. Kawakami
						作り出した日	20th Nov. '98
====================================================*/

#include	"common.h"
#include	"work.h"

void	set_win(WINDOW *);

WINDOW	*winlist_top = NULL;
WINDOW	*winlist_tail = NULL;

/*===========================================================
	ウィンドウの登録
		in:	WINDOW	*wp		構造体ポインタ
			short	ox, oy	位置
			short	ow, oh	サイズ
			short	op		プライオリティ
			void	*funcp	関数ポインタ
===========================================================*/
WINDOW	*make_window(short ox, short oy, short ow, short oh, short op, void *funcp) {
	WINDOW		*wp;
	POLY_F4		*cp;
	LINE_F2		**cl2pp;
	LINE_F4		*cl4;
	int			i;
	
	wp = NULL;
	
	wp = (WINDOW *)memalloc(sizeof(WINDOW), (void **)&wp);
	if (wp != NULL) {
		wp->active = TRUE;
		// ワーク／文字ID初期化 
		for (i = 0; i < 16; i++) {
			wp->moji_id[i] = 0;
			if (i < 8) wp->work[i] = 0;
		}
		// 板 
		cp = wp->pp = poly_f4_make();
		if (cp != NULL) {
			cp->r0 = cp->b0 = 0x00;	cp->g0 = 0x30;	//	iteya	12/05
			poly_priset(cp, op);
		}
		
		// 線分 
		cl2pp = &wp->l2p[0];
		for (i = 0; i < 7; i++, cl2pp++) {
			*cl2pp = line_f2_make();
			switch (i) {
			case 0:
				(*cl2pp)->r0 = 104;	(*cl2pp)->g0 = 80;	(*cl2pp)->b0 = 56;
				break;
			case 1:
				(*cl2pp)->r0 = 72;	(*cl2pp)->g0 = 40;	(*cl2pp)->b0 = 8;
				break;
			case 2:
				(*cl2pp)->r0 = 32;	(*cl2pp)->g0 = 16;	(*cl2pp)->b0 = 0;
				break;
			case 3:
				(*cl2pp)->r0 = 80;	(*cl2pp)->g0 = 48;	(*cl2pp)->b0 = 16;
				break;
			case 4:
				(*cl2pp)->r0 = 104;	(*cl2pp)->g0 = 80;	(*cl2pp)->b0 = 56;
				break;
			case 5:
				(*cl2pp)->r0 = 48;	(*cl2pp)->g0 = 32;	(*cl2pp)->b0 = 16;
				break;
			case 6:
				(*cl2pp)->r0 = 48;	(*cl2pp)->g0 = 32;	(*cl2pp)->b0 = 16;
				break;
			}
		}
		
		cl4 = wp->l4p[0] = line_f4_make();
		if (cl4 != NULL) {
			cl4->r0 = 10*8;	cl4->g0 = 6*8;	cl4->b0 = 2*8;
		}
		cl4 = wp->l4p[1] = line_f4_make();
		if (cl4 != NULL) {
			cl4->r0 = 9*8;	cl4->g0 = 5*8;	cl4->b0 = 1*8;
		}
		cl4 = wp->l4p[2] = line_f4_make();
		if (cl4 != NULL) {
			cl4->r0 = 0*8;	cl4->g0 = 3*8;	cl4->b0 = 0*8;
		}
		
		wp->sx = wp->dx = wp->x = ox;
		wp->sy = wp->dy = wp->y = oy;
		wp->sw = wp->dw = wp->w = ow;
		wp->sh = wp->dh = wp->h = oh;
		wp->pri = op;
		set_win(wp);
		
		wp->func = funcp;
		wp->f_step = 0;
		
		wp->cnt = 0;
		wp->moji_max = 0;
		wp->mode = WINMODE_NOP;
		
		//	リストへつなぐ
		if(winlist_top == NULL ){	//	初めて
			winlist_top	= wp;
			wp->before	= NULL;
			wp->next	= NULL;
		}	else{					//	２つめ以降
			winlist_tail->next	= wp;
			wp->before			= winlist_tail;
			wp->next			= NULL;
		}
		winlist_tail = wp;
	}
	return wp;
}

/*===========================================================
	ウィンドウの構造体内容に基づいた位置設定
===========================================================*/
void	set_win(WINDOW *wp) {
	POLY_F4		*cp;
	LINE_F2		*cl2;
	LINE_F4		*cl4;
	short		ox, oy, ow, oh;
	
	ox = wp->x;	oy = wp->y;
	ow = wp->w;	oh = wp->h;
	
	// 板 
	cp = wp->pp;
	cp->x0 = cp->x2 = 4 + ox;
	cp->x1 = cp->x3 = 4 + ox + ow - 8;
	cp->y0 = cp->y1 = 4 + oy;
	cp->y2 = cp->y3 = 4 + oy + oh - 8;
	poly_priset(cp, wp->pri);
	
	// 線分 
	cl2 = wp->l2p[0];
	cl2->x0 = ox;
	cl2->x1 = ox + ow - 1;
	cl2->y0 = cl2->y1 = oy;
	poly_priset(cl2, wp->pri);
	
	cl2 = wp->l2p[1];
	cl2->x0 = ox;
	cl2->x1 = ox + ow - 1;
	cl2->y0 = cl2->y1 = oy + oh - 2;
	poly_priset(cl2, wp->pri);
	
	cl2 = wp->l2p[2];
	cl2->x0 = ox;
	cl2->x1 = ox + ow - 1;
	cl2->y0 = cl2->y1 = oy + oh - 1;
	poly_priset(cl2, wp->pri);
	
	cl2 = wp->l2p[3];
	cl2->x0 = ox + 1;
	cl2->x1 = ox + ow - 2;
	cl2->y0 = cl2->y1 = oy + oh - 3;
	poly_priset(cl2, wp->pri);
	
	cl2 = wp->l2p[4];
	cl2->x0 = ox + 2;
	cl2->x1 = ox + ow - 3;
	cl2->y0 = cl2->y1 = oy + oh - 4;
	poly_priset(cl2, wp->pri);
	
	cl2 = wp->l2p[5];
	cl2->x0 = cl2->x1 = ox;
	cl2->y0 = oy + 1;
	cl2->y1 = oy + oh - 3;
	poly_priset(cl2, wp->pri);
	
	cl2 = wp->l2p[6];
	cl2->x0 = cl2->x1 = ox + ow - 1;
	cl2->y0 = oy + 1;
	cl2->y1 = oy + oh - 3;
	poly_priset(cl2, wp->pri);
	
	// 四点連結線分 
	cl4 = wp->l4p[0];
	cl4->x0 = cl4->x1 = ox + 1;
	cl4->x2 = cl4->x3 = ox + ow - 2;
	cl4->y0 = cl4->y3 = oy + oh - 3;
	cl4->y1 = cl4->y2 = oy + 1;
	poly_priset(cl4, wp->pri);
	
	cl4 = wp->l4p[1];
	cl4->x0 = cl4->x1 = ox + 2;
	cl4->x2 = cl4->x3 = ox + ow - 3;
	cl4->y0 = cl4->y3 = oy + oh - 4;
	cl4->y1 = cl4->y2 = oy + 2;
	poly_priset(cl4, wp->pri);
	
	cl4 = wp->l4p[2];
	cl4->x0 = cl4->x1 = ox + 3;
	cl4->x2 = cl4->x3 = ox + ow - 4;
	cl4->y0 = cl4->y3 = oy + oh - 5;
	cl4->y1 = cl4->y2 = oy + 3;
	poly_priset(cl4, wp->pri);
	
}

/*===========================================================
	ウィンドウの出現／退避
		in:		WINDOW	*wp		構造体ポインタ
				short	sync	移動シンク数
				char	dir		退避方向	→１↑２←３↓４
				char	sw		0:復帰	1:退避
===========================================================*/
void	hide_app_win(WINDOW *wp, short sync, char dir, char sw) {
	short	d;
	
	d = (sw) ? 1: -1;
	wp->sx = wp->x;	wp->sy = wp->y;
	wp->sw = wp->w;	wp->sh = wp->h;
	
	if ((auto_on_s==1) && (au_sp!=0))	sync = 1;
	
	switch (dir) {
	case 1:
		wp->dx = wp->x + HIDE_XOFS * d;	break;
	case 2:
		wp->dy = wp->y - HIDE_YOFS * d;	break;
	case 3:
		wp->dx = wp->x - HIDE_XOFS * d;	break;
	case 4:
		wp->dy = wp->y + HIDE_YOFS * d;	break;
	}
	
	wp->cnt = wp->scnt = sync;
	wp->mode = WINMODE_MOVE;
}

/*===========================================================
	ウィンドウ移動
		in:		WINDOW *wp		オペレーション対象
		out:	short			0:処理中	1:完了
===========================================================*/
short	win_move(WINDOW *wp) {
	if (wp->cnt < 1) wp->cnt = 1;
	wp->cnt--;
	wp->x = wp->dx - (wp->dx - wp->sx) * wp->cnt / wp->scnt;
	wp->y = wp->dy - (wp->dy - wp->sy) * wp->cnt / wp->scnt;
	set_win(wp);
	
	if (wp->cnt <= 0)
		return 1;
	else
		return 0;
}

/*===========================================================
	ウィンドウサイズ変更
		in:		WINDOW *wp		オペレーション対象
		out:	short			0:処理中	1:完了
===========================================================*/
short	win_size(WINDOW *wp) {
	if (wp->cnt < 1) wp->cnt = 1;
	wp->w = wp->dw + (wp->sw - wp->dw) * wp->cnt / wp->scnt;
	wp->x = wp->sx + (wp->sw - wp->w) / 2;
	wp->h = wp->dh + (wp->sh - wp->dh) * wp->cnt / wp->scnt;
	wp->y = wp->sy + (wp->sh - wp->h) / 2;
	set_win(wp);
	wp->cnt--;
	if (wp->cnt == 0)
		return 1;
	else
		return 0;
}

/*===========================================================
	ウィンドウ削除
===========================================================*/
void	dispose_window(WINDOW *wp) {
	WINDOW	*befp, *nexp;
	short	i;
	
	if (wp != NULL && wp->active) {
		wp->active = FALSE;
		
		befp = wp->before;
		nexp = wp->next;
		
		if (befp == NULL && nexp == NULL) {
			winlist_top = winlist_tail = NULL;
		} else {
			if (befp == NULL) {
				winlist_top = nexp;
			} else {
				befp->next = nexp;
			}
			if (nexp == NULL) {
				winlist_tail = befp;
			} else {
				nexp->before = befp;
			}
		}
		
		for (i = 0; i < 7; i++) {
			poly_kill(wp->l2p[i]);
			if (i < 3) {
				poly_kill(wp->l4p[i]);
			}
		}
		poly_kill(wp->pp);
		
		memfree((void **)&wp);
		*((void **)&wp) = NULL;
//		(void **)&wp = NULL;
//		(void *)wp = NULL;
	}
}

void (*win_func)(WINDOW *);
/*===========================================================
	ウィンドウ動作
===========================================================*/
void	window_job(WINDOW *wp) {
	char	dispose_flag = FALSE;
	
	switch (wp->mode) {
	case WINMODE_MOVE:
		if (win_move(wp)) {
			wp->mode = WINMODE_NOP;
		}
		break;
	case WINMODE_MOVE_DEL:
		if (win_move(wp))
			dispose_flag = TRUE;
		break;
	case WINMODE_APP:
		if (win_size(wp)) {
			wp->mode = WINMODE_NOP;
		}
		break;
	case WINMODE_DISAPP_DEL:
		if (win_size(wp))
			dispose_flag = TRUE;
		break;
	case WINMODE_DEL:
		dispose_flag = TRUE;
		break;
	case WINMODE_NOP:
	default:
	}
	
	if (wp->func != NULL) {
		win_func = wp->func;
		win_func(wp);
	}
	
	if (dispose_flag == TRUE) {
		dispose_window(wp);
	}
}

/*===========================================================
	ウィンドウドライバ
===========================================================*/
char	ireflag = 0;
void	window_drv() {
	WINDOW	*wp;
	short	i;
	
	if (!ireflag) {
		ireflag = 1;
		wp = winlist_top;
		
		while (wp != NULL) {
			window_job(wp);
			wp = wp->next;
		}
		ireflag = 0;
	}
}
