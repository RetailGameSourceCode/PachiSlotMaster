
#ifndef _TYPEDEF_H_

#define _TYPEDEF_H_

//	ＤＲＡＷ.Ｃ	で使用
#ifdef ssss
struct _OBJECT_TREE{ 
	u_short	type;		// 構造体の種類 
	void	*point;		// システム予約	//	ＯＢＪの構造体アドレス 
	void	*before;	// システム予約	//	前のＯＢＪの木 
	void	*next;		// システム予約	//	次のＯＢＪの木 
}; 
typedef struct _OBJECT_TREE OBJECT_TREE; 
#endif 
 
/* ＢＧ登録時に渡す構造体 */ 
typedef struct{ 
	u_long	attribute;		//	このＢＧの属性 
	short	screenw,screenh;//	画面表示ＸＹサイズ (fixbg_makeなら無視) 
	u_char	cellw,cellh;	//	セルのＸＹサイズ(ピクセル単位) (fixbg_makeなら無視) 
	u_short	bgw,bgh;		//	ＢＧデータのＸＹサイズ(セル単位) 
	u_short	pri;			//	このＢＧ面のプライオリティー 
}BGINFO; 
 
/* ＢＧコントローラ */ 
typedef struct{ 
	u_short	flg;		/* エントリーフラグ */ 
	u_short	pri;		/* このＢＧ面のプライオリティー */ 
	u_long	*work;		/* 作業領域アドレス */ 
}BGCTRL; 
 
 
typedef struct{ 
	short x,y; 
}POSXY; 
 
//	偽ポリゴン用 
struct _POLY_LST{ 
	u_long attribute;			// 属性 
	u_short pri;				// 表示優先度 
	u_short type;				// POLY_??? プリミティブの種類 
	long	work[4]; 
	void *poly;					// POLY_??? プリミティブ本体のポインタ 
	struct _POLY_LST *before;	// 前のリストへのポインタ 
	struct _POLY_LST *next;		// 次のリストへのポインタ 
}; 
typedef struct _POLY_LST POLY_LST; 
 
//	８ｂｉｔポート用 
 
struct _EIGHT_PORT{ 
		unsigned	bit7	:1; 
		unsigned	bit6	:1; 
		unsigned	bit5	:1; 
		unsigned	bit4	:1; 
		unsigned	bit3	:1; 
		unsigned	bit2	:1; 
		unsigned	bit1	:1; 
		unsigned	bit0	:1; 
};typedef struct _EIGHT_PORT EIGHT_PORT; 
 
struct _SAVE_DATA{ 
	char dummy;
};typedef struct _SAVE_DATA SAVE_DATA; 
 
 
#endif 


