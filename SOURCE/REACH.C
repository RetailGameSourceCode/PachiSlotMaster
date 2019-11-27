/*=====================================================
	reach.c
	
	パチスロマスターSummy SP
		０１０－０７１－５５０２
		リーチ目研究メニュー
		なんか細かく分割してますけど。
		
						作ってる人		T. Kawakami
						作り出した日	3rd Jan. '99
====================================================*/
#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"
#include	"submenu.h"

enum {
	C_PUSH,	C_EXIT,
};
short	reach_item[ITEMN_REACH]  = {
	STR_AUTO_0, SMENU11,
};


char	push_type = 0;

extern	short	auto_push[];


#if DEBUG_MODE
char	r_sel_enable[ITEMN_REACH] = {
	1,1,
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
	case C_PUSH:
		
		break;
	case C_EXIT:
		rackwin[1] = make_window(xp, yp, 8 + FNT_W * 16, 8 + 32, 15, panel_exit);
		break;
	default:
		break;
	}
}
/*===========================================================
	リーチ目研究パネル　キー処理
===========================================================*/
void	key_reach(WINDOW *wp) {
	if (pad_cnt & PADR_DOWN) {			// × 
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
		wp->f_step = MENU_EXIT;
		set_findst2(&swp->fcur, MENU_LEFT - 20 - HIDE_XOFS, MENU_TOP + 4);
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
#if DEBUG_MODE
		if (!r_sel_enable[swp->cp_aut]) return;
#endif
		make_second_win(swp->cp_aut);
		
		// サブメニュー退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
		wp->f_step = MENU_EXIT;
		_SE_SUR2
	} else if (pad_beta & PADL_UP) {
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[swp->cp_aut], 0x80, 0x80, 0x80);
			if (swp->cp_aut > 0)	swp->cp_aut--;
			else			swp->cp_aut = ITEMN_REACH - 1;
			ffnt_color(wp->moji_id[swp->cp_aut], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + (swp->cp_aut + 1) * FNT_H);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[swp->cp_aut], 0x80, 0x80, 0x80);
			swp->cp_aut++;
			if (swp->cp_aut > ITEMN_REACH - 1) swp->cp_aut = 0;
			ffnt_color(wp->moji_id[swp->cp_aut], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + (swp->cp_aut + 1) * FNT_H);
			_SE_CUR1
		}
	} else if (swp->cp_aut < 1) {
		if (pad_beta & (PADL_LEFT|PADL_RIGHT)) {
			if (key_push(bit2d(PADL_LEFT))
			 || key_push(bit2d(PADL_RIGHT))) {
				push_type ^= 1;
				ffnt_redraw(wp->moji_id[3], (u_short *)fnt_data + auto_push[push_type]);
				_SE_SUR2
			}
		}
	}
}

/*===========================================================
	リーチ目研究パネルパネル位置設定
===========================================================*/
void	set_reach_panel(WINDOW *wp) {
	int		*ip;
	short	i, tx, ty;
	
	ip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 20;
	for (i = 0; i < ITEMN_REACH; i++, ty += FNT_H, ip++) {
		ffnt_xy(*ip, tx, ty);
	}
	ffnt_xy(wp->moji_id[2], wp->x + 116, wp->y + 4);
	ffnt_xy(wp->moji_id[3], wp->x + 116, wp->y + 20);
	
	ty = (swp->cp_aut) ? HIDE_YOFS: wp->y + 23;
	spr_xyset((SPRITE_OBJECT *)wp->work[1], wp->x + 106, ty);
	spr_xyset((SPRITE_OBJECT *)wp->work[2], wp->x + 194, ty);
}

/*===========================================================
	リーチ目研究パネル
		moji_id	[0~1]		具
				[2]			押し順ガイド
				[3]			押し順
		work	[0]			押し順番号
				[1~2]		カーソルポインタス
===========================================================*/
void	panel_reach(WINDOW *wp) {
	SPRITE_OBJECT	*cslp;
	int		i;
	char	direc;
	
	switch (wp->f_step) {
	case 0:
		wp->work[0] = push_type;
		// メニュー 
		for (i = 0; i < ITEMN_REACH; i++) {
			wp->moji_id[wp->moji_max] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + reach_item[i]);
			ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
			wp->moji_max++;
		}
		ffnt_color(wp->moji_id[swp->cp_aut], 0x80, 0x20, 0x20);
		// 押し順ガイド 
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + STR_AUTO_5);
		ffnt_color(wp->moji_id[wp->moji_max], 0x20, 0x80, 0x20);
		wp->moji_max++;
		// 押し順 
		wp->moji_id[wp->moji_max] = ffnt_open(0,0, FNT_W * 5, FNT_H, (u_short *)fnt_data + auto_push[push_type]);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
		wp->moji_max++;
		
		// カーソルズ 
		for (i = 0; i < 2; i++) {
			cslp = (SPRITE_OBJECT *)wp->work[1 + i] = sprobj_make();
			cslp->r = cslp->g = cslp->b = 0x80;
			cslp->pri = wp->pri - 1;
			spr_texset(cslp, 0,0, 944, 0, 928, 255);
			spr_whset(cslp, 8,8);
			spr_uvset(cslp, 0, 944 + 6 * i, 0);
		}
		
		
		if (swp->cur_win == SM_NONE)
			direc = 3;
		else
			direc = 4;
		hide_app_win(wp, WIN_CHG_SYNC, direc, 0);
		set_reach_panel(wp);
		
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * (swp->cp_aut + 1));
		swp->cur_win = P_FIRST;//RP_MAIN;
		wp->f_step++;
		break;
	case 1:
		set_reach_panel(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 20, wp->y + FNT_H * (swp->cp_aut + 1));
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_reach(wp);
		set_reach_panel(wp);
		break;
	case MENU_EXIT:
		set_reach_panel(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			
			for (i = 0; i < 2; i++) {
				sprobj_kill((SPRITE_OBJECT *)wp->work[1 + i]);
			}
			
//			push_type = wp->work[0];
			
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
	リーチ目研究サブメニュードライバ
===========================================================*/
short	reach_drv(void) {
	WINDOW		*wp;
	POL_MEMB	*cpm;
	void		*lda;
	short		retv, i;
	
	switch (submenu_sts) {
	case SUBM_INIT:
		swp = (SUBMENU *)memalloc(sizeof(SUBMENU), (void **)&swp);
		if (swp == NULL) return -1;
		_SE_OK
		swp->cp_aut = 0;
		// 指 
		make_fcur();
		
		swp->cur_win = SM_NONE;
		
		submenu_sts++;
		break;
	case SUBM_INIT + 1:
		rackwin[0] = make_window(MENU_LEFT - HIDE_XOFS - 4, MENU_TOP - 4, FNT_W * 13 + 8, FNT_H * (ITEMN_REACH + 1) + 8, 15, &panel_reach);
		submenu_sts = SUBM_NORMAL;
		break;
	case SUBM_NORMAL:
		if (swp->cur_win == P_FIRST/*RP_MAIN*/ && rackwin[0] == NULL) {
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