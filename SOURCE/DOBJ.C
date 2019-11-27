/*=============================================================
 *	３Ｄオブジェクトを処理します
 *
 *=============================================================*/


#include "common.h"
#include "work.h"

/***************************************************************
 *
 *	マニュアルには
 *　	GsInitObjTable2()
 *		GsCreateNewObj2()
 *		GsRemoveObj2()
 *		GsSearchObjByID2()
 *  	GsSearchTmdByID()
 *  	GsSetTodFrame2()
 *  	GsSetTodPacket2()
 *	が用意されてると、書いたーるけど、どこにもそんなもんが、見当たらんかった。
 *	それで、TODデータを処理するプログラムの例がサンプルプログラムの
 *	PSX\SAMPLE\GRAPHICS\TODの下にあり、これを元に作れと書いてあったので、
 *	そっから、引っ張って来て、そのままでは使いにくいので、いじくったのがこれです。
 *
 ***************************************************************/



/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/
#define DOBJ_MAX 100		/* Max Objects */
                            /* ３Dのモデルは論理的なオブジェクトに */
                            /* 分けられるこの最大数 を定義する */

extern MATRIX GsIDMATRIX;	/* Unit Matrix /* 単位行列 */

extern GsF_LIGHT pslt[3];		/* 光源×３個 */


/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/

/* 構造体 */
struct _DOBJ_LST{
	u_long id;					/* id番号 */
	GsDOBJ2 *dobj;				/* オブジェクト本体のポインタ */
	struct _DOBJ_LST *before;	/* 前のリストへのポインタ */
	struct _DOBJ_LST *next;		/* 次のリストへのポインタ */
};
typedef struct _DOBJ_LST DOBJ_LST;

#ifdef OBJ_ALLOC
#else
DOBJ_LST dobj_lst[DOBJ_MAX];	/* オブジェクトリスト */
GsDOBJ2 dobj2_hnd[DOBJ_MAX];	/* オブジェクトハンドラ objの数だけ必要 */
GsCOORDINATE2 dcoord[DOBJ_MAX];	/* オブジェクトごとの座標系 */
GsCOORD2PARAM dparam[DOBJ_MAX];	/* ローカル座標のパラメータ領域 */
#endif

DOBJ_LST *dobjlst_top;
DOBJ_LST *dobjlst_last;

#define	TOD_ANIM_MAX 16
TOD_ANIM tod_anim[TOD_ANIM_MAX];

#ifdef	DEBUG_FLAG
int	obj_cnt;
#endif

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/


/*===================================================================
 *　DOBJ2を初期化します	（GsInitObjTable2()のようなもん）
 *
 * in:
 *		void
 * out:
 *		void
 *
 *=================================================================*/
void dobj_init(void)
{
 u_short dobj_cnt;

	dobj_anim_init();
	dobjlst_top = dobjlst_last = NULL;
#ifdef OBJ_ALLOC
#else
	for(dobj_cnt = 0; dobj_cnt < DOBJ_MAX; dobj_cnt++ )
	{
		dobj_lst[dobj_cnt].dobj = NULL;
	}
#endif
#ifdef	DEBUG_FLAG
	obj_cnt = 0;
#endif
}


#ifdef OBJ_ALLOC
/*===================================================================
 *　DOBJバッファのメモリを割り当てます
 *
 * in:
 *		void
 * out:
 *		DOBJ_LST * スプライトオブジェクトのポインタ
 *
 *=================================================================*/
void *memalloc2(size_t s)
{
 void *adr;

	adr = (void *)malloc2(s);
	if(adr == NULL)
	{
		while(1)
		{
			FntPrint("malloc2 err!!\n");
			FntPrint("malloc2 err!!\n");
			FntPrint("malloc2 err!!\n");
			wait(1);
		}
	}
	mem_cnt++;
	return adr;
}


DOBJ_LST *dalloc(void)
{
	return (DOBJ_LST *)memalloc2(
						sizeof(DOBJ_LST)+
						sizeof(GsDOBJ2)+
						sizeof(GsCOORDINATE2)+
						sizeof(GsCOORD2PARAM));
}
#endif

/*===================================================================
 *	３次元オブジェクトハンドラ GsDOBJ2をエントリーします
 *	メンバのcoord2に座標系もセットします	（GsCreateNewObj2()のようなもん）
 *
 * in:
 *		u_long id オブジェクトid
 * out:
 *		GsDOBJ2 * オブジェクトハンドラのポインタ
 *
 *=================================================================*/
#ifdef OBJ_ALLOC
GsDOBJ2 *dobj_make(u_long id)
{
 DOBJ_LST *dobjlst_pt;
 GsDOBJ2 *dobj_pt;

	if(NULL != (dobjlst_pt = dalloc()))
	{
		dobjlst_pt->id = id;
		dobj_pt = dobjlst_pt->dobj = (GsDOBJ2 *)((u_long)dobjlst_pt + sizeof(DOBJ_LST));/*エントリー*/
		dobj_pt->id = id;
		dobj_pt->attribute = 0;
		dobj_pt->coord2 = (GsCOORDINATE2 *)((u_long)dobj_pt + sizeof(GsDOBJ2));
		dobj_pt->coord2->param = (GsCOORD2PARAM *)((u_long)dobj_pt->coord2 + sizeof(GsCOORDINATE2));
		GsInitCoordinate2(WORLD,dobj_pt->coord2);
		dobj_pt->coord2->param->scale.vx = ONE;
		dobj_pt->coord2->param->scale.vy = ONE;
		dobj_pt->coord2->param->scale.vz = ONE;
		dobj_pt->coord2->param->rotate.vx = 0;
		dobj_pt->coord2->param->rotate.vy = 0;
		dobj_pt->coord2->param->rotate.vz = 0;
		dobj_pt->coord2->param->trans.vx = 0;
		dobj_pt->coord2->param->trans.vy = 0;
		dobj_pt->coord2->param->trans.vz = 0;
		dobj_pt->tmd = NULL;
		/*リストへつなぐ*/
		if(dobjlst_top == NULL)
		{
			/*初めて*/
			dobjlst_top = dobjlst_pt;
			dobjlst_pt->before = NULL;
			dobjlst_pt->next = NULL;
		}
		else
		{
			/*２つめ以降*/
			dobjlst_last->next = dobjlst_pt;
			dobjlst_pt->before = dobjlst_last;
			dobjlst_pt->next = NULL;
		}
		dobjlst_last = dobjlst_pt;
#ifdef	DEBUG_FLAG
	obj_cnt++;
#endif
		return dobj_pt;
	}
	return NULL;
}

#else
GsDOBJ2 *dobj_make(u_long id)
{
 u_short dobj_cnt;
 GsDOBJ2 *dobj_pt;

	dobj_cnt = 0;
	while(dobj_cnt < DOBJ_MAX)
	{
		if(dobj_lst[dobj_cnt].dobj != NULL)/*使用されているかどうか*/
		{
			dobj_cnt++;
		}
		else
		{
			dobj_lst[dobj_cnt].id = id;
			dobj_pt = dobj_lst[dobj_cnt].dobj = &dobj2_hnd[dobj_cnt];/*エントリー*/
			dobj_pt->attribute = 0;
			dobj_pt->coord2 = &dcoord[dobj_cnt];
			dobj_pt->coord2->param = &dparam[dobj_cnt];
			GsInitCoordinate2(WORLD,dobj_pt->coord2);
/*			dobj_pt->coord2->flg = 0;
/*			dobj_pt->coord2->coord.t[0] = 0;
/*			dobj_pt->coord2->coord.t[1] = 0;
/*			dobj_pt->coord2->coord.t[2] = 0;
/*			dobj_pt->coord2->super = 0;*/
			dobj_pt->coord2->param->scale.vx = ONE;
			dobj_pt->coord2->param->scale.vy = ONE;
			dobj_pt->coord2->param->scale.vz = ONE;
			dobj_pt->coord2->param->rotate.vx = 0;
			dobj_pt->coord2->param->rotate.vy = 0;
			dobj_pt->coord2->param->rotate.vz = 0;
			dobj_pt->coord2->param->trans.vx = 0;
			dobj_pt->coord2->param->trans.vy = 0;
			dobj_pt->coord2->param->trans.vz = 0;
			dobj_pt->tmd = NULL;
			/*リストへつなぐ*/
			if(dobjlst_top == NULL)
			{
				/*初めて*/
				dobjlst_top = &dobj_lst[dobj_cnt];
				dobj_lst[dobj_cnt].before = NULL;
				dobj_lst[dobj_cnt].next = NULL;
			}
			else
			{
				/*２つめ以降*/
				dobjlst_last->next = &dobj_lst[dobj_cnt];
				dobj_lst[dobj_cnt].before = dobjlst_last;
				dobj_lst[dobj_cnt].next = NULL;
			}
			dobjlst_last = &dobj_lst[dobj_cnt];
#ifdef	DEBUG_FLAG
	obj_cnt++;
#endif
			return &dobj2_hnd[dobj_cnt];
		}
	}
	return NULL;
}
#endif


/*===================================================================
 *	３次元オブジェクトハンドラ GsDOBJ2をエントリーからはずします
 *
 * in:
 *		GsDOBJ2 * オブジェクトハンドラのポインタ
 * out:
 *		void
 *
 *=================================================================*/
#ifdef OBJ_ALLOC
void memfree2(void *adr)
{
	if(!mem_cnt)
	{
		while(1)
		{
			FntPrint("free err!!\n");
			FntPrint("free err!!\n");
			FntPrint("free err!!\n");
			wait(1);
		}
	}
	free2(adr);
	mem_cnt--;
}

void dobj_kill(GsDOBJ2 *dobj_pt)
{
 DOBJ_LST *dobjlst_pt;
 DOBJ_LST *before_pt;
 DOBJ_LST *next_pt;

	if(dobj_pt != NULL)
	{
		dobjlst_pt = (DOBJ_LST *)((u_long)dobj_pt - sizeof(DOBJ_LST));/*リスト位置*/
		/*リスト列からはずす*/
		before_pt = dobjlst_pt->before;
		next_pt = dobjlst_pt->next;
		if( before_pt == NULL && next_pt == NULL )
		{
			/*自分しかいない*/
			dobjlst_top = dobjlst_last = NULL;
		}
		else
		{
			if( before_pt == NULL )
			{
				dobjlst_top = next_pt;
			}
			else
			{
				before_pt->next = next_pt;
			}
			if( next_pt == NULL )
			{
				dobjlst_last = before_pt;
			}
			else
			{
				next_pt->before = before_pt;
			}
		}
		memfree2(dobjlst_pt);
#ifdef	DEBUG_FLAG
	obj_cnt--;
#endif
	}
}


#else
void dobj_kill(GsDOBJ2 *dobj_pt)
{
 DOBJ_LST *dobjlst_pt;
 DOBJ_LST *before_pt;
 DOBJ_LST *next_pt;

	if(dobj_pt != NULL)
	{
		dobjlst_pt = dobjlst_top;
		while(dobjlst_pt != NULL)
		{
			if(dobjlst_pt->dobj == dobj_pt)/*ある？*/
			{
				/*エントリーからはずす*/
				dobjlst_pt->dobj = NULL;
				/*リスト列からはずす*/
				before_pt = dobjlst_pt->before;
				next_pt = dobjlst_pt->next;
				if( before_pt == NULL && next_pt == NULL )
				{
					/*自分しかいない*/
					dobjlst_top = dobjlst_last = NULL;
				}
				else
				{
					if( before_pt == NULL )
					{
						dobjlst_top = next_pt;
					}
					else
					{
						before_pt->next = next_pt;
					}
					if( next_pt == NULL )
					{
						dobjlst_last = before_pt;
					}
					else
					{
						next_pt->before = before_pt;
					}
				}
#ifdef	DEBUG_FLAG
				obj_cnt--;
#endif
				return;
			}
			dobjlst_pt = dobjlst_pt->next;
		}
	}
}
#endif


/*===================================================================
 *	３次元オブジェクトハンドラ GsDOBJ2をエントリーからはずします
 *	id番号で切り放します	（GsRemoveObj2()のようなもん）
 *
 * in:
 *		u_long id オブジェクトid
 * out:
 *		void
 *
 *=================================================================*/
#ifdef OBJ_ALLOC
void dobj_idkill(u_long id)
{
 DOBJ_LST *dobjlst_pt;
 DOBJ_LST *before_pt;
 DOBJ_LST *next_pt;

	dobjlst_pt = dobjlst_top;
	while(dobjlst_pt != NULL)
	{
		if(dobjlst_pt->id == id)/*ある？*/
		{
			/*リスト列からはずす*/
			before_pt = dobjlst_pt->before;
			next_pt = dobjlst_pt->next;
			if( before_pt == NULL && next_pt == NULL )
			{
				/*自分しかいない*/
				dobjlst_top = dobjlst_last = NULL;
			}
			else
			{
				if( before_pt == NULL )
				{
					dobjlst_top = next_pt;
				}
				else
				{
					before_pt->next = next_pt;
				}
				if( next_pt == NULL )
				{
					dobjlst_last = before_pt;
				}
				else
				{
					next_pt->before = before_pt;
				}
			}
			memfree2(dobjlst_pt);
#ifdef	DEBUG_FLAG
		obj_cnt--;
#endif
			return;
		}
		dobjlst_pt = dobjlst_pt->next;
	}
}


#else
void dobj_idkill(u_long id)
{
 DOBJ_LST *dobjlst_pt;
 DOBJ_LST *before_pt;
 DOBJ_LST *next_pt;

	dobjlst_pt = dobjlst_top;
	while(dobjlst_pt != NULL)
	{
		if(dobjlst_pt->id == id)/*ある？*/
		{
			/*エントリーからはずす*/
			dobjlst_pt->dobj = NULL;
			/*リスト列からはずす*/
			before_pt = dobjlst_pt->before;
			next_pt = dobjlst_pt->next;
			if( before_pt == NULL && next_pt == NULL )
			{
				/*自分しかいない*/
				dobjlst_top = dobjlst_last = NULL;
			}
			else
			{
				if( before_pt == NULL )
				{
					dobjlst_top = next_pt;
				}
				else
				{
					before_pt->next = next_pt;
				}
				if( next_pt == NULL )
				{
					dobjlst_last = before_pt;
				}
				else
				{
					next_pt->before = before_pt;
				}
			}
#ifdef	DEBUG_FLAG
		obj_cnt--;
#endif
			return;
		}
		dobjlst_pt = dobjlst_pt->next;
	}
}
#endif


/*=============================================================
 *	オブジェクトをID番号で検索します	（GsSearchObjByID2()のようなもん）
 *
 * in:
 *		u_long id	検索するオブジェクトのID番号
 * out:
 *		GsDOBJ2 * 見つけたオブジェクトのポインタ
 *
 *=============================================================*/
GsDOBJ2 *dobj_search(u_long id)
{
 DOBJ_LST *dobjlst_pt;

	dobjlst_pt = dobjlst_top;
	while(dobjlst_pt != NULL)
	{
		if(dobjlst_pt->id == id)
		{
			return dobjlst_pt->dobj;
		}
		dobjlst_pt = dobjlst_pt->next;
	}
	return NULL;
}


/*=============================================================
 *	GsDOBJ2をＯＴに登録します
 *
 * in:
 *		void
 * out:
 *		void
 *
 *=============================================================*/
extern	int mem_cnt;
void dobj_draw(void)
{
 DOBJ_LST *dobjlst_pt;		/* オブジェクトリストへのポインタ */
 GsDOBJ2 *dobj_pt;			/* オブジェクトハンドラへのポインタ */
 MATRIX lw_mtx,ls_mtx;

	dobj_anim();
	dobjlst_pt = dobjlst_top;
	while(dobjlst_pt != NULL)
	{
		dobj_pt = dobjlst_pt->dobj;
		if((dobj_pt->tmd != NULL)&&(!(dobj_pt->attribute & 0x80000000)))
		{

/*			/* ローカル-ワールド/ワールド-スクリーンマトリックスを計算する */
/*			GsGetLws(dobj_pt->coord2,&lw_mtx,&ls_mtx);
/*			/* ライトマトリックスをGTEにセットする */
/*			GsSetLightMatrix2(&lw_mtx);
/*			/* スクリーン／ローカルマトリックスをGTEにセットする */
/*			GsSetLsMatrix(&ls_mtx);
*/
			GsGetLs(dobj_pt->coord2,&ls_mtx);
			GsSetLsMatrix(&ls_mtx);
			GsSetLightMatrix(&ls_mtx);

			/* Perspective Translate Object and Set OT */
			/* オブジェクトを透視変換しオーダリングテーブルに登録する */
/*			GsSortObject(dobj_pt,&ot[actframe],14-OT_LENGTH);*/
/*			GsSortObject2(dobj_pt,&ot[actframe],14-OT_LENGTH);*/
/*			GsSortObject3(dobj_pt,&ot[actframe],14-OT_LENGTH);*/
/*			GsSortObject4(dobj_pt,&ot[actframe],14-OT_LENGTH,0x1f800000);*/
			GsSortObject4(dobj_pt,&ot[actframe],14-OT_LENGTH,getScratchAddr(0));/* */
		}
		dobjlst_pt = dobjlst_pt->next;		/*dobjlstを次へ*/
	}
#ifdef	DEBUG_FLAG
	FntPrint("DOBJ=%d\n",obj_cnt);/*testtest*/
#endif
}






















/*=============================================================
 *  TMD内のモデリングデータをID番号で検索します	（GsSearchTmdByID()のようなもん）
 *
 * in:
 *		u_long *tmd_adr;	TMDデータのポインタ
 *		int *tmd_id;		モデリングデータIDリストのポインタ
 *		u_long id;			モデリングデータのID
 * out:
 *		u_long *			モデリングデータIDのTMDデータのポインタ
 *
 *=============================================================*/
u_long *tmd_search(u_long *tmd_adr, int *tmd_id, u_long id)
{
 int n;

	tmd_adr++;		/* ヘッダを読み飛ばす */
	n = *tmd_adr++;	/* モデリングデータの数 */

	while(n > 0)
	{
		if(id == *tmd_id)
		{
			/* アドレスを返す */
			return tmd_adr;
		}
		tmd_adr += 7;	/* ポインタを進める */
		tmd_id++;
		n--;
	}
	/* 見つからなければNULLを返す */
	return NULL;
}


/*=============================================================
 *  １フレーム分のTODデータの処理	（GsSetTodFrame2()のようなもん）
 *
 * in:
 *		int cframe		現在の時刻（フレーム番号）
 *		u_long *tod_adr	再生フレームのTODデータのポインタ
 *		int *tmd_id		モデリングデータIDリストのポインタ
 *		u_long *tmd_adr	TMDデータのポインタ
 *		int mode		再生モード
 * out:
 *		u_long *		次のフレームのポインタ
 *
 *=============================================================*/
u_long *dobj_anim_frame(int cframe, u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode)
{
 u_long hdr;			/* frame header */
 u_long packet_cnt;		/* number of packets */
 int i;
#if 0
	/* 現在時刻のフレームでなければ何も処理しない */
	if((*(tod_adr+1)) > cframe) return NULL;

	/* フレーム情報を得る */
	hdr = *tod_adr;					/* 現フレームのヘッダを得る */
	packet_cnt = (hdr>>16)&0x0ffff;	/* パケット個数 */

	/* フレームの中の各パケットを処理する */
	tod_adr += 2;					/* パケットデータの位置へ（frameヘッダ飛ばし）*/
	for(i = 0; i < packet_cnt; i++) /*パケット数分処理 */
	{
		tod_adr = dobj_anim_packet(tod_adr, tmd_id, tmd_adr, mode);
	}

	return tod_adr;		/* 次のフレームへのポインタを返す */
#endif
}


/*=============================================================
 *  １パケットの処理	（GsSetTodPacket2()のようなもん）
 *
 * in:
 *		u_long *tod_adr	TODデータの処理packet部分のポインタ
 *		int *tmd_id		モデリングデータIDリストのポインタ
 *		u_long *tmd_adr	TMDデータのポインタ
 *		int mode		再生モード
 * out:
 *		u_long *		次のpacketのポインタ
 *
 *=============================================================*/
u_long *dobj_anim_packet(u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode)
{
 u_long *pkt_adr;		/* 処理中のTODへのポインタ */

 u_long hdr;
 u_long id;
 u_long flag;
 u_long type;
 u_long len;

 /* 処理中オブジェクト */
 GsDOBJ2 *dobj_pt;		/* オブジェクトへのポインタ */
 MATRIX *coordp;		/* 座標マトリクス */
 GsCOORD2PARAM *cparam;	/* 座標パラメータ(R,S,T) */
 GsDOBJ2 *parent_pt;	/* 親オブジェクト */

/* VECTOR v;
/* SVECTOR sv;
/*
/* /* ダミーオブジェクト変数 */
/* GsDOBJ2 dmy_dobj;
/* MATRIX dmy_dobj_coord;
/* GsCOORD2PARAM dmy_dobj_param;
*/
#if 0

	/* パケット情報を得る */
	pkt_adr = tod_adr;
	hdr = *pkt_adr++;
	id = hdr&0x0ffff;		/* ID番号 */
	type = (hdr>>16)&0x0f;	/* packet type (TOD_???) */
	flag = (hdr>>20)&0x0f;	/* flag */
	len = (hdr>>24)&0x0ff;	/* パケットのワード長 */

	if(type != TOD_OBJCTL)
	{
		/* ID番号で該当するオブジェクトをサーチ */
		dobj_pt = dobj_search(id);
		if(dobj_pt == NULL) 
		{
/*			/* ない場合はダミーオブジェクトを使う */
/*			dobj_pt = &dmy_dobj;
/*			coordp = &dmy_dobj_coord;
/*			cparam = &dmy_dobj_param;	/* */
			/* ^^^上記の処理について^^^　なんじゃそりゃ、そんなもん使っても何ものこらんぞ */
			dobj_pt = dobj_make(id);	/* ないのなら作る */
		}
		coordp = &(dobj_pt->coord2->coord);
		cparam = (dobj_pt->coord2->param);
		dobj_pt->coord2->flg = 0;
	}

/**** パケットのタイプ別に処理します ***/
	switch(type)
	{
/*-------------------------------------------------------------*/
/*------ アトリビュート変更 ------*/
	case TOD_ATTR:
		dobj_pt->attribute = (dobj_pt->attribute&*pkt_adr)|*(pkt_adr+1);
		pkt_adr += 2;
		break;
/*-------------------------------------------------------------*/
/*------ 座標変更（移動／回転／拡大）------*/
	case TOD_COORD:
		/* 該当オブジェクトのcoordinateの内容を更新する   */
		/* 更新するパラメータはcparamメンバに保管してある */
		if(flag&0x01)
		{
			/* ----- 前フレームからの差分の場合 ----- */
			/* Rotation処理 */
			if(flag&0x02)
			{
				cparam->rotate.vx += (*(((long *)pkt_adr)+0))/360;
				cparam->rotate.vy += (*(((long *)pkt_adr)+1))/360;
				cparam->rotate.vz += (*(((long *)pkt_adr)+2))/360;
				pkt_adr += 3;
			}
			/* Scaling処理 */
			if(flag&0x04)
			{
				cparam->scale.vx
				 = (cparam->scale.vx**(((short *)pkt_adr)+0))/4096;
				cparam->scale.vy
				 = (cparam->scale.vy**(((short *)pkt_adr)+1))/4096;
				cparam->scale.vz
				 = (cparam->scale.vz**(((short *)pkt_adr)+2))/4096;
				pkt_adr += 2;
			}
			/* Transfer処理 */
			if(flag&0x08)
			{
				cparam->trans.vx += *(((long *)pkt_adr)+0);
				cparam->trans.vy += *(((long *)pkt_adr)+1);
				cparam->trans.vz += *(((long *)pkt_adr)+2);
				pkt_adr += 3;
			}

			RotMatrix(&(cparam->rotate), coordp);
			ScaleMatrix(coordp, &(cparam->scale));
			TransMatrix(coordp, &(cparam->trans));
		}
		else
		{
			/* ----- 絶対値の場合 ----- */
			/* Rotation処理 */
			if(flag&0x02)
			{
				cparam->rotate.vx = (*(((long *)pkt_adr)+0))/360;
				cparam->rotate.vy = (*(((long *)pkt_adr)+1))/360;
				cparam->rotate.vz = (*(((long *)pkt_adr)+2))/360;
				pkt_adr += 3;
				RotMatrix(&(cparam->rotate), coordp);
			}
			/* Scaling処理 */
			if(flag&0x04)
			{
				cparam->scale.vx = *(((short *)pkt_adr)+0);
				cparam->scale.vy = *(((short *)pkt_adr)+1);
				cparam->scale.vz = *(((short *)pkt_adr)+2);
				pkt_adr += 2;
				if(!(flag&0x02))
					RotMatrix(&(cparam->rotate), coordp);
				ScaleMatrix(coordp, &(cparam->scale));
			}
			/* Transfer処理 */
			if(flag&0x08)
			{
				cparam->trans.vx = *(((long *)pkt_adr)+0);
				cparam->trans.vy = *(((long *)pkt_adr)+1);
				cparam->trans.vz = *(((long *)pkt_adr)+2);
				pkt_adr += 3;
				TransMatrix(coordp, &(cparam->trans));
			}
		}
		break;
/*-------------------------------------------------------------*/
/*------ TMDとのリンクを設定 ------*/
	case TOD_TMDID:
		if(tmd_adr != NULL)
		{
/*			dobj_pt->tmd = TodSearchTMDByID(tmd_adr, tmd_id,
/*					(unsigned long)(*pkt_adr&0xffff));
*/
			GsLinkObject4((u_long)tmd_search(tmd_adr,tmd_id,(unsigned long)(*pkt_adr&0xffff)),
					dobj_pt,0);
		}
		break;
/*-------------------------------------------------------------*/
/*----- 親オブジェクトの設定 -----*/
    case TOD_PARENT:
		if(mode != GsTOD_COORDONLY)
		{
			if((*pkt_adr == NULL)||(*pkt_adr == 0xffff))
			{
				dobj_pt->coord2->super = NULL;
			}
			else
			{
				parent_pt = dobj_search(*pkt_adr);
				if(parent_pt != NULL)
				{
					dobj_pt->coord2->super = parent_pt->coord2;
				}
			}
			pkt_adr++;
		}
		break;
/*-------------------------------------------------------------*/
	case TOD_MATRIX:
		break;
/*-------------------------------------------------------------*/
	case TOD_TMDDATA:
		break;
/*-------------------------------------------------------------*/
/*------ 光源設定 ------*/
	case TOD_LIGHT:
		if(flag&0x02)
		{
			if(flag&0x01)
			{
				pslt[id].vx += *(((long *)pkt_adr)+0);
				pslt[id].vy += *(((long *)pkt_adr)+1);
				pslt[id].vz += *(((long *)pkt_adr)+2);
			}
			else
			{
				pslt[id].vx = *(((long *)pkt_adr)+0);
				pslt[id].vy = *(((long *)pkt_adr)+1);
				pslt[id].vz = *(((long *)pkt_adr)+2);
			}
			pkt_adr += 3;
		}
		if(flag&0x04)
		{
			if(flag&0x01)
			{
				pslt[id].r += *(((u_char *)pkt_adr)+0);
				pslt[id].g += *(((u_char *)pkt_adr)+1);
				pslt[id].b += *(((u_char *)pkt_adr)+2);
			}
			else
			{
				pslt[id].r = *(((u_char *)pkt_adr)+0);
				pslt[id].g = *(((u_char *)pkt_adr)+1);
				pslt[id].b = *(((u_char *)pkt_adr)+2);
			}
			pkt_adr++;
		}
		GsSetFlatLight(id, &pslt[id]);
		break;
/*-------------------------------------------------------------*/
	case TOD_CAMERA:
		break;
/*-------------------------------------------------------------*/
/*----- テーブル内オブジェクトの管理 -----*/
	case TOD_OBJCTL:
		switch(flag)
		{
		case 0:
			/* 新規オブジェクトの生成 */
			dobj_make(id);
			break;
		case 1:
			/* オブジェクトの削除 */
			dobj_idkill(id);
			break;
		}
		break;
/*-------------------------------------------------------------*/
/*------ ここにユーザ定義パケットの処理を記述する ------*/
	case TOD_USER0:
	case TOD_USER1:
	case TOD_USER2:
	case TOD_USER3:
	case TOD_USER4:
		break;
	}

/*-------------------------------------------------------------*/
/*-------------------------------------------------------------*/
	/* 次のパケットへのポインタを返す */
	return tod_adr+len;
#endif
}



/*=============================================================
 *	アニメーション処理を初期化します
 *
 * in:
 *		void
 * out:
 *		void
 *
 *=============================================================*/
void dobj_anim_init(void)
{
 int i;
#if 0
	for(i=0;i<TOD_ANIM_MAX;i++)
	{
		tod_anim[i].tod_adr = NULL;
	}
#endif
}


/*=============================================================
 *	アニメーション処理をエントリーし実行します
 *	登録後すぐに有効になります
 *
 * in:
 *		u_long *tod_adr	TODデータのポインタ
 *		int *tmd_id		モデリングデータIDリストのポインタ
 *		u_long *tmd_adr	TMDデータのポインタ
 *		int mode		再生モード
 *		u_short type	再生種別
 * out:
 *		TOD_ANIM *		アニメーション登録のポインタ
 *
 *=============================================================*/
TOD_ANIM *dobj_anim_set(u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode, u_short type)
{
 int i;
#if 0
	for(i=0;i<TOD_ANIM_MAX;i++)
	{
		if(tod_anim[i].tod_adr == NULL)
		{
			dobj_anim_chg(&tod_anim[i],tod_adr,tmd_id,tmd_adr,mode,type);
			return &tod_anim[i];
		}
	}
	return NULL;
#endif
}


/*=============================================================
 *	アニメーション処理を切り替えます。セットします。
 *	登録後すぐに有効になります
 *
 * in:
 *		TOD_ANIM *todanim_pt	アニメーション登録のポインタ
 *		u_long *tod_adr	TODデータのポインタ
 *		int *tmd_id		モデリングデータIDリストのポインタ
 *		u_long *tmd_adr	TMDデータのポインタ
 *		int mode		再生モード
 *		u_short type	再生種別
 * out:
 *		void
 *
 *=============================================================*/
void dobj_anim_chg(TOD_ANIM *todanim_pt, u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode, u_short type)
{
#if 0
	todanim_pt->anim_flg = 0;			/* 再生状態 */
	todanim_pt->type = type;			/* 再生種別 */
	todanim_pt->cnt = 0;				/* カウンター */

	todanim_pt->tmd_adr = tmd_adr;		/* TMDデータのポインタ */
	todanim_pt->tmd_id = tmd_id;		/* モデリングデータIDリストのポインタ */
	todanim_pt->mode = mode;			/* 再生モード */

	todanim_pt->tod_org = tod_adr;		/* TODデータのポインタ保持用 */
	tod_adr++;							/*ヘッダー飛ばして*/
	todanim_pt->frame_cnt = *tod_adr;	/* number of frames */
	tod_adr++;
	todanim_pt->act_frame = *(tod_adr+1);	/*開始フレーム番号*/

	todanim_pt->tod_adr = tod_adr;		/* TODデータのポインタ */
#endif
}


/*=============================================================
 *	アニメーション処理を切り替えます。セットします。
 *	登録後すぐに有効になります
 *	最初の一回は dobj_anim_chg() を使ってください
 *
 * in:
 *		TOD_ANIM *todanim_pt	アニメーション登録のポインタ
 *		u_long *tod_adr	TODデータのポインタ
 *		int mode		再生モード
 *		u_short type	再生種別
 * out:
 *		void
 *
 *=============================================================*/
void dobj_anim_chg2(TOD_ANIM *todanim_pt, u_long *tod_adr, int mode, u_short type)
{
#if 0
	todanim_pt->anim_flg = 0;			/* 再生状態 */
	todanim_pt->type = type;			/* 再生種別 */
	todanim_pt->cnt = 0;				/* カウンター */

	todanim_pt->mode = mode;			/* 再生モード */

	todanim_pt->tod_org = tod_adr;		/* TODデータのポインタ保持用 */
	tod_adr++;							/*ヘッダー飛ばして*/
	todanim_pt->frame_cnt = *tod_adr;	/* number of frames */
	tod_adr++;
	todanim_pt->act_frame = *(tod_adr+1);	/*開始フレーム番号*/

	todanim_pt->tod_adr = tod_adr;		/* TODデータのポインタ */
#endif
}


/*=============================================================
 *	アニメーション処理を登録から切り離し終了します
 *
 * in:
 *		u_long *tod_adr	TODデータのポインタ
 * out:
 *		void
 *
 *=============================================================*/
void dobj_anim_end(TOD_ANIM *todanim_pt)
{
 int i;
#if 0
	for(i=0;i<TOD_ANIM_MAX;i++)
	{
		if(&tod_anim[i] == todanim_pt)
		{
			tod_anim[i].tod_adr = NULL;
			return;
		}
	}
	return;
#endif
}


/*=============================================================
 *	TODアニメーションを処理します。
 *
 * in:
 *		void
 * out:
 *		void
 *
 *=============================================================*/
void dobj_anim(void)
{
 TOD_ANIM *todanim_pt;
 u_long *adr;
 int i;
#if 0
	for(i=0;i<TOD_ANIM_MAX;i++)
	{
		if(tod_anim[i].tod_adr != NULL)
		{
			todanim_pt = &tod_anim[i];
			if(todanim_pt->cnt < todanim_pt->frame_cnt)
			{
				adr = dobj_anim_frame(todanim_pt->act_frame,todanim_pt->tod_adr,
								todanim_pt->tmd_id,todanim_pt->tmd_adr,todanim_pt->mode);
				if(adr != NULL)
				{
					todanim_pt->tod_adr = adr;	/*今の時間で処理を行っていたら更新 */
					todanim_pt->cnt++;
				}
				todanim_pt->act_frame++;		/* 時間+1 */
			}
			else
			{
				/*最終フレームまで処理したあと*/
				switch(todanim_pt->type)
				{
				case TOD_ANIM_END:
					todanim_pt->anim_flg = 1;	/* 再生終了 */
					break;
				case TOD_ANIM_LOOP:
					dobj_anim_chg2(todanim_pt,todanim_pt->tod_org,todanim_pt->mode,todanim_pt->type);
					break;
				case TOD_ANIM_KILL:
					dobj_anim_end(todanim_pt);
					break;
				default:
					break;
				}
			}
		}
	}
#endif
}



























#if 0
/*
 * Set TOD data from the memory
/* メモリ上のTODデータの読み込み
 *
 */
void
initTod()
{
	TodP[0] = ( u_long * )TOD_ADDR0;
	TodP[0]++;
	NumFrame[0] = *TodP[0]++;
	StartFrameNo[0] = *( TodP[0] + 1 );

	TodP[1] = ( u_long * )TOD_ADDR1;
	TodP[1]++;
	NumFrame[1] = *TodP[1]++;
	StartFrameNo[1] = *( TodP[1] + 1 );

	TodP[2] = ( u_long * )TOD_ADDR2;
	TodP[2]++;
	NumFrame[2] = *TodP[2]++;
	StartFrameNo[2] = *( TodP[2] + 1 );

	TodP[3] = ( u_long * )TOD_ADDR3;
	TodP[3]++;
	NumFrame[3] = *TodP[3]++;
	StartFrameNo[3] = *( TodP[3] + 1 );

	TodP[4] = ( u_long * )TOD_ADDR4;
	TodP[4]++;
	NumFrame[4] = *TodP[4]++;
	StartFrameNo[4] = *( TodP[4] + 1 );

	TodP[5] = ( u_long * )TOD_ADDR5;
	TodP[5]++;
	NumFrame[5] = *TodP[5]++;
	StartFrameNo[5] = *( TodP[5] + 1 );

	TodP[6] = ( u_long * )TOD_ADDR6;
	TodP[6]++;
	NumFrame[6] = *TodP[6]++;
	StartFrameNo[6] = *( TodP[6] + 1 );

	TodP[7] = ( u_long * )TOD_ADDR7;
	TodP[7]++;
	NumFrame[7] = *TodP[7]++;
	StartFrameNo[7] = *( TodP[7] + 1 );

	TodP[8] = ( u_long * )TOD_ADDR8;
	TodP[8]++;
	NumFrame[8] = *TodP[8]++;
	StartFrameNo[8] = *( TodP[8] + 1 );
}

/*
 * Draw the initial pose
/* 登場から初期ポーズをとるまで
 *
 */
void
initPose()
{
    int		i;
    int		j;
    int		frameNo;
    int		oldFrameNo;

    /* 最初のフレームの TODデータの処理 */
    TodP[0] = TodSetFrame( StartFrameNo[0], TodP[0], &objs, te_list, 
			   TmdP, GsTOD_CREATE );
    drawObject();
    oldFrameNo = StartFrameNo[0];

    /* それ以降のフレームの TODデータの処理 */
    for ( i = 1 ; i < NumFrame[0] ; i++ )
	{
		frameNo = *( TodP[0] + 1 );

		for ( j = 0 ; j < frameNo - oldFrameNo - 1 ; j++ )
		{
	    	drawObject();
		}

		/* 1フレーム分の TODデータの処理 */
		TodP[0] = TodSetFrame( frameNo, TodP[0], &objs, te_list, 
			       TmdP, GsTOD_CREATE );
		drawObject();
		oldFrameNo = frameNo;
    }
    drawObject();

    pose = -1;
}

/*
 * play TOD data according to the pad data 
/* パッドにより、TODデータを表示する
 *
 */
int obj_interactive()
{
int		i;
u_long	*TodPtmp;		/* pointer to TOD data  */
int		step;

    /* 「ぐー」( ) */
    if ( ( padd & PADRright ) > 0 )
	{

		/* 現在のポーズから振り始めの定位置に戻る */
		if ( pose > 0 )
		{
	    	TodPtmp = TodP[pose+3];
	    	for ( i = StartFrameNo[pose+3]; i < NumFrame[pose+3] + StartFrameNo[pose+3]; i++ )
			{
				TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
				drawObject();
	    	}
	    	drawObject();
		}

		/* 「じゃ～んけ～ん」と握り拳を振る */
		TodPtmp = TodP[1];
		for ( i = StartFrameNo[1]; i < NumFrame[1] + StartFrameNo[1]; i++ )
		{
		    TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
		    drawObject();
		}
		drawObject();

		/* 定位置から「ぐー」を出す */
		TodPtmp = TodP[2];
		for ( i = StartFrameNo[2]; i < NumFrame[2] + StartFrameNo[2]; i++ )
		{
		    TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
		    drawObject();
		}
		drawObject();

		pose = 2;
    }

    /* 「ぱー」 */
    if ( ( padd & PADRleft ) > 0 )
	{

		/* 現在のポーズから振り始めの定位置に戻る */
		if ( pose > 0 )
		{
	    	TodPtmp = TodP[pose+3];
			for ( i = StartFrameNo[pose+3]; i < NumFrame[pose+3] + StartFrameNo[pose+3]; i++ )
			{

				TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
				drawObject();
	    	}
	    	drawObject();
		}

		/* 「じゃ～んけ～ん」と握り拳を振る */
		TodPtmp = TodP[1];
		for ( i = StartFrameNo[1]; i < NumFrame[1] + StartFrameNo[1]; i++ )
		{

		    TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
	    	drawObject();
		}
		drawObject();

		/* 定位置から「ぱー」を出す */
		TodPtmp = TodP[4];
		for ( i = StartFrameNo[4]; i < NumFrame[4] + StartFrameNo[4]; i++ )
		{

	    	TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
	    	drawObject();
		}
		drawObject();

		pose = 4;
    }

    /* 「ちょき」 */
    if ( ( padd & PADRup ) > 0 )
	{

		/* 現在のポーズから振り始めの定位置に戻る */
		if ( pose > 0 )
		{
	    	TodPtmp = TodP[pose+3];
	    	for ( i = StartFrameNo[pose+3]; i < NumFrame[pose+3] + StartFrameNo[pose+3]; i++ )
			{

				TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
				drawObject();
	    	}
	    	drawObject();
		}

		/* 「じゃ～んけ～ん」と握り拳を振る */
		TodPtmp = TodP[1];
		for ( i = StartFrameNo[1]; i < NumFrame[1] + StartFrameNo[1]; i++ )
		{

	    	TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
	    	drawObject();
		}
		drawObject();

		/* 定位置から「ちょき」を出す */
		TodPtmp = TodP[3];
		for ( i = StartFrameNo[3] ; i < NumFrame[3] + StartFrameNo[3]; i++ )
		{

	    	TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
	    	drawObject();
		}
		drawObject();

		pose = 3;
    }

    /* 「ぐー」「ちょき」「ぱー」のいずれかをランダムに出す */
    if ( ( padd & PADRdown ) > 0 )
	{

		/* 現在のポーズから振り始めの定位置に戻る */
		if ( pose > 0 )
		{
	    	TodPtmp = TodP[pose+3];
	    	for ( i = StartFrameNo[pose+3]; i < NumFrame[pose+3] + StartFrameNo[pose+3]; i++ )
			{

				TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
				drawObject();
	    	}
	    	drawObject();
		}

		/* 「じゃ～んけ～ん」と握り拳を振る */
		TodPtmp = TodP[1];
		for ( i = StartFrameNo[1]; i < NumFrame[1] + StartFrameNo[1]; i++ )
		{

	    	TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
	    	drawObject();
		}
		drawObject();

		/* 定位置から「ぐー」「ちょき」「ぱー」のいずれかをランダムに出す */
		pose = rand()%3 + 2;
		TodPtmp = TodP[pose];
		for ( i = StartFrameNo[pose]; i < NumFrame[pose] + StartFrameNo[pose]; i++ )
		{

	    	TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
	    	drawObject();
		}
		drawObject();
    }

    /* 視点の変更 */
    if ( ( padd & PADn ) > 0 )
	{
		view.vpz += 100;
		GsSetRefView2( &view );
		drawObject();
    }
    if ( ( padd & PADo ) > 0 )
	{
		view.vpz -= 100;
		GsSetRefView2( &view );
		drawObject();
    }
    if ( ( padd & PADLleft ) > 0 )
	{
		view.vpx -= 100;
		GsSetRefView2( &view );
		drawObject();
    }
    if ( ( padd & PADLright ) > 0 )
	{
		view.vpx += 100;
		GsSetRefView2( &view );
		drawObject();
    }
    if ( ( padd & PADLdown ) > 0 )
	{
		view.vpy += 100;
		GsSetRefView2( &view );
		drawObject();
    }
    if ( ( padd & PADLup ) > 0 )
	{
		view.vpy -= 100;
		GsSetRefView2( &view );
		drawObject();
    }
    
    /* Move the view point to the initial place 
       /* 視点を元に戻す */
    if ( ( padd & PADh ) > 0 )
	{
		initView();
		drawObject();
    }

    /* Exit the program 
       /* プログラムを終了する */
    if ( ( padd & PADk ) > 0 )
	{

		/* 初期ポーズに戻す */
		if ( pose > 0 )
		{

	    	TodPtmp = TodP[pose+3];
			for ( i = StartFrameNo[pose+3]; i < NumFrame[pose+3] + StartFrameNo[pose+3]; i++ )
			{

				TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
				drawObject();
	    	}
	    	drawObject();
		}

		/* 視点を元の位置に戻す */
		step = ( ( VPX - view.vpx ) * ( VPX - view.vpx )
			 + ( VPY - view.vpy ) * ( VPY - view.vpy )
			 + ( VPZ - view.vpz ) * ( VPZ - view.vpz ) ) / 500000;
		if ( step > 50 )
		{
	    	step = 50;
		}
		for ( i = 1 ; i <= step ; i++ )
		{
	    	view.vpx = view.vpx + ( i * ( VPX - view.vpx ) ) / step;
	    	view.vpy = view.vpy + ( i * ( VPY - view.vpy ) ) / step;
	    	view.vpz = view.vpz + ( i * ( VPZ - view.vpz ) ) / step;
	    	GsSetRefView2( &view );
	    	drawObject();
		}

		/* 退場 */
		TodPtmp = TodP[8];
		for ( i = StartFrameNo[8] ;i < NumFrame[8] + StartFrameNo[8]; i++ )
		{

	    	TodPtmp = TodSetFrame( i, TodPtmp, &objs, te_list, TmdP, GsTOD_CREATE );
	    	drawObject();
		}
		drawObject();

		/* プログラムの終了 */
		return -1;
    }
    return 0;
}

#endif
