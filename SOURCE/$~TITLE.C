/*===================================================
	title.c
	
	ＴＥＮ	パチスロコレクション
	タイトル画面
	
						作ってる人		T. Kawakami
						作り出した日	19th Nov. '98
====================================================*/

#include	"common.h"
#include	"work.h"
#include	"title.h"
#include	"window.h"

#define	MENU_NORMAL		10
#define	MENU_EXIT		MENU_NORMAL 	+10
#define	MENU_LEFT	-128
#define	MENU_TOP	 -96
#define	ITEMN_OPT	4
#define	ITEMN_T_OPT	5
void	option(WINDOW *);

#define	ITEMN_TITLE	3
#define	NOTIMEOUT 0

//#define	WIN_NUM		5
#define	TITLE_SYNC	1800 

void	init_view(void);
void	fade_set(short, char);
void	fade_drv(void);
void	titlepanel(WINDOW *);
void	key_t_option(WINDOW *);
void	t_option(WINDOW *);

char	rankin_no = 10;		// ランキング順位 0~9：順位 それ以上：ランク外 
char	fade_cur = 0, fade_fs;	// フェードのカレントタイマとＦＳ 
char	fade_dir = 1;	// フェードの向き 
char	quitflag = FALSE;

extern	SPRITE_OBJECT *sprobj_top;			/*スプライトグループトップ*/
extern	SPRITE_OBJECT *sprobj_last;			/*スプライトグループラスト*/

short	opt_t_item[5] = {
	STR_OPT_4, STR_OPT_0, STR_OPT_1, STR_OPT_2, STR_OPT_3,
};
char	exitFlag = FALSE;
GsRVIEW2	view;			/* 視点を設定するための構造体 */
//WINDOW		*winp[WINDOW_MAX];
short	bonus_rate[MACHINE_MAX][RMODE_MAX][2] = {
/*	かっぱっぱ	*/
/*	big	 reg	*/
	297, 381,
	282, 356,
	273, 348,
	268, 334,
	256, 321,
	240, 321,
	 -2,  -2,
	200, 300,
/*	かみさま	*/
	348, 655,
	334, 655,
	315, 655,
	297, 630,
	273, 630,
	240, 364,
	 -2,  -2,
	200, 600,
};
TIM_INF	timinf[TIM_F_MAX] = {
	704, 432,  56,  64, 0, 510, 1,/*	かみさまロゴ 	*/
	704, 256,  52, 176, 0, 509, 1,/*	かみさま台 	*/
	576,   0,  56, 200, 0, 511, 1,/*	複合ロゴ 	*/
	640, 432,  56,  64, 0, 508, 1,/*	かっぱロゴ 	*/
	640, 256,  52, 176, 0, 507, 1,/*	かっぱ台 	*/
	768,   0,  30, 32, 0, 506, 1,/*	ローディング 	*/

	548,   0,  22,  56, 0, 485, 0,/*	雲１ 	*/
	512,   0,  36,  98, 0, 485, 0,/*	雲２ 	*/
	512,  98,  16,  64, 0, 485, 0,/*	雲３ 	*/
	530,  98,  16,  64, 0, 485, 0,/*	雲４ 	*/
	546,  98,  16,  64, 0, 485, 0,/*	雲５	*/
	640, 176,  38,  48, 0, 492, 0,/*	メッセージ長い方	*/
	676,  16,  24,  16, 0, 492, 0,/*	数字	*/
	668, 144,   8,  32, 0, 492, 0,/*	サウンド用文字	*/
	640,   0,  28, 128, 0, 492, 0,/*	モードメニュー	*/
	676,  32,  24,  96, 0, 492, 0,/*	メッセージ短い方	*/
	668,   0,   8, 144, 0, 492, 0,/*	レート縦	*/
	676,   0,  28,  16, 0, 492, 0,/*	レート横	*/
	640, 128,  28,  48, 0, 492, 0,/*	ヘルプ	*/
	850, 256,   6,  24, 0, 481, 0,/*	モード枠	*/
	844, 256,   6,  24, 0, 480, 0,/*	メッセージ枠	*/
	844, 280,   2,  32, 0, 482, 0,/*	縦カーソル	*/
	862, 272,   8,   8, 0, 482, 0,/*	横カーソル	*/
	832, 256,   8, 192, 0, 483, 0,/*	Tカーソル	*/
	856, 256,   6,  24, 0, 484, 0,/*	指	*/
	840, 256,   4,  64, 0, 488, 0,/*	ボタン	*/
	796, 256,  28, 144, 0, 492, 0,/*	ＢＧＭ名前	*/
	768, 256,  28, 144, 0, 492, 0,/*	ＳＥ名前	*/
	548,  56,  16,  32, 0, 492, 0,/*	リセット/ランダム */
	576, 200,  28,  32, 0, 492, 0,/*	設定判別タイプ	*/
	
	768, 400, 40,  64, 0, 492, 0,	// タイトルメニュー文字列 
};

/*===========================================================
	指カーソルの位置ドライバ
===========================================================*/
void	finger_drv(F_CUR *cp) {
	if (cp->vx || cp->vy) {
		POL_MEMB	*pmp;
		
		pmp = &cp->pm;
		
		pmp->x += cp->vx;
		if (cp->vx < 0 && pmp->x < cp->dx
		 || cp->vx > 0 && pmp->x > cp->dx)
			pmp->x = cp->dx;
		
		pmp->y += cp->vy;
		if (cp->vy < 0 && pmp->y < cp->dy
		 || cp->vy > 0 && pmp->y > cp->dy)
		 	pmp->y = cp->dy;
		
		poly_xyset(pmp->pp, pmp->x, pmp->y, pmp->w, pmp->h);
	}
}

/*===========================================================
	フェード設定
===========================================================*/
void	fade_set(short time, char sw) {
	SPRITE_OBJECT	*sp;
	POLY_LST		*pp;
	
	// やらないチェック 
	if (fade_dir <= 0 && fade_cur == 0) {		// フェードアウトしきってる
		if (sw == 0) return;
	} else if (fade_dir > 0 && fade_cur == 0) {	// 普通状態 
		if (sw == 1) return;
	}
	
	if (time < 1) time = 1;	// 最低1sync使う 
	
	if (fade_cur == 0) {
	// 通常 
		fade_cur = time;
	} else {
	// 途中割込みの調整 
		if (sw) {	// フェードイン 
			if (fade_dir > 0)	// フェードイン中 
				fade_cur = time * fade_cur / fade_fs;
			else				// フェードアウト中 
				fade_cur = time * (fade_fs - fade_cur) / fade_fs;
		} else {	// フェードアウト 
			if (fade_dir > 0)	// フェードイン中 
				fade_cur = time * (fade_fs - fade_cur) / fade_fs;
			else				// フェードアウト中 
				fade_cur = time * fade_cur / fade_fs;
		}
	}
	fade_fs = time;
	fade_dir = sw;
	
	if (fade_dir <= 0 && fade_cur == fade_fs) {
		sp = sprobj_top;
		while (sp != NULL) {
			sp->work[0] = sp->r;
			sp->work[1] = sp->g;
			sp->work[2] = sp->b;
			
			sp = sp->next;
		}
		
		pp = polylst_top;
		while (pp != NULL) {
			switch (get_polylst((void *)pp->poly)->type) {
			case 0:
				pp->work[0] = ((POLY_F3 *)(pp->poly))->r0;
				pp->work[1] = ((POLY_F3 *)(pp->poly))->g0;
				pp->work[2] = ((POLY_F3 *)(pp->poly))->b0;
				break;
			case 1:
				pp->work[0] = ((POLY_F4 *)(pp->poly))->r0;
				pp->work[1] = ((POLY_F4 *)(pp->poly))->g0;
				pp->work[2] = ((POLY_F4 *)(pp->poly))->b0;
				break;
			case 2:
				{
				POLY_G3 *cp = (POLY_G3 *)pp->poly;
				pp->work[0]  = cp->r0;
				pp->work[0] |= cp->g0<<4;
				pp->work[0] |= cp->b0<<8;
				pp->work[1]  = cp->r1;
				pp->work[1] |= cp->g1<<4;
				pp->work[1] |= cp->b1<<8;
				pp->work[2]  = cp->r2;
				pp->work[2] |= cp->g2<<4;
				pp->work[2] |= cp->b2<<8;
				}
				break;
			case 3:
				{
				POLY_G4 *cp = (POLY_G4 *)pp->poly;
				pp->work[0]  = cp->r0;
				pp->work[0] |= cp->g0<<4;
				pp->work[0] |= cp->b0<<8;
				pp->work[1]  = cp->r1;
				pp->work[1] |= cp->g1<<4;
				pp->work[1] |= cp->b1<<8;
				pp->work[2]  = cp->r2;
				pp->work[2] |= cp->g2<<4;
				pp->work[2] |= cp->b2<<8;
				pp->work[3]  = cp->r3;
				pp->work[3] |= cp->g3<<4;
				pp->work[3] |= cp->b3<<8;
				}
				break;
			case 4:
				pp->work[0] = ((POLY_FT3 *)(pp->poly))->r0;
				pp->work[1] = ((POLY_FT3 *)(pp->poly))->g0;
				pp->work[2] = ((POLY_FT3 *)(pp->poly))->b0;
				break;
			case 5:
				pp->work[0] = ((POLY_FT4 *)(pp->poly))->r0;
				pp->work[1] = ((POLY_FT4 *)(pp->poly))->g0;
				pp->work[2] = ((POLY_FT4 *)(pp->poly))->b0;
				break;
			case 6:
				{
				POLY_GT3 *cp = (POLY_GT3 *)pp->poly;
				pp->work[0]  = cp->r0;
				pp->work[0] |= cp->g0<<4;
				pp->work[0] |= cp->b0<<8;
				pp->work[1]  = cp->r1;
				pp->work[1] |= cp->g1<<4;
				pp->work[1] |= cp->b1<<8;
				pp->work[2]  = cp->r2;
				pp->work[2] |= cp->g2<<4;
				pp->work[2] |= cp->b2<<8;
				}
				break;
			case 7:
				{
				POLY_GT4 *cp = (POLY_GT4 *)pp->poly;
				pp->work[0]  = cp->r0;
				pp->work[0] |= cp->g0<<4;
				pp->work[0] |= cp->b0<<8;
				pp->work[1]  = cp->r1;
				pp->work[1] |= cp->g1<<4;
				pp->work[1] |= cp->b1<<8;
				pp->work[2]  = cp->r2;
				pp->work[2] |= cp->g2<<4;
				pp->work[2] |= cp->b2<<8;
				pp->work[3]  = cp->r3;
				pp->work[3] |= cp->g3<<4;
				pp->work[3] |= cp->b3<<8;
				}
				break;
			case 8:
				pp->work[0] = ((LINE_F2 *)(pp->poly))->r0;
				pp->work[1] = ((LINE_F2 *)(pp->poly))->g0;
				pp->work[2] = ((LINE_F2 *)(pp->poly))->b0;
				break;
			case 9:
				pp->work[0] = ((LINE_F3 *)(pp->poly))->r0;
				pp->work[1] = ((LINE_F3 *)(pp->poly))->g0;
				pp->work[2] = ((LINE_F3 *)(pp->poly))->b0;
				break;
			case 10:
				pp->work[0] = ((LINE_F4 *)(pp->poly))->r0;
				pp->work[1] = ((LINE_F4 *)(pp->poly))->g0;
				pp->work[2] = ((LINE_F4 *)(pp->poly))->b0;
				break;
			case 11:
				{
				LINE_G2 *cp = (LINE_G2 *)pp->poly;
				pp->work[0]  = cp->r0;
				pp->work[0] |= cp->g0<<4;
				pp->work[0] |= cp->b0<<8;
				pp->work[1]  = cp->r1;
				pp->work[1] |= cp->g1<<4;
				pp->work[1] |= cp->b1<<8;
				}
				break;
			case 12:
				{
				LINE_G3 *cp = (LINE_G3 *)pp->poly;
				pp->work[0]  = cp->r0;
				pp->work[0] |= cp->g0<<4;
				pp->work[0] |= cp->b0<<8;
				pp->work[1]  = cp->r1;
				pp->work[1] |= cp->g1<<4;
				pp->work[1] |= cp->b1<<8;
				pp->work[2]  = cp->r2;
				pp->work[2] |= cp->g2<<4;
				pp->work[2] |= cp->b2<<8;
				}
				break;
			case 13:
				{
				LINE_G4 *cp = (LINE_G4 *)pp->poly;
				pp->work[0]  = cp->r0;
				pp->work[0] |= cp->g0<<4;
				pp->work[0] |= cp->b0<<8;
				pp->work[1]  = cp->r1;
				pp->work[1] |= cp->g1<<4;
				pp->work[1] |= cp->b1<<8;
				pp->work[2]  = cp->r2;
				pp->work[2] |= cp->g2<<4;
				pp->work[2] |= cp->b2<<8;
				pp->work[3]  = cp->r3;
				pp->work[3] |= cp->g3<<4;
				pp->work[3] |= cp->b3<<8;
				}
				break;
			case 14:
				pp->work[0] = ((GsBOXF *)(pp->poly))->r;
				pp->work[1] = ((GsBOXF *)(pp->poly))->g;
				pp->work[2] = ((GsBOXF *)(pp->poly))->b;
			}
			
			pp = pp->next;
		}
	}
}

char	fade_culc(int org, int cur, int fs, int sw) {
	return (sw) ? org * (fs - cur) / fs: org * cur / fs;
}
/*===========================================================
	フェード制御
===========================================================*/
void	fade_drv(void) {
	if (fade_cur > 0) {
		SPRITE_OBJECT	*sp;
		POLY_LST		*pp;
		int				cr, cg, cb, c_v;
		
		fade_cur--;
		
		sp = sprobj_top;
		while (sp != NULL) {
			if (fade_dir > 0) {
				c_v = fade_fs - fade_cur;
				sp->r = sp->work[0] * c_v / fade_fs;
				sp->g = sp->work[1] * c_v / fade_fs;
				sp->b = sp->work[2] * c_v / fade_fs;
			} else {
				sp->r = sp->work[0] * fade_cur / fade_fs;
				sp->g = sp->work[1] * fade_cur / fade_fs;
				sp->b = sp->work[2] * fade_cur / fade_fs;
			}
			sp = sp->next;
		}
		pp = polylst_top;
		while (pp != NULL) {
			switch (get_polylst((void *)pp->poly)->type) {
			case 2:
				{
				POLY_G3 *cp = (POLY_G3 *)pp->poly;
				cp->r0 = fade_culc(pp->work[0]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g0 = fade_culc(pp->work[0] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b0 = fade_culc(pp->work[0] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r1 = fade_culc(pp->work[1]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g1 = fade_culc(pp->work[1] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b1 = fade_culc(pp->work[1] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r2 = fade_culc(pp->work[2]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g2 = fade_culc(pp->work[2] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b2 = fade_culc(pp->work[2] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				}
				break;
			case 3:
				{
				POLY_G4 *cp = (POLY_G4 *)pp->poly;
				cp->r0 = fade_culc(pp->work[0]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g0 = fade_culc(pp->work[0] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b0 = fade_culc(pp->work[0] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r1 = fade_culc(pp->work[1]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g1 = fade_culc(pp->work[1] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b1 = fade_culc(pp->work[1] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r2 = fade_culc(pp->work[2]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g2 = fade_culc(pp->work[2] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b2 = fade_culc(pp->work[2] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r3 = fade_culc(pp->work[3]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g3 = fade_culc(pp->work[3] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b3 = fade_culc(pp->work[3] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				}
				break;
			case 6:
				{
				POLY_GT3 *cp = (POLY_GT3 *)pp->poly;
				cp->r0 = fade_culc(pp->work[0]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g0 = fade_culc(pp->work[0] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b0 = fade_culc(pp->work[0] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r1 = fade_culc(pp->work[1]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g1 = fade_culc(pp->work[1] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b1 = fade_culc(pp->work[1] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r2 = fade_culc(pp->work[2]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g2 = fade_culc(pp->work[2] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b2 = fade_culc(pp->work[2] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				}
				break;
			case 7:
				{
				POLY_GT4 *cp = (POLY_GT4 *)pp->poly;
				cp->r0 = fade_culc(pp->work[0]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g0 = fade_culc(pp->work[0] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b0 = fade_culc(pp->work[0] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r1 = fade_culc(pp->work[1]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g1 = fade_culc(pp->work[1] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b1 = fade_culc(pp->work[1] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r2 = fade_culc(pp->work[2]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g2 = fade_culc(pp->work[2] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b2 = fade_culc(pp->work[2] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r3 = fade_culc(pp->work[3]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g3 = fade_culc(pp->work[3] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b3 = fade_culc(pp->work[3] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				}
				break;
			case 11:
				{
				LINE_G2 *cp = (LINE_G2 *)pp->poly;
				cp->r0 = fade_culc(pp->work[0]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g0 = fade_culc(pp->work[0] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b0 = fade_culc(pp->work[0] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r1 = fade_culc(pp->work[1]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g1 = fade_culc(pp->work[1] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b1 = fade_culc(pp->work[1] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				}
				break;
			case 12:
				{
				LINE_G3 *cp = (LINE_G3 *)pp->poly;
				cp->r0 = fade_culc(pp->work[0]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g0 = fade_culc(pp->work[0] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b0 = fade_culc(pp->work[0] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r1 = fade_culc(pp->work[1]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g1 = fade_culc(pp->work[1] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b1 = fade_culc(pp->work[1] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r2 = fade_culc(pp->work[2]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g2 = fade_culc(pp->work[2] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b2 = fade_culc(pp->work[2] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				}
				break;
			case 13:
				{
				LINE_G4 *cp = (LINE_G4 *)pp->poly;
				cp->r0 = fade_culc(pp->work[0]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g0 = fade_culc(pp->work[0] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b0 = fade_culc(pp->work[0] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r1 = fade_culc(pp->work[1]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g1 = fade_culc(pp->work[1] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b1 = fade_culc(pp->work[1] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r2 = fade_culc(pp->work[2]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g2 = fade_culc(pp->work[2] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b2 = fade_culc(pp->work[2] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->r3 = fade_culc(pp->work[3]      & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->g3 = fade_culc(pp->work[3] >> 4 & 0xFF, fade_cur, fade_fs, fade_dir);
				cp->b3 = fade_culc(pp->work[3] >> 8 & 0xFF, fade_cur, fade_fs, fade_dir);
				}
				break;
			default:
				cr = fade_culc(pp->work[0], fade_cur, fade_fs, fade_dir);
				cg = fade_culc(pp->work[1], fade_cur, fade_fs, fade_dir);
				cb = fade_culc(pp->work[2], fade_cur, fade_fs, fade_dir);
				poly_rgbset(pp->poly, cr, cg, cb);
				break;
			}
			pp = pp->next;
		}
	}
}
/*===========================================================
	ビットを使ったフラグを整数に戻す
		例：0x40	→	7
			0x8		→	4
			一番下位の桁しか検出しない
			３２ビットしか見ない
		in:		u_int	num		元のパターン
		out:	char			値
===========================================================*/
char	bit2d(u_int num) {
	char	i;
	
	for (i = 0; i < 31; i++) {
		if (num & (1 << i)) return i + 1;
	}
	return 0;
}
/*===========================================================
	キー押しっぱなし時間に比例した変化量を返す関数
		in:		short	but_n	ボタン番号
		out:	short			変化量
===========================================================*/
short	keyin_slide(short but_n) {
	short	retv, bn;
	
	bn = but_n - 1;
	if 		(Padbuf[bn] > 210)	retv =  8;
	else if (Padbuf[bn] > 150)	retv =  4;
	else if (Padbuf[bn] >  90)	retv =  2;
	else if (Padbuf[bn] >  30)	retv =  1;
	else if (Padbuf[bn] ==  1)	retv = -1;
	else						retv =  0;
	
	return retv;
}
/*===========================================================
	キー押しっぱなしで一定タイミング毎に１を返す
		in:		short	but_n	ボタン番号
		out:	short			当たりタイミング	１
								それ以外			０
===========================================================*/
short	key_push(short bnum) {
static	u_long	push_c;	//	キー押しっぱなし用カウンタ	
	short	val;
	
	val = keyin_slide(bnum);
	
	if (val != 0) {	//	押されてる	
		if (val == -1) {	//	トリガ	
			push_c = 0;
			val = -1;
		} else {			//	押しっ放し	
			push_c++;
			if (push_c % 6 == 0) {	//	当たりタイミング	
				val = 1;
			} else {
				val = 0;
			}
		}
	}
	return val;
}


/*===========================================================
	まとまったTIMファイル読込み
		in:		void
		out:	void
===========================================================*/
void	load_tims(void){
	void	*lda;
	short	i;
	
	lda = datafile_read(F_SELECT, NULL);
	tim_load((void *)lda, 0);
	DrawSync(0);
	memfree((void **)&lda);
}
/*===========================================================
	TIMデータをTEX_INFスタイルに変換する
		in:		TIM_INF	*timp	ソース
				TEX_INF	*texp	ディスティネーション
===========================================================*/
void	timi2texi(TIM_INF *timp, TEX_INF *texp) {
	texp->mode = timp->mode;
	texp->page = GetTPage(timp->mode, 0, timp->x, timp->y);
	texp->rate = (texp->mode < 2) ? (texp->mode - 2) * -2: 1;
	texp->cx = timp->cx;
	texp->cy = timp->cy;
	texp->u = texp->u0 = (timp->x & 0x3F) * texp->rate;
	texp->v = texp->v0 = (timp->y & 0xFF);
	texp->tw = timp->w;
	texp->th = timp->h;
}

/*===========================================================
	基本的なスプライトセット	ＴＩＭフルサイズのものを作成する
		in:		POL_MEMB	*pm			主な情報構造体
				short		x, y		位置
				short		w, h		縦横幅	-指定の時はＴＩＭの幅となる
				short		timfnum		TIMファイル番号
				short		half		半透明フラグ
				short		pri			プライオリティ
		out:	void
===========================================================*/
void	spr_set(POL_MEMB *pm, short x, short y, short w, short h, short timfnum, short half, short pri) {
	TIM_INF	*timdp;
	short	u, v;
	
	pm->pp = poly_ft4_make();
	timdp = &timinf[timfnum];
	timi2texi(timdp, &pm->tp);
	
	pm->x = x;
	pm->y = y;
	pm->w = pm->tp.tw = (w < 0) ? timdp->w * pm->tp.rate: w;
	pm->h = pm->tp.th = (h < 0) ? timdp->h: h;
	pm->r = pm->g = pm->b = 0x80;
	
	poly_xyset((void *)pm->pp, pm->x, pm->y, pm->w, pm->h);
	poly_ft4_fset(pm->pp, timdp->cx, timdp->cy, timdp->x, timdp->y, half, 0, pm->tp.mode);
	poly_uvset(pm->pp, pm->tp.u, pm->tp.v, pm->tp.tw, pm->tp.th - 1);
	poly_rgbset((void *)pm->pp, pm->r, pm->g, pm->b);
	poly_priset(pm->pp, pri);
}

/*===========================================================
	パネル枠初期化
===========================================================*/
void	init_waku(FRAMES *ccp, short xp, short yp, short wid, short hei, short pri, short type) {
	POL_MEMB	*cpm;
	TIM_INF		*cti;
	short		i, ctx, cty, tx, ty, fnum;
	
	if (type == 0)
		fnum = F_BRD_MOD_H;
	else
		fnum = F_BRD_MOD_L;
	
	for (i = 0; i < 8; i++) {
		cpm = &ccp->frame[i];
		
		cpm->pp = poly_ft4_make();
		cti = &timinf[fnum];
		timi2texi(cti, &cpm->tp);
		
		if (i < 4) {
			cpm->w = cpm->h = 8;
			tx = (i % 2) ? 16: 0;
			ty = (i < 2) ? 0: 16;
		} else if (i < 6) {
			cpm->w = wid;
			cpm->h = 8;
			tx = 8;
			ty = (i == 4) ? 0: 16;
		} else {
			cpm->w = 8;
			cpm->h = hei;
			tx = (i == 6) ? 0: 16;
			ty = 8;
		}
		cpm->tp.tw = cpm->tp.th = 7;
		poly_ft4_fset(cpm->pp, cti->cx, cti->cy, cti->x, cti->y, 0,0,cti->mode);
		poly_uvset(cpm->pp, cpm->tp.u + tx, cpm->tp.v + ty, cpm->tp.tw, cpm->tp.th);
		poly_rgbset((void *)cpm->pp, 0x80, 0x80, 0x80);
		poly_priset(cpm->pp, pri);
	}
	set_waku(ccp, xp, yp, wid, hei);
}

/*===========================================================
	枠のポリ達の解放
===========================================================*/
void	free_waku(FRAMES *fp) {
	short	i;
	
	for (i = 0; i < 8; i++) {
		poly_kill(fp->frame[i].pp);
	}
}

/*===========================================================
	視点／注視点初期化
===========================================================*/
void init_view(void)
{
	/* 視点から投影面の距離を設定 */
	GsSetProjection(1000);
	
	/*	視点設定	*/
	view.vpx = 0;
	view.vpy = 0;
	view.vpz = 0;
	/* 注視点パラメータ設定 */
	view.vrx = 0; view.vry = 0; view.vrz = 0;
	view.rz= 0x0;		/*	視点の捻り	*/
	view.super = WORLD;	/*	親座標系	*/
/*	view.super = &dcoord;  /* ローカル座標に視点を設定する */
  
	/* 視点パラメータを群から視点を設定して ワールドスクリーンマトリックスを計算する */
	GsSetRefView2(&view);
}

//	ロゴ表示そのいち 
short	logo1_disp(short *sp) {
	short	retv = TRUE;
	return retv;
}

//	ロゴ表示そのに 
short	logo2_disp(short *sp) {
	short	retv = TRUE;
	return retv;
}

//	ＯＰムービー 
short	opMovie(short *sp) {
	short	retv = TRUE;
	return retv;
}

/***************************************************************
//		キーコンフィグ関連
***************************************************************/
short	keyconfig_str[4] = {
	STR_PATTERN_0,	STR_PATTERN_1,	STR_PATTERN_2,	STR_PATTERN_3,
};
short	botan_tim_data[16][4] = {
	832,	224,	864,	249,	// ↑ 
	836,	224,	864,	249,	// → 
	840,	224,	864,	249,	// ↓ 
	844,	224,	864,	249,	// ← 
	848,	224,	864,	249,	// ↑↓ 
	852,	224,	864,	249,	// ←→ 
	856,	224,	864,	250,	// △ 
	860,	224,	864,	251,	// ○ 
	864,	224,	864,	252,	// × 
	868,	224,	864,	253,	// □ 
	872,	224,	864,	254,	// Ｌ２ 
	876,	224,	864,	254,	// Ｌ１ 
	880,	224,	864,	254,	// Ｒ２ 
	884,	224,	864,	254,	// Ｒ１ 
	888,	224,	864,	255,	// ｏｒ 
	892,	224,	864,	255,	// ＋ 
};
char	keyconfig_num_set[4][13] = {
	6, 9, 8, 7, 2, 10, 13, 13, 12, 14, 0, 15, 12,
	6, 9, 8, 7, 2, 10, 12, 13, 13, 14, 0, 15, 12,
	0, 9, 6, 7, 2, 10, 13, 13, 12, 14, 8, 15, 12,
	6, 9, 8, 7, 0, 10, 2, 13, 12, 14, 13, 15, 12,
};

/*===========================================================
	キーコンフィグボタンuv設定
		in:	mode	セット番号
===========================================================*/
void	set_bottan_uv(char mode, SPRITE_OBJECT **spp) {
	char	*k_n_sp;
	short	*b_t_dp;
	int		i;
	
	k_n_sp = keyconfig_num_set[mode];
	for (i = 0; i < 13; i++, k_n_sp++, spp++) {
		b_t_dp = botan_tim_data[*k_n_sp];
		spr_uvset(*spp, 0, *b_t_dp, *(b_t_dp + 1));
		(*spp)->cx = *(b_t_dp + 2);
		(*spp)->cy = *(b_t_dp + 3);
	}
}

/*===========================================================
	キーコンフィグパネルのキー処理
===========================================================*/
char	key_keyconfig(WINDOW *wp) {
	if (pad_cnt & PADR_DOWN) {
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);	// 退避セット 
		
		// オプションメニュー復活 
//		if (swp->titleF)
		if (wp->work[7])
			rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_T_OPT + 1) + 8, 15, t_option);
		else
			rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_OPT + 1) + 8, 15, option);
		
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_beta & PADL_LEFT) {
		if (key_push(bit2d(PADL_LEFT))) {
			if (pad_mode > 0)	pad_mode--;
			else				pad_mode = 3;
			set_bottan_uv(pad_mode, (SPRITE_OBJECT **)wp->work[1]);
			ffnt_redraw(wp->moji_id[1], (u_short *)fnt_data + keyconfig_str[pad_mode]);
			_SE_SUR2
		}
	} else if (pad_beta & PADL_RIGHT) {
		if (key_push(bit2d(PADL_RIGHT))) {
			if (pad_mode < 4 - 1)	pad_mode++;
			else					pad_mode = 0;
			set_bottan_uv(pad_mode, (SPRITE_OBJECT **)wp->work[1]);
			ffnt_redraw(wp->moji_id[1], (u_short *)fnt_data + keyconfig_str[pad_mode]);
			_SE_SUR2
		}
	}
}

/*===========================================================
	キーコンフィグボタン配置
===========================================================*/
void	set_botan_xy(SPRITE_OBJECT **spp, short x0, short y0) {
	int		i;
	short	xc, yc;
	
	xc = x0 + 160;
	yc = y0;
	for (i = 0; i < 8; i++, spp++, yc += 16) {
		spr_xyset(*spp, xc, yc);
	}
	yc += 8;
	spr_xyset(*spp++, xc, yc);
	xc += 16;	yc = y0 + 64;
	spr_xyset(*spp++, xc, yc);
	xc += 16;
	spr_xyset(*spp++, xc, yc);
	xc -= 16;	yc += 48;
	spr_xyset(*spp++, xc, yc);
	xc += 16;
	spr_xyset(*spp++, xc, yc);
}
/*===========================================================
	キーコンフィグパネル配置
===========================================================*/
void	set_keyconfig(WINDOW *wp) {
	ffnt_xy(wp->moji_id[0], wp->x + 8, wp->y + 4);
	poly_xyset((void *)wp->work[0], wp->x + 4, wp->y + 22, wp->w - 8, 2);
	
	ffnt_xy(wp->moji_id[1], wp->x + 96, wp->y + 4);
	ffnt_xy(wp->moji_id[2], wp->x + 4, wp->y + 24);
	set_botan_xy((SPRITE_OBJECT **)wp->work[1], wp->x + 4, wp->y + 24);
}
/*===========================================================
	キーコンフィグ
		moji_id	[0]		パネルタイトル
				[1]		パターン表示
				[2]		ボタン機能群
		work	[0]		白線用
				[1]		ボタンスプライト用	１３コ
				[7]		復帰先	0:ただオプション 1:タイトル型オプション
===========================================================*/
void	keyconfig(WINDOW *wp) {
	POLY_F4			*lp;
	SPRITE_OBJECT	**spp;
	int				i;
	
	switch (wp->f_step) {
	case 0:	// 初期設定 
		// タイトル白線 
		lp = (POLY_F4 *)wp->work[0] = poly_f4_make();
		lp->r0 = lp->g0 = lp->b0 = 0xF0;
		
		// ボタンアイコンズ 
		spp = (SPRITE_OBJECT **)wp->work[1] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 13, (void **)&wp->work[1]);
		for (i = 0; i < 13; i++, spp++) {
			*spp = sprobj_make();
			spr_texset(*spp, 0,0, 832, 224, 864, 249);
			(*spp)->r = (*spp)->g = (*spp)->b = 0x80;
			(*spp)->pri = wp->pri - 1;
			spr_whset(*spp, 16, 16);
		}
		spp -= 13;	// return to top 
		set_bottan_uv(pad_mode, spp);
		
		// 文字 
		// パネルタイトル 
		wp->moji_id[0] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + STR_OPT_3);
		wp->moji_max++;
		ffnt_color(wp->moji_id[0], 0x80, 0x80, 0x20);
		// セット番号表示 
		wp->moji_id[1] = ffnt_open(wp->x, wp->y, 81, 16, (u_short *)fnt_data + keyconfig_str[pad_mode]);
		wp->moji_max++;
		ffnt_color(wp->moji_id[1], 0x20, 0x80, 0x20);
		// 機能 
		wp->moji_id[2] = ffnt_open(wp->x, wp->y, 160, 160, (u_short *)fnt_data + STR_KEYCONFIG);
		wp->moji_max++;
		ffnt_color(wp->moji_id[2], 0x80, 0x80, 0x80);
		
		if (!swp->titleF)
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP - HIDE_YOFS);
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		set_keyconfig(wp);
		swp->cur_win = (swp->titleF) ? TP_K_CONF: SM_K_CONF;
//		swp->cur_win = SM_OPTION;
		wp->f_step++;
		break;
	case 1:	// 切り替え中 
		if (!swp->titleF)
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP - HIDE_YOFS);
		set_keyconfig(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		key_keyconfig(wp);
//		set_keyconfig(wp);
		break;
	case MENU_EXIT:
		set_keyconfig(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			poly_kill((void *)wp->work[0]);
			spp = (SPRITE_OBJECT **)wp->work[1];
			for (i = 0; i < 13; i++, spp++) {
				sprobj_kill(*spp);
			}
			memfree((void **)&wp->work[1]);
			wp->f_step++;
		}
		
		break;
	case MENU_EXIT + 1:
		dispose_window(wp);
		rackwin[3] = NULL;
		break;
	}
}

/*===========================================================
	ランキングパネルのキー処理
===========================================================*/
void	key_ranking(WINDOW *wp) {
	if (pad_cnt & (PADR_RIGHT|PADR_DOWN)) {
		// 退避セット 
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		
		// タイトルメニュー復活 
		if (wp->work[7]) {
			rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_T_OPT + 1) + 8, 15, t_option);
		}
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	}
}

/*===========================================================
	ランキングパネル配置
===========================================================*/
void	set_ranking(WINDOW *wp) {
	SPRITE_OBJECT	**rankpp, **numpp;
	int				i, j, k;
	
	ffnt_xy(wp->moji_id[0], wp->x + 8, wp->y + 4);
	poly_xyset((void *)wp->work[0], wp->x + 4, wp->y + 22, wp->w - 8, 2);
	
	ffnt_xy(wp->moji_id[1], wp->x + 4, wp->y + 23);
	ffnt_xy(wp->moji_id[2], wp->x + 4 + FNT_W * 7, wp->y + 23);
	ffnt_xy(wp->moji_id[3], wp->x + 4 + FNT_W * 12, wp->y + 23);
	
	// 順位 
	rankpp = (SPRITE_OBJECT **)wp->work[1];
	for (i = 0; i < 9; i++, rankpp++) {
		spr_xyset(*rankpp, wp->x + 4 + 128, wp->y + 38 + i * FNT_H);
	}
	spr_xyset(*rankpp++, wp->x + 4 + 120, wp->y + 38 + 144);
	spr_xyset(*rankpp, wp->x + 4 + 128, wp->y + 38 + 144);
	
	// 値 
	numpp = (SPRITE_OBJECT **)wp->work[2];
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 10; j++) {
			set_8wval(numpp, wp->x + 200 - 160 * i, wp->y + 38 + FNT_H * j, 3);
			if (i == machine_no && j == rankin_no) {
				for (k = 0; k < 3; k++, numpp++) {
					(*numpp)->r = (*numpp)->g = (*numpp)->b = wp->work[3];
				}
				numpp -= 3;
			}
			numpp += 3;
		}
	}
}
/*===========================================================
	ランキングパネル数値作成
===========================================================*/
void	make_ranking_nums(WINDOW *wp) {
	SPRITE_OBJECT	**spp;
	int				i, j;
	
	spp = (SPRITE_OBJECT **)wp->work[2];
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 10; j++) {
			set_8wvals(spp, bb_best[i][j], 3, 0);
			spp += 3;
		}
	}
}
/*===========================================================
	BIG獲得ランキング
		moji_id	[0]		パネルタイトル
				[1]		ＢＩＮ貧神さま
				[2]		ＲＡＮＫ
				[3]		かっぱっぱ
		work	[0]		白線
				[1]		数字スプライト×11
				[2]		数字スプライト×３０
				[3]		点滅シェード値
				[4]		点滅向き
				[5]		点滅カウンタ
				[7]		バトン先	0:なし 1:パネル
===========================================================*/
void	p_ranking(WINDOW *wp) {
	POLY_F4		*f4p;
	SPRITE_OBJECT	**spp;
	int			i, j;
	
	switch (wp->f_step) {
	case 0:
		// 白線 
		f4p = (POLY_F4 *)wp->work[0] = poly_f4_make();
		f4p->r0 = f4p->g0 = f4p->b0 = 0xF0;
		
		// 順位数値 
		spp = (SPRITE_OBJECT **)wp->work[1] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 11, (void **)&wp->work[1]);
		for (i = 0; i < 11; i++, spp++) {
			*spp = sprobj_make();
			spr_texset(*spp, 0,0, 928, 76, 944, 250);
			(*spp)->r = 0x40;
			(*spp)->g = (*spp)->b = 0x80;
			(*spp)->pri = wp->pri - 1;
			spr_xyset(*spp, wp->w, wp->y);
			spr_whset(*spp, 8, 16);
			
			if (i == 10)
				spr_uvset(*spp, 0, 928, 76);
			else if (i == 9)
				spr_uvset(*spp, 0, 930, 76);
			else
				spr_uvset(*spp, 0, 930 + 2 * i, 76);
		}
		
		// 記録数値 
		spp = (SPRITE_OBJECT **)wp->work[2] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * 60, (void **)&wp->work[2]);
		for (i = 0; i < 60; i++, spp++) {
			*spp = sprobj_make();
			spr_texset(*spp, 0,0, 928, 76, 944, 250);
			(*spp)->r = (*spp)->g = (*spp)->b = 0x80;
			(*spp)->pri = wp->pri - 1;
			spr_xyset(*spp, wp->w, wp->y);
			spr_whset(*spp, 8, 16);
		}
		make_ranking_nums(wp);
		
		// パネルタイトル 
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + STR_OPT_5);
		ffnt_color(wp->moji_id[wp->moji_max], 0x80, 0x80, 0x20);
		wp->moji_max++;
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 128, FNT_H, (u_short *)fnt_data + STR_KAMI);
		ffnt_color(wp->moji_id[wp->moji_max], 0x40, 0x80, 0x80);
		wp->moji_max++;
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 128, FNT_H, (u_short *)fnt_data + STR_RANK);
		ffnt_color(wp->moji_id[wp->moji_max], 0x40, 0x80, 0x80);
		wp->moji_max++;
		wp->moji_id[wp->moji_max] = ffnt_open(wp->x, wp->y, 128, FNT_H, (u_short *)fnt_data + STR_KAPP);
		ffnt_color(wp->moji_id[wp->moji_max], 0x40, 0x80, 0x80);
		wp->moji_max++;
		
		wp->work[3] = 0x80;
		wp->work[4] = 1;
		
		if (!swp->titleF)
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP - HIDE_YOFS);
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		set_ranking(wp);
		swp->cur_win = TP_RANKING;
		wp->f_step++;
		break;
	case 1:	// 切り替え中 
		wp->work[3] += wp->work[4] * 8;
		if (wp->work[3] >= 0xF8)		wp->work[4] = -1;
		else if (wp->work[3] <= 0x20)	wp->work[4] = 1;
		if (!swp->titleF)
			set_findst2(&swp->fcur, MENU_LEFT - 20, MENU_TOP - HIDE_YOFS);
		set_ranking(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		wp->work[3] += wp->work[4] * 8;
		if (wp->work[3] >= 0xF8)		wp->work[4] = -1;
		else if (wp->work[3] <= 0x20)	wp->work[4] = 1;
		key_ranking(wp);
		set_ranking(wp);
		break;
	case MENU_EXIT:
		wp->work[3] += wp->work[4] * 8;
		if (wp->work[3] >= 0xF8)		wp->work[4] = -1;
		else if (wp->work[3] <= 0x20)	wp->work[4] = 1;
		set_ranking(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			poly_kill((void *)wp->work[0]);
			spp = (SPRITE_OBJECT **)wp->work[1];
			for (i = 0; i < 11; i++, spp++) {
				sprobj_kill(*spp);
			}
			memfree((void **)&wp->work[1]);
			spp = (SPRITE_OBJECT **)wp->work[2];
			for (i = 0; i < 60; i++, spp++) {
				sprobj_kill(*spp);
			}
			memfree((void **)&wp->work[2]);
			
			wp->f_step++;
		}
		
		break;
	case MENU_EXIT + 1:
//		bb_shot_coin = bb_toushi_coin = 0;	01/24 kawakami 
		dispose_window(wp);
		rackwin[3] = NULL;
		break;
	}
}

/*===========================================================
	タイトル型オプション中のキー処理
===========================================================*/
void	key_t_option(WINDOW *wp) {
	if (pad_cnt & PADR_DOWN) {			// × 
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
		
		// サブメニューさん復活セット 
		if (swp->titleF) {	// タイトル時 
			rackwin[0] = make_window(-84 - 4, 32 - 4 + HIDE_YOFS, 160 + 8, 16 * ITEMN_TITLE + 8, 11, titlepanel);
		} else {
			revive_submenu();
		}
		wp->f_step = MENU_EXIT;
		_SE_CANCEL
	} else if (pad_cnt & PADR_RIGHT) {	// ○ 
		if (swp->cp_opt == 1) {
			pad_shibirenai();
			vib_flag ^= 1;
			if (vib_flag > 0) {
				pad_shibireru();
				wp->work[4] = 10;
			}
			spr_uvset((SPRITE_OBJECT *)wp->work[0], 0, 952, vib_flag ? 0: 16);
			_SE_SUR2
		} else if (swp->cp_opt == 4) {
			hide_app_win(wp, WIN_CHG_SYNC, 4, 0);	// 退避セット 
			rackwin[3] = make_window(-132, -100 + HIDE_YOFS, FNT_W * 14 + 8, FNT_H * 10 + 28, 15, keyconfig);
			rackwin[3]->work[7] = 1;
			wp->f_step = MENU_EXIT;
			_SE_SUR2
		} else if (swp->cp_opt == 0) {
			hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
			rankin_no = 10;
			rackwin[3] = make_window(-148, -100 + HIDE_YOFS, FNT_W * 18 + 8, FNT_H * 11 + 28, 15, p_ranking);
			rackwin[3]->work[7] = 1;
			wp->f_step = MENU_EXIT;
			_SE_SUR2
		}
	} else if (pad_beta & PADL_UP) {	// ↑ 
		if (key_push(bit2d(PADL_UP))) {
			ffnt_color(wp->moji_id[swp->cp_opt], 0x80, 0x80, 0x80);
			swp->cp_opt--;
			if (swp->cp_opt < 0) swp->cp_opt = ITEMN_T_OPT - 1;
			ffnt_color(wp->moji_id[swp->cp_opt], 0x80, 0x20, 0x20);
			if (!swp->titleF)
				set_findst2(&swp->fcur, wp->x - 20, wp->y +  16 + FNT_H * swp->cp_opt);
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	// ↓ 
		if (key_push(bit2d(PADL_DOWN))) {
			ffnt_color(wp->moji_id[swp->cp_opt], 0x80, 0x80, 0x80);
			swp->cp_opt++;
			if (swp->cp_opt > ITEMN_T_OPT - 1) swp->cp_opt = 0;
			ffnt_color(wp->moji_id[swp->cp_opt], 0x80, 0x20, 0x20);
			if (!swp->titleF)
				set_findst2(&swp->fcur, wp->x - 20, wp->y +  16 + FNT_H * swp->cp_opt);
			_SE_CUR1
		}
	} else if (swp->cp_opt == 2) {
		if (key_push(bit2d(PADL_LEFT))
		 || key_push(bit2d(PADL_RIGHT))) {
			mono_flag ^= 1;
			ffnt_redraw(wp->moji_id[5],
			 (u_short *)fnt_data + (mono_flag ? STR_MONO: STR_STEREO));
			_SE_SUR2
		}
	} else if (swp->cp_opt == 3) {
		if (key_push(bit2d(PADL_LEFT))){
			if(volume >= 0x2F){
				volume -= 0x10;
				_SE_CUR1
			} else {
				volume = 0x1F;
				_SE_CUR1
			}
			vol_set_five();
		} else if (key_push(bit2d(PADL_RIGHT))) {
//	iteya 
			if (volume < 0x7F) {
				volume += 0x10;
				_SE_CUR1
			} else {
				volume = 0x7F;
				_SE_CUR1
			}
			if(volume > 0x7F)	volume = 0x7F;
			vol_set_five();
		}
	}
}
/*===========================================================
	オプションパネルセット
===========================================================*/
void	set_t_option(WINDOW *wp, signed char cp) {
	SPRITE_OBJECT	*sprp;
	POLY_F3		*trip;
	int			*cip;
	short		i, tx, ty, tw, th;
	
	// タイトル 
	ffnt_xy(wp->moji_id[6], wp->x + 4 , wp->y + 4);
	// 白線 
	poly_xyset((void *)wp->work[7], wp->x + 3, wp->y + 4 + 15, wp->w - 8, 2);
	
	// 文字 
	cip = &wp->moji_id[0];
	tx = wp->x + 4;
	ty = wp->y + 20;
	for (i = 0; i < ITEMN_T_OPT; i++, cip++, ty += FNT_H) {
		ffnt_xy(*cip, tx, ty);
	}
	ffnt_xy(wp->moji_id[5], tx + FNT_W * 7, wp->y + 52);
	
	// ON/OFF 
	sprp = (SPRITE_OBJECT *)wp->work[0];
	spr_xyset(sprp, wp->x + 4 + FNT_W * 8, wp->y + 36);
	
	// カーソル 
	for (i = 0; i < 2; i++) {
		switch (cp) {
		case 2:
			tx = wp->x + 12 + FNT_W * 6;
			ty = wp->y + 24 + cp * FNT_H;
			break;
		case 3:
			if (i < 1 && volume < 0x2F || i > 0 && volume > 0x6F) {
				tx = -HIDE_XOFS;
				ty = -HIDE_YOFS;
			} else {
				tx = wp->x + 4 + 8 + FNT_W * 6;
				ty = wp->y + 4 + 20 + cp * FNT_H;
			}
			break;
		default:
			tx = -HIDE_XOFS;
			ty = -HIDE_YOFS;
			break;
		}
		sprp = (SPRITE_OBJECT *)wp->work[1 + i];
		spr_xyset(sprp, tx + 72 * i, ty);
	}
	
	// グラフ 
	th = 15 * volume >> 7;
	tw = 62 * volume >> 7;
	trip = (POLY_F3 *)wp->work[3];
	trip->x0 = wp->x + 2 + FNT_W * 7;
	trip->x1 = trip->x2 = trip->x0 + tw;
	trip->y0 = trip->y1 = wp->y + 2 + FNT_H * 5;
	trip->y2 = trip->y0 - th;
}

/*===========================================================
	タイトルオプション
		WINDOW	work[0]			ON/OFFポリ
				work[1～2]		カーソル
				work[3]			グラフ用三角
				work[4～6]		設定内容
				work[7]			白線ポリ
				moji_id[0～3]	メニューアイテム
				moji_id[4]		ステレオ／モノラル文字列
				moji_id[5]		パネルタイトル
===========================================================*/
void	t_option(WINDOW *wp) {
	SPRITE_OBJECT	*sprp;
	POLY_F3		*trip;
	POLY_F4		*f4p;
	short		i;
	
	switch (wp->f_step) {
	case 0:	// 初期設定 
		// ＯＮフラグ 
		sprp = (SPRITE_OBJECT *)wp->work[0] = sprobj_make();
		sprp->r = sprp->g = sprp->b = 0x80;
		sprp->pri = wp->pri - 1;
		spr_texset(sprp, 0,0, 952, 0, 944, 250);
		spr_whset(sprp, 32, 16);
		spr_uvset(sprp, 0, 952, (vib_flag) ? 0: 16);
		// カーソル 
		for (i = 0; i < 2; i++) {
			sprp = (SPRITE_OBJECT *)wp->work[1 + i] = sprobj_make();
			sprp->r = sprp->g = sprp->b = 0x80;
			sprp->pri = wp->pri - 1;
			spr_texset(sprp, 0,0, 944, 0, 928, 255);
			spr_whset(sprp, 8,8);
			spr_uvset(sprp, 0, 944 + 6 * i, 0);
		}
		// グラフ三角 
		trip = (POLY_F3 *)wp->work[3] = poly_f3_make();
		trip->r0 = 0x80;
		trip->g0 = 0x80;
		trip->b0 = 0xFF;
		
		wp->work[4] = 0;//vib_flag;
//		wp->work[5] = mono_flag;
//		wp->work[6] = volume;
		
		// 白線 
		f4p = (POLY_F4 *)wp->work[7] = poly_f4_make();
		f4p->r0 = f4p->g0 = f4p->b0 = 0xF0;
		
		// 文字 
		for (i = 0; i < ITEMN_T_OPT; i++) {
			wp->moji_id[i] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + opt_t_item[i]);
			wp->moji_max++;
			ffnt_color(wp->moji_id[i], 0x80, 0x80, 0x80);
		}
		ffnt_color(wp->moji_id[swp->cp_opt], 0x80, 0x20, 0x20);
		// ステレオ／モノラル文字列 
		wp->moji_id[5] = ffnt_open(wp->x, wp->y, FNT_W * 4, FNT_H, (u_short *)fnt_data + (mono_flag ? STR_MONO: STR_STEREO));
		wp->moji_max++;
		ffnt_color(wp->moji_id[5], 0x80,0x80,0x80);
		// パネルタイトル 
		wp->moji_id[6] = ffnt_open(wp->x, wp->y, wp->w - 8, FNT_H, (u_short *)fnt_data + SMENU10);
		wp->moji_max++;
		ffnt_color(wp->moji_id[6], 0x80, 0x80, 0x20);
		
		hide_app_win(wp, WIN_CHG_SYNC, 2, 0);
		set_option(wp, swp->cp_opt);
		set_findst2(&swp->fcur, wp->x - 20, wp->y + 16 + FNT_H * swp->cp_opt);
		swp->cur_win = TP_OPTION;
		wp->f_step++;
		break;
	case 1:	// 切り替え中 
		set_t_option(wp, swp->cp_opt);
		set_findst2(&swp->fcur, wp->x - 20, wp->y + 16 + FNT_H * swp->cp_opt);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step = MENU_NORMAL;
		}
		break;
	case MENU_NORMAL:
		if (wp->work[4] == 0) key_t_option(wp);
		set_t_option(wp, swp->cp_opt);
		if (wp->work[4] > 0) {	// 振動制御 
			wp->work[4]--;
			if (wp->work[4] == 0) pad_shibirenai();
		}
		break;
	case MENU_EXIT:
		set_t_option(wp, swp->cp_opt);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			wp->moji_max = 0;
			
			for (i = 0; i < 3; i++) {
				sprobj_kill((SPRITE_OBJECT *)wp->work[i]);
			}
			poly_kill((void *)wp->work[3]);
			poly_kill((void *)wp->work[7]);
			
//			vib_flag = wp->work[4];
//			mono_flag = wp->work[5];
//			volume = wp->work[6];
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
	POL_MEMBのパレット変更　特殊なのでよい子は真似しない
===========================================================*/
void	chg_pol_clut(POL_MEMB *cp, char col_n) {
	cp->pp->clut = GetClut(cp->tp.cx, cp->tp.cy + col_n);
}

/*===========================================================
	タイトルメニューの初期化
===========================================================*/
void	init_tMenu(void) {
	POLY_FT4	*tbp;
	SPRITE_OBJECT	*sprp;
	
	// タイトルバック 
	sprp = (SPRITE_OBJECT *)swp->work[0] = sprobj_make();
	sprp->r = sprp->g = sprp->b = 0x80;
	sprp->pri = 40;
	spr_texset(sprp, 1, 0, 512, 256, 0, 505);
	spr_uvset(sprp, 1, 512, 256);
	spr_xyset(sprp, -128, -100);
	spr_whset(sprp, 256, 160);
	
	// コピーライト表記 
	sprp = (SPRITE_OBJECT *)swp->work[1] = sprobj_make();
	sprp->r = sprp->g = sprp->b = 0x80;
	sprp->pri = 38;
	spr_texset(sprp, 0, 0, 640, 496, 0, 486);
	spr_uvset(sprp, 0, 640, 496);
	spr_xyset(sprp, -108, 92);
	spr_whset(sprp, 216, 16);
	
	// "PUSH START"表記 
	sprp = (SPRITE_OBJECT *)swp->work[2] = sprobj_make();
	sprp->r = sprp->g = sprp->b = 0x80;
	sprp->pri = 39;
	spr_texset(sprp, 0, 0, 768, 464, 0, 498);
	spr_uvset(sprp, 0, 768, 464);
	spr_xyset(sprp, -88, 56);
	spr_whset(sprp, 176, 24);
	
	swp->work[3] = 0;
	swp->cp_fir = 0;
	swp->exitF = FALSE;
	
	swp->cur_win = TP_NONE;
	swp->titleF = TRUE;
	swp->loadF = FALSE;
}
/*===========================================================
	タイトルメニューのメモリ確保物の解放
===========================================================*/
void	free_tMenu(void) {
	short	i;
	
	for (i = 0; i < 3; i++) {
		sprobj_kill((SPRITE_OBJECT *)swp->work[i]);
	}
}

/*===========================================================
	タイトルメニューでのキー入力処理	
===========================================================*/
void	key_title(WINDOW *wp) {
	SPRITE_OBJECT	**spp;
	
	if (pad_beta)	swp->work[3] = 0;	// ノータッチタイマ処理 
	
	if (pad_beta & PADL_UP) {			// ↑ 
		if (key_push(bit2d(PADL_UP))) {
			spp = (SPRITE_OBJECT **)wp->work[0];
			(*(spp + swp->cp_fir))->cy = 492;
			if (swp->cp_fir > 0)
				swp->cp_fir--;
			else
				swp->cp_fir = ITEMN_TITLE - 1;
			(*(spp + swp->cp_fir))->cy = 493;
			_SE_CUR1
		}
	} else if (pad_beta & PADL_DOWN) {	// ↓ 
		if (key_push(bit2d(PADL_DOWN))) {
			spp = (SPRITE_OBJECT **)wp->work[0];
			(*(spp + swp->cp_fir))->cy = 492;
			if (swp->cp_fir < ITEMN_TITLE - 1)
				swp->cp_fir++;
			else
				swp->cp_fir = 0;
			(*(spp + swp->cp_fir))->cy = 493;
			_SE_CUR1
		}
	} else if (pad_trg & PADR_RIGHT) {	// ○ 
		switch (swp->cp_fir) {
		case 1:
			hide_app_win(wp, WIN_CHG_SYNC, 4, 1);
			wp->f_step = MENU_EXIT;
// kawakami　1/3これでロードパネル作る 
			slc=0;	// セーブかロードか？ 0=LOAD
			rackwin[1] = make_window(MENU_LEFT - 20, MENU_TOP - HIDE_YOFS - 4, 8 + FNT_W * 18, 176 + 8+16, 15, datasave);
			break;
		case 2:	// オプション 
			hide_app_win(wp, WIN_CHG_SYNC, 4, 1);
			wp->f_step = MENU_EXIT;
			rackwin[1] = make_window(MENU_LEFT - 4, MENU_TOP - HIDE_YOFS - 4, FNT_W * 12 + 8, FNT_H * (ITEMN_T_OPT + 1) + 8, 15, t_option);
			break;
		default:
			fade_set(20, 0);
			wp->f_step++;
			break;
		}
		_SE_OK
	}
}

/*===========================================================
	タイトルパネルセット
===========================================================*/
void	set_tpanel(WINDOW *wp) {
	SPRITE_OBJECT	**spp;
	int		i;
	
	spp = (SPRITE_OBJECT **)wp->work[0];
	for (i = 0; i < ITEMN_TITLE; i++, spp++) {
		spr_xyset(*spp, wp->x + 4, wp->y + 4 + FNT_H * i);
	}
}

/*===========================================================
	タイトルメニューパネル関数
		work[0]		メニューアイテムのSPRITE_OBJECTポインタポインタ
===========================================================*/
void	titlepanel(WINDOW *wp) {
	SPRITE_OBJECT	**spp;
	short		i;
	
	switch (wp->f_step) {
	case 0:
		spp = (SPRITE_OBJECT **)wp->work[0] = (SPRITE_OBJECT **)memalloc(sizeof(SPRITE_OBJECT *) * ITEMN_TITLE, (void **)&wp->work[0]);
		for (i = 0; i < ITEMN_TITLE; i++, spp++) {
			*spp = sprobj_make();
			spr_texset(*spp, 0,0, 768, 400, 0, 492);
			if (i == swp->cp_fir) (*spp)->cy = 493;
			(*spp)->r = (*spp)->g = (*spp)->b = 0x80;
			(*spp)->pri = 3;
			spr_uvset(*spp, 0, 768, 400 + FNT_H * i);
			spr_xyset(*spp, wp->x + 4, wp->y + 4 + FNT_H * i);
			spr_whset(*spp, 160, 16);
		}
		
		hide_app_win(wp, WIN_CHG_SYNC, 4, 0);
		set_tpanel(wp);
		swp->cur_win = TP_MAIN;
		
		wp->f_step++;
		break;
	case 1:	// フェードイン待ち 
		set_tpanel(wp);
		if (wp->mode == WINMODE_NOP) {
			wp->f_step++;
		}
		break;
	case 2:
		key_title(wp);
		swp->work[3]++;
#if 0
		if (swp->work[3] > 1800) {
			wp->f_step++;
		}
#endif
		break;
	case 3:	// フェードアウト待ち 
		if (fade_cur == 0) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			
			spp = (SPRITE_OBJECT **)wp->work[0];
			for (i = 0; i < ITEMN_TITLE; i++, spp++) {
				sprobj_kill(*spp);
			}
			memfree((void **)&wp->work[0]);
			wp->moji_max = 0;
			wp->f_step++;
		}
		
		break;
	case 4:
		dispose_window(wp);
		rackwin[0] = NULL;
		break;
	case MENU_EXIT:
		set_tpanel(wp);
		if (wp->mode == WINMODE_NOP) {
			for (i = 0; i < wp->moji_max; i++) {
				ffnt_close(wp->moji_id[i]);
			}
			
			spp = (SPRITE_OBJECT **)wp->work[0];
			for (i = 0; i < ITEMN_TITLE; i++, spp++) {
				sprobj_kill(*spp);
			}
			memfree((void **)&wp->work[0]);
			wp->moji_max = 0;
			wp->f_step = 4;
		}
		break;
	}
}

/*===========================================================
	タイトルメニュー
		swp		work	[0]		タイトルバック
						[1]		コピーライト
						[2]		プッシュスタートスプライト
						[3]		点滅カウンタ
						[4]		ノータッチカウンタ
===========================================================*/
short	titleMenu(short *sp) {
	POL_MEMB	*cpm;
	SPRITE_OBJECT	*sprp;
	short		retv = 0;
	
	switch (*sp) {
	case 0:
		draw_rq = 1;	// 描画ｏｆｆ 
		OPN_SEQ
		swp = (SUBMENU *)memalloc(sizeof(SUBMENU), (void **)&swp);
		if (swp != NULL) {
			init_tMenu();
			
			swp->work[3] = 0;
			swp->work[4] = 0;
			swp->cp_opt = 0;
			
			fade_set(1, 0);	// 一気に暗く 
			fade_drv();
			
			fade_set(20, 1);
			
			draw_rq = 0;	// 描画ｏｎ 
			(*sp)++;
		} else
			retv = -1;
		break;
	case 1:
		if (fade_cur == 0) {
			make_yn_win(); 
			make_mes_win(); 
			(*sp)++;
		}
		break;
	case 2:
		sprp = (SPRITE_OBJECT *)swp->work[2];
		swp->work[3]++;
		if (swp->work[3] % 60 == 0) {
			if (swp->work[3] % 120 / 2)	sprp->y = 56;
			else						sprp->y = HIDE_YOFS;
		}
		
		swp->work[4]++;
		if (swp->work[4] > 1800) {
			(*sp) += 2;
			break;
		}
		
		if (pad_cnt & (PAD_START)) {
			sprp->y = HIDE_YOFS;
			rankin_no = 10;
			// パネル 
			rackwin[0] = make_window(-84 - 4, 32 - 4 + HIDE_YOFS, 160 + 8, 16 * ITEMN_TITLE + 8, 11, titlepanel);
			(*sp)++;
			_SE_OK
		}
		break;
	case 3:
		if (rackwin[0] == NULL && swp->cur_win == TP_MAIN
		 || rackwin[1] == NULL && swp->loadF == TRUE) {
			(*sp)++;
		}
//		finger_drv(&swp->fcur);
		break;
	case 4:
		if (swp->loadF)	// 1/2	swp->loadFが立ってるとロードされたものとみなす 
			retv = 10;
		else if (swp->work[4] > 1800)
			retv = 4;
		else
			retv = swp->cp_fir + 1;
		
//		dispose_yn_win();
		free_tMenu();
		poly_kill(swp->fcur.pm.pp);	// カーソル解放 
		memfree((void **)&swp);
		fade_set(1, 1);
		break;
	default:
	}
	
	return retv;
}

#define	TJOB_LOGO1		10
#define	TJOB_LOGO2		TJOB_LOGO1		+10
#define	TJOB_OPMOVIE	TJOB_LOGO2		+10
#define	TJOB_TITLE		TJOB_OPMOVIE	+10
#define	TJOB_SELECT		TJOB_TITLE		+10
#define	TJOB_TLOAD		TJOB_SELECT		+10
#define	TJOB_PLOAD		TJOB_TLOAD		+10
#define	TJOB_OPTION		TJOB_PLOAD		+10
#define	TJOB_DEMO		TJOB_OPTION		+10
#define	GAME_PLAY		TJOB_DEMO		+10
#define	DISP_LOADING	GAME_PLAY		+10

/*===========================================================
	タイトル系メインループ
===========================================================*/
void	titleMain(void) {
static	SPRITE_OBJECT	*loading_p, *l_ic_p;
	short	_step, cue, child_step, fret;
	short	*csp;
	
	_step = 0;
	child_step = 0;
	csp = &child_step;
	while (1) {
		switch (_step) {
		case 0:
			if (quitflag) {
				quitflag = FALSE;
				_step = TJOB_SELECT;
			} else {
				draw_rq = 1;	// 描画ｏｆｆ 
				init_view();
				_step = TJOB_TITLE;
			}
			child_step = 0;
			break;
		case TJOB_TITLE:
			fret = titleMenu(csp);
			switch (fret) {
			case 1:	// はじめから 
				_step = DISP_LOADING;
				cue = TJOB_SELECT;
				break;
			case 2:	// トータルデータロード 
				_step = TJOB_TLOAD;
				OPN_SEQ_END
				break;
			case 3:	// オプション 
				_step = TJOB_OPTION;
				OPN_SEQ_END
				break;
			case 4:	// タイムアウト 
				OPN_SEQ_END
			func_mode = MODE_MOVIE;
			return;
//				_step = TJOB_DEMO;
				break;
			case 10:	// ロード 
				_step = DISP_LOADING;
				cue = GAME_PLAY;
				OPN_SEQ_END
				break;
			default:
			}
			if (fret) child_step = 0;
			break;
#if 0
		case TJOB_OPTION:	// オプション 
			// ウィンドウ呼び出しで済ませたのでカット 
			break;
#endif
		case DISP_LOADING:
			loading_p = sprobj_make();
			loading_p->pri = 3;
			spr_texset(loading_p, 0, 0, 960, 192, 960, 248);
			spr_xyset(loading_p, 20, 60);
			spr_uvset(loading_p, 0, 960, 192);
			spr_whset(loading_p, 120, 32);
			
			l_ic_p = sprobj_make();
			l_ic_p->pri = 3;
			spr_texset(l_ic_p, 1, 0, 576, 0, 0, 511);
			spr_xyset(l_ic_p, -120, -80);
			spr_uvset(l_ic_p, 1, 576, 1);
			spr_whset(l_ic_p, 112, 100);
			
			_step++;
			break;
		case DISP_LOADING + 1:
			_step++;
			break;
		case DISP_LOADING + 2:
			_step = cue;
			draw_rq = 1;
			sprobj_kill(loading_p);
			sprobj_kill(l_ic_p);
			break;
		case TJOB_SELECT:
			fret = selMenu(csp);
			switch (fret) {
			case -1:	// タイトルに戻る 
				_step = DISP_LOADING;
				cue = TJOB_TITLE;
				break;
			case 1:		// プレイに進む 
				_step = DISP_LOADING;
				cue = GAME_PLAY;
				break;
			default:
			}
			if (fret) child_step = 0;
			break;
		case GAME_PLAY:
			hawk_pos[0] = hawk_pos[1] = hawk_pos[2] = -1;
			
			func_mode = MODE_GAME;
			return;
			break;
		default:
			child_step = 0;
			_step = TJOB_TITLE;
			break;
		}
		
		if (exitFlag)	break;
		
		fade_drv();
		card_seq_check(0);
		wait(1);
	}
}

