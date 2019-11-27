/*=====================================================
	flash.c
	
	パチスロマスターSummy SP
		０９０１－０７１－５５０２
		リーチ目研究メニュー
		すでにマスター予定日割ってますけど
		
						作ってる人		T. Kawakami
						作り出した日	4th Jan. '99
====================================================*/
#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"
#include	"submenu.h"

char	flash_no = 0;

enum {
	C_FLASH,	C_OPTION,	C_EXIT,
};
short	flash_item[ITEMN_FLASH]  = {
	STR_FLASH_0, SMENU10, SMENU11,
};
static	signed	char	f_cur_yp[ITEMN_FLASH] = {0, 32, 48};

#define	FLASH_MAX	7
short	flash_name[FLASH_MAX*2] = {
	STR_FLASHN_K0,	STR_FLASHN_K1,	STR_FLASHN_K2,	STR_FLASHN_K3,
	STR_FLASHN_K4,	STR_FLASHN_K5,	STR_FLASHN_K6,//	STR_FLASHN_K7,
	STR_FLASHN_B0,	STR_FLASHN_B1,	STR_FLASHN_B2,	STR_FLASHN_B3,
	STR_FLASHN_B4,	STR_FLASHN_B5,	STR_FLASHN_B6,//	STR_FLASHN_B7,
};

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
	case C_FLASH:
		
		break;
	case C_OPTION:
		rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_OPT + 1) + 8, 15, option);
		break;
	case C_EXIT:
		rackwin[1] = make_window(xp, yp, 8 + FNT_W * 16, 8 + 32, 15, panel_exit);
		break;
	default:
		break;
	}
}
/*===========================================================
	フラッシュミュージアム　キー処理
===========================================================*/
void	key_flash(WINDOW *wp) {
	if (pad_cnt & PADR_RIGHT) {	// ○ 
		switch (swp->cp_fir) {
		case C_FLASH:
			// 退避 
			hide_app_win(wp, WIN_CHG_SYNC, 3, 1);
			wp->f_step = MENU_EXIT;
			set_findst2(&swp->fcur, MENU_LEFT - 20 - HIDE_XOFS, MENU_TOP + 4);
			flash_no = wp->work[0];
			_SE_OK
			break;
		case C_OPTION:
		case C_EXIT:
			make_second_win(swp->cp_fir);
			
			// サブメニュー退避セット 
			hide_app_win(wp, WIN_CHG_SYNC, 4, 1);
			wp->f_step = MENU_EXIT;
			_SE_SUR2
			break;
		}
	} else if (pad_beta & PADL_UP) {
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[swp->cp_fir], 0x80, 0x80, 0x80);
			if (swp->cp_fir > 0)	swp->cp_fir--;
			else					swp->cp_fir = ITEMN_FLASH - 1;
			ffnt_color(wp->moji_id[swp->cp_fir], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + f_cur_yp[swp->cp_fir]);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[swp->cp_fir], 0x80, 0x80, 0x80);
			swp->cp_fir++;
			if (swp->cp_fir > ITEMN_FLASH - 1) swp->cp_fir = 0;
			ffnt_color(wp->moji_id[swp->cp_fir], 0x80, 0x20, 0x20);
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP + f_cur_yp[swp->cp_fir]);
			_SE_CUR1
		}
	} else if (swp->cp_fir < 1) {
		if (pad_beta & (PADL_LEFT)) {
			if (key_push(bit2d(PADL_LEFT))) {
				if (wp->work[0] > 0)
					wp->work[0]--;
				else
					wp->work[0] = FLASH_MAX - 1;
				
				set_8wnum((SPRITE_OBJECT *)wp->work[3], wp->work[0] + 1);
				ffnt_redraw(wp->moji_id[3], (u_short *)fnt_data + flash_name[FLASH_MAX * MACHINE_NO  + wp->work[0]]);
				_SE_SUR2
			}
		} else if (pad_beta & (PADL_RIGHT)) {
			if (key_push(bit2d(PADL_RIGHT))) {
				if (wp->work[0] < FLASH_MAX - 1) {
					wp->work[0]++;
				} else {
					wp->work[0] = 0;
				}
				
				set_8wnum((SPRITE_OBJECT *)wp->work[3], wp->work[0] + 1);
				ffnt_redraw(wp->moji_id[3], (u_short *)fnt_data + flash_name[FLASH_MAX * MACHINE_NO + wp->work[0]]);
				_SE_SUR2
			}
		}
	}
}

/*===========================================================
	フラッシュミュージアムパネル位置設定
===========================================================*/
void	set_flash_panel(WINDOW *wp) {
	int		*ip;
	short	i, tx, ty;
	
	ip = &wp->moji_id[0];
	tx = wp->x + 8;
	ty = wp->y + 4;
	for (i = 0; i < ITEMN_FLASH; i++, ty += FNT_H * 2, ip++) {
		ffnt_xy(*ip, tx, ty);
	}
	ffnt_xy(wp->moji_id[0], wp->x + 8, wp->y + 4);
	ffnt_xy(wp->moji_id[1], wp->x + 8, wp->y + 36);
	ffnt_xy(wp->moji_id[2], wp->x + 8, wp->y + 52);
	ffnt_xy(wp->moji_id[3], wp->x + 8, wp->y + 20);
	
	ty = (swp->cp_fir) ? HIDE_YOFS: wp->y + 6;
	spr_xyset((SPRITE_OBJECT *)wp->work[1], wp->x + 130, ty + 4);
	spr_xyset((SPRITE_OBJECT *)wp->work[2], wp->x + 154, ty + 4);
	
	spr_xyset((SPRITE_OBJECT *)wp->work[3], wp->x + 142, wp->y + 6);
}

/*===========================================================
	フラッシュミュージアムパネル
		moji_id	[0~1]		具
				[2]			フラッシュ名
		work	[0]			現在のフラッシュ番号
				[1~2]		カーソルズ
				[3]			番号のスプライト
===========================================================*/
void	panel_flash(WINDOW *wp) {
	SPRITE_OBJECT	*cslp, *nump;
	int		i;
	char	direc;
	
	switch (wp->f_step) {
	case 0:
//		swp->cp_aut = 0;
		wp->work[0] = flash_no;	// 現在の番号 
		
		// メニュー 
		for (i = 0; i < ITEMN_FLASH; i++) {
			wp->moji_id[wp->moji_max] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + flash_item[i]);
			ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x80);
			wp->moji_max++;
		}
		ffnt_color(wp->moji_id[swp->cp_fir], 0x80, 0x20, 0x20);
		// フラッシュ名 
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x + 4, wp->y + 4 + FNT_H * i, wp->w - 8, FNT_H, (u_short *)fnt_data + flash_name[FLASH_MAX * MACHINE_NO + wp->work[0]]);
		ffnt_color(wp->moji_id[wp->moji_max], 0x20, 0x80, 0x20);
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
		// 番号スプライト 
		nump = (SPRITE_OBJECT *)wp->work[3] = sprobj_make();
		nump->r = nump->g = 0x80;
		nump->b = 0x40;
		nump->pri = wp->pri - 1;
		spr_texset(nump, 0,0, 928, 76, 944, 250);
		spr_whset(nump, 8, 16);
		set_8wnum(nump, wp->work[0] + 1);
		
		if (swp->cur_win == SM_NONE)
			direc = 3;
		else
			direc = 4;
		hide_app_win(wp, WIN_CHG_SYNC, direc, 0);
		
		set_flash_panel(wp);
		
		set_findst2(&swp->fcur, wp->x - 20, wp->y + f_cur_yp[swp->cp_fir]);
		swp->cur_win = P_FIRST;//FP_MAIN;
		wp->f_step++;
		break;
	case 1:
		set_flash_panel(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		set_findst2(&swp->fcur, wp->x - 20, wp->y + f_cur_yp[swp->cp_fir]);
		break;
	case MENU_NORMAL:
		if (yn_sts < 0) key_flash(wp);
		set_flash_panel(wp);
		break;
	case MENU_EXIT:
		set_flash_panel(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			
			for (i = 0; i < 3; i++) {
				sprobj_kill((SPRITE_OBJECT *)wp->work[1 + i]);
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
	フラッシュミュージアムサブメニュードライバ
===========================================================*/
short	flash_drv(void) {
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
		rackwin[0] = make_window(MENU_LEFT - HIDE_XOFS - 4, MENU_TOP - 4, FNT_W * 11 - 4, FNT_H * (ITEMN_FLASH + 1) + 8, 15, &panel_flash);
		submenu_sts = SUBM_NORMAL;
		break;
	case SUBM_NORMAL:
		if (swp->cur_win == /*FP_MAIN*/P_FIRST && rackwin[0] == NULL) {
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