/*===================================================
	select.c

	ＴＥＮ	パチスロコレクション
	機種選択画面など	タイトルとゲームの間
	
	※テクスチャページ３０を生成用に処理内で使用する
	
						作ってる人		T. Kawakami
						作り出した日	28th Oct. '98
====================================================*/

#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"select.h"

char	u_cfset[2] = {0, 0};
char	d_cfset = 0;
char	c_cfset = 0;
char	h_cfset[2] = {0, 0};

extern	char	fade_cur;
TIM_INF	made_tim = {
	896, 256, 112,  224, 0, 492, 0,	//	ＢＧＭ括弧内	
};
char	koyakucnt_reset;

void	timi2texi(TIM_INF *, TEX_INF *);
void	spr_set(POL_MEMB *, short, short, short, short, short, short, short);
void	init_waku(FRAMES *, short, short, short, short, short, short);
void	chg_pol_clut(POL_MEMB *, char);
char	bit2d(u_int);

static	void	set_nums(signed char);
static	void	init_modepanel(void);
static	void	set_modewin(void);
static	void	chg_col_rate(short, short);
static	void	chg_col_sound(short, short);
static	void	chg_col_mode(char, char);
static	void	chg_col_reset(char, char, int);
static	void	set_macpanel(PANEL_RATE *);
static	void	set_soundwin(short, short);
static	void	init_resetpanel(int);

typedef	struct	{
	POLY_G4		*backp;		// バックドロップ 
	MESWIN_OBJ	meswin;					//	メッセージウィンドウ 
	POL_MEMB	machine[MACHINE_MAX];	//	台イメージ用 
	LOGO		logo[MACHINE_MAX];		//	ロゴイメージ用 
	RATE_N		rate_num_str[2][2][8];	//	数字用[機種][ボーナス種別][確率設定] 
	CLOUD		cloud[CLOUD_MAX];
	PANEL_RATE	panel_mac[2];		//	機種選択画面パネル 
	PANEL_RATE	panel_rate;			//	確率設定画面パネル 
	PANEL_RATE	panel_chk_rate;		//	設定判別用確率設定画面パネル 
	MODE_PANEL	mode_panel;			//	モード選択パネル 
	MODE_PANEL	reset_panel[2];		//	小役カウンタ状態選択パネル 
	T_CUR		tcur[2];			//	機種選択画面カーソル 
	F_CUR		fcur;				//	指カーソル 
	PANEL_SOUND	st_sound;			//	サウンド選択用 
	PANEL_HELP	panel_help;			//	ヘルプパネル	
	int			work[8];
	short		wind_dir;
	signed char	scrmode;	/*	画面状態	*/
	signed char	gamemode;	/*	ゲームモード	*/
	signed char	mach_n;		/*	機械番号	*/
	signed char	rate_n;		//	確率番号	
	signed char	chg_scr;	//	画面切替え中	
	signed char	chg_menu;	//	画面内切替え中	
	signed char	exitF;
}	SELECT_INF;
SELECT_INF	*sip;

/*===========================================================
	POL_MEMBのtpを基準にテクスチャ位置を変更する
===========================================================*/
void	chg_uv(POL_MEMB *cp, short u, short v, short w, short h) {
	TEX_INF	*c_t;
	short	cu, cv, cw, ch;
	
	c_t = &cp->tp;
	
	c_t->u = u;
	c_t->v = v;
	cw = (w < 0) ? c_t->tw: w;
	ch = (h < 0) ? c_t->th: h;
	
	poly_uvset(cp->pp, c_t->u0 + c_t->u, c_t->v0 + c_t->v, cw, ch);
}

/*===========================================================
	基準値、変動最大値、ステップ値、最大ステップ値、増減向きから
	ステップ値時点での値を求める
===========================================================*/
short	make_step(int low, int wid, int fs, int step, int direc) {
	if (direc > 0) {
		return low + wid * step / fs;
	} else {
		return low + wid * (fs - step) / fs;
	}
}

/*===========================================================
	機種に合ったＢＧＭ名用ＴＩＭの作成
		in:		short	mac_n		機種番号
===========================================================*/
void	make_bgm_tim(short mac_n) {
	RECT	src;
	short	i, by, dx, dy;
	
	dx = made_tim.x;
	dy = made_tim.y;
	src.x = timinf[F_BGM_NAME].x;
	src.w = timinf[F_BGM_NAME].w;
	by = timinf[F_BGM_NAME].y;
	src.y = by;
	src.h = 16;
	switch (mac_n) {
	case KAPP:
		MoveImage(&src, dx, dy);	//	BIG入賞F	
		MoveImage(&src, dx, dy+32);	//	BIG入賞F	
		src.y = by + 5*16;
		MoveImage(&src, dx, dy+16);	//	７	
		src.y = by + 6*16;
		MoveImage(&src, dx, dy+48);	//	かっぱ	
		for (i = 0; i < 3; i++) {
			src.y = (i + 1) * 16 + by;	//	小～終了	
			MoveImage(&src, dx, dy + 64 + i*32);
		}
		src.y = by + 4*16;
		for (i = 0; i < 3; i++) {
			MoveImage(&src, dx, dy + 80 + i*32);
		}
		break;
	case KAMI:
		MoveImage(&src, dx, dy);		// ＢＩＧ入賞ファンファーレ 
		MoveImage(&src, dx, dy + 32);
		src.y = by + 5*16;	//	７	
		MoveImage(&src, dx, dy + 16);
		MoveImage(&src, dx, dy + 80);
		src.y = by + 7*16;	//	福	
		MoveImage(&src, dx, dy + 48);
		MoveImage(&src, dx, dy + 112);
		src.y = by + 8*16;	//	残６	
		MoveImage(&src, dx, dy + 144);
		src.y = by + 16;	//	小役	
		for (i = 0; i < 3; i++) {
			MoveImage(&src, dx, dy + 64 + 32 * i);
		}
		for (i = 0; i < 2; i++) {
			src.y = by + (i + 2) * 16;
			MoveImage(&src, dx, dy + 160 + i*32);
		}
		src.y = by + 4*16;	//	空白	
		MoveImage(&src, dx, dy + 176);
		MoveImage(&src, dx, dy + 208);
		break;
	}
}

/*===========================================================
	垂直カーソル配置
		in:		char	pos		0:退場中	1:出場中
===========================================================*/
void	set_vcur(char pos) {
	POL_MEMB	*cpm;
	
	cpm = &sip->panel_rate.cursor;
	cpm->x = sip->panel_rate.x + 61 + sip->panel_rate.bonus_n * 44 - (pos - 1) * HIDE_XOFS;
	poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
}

/*===========================================================
	数値のＵＶ設定
		valの値が負の場合は特殊記号
			-1	スラッシュ
			-2	クエスチョンマーク
		
		in:		POL_MEMB	*pmp	ポリ構造体
				short		val		値
				short		keta	値の指定桁
		out:	void
===========================================================*/
void	set_numuv(POL_MEMB *pmp, short val, short keta) {
	int		i, num;
	
	if (val >= 0) {
		for (i = 1; i < keta; i++) {
			val /= 10;
		}
		num = val % 10;
	} else {
		num = 9 - val;
	}
	chg_uv(pmp, num * 8, 0, -1, -1);
}

/*===========================================================
	確率値のＵＶ設定
		in:		short	machine	機種番号
				short	bonus	ボーナス種別	0:BIG	1:REG
				short	set		設定値			-1　→	???
				short	val		値
		out:	void
===========================================================*/
void	set_numb(short machine, short bonus, short set, short val) {
	POL_MEMB	*cpm;
	int			i;
	
	cpm = &sip->rate_num_str[machine][bonus][set].pm[2];
	for (i = 2; i < 5; i++, cpm++) {
		set_numuv(cpm, val, -i + 5);
	}
}

/*===========================================================
	数字用ポリの初期化
		in:		void
		out:	void
===========================================================*/
void	init_rate_nums(void) {
//	RATE_N		rate_num_str[2][2][8];	//	数字用[機種][ボーナス種別][確率設定] 
	RATE_N		*c_rn;
	POL_MEMB	*cpm;
	int			i, j, k, l;
	short		*c_br;
	
	c_rn = &sip->rate_num_str[1][0][0];
	for (i = 1; i > -1; i--, c_rn -= 32) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 8; k++, c_rn++) {
				cpm = &c_rn->pm[0];
				for (l = 0; l < 5; l++, cpm++) {
					spr_set(cpm, 640, 0, 8, 16, F_STR_NUM, FALSE, PRI_MAC - 1);
					cpm->r = 0x80;	cpm->g = 0x80;	cpm->b = 0x80;
					poly_rgbset((void *)cpm->pp, cpm->r, cpm->g, cpm->b);
					if (l < 2)
						poly_uvset(cpm->pp, cpm->tp.u + 8 + 8 * ((l != 0) ? 9: 0), cpm->tp.v, cpm->tp.tw, cpm->tp.th);
					else
						set_numuv(cpm, bonus_rate[i][k][j], -l + 5);
				}
			}
		}
	}
}
/*===========================================================
	数字用ポリの破棄
===========================================================*/
void	free_rate_nums(void) {
	RATE_N		*c_rn;
	POL_MEMB	*cpm;
	int			i, j, k, l;
	
	c_rn = &sip->rate_num_str[0][0][0];
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < 8; k++, c_rn++) {
				cpm = c_rn->pm;
				for (l = 0; l < 5; l++, cpm++) {
					poly_kill(cpm->pp);
				}
			}
}

/*===========================================================
	雲のポリゴンの初期化
		in:		void
		out:	void
===========================================================*/
void	init_cloud(void) {
	CLOUD		*c_cld;
	POL_MEMB	*cpm;
	short		i;
	
	sip->wind_dir = 0;
	
	c_cld = sip->cloud;
	for (i = 0; i < CLOUD_MAX; i++, c_cld++) {
		cpm = &c_cld->pm;
		spr_set(cpm, rnd(320) - 160, i * 40 + rnd(40) - 120, -1, -1, F_CLOUD1 + i, TRUE, PRI_CLOUD);
		cpm->x <<= 4;
		cpm->y <<= 4;
		
		c_cld->ow = cpm->w;
		c_cld->oh = cpm->h;
		c_cld->vx = 0;
		c_cld->vy = -0x10 - rnd(0x8);
	}
}
/*===========================================================
	ヘルプパネル初期化
===========================================================*/
void	init_help(void) {
	POL_MEMB	*cp;
	short		i, ctx, pal;
	
	sip->panel_help.x = P_HELP_L;
	sip->panel_help.y = P_HELP_U;
	//	パネル	
	init_waku(&sip->panel_help.frames, P_HELP_L, P_HELP_U, 112, 16, PRI_RATE, 1);
	//	文字列二枚＆ボタン４つ	
	for (i = 0; i < 4; i++) {
		cp = &sip->panel_help.but[i];
		//	○×□	
		spr_set(cp, P_HELP_L + 4 + i * 53, P_HELP_U + 4, -1, 16, F_BUTT, FALSE, PRI_RATE - 2);
		pal = (i < 3) ? i + 1: 3;
		cp->pp->clut = GetClut(cp->tp.cx, cp->tp.cy + pal);
		if (i >= 2) {	//	□	
			cp->x = P_HELP_L + 41;
			cp->y += 200;
		}
		poly_xyset((void *)cp->pp, cp->x, cp->y, cp->w, cp->h);
		chg_uv(cp, 0, 16 * pal, -1, 16);
		if (i < 2) {	//	文字列	
			cp = &sip->panel_help.str[i];
			spr_set(cp, P_HELP_L + 4, P_HELP_U + 4, -1, 16 * i, F_STR_HELP, FALSE, PRI_RATE - 1);
			chg_uv(cp, 0, i * 16, -1, 16);
		}
	}
}

/*===========================================================
	メッセージウィンドウ初期化
		in:		void
		out:	void
===========================================================*/
void	init_meswin(void) {
	POL_MEMB	*cpm;
	TIM_INF		*ctim;
	short		xp, yp, i, j, cx, cy, cw, ch, tx, ty, tw, th;
	
	xp = sip->meswin.x = MES_L;
	yp = sip->meswin.y = MES_U;
	//	黒板
	init_waku(&sip->meswin.frames, sip->meswin.x-1, sip->meswin.y, 248, 16, PRI_RATE, 0);
	
	xp = MES_L + 3;
	yp = MES_U + 4;
	cpm = &sip->meswin.mes_str[0][0];
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++, cpm++) {
			spr_set(cpm, xp + i * 96, yp, -1, 16, (i == 0) ? F_STR_MES_S: F_STR_MES_L, FALSE, PRI_MES - 1);
		}
	}
}

/*===========================================================
	台ウィンドウ初期化
		in:		void
		out:	void
===========================================================*/
void	init_machine(void) {
	short	i, fn;
	
	for (i = 0; i < MACHINE_MAX; i++) {
		if (i == 0) fn = F_MAC_KAPP; else fn = F_MAC_KAMI;
		spr_set(&sip->machine[i], MACH_L - (sip->mach_n - i) * HIDE_XOFS, MACH_U, 102, 174, fn, FALSE, PRI_MAC);
	}
}

/*===========================================================
	ロゴ達初期化	
		in:		void
		out:	void
===========================================================*/
void	init_logo(void) {
	short	i, fn;
	
	for (i = 0; i < MACHINE_MAX; i++) {
		if (i == 0) fn = F_LOGO_KAPP;
		else fn = F_LOGO_KAMI;
		spr_set(&sip->logo[i].pm, LOGO_L + HIDE_XOFS * (sip->mach_n - i), LOGO_U, -1, -1, fn, FALSE, PRI_LOGO);
	}
}

/*===========================================================
	雲の移動
		in:		void
		out:	void
===========================================================*/
void	move_cloud(void) {
	POL_MEMB	*cpm;
	CLOUD		*cc;
	short		i;
	
	if (vcount % 300 == 0)	sip->wind_dir = rnd(3) - 1;
	
	cc = sip->cloud;
	for (i = 0; i < CLOUD_MAX; i++, cc++) {
		cpm = &cc->pm;
		
		cpm->x += cc->vx + sip->wind_dir * 0x8;
		cpm->y += cc->vy;
		
		if (cpm->y < 120<<4 && (cpm->y>>4) % 4 == 0) {
			cpm->w++;
			cpm->h++;
		}
		
		if (cpm->y < (-300<<4) || cpm->x < (-320<<4) || cpm->x > (320<<4)) {
			cpm->x = (rnd(320) - 160)<<4;
			cpm->y = 300<<4;
			cc->vx = rnd(0x8) - 0x4;
			cc->vy = -0x10 - rnd(0x8);
			cpm->w = cc->ow;
			cpm->h = cc->oh;
		}
		poly_xyset((void *)cpm->pp, (cpm->x>>4) - cpm->w / 2, (cpm->y>>4) - cpm->h / 2, cpm->w, cpm->h);
	}
}

/*===========================================================
	パネル枠セット
===========================================================*/
void	set_waku(FRAMES *frp, short xp, short yp, short wid, short hei) {
	POL_MEMB	*cp;
	int			i;
	
	cp = frp->frame;
	for (i = 0; i < 8; i++, cp++) {
		if (i < 4) {
			cp->x = xp + ((i % 2) ? wid + 8: 0) - 4;
			cp->y = yp + ((i < 2) ? 0: hei + 8) - 4;
		} else if (i < 6) {
			cp->x = xp + 8 - 4;
			cp->y = yp + ((i == 4) ? 0: hei + 8) - 4;
		} else {
			cp->x = xp + ((i == 6) ? 0: wid + 8) - 4;
			cp->y = yp + 8 - 4;
		}
		poly_xyset((void *)cp->pp, cp->x, cp->y, cp->w, cp->h);
	}
}
/*===========================================================
	機種選択画面パネル初期化
===========================================================*/
void	init_macpanel(void) {
//	PANEL_RATE	panel_mac[2];		//	機種選択画面パネル 
	PANEL_RATE	*c_pr;
	POL_MEMB	*cpm;
	short		i, j, cx, cy, ctx;
	
	c_pr = &sip->panel_mac[1];
	for (i = 1; i >= 0; i--, c_pr--) {
		if (i == sip->mach_n)
			cx = P_MACH_L;
		else
			cx = P_MACH_L - HIDE_XOFS + i * HIDE_XOFS * 2;
		
		cy = P_MACH_U;
		
		c_pr->x = cx;
		c_pr->y = cy;
		c_pr->w = 116;
		c_pr->h = 112;
		init_waku(&c_pr->frames, c_pr->x, c_pr->y, c_pr->w, c_pr->h, PRI_MAC, 1);
		//	縦ガイド	
		cpm = &c_pr->vstr;
		spr_set(cpm, cx + 4, cy + 16 + 4, -1, 16*6, F_STR_RAT_V, FALSE, PRI_MAC - 1);
		cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + C_YELLOW);
		//	横ガイド	
		ctx = 0;
		cpm = &c_pr->hstr[0];
		for (j = 0; j < 3; j++, cpm++) {
			spr_set(cpm, cx + 4 + ctx, cy + 4, 32 + 8 * (j > 0), -1, F_STR_RAT_H, FALSE, PRI_MAC - 1);
			cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + j);
			chg_uv(cpm, ctx - (j > 1) * 4, 0, -1, -1);
			ctx += cpm->w + (j > 0) * 4;
		}
		//	無地	
		cpm = &c_pr->blank;
		spr_set(cpm, c_pr->x + 72 + 4, c_pr->y + 4, 7, 112, F_STR_RAT_V, FALSE, PRI_RATE);
		chg_uv(cpm, 0, 7 * 16, -1, 7);
	}
	
	set_nums(sip->scrmode);
}
/*===========================================================
	機種選択画面パネルポリ解放
===========================================================*/
void free_macpanel(void) {
	PANEL_RATE	*c_pr;
	short	i, j;
	
	c_pr = &sip->panel_mac[0];
	for (i = 0; i < 2; i++, c_pr++) {
		free_waku(&c_pr->frames);
		poly_kill(c_pr->vstr.pp);
		poly_kill(c_pr->blank.pp);
		for (j = 0; j < 3; j++) {
			poly_kill(c_pr->hstr[j].pp);
		}
	}
}

/*===========================================================
	レートパネル初期化
===========================================================*/
void	init_rpanel(int	sw) {
	PANEL_RATE	*prp;			//	確率設定画面パネル 
	POL_MEMB	*cp;
	short		i, ctx;
	
	if (sw < 1)	prp = &sip->panel_rate;
	else		prp = &sip->panel_chk_rate;
	
	prp->bonus_n = 0;
	prp->x = P_RATE_L + HIDE_XOFS;
	prp->y = P_RATE_U + sw * 32;
	prp->w = 116;
	if (sw < 1)	prp->h = 16*10;
	else		prp->h = 16 * 8;
	//	パネル	
	init_waku(&prp->frames, prp->x, prp->y, prp->w, prp->h, PRI_RATE, 1);
	//	縦項目	
	cp = &prp->vstr;
	if (sw < 1)
		spr_set(cp, prp->x + 4, prp->y + 4 + 16, -1, -1, F_STR_RAT_V, FALSE, PRI_RATE - 1);
	else
		spr_set(cp, prp->x + 4, prp->y + 4 + 16, -1, prp->h - 16, F_STR_RAT_V, FALSE, PRI_RATE - 1);
	cp->pp->clut = GetClut(cp->tp.cx, cp->tp.cy + C_YELLOW);
	//	横項目	
	ctx = 0;
	cp = &prp->hstr[0];
	for (i = 0; i < 3; i++, cp++) {
		spr_set(cp, prp->x + 4, prp->y + 4, 32 + 8*(i>0), -1, F_STR_RAT_H, FALSE, PRI_RATE - 1);
		cp->pp->clut = GetClut(cp->tp.cx, cp->tp.cy + i);
		chg_uv(cp, ctx - (i > 1) * 4, 0, -1, -1);
		ctx += cp->w + (i > 0) * 4;
	}
	if (sw < 1) {
		//	カーソル	
		spr_set(&prp->cursor, prp->x + 56, prp->y + 131, -1, -1, F_CUR_V, FALSE, PRI_RATE - 1);
	}
	//	無地	
	cp = &prp->blank;
	spr_set(cp, prp->x + 32 + 4, prp->y + 4, 84, prp->h, F_STR_RAT_V, FALSE, PRI_RATE);
	chg_uv(cp, 0, 16 * 7, 8, 8);
}
/*===========================================================
	レートパネルポリ達解放
===========================================================*/
void	free_rpanel(int sw) {
	PANEL_RATE	*prp;
	POL_MEMB	*cp;
	short		i;
	
	if (sw < 1)	prp = &sip->panel_rate;
	else		prp = &sip->panel_chk_rate;
	
	free_waku(&prp->frames);
	poly_kill(prp->vstr.pp);
	poly_kill(prp->blank.pp);
	cp = &prp->hstr[0];
	for (i = 0; i < 3; i++) {
		poly_kill(cp++->pp);
	}
	
	if (sw < 1)
		poly_kill(prp->cursor.pp);
}
/*===========================================================
	サウンドパネル初期化
		in:		void
		out:	void
===========================================================*/
void	init_spanel(void) {
	PANEL_SOUND	*ssp;			//	サウンド選択用 
	POL_MEMB	*cpm;
	short		i, j;
	
	make_bgm_tim(sip->mach_n);
	
	ssp = &sip->st_sound;
	
	ssp->cur_p = 0;
	ssp->disp_n[0] = ssp->snd_n[0] = 0;
	ssp->disp_n[1] = ssp->snd_n[1] = 0;
	
	ssp->x = P_SOUND_L + HIDE_XOFS;
	ssp->y = P_SOUND_U;
	ssp->w = 112;		ssp->h = 112;
	
	//	枠	
	init_waku(&ssp->frames, ssp->x, ssp->y, ssp->w, ssp->h, PRI_RATE, 1);
	//	横項目	
	cpm = &ssp->upstr;
	spr_set(cpm, ssp->x + 4, ssp->y + 4, ssp->w, 16, F_STR_MOD, FALSE, PRI_RATE);
	chg_uv(cpm, 0, 6 * 16, -1, -1);
	cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + C_YELLOW);
	//	無地	
	cpm = &ssp->blank;
	spr_set(cpm, ssp->x + 4, ssp->y + 4 + 16, ssp->w, ssp->h - 16, F_STR_RAT_V, FALSE, PRI_RATE);
	chg_uv(cpm, 0, 7 * 16, 7, 7);
	for (i = 0; i < 2; i++) {
		//	ＳＥ名称	
		cpm = &ssp->se_name[i];
		spr_set(cpm, ssp->x + 4, ssp->y + 40, 112 * i, 16, F_SE_NAME, FALSE, PRI_RATE - 1);
		chg_uv(cpm, 0, 16 * ssp->disp_n[0], -1, -1);
		cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + C_GREEN);
		//	ＢＧＭ名称	
		cpm = &ssp->bgm_name[i];
		spr_set(cpm, ssp->x + 4, ssp->y + 24 + 56, 112 * i, 32, F_BGM_NAME, FALSE, PRI_RATE - 1);
		timi2texi(&made_tim, &cpm->tp);
		cpm->tp.th = 32;
		poly_ft4_fset(cpm->pp, cpm->tp.cx, cpm->tp.cy, made_tim.x, made_tim.y, 0, 0, cpm->tp.mode);
		chg_uv(cpm, 0, 32 * ssp->disp_n[1], -1, -1);
		cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + C_GREEN);
		//	項目名 
		cpm = &ssp->title[i];
		spr_set(cpm, ssp->x + 12, ssp->y+24 + i * 36, -1,16, F_STR_SOU, FALSE, PRI_RATE-1);
		chg_uv(cpm, 0, i * 16, -1, -1);
		
		//	項目	e
		for (j = 0; j < 2; j++) {	//	桁	
			cpm = &ssp->string[i][j];
			spr_set(cpm, ssp->x+76+ j *8, ssp->y+26+ i *36, 8, 16, F_STR_NUM, FALSE, PRI_RATE-2);
			set_numuv(cpm, ssp->snd_n[i] + 1, -j + 2);
		}
	}
	//	カーソル 
	spr_set(&ssp->cursor, ssp->x+68, ssp->y+29, -1, -1, F_CUR_H, FALSE, PRI_RATE-1);
}
/*===========================================================
	サウンドパネルポリ達解放
===========================================================*/
void	free_spanel(void) {
	PANEL_SOUND	*ssp;			//	サウンド選択用 
	short	i, j;
	
	ssp = &sip->st_sound;
	free_waku(&ssp->frames);
	poly_kill(ssp->upstr.pp);
	poly_kill(ssp->blank.pp);
	poly_kill(ssp->cursor.pp);
	for (i = 0; i < 2; i++) {
		poly_kill(ssp->se_name[i].pp);
		poly_kill(ssp->bgm_name[i].pp);
		poly_kill(ssp->title[i].pp);
		for (j = 0; j < 2; j++) {
			poly_kill(ssp->string[i][j].pp);
		}
	}
}
/*===========================================================
	数字達プライオリティ設定
		in:		short	pri		プライオリティ値
===========================================================*/
void	set_numpri(short pri) {
	RATE_N		*c_rn;
	POL_MEMB	*cpm;
	int			i, j, k, l;
	
	c_rn = &sip->rate_num_str[0][0][0];
	for (i = 0; i < MACHINE_MAX; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < RMODE_MAX; k++, c_rn++) {
				cpm = c_rn->pm;
				for (l = 0; l < 5; l++, cpm++) {
					poly_priset(cpm->pp, pri);
				}
			}
}

/*===========================================================
	数字達位置設定
		in:		signed char	mode	画面モード
===========================================================*/
void	set_nums(signed char mode) {
	PANEL_RATE	*c_pr;
	RATE_N		*c_rn;
	POL_MEMB	*cpm;
	int			i, j, k, mac;
	
	switch (mode) {
	case SEL_MACHINE:
		c_rn = &sip->rate_num_str[0][0][0];
		c_pr = &sip->panel_mac[0];
		for (mac = 0; mac < MACHINE_MAX; mac++, c_pr++)	//	機種	
			for (i = 0; i < 2; i++) {					//	ボーナス種	
				for (j = 0; j < 6; j++, c_rn++) {		//	設定	
					cpm = c_rn->pm;
					for (k = 0; k < 5; k++, cpm++) {		//	文字	
						cpm->x = c_pr->x + 36 + 44 * i + 8 * k;
						cpm->y = c_pr->y + 20 + 16 * j;
						poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
					}
				}
				c_rn += 2;
			}
		break;
	case SEL_RATE:
		c_rn = &sip->rate_num_str[sip->mach_n][0][0];
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 8; j++, c_rn++) {
				cpm = c_rn->pm;
				for (k = 0; k < 5; k++, cpm++) {
					cpm->x = sip->panel_rate.x + 36 + 44 * i + 8 * k;
					cpm->y = sip->panel_rate.y + 20 + 16 * j;
					if (j == 7) cpm->y += 8;
					poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
				}
			}
		}
		break;
	case SEL_RATE_CHK:
		c_rn = &sip->rate_num_str[sip->mach_n][0][0];
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 7; j++, c_rn++) {
				cpm = c_rn->pm;
				for (k = 0; k < 5; k++, cpm++) {
					cpm->x = sip->panel_chk_rate.x + 36 + 44 * i + 8 * k;
					cpm->y = sip->panel_chk_rate.y + 20 + 16 * j;
					poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
				}
			}
			c_rn++;
		}
		break;
	default:
		break;
	}
}
/*===========================================================
	カーソル初期化	
		in:		void
		out:	void
===========================================================*/
void	init_cursor(void) {
	POL_MEMB	*cmp;
	short		i;
	
	for (i = 0; i < 2; i++) {	//	ツイン	
		cmp = &sip->tcur[i].pm;
		
		sip->tcur[i].anm = 0;
		sip->tcur[i].count = 0;
		
		spr_set(cmp, C_TWIN_L + i * 272, C_TWIN_U, 16, 32, F_CUR_T, FALSE, PRI_BACK - 2);
		chg_uv(cmp, i * 16, 32 * sip->tcur[i].anm, -1, -1);
	}
	
	//	指	
	cmp = &sip->fcur.pm;
	sip->fcur.vx = sip->fcur.vy = 0;
	spr_set(cmp, 200 + 160, 200, -1,-1, F_CUR_F, FALSE, PRI_CUR);
	sip->fcur.dx = cmp->x;
	sip->fcur.dy = cmp->y;
}

/*===========================================================
	初期化元締	
		in:		void
		out:	void
===========================================================*/
void	init_select(void) {
	POLY_G4	*bp;
	short	i;
	
	// バックドロップ 
	sip->backp = poly_g4_make();
	bp = sip->backp;
	poly_xyset((void *)bp, -160, -120, 320, 240);
	bp->r0 = bp->r1 = 20;// 40;
	bp->r2 = bp->r3 = 136;//136;
	bp->g0 = bp->g1 = 80;//112;
	bp->g2 = bp->g3 = 200;//200;
	bp->b0 = bp->b1 = 240;//208;
	bp->b2 = bp->b3 = 240;//240;
	poly_priset(bp, PRI_BACK);
	
	/*	イニシャライズ	*/
	sip->scrmode = SEL_MACHINE;
	sip->gamemode = MODE_NORM;
	sip->mach_n = machine_no;
	sip->rate_n = 0;
	sip->chg_menu = sip->chg_scr = FALSE;
	sip->exitF = 0;
	
	koyakucnt_reset = 0;
	
	for (i = 0; i < 8; i++) {
		sip->work[i] = 0;
	}
	
	init_rate_nums();
	init_cloud();
	
	init_macpanel();
	init_modepanel();
	init_rpanel(0);
	init_rpanel(1);	// 設定判別用 
	init_resetpanel(0);
	init_resetpanel(1);
	init_spanel();
	init_help();
	init_meswin();
	
	init_cursor();
	init_machine();
	init_logo();
}
/*===========================================================
	まとめてFree!!!
===========================================================*/
void	free_select(void) {
	short	i, j;
	
	poly_kill(sip->backp);
	free_rate_nums();
	for (i = 0; i < CLOUD_MAX; i++) {
		poly_kill(sip->cloud[i].pm.pp);
	}
	
	free_macpanel();
	free_waku(&sip->mode_panel.frames);
	for (i = 0; i < MODE_MAX; i++) {
		poly_kill(sip->mode_panel.m_clmW[i].pp);
	}
	
	for (i = 0; i < 2; i++) {
		free_waku(&sip->reset_panel[i].frames);
		for (j = 0; j < 2; j++) {
			poly_kill(sip->reset_panel[i].m_clmW[j].pp);
		}
	}
	
	free_rpanel(0);
	free_rpanel(1);
	free_spanel();
	free_waku(&sip->panel_help.frames);
	for (i = 0; i < 4; i++) {
		poly_kill(sip->panel_help.but[i].pp);
		if (i < 2) {
			poly_kill(sip->panel_help.str[i].pp);
		}
	}
	free_waku(&sip->meswin.frames);
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++) {
			poly_kill(sip->meswin.mes_str[i][j].pp);
		}
	
	poly_kill(sip->fcur.pm.pp);
	for (i = 0; i < 2; i++) {
		poly_kill(sip->tcur[i].pm.pp);
	}
	for (i = 0; i < MACHINE_MAX; i++) {
		poly_kill(sip->machine[i].pp);
		poly_kill(sip->logo[i].pm.pp);
	}
}

/*===========================================================
	機種選択でのキー入力処理	
		in:		void
		out:	void
===========================================================*/
void	key_machine(void) {
	short	s_panel, d_panel, kval;
	
	s_panel = sip->mach_n;
	d_panel = s_panel ^ 1;	//	機種が増えたときは変えること	
	
	if (sip->chg_scr == TRUE || sip->chg_menu == TRUE) return;
	
	if (pad_beta & PADL_LEFT) {			//	←	
		kval = key_push(bit2d(PADL_LEFT));
		
		if (kval) {
			sip->panel_mac[d_panel].x = sip->panel_mac[s_panel].x + 320;
			sip->logo[d_panel].pm.x = sip->logo[s_panel].pm.x + 320;
			sip->machine[d_panel].x = sip->machine[s_panel].x + 320;
			sip->mach_n++;
			if (sip->mach_n >= MACHINE_MAX) sip->mach_n = 0;
			sip->work[0] = -1;	//	work[0]を移動方向に使う	
			sip->work[7] = 0;	//	work[7]をカウンタに使う	
			sip->chg_menu = TRUE;
			_SE_SUR2
		}
	} else if (pad_beta & PADL_RIGHT) {	//	→	
		kval = key_push(bit2d(PADL_RIGHT));
		
		if (kval) {
			sip->panel_mac[d_panel].x = sip->panel_mac[s_panel].x - 320;
			sip->logo[d_panel].pm.x = sip->logo[s_panel].pm.x - 320;
			sip->machine[d_panel].x = sip->machine[s_panel].x - 320;
			sip->mach_n--;
			if (sip->mach_n < 0) sip->mach_n = 1;
			sip->work[0] = +1;	//	work[0]を移動方向に使う	
			sip->work[7] = 0;	//	work[7]をカウンタに使う	
			sip->chg_menu = TRUE;
			_SE_SUR2
		}
	} else if (pad_cnt & PADR_RIGHT) {	//	○	
		//	カーソルを消す	
		poly_doff(sip->tcur[0].pm.pp);
		poly_doff(sip->tcur[1].pm.pp);
		
		sip->work[0] = sip->scrmode;	//	work[0]に切替え前のscrmodeをストアする	
		sip->scrmode++;
		sip->work[7] = 0;			//	work[7]をカウンタに使う	
		sip->chg_scr = TRUE;
		_SE_OK
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		//	タイトルに戻る
		sip->exitF = -1;
		_SE_CANCEL
	}
}

/*===========================================================
	小役カウンタリセットのキー処理
===========================================================*/
void	key_reset(void) {
	if (sip->chg_scr || sip->chg_menu) return;
	
	if (pad_beta & PADL_UP) {				//	↑	
		if (key_push(bit2d(PADL_UP))) {
			chg_col_reset(koyakucnt_reset, C_WHITE, (sip->gamemode == MODE_CHECK) ? 1: 0);
			if (koyakucnt_reset > 0)	koyakucnt_reset--;
			else						koyakucnt_reset = 1;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	//	↓	
		if (key_push(bit2d(PADL_DOWN))) {
			chg_col_reset(koyakucnt_reset, C_WHITE, (sip->gamemode == MODE_CHECK) ? 1: 0);
			if (koyakucnt_reset < 1)	koyakucnt_reset++;
			else						koyakucnt_reset = 0;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_cnt & PADR_RIGHT) {	//	○	
		sip->work[0] = sip->scrmode;
		sip->scrmode = SEL_OK;
		sip->chg_scr = TRUE;
		sip->work[7] = 0;
		_SE_OK
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		if (sip->rate_n == 7) {
			sip->scrmode = SEL_NUM;
		} else {
			sip->scrmode = (sip->gamemode == MODE_CHECK) ? SEL_RATE_CHK: SEL_RATE;
		}
		sip->work[0] = SEL_RESET;
		sip->work[7] = 0;			//	カウンタ
		sip->chg_scr = TRUE;
		_SE_CANCEL
	}
}
/*===========================================================
	モード選択でのキー入力処理	
		in:		void
		out:	void
===========================================================*/
void	key_mode(void) {
	if (sip->chg_scr == TRUE || sip->chg_menu == TRUE) return;
	
	if (pad_beta & PADL_UP) {				//	↑	
		if (key_push(bit2d(PADL_UP))) {
			chg_col_mode(sip->gamemode, C_WHITE);
			sip->gamemode--;
			if (sip->gamemode < 0) sip->gamemode = MODE_MAX - 1;
			if (sip->mach_n == KAMI) {	//	かみさま	
				if (sip->gamemode == MODE_CHECK || sip->gamemode == MODE_CROSS)
					sip->gamemode = MODE_UNLOCK;
			}
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	//	↓	
		if (key_push(bit2d(PADL_DOWN))) {
			chg_col_mode(sip->gamemode, C_WHITE);
			sip->gamemode++;
			if (sip->mach_n == KAMI) {	//	かみさま	
				if (sip->gamemode == MODE_CHECK || sip->gamemode == MODE_CROSS)
					sip->gamemode = MODE_REACH;
			}
			if (sip->gamemode >= MODE_MAX) sip->gamemode = 0;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_cnt & PADR_RIGHT) {	//	○	
		sip->work[0] = sip->scrmode;
		switch (sip->gamemode) {
		case MODE_NORM:
			sip->scrmode = SEL_RATE;
			break;
		case MODE_SOUND:
			sip->scrmode = SEL_SOUNDLOAD;
			SEL_SEQ_END	// ＢＧＭ消す之介 
			MACINE=sip->mach_n;
#if 0
			game_vab_set(1);	//	iteya 12/28 音のデータ読む
#endif
			break;
		case MODE_CHECK:
			sip->scrmode = SEL_RATE_CHK;
			break;
		default:
			sip->scrmode = SEL_OK;
			break;
		}
		sip->chg_scr = TRUE;
		sip->work[7] = 0;
		_SE_OK
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		sip->work[0] = sip->scrmode;	//	バックアップ
		sip->scrmode = SEL_MACHINE;
		sip->work[7] = 0;			//	カウンタ
		sip->chg_scr = TRUE;
		_SE_CANCEL
	}
}

/*===========================================================
	レート選択でのキー入力処理	
		in:		void
		out:	void
===========================================================*/
void	key_rate(void) {
	short	kval;
	
	if (sip->chg_scr == TRUE || sip->chg_menu == TRUE) return;
	
	if (pad_beta & PADL_UP) {				//	↑	
		kval = key_push(bit2d(PADL_UP));
		
		if (kval != 0) {
			chg_col_rate(sip->rate_n, 0);
			sip->rate_n--;
			if (sip->rate_n < 0) sip->rate_n = RMODE_MAX - 1;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	//	↓	
		kval = key_push(bit2d(PADL_DOWN));
		
		if (kval != 0) {
			chg_col_rate(sip->rate_n, 0);
			sip->rate_n++;
			if (sip->rate_n >= RMODE_MAX) sip->rate_n = 0;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_cnt & PADR_RIGHT) {	//	○	
		sip->work[0] = sip->scrmode;
		if (sip->rate_n == 7) {	// 確率カスタム 
			sip->scrmode = SEL_NUM;
		} else {				// プリセット確率 
			sip->scrmode = SEL_RESET;
		}
		
		sip->chg_scr = TRUE;
		sip->work[7] = 0;
		_SE_OK
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		sip->work[0] = sip->scrmode;	//	バックアップ
		sip->scrmode = SEL_MODE;
		chg_col_mode(sip->gamemode, C_WHITE);
		sip->work[7] = 0;			//	カウンタ
		sip->chg_scr = TRUE;
		_SE_CANCEL
	}
}

/*===========================================================
	サウンドでのキー入力処理	
===========================================================*/
char	ringing = 0;
void	key_sound(void) {
	PANEL_SOUND	*ssp;			//	サウンド選択用 
	short	i, *vp;
	
	ssp = &sip->st_sound;
	if (sip->chg_scr == TRUE || sip->chg_menu == TRUE) return;
	
	if (pad_beta & PADL_UP) {				//	↑	
		if (key_push(bit2d(PADL_UP))) {
			chg_col_sound(ssp->cur_p, 0);
			ssp->cur_p--;
			if (ssp->cur_p < 0) ssp->cur_p = 1;	//	ちょっと嫌かな	
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	//	↓	
		if (key_push(bit2d(PADL_DOWN))) {
			chg_col_sound(ssp->cur_p, 0);
			ssp->cur_p++;
			if (ssp->cur_p > 1) ssp->cur_p = 0;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_LEFT) {	//	←	
		if (key_push(bit2d(PADL_LEFT))) {
			vp = &ssp->snd_n[ssp->cur_p];
			(*vp)--;
			if (*vp < 0) {
				if (ssp->cur_p == 1)
					*vp = bgm_max[sip->mach_n] - 1;
				else
					*vp = se_max[sip->mach_n] - 1;
			}
			for (i = 0; i < 2; i++) {
				set_numuv(&ssp->string[ssp->cur_p][i], *vp + 1, -i + 2);
			}
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
		}
	} else if (pad_beta & PADL_RIGHT) {	//	→	
		if (key_push(bit2d(PADL_RIGHT))) {
			vp = &ssp->snd_n[ssp->cur_p];
			(*vp)++;
			if (ssp->cur_p == 1) {
				if (*vp >= bgm_max[sip->mach_n]) *vp = 0;
			} else {
				if (*vp >= se_max[sip->mach_n]) *vp = 0;
			}
			for (i = 0; i < 2; i++) {
				set_numuv(&ssp->string[ssp->cur_p][i], *vp + 1, -i + 2);
			}
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
		}
#if 1
	} else if (pad_cnt & PADR_RIGHT) {	//	○ 
		//		ssn->cur_p	０：ＳＥ	１：ＢＧＭ
/*	ＳＥ（両機種共通）：	０：メダル投入音
							１：リールスタート音
							２：ウェイト音
							３：リール停止受付音
							４：リール停止音
							５：メダル払い出し音
							６：リプレイ音
							７：リーチ音
							８：エラー音
	ＢＧＭ（BIN貧／かっぱ）	０：セブン入賞						セブン入賞
							１：福の神入賞						かっぱ入賞
							２：小役ゲーム中（７）				小役中
							３：小役ゲーム中（福）				ＪＡＣ中
							４：小役ゲーム中（残り６Ｇ以下）	ＢＩＧ終了
							５：ＪＡＣ中
							６：ＢＩＧ終了	*/
		vp = &ssp->snd_n[ssp->cur_p];	// vpは番号のポインタ 
		
		// 鳴らす 
		if (ringing) {
			game_seq_stop();
			se_stop();
		}
		if (ssp->cur_p)	game_seq_set(*vp,1);	//	iteya 12/28 シーケンスのほう 
		else {
			se_stop();
			if (*vp > 7) {
				_SE_ERROR
			} else {
				gse_start(*vp);
			}
		}
		ringing = TRUE;
	} else if (pad_cnt & PADR_LEFT) {		//	■ 
		vp = &ssp->snd_n[ssp->cur_p];
		// 止める	音停止のハズ 
		if (ssp->cur_p)	game_seq_stop();
		else			se_stop();
		ringing = FALSE;
#endif
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		sip->work[0] = sip->scrmode;	//	バックアップ
		sip->scrmode = SEL_SOUNDLOAD;
		chg_col_mode(sip->gamemode, C_WHITE);
		sip->work[7] = 0;			//	カウンタ
		sip->chg_scr = TRUE;

		game_vab_end();
		game_seq_stop();

//		SEL_SEQ
		_SE_CANCEL
	}
}

/*===========================================================
	確率手設定時のキー操作
===========================================================*/
void	key_setnum(void) {
	short	*vp, val;
	
	if (sip->chg_scr == TRUE || sip->chg_menu == TRUE) return;
	
	if (pad_beta & PADL_LEFT) {				//	←	
		val = key_push(bit2d(PADL_LEFT));
		
		if (val) {
			sip->panel_rate.bonus_n--;
			if (sip->panel_rate.bonus_n < 0) sip->panel_rate.bonus_n = 1;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_RIGHT) {	//	→	
		val = key_push(bit2d(PADL_RIGHT));
		
		if (val) {
			sip->panel_rate.bonus_n++;
			if (sip->panel_rate.bonus_n > 1) sip->panel_rate.bonus_n = 0;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_UP) {		//	↑	
		val = keyin_slide(bit2d(PADL_UP));
		val += (val == -1) ? 2: 0;
		vp = &bonus_rate[sip->mach_n][7][sip->panel_rate.bonus_n];
		if (*vp < 999 && val) {
			*vp += val;
			if (*vp > 999)
				*vp = 999;
			else
				_SE_CUR1
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
		}
	} else if (pad_beta & PADL_DOWN) {		//	↓	
		val = keyin_slide(bit2d(PADL_DOWN));
		val += (val == -1) ? 2: 0;
		vp = &bonus_rate[sip->mach_n][7][sip->panel_rate.bonus_n];
		if (*vp > 10 && val) {
			*vp -= val;
			if (*vp < 10)
				*vp = 10;
			else
				_SE_CUR1
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
		}
	} else if (pad_cnt & PADR_RIGHT) {	//	○	
		sip->work[0] = sip->scrmode;
		sip->scrmode = SEL_RESET;
		sip->chg_scr = TRUE;
		sip->work[7] = 0;
		_SE_OK
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		sip->work[0] = sip->scrmode;	//	バックアップ
		sip->scrmode = SEL_RATE;
		sip->work[7] = 0;			//	カウンタ
		sip->chg_scr = TRUE;
		_SE_CANCEL
	}
}

/*===========================================================
	確認状態のキー入力
===========================================================*/
void	key_ok(void) {
	if (sip->chg_scr == TRUE || sip->chg_menu == TRUE) return;
	
	if (pad_cnt & PADR_RIGHT) {	//	○	進んじゃう	
		int		tmp;
		
		if (sip->gamemode > MODE_NORM && sip->gamemode < MODE_REACH) {
			tmp = (sip->mach_n) ? 4: sip->gamemode - 1;
		} else if (sip->gamemode == MODE_HAWKEYE) {
			tmp = (sip->mach_n) ? 5: 3;
		} else {
			tmp = -1;
		}
		if (tmp > -1)	restore_setting_data(&copy_sav[tmp]);
		
		switch (sip->gamemode) {
		case MODE_UNLOCK:
			tmp = 0 + sip->mach_n * 4;
			restore_setting_data(&copy_sav[tmp]);
			break;
		case MODE_CHECK:
			tmp = 1;
			restore_setting_data(&copy_sav[tmp]);
			break;
		case MODE_CROSS:
			tmp = 2;
			restore_setting_data(&copy_sav[tmp]);
			break;
		case MODE_HAWKEYE:
			tmp = 3 + sip->mach_n * 2;
			restore_setting_data(&copy_sav[tmp]);
			break;
		default:
			sw_config = 0x81;
			break;
		}
		
		switch (sip->gamemode) {
		case MODE_NORM:		sw_config = 0x91;	break;
		case MODE_REACH:	sw_config = 0xB5;
			r_drum.req = 0;
		case MODE_FLASH:
			ZOOM_LEVEL = 2;
			break;
		}
		
		flash_no = 0;
		sip->exitF = 1;
		_SE_OK
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		sip->scrmode = sip->work[0];	//	リストア	
		sip->work[0] = SEL_OK;
		sip->work[7] = 0;			//	カウンタ
		sip->chg_scr = TRUE;
		_SE_CANCEL
	}
}
/*===========================================================
	ロゴ・台・パネルをまとめてスライドさせる
===========================================================*/
void	lmp_slide(void) {
	POL_MEMB	*lcmp, *mcmp;
	short		offset, ofs, i;
	
	offset = sip->work[7] * HIDE_XOFS / CHG_SYNC;
	for (i = 0; i < MACHINE_MAX; i++) {
		ofs = offset * sip->work[0] - ((i == sip->mach_n) ? HIDE_XOFS * sip->work[0]: 0);
		
		lcmp = &sip->logo[i].pm;
		mcmp = &sip->machine[i];
		
		lcmp->x = LOGO_L + ofs;
		poly_xyset((void *)lcmp->pp, lcmp->x, lcmp->y, lcmp->w, lcmp->h);
		
		mcmp->x = MACH_L + ofs;
		poly_xyset((void *)mcmp->pp, mcmp->x, mcmp->y, mcmp->w, mcmp->h);
		
		sip->panel_mac[i].x = P_MACH_L + ofs;
		set_macpanel(&sip->panel_mac[i]);
	}
}

/*===========================================================
	数字達のシェードを変更する
		絶対値1			ゆっくり
		絶対値それ以上	いっきに
===========================================================*/
void	shade_nums(short direc) {
	RATE_N		*c_rn;
	POL_MEMB	*cp;
	int			i, j, k, l, tmp;
	short		colofs, cr, cg, cb;
	
	tmp = sip->work[7];
	if (direc > 1 || direc < -1) {
		if (direc > 0) {
			colofs =  0x80;
		} else {
			colofs = 0x40;
		}
	} else {
		colofs = make_step(SHADE_L, SHADE_W, CHG_SYNC, tmp, direc);
	}
	
	c_rn = &sip->rate_num_str[0][0][0];
	for (i = 0; i < MACHINE_MAX; i++)
		for (j = 0; j < 2; j++)
			for (k = 0; k < RMODE_MAX; k++, c_rn++) {
				cp = c_rn->pm;
				for (l = 0; l < 5; l++, cp++) {
					if (direc > 1 || direc < -1) {
						if (direc > 0) {
							poly_rgbset((void *)cp->pp, cp->r, cp->g, cp->b);
						} else {
							poly_rgbset((void *)cp->pp, cp->r/2, cp->g/2, cp->b/2);
						}
					} else {
						cr = make_step(cp->r/2, cp->r/2, CHG_SYNC, tmp, direc);
						cg = make_step(cp->g/2, cp->g/2, CHG_SYNC, tmp, direc);
						cb = make_step(cp->b/2, cp->b/2, CHG_SYNC, tmp, direc);
						poly_rgbset((void *)cp->pp, cr, cg, cb);
					}
				}
			}
}
/*===========================================================
	ロゴと機種別確率パネルのシェードを変更する
		in:		short	direc	０以下			標準→ハーフ
								０より大きい	ハーフ→標準
===========================================================*/
void	shade_logo(short direc) {
	PANEL_RATE	*c_pr;
	POL_MEMB	*cp, *hp;
	int			colofs, i;
	
	colofs = make_step(SHADE_L, SHADE_W, CHG_SYNC, sip->work[7], direc);
	
	poly_rgbset((void *)sip->logo[sip->mach_n].pm.pp, colofs, colofs, colofs);
	
	c_pr = &sip->panel_mac[sip->mach_n];
	cp = c_pr->frames.frame;
	for (i = 0; i < 8; i++, cp++) {
		poly_rgbset((void *)cp->pp, colofs, colofs, colofs);
		if (i < 3) {
			poly_rgbset((void *)c_pr->hstr[i].pp, colofs, colofs, colofs);
		}
	}
	poly_rgbset((void *)c_pr->vstr.pp, colofs, colofs, colofs);
}

/*===========================================================
	モード選択パネルのシェードを調節する
		in:		short	direc	０以下			標準→ハーフ
								０より大きい	ハーフ→標準
===========================================================*/
void	shade_ratep(short direc, int pnum) {
	PANEL_RATE	*prp;
	int			i, colofs;
	
	if (pnum > 0)
		prp = &sip->panel_chk_rate;
	else
		prp = &sip->panel_rate;
	
	colofs = make_step(SHADE_L, SHADE_W, CHG_SYNC, sip->work[7], direc);
	for (i = 0; i < 8 - pnum; i++) {
		poly_rgbset((void *)prp->frames.frame[i].pp, colofs, colofs, colofs);
		if (i < 3)
			poly_rgbset((void *)prp->hstr[i].pp, colofs, colofs, colofs);
	}
	poly_rgbset((void *)prp->vstr.pp, colofs, colofs, colofs);
	poly_rgbset((void *)prp->blank.pp, colofs, colofs, colofs);
	if (pnum < 1)
		poly_rgbset((void *)prp->cursor.pp, colofs, colofs, colofs);
}
void	shade_modep(short direc) {
	int			i, colofs;
	
	colofs = make_step(SHADE_L, SHADE_W, CHG_SYNC, sip->work[7], direc);
	for (i = 0; i < 8; i++) {
		poly_rgbset((void *)sip->mode_panel.frames.frame[i].pp, colofs, colofs, colofs);
		poly_rgbset((void *)sip->mode_panel.m_clmW[i].pp, colofs, colofs, colofs);
	}
}

/*===========================================================
	モード選択パネル初期化		041
		in:		void			6 7
		out:	void			253
===========================================================*/
void	init_modepanel(void) {
	POL_MEMB	*cmp;
	int			i;
	short		ctx, cty;
	
	sip->mode_panel.x = P_MODE_L + HIDE_XOFS;
	sip->mode_panel.y = P_MODE_U;
	sip->mode_panel.w = 112;
	sip->mode_panel.h = 16 * 8;
	//	ワク	
	init_waku(&sip->mode_panel.frames, sip->mode_panel.x, sip->mode_panel.y, sip->mode_panel.w, sip->mode_panel.h, PRI_MODE, 1);
	
	//	項目	
	for (i = 0; i < MODE_MAX; i++) {
		cmp = &sip->mode_panel.m_clmW[i];
		spr_set(cmp, sip->mode_panel.x + 4, sip->mode_panel.y + 4 + 16 * i,-1, 16, F_STR_MOD, FALSE, PRI_MODE - 1);
		chg_uv(cmp, 0, i * cmp->h, -1, -1);
	}
}
/*===========================================================
	小役カウンタ状態設定パネル初期化
===========================================================*/
void	init_resetpanel(int mode) {
	MODE_PANEL	*panelp;
	POL_MEMB	*cpmp;
	int			i;
	
	panelp = &sip->reset_panel[mode];
	panelp->x = P_RESET_L + HIDE_XOFS + ((mode > 0) ? -16: 0);
	panelp->y = P_RESET_U;
	panelp->w = (mode == 0) ? 64: 112;
	panelp->h = 32;
	
	init_waku(&panelp->frames, panelp->x, panelp->y, panelp->w, panelp->h, PRI_RATE - 2, 1);
	
	for (i = 0; i < 2; i++) {
		cpmp = &panelp->m_clmW[i];
		spr_set(cpmp, panelp->x + 4, panelp->y + 4 + 16 * i, -1, 16, F_RESET + mode, FALSE, PRI_RATE - 3);
		chg_uv(cpmp, 0, i * cpmp->h, -1, -1);
	}
}

/*===========================================================
	二つのポリゴンで表事物を横に流す
===========================================================*/
void	slide_str(POL_MEMB *scp, POL_MEMB *dcp, short *cnt, short fs, short direc) {
	POL_MEMB	*cp[2];
	short		i, ctx, sw, dw, stw, dtw;
	
	(*cnt)--;
	sw = fs * *cnt / H_CHG_SYNC;
	dw = fs - sw;
	stw = scp->tp.tw * *cnt / H_CHG_SYNC;
	dtw = dcp->tp.tw * (H_CHG_SYNC - *cnt) / H_CHG_SYNC;
	
	poly_xyset(scp->pp, scp->x, scp->y, sw, scp->h);
	chg_uv(scp, dtw, scp->tp.v, stw, -1);
	poly_xyset(dcp->pp, scp->x + sw, scp->y, dw, scp->h);
	chg_uv(dcp, 0, dcp->tp.v, dtw, -1);
}

/*===========================================================
	ＢＧＭ／ＳＥ名変更ドライバ
===========================================================*/
void	bgm_name_drv(void) {
	PANEL_SOUND	*ssp;			//	サウンド選択用 
	POL_MEMB	*cp;
	short	i, cnum, direc, ch;
	
	ssp = &sip->st_sound;
	for (i = 0; i < 2; i++) {	//	i == 0だとＳＥ	1でＢＧＭ	
#if 1
		ch = 16 * (i + 1);
		if (ssp->disp_n[i] != ssp->snd_n[i]) {
			cp = (i == 0) ? &ssp->se_name[0]: &ssp->bgm_name[0];
			chg_uv(cp, 0, ch * ssp->snd_n[i], 112, ch);
			
			cp = (i == 0) ? &ssp->se_name[1]: &ssp->bgm_name[1];
			chg_uv(cp, 0, ch * ssp->snd_n[i], 112, ch);
			
			ssp->disp_n[i] = ssp->snd_n[i];
		}
#else
		ch = 16 * (i + 1);
		
		if (ssp->disp_n[i] != ssp->snd_n[i]) {
			direc = (ssp->disp_n[i] < ssp->snd_n[i]) ? 1: -1;
			if (ssp->count[i] == 0) {
				ssp->count[i] = H_CHG_SYNC;
				
				cp = (i == 0) ? &ssp->se_name[0]: &ssp->bgm_name[0];
				poly_xyset(cp->pp, cp->x, cp->y, cp->w, ch);
				chg_uv(cp, 0, ch * ssp->disp_n[i], 112, ch);
				cp->tp.tw = 112;
				
				cp = (i == 0) ? &ssp->se_name[1]: &ssp->bgm_name[1];
				poly_xyset(cp->pp, cp->x, cp->y, cp->w, ch);
				chg_uv(cp, 0, ch * (ssp->disp_n[i] + direc), 112, ch);
				cp->tp.tw = 112;
				_SE_CUR1
			}
			if (i == 0)
				slide_str(&ssp->se_name[0], &ssp->se_name[1], &ssp->count[i], 112, direc);
			else
				slide_str(&ssp->bgm_name[0], &ssp->bgm_name[1], &ssp->count[i], 112, direc);
			
			if (ssp->count[i] == 0) ssp->disp_n[i] += direc;
		}
#endif
	}
}

/*===========================================================
	サウンドメニュー配置
		in:		short	xp, yp		位置（オフセット指定後）
===========================================================*/
void	set_soundwin(short xp, short yp) {
	PANEL_SOUND	*ssp;			//	サウンド選択用 
	POL_MEMB	*cpm;
	POLY_FT4	*cp;
	TIM_INF		*ct;
	int			i, j;
	
	ssp = &sip->st_sound;
	set_waku(&ssp->frames, xp, yp, ssp->w, ssp->h);
	
	cpm = &ssp->upstr;
	cpm->x = xp + 4;		cpm->y = yp + 4;
	poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
	
	cpm = &ssp->blank;	//	無地バック	
	cpm->x = xp + 4;		cpm->y = yp + 4 + 16;
	poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
	
	cpm = &ssp->cursor;	//	カーソル	
	cpm->x = xp + 68;
	cpm->y = yp + 29 + 36 * ssp->cur_p;
	poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
	
	for (i = 0; i < 2; i++) {
		//	ＳＥ名称	
		cpm = &ssp->se_name[i];
		cpm->x = xp + 4;	cpm->y = yp + 40;
		poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
		//	ＢＧＭ名称	
		cpm = &ssp->bgm_name[i];
		cpm->x = xp + 4;	cpm->y = yp + 24 + 56;
		poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
		
		//	行タイトル	
		cpm = &ssp->title[i];
		cpm->x = xp + 12;// + ((i == 0) ? 4: 0);
		cpm->y = yp + 24 + i * 36;
		poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
		//	数字	
		for (j = 0; j < 2; j++) {
			cpm = &ssp->string[i][j];
			cpm->x = xp + 76 + j * 8;
			cpm->y = yp + 26 + i * 36;
			poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
		}
	}
}

/*===========================================================
	設定判別でのレートパネル配置
===========================================================*/
void	set_chk_rpanel(PANEL_RATE *panp) {
	POL_MEMB	*cpm;
	int			i;
	short		ctx;
	
	set_waku(&panp->frames, panp->x, panp->y, panp->w, panp->h);
	//	縦ガイド	
	cpm = &panp->vstr;
	cpm->x = panp->x + 4;
	cpm->y = panp->y + 4 + 16;
	poly_xyset((void *)cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
	//	横ガイド	
	ctx = 0;
	cpm = &panp->hstr[0];
	for (i = 0; i < 3; i++, cpm++) {
		cpm->x = panp->x + 4 + ctx;
		poly_xyset((void *)cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
		ctx += cpm->w + (i > 0) * 4;
	}
	//	空白部	
	cpm = &panp->blank;
	cpm->x = panp->x + 4 + 32 + 40 * (sip->scrmode == SEL_MACHINE);
	poly_xyset((void *)cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
}
/*===========================================================
	レートパネル配置
===========================================================*/
void	set_macpanel(PANEL_RATE *panp) {
	POL_MEMB	*cpm;
	int			i;
	short		ctx;
	
	set_waku(&panp->frames, panp->x, panp->y, panp->w, panp->h);
	//	縦ガイド	
	cpm = &panp->vstr;
	cpm->x = panp->x + 4;
	cpm->y = panp->y + 4 + 16;
	poly_xyset((void *)cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
	//	横ガイド	
	ctx = 0;
	cpm = &panp->hstr[0];
	for (i = 0; i < 3; i++, cpm++) {
		cpm->x = panp->x + 4 + ctx;
		poly_xyset((void *)cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
		ctx += cpm->w + (i > 0) * 4;
	}
	//	空白部	
	cpm = &panp->blank;
	cpm->x = panp->x + 4 + 32 + 40 * (sip->scrmode == SEL_MACHINE);
	poly_xyset((void *)cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
}
/*===========================================================
	モードメニュー配置
===========================================================*/
void	set_modewin(void) {
	MODE_PANEL	*mp_p;			//	モード選択パネル 
	POL_MEMB	*cmp;
	int			i;
	
	mp_p = &sip->mode_panel;
	set_waku(&mp_p->frames, mp_p->x, mp_p->y, mp_p->w, mp_p->h);
	cmp = &mp_p->m_clmW[0];
	for (i = 0; i < MODE_MAX; i++, cmp++) {
		cmp->x = mp_p->x + 4;
		poly_xyset(cmp->pp, cmp->x, cmp->y, cmp->w, cmp->h);
	}
}
/*===========================================================
	小役カウンタ状態設定パネル配置
===========================================================*/
void	set_reset_panel(int mode) {
	MODE_PANEL	*mp_p;			//	モード選択パネル 
	POL_MEMB	*cmp;
	int			i;
	
	mp_p = &sip->reset_panel[mode];
	set_waku(&mp_p->frames, mp_p->x, mp_p->y, mp_p->w, mp_p->h);
	cmp = &mp_p->m_clmW[0];
	for (i = 0; i < 2; i++, cmp++) {
		cmp->x = mp_p->x + 4;
		poly_xyset(cmp->pp, cmp->x, cmp->y, cmp->w, cmp->h);
	}
}

/*===========================================================
	モードメニュー退場
===========================================================*/
void	disap_mwin(void) {
	short	offset;
	
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	sip->mode_panel.x = P_MODE_L + offset;
	
	set_modewin();
}
/*===========================================================
	レートメニュー退場
===========================================================*/
void	disap_rwin(void) {
	short	offset;
	
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	sip->panel_rate.x = P_RATE_L + offset;
	set_macpanel(&sip->panel_rate);
}
/*===========================================================
	小役カウンタ状態設定パネル退場
===========================================================*/
void	disap_reset_panel(int mode) {
	MODE_PANEL	*mp_p;			//	モード選択パネル 
	short	offset;
	
	mp_p = &sip->reset_panel[mode];
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	mp_p->x = P_RESET_L + offset - 18 * mode;
	
	set_reset_panel(mode);
}
/*===========================================================
	設定判別レートメニュー退場
===========================================================*/
void	disap_c_rwin(void) {
	short	offset;
	
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	sip->panel_chk_rate.x = P_RATE_L + offset;
	set_macpanel(&sip->panel_chk_rate);
}
/*===========================================================
	サウンドメニュー退場
===========================================================*/
void	disap_swin(void) {
	short	offset;
	
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	sip->st_sound.x = P_SOUND_L + offset;
	
	set_soundwin(sip->st_sound.x, sip->st_sound.y);
}

/*===========================================================
	モードメニュー出現
===========================================================*/
void	app_mwin(void) {
	short		offset;
	
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	sip->mode_panel.x = P_MODE_L + HIDE_XOFS - offset;
	
	set_modewin();
}
/*===========================================================
	小役カウンタ状態設定パネル出現
===========================================================*/
void	app_reset_panel(int mode) {
	MODE_PANEL	*mp_p;			//	モード選択パネル 
	short		offset;
	
	mp_p = &sip->reset_panel[mode];
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	mp_p->x = P_RESET_L + HIDE_XOFS - offset - 18 * mode;
	
	set_reset_panel(mode);
}

/*===========================================================
	レートメニュー出現
===========================================================*/
void	app_rwin(void) {
	short	offset;
	
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	sip->panel_rate.x = P_RATE_L + HIDE_XOFS - offset;
	set_macpanel(&sip->panel_rate);
}
/*===========================================================
	設定判別レートメニュー出現
===========================================================*/
void	app_c_rwin(void) {
	short	offset;
	
	offset = HIDE_XOFS * sip->work[7] / CHG_SYNC;
	sip->panel_chk_rate.x = P_RATE_L + HIDE_XOFS - offset;
	set_macpanel(&sip->panel_chk_rate);
}
/*===========================================================
	サウンドメニュー出現
===========================================================*/
void	app_swin(void) {
	short	offset;
	
	offset = HIDE_XOFS * (CHG_SYNC - sip->work[7]) / CHG_SYNC;
	sip->st_sound.x = P_SOUND_L + offset;
	set_soundwin(sip->st_sound.x, sip->st_sound.y);
}

/*===========================================================
	枠内の擬似スクロール表示
		POL_MEMB	*sp, *dp	元／先ポリ構造体
		short		src, dst	元／先セット番号
		short		bx, by		位置
		short		fs			移転総量
		char		dir			向き（ダミー）
===========================================================*/
void	slide_scr_panel(POL_MEMB *sp, POL_MEMB *dp, short src, short dst, short bx, short by, short fs, char dir) {
	POL_MEMB	*cp[2];
	short		i, cty, offset[2];
	
	offset[1] = fs * sip->work[7] / CHG_SYNC;
	offset[0] = fs - offset[1];
	
	cp[0] = sp;
	cp[1] = dp;
	
	for (i = 0; i < 2; i++) {
		if (i == 0)	cty = 16 * src + offset[1];
		else		cty = 16 * dst;
		
		cp[i]->y = by + 4 + offset[0] * i;
		cp[i]->h = offset[i];
		
		poly_xyset(cp[i]->pp, cp[i]->x, cp[i]->y, cp[i]->w, cp[i]->h);
		chg_uv(cp[i], 0, cty, -1, offset[i]);
	}
}

/*===========================================================
	メッセージパネル文字変更
===========================================================*/
void	chg_mespanel(int src, int dst) {
	POL_MEMB	*cp[2];
	short		j, src_n, dst_n;
	
	for (j = 0; j < 2; j++) {
		if (j > 0 && src < SEL_OK && dst < SEL_OK)	continue;;
		
		if (j == 0) {	// 左パーツ 
			if (src == SEL_SOUNDLOAD) {
				src_n = 6;
			} else {
				src_n = (src <= SEL_OK) ? src: SEL_RATE;
			}
			if (dst == SEL_SOUNDLOAD) {
				dst_n = 6;
			} else {
				dst_n = (dst <= SEL_OK) ? dst: SEL_RATE;
			}
		} else {		// 右パーツ 
			switch (src) {
			case SEL_OK:		src_n = 1;	break;
			case SEL_SOUNDLOAD:	src_n = 2;	break;
			default:			src_n = 0;	break;
			}
			switch (dst) {
			case SEL_OK:		dst_n = 1;	break;
			case SEL_SOUNDLOAD:	dst_n = 2;	break;
			default:			dst_n = 0;	break;
			}
		}
		if (src_n != dst_n)
			slide_scr_panel(&sip->meswin.mes_str[j][0], &sip->meswin.mes_str[j][1], src_n, dst_n, MES_L, MES_U, 16, 0);
	}
	
	src_n = (src == SEL_OK) ? 0: ((src == SEL_SOUND) ? 2: 1);
	dst_n = (dst == SEL_OK) ? 0: ((dst == SEL_SOUND) ? 2: 1);
	if (src_n != dst_n)
		slide_scr_panel(&sip->panel_help.str[0], &sip->panel_help.str[1], src_n, dst_n, sip->panel_help.x, sip->panel_help.y, 16, 0);
	if (dst_n == 2) {
		//	△出す	
		slide_scr_panel(&sip->panel_help.but[2], &sip->panel_help.but[3], 4, 3, sip->panel_help.x + 74, sip->panel_help.y, 16, 0);
		//	×→へ	
		cp[0] = &sip->panel_help.but[1];
		cp[0]->x = sip->panel_help.x + 57 + 23 * sip->work[7] / CHG_SYNC;
		poly_xyset(cp[0]->pp, cp[0]->x, cp[0]->y, cp[0]->w, cp[0]->h);
	} else if (src_n == 2) {
		//	△消す	
		slide_scr_panel(&sip->panel_help.but[2], &sip->panel_help.but[3], 3, 4, sip->panel_help.x + 74, sip->panel_help.y, 16, 0);
		//	×←へ	
		cp[0] = &sip->panel_help.but[1];
		cp[0]->x = sip->panel_help.x + 80 - 23 * sip->work[7] / CHG_SYNC;
		poly_xyset(cp[0]->pp, cp[0]->x, cp[0]->y, cp[0]->w, cp[0]->h);
	}
}

/*===========================================================
	モード名文字列色変更
		in:		short	menu_n	メニュー位置
				short	col_n
===========================================================*/
void	chg_col_mode(char menu_n, char col_n) {
	POL_MEMB	*cpm;
	
	cpm = &sip->mode_panel.m_clmW[menu_n];
	cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + col_n);
}
void	chg_col_reset(char menu_n, char col_n, int mode) {
	MODE_PANEL	*mp_p;			//	モード選択パネル 
	POL_MEMB	*cpmp;
	
	mp_p = &sip->reset_panel[mode];
	cpmp = &mp_p->m_clmW[menu_n];
	cpmp->pp->clut = GetClut(cpmp->tp.cx, cpmp->tp.cy + col_n);
}
/*===========================================================
	サウンド文字列色変更
===========================================================*/
static	void	chg_col_sound(short num, short col_n) {
	POL_MEMB	*cpm;
	short		i;
	
	cpm = &sip->st_sound.title[num];
	cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + col_n);
	for (i = 0; i < 2; i++) {
		cpm = &sip->st_sound.string[num][i];
	}
}

/*===========================================================
	設定文字列色変更
===========================================================*/
static	void	chg_col_rate(short num, short col_n) {
	POL_MEMB	*cpm;
	short		i, j;
	
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 5; j++) {
			cpm = &sip->rate_num_str[sip->mach_n][i][num].pm[j];
			cpm->pp->clut = GetClut(cpm->tp.cx, cpm->tp.cy + col_n);
			if (col_n != C_WHITE) {
				poly_rgbset((void *)cpm->pp, 0x80, 0x80, 0x80);
			} else {
				poly_rgbset((void *)cpm->pp, cpm->r, cpm->g, cpm->b);
			}
		}
	}
}

/*===========================================================
	ツインカーソルのアニメーション
===========================================================*/
void	tcur_drv(void) {
	POL_MEMB	*cmp;
	short	i;
	
	for (i = 0; i < 2; i++) {
		sip->tcur[i].count++;
		if (sip->tcur[i].count >= 6) {
			cmp = &sip->tcur[i].pm;
			sip->tcur[i].anm++;
			sip->tcur[i].count = 0;
			if (sip->tcur[i].anm >= 6) {
				sip->tcur[i].anm = 0;
			}
			chg_uv(cmp, i * 16, 32 * sip->tcur[i].anm, -1, -1);
		}
	}
}

/*===========================================================
	指カーソル移動先設定
		in:	signed char		mode	画面モード
			signed char		pos		画面内のメニュー位置
===========================================================*/
void	set_findst_sel(signed char mode, signed char pos) {
	POL_MEMB	*cp;
	F_CUR		*fp;
	
	fp = &sip->fcur;
	switch (mode) {
	case SEL_MODE:
		fp->dx = P_MACH_L - 12;
		fp->dy = P_MACH_U - 12 + pos * 16;
		break;
	case SEL_RATE:
		fp->dx = P_RATE_L - 12;
		fp->dy = P_RATE_U + 21 + pos * 16;
		if (pos >= 6) fp->dx -= 7;
		if (pos == 7) fp->dy += 8;
		break;
	case SEL_SOUND:
		fp->dx = P_SOUND_L - 14;
		fp->dy = P_SOUND_U + 24 + sip->st_sound.cur_p * 36;
		break;
	case SEL_RATE_CHK:
		fp->dx = P_RATE_L - 12;
		fp->dy = P_RATE_U + 53 + pos * 16;
		if (pos >= 6) fp->dx -= 7;
		break;
	case SEL_RESET:
		fp->dx = P_RESET_L - 14;
		if (sip->gamemode == MODE_CHECK) fp->dx -= 18;
		fp->dy = P_RESET_U + 16 * pos;
		break;
	default:
		fp->dx = P_MACH_L + 200;
		break;
	}
	
	cp = &fp->pm;
	if (fp->dx != cp->x) {
		fp->vx = fp->dx - cp->x;
		if (fp->vx >= CHG_SYNC*3 || fp->vx <= -CHG_SYNC*3)	fp->vx /= CHG_SYNC;
		else if (fp->vx < 0)								fp->vx = -3;
		else												fp->vx =  3;
	}
	if (fp->dy != cp->y) {
		fp->vy = fp->dy - cp->y;
		if (fp->vy >= CHG_SYNC*3 || fp->vy <= -CHG_SYNC*3)	fp->vy /= CHG_SYNC;
		else if (fp->vy < 0)								fp->vy = -3;
		else												fp->vy =  3;
	}
}
/*===========================================================
	機種選択時の動作管理
===========================================================*/
void	job_machine(void) {
	if (sip->chg_scr == FALSE && sip->chg_menu == FALSE) {
		tcur_drv();
		key_machine();
	} else if (sip->chg_menu == TRUE) {
		//	機種変更中
		sip->work[7]++;
		lmp_slide();
		set_nums(SEL_MACHINE);
		switch (sip->work[7]) {
		case 1:
			make_bgm_tim(sip->mach_n);
			poly_doff(sip->tcur[0].pm.pp);
			poly_doff(sip->tcur[1].pm.pp);
			break;
		case CHG_SYNC:
			poly_don(sip->tcur[0].pm.pp);
			poly_don(sip->tcur[1].pm.pp);
			sip->chg_menu = FALSE;
			break;
		}
	} else {	//	モード選択から戻り中
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, sip->gamemode);
		}
		shade_logo(1);
		shade_nums(1);
		chg_mespanel(sip->work[0], sip->scrmode);
		disap_mwin();
		switch (sip->work[7]) {
		case 1:
			sip->panel_mac[sip->mach_n].x -= HIDE_XOFS;
			set_macpanel(&sip->panel_mac[sip->mach_n]);
			set_nums(SEL_MACHINE);
			set_numpri(PRI_MAC - 1);
			break;
		case CHG_SYNC:
			poly_don(sip->tcur[0].pm.pp);
			poly_don(sip->tcur[1].pm.pp);
			sip->chg_scr = FALSE;
			break;
		}
	}
}

/*===========================================================
	モード選択時の動作管理
===========================================================*/
void	job_mode(void) {
	if (sip->chg_scr == FALSE && sip->chg_menu == FALSE) {
		key_mode();
	} else if (sip->chg_menu == TRUE) {
	//	項目変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, sip->gamemode);
		}
		if (sip->work[7] >= MOVE_SYNC) {
			chg_col_mode(sip->gamemode, C_RED);
			sip->chg_menu = FALSE;
		}
	} else {
	//	画面変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, sip->gamemode);
		}
		switch (sip->work[0]) {
		case SEL_MACHINE:	//	機種選択から	
			if (sip->mach_n == KAMI) {	
			//	かみさまには無いモードを避ける処理	
				if (sip->gamemode == MODE_CHECK || sip->gamemode == MODE_CROSS) {
					sip->gamemode = MODE_UNLOCK;
					if (sip->work[7] == 1)	set_findst_sel(sip->scrmode, sip->gamemode);
				}
				chg_col_mode(MODE_CHECK, C_GRAY);
				chg_col_mode(MODE_CROSS, C_GRAY);
			} else {
				chg_col_mode(MODE_CHECK, C_WHITE);
				chg_col_mode(MODE_CROSS, C_WHITE);
			}
			shade_logo(-1);
			shade_nums(-1);
			chg_mespanel(sip->work[0], sip->scrmode);
			app_mwin();
			if (sip->work[7] >= CHG_SYNC) {
				sip->panel_mac[sip->mach_n].x += HIDE_XOFS;
				set_macpanel(&sip->panel_mac[sip->mach_n]);
				set_nums(SEL_MACHINE);
			}
			break;
		case SEL_RATE:		//	レート選択から	
			chg_mespanel(sip->work[0], sip->scrmode);
			shade_modep(1);
			disap_rwin();
			set_nums(SEL_RATE);
			switch (sip->work[7]) {
			case 1:
				sip->mode_panel.x -= HIDE_XOFS;
				set_modewin();
				chg_col_rate(sip->rate_n, 0);
				break;
			case CHG_SYNC:
				break;
			}
			break;
		case SEL_RATE_CHK:		//	設定判別のレート選択から 
			chg_mespanel(sip->work[0], sip->scrmode);
			shade_modep(1);
			disap_c_rwin();
			set_nums(SEL_RATE_CHK);
			switch (sip->work[7]) {
			case 1:
				sip->mode_panel.x -= HIDE_XOFS;
				set_modewin();
				chg_col_rate(sip->rate_n, 0);
				break;
			case CHG_SYNC:
				break;
			}
			break;
		case SEL_SOUNDLOAD:		//	サウンドから	
			chg_mespanel(sip->work[0], sip->scrmode);
			shade_modep(1);
			disap_swin();
			switch (sip->work[7]) {
			case 1:
				break;
			case CHG_SYNC:
				break;
			}
			break;
		case SEL_OK:		//	確認から	
			chg_mespanel(sip->work[0], sip->scrmode);
			break;
		}
		if (sip->work[7] >= CHG_SYNC) {
			chg_col_mode(sip->gamemode, C_RED);
			sip->chg_scr = FALSE;
		}
	}
}
/*===========================================================
	レート選択時の動作管理
===========================================================*/
void	job_rate(void) {
	if (sip->chg_scr == FALSE && sip->chg_menu == FALSE) {	//	通常
		key_rate();
	} else if (sip->chg_menu == TRUE) {
	//	項目変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, sip->rate_n);
		}
		if (sip->work[7] >= MOVE_SYNC) {
			chg_col_rate(sip->rate_n, 1);
			sip->chg_menu = FALSE;
		}
	} else {
	//	画面変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, sip->rate_n);
		}
		switch (sip->work[0]) {
		case SEL_MODE:	//	モード設定から
			chg_mespanel(sip->work[0], sip->scrmode);
			shade_modep(-1);
			app_rwin();
			set_nums(SEL_RATE);
			switch (sip->work[7]) {
			case 1:
				set_numpri(PRI_RATE - 1);
				shade_nums(2);
				break;
			case CHG_SYNC:
				sip->mode_panel.x += HIDE_XOFS;
				set_modewin();
				chg_col_rate(sip->rate_n, 1);
				
				sip->chg_scr = FALSE;
				break;
			}
			break;
		case SEL_NUM:
			switch (sip->work[7]) {
			case 1:
				set_vcur(0);
				sip->chg_scr = FALSE;
				break;
			}
			break;
		case SEL_RESET:	//	小役カウンタ状態設定から戻ってきた
			if (sip->work[7] == 1) {
				set_findst_sel(sip->scrmode, sip->rate_n);
			}
			shade_nums(1);
			if (sip->gamemode == MODE_CHECK) {
				shade_ratep(1, 1);
				disap_reset_panel(1);
			} else {
				shade_ratep(1, 0);
				chg_mespanel(sip->work[0], sip->scrmode);
				disap_reset_panel(0);
			}
			switch (sip->work[7]) {
			case CHG_SYNC:
				sip->chg_scr = FALSE;
				break;
			}
			break;
		}
	}
}

/*===========================================================
	設定判別レート選択でのキー入力処理	
		in:		void
		out:	void
===========================================================*/
void	key_r_check(void) {
	if (sip->chg_scr == TRUE || sip->chg_menu == TRUE) return;
	
	if (pad_beta & PADL_UP) {				//	↑	
		if (key_push(bit2d(PADL_UP))) {
			chg_col_rate(sip->rate_n, 0);
			sip->rate_n--;
			if (sip->rate_n < 0) sip->rate_n = RMODE_MAX - 2;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	//	↓	
		if (key_push(bit2d(PADL_DOWN))) {
			chg_col_rate(sip->rate_n, 0);
			sip->rate_n++;
			if (sip->rate_n > RMODE_MAX - 2) sip->rate_n = 0;
			sip->work[7] = 0;
			sip->chg_menu = TRUE;
			_SE_CUR1
		}
	} else if (pad_cnt & PADR_RIGHT) {	//	○	
		sip->work[0] = SEL_RATE_CHK;
		sip->scrmode = SEL_RESET;
		sip->chg_scr = TRUE;
		sip->work[7] = 0;
		_SE_OK
	} else if (pad_cnt & PADR_DOWN) {	//	×	
		sip->work[0] = sip->scrmode;	//	バックアップ
		sip->scrmode = SEL_MODE;
		chg_col_mode(sip->gamemode, C_WHITE);
		sip->work[7] = 0;			//	カウンタ
		sip->chg_scr = TRUE;
		_SE_CANCEL
	}
}

/*===========================================================
	設定判別モードでの設定選択
===========================================================*/
void	job_rat_chk(void) {
	if (sip->chg_scr == FALSE && sip->chg_menu == FALSE) {	//	通常
		key_r_check();
	} else if (sip->chg_menu == TRUE) {
	//	項目変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(SEL_RATE_CHK, sip->rate_n);
		}
		if (sip->work[7] >= MOVE_SYNC) {
			chg_col_rate(sip->rate_n, 1);
			sip->chg_menu = FALSE;
		}
	} else {
	//	画面変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, sip->rate_n);
		}
		switch (sip->work[0]) {
		case SEL_MODE:	//	モード設定から
			chg_mespanel(sip->work[0], SEL_RATE);
			shade_modep(-1);
			app_c_rwin();
			set_nums(SEL_RATE_CHK);
			switch (sip->work[7]) {
			case 1:
				set_numpri(PRI_RATE - 1);
				shade_nums(2);
				break;
			case CHG_SYNC:
				sip->mode_panel.x += HIDE_XOFS;
				set_modewin();
				chg_col_rate(sip->rate_n, 1);
				
				sip->chg_scr = FALSE;
				break;
			}
			break;
		case SEL_RESET:	// 小役カウンタ状態設定から 
			if (sip->work[7] == 1) {
				set_findst_sel(sip->scrmode, sip->rate_n);
			}
			shade_nums(1);
			if (sip->gamemode == MODE_CHECK) {
				shade_ratep(1, 1);
				disap_reset_panel(1);
			} else {
				shade_ratep(1, 0);
				chg_mespanel(sip->work[0], sip->scrmode);
				disap_reset_panel(0);
			}
			switch (sip->work[7]) {
			case CHG_SYNC:
				sip->chg_scr = FALSE;
				break;
			}
			break;
		}
	}
}

/*===========================================================
	サウンドデータ時の緩衝ステップ
===========================================================*/
void	job_soundload(void) {
	if (sip->chg_scr == FALSE) {	//	通常
		sip->work[7]++;
		if (sip->work[7] > 2) {
			switch (sip->work[0]) {
			case SEL_MODE:	// モード→サウンド 
				sip->work[0] = sip->scrmode;
				sip->scrmode = SEL_SOUND;
				game_vab_set(1);	//	iteya 12/28 音のデータ読む
				break;
			case SEL_SOUND:	// サウンド→モード 
				sip->work[0] = sip->scrmode;
				sip->scrmode = SEL_MODE;
				SEL_SEQ
				break;
			}
			sip->chg_scr = TRUE;
			sip->work[7] = 0;
		}
	} else {	// メッセージ変更中 
		sip->work[7]++;
		chg_mespanel(sip->work[0], sip->scrmode);
		switch (sip->work[7]) {
		case CHG_SYNC:
			sip->chg_scr = FALSE;
			sip->work[7] = 0;
			break;
		}
	}
}
/*===========================================================
	サウンド選択時の動作管理
===========================================================*/
void	job_sound(void) {
	PANEL_SOUND	*ssp;			//	サウンド選択用 
	POL_MEMB	*cpm;
	short		i;
	
	ssp = &sip->st_sound;
	if (sip->chg_scr == FALSE && sip->chg_menu == FALSE) {	//	通常
		bgm_name_drv();
		key_sound();
	} else if (sip->chg_menu == TRUE) {
	//	項目変更時
		sip->work[7]++;
		bgm_name_drv();
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, ssp->cur_p);
		}
		if (sip->work[7] >= MOVE_SYNC) {
			chg_col_sound(ssp->cur_p, C_RED);
			cpm = &ssp->cursor;
			cpm->y = ssp->y + 29 + 36 * ssp->cur_p;
			poly_xyset(cpm->pp, cpm->x, cpm->y, cpm->w, cpm->h);
			sip->chg_menu = FALSE;
		}
	} else {
	//	画面変更時
		sip->work[7]++;
		switch (sip->work[0]) {
		case SEL_SOUNDLOAD:	//	モード設定から
			// ＢＧＭ準備 
			chg_mespanel(sip->work[0], sip->scrmode);
			shade_modep(-1);
			app_swin();
			set_nums(SEL_RATE_CHK);
			switch (sip->work[7]) {
			case 1:	//	値を１（内部的には０）に戻す	
				chg_col_sound(ssp->cur_p, C_WHITE);
				ssp->cur_p = 0;
				set_findst_sel(sip->scrmode, ssp->cur_p);
				for (i = 0; i < 2; i++) {
					ssp->disp_n[i] = ssp->snd_n[i] = 0;
					set_numuv(&ssp->string[i][0], ssp->snd_n[i]+1, 2);
					set_numuv(&ssp->string[i][1], ssp->snd_n[i]+1, 1);
					chg_uv(&ssp->se_name[i], 0, 0, -1, -1);
					chg_uv(&ssp->bgm_name[i], 0, 0, -1, -1);
				}
				break;
			case CHG_SYNC:
				chg_col_sound(ssp->cur_p, C_RED);
				sip->chg_scr = FALSE;
				break;
			}
			break;
		}
	}
}
/*===========================================================
	確認時の動作管理
===========================================================*/
void	job_ok(void) {
	int		tmp;
	
	if (sip->chg_scr == FALSE) {
		key_ok();
	} else {	// 入ってきたとき 
		sip->work[7]++;
		if (sip->work[0] == SEL_RESET) {
			tmp = (sip->gamemode == MODE_CHECK) ? SEL_RATE: sip->work[0];
		} else {
			tmp = sip->work[0];
		}
		chg_mespanel(tmp, sip->scrmode);
		switch (sip->work[7]) {
		case 1:
			break;
		case CHG_SYNC:
			sip->chg_scr = FALSE;
			break;
		}
	}
}

/*===========================================================
	小役カウンタリセット／設定判別タイプ設定
===========================================================*/
void	job_reset(void) {
	int		chktype, tmp;
	
	chktype = (sip->gamemode == MODE_CHECK) ? 1: 0;
	
	if (sip->chg_scr == FALSE && sip->chg_menu == FALSE) {
		key_reset();
	} else if (sip->chg_menu == TRUE) {
	//	項目変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, koyakucnt_reset);
		}
		if (sip->work[7] >= MOVE_SYNC) {
			chg_col_reset(koyakucnt_reset, C_RED,(sip->gamemode == MODE_CHECK) ? 1: 0);
			sip->chg_menu = FALSE;
		}
	} else {
	//	画面変更時
		sip->work[7]++;
		if (sip->work[7] == 1) {
			set_findst_sel(sip->scrmode, koyakucnt_reset);
		}
		switch (sip->work[0]) {
		case SEL_RATE:	// 確率選択から 
		case SEL_NUM:	// 確率カスタムから 
			chg_mespanel(sip->work[0], sip->scrmode);
			shade_ratep(-1, 0);
			app_reset_panel(0);
			shade_nums(-1);
			break;
		case SEL_RATE_CHK:
			shade_ratep(-1, 1);
			app_reset_panel(1);
			shade_nums(-1);
			break;
		case SEL_OK:		//	確認から	
			tmp = (sip->gamemode == MODE_CHECK) ? SEL_RATE: SEL_RESET;
			chg_mespanel(sip->work[0], tmp);
			break;
		}
		if (sip->work[7] >= CHG_SYNC) {
			chg_col_reset(koyakucnt_reset, C_RED, (sip->gamemode == MODE_CHECK) ? 1: 0);
			sip->chg_scr = FALSE;
		}
	}
}
/*===========================================================
	数値設定時の動作管理
===========================================================*/
void	job_setnum(void) {
	if (sip->chg_scr == FALSE && sip->chg_menu == FALSE) {
		key_setnum();
	} else if (sip->chg_scr == TRUE) {	//	画面切替え	
		sip->work[7]++;
		switch (sip->work[0]) {
		case SEL_RATE:
		//	確率設定選択から
			switch (sip->work[7]) {
			case 1:
				sip->panel_rate.bonus_n = 0;
				set_vcur(1);
				sip->panel_rate.bonus_n = 0;
				sip->chg_scr = FALSE;
				break;
			}
			break;
		case SEL_RESET:	//	小役カウンタ状態設定から戻ってきた
			if (sip->work[7] == 1) {
				set_findst_sel(SEL_RATE, sip->rate_n);
			}
			shade_nums(1);
			shade_ratep(1, 0);
			chg_mespanel(sip->work[0], sip->scrmode);
			disap_reset_panel(0);
			switch (sip->work[7]) {
			case CHG_SYNC:
				sip->chg_scr = FALSE;
				break;
			}
			break;
		}
	} else {	//	項目状態変更	
		sip->work[7]++;
		switch (sip->work[7]) {
		case 1:
			set_numb(sip->mach_n, sip->panel_rate.bonus_n, 7, bonus_rate[sip->mach_n][7][sip->panel_rate.bonus_n]);
			set_vcur(1);
			sip->chg_menu = FALSE;
			break;
		}
	}
}

/*===========================================================
	選択の実処理分岐元締	後にぜんぜん元締じゃなくなるのでjob_シリーズに分ける
===========================================================*/
void	select_drv(void) {
	move_cloud();
	
	switch (sip->scrmode) {
	case SEL_MACHINE:	//	機種選択	
		job_machine();	break;
	case SEL_MODE:		//	モード選択	
		job_mode();		break;
	case SEL_RATE:		//	確率設定	
		job_rate();		break;
	case SEL_SOUND:		//	サウンドミュージアム	
		job_sound();	break;
	case SEL_SOUNDLOAD:	// サウンドデータロード中 
		job_soundload();break;
	case SEL_OK:		//	ロード確認	
		job_ok();		break;
	case SEL_NUM:		//	確率手設定
		job_setnum();	break;
	case SEL_RATE_CHK:	// 設定判別モードでの設定選択 
		job_rat_chk();	break;
	case SEL_RESET:		// 小役カウンタ状態選択 
		job_reset();	break;
	}
	finger_drv(&sip->fcur);
}

/*===========================================================
	セレクトメニュー
===========================================================*/
short	selMenu(short *sp) {
	int			i;
	short		retv = 0;
	
	switch (*sp) {
	case 0:
		draw_rq=1;	/* 描画ＯＦＦ */
		SEL_SEQ
		sip = (SELECT_INF *)memalloc(sizeof(SELECT_INF), (void **)&sip);
		if (sip != NULL) {
			init_select();
			fade_set(1, 0);
			fade_drv();
			fade_set(20, 1);
			(*sp)++;
		} else
			retv = -1;
		
		break;
	case 1:
		draw_rq= 0;
		move_cloud();
		if (fade_cur == 0) (*sp)++;
		break;
	case 2:
		select_drv();
		if (sip->exitF != 0) {
			fade_set(20, 0);
			(*sp)++;
		}
		break;
	case 3:
		move_cloud();
		if (fade_cur == 0) {
			(*sp)++;
		}
		break;
	case 4:	// タイトルに戻る 
		mode_game = sip->gamemode;
		machine_no = sip->mach_n;
		if (sip->rate_n < 6) {
			bingo_rate = sip->rate_n + 1;
			rate_rndcst = 0;
			user_rate[0] = user_rate[1] = 0;
		} else {
			if (sip->rate_n == 6) {
				bingo_rate = rnd(6) + 1;
				rate_rndcst = 1;
				user_rate[0] = user_rate[1] = 0;
			} else {
				bingo_rate = 7;
				for (i = 0; i < 2; i++) {
//					user_rate[i] = (bonus_rate[machine_no][8][i] << 12) / 6;
					user_rate[i] = bonus_rate[machine_no][7][i];
				}
				rate_rndcst = 2;
			}
		}
		retv = sip->exitF;
		free_select();
		memfree((void **)&sip);
		fade_set(1, 1);
		SEL_SEQ_END	// ＢＧＭ消す之介 
		break;
	}
	return retv;
}

