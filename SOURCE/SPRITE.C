/*=============================================================
 *	スプライトコントロール
 *
 *=============================================================*/

#include "common.h"
#include "work.h"

/*　スプライト　*/
SPRITE_OBJECT *sprobj_top;			/*スプライトグループトップ*/
SPRITE_OBJECT *sprobj_last;			/*スプライトグループラスト*/
//char bright[RGB_COUNT];
//POLY_GT4	*cvgt4[CVGT4_MAX];
//POLY_G4		*pg4;
//int 		work4[CVGT4_MAX][8];	//	GT4に付随させるＷＯＲＫ
//char		cvgt4_on[CVGT4_MAX];

/*　スプライト　*/
#ifdef OBJ_ALLOC
//SPRITE_OBJECT	*sprite[SPROBJ_MAX];
#else
SPRITE_OBJECT sprobj[SPROBJ_MAX];	/*スプライトグループ*/
#endif

#if	DEBUG_MODE==1
static int spobj_cnt;
#endif

// these 4 functions are added by kawakami at 17th Dec. '98 
/*===========================================================
	指定スプライトのテクスチャページとCLUT位置を指定
		in:	int		mode		テクス色数チャモード
			int		abr			半透明アトリビュート
			int		tx, ty		テクスチャ位置
			short	cx, cy		CLUT位置
===========================================================*/
void	spr_texset(SPRITE_OBJECT *sop, int mode, int abr, int tx, int ty, short cx, short cy) {
	sop->attribute = (mode << 24);
	sop->tpage = GetTPage(mode, abr, tx, ty);
	sop->cx = cx;
	sop->cy = cy;
}
/*===========================================================
	指定スプライトの表示位置指定
===========================================================*/
void	spr_xyset(SPRITE_OBJECT *sop, short x, short y) {
	sop->x = x;	sop->y = y;
}
/*===========================================================
	指定スプライトのUV指定
===========================================================*/
void	spr_uvset(SPRITE_OBJECT *sop, int mode, short u, short v) {
	int	by;
	
	by = 4 - mode * 2;
	if (by < 0) by = 0;
	
	sop->u = (u & 0x3F) * by;
	sop->v = v & 0xFF;
}
/*===========================================================
	指定スプライトの表示サイズ指定
===========================================================*/
void	spr_whset(SPRITE_OBJECT *sop, short w, short h) {
	sop->w = w;	sop->h = h;
}



/*=============================================================
 *　スプライトの表示をＯＮ ＯＦＦします
 *
 * in : SPRITE_OBJECT * 表示をＯＮ ＯＦＦする
 * 						スプライトオブジェクトのポインタ
 *
 * out: void
 *
 *=============================================================*/
void sprobj_don( SPRITE_OBJECT *sprobj_pt )
{
	sprobj_pt->attribute = sprobj_pt->attribute & 0x7fffffff;
}


void sprobj_doff( SPRITE_OBJECT *sprobj_pt )
{
	sprobj_pt->attribute = sprobj_pt->attribute | 0x80000000;
}

//=============================================================
//	GPUのプリミティブをＯＴに登録します
//
//in:
//	void *pt	プリミティブのポインタ
//	GsOT *ot	ＯＴのポインタ
//	int pri		ＯＴでの位置
//
//out:
//	void
//
//=============================================================
void add_prim(void *pt, GsOT *ot, int pri)
{
	AddPrim((u_long *)(ot->org)+pri, pt);
}

/*=============================================================
 *　スプライトのＸＹ座標をmx,myへコピーします
 *
 * in : SPRITE_OBJECT * スプライトオブジェクトのポインタ
 *
 * out: void
 *
 *=============================================================*/
void sprobj_xy_to_mxy( SPRITE_OBJECT *sprobj_pt )
{
	sprobj_pt->mx = sprobj_pt->x;
	sprobj_pt->my = sprobj_pt->y;
}

/*===================================================================
 *　画面端の座標を指定します
 *　スプライトのクリッピングやＢＧの端っこの指定などに使用します
 *　画面のドット比を設定したり変えたりするときに呼んでください
 *
 * in : short x0,x1,y0,y1
 *		左端,右端,上端,下端の座標
 * out: void
 *
 *=================================================================*/
void dispxy_set( short x0,short x1,short y0,short y1)
{
	dispx0 = x0;
	dispx1 = x1;
	dispy0 = y0;
	dispy1 = y1;
}


/*===================================================================
 *　スプライトのオブジェクトを初期化します
 *
 * in : void
 * out: void
 *
 *=================================================================*/
void sprobj_init(void)
{
	u_short obj_cnt;

	sprobj_top = sprobj_last = NULL;
//	for(obj_cnt = 0; obj_cnt < SPROBJ_MAX; obj_cnt++){
//		sprite[obj_cnt]=NULL;
//	}
//	bright[RED]		= 128;
//	bright[GREEN]	= 128;
//	bright[BLUE]	= 128;
#if	DEBUG_MODE==1
	spobj_cnt = 0;
#endif
}


#ifdef OBJ_ALLOC
/*===================================================================
 *　スプライト管理バッファのメモリを割り当てます
 *
 * in : void
 * out: SPRITE_OBJECT * スプライトオブジェクトのポインタ
 *
 *=================================================================*/
//SPRITE_OBJECT *spalloc(void)
//{
//	return (SPRITE_OBJECT *)memalloc(sizeof(SPRITE_OBJECT));
//}
#endif

void sprite_rgbset(SPRITE_OBJECT *sprobj_pt,short r,short g,short b)
{
	sprobj_pt->r=r;
	sprobj_pt->g=g;
	sprobj_pt->b=b;

}

//	指定したオブジェクトを点滅させる
void sp_rgb_ld(SPRITE_OBJECT *sprobj_pt)
{
	if(sprobj_pt->r<110)	sprobj_pt->b=sprobj_pt->g=sprobj_pt->r=128;

	if(sprobj_pt->work[7]){
		if(sprobj_pt->r<240)	sprobj_pt->b=sprobj_pt->g=sprobj_pt->r=(sprobj_pt->r+8);
		else					sprobj_pt->work[7]=(sprobj_pt->work[7]+1)%2;
	}
	else{
		if(sprobj_pt->r>128)	sprobj_pt->b=sprobj_pt->g=sprobj_pt->r=sprobj_pt->r-8;
		else					sprobj_pt->work[7]=(sprobj_pt->work[7]+1)%2;
	}
}

void sp_obj_onf(SPRITE_OBJECT *sprobj_pt)
{
	sprobj_pt->work[7]=(sprobj_pt->work[7]+1)%20;
	if(!sprobj_pt->work[7])	sprobj_pt->work[6]=(sprobj_pt->work[6]+1)%2;
	if(sprobj_pt->work[6])	sprobj_doff(sprobj_pt);
	else					sprobj_don(sprobj_pt);
}


/*===================================================================
 *　スプライトのオブジェクトを登録します
 *
 * in : void
 * out: SPRITE_OBJECT * スプライトオブジェクトのポインタ
 *
 *=================================================================*/
SPRITE_OBJECT *sprobj_make(void)
{
	SPRITE_OBJECT	*sprobj_pt;

	sprobj_pt = NULL;
	//if(NULL != (sprobj_pt = spalloc())){		//	葉の作成
	if(NULL != (sprobj_pt = (SPRITE_OBJECT *)memalloc(sizeof(SPRITE_OBJECT), (void**)&sprobj_pt))){		//	葉の作成
		sprobj_pt->flg			= 1; 			//	エントリーして
		sprobj_pt->pri			= 1; 			//	エントリーして
		sprobj_pt->attribute	= GsROTOFF;		//	反転拡縮なし
		sprobj_pt->scalex		= 0x1000;
		sprobj_pt->scaley		= 0x1000;
		sprobj_pt->r			= 128;
		sprobj_pt->g			= 128;
		sprobj_pt->b			= 128;
#if 0
//		memallocの中で零クリアしてるので省く
		sprobj_pt->x			= 0;
		sprobj_pt->y			= 0;
		sprobj_pt->cx			= 0;
		sprobj_pt->cy			= 0;
		sprobj_pt->pri			= 0;
		sprobj_pt->mx			= 0;
		sprobj_pt->my			= 0;
		sprobj_pt->rotate		= 0;
//		sprobj_pt->vx			= 0;
//		sprobj_pt->vy			= 0;
//		sprobj_pt->vwx			= 0;
//		sprobj_pt->vwy			= 0;
		sprobj_pt->work[0]		= 0;
		sprobj_pt->work[1]		= 0;
		sprobj_pt->work[2]		= 0;
		sprobj_pt->work[3]		= 0;
		sprobj_pt->work[4]		= 0;
		sprobj_pt->work[5]		= 0;
		sprobj_pt->work[6]		= 0;
		sprobj_pt->work[7]		= 0;
//		sprobj_pt->func			= NULL;
#endif
		//	リストへつなぐ
		if(sprobj_top == NULL ){	//	初めて
			sprobj_top			= sprobj_pt;
			sprobj_pt->before	= NULL;
			sprobj_pt->next		= NULL;
		}
		else{						//	２つめ以降
			sprobj_last->next	= sprobj_pt;
			sprobj_pt->before	= sprobj_last;
			sprobj_pt->next		= NULL;
		}
		sprobj_last = sprobj_pt;
#if	DEBUG_MODE==1
		spobj_cnt++;
#endif
		return sprobj_pt;
	}
	return NULL;
}

#if 0
SPRITE_OBJECT *sprobj_make3(SPRITE_OBJECT** sprobj_pt)
{
//	SPRITE_OBJECT	*sprobj_pt;

	*sprobj_pt = NULL;
	if(NULL != (*sprobj_pt = (SPRITE_OBJECT *)memalloc(sizeof(SPRITE_OBJECT), (void**)&sprobj_pt))){		//	葉の作成
		*sprobj_pt->flg			= 1; 			//	エントリーして
		*sprobj_pt->pri			= 1; 			//	エントリーして
		*sprobj_pt->attribute	= GsROTOFF;		//	反転拡縮なし
		*sprobj_pt->scalex		= 0x1000;
		*sprobj_pt->scaley		= 0x1000;
		sprobj_pt->r			= 128;
		*sprobj_pt.g			= 128;
		sprobj_pt.b				= 128;
#ifdef 0
//		memallocの中で零クリアしてるので省く
		sprobj_pt->x			= 0;
		sprobj_pt->y			= 0;
		sprobj_pt->cx			= 0;
		sprobj_pt->cy			= 0;
		sprobj_pt->pri			= 0;
		sprobj_pt->mx			= 0;
		sprobj_pt->my			= 0;
		sprobj_pt->rotate		= 0;
//		sprobj_pt->vx			= 0;
//		sprobj_pt->vy			= 0;
//		sprobj_pt->vwx			= 0;
//		sprobj_pt->vwy			= 0;
		sprobj_pt->work[0]		= 0;
		sprobj_pt->work[1]		= 0;
		sprobj_pt->work[2]		= 0;
		sprobj_pt->work[3]		= 0;
		sprobj_pt->work[4]		= 0;
		sprobj_pt->work[5]		= 0;
		sprobj_pt->work[6]		= 0;
		sprobj_pt->work[7]		= 0;
//		sprobj_pt->func			= NULL;
#endif
		//	リストへつなぐ
		if(sprobj_top == NULL ){	//	初めて
			sprobj_top			= *sprobj_pt;
			*sprobj_pt->before	= NULL;
			*sprobj_pt->next		= NULL;
		}
		else{						//	２つめ以降
			sprobj_last->next	= *sprobj_pt;
			*sprobj_pt->before	= *sprobj_last;
			*sprobj_pt->next		= NULL;
		}
		sprobj_last = *sprobj_pt;
#if	DEBUG_MODE==1
		spobj_cnt++;
#endif
		return *sprobj_pt;
	}
	return NULL;
}
#endif

#if 0
//	実験用に作りました
SPRITE_OBJECT *sprobj_make2(u_short tpx,u_short tpy,long atrb,short u,short v,short h,short w,short cx,short cy)
{
	SPRITE_OBJECT	*sprobj_pt;

	sprobj_pt = NULL;
	//if(NULL != (sprobj_pt = spalloc())){		//	葉の作成
	if(NULL != (sprobj_pt = (SPRITE_OBJECT *)memalloc(sizeof(SPRITE_OBJECT), (void**)&sprobj_pt))){		//	葉の作成
//		memallocの中で零クリアしてるので省く
//		memset(&sprobj_pt, 0,sizeof(SPRITE_OBJECT));

		sprobj_pt->flg			= 1; 			//	エントリーして
		sprobj_pt->pri			= 1; 			//	エントリーして
		sprobj_pt->tpage=GetTPage(0,1,tpx,tpy);	//	テクスチャページ
		sprobj_pt->attribute	= atrb;
		sprobj_pt->u			= u;
		sprobj_pt->v			= v;
		sprobj_pt->w			= w;
		sprobj_pt->h			= h;
		sprobj_pt->cx			= cx;
		sprobj_pt->cy			= cy;
		sprobj_pt->r			= 128;
		sprobj_pt->g			= 128;
		sprobj_pt->b			= 128;
		//	リストへつなぐ
		if(sprobj_top == NULL ){	//	初めて
			sprobj_top			= sprobj_pt;
			sprobj_pt->before	= NULL;
			sprobj_pt->next		= NULL;
		}
		else{						//	２つめ以降
			sprobj_last->next	= sprobj_pt;
			sprobj_pt->before	= sprobj_last;
			sprobj_pt->next		= NULL;
		}
		sprobj_last = sprobj_pt;
#if	DEBUG_MODE==1
		spobj_cnt++;
#endif
		return sprobj_pt;
	}
	return NULL;
}
#endif

/*===================================================================
 *　スプライトのオブジェクトを解放します
 *
 * in : SPRITE_OBJECT * 解放するスプライトオブジェクトのポインタ
 * out: void
 *
 *=================================================================*/
void sprobj_kill(SPRITE_OBJECT *sprobj_pt)
{
	SPRITE_OBJECT *before_pt;
	SPRITE_OBJECT *next_pt;

//	if(sprobj_pt && sprobj_pt->flg){
//	if(((void *)sprobj_pt!=NULL) && sprobj_pt->flg){
	if(sprobj_pt->flg){
		sprobj_pt->flg = 0; 	/*エントリーを消して*/
		before_pt = sprobj_pt->before;
		next_pt = sprobj_pt->next;
		/*リスト列からはずす*/
		if( before_pt == NULL && next_pt == NULL ){
			/*自分しかいない*/
			sprobj_top = sprobj_last = NULL;
		}
		else{
			if( before_pt == NULL ){
				sprobj_top = next_pt;
			}
			else{
				before_pt->next = next_pt;
			}
			if( next_pt == NULL ){
				sprobj_last = before_pt;
			}
			else{
				next_pt->before = before_pt;
			}
		}
		memfree((void**)&sprobj_pt);
//		(void *)sprobj_pt = NULL;

#if	DEBUG_MODE==1
//		mal_size-=sizeof(SPRITE_OBJECT);
		spobj_cnt--;
#endif
	}
#if	DEBUG_MODE==1
	else{
		DEB_STOP3(sprobj_pt);
	}
#endif
}

#if 0
void sprobj_kill2(SPRITE_OBJECT *sprobj_pt)
{
	SPRITE_OBJECT *before_pt;
	SPRITE_OBJECT *next_pt;

	if(sprobj_pt && *sprobj_pt->flg){
		*sprobj_pt->flg = 0; 	/*エントリーを消して*/
		before_pt = *sprobj_pt->before;
		next_pt = *sprobj_pt->next;
		/*リスト列からはずす*/
		if( before_pt == NULL && next_pt == NULL ){
			/*自分しかいない*/
			sprobj_top = sprobj_last = NULL;
		}
		else{
			if( before_pt == NULL ){
				sprobj_top = next_pt;
			}
			else{
				before_pt->next = next_pt;
			}
			if( next_pt == NULL ){
				sprobj_last = before_pt;
			}
			else{
				next_pt->before = before_pt;
			}
		}
		memfree((void**)&sprobj_pt);
		(void *)sprobj_pt = NULL;

#if	DEBUG_MODE==1
//		mal_size-=sizeof(SPRITE_OBJECT);
		spobj_cnt--;
#endif
	}
}
#endif

int spc;
void sprobj_all_kill(void)
{
	SPRITE_OBJECT *next_pt;
	SPRITE_OBJECT *sprobj_pt;

	spc=0;
	sprobj_pt=sprobj_top;
	while(sprobj_pt){
		next_pt = sprobj_pt->next;
		memfree((void**)&sprobj_pt);
		(void *)sprobj_pt=NULL;
		sprobj_pt=next_pt;
#if	DEBUG_MODE==1
		spobj_cnt-=1;
		spc++;
#endif
	}
	sprobj_top = NULL;
	sprobj_last = NULL;
}


/*===================================================================
 *　スプライトオブジェクトに処理を付随させます
 *　登録後関数がスプライトにリンクされます
 *	登録する関数の型は void (*func_adr)(SPRITE_OBJECT *sprobj_pt) の型で宣言
 *
 * in : SPRITE_OBJECT *	スプライトオブジェクトのポインタ
 *		void *func_adr	関数のアドレス
 *
 * out: void
 *
 *=================================================================*/
#ifdef SPR_BETSUSYORI
void sprobj_func_set( SPRITE_OBJECT *sprobj_pt,void *func_adr )
{
	sprobj_pt->func = func_adr;
}

#endif
/*===================================================================
 *　スプライトオブジェクトに付随している処理を切り放します
 *
 * in : SPRITE_OBJECT *	スプライトオブジェクトのポインタ
 *
 * out: void
 *
 *=================================================================*/
#ifdef SPR_BETSUSYORI
void sprobj_func_end( SPRITE_OBJECT *sprobj_pt )
{
	sprobj_pt->func = NULL;
}
#endif

/*===================================================================
 *　スプライトのオブジェクトをＰＵＴします
 *　（ＯＴに登録するだけです）
 *
 * in : void
 * out: void
 *
 *=================================================================*/
void sprobj_draw(void)
{
	register SPRITE_OBJECT *sprobj_pt;
	register u_long attribute;
	register short ofsx,ofsy;

	GsSPRITE spr_hnd;

#if	DEBUG_MODE==1
	register u_short spr_cnt;
	spr_cnt = 0;
#endif

	sprobj_pt = sprobj_top;	/*スプライトＯＢＪバッファのトップポインタ*/

	while(sprobj_pt != NULL){
		attribute = sprobj_pt->attribute;
		if(!(attribute & GsDOFF)){		/*表示ＯＮ？ＯＦＦ？*/
			spr_hnd.attribute =	attribute;	/*属性*/

			spr_hnd.x	= sprobj_pt->x;	/*Ｘ座標*/
			spr_hnd.y	= sprobj_pt->y;	/*Ｙ座標*/
			spr_hnd.mx	= sprobj_pt->mx;	/*ＭＸ座標*/
			spr_hnd.my	= sprobj_pt->my;	/*ＭＹ座標*/
			spr_hnd.w	= sprobj_pt->w;	/*横幅*/
			spr_hnd.h	= sprobj_pt->h;	/*縦幅*/

#ifdef dsss
			if(attribute & GsCLUT4){			/*４Ｂｉｔ？*/
				spr_hnd.tpage = GetTPage(0,0,sprobj_pt->u,sprobj_pt->v);	/*テクスチャページ*/
				spr_hnd.u	=	sprobj_pt->u%64;	/*ページオフセットＸ*/
			}
			else	if(attribute & GsCLUT8){		/*４Ｂｉｔ？*/
				spr_hnd.tpage = GetTPage(1,1,sprobj_pt->u,sprobj_pt->v);	/*テクスチャページ*/
				spr_hnd.u	=	sprobj_pt->u%64;	/*ページオフセットＸ*/
			}
			else	if(attribute & GsCLUTD){		/*４Ｂｉｔ？*/
				spr_hnd.tpage = GetTPage(2,1,sprobj_pt->u,sprobj_pt->v);	/*テクスチャページ*/
				spr_hnd.u	=	sprobj_pt->u%64;	/*ページオフセットＸ*/
			}

			spr_hnd.tpage = GetTPage(2,1,sprobj_pt->u,sprobj_pt->v);	/*テクスチャページ*/
			spr_hnd.u	=	sprobj_pt->u%64;	/*ページオフセットＸ*/
			spr_hnd.v	=	sprobj_pt->v%256;	/*ページオフセットＹ*/
#endif

			spr_hnd.tpage = sprobj_pt->tpage;
			spr_hnd.u	=	sprobj_pt->u;	/*ページオフセットＸ*/
			spr_hnd.v	=	sprobj_pt->v;	/*ページオフセットＹ*/

			spr_hnd.cx	= sprobj_pt->cx;		/*ＣＵＬＴアドレスＸ*/
			spr_hnd.cy	= sprobj_pt->cy;		/*ＣＵＬＴアドレスＹ*/

			/*輝度値*/
			spr_hnd.r	= sprobj_pt->r;
			spr_hnd.g	= sprobj_pt->g;
			spr_hnd.b	= sprobj_pt->b;

			/*属性をみて拡大縮小回転を使うか*/
			if(attribute & 0x08000000){	/********回転拡大は無し********/
/*--------------------------------------------------------------------*/
				/**ＧＳＳＰＲＩＴＥ(Fast,Flip)**/
				/*ＯＴへ登録する*/
				if(attribute & (GsRETH | GsRETV)){
					/*反転あり*/
					GsSortFlipSprite(&spr_hnd,&ot[actframe],sprobj_pt->pri);
				}
				else{
					/*反転無し*/
					GsSortFastSprite(&spr_hnd,&ot[actframe],sprobj_pt->pri);
				}
			}
			else{	/********回転拡大あり********/
/*--------------------------------------------------------------------*/
				/**ＧＳＳＰＲＩＴＥ(Sort)**/
				spr_hnd.scalex = sprobj_pt->scalex;	/*スケール値Ｘ*/
				spr_hnd.scaley = sprobj_pt->scaley;	/*スケール値Ｙ*/
				spr_hnd.rotate = sprobj_pt->rotate;	/*回転角*/

				/*ＯＴへ登録する*/
				GsSortSprite( &spr_hnd, &ot[actframe], sprobj_pt->pri);
			}
#if	DEBUG_MODE==1
	spr_cnt++;	/*testtest*/
#endif
		}
		sprobj_pt = sprobj_pt->next;				/*sprobjを次へ*/
	}
#ifdef	DEBUG_FONT
	FntPrint(dbg_flg.fnt[0],"SPRITE=%d\n",spr_cnt);
#endif
}



/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
/*=================================================================================*/
#if 1
/* /* 構造体 */
/* struct _POLY_LST{
/* 	u_long attribute;			/* 属性 */
/* 	u_short pri;				/* 表示優先度 */
/* 	u_short type;				/* POLY_??? プリミティブの種類 */
/* 	void *poly;					/* POLY_??? プリミティブ本体のポインタ */
/* 	struct _POLY_LST *before;	/* 前のリストへのポインタ */
/* 	struct _POLY_LST *next;		/* 次のリストへのポインタ */
/* };
/* typedef struct _POLY_LST POLY_LST;
*/

POLY_LST *polylst_top;
POLY_LST *polylst_last;

#if	DEBUG_MODE==1
int	ply_cnt;
#endif

long poly_size[]=
{
	sizeof(POLY_LST)+sizeof(POLY_F3 ),	/*フラット３角形プリミティブ*/
	sizeof(POLY_LST)+sizeof(POLY_F4 ),	/*フラット４角形プリミティブ*/
	sizeof(POLY_LST)+sizeof(POLY_G3 ),	/*グーローシェーディング３角形プリミティブ*/
	sizeof(POLY_LST)+sizeof(POLY_G4 ),	/*グーローシェーディング４角形プリミティブ*/
	sizeof(POLY_LST)+sizeof(POLY_FT3),	/*フラットテクスチャマップ３角形プリミティブ*/
	sizeof(POLY_LST)+sizeof(POLY_FT4),	/*フラットテクスチャマップ４角形プリミティブ*/
	sizeof(POLY_LST)+sizeof(POLY_GT3),	/*グーローテクスチャマップ３角形プリミティブ*/
	sizeof(POLY_LST)+sizeof(POLY_GT4),	/*グーローテクスチャマップ４角形プリミティブ*/

	sizeof(POLY_LST)+sizeof(LINE_F2),	/*フラット非連結直線*/
	sizeof(POLY_LST)+sizeof(LINE_F3),	/*フラット１連結直線*/
	sizeof(POLY_LST)+sizeof(LINE_F4),	/*フラット２連結直線*/
	sizeof(POLY_LST)+sizeof(LINE_G2),	/*グーロー非連結直線*/
	sizeof(POLY_LST)+sizeof(LINE_G3),	/*グーロー１連結直線*/
	sizeof(POLY_LST)+sizeof(LINE_G4),	/*グーロー２連結直線*/
	sizeof(POLY_LST)+sizeof(GsBOXF),	/*ＢＯＸ*/
};

void (*set_poly[])(void *pt)=
{
	(void *)SetPolyF3,	/*フラットシェーディング３角形プリミティブを初期化*/
	(void *)SetPolyF4,	/*フラットシェーディング４角形プリミティブを初期化*/
	(void *)SetPolyG3,	/*グーローシェーディング３角形プリミティブを初期化*/
	(void *)SetPolyG4,	/*グーローシェーディング４角形プリミティブを初期化*/
	(void *)SetPolyFT3,	/*フラットテクスチャ３角形プリミティブを初期化*/
	(void *)SetPolyFT4,	/*フラットテクスチャ４角形プリミティブを初期化*/
	(void *)SetPolyGT3,	/*グーローテクスチャ３角形プリミティブを初期化*/
	(void *)SetPolyGT4,	/*グーローテクスチャ４角形プリミティブを初期化*/

	(void *)SetLineF2,	/*フラット非連結直線*/
	(void *)SetLineF3,	/*フラット１連結直線*/
	(void *)SetLineF4,	/*フラット２連結直線*/
	(void *)SetLineG2,	/*グーロー非連結直線*/
	(void *)SetLineG3,	/*グーロー１連結直線*/
	(void *)SetLineG4,	/*グーロー２連結直線*/
	(void *)GsSortBoxFill,	/*ＢＯＸ*/
};


/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

/*===================================================================
 *　POLYを初期化します
 *
 * in : void
 * out: void
 *
 *=================================================================*/
void poly_init(void)
{
	polylst_top = polylst_last = NULL;
#if	DEBUG_MODE==1
	ply_cnt = 0;
#endif
}


/*===================================================================
 *	POLY_??? プリミティブをエントリーします
 *
 * in : void
 *
 * out: POLY_???のポインタ
 *
 *=================================================================*/
/*POLY_F3		フラット３角形プリミティブ*/
POLY_F3 *poly_f3_make(void)
{
	return (POLY_F3 *)poly_make(0);
}

/*POLY_F4 	フラット４角形プリミティブ*/
POLY_F4 *poly_f4_make(void)
{
	return (POLY_F4 *)poly_make(1);
}

/*POLY_G3 	グーローシェーディング３角形プリミティブ*/
POLY_G3 *poly_g3_make(void)
{
	return (POLY_G3 *)poly_make(2);
}

/*POLY_G4 	グーローシェーディング４角形プリミティブ*/
POLY_G4 *poly_g4_make(void)
{
	return (POLY_G4 *)poly_make(3);
}

/*POLY_FT3	フラットテクスチャマップ３角形プリミティブ*/
POLY_FT3 *poly_ft3_make(void)
{
	return (POLY_FT3 *)poly_make(4);
}

/*POLY_FT4	フラットテクスチャマップ４角形プリミティブ*/
POLY_FT4 *poly_ft4_make(void)
{
	return (POLY_FT4 *)poly_make(5);
}

/*POLY_GT3	グーローテクスチャマップ３角形プリミティブ*/
POLY_GT3 *poly_gt3_make(void)
{
	return (POLY_GT3 *)poly_make(6);
}

/*POLY_GT4	グーローテクスチャマップ４角形プリミティブ*/
POLY_GT4 *poly_gt4_make(void)
{
	return (POLY_GT4 *)poly_make(7);
}

LINE_F2 *line_f2_make(void)
{
	return (LINE_F2 *)poly_make(8);
}

LINE_F3 *line_f3_make(void)
{
	return (LINE_F3 *)poly_make(9);
}

LINE_F4 *line_f4_make(void)
{
	return (LINE_F4 *)poly_make(10);
}

LINE_G2 *line_g2_make(void)
{
	return (LINE_G2 *)poly_make(11);
}

LINE_G3 *line_g3_make(void)
{
	return (LINE_G3 *)poly_make(12);
}

LINE_G4 *line_g4_make(void)
{
	return (LINE_G4 *)poly_make(13);
}

GsBOXF *box_make(void)
{
	return (GsBOXF *)poly_make(14);
}


/*===================================================================
 *	POLY_??? プリミティブをエントリーします
 *
 * in : u_short type POLY_??? プリミティブのタイプ
 *						 0:POLY_F3	フラット３角形プリミティブ
 *						 1:POLY_F4 	フラット４角形プリミティブ
 *						 2:POLY_G3 	グーローシェーディング３角形プリミティブ
 *						 3:POLY_G4 	グーローシェーディング４角形プリミティブ
 *						 4:POLY_FT3	フラットテクスチャマップ３角形プリミティブ
 *						 5:POLY_FT4	フラットテクスチャマップ４角形プリミティブ
 *						 6:POLY_GT3	グーローテクスチャマップ３角形プリミティブ
 *						 7:POLY_GT4	グーローテクスチャマップ４角形プリミティブ
 *						 8:LINE_F2	
 *						 9:LINE_F3	
 *						10:LINE_F4	
 *						11:LINE_G2	
 *						12:LINE_G3	
 *						13:LINE_G4	
 *
 * out: void * POLY_???のポインタ(キャストしてください)
 *
 *=================================================================*/
void *poly_make(u_short type)
{
 POLY_LST *polylst_pt;

	polylst_pt = NULL;
	if(NULL != (polylst_pt = (POLY_LST *)memalloc(poly_size[type], (void**)&polylst_pt))){
		polylst_pt->poly = (void *)((u_long)polylst_pt + sizeof(POLY_LST));/*エントリー*/
		polylst_pt->type = type;	/*種類*/

		if(type!=14)	set_poly[type](polylst_pt->poly);	/*初期化*/

		/*リストへつなぐ*/
		if(polylst_top == NULL){
			/*初めて*/
			polylst_top = polylst_pt;
			polylst_pt->before = NULL;
			polylst_pt->next = NULL;
		}
		else{
			/*２つめ以降*/
			polylst_last->next = polylst_pt;
			polylst_pt->before = polylst_last;
			polylst_pt->next = NULL;
		}
		polylst_last = polylst_pt;
#if	DEBUG_MODE==1
	ply_cnt++;
#endif
		return polylst_pt->poly;
	}
	return NULL;
}


/*===================================================================
 *	POLY_??? プリミティブをエントリーからはずします
 *
 * in : void * POLY_??? プリミティブのポインタ
 * out: void
 *
 *=================================================================*/
void poly_kill(void *poly_pt)
{
	//register POLY_LST *polylst_pt;
	POLY_LST *polylst_pt;
	register POLY_LST *before_pt;
	register POLY_LST *next_pt;

	if(poly_pt != NULL){
		polylst_pt = get_polylst((void *)poly_pt);
		/*リスト列からはずす*/
		before_pt = polylst_pt->before;
		next_pt = polylst_pt->next;
		if( before_pt == NULL && next_pt == NULL ){
			/*自分しかいない*/
			polylst_top = polylst_last = NULL;
		}
		else{
			if( before_pt == NULL )	polylst_top = next_pt;
			else					before_pt->next = next_pt;

			if( next_pt == NULL )	polylst_last = before_pt;
			else					next_pt->before = before_pt;
		}
		memfree((void**)&polylst_pt);
		poly_pt = NULL;
#if	DEBUG_MODE==1
	ply_cnt--;
#endif
	}
}


/*===================================================================
 *　POLY_?? プリミティブのポインタからリストのポインタを求めます
 *
 * in : void *POLY_???	プリミティブのポインタ
 * out: POLY_LST *		リストのポインタ
 *
 *=================================================================*/
POLY_LST *get_polylst(void *poly_pt)
{
	return (POLY_LST *)((u_long)poly_pt - sizeof(POLY_LST));/*リスト位置*/
}

//	SetShadeTex( poly,(attribute>>6)&0x00000001 );
//						/*半透明*/
//	SetSemiTrans( poly,((attr|attribute)>>30)&0x00000001 );

// added by kawakami 23rd Dec. '98 
/*======================================================
	poly_lstのポリゴンのプライオリティを設定する
		in:		void	*primP	ポリのポインタ
				u_short	priN	プライオリティ番号
		out:	void
======================================================*/
//void	poly_priset(void *primP, u_short priN) {
//	POLY_LST	*polyP;
//	
//	polyP = get_polylst(primP);
//	polyP->pri = priN;
//}
void	poly_priset(void *poly_pt, u_short pri) {
	get_polylst((void *)poly_pt)->pri = pri;
}

void poly_don(void *poly_pt)
{
	get_polylst((void *)poly_pt)->attribute&=0x7fffffff;

}

void poly_doff(void *poly_pt)
{
	get_polylst((void *)poly_pt)->attribute|=0x80000000;
}

/*===================================================================
 *　POLY_?T4 プリミティブのＸＹセット
 *
 * in : void
 * out: void
 *
 *=================================================================*/
void poly_xyset(void *poly_pt,short x,short y,short w,short h)
{
	if(poly_pt != NULL){
		switch(get_polylst((void *)poly_pt)->type){
			case  1:
				poly_f4_xyset(poly_pt,x,y,w,h);
			break;
			case  3:
				poly_g4_xyset(poly_pt,x,y,w,h);
			break;
			case  5:
				poly_ft4_xyset(poly_pt,x,y,w,h);
			break;
			case  7:
				poly_gt4_xyset(poly_pt,x,y,w,h);
			break;

			//	ここからＬＩＮＥ
			case  10:
				line_f4_xyset(poly_pt,x,y,w,h);
			break;
			case  13:
				line_g4_xyset(poly_pt,x,y,w,h);
			break;
			case  14:
				box_xyset(poly_pt,x,y,w,h);
			break;
		}
	}
}

void poly_uvset(void *poly_pt,short u,short v,short w,short h)
{
	if(poly_pt != NULL){
		switch(get_polylst((void *)poly_pt)->type){
			case  5:
				poly_ft4_uvset(poly_pt,u,v,w,h);
			break;
			case  7:
				poly_gt4_uvset(poly_pt,u,v,w,h);
			break;
		}
	}
}

void poly_uv4set(void *poly_pt,short u0,short v0,short u1,short v1,short u2,short v2,short u3,short v3)
{
	if(poly_pt != NULL){
		switch(get_polylst((void *)poly_pt)->type){
			case  5:
				poly_ft4_uv4set(poly_pt,u0,v0,u1,v1,u2,v2,u3,v3);
			break;
			case  7:
				poly_gt4_uv4set(poly_pt,u0,v0,u1,v1,u2,v2,u3,v3);
			break;
		}
	}
}

void poly_rgbset(void *poly_pt,short r,short g,short b)
{
	if(poly_pt != NULL){
		switch(get_polylst((void *)poly_pt)->type){
			case  1:
				poly_f4_rgbset(poly_pt,r,g,b);
			break;
			case  3:
				poly_g4_rgbset(poly_pt,r,g,b);
			break;
			case  5:
				poly_ft4_rgbset(poly_pt,r,g,b);
			break;
			case  7:
				poly_gt4_rgbset(poly_pt,r,g,b);
			break;

			//	ここからＬＩＮＥ
			case  8:
				line_f2_rgbset(poly_pt,r,g,b);
			break;
			case  9:
				line_f3_rgbset(poly_pt,r,g,b);
			break;
			case  10:
				line_f4_rgbset(poly_pt,r,g,b);
			break;
			case  11:
				line_g2_rgbset(poly_pt,r,g,b);
			break;
			case  12:
				line_g3_rgbset(poly_pt,r,g,b);
			break;
			case  13:
				line_g4_rgbset(poly_pt,r,g,b);
			break;
			case  14:
				box_rgbset(poly_pt,r,g,b);
			break;
		}
	}
}




void poly_ft4_xyset(POLY_FT4 *poly_pt,short x,short y,short w,short h)
{
	poly_pt->x0=x;
	poly_pt->y0=y;

	poly_pt->x1=x+w;
	poly_pt->y1=y;

	poly_pt->x2=x;
	poly_pt->y2=y+h;

	poly_pt->x3=x+w;
	poly_pt->y3=y+h;
}

void line_f4_xyset(LINE_F4 *poly_pt,short x,short y,short w,short h)
{
	poly_pt->x0=x;
	poly_pt->y0=y;

	poly_pt->x1=x+w;
	poly_pt->y1=y;

	poly_pt->x2=x;
	poly_pt->y2=y+h;

	poly_pt->x3=x+w;
	poly_pt->y3=y+h;

}

void line_g4_xyset(LINE_G4 *poly_pt,short x,short y,short w,short h)
{
	poly_pt->x0=x;
	poly_pt->y0=y;

	poly_pt->x1=x+w;
	poly_pt->y1=y;

	poly_pt->x2=x;
	poly_pt->y2=y+h;

	poly_pt->x3=x+w;
	poly_pt->y3=y+h;

}

void poly_g4_xyset(POLY_G4 *poly_pt,short x,short y,short w,short h)
{
	poly_pt->x0=x;
	poly_pt->y0=y;

	poly_pt->x1=x+w;
	poly_pt->y1=y;

	poly_pt->x2=x;
	poly_pt->y2=y+h;

	poly_pt->x3=x+w;
	poly_pt->y3=y+h;

}

void box_xyset(GsBOXF *poly_pt,short x,short y,short w,short h)
{
	poly_pt->x=x;
	poly_pt->y=y;

	poly_pt->w=w;
	poly_pt->h=h;

}


void poly_gt4_xyset(POLY_GT4 *poly_pt,short x,short y,short w,short h)
{
	poly_pt->x0=x;
	poly_pt->y0=y;

	poly_pt->x1=x+w;
	poly_pt->y1=y;

	poly_pt->x2=x;
	poly_pt->y2=y+h;

	poly_pt->x3=x+w;
	poly_pt->y3=y+h;

}

void poly_gt4_xy4set(POLY_GT4 *poly_pt,short x0,short y0,short x1,short y1,short x2,short y2,short x3,short y3)
{
	poly_pt->x0=x0;
	poly_pt->y0=y0;

	poly_pt->x1=x1;
	poly_pt->y1=y1;

	poly_pt->x2=x2;
	poly_pt->y2=y2;

	poly_pt->x3=x3;
	poly_pt->y3=y3;

}

void poly_ft4_xy4set(POLY_FT4 *poly_pt,short x0,short y0,short x1,short y1,short x2,short y2,short x3,short y3)
{
	poly_pt->x0=x0;
	poly_pt->y0=y0;

	poly_pt->x1=x1;
	poly_pt->y1=y1;

	poly_pt->x2=x2;
	poly_pt->y2=y2;

	poly_pt->x3=x3;
	poly_pt->y3=y3;
}


void poly_f4_xyset(POLY_F4 *poly_pt,short x,short y,short w,short h)
{
	poly_pt->x0=x;
	poly_pt->y0=y;

	poly_pt->x1=x+w;
	poly_pt->y1=y;

	poly_pt->x2=x;
	poly_pt->y2=y+h;

	poly_pt->x3=x+w;
	poly_pt->y3=y+h;
}



void box_rgbset(GsBOXF *poly_pt,short r,short g,short b)
{
	poly_pt->r=r;
	poly_pt->g=g;
	poly_pt->b=b;

}


void poly_ft4_rgbset(POLY_FT4 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;
}

void poly_f4_rgbset(POLY_F4 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;
}

void poly_f4_rgb_ld(POLY_F4 *poly_pt)
{
	if(poly_pt->r0<110)	poly_pt->b0=poly_pt->g0=poly_pt->r0=128;

	if(get_polylst((void *)poly_pt)->work[3]){
		if(poly_pt->r0<240)	poly_pt->b0=poly_pt->g0=poly_pt->r0=(poly_pt->r0+8);
		else					get_polylst((void *)poly_pt)->work[3]=(get_polylst((void *)poly_pt)->work[3]+1)%2;
	}
	else{
		if(poly_pt->r0>128)	poly_pt->b0=poly_pt->g0=poly_pt->r0=poly_pt->r0-8;
		else					get_polylst((void *)poly_pt)->work[3]=(get_polylst((void *)poly_pt)->work[3]+1)%2;
	}
}



void poly_gt4_rgbset(POLY_GT4 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

	poly_pt->r1=r;
	poly_pt->g1=g;
	poly_pt->b1=b;

	poly_pt->r2=r;
	poly_pt->g2=g;
	poly_pt->b2=b;

	poly_pt->r3=r;
	poly_pt->g3=g;
	poly_pt->b3=b;

}

void poly_g4_rgbset(POLY_G4 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

	poly_pt->r1=r;
	poly_pt->g1=g;
	poly_pt->b1=b;

	poly_pt->r2=r;
	poly_pt->g2=g;
	poly_pt->b2=b;

	poly_pt->r3=r;
	poly_pt->g3=g;
	poly_pt->b3=b;

}

void line_f2_rgbset(LINE_F2 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

}

void line_f3_rgbset(LINE_F3 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

}

void line_f4_rgbset(LINE_F4 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

}



void line_g2_rgbset(LINE_G2 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

	poly_pt->r1=r;
	poly_pt->g1=g;
	poly_pt->b1=b;

}

void line_g3_rgbset(LINE_G3 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

	poly_pt->r1=r;
	poly_pt->g1=g;
	poly_pt->b1=b;

//	poly_pt->r2=r;
//	poly_pt->g2=g;
//	poly_pt->b2=b;

//	poly_pt->r3=r;
//	poly_pt->g3=g;
//	poly_pt->b3=b;

}

void line_g4_rgbset(LINE_G4 *poly_pt,short r,short g,short b)
{
	poly_pt->r0=r;
	poly_pt->g0=g;
	poly_pt->b0=b;

	poly_pt->r1=r;
	poly_pt->g1=g;
	poly_pt->b1=b;

	poly_pt->r2=r;
	poly_pt->g2=g;
	poly_pt->b2=b;

	poly_pt->r3=r;
	poly_pt->g3=g;
	poly_pt->b3=b;

}

void waku_f3set(LINE_F3 *_pt0,LINE_F3 *_pt1,LINE_F3 *_pt2,LINE_F3 *_pt3,int x,int y,int w,int h)
{

	_pt0->x0=x;
	_pt0->y0=y;
	_pt0->x1=x+w;
	_pt0->y1=y;
	_pt0->x2=x+w;
	_pt0->y2=y+h;

	_pt1->x0=x;
	_pt1->y0=y;
	_pt1->x1=x;
	_pt1->y1=y+h;
	_pt1->x2=x+w;
	_pt1->y2=y+h;

	_pt2->x0=x-1;
	_pt2->y0=y-1;
	_pt2->x1=x+w+1;
	_pt2->y1=y-1;
	_pt2->x2=x+w+1;
	_pt2->y2=y+h+1;

	_pt3->x0=x-1;
	_pt3->y0=y-1;
	_pt3->x1=x-1;
	_pt3->y1=y+h+1;
	_pt3->x2=x+w+1;
	_pt3->y2=y+h+1;

}


/*===================================================================
 *　POLY_GT4 プリミティブの初期設定
 *
 * in : POLY_GT4 *poly_pt	プリミティブポインタ
 *		short cx			ＣＬＵＴ　Ｘ
 *		short cy			ＣＬＵＴ　Ｙ
 *		short u				テクスチャ　Ｕ
 *		short v				テクスチャ　Ｖ
 *		short i				半透明	0:OFF 1:ON
 *		short d				シェーディング	0:ON 1:OFF
 *		short tm			ＣＬＵＴモード 0:4bit 1:8bit 2:16bit 3:24bit
 * out: void
 *
 *=================================================================*/
void poly_gt4_fset(POLY_GT4 *poly_pt,short cx,short cy,short u,short v,short i,short d,short tm)
{
	SetSemiTrans(poly_pt,i);	// 半透明
	SetShadeTex(poly_pt,d);		// ｼｪｰﾄﾞ

	poly_pt->tpage=GetTPage(tm,0,u,v);	/* 本番	*/
	poly_pt->clut=GetClut(cx,cy);

}

void poly_ft4_fset(POLY_FT4 *poly_pt,short cx,short cy,short u,short v,short i,short dummy,short tm)
{
	SetSemiTrans(poly_pt,i);	// 半透明

	poly_pt->tpage=GetTPage(tm,0,u,v);	/* 本番	*/
	poly_pt->clut=GetClut(cx,cy);
}



void poly_ft4_uvset(POLY_FT4 *poly_pt,short u,short v,short w,short h)
{
	if(u+w>255)	w=255-u;
	if(v+h>255)	h=255-v;

	poly_pt->u0=u;
	poly_pt->v0=v;

	poly_pt->u1=u+w;
	poly_pt->v1=v;

	poly_pt->u2=u;
	poly_pt->v2=v+h;

	poly_pt->u3=u+w;
	poly_pt->v3=v+h;

}


void poly_ft4_uv4set(POLY_FT4 *poly_pt,short u0,short v0,short u1,short v1,short u2,short v2,short u3,short v3)
{
	poly_pt->u0=u0;
	poly_pt->v0=v0;

	poly_pt->u1=u1;
	poly_pt->v1=v1;

	poly_pt->u2=u2;
	poly_pt->v2=v2;

	poly_pt->u3=u3;
	poly_pt->v3=v3;

}


void poly_gt4_uvset(POLY_GT4 *poly_pt,short u,short v,short w,short h)
{
	if(u+w>255)	w=255-u;
	if(v+h>255)	h=255-v;

	poly_pt->u0=u;
	poly_pt->v0=v;

	poly_pt->u1=u+w;
	poly_pt->v1=v;

	poly_pt->u2=u;
	poly_pt->v2=v+h;

	poly_pt->u3=u+w;
	poly_pt->v3=v+h;
}

void poly_gt4_uv4set(POLY_GT4 *poly_pt,short u0,short v0,short u1,short v1,short u2,short v2,short u3,short v3)
{
	poly_pt->u0=u0;
	poly_pt->v0=v0;

	poly_pt->u1=u1;
	poly_pt->v1=v1;

	poly_pt->u2=u2;
	poly_pt->v2=v2;

	poly_pt->u3=u3;
	poly_pt->v3=v3;

}

/*===================================================================
 *　POLY_?? プリミティブをＰＵＴします
 *　（ＯＴに登録するだけです）
 *
 * in : void
 * out: void
 *
 *=================================================================*/
void poly_draw(void)
{
	register POLY_LST *polylst_pt;

	polylst_pt = polylst_top;	/*POLY_LSTバッファのトップポインタ*/
	while( polylst_pt != NULL ){
		if( !(polylst_pt->attribute & GsDOFF) ){	/*表示ＯＮ？ＯＦＦ？*/
			/*ＯＴへ登録する*/
			if(polylst_pt->type!=14)
				GsSortPoly( polylst_pt->poly, &ot[actframe], polylst_pt->pri);
			else
				GsSortBoxFill( polylst_pt->poly, &ot[actframe], polylst_pt->pri);	/*ＢＯＸ*/
		}
		polylst_pt = polylst_pt->next;				/*sprobjを次へ*/
	}
#if	DEBUG_MODE==1
	FntPrint(dbg_flg.fnt[0],"POLY=%d\n",ply_cnt);	
#endif
}
#endif



#if	DEBUG_MODE==1
void sp_xytest(SPRITE_OBJECT *sp_pt)
{
	int x,y,sw;

	x=0;
	y=0;
	sw=1;

	sp_pt->x=x;
	sp_pt->y=y;
#ifdef	DEBUG_FONT
	VSync(4);
	dbg_fntset();
#endif

	while(1){
		if(pad_beta & PADL_UP){
			y--;
			sp_pt->y=y;
		}
		if(pad_beta & PADL_DOWN){
			y++;
			sp_pt->y=y;
		}

		if(pad_beta & PADL_LEFT){
			x-=1;
			sp_pt->x=x;
		}
		if(pad_beta & PADL_RIGHT){
			x+=1;
			sp_pt->x=x;
		}

		if(pad_beta & PADR_DOWN){
			break;
		}

#ifdef DEBUG_FONT
//		FntPrint(dbg_flg.fnt[0],"\nX_POS = %d\n",x);
//		FntPrint(dbg_flg.fnt[0],"Y_POS = %d\n\n",y);
#endif
		wait(1);
	}
}
#endif

void f_tim_change(u_short *tim,int px,int py,int cx,int cy)
{	/* ＴＩＭをロード前にＦＢ位置を変更 */
	if	(*tim==0x10) {
		tim[6]=cx;
		tim[7]=cy;
		tim+=((tim[4]&0x0000ffffL)|(tim[5]<<16))/2+4;
		tim[2]=px;
		tim[3]=py;
	}
}


/* ============================================ */
/* f_spritefade                                 */
/* ============================================ */
#define SPRS 100	/* スプライトの数 */
extern SPRITE_OBJECT *sprobj_top;	/*スプライトグループトップ*/
void f_spritefade(int f,int time)
{	/* ＳＰＲのＲＧＢによるフェード f:0..out 1..in*/
	int i,j,cn,r[SPRS],g[SPRS],b[SPRS];
	SPRITE_OBJECT *sprobj_pt;

	/* 初期値を保存 */
	sprobj_pt=sprobj_top;
	for (i=0;i<SPRS && sprobj_pt!=0;i++) {
		r[i]=sprobj_pt->r;
		g[i]=sprobj_pt->g;
		b[i]=sprobj_pt->b;
		sprobj_pt=sprobj_pt->next;
	}
	/* フェード */
	for	(j=0;j<=time;j++) {
		sprobj_pt=sprobj_top;
		if (f) cn=256*j/time; else cn=256*(time-j)/time;
		for (i=0;i<SPRS && sprobj_pt!=0;i++) {
			sprobj_pt->r=cn*r[i]/256;
			sprobj_pt->g=cn*g[i]/256;
			sprobj_pt->b=cn*b[i]/256;
			sprobj_pt=sprobj_pt->next;
		}
		wait(1);
	}
}


/* ============================================ */
/* s_sprite_off/on                              */
/* ============================================ */
static int *sprflg;					/* 前画面で使っているＳＰＲ個数 */
void s_sprite_off(void)
{	/* ＳＰＲ描画一時的ＯＦＦ */
	int i;
	SPRITE_OBJECT *sprobj_pt;

	sprflg=memalloc(sizeof(int)*SPRS, (void**)&sprflg);
	sprobj_pt=sprobj_top;
	for (i=0;i<SPRS && sprobj_pt!=0;i++) {
		if	(sprobj_pt->attribute&GsDOFF) sprflg[i]=0;
		else {	/* 描画中のもののみ */
			sprflg[i]=1;
			sprobj_pt->attribute|=GsDOFF;
		}
		sprobj_pt=sprobj_pt->next;
	}
}

void s_sprite_on(void)
{	/* ＳＰＲ描画再開 */
	int i;
	SPRITE_OBJECT *sprobj_pt;

	sprobj_pt=sprobj_top;
	for (i=0;i<SPRS && sprobj_pt!=0;i++) {
		if	(sprflg[i]) sprobj_pt->attribute&=GsDOFF^-1;
		sprobj_pt=sprobj_pt->next;
	}
	memfree((void**)&sprflg);
}


