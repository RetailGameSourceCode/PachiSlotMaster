
#ifndef _KKFFNT_H_

#define _KKFFNT_H_

#ifdef EXT
#undef EXT
#endif
#ifdef _KKFFNT_H_
#define EXT
#else
#define EXT extern
#endif

/*====================================================
 definition
====================================================*/
//#define FFNT_MAX	(448)	/* 最大文字数 */
#define FFNT_MAX	(512)	/* 最大文字数 */
#define FFNT_WIN	(32)		/* 最大ウィンドウ数 */
#define FFNT_LV		(4)		/* FTXTにより変更不可:４重合成ＦＯＮＴを意味 */
#define FFNT_W		(16)	/* FTXTにより変更不可:フォントサイズ w */
#define FFNT_WW		(16)	/* FTXTにより変更不可:一行の文字数 */
#define FFNT_H		(14)	/* FTXTにより変更不可:フォントサイズ h */
#define FFNT_W2		(16)	/* 桁幅 */
#define FFNT_H2		(16)	/* 改行幅 */
#define FFNT_R		(0x04)	/* 初期カラー r */
#define FFNT_G		(0x04)	/* 初期カラー g */
#define FFNT_B		(0x04)	/* 初期カラー b */
#define FFNT_OFSX	(0)		/* 表示位置オフセット x */
#define FFNT_OFSY	(0)		/* 表示位置オフセット y */
#define FFNT_SPD	(2)		/* 自動スクロールスピード */
#define FFNT_CNVMAX (16)	/* 変換特殊キャラ登録最大数 */
#define FFNT_KINMAX  (8)	/* 禁則処理キャラ登録最大数 */
#define FFNT_FUNMAX (10)	/* 特殊処理キャラ登録最大数 */

#define FFNT_ALL	(1024)	/* ffnt_getspr用、すべてのＩＤを指定 */

#define FFNT_EOF (0xffff)	/* FTDT.EXE出力のテキストデータＥＯＦ */
#define FFNT_EOL (0xfffe)	/* FTDT.EXE出力のテキストデータＥＯＬ */
#define FFNT_SPC (0xfffd)	/* FTDT.EXE出力のテキストデータ半角空白 */
#define FFNT_BTN (0xfff8)	/* 特殊ボタン処理 */

/*====================================================
 work
====================================================*/
//EXT void *fnt_data;
EXT u_char fnt_data[BIN_TEXT_SIZE];

/*====================================================
 prottype
====================================================*/

EXT void ffnt_init(int px,int py,int cx,int cy);			/* ＦＦＮＴ初期化 */
EXT void ffnt_end(void);									/* ＦＦＮＴ終了 */
EXT void ffnt_drv(void);									/* ＦＦＮＴ表示更新ドライバ */
EXT void ffnt_getspr_reset(void);							/* ＦＦＮＴカウンタをリセット */
EXT SPRITE_OBJECT *ffnt_getspr(int id);						/* ＦＦＮＴスプライトを取得 */
EXT void ffnt_draw(void *ot,int id,int pri);				/* ＦＦＮＴ描画 */
EXT int ffnt_open(int wx,int wy,int ww,int wh,u_short *ft);	/* ＦＦＮＴオープン */
EXT void ffnt_close(int id);								/* ＦＦＮＴクローズ */
EXT void ffnt_xywh(int id,int wx,int wy,int ww,int wh);		/* ＦＦＮＴ表示位置、範囲再設定 */
EXT void ffnt_color_one(int id,char wr,char wg,char wb);	/* ＦＦＮＴカラー変更 */
EXT void ffnt_color(int id,char wr,char wg,char wb);		/* ＦＦＮＴウカラー変更 */
EXT void ffnt_scroll(int id,int wv);						/* ＦＦＮＴスクロール */
EXT int ffnt_gety(int id);									/* ＦＦＮＴ現在位置取得 */
EXT int ffnt_getvline(int id);								/* ＦＦＮＴ行数取得 */
EXT int ffnt_getvmax(int id);								/* ＦＦＮＴ最大スクロール値取得 */
EXT int ffnt_status(int id);								/* ＦＦＮＴ状態取得 */
EXT int ffnt_scroll2(int id,int ws);						/* ＦＦＮＴ自動スクロール */
EXT void ffnt_cnv_set(u_short cnv,u_short *cdt);			/* コンバートキャラ登録 */
EXT u_short *ffnt_cnv(u_short *srce,u_short *dest);			/* ＦＦＮＴメッセージ編集 */
EXT void ffnt_set_padfunc(int (*padfunc)());				/* 特殊ボタン判定用関数の登録 */
EXT u_short ffnt_change(u_short s);							/* ＦＦＮＴ任意文字変換 */
EXT u_short *ffnt_changes(char *srce,u_short *dest);		/* ＦＦＮＴ任意文字列変換 */
EXT void ffnt_fun_set(u_short fun,int (*fdt)(u_short));		/* 特殊処理登録 */
EXT void ffnt_kin_set(u_short *kin);						/* 禁則処理登録 */
EXT void ffnt_priset(int id,int pri);

#endif

