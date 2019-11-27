/*=====================================================
	toggles.c
	
	パチスロマスターSummy SP
		コンフィグの動作内容ドライバなど
		なんか細かく分割してますけど。
	
						作ってる人		T. Kawakami
						作り出した日	7th Dec. '98
====================================================*/
#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"
#include	"submenu.h"

#include	"kapreach.h"
#include	"binreach.h"

short	det_val[3][3];	// 設定判別表 

signed	char	mr_light[3][21];	// 発光ミニリール番号 

extern	short pad_pat_data[4][5];
#define PAD_STL	pad_pat_data[pad_mode][2]

short	det_play_num;	// 設定判別モードでの判別プレイ数 
//short	out_koya_coin;	// 設定判別モードでの小役総払出し枚数 
short	detplay_get_num;// 判別プレイでの小役獲得回数 

void	calc_det(int, int);
void	yn_panel(WINDOW *);
void	dispose_hawk(void);
WINDOW	*yn_p = NULL;
WINDOW	*mesp_p = NULL;

ROLL_DRUM	r_drum;
signed	char	mesp_sts;	// -1:スリープ0:稼動中
signed	char	yn_sts;		// -1:スリープ0:選択中1:はい2:いいえ
							// １以上は１シンクのみで去る 
char	hawk_setting = 0;	// 目押しランプ設定中 

// リールのセンター位置 [機種][ズームレベル][リール] 
short	reel_center[2][3][3] = {
	 -59,   -6,   46,	// かっぱ　引き 
	 -72,   -7,   57,	// かっぱ　中間 
	 -96,    0,   97,	// かっぱ　寄り 
	 -59,   -7,   46,	// びん　引き 
	 -72,   -8,   55,	// びん　中間 
	 -97,   -1,   95,	// びん　寄り 
};

short	drum_csl_y[2][3][2] = {
	-50, 40, -52, 52, -76, 44,
	-50, 40, -52, 52, -76, 44,
};
short	hawk_sign_y[2][3] = {
	-50, -52, -90,
	-52, -54, -90,
};


//------------------------------------------
// 成立フラグ表示 
struct	_DISPFLAG {
	SPRITE_OBJECT	*flp[8];
	int			disp_num;
	short		y_ofs;
	char		item_max;
	char		flag_copy;
	char		bingo_bup;
};
typedef	struct	_DISPFLAG	DISPFLAG;
DISPFLAG	*dfp = NULL;

/*-------------------------------------------
	成立フラグ表示解放 
-------------------------------------------*/
void	dispose_flagdisp(void) {
	SPRITE_OBJECT	**sopp;
	int				i;
	
	sopp = dfp->flp;
	for (i = 0; i < dfp->item_max; i++) {
		sprobj_kill(*sopp++);
	}
	memfree((void **)&dfp);
	dfp = NULL;
}

/*-------------------------------------------
	成立フラグ表示位置設定
-------------------------------------------*/
void	set_dispflags(DISPFLAG *dfp) {
	SPRITE_OBJECT	**sopp;
	int			i;
	short		cx;
	
	sopp = dfp->flp;
	for (i = 0, cx = -40; i < dfp->disp_num; i++, cx += 80)
		spr_xyset(*sopp++, -100 + cx, 80 + dfp->y_ofs);
	while (i < 8) {
		spr_xyset(*sopp++, HIDE_XOFS, HIDE_YOFS);
		i++;
	}
}

/*-------------------------------------------
	成立フラグ表示のＵＶ設定
-------------------------------------------*/
void	set_flaguv_p(SPRITE_OBJECT *flp, char num) {
	short	c_u, c_v, c_x, c_cy;
	
	c_v = 24 * num;
	c_cy = 247 + num;
	spr_texset(flp, 0,0, 832, 0, 832 + 16 * MACHINE_NO, c_cy);
	spr_uvset(flp, 0, 832 + 20 * MACHINE_NO, c_v);
}

/*-------------------------------------------
	成立フラグ再設定
-------------------------------------------*/
void	reset_dispflags(DISPFLAG *dfp) {
	SPRITE_OBJECT	**sopp;
	int		i;
	
	sopp = dfp->flp;
	dfp->disp_num = 0;
	if (FLAG_BIG) {
		set_flaguv_p(*sopp, 0);
		sopp++;
		dfp->disp_num++;
	}
	if (FLAG_REG) {
		set_flaguv_p(*sopp, 1);
		sopp++;
		dfp->disp_num++;
	}
	if (FLAG_YAKU0) {
		set_flaguv_p(*sopp, 2);
		sopp++;
		dfp->disp_num++;
	}
	if (FLAG_YAKU1) {
		set_flaguv_p(*sopp, 3);
		sopp++;
		dfp->disp_num++;
	}
	if (FLAG_YAKU2) {
		set_flaguv_p(*sopp, 4);
		sopp++;
		dfp->disp_num++;
	}
	
	switch (play_mode) {
	case 4:		// JAC 
		if (FLAG_JAC) {
			set_flaguv_p(*sopp, 7);
			sopp++;
			dfp->disp_num++;
		}
		break;
	case 3:		// BIG
		if (FLAG_JIN) {
			set_flaguv_p(*sopp, 6);
			sopp++;
			dfp->disp_num++;
		}
		break;
	default:	// else
		if (FLAG_REP) {
			set_flaguv_p(*sopp, 5);
			sopp++;
			dfp->disp_num++;
		}
		break;
	}
}
/*-------------------------------------------
	成立フラグ表示のドライバなんですわ
-------------------------------------------*/
void	flagdisp_drv(void) {
	SPRITE_OBJECT	**sopp;
	int			i;
	char		atariflg;
	
	if ((sw_config & 0x2) == 0) {	// 表示フラグ不成立 
		if (dfp != NULL) {
			dispose_flagdisp();
		}
		return;
	}
	
	if (dfp == NULL) {	// ワーク未確保 
		// ワーク確保 
		dfp = (DISPFLAG *)memalloc(sizeof(DISPFLAG), (void **)&dfp);
		
#if 1
		dfp->item_max = 7;
#else
		switch (play_mode) {
		case GAME_NORMAL:
			dfp->item_max = 7;
			break;
		case REACH_BIG:
		case REACH_REG:
		case GAME_BIG:
			dfp->item_max = 5;
			break;
		case GAME_JAC:
			dfp->item_max = 2;
			break;
		}
#endif
		// ポリ確保 
		sopp = dfp->flp;
		for (i = 0; i < dfp->item_max; i++, sopp++) {
			*sopp = sprobj_make();
			spr_texset(*sopp, 0,0, 832, 0, 832, 247);
			spr_xyset(*sopp, HIDE_XOFS, HIDE_YOFS);
			spr_whset(*sopp, 80,24);
			(*sopp)->pri = 20;
			(*sopp)->r = (*sopp)->g = (*sopp)->b = 0x80;
		}
		
		dfp->y_ofs = 32;
		dfp->disp_num = 0;
		dfp->bingo_bup = 0;
	}
	
	atariflg = ((FLAG_BIG) ? 1: 0) << 0;
	atariflg |= ((FLAG_REG) ? 1: 0) << 1;
	atariflg |= ((FLAG_YAKU0) ? 1: 0) << 2;
	atariflg |= ((FLAG_YAKU1) ? 1: 0) << 3;
	atariflg |= ((FLAG_YAKU2) ? 1: 0) << 4;
	switch (play_mode) {
	case 4:	// JAC 
		atariflg |= ((FLAG_JAC) ? 1: 0) << 7;
		break;
	case 3:	// BIG 
		atariflg |= ((FLAG_JIN) ? 1: 0) << 6;
		break;
	default:
		atariflg |= ((FLAG_REP) ? 1: 0) << 5;
		break;
	}
	
	if ((_WK_REEL[0][0] | _WK_REEL[1][0] | _WK_REEL[2][0]) != 0
	 || swp->cur_win == SM_REVIEW) {
		if (atariflg) { // なんか当たってる：つまり表示する 
			if (dfp->bingo_bup != atariflg) {	// Yオフセットを下げるところ 
				dfp->y_ofs = (auto_on && au_sp > 0) ? 0: 32;
				reset_dispflags(dfp);
			}
			if (dfp->y_ofs > 0) dfp->y_ofs -= 2;
			set_dispflags(dfp);
		} else {
			dfp->y_ofs = 32;
			set_dispflags(dfp);
		}
		dfp->bingo_bup = atariflg;
	} else {	// リール停止状態 
		if (cyuusengo == 0) {	// 抽選開始直前 
			dfp->y_ofs = 32;
			set_dispflags(dfp);
		}
		dfp->bingo_bup = 0;
	}
}

//------------------------------------------
// リーチ目ランプ 
char	reachme;
struct	_REACH_LAMP {
	SPRITE_OBJECT	*lampp[3];
	char			*tblp;
};
typedef	struct	_REACH_LAMP	REACH_LAMP;
REACH_LAMP	*rlp = NULL;

/*-------------------------------------------
	リーチ目表示ランプ解放 
-------------------------------------------*/
void	dispose_reachdisp(void) {
	SPRITE_OBJECT	**sopp;
	int				i;
	
	sopp = rlp->lampp;
	for (i = 0; i < 3; i++) {
		sprobj_kill(*sopp++);
	}
	memfree((void **)&rlp);
	rlp = NULL;
}

/*-------------------------------------------
	リーチ目ランプのドライバなんですわ
-------------------------------------------*/
#define	U_REACHLAMP		936
#define	V_REACHLAMP		24
#define	CX_REACHLAMP	944
#define	CY_REACHLAMP	246

void	reachdisp_drv(void) {
	SPRITE_OBJECT	**lpp;
	char			*tbp;
	int				i, c_cy, sw, chki, bf, rf, nf, lp, lf[3];
	static	char	roll_bup = 0;
	static	char	push_out = 0;
	char			tmp, rolling;
	
	if ((sw_config & 0x4) == 0) {	// 表示フラグ不成立 
		if (rlp != NULL) {			// ワーク解放 
			dispose_reachdisp();
		}
		return;
	}
	
	if (rlp == NULL) {
		// ワーク確保 
		rlp = (REACH_LAMP *)memalloc(sizeof(REACH_LAMP), (void **)&rlp);
		// ポリ確保 
		lpp = rlp->lampp;
		for (i = 0; i < 3; i++, lpp++) {
			*lpp = sprobj_make();
			spr_texset(*lpp, 0,0, U_REACHLAMP, V_REACHLAMP, CX_REACHLAMP, CY_REACHLAMP + i);
			spr_uvset(*lpp, 0, U_REACHLAMP, V_REACHLAMP + 16 * i);
			spr_whset(*lpp, 32, 16);
			(*lpp)->r = (*lpp)->g = (*lpp)->b = 0x40;
			(*lpp)->pri = 30;
		}
		rlp->tblp = (machine_no) ? binreach_tbl: kapreach_tbl;
	}
	
	lpp = rlp->lampp;
	tbp = rlp->tblp;
	lp=_WK_REEL[0][5]+(_WK_REEL[1][5]*21)+(_WK_REEL[2][5]*441);
	
	if ((1 << push_type) & tbp[lp])	// 押し順による区別 
		tmp = tbp[lp];
	else
		tmp = 0;
	
	rolling = (_WK_REEL[0][0] | _WK_REEL[1][0] | _WK_REEL[2][0]) ? 1: 0;
	if (mode_game == MODE_NORM) {
		if (roll_bup == 1 && rolling == 0) {
			if (_BF_STOP_CTL == 0 || _NB_PLAY_MEDAL != 3) {
				push_out = 1;
			} else {
				push_out = 0;
			}
		}
	}
	
	if (push_out == 1)
		tmp = 0;
	
	lf[0] = lf[1] = lf[2] = 0;
	lf[0] = tmp & 0x20;
	lf[1] = tmp & 0x40;
	lf[2] = tmp & 0x10;
	
	for (i = 0; i < 3; i++, lpp++) {
		if (rolling == 0 && play_mode < 3) {
			// 全てのドラムが停止中でＢＩＧ／ＲＥＧ中でない 
			sw = (lf[i]) ? 1: 0;
			if (sw)	(*lpp)->r = (*lpp)->g = (*lpp)->b = 0xC0;
			else	(*lpp)->r = (*lpp)->g = (*lpp)->b = 0x40;
		} else {
			(*lpp)->r = (*lpp)->g = (*lpp)->b = 0x40;
		}
		spr_xyset(*lpp, -144, 68 + 12 * i);
	}
	roll_bup = rolling;
#if 1	//  
	FntPrint("p-out %d\n", push_out);
	FntPrint("roll  %d\n", rolling);
	FntPrint("r-bup %d\n", roll_bup);
#endif
}

/*******************************************************/
// 	取りこぼしコメント関連 
struct	_DROP_COMMENT {
	WINDOW	*wp;
	int		counter;
};
typedef	struct	_DROP_COMMENT	DROP_COMMENT;
DROP_COMMENT	*dcp = NULL;
/*-------------------------------------------
	取りこぼし表示解放 
-------------------------------------------*/
void	dispose_dropflag(void) {
	ffnt_close(dcp->wp->moji_id[0]);
	dcp->wp->moji_max = 0;
	sprobj_kill((SPRITE_OBJECT *)dcp->wp->work[0]);
	dispose_window(dcp->wp);
	memfree((void **)&dcp);
	dcp = NULL;
}

void	set_dropuv(SPRITE_OBJECT *flp, int num) {
	spr_uvset(flp, 0, 832 + 20 * MACHINE_NO, 24 * num);
	flp->cx = 832 + 16 * MACHINE_NO;
	flp->cy = 247 + num;
}
/*-------------------------------------------
	取りこぼしコメントパネル位置設定
-------------------------------------------*/
void	set_dropmess(WINDOW *wp) {
	ffnt_xy(wp->moji_id[0], wp->x + 4 + 88, wp->y + 4 + 8);
	spr_xyset((SPRITE_OBJECT *)wp->work[0], wp->x + 4, wp->y + 8);
}
/*-------------------------------------------
	取りこぼしコメント表示ウィンドウ
		moji_id		[0]		文字列部
		work		[0]		役ポリ
					[7]		カウンタ
-------------------------------------------*/
void	dropmess(WINDOW *wp) {
	SPRITE_OBJECT	*yakup;
	int		i;
	
	switch (wp->f_step) {
	case 0:	// 取りこぼしコメントパネル作成 
		wp->moji_id[0] = ffnt_open(wp->x + 4 + 40, wp->y + 4 + 8, 145, FNT_H, (u_short *)fnt_data + STR_TORI_0);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80,0x80,0x80);
		ffnt_priset(wp->moji_id[0], wp->pri - 1);
		
		yakup = (SPRITE_OBJECT *)wp->work[0] = sprobj_make();
		spr_texset(yakup, 0,0, 832, 0, 832, 247);
		spr_uvset(yakup, 0, 832, 0);
		spr_whset(yakup, 80, 24);
		yakup->r = yakup->g = yakup->b = 0x80;
		yakup->pri = wp->pri - 1;
		
		wp->work[7] = 0;
		
		set_dropmess(wp);
		
		wp->f_step++;
		break;
	case 1:
		if (TORIKOBOSHI){
			if 		(FLAG_YAKU0)	i = 2;
			else if (FLAG_YAKU1)	i = 3;
			else if (FLAG_YAKU2)	i = 4;
			else {
				switch (play_mode) {
				case 4:
					i = 7;
					break;
				case 3:
					i = 6;
					break;
				default:
					i = 5;
					break;
				}
			}
			
			set_dropuv((SPRITE_OBJECT *)wp->work[0], i);
			hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
			set_dropmess(wp);
			wp->f_step++;
			TORIKOBOSHI = FALSE;
		}
		break;
	case 2:
		set_dropmess(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step++;
		}
		break;
	case 3:
		wp->work[7]++;
		if (wp->work[7] > 90 || pad_cnt & (PADR_RIGHT|PADR_DOWN|PADR2|PADR1|PADL_DOWN)) {
			wp->work[7] = 0;
			hide_app_win(wp, WIN_CHG_SYNC, 2, 1);
			wp->f_step++;
		}
		break;
	case 4:
		set_dropmess(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = 1;
		}
		break;
	case MENU_NORMAL:
		break;
	}
}
/*-------------------------------------------
	取りこぼしコメント表示ののドライバなんですわ
-------------------------------------------*/
void	dropflag_drv(void) {
	
	if ((sw_config & 0x8) == 0) {	// 表示フラグ不成立 
		if (dcp != NULL) {			// ワーク解放 
			dispose_dropflag();
		}
		return;
	}
	
	if (dcp == NULL) {
		// ワーク確保 
		dcp = (DROP_COMMENT *)memalloc(sizeof(DROP_COMMENT), (void **)&dcp);
		
		dcp->wp = make_window(MENU_LEFT - 4, -20 - HIDE_YOFS, FNT_W * 15 + 8, 32 + 8, 26, &dropmess);
	}
}

/***************************************************
****************************************************
***************** 設定判別表 ***********************
****************************************************
***************************************************/
WINDOW	*dets = NULL;
/*-------------------------------------------
	設定判別表解放 
-------------------------------------------*/
void	dispose_detsheet(void) {
	SPRITE_OBJECT	**sopp;
	int				i;
	
	for (i = 0; i < dets->moji_max; i++) {
		ffnt_close(dets->moji_id[i]);
	}
	dets->moji_max = 0;
	
	sopp = (SPRITE_OBJECT **)dets->work[0];
	for (i = 0; i < 36; i++) {
		sprobj_kill(*sopp++);
	}
	memfree((void **)&dets->work[0]);
	
	dispose_window(dets);
	dets = NULL;
}
/*-------------------------------------------
	設定判別表の数字スプライトのＵＶ設定
-------------------------------------------*/
void	set_dsheet_uv(SPRITE_OBJECT **pp) {
	int		i, j;
	
	for (i = 0; i < 3; i++) {
		set_8wvals(pp, det_val[i][0], 3, 0);
		pp += 3;
		for (j = 1; j < 3; j++) {
			set_8wvals(pp, det_val[i][j], 4, 0);
			pp += 4;
		}
		set_8wnum(*pp++, 11);
	}
}
/*-------------------------------------------
	設定判別表の具位置設定
-------------------------------------------*/
void	set_dsheet_nums(WINDOW *wp) {
	SPRITE_OBJECT	**pp;
	int				i, j;
	short			y_p;
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 3);
	
	pp = (SPRITE_OBJECT **)wp->work[0];
	y_p = wp->y + 17;
	for (i = 0; i < 3; i++, y_p += 15) {
		set_8wval(pp, wp->x + 16, y_p, 3);
		pp += 3;
		set_8wval(pp, wp->x + 88, y_p, 4);
		pp += 4;
		set_8wval(pp, wp->x + 136, y_p, 4);
		pp += 4;
		spr_xyset(*pp++, wp->x + 134, y_p);
	}
}
/*-------------------------------------------
	設定判別表
		moji_id		[0]		固定子
		work		[0]		数字ポリ×１４×３ 
					[1]		前シンクのplay_num
					[2]		hide_flag	1:hide
					[3]		前シンクの[2]
-------------------------------------------*/
void	det_sheet(WINDOW *wp) {
	SPRITE_OBJECT	**sprpp;
	int			i;
	
	switch (wp->f_step) {
	case 0:
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, wp->w, 16, (u_short *)fnt_data + STR_DET_SHEET);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		
		sprpp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 36, (void **)&wp->work[0]);
		for (i = 0; i < 36; i++, sprpp++) {
			*sprpp = sprobj_make();
			(*sprpp)->r = (*sprpp)->g = 0x80;
			(*sprpp)->b = 0x40;
			(*sprpp)->pri = wp->pri - 1;
			spr_texset(*sprpp, 0, 0, 928, 76, 944, 250);
			spr_whset(*sprpp, 8, 16);
		}
		wp->work[1] = play_num - replay_num;
		calc_det(koyakucnt_reset, play_num - replay_num);
		set_dsheet_uv((SPRITE_OBJECT **)wp->work[0]);
		set_dsheet_nums(wp);
		
		wp->work[3] = wp->work[2] = 0;
		
		wp->f_step = MENU_NORMAL;
		break;
	case MENU_NORMAL:
		if ((_WK_REEL[0][0] | _WK_REEL[1][0] | _WK_REEL[2][0]) == 0) {
		// 全ドラム停止 
			wp->work[2] = 0;
		} else {
			wp->work[2] = 1;
		}
		
		if (wp->work[2] != wp->work[3]) {
			if (wp->work[2] > 0) {	// 隠す 
				wp->x = HIDE_XOFS;	wp->y = HIDE_YOFS;
			} else {
				wp->x = MENU_LEFT - 24;	wp->y =  MENU_TOP + 22;
			}
			set_win(wp);
			set_dsheet_nums(wp);
		}
		wp->work[3] = wp->work[2];
		if (wp->work[1] != play_num - replay_num) {
			calc_det(koyakucnt_reset, play_num - replay_num);
			wp->work[1] = play_num - replay_num;
		}
		set_dsheet_uv((SPRITE_OBJECT **)wp->work[0]);
		break;
	}
}
/*-------------------------------------------
	設定判別表ドライバ
-------------------------------------------*/
void	detsheet_drv(void) {
	int			i;
	
	if (detect_level_flg[2] == 0) {
		if (dets != NULL) {
			dispose_detsheet();
		}
		return;
	}
	
	if (dets == NULL) {
		dets = make_window(MENU_LEFT - 24, MENU_TOP + 22, FNT_W * 11 + 8, 2 + FNT_H * 4, 30, &det_sheet);
	}
}


/***************************************************
****************************************************
*************** 台情報表示関連 *********************
****************************************************
***************************************************/
WINDOW	*pinfp;
short	pinf_item[6] = {
	STR_PINF_00, STR_PINF_01, STR_PINF_02,
	STR_PINF_1, STR_PINF_2, STR_PINF_3,
};
short	pinf_c_item[3] = {
	STR_CPINF_0, STR_CPINF_1, STR_CPINF_2,
};
/*-------------------------------------------
	プレイ情報表記解放 
-------------------------------------------*/
void	dispose_playnf(void) {
	SPRITE_OBJECT	**sopp;
	int				i, spr_max;
	
	switch (mode_game) {
	case MODE_NORM:
		spr_max = 26;
		break;
	case MODE_UNLOCK:
		spr_max = 3;
		break;
	case MODE_CHECK:
		spr_max = 13;
		break;
	case MODE_CROSS:
		spr_max = 22;
		break;
	}
	
	for (i = 0; i < pinfp->moji_max; i++) {
		ffnt_close(pinfp->moji_id[i]);
	}
	pinfp->moji_max = 0;
	
	sopp = (SPRITE_OBJECT **)pinfp->work[0];
	for (i = 0; i < spr_max; i++) {
		sprobj_kill(*sopp++);
	}
	memfree((void **)&pinfp->work[0]);
	
	dispose_window(pinfp);
	pinfp = NULL;
}

/*-------------------------------------------
	台表時ウィンドウのuv設定
-------------------------------------------*/
void	set_pinf_uv(SPRITE_OBJECT **pp) {
	set_8wvals(pp, PLAYTIME_HOUR, 2, 0);
	pp += 2;
	set_8wvals(pp, PLAYTIME_MIN, 2, 2);
	pp += 2;
	set_8wnum(*pp++, 14);	// ":" 
	set_8wvals(pp, hand_medal + ((_NB_CREDIT_LED != 0xFF) ? _NB_CREDIT_LED: 0), 6, 0);
	pp += 6;
	set_8wvals(pp, bb_shot_coin - bb_toushi_coin, 3, 0);
	pp += 3;
	
	if (bb_firstend > 0
//	if (bingo_n_bb > 1
//	 || bingo_n_bb == 1 && !(_FL_ACTION&(0x01<<BT_BB))
	 ) {	// 一度ＢＩＧを取るまではハイフン表示 
		set_8wvals(pp, MAEKARA_BIG, 4, 0);
		pp += 4;
	} else {
		int		i;
		
		for (i = 0; i < 4; i++) {
			set_8wnum(*pp++, 11);
		}
	}
	set_8wvals(pp, KAISU_BIG, 4, 0);
	pp += 4;
	set_8wvals(pp, KAISU_REG, 4, 0);
}
/*-------------------------------------------
	設定判別モード台表時ウィンドウのuv設定
-------------------------------------------*/
void	set_d_pinf_uv(SPRITE_OBJECT **pp) {
	set_8wvals(pp, play_num - replay_num, 3, 0);
	pp += 3;
	set_8wvals(pp, det_play_num, 3, 0);
	pp += 3;
	set_8wvals(pp, out_coin_nrb, 4, 0);
	pp += 4;
	set_8wvals(pp, detplay_get_num, 3, 0);
}
/*-------------------------------------------
	台表時ウィンドウの数値位置設定
-------------------------------------------*/
void	set_pinf_nums(WINDOW *wp) {
	SPRITE_OBJECT	**pp;
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	ffnt_xy(wp->moji_id[1], wp->x + 4, wp->y + 18);
	ffnt_xy(wp->moji_id[2], wp->x + 4, wp->y + 32);
	ffnt_xy(wp->moji_id[3], wp->x + 4 + 136, wp->y + 4);
	ffnt_xy(wp->moji_id[4], wp->x + 4 + 152, wp->y + 18);
	ffnt_xy(wp->moji_id[5], wp->x + 4 + 152, wp->y + 32);
	
	pp = (SPRITE_OBJECT **)wp->work[0];
	
	set_8wval(pp, wp->x + 4 + 80, wp->y + 4, 2);	// 時間 
	pp += 2;
	set_8wval(pp, wp->x + 4 + 104, wp->y + 4, 2);	// 分 
	pp += 2;
	spr_xyset(*pp++, wp->x + 4 + 104, wp->y + 4);	// ":" 
	
	set_8wval(pp, wp->x + 4 + 216, wp->y + 4, 6);
	pp += 6;
	set_8wval(pp, wp->x + 4 + 88, wp->y + 18, 3);
	pp += 3;
	set_8wval(pp, wp->x + 4 + 208, wp->y + 18, 4);
	pp += 4;
	set_8wval(pp, wp->x + 4 + 80, wp->y + 32, 4);
	pp += 4;
	set_8wval(pp, wp->x + 4 + 232, wp->y + 32, 4);
}
/*-------------------------------------------
	設定変更判別モード：プレイ情報ウィンドウ具設定
-------------------------------------------*/
void	set_c_pinf_uv(SPRITE_OBJECT **pp) {
	int	i;
	
	set_8wvals(pp, play_num, 5, 0);
	pp += 5;
	set_8wvals(pp, out_coin - use_coin, 7, 0);
	pp += 7;
	if (p_per_t_ir > 0) {	// 千円当りのプレイ数が確定できない間は伏せる 
		set_8wvals(pp, p_per_t_ir, 5, 0);
		pp += 5;
		set_8wvals(pp, p_per_t_nr, 5, 0);
		pp += 5;
	} else {
		for (i = 0; i < 10; i++) {
			set_8wnum(*pp++, 11);
		}
	}
}
/*-------------------------------------------
	設定変更判別モード：プレイ情報ウィンドウの具設置
-------------------------------------------*/
void	set_c_pinf_nums(WINDOW *wp) {
	SPRITE_OBJECT	**pp;
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	ffnt_xy(wp->moji_id[1], wp->x + 4, wp->y + 18);
	ffnt_xy(wp->moji_id[2], wp->x + 4, wp->y + 32);
	
	pp = (SPRITE_OBJECT **)wp->work[0];
	
	set_8wval(pp, wp->x + 4 + 80, wp->y + 4, 5);
	pp += 5;
	set_8wval(pp, wp->x + 4 + 231, wp->y + 4, 7);
	pp += 7;
	set_8wval(pp, wp->x + 4 + 247, wp->y + 18, 5);
	pp += 5;
	set_8wval(pp, wp->x + 4 + 247, wp->y + 32, 5);
}
/*-------------------------------------------
	リプレイはずしモード：プレイ情報ウィンドウの具設置
-------------------------------------------*/
void	set_u_pinf_nums(WINDOW *wp) {
	SPRITE_OBJECT	**pp;
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	
	pp = (SPRITE_OBJECT **)wp->work[0];
	set_8wval(pp, wp->x + 4 + 88, wp->y + 4, 3);
}
void	set_d_pinf_xy(WINDOW *wp, SPRITE_OBJECT **spp) {
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	ffnt_xy(wp->moji_id[1], wp->x + 4, wp->y + 18);
	
	set_8wval(spp, wp->x + 4 + 88, wp->y + 4, 3);
	spp += 3;
	set_8wval(spp, wp->x + 4 + 232, wp->y + 4, 3);
	spp += 3;
	set_8wval(spp, wp->x + 4 + 80, wp->y + 18, 4);
	spp += 4;
	set_8wval(spp, wp->x + 4 + 232, wp->y + 18, 3);
	spp += 3;
}

/*-------------------------------------------
	台情報表示ウィンドウ
		moji_id		[0～3]		固定物
		work		[0]		数値ポリズポインタ
-------------------------------------------*/
void	panel_pinf(WINDOW *wp) {
	SPRITE_OBJECT	**sprpp;
	int			i;
	
	switch (wp->f_step) {
	case 0:
		for (i = 0; i < 6; i++) {
			pinfp->moji_id[i] = ffnt_open(pinfp->x, pinfp->y, 161, 16 + ((i == 0) ? 48: 16), (u_short *)fnt_data + pinf_item[i]);
			pinfp->moji_max++;
			ffnt_color(pinfp->moji_id[i], 0x80,0x80,0x80);
			ffnt_priset(pinfp->moji_id[i], wp->pri - 1);
		}
		
		sprpp = (SPRITE_OBJECT **)pinfp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 26, (void **)&pinfp->work[0]);
		for (i = 0; i < 26; i++, sprpp++) {
			*sprpp = sprobj_make();
			(*sprpp)->r = (*sprpp)->g = 0x80;
			(*sprpp)->b = 0x40;
			(*sprpp)->pri = wp->pri - 1;
			spr_texset(*sprpp, 0, 0, 928, 76, 944, 250);
			spr_whset(*sprpp, 8, 16);
		}
		set_pinf_uv((SPRITE_OBJECT **)pinfp->work[0]);
		set_pinf_nums(pinfp);
		
		pinfp->f_step = MENU_NORMAL;
		break;
	case MENU_NORMAL:
		set_pinf_uv((SPRITE_OBJECT **)pinfp->work[0]);
		break;
	}
}
/*-------------------------------------------
	設定変更判別台情報表示ウィンドウ
		moji_id		[0]		固定物
		work		[0]		数値ポリズポインタ
-------------------------------------------*/
void	panel_c_pinf(WINDOW *wp) {
	SPRITE_OBJECT	**npp;
	int			i;
	
	switch (wp->f_step) {
	case 0:
		for (i = 0; i < 3; i++) {
			wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, wp->w, 48, (u_short *)fnt_data + pinf_c_item[wp->moji_max]);
			ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
			ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
			wp->moji_max++;
		}
		
		npp = (SPRITE_OBJECT **)pinfp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 22, (void **)&wp->work[0]);
		for (i = 0; i < 22; i++, npp++) {
			*npp = sprobj_make();
			(*npp)->r = (*npp)->g = 0x80;
			(*npp)->b = 0x40;
			(*npp)->pri = wp->pri - 1;
			spr_texset(*npp, 0,0, 928, 76, 944, 250);
			spr_whset(*npp, 8, 16);
		}
		set_c_pinf_uv((SPRITE_OBJECT **)wp->work[0]);
		set_c_pinf_nums(wp);
		
		pinfp->f_step = MENU_NORMAL;
		break;
	case MENU_NORMAL:
		set_c_pinf_uv((SPRITE_OBJECT **)pinfp->work[0]);
		break;
	}
}
/*-------------------------------------------
	リプレイはずし台情報表示ウィンドウ
		moji_id		[0～3]		固定物
		work		[0]		数値ポリズポインタ
-------------------------------------------*/
void	panel_u_pinf(WINDOW *wp) {
	SPRITE_OBJECT	**sprpp;
	int			i;
	
	switch (wp->f_step) {
	case 0:
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 145, 16, (u_short *)fnt_data + STR_PINF_01);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		
		sprpp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 3, (void **)&wp->work[0]);
		for (i = 0; i < 3; i++, sprpp++) {
			*sprpp = sprobj_make();
			(*sprpp)->r = (*sprpp)->g = 0x80;
			(*sprpp)->b = 0x40;
			(*sprpp)->pri = wp->pri - 1;
			spr_texset(*sprpp, 0, 0, 928, 76, 944, 250);
			spr_whset(*sprpp, 8, 16);
		}
		sprpp -= 3;
		set_8wvals(sprpp, bb_shot_coin - bb_toushi_coin, 3, 0);
		set_u_pinf_nums(wp);
		
		wp->f_step = MENU_NORMAL;
		break;
	case MENU_NORMAL:
		set_8wvals((SPRITE_OBJECT **)wp->work[0], bb_shot_coin - bb_toushi_coin, 3, 0);
		break;
	}
}
/*-------------------------------------------
	設定判別台情報表示ウィンドウ
		moji_id		[0～1]		固定物
		work		[0]		数値ポリズポインタ
-------------------------------------------*/
void	panel_d_pinf(WINDOW *wp) {
	SPRITE_OBJECT	**sprpp;
	int			i;
	
	switch (wp->f_step) {
	case 0:
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 225, 16, (u_short *)fnt_data + STR_DPINF_0);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 225, 16, (u_short *)fnt_data + STR_DPINF_1);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		
		sprpp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 13, (void **)&wp->work[0]);
		for (i = 0; i < 13; i++, sprpp++) {
			*sprpp = sprobj_make();
			(*sprpp)->r = (*sprpp)->g = 0x80;
			(*sprpp)->b = 0x40;
			(*sprpp)->pri = wp->pri - 1;
			spr_texset(*sprpp, 0, 0, 928, 76, 944, 250);
			spr_whset(*sprpp, 8, 16);
		}
		sprpp -= 13;
		set_d_pinf_uv(sprpp);
		set_d_pinf_xy(wp, sprpp);
		
		wp->f_step = MENU_NORMAL;
		break;
	case MENU_NORMAL:
		set_d_pinf_uv((SPRITE_OBJECT **)wp->work[0]);
		break;
	}
}
/*-------------------------------------------
	台情報表示
-------------------------------------------*/
void	playnf_drv(void) {
	int			i;
	
	if ((sw_config & 0x10) == 0) {
		if (pinfp != NULL) {
			dispose_playnf();
		}
		return;
	}
	
	if (pinfp == NULL) {
		switch (mode_game) {
		case 0:
			pinfp = make_window(MENU_LEFT - 24, MENU_TOP - 12, FNT_W * 19, 3 + FNT_H * 3, 28, &panel_pinf);
			break;
		case MODE_UNLOCK:
			pinfp = make_window(MENU_LEFT - 24, MENU_TOP - 12, FNT_W * 10, 8 + FNT_H, 28, &panel_u_pinf);
			break;
		case MODE_CHECK:
			pinfp = make_window(MENU_LEFT - 24, MENU_TOP - 12, FNT_W * 17, 5 + FNT_H * 2, 28, &panel_d_pinf);
			break;
		case MODE_CROSS:
			pinfp = make_window(MENU_LEFT - 24, MENU_TOP - 12, FNT_W * 19, 3 + FNT_H * 3, 28, &panel_c_pinf);
			break;
		}
	}
}
/**********************************************************/
// ＯＮ／ＯＦＦ小窓 
short	onfwin_xpos[2][3][3] = {
	 -84,  -32,  24,	// かっぱ引き 
	 -96,  -32,  34,
	-122,  -24,  74,
	 -84,  -32,  24,	// BIN貧引き 
	 -96,  -32,  34,
	-120,  -22,  74,
};
/*-------------------------------------------
	ＯＮ／ＯＦＦ表示ウィンドウの位置設定など
-------------------------------------------*/
void	set_onoff_panel(WINDOW *wp, int zoom_l) {
	SPRITE_OBJECT	*sprp;
	
	sprp = (SPRITE_OBJECT *)wp->work[0];
	if (wp->work[4] != zoom_l) {
		wp->x = onfwin_xpos[MACHINE_NO][zoom_l][wp->work[1]];
		wp->y = 72;
		set_win(wp);
		wp->work[4] = ZOOM_LEVEL;
	}
	spr_xyset(sprp, wp->x + 4, wp->y + 3);
}
/*-------------------------------------------
	ＯＮ／ＯＦＦ表示ウィンドウ解放
-------------------------------------------*/
void	dispose_onoff(WINDOW **wpp) {
	int		i;
	
	for (i = 0; i < 3; i++, wpp++) {
		sprobj_kill((SPRITE_OBJECT *)(*wpp)->work[0]);
		dispose_window(*wpp);
	}
}
/*-------------------------------------------
	ＯＮ／ＯＦＦ表示ウィンドウ
		work		[0]		ＯＮ／ＯＦＦスプライト
					[1]		自分の番号　左から0,1,2
					[2]		今の値
					[3]		押し位置
					[4]		表示ズームレベル
-------------------------------------------*/
void	onoff_panel(WINDOW *wp) {
	SPRITE_OBJECT	*sprp;
	char			*reelinfp;
	int				i;
	
	switch (wp->f_step) {
	case 0:
		sprp = (SPRITE_OBJECT *)wp->work[0] = sprobj_make();
		sprp->r = sprp->g = sprp->b = 0x80;
		sprp->pri = wp->pri - 1;
		spr_texset(sprp, 0,0, 952, 0, 944, 250);
		spr_uvset(sprp, 0, 952, (wp->work[2]) ? 0: 16);
		spr_whset(sprp, 32, 16);
		
		wp->work[4] = -1;	// 最初は不定にする 
		set_onoff_panel(wp, ZOOM_LEVEL);
		
		wp->f_step = MENU_NORMAL;
		break;
	case MENU_NORMAL:
		if (wp->work[2] != ((hawkd_flag >> wp->work[1]) & 1)) {
			wp->work[2] = ((hawkd_flag >> wp->work[1]) & 1);
			spr_uvset((SPRITE_OBJECT *)wp->work[0], 0, 952, (wp->work[2]) ? 0: 16);
			set_onoff_panel(wp, ZOOM_LEVEL);
		}
		break;
	}
}

/**********************************************************/
// 滑りコマ数表示のエリア 
void	set_slide_panel(WINDOW *wp, int zoom_l) {
	SPRITE_OBJECT	*sprp;
	
	sprp = (SPRITE_OBJECT *)wp->work[0];
	if (wp->work[4] != zoom_l) {
		wp->x = reel_center[MACHINE_NO][zoom_l][wp->work[1]] - wp->w / 2;
		wp->y = 72;
		set_win(wp);
		wp->work[4] = ZOOM_LEVEL;
	}
	spr_xyset(sprp, wp->x + 4, wp->y + 4);
}

/*-------------------------------------------
	滑りコマ表示ウィンドウ
		work		[0]		数値ポリポインタ
					[1]		自分の番号　左から0,1,2
					[2]		今の値
					[3]		押し位置
					[4]		表示ズームレベル
-------------------------------------------*/
void	slide_panel(WINDOW *wp) {
	SPRITE_OBJECT	*sprp;
	char		*reelinfp;
	int			i;
	
	switch (wp->f_step) {
	case 0:	// すべりコマ数表示コメントパネル作成 
		sprp = (SPRITE_OBJECT *)wp->work[0] = sprobj_make();
		sprp->r = sprp->g = sprp->b = 0x80;
		sprp->pri = wp->pri - 1;
		
		spr_texset(sprp, 0,0, 928, 76, 944, 250);
		set_8wnum(sprp, 11);
		spr_whset(sprp, 8, 16);
		
		wp->work[4] = -1;
		set_slide_panel(wp, ZOOM_LEVEL);
		
		wp->f_step = MENU_NORMAL;
		break;
	case MENU_NORMAL:
		reelinfp = _WK_REEL[wp->work[1]];
		switch (reelinfp[0]) {
		case 0:
			if (wp->work[2] < 0) {
				wp->work[2] = reelinfp[5] - wp->work[3];
				if (wp->work[3] > reelinfp[5]) wp->work[2] += 21;
				
				set_8wnum((SPRITE_OBJECT *)wp->work[0], wp->work[2]);
			}
			break;
		case 1:
			if (wp->work[2] > -1) {
				wp->work[2] = -1;
				set_8wnum((SPRITE_OBJECT *)wp->work[0], 11);
			}
			if (wp->work[3] > -1) wp->work[3] = -1;
			break;
		case 3:
			if (wp->work[3] < 0) wp->work[3] = stp_reel_buf[wp->work[1]] + 1;
			break;
		}
		if (wp->work[4] != ZOOM_LEVEL) {
			set_slide_panel(wp, ZOOM_LEVEL);
		}
		break;
	}
}
/*-------------------------------------------
	すべりコマ数表示解放
-------------------------------------------*/
static	WINDOW	*slidep[3] = {NULL, NULL, NULL};
void	dispose_slide(void) {
	int		i;
	
	for (i = 0; i < 3; i++) {	// 解放 
		sprobj_kill((SPRITE_OBJECT *)slidep[i]->work[0]);
		
		dispose_window(slidep[i]);
		slidep[i] = NULL;
	}
}
/*-------------------------------------------
	滑りコマ数表示
-------------------------------------------*/
void	slide_drv(void) {
	int		i;
	short	c_x;
	
	if ((sw_config & 0x40) == 0) {	// 表示フラグ寝ている 
		if (slidep[0] != NULL) {	// ３つ同時に扱うので先頭のみチェック 
			dispose_slide();
		}
		return;
	}
	
	if (slidep[0] == NULL) {
		c_x = -88;
		for (i = 0; i < 3; i++, c_x += 64) {
			slidep[i] = make_window(c_x, 72, 16, 24, 36, &slide_panel);
			slidep[i]->work[1] = i;
		}
	}
}

/**********************************************************
 リール配列 
***********************************************************/
char	reel_item_n[2][3][21] = {
	5, 0, 6, 4, 1, 3, 4,	// かっぱっぱ：左回胴 
	3, 4, 6, 2, 5, 3, 0,
	6, 4, 3, 4, 6, 2, 3,
	
	6, 0, 5, 6, 1, 4, 5,	// かっぱっぱ：中回胴 
	6, 3, 2, 4, 5, 6, 3,
	5, 4, 6, 5, 1, 5, 4,
	
	4, 0, 6, 1, 4, 3, 6,	// かっぱっぱ：右回胴 
	4, 5, 2, 3, 6, 4, 5,
	1, 5, 6, 4, 5, 6, 3,
	
	4, 0, 5, 2, 6, 4, 2,	// BIN貧神さま：左回胴 
	5, 0, 3, 6, 4, 1, 3,
	3, 6, 4, 3, 3, 1, 6,
	
	6, 0, 4, 6, 5, 5, 3,	// BIN貧神さま：中回胴 
	4, 6, 5, 4, 5, 4, 6,
	1, 4, 6, 2, 5, 5, 4,
	
	4, 0, 6, 4, 2, 6, 5,	// BIN貧神さま：右回胴 
	5, 4, 3, 6, 4, 3, 6,
	1, 1, 4, 5, 6, 4, 2,
	
};
short	mreel_xpos[2][3][3] = {
	90, 111, 132,
	-48, 16, 80,
	-56, 38, 132,
	89, 111, 133,
	-48, 16, 80,
	-56, 38, 132,
};
/*************************************************
	ミニリール表示のエリア	*/
struct	_MINI_REEL {
	SPRITE_OBJECT	*reel_item[21];	// リールの具用 
	SPRITE_OBJECT	*pointer[3];	// リールのポインタ用 
	char			*reel_in;		// リールの具の番号 
	POLY_F4			*wboard;		// 白板 
	int				id;				// リール番号 
	int				p_pos[3];		// ポインタ位置 
	int				reelback;		// 前シンクのリール状態 
	int				zoom;			// 画面ズームモード 
	int				step;
	char			bright;		// 輝度 
	char			b_dir;
};
typedef	struct	_MINI_REEL	MINI_REEL;
MINI_REEL	*mini_r[3] = {NULL, NULL, NULL};
/*-------------------------------------------
	ミニリール表示更新
-------------------------------------------*/
void	set_minireel(MINI_REEL *mrp) {
	SPRITE_OBJECT	**sprp;
	int		i, ofs;
	short	c_x, c_y;
	
	c_x = mreel_xpos[MACHINE_NO][ZOOM_LEVEL][mrp->id];
	
	if (mrp->zoom != ZOOM_LEVEL) {
		// 白板 
		poly_xyset(mrp->wboard, c_x - 4, -103, 20, 212);
		
		// 具 
		c_y = -106;
		sprp = mrp->reel_item;
		for (i = 0; i < 21; i++, sprp++, c_y += 10) {
			spr_xyset(*sprp, c_x - 6, c_y);
		}
		
		mrp->zoom = ZOOM_LEVEL;
	}
	
	// ポインタ 
	ofs = 0;
	if (_WK_REEL[mrp->id][0] < 1) {
		if ((vcount % 30) / 15)	ofs = HIDE_XOFS;
	}
	
	c_y = -105;
	if (mrp->p_pos[0] > 0) c_y += 10 * (21 - mrp->p_pos[0]);
	spr_xyset(mrp->pointer[0], c_x - 6 + ofs, c_y);
	c_y = -105;
	if (mrp->p_pos[1] > 0) c_y += 10 * (21 - mrp->p_pos[1]);
	spr_xyset(mrp->pointer[1], c_x - 6 + ofs, c_y);
}

/*-------------------------------------------
	ミニリール表示のプライオリティ変更
-------------------------------------------*/
void	set_mini_pri(int pri) {
	SPRITE_OBJECT	*sp;
	MINI_REEL		*mp;
	int		i, j;
	
	for (i = 0; i < 3; i++) {
		mp = mini_r[i];
		poly_priset(mp->wboard, pri);
		for (j = 0; j < 21; j++) {
			sp = mp->reel_item[j];
			sp->pri = pri - 1;
		}
		mp->pointer[0]->pri = pri - 1;
		mp->pointer[1]->pri = pri - 1;
	}
}
/*-------------------------------------------
	ミニリール表示のシンク毎処理
-------------------------------------------*/
void	minireel_disp(MINI_REEL *mrp) {
	SPRITE_OBJECT	*sprp;
	int		i;
	short	c_x, c_y, c_u, c_v, c_cx, c_cy;
	
	switch (mrp->step) {
	case 0:
		mrp->reel_in = reel_item_n[MACHINE_NO][mrp->id];
		c_x = -88 + 64 * mrp->id;
		c_y = -106;
		// 白板 
		mrp->wboard = poly_f4_make();
		mrp->wboard->r0 = 0xC0;
		mrp->wboard->g0 = 0xC0;
		mrp->wboard->b0 = 0xC0;
		poly_priset(mrp->wboard, 32);
		// 具 
		for (i = 0; i < 21; i++, c_y += 10) {
			c_u = 896 + 6 * *mrp->reel_in;
			c_v = 192 + 16 * MACHINE_NO;
			c_cx = 928 + 16 * MACHINE_NO;
			c_cy = 233 + *mrp->reel_in++;
			
			sprp = mrp->reel_item[i] = sprobj_make();
			sprp->r = sprp->g = sprp->b = 0x80;
			sprp->pri = 31;
			
			spr_texset(sprp, 0,0,c_u, c_v, c_cx, c_cy);
			spr_uvset(sprp, 0, c_u, c_v);
			spr_whset(sprp, 24, 16);
		}
		// カーソル 
		sprp = mrp->pointer[0] = sprobj_make();
		sprp->r = sprp->g = sprp->b = 0x80;
		sprp->pri = 30;
		spr_texset(sprp, 0,0, 896, 36, 928, 249);
		spr_uvset(sprp, 0, 896, 36);
		spr_whset(sprp, 30, 16);
		sprp = mrp->pointer[1] = sprobj_make();
		sprp->r = sprp->g = sprp->b = 0xF0;
		sprp->pri = 30;
		spr_texset(sprp, 0,0, 920, 108, 896, 254);
		spr_uvset(sprp, 0, 920, 108);
		spr_whset(sprp, 30, 16);
		
		mrp->p_pos[1] = _WK_REEL[mrp->id][5];
		mrp->bright = 0x80;
		mrp->b_dir = 1;
		set_minireel(mrp);
		
		mrp->step++;
		break;
	case 1:
		mrp->bright += mrp->b_dir * 8;
		if (mrp->bright >= 0xF8)		mrp->b_dir = -1;
		else if (mrp->bright <= 0x20)	mrp->b_dir = 1;
		
		sprp = mrp->reel_item[0];
		if (mr_light[mrp->id][0] != 0) {
			sprp->r = sprp->g = sprp->b = mrp->bright;
		} else {
			sprp->r = sprp->g = sprp->b = 0x80;
		}
		for (i = 1; i < 21; i++) {
			sprp = mrp->reel_item[i];
			if (mr_light[mrp->id][21 - i]) {
				sprp->r = sprp->g = sprp->b = mrp->bright;
			} else {
				sprp->r = sprp->g = sprp->b = 0x80;
			}
		}
		
		mrp->p_pos[0] = _WK_REEL[mrp->id][5];
		
		if (mode_game == MODE_REACH) {
			mrp->p_pos[1] = mrp->p_pos[0];
		} else {
			switch (_WK_REEL[mrp->id][0]) {
			case 1:
			case 2:
				mrp->p_pos[1] = _WK_REEL[mrp->id][5];
				break;
			case 3:
				if (mrp->reelback != 3) {
					mrp->p_pos[1] = stp_reel_buf[mrp->id] + 1;
				}
				break;
			default:
				break;
			}
		}
		set_minireel(mrp);
		mrp->reelback = _WK_REEL[mrp->id][0];
		break;
	}
}

/*-------------------------------------------
	ミニリール表示解放 
-------------------------------------------*/
void	dispose_mini(void) {
	int		i, j;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 21; j++) {
			sprobj_kill(mini_r[i]->reel_item[j]);
		}
		sprobj_kill(mini_r[i]->pointer[0]);
		sprobj_kill(mini_r[i]->pointer[1]);
		poly_kill((void *)mini_r[i]->wboard);
		memfree((void **)&mini_r[i]);
		mini_r[i] = NULL;
	}
}
/*-------------------------------------------
	ミニリール表示のドライバ
-------------------------------------------*/
void	mini_drv(void) {
	int		i, j;
	
	if ((sw_config & 0x20) == 0) {
		if (mini_r[0] != NULL) {
			dispose_mini();
		}
		return;
	}
	
	if (mini_r[0] == NULL) {
		signed char	*mr_p;
		
		mr_p = &mr_light[0][0];
		for (i = 0; i < 3; i++) {
			mini_r[i] = (MINI_REEL *)memalloc(sizeof(MINI_REEL), (void **)&mini_r[i]);
			mini_r[i]->id = i;
			mini_r[i]->step = 0;
			mini_r[i]->zoom = -1;	// 最初は不定にしておく 
			for (j = 0; j < 21; j++) {
				*mr_p++ = 0;
			}
		}
	} else {
		for (i = 0; i < 3; i++) {
			minireel_disp(mini_r[i]);
		}
		if ((_WK_REEL[0][0] | _WK_REEL[1][0] | _WK_REEL[2][0]) == 0) {
		// 全ドラム停止 
			set_mini_pri(32);
		} else {
			set_mini_pri(24);
		}
	}
}

/*************************************************
	目押しパネルのエリア	*/
struct	_HAWK_LAMP {
	SPRITE_OBJECT	*hlamp[3];		// ランプ用 
//	char			set;
};
typedef	struct	_HAWK_LAMP	HAWK_LAMP;
HAWK_LAMP	*hlampp;

/*-------------------------------------------
	目押しランプ関連解放
-------------------------------------------*/
void	dispose_hawk(void) {
	int		i;
	
	if (hlampp == NULL) return;
	for (i = 0; i < 3; i++) {
		sprobj_kill(hlampp->hlamp[i]);
	}
	memfree((void **)&hlampp);
}
/*-------------------------------------------
	目押しランプ表示
-------------------------------------------*/
void	hawk_lamp(void) {
	SPRITE_OBJECT *sp;
	int		i, a, b,/* c, */c_r, hilow;
	short	xp;
	
	if ((_WK_REEL[0][0] | _WK_REEL[1][0] | _WK_REEL[2][0]) == 0) {
	// 全ドラム停止 
		hilow = 32;
	} else {
		hilow = 24;
	}
	
	for (i = 0; i < 3; i++) {
		sp = hlampp->hlamp[i];
		
		sp->pri = hilow;
		
		a = (hawk_pos[i] + 20) % 21;
		b = hawk_pos[i];
//		c = (hawk_pos[i] + 1) % 21;
		c_r = _WK_REEL[i][5];
		
		if ((hawkd_flag & (1 << i))	// ＯＮ 
		 /*|| hawk_setting*/) {			// 設定中 
		 	if (hawk_setting && (hawkd_flag & (1 << i))
			 || (c_r == a || c_r == b/* || c_r == c*/) && _WK_REEL[i][0]) {
				spr_uvset(sp, 0, 938, 192);	// びっくり 
			} else {
				spr_uvset(sp, 0, 946, 192);	// のっぺら 
			}
			spr_xyset(sp, reel_center[machine_no][ZOOM_LEVEL][i] - 16, hawk_sign_y[machine_no][ZOOM_LEVEL]);
		} else {
			spr_xyset(sp, HIDE_XOFS, HIDE_YOFS);
		}
	}
}

/*-------------------------------------------
	目押しランプ表示初期化
-------------------------------------------*/
void	init_hawk(void) {
	SPRITE_OBJECT	*sp;
	int				i;
	
	hlampp = (HAWK_LAMP *)memalloc(sizeof(HAWK_LAMP), (void **)&hlampp);
	for (i = 0; i < 3; i++) {
		sp = hlampp->hlamp[i] = sprobj_make();
		spr_texset(sp, 0,0, 938, 192, 928, 248);
		sp->r = sp->g = sp->b = 0x80;
		sp->pri = 17;
		spr_uvset(sp, 0, 946, 192);
		spr_whset(sp, 32, 32);
		spr_xyset(sp, HIDE_XOFS, HIDE_YOFS);
	}
}

/*-------------------------------------------
	ランプ
-------------------------------------------*/
void	hawk_drv(void) {
	if (hlampp == NULL) {
		init_hawk();
	} else {
		hawk_lamp();
	}
}

typedef struct {
	SPRITE_OBJECT	*csl[2];
	int				cp;	// カーソル位置	0~2 
	int				_step;
}	WK_REACH;
WK_REACH	*wk_reach;

short	drum_csl_x[2][3][3] = {
	-74, -22, 32,	// BIN貧引き 
	-86, -22, 42,
	-112, -14, 82,
	-76, -24, 32,	// BIN貧引き 
	-86, -24, 42,
	-112, -14, 82,
};
/*-------------------------------------------
	リーチ目研究モード上下カーソルセット
-------------------------------------------*/
void	set_reach_cursol(SPRITE_OBJECT **spp, int pos) {
	int				i;
	short			xp, *yp, yofs;
	
	xp = reel_center[machine_no][ZOOM_LEVEL][pos] - 16;
	yp = drum_csl_y[machine_no][ZOOM_LEVEL];
	
	for (i = 0; i < 2; i++, spp++, yp++) {
		yofs = ((i < 1) && (ZOOM_LEVEL == 2) && (mode_game != MODE_REACH)) ? 14: 0;
		spr_xyset(*spp, xp, *yp + yofs);
	}
}
/*-------------------------------------------
	リーチ目研究モードキー処理
-------------------------------------------*/
void	key_reach_roll(WK_REACH *wk) {
	if (pad_beta & PADL_LEFT) {	// ← 
		if (key_push(bit2d(PADL_LEFT))) {
			wk->cp--;
			if (wk->cp < 0) wk->cp = 2;
			r_drum.drum_no = wk->cp;
			r_drum.item_no = (_WK_REEL[r_drum.drum_no][5]) % 21;
		}
	} else if (pad_beta & PADL_RIGHT) {	// → 
		if (key_push(bit2d(PADL_RIGHT))) {
			wk->cp++;
			if (wk->cp > 2) wk->cp = 0;
			r_drum.drum_no = wk->cp;
			r_drum.item_no = (_WK_REEL[r_drum.drum_no][5]) % 21;
		}
	} else if (pad_beta & PADL_UP) {	// ↑ 
		r_drum.direc = 1;
		r_drum.drum_no = wk->cp;
		r_drum.item_no = (_WK_REEL[r_drum.drum_no][5] + 1) % 21;
		r_drum.req = 1;
	} else if (pad_beta & PADL_DOWN) {	// ↓ 
		r_drum.direc = -1;
		r_drum.drum_no = wk->cp;
		r_drum.item_no = (_WK_REEL[r_drum.drum_no][5] + 20) % 21;
		r_drum.req = 1;
	}
}
/*-------------------------------------------
	リーチ目研究モード実タスク
-------------------------------------------*/
void	reach_task(WK_REACH *wk) {
	SPRITE_OBJECT	*sp;
	int				i;
	
	switch (wk->_step) {
	case 0:
		for (i = 0; i < 2; i++) {
			sp = wk->csl[i] = sprobj_make();
			spr_texset(sp, 0,0, 944, 8, 928, 250);
			sp->r = sp->g = sp->b = 0x80;
			sp->pri = 17;
			spr_uvset(sp, 0, 944, 8 + 24 * i);
			spr_whset(sp, 32, 24);
		}
		set_reach_cursol(wk->csl, wk->cp);
		
		r_drum.item_no = (_WK_REEL[wk->cp][5]) % 21;
		r_drum.drum_no = wk->cp;
		
		wk->_step++;
		break;
	case 1:
		set_reach_cursol(wk->csl, wk->cp);
		if (submenu_sts == 0 && r_drum.req == 0) {
			key_reach_roll(wk);
		}
		break;
	}
}
/*-------------------------------------------
	リーチ目研究モードタスク確保物解放
-------------------------------------------*/
void	dispose_reach_task(void) {
	SPRITE_OBJECT	*sp;
	int				i;
	
	if (wk_reach == NULL) return;
	
	for (i = 0; i < 2; i++) {
		sp = wk_reach->csl[i];
		sprobj_kill(sp);
	}
	memfree((void **)&wk_reach);
}
/*-------------------------------------------
	リーチ目研究モード管理ドライバ
-------------------------------------------*/
void	reachmode_drv(void) {
	if (wk_reach == NULL) {
		wk_reach = (WK_REACH *)memalloc(sizeof(WK_REACH), (void **)&wk_reach);
		wk_reach->cp = 0;
		wk_reach->_step = 0;
		wk_reach->csl[0] = wk_reach->csl[1] = NULL;
	} else {
		reach_task(wk_reach);
	}
}

/***********************************************
// 解説モードでのメッセージパネル	ぱねぱね */
short mpanel_mess[]={

STR_UNLOCK_0,	// 0:ＢＩＧボーナスフラグ成立ですＢＩＧをそろえましょう 
STR_UNLOCK_1,	// 1:手順に従ってはずしの練習をしましょう 
STR_UNLOCK_2,	// 2:２回目のＪＡＣゲームまでは小役を狙います 
STR_PUSH_STR,	// 3:押し順は左・中・右です 
STR_PUSH_SAND,	// 4:押し順は左・右・中です 
STR_AIM_BLACK,	// 5:左リールの黒いかたまりを狙います 
STR_AIM_RED,	// 6:右リールの赤いかたまりを狙います 
STR_PUSH_CR_ANY,// 7:中・右リールはどこでもいいので適当に止めましょう 
STR_PUSH_R_ANY,	// 8:右リールは、どこでもいいので適当に止めましょう 
STR_PUSH_C_ANY,	// 9:中リールは、どこでもいいので適当に止めましょう 
STR_PLAY_JAC,	//10:ＪＡＣゲームを消化します 
STR_UNLOCK_3,	//11:リプレイはずしをします押し順は　左・中・右です 
STR_UNLOCK_4,	//12:リプレイはずしをします押し順は　右・中・左です 
STR_UNLOCK_5,	//13:パンクを回避するために小役狙いに切り替えます 
STR_UNLOCK_6,	//14:パンクを回避するために手順を切り替えます 
STR_AIM_L_0,	//15:左リールの１０番目のひょうたんを狙います 
STR_AIM_L_1,	//16:左リールの１２番目の月を狙います 
STR_AIM_L_2,	//17:左リールの１３番目のきゅうりを狙います 
STR_AIM_L_3,	//18:左リールの１５番目のきゅうりを狙います 
STR_AIM_L_4,	//19:左リールの１９番目の月を狙います 
STR_AIM_L_5,	//20:左リールの１４番目の酒か１３番目のきゅうりを狙います 
STR_AIM_L_6,	//21:リールの１０番目のひょうたんか番目のひょうたんを狙います 
STR_AIM_C_0,	//22:中リールの１２番目のＲＥＧを狙います 
STR_AIM_C_1,	//23:中リールの１９番目のひょうたんを狙います 
STR_AIM_C_2,	//24:中リールの２０番目のセブンを狙います 
STR_AIM_C_3,	//25:中リールの　１７番目のかっぱをテンパイラインに狙います 
STR_AIM_R_0,	//26:右リールの３番目のひょうたんを狙います 
STR_AIM_R_1,	//27:右リールの１０番目の月を狙います 
STR_AIM_R_2,	//28:右リールの１１番目の酒を狙います 
STR_AIM_R_3,	//29:右リールの１２番目のＲＥＧを狙います 
STR_AIM_R_4,	//30:右リールの１９番目の月を狙います 
STR_DET_0,		//31:設定５以上の判別を行います
STR_DET_1,		//32:設定６の判別を行います
STR_DET_2,		//33:手順にしたがって判別プレイをこなしましょう 
STR_DET_3,		//34:？？プレイで？？枚の払い出しが必要です 
STR_DET_4,		//35:払い出し枚数が少ないので小役を狙います 
STR_DET_5,		//36:払い出し枚数が多いので小役をはずします 
STR_DET_6,		//37:次のプレイは　判別プレイです小役を狙います 
STR_DET_7,		//38:プレイ数が９９９になりました判別結果を発表します 
STR_CROSS_0,	//39:設定変更判別を行います 
STR_CROSS_1,	//40:前日に高確率状態を作り翌日の状態を見て判断できます 
STR_CROSS_2,	//41:から始めます　小役カウンタをげるため小役をはずしましょう 
STR_CROSS_3,	//42:翌日に移行します設定が変更されるかもしれません 
STR_CROSS_4,	//43:翌日ですが変更されているかもしれません 
STR_CROSS_5,	//44:設定が変更されていなければ小役が獲得しやすいはずです 
STR_CROSS_6,	//45:小役を狙います
STR_CROSS_7,	//46:設定変更がされていたか結果発表します 
STR_CROSS_8,	//47:前日は設定？？　翌日も設定？？設定すえおきでした 
STR_CROSS_9,	//48:前日は設定？？　翌日は設定？？設定は変更されていました 
STR_DET_8,		//49:設定判別モードでは３枚がけ以外ではプレイできません 
STR_PUSH_RC_ANY,//50:右・中リールはどこでもいいので適当に止めましょう 
STR_MAXMES_0,	//51:プレイ数が最大になりましたこれ以上のプレイはできません
STR_MAXMES_1,	//52:メダル投入枚数が最大になりましたこれ以上のプレイはできません
STR_MAXMES_2,	//53:メダル払出し枚数が最大になりましたこれ以上のプレイはできません
STR_BIG_UP_0,	//54:ＢＩＧフラグが成立しました
STR_BIG_UP_1,	//55:ＢＩＧフラグが成立しています
STR_REG_UP_0,	//56:ＲＥＧフラグが成立しました
STR_REG_UP_1,	//57:ＲＥＧフラグが成立しています
STR_BONUS_END_0,//58:ＢＩＧボーナス終了です
STR_BONUS_END_1,//59:ＲＥＧボーナス終了です
STR_HISPEED_0,	//60:ＢＩＧ高速処理中です 
STR_HISPEED_1,	//61:ＲＥＧ高速処理中です 
STR_HISPEED_END,//62:高速処理を終了しました
};
/*-------------------------------------------
	メッセージパネル呼出し
		in:		short	xp, yp	予定位置
-------------------------------------------*/
int	call_mes_panel(short xp, short yp, short mesno) {
	if (mesp_p == NULL)		return -1;
	if (mesp_sts > -1)		return -2;	// 二重起動回避 
	if (mesp_p->f_step != 1)	return -3;
	
	mesp_p->sx = mesp_p->dx = mesp_p->x = xp;
	mesp_p->sy = mesp_p->dy = mesp_p->y = yp + HIDE_YOFS;
	set_win(mesp_p);
	
	mesp_p->work[0] = mesno;// 文字列番号設定　リドローは配置時に実行される 
	mesp_p->work[1] = 1;	// 起動フラグＯＮ 
	return	0;
}
/*-------------------------------------------
	メッセージパネル退場リクエスト
-------------------------------------------*/
int	del_mes_panel(void) {
	if (mesp_p == NULL)		return -1;
	if (mesp_sts < 0)		return -2;
	if (mesp_p->f_step != 3)	return -3;
	mesp_p->work[2] = 1;
	return 0;
}
/*-------------------------------------------
	メッセージパネル数字設定
-------------------------------------------*/
void	set_mesp_val(int mode, int v1, int v2) {
	SPRITE_OBJECT	**npp;
	
	if (mesp_p == NULL) return;
	
	mesp_p->work[4] = mode;
	npp = (SPRITE_OBJECT **)mesp_p->work[3];
	switch (mode) {
	case 1:
		set_8wvals(npp, v1, 4, 0);
		npp += 4;
		set_8wvals(npp, v2, 4, 0);
		break;
	case 2:
		set_8wvals(npp, v1, 4, 0);
		npp += 4;
		set_8wvals(npp, v2, 4, 0);
		break;
	}
}
/*-------------------------------------------
	メッセージパネル解放
-------------------------------------------*/
void	dispose_mes_win(void) {
	SPRITE_OBJECT	**sp;
	int			i;
	
	for (i = 0; i < mesp_p->moji_max; i++) {
		ffnt_close(mesp_p->moji_id[i]);
	}
	
	sp = (SPRITE_OBJECT **)mesp_p->work[3];
	for (i = 0; i < 8; i++) {
		sprobj_kill(*sp);
	}
	memfree((void **)&mesp_p->work[3]);
	dispose_window(mesp_p);	// メッセージパネル解放 
	mesp_p = NULL;
}

/*-------------------------------------------
	メッセージパネル具セット
-------------------------------------------*/
void	set_mp(WINDOW *wp) {
	SPRITE_OBJECT	**npp;
	short			x_p, y_p;
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	switch (wp->work[4]) {
	case 0:
		x_p = HIDE_XOFS;
		y_p = HIDE_YOFS;
		break;
	case 1:
		x_p = wp->x + 40;
		y_p = wp->y + 4;
		break;
	case 2:
		x_p = wp->x + 96;
		y_p = wp->y + 4;
		break;
	}
	npp = (SPRITE_OBJECT **)wp->work[3];
	set_8wval(npp, x_p, y_p, 4);
	npp += 4;
	set_8wval(npp, x_p + 96 + 32 * (wp->work[4] - 1), y_p, 4);
}
/*-------------------------------------------
	メッセージパネル
		moji_id		[0]		文字列
		work		[0]		文字列番号
					[1]		起動スイッチ
					[2]		退場スイッチ
					[3]		数字ズ
					[4]		数字モード
-------------------------------------------*/
void	mes_panel(WINDOW *wp) {
	SPRITE_OBJECT	**sp;
	int		i;
	
	wp = mesp_p;
	mesp_sts = -1;
	switch (mesp_p->f_step) {
	case 0:	// 準備 
		mesp_p->moji_id[mesp_p->moji_max] = ffnt_open(mesp_p->x + 4, mesp_p->y + 4, mesp_p->w - 8, FNT_H * 2, (u_short *)fnt_data + STR_BDN_0);
		ffnt_color(mesp_p->moji_id[mesp_p->moji_max], 0x80,0x80,0x80);
		ffnt_priset(mesp_p->moji_id[mesp_p->moji_max], mesp_p->pri - 1);
		mesp_p->moji_max++;
		
#if 1	// 1/23 
		wp->work[1] = FALSE;
#else
		wp->work[1] = 1;
#endif
		
		sp = (SPRITE_OBJECT **)wp->work[3] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 8, (void **)&wp->work[3]);
		for (i = 0; i < 8; i++, sp++) {
			*sp = sprobj_make();
			(*sp)->r = (*sp)->g = 0x80;
			(*sp)->b = 0x40;
			(*sp)->pri = wp->pri - 1;
			spr_texset(*sp, 0, 0, 928, 76, 944, 250);
			spr_whset(*sp, 8, 16);
		}
		sp -= 8;
		set_8wvals(sp, 0, 4, 0);
		set_8wval(sp, HIDE_XOFS, HIDE_YOFS, 4);
		sp += 4;
		set_8wvals(sp, 0, 4, 0);
		set_8wval(sp, HIDE_XOFS, HIDE_YOFS, 4);
		
		mesp_p->f_step++;
		break;
	case 1:	// 出場司令待ち 
		if (mesp_p->work[1]) {	// 起動フラグＯＮ？ 
			ffnt_redraw(mesp_p->moji_id[0], (u_short *)fnt_data + mpanel_mess[mesp_p->work[0]]);
			hide_app_win(mesp_p, WIN_CHG_SYNC, 4, 0);
			set_mp(wp);
			mesp_p->f_step++;
			mesp_p->work[1] = 0;	// 起動フラグクリア 
			mesp_sts = 0;
		} else {
			mesp_sts = -1;
		}
		break;
	case 2:	// 出場中 
		mesp_sts = 0;
		set_mp(wp);
		if (mesp_p->mode == WINMODE_NOP) {
			mesp_p->f_step++;
		}
		break;
	case 3:	// 退場司令待ち（指定位置で表示中） 
		mesp_sts = 0;
		if (wp->work[2]) {
			hide_app_win(mesp_p, WIN_CHG_SYNC, 4, 1);
			wp->work[2] = 0;
			mesp_p->f_step++;
		}
		break;
	case 4:	// 退場中 
		mesp_sts = 0;
		set_mp(wp);
		if (mesp_p->mode == WINMODE_NOP) {
			mesp_p->f_step = 1;
		}
		break;
	}
}

/*-------------------------------------------
	はい／いいえパネル位置設定
-------------------------------------------*/
void	set_yn_panel(WINDOW *wp) {
	set_win(wp);
	ffnt_xy(wp->moji_id[0], wp->x + 6, wp->y + 4);
	spr_xyset((SPRITE_OBJECT *)wp->work[0], wp->x + 38, wp->y + 4);
	spr_xyset((SPRITE_OBJECT *)wp->work[1], wp->x + 100, wp->y + 4);
}
/*-------------------------------------------
	はい／いいえパネル呼出し
		in:		short	xp, yp	予定位置
-------------------------------------------*/
void	call_yn_panel(short xp, short yp) {
	if (yn_sts > -1) return;	// 二重起動回避 
	if (yn_p == NULL) return;
	
	yn_p->sx = yn_p->dx = yn_p->x = xp;
	yn_p->sy = yn_p->dy = yn_p->y = yp + HIDE_YOFS;
	set_win(yn_p);
	yn_p->work[2] = 1;
}
/*-------------------------------------------
	はい／いいえパネル退場
-------------------------------------------*/
void	del_yn_panel(void) {
	if (yn_sts < 0) return;
	yn_p->work[3] = 1;
}
/*-------------------------------------------
	はい／いいえパネル解放
-------------------------------------------*/
void	dispose_yn_win(void) {
	int			i;
	
	for (i = 0; i < yn_p->moji_max; i++) {
		ffnt_close(yn_p->moji_id[i]);
	}
	sprobj_kill((SPRITE_OBJECT *)yn_p->work[0]);	// ○yn 
	sprobj_kill((SPRITE_OBJECT *)yn_p->work[1]);	// ×yn 
	dispose_window(yn_p);	// ＹＮパネル解放 
	yn_p = NULL;
}
/*-------------------------------------------
	はい／いいえパネル
		moji_id		[0]		文字列
		work		[0~1]	○×
					[2]		起動スイッチ
					[3]		立去りスイッチ
-------------------------------------------*/
void	yn_panel(WINDOW *wp) {
	SPRITE_OBJECT	*sp;
	int		i;
	
	wp = yn_p;
	yn_sts = -1;
	switch (yn_p->f_step) {
	case 0:	// 具作成 
		yn_p->moji_id[yn_p->moji_max] = ffnt_open(yn_p->x + 4, yn_p->y + 4, FNT_W * 7, FNT_H, (u_short *)fnt_data + STR_YN);
		ffnt_color(yn_p->moji_id[yn_p->moji_max], 0x80,0x80,0x80);
		ffnt_priset(yn_p->moji_id[yn_p->moji_max], yn_p->pri - 1);
		yn_p->moji_max++;
		
		for (i = 0; i < 2; i++) {
			sp = (SPRITE_OBJECT *)yn_p->work[i] = sprobj_make();
			spr_texset(sp, 0,0, 880, 0, 880, 253 + i);
			sp->r = sp->g = sp->b = 0x80;
			sp->pri = yn_p->pri - 1;
			spr_uvset(sp, 0, 880, 16 * (i + 1));
			spr_whset(sp, 16, 16);
		}
		set_yn_panel(yn_p);
		yn_p->work[2] = 0;
		yn_p->work[3] = 0;
		yn_p->f_step++;
		break;
	case 1:
		if (yn_p->work[2]){
			hide_app_win(yn_p, WIN_CHG_SYNC, 4, 0);
			set_yn_panel(yn_p);
			yn_p->f_step++;
			yn_p->work[2] = 0;
			yn_sts = 0;
		} else {
			yn_sts = -1;
		}
		break;
	case 2:
		set_yn_panel(yn_p);
		if (yn_p->mode == WINMODE_NOP) {
			yn_p->f_step++;
		}
		yn_sts = 0;
		break;
	case 3:
		yn_sts = 0;
		
		// キー 
		if (pad_cnt & PADR_RIGHT) {
			yn_sts = 1;
		} else if (pad_cnt & PADR_DOWN) {
			yn_sts = 2;
		}
		
		if (yn_p->work[3]) {
			hide_app_win(yn_p, WIN_CHG_SYNC, 4, 1);
			yn_p->work[3] = 0;
			yn_p->f_step++;
		}
		break;
	case 4:
		yn_sts = 0;
		set_yn_panel(yn_p);
		if (yn_p->mode == WINMODE_NOP) {
			yn_p->f_step = 1;
		}
		break;
	}
}

void	make_mes_win(void) {
	if (mesp_p == NULL) {
		mesp_p = make_window(HIDE_XOFS, HIDE_YOFS, 8 + FNT_W * 18, 40, 8, mes_panel);
	}
}
/*-------------------------------------------
	はい／いいえパネル作成
-------------------------------------------*/
void	make_yn_win(void) {
	if (yn_p == NULL) {
		yn_p = make_window(HIDE_XOFS, HIDE_YOFS, 8 + FNT_W * 7, 24, 4, yn_panel);
	}
}
/*-------------------------------------------
	情報表示ドライバ元締
-------------------------------------------*/
void	toggles_drv(void) {
	if (!toggle_start_ok) return;
//	if (func_mode != MODE_GAME) return;
	
	switch (mode_game) {
	case MODE_REACH:
		reachmode_drv();
		break;
	case MODE_CHECK:
		detsheet_drv();
		break;
	}
	
	flagdisp_drv();
	reachdisp_drv();
	dropflag_drv();
	playnf_drv();
	mini_drv();
	slide_drv();
	
	hawk_drv();
	
#if 0
	if (pad_beta & PADR_UP) {
		call_detect_result();
	}
#endif
}

/*-------------------------------------------
	情報表示ドライバ総解放
-------------------------------------------*/
void	dispose_all_toggles(void) {
	toggle_start_ok = 0;
	
	if (dfp != NULL)		dispose_flagdisp();
	if (rlp != NULL)		dispose_reachdisp();
	if (dcp != NULL)		dispose_dropflag();
	if (pinfp != NULL)		dispose_playnf();
	if (mini_r[0] != NULL)	dispose_mini();
	if (slidep[0] != NULL)	dispose_slide();
	
	if (hlampp != NULL)		dispose_hawk();
	if (dets != NULL)		dispose_detsheet();
	
	if (mode_game == MODE_REACH)	dispose_reach_task();
}

#define	VAL1		96	// 設定１～４減算値
#define	VAL2		100	// 設定５減算値
#define	VAL3		104	// 設定６減算値
#define	VAL0		256	// 払い出し値
#define GAMECOUNT	999	// プレイ最大数

short	detcalc_p = 0;	// 設定判別表プレイ数ポインタ 

void	calc_det(int mode, int dvp_num) {
	int val1 = 0;		//　規定設定以下減算値用
	int val2 = 0;		//　規定設定以下減算値用
	int add1 = 0;		//	規定設定以下加算値用
	int add2 = 0;		//	規定設定以下加算値用
	int	pay = 0;		//	子役払出減算値用
	int	pay2 = 0;		//	子役払出減算値用
	int	payout = 0, cur_pout;		//	子役払出用
	int counter, cur_counter;
	int	i, dvp_p, dvp_sw, dp_min, dp_max, c_dpn;
	
	if (mode == 0) {	// 設定５以上判別
		add1 = VAL1;
		add2 = VAL2;
	} else {			// 設定６以上判別
		add1 = VAL2;
		add2 = VAL3;
	}
	
	dvp_p = 0;
	dvp_sw = 0;
	c_dpn = 0;
	
	for (counter = 0;counter < GAMECOUNT;counter++) {
		
		// ３枚投入して１ゲーム消化したとする 
		val1 += add1 * 3;
		val2 += add2 * 3;
		
		// 払い出し枚数が基準値を超えるまで払い出す 
		while (pay < val1) {
			pay += VAL0;
			payout++;
		}
		
		dvp_sw = 0;
		
		for (i = 0;;i++) {
			pay2 = pay + i * VAL0;
			
			if (pay2 > val2) {	// 基準値と子役払出減算値を比較 
			// 基準値を超えた 
				if (dvp_sw) {
					det_val[dvp_p][0] = counter;
					det_val[dvp_p][1] = dp_min;
					det_val[dvp_p][2] = dp_max;
					
					// 払い出し枚数による蹴り 
					if (det_val[dvp_p][2] < out_coin_nrb)
						break;
					
					dvp_p++;
					if (dvp_p >= 3) return;	// そろえばトンズラ 
				}
				break;
			} else if ((val1 < pay2) && (pay2 <= val2)) {
			// 基準値と基準値の間に子役払出減算値がある場合は判別プレイ 
				dvp_sw = 1;
				// プレイ回数がカウンタを上回れば蹴る 
				if (counter < dvp_num)
					break;
//				if (payout + i < out_coin_nrb)	break;	// 払い出し枚数による蹴り 
				if (c_dpn != counter) {
					dp_max = dp_min = payout + i;
					c_dpn = counter;
				} else {
					dp_max = payout + i;
				}
//				printf("PLAY Point [%3d]G[%3d]Out\n",
//					counter, payout + i);
			}
		}
	}
}
