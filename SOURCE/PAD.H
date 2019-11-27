
#ifndef	_PAD_H_

#define	_PAD_H_

//使用種別定義///////////////////////////////////////////////////////////
#define NORMAL_PAD		//	何も考えずに使う時
//#define MULTI_PAD			//	マルチパッドを使用するとき
//#define EXCHENGE_PAD	//	パッドの内容を入れ替えて使う時

/////////////////////////////////////////////////////////////////////////


#define	BETA	0
#define	RPT		1
#define	CNT		2
#define	TRG		3

#define pad_beta	Paddata[BETA]
#define pad_rpt		Paddata[RPT]
#define pad_cnt		Paddata[CNT]
#define pad_trg		Paddata[TRG]

extern u_long	Paddata[4];
extern short	Padbuf[16];
extern char pad_toreru;
extern void pad_toreruyo(char data);

extern void pad_init(void);
extern u_short pad_read(void);
extern void pad_shibireru(void);
extern void pad_shibirenai(void);
extern void pad_stop(void);

#ifdef NORMAL_PAD
//	パッド関連
#define PAD_UP		0x1000
#define PADL_UP		0x1000
#define PADL_U		0x1000
#define PAD_DOWN	0x4000
#define PADL_DOWN	0x4000
#define PADL_D		0x4000
#define PAD_LEFT	0x8000
#define PADL_LEFT	0x8000
#define PADL_L		0x8000
#define PAD_RIGHT	0x2000
#define PADL_RIGHT	0x2000
#define PADL_R		0x2000
#define PAD_SANKAKU	0x0010
#define PADR_UP		0x0010
#define PADR_U		0x0010
#define PAD_PEKE	0x0040
#define PAD_BATSU	0x0040
#define PADR_DOWN	0x0040
#define PADR_D		0x0040
#define PAD_SHIKAKU	0x0080
#define PADR_LEFT	0x0080
#define PADR_L		0x0080
#define PAD_MARU	0x0020
#define PADR_RIGHT	0x0020
#define PADR_R		0x0020
#define PAD_SELECT	0x0100
#define PAD_START	0x0800
#define PAD_L1		0x0004
#define PAD_L2		0x0001
#define PAD_R1		0x0008
#define PAD_R2		0x0002
#define PAD_ALL		0xFFFF

#endif

#ifdef EXCHENGE_PAD

#define	PAD_USE_MAX	14
extern short pad_use_data[PAD_USE_MAX];
extern short pad_use[PAD_USE_MAX];

#define CON_UP		0x1000
#define CON_DOWN	0x4000
#define CON_LEFT	0x8000
#define CON_RIGHT	0x2000
#define CON_SANKAKU	0x0010
#define CON_PEKE	0x0040
#define CON_SHIKAKU	0x0080
#define CON_MARU	0x0020
#define CON_L1		0x0004
#define CON_L2		0x0001
#define CON_R1		0x0008
#define CON_R2		0x0002
#define CON_SEL		0x0100
#define CON_START	0x0800

#define PADL_UP		pad_use[0]
#define PADL_U		pad_use[0]
#define PAD_UP		pad_use[0]
#define PADL_DOWN	pad_use[1]
#define PADL_D		pad_use[1]
#define PAD_DOWN	pad_use[1]
#define PADL_LEFT	pad_use[2]
#define PADL_L		pad_use[2]
#define PAD_LEFT	pad_use[2]
#define PADL_RIGHT	pad_use[3]
#define PADL_R		pad_use[3]
#define PAD_RIGHT	pad_use[3]
#define PADR_UP		pad_use[4]
#define PADR_U		pad_use[4]
#define PAD_SANKAKU	pad_use[4]
#define PADR_DOWN	pad_use[5]
#define PADR_D		pad_use[5]
#define PAD_BATSU	pad_use[5]
#define PAD_PEKE	pad_use[5]
#define PADR_LEFT	pad_use[6]
#define PADR_L		pad_use[6]
#define PAD_SHIKAKU	pad_use[6]
#define PADR_RIGHT	pad_use[7]
#define PADR_R		pad_use[7]
#define PAD_MARU	pad_use[7]
#define PAD_L1		pad_use[8]
#define PAD_L2		pad_use[9]
#define PAD_R1		pad_use[10]
#define PAD_R2		pad_use[11]
#define PAD_SELECT	pad_use[12]
#define PAD_START	pad_use[13]

#endif

#endif

