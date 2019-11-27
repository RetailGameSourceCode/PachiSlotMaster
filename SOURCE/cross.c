/*=====================================================
	cross.c
	
	パチスロマスターSummy SP
		０１０－０７１－５５０２
		設定変更判別メニュー
		なんか細かく分割してますけど。
		
						作ってる人		T. Kawakami
						作り出した日	3rd Jan. '99
====================================================*/
#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"
#include	"submenu.h"

short	cross_poll[4];
short	cross_get[4];
short	playnum_cross;// プレイ回数［］ *
short	replaynum_cross;
short	yest_thou_ir = 0;
short	yest_thou_nr = 0;
short	toda_thou_ir = 0;
short	toda_thou_nr = 0;
enum {
	/*C_MEDAL,*/C_HAWK,	C_FLAG,	C_CONF,
	C_SAVE,	C_OPT,	C_TOMM,	C_EXIT,
};
enum {
	CC_41,		CC_DFLAG,	CC_DDROP,	CC_DPINF,
	CC_DMINI,	CC_DSLIDE,	CC_DINF,	CC_REELS,
};
short	cross_item[ITEMN_CROSS]  = {
	/*SMENU0, */SMENU2, SMENU4, SMENU7,
	STR_CFGSAVE, SMENU10, STR_TO_TOMMOROW, SMENU11,
};

#define	ITEMN_C_CONF	8
short	cconf_item[ITEMN_C_CONF] = {
	STR_CONF0, STR_CONF1, STR_CONF3, STR_CONF4,
	STR_CONF5, STR_CONF6, STR_CONF7, STR_CONF8,
};

void	cross_config(WINDOW *);
void	call_cross_resulut(void);

#if DEBUG_MODE
char	c_sel_enable[ITEMN_CROSS] = {
	/*1,*/1,1,1,1,1,1,1,
};
#endif

/*===========================================================
	設定変更判別フラグ強制成立のキー処理
===========================================================*/
static	void	key_setflag(WINDOW *wp) {
	if (pad_cnt & PADR_DOWN) {
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		
		// サブメニューさん復活セット 
		revive_submenu();
		
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○  
		setflag_key_on(&wp->work[5], wp->work[0], GAME_BIG, swp->cp_flg);
	} else if (pad_beta & PADL_UP) {
		if (key_push(bit2d(PADL_UP))) {
			swp->cp_flg--;
			if (swp->cp_flg < 0) swp->cp_flg = wp->work[0] - 1;
			set_findst2(&swp->fcur, wp->x - 14, wp->y + 24 + 24 * swp->cp_flg);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			swp->cp_flg++;
			if (swp->cp_flg > wp->work[0] - 1) swp->cp_flg = 0;
			set_findst2(&swp->fcur, wp->x - 14, wp->y + 24 + 24 * swp->cp_flg);
			_SE_CUR1
		}
	}
}
/*===========================================================
	設定変更判別フラグ強制設立パネル配置
===========================================================*/
static	void	set_setflag(WINDOW *wp) {
	SPRITE_OBJECT	**icpp, **onpp;
	int			i;
	short		tx, ty, onx;
	
	icpp = (SPRITE_OBJECT **)wp->work[1];
	onpp = (SPRITE_OBJECT **)wp->work[2];
	tx = wp->x + 4 + 8;
	ty = wp->y + 4 + 20;
	
	for (i = 0; i < wp->work[0]; i++, ty += 24, icpp++, onpp++) {
		spr_xyset(*icpp, tx, ty);
		onx = ((wp->work[5] >> i) & 1) ? 0: HIDE_XOFS;
		spr_xyset(*onpp, tx + 104 + onx, ty + 2);
	}
	poly_xyset((void *)wp->work[3], wp->x + 3, wp->y + 4 + 16, wp->w - 6, 2);
	
	ffnt_xy(wp->moji_id[0], wp->x + 4, wp->y + 4);
}
/*===========================================================
	設定変更判別フラグ強制成立
		work	[0]		項目数
				[1]		フラグポリポインタ配列の先頭
				[2]		ON/OFFポリポインタ配列の先頭
				[3]		タイトル白線ポリ
				[4]		成立可能フラグ判別状況
							0:通常ゲーム
							1:ＢＩＧフラグ成立後
							2:ＲＥＧフラグ成立後
							3:小役ゲーム中
							4:ＪＡＣゲーム中
				[5]		ＯＮフラグ
				[6]		ＯＮフラグの初期状態バックアップ
		moji_id	[0]		パネルタイトル
===========================================================*/
void	cross_setflag(WINDOW *wp) {
	SPRITE_OBJECT	**icspr, **onspr;
	POLY_F4		*lp;
	int			*ip;
	short		i, j;
	
	switch (wp->f_step) {
	case 0:
	ouch_flag = 0;
	bingo_flag = 0;
	reach_me = 0;
	never_bingo_flag = 0;
		wp->work[0] = 5;
		
		icspr = (SPRITE_OBJECT **)wp->work[1] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * wp->work[0], (void **)&wp->work[1]);
		onspr = (SPRITE_OBJECT **)wp->work[2] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * wp->work[0], (void **)&wp->work[2]);
		for (i = 0; i < wp->work[0]; i++, icspr++, onspr++) {
			*icspr = sprobj_make();
			spr_texset(*icspr, 0,0, 832, 0, 832, 247);
			(*icspr)->r = (*icspr)->g = (*icspr)->b = 0x80;
			(*icspr)->pri = wp->pri - 1;
			spr_whset(*icspr, 80, 24);
			
			*onspr = sprobj_make();
			spr_texset(*onspr, 0,0, 952, 0, 944, 250);
			(*onspr)->r = (*onspr)->g = (*onspr)->b = 0x80;
			(*onspr)->pri = wp->pri - 1;
			spr_whset(*onspr, 32, 16);
			spr_uvset(*onspr, 0, 952, 0);
		}
		set_reeluv(wp, 1, GAME_BIG, wp->work[0]);
		
		lp = (POLY_F4 *)wp->work[3] = poly_f4_make();
		lp->r0 = lp->g0 = lp->b0 = 0xF0;
		
		wp->moji_id[0] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + SMENU4);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80, 0x80, 0x20);
		
		make_setflag_flag(&wp->work[5], GAME_BIG, wp->work[0]);

// ここで "&wp->work[5]"の内容を保存しておく Ａ地点
		wp->work[6] = wp->work[5];
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		set_setflag(wp);
		set_findst2(&swp->fcur, wp->x - 14, wp->y + 24 + 24 * swp->cp_flg);
		
		swp->cur_win = SM_SETFLAG;
		wp->f_step++;
		break;
	case 1:	// 切り替え中 
		set_setflag(wp);
		set_findst2(&swp->fcur, wp->x - 14, wp->y + 24 + 24 * swp->cp_flg);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_setflag(wp);
		set_setflag(wp);
		break;
	case MENU_EXIT:
		set_setflag(wp);
		
		if (wp->mode == WINMODE_NOP) {
// ここで Ａ地点で保存した内容と
//"&wp->work[5]"の内容を比べて変更がなければ”
//"set_setflag(wp);"は、すっとばす
			if (wp->work[6] != wp->work[5]) {
				restore_setflag_flag(wp->work[5], wp->work[0], play_mode);
			}
			
			icspr = (SPRITE_OBJECT **)wp->work[1];
			onspr = (SPRITE_OBJECT **)wp->work[2];
			for (i = 0; i < wp->work[0]; i++, icspr++, onspr++) {
				sprobj_kill(*icspr);
				sprobj_kill(*onspr);
			}
			memfree((void **)&wp->work[1]);
			memfree((void **)&wp->work[2]);
			
			poly_kill((void *)wp->work[3]);
			
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
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
#if 0
	case C_MEDAL:	// メダル貸出し 
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 14 + 16, FNT_H * 4 + 8, 15, medal);
		break;
#endif
	case C_HAWK:
		rackwin[1] = make_window(HIDE_XOFS, HIDE_YOFS, 16, 16, 15, sethawk);
		break;
	case C_FLAG:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 9 + 8, 24 * 5 + 24 + 8, 15, cross_setflag);
		break;
	case C_CONF:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 15 + 8, FNT_H * ITEMN_C_CONF + 8, 15, cross_config);
		break;
	case C_OPT:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_OPT + 1) + 8, 15, option);
		break;
	case C_EXIT:
		rackwin[1] = make_window(xp, yp, 8 + FNT_W * 6, 8 + 32, 15, panel_exit_retry);
		break;
#if 1
	case C_SAVE:
		make_setting_data(&copy_sav[2]);
		slc=1;	// セーブかロードか？ 0=LOAD
		rackwin[1] = make_window(MENU_LEFT - 20, MENU_TOP - HIDE_YOFS - 4, 8 + FNT_W * 18, 176 + 8+16, 15, datasave);
		break;
#endif
	default:
		break;
	}
}
/*===========================================================
	設定変更判別パネルキー処理
===========================================================*/
void	key_cross(WINDOW *wp) {
	if (pad_cnt & PADR_DOWN) {			// × 
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
		wp->f_step = MENU_EXIT;
		set_findst2(&swp->fcur, MENU_LEFT - 20 - HIDE_XOFS, MENU_TOP + 4);
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
#if DEBUG_MODE
		if (!c_sel_enable[cp_sm]) return;
#endif
		if (cp_sm == C_TOMM) {	// 翌日へ 
			int		i;
			
yest_thou_ir = p_per_t_ir;
yest_thou_nr = p_per_t_nr;
			rep_no = 2;
			bb_kitakana = 3;
			hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
			set_findst2(&swp->fcur, MENU_LEFT - 20 - HIDE_XOFS, MENU_TOP + 4);
			cp_sm = 0;
			
			for (i = 0; i < 4; i++) {
				cross_poll[i] = bingo_poll[0][i] + bingo_poll[1][i];
				bingo_poll[0][i] = bingo_poll[1][i] = 0;
				cross_get[i] = bingo_get[0][i] + bingo_get[1][i];
				bingo_get[0][i] = bingo_get[1][i] = 0;
			}
			playnum_cross = play_num;
			replaynum_cross = replay_num;
			play_num = 0;
			replay_num = 0;
			
			out_coin = imano_harai = out_coin_nrb = use_coin = 0;
			thousand_num = p_per_t_ir = p_per_t_nr = 0;
			next_thousand = 50;
			
			_SE_OK
		} else {
			make_second_win(cp_sm);
			// サブメニュー退避セット 
			hide_app_win(wp, WIN_CHG_SYNC, 4, 1);
			_SE_SUR2
		}
		wp->f_step = MENU_EXIT;
	} else if (pad_beta & PADL_UP) {
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x80, 0x80);
			if (cp_sm > 0)	cp_sm--;
			else			cp_sm = ITEMN_CROSS - 1;
			
			if (rep_no > 1 && cp_sm == C_TOMM) cp_sm--;
			
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x80, 0x80);
			cp_sm++;
			if (cp_sm > ITEMN_CROSS - 1) cp_sm = 0;
			
			if (rep_no > 1 && cp_sm == C_TOMM) cp_sm++;
			
			ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + cp_sm * FNT_H);
			_SE_CUR1
		}
	}
}

/*===========================================================
	設定変更判別パネル位置設定
===========================================================*/
void	set_cross_panel(WINDOW *wp) {
	int		*ip;
	short	i, tx, ty;
	
	ip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 4;
	if (rep_no > 1)	ffnt_color(wp->moji_id[C_TOMM], 0x20, 0x20, 0x20);
	for (i = 0; i < ITEMN_CROSS; i++, ty += FNT_H, ip++) {
		ffnt_xy(*ip, tx, ty);
	}
}

/*===========================================================
	設定変更判別パネル
		moji_id	[0~7]		具
===========================================================*/
void	panel_cross(WINDOW *wp) {
	int		i;
	char	direc;
	
	switch (wp->f_step) {
	case 0:
		for (i = 0; i < ITEMN_CROSS; i++) {
			wp->moji_id[wp->moji_max] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + cross_item[i]);
			ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
			wp->moji_max++;
		}
		ffnt_color(wp->moji_id[cp_sm], 0x80, 0x20, 0x20);
		
		if (swp->cur_win == SM_NONE)
			direc = 3;
		else
			direc = 4;
		hide_app_win(wp, WIN_CHG_SYNC, direc, 0);
		
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * cp_sm);
		swp->cur_win = P_FIRST;//CP_MAIN;
		wp->f_step++;
		break;
	case 1:
		set_cross_panel(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * cp_sm);
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_cross(wp);
		break;
	case MENU_EXIT:
		set_cross_panel(wp);
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
	設定変更判別コンフィグ中のキー処理
===========================================================*/
static	void	key_c_config(WINDOW *wp, u_short *strp) {
	SPRITE_OBJECT **spp;
	int		tmp;
	char	tstr[4], *flp;
	
	if (pad_cnt & PADR_DOWN) {			// × 
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
		
		revive_submenu();
		make_setting_data(&copy_sav[2]);
		c_cfset = 1;
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		if (swp->cp_cfg < 7) {
			flp = (char *)wp->work[3];
			flp[swp->cp_cfg] ^= 1;
			
			if (swp->cp_cfg > FLS_DSPFLAG)	tmp = swp->cp_cfg + 1;
			else							tmp = swp->cp_cfg;
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
			if (swp->cp_cfg < 0) swp->cp_cfg = ITEMN_C_CONF - 1;
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * swp->cp_cfg);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	// ↓ 
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x80, 0x80);
			swp->cp_cfg++;
			if (swp->cp_cfg > ITEMN_C_CONF - 1) swp->cp_cfg = 0;
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
	設定変更判別コンフィグパネルセット
===========================================================*/
static	void	set_c_config(WINDOW *wp) {
	SPRITE_OBJECT	**spp, *curspr;
	int			*cip;
	short		i, tx, ty, ofs;
	
	// 文字 
	cip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 4;
	for (i = 0; i < ITEMN_C_CONF; i++, cip++, ty += FNT_H) {
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
	設定変更判別コンフィグレーション
		work	[0]			ON/OFFポリ用ポインタ×7の先頭
				[1],[2]		カーソルポリ用
				[3]			sw_configからの目押しモード用変換後
		moji_id	[0]～[7]	メニューアイテム
				[8]			リールスピード設定内容
===========================================================*/
void	cross_config(WINDOW *wp) {
	static		u_short		reel_str[4];
				SPRITE_OBJECT	**spp, *curspr;
				int			i;
				char		tmpb[4], *fl_p;
	
	switch (wp->f_step) {
	case 0:	// 初期設定 
		// sw_configのコンバート 
		fl_p = (char *)wp->work[3] = (char *)memalloc(sizeof(char) * ITEMN_C_CONF, (void **)&wp->work[3]);
		fl_p[0] = FLG_41W;
		fl_p[1] = FLG_DSPFLAG;
		fl_p[2] = FLG_DSPDROP;
		fl_p[3] = FLG_DSPPINF;
		fl_p[4] = FLG_DSPMINI;
		fl_p[5] = FLG_DSPSLID;
		fl_p[6] = FLG_DSPINFO;
		
		// ON/OFF表示 
		spp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * (ITEMN_C_CONF - 1), (void **)&wp->work[0]);
		for (i = 0; i < ITEMN_C_CONF - 1; i++, spp++) {
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
		for (i = 0; i < ITEMN_C_CONF; i++) {
			wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + cconf_item[i]);
			ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
			wp->moji_max++;
		}
		ffnt_color(wp->moji_id[swp->cp_cfg], 0x80, 0x20, 0x20);
		
		sprintf(tmpb, "%d", reel_speed + 1);
		ffnt_changes(tmpb, reel_str);
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, FNT_W, FNT_H, (u_short *)reel_str);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		wp->moji_max++;
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		set_c_config(wp);
		set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
		swp->cur_win = CP_CONFIG;
		wp->f_step++;
		break;
	case 1:	// 切り替え中 
		set_c_config(wp);
		set_findst2(&swp->fcur, wp->x - 20, wp->y +  FNT_H * swp->cp_cfg);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_c_config(wp, reel_str);
		set_c_config(wp);
		break;
	case MENU_EXIT:
		set_c_config(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			spp = (SPRITE_OBJECT **)wp->work[0];
			for (i = 0; i < ITEMN_C_CONF - 1; i++, spp++) {
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
	設定変更判別サブメニュードライバ
===========================================================*/
static	char	result_2;
short	cross_drv(void) {
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
		rackwin[0] = make_window(MENU_LEFT - HIDE_XOFS - 4, MENU_TOP - 4, FNT_W * 11 + 8, FNT_H * ITEMN_CROSS + 8, 15, &panel_cross);
		submenu_sts = SUBM_NORMAL;
		break;
	case SUBM_NORMAL:
		finger_drv(&swp->fcur);
		switch (swp->cur_win) {
		case SM_2START:	// やり直し確認 
			if (rackwin[2] == NULL) {	// 本人死んでいる 
				if (rep_no < 2) {	// 前日 
yest_thou_ir = 0;
yest_thou_nr = 0;
					bb_kitakana = 3;
					retry_initial();
					poly_kill(swp->fcur.pm.pp);
					memfree((void **)&swp);
					submenu_sts = 0;
				} else {
					if (pad_cnt & (PADR_RIGHT|PADR_DOWN)) {
						if (mesp_p->f_step == 3) {
							del_mes_panel();
							call_cross_resulut();
							result_2 = 0;
						}
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
		case CP_RES1:	// 結果発表死亡後 
//			finger_drv(&swp->fcur);
			if (rackwin[1] == NULL) {	// 本人死んでいる 
				if (mesp_p->f_step == 3) {
					if (pad_cnt & (PADR_RIGHT|PADR_DOWN)) {
						del_mes_panel();
						set_mesp_val(0, 0, 0);
					}
				} else if (mesp_sts < 0) {
					if (result_2 < 1) {	// やりなおし 
yest_thou_ir = 0;
yest_thou_nr = 0;
						bb_kitakana = 3;
						rep_no = 1;
						cp_sm = 0;
						
						retry_initial();
						
						poly_kill(swp->fcur.pm.pp);
						memfree((void **)&swp);
						submenu_sts = 0;
					} else {					// 終了 
						// ここで何もかも解放する 
						draw_rq=1;
						func_mode = MODE_TITLE;
						quitflag = TRUE;
						
						dispose_all_toggles();
						poly_kill(swp->fcur.pm.pp);	// カーソル解放 
						
						memfree((void **)&swp);		// サブメニューワーク解放 
						submenu_sts = 0;			// サブメニュー実行ステップクリア 
					}
				}
			}
			break;
		case P_FIRST:	// 終了 
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
	設定変更判別結果表示パネル配置
===========================================================*/
void	setpanel_cross_result(WINDOW *wp) {
	SPRITE_OBJECT	**ipp, **npp;
	POLY_F4			**ppp;
	int		i;
	short	c_y;
	
	ffnt_xy(wp->moji_id[0], wp->x +   4, wp->y +  4);
	ffnt_xy(wp->moji_id[1], wp->x +   4, wp->y +  20);
	ffnt_xy(wp->moji_id[2], wp->x +   4, wp->y +  68);
	ffnt_xy(wp->moji_id[3], wp->x +   4, wp->y +  100);
	
	ipp = (SPRITE_OBJECT **)wp->work[1];
	npp = (SPRITE_OBJECT **)wp->work[2];
	ppp = (POLY_F4 **)wp->work[3];
	c_y = wp->y + 116;
	for (i = 0; i < 4; i++, c_y += 16, ipp++) {
		spr_xyset(*ipp, wp->x + 8, c_y);
		set_8wval(npp, wp->x + 48, c_y, 5);
		npp += 5;
		set_8wval(npp, wp->x + 112, c_y, 5);
		npp += 5;
		set_8wval(npp, wp->x + 162, c_y, 5);
		npp += 5;
		set_8wval(npp, wp->x + 224, c_y, 5);
		npp += 5;
		
		poly_xyset((void *)*ppp++, wp->x + 144, c_y + 13, 1,1);
		poly_xyset((void *)*ppp++, wp->x + 256, c_y + 13, 1,1);
	}
	c_y = wp->y + 36;
	set_8wval(npp, wp->x + 176, c_y, 5);
	npp += 5;	c_y += 16;
	set_8wval(npp, wp->x + 176, c_y, 5);
	npp += 5;	c_y += 16;
	set_8wval(npp, wp->x + 160, c_y, 7);
}

/*===========================================================
	設定変更判別結果発表数値設定
===========================================================*/
char	bingo_out[4] = {15, 10, 2, 0};
void	make_crossres_numuv(SPRITE_OBJECT **npp, int mode) {
	int		i, poll, poll_r, get, get_r, total, yes_get;
	
	total = 0;
	if (mode < 1) {	// 前日 
		for (i = 0; i < 4; i++) {
			poll = cross_poll[i];
			set_8wvals(npp, poll, 5, 0);
			npp += 5;
			
			poll_r = (playnum_cross > 0) ? poll * 10000 / playnum_cross: 0;
			set_8wvals(npp, poll_r, 5, 3);
			npp += 5;
			
			get = /*poll - */cross_get[i];
			set_8wvals(npp, get, 5, 0);
			npp += 5;
//			total += get * bingo_out[i];
			
			yes_get = poll - cross_get[i];
			total += yes_get * bingo_out[i];
			
			get_r = (poll > 0) ? get * 10000 / poll: 0;
			set_8wvals(npp, get_r, 5, 3);
			npp += 5;
		}
		if (yest_thou_ir > 0) {
			set_8wvals(npp, yest_thou_ir, 5, 0);
			npp += 5;
		} else {
			for (i = 0; i < 3; i++)	set_8wnum(*npp++, 11);
			for (i = 0; i < 2; i++)	set_8wnum(*npp++, 10);
		}
		if (yest_thou_nr > 0) {
			set_8wvals(npp, yest_thou_nr, 5, 0);
			npp += 5;
		} else {
			for (i = 0; i < 3; i++)	set_8wnum(*npp++, 11);
			for (i = 0; i < 2; i++)	set_8wnum(*npp++, 10);
		}
		set_8wvals(npp, total, 7, 0);
	} else {		// 翌日
		for (i = 0; i < 4; i++) {
			poll = bingo_poll[0][i] + bingo_poll[1][i];
			set_8wvals(npp, poll, 5, 0);
			npp += 5;
			
			poll_r = (playnum_rate[0] + playnum_rate[1] > 0) ? poll * 10000 / (playnum_rate[0] + playnum_rate[1]): 0;
			set_8wvals(npp, poll_r, 5, 3);
			npp += 5;
			
			get = bingo_get[0][i] + bingo_get[1][i];
			set_8wvals(npp, get, 5, 0);
			npp += 5;
			total += get * bingo_out[i];
			
			get_r = (poll > 0) ? get * 10000 / poll: 0;
			set_8wvals(npp, get_r, 5, 3);
			npp += 5;
		}
		if (p_per_t_ir > 0) {
			set_8wvals(npp, p_per_t_ir, 5, 0);
			npp += 5;
		} else {
			for (i = 0; i < 3; i++)	set_8wnum(*npp++, 11);
			for (i = 0; i < 2; i++)	set_8wnum(*npp++, 10);
		}
		if (p_per_t_nr > 0) {
			set_8wvals(npp, p_per_t_nr, 5, 0);
			npp += 5;
		} else {
			for (i = 0; i < 3; i++)	set_8wnum(*npp++, 11);
			for (i = 0; i < 2; i++)	set_8wnum(*npp++, 10);
		}
		set_8wvals(npp, total, 7, 0);
	}
}
/*===========================================================
	設定変更判別結果発表
		moji_id	[0]		前日／翌日
				[1]		上部固定子
				[2]		中部可変子
				[3]		下部固定子
		work	[0]		0:前日／1:翌日
				[1]		アイコンスプライツ
				[2]		数値スプライト×９７
				[3]		ピリオドのスプライト×８
===========================================================*/
void	cross_result(WINDOW *wp) {
	POLY_F4		*lp, **ppp;
	SPRITE_OBJECT	**npp, **ipp;
	int			i, tmp;
	
	switch (wp->f_step) {
	case 0:
		// アイコン 
		ipp = (SPRITE_OBJECT **)wp->work[1] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 4, (void **)&wp->work[1]);
		for (i = 0; i < 4; i++, ipp++) {
			*ipp = sprobj_make();
			spr_texset(*ipp, 0,0, 928, 76, 944, 250);
			spr_whset(*ipp, 32, 16);
			(*ipp)->r = (*ipp)->g = (*ipp)->b = 0x80;
			(*ipp)->pri = wp->pri - 1;
			set_yakuuv(*ipp, i + 4);
		}
		
		// 数字 
		npp = (SPRITE_OBJECT **)wp->work[2] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 97, (void **)&wp->work[2]);
		for (i = 0; i < 97; i++, npp++) {
			*npp = sprobj_make();
			spr_texset(*npp, 0,0, 928, 76, 944, 250);
			spr_whset(*npp, 8, 16);
			(*npp)->r = (*npp)->g = (*npp)->b = 0x80;
			(*npp)->pri = wp->pri - 1;
		}
		npp -= 97;	// to top 
		make_crossres_numuv(npp, wp->work[0]);
		
		// ピリオド 
		ppp = (POLY_F4 **)wp->work[3] = (POLY_F4 **)memalloc(sizeof(POLY_F4 *) * 8, (void **)&wp->work[3]);
		for (i = 0; i < 8; i++, ppp++) {
			*ppp = poly_f4_make();
			(*ppp)->r0 = (*ppp)->g0 = (*ppp)->b0 = 0xF0;
			poly_priset(*ppp, wp->pri - 1);
		}
		
		wp->moji_id[0] = ffnt_open(wp->x, wp->y, 33, FNT_H, (u_short *)fnt_data + ((wp->work[0] > 0) ? STR_YOKUJITSU: STR_ZENJITSU));
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80, 0x80, 0x20);
		
		wp->moji_id[1] = ffnt_open(wp->x, wp->y, wp->w, 48, (u_short *)fnt_data + STR_CROSS_RESULT_0);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[1], 0x80,0x80,0x80);
		
		wp->moji_id[2] = ffnt_open(wp->x, wp->y, wp->w, 32, (u_short *)fnt_data + ((wp->work[0] > 0) ? STR_CROSS_RESULT_3: STR_CROSS_RESULT_2));
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[2], 0x80,0x80,0x80);
		
		wp->moji_id[3] = ffnt_open(wp->x, wp->y, wp->w, 80, (u_short *)fnt_data + STR_CROSS_RESULT_1);
		ffnt_priset(wp->moji_id[wp->moji_max], wp->pri - 1);
		wp->moji_max++;
		ffnt_color(wp->moji_id[3], 0x80,0x80,0x80);
		
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		setpanel_cross_result(wp);
		
		swp->cur_win = CP_RES0 + wp->work[0];
		
		wp->f_step++;
		break;
	case 1:
		setpanel_cross_result(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (pad_cnt & (PADR_RIGHT | PADR_DOWN)) {	// ○or× 
			if (wp->work[0] < 1 && rackwin[1] == NULL) {	// 一枚目 
				rackwin[1] = make_window(MENU_LEFT - 4 - 16, MENU_TOP - 4 + HIDE_YOFS, 288 + 8, 176 + 8, 15, &cross_result);
				rackwin[1]->work[0] = 1;	// 翌日板 
			} else {										// 二枚目 
				int		mesno;
				if (_NB_RANK != _NB_RANKB) {
					mesno = 48;
				} else {
					mesno = 47;
				}
				set_mesp_val(2, _NB_RANKB, _NB_RANK);
				call_mes_panel(-152, 32, mesno);
//				rep_no = 1;
			}
			// 退避 
			hide_app_win(wp, WIN_CHG_SYNC, 4, 1);
			wp->f_step = MENU_EXIT;
			_SE_OK
		}
		break;
	case MENU_EXIT:
		setpanel_cross_result(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {	// 文字解放 
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			ipp = (SPRITE_OBJECT **)wp->work[1];
			for (i = 0; i < 4; i++, ipp++) {
				sprobj_kill(*ipp);
			}
			memfree((void **)&wp->work[1]);
			npp = (SPRITE_OBJECT **)wp->work[2];
			for (i = 0; i < 97; i++, npp++) {
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
		rackwin[wp->work[0]] = NULL;
		dispose_window(wp);
		break;
	}
	
}

/*===========================================================
	クロスカウンタ結果発表呼び出し
===========================================================*/
void	call_cross_resulut(void) {
	if (rackwin[0] == NULL) {
		rackwin[0] = make_window(MENU_LEFT - 4 - 16, MENU_TOP - 4 + HIDE_YOFS, 288 + 8, 176 + 8, 15, &cross_result);
		rackwin[0]->work[0] = 0;	// 前日板 
	}
}
