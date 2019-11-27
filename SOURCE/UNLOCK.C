/*=====================================================
	unlock.c
	
	パチスロマスターSummy SP
		０１０－０７１－５５０２
		リプレイはずしメニュー
		なんか細かく分割してますけど。
		
						作ってる人		T. Kawakami
						作り出した日	31st Dec. '98
====================================================*/
#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"
#include	"submenu.h"

short	unlock_item[ITEMN_UNLOCK]  = {
	SMENU2, SMENU7, STR_CFGSAVE, SMENU10, SMENU11,
};

#define	ITEMN_U_CONF	8
short	uconf_item[ITEMN_U_CONF] = {
	STR_CONF0, STR_CONF1, STR_CONF3, STR_CONF4,
	STR_CONF5, STR_CONF6, STR_CONF7, STR_CONF8,
};

void	unlock_config(WINDOW *);

#if DEBUG_MODE
char	u_sel_enable[ITEMN_UNLOCK] = {
	1, 1, 1, 1, 1,
};
#endif
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
	case 0:
		rackwin[1] = make_window(HIDE_XOFS, HIDE_YOFS, 16, 16, 15, sethawk);
		break;
	case 1:
		rackwin[1] = make_window(xp, yp, FNT_W * 15 + 8, FNT_H * ITEMN_U_CONF + 8, 15, unlock_config);
		break;
#if 1
	case 2:
		make_setting_data(&copy_sav[(machine_no) ? 4: 0]);
		slc=1;	// セーブかロードか？ 0=LOAD
		rackwin[1] = make_window(MENU_LEFT - 20, MENU_TOP - HIDE_YOFS - 4, 8 + FNT_W * 18, 176 + 8+16, 15, datasave);
		break;
#endif
	case 3:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_OPT + 2) + 8, 15, t_option);
		break;
	case 4:
		rackwin[1] = make_window(xp, yp, 8 + FNT_W * 6, 8 + 32, 15, panel_exit_retry);
		break;
	default:
		break;
	}
}
/*===========================================================
	リプレイはずしサブメニューキー処理
===========================================================*/
char	key_unlock(WINDOW *wp, SUBMENU *swp) {
	if (pad_cnt & PADR_DOWN) {			// × 
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
		wp->f_step = MENU_EXIT;
		set_findst2(&swp->fcur, MENU_LEFT - 20 - HIDE_XOFS, MENU_TOP + 4);
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
#if DEBUG_MODE
		if (!u_sel_enable[cp_sm]) return;
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
			else			cp_sm = ITEMN_UNLOCK - 1;
			
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x80, 0x80);
			cp_sm++;
			if (cp_sm > ITEMN_UNLOCK - 1) cp_sm = 0;
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	}
}

/*===========================================================
	目押しパネルセット
===========================================================*/
void	set_unlock_panel(WINDOW *wp) {
	int		*ip;
	short	i, tx, ty;
	
	ip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 4;
	for (i = 0; i < ITEMN_UNLOCK; i++, ty += FNT_H, ip++) {
		ffnt_xy(*ip, tx, ty);
	}
}

/*===========================================================
	リプレイはずしサブメニュー
		work[0]		終了方法	0:ゲームへ	1:別のウィンドウへ
===========================================================*/
void	panel_unlock(WINDOW *wp) {
	int		i;
	char	direc;
	
	switch (wp->f_step) {
	case 0:
		for (i = 0; i < ITEMN_UNLOCK; i++) {
			wp->moji_id[i] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + unlock_item[i]);
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
		swp->cur_win = /*U*/P_FIRST;
		wp->f_step++;
		break;
	case 1:
		set_unlock_panel(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * cp_sm);
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_unlock(wp, swp);
		break;
	case MENU_EXIT:
		set_unlock_panel(wp);
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
	コンフィグ中のキー処理
===========================================================*/
static	char	key_config(WINDOW *wp, u_short *strp) {
	SPRITE_OBJECT **spp;
	int		tmp;
	char	tstr[4], *flp;
	
	if (pad_cnt & PADR_DOWN) {			// × 
		make_setting_data(&copy_sav[(machine_no) ? 4: 0]);
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
		
		// サブメニューさん復活セット 
		rackwin[0] = make_window(MENU_LEFT - 4, MENU_TOP - 4 + HIDE_YOFS, FNT_W * 11 + 8, FNT_H * ITEMN_UNLOCK + 8, 15, &panel_unlock);
		
		make_setting_data(&copy_sav[(machine_no) ? 4: 0]);
		u_cfset[machine_no] = 1;
		
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		if (swp->cp_cfg < 7) {
			flp = (char *)wp->work[3];
			flp[swp->cp_cfg] ^= 1;
			
			if (swp->cp_cfg > 1)	tmp = swp->cp_cfg + 1;
			else					tmp = swp->cp_cfg;
			sw_config ^= (1 << tmp);
			
			spp = (SPRITE_OBJECT **)wp->work[0];
			spp += swp->cp_cfg;
			spr_uvset(*spp, 0, 952, 16 - (flp[swp->cp_cfg] != FALSE) * 16);
			_SE_SUR2
		}
	} else if (pad_beta & PADL_UP) {	// ↑ 
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x80, 0x80);
			swp->cp_cfg--;
			if (swp->cp_cfg < 0) swp->cp_cfg = ITEMN_U_CONF - 1;
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * swp->cp_cfg);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	// ↓ 
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x80, 0x80);
			swp->cp_cfg++;
			if (swp->cp_cfg > ITEMN_U_CONF - 1) swp->cp_cfg = 0;
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
				ffnt_redraw(wp->moji_id[8], strp);
				_SE_SUR2
			}
		} else if (key_push(bit2d(PADL_RIGHT))) {
			if (reel_speed < 4) {
				reel_speed++;
				
				sprintf(tstr, "%d", reel_speed + 1);
				ffnt_changes(tstr, strp);
				ffnt_redraw(wp->moji_id[8], strp);
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
	for (i = 0; i < ITEMN_U_CONF; i++, cip++, ty += FNT_H) {
		ffnt_xy(*cip, tx, ty);
	}
	ffnt_xy(wp->moji_id[8], wp->x + 12 + FNT_W * 12, wp->y + 4 + FNT_H * 7);
	
	spp = (SPRITE_OBJECT **)wp->work[0];
	tx = wp->x + 4 + FNT_W * 12;
	ty = wp->y + 4;
	for (i = 0; i < 7; i++, ty += FNT_H, spp++) {
		spr_xyset(*spp, tx, ty);
	}
	
	tx = wp->x + 11 + FNT_W * 11;
	ty = (swp->cp_cfg < 7) ? -HIDE_YOFS: wp->y + 7 + FNT_H * 7;
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
	リプレイはずしコンフィグレーション
		work	[0]			ON/OFFポリ用ポインタ×7の先頭
				[1],[2]		カーソルポリ用
				[3]			sw_configからの目押しモード用変換後
		moji_id	[0]～[7]	メニューアイテム
				[8]			リールスピード設定内容
===========================================================*/
void	unlock_config(WINDOW *wp) {
	static		u_short		reel_str[4];
				SPRITE_OBJECT	**spp, *curspr;
				int			i;
				char		tmpb[4], *fl_p;
	
	switch (wp->f_step) {
	case 0:	// 初期設定 
		// sw_configのコンバート 
		fl_p = (char *)wp->work[3] = (char *)memalloc(sizeof(char) * 8, (void **)&wp->work[3]);
		fl_p[0] = FLG_41W;
		fl_p[1] = FLG_DSPFLAG;
		fl_p[2] = FLG_DSPDROP;
		fl_p[3] = FLG_DSPPINF;
		fl_p[4] = FLG_DSPMINI;
		fl_p[5] = FLG_DSPSLID;
		fl_p[6] = FLG_DSPINFO;
		
		// ON/OFF表示 
		spp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 7, (void **)&wp->work[0]);
		for (i = 0; i < 7; i++, spp++) {
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
		for (i = 0; i < ITEMN_U_CONF; i++) {
			wp->moji_id[i] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + uconf_item[i]);
			wp->moji_max++;
			ffnt_color(wp->moji_id[i], 0x80, 0x80, 0x80);
		}
		ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
		
		sprintf(tmpb, "%d", reel_speed + 1);
		ffnt_changes(tmpb, reel_str);
		wp->moji_id[8] = ffnt_open(wp->x, wp->y, FNT_W, FNT_H, (u_short *)reel_str);
		wp->moji_max++;
		ffnt_color(wp->moji_id[8], 0x80, 0x80, 0x80);
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		set_cnfmenu(wp);
		set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
		swp->cur_win = UP_CONFIG;
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
			for (i = 0; i < 7; i++, spp++) {
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
	リプレイはずしサブメニュードライバ
		ITEMN_SUB = 12
		moji_id[0～11]	メニューアイテム
		work	[0]		子ウィンドウの実行ステップ
				[1]		子ウィンドウの認識番号
===========================================================*/
short	unlock_drv(void) {
	WINDOW		*wp;
	POL_MEMB	*cpm;
	void		*lda;
	short		retv, i;
	
	switch (submenu_sts) {
	case SUBM_INIT:
		_SE_OK
		swp = (SUBMENU *)memalloc(sizeof(SUBMENU), (void **)&swp);
		if (swp == NULL) return -1;
		
		make_fcur();
		
		swp->cur_win = SM_NONE;
		
		submenu_sts++;
		break;
	case SUBM_INIT + 1:
		cp_sm = 0;//1;
		rackwin[0] = make_window(MENU_LEFT - HIDE_XOFS - 4, MENU_TOP - 4, FNT_W * 11 + 8, FNT_H * ITEMN_UNLOCK + 8, 15, &panel_unlock);
		submenu_sts = SUBM_NORMAL;
		break;
	case SUBM_NORMAL:
		if (swp->cur_win == /*U*/P_FIRST && rackwin[0] == NULL) {
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

/***************************************************
****************************************************
*************** 取りこぼし情報 *********************
****************************************************
***************************************************/
/*===========================================================
	リプレイはずし取りこぼし結果表示パネル配置
===========================================================*/
void	setpanel_ul_away(WINDOW *wp) {
	SPRITE_OBJECT	**ipp, **npp;
	POLY_F4			**ppp;
	int		i;
	short	c_y;
	
	ffnt_xy(wp->moji_id[0], wp->x +   8, wp->y +  5);
	ffnt_xy(wp->moji_id[1], wp->x +   4, wp->y +  24);
	poly_xyset((void *)wp->work[0], wp->x + 4, wp->y + 4 + 18, wp->w - 6, 2);
	
	ipp = (SPRITE_OBJECT **)wp->work[1];
	npp = (SPRITE_OBJECT **)wp->work[2];
	ppp = (POLY_F4 **)wp->work[3];
	c_y = wp->y + 24 + FNT_H;
	for (i = 0; i < 4; i++, c_y += 16, ipp++) {
		spr_xyset(*ipp, wp->x + 8, c_y);
		set_8wval(npp, wp->x + 72, c_y, 2);
		npp += 2;
		set_8wval(npp, wp->x + 112, c_y, 5);
		npp += 5;
		set_8wval(npp, wp->x + 186, c_y, 2);
		npp += 2;
		set_8wval(npp, wp->x + 224, c_y, 5);
		npp += 5;
		
		poly_xyset((void *)*ppp++, wp->x + 144, c_y + 13, 1,1);
		poly_xyset((void *)*ppp++, wp->x + 256, c_y + 13, 1,1);
	}
	set_8wval(npp, wp->x + 160, c_y, 3);
}
/*===========================================================
	リプレイはずし取りこぼし結果表示
		moji_id	[0]		パネルタイトル
				[1]		固定子
		work	[0]		タイトル白線
				[1]		アイコンスプライツ
				[2]		数値スプライト×５９
				[3]		ピリオドのスプライト×８
===========================================================*/
void	unlock_away(WINDOW *wp) {
	POLY_F4		*lp, **ppp;
	SPRITE_OBJECT	**npp, **ipp;
	int			i, tmp;
	
	switch (wp->f_step) {
	case 0:
		// 白線 
		lp = (POLY_F4 *)wp->work[0] = poly_f4_make();
		lp->r0 = lp->g0 = lp->b0 = 0xF0;
		
		// アイコン 
		ipp = (SPRITE_OBJECT **)wp->work[1] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 4, (void **)&wp->work[1]);
		for (i = 0; i < 4; i++, ipp++) {
			*ipp = sprobj_make();
			spr_texset(*ipp, 0,0, 928, 76, 944, 250);
			spr_whset(*ipp, 32, 16);
			(*ipp)->r = (*ipp)->g = (*ipp)->b = 0x80;
			(*ipp)->pri = wp->pri - 1;
			set_yakuuv(*ipp, i + 4 + 7 * machine_no);
		}
		
		// 数字 
		npp = (SPRITE_OBJECT **)wp->work[2] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 59, (void **)&wp->work[2]);
		for (i = 0; i < 59; i++, npp++) {
			*npp = sprobj_make();
			spr_texset(*npp, 0,0, 928, 76, 944, 250);
			spr_whset(*npp, 8, 16);
			(*npp)->r = (*npp)->g = (*npp)->b = 0x80;
			(*npp)->pri = wp->pri - 1;
		}
		npp -= 59;	// to top 
		for (i = 0; i < 4; i++) {
			set_8wvals(npp, bingo_poll[2][i], 2, 0);
			npp += 2;
			tmp = (playnum_rate[2] == 0) ? 0: bingo_poll[2][i] * 10000 / playnum_rate[2];
			set_8wvals(npp, tmp, 5, 3);
			npp += 5;
			set_8wvals(npp, bingo_get[2][i], 2, 0);
			npp += 2;
			tmp = (bingo_poll[2][i] == 0) ? 0: bingo_get[2][i] * 10000 / bingo_poll[2][i];
			set_8wvals(npp, tmp, 5, 3);
			npp += 5;
		}
		set_8wvals(npp, bb_getcoin_last - bb_toushi_coin, 3, 0);
		npp += 3;
		
		// ピリオド 
		ppp = (POLY_F4 **)wp->work[3] = (POLY_F4 **)memalloc(sizeof(POLY_F4 *) * 8, (void **)&wp->work[3]);
		for (i = 0; i < 8; i++, ppp++) {
			*ppp = poly_f4_make();
			(*ppp)->r0 = (*ppp)->g0 = (*ppp)->b0 = 0xF0;
			poly_priset(*ppp, wp->pri - 1);
		}
		
		wp->moji_id[0] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + STR_DDISPW2);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80, 0x80, 0x20);
		
		wp->moji_id[1] = ffnt_open(wp->x, wp->y, wp->w, 176, (u_short *)fnt_data + STR_REPRESLUT_0);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[1], 0x80,0x80,0x80);
		
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		setpanel_ul_away(wp);
		
		wp->f_step++;
		break;
	case 1:
		setpanel_ul_away(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (pad_beta & (PADR_RIGHT | PADR_DOWN)) {
			// ランキング作成 
			rackwin[3] = make_window(-148, -100 + HIDE_YOFS, FNT_W * 18 + 8, FNT_H * 11 + 28, 15, p_ranking);
			rackwin[3]->work[7] = 0;
			// 退避 
			hide_app_win(wp, WIN_CHG_SYNC, 4, 1);
			wp->f_step = MENU_EXIT;
			_SE_OK
		}
		break;
	case MENU_EXIT:
		setpanel_ul_away(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {	// 文字解放 
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			poly_kill((void *)wp->work[0]);
			ipp = (SPRITE_OBJECT **)wp->work[1];
			for (i = 0; i < 4; i++, ipp++) {
				sprobj_kill(*ipp);
			}
			memfree((void **)&wp->work[1]);
			npp = (SPRITE_OBJECT **)wp->work[2];
			for (i = 0; i < 59; i++, npp++) {
				sprobj_kill(*npp);
			}
			memfree((void **)&wp->work[2]);
			ppp = (POLY_F4 **)wp->work[3];
			for (i = 0; i < 8; i++, npp++) {
				poly_kill((void *)*ppp);
			}
			memfree((void **)&wp->work[3]);
			
			wp->f_step++;
		}
		break;
	case MENU_EXIT + 1:
		bb_shot_coin = 0;
		bb_toushi_coin = 0;
		bingo_poll[2][0]=0;
		bingo_poll[2][1]=0;
		bingo_poll[2][2]=0;
		bingo_poll[2][3]=0;
		bingo_get[2][0]=0;
		bingo_get[2][1]=0;
		bingo_get[2][2]=0;
		bingo_get[2][3]=0;
		dispose_window(wp);
		rackwin[0] = NULL;
		if (mode_game == MODE_UNLOCK) {
			playnum_rate[0] = playnum_rate[1] = playnum_rate[2] = 0;
		}
		break;
	}
	
}

/*===========================================================
	リプレイはずし結果発表呼び出し
===========================================================*/
void	call_unlock_resulut(void) {
	if (rackwin[0] == NULL)
		rackwin[0] = make_window(MENU_LEFT - 4 - 16, MENU_TOP - 4 + HIDE_YOFS, 288 + 8, 96 + 20 + 8, 15, &unlock_away);
}
