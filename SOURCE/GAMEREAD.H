
#ifndef _GAMEREAD_H_

#define _GAMEREAD_H_

#define	D_DEF_CLUT_X	drum_tex_data[ZOOM_LEVEL][0]
#define	D_DEF_CLUT_Y	drum_tex_data[ZOOM_LEVEL][1]
#define D_DEF_TIM_X		drum_tex_data[ZOOM_LEVEL][2]
#define D_DEF_TIM_Y		drum_tex_data[ZOOM_LEVEL][3]
#define D_DEF_TIM_W		drum_tex_data[ZOOM_LEVEL][4]
#define D_DEF_TIM_H		drum_tex_data[ZOOM_LEVEL][5]

#define DK_SEVEN	(0)
#define DK_HYOUTAN	(1)
#define DK_KAPPA	(2)
#define DK_OYAKO	(3)
#define DK_KYUURI	(4)
#define DK_SAKE		(5)
#define DK_TSUKI	(6)

#define DB_BINBOU	(0)
#define DB_KAMI		(1)
#define DB_KOZUCHI	(2)
#define DB_CHERRY	(3)
#define DB_SEVEN	(4)
#define DB_SUZU		(5)
#define DB_YAMA		(6)

struct _VERT{
	long	hed;
	char	u0;
	char	v0;
	short	cba;
	char	u1;
	char	v1;
	short	tsb;
	char	u2;
	char	v2;
	short	dum1;
	char	u3;
	char	v3;
	short	dum2;
	short	norm0;
	short	vert0;
	short	norm1;
	short	vert1;
	short	norm2;
	short	vert2;
	short	norm3;
	short	vert3;
};
typedef struct _VERT VERTS;

struct _VERTEX_{
	short vx;
	short vy;
	short vz;
	short dummy;
};
typedef struct _VERTEX_ VERTEXS;

extern void slot_tex_set(int);
extern void slot_data_read(void);

extern unsigned long A_TMD[3][1151];
extern void *dig_s;
extern char dig_r[4];

extern short drum_tex_data[3][6];
extern char	toggle_start_ok;
extern VERTS *ve[3][21];


#endif

