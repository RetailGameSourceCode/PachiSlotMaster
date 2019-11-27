#include "common.h"
#include "work.h"

//#define BASEE
#define DRUMM

//	“ü—Í”»’èi‚o‚`‚cj

void moji_test(void);


void game_main(void)
{
#if 0
	int lp;
	int dt;
	int sw;
	char sa[32];

	VERTS *ve;
	VERTEXS	*vex;
	VERTEXS	*vex2;

#if	DEBUG_MODE==1
//	if(pad_beta & PAD_L1)	MACINE=0;
//	else					MACINE=1;
#endif

	sw=0;

//	moji_test();	//	•¶š‚Ìo—ÍƒeƒXƒg


//	M_PRG_START();


//	slot_data_read();

#if 0
	for(lp=0;lp<35;lp++){
		kyoutai_sp[lp]->pri = 80;	//	“K“–‚¾‚¯‚Ç–{”Ô—p
		kyoutai_sp[lp]->attribute = GsCLUT8;
		sprobj_doff(kyoutai_sp[lp]);
	}
	for(lp=0;lp<40;lp++){
		lamp_sp[lp]->pri = 80-1;	//	‘ä‚æ‚èˆêŒÂ—Dæ‚ª‚‚¢
		lamp_sp[lp]->attribute = GsCLUT8;
		sprobj_doff(lamp_sp[lp]);
	}

	dt=0;
	vex=(VERTEXS*)&A_TMD[0][647+(dt*2)];
	vex2=(VERTEXS*)&A_TMD[0][647+42+(dt*2)];
	while(1){

		if(pad_trg&PADR_R){
			vex->vx+=10;
			vex2->vx-=10;
		}
		if(pad_trg&PADR_L){
			vex->vx-=10;
			vex2->vx+=10;
		}


		if(pad_cnt&PADL_R){
			dt=(dt+1)%20;
			vex=(VERTEXS*)&A_TMD[0][647+(dt*2)];
			vex2=(VERTEXS*)&A_TMD[0][647+42+(dt*2)];
		}

		FntPrint(dbg_flg.fnt[0],"\nVX=%04x\nVY=%04x\n",vex->vx,vex->vy);
		FntPrint(dbg_flg.fnt[0],"VZ=%04x\n ",vex->vz);

		wait(1);
	}
#endif


#if	DEBUG_MODE==1
#if 0
sw_config |= 1; 
sw_config|=0x01<<1;
sw_config|=0x01<<3;
sw_config|=0x01<<5;
sw_config|=0x01<<6;

_NB_RANK=6;
MACINE=1;
#endif

#endif
#endif

	slot_main();	//	kapbin.c

}



void moji_test(void)
{
#if 0
	int	moji_id;
	static u_short str[20];
	char str2[100];
	u_short *ad;

//	moji_id=ffnt_open((dispx0+48+16),(dispy0+96),16*16,16*1,
//		(u_short *)fnt_data+SAMPLE3);	/* ‚e‚e‚m‚sƒI[ƒvƒ“ */

//	ffnt_init(1024-64,0,256,480);	//	ƒtƒHƒ“ƒg‰Šú‰»
	sprintf(str2,"‚ ‚¦‚¨%d",32);
	ffnt_changes(str2,str);	/* ‚e‚e‚m‚s”CˆÓ•¶š—ñ•ÏŠ· */
	moji_id=ffnt_open(-136,58,16*17,16*3,(u_short*)str);	/* ‚e‚e‚m‚sƒI[ƒvƒ“ */

//	moji_id=ffnt_open((dispx0+48+16),(dispy0+96),16*16,16*1,
//		(u_short *)fnt_data+MAST_MOJI);	/* ‚e‚e‚m‚sƒI[ƒvƒ“ */

	ffnt_color(moji_id,0x80,0x80,0x80);	/* Œ©o‚µ */

	ad=fnt_data;
	while(1){
#ifdef	DEBUG_FONT

		FntPrint(dbg_flg.fnt[0]," fnt = %d\n",*ad);
		FntPrint(dbg_flg.fnt[0]," str0 = %d\n",str[0]);
		FntPrint(dbg_flg.fnt[0]," str1 = %d\n",str[1]);
		FntPrint(dbg_flg.fnt[0]," str2 = %d\n",str[2]);
		FntPrint(dbg_flg.fnt[0]," str3 = %d\n",str[3]);
		FntPrint(dbg_flg.fnt[0]," str4 = %d\n",str[4]);
		FntPrint(dbg_flg.fnt[0]," str5 = %d\n",str[5]);
		FntPrint(dbg_flg.fnt[0]," str6 = %d\n",str[6]);

//		if(pad_beta&PADL_UP)	ffnt_scroll2(moji_id,-1);
//		if(pad_beta&PADL_DOWN)	ffnt_scroll2(moji_id,1);
//		if(pad_cnt&PAD_L2)		break;

#endif
		wait(1);
	}
#endif
}




#if 0
	POLY_FT4 *f4;
	f4=poly_ft4_make();

	poly_ft4_fset(f4,320,256+128,320,256,0,0,0);
	poly_ft4_xyset(f4,-150,-100,256,256);
	poly_ft4_uvset(f4,0,0,256,256);
	poly_ft4_rgbset(f4,127,127,32);

GsBOXF *box;
box=box_make();
box_xyset(box,32,32,64,64);
box_rgbset(box,127,127,32);
#endif
