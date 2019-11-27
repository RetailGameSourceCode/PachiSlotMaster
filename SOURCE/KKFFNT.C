/*====================================================
 kkffnt.c
qc====================================================*/
#define _KKFFNT_C_

#if 0	/* インクルードファイル選択 */
#include <libps.h>
#else
#include <sys/types.h>
#include <sys/file.h>
#include <r3000.h>
#include <asm.h>
#include <kernel.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libcd.h>
#include <libgs.h>
#include <libsn.h>
#include <libspu.h>
#include <libsnd.h>
#include <stdlib.h>
#include <libmath.h>
#include <limits.h>
#include <setjmp.h>
#endif

#include "common.h"
#include "kkffnt.h"

/*====================================================
  ====================================================
 work
====================================================
====================================================*/
//void *fnt_data;
u_char fnt_data[BIN_TEXT_SIZE];

//static GsSPRITE *fspr[FFNT_MAX];
SPRITE_OBJECT	*fspr[FFNT_MAX];

typedef struct { 	/* ウィンドウワーク */
	int wf;			/* ウィンドウオープンフラグ(0:none,1:open 2:redraw) */
	int wx;			/* 表示範囲(pixel) x */
	int wy;			/* 表示範囲(pixel) y */
	int ww;			/* 表示範囲(pixel) w */
	int wh;			/* 表示範囲(pixel) h */
	int wr;			/* フォントカラー r */
	int wg;			/* フォントカラー g */
	int wb;			/* フォントカラー b */
	int wv;			/* 表示開始縦位置 */
	int ws;			/* 自動スクロール用 */
	int pri;
	u_short *btn;	/* 特殊ボタン処理用 */
	u_short *wt; 	/* FTDT出力のテキストデータ先頭アドレス */
} FFNTWIN;

typedef struct {
	int cy;						/* FTXT出力TIMのclut配置位置y */
	int cn;						/* ffnt_getspr用カウンタ */
	u_short cnv[FFNT_CNVMAX];	/* ffnt_cnv コンバート前 */
	u_short *cdt[FFNT_CNVMAX];	/* ffnt_cnv コンバート後 */
	int cnvs;					/* ffnt_cnv コンバートキャラ登録数 */
	int (*padfunc)();			/* 特殊ボタン判定用関数 */
	u_short kin[FFNT_KINMAX];	/* 禁則処理キャラ */
	int kins;					/* 禁則処理キャラ登録数 */
	u_short fun[FFNT_FUNMAX];	/* 特殊処理キャラ */
	int (*fdt[FFNT_FUNMAX])(u_short);	/* 特殊処理関数 */
	int funs;					/* 特殊処理キャラ登録数 */
	char flg[FFNT_MAX];		/* fspr使用フラグ(0:none 1~:fntid+1) */
	FFNTWIN fw[FFNT_WIN];	/* ウィンドウワーク */
} FFNT;

static FFNT ffnt;	/* ffntワーク */

/*====================================================
  ====================================================
	ffnt_init	ＦＦＮＴ初期化
	**: 最初に必ず一回呼んでください
	in: px .. FTXT出力TIMのpixel配置位置x 
	    py .. FTXT出力TIMのpixel配置位置y 
	    cx .. FTXT出力TIMのclut配置位置x 
	    cy .. FTXT出力TIMのclut配置位置y 
====================================================
====================================================*/

void ffnt_init(int px,int py,int cx,int cy)
{	/* ＦＦＮＴ初期化 */
	int i;

	ffnt.cy=cy;
	ffnt.cn=0;

	for (i=0;i<FFNT_MAX;i++){
//	 fspr[i]=(GsSPRITE *)memalloc(sizeof(GsSPRITE), (void**)&fspr[i]);
		fspr[i]=sprobj_make();
	}
	for (i=0;i<FFNT_WIN;i++) {
		ffnt.fw[i].wf=0;
		ffnt_color(i,FFNT_R,FFNT_G,FFNT_B); /* ＦＦＮＴカラー変更 */
	}
	for (i=0;i<FFNT_MAX;i++) {
		ffnt.flg[i]=0;
		/* スプライト普遍部分はあらかじめ設定 */
//		fspr[i]->attribute=GsROTOFF;	/*|(GsALON|GsAZERO);*/
		fspr[i]->attribute=GsCLUT4;	/*|(GsALON|GsAZERO);*/
		fspr[i]->w=FFNT_W;
		fspr[i]->tpage=((((py)&0x100)>>4)|(((px)&0x3ff)>>6));	/* get_tpage(px,py) */
		fspr[i]->cx=cx;
		fspr[i]->cy=cy;
		fspr[i]->mx=0;
		fspr[i]->my=0;
		fspr[i]->pri=10;
		fspr[i]->scalex=fspr[i]->scaley=ONE;
		fspr[i]->rotate=0;
		sprobj_doff(fspr[i]);
	}
	ffnt.padfunc=0;
	for (i=0;i<FFNT_KINMAX;i++) ffnt.kin[i]=0;
	ffnt.cnvs=0;
	ffnt.kins=0;
	ffnt.funs=0;
}



/*====================================================
  ====================================================
	ffnt_end	ＦＦＮＴ終了
	**: ffnt使用終了時に呼び出します
====================================================
====================================================*/

void ffnt_end(void)
{	/* ＦＦＮＴ終了 */
	int i;

	for (i=0;i<FFNT_WIN;i++) ffnt.fw[i].wf=0;
	for (i=0;i<FFNT_MAX;i++) ffnt.flg[i]=0;
	for (i=0;i<FFNT_MAX;i++){
//	 memfree((void**)&fspr[i]);

		sprobj_kill(fspr[i]);
	}
}



/*====================================================
  ====================================================
	ffnt_drv	ＦＦＮＴ表示更新ドライバ
	**: 毎フレーム、描画処理前に呼び出してください
====================================================
====================================================*/
static int kin_check(u_short s)
{	/* 禁則処理文字？ */
	int i;

	for	(i=0;i<ffnt.kins;i++) 
		if	(s==ffnt.kin[i]) return(i);
	return(-1);
}

static int fun_check(u_short s)
{	/* 特殊処理文字？ */
	int i;

	for	(i=0;i<ffnt.funs;i++) 
		if	(s==ffnt.fun[i]) return(i);
	return(-1);
}

static void ffnt_drv_spr(FFNTWIN *fw,int i,u_short s,int x,int y)
{	/* スプライト作成 */
//	GsSPRITE	*fsp;
	SPRITE_OBJECT	*fsp;
	
	fsp = fspr[i];
	sprobj_don(fspr[i]);

	fsp->x=fw->wx+FFNT_OFSX+x;
	fsp->u=((s/FFNT_LV)&(FFNT_WW-1))*FFNT_W;
	if (y<0) {					/* 上部隠れ：下部のみ表示 */
		fsp->y=fw->wy+FFNT_OFSY;
		fsp->v=((s/FFNT_LV)/FFNT_WW)*FFNT_H-y;
		fsp->h=FFNT_H+y;
	} else
	if	(y<=fw->wh-FFNT_H) {	/* 全範囲内：全表示 */
		fsp->y=fw->wy+FFNT_OFSY+y;
		fsp->v=((s/FFNT_LV)/FFNT_WW)*FFNT_H;
		fsp->h=FFNT_H;
	} else {					/* 下部隠れ：上部のみ表示 */
		fsp->y=fw->wy+FFNT_OFSY+y;
		fsp->v=((s/FFNT_LV)/FFNT_WW)*FFNT_H;
		fsp->h=fw->wh-y;
	}
//	fsp->y&=0xfffffffe;	// インターレースモードのため

	fsp->cy=ffnt.cy+(s&(FFNT_LV-1));	/* ４重合成ＦＯＮＴのため */
	fsp->r=fw->wr;
	fsp->g=fw->wg;
	fsp->b=fw->wb;
	fsp->pri=fw->pri;
}

void ffnt_drv(void)
{	/* ＦＦＮＴ表示更新ドライバ */
	int id,i,x,y,r;
	u_short *u,s;
	FFNTWIN *fw;
	char	*ccp;

	for (id=0;id<FFNT_WIN;id++) {
		fw=&ffnt.fw[id];
		for (i=0;i<FFNT_SPD;i++) if	(fw->wf!=0 && fw->ws) {
			/* 自動スクロール処理 */
			if (fw->ws<0) { if (fw->wv>0) fw->wv--; }
			else	 	  { if (fw->wv<ffnt_getvmax(id)) fw->wv++; }
			if ((fw->wv%FFNT_H2)==0 || fw->wv>=ffnt_getvmax(id)) fw->ws=0;
			fw->wf=2;	/* redraw req. */
		}
		if	(fw->wf==1) {	/* enable */
			if	(fw->btn && ffnt.padfunc!=0) {
				if (ffnt.padfunc()) {
					fw->wt=fw->btn;
					fw->btn=0;
					fw->wf=2;
				}
			}
		}
		if	(fw->wf==2) {	/* redraw req. */
			/* テキスト全文字確認：表示範囲内ならＳＰＲ登録していく */
			u=fw->wt;	/* テキスト上ポインタ */
			x=0;		/* 横位置 */
			y=-fw->wv;	/* 縦位置 */
			i=0;		/* 空きＳＰＲ検索用 */
			while((s=*u++)!=FFNT_EOF && s!=FFNT_BTN) {	/* 終了コードまで */
				if	(s==FFNT_EOL) {		/* 改行 */
					x=0; y+=FFNT_H2;
					continue;
				} else
				if	(s==FFNT_SPC) {		/* 半角空白 */
					x+=FFNT_W2;//FFNT_H2/2;
				} else
				if	((r=fun_check(s))!=-1) {	/* 特殊処理文字？ */
					r=ffnt.fdt[r](s);			/* 特殊処理実行 */
					if (r==-1) {		/* 文字表示終了 */
						break;
					}	/* 以後追加可能 */
				} else
				if (y>=fw->wh) break; /* 範囲外 */
				else {				/* 文字 */
					if (y<=-FFNT_H || y>=fw->wh) continue; /* 範囲外 */
					for (;i<FFNT_MAX;i++) 		/* 空いているか、同ＩＤのＳＰＲを探す */
						if (ffnt.flg[i]==0 || ffnt.flg[i]==id+1) break;
					if (i==FFNT_MAX) return;	/* 表示文字数オーバー (error) */
					ffnt_drv_spr(fw,i,s,x,y);		/* スプライト作成 */
					ffnt.flg[i]=id+1;
					x+=FFNT_W2;
					i++;
				}
				if	(x>=fw->ww && kin_check(s)==-1 && kin_check(*u)==-1)  {	/* 改行 */
					x=0; y+=FFNT_H2;
				}
			}
			if	(s==FFNT_BTN) fw->btn=u;	/* 特殊ボタン処理用コードで終了 */
			/* 今回は使用しなかった、残りの同ＩＤのＳＰＲを消去 */
#if 1
			ccp = &ffnt.flg[i];
			for	 (;i<FFNT_MAX;i++, ccp++)
				if (*ccp == id + 1) {
					*ccp = 0;
					sprobj_doff(fspr[i]);
				}
#else
			for	 (;i<FFNT_MAX;i++, ccp++)
				if (ffnt.flg[i]==id+1) {
					ffnt.flg[i]=0;
					sprobj_doff(fspr[i]);
				}
#endif

			fw->wf=1;	/* redraw req. off */
		}
	}
}


/*====================================================
  ====================================================
	ffnt_getspr_reset	ＦＦＮＴカウンタをリセット
	** :ffnt_getspr用カウンタをリセットします
	** :描画時ＳＰＲを取得前にコールしてください
====================================================
====================================================*/

void ffnt_getspr_reset(void)
{	/* ＦＦＮＴカウンタをリセット */
	ffnt.cn=0;
}



/*====================================================
  ====================================================
	ffnt_getspr	ＦＦＮＴスプライトを取得
	** :ffnt_getspr_resetで一度カウンタ初期化した後、
	** :0を返すまでこれをコールし、返したＳＰＲを登録
	** :していってください。
	in :取得したいウインドウＩＤ/FFNT_ALL..すべてのＩＤ
	out:表示すべきGsSPRITEアドレス/0..終了
====================================================
====================================================*/

SPRITE_OBJECT *ffnt_getspr(int id)
{	/* ＦＦＮＴスプライトを取得 */
	int i;

	for (i=ffnt.cn;i<FFNT_MAX;i++)	{
		ffnt.cn++;
		if	(ffnt.flg[i] &&
			 (id==FFNT_ALL || ffnt.flg[i]==id+1)) return(fspr[i]);
	}
	return(0);	/* 終了 */
}



/*====================================================
  ====================================================
	ffnt_draw	ＦＦＮＴ描画
====================================================
====================================================*/
int ftdt_mx;
void ffnt_draw(void *ot,int id,int pri)
{	/* ＦＦＮＴ描画 */
//	GsSPRITE *spr;

	SPRITE_OBJECT *spr;

	ffnt_getspr_reset();				/* ＦＦＮＴカウンタをリセット */
#ifdef DEBUG_FONT
	ftdt_mx=0;
#endif
	while((spr=ffnt_getspr(id))!=0){		/* ＦＦＮＴスプライトを取得 */
		sprobj_don(spr);
#ifdef DEBUG_FONT
		ftdt_mx+=1;
#endif
	}
#ifdef DEBUG_FONT
	FntPrint(dbg_flg.fnt[0],"FONT=%d\n",ftdt_mx);	
#endif
//		GsSortFastSprite(spr,ot,pri);

}



/*====================================================
  ====================================================
	ffnt_open	ＦＦＮＴオープン
	** :テキストを表示するウィンドウを開きます。
	in :wx,wy,ww,wh .. ウィンドウ表示左上座標、大きさ
	    (pixel.但しwwは現在ダミー。座標はFFNT_OFSX,
	    FFNT_OFSYのオフセットを受ける)
	    ft .. 表示したいテキストデータ(FTDT.EXE データ)
	out:ウィンドウＩＤ番号
====================================================
====================================================*/

int ffnt_open(int wx,int wy,int ww,int wh,u_short *ft)
{	/* ＦＦＮＴオープン */
	int i;

	for (i=0;i<FFNT_WIN;i++)	/* 空きウィンドウの取得 */
		if	(!ffnt.fw[i].wf) break;
	if	(i==FFNT_WIN) return(-1); /* 失敗 */

	ffnt.fw[i].wf=1;			/* window enable */
	ffnt.fw[i].wv=0;			/* window scroll set */
	ffnt.fw[i].ws=0;			/* window auto scroll set */
	ffnt.fw[i].wt=ft;			/* text pointer set */
	ffnt.fw[i].btn=0;			/* 特殊ボタン処理用 */
	ffnt.fw[i].pri=10;			/* 特殊ボタン処理用 */
	ffnt_xywh(i,wx,wy,ww,wh);	/* ＦＦＮＴ表示位置、範囲設定 */
	ffnt_color(i,FFNT_R,FFNT_G,FFNT_B); /* ＦＦＮＴカラー変更 */
	return(i);
}



/*====================================================
  ====================================================
	ffnt_close	ＦＦＮＴクローズ
	** :指定したウィンドウを閉じます
	in :ウィンドウＩＤ番号
====================================================
====================================================*/

void ffnt_close(int id)
{	/* ＦＦＮＴクローズ */
	int i;

	if	(ffnt.fw[id].wf) {
		for (i=0;i<FFNT_MAX;i++)	/* 使用していたＳＰＲの消去 */
			if	(ffnt.flg[i]==id+1) {
				ffnt.flg[i]=0;
				sprobj_doff(fspr[i]);
			}
		ffnt.fw[id].wf=0;
	} /* else error; */
}



/*====================================================
  ====================================================
	ffnt_xywh	ＦＦＮＴ表示位置、範囲再設定
	** :ウィンドウの位置、範囲を再設定します。
	in :id .. ウィンドウＩＤ番号
	    wx,wy,ww,wh .. ウィンドウ表示左上座標、大きさ
====================================================
====================================================*/
void ffnt_redraw(int id, u_short *ft) {
	ffnt.fw[id].wt=ft;			/* text pointer set */
	ffnt.fw[id].wf = 2;
}
void ffnt_xy(int id, int wx, int wy) {
	FFNTWIN *twin;
	
	twin = &ffnt.fw[id];
	if (twin->wf) {
		twin->wx = wx;
		twin->wy = wy;
		twin->wf = 2;
	}
}
void ffnt_xywh(int id,int wx,int wy,int ww,int wh)
{	/* ＦＦＮＴ表示位置、範囲再設定 */
	FFNTWIN	*wp;
	
	wp = &ffnt.fw[id];
	if	(wp->wf) {
		wp->wx=wx;
		wp->wy=wy;
		wp->ww=ww;
		wp->wh=wh;
		wp->wf=2;	/* redraw req. */
	} /* else error; */
}



/*====================================================
  ====================================================
	ffnt_color	ＦＦＮＴカラー変更
	** :ウィンドウフォントのカラーを設定します
	in :id .. ウィンドウＩＤ番号
	    wr,wg,wb .. カラー r,g,b (0~255)
	** :デフォルトはFFNT_R,FFNT_G,FFNT_Bです

	ffnt_color_one	ＦＦＮＴカラー変更
	** :次から描画するフォントのカラーを設定します
	in :id .. ウィンドウＩＤ番号
	    wr,wg,wb .. カラー r,g,b (0~255)
====================================================
====================================================*/

void ffnt_color_one(int id,char wr,char wg,char wb)
{	/* ＦＦＮＴカラー変更 */

	if	(ffnt.fw[id].wf) {
		ffnt.fw[id].wr=wr;
		ffnt.fw[id].wg=wg;
		ffnt.fw[id].wb=wb;
		ffnt.fw[id].wf=2;	/* redraw req. */
	} /* else error; */
}



void ffnt_color(int id,char wr,char wg,char wb)
{	/* ＦＦＮＴカラー変更 */
	int i;

	if	(ffnt.fw[id].wf) {
		ffnt.fw[id].wr=wr;
		ffnt.fw[id].wg=wg;
		ffnt.fw[id].wb=wb;
		for (i=0;i<FFNT_MAX;i++) /* 表示中のスプライトを変更 */
			if (ffnt.flg[i]==id+1) {
				fspr[i]->r=wr;
				fspr[i]->g=wg;
				fspr[i]->b=wb;
		}
	} /* else error; */
}

void ffnt_priset(int id,int pri)
{	/* ＦＦＮＴプライオリティ変更 */

	if	(ffnt.fw[id].wf) {
		ffnt.fw[id].pri=pri;
	}
}

/*====================================================
  ====================================================
	ffnt_scroll	ＦＦＮＴスクロール
	** :ウィンドウ内でのテキスト表示開始縦位置
	    をピクセル単位で変更します。
	in :id .. ウィンドウＩＤ番号
	    wv .. スクロール値
====================================================
====================================================*/

void ffnt_scroll(int id,int wv)
{	/* ＦＦＮＴスクロール */

	if	(ffnt.fw[id].wf) {
		ffnt.fw[id].wv=wv;
		ffnt.fw[id].wf=2;	/* redraw req. */
	} /* else error; */
}



/*====================================================
  ====================================================
	ffnt_gety	ＦＦＮＴ現在位置取得
	** :ＦＦＮＴテキストの現在位置を返します
	in :id .. ウィンドウＩＤ番号
	out:行数
====================================================
====================================================*/

int ffnt_gety(int id)
{	/* ＦＦＮＴ現在位置取得 */

	if	(ffnt.fw[id].wf) return(ffnt.fw[id].wv);
	/* else error; */
	return(0);
}



/*====================================================
  ====================================================
	ffnt_getvline	ＦＦＮＴ行数取得
	** :ＦＦＮＴテキストの行数を返します
	in :id .. ウィンドウＩＤ番号
	out:行数
====================================================
====================================================*/

int ffnt_getvline(int id)
{	/* ＦＦＮＴ行数取得 */
	int i,y,x;
	u_short *u,s;
	FFNTWIN *fw;

	y=0;	/* 縦位置 */
	if	(ffnt.fw[id].wf) {
		fw=&ffnt.fw[id];
		/* テキスト全文字確認 */
		u=fw->wt;	/* テキスト上ポインタ */
		x=0;		/* 横位置 */
		while((s=*u++)!=FFNT_EOF && s!=FFNT_BTN) {	/* 終了コードまで */
			if	(s==FFNT_EOL) {		/* 改行 */
				if (*u!=FFNT_EOF && *u!=FFNT_BTN) {
					y++;
					x=0;
					continue;
				}
			} else
			if	(s==FFNT_SPC) {		/* 半角空白 */
				x+=FFNT_W2;//2;
			} else {				/* 文字 */
				x+=FFNT_W2;
			}
			if	(x>=fw->ww && kin_check(s)==-1 && kin_check(*u)==-1)  {	/* 改行 */
				x=0; y++;
			}
		}
	} /* else error; */
	return(y);
}



/*====================================================
  ====================================================
	ffnt_getvmax	ＦＦＮＴ最大スクロール値取得
	** :ウィンドウのテキスト表示開始縦位置
	    の、最後尾が表示される最大値を返します
	in :id .. ウィンドウＩＤ番号
	out:スクロール値
====================================================
====================================================*/

int ffnt_getvmax(int id)
{	/* ＦＦＮＴ最大スクロール値取得 */
	int i,y;
	u_short *u,s;
	FFNTWIN *fw;

	y=0;	/* 縦位置 */
	if	(ffnt.fw[id].wf) {
		y=ffnt_getvline(id);
		y=y*FFNT_H2-ffnt.fw[id].wh+FFNT_H2;
	} /* else error; */
	return(y);
}



/*====================================================
  ====================================================
	ffnt_scroll2	ＦＦＮＴ自動スクロール
	** :ウィンドウ内でのテキスト表示開始縦位置
	    を行単位で自動変更します。
	in :id .. ウィンドウＩＤ番号
	    ws .. スクロール方向(-1:up 1:down)
	out:0..ok,-1..限界or,error
====================================================
====================================================*/

int ffnt_scroll2(int id,int ws)
{	/* ＦＦＮＴ自動スクロール */

	if	(ffnt.fw[id].wf) {
		if ((ws<0 && ffnt.fw[id].wv<=0) || 
			(ws>0 && ffnt.fw[id].wv>=ffnt_getvmax(id))) return(-1);
		ffnt.fw[id].ws=ws;
		ffnt.fw[id].wf=2;	/* redraw req. */
	} return(-1);
	return(0);
}




/*====================================================
  ====================================================
	ffnt_status	ＦＦＮＴ状態取得
	** :ＦＦＮＴ自動スクロールの状態を返します
	in :id .. ウィンドウＩＤ番号
	out:bit0:1..移動中 0..停止中
	    bit1:1..RollUp可能 0..不可
	    bit2:1..RollDown可能 0..不可
	    -1 .. 該当するＩＤのウィンドウなし
====================================================
====================================================*/

int ffnt_status(int id)
{	/* ＦＦＮＴ状態取得 */
	int flg=-1;
	if	(ffnt.fw[id].wf) {
		flg=0;
		if	(ffnt.fw[id].ws) flg|=1;
		if	(ffnt.fw[id].wv>0) flg|=2;
		if	(ffnt.fw[id].wv<ffnt_getvmax(id)) flg|=4;
	} /* else error; */
	return(flg);
}



/*====================================================
  ====================================================
	ffnt_cnv_set ＦＦＮＴメッセージ編集
	*ffnt_initでコンバートキャラ登録が初期化されます。
	in :cnv .. コンバート前のコード
	    cdt .. 挿入する文字列

	ffnt_cnv	ＦＦＮＴメッセージ編集
	in :srce .. もとの文字列
	    dest .. 出力先文字列
	out:次の書き込み先（EOFの上となる。）
====================================================
====================================================*/

void ffnt_cnv_set(u_short cnv,u_short *cdt)
{	/* コンバートキャラ登録 */
	int i;

	for	(i=0;i<ffnt.cnvs;i++) if (ffnt.cnv[i]==cnv) break;	/* 更新 */
	if	(i<FFNT_CNVMAX) {
		ffnt.cnv[i]=cnv;
		ffnt.cdt[i]=cdt;
		if	(i==ffnt.cnvs) ffnt.cnvs++; /* 新規 */
	} /* else error; */
}

u_short *ffnt_cnv(u_short *srce,u_short *dest)
{	/* ＦＦＮＴメッセージ編集 */
	int i;
	u_short s;

	while((s=*srce++)!=FFNT_EOF) {	/* 終了コードまで */
		for	(i=0;i<ffnt.cnvs;i++) if (ffnt.cnv[i]==s) break;
		if (i<ffnt.cnvs) dest=ffnt_cnv(ffnt.cdt[i],dest);	/* 再帰コンバート */
		else if (s==FFNT_EOL && *srce==FFNT_EOF) ;	/* EOF前のEOL */
		else *dest++=s;
	}
	*dest=s;
	return(dest);
}



void ffnt_set_padfunc(int (*padfunc)())
{	/* 特殊ボタン判定用関数の登録 */
	ffnt.padfunc=padfunc;
}

/*====================================================
  ====================================================
	ffnt_change ＦＦＮＴ任意文字変換
	** :tmp\namefont.txt文字を使った文字の
	    ffnt文字番号にして返します。
	in :s    .. もとの全角文字
	    dest .. 出力先文字列
	out:ffnt文字番号

	ffnt_changes ＦＦＮＴ任意文字列変換
	** :tmp\namefont.txt文字を使った文字配列を
	    ffntデータに変換します。
	    半角スペースはFFNT_SPCとして、その他半角の
	    一部は大文字にして返します。
	in :srce .. もとの文字列
	    dest .. 出力先文字列
	out:次の書き込み先（EOFの上となる。）
====================================================
====================================================*/
/* 下の文字配列は"/MAST_MOJI"から持ってくること */
/* ただし、「ソ」については「\x82\x5c」に直すこと */
static char fcdt[]="
　゛゜，．・：；？！（）＋－＝￥
＄％＆０１２３４５６７８９ＡＢＣ
ＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳ
ＴＵＶＷＸＹＺａｂｃｄｅｆｇｈｉ
ｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙ
ｚぁあぃいぅうぇえぉおかきくけこ
さしすせそたちっつてとなにぬねの
はひふへほまみむめもゃやゅゆょよ
らりるれろゎわをんァアィイゥウェ
エォオカキクケコサシスセ\x83\x5cタチッ
ツテトナニヌネノハヒフヘホマミム
メモャヤュユョヨラリルレロヮワヲ
ンヵヶー～［］｛｝〈〉＃＊＠☆★
がぎぐげござじずぜぞだぢづでどば
びぶべぼガギグゲゴザジズゼゾダヂ
ヅデドバビブベボぱぴぷぺぽパピプ
ペポ
";

u_short ffnt_change(u_short s)
{	/* ＦＦＮＴ任意文字変換 */
	int i=0,j=-1;

	while(fcdt[i]){
		if(fcdt[i]=='\n'){
			i++;
		}else{
			j++;
			if((s>>8)==fcdt[i] && (s&0x00FF)==fcdt[i+1])	return(j);
			i+=2;
		}
	}
	return(0);	/* not found */
}


u_short *ffnt_changes(char *srce,u_short *dest)
{	/* ＦＦＮＴ任意文字列変換 */
	/* 変換可能な半角文字リスト:tmp\namefont.txtにある文字のみ。 */
	static char large[]={"，．：（）＋－＝％＆０１２３４５"
						 "６７８９ＡＢＣＤＥＦＧＨＩＪＫＬ"
						 "ＭＮＯＰＱＲＳＴＵＶＷＸＹＺａｂ"
						 "ｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒ"
						 "ｓｔｕｖｗｘｙｚ［］｛｝〈〉＃＊"};
	static char small[]={",.:()+-=%&012345"
						 "6789ABCDEFGHIJKL"
						 "MNOPQRSTUVWXYZab"
						 "cdefghijklmnopqr"
						 "stuvwxyz[]{}<>#*"};
	int i;
	char c;
	u_short *adr;
	u_short s,t;
	short wk;

	while((c=*srce++)!=0) {	/* 終了コードまで */
		if(c==' '){
			*dest++=FFNT_SPC;	/* 半角SPC */
		}
		else if(c<0x80){	/* 半角の一部 */
			for (i=0;c!=small[i] && small[i]!=0;i++);
			if(small[i]!=0){
//				 *dest++=ffnt_change((large[i*2]<<8)|large[i*2+1]);

				 wk=ffnt_change((large[i*2]<<8)|large[i*2+1]);
//				 adr=&fnt_data[0]+(wk*2)+((wk/16)*2);
				 adr=(u_short *)&fnt_data[(wk*2)+((wk/16)*2)];

				 *dest++=*adr;
			}
			else break; /* not found */
		} else {	/* 全角文字 */
//			*dest++=(ffnt_change((c<<8)|(*srce++));

			wk=ffnt_change((c<<8)|(*srce++));
//			adr=&fnt_data[0]+(wk*2)+((wk/16)*2);
			adr=(u_short *)&fnt_data[(wk*2)+((wk/16)*2)];

			*dest++=*adr;
		}
	}
	*dest=FFNT_EOF;

	return(dest);
}



/*====================================================
  ====================================================
	ffnt_fun_set ＦＦＮＴ特殊処理登録
	*ffnt_initで登録が初期化されます。
	in :fun .. 特殊処理を呼び出すコード
	    fdt .. 挿入する文字列
====================================================
====================================================*/

void ffnt_fun_set(u_short fun,int (*fdt)(u_short))
{	/* 特殊処理登録 */
	int i;

	for	(i=0;i<ffnt.funs;i++) if (ffnt.fun[i]==fun) break;	/* 更新 */
	if	(i<FFNT_FUNMAX) {
		ffnt.fun[i]=fun;
		ffnt.fdt[i]=fdt;
		if	(i==ffnt.funs) ffnt.funs++; /* 新規 */
	} /* else error; */
}



/*====================================================
  ====================================================
	ffnt_kin_set ＦＦＮＴ禁則処理登録
	*ffnt_initで登録が初期化されます。
	in :kin .. 禁則処理する文字列
====================================================
====================================================*/

void ffnt_kin_set(u_short *kin)
{	/* 禁則処理登録 */
	int i;

	for	(i=0;kin[i]!=FFNT_EOF && kin[i]!=FFNT_EOL && i<FFNT_KINMAX;i++)
		ffnt.kin[i]=kin[i];
	ffnt.kins=i;
}

