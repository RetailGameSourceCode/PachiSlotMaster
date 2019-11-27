/*=====================================================
	detect.c
	
	パチスロマスターSummy SP
		０１０－０７１－５５０２
		設定判別メニュー
		なんか細かく分割してますけど。
		
						作ってる人		T. Kawakami
						作り出した日	1 Jan. '99
====================================================*/
#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"
#include	"submenu.h"

char	detect_line[21][2] = {	// 設定判別判定テーブル 
	  0,  0,	//  0 
	  0,  0,	//  1 
	100,  0,	//  2 
	100,  0,	//  3 
	 75,  0,	//  4 
	 60,  0,	//  5 
	 50,  0,	//  6 
	 42,  0,	//  7 
	 50,  1,	//  8 
	 44,  1,	//  9 
	 40,  1,	// 10 
	 36,  1,	// 11 
	 33,  1,	// 12 
	 30,  8,	// 13 
	 35,  8,	// 14 
	 33,  7,	// 15 
	 31,  7,	// 16 
	 29,  6,	// 17 
	 27,  6,	// 18 
	 31, 11,	// 19 
	 30, 11,	// 20 
};

signed	char	sheet_data[3][2];	// [次から三つ][プレイ数／払出し枚数] 

short	detect_item[ITEMN_DETECT]  = {
	STR_CHK_CURR, STR_RST_KOYAKU, SMENU2, SMENU4,
	SMENU7, STR_CFGSAVE, SMENU10, SMENU11,
};

short	dcheck_item[3] = {
	STR_DETECT_0, STR_DETECT_1, STR_DETECT_2,
};
short	dcheck_type[2] = {
	STR_DETECT_P0, STR_DETECT_P1,
};

#define	ITEMN_D_CONF	11
short	dconf_item[ITEMN_D_CONF] = {
	STR_CONF0, STR_CONF1, STR_CONF3, STR_CONF4, STR_CONF5, STR_CONF6,
	STR_CONF7, STR_CONF8, STR_CONF9, STR_CONF10, STR_CONF11,
};

void	detect_config(WINDOW *);
void	detect_check(WINDOW *);

#if DEBUG_MODE
char	d_sel_enable[ITEMN_DETECT] = {
	1, 1, 1, 1, 1, 1, 1, 1,
};
#endif

/***************************************************
****************************************************
********** 小役カウンタリセット確認 ****************
****************************************************
***************************************************/
#if 0
/*===========================================================
	小役カウンタリセット確認パネル配置
===========================================================*/
void	set_koyarstpanel(WINDOW *wp) {
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
	ffnt_xy(wp->moji_id[1], wp->x + 4, wp->y + 20);
	spr_xyset((SPRITE_OBJECT *)wp->work[0], wp->x + 162, wp->y + 20);
	spr_xyset((SPRITE_OBJECT *)wp->work[1], wp->x + 226, wp->y + 20);
}
#endif
/*===========================================================
	小役カウンタリセット確認キー処理
===========================================================*/
void	key_koyakurst(WINDOW *wp) {
	if (pad_cnt & PADR_DOWN) {			// × 
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		revive_submenu();
		
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		revive_submenu();
		
		// リセット処理をここに 
		_CT_IN_OUT[0] = _CT_IN_OUT[1] = 0;
		play_num=0;
		replay_num=0;
		out_coin=0;
		out_coin_nrb=0;
		
		wp->f_step = MENU_EXIT;
		_SE_OK
	}
}
/*===========================================================
	小役カウンタリセット確認
		work	[0]		○ぼたん
				[1]		×ぼたん
		moji_id	[0]		確認メッセージ
===========================================================*/
void	panel_koyakurst(WINDOW *wp) {
	SPRITE_OBJECT	*spp;
	int				i;
	
	switch (wp->f_step) {
	case 0:	// 初期設定 
		// 文字 
		wp->moji_id[0] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H * 2, (u_short *)fnt_data + STR_KOYARST_0);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80,0x80,0x40);
		wp->moji_id[1] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H * 2, (u_short *)fnt_data + STR_EXITMES_1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[1], 0x80,0x80,0x80);
		
		for (i = 0; i < 2; i++) {
			spp = (SPRITE_OBJECT *)wp->work[i] = sprobj_make();
			spr_texset(spp, 0,0, 880, 0, 880, 253 + i);
			spp->r = spp->g = spp->b = 0x80;
			spp->pri = 8;
			spr_uvset(spp, 0, 880, 16 * (i + 1));
			spr_whset(spp, 16, 16);
		}
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		set_exitmes(wp);
		set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + HIDE_YOFS);
		swp->cur_win = DP_KOYARST;
		
		wp->f_step++;
		break;
	case 1:	// 切り替え中 
		set_exitmes(wp);
		set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + HIDE_YOFS);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_koyakurst(wp);
		break;
	case MENU_EXIT:
		set_exitmes(wp);
		
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			sprobj_kill((SPRITE_OBJECT *)wp->work[0]);
			sprobj_kill((SPRITE_OBJECT *)wp->work[1]);
			
			wp->f_step++;
		}
		
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		rackwin[1] = NULL;
		break;
	}
}

/*===========================================================
	二世代目のウィンドウ登録
		同名の関数が多数あるので気をつける
===========================================================*/
static	void	make_second_win(signed char win_num) {
	short	xp, yp;
	char	column_n;
	
	xp = MENU_LEFT - 4;
	yp = MENU_TOP - HIDE_YOFS - 4;
	switch (win_num) {
	case 0:	// 現時点での判別 
		rackwin[1] = make_window(xp, yp, 200, 40, 15, detect_check);
		break;
	case 1:	// 小役カウンタリセット 
		rackwin[1] = make_window(xp, yp, 8 + FNT_W * 16, 8 + 32, 15, panel_koyakurst);
		break;
	case 2:	// 目押しタイミングランプ 
		rackwin[1] = make_window(HIDE_XOFS, HIDE_YOFS, 16, 16, 15, sethawk);
		break;
	case 3:	// フラグ強制成立 
		switch (play_mode) {
		case GAME_NORMAL:
			column_n = 7;
			break;
		case REACH_BIG:
		case REACH_REG:
		case GAME_BIG:
			column_n = 5;
			break;
		case GAME_JAC:
			column_n = 2;
			break;
		}
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 9 + 8, 24 * column_n + 24 + 8, 15, setflag);
		break;
	case 4:	// コンフィグ 
		rackwin[1] = make_window(xp, yp, 248, 184, 15, detect_config);
		break;
#if 1
	case 5:
		make_setting_data(&copy_sav[1]);
		slc=1;	// セーブかロードか？ 0=LOAD
		rackwin[1] = make_window(MENU_LEFT - 20, MENU_TOP - HIDE_YOFS - 4, 8 + FNT_W * 18, 176 + 8+16, 15, datasave);
		break;
#endif
	case 6:	// オプション 
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_OPT + 1) + 8, 15, option);
		break;
	case 7:	// ぴりりりり終了 
		rackwin[1] = make_window(xp, yp, 8 + FNT_W * 6, 8 + 32, 15, panel_exit_retry);
		break;
	default:
		break;
	}
}

//int	detplay_num;	// 判別プレイ数 
//int	detget_num;		// 判別プレイ獲得枚数 

/*===========================================================
	設定判別判定パネル位置設定
===========================================================*/
void	set_dcheck_panel(WINDOW *wp) {
	ffnt_xy(wp->moji_id[0], wp->x + 8, wp->y + 4);
	if (wp->work[0] > 0)
		ffnt_xy(wp->moji_id[1], wp->x + 53, wp->y + 4);
	else
		ffnt_xy(wp->moji_id[1], wp->x + 53, wp->y + 4 - HIDE_YOFS);
}
/*===========================================================
	設定判別判定パネルキー入力処理
===========================================================*/
void	key_dcheck(WINDOW *wp) {
	if (pad_beta & (PADR_RIGHT|PADR_DOWN)) {
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
		rackwin[0] = make_window(MENU_LEFT - 4, MENU_TOP - 4 + HIDE_YOFS, FNT_W * 11 + 8, FNT_H * ITEMN_DETECT + 8, 15, &panel_detect);
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	}
}
int		detect_level(void) {
	int		retv, chkv, tbl_n;
	
	if (det_play_num < 2) {
		retv = 0;
	} else {
		chkv = detplay_get_num * 100 / det_play_num;
		tbl_n = (det_play_num < 20) ? det_play_num: 20;
		if (chkv >= detect_line[tbl_n][0]) {
			retv = 2;
		} else if (chkv < detect_line[tbl_n][1]) {
			retv = 1;
		} else {
			retv = 0;
		}
	}
	return retv;
}
/*===========================================================
	設定判別判定
		work	[0]	判定	0:不明	1:ダメ	2:アタリ
		moji_id	[0]	メッセージ
				[1]	判別内容（５以上／６）
===========================================================*/
void	detect_check(WINDOW *wp) {
	int		i;
	
	switch (wp->f_step) {
	case 0:
		wp->work[0] = detect_level();
//		wp->work[0] = 1;
		// 文字 
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 193, FNT_H * 2, (u_short *)fnt_data + dcheck_item[wp->work[0]]);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		wp->moji_max++;
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 49, 16, (u_short *)fnt_data + dcheck_type[koyakucnt_reset]);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		wp->moji_max++;
		
		set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + HIDE_YOFS);
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		swp->cur_win = DP_CHK;
		set_dcheck_panel(wp);
		
		wp->f_step++;
		break;
	case 1:
		set_dcheck_panel(wp);
		set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + HIDE_YOFS);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_dcheck(wp);
		break;
	case MENU_EXIT:
		set_dcheck_panel(wp);
		
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
//		(void **)&wp = NULL;
		rackwin[1] = NULL;
		break;
	}
}

/*===========================================================
	設定判別サブメニューキー処理
===========================================================*/
void	key_detect(WINDOW *wp, SUBMENU *swp) {
	if (pad_cnt & PADR_DOWN) {			// × 
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
		wp->f_step = MENU_EXIT;
		set_findst2(&swp->fcur, MENU_LEFT - 20 - HIDE_XOFS, MENU_TOP + 4);
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
#if DEBUG_MODE
		if (!d_sel_enable[cp_sm]) return;
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
			else			cp_sm = ITEMN_DETECT - 1;
			
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x80, 0x80);
			cp_sm++;
			if (cp_sm > ITEMN_DETECT - 1) cp_sm = 0;
			
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	}
}

/*===========================================================
	設定判別サブメニューセット
===========================================================*/
void	set_detect_panel(WINDOW *wp) {
	int		*ip;
	short	i, tx, ty;
	
	ip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 4;
	for (i = 0; i < ITEMN_DETECT; i++, ty += FNT_H, ip++) {
		ffnt_xy(*ip, tx, ty);
	}
}

/*===========================================================
	設定判別サブメニュー
		moji_id	[0~7]	具
===========================================================*/
void	panel_detect(WINDOW *wp) {
	int		i;
	char	direc;
	
	switch (wp->f_step) {
	case 0:
		for (i = 0; i < ITEMN_DETECT; i++) {
			wp->moji_id[i] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + detect_item[i]);
			wp->moji_max++;
			ffnt_color(wp->moji_id[i], 0x80, 0x80, 0x80);
		}
		ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
		
		if (swp->cur_win == SM_NONE)
			direc = 3;
		else
			direc = 4;
		hide_app_win(wp, WIN_CHG_SYNC, direc, 0);
		
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * cp_sm);
		swp->cur_win = /*D*/P_FIRST;
		wp->f_step++;
		break;
	case 1:
		set_detect_panel(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * cp_sm);
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_detect(wp, swp);
		break;
	case MENU_EXIT:
		set_detect_panel(wp);
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

char	d_shift_w2sw[7] = {
	0, 1, 3, 4, 5, 6, 7,
};

/*===========================================================
	コンフィグ中のキー処理
===========================================================*/
static	char	key_config(WINDOW *wp, u_short *strp) {
	SPRITE_OBJECT **spp;
	int		tmp;
	char	tstr[4], *flp;
	
	if (pad_cnt & PADR_DOWN) {			// × 
		make_setting_data(&copy_sav[1]);
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
		
		// サブメニューさん復活セット 
		rackwin[0] = make_window(MENU_LEFT - 4, MENU_TOP - 4 + HIDE_YOFS, FNT_W * 11 + 8, FNT_H * ITEMN_DETECT + 8, 15, &panel_detect);
		
		make_setting_data(&copy_sav[1]);
		d_cfset = 1;
		
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		if (swp->cp_cfg != 7) {
			if (swp->cp_cfg < 7) {
				flp = (char *)wp->work[3];
				flp[swp->cp_cfg] ^= 1;
				if (swp->cp_cfg > 1)	tmp = swp->cp_cfg + 1;
				else					tmp = swp->cp_cfg;
				sw_config ^= (1 << tmp);
				spp = (SPRITE_OBJECT **)wp->work[0];
				spp += swp->cp_cfg;
				spr_uvset(*spp, 0, 952, 16 - (flp[swp->cp_cfg] != FALSE) * 16);
			} else if (swp->cp_cfg > 7) {
				tmp = swp->cp_cfg - 1;
				flp = (char *)wp->work[3];
				
				flp[tmp] ^= 1;
				detect_level_flg[tmp - 7] ^= 1;
				
				spp = (SPRITE_OBJECT **)wp->work[0];
				spp += swp->cp_cfg - 1;
				spr_uvset(*spp, 0, 952, 16 - (flp[tmp] != FALSE) * 16);
			}
			_SE_SUR2
		}
	} else if (pad_beta & PADL_UP) {	// ↑ 
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x80, 0x80);
			swp->cp_cfg--;
			if (swp->cp_cfg < 0) swp->cp_cfg = ITEMN_D_CONF - 1;
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * swp->cp_cfg);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	// ↓ 
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x80, 0x80);
			swp->cp_cfg++;
			if (swp->cp_cfg > ITEMN_D_CONF - 1) swp->cp_cfg = 0;
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
			_SE_CUR1
		}
	} else if (swp->cp_cfg == 7) {
		if (key_push(bit2d(PADL_LEFT))) {
			if (reel_speed > 0) {
				reel_speed--;
				
				sprintf(tstr, "%d", reel_speed + 1);
				ffnt_changes(tstr, strp);
				ffnt_redraw(wp->moji_id[11], strp);
				_SE_SUR2
			}
		} else if (key_push(bit2d(PADL_RIGHT))) {
			if (reel_speed < 4) {
				reel_speed++;
				
				sprintf(tstr, "%d", reel_speed + 1);
				ffnt_changes(tstr, strp);
				ffnt_redraw(wp->moji_id[11], strp);
				_SE_SUR2
			}
		}
	}
}
/*===========================================================
	コンフィグパネルセット
===========================================================*/
static	void	set_cnfmenu(WINDOW *wp) {
	SPRITE_OBJECT	**spp, *curspr;
	int			*cip;
	short		i, tx, ty, ofs;
	
	// 文字 
	cip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 4;
	for (i = 0; i < ITEMN_D_CONF; i++, cip++, ty += FNT_H) {
		ffnt_xy(*cip, tx, ty);
	}
	ffnt_xy(wp->moji_id[11], wp->x + 12 + FNT_W * 12, wp->y + 4 + FNT_H * 7);
	
	spp = (SPRITE_OBJECT **)wp->work[0];
	tx = wp->x + 4 + FNT_W * 12;
	ty = wp->y + 4;
	for (i = 0; i < 7; i++, ty += FNT_H, spp++) {
		spr_xyset(*spp, tx, ty);
	}
	ty += FNT_H;
	for (i = 0; i < 3; i++, ty += FNT_H, spp++) {
		spr_xyset(*spp, tx, ty);
	}
	
	tx = wp->x + 11 + FNT_W * 11;
	ty = (swp->cp_cfg != 7) ? -HIDE_YOFS: wp->y + 7 + FNT_H * 7;
	for (i = 0; i < 2; i++, tx += 40) {
		curspr = (SPRITE_OBJECT *)wp->work[1 + i];
		if (i < 1 && reel_speed < 1 || i > 0 && reel_speed > 3)
			ofs = HIDE_XOFS;
		else
			ofs = 0;
		spr_xyset(curspr, tx + ofs, ty);
	}
}
/*===========================================================
	設定判別コンフィグレーション
		work	[0]			ON/OFFポリ用ポインタ×10の先頭
				[1],[2]		カーソルポリ用
				[3]			sw_configからの目押しモード用変換後
		moji_id	[0]～[10]	メニューアイテム
				[11]		リールスピード設定内容
===========================================================*/
void	detect_config(WINDOW *wp) {
	static		u_short		reel_str[4];
				SPRITE_OBJECT	**spp, *curspr;
				int			i;
				char		tmpb[4], *fl_p;
	
	switch (wp->f_step) {
	case 0:	// 初期設定 
		// sw_configのコンバート 
		fl_p = (char *)wp->work[3] = (char *)memalloc(sizeof(char) * 10, (void **)&wp->work[3]);
		fl_p[0] = FLG_41W;
		fl_p[1] = FLG_DSPFLAG;
		fl_p[2] = FLG_DSPDROP;
		fl_p[3] = FLG_DSPPINF;
		fl_p[4] = FLG_DSPMINI;
		fl_p[5] = FLG_DSPSLID;
		fl_p[6] = FLG_DSPINFO;
		fl_p[7] = detect_level_flg[0];
		fl_p[8] = detect_level_flg[1];
		fl_p[9] = detect_level_flg[2];
		
		// ON/OFF表示 
		spp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 10, (void **)&wp->work[0]);
		for (i = 0; i < 10; i++, spp++) {
			*spp = sprobj_make();
			(*spp)->r = (*spp)->g = (*spp)->b = 0x80;
			(*spp)->pri = wp->pri - 1;
			spr_texset(*spp, 0,0, 952, 0, 944, 250);
			spr_uvset(*spp, 0, 952, 16 - (fl_p[i] == TRUE) * 16);
			spr_whset(*spp, 32, 16);
		}
		// カーソルズ 
		for (i = 0; i < 2; i++) {
			curspr = (SPRITE_OBJECT *)wp->work[1 + i] = sprobj_make();
			curspr->r = curspr->g = curspr->b = 0x80;
			curspr->pri = wp->pri - 2;
			spr_texset(curspr, 0,0, 944, 0, 928, 255);
			spr_uvset(curspr, 0, 944 + 6 * i, 0);
			spr_whset(curspr, 8, 8);
		}
		
		// 文字 
		for (i = 0; i < ITEMN_D_CONF; i++) {
			wp->moji_id[i] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + dconf_item[i]);
			ffnt_color(wp->moji_id[i], 0x80, 0x80, 0x80);
			wp->moji_max++;
		}
		ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
		
		sprintf(tmpb, "%d", reel_speed + 1);
		ffnt_changes(tmpb, reel_str);
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, FNT_W, FNT_H, (u_short *)reel_str);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		wp->moji_max++;
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		set_cnfmenu(wp);
		set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
		swp->cur_win = DP_CONFIG;
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
			
			spp = (SPRITE_OBJECT **)wp->work[0];
			for (i = 0; i < 10; i++, spp++) {
				sprobj_kill(*spp);
			}
			memfree((void **)&wp->work[0]);
			
			for (i = 0; i < 2; i++) {			// カーソルズ 
				sprobj_kill((SPRITE_OBJECT *)wp->work[1 + i]);
			}
			
			memfree((void **)&wp->work[3]);
			wp->f_step++;
		}
		
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		rackwin[1] = NULL;
		break;
	}
}

/*===========================================================
	設定判別サブメニュードライバ
===========================================================*/
static	char	result_2;
char	result_call;
short	detect_drv(void) {
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
		
		swp->cur_win = SM_NONE;
		
		submenu_sts++;
		break;
	case SUBM_INIT + 1:
		if (result_call) {
			rackwin[1] = make_window(-76, MENU_TOP - 4 - HIDE_YOFS, 8 + FNT_W * 9, 8 + 80, 15, &detect_result);
		} else {
			rackwin[0] = make_window(MENU_LEFT - HIDE_XOFS - 4, MENU_TOP - 4, FNT_W * 11 + 8, FNT_H * ITEMN_DETECT + 8, 15, &panel_detect);
		}
		submenu_sts = SUBM_NORMAL;
		break;
	case SUBM_NORMAL:
		finger_drv(&swp->fcur);
		switch (swp->cur_win) {
#if 0
		case SM_2START:	// やり直し確認 
			if (rackwin[2] == NULL) {	// 本人死んでいる 
				if (pad_cnt & (PADR_RIGHT|PADR_DOWN)) {
					if (mesp_p->f_step == 3) {
						del_mes_panel();
						call_cross_resulut();
						result_2 = 0;
					}
				}
			}
			break;
		case SM_EXIT:	// 終了確認 
			if (rackwin[2] == NULL) {	// 本人死んでいる 
				if (pad_cnt & (PADR_RIGHT|PADR_DOWN)) {
					if (mesp_p->f_step == 3) {
						del_mes_panel();
						call_cross_resulut();
						result_2 = 1;
					}
				}
			}
			break;
#endif
		case DP_RESULT:
			if (rackwin[1] == NULL) {
				if (result_2 < 1) {	// やりなおし 
					bb_kitakana = 3;
					cp_sm = 0;
					if (rate_rndcst)	bingo_rate = rnd(6) + 1;
					retry_initial();
					swp->cur_win = P_FIRST;
					result_call = 0;
				} else {			// 終了 
					// ここで何もかも解放する 
					draw_rq=1;
					func_mode = MODE_TITLE;
					quitflag = TRUE;
					
					dispose_all_toggles();
					
					poly_kill(swp->fcur.pm.pp);
					memfree((void **)&swp);
					submenu_sts = 0;
				}
			}
			break;
		case P_FIRST:
			if (rackwin[0] == NULL) {
				submenu_sts = SUBM_DISPOSE;
			}
			break;
		}
		break;
	case SUBM_DISPOSE:
		poly_kill(swp->fcur.pm.pp);
		memfree((void **)&swp);
		submenu_sts = 0;
		break;
	}
	return retv;
}


/***************************************************
****************************************************
***************    結果発表    *********************
****************************************************
***************************************************/
/*===========================================================
	設定判別結果表示パネル配置
===========================================================*/
void	setpanel_detect_result(WINDOW *wp) {
	SPRITE_OBJECT	**npp;
	int		i;
	short	c_x, c_y;
	
	ffnt_xy(wp->moji_id[0], wp->x +   4, wp->y +  4);
	
	npp = (SPRITE_OBJECT **)wp->work[0];
	c_x = wp->x + 92;
	c_y = wp->y + 4;
	for (i = 0; i < 3; i++, npp += 3, c_y += 16) {
		set_8wval(npp, c_x, c_y, 3);
	}
	set_8wval(npp, wp->x + 64, c_y + 16, 1);
}

/*===========================================================
	設定変更判別結果発表数値設定
===========================================================*/
void	make_detres_numuv(SPRITE_OBJECT **npp) {
	int		perc;
	
	set_8wvals(npp, det_play_num, 3, 0);
	npp += 3;
	set_8wvals(npp, detplay_get_num, 3, 0);
	npp += 3;
	perc = (det_play_num > 0) ? detplay_get_num * 100 / det_play_num: 0;
	set_8wvals(npp, perc, 3, 0);
	npp += 3;
	set_8wnum(*npp, _NB_RANK);
}
/*===========================================================
	設定判別結果発表
		moji_id	[0]		固定子
		work	[0]		数値スプライト×10
				[7]		0:やりなおし	1:終了
===========================================================*/
void	detect_result(WINDOW *wp) {
	SPRITE_OBJECT	**npp;
	int			i, tmp;
	
	switch (wp->f_step) {
	case 0:
		result_2 = wp->work[7];
		// 数字 
		npp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 10, (void **)&wp->work[0]);
		for (i = 0; i < 10; i++, npp++) {
			*npp = sprobj_make();
			spr_texset(*npp, 0,0, 928, 76, 944, 250);
			spr_whset(*npp, 8, 16);
			(*npp)->r = (*npp)->g = 0x80;
			(*npp)->b = 0x40;
			(*npp)->pri = wp->pri - 1;
		}
		npp -= 10;	// to top 
		make_detres_numuv(npp);
		
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, wp->w, FNT_H*5, (u_short *)fnt_data + STR_DET_RESULT);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80, 0x80, 0x80);
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		setpanel_detect_result(wp);
		
		swp->cur_win = DP_RESULT;
		
		wp->f_step++;
		break;
	case 1:
		setpanel_detect_result(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (pad_cnt & (PADR_RIGHT | PADR_DOWN)) {	// ○or× 
#if 0
			int		mesno;
			if (_NB_RANK != _NB_RANKB) {
				mesno = 48;
			} else {
				mesno = 47;
			}
			set_mesp_val(2, _NB_RANKB, _NB_RANK);
			call_mes_panel(-152, 32, mesno);
#endif
			// 退避 
			hide_app_win(wp, WIN_CHG_SYNC, 2, 1);
			wp->f_step = MENU_EXIT;
			_SE_OK
		}
		break;
	case MENU_EXIT:
		setpanel_detect_result(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {	// 文字解放 
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			npp = (SPRITE_OBJECT **)wp->work[0];
			for (i = 0; i < 10; i++, npp++) {
				sprobj_kill(*npp);
			}
			memfree((void **)&wp->work[0]);
			
			wp->f_step++;
		}
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		rackwin[1] = NULL;
		break;
	}
	
}

void call_detect_result(void) {
}
