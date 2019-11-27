/*==========r===========================================
	hawk.c
	
	パチスロマスターSummy SP
		目押し練習モード用メニュー
		なんか細かく分割してますけど。
	
						作ってる人		T. Kawakami
						作り出した日	10th Dec. '98
====================================================*/
#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"
#include	"submenu.h"

#define IN0_POSI	(0xff)	//1111 1111B	//; 入力ポート０正論理ビット 
//extern	char IN0_PORT	;//EQU	080H		; 入力ポート　０ 

char	start_flag = 0;
char	tmp_play_mode = GAME_NORMAL;

short	hmenu_item[ITEMN_HAWK]  = {
	STR_HAWK_0, SMENU2, SMENU7, STR_CFGSAVE, SMENU10, SMENU11,
};

#define	ITEMN_CHOI_M	5
short	choigm_item[ITEMN_CHOI_M] = {
	STR_CHOI_0, STR_CHOI_1, STR_CHOI_2,
	STR_CHOI_3, STR_CHOI_4, /*STR_CHOI_5,*/
};

#define	ITEMN_H_CONF	6
short	hconf_item[ITEMN_H_CONF] = {
	STR_CONF0, STR_CONF1, STR_CONF3, STR_CONF5, STR_CONF6, STR_CONF8,
};

char	mode_bup, bingo_bup, inum_bup;	// 設定したフラグ状況 

void	choi_gmode(WINDOW *);
void	hawk_config(WINDOW *);
void	hawk_setflag(WINDOW *);

#if 1
char	h_sel_enable[ITEMN_HAWK] = {
	1, 1, 1, 1, 1, 1,
};
#endif
/*===========================================================
	二世代目のウィンドウ登録
		同名の関数がsubmenu.cにもあるので気をつける
===========================================================*/
static	void	make_second_win(signed char win_num) {
	char	column_n;
	
	switch (win_num) {
	case 0:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 9 + 8, FNT_H * ITEMN_CHOI_M + 20 + 8, 15, choi_gmode);
		break;
	case 1:
		rackwin[1] = make_window(HIDE_XOFS, HIDE_YOFS, 16, 16, 15, sethawk);
		break;
	case 2:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 13 + 8, FNT_H * ITEMN_H_CONF + 8, 15, hawk_config);
		break;
#if 1
	case 3:
		make_setting_data(&copy_sav[(machine_no) ? 5: 3]);
		slc=1;	// セーブかロードか？ 0=LOAD
		rackwin[1] = make_window(MENU_LEFT - 20, MENU_TOP - HIDE_YOFS - 4, 8 + FNT_W * 18, 176 + 8+16, 15, datasave);
		break;
#endif
	case 4:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_OPT + 1) + 8, 15, option);
		break;
	case 5:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, 8 + FNT_W * 16, 8 + 32, 15, panel_exit);
		break;
	default:
		break;
	}
}
/*===========================================================
	目押し練習パネルキー処理
===========================================================*/
char	key_hawkp(WINDOW *wp, SUBMENU *swp) {
	if (pad_cnt & PADR_DOWN) {			// × 
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
		wp->f_step = MENU_EXIT;
		set_findst2(&swp->fcur, MENU_LEFT - 20 - HIDE_XOFS, MENU_TOP + 4);
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
#if 1
		if (!h_sel_enable[cp_sm]) return;
#endif
		make_second_win(cp_sm);
		
		// サブメニュー退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 4, 1);
		wp->f_step = MENU_EXIT;
		_SE_SUR2
	} else if (pad_beta & PADL_UP) {
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x80, 0x80);
			if (cp_sm > 0)	cp_sm--;
			else			cp_sm = ITEMN_HAWK - 1;
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x80, 0x80);
			cp_sm++;
			if (cp_sm > ITEMN_HAWK - 1) cp_sm = 0;
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	}
}

/*===========================================================
	目押しパネルセット
===========================================================*/
void	set_hawkp(WINDOW *wp) {
	int		*ip;
	short	i, tx, ty;
	
	ip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 4;
	for (i = 0; i < ITEMN_HAWK; i++, ty += FNT_H, ip++) {
		ffnt_xy(*ip, tx, ty);
	}
}

/*===========================================================
	目押し練習パネル
===========================================================*/
void	panel_hawk(WINDOW *wp) {
	int		i;
	char	direc;
	
	switch (wp->f_step) {
	case 0:
		for (i = 0; i < ITEMN_HAWK; i++) {
			wp->moji_id[i] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + hmenu_item[i]);
			wp->moji_max++;
			ffnt_color(wp->moji_id[i], 0x80, 0x80, 0x80);
		}
		ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
		
		if (swp->cur_win == SM_NONE)	direc = 3;
		else							direc = 4;
		hide_app_win(wp, WIN_CHG_SYNC, direc, 0);
		
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * cp_sm);
		swp->cur_win = /*H*/P_FIRST;
		wp->f_step++;
		break;
	case 1:
		set_hawkp(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * cp_sm);
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_hawkp(wp, swp);
		break;
	case MENU_EXIT:
		set_hawkp(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			wp->f_step++;
		}
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		rackwin[0] = NULL;
		break;
	}
}

/*===========================================================
	状況に応じたフラグ設定ウィンドウ作成
===========================================================*/
void	make_setflagpanel(SUBMENU *swp) {
	int		i, col_n;
	
	switch (swp->cp_ddw) {
	case GAME_NORMAL:
		col_n = 8;
		break;
	case REACH_BIG:
	case REACH_REG:
	case GAME_BIG:
		col_n = 6;
		break;
	case GAME_JAC:
		col_n = 3;
		break;
	}
	
	rackwin[2] = make_window(MENU_LEFT - 4, MENU_TOP - 4 + HIDE_YOFS, 160 + 8, 28 + col_n * 22, 15, &hawk_setflag);
}

/*===========================================================
	ゲームモード選択キー入力処理
===========================================================*/
char	key_choi_m(SUBMENU *swp) {
	WINDOW	*wp = rackwin[1];
	
	if (pad_cnt & PADR_DOWN) {			// × 
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
		// サブメニューさん復活セット 
		rackwin[0] = make_window(MENU_LEFT - 4, MENU_TOP - 4 + HIDE_YOFS, FNT_W * 11 + 8, FNT_H * ITEMN_HAWK + 8, 15, &panel_hawk);
		wp->f_step = MENU_EXIT;
		_SE_SUR2
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		if (swp->cp_ddw < 5) {
			hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
			make_setflagpanel(swp);					// 第三段階用意 
			wp->f_step = MENU_EXIT;
			mode_bup = swp->cp_ddw;	// 選択モードストア 
			_SE_SUR2
		}
	} else if (pad_beta & PADL_UP) {
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[1 + swp->cp_ddw], 0x80, 0x80, 0x80);
			swp->cp_ddw--;
			if (swp->cp_ddw < 0) swp->cp_ddw = ITEMN_CHOI_M - 1;
			ffnt_color(wp->moji_id[1 + swp->cp_ddw], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + 20 + swp->cp_ddw * FNT_H);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[1 + swp->cp_ddw], 0x80, 0x80, 0x80);
			swp->cp_ddw++;
			if (swp->cp_ddw > ITEMN_CHOI_M - 1) swp->cp_ddw = 0;
			ffnt_color(wp->moji_id[1 + swp->cp_ddw], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + 20 + swp->cp_ddw * FNT_H);
			_SE_CUR1
		}
	}
}

/*===========================================================
	ゲームモード設定パネルセット
===========================================================*/
void	set_choip(WINDOW *wp) {
	int		*ip;
	short	i, tx, ty;
	
	poly_xyset((void *)wp->work[0], wp->x + 4, wp->y + 4 + 15, wp->w - 7, 2);
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	ip = &wp->moji_id[1];
	tx = wp->x + 4;
	ty = wp->y + 4 + 20;
	for (i = 0; i < ITEMN_CHOI_M; i++, ty += FNT_H, ip++) {
		ffnt_xy(*ip, tx, ty);
	}
}

/*===========================================================
	目押し練習　ゲームモード設定
		moji_id	[0]		タイトル
				[1～6]	メニューアイテム
		work	[0]		白線
===========================================================*/
void	choi_gmode(WINDOW *wp) {
	POLY_F4	*f4p;
	int		i;
	
	switch (wp->f_step) {
	case 0:
		f4p = (POLY_F4 *)wp->work[0] = poly_f4_make();
		f4p->r0 = f4p->g0 = f4p->b0 = 0xF0;
		poly_priset(f4p, 2);
		
		wp->moji_id[0] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + STR_CHOI_T);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80, 0x80, 0x20);
		for (i = 0; i < ITEMN_CHOI_M; i++) {
			wp->moji_id[1 + i] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + choigm_item[i]);
			wp->moji_max++;
			ffnt_color(wp->moji_id[1 + i], 0x80, 0x80, 0x80);
		}
		ffnt_color(wp->moji_id[swp->cp_ddw + 1], 0x80, 0x20, 0x20);
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		
		set_findst2(&swp->fcur, wp->x - 20, wp->y + 20 + FNT_H * swp->cp_ddw);
		swp->cur_win = HP_FLAG;
		wp->f_step++;
		break;
	case 1:
		set_choip(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 20, wp->y + 20 + FNT_H * swp->cp_ddw);
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_choi_m(swp);
		break;
	case MENU_EXIT:
		set_choip(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			poly_kill((void *)wp->work[0]);
			wp->f_step++;
		}
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		rackwin[1] = NULL;
		break;
	}
}

char	shift_w2sw[5] = {
	0, 1, 3, 5, 6,
};

/*===========================================================
	コンフィグ中のキー処理
===========================================================*/
static	char	key_config(WINDOW *wp, u_short *strp) {
	POLY_FT4	**ft4pp;
	char	tstr[4];
	
	if (pad_cnt & PADR_DOWN) {			// × 
		make_setting_data(&copy_sav[(machine_no) ? 5: 3]);
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
		
		// サブメニューさん復活セット 
		rackwin[0] = make_window(MENU_LEFT - 4, MENU_TOP - 4 + HIDE_YOFS, FNT_W * 11 + 8, FNT_H * ITEMN_HAWK + 8, 15, &panel_hawk);
		
		make_setting_data(&copy_sav[(machine_no) ? 5: 3]);
		h_cfset[machine_no] = 1;
		
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		if (swp->cp_cfg < 5) {
			wp->work[3 + swp->cp_cfg] ^= 1;
			sw_config ^= (1 << shift_w2sw[swp->cp_cfg]);
			ft4pp = (POLY_FT4 **)wp->work[0];
			ft4pp += swp->cp_cfg;
			poly_uvset(*ft4pp, (952 & 0x3F) * 4, 16 - (wp->work[3 + swp->cp_cfg] != FALSE) * FNT_H, 32, FNT_H);
			_SE_SUR2
		}
	} else if (pad_beta & PADL_UP) {	// ↑ 
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x80, 0x80);
			swp->cp_cfg--;
			if (swp->cp_cfg < 0) swp->cp_cfg = ITEMN_H_CONF - 1;
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * swp->cp_cfg);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	// ↓ 
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x80, 0x80);
			swp->cp_cfg++;
			if (swp->cp_cfg > ITEMN_H_CONF - 1) swp->cp_cfg = 0;
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
			_SE_CUR1
		}
	} else if (swp->cp_cfg == 5) {
		if (key_push(bit2d(PADL_LEFT))) {
			if (reel_speed > 0) {
				reel_speed--;
				
				sprintf(tstr, "%d", reel_speed + 1);
				ffnt_changes(tstr, strp);
				ffnt_redraw(wp->moji_id[6], strp);
				_SE_SUR2
			}
		} else if (key_push(bit2d(PADL_RIGHT))) {
			if (reel_speed < 4) {
				reel_speed++;
				
				sprintf(tstr, "%d", reel_speed + 1);
				ffnt_changes(tstr, strp);
				ffnt_redraw(wp->moji_id[6], strp);
				_SE_SUR2
			}
		}
	}
}
/*===========================================================
	コンフィグパネルセット
===========================================================*/
static	void	set_cnfmenu(WINDOW *wp) {
	POLY_FT4	**ft4pp, *cslp;
	int			*cip;
	short		i, tx, ty, ofs;
	
	// 文字 
	cip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 4;
	for (i = 0; i < ITEMN_H_CONF; i++, cip++, ty += FNT_H) {
		ffnt_xy(*cip, tx, ty);
	}
	ffnt_xy(wp->moji_id[6], wp->x + 12 + FNT_W * 10, wp->y + 4 + FNT_H * 5);
	
	ft4pp = (POLY_FT4 **)wp->work[0];	// ON/OFFズ 
	tx = wp->x + 4 + FNT_W * 10;
	ty = wp->y + 4;
	for (i = 0; i < 5; i++, ty += FNT_H, ft4pp++) {
		poly_xyset((void *)*ft4pp, tx, ty, 32, FNT_H);
	}
	
	tx = wp->x + 11 + FNT_W * 9;
	ty = (swp->cp_cfg < 5) ? -HIDE_YOFS: wp->y + 7 + FNT_H * 5;
	for (i = 0; i < 2; i++, tx += 40) {
		cslp = (POLY_FT4 *)wp->work[i + 1];
		if (i < 1 && reel_speed < 1 || i > 0 && reel_speed > 3)
			ofs = HIDE_XOFS;
		else
			ofs = 0;
		poly_xyset((void *)cslp, tx + ofs, ty, 8,8);
	}
}
/*===========================================================
	コンフィグレーション
		work	[0]			ON/OFFポリ用ポインタ×5の先頭
				[1],[2]		カーソルポリ用
				[3]			sw_configからの目押しモード用変換後
		moji_id	[0]～[5]	メニューアイテム
				[6]			リールスピード設定内容
===========================================================*/
void	hawk_config(WINDOW *wp) {
	static		u_short		reel_str[4];
				POLY_FT4	**ft4pp, *cslp;
				int			i;
				char		tmpb[4];
	
	switch (wp->f_step) {
	case 0:	// 初期設定 
		// sw_configのコンバート 
		wp->work[3] = FLG_41W;
		wp->work[4] = FLG_DSPFLAG;
		wp->work[5] = FLG_DSPDROP;
		wp->work[6] = FLG_DSPMINI;
		wp->work[7] = FLG_DSPSLID;
		
		// ON/OFF表示 
		ft4pp = (POLY_FT4 **)wp->work[0] = (POLY_FT4 **)memalloc(sizeof(POLY_FT4 *) * 5, (void **)&wp->work[0]);
		for (i = 0; i < 5; i++, ft4pp++) {
			*ft4pp = poly_ft4_make();
			poly_ft4_fset(*ft4pp, 944, 250, 952, 0,0,0,0);
			poly_uvset(*ft4pp, (952 & 0x3F) * 4, 16 - (wp->work[3 + i] != FALSE) * FNT_H, 32, FNT_H);
			poly_rgbset((void *)*ft4pp, 0x80, 0x80, 0x80);
			poly_priset(*ft4pp, 3);
		}
		// カーソルズ 
		for (i = 0; i < 2; i++) {
			cslp = (POLY_FT4 *)wp->work[i + 1] = poly_ft4_make();
			poly_ft4_fset(cslp, 928, 255, 944, 0,0,0,0);
			poly_uvset(cslp, (944 & 0x3F) * 4 + 24 * i, 0,8,8);
			poly_rgbset((void *)cslp, 0x80, 0x80, 0x80);
			poly_priset(cslp, 2);
		}
		
		// 文字 
		for (i = 0; i < ITEMN_H_CONF; i++) {
			wp->moji_id[i] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + hconf_item[i]);
			wp->moji_max++;
			ffnt_color(wp->moji_id[i], 0x80, 0x80, 0x80);
		}
		ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
		
		sprintf(tmpb, "%d", reel_speed + 1);
		ffnt_changes(tmpb, reel_str);
		wp->moji_id[6] = ffnt_open(wp->x, wp->y, FNT_W, FNT_H, (u_short *)reel_str);
		wp->moji_max++;
		ffnt_color(wp->moji_id[6], 0x80, 0x80, 0x80);
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		set_cnfmenu(wp);
		set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
		swp->cur_win = HP_CONFIG;
		wp->f_step++;
		break;
	case 1:	// 切り替え中 
		set_cnfmenu(wp);
		set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_config(wp, reel_str);
		set_cnfmenu(wp);
		break;
	case MENU_EXIT:
		set_cnfmenu(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			ft4pp = (POLY_FT4 **)wp->work[0];	// ON/OFFズ 
			for (i = 0; i < 5; i++) {
				poly_kill(*ft4pp++);
			}
			memfree((void **)&wp->work[0]);
			
			for (i = 0; i < 2; i++) {			// カーソルズ 
				poly_kill((void *)wp->work[i + 1]);
			}
			
			wp->f_step++;
		}
		
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		rackwin[1] = NULL;
		break;
	}
}

char	reel_ptrn[][7] = {
	0, 1, 2, 3, 4, 5, 8,
	2, 3, 4, 5, 8, 0xFF, 0xFF,
	2, 3, 4, 5, 8, 0xFF, 0xFF,
	2, 3, 4, 6, 8, 0xFF, 0xFF,
	7, 8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};
/*===========================================================
	リール図柄設定
		in:		int	workn	ポリ配列用ワークナンバ
===========================================================*/
void	set_reeluv(WINDOW *wp, int workn, int pmode, int itemn) {
	SPRITE_OBJECT	**sprpp;
	int			i;
	short		c_u, c_v, c_cx, c_cy;
	
	c_u = 832 + 20 * machine_no;
	c_cx = 832 + 16 * machine_no;
	
	if (mode_game == MODE_HAWKEYE)	itemn -= 1;
	
	sprpp = (SPRITE_OBJECT **)wp->work[workn];
	for (i = 0; i < itemn; i++, sprpp++) {	// 通常図柄 
		c_v = 24 * reel_ptrn[pmode][i];
		c_cy = 247 + reel_ptrn[pmode][i];
		spr_uvset(*sprpp, 0, c_u, c_v);
		(*sprpp)->cx = c_cx;
		(*sprpp)->cy = c_cy;
	}
	spr_uvset(*sprpp, 0, 936, 92);	// 「スタート」 
	(*sprpp)->cx = 944;
	(*sprpp)->cy = 250;
}
/*===========================================================
	フラグセットパネル配置
===========================================================*/
static	void	set_setflag(WINDOW *wp) {
	SPRITE_OBJECT	**icpp, **onpp;
	int			i;
	short		tx, ty, onx;
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	poly_xyset((void *)wp->work[0], wp->x + 4, wp->y + 4 + 15, wp->w - 7, 2);
	
	tx = wp->x + 4 + 8;
	ty = wp->y + 4 + 20;
	
	icpp = (SPRITE_OBJECT **)wp->work[1];
	onpp = (SPRITE_OBJECT **)wp->work[2];
	for (i = 0; i < wp->work[7]; i++, ty += 22, icpp++, onpp++) {
		spr_xyset(*icpp, tx, ty);
		onx = ((wp->work[5] >> i) & 1) ? 0: HIDE_XOFS;
		if (i == wp->work[7] - 1)	onx += 24;	// 「スタート」は目立たせる 
		spr_xyset(*onpp, tx + 104 + onx, ty + 2);
	}
}
/*===========================================================
	フラグセット○キー処理
		in:		int		*flg	フラグデータポインタ
				int		i_num	項目数
				int		mode	ゲームモード
				char	pos		現在のカーソル位置
===========================================================*/
void	setflag_key_on(int *flg, int i_num, int mode, char pos) {
	if (pos == i_num - 1) {	// はずれ 
		if (*flg != 1 << i_num - 1) {
			*flg = 1 << i_num - 1;
		} else {
			*flg = 0;
		}
		_SE_SUR2
	} else {				// 通常ゲーム以外 
		if (*flg == (1 << pos))
			*flg = 0;
		else
			*flg = 1 << pos;
		_SE_SUR2
	} 
}
/*===========================================================
	目押しモードフラグセット○キー処理
		in:		int		*flg	フラグデータポインタ
				int		i_num	項目数
				int		mode	ゲームモード
				char	pos		現在のカーソル位置
===========================================================*/
void	setflag_key_on_hawk(int *flg, int i_num, int mode, char pos) {
	if (pos == i_num - 1) {	// はずれ 
		if (*flg != 1 << i_num - 1) {
			*flg = 1 << i_num - 1;
		} else {
			*flg = 0;
		}
		_SE_SUR2
	} else {				// 通常ゲーム以外 
		if (*flg == (1 << pos))
			*flg = 0;
		else
			*flg = 1 << pos;
		_SE_SUR2
	} 
}
/*===========================================================
	フラグセットパネルキー入力処理
===========================================================*/
static	void	key_setflag(WINDOW *wp) {
	if (pad_cnt & PADR_DOWN) {
		bingo_bup = wp->work[5];
		inum_bup = wp->work[7];
		
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		
		// モード設定パネル復活セット 
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 9 + 8, FNT_H * ITEMN_CHOI_M + 20 + 8, 15, choi_gmode);
		
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		if (swp->cp_flg < wp->work[7] - 1) {
			setflag_key_on_hawk(&wp->work[5], wp->work[7], wp->work[6], swp->cp_flg);
		} else {
			// ウィンドウを消す＆スタートする 
			hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
			restore_setflag_flag(wp->work[5], wp->work[7] - 1, wp->work[6]);
			start_flag = 1;	// スタートボタンで終了の証 
			play_mode = wp->work[6];
//	iteya 01/10 改変
			if 		(play_mode == 0)	reach_me = wp->work[5] & 3;
			else if	(play_mode == 1)	reach_me = 1;
			else if	(play_mode == 2)	reach_me = 2;
			else						reach_me = 0;

//	iteya 01/10 挿入
			pflg_set_();
			
			wp->f_step = MENU_EXIT;
			_SE_OK
		}
		
	} else if (pad_beta & PADL_UP) {
		if (key_push(bit2d(PADL_UP))) {
			swp->cp_flg--;
			if (swp->cp_flg < 0) swp->cp_flg = wp->work[7] - 1;
			set_findst2(&swp->fcur, wp->x - 10, wp->y + 26 + 22 * swp->cp_flg);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			swp->cp_flg++;
			if (swp->cp_flg > wp->work[7] - 1) swp->cp_flg = 0;
			set_findst2(&swp->fcur, wp->x - 10, wp->y + 26 + 22 * swp->cp_flg);
			_SE_CUR1
		}
	}
}
/*===========================================================
	フラグセット
		work	[0]		白線
				[1]		アイコンポリポインタ配列
				[2]		ＯＮ／ＯＦＦポリポインタ配列
				[5]		フラグ成立状況のコピー
				[6]		機器モード
				[7]		項目数
		moji_id	[0]		タイトル
===========================================================*/
void	hawk_setflag(WINDOW *wp) {
	POLY_F4		*lp;
	SPRITE_OBJECT	**icpp, **onpp;
	int			i;
	
	switch (wp->f_step) {
	case 0:
	ouch_flag = 0;
	bingo_flag = 0;
	reach_me = 0;
	never_bingo_flag = 0;
		start_flag = 0;
		
		_FL_ACTION = _FL_PUL_PIC2 = _FL_PUL_PIC1_ = 0;
		never_bingo_flag = 0;
		
		wp->work[5] = 0;
		wp->work[6] = swp->cp_ddw;
		switch (wp->work[6]) {	// 要素数決定 
		case GAME_NORMAL:
			wp->work[7] = 8;
			break;
		case REACH_BIG:
		case REACH_REG:
		case GAME_BIG:
			wp->work[7] = 6;
			break;
		case GAME_JAC:
			wp->work[7] = 3;
			break;
		}
		if (swp->cp_flg > wp->work[7] - 1) swp->cp_flg = wp->work[7] - 1;
		
		// 白線 
		lp = (POLY_F4 *)wp->work[0] = poly_f4_make();
		lp->r0 = lp->g0 = lp->b0 = 0xF0;
		// リール 
		icpp = (SPRITE_OBJECT **)wp->work[1] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * wp->work[7], (void **)&wp->work[1]);
		// ＯＮ／ＯＦＦ 
		onpp = (SPRITE_OBJECT **)wp->work[2] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * wp->work[7], (void **)&wp->work[2]);
		for (i = 0; i < wp->work[7]; i++, icpp++, onpp++) {
			*icpp = sprobj_make();
			if (i < wp->work[7] - 1) {
				spr_texset(*icpp, 0,0, 832, 0, 832, 247);
			} else {
				spr_texset(*icpp, 0,0, 936, 92, 944, 250);
			}
			(*icpp)->r = (*icpp)->g = (*icpp)->b = 0x80;
			(*icpp)->pri = wp->pri - 1;
			spr_whset(*icpp, 80, 24);
			
			*onpp = sprobj_make();
			spr_texset(*onpp, 0,0, 952, 0, 944, 250);
			(*onpp)->r = (*onpp)->g = (*onpp)->b = 0x80;
			(*onpp)->pri = wp->pri - 1;
			spr_whset(*onpp, 32, 16);
			spr_uvset(*onpp, 0, 952, 0);
		}
		set_reeluv(wp, 1, wp->work[6], wp->work[7]);
		
		make_setflag_flag(&wp->work[5], wp->work[6], wp->work[7]);
		
		// 白線 
		wp->moji_id[0] = ffnt_open(wp->x, wp->y, wp->w - 6, FNT_H, (u_short *)fnt_data + choigm_item[wp->work[6]]);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80,0x80,0x20);
		
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		set_setflag(wp);
		
		set_findst2(&swp->fcur, wp->x - 10, wp->y + 26 + 22 * swp->cp_flg);
		swp->cur_win = HP_FSET;
		wp->f_step++;
		break;
	case 1:
		set_setflag(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 10, wp->y + 26 + 22 * swp->cp_flg);
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_setflag(wp);
		set_setflag(wp);
		break;
	case MENU_EXIT:
		if (start_flag)	set_findst2(&swp->fcur, wp->x - 10, wp->y + 26 + 22 * swp->cp_flg);
		set_setflag(wp);
		if (wp->mode == WINMODE_NOP) {
			
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			poly_kill((void *)wp->work[0]);
			icpp = (SPRITE_OBJECT **)wp->work[1];
			onpp = (SPRITE_OBJECT **)wp->work[2];
			for (i = 0; i < wp->work[7]; i++, icpp++, onpp++) {
				sprobj_kill(*icpp);
				sprobj_kill(*onpp);
			}
			memfree((void **)&wp->work[1]);
			memfree((void **)&wp->work[2]);
			
			wp->f_step++;
		}
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		if (start_flag)	swp->cur_win = /*H*/P_FIRST;
		rackwin[2] = NULL;
		break;
	}
}

/*===========================================================
	目押し練習メニュー
		ITEMN_SUB = 12
		moji_id[0～11]	メニューアイテム
		work	[0]		子ウィンドウの実行ステップ
				[1]		子ウィンドウの認識番号
===========================================================*/
short	hawkmenu_drv(void) {
	WINDOW		*wp;
	POL_MEMB	*cpm;
	void		*lda;
	short		retv, i;
	
	switch (submenu_sts) {
	case SUBM_INIT:
		swp = (SUBMENU *)memalloc(sizeof(SUBMENU), (void **)&swp);
		if (swp == NULL) return -1;
		_SE_OK
		
		// 指 
		make_fcur();
		
		submenu_sts++;
		break;
	case SUBM_INIT + 1:
		rackwin[0] = make_window(MENU_LEFT - HIDE_XOFS - 4, MENU_TOP - 4, FNT_W * 11 + 8, FNT_H * ITEMN_HAWK + 8, 15, &panel_hawk);
		submenu_sts = SUBM_NORMAL;
		break;
	case SUBM_NORMAL:
		if (swp->cur_win == /*H*/P_FIRST && rackwin[0] == NULL) {
			submenu_sts = SUBM_DISPOSE;
		}
		finger_drv(&swp->fcur);
		break;
	case SUBM_DISPOSE:
		poly_kill(swp->fcur.pm.pp);
		memfree((void **)&swp);
		submenu_sts = 0;
		break;
	}
	return retv;
}

