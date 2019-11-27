
#ifndef _INIT_H_

#define _INIT_H_

//#define HEAP_TOP	(0x8015c000)	//ヒープエリアの先頭アドレス
#define HEAP_TOP	(0x80151040)	//ヒープエリアの先頭アドレス
#define HEAP_SIZE	(0x80200000-(HEAP_TOP+0x00010000))	//ヒープエリアのサイズ
//#define HEAP_SIZE	(0x000e0000)	//ヒープエリアのサイズ

extern void *anm_adr,*atime_adr;
extern char wind_w;

extern void initSystem(void);	//	システム全体の初期化
extern void cbvsync(void);		//	Ｖ－ＳＹＮＣコールバック関数
extern void pad_init_local(void);


extern void draw_init(void);	//	ＤＲＡＷ初期化
extern void vramclear(int,int,int);	//	ＶＲＡＭクリアー
extern void video320(void);
extern void video512(void);
extern void video640(void);
extern void mode_init(void);
extern void game_init(void);	//	ゲームに使うパラメータ初期化

#endif

