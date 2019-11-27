#include "common.h"
#include "work.h"
#include "libmcrd.h"

#if	DEBUG_MODE==1
DEBUG_FLAG dbg_flg;	//	デバッグ用フラグ全般
POLY_G4		*db_g4;

extern int lu_r1;
extern int lu_r2;
extern int lu_l1;
extern int lu_l2;


void deb_stop(void)
{
	wait(2);
	while(1){
		if(pad_cnt & PAD_L2)	break;
#ifdef	DEBUG_FONT
		FntPrint(dbg_flg.fnt[0],"\nSTOP ! PUSH PAD_L2!!\n");
#endif
		wait(1);
	}
	wait(2);

}


//#define DEB_STOP2 deb_stop2
void deb_stop2(long no)
{
	wait(2);
	while(1){
		if(pad_cnt & PAD_L2)	break;
#ifdef	DEBUG_FONT
		FntPrint(dbg_flg.fnt[0],"\nHYOUJI = %d\n",no);
		FntPrint(dbg_flg.fnt[0],"STOP ! PUSH PAD_L2!!\n");
#endif
		wait(1);
	}
	wait(2);

}


//#define DEB_STOP3 deb_stop3
void deb_stop3(long no)
{
	wait(2);
	while(1){
		if(pad_cnt & PAD_L2)	break;
#ifdef	DEBUG_FONT
		FntPrint(dbg_flg.fnt[0],"\nHYOUJI1 = %d\n",no);
		FntPrint(dbg_flg.fnt[0],"HYOUJI2 = %x\n",no);
		FntPrint(dbg_flg.fnt[0],"STOP ! PUSH PAD_L2!!\n");
#endif
		wait(1);
	}
	wait(2);

}


//#define DEB_KA deb_ka
void deb_ka(long no)
{
#ifdef	DEBUG_FONT
		FntPrint(dbg_flg.fnt[0],"\nHYOUJI1 = %d\n",no);
		FntPrint(dbg_flg.fnt[0],"HYOUJI2 = %x\n",no);
#endif
}

//#define DEB_HI deb_hi
void deb_hi(long no1,long no2)
{
	wait(2);
	while(1){
		if(pad_cnt & PAD_L2)	break;
#ifdef	DEBUG_FONT
		FntPrint(dbg_flg.fnt[0],"\nHYOUJI = %02x,%02x\n",no1,no2);
		FntPrint(dbg_flg.fnt[0],"STOP ! PUSH PAD_L2!!\n");
#endif
		wait(1);
	}
	wait(2);

}




void dbgflg_clr(void)
{
	int lp;

	for(lp=0;lp<4;lp++)	dbg_flg.fnt[lp]=NULL;
	dbg_flg.mode=0;
	dbg_flg.point=0;
	dbg_flg.font=0;
	dbg_flg.line=0;
	dbg_flg.fram=0;
	dbg_flg.cd_mode=READ_MODE;

#ifdef	DEBUG_FONT
	dbg_fntset();
	mal_l=0;
#endif
#ifdef	DEBUG_POLY
	select[0]=0;
	select[1]=0;
	select[2]=0;
#endif

}


char debs1;
char debs2;
char debs3;
char debs4;
char debs5;

char pii=0;
extern int cn2;
//extern int slno;
extern WINDOW	*yn_p;
extern int spc;
extern char zura[3];

extern char	_FL_REJ_PIC;
extern char	_WK_ALL_PIC;
extern char	binreach_tbl[];
extern char	kapreach_tbl[];
extern char	K_ALL;

extern signed char	submenu_sts;		// サブメニューステップ 
extern char backl;

//	Ｖ－Ｓｙｎｃ中に行うデバッグ
void debug_vsync(void)
{
	int lp;

#ifdef DEBUG_FRAM
	frame_buf_look();
#endif

#ifdef DEBUG_FONT
	FntPrint(dbg_flg.fnt[0],"\nPAD_M=%d\n",pikapika);
	FntPrint(dbg_flg.fnt[0],"SUB=%d\n",submenu_sts);
	FntPrint(dbg_flg.fnt[0],"MCM=%d\n",mc_mode);

	FntPrint(dbg_flg.fnt[0],"\nBLAMP=%d\n",_WK_BACK_LP.lamp);
	FntPrint(dbg_flg.fnt[0],"PT7=%02x\n",_PT_OUT7&0x80);
	FntPrint(dbg_flg.fnt[0],"PT8=%02x\n",_PT_OUT8);

#if 0
	FntPrint(dbg_flg.fnt[0],"\nSTOP_LP=%02x\n",_FL_STOP_LP);
	FntPrint(dbg_flg.fnt[0],"STOP_PN=%02x\n",_FL_STOP_PNT);
	FntPrint(dbg_flg.fnt[0],"STOP_BF=%02x\n",_BF_STOP_CTL);
	FntPrint(dbg_flg.fnt[0],"STOP_RL=%02x\n",_NB_STOP_REEL);
	FntPrint(dbg_flg.fnt[0],"ORDER=%02x\n",_NB_STOP_ORDER);


//	FntPrint(dbg_flg.fnt[0],"ME0=%02x\n",kapreach_tbl[_WK_REEL[0][5]+(_WK_REEL[1][5]*21)+(_WK_REEL[2][5]*441)]);
//	FntPrint(dbg_flg.fnt[0],"ME1=%02x\n",binreach_tbl[_WK_REEL[0][5]+(_WK_REEL[1][5]*21)+(_WK_REEL[2][5]*441)]);

	FntPrint(dbg_flg.fnt[0],"\nBLAMP=%02x\n",_WK_BACK_LP.lamp);
	FntPrint(dbg_flg.fnt[0],"FLAMP=%02x\n",_WK_FLASH_LP.lamp);
	FntPrint(dbg_flg.fnt[0],"ELAMP=%02x\n",_WK_EFFECT_LP.lamp);
	FntPrint(dbg_flg.fnt[0],"WLAMP=%02x\n",_WK_WIN_LP);
	FntPrint(dbg_flg.fnt[0],"PT7=%02x\n",_PT_OUT7);
	FntPrint(dbg_flg.fnt[0],"PT8=%02x\n",_PT_OUT8);
	FntPrint(dbg_flg.fnt[0],"WK1=%02x\n",_WK_WINBACK_LP[1]);
	FntPrint(dbg_flg.fnt[0],"WK0=%02x\n",_WK_WINBACK_LP[0]);

	FntPrint(dbg_flg.fnt[0],"HDI=%d\n",hd_inter);
	FntPrint(dbg_flg.fnt[0],"SUB=%d\n",submenu_sts);
	FntPrint(dbg_flg.fnt[0],"MES=%d\n",mesp_sts);

	FntPrint(dbg_flg.fnt[0],"RP0=%d\n",rep_step[0]);
	FntPrint(dbg_flg.fnt[0],"CB=%d\n",user_rate[0]);
	FntPrint(dbg_flg.fnt[0],"CR=%d\n",user_rate[1]);

	FntPrint(dbg_flg.fnt[0],"S0=%02x\n",_CT_IN_OUT[0]);
	FntPrint(dbg_flg.fnt[0],"S1=%02x\n",_CT_IN_OUT[1]);
	FntPrint(dbg_flg.fnt[0],"TK=%02x\n",tei_kou);
	FntPrint(dbg_flg.fnt[0],"REAC=%02x\n",reach_me);
	FntPrint(dbg_flg.fnt[0],"BING=%02x\n",bingo_flag);
	FntPrint(dbg_flg.fnt[0],"OUCH=%02x\n",ouch_flag);
	FntPrint(dbg_flg.fnt[0],"NEVE=%02x\n",never_bingo_flag);
	FntPrint(dbg_flg.fnt[0],"MURI=%02x\n",muriyari_ateru);
	FntPrint(dbg_flg.fnt[0],"WIND=%d\n",mesp_p->f_step);
	FntPrint(dbg_flg.fnt[0],"WIND=%d\n",mesp_sts);


//	FntPrint(dbg_flg.fnt[0],"=%02x \n",_FL_STOP_PNT);
//	FntPrint(dbg_flg.fnt[0],"STP=%02x \n",_FL_STOP_PNT);

	FntPrint(dbg_flg.fnt[0],"FL=%02x,%02x,%02x,\n",sta[0][0],sta[1][0],sta[2][0]);
	FntPrint(dbg_flg.fnt[0],"FL=%02x,%02x,%02x,\n",sta[0][1],sta[1][1],sta[2][1]);
	FntPrint(dbg_flg.fnt[0],"FL=%02x,%02x,%02x,\n",sta[0][2],sta[1][2],sta[2][2]);
	FntPrint(dbg_flg.fnt[0],"FL=%02x,%02x,%02x,\n",sta[0][3],sta[1][3],sta[2][3]);

	if(pad_cnt&PADR_UP) pii=(pii+1)%15;

	FntPrint(dbg_flg.fnt[0],"NO  =%d \n",pii);
	FntPrint(dbg_flg.fnt[0],"ALF =%d \n",alf);
	FntPrint(dbg_flg.fnt[0],"ALF2=%d \n",alf2);
	FntPrint(dbg_flg.fnt[0],"NAME=%s \n",dirent[pii].name);
	FntPrint(dbg_flg.fnt[0],"NAME=%s \n",dirent2[pii].name);

	FntPrint(dbg_flg.fnt[0],"ATTR=%d \n",dirent[pii].attr);
	FntPrint(dbg_flg.fnt[0],"SIZE=%d \n",dirent[pii].size);
	FntPrint(dbg_flg.fnt[0],"HEAD=%d \n",dirent[pii].head);
	FntPrint(dbg_flg.fnt[0],"SYS =%d,%d,%d,%d \n",dirent[pii].system[0],dirent[pii].system[1],dirent[pii].system[2],dirent[pii].system[3]);
	FntPrint(dbg_flg.fnt[0],"SAVE2=%d \n",sizeof(SAVE2));
#endif

#if 1
//	最新
//	&yn_p=NULL;
//	(WINDOW	*)yn_p=123;
#if 0

	FntPrint(dbg_flg.fnt[0],"SC=%x,%x,%x,%x,%x\n",_WK_STOP_PIC1[0],_WK_STOP_PIC1[1],_WK_STOP_PIC1[2],_WK_STOP_PIC1[3],_WK_STOP_PIC1[4]);
	FntPrint(dbg_flg.fnt[0],"SC=%x,%x,%x,%x\n",_WK_REEL_PIC1[0],_WK_REEL_PIC1[1],_WK_REEL_PIC1[2],_WK_REEL_PIC1[3]);
	FntPrint(dbg_flg.fnt[0],"SC=%x,%x,%x\n",_WK_REEL_PIC1[4],_WK_REEL_PIC1[5],_WK_REEL_PIC1[6]);
	FntPrint(dbg_flg.fnt[0],"SP=%x,%x \n",_FL_STOP_PNT,_NB_STOP_REEL);
	FntPrint(dbg_flg.fnt[0],"SB=%x,%x,%x\n",_NB_REJECT,zura[1],zura[2]);
	FntPrint(dbg_flg.fnt[0],"FL=%x,%x,%x\n",_FL_REJ_PIC,_WK_ALL_PIC,K_ALL);

	FntPrint(dbg_flg.fnt[0],"REACH=%x NEV_BIN=%x \n",reach_me,never_bingo_flag);
	FntPrint(dbg_flg.fnt[0],"PLAY=%d PK=%d\n",play_mode,play_num);

	FntPrint(dbg_flg.fnt[0],"TORI=%d \n",torikoboshi);
	FntPrint(dbg_flg.fnt[0],"MACINE=%d \n",MACINE);
	FntPrint(dbg_flg.fnt[0],"RANK=%d ",_NB_RANK);
	FntPrint(dbg_flg.fnt[0],"KERU=%x\n",_FL_STOP_PNT);
	FntPrint(dbg_flg.fnt[0],"REJECT=%x\n",_NB_REJECT);
	FntPrint(dbg_flg.fnt[0],"ACT = %02x ",_FL_ACTION);
	FntPrint(dbg_flg.fnt[0],"WIN = %02x\n",_FL_WIN);
	FntPrint(dbg_flg.fnt[0],"ALL1=%02x ",_WK_ALL_PIC1);
	FntPrint(dbg_flg.fnt[0],"ALL2=%02x\n",_WK_ALL_PIC2);
	FntPrint(dbg_flg.fnt[0],"PUL1=%02x ",_FL_PUL_PIC1);
	FntPrint(dbg_flg.fnt[0],"REJ1=%02x\n",_FL_REJ_PIC1);
	FntPrint(dbg_flg.fnt[0],"PUL2=%02x ",_FL_PUL_PIC2);
	FntPrint(dbg_flg.fnt[0],"REJ2=%02x\n",_FL_REJ_PIC2);
	FntPrint(dbg_flg.fnt[0],"STP=%d CHK=%d\n",_BF_PICTURE,chk);
	FntPrint(dbg_flg.fnt[0],"%d ",_WK_REEL[0][0]);
	FntPrint(dbg_flg.fnt[0],"RL05=%d ",_WK_REEL[0][5]);
	FntPrint(dbg_flg.fnt[0],"RL06=%d\n",_WK_REEL[0][6]);
	FntPrint(dbg_flg.fnt[0],"%d ",_WK_REEL[1][0]);
	FntPrint(dbg_flg.fnt[0],"RL15=%d ",_WK_REEL[1][5]);
	FntPrint(dbg_flg.fnt[0],"RL16=%d\n",_WK_REEL[1][6]);
	FntPrint(dbg_flg.fnt[0],"%d ",_WK_REEL[2][0]);
	FntPrint(dbg_flg.fnt[0],"RL25=%d ",_WK_REEL[2][5]);
	FntPrint(dbg_flg.fnt[0],"RL26=%d\n",_WK_REEL[2][6]);
#endif
//	FntPrint(dbg_flg.fnt[0],"AU=%d TE=%d SE=%d SP=%d\n",auto_on,au_te,au_se,au_sp);
//	FntPrint(dbg_flg.fnt[0],"MEDAL=%d\n",_NB_PLAY_MEDAL);

#endif

#endif


#if 0
	if((_FL_ACTION&(0x01<<1)))	FntPrint(dbg_flg.fnt[0],"RB0 = 1\n");
	else					FntPrint(dbg_flg.fnt[0],"RB0 = 0\n");
	if((_FL_ACTION&(0x01<<2)))	FntPrint(dbg_flg.fnt[0],"BB0 = 1\n");
	else					FntPrint(dbg_flg.fnt[0],"BB0 = 0\n");

	if((_FL_WIN&(0x01<<1)))	FntPrint(dbg_flg.fnt[0],"RB1 = 1\n");
	else					FntPrint(dbg_flg.fnt[0],"RB1 = 0\n");
	if((_FL_WIN&(0x01<<2)))	FntPrint(dbg_flg.fnt[0],"BB1 = 1\n");
	else					FntPrint(dbg_flg.fnt[0],"BB1 = 0\n");
#endif
	if(pad_cnt & PAD_SELECT){
//		font_flash();
//		print_rech();

#ifdef DEBUG_FONT
		dbg_fntset();
#endif
		dbg_flg.mode=(dbg_flg.mode+1)%DBG_MODE_MAX;
		dbg_flg.point=0;

//#ifdef dsdss
		if(dbg_flg.mode==1){

			db_g4=poly_g4_make();	//	ぽりつくる
			get_polylst(db_g4)->pri=0;
			SetSemiTrans(db_g4,1);	/* 1=半透明		*/
			SetShadeTex(db_g4,1);		/* 0=ｼｪｰﾄﾞする	*/

			poly_g4_rgbset(db_g4,48,48,48);
#ifdef DEBUG_FONT
			dbfb_xyset();
#endif
		}
		if(dbg_flg.mode==2){
			poly_kill(db_g4);
		}
//#endif
	}

	switch(dbg_flg.mode){
		case  0:
		case  1:
#ifdef DEBUG_FONT
	FntPrint(dbg_flg.fnt[0],"MEMORY CNT %d\n",mem_cnt);
//	FntPrint(dbg_flg.fnt[0],"GAME MALLOC %d\n",mal_cnt);
//			FntPrint(dbg_flg.fnt[0],"~c808");
//			FntPrint(dbg_flg.fnt[0],"-malloc size\n");
//			FntPrint(dbg_flg.fnt[0],"-MAX=0x%x\n",HEAP_SIZE);
//			FntPrint(dbg_flg.fnt[0],"-HIG=0x%x\n",mal_msize);
//			FntPrint(dbg_flg.fnt[0],"-NOW=0x%x\n",mal_size);
//			FntPrint(dbg_flg.fnt[0],"~c888");

#if 0
			FntPrint(dbg_flg.fnt[0],"\nREG_A  = %x\n",((Z80_MC *)z80f)->A);
			FntPrint(dbg_flg.fnt[0],"REG_F  = %x\n",((Z80_MC *)z80f)->F);
			FntPrint(dbg_flg.fnt[0],"REG_B  = %x\n",((Z80_MC *)z80f)->B);
			FntPrint(dbg_flg.fnt[0],"REG_C  = %x\n",((Z80_MC *)z80f)->C);
			FntPrint(dbg_flg.fnt[0],"REG_D  = %x\n",((Z80_MC *)z80f)->D);
			FntPrint(dbg_flg.fnt[0],"REG_E  = %x\n",((Z80_MC *)z80f)->E);
			FntPrint(dbg_flg.fnt[0],"REG_H  = %x\n",((Z80_MC *)z80f)->H);
			FntPrint(dbg_flg.fnt[0],"REG_I  = %x\n",((Z80_MC *)z80f)->I);
			FntPrint(dbg_flg.fnt[0],"REG_AF = %x\n",((Z80_MS *)z80f)->AF);
			FntPrint(dbg_flg.fnt[0],"REG_BC = %x\n",((Z80_MS *)z80f)->BC);
			FntPrint(dbg_flg.fnt[0],"REG_DE = %x\n",((Z80_MS *)z80f)->DE);
			FntPrint(dbg_flg.fnt[0],"REG_HL = %x\n",((Z80_MS *)z80f)->HL);
			FntPrint(dbg_flg.fnt[0],"REG_ABC= %x\n",((Z80_MS *)z80f)->ABC);
			FntPrint(dbg_flg.fnt[0],"REG_ADE= %x\n",((Z80_MS *)z80f)->ADE);
			FntPrint(dbg_flg.fnt[0],"REG_AHL= %x\n",((Z80_MS *)z80f)->AHL);
			FntPrint(dbg_flg.fnt[0],"REG_IX = %x\n",((Z80_MS *)z80f)->IX);
			FntPrint(dbg_flg.fnt[0],"REG_IY = %x\n",((Z80_MS *)z80f)->IY);
#endif
			FntPrint(dbg_flg.fnt[0],"V-BLNK(%d)\n", VSync(-1));
			FntPrint(dbg_flg.fnt[0],"V-WARI(%d)\n", vcount);
#endif


		break;
		break;
		case  2:
		break;
		case  3:
		break;
	}

#ifdef DEBUG_FONT
	font_flash();
	if(dbg_flg.mode==0 || dbg_flg.mode==1)	FntPrint(dbg_flg.fnt[0],"DEBUG MODE 0\n");
#if 0

	FntPrint(dbg_flg.fnt[0],"\nREEL 0 = %d\n",_WK_REEL[0][0]);
	FntPrint(dbg_flg.fnt[0],"REEL 1 = %d\n",_WK_REEL[0][1]);
	FntPrint(dbg_flg.fnt[0],"REEL 2 = %d\n",_WK_REEL[0][2]);
	FntPrint(dbg_flg.fnt[0],"REEL 3 = %d\n",_WK_REEL[0][3]);
	FntPrint(dbg_flg.fnt[0],"REEL 4 = %d\n",_WK_REEL[0][4]);
	FntPrint(dbg_flg.fnt[0],"REEL 5 = %d\n",_WK_REEL[0][5]);
	FntPrint(dbg_flg.fnt[0],"REEL 6 = %d\n",_WK_REEL[0][6]);

	FntPrint(dbg_flg.fnt[0],"MEMORY CNT %d\n",mem_cnt);
	FntPrint(dbg_flg.fnt[0],"GAME MALLOC %d\n",mal_cnt);
	FntPrint(dbg_flg.fnt[0],"MALOC FIRST\n = %x\n",mal_a);
	FntPrint(dbg_flg.fnt[0],"MALOC SIZE\n = %d\n",mal_s);
	FntPrint(dbg_flg.fnt[0],"MALOC END\n = %x\n",mal_a+mal_s);
	FntPrint(dbg_flg.fnt[0],"MALOC MAX\n = %x\n",mal_l);

	for(lp=0;lp<20;lp++)	FntPrint(dbg_flg.fnt[0],"M(%d)= %x\n",lp,mall[lp]);
#endif


#endif
}

///////////////////////////////////////////////////////////////////////////////
//	内蔵フォントの表示
//
#ifdef	DEBUG_FONT

void dbg_fntset(void)
{
	int lp;
	VSync(4);
	FntLoad(1024-(64*5),0);
//	KanjiFntOpen(256,16-120,256,256,896,256,0,511,0,512);
	for(lp=0;lp<DBG_MODE_MAX;lp++)	dbg_flg.fnt[lp]=FntOpen(dispx0+8,dispy0+32,(dispx1*2)-36,(dispy1*2)-64,0,480);
	dbfb_xyset();

}

void dbfb_xyset(void)
{
	if(dbg_flg.mode==1){
		db_g4->x0=dispx0;
		db_g4->y0=dispy0;

		db_g4->x1=dispx0+160;
		db_g4->y1=dispy0;

		db_g4->x2=dispx0;
		db_g4->y2=dispy1;

		db_g4->x3=dispx0+160;
		db_g4->y3=dispy1;
	}
}

void font_flash(void)
{
	if(dbg_flg.mode==0 || dbg_flg.mode==1)	FntFlush(dbg_flg.fnt[0]);
	else				FntFlush(dbg_flg.fnt[1]);
//	KanjiFntFlush(-1);
}


#endif	//	DEBUG_FONT END

///////////////////////////////////////////////////////////////////////////////
//	処理ラインを表示します
//
#ifdef DEBUG_LINE

void func_line(void)
{
 DISPENV	deb_disp;
#ifdef DEBUG_FRAM
	if(!dbg_flg.fram){
#endif
		if(dbg_flg.mode!=2){
			GetDispEnv(&deb_disp);
			deb_disp.disp.x = 512;
			PutDispEnv(&deb_disp);
			PutDispEnv(&GsDISPENV);
		}
#ifdef DEBUG_FRAM
	}
#endif
}
#endif	//	DEBUG_LINE END

///////////////////////////////////////////////////////////////////////////////
//	フレームバッファの中を見る
//
#ifdef	DEBUG_FRAM
short	dispx;
short	dispy;
short	spd;


void frame_buf_look(void)
{
#if 0
	if(pad_cnt & PAD_R1){
		lu_r1++;
	}else if(pad_cnt & PAD_R2){
		lu_r1--;
	}else if(pad_cnt & PAD_L1){
		lu_l1++;
	}else if(pad_cnt & PAD_L2){
		lu_l1--;
	}

#endif

#if 1
	DISPENV	deb_disp;

	if(pad_cnt & PAD_R2){
		if(dbg_flg.fram){
			PutDispEnv(&GsDISPENV);
			dbg_flg.fram = 0;
		}
		else{
			GetDispEnv(&deb_disp);
			dispx = deb_disp.disp.x;
			dispy = deb_disp.disp.y;
			dbg_flg.fram = 1;
		}
	}

	if(dbg_flg.fram){
		if(pad_beta & PAD_SHIKAKU)		spd	= 8;
		else							spd = 2;

		if(pad_beta & PAD_LEFT)			dispx -= spd;
		else if(pad_beta & PAD_RIGHT)	dispx += spd;

		if(pad_beta & PAD_UP)			dispy -= spd;
		else if(pad_beta & PAD_DOWN)	dispy += spd;

		GetDispEnv(&deb_disp);
		deb_disp.disp.x = dispx;
		deb_disp.disp.y = dispy;
		PutDispEnv(&deb_disp);
	}
#endif
}

#endif	//	DEBUG_FRAM END
///////////////////////////////////////////////////////////////////////////////
//	ポリゴン用デバッグ
//	
#ifdef	DEBUG_POLY

int	select[3];

#define	DBG0_MAX	21
void poly_debug(void)
{
	int lp;

	if(obj_cnt){
#ifdef DEBUG_FONT
		lp=0;

		if(pad_trg & PAD_UP){
			dbg_flg.point=(dbg_flg.point+(DBG0_MAX-1))%DBG0_MAX;
		}else	if(pad_trg & PAD_DOWN){
			dbg_flg.point=(dbg_flg.point+1)%DBG0_MAX;
		}

		if(pad_beta & PAD_MARU){
			light_para[dbg_flg.point]+=1;
			lp=1;
		}else	if(pad_beta & PAD_PEKE){
			light_para[dbg_flg.point]-=1;
			lp=1;
		}

		if(pad_beta & PAD_SANKAKU){
			light_para[dbg_flg.point]+=10;
			lp=1;
		}else	if(pad_beta & PAD_SHIKAKU){
			light_para[dbg_flg.point]-=10;
			lp=1;
		}


		if(lp)	light_init();	//	データ変更

		FntPrint(dbg_flg.fnt[1],"DEBUG MODE 1\n");
		FntPrint(dbg_flg.fnt[1],"~c800");
		FntPrint(dbg_flg.fnt[1],"LIGHT-SET\n");
//		FntPrint(dbg_flg.fnt[1],"~c888");

		FntPrint(dbg_flg.fnt[1],"-- LIGHT-0 --\n");

		if(dbg_flg.point==0)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VX :%4d\n",pslt[0].vx);

		if(dbg_flg.point==1)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VY :%4d\n",pslt[0].vy);

		if(dbg_flg.point==2)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VZ :%4d\n",pslt[0].vz);

		if(dbg_flg.point==3)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"R  :%4d\n",pslt[0].r);

		if(dbg_flg.point==4)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"G  :%4d\n",pslt[0].g);

		if(dbg_flg.point==5)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"B  :%4d\n",pslt[0].b);

		FntPrint(dbg_flg.fnt[1],"-- LIGHT-1 --\n");

		if(dbg_flg.point==6)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VX :%4d\n",pslt[1].vx);

		if(dbg_flg.point==7)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VY :%4d\n",pslt[1].vy);

		if(dbg_flg.point==8)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VZ :%4d\n",pslt[1].vz);

		if(dbg_flg.point==9)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"R  :%4d\n",pslt[1].r);

		if(dbg_flg.point==10)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"G  :%4d\n",pslt[1].g);

		if(dbg_flg.point==11)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"B  :%4d\n",pslt[1].b);

		FntPrint(dbg_flg.fnt[1],"-- LIGHT-2 --\n");

		if(dbg_flg.point==12)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VX :%4d\n",pslt[2].vx);

		if(dbg_flg.point==13)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VY :%4d\n",pslt[2].vy);

		if(dbg_flg.point==14)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VZ :%4d\n",pslt[2].vz);

		if(dbg_flg.point==15)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"R  :%4d\n",pslt[2].r);

		if(dbg_flg.point==16)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"G  :%4d\n",pslt[2].g);

		if(dbg_flg.point==17)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"B  :%4d\n",pslt[2].b);

		FntPrint(dbg_flg.fnt[1],"-- AMBIENT --\n");	//	周辺光

		if(dbg_flg.point==18)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"R  :%4d\n",light_para[18]);

		if(dbg_flg.point==19)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"G  :%4d\n",light_para[19]);

		if(dbg_flg.point==20)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"B  :%4d\n",light_para[20]);

		FntPrint(dbg_flg.fnt[1],"-- MODE %2d --\n",light_para[21]);
		FntPrint(dbg_flg.fnt[1],"~c888");

#endif
	}
}

#define	DBG1_MAX	8
void poly_debug1(void)
{
	int lp;

	if(obj_cnt){
#ifdef DEBUG_FONT
		lp=0;

		if(pad_trg & PAD_UP){
			dbg_flg.point=(dbg_flg.point+(DBG1_MAX-1))%DBG1_MAX;
		}else	if(pad_trg & PAD_DOWN){
			dbg_flg.point=(dbg_flg.point+1)%DBG1_MAX;
		}

		if(pad_beta & PAD_MARU){
			view_buf[dbg_flg.point]+=1;
			lp=1;
		}else	if(pad_beta & PAD_PEKE){
			view_buf[dbg_flg.point]-=1;
			lp=1;
		}

		if(pad_beta & PAD_SANKAKU){
			view_buf[dbg_flg.point]+=100;
			lp=1;
		}else	if(pad_beta & PAD_SHIKAKU){
			view_buf[dbg_flg.point]-=100;
			lp=1;
		}

		if(lp)	poly_view();	//	データ変更

		FntPrint(dbg_flg.fnt[1],"DEBUG MODE 2\n");
		FntPrint(dbg_flg.fnt[1],"~c800");
		FntPrint(dbg_flg.fnt[1],"VIEW-SET\n");
//		FntPrint(dbg_flg.fnt[1],"~c888");
		if(dbg_flg.point==0)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"PROJE :%6d\n",view_buf[0]);

		if(dbg_flg.point==1)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VPX   :%6d\n",view_buf[1]);

		if(dbg_flg.point==2)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VPY   :%6d\n",view_buf[2]);

		if(dbg_flg.point==3)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VPZ   :%6d\n",view_buf[3]);

		if(dbg_flg.point==4)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VRX   :%6d\n",view_buf[4]);

		if(dbg_flg.point==5)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VRY   :%6d\n",view_buf[5]);

		if(dbg_flg.point==6)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"VRZ   :%6d\n",view_buf[6]);

		if(dbg_flg.point==7)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"RZ    :%6d\n",view_buf[7]);

		if(dbg_flg.point==8)	FntPrint(dbg_flg.fnt[1],">>");
		else					FntPrint(dbg_flg.fnt[1],"  ");
		FntPrint(dbg_flg.fnt[1],"SUPER :%6d\n",view_buf[8]);
		FntPrint(dbg_flg.fnt[1],"~c888");

#endif
	}
}

#endif
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#endif	//	DEBUG_MODE END


