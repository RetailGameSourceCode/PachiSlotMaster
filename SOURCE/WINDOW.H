/*===================================================
	window.h
	
	射手矢さんライブラリ上での簡易矩形取扱い関連
		のヘッダ
	
						作ってる人		T. Kawakami
						作り出した日	20th Nov. '98
====================================================*/
#ifndef _WINDOW_H_
#define _WINDOW_H_

#define	HIDE_XOFS	320	//	Ｘ方向待避オフセット 
#define	HIDE_YOFS	240	//	Y方向待避オフセット 

enum	WMODE {
	WINMODE_NOP,
	WINMODE_MOVE,
	WINMODE_MOVE_DEL,
	WINMODE_APP,
	WINMODE_DISAPP_DEL,
	WINMODE_DEL,
};

#define	WIN_CHG_SYNC	12
#define	WINDOW_MAX		64

struct	_WINDOW {
	POLY_F4		*pp;		// 板 
	LINE_F2		*l2p[7];	// 枠 
	LINE_F4		*l4p[3];	// 枠 
	struct	_WINDOW		*before;
	struct	_WINDOW		*next;
	int			moji_id[16];
	int			work[8];
	void		*func;
	void		*wwp;
	short		f_step;
	short		cnt, scnt;
	short		x, y;
	short		w, h;
	short		dx, dy;
	short		dw, dh;
	short		sx, sy;
	short		sw, sh;
	short		pri;
	char		active;
	char		mode;
	char		moji_max;	// 文字パネル数 
};
typedef	struct	_WINDOW	WINDOW;

WINDOW	*make_window(short, short, short, short, short, void *);
WINDOW	*rackwin[8];

#endif
