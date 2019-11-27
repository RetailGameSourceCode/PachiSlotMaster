#ifndef _SPRITE_H_
#define _SPRITE_H_


//	SPRITE.C 構造体	開始	////////////////////////////////////////////////
#define SPROBJ_MAX 1			/* スプライトグループ最大個数 */
#define	CVGT4_MAX	96	// ＧＴ４等で使うスプライトの最大枚数


#ifdef	MIHON
struct _OBJECT_TREE{
	u_short	type;		// 構造体の種類
	void	*point;		// システム予約	//	ＯＢＪの構造体アドレス
	void	*before;	// システム予約	//	前のＯＢＪの木
	void	*next;		// システム予約	//	次のＯＢＪの木
};
#endif

//	スプライト構造体 ANM無し
struct _SPRITE_OBJECT{
	u_long	attribute;				// 属性
	u_short	pri;					// 表示優先度
	u_short	tpage;					// テクスチャページ
	short	x,y;					// 原点座標
	short	mx,my;					// 回転拡大縮小中心座標
	short	u,v;					// テクスチャ（ページ内）座標
	short	w,h;					// スプライト幅
	short	cx,cy;					// ＣＬＵＴ座標
	short	scalex,scaley;			// 拡大縮小率
//	short	vx,vy;					// 移動ベクタ
//	u_short vwx,vwy;				// システム予約
	long	rotate;					// Ｚ軸回転角
	long	work[8];				// 汎用ワーク
	u_char	r,g,b;					// 輝度値
	u_char	flg;					// システム予約
//	void	*func;					// 関数処理を付随させる
	struct _SPRITE_OBJECT *before;	// システム予約
	struct _SPRITE_OBJECT *next;	// システム予約
};
typedef struct _SPRITE_OBJECT SPRITE_OBJECT;

/* スプライト構造体 ANM有り*/
struct _ANIMSPR_OBJECT{
	u_long	attribute;				/* 属性 */
	short	x,y;					/* 原点座標 */
	u_short	pri;					/* 表示優先度 */
	u_short	num;					/* パターン番号 */
	short	mx,my;					/* 回転拡大縮小中心座標 */
	short	scalex,scaley;			/* 拡大縮小率 */
	long	rotate;					/* Ｚ軸回転角 */
	long	work[8];				/* 汎用ワーク */
	u_char	r,g,b;					/* 輝度値 */
	u_char	flg;					/* システム予約 */
//	short	vx,vy;					/* 移動ベクタ */
//	u_short vwx,vwy;				/* システム予約 */
//	void	*func;					/* システム予約 */
	u_short	*anim_pt;				/* システム予約 */
//	u_short	anim_flg;				/* アニメーションデータからの返値 */
//	u_short anim_time;				/* システム予約 */
//	short	anim_rptp;				/* システム予約 */
//	u_short anim_rpt[3];			/* システム予約 */
	struct _ANIMSPR_OBJECT *before;	/* システム予約 */
	struct _ANIMSPR_OBJECT *next;	/* システム予約 */
};
typedef struct _ANIMSPR_OBJECT ANIMSPR_OBJECT;

/* アニメーションデータ */

//	SPRITE.C 構造体	終了	////////////////////////////////////////////////

#define	RGB_COUNT	3
#define	RED			0
#define	GREEN		1
#define	BLUE		2

void sprite_rgbset(SPRITE_OBJECT *sprobj_pt,short r,short g,short b);
void sp_rgb_ld(SPRITE_OBJECT *sprobj_pt);

void	spr_texset(SPRITE_OBJECT *, int, int, int, int, short, short);
void	spr_xyset(SPRITE_OBJECT *, short, short);
void	spr_uvset(SPRITE_OBJECT *, int, short, short);
void	spr_whset(SPRITE_OBJECT *, short, short);

void	poly_priset(void *, u_short);


void sprobj_don(SPRITE_OBJECT *);
void sprobj_doff(SPRITE_OBJECT *);
void add_prim(void *,GsOT *, int);
void sprobj_xy_to_mxy(SPRITE_OBJECT *);

SPRITE_OBJECT *sprobj_make(void);
SPRITE_OBJECT *sprobj_make3(SPRITE_OBJECT** sprobj_pt);


void sprobj_kill(SPRITE_OBJECT *);
void sprobj_all_kill(void);

void dispxy_set(short,short,short,short);
void sprobj_init(void);

//void sprobj_func_set(SPRITE_OBJECT *,void *);
//void sprobj_func_end(SPRITE_OBJECT *);
void sprobj_draw();



void poly_init(void);
/*POLY_F3		フラット３角形プリミティブ*/
POLY_F3 *poly_f3_make(void);
/*POLY_F4 	フラット４角形プリミティブ*/
POLY_F4 *poly_f4_make(void);
/*POLY_G3 	グーローシェーディング３角形プリミティブ*/
POLY_G3 *poly_g3_make(void);
/*POLY_G4 	グーローシェーディング４角形プリミティブ*/
POLY_G4 *poly_g4_make(void);
/*POLY_FT3	フラットテクスチャマップ３角形プリミティブ*/
POLY_FT3 *poly_ft3_make(void);
/*POLY_FT4	フラットテクスチャマップ４角形プリミティブ*/
POLY_FT4 *poly_ft4_make(void);
/*POLY_GT3	グーローテクスチャマップ３角形プリミティブ*/
POLY_GT3 *poly_gt3_make(void);
/*POLY_GT4	グーローテクスチャマップ４角形プリミティブ*/
POLY_GT4 *poly_gt4_make(void);

LINE_G4 *line_g4_make(void);
LINE_G3 *line_g3_make(void);
LINE_G2 *line_g2_make(void);
LINE_F4 *line_f4_make(void);
LINE_F3 *line_f3_make(void);
LINE_F2 *line_f2_make(void);
GsBOXF *box_make(void);


void *poly_make(u_short type);
void poly_kill(void *poly_pt);
POLY_LST *get_polylst(void *poly_pt);

void poly_don(void *poly_pt);
void poly_doff(void *poly_pt);

void box_xyset(GsBOXF *poly_pt,short x,short y,short w,short h);
void box_rgbset(GsBOXF *poly_pt,short r,short g,short b);

void poly_f4_xyset(POLY_F4 *poly_pt,short x,short y,short w,short h);
void poly_g4_xyset(POLY_G4 *poly_pt,short x,short y,short w,short h);
void poly_f4_rgbset(POLY_F4 *poly_pt,short r,short g,short b);
void poly_g4_rgbset(POLY_G4 *poly_pt,short r,short g,short b);

void line_g4_xyset(LINE_G4 *poly_pt,short x,short y,short w,short h);
void line_f4_xyset(LINE_F4 *poly_pt,short x,short y,short w,short h);

void line_g2_rgbset(LINE_G2 *poly_pt,short r,short g,short b);
void line_g3_rgbset(LINE_G3 *poly_pt,short r,short g,short b);
void line_g4_rgbset(LINE_G4 *poly_pt,short r,short g,short b);
void line_f2_rgbset(LINE_F2 *poly_pt,short r,short g,short b);
void line_f3_rgbset(LINE_F3 *poly_pt,short r,short g,short b);
void line_f4_rgbset(LINE_F4 *poly_pt,short r,short g,short b);

void poly_f4_rgb_ld(POLY_F4 *poly_pt);

void poly_uvset(void *,short,short,short,short);
void poly_uv4set(void *poly_pt,short u0,short v0,short u1,short v1,short u2,short v2,short u3,short v3);
void poly_xyset(void *,short,short,short,short);
void poly_rgbset(void *poly_pt,short r,short g,short b);

void poly_ft4_rgbset(POLY_FT4 *poly_pt,short r,short g,short b);
void poly_ft4_xyset(POLY_FT4 *,short,short,short,short);
void poly_ft4_uvset(POLY_FT4 *,short,short,short,short);
void poly_ft4_fset(POLY_FT4 *,short,short,short,short,short,short,short);
void poly_ft4_xy4set(POLY_FT4 *poly_pt,short x0,short y0,short x1,short y1,short x2,short y2,short x3,short y3);
void poly_ft4_uv4set(POLY_FT4 *poly_pt,short u0,short v0,short u1,short v1,short u2,short v2,short u3,short v3);

void poly_gt4_rgbset(POLY_GT4 *poly_pt,short r,short g,short b);
void poly_gt4_xyset(POLY_GT4 *,short,short,short,short);
void poly_gt4_uvset(POLY_GT4 *,short,short,short,short);
void poly_gt4_fset(POLY_GT4 *,short,short,short,short,short,short,short);
void poly_gt4_xy4set(POLY_GT4 *poly_pt,short x0,short y0,short x1,short y1,short x2,short y2,short x3,short y3);
void poly_gt4_uv4set(POLY_GT4 *poly_pt,short u0,short v0,short u1,short v1,short u2,short v2,short u3,short v3);

void waku_f3set(LINE_F3 *_pt0,LINE_F3 *_pt1,LINE_F3 *_pt2,LINE_F3 *_pt3,int x,int y,int w,int h);

void f_tim_change(u_short *tim,int px,int py,int cx,int cy);

void f_spritefade(int f,int time);
void s_sprite_off(void);
void s_sprite_on(void);
void sp_obj_onf(SPRITE_OBJECT *sprobj_pt);

#if	DEBUG_MODE==1
void sp_xytest(SPRITE_OBJECT *);
#endif

void poly_draw(void);

/*　スプライト　*/
//extern	SPRITE_OBJECT *sprobj_top;			/*スプライトグループトップ*/
//extern	SPRITE_OBJECT *sprobj_last;			/*スプライトグループラスト*/
extern	POLY_LST *polylst_top;
extern	POLY_LST *polylst_last;
//extern	char bright[RGB_COUNT];

//extern	POLY_GT4	*cvgt4[CVGT4_MAX];
//extern	POLY_G4		*pg4;
//extern	int 		work4[CVGT4_MAX][8];	//	GT4に付随させるＷＯＲＫ
//extern	char		cvgt4_on[CVGT4_MAX];


#ifdef OBJ_ALLOC
//extern SPRITE_OBJECT	*sprite[SPROBJ_MAX];
#else
extern SPRITE_OBJECT	sprobj[SPROBJ_MAX];	/*スプライトグループ*/
#endif

#endif


#if COMMENT

	 0:POLY_F3	フラット３角形プリミティブ
	 1:POLY_F4 	フラット４角形プリミティブ
	 2:POLY_G3 	グーローシェーディング３角形プリミティブ
	 3:POLY_G4 	グーローシェーディング４角形プリミティブ
	 4:POLY_FT3	フラットテクスチャマップ３角形プリミティブ
	 5:POLY_FT4	フラットテクスチャマップ４角形プリミティブ
	 6:POLY_GT3	グーローテクスチャマップ３角形プリミティブ
	 7:POLY_GT4	グーローテクスチャマップ４角形プリミティブ

	 8:LINE_F2	
	 9:LINE_F3	
	10:LINE_F4	
	11:LINE_G2	
	12:LINE_G3	
	13:LINE_G4	

#endif
