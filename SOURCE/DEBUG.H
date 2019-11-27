
#ifndef _DEBUG_H_

#define _DEBUG_H_

#if	DEBUG_MODE==1

#define	DBG_MODE_MAX	3		//	ÇPÅ`ÇS
typedef struct {
	int			fnt[4];
	char		cd_mode;
	char		mode;
	char		point;
	char		font;
	char		line;
	char		fram;
}	DEBUG_FLAG;

extern	DEBUG_FLAG dbg_flg;
extern	POLY_G4		*db_g4;

extern	void dbgflg_clr(void);
extern void debug_vsync(void);
extern void deb_stop(void);
extern void deb_stop2(long);
extern void deb_stop3(long);
extern void deb_ka(long no);
extern void deb_hi(long no1,long no2);
#define DEB_STOP deb_stop();
#define DEB_STOP2 deb_stop2
#define DEB_STOP3 deb_stop3
#define DEB_KA deb_ka
#define DEB_HI deb_hi


extern char debs1;
extern char debs2;
extern char debs3;
extern char debs4;
extern char debs5;


#ifdef	DEBUG_FONT	///////////////////////////////////////////////////////////

extern void dbg_fntset(void);
extern void dbfb_xyset(void);
extern void font_flash(void);

#endif	//	DEBUG_FONT END

#ifdef DEBUG_LINE	///////////////////////////////////////////////////////////

extern void func_line(void);

#endif	//	DEBUG_LINE END

#ifdef	DEBUG_FRAM	///////////////////////////////////////////////////////////
extern	short	dispx;
extern	short	dispy;
extern	short	spd;

extern void frame_buf_look(void);
#endif	//	DEBUG_FRAM END

#ifdef	DEBUG_POLY	///////////////////////////////////////////////////////////

extern int	select[3];
extern void poly_debug(void);
extern void poly_debug1(void);

#endif	//	DEBUG_POLY END

#endif	//	DEBUG_MODE END

#endif


