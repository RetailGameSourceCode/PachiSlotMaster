//=============================================================
//ドラムのセット
//モーター制御
//=============================================================
#include "common.h"
#include "work.h"
#include "bin_d.hd"

extern signed char	submenu_sts;		// サブメニューステップ

GsRVIEW2	view;			/* 視点を設定するための構造体		*/
GsF_LIGHT	pslt[3];		/* 平行光源を設定するための構造体	*/

//#define KYOUTAI_SP_MAX (35)
SPRITE_OBJECT	*kyoutai_sp[KYOUTAI_SP_MAX];
//#define LAMP_SP_MAX (40)
SPRITE_OBJECT	*lamp_sp[LAMP_SP_MAX];

GsDOBJ2			*drum[DRUM_MAX];
MATRIX			*drum_coord[DRUM_MAX];	/* 座標マトリクス			*/
GsCOORD2PARAM	*drum_param[DRUM_MAX];	/* 座標パラメータ(R,S,T)	*/
char	drum_arimasu;
char auto_on_s;
#define DEF_ZERO_Y	(-164)
#define NOW_ZERO_Y	zero_y
int hd_inter = 0;

/*							1     2     3     4     5     6	*/
#if 0	//
short drum_rotate_vx[6] = {0x000,0x000,0x400,0xc00,0x000,0x000};
short drum_rotate_vy[6] = {0x000,0x400,0x000,0x000,0xc00,0x800};
short drum_rotate_vz[6] = {0x000,0x000,0x000,0x000,0x000,0x000};
#endif
short drum_rotate_vx[6] = {0x000,0x000,0x000,0x000,0x000,0x000};
short drum_rotate_vy[6] = {0x000,0x000,0x000,0x000,0x000,0x000};
short drum_rotate_vz[6] = {0x000,0x000,0x000,0x000,0x000,0x000};

#define DRUM_Y001 (470+100)
#define DRUM_Y002 (490+80)
#define DRUM_Y003 (196+40)

#define DRUM_Y01 (470+30)
#define DRUM_Y02 (490+20)
long drum_y[2][3][3]=
{

{{	 DRUM_Y001,DRUM_Y001,DRUM_Y001,},
{	 DRUM_Y002,DRUM_Y002,DRUM_Y002,},
{	 DRUM_Y003,DRUM_Y003,DRUM_Y003,},	},
{{	 DRUM_Y01,DRUM_Y01,DRUM_Y01,},
{	 DRUM_Y02,DRUM_Y02,DRUM_Y02,},
{	 196,196,196,},	},
};


//#define YPLUS (0x0400)
//#define YPLUS (896)	//	元
#define XKIHON0 (-127)
#define XKIHON1 (-137)
#define XKIHON2 (4)
//ssssssssssssssssss
long drum_x[2][3][3]={
#if 0
{	{	 XKIHON0-(1135)+38,XKIHON0+10,XKIHON0+(1143)-8,},
	{	 XKIHON1-(1144)+50,XKIHON1+12,XKIHON1+1141+8,},
	{	 XKIHON2-(1108)+48,XKIHON2+8,XKIHON2+1108-13,},},
#endif
{	{	 XKIHON0-(1135+160),XKIHON0-6,XKIHON0+(1143+150),},
	{	 XKIHON1-(1144+190),XKIHON1+10,XKIHON1+(1141+200),},
	{	 XKIHON2-(1100+120),XKIHON2+12,XKIHON2+(1100+160),},},

{	{	 XKIHON0-(1135+180),XKIHON0-20,XKIHON0+(1143+120),},
	{	 XKIHON1-(1144+190),XKIHON1,XKIHON1+(1141+184),},
	{	 XKIHON2-(1100+120),XKIHON2-2,XKIHON2+(1100+134),},},
};

long drum_z[3][3]=
{
{	 0x0200,0x0200,0x0200,},
{	 0x0200,0x0200,0x0200,},
{	 0x0200,0x0200,0x0200,},
};
//	 0x1400+POFS,0x1400+MOFS,0x1400+POFS,
//	 0x1400+POFS,0x1400+MOFS,0x1400+MOFS,0x1400+POFS+POFS,0x1400+POFS+POFS,0x1400+POFS+POFS
//};

//	short lamp_act_tim_dataの略
#define LAMP_DATA_TBL_S	lat_dat_s[MACINE]
#define LAMP_DATA_TBL_M	lat_dat_m[MACINE]
#define LAMP_DATA_TBL_L	lat_dat_l[MACINE]

#define LAMP_S_MAX	(40)
#define LAMP_M_MAX	(16+7)
#define LAMP_L_MAX	(13)

#define LAMP_KYOUTSUU	(0)
#define LU_PAY3U	lamp_sp[LAMP_KYOUTSUU+0]
#define LU_PAY3D	lamp_sp[LAMP_KYOUTSUU+1]
#define LU_PAY2U	lamp_sp[LAMP_KYOUTSUU+2]
#define LU_PAY2D	lamp_sp[LAMP_KYOUTSUU+3]
#define LU_PAY1		lamp_sp[LAMP_KYOUTSUU+4]
#define LU_WAIT		lamp_sp[LAMP_KYOUTSUU+5]
#define LU_BINBOU	lamp_sp[LAMP_KYOUTSUU+6]
#define LU_SAKURA	lamp_sp[LAMP_KYOUTSUU+7]
#define LU_KAMISAMA	lamp_sp[LAMP_KYOUTSUU+8]
#define LU_MEDAL_IN	lamp_sp[LAMP_KYOUTSUU+9]
#define LU_OMEDETO	lamp_sp[LAMP_KYOUTSUU+10]
#define LU_ATARI	lamp_sp[LAMP_KYOUTSUU+11]
#define LU_KOZUCHI	lamp_sp[LAMP_KYOUTSUU+12]
#define LU_REPLAY	lamp_sp[LAMP_KYOUTSUU+13]
#define LU_REPLAY_U	lamp_sp[LAMP_KYOUTSUU+14]
#define LU_MAX_BET	lamp_sp[LAMP_KYOUTSUU+15]

/* デジタル */
#define DIG_START (16)
#define DIG_WIN		lamp_sp[DIG_START+0] /* WIN LAMP     */
#define DIG_WINP	lamp_sp[DIG_START+1] /* WIN LAMPピリオド    */
#define DIG_GAME	lamp_sp[DIG_START+2] /* GAME         */
#define DIG_CR_R	lamp_sp[DIG_START+3] /* WIN CREDIT R */
#define DIG_CR_L	lamp_sp[DIG_START+4] /* WIN CREDIT L */
#define DIG_CO_R	lamp_sp[DIG_START+5] /* COUNT      R */
#define DIG_CO_L	lamp_sp[DIG_START+6] /* COUNT      L */

#define S_KOYUU	(23)
#define LU_R4L		lamp_sp[S_KOYUU+0]
#define LU_R3L		lamp_sp[S_KOYUU+1]
#define LU_R2L		lamp_sp[S_KOYUU+2]
#define LU_R1L		lamp_sp[S_KOYUU+3]
#define LU_R1R		lamp_sp[S_KOYUU+4]
#define LU_R2R		lamp_sp[S_KOYUU+5]
#define LU_R3R		lamp_sp[S_KOYUU+6]
#define LU_R4R		lamp_sp[S_KOYUU+7]
#define LU_REBER	lamp_sp[S_KOYUU+8]
#define LU_ONE_BET	lamp_sp[S_KOYUU+9]
#define LU_TWO_BET	lamp_sp[S_KOYUU+10]
#define LU_STOP_L	lamp_sp[S_KOYUU+11]
#define LU_STOP_C	lamp_sp[S_KOYUU+12]
#define LU_STOP_R	lamp_sp[S_KOYUU+13]
#define LU_STOP_L2	lamp_sp[S_KOYUU+14]
#define LU_STOP_C2	lamp_sp[S_KOYUU+15]
#define LU_STOP_R2	lamp_sp[S_KOYUU+16]


short lat_dat_s[2][40][8]={
//                 cx     cy     px     py     w      h     x   y
{
/*KPS_PY31.TIM */ {576   ,486   ,794   ,428   ,26    ,20  , 20,134},
/*KPS_PY32.TIM */ {576   ,487   ,788   ,388   ,27    ,18  , 18,206},
/*KPS_PY21.TIM */ {576   ,484   ,738   ,370   ,26    ,22  , 20,150},
/*KPS_PY22.TIM */ {576   ,485   ,738   ,424   ,27    ,20  , 18+1,188},
/*KPS_PY11.TIM */ {576   ,483   ,768   ,428   ,26    ,20  , 20,170},
/*KPS_WAIT.TIM */ {576   ,491   ,768   ,336   ,10    ,30  , 60,226},
/*KPS_KMS1.TIM */ {576   ,477   ,682   ,334   ,22    ,36  , 84,222},
/*KPS_KMS2.TIM */ {576   ,478   ,704   ,334   ,28    ,36  ,128,222},
/*KPS_KMS3.TIM */ {576   ,479   ,732   ,332   ,21    ,38  ,183,220},
/*KPS_MDIN.TIM */ {576   ,481   ,820   ,424   ,12    ,24  ,234,224},
/*KPS_OMDT.TIM */ {576   ,482   ,768   ,406   ,32    ,22  ,240,168},
/*KPS_ATRI.TIM */ {576   ,476   ,664   ,396   ,31    ,24  ,240,150},
/*KPS_KZTI.TIM */ {576   ,480   ,746   ,320   ,16    ,12  ,265,142},
/*KPS_RPY1.TIM */ {576   ,488   ,704   ,414   ,33    ,20  ,238,206},
/*KPS_RPY2.TIM */ {576   ,488   ,704   ,414   ,33    ,20  ,238,206},/*未使用*/
/*KPS_MBET.TIM */ {576   ,497   ,802   ,338   ,12    ,18  , 65,242},

/* デジタル     */
/* WIN LAMP     */	{576   ,501   ,832   ,256   ,20    ,34, 20,224},
/* WIN LAMP P   */	{576   ,501   ,832   ,256   ,20    ,34, 20,224},
/* GAME         */	{576   ,502   ,960   ,256   , 6    ,13,246,192},
/* WIN CREDIT R */	{576   ,501   ,832   ,256   ,18    ,15,265,226},
/* WIN CREDIT L */	{576   ,501   ,832   ,256   ,18    ,15,265,226},
/* COUNT      R */	{576   ,502   ,960   ,256   ,18    ,15,263,192},
/* COUNT      L */	{576   ,502   ,960   ,256   ,18    ,15,263,192},

/* 上部ランプ   */
/*KPS_UR4L.TIM  */	{576   ,490   ,640   ,364   ,26    ,32  , 11,  4},
/*KPS_UR3L.TIM  */	{576   ,490   ,640   ,396   ,24    ,32  , 51,  4},
/*KPS_UR2L.TIM  */	{576   ,490   ,768   ,284   ,18    ,32  , 91,  4},
/*KPS_UR1L.TIM  */	{576   ,490   ,786   ,284   ,16    ,32  ,127,  4},
/*KPS_UR1R.TIM  */	{576   ,490   ,802   ,284   ,16    ,32  ,159,  4},
/*KPS_UR2R.TIM  */	{576   ,490   ,746   ,288   ,18    ,32  ,191,  4},
/*KPS_UR3R.TIM  */	{576   ,490   ,738   ,392   ,24    ,32  ,219,  4},
/*KPS_UR4R.TIM  */	{576   ,490   ,742   ,256   ,26    ,32  ,256,  4},

/* ボタン */
/*KPS_REBA.TIM  */	{576   ,493   ,730   ,288   ,16    ,44  , 44,268},
/*KPS_BET1.TIM  */	{576   ,494   ,666   ,364   ,14    ,28  , 12,272},
/*KPS_BET2.TIM  */	{576   ,494   ,690   ,256   ,14    ,28  , 12,272},
/*KPS_BTG1.TIM  */	{576   ,495   ,818   ,284   ,13    ,28  ,112,272},
/*KPS_BTG2.TIM  */	{576   ,495   ,790   ,338   ,12    ,26  ,148,272},
/*KPS_BTG3.TIM  */	{576   ,495   ,810   ,256   ,13    ,28  ,182,272},
/*KPS_BTR1.TIM  */	{576   ,496   ,768   ,256   ,13    ,28  ,112,272},
/*KPS_BTR2.TIM  */	{576   ,496   ,778   ,338   ,12    ,26  ,148,272},
/*KPS_BTR3.TIM  */	{576   ,496   ,782   ,256   ,13    ,28  ,182,272},
},
{
//	小サイズ びんびん
/*BKS_PY31.TIM   */	{ 576   ,486   ,804   ,332   ,27    ,22, 22,132},
/*BKS_PY32.TIM   */	{ 576   ,487   ,640   ,396   ,27    ,18, 20,204},
/*BKS_PY21.TIM   */	{ 576   ,484   ,801   ,354   ,28    ,22, 20,150},
/*BKS_PY22.TIM   */	{ 576   ,485   ,704   ,394   ,27    ,18, 20,186},
/*BKS_PY11.TIM   */	{ 576   ,483   ,674   ,390   ,28    ,20, 20,168},
/*BKS_WAIT.TIM   */	{ 576   ,491   ,791   ,398   ,11    ,28, 58,228},
/*BKS_KMS1.TIM   */	{ 576   ,477   ,784   ,256   ,20    ,38, 84,222},
/*BKS_KMS2.TIM   */	{ 576   ,478   ,674   ,320   ,28    ,38,124,220},
/*BKS_KMS3.TIM   */	{ 576   ,479   ,704   ,332   ,27    ,38,180,220},
/*BKS_MDIN.TIM   */	{ 576   ,481   ,752   ,420   ,12    ,24,234,224},
/*BKS_OMDT.TIM   */	{ 576   ,482   ,768   ,332   ,36    ,22,232,168},
/*BKS_ATRI.TIM   */	{ 576   ,476   ,736   ,256   ,32    ,30,238,148},
/*BKS_KZTI.TIM   */	{ 576   ,480   ,768   ,354   ,33    ,24,236,132},
/*BKS_RPY1.TIM   */	{ 576   ,488   ,782   ,430   ,29    ,14,244,206},
/*BKS_RPY2.TIM   */	{ 576   ,489   ,640   ,442   , 8    , 6,260,242},
/*BKS_MBET.TIM   */	{ 576   ,497   ,668   ,428   ,12    ,18, 65,242},

//                    cx     cy     px     py     w      h     x   y
/* デジタル */
/* WIN LAMP      */	{ 576   ,501   ,832   ,256   ,20    ,34, 19,224},
/* WIN LAMP P    */	{ 576   ,501   ,832   ,256   ,20    ,34, 19,224},
/* GAME          */	{ 576   ,502   ,960   ,256   , 6    ,13,246,190},
/* WIN CREDIT R  */	{ 576   ,501   ,832   ,256   ,18    ,15,265,223},
/* WIN CREDIT L  */	{ 576   ,501   ,832   ,256   ,18    ,15,265,223},
/* COUNT      R  */	{ 576   ,502   ,960   ,256   ,18    ,15,263,190},
/* COUNT      L  */	{ 576   ,502   ,960   ,256   ,18    ,15,263,190},

/* 上部ランプ    */
/*BKS_UR4L.TIM   */	{ 576   ,490   ,768   ,300   ,26    ,32, 11,  4},
/*BKS_UR3L.TIM   */	{ 576   ,490   ,640   ,364   ,24    ,32, 51,  4},
/*BKS_UR2L.TIM   */	{ 576   ,490   ,804   ,256   ,18    ,32, 91,  4},
/*BKS_UR1L.TIM   */	{ 576   ,490   ,802   ,378   ,16    ,32,127,  4},
/*BKS_UR1R.TIM   */	{ 576   ,490   ,812   ,300   ,16    ,32,159,  4},
/*BKS_UR2R.TIM   */	{ 576   ,490   ,794   ,300   ,18    ,32,191,  4},
/*BKS_UR3R.TIM   */	{ 576   ,490   ,674   ,358   ,24    ,32,219,  4},
/*BKS_UR4R.TIM   */	{ 576   ,490   ,738   ,300   ,26    ,32,256,  4},

/* ボタン */
/*BKS_REBA.TIM   */	{ 576   ,493   ,768   ,256   ,16    ,44, 44,268},
/*BKS_BET1.TIM   */	{ 576   ,494   ,818   ,378   ,14    ,28, 12,272},
/*BKS_BET2.TIM   */	{ 576   ,494   ,689   ,288   ,14    ,28, 12,272},
/*BKS_BTG1.TIM   */	{ 576   ,495   ,653   ,414   ,13    ,28,112,272},
/*BKS_BTG2.TIM   */	{ 576   ,495   ,728   ,412   ,12    ,26,148,272},
/*BKS_BTG3.TIM   */	{ 576   ,495   ,640   ,414   ,13    ,28,182,272},
/*BKS_BTR1.TIM   */	{ 576   ,496   ,755   ,392   ,13    ,28,112,272},
/*BKS_BTR2.TIM   */	{ 576   ,496   ,740   ,412   ,12    ,26,148,272},
/*BKS_BTR3.TIM   */	{ 576   ,496   ,755   ,332   ,13    ,28,182,272},

//                     cx     cy     px     py     w      h x y
},
};


short lat_dat_m[2][23][8]={
//	中サイズ
{
/*KPM_PY31.TIM   */	{576   ,471   ,680   ,370   ,20    ,22  , 12, 74+8},
/*KPM_PY32.TIM   */	{576   ,472   ,768   ,386   ,20    ,20  , 12,162+8},
/*KPM_PY21.TIM   */	{576   ,469   ,768   ,316   ,20    ,20  , 12, 96+8},
/*KPM_PY22.TIM   */	{576   ,470   ,788   ,316   ,20    ,22  , 12,140+8},
/*KPM_PY11.TIM   */	{576   ,468   ,800   ,406   ,20    ,22  , 12,118+8},
/*KPM_WAIT.TIM   */	{576   ,475   ,754   ,332   ,11    ,34  , 40,190+8},
/*KPM_KMS1.TIM   */	{576   ,462   ,674   ,288   ,28    ,46  , 68,180+8},
/*KPM_KMS2.TIM   */	{576   ,463   ,640   ,288   ,33    ,46  ,123,180+8},
/*KPM_KMS3.TIM   */	{576   ,464   ,704   ,288   ,26    ,46  ,188,180+8},
/*KPM_MDIN.TIM   */	{576   ,466   ,796   ,256   ,14    ,28  ,250,186+8},
/*KPM_OMDT.TIM   */	{576   ,467   ,768   ,370   ,25    ,16  ,258,120+8},
/*KPM_ATRI.TIM   */	{576   ,461   ,678   ,422   ,26    ,26  ,258, 94+8},
/*KPM_KZTI.TIM   */	{576   ,465   ,704   ,434   ,12    ,10  ,286, 87+8},
/*KPM_RPY1.TIM   */	{576   ,473   ,704   ,392   ,34    ,22  ,252,164+8},
/*KPM_RPY2.TIM   */	{576   ,473   ,704   ,392   ,34    ,22  ,252,164+8}, /*未使用*/
/*KPM_MBET.TIM   */	{576   ,498   ,808   ,316   ,14    ,18  , 45,206+8},

/* デジタル      */
/* WIN LAMP      */	{ 576   ,501   ,832   ,256   ,14    ,40, 12,188+8},
/* WIN LAMP P    */	{ 576   ,501   ,832   ,256   ,14    ,40, 12,188+8},
/* GAME          */	{ 576   ,502   ,960   ,256   , 6    ,16,268,146+8},
/* WIN CREDIT R  */	{ 576   ,501   ,832   ,256   ,12    ,16,288,188+8},
/* WIN CREDIT L  */	{ 576   ,501   ,832   ,256   ,12    ,16,288,188+8},
/* COUNT      R  */	{ 576   ,502   ,960   ,256   ,10    ,16,286,146+8},
/* COUNT      L  */	{ 576   ,502   ,960   ,256   ,10    ,16,286,146+8},
},
{
/*BKM_PY31.TIM   */	{ 576   ,471   ,704   ,412   ,24    ,24,12,80},
/*BKM_PY32.TIM   */	{ 576   ,472   ,680   ,428   ,22    ,20,12,170},
/*BKM_PY21.TIM   */	{ 576   ,469   ,768   ,398   ,23    ,20,12,104},
/*BKM_PY22.TIM   */	{ 576   ,470   ,802   ,410   ,22    ,20,12,148},
/*BKM_PY11.TIM   */	{ 576   ,468   ,732   ,392   ,22    ,20,12,126},
/*BKM_WAIT.TIM   */	{ 576   ,475   ,692   ,256   ,12    ,32,36,200},
/*BKM_KMS1.TIM   */	{ 576   ,462   ,731   ,332   ,24    ,40,68,192},
/*BKM_KMS2.TIM   */	{ 576   ,463   ,640   ,320   ,34    ,44,116,188},
/*BKM_KMS3.TIM   */	{ 576   ,464   ,704   ,256   ,32    ,44,184,188},
/*BKM_MDIN.TIM   */	{ 576   ,466   ,768   ,418   ,14    ,26,250,194},
/*BKM_OMDT.TIM   */	{ 576   ,467   ,731   ,372   ,34    ,20,252,126},
/*BKM_ATRI.TIM   */	{ 576   ,461   ,704   ,370   ,27    ,24,256,102},
/*BKM_KZTI.TIM   */	{ 576   ,465   ,768   ,378   ,34    ,20,252,82},
/*BKM_RPY1.TIM   */	{ 576   ,473   ,736   ,286   ,24    ,14,262,172},
/*BKM_RPY2.TIM   */	{ 576   ,474   ,784   ,294   , 9    , 6,280,216},
/*BKM_MBET.TIM   */	{ 576   ,498   ,668   ,410   ,15    ,18,44,206+8},

/* デジタル      */
/* WIN LAMP      */	{ 576   ,501   ,832   ,256   ,14    ,40, 14,184+8},
/* WIN LAMP  P   */	{ 576   ,501   ,832   ,256   ,14    ,40, 14,184+8},
/* GAME          */	{ 576   ,502   ,960   ,256   , 6    ,16,265,145+8},
/* WIN CREDIT R  */	{ 576   ,501   ,832   ,256   ,12    ,16,287,185+8},
/* WIN CREDIT L  */	{ 576   ,501   ,832   ,256   ,12    ,16,287,185+8},
/* COUNT      R  */	{ 576   ,502   ,960   ,256   ,10    ,16,286,145+8},
/* COUNT      L  */	{ 576   ,502   ,960   ,256   ,10    ,16,286,145+8},
},
//                     cx     cy     px     py     w      h x y
};

short lat_dat_l[2][13][8]={
//	大サイズ
{
//                   cx     cy     px     py     w      h     x    y
/*KPB_PY31.TIM   */	{576   ,458   ,640   ,434   ,7     ,14  ,  0, 46+8},
/*KPB_PY32.TIM   */	{576   ,459   ,824   ,256   ,7     ,14  ,  0,178+8},
/*KPB_PY21.TIM   */	{576   ,456   ,696   ,396   ,7     ,14  ,  0, 80+8},
/*KPB_PY22.TIM   */	{576   ,457   ,824   ,270   ,7     ,14  ,  0,146+8},
/*KPB_PY11.TIM   */	{576   ,455   ,822   ,312   ,7     ,14  ,  0,112+8},
/*KPB_WAIT.TIM   */	{576   ,460   ,820   ,408   ,11    ,16  ,  0,204+8},
/*KPB_KMS1.TIM   */	{576   ,449   ,640   ,334   ,41    ,30  , 32,194+8},
/*KPB_KMS2.TIM   */	{576   ,450   ,640   ,256   ,49    ,32  ,116,192+8},
/*KPB_KMS3.TIM   */	{576   ,451   ,704   ,256   ,37    ,32  ,213,192+8},
/*KPB_MDIN.TIM   */	{576   ,453   ,762   ,392   ,6     ,16  ,308,200+8},
/*KPB_OMDT.TIM   */	{576   ,454   ,764   ,288   ,4     ,8   ,-60,-60},
/*KPB_ATRI.TIM   */	{576   ,448   ,764   ,304   ,4     ,8   ,-60,-60},
/*KPB_KZTI.TIM   */	{576   ,452   ,764   ,296   ,4     ,8   ,-60,-60},
},

{
/*BKB_PY31.TIM   */	{ 576   ,458   ,698   ,368   , 5    ,10,8,50},
/*BKB_PY32.TIM   */	{ 576   ,459   ,698   ,358   , 5    ,10,4,182},
/*BKB_PY21.TIM   */	{ 576   ,456   ,755   ,360   , 5    ,10,6,82},
/*BKB_PY22.TIM   */	{ 576   ,457   ,698   ,378   , 5    ,10,6,148},
/*BKB_PY11.TIM   */	{ 576   ,455   ,760   ,360   , 5    ,10,6,108+8},
/*BKB_WAIT.TIM   */	{ 576   ,460   ,684   ,410   ,12    ,16,0,216},
/*BKB_KMS1.TIM   */	{ 576   ,449   ,704   ,300   ,34    ,32,36,200},
/*BKB_KMS2.TIM   */	{ 576   ,450   ,640   ,256   ,52    ,32,104,200},
/*BKB_KMS3.TIM   */	{ 576   ,451   ,640   ,288   ,49    ,32,208,200},
/*BKB_MDIN.TIM   */	{ 576   ,453   ,760   ,286   , 6    ,12,308,208},
/*BKB_OMDT.TIM   */	{ 576   ,454   ,664   ,364   , 6    ,24,308,108},
/*BKB_ATRI.TIM   */	{ 576   ,448   ,670   ,364   , 4    ,36,312,68},
/*BKB_KZTI.TIM   */	{ 576   ,452   ,822   ,256   , 4    ,16,312,48},
},
};


GsRVIEW2	dbg_view;			/* 視点を設定するための構造体 */
int pause_flg=2;
int buf[7];
int	po;

void dbg_drum_view(void);
void drum_light3(void);

#if 0
void drum_light(int d_no ,int r_no,int mode);
void drum_light2(int no);
#endif
void deb_drum_kakudo_sonota(void)
{
#if 0
	if(pause_flg==2){

		buf[0]=view.vpx;
		buf[1]=view.vpy;
		buf[2]=view.vpz;
		buf[3]=view.vrx;
		buf[4]=view.vry;
		buf[5]=view.vrz;
		buf[6]=view.rz;
		po=0;
		pause_flg=3;
	}
	if(pause_flg==3){
		if(pad_trg & PADLup){
				po=(po+6)%7;
		}else if(pad_trg & PADLdown){
				po=(po+1)%7;
		}else if(pad_cnt & PADLright){
			if(pad_cnt & PADRup){
				buf[po]+=1000;
			}else if(pad_cnt & PADRleft){
				buf[po]+=10;
			}else{
				buf[po]+=100;
			}
		}else if(pad_cnt & PADLleft){
			if(pad_cnt & PADRup){
				buf[po]-=1000;
			}else if(pad_cnt & PADRleft){
				buf[po]-=10;
			}else{
				buf[po]-=100;
			}
		}

		FntPrint(" \n\n");
		if(po==0)	FntPrint("                    * ");
		else		FntPrint("                      ");
		FntPrint("VPX=%8d\n",buf[0]);
		if(po==1)	FntPrint("                    * ");
		else		FntPrint("                      ");
		FntPrint("VPY=%8d\n",buf[1]);
		if(po==2)	FntPrint("                    * ");
		else		FntPrint("                      ");
		FntPrint("VPZ=%8d\n",buf[2]);
		if(po==3)	FntPrint("                    * ");
		else		FntPrint("                      ");
		FntPrint("VRX=%8d\n",buf[3]);
		if(po==4)	FntPrint("                    * ");
		else		FntPrint("                      ");
		FntPrint("VRY=%8d\n",buf[4]);
		if(po==5)	FntPrint("                    * ");
		else		FntPrint("                      ");
		FntPrint("VRZ=%8d\n",buf[5]);
		if(po==6)	FntPrint("                    * ");
		else		FntPrint("                      ");
		FntPrint("RZ =%8d\n\n",buf[6]);

//		bwait(1);
		view.vpx=buf[0];
		view.vpy=buf[1];
		view.vpz=buf[2];
		view.vrx=buf[3];
		view.vry=buf[4];
		view.vrz=buf[5];
		view.rz =buf[6];
	}
	dbg_drum_view();
#endif
}


void dbg_drum_view(void)
{
	/* 視点から投影面の距離を設定 */
//	GsSetProjection(1000);
	/* 視点パラメータ設定 */
//	view.vpx = dbg_view.vpx; view.vpy = dbg_view.vpy; view.vpz = dbg_view.vpz;
	/* 注視点パラメータ設定 */
//	view.vrx = dbg_view.vrx; view.vry = dbg_view.vry; view.vrz = dbg_view.vrz;
	/* 視点の捻りパラメータ設定 */
//	view.rz= dbg_view.rz;
	/* 視点座標パラメータ設定 */
//	view.super = WORLD;
	/* 視点パラメータを群から視点を設定して ワールドスクリーンマトリックスを計算する */
	GsSetRefView2(&view);
}



/*=============================================================
 *	ドラムの作成ルーティン
 *	drum_end()を呼んで、消してください
 *
 * in:
 *		short cnt	ドラムの番号
 *		int mode	予備
 *		u_long mod_adr	モデリングデータアドレス
 * out:
 *		int	TRUE	作成しました
 *			FALSE	作成出来ませんでした
 *
 *=============================================================*/
int drum_set(short cnt, int mode, u_long mod_adr)
{
	int i;
	short now_drum=0;

	drum[cnt]=NULL;

	light_init();		/* Setting Flat Light /* 平行光源設定 */

/*** エントリー初期化 ***/
//	for(i = 0; i < DRUM_MAX; i++){
	i=cnt;

	drum[i] = dobj_make(0);	//	オブジェの作成
	GsLinkObject4(mod_adr,drum[i],now_drum);/*OBJにMODELをLINK*/

	/*構造体ポインタだらけになるので必要なポインタを取り出しておく*/
	drum_coord[i] = &(drum[i]->coord2->coord);
	drum_param[i] = (drum[i]->coord2->param);

	/* ワールド座標 */
	drum_coord[i]->t[TX] = drum_x[MACINE][ZOOM_LEVEL][i];
	drum_coord[i]->t[TY] = drum_y[MACINE][ZOOM_LEVEL][i];
	drum_coord[i]->t[TZ] = drum_z[ZOOM_LEVEL][i];

	/* 初期回転角 */
	drum_param[i]->rotate.vx = DZERO_F;
	drum_param[i]->rotate.vy = 0;
	drum_param[i]->rotate.vz = 0;

	if(!slf){	//	ロードされてきてない時だけ設定
	_WK_REEL[i][0]=0;
	_WK_REEL[i][1]=0;
	_WK_REEL[i][2]=0;
	_WK_REEL[i][3]=0;
	_WK_REEL[i][4]=0;
	_WK_REEL[i][5]=0;
	_WK_REEL[i][6]=0;
	_WK_REEL[i][7]=0;
	}else{
//		drum_point_set(i,_WK_REEL[i][5],0);
	}
	RotMatrix(&(drum_param[i]->rotate),drum_coord[i]);
	/*回転角から回転マトリックス*/
	drum[i]->coord2->flg = 0;
//	wait(1);
	DRUM_ARIMASU = 1;	//	ドラム作成終了

	return TRUE;
}


//=================================================
//	オブジェクトモデルを消す
//=================================================
void drum_end(void)
{
	int i;

	DRUM_ARIMASU = 0;	//	ドラム消去
	for(i=0; i<DRUM_MAX; i++){
		if(drum[i] != NULL){
			dobj_kill(drum[i]);
			drum[i] = NULL;
		}
	}
	wait(1);
}



//=============================================================
//	ドラムの視点設定をします
//=============================================================
void drum_view_set(void)
{
//	sssssssssssssssssss
	int i;
	int _vpz_data[3]={
		-23100+800-3300,
		-18600+100-3200,
		-12500+200-1500,
	};

	for(i=0;i<3;i++){
		drum_coord[i]->t[TX] = drum_x[MACINE][ZOOM_LEVEL][i];
		drum_coord[i]->t[TY] = drum_y[MACINE][ZOOM_LEVEL][i];
		drum_coord[i]->t[TZ] = drum_z[ZOOM_LEVEL][i];
		RotMatrix(&(drum_param[i]->rotate),drum_coord[i]);
		drum[i]->coord2->flg = 0;
	}

	/* 視点から投影面の距離を設定 */
	GsSetProjection(1000);
	view.vpx = 0;
	view.vpy = 0;
	view.vpz = _vpz_data[ZOOM_LEVEL];	/*test*/

	/* 注視点パラメータ設定 */
	view.vrx = 0; view.vry = 0; view.vrz = 0;
	view.rz= 0x0000;
	view.super = WORLD;
/*	view.super = &dcoord;  /* ローカル座標に視点を設定する */

	/* 視点パラメータを群から視点を設定して ワールドスクリーンマトリックスを計算する */
	GsSetRefView2(&view);

}


/*=============================================================
 *	init Flat light 平行光源設定
 *
 *
 *
 *
 *=============================================================*/
void light_init(void)
{
/* ライトID０ 設定 正面　*/
	/* 平行光源方向パラメータ設定 */
//	pslt[0].vx = 100; pslt[0].vy= 100; pslt[0].vz= 100;
//	pslt[0].vx = 200; pslt[0].vy= -40; pslt[0].vz= 180;
	pslt[0].vx = 0; pslt[0].vy= -32; pslt[0].vz= 100;
	/* 平行光源色パラメータ設定 */
//	pslt[0].r=0x80; pslt[0].g=0x80; pslt[0].b=0x80;
//	pslt[0].r=0xac; pslt[0].g=0xac; pslt[0].b=0xa2;
//	pslt[0].r=0xf0; pslt[0].g=0xf0; pslt[0].b=0xf0;
	pslt[0].r=0xfc; pslt[0].g=0xfc; pslt[0].b=0xfc;
	/* 光源パラメータから光源設定 */
	GsSetFlatLight(0,&pslt[0]);

/* ライトID１ 設定 真上　*/
	pslt[1].vx = 0; pslt[1].vy= 200; pslt[1].vz= 0;
	pslt[1].r=0x40; pslt[1].g=0x40; pslt[1].b=0x80;	//	本物
//	pslt[1].r=0x00; pslt[1].g=0x00; pslt[1].b=0xa0;
//	GsSetFlatLight(1,&pslt[1]);

/* ライトID２ 設定 真下　*/
	pslt[2].vx = -200; pslt[2].vy= -40; pslt[2].vz= 180;
//	pslt[0].vx = 80; pslt[0].vy= 80; pslt[0].vz= 180;
	pslt[2].r=0xa0; pslt[2].g=0xa0; pslt[2].b=0xa0;

//	pslt[2].r=0x00; pslt[2].g=0x00; pslt[2].b=0x60;
//	GsSetFlatLight(2,&pslt[2]);

/* アンビエント設定 */
	GsSetAmbient(80,80,80);

/* 光源計算のデフォルトの方式設定 */
	GsSetLightMode(0);	/* ノーマル状態 */
/*	GsSetLightMode(1);	/* 遠くを霞ませる */
}

/* ドラムの回転処理	****************************************************/
/**/
/**/
/**/
/***********************************************************************/
char sshi;
void drum_spin(void)
{
	int i,lp,lp2;

	if(DRUM_ARIMASU){
	for(i = 0; i < DRUM_MAX; i++){
		switch(_WK_REEL[i][0]){
			case 0:	//	ドラム停止中
			break;
			case 4:	//	ドラム停止命令実行中
					drum_param[i]->rotate.vx=((_WK_REEL[i][6])*195);
					drum_param[i]->rotate.vx%=4096;
					_WK_REEL[i][5]=((((drum_param[i]->rotate.vx+20)%4096)/195));
					/* 回転角から回転マトリックス*/
					RotMatrix(&(drum_param[i]->rotate),drum_coord[i]);
					drum[i]->coord2->flg = 0;
			break;
			case 1:	//	ドラム回転中 //	回転開始処理
//			if((auto_on_s==0) || ((auto_on_s==1) && (au_sp==0))){
//				drum_param[i]->rotate.vx += ((60/5)*(reel_speed+1));
//				drum_param[i]->rotate.vx%=4096;
//			}
			case 2:	//	ドラム回転中 //	定速回転中
			case 3:	//	ドラム回転中 //	定速回転中
				if((auto_on_s==0) || ((auto_on_s==1) && (au_sp==0))){
					if(_WK_REEL[i][0]==1){
						drum_param[i]->rotate.vx += ((60/5)*(reel_speed+1));
						drum_param[i]->rotate.vx%=4096;
					}else{
						drum_param[i]->rotate.vx += ((90/5)*(reel_speed+1));
						drum_param[i]->rotate.vx%=4096;
					}
					/* 現在のドラム番号 */
					_WK_REEL[i][5]=((((drum_param[i]->rotate.vx+20)%4096)/195));
					if(_WK_REEL[i][5]==0){	//	回胴通過フラグセット
						IN2_PORT^=(0x01<<i);
						_WK_REEL[i][3]=0xFF;
					}
				}else{
					switch(au_sp){
						case 1:
						case 3:
							drum_param[i]->rotate.vx += 195;
							drum_param[i]->rotate.vx %= 4096;
							_WK_REEL[i][5]=((((drum_param[i]->rotate.vx+20)%4096)/195));
							if(_WK_REEL[i][5]==0){	//	回胴通過フラグセット
								IN2_PORT^=(0x01<<i);
								_WK_REEL[i][3]=0xFF;
							}
						break;
						case 2:
							if(_WK_REEL[i][6]==0xFF){
								drum_param[i]->rotate.vx=((stpl[i])*195);
								drum_param[i]->rotate.vx%=4096;
								_WK_REEL[i][5]=drum_param[i]->rotate.vx/195;
								IN2_PORT^=(0x01<<i);
								_WK_REEL[i][3]=0xFF;
							}else{
								drum_param[i]->rotate.vx=((_WK_REEL[i][6])*195);
								drum_param[i]->rotate.vx%=4096;
								_WK_REEL[i][5]=drum_param[i]->rotate.vx/195;
								IN2_PORT^=(0x01<<i);
								_WK_REEL[i][3]=0xFF;
							//	_WK_REEL[i][0]=0;
							}
						break;
					}
				}
				/* 回転角から回転マトリックス*/
				RotMatrix(&(drum_param[i]->rotate),drum_coord[i]);
				drum[i]->coord2->flg = 0;
			break;
		}
	}
	GsSetRefView2(&view);
	}
}

/* ドラムの位置設定 *********************************************/
/* d_no	: ドラムの番号											*/
/* r_no	: ドラム中のロール番号									*/
/* mode :  0=一瞬でその場所へ									*/
/*      :  1=順回転												*/
/*      : -1=逆回転												*/
/* **************************************************************/
void drum_point_set(int d_no,int r_no,int mode)
{
	int lp;
	int sw;
	short mh;

	r_no=(r_no%21);
	_WK_REEL[d_no][6]=r_no;
	if(!mode){
		drum_param[d_no]->rotate.vx=((_WK_REEL[d_no][6])*195);
		drum_param[d_no]->rotate.vx%=4096;
		/* 回転角から回転マトリックス*/
		RotMatrix(&(drum_param[d_no]->rotate),drum_coord[d_no]);
		drum[d_no]->coord2->flg = 0;
		GsSetRefView2(&view);
		_WK_REEL[d_no][5]=r_no;
		wait2(2);
	}else{
		if(mode==1){
			mh= ((60/5)*(2))+4096;
		}else{
			mh= 4096-((60/5)*(2));
		}

		sw=1;
		while(sw){
			drum_param[d_no]->rotate.vx+=mh;
			drum_param[d_no]->rotate.vx%=4096;
			if(mode==1)
				_WK_REEL[d_no][5]=((((drum_param[d_no]->rotate.vx+20)%4096)/195));
			else
				_WK_REEL[d_no][5]=(((drum_param[d_no]->rotate.vx)/195));

//			if(_WK_REEL[d_no][5]==_WK_REEL[d_no][6])	sw=0;
			if(_WK_REEL[d_no][5]==_WK_REEL[d_no][6]){
			if(mode==1){
				if((drum_param[d_no]->rotate.vx%195)>(195-20))	sw=0;
			}else{
				if((drum_param[d_no]->rotate.vx%195)<21)	sw=0;
			}
			}
			RotMatrix(&(drum_param[d_no]->rotate),drum_coord[d_no]);	/* 回転角から回転マトリックス*/
			drum[d_no]->coord2->flg = 0;
			GsSetRefView2(&view);
			wait(1);
		}
		drum_param[d_no]->rotate.vx=((_WK_REEL[d_no][6])*195);
		RotMatrix(&(drum_param[d_no]->rotate),drum_coord[d_no]);	/* 回転角から回転マトリックス*/
		drum[d_no]->coord2->flg = 0;
		GsSetRefView2(&view);
	}
}


//	現状順回転のみ
//	mode  : 0 r_noで指定された場所へ回り出す
//        : 1 ずっと回ってる
//        : 2
// return : mode 0 の時だけ指定位置に達したら１を返す
int drum_roll_set(int d_no,int r_no,int mode)
{
	int lp;
	int sw;
	sw=0;
	switch(mode){
		case 0:
			r_no=(r_no%21);
			_WK_REEL[d_no][6]=r_no;
		break;
		case 1:
			/* 次の図柄を常に指し示してやる */
			_WK_REEL[d_no][6]=((_WK_REEL[d_no][5]+1)%21);
		break;
	}

	drum_param[d_no]->rotate.vx +=90;
	drum_param[d_no]->rotate.vx%=4096;
	_WK_REEL[d_no][5]=((((drum_param[d_no]->rotate.vx+20)%4096)/195));
	drum_param[d_no]->rotate.vx=((_WK_REEL[d_no][6])*195);
	RotMatrix(&(drum_param[d_no]->rotate),drum_coord[d_no]);	/* 回転角から回転マトリックス*/
	drum[d_no]->coord2->flg = 0;

	_PT_OUT8=0xFF;
	_PT_OUT7=(_PT_OUT7|0x80);
	drum_light3();
	_PT_OUT8=0;
	_PT_OUT7=(_PT_OUT7&0x7F);

	GsSetRefView2(&view);
	if(!mode){
		if(_WK_REEL[d_no][5]==_WK_REEL[d_no][6]){
			sw=1;
			wait(1);
			drum_param[d_no]->rotate.vx=((_WK_REEL[d_no][6])*195);
			drum_param[d_no]->rotate.vx%=4096;
			RotMatrix(&(drum_param[d_no]->rotate),drum_coord[d_no]);	/* 回転角から回転マトリックス*/
			drum[d_no]->coord2->flg = 0;
			GsSetRefView2(&view);
			wait(1);
		}
	}
	return(sw);
}



/* ドラムのテクスチャ設定 ***********************************************/
/* d_no	:ドラムの番号													*/
/* r_no	:ドラム中のロール番号											*/
/* mode	:0=normal 1=light												*/
/************************************************************************/

extern char mes_deteimasuka;
extern signed	char	mesp_sts;	// -1:スリープ0:稼動中
char backl=0;
void drum_light3(void)
{
	int ct;
	int lp,lp2;
	short bk,bk2;
	short bitt[3];
	short wk;
	short hiku[3]={20,0,1};
	short wks[3];
	char shib_;
	VERTS *ve;

	if(!DRUM_ARIMASU) return;
	if(!hd_inter)	return;

	shib_=0;

	bk=_PT_OUT8;
	bk2=_PT_OUT7;
	if(submenu_sts==50){
		_PT_OUT8=0xFF;
		_PT_OUT7=0x80;
	}
	wk=0;
	wk=_PT_OUT8;
	wk=(wk&0x00FF);
	if(_PT_OUT7&0x80)	wk=(wk|0x0100);
#if 0
	//	クラットＹ座標
	if(!wk){
		if(backl==0){
			backl=1;
		}else{
//			for(lp=0;lp<21;lp++){	/* 取り敢えず全部くらくする */
//				ve[0][lp]->cba=((D_DEF_CLUT_Y)<<6);
//				ve[1][lp]->cba=((D_DEF_CLUT_Y)<<6);
//				ve[2][lp]->cba=((D_DEF_CLUT_Y)<<6);
//			}
			return;
		}
	}else{
		backl=0;
	}
#endif
	wks[0]=20-((_WK_REEL[0][5]+20)%21);
	wks[1]=20-((_WK_REEL[1][5]+20)%21);
	wks[2]=20-((_WK_REEL[2][5]+20)%21);

	if((auto_on_s==0) || ((auto_on_s==1) && (au_sp==0))){

	for(lp=0;lp<21;lp++){	/* 取り敢えず全部くらくする */
		if(!(((wks[0]-2)<=lp) && (lp<=((wks[0])%21)))){
			ve=(VERTS*)&A_TMD[0][17+((20-lp)*9)];
			ve->cba=((D_DEF_CLUT_Y)<<6);
		}
		if(!(((wks[1]-2)<=lp) && (lp<=((wks[1])%21)))){
			ve=(VERTS*)&A_TMD[1][17+((20-lp)*9)];
			ve->cba=((D_DEF_CLUT_Y)<<6);
		}
		if(!(((wks[2]-2)<=lp) && (lp<=((wks[2])%21)))){
			ve=(VERTS*)&A_TMD[2][17+((20-lp)*9)];
			ve->cba=((D_DEF_CLUT_Y)<<6);
		}
	}
	bitt[0]=0x0001;
	bitt[1]=0x0008;
	bitt[2]=0x0040;


	for(lp=0;lp<3;lp++){
		if(wk & bitt[0]){	/*ビットが立ってたら光らす*/
			ve=(VERTS*)&A_TMD[0][17+(((20-(_WK_REEL[0][5]+hiku[lp])%21))*9)];
			ve->cba=((D_DEF_CLUT_Y+1)<<6);
			shib_+=1;
		}else{
			ve=(VERTS*)&A_TMD[0][17+(((20-(_WK_REEL[0][5]+hiku[lp])%21))*9)];
			ve->cba=((D_DEF_CLUT_Y)<<6);
		}

		if(wk & bitt[1]){	/*ビットが立ってたら光らす*/
			ve=(VERTS*)&A_TMD[1][17+(((20-(_WK_REEL[1][5]+hiku[lp])%21))*9)];
			ve->cba=((D_DEF_CLUT_Y+1)<<6);
			shib_+=1;
		}else{
			ve=(VERTS*)&A_TMD[1][17+(((20-(_WK_REEL[1][5]+hiku[lp])%21))*9)];
			ve->cba=((D_DEF_CLUT_Y)<<6);
		}

		if(wk & bitt[2]){	/*ビットが立ってたら光らす*/
			ve=(VERTS*)&A_TMD[2][17+(((20-(_WK_REEL[2][5]+hiku[lp])%21))*9)];
			ve->cba=((D_DEF_CLUT_Y+1)<<6);
			shib_+=1;
		}else{
			ve=(VERTS*)&A_TMD[2][17+(((20-(_WK_REEL[2][5]+hiku[lp])%21))*9)];
			ve->cba=((D_DEF_CLUT_Y)<<6);
		}
		bitt[0]=(bitt[0]<<1);
		bitt[1]=(bitt[1]<<1);
		bitt[2]=(bitt[2]<<1);
	}

	}else{
		for(lp=0;lp<21;lp++){	/* 取り敢えず全部あかるく */
			ve=(VERTS*)&A_TMD[0][17+((20-lp)*9)];
			ve->cba=((D_DEF_CLUT_Y+1)<<6);
			ve=(VERTS*)&A_TMD[1][17+((20-lp)*9)];
			ve->cba=((D_DEF_CLUT_Y+1)<<6);
			ve=(VERTS*)&A_TMD[2][17+((20-lp)*9)];
			ve->cba=((D_DEF_CLUT_Y+1)<<6);
		}
	}

	if(submenu_sts!=0){
		pad_shibirenai();
	}else{
		if((0<shib_) && (shib_<9)){
			if(!MACINE){
				if(_WK_BACK_LP.lamp!=2){/* セーバーの時*/
					pad_shibireru();
				}else{
					pad_shibirenai();
				}
			}else{
				pad_shibireru();
			}
		}else{
			if(!MACINE){
				if(_WK_BACK_LP.lamp==6){
					pad_shibireru();
				}else{
					pad_shibirenai();
				}
			}else{
				pad_shibirenai();
			}
		}
	}

	_PT_OUT8=bk;
	_PT_OUT7=bk2;
}



/////////////////////////////////////////////////////////////////////////
//
//	筐体作成
//
/////////////////////////////////////////////////////////////////////////
//	筐体のＣＧの読み込みとスプライトの設定			//
//	sw:1	次のズームレベルに移行してセット		//
//	sw:2	スプライトオブジェを作成してからセット	//
void kyoutai_set(int sw)
{
	short l_data[4][8]={
		{480,224,-160,(-120)+8,64,256-224,((480%64)*2),224},
		{512,224,(-160)+64,(-120)+8,256,256-224,0,224},
		{480,256,-160,((-120)+8)+(256-224),64,(240-16)-(256-224),((480%64)*2),0},
		{512,256,(-160)+64,((-120)+8)+(256-224),256,(240-16)-(256-224),0,0},
	};
	int lp;
	if(sw==1)	ZOOM_LEVEL=(ZOOM_LEVEL+1)%3;
	if(sw==-1)	ZOOM_LEVEL=(ZOOM_LEVEL+2)%3;
	if(sw==2){
		for(lp=0;lp<KYOUTAI_SP_MAX;lp++)	kyoutai_sp[lp]=sprobj_make();
		for(lp=0;lp<LAMP_SP_MAX;lp++)		lamp_sp[lp]=sprobj_make();
		slot_tex_set(1);
		NOW_ZERO_Y=0;
	}

//	すべてのＳＰに共通する設定
	for(lp=0;lp<KYOUTAI_SP_MAX;lp++){
		kyoutai_sp[lp]->pri = 80;	//	適当だけど本番用
		kyoutai_sp[lp]->attribute = GsCLUT8;
		sprobj_doff(kyoutai_sp[lp]);
	}
	for(lp=0;lp<LAMP_SP_MAX;lp++){
		lamp_sp[lp]->pri = 80-1;	//	台より一個優先が高い
		lamp_sp[lp]->attribute = GsCLUT8;
		sprobj_doff(lamp_sp[lp]);
	}
//	モード別の設定
	switch(ZOOM_LEVEL){
		case 0:
			NOW_ZERO_Y=0;
			for(lp=0;lp<KYOUTAI_SP_MAX;lp++){
//	デフォルト設定
				kyoutai_sp[lp]->tpage = GetTPage(0, 0, 320+((lp%5)*32),((lp/5)*64));
				kyoutai_sp[lp]->x = ((lp%5)*64)-160;
				kyoutai_sp[lp]->y = ((((lp/5)*64)+(DEF_ZERO_Y+NOW_ZERO_Y)));
				kyoutai_sp[lp]->u = ((lp%5)*64)%128;
				kyoutai_sp[lp]->v = ((lp/5)*64)%256;
//				kyoutai_sp[lp]->mx = 0;
//				kyoutai_sp[lp]->my = 0;
				kyoutai_sp[lp]->w = 64;
				if(lp<30)	kyoutai_sp[lp]->h = 64;
				else		kyoutai_sp[lp]->h = 48;
				kyoutai_sp[lp]->cx = 320;
				kyoutai_sp[lp]->cy = 450+lp;
				sprobj_don(kyoutai_sp[lp]);
			}
			for(lp=0;lp<LAMP_S_MAX;lp++){
//	デフォルト設定
//LAMP_DATA_TBL[][]
// cx     cy     px     py     w      h  x  y
				lamp_sp[lp]->tpage = GetTPage(0, 0,LAMP_DATA_TBL_S[lp][2],LAMP_DATA_TBL_S[lp][3]);
				lamp_sp[lp]->x = kyoutai_sp[0]->x+LAMP_DATA_TBL_S[lp][6];
				lamp_sp[lp]->y = kyoutai_sp[0]->y+LAMP_DATA_TBL_S[lp][7];
				lamp_sp[lp]->u = (LAMP_DATA_TBL_S[lp][2]%64)*2;
				lamp_sp[lp]->v = LAMP_DATA_TBL_S[lp][3]%256;
				lamp_sp[lp]->w = LAMP_DATA_TBL_S[lp][4]*2;
				lamp_sp[lp]->h = LAMP_DATA_TBL_S[lp][5];
				lamp_sp[lp]->cx = LAMP_DATA_TBL_S[lp][0];
				lamp_sp[lp]->cy = LAMP_DATA_TBL_S[lp][1];
//				sprobj_don(lamp_sp[lp]);
			}
		break;
		case 1:
			for(lp=0;lp<20;lp++){

//	デフォルト設定
				kyoutai_sp[lp]->tpage = GetTPage(0, 0, 480+((lp%5)*32),((lp/5)*64));
				kyoutai_sp[lp]->x = ((lp%5)*64)-160;
				kyoutai_sp[lp]->y = (((lp/5)*64)-(120-8));
				if(!(lp%5))	kyoutai_sp[lp]->u = ((480%64)*2);
				else		kyoutai_sp[lp]->u = ((((lp-1)%5)*64)%128);
				kyoutai_sp[lp]->v = ((lp/5)*64)%256;
				kyoutai_sp[lp]->mx = 0;
				kyoutai_sp[lp]->my = 0;
				kyoutai_sp[lp]->w = 64;
				if(lp<15)	kyoutai_sp[lp]->h = 64;
				else		kyoutai_sp[lp]->h = 64-16;

				kyoutai_sp[lp]->cx = 320;
				kyoutai_sp[lp]->cy = 485+lp;
				sprobj_don(kyoutai_sp[lp]);
			}

			for(lp=0;lp<LAMP_M_MAX;lp++){
//	デフォルト設定
//LAMP_DATA_TBL[][]
// cx     cy     px     py     w      h  x  y
				lamp_sp[lp]->tpage = GetTPage(0, 0,LAMP_DATA_TBL_M[lp][2],LAMP_DATA_TBL_M[lp][3]);
				lamp_sp[lp]->x = kyoutai_sp[0]->x+LAMP_DATA_TBL_M[lp][6];
				lamp_sp[lp]->y = kyoutai_sp[0]->y+LAMP_DATA_TBL_M[lp][7]-8;
				lamp_sp[lp]->u = (LAMP_DATA_TBL_M[lp][2]%64)*2;
				lamp_sp[lp]->v = LAMP_DATA_TBL_M[lp][3]%256;
				lamp_sp[lp]->w = LAMP_DATA_TBL_M[lp][4]*2;
				lamp_sp[lp]->h = LAMP_DATA_TBL_M[lp][5];
				lamp_sp[lp]->cx = LAMP_DATA_TBL_M[lp][0];
				lamp_sp[lp]->cy = LAMP_DATA_TBL_M[lp][1];
//				sprobj_don(lamp_sp[lp]);
			}
		break;
		case 2:
			for(lp=0;lp<4;lp++){
				kyoutai_sp[lp]->tpage = GetTPage(0, 0, l_data[lp][0],l_data[lp][1]);
				kyoutai_sp[lp]->x = l_data[lp][2];
				kyoutai_sp[lp]->y = l_data[lp][3];
				kyoutai_sp[lp]->w = l_data[lp][4];
				kyoutai_sp[lp]->h = l_data[lp][5];
				kyoutai_sp[lp]->u = l_data[lp][6];
				kyoutai_sp[lp]->v = l_data[lp][7];
				kyoutai_sp[lp]->mx = 0;
				kyoutai_sp[lp]->my = 0;
				kyoutai_sp[lp]->cx = 320;
				kyoutai_sp[lp]->cy = 505;
				sprobj_don(kyoutai_sp[lp]);
			}

//	デフォルト設定
//LAMP_DATA_TBL[][]
// cx     cy     px     py     w      h  x  y y
			for(lp=0;lp<LAMP_L_MAX;lp++){
				lamp_sp[lp]->tpage = GetTPage(0, 0,LAMP_DATA_TBL_L[lp][2],LAMP_DATA_TBL_L[lp][3]);
				lamp_sp[lp]->x = kyoutai_sp[0]->x+LAMP_DATA_TBL_L[lp][6];
				lamp_sp[lp]->y = kyoutai_sp[0]->y+LAMP_DATA_TBL_L[lp][7]-8;
				lamp_sp[lp]->u = (LAMP_DATA_TBL_L[lp][2]%64)*2;
				lamp_sp[lp]->v = LAMP_DATA_TBL_L[lp][3]%256;
				lamp_sp[lp]->w = LAMP_DATA_TBL_L[lp][4]*2;
				lamp_sp[lp]->h = LAMP_DATA_TBL_L[lp][5];
				lamp_sp[lp]->cx = LAMP_DATA_TBL_L[lp][0];
				lamp_sp[lp]->cy = LAMP_DATA_TBL_L[lp][1];
//				sprobj_don(lamp_sp[lp]);
			}

		break;
	}
	DrawSync(0);
	slot_tex_set(0);
	drum_view_set();
	kyoutai_move();
}

void kyoutai_move(void)
{
	int lp;
	if(!ZOOM_LEVEL){
		for(lp=0;lp<KYOUTAI_SP_MAX;lp++)
			kyoutai_sp[lp]->y = ((((lp/5)*64)+(DEF_ZERO_Y+NOW_ZERO_Y)));

		for(lp=0;lp<LAMP_S_MAX;lp++)
			lamp_sp[lp]->y = kyoutai_sp[0]->y+LAMP_DATA_TBL_S[lp][7];

		for(lp=0;lp<3;lp++){
			drum_coord[lp]->t[TY] = drum_y[MACINE][ZOOM_LEVEL][lp]+(NOW_ZERO_Y*25);
			RotMatrix(&(drum_param[lp]->rotate),drum_coord[lp]);
			drum[lp]->coord2->flg = 0;
		}
	}
}


void hard_all_kill(void)
{
	int lp;

	while(hd_inter==2);

	hd_inter=0;	//	割り込みを終わらせておく

	for(lp=0;lp<KYOUTAI_SP_MAX;lp++)	sprobj_kill(kyoutai_sp[lp]);
	for(lp=0;lp<LAMP_SP_MAX;lp++)		sprobj_kill(lamp_sp[lp]);

	drum_end();

	game_vab_end();
	game_seq_stop();
	toggle_start_ok=0;

//	wait(1);
	draw_rq=0;	//	書き込む
	wait(1);
	draw_rq=1;	//	書き込む
	rect_ef0(0,((actframe^1)*240),0,((actframe)*240));
//	rect_ef00(0,(0,(actframe^1)*240),320,240);
	draw_rq=0;
}


void ramp_hikare(void)
{
	if(_NB_PLAY_MEDAL==0){
		sprobj_doff(LU_PAY3D);
		sprobj_doff(LU_PAY3U);
		sprobj_doff(LU_PAY2U);
		sprobj_doff(LU_PAY2D);
		sprobj_doff(LU_PAY1);
	}else if(_NB_PLAY_MEDAL==1){
		sprobj_doff(LU_PAY3D);
		sprobj_doff(LU_PAY3U);
		sprobj_doff(LU_PAY2U);
		sprobj_doff(LU_PAY2D);
		sprobj_don(LU_PAY1);
	}else if(_NB_PLAY_MEDAL==2){
		sprobj_doff(LU_PAY3D);
		sprobj_doff(LU_PAY3U);
		sprobj_don(LU_PAY2U);
		sprobj_don(LU_PAY2D);
		sprobj_don(LU_PAY1);
	}else if(_NB_PLAY_MEDAL==3){
		sprobj_don(LU_PAY3D);
		sprobj_don(LU_PAY3U);
		sprobj_don(LU_PAY2U);
		sprobj_don(LU_PAY2D);
		sprobj_don(LU_PAY1);
	}
}

/////////////////////////////////////////////////////////////////////////
//	ランプ
/////////////////////////////////////////////////////////////////////////

void lamp_on_off(void)
{
	int lp;
//	MEDAL LINE LUMP
	if(_PT_OUT5&0x01)	sprobj_don(LU_PAY3D);
	else				sprobj_doff(LU_PAY3D);
	if(_PT_OUT5&0x02)	sprobj_don(LU_PAY2D);
	else				sprobj_doff(LU_PAY2D);
	if(_PT_OUT5&0x04)	sprobj_don(LU_PAY1);
	else				sprobj_doff(LU_PAY1);
	if(_PT_OUT5&0x08)	sprobj_don(LU_PAY2U);
	else				sprobj_doff(LU_PAY2U);
	if(_PT_OUT5&0x10)	sprobj_don(LU_PAY3U);
	else				sprobj_doff(LU_PAY3U);

	if(swp->cur_win == 8/*SM_REVIEW*/){
	/* プレイリビュー中 */
		ramp_hikare();
	}

//	drum_light3();

	if(_PT_OUT1&0x20)	sprobj_don(LU_WAIT);
	else				sprobj_doff(LU_WAIT);

//	メダルインランプ
	if(_PT_OUT7&(0x01<<6))	sprobj_don(LU_MEDAL_IN);
	else					sprobj_doff(LU_MEDAL_IN);

//	貧乏神
	if(_PT_OUT5&(0x01<<5))	sprobj_don(LU_BINBOU);
	else					sprobj_doff(LU_BINBOU);

//	桜
	if(_PT_OUT5&(0x01<<6))	sprobj_don(LU_SAKURA);
	else					sprobj_doff(LU_SAKURA);

//	神様
	if(_PT_OUT5&(0x01<<7))	sprobj_don(LU_KAMISAMA);
	else					sprobj_doff(LU_KAMISAMA);

	if(_PT_OUT2&(0x01<<5))	sprobj_don(LU_OMEDETO);
	else					sprobj_doff(LU_OMEDETO);

	if(_PT_OUT2&(0x01<<6))	sprobj_don(LU_ATARI);
	else					sprobj_doff(LU_ATARI);

	if(!MACINE){
		if(mode_game==5){
			sprobj_doff(LU_KOZUCHI);
		}else{
			if(_PT_OUT2&(0x01<<7))	sprobj_don(LU_KOZUCHI);
			else					sprobj_doff(LU_KOZUCHI);
		}
	}else{
		if(_PT_OUT2&(0x01<<7))	sprobj_don(LU_KOZUCHI);
		else					sprobj_doff(LU_KOZUCHI);
	}

	switch(ZOOM_LEVEL){
		case 0:	//	ミニサイズのみ
			//	レバー
			if(IN0_PORT&(0x01<<5))	sprobj_don(LU_REBER);
			else					sprobj_doff(LU_REBER);

			//	ＯＮＥベットボタン
			if(IN0_PORT&(0x01<<0))	sprobj_don(LU_ONE_BET);
			else					sprobj_doff(LU_ONE_BET);

			//	ＴＷＯベットボタン
			if(IN0_PORT&(0x01<<1))	sprobj_don(LU_TWO_BET);
			else					sprobj_doff(LU_TWO_BET);

			//	ストップ押左
			if(!(IN2_PORT&(0x01<<5)))	sprobj_don(LU_STOP_L);
			else					sprobj_doff(LU_STOP_L);

			//	ストップ押中
			if(!(IN2_PORT&(0x01<<6)))	sprobj_don(LU_STOP_C);
			else						sprobj_doff(LU_STOP_C);

			//	ストップ押右
			if(!(IN2_PORT&(0x01<<7)))	sprobj_don(LU_STOP_R);
			else						sprobj_doff(LU_STOP_R);

			//	ストップ無押左点灯
			if(_PT_OUT7&(0x01<<0))	sprobj_don(LU_STOP_L2);
			else					sprobj_doff(LU_STOP_L2);

			//	ストップ無押中点灯
			if(_PT_OUT7&(0x01<<1))	sprobj_don(LU_STOP_C2);
			else					sprobj_doff(LU_STOP_C2);

			//	ストップ無押右点灯
			if(_PT_OUT7&(0x01<<2))	sprobj_don(LU_STOP_R2);
			else					sprobj_doff(LU_STOP_R2);

			//	上部ランプ左端から
			for(lp=0;lp<8;lp++){
				if(_PT_OUT6&(0x01<<lp))	sprobj_don(lamp_sp[S_KOYUU+lp]);
				else					sprobj_doff(lamp_sp[S_KOYUU+lp]);
			}

		case 1:	//	中間サイズとミニサイズ共通

			//	ＭＡＸベットボタン
			if(IN0_PORT&(0x01<<2))	sprobj_don(LU_MAX_BET);
			else					sprobj_doff(LU_MAX_BET);

			if(_PT_OUT2&(0x01<<4)){
				sprobj_don(LU_REPLAY);
				sprobj_don(LU_REPLAY_U);
			}
			else{
				sprobj_doff(LU_REPLAY);
				sprobj_doff(LU_REPLAY_U);
			}
			digital_set();
		break;
	}
}

//	ＷＩＮランプ用		no=0
//	クレジット用		no=1
//	ゲームランプ用		no=2
//	カウントランプ用	no=3
void digital_set(void)
{
	char wk;
	short cre_01s[2][17][2]={
	{	{  0,182},{ 36,182},{ 72,182},{108,182},{144,182},
		{180,182},{216,182},{  0,197},{ 36,197},{ 72,197},{108,197},
		{144,197},{180,197},{216,197},{180,212},{216,212},{ 36, 15},},
	{	{  0,212},{ 24,212},{ 48,212},{ 72,212},{ 96,212},
		{120,212},{  0,228},{ 24,228},{ 48,228},{ 72,228},{ 96,228},
		{120,228},{144,228},{168,228},{192,228},{216,228},{ 24, 16},},
	};

	short win_01s[2][18][2]={
	{	{  0,  0},{ 40,  0},{ 80,  0},
		{120,  0},{160,  0},{200,  0},{  0, 34},{ 40, 34},
		{ 80, 34},{120, 34},{160, 34},{200, 34},{  0, 68},
		{ 40, 68},{ 80, 68},{120, 68},{160, 68},{ 40, 34},},
	{	{  0,102},{ 28,102},{ 56,102},
		{ 84,102},{112,102},{140,102},{168,102},{196,102},
		{224,102},{  0,142},{ 28,142},{ 56,142},{ 84,142},
		{112,142},{140,142},{168,142},{196,142},{ 28, 40},},
	};

	short cou_01s[2][14][2]={
	{	{  0,  0},{ 36,  0},{  0, 15},{ 36, 15},
		{  0, 30},{ 36, 30},{  0, 45},{ 36, 45},{  0, 60},
		{ 36, 60},{  0, 75},{ 36, 75},{  0, 90},{ 36, 15},},

	{	{  0,132},{ 20,132},{ 40,132},{  0,148},
		{ 20,148},{ 40,148},{  0,164},{ 20,164},{ 40,164},
		{  0,180},{ 20,180},{ 40,180},{  0,196},{ 20, 16},},
	};

	short gam_01s[2][10][2]={
	{	{  0,106},{ 12,106},{ 24,106},{ 36,106},{ 48,106},
		{ 60,106},{  0,119},{ 12,119},{ 24,119},{ 12, 13},},

	{	{ 36,196},{ 48,196},{ 60,196},{  0,212},{ 12,212},
		{ 24,212},{ 36,212},{ 48,212},{ 60,212},{ 12, 16}},
	};


	if(ZOOM_LEVEL==2)	return;

//	if(dig_r[0]!=_NB_CREDIT_LED){
		dig_r[0]=_NB_CREDIT_LED;
		if(_NB_CREDIT_LED!=0xFF){	//	クレジット
			DIG_CR_R->u = cre_01s[ZOOM_LEVEL][_NB_CREDIT_LED%10][0];
			DIG_CR_R->v = cre_01s[ZOOM_LEVEL][_NB_CREDIT_LED%10][1];
			DIG_CR_R->w = cre_01s[ZOOM_LEVEL][16][0];
			DIG_CR_R->h = cre_01s[ZOOM_LEVEL][16][1];

			DIG_CR_L->u = cre_01s[ZOOM_LEVEL][(_NB_CREDIT_LED/10)+10][0];
			DIG_CR_L->v = cre_01s[ZOOM_LEVEL][(_NB_CREDIT_LED/10)+10][1];
			DIG_CR_L->w = cre_01s[ZOOM_LEVEL][16][0];
			DIG_CR_L->h = cre_01s[ZOOM_LEVEL][16][1];

			sprobj_don(DIG_CR_R);	//	10の位
			sprobj_don(DIG_CR_L);	//	 1の位
		}else{
			sprobj_doff(DIG_CR_R);	//	10の位
			sprobj_doff(DIG_CR_L);	//	 1の位
		}
//	}

//	if(dig_r[1]!=_NB_PAY_LED){
		dig_r[1]=_NB_PAY_LED;
		if(_NB_PAY_LED!=0xFF){
			if((_NB_PAY_LED&0x0F)!=0x7F){
				DIG_WIN->u = win_01s[ZOOM_LEVEL][_NB_PAY_LED&0x0F][0];
				DIG_WIN->v = win_01s[ZOOM_LEVEL][_NB_PAY_LED&0x0F][1];
				DIG_WIN->w = win_01s[ZOOM_LEVEL][17][0];
				DIG_WIN->h = win_01s[ZOOM_LEVEL][17][1];
				DIG_WINP->u = win_01s[ZOOM_LEVEL][16][0];
				DIG_WINP->v = win_01s[ZOOM_LEVEL][16][1];
				DIG_WINP->w = win_01s[ZOOM_LEVEL][17][0];
				DIG_WINP->h = win_01s[ZOOM_LEVEL][17][1];
				sprobj_don(DIG_WIN);
			}else					sprobj_doff(DIG_WIN);

			if(_NB_PAY_LED&0x80)	sprobj_don(DIG_WINP);
			else					sprobj_don(DIG_WINP);
		}
		else{
			sprobj_doff(DIG_WIN);
			sprobj_doff(DIG_WINP);
		}
//	}

//	if(dig_r[2]!=_NB_COUNT_LED1){
		dig_r[2]=_NB_COUNT_LED1;
		if(_NB_COUNT_LED1!=0xFF){
			DIG_CO_R->u = cou_01s[ZOOM_LEVEL][_NB_COUNT_LED1%10][0];
			DIG_CO_R->v = cou_01s[ZOOM_LEVEL][_NB_COUNT_LED1%10][1];
			DIG_CO_R->w = cou_01s[ZOOM_LEVEL][13][0];
			DIG_CO_R->h = cou_01s[ZOOM_LEVEL][13][1];
			sprobj_don(DIG_CO_R);

			if(_NB_COUNT_LED1>9){
				DIG_CO_L->u = cou_01s[ZOOM_LEVEL][(_NB_COUNT_LED1/10)+9][0];
				DIG_CO_L->v = cou_01s[ZOOM_LEVEL][(_NB_COUNT_LED1/10)+9][1];
				DIG_CO_L->w = cou_01s[ZOOM_LEVEL][13][0];
				DIG_CO_L->h = cou_01s[ZOOM_LEVEL][13][1];
				sprobj_don(DIG_CO_L);
			}else{
			 sprobj_doff(DIG_CO_L);
			}
		}else{
			sprobj_doff(DIG_CO_R);
			sprobj_doff(DIG_CO_L);
		}
//	}

//	ゲーム表示
//	if(dig_r[3]!=_NB_COUNT_LED2){
	if((_FL_ACTION & (0x01<<BT_RB))){	//	ＲＢ作動中
		if(mode_game==5){
			sprobj_doff(DIG_CO_R);
			sprobj_doff(DIG_CO_L);
			sprobj_doff(DIG_GAME);
		}else{

		dig_r[2]=_CT_BONUS_WIN;
		if(_CT_BONUS_WIN!=0xFF){
			DIG_CO_R->u = cou_01s[ZOOM_LEVEL][_CT_BONUS_WIN%10][0];
			DIG_CO_R->v = cou_01s[ZOOM_LEVEL][_CT_BONUS_WIN%10][1];
			DIG_CO_R->w = cou_01s[ZOOM_LEVEL][13][0];
			DIG_CO_R->h = cou_01s[ZOOM_LEVEL][13][1];
			sprobj_don(DIG_CO_R);

			if(_CT_BONUS_WIN>9){
				DIG_CO_L->u = cou_01s[ZOOM_LEVEL][(_CT_BONUS_WIN/10)+9][0];
				DIG_CO_L->v = cou_01s[ZOOM_LEVEL][(_CT_BONUS_WIN/10)+9][1];
				DIG_CO_L->w = cou_01s[ZOOM_LEVEL][13][0];
				DIG_CO_L->h = cou_01s[ZOOM_LEVEL][13][1];
				sprobj_don(DIG_CO_L);
			}else{
			 sprobj_doff(DIG_CO_L);
			}
		}else{
			sprobj_doff(DIG_CO_R);
			sprobj_doff(DIG_CO_L);
		}


		if((_FL_ACTION & (0x01<<BT_BB))){	//	ＢＢ中のＲＢ作動中
			dig_r[3]=_NB_COUNT_LED2;
			if(_NB_COUNT_LED2!=0x0F){
				if(_NB_COUNT_LED2==0)	sprobj_doff(DIG_GAME);
				else{
				if(_NB_COUNT_LED2==0x0E)	wk=8;
				else						wk=_NB_COUNT_LED2-1;
				DIG_GAME->u = gam_01s[ZOOM_LEVEL][wk][0];
				DIG_GAME->v = gam_01s[ZOOM_LEVEL][wk][1];
				DIG_GAME->w = gam_01s[ZOOM_LEVEL][9][0];
				DIG_GAME->h = gam_01s[ZOOM_LEVEL][9][1];
				sprobj_don(DIG_GAME);
				}
			}else{
				sprobj_doff(DIG_GAME);
			}
		}else{	//	ＲＢ単体の表示
			_NB_COUNT_LED2=0x0E;
			dig_r[3]=_NB_COUNT_LED2;
			if(_NB_COUNT_LED2!=0x0F){
				if(_NB_COUNT_LED2==0)	sprobj_doff(DIG_GAME);
				else{
					if(_NB_COUNT_LED2==0x0E)	wk=8;
					else					wk=_NB_COUNT_LED2-1;
					DIG_GAME->u = gam_01s[ZOOM_LEVEL][wk][0];
					DIG_GAME->v = gam_01s[ZOOM_LEVEL][wk][1];
					DIG_GAME->w = gam_01s[ZOOM_LEVEL][9][0];
					DIG_GAME->h = gam_01s[ZOOM_LEVEL][9][1];
					sprobj_don(DIG_GAME);
				}
			}else{
				sprobj_doff(DIG_GAME);
			}
		}
		}
	}else{	//	ＢＢ中ＲＢじゃない
		if(mode_game==5){
			sprobj_doff(DIG_CO_R);
			sprobj_doff(DIG_CO_L);
			sprobj_doff(DIG_GAME);
		}else{

		dig_r[2]=_NB_COUNT_LED1;
		if(_NB_COUNT_LED1!=0xFF){
			DIG_CO_R->u = cou_01s[ZOOM_LEVEL][_NB_COUNT_LED1%10][0];
			DIG_CO_R->v = cou_01s[ZOOM_LEVEL][_NB_COUNT_LED1%10][1];
			DIG_CO_R->w = cou_01s[ZOOM_LEVEL][13][0];
			DIG_CO_R->h = cou_01s[ZOOM_LEVEL][13][1];
			sprobj_don(DIG_CO_R);

			if(_NB_COUNT_LED1>9){
				DIG_CO_L->u = cou_01s[ZOOM_LEVEL][(_NB_COUNT_LED1/10)+9][0];
				DIG_CO_L->v = cou_01s[ZOOM_LEVEL][(_NB_COUNT_LED1/10)+9][1];
				DIG_CO_L->w = cou_01s[ZOOM_LEVEL][13][0];
				DIG_CO_L->h = cou_01s[ZOOM_LEVEL][13][1];
				sprobj_don(DIG_CO_L);
			}else{
			 sprobj_doff(DIG_CO_L);
			}
		}else{
			sprobj_doff(DIG_CO_R);
			sprobj_doff(DIG_CO_L);
		}
		dig_r[3]=_NB_COUNT_LED2;
		if(_NB_COUNT_LED2!=0x0F){
			if(_NB_COUNT_LED2==0)	sprobj_doff(DIG_GAME);
			else{
			if(_NB_COUNT_LED2==0x0E)	wk=8;
			else						wk=_NB_COUNT_LED2-1;
			DIG_GAME->u = gam_01s[ZOOM_LEVEL][wk][0];
			DIG_GAME->v = gam_01s[ZOOM_LEVEL][wk][1];
			DIG_GAME->w = gam_01s[ZOOM_LEVEL][9][0];
			DIG_GAME->h = gam_01s[ZOOM_LEVEL][9][1];
			sprobj_don(DIG_GAME);
			}
		}else{
			sprobj_doff(DIG_GAME);
		}
	}
	}
}


/////////////////////////////////////////////////////////////////////////
//
//	初期化　割り込み
//
/////////////////////////////////////////////////////////////////////////
/*	各種スイッチのチェック							*/
/*	機械制御部分のＰＡＤへの割り当てを取り決める	*/

//; 入力ポート０ (@IN0_PORT)		　　　	     ACTIVE
//;BIT 0		１枚投入ボタンスイッチ			H
//;    1		２枚投入ボタンスイッチ			H
//;    2		３枚投入ボタンスイッチ			H
//;    3		遊技メダル払出センサー信号		H
//;    4		精算ボタンスイッチ				H
//;    5		回胴回転始動装置スイッチ		H
//;    6		設定用キースイッチ		 		H
//;    7		打止解除スイッチ		 		H
//
//#define IN0_POSI	(0xff)	//1111 1111B	//; 入力ポート０正論理ビット
//char	IN0_POSI;	//(0xff)	//1111 1111B	//; 入力ポート０正論理ビット
//
//; 入力ポート１ (@IN1_PORT)		　　　	     ACTIVE
//;BIT 0		自動払戻切替スイッチ			H
//;    1		エラー解除スイッチ				H
//;    2		打止切替スイッチ				H
//;    3		設定ボタンスイッチ				H
//;    4		遊技メダル投入センサー１（先）	L
//;    5		遊技メダル投入センサー２（後）	L
//;    6		未使用							NC
//;    7		外部打止め解除信号				L
//
//#define IN1_POSI	(0x0f)	//00001111B	//; 入力ポート１正論理ビット
//char	IN1_POSI;	//(0x0f)	//00001111B	//; 入力ポート１正論理ビット
//
//; 入力ポート２ (@IN2_PORT)		　　　	     ACTIVE
//;BIT 0		第１回胴センサー				L
//;    1		第２回胴センサー				L
//;    2		第３回胴センサー				L
//;    3		未使用							NC
//;    4		未使用							NC
//;    5		本体停止ボタン第１回胴			L
//;    6		本体停止ボタン第２回胴			L
//;    7		本体停止ボタン第３回胴			L
//


void hardware_init(void)
{
	DRUM_ARIMASU	= 0;
	hd_inter=0;	//	割り込み禁止にしておく
	toggle_start_ok=0;

}

//	ゲーム中のハードウェア制御（スロット等）

int dsd=0;
short zom=0;

void kyoutai_ugoke(void)
{
	if((mode_game!=4) && (mode_game!=7)){
		if(zom){
			kyoutai_set(zom);		//	引数１で次のモードへ
			zom=0;
		//	wait(1);
		}


		if(!ZOOM_LEVEL){	//	筐体上下移動
			if((pad_beta&PAD_L1)&&(pad_beta&PADL_U)){
				if((-150)<NOW_ZERO_Y){
					NOW_ZERO_Y-=1;
					kyoutai_move();
				}
			}
			if((pad_beta&PAD_L1)&&(pad_beta&PADL_D)){
				if((44+8)>NOW_ZERO_Y){
					NOW_ZERO_Y+=1;
					kyoutai_move();
				}
			}
		}
	}
}

void hardware_inter(void)
{
	int lp;

	if((submenu_sts==0) || (submenu_sts==50)){
	if(hd_inter){

		if(submenu_sts==0){
			if(game_time<0x01464B40)	game_time+=1;	//	９９時間まで
			kyoutai_ugoke();
			I_INTR();
		}
		drum_spin();	//	ドラムの回転制御
		if(submenu_sts==0){
		lamp_on_off();

		if(mode_game!=5)
		if (FLAG_BIG) {
			play_mode = 1;
		} else if (FLAG_REG) {
			if (_FL_ACTION & _JAC)
				play_mode = 4;
			else
				play_mode = 2;
		} else {
			if ((!_FL_ACTION)){
				play_mode = 0;
			} else {
				if (_FL_ACTION & _JAC) {
					play_mode = 4;
				} else if (_FL_ACTION & _RP) {
					play_mode = 0;
				} else {
					play_mode = 3;
				}
			}
		}
	}
	}
	}
}

#if 0
char (*TBL_BACK_DATA[2][9])={
{
	TBL_B_ALL,	//	ダミー
//; （１０）入賞期待終了時の出力要求
		{0,		KAP_ELP_CLEAR,	KAP_BLP_ALL,	KAP_SD_CLEAR1 ,},
	TBL_B_ALL,
//; （１０）入賞期待終了時の出力要求
		{0,		KAP_ELP_CLEAR,	KAP_BLP_ALL,	KAP_SD_CLEAR1 ,},
	TBL_B_SAVER,
//; （１）遊技待機時の出力要求
		{0,		0,		KAP_BLP_SAVER,	0 ,},
	TBL_B_BBHIT1,
//; （２）役物連続作動増加装置入賞時の出力要求１(ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
		{KAP_FLP_BBHIT1,	KAP_ELP_BBHIT1,	KAP_BLP_BBHIT1,	KAP_SD_BBHIT1 ,},
	TBL_B_BBHIT2,
//; （３）役物連続作動増加装置入賞時の出力要求２(かっぱ･かっぱ･かっぱ)
		{KAP_FLP_BBHIT2,	KAP_ELP_BBHIT2,	KAP_BLP_BBHIT2,	KAP_SD_BBHIT2 ,},
	TBL_B_BBEND,
//; （５）役物連続作動増加装置作動終了時の出力要求
		{KAP_FLP_BBEND,	KAP_ELP_BBEND,	KAP_BLP_BBEND,	KAP_SD_BBEND ,},
	TBL_B_STOP1,
//; （１９）回胴回転停止時（点滅パターンａ）の出力要求
		{0,		0,		KAP_BLP_STOP1,	0 ,},
	TBL_B_STOP2,
//; （２０）回胴回転停止時（点滅パターンｂ）の出力要求
		{0,		0,		KAP_BLP_STOP2,	0 ,},
	TBL_B_STOP3,
//; （２１）回胴回転停止時（点滅パターンｃ）の出力要求
		{0,		0,		KAP_BLP_STOP3,	0 ,},
},
{
	B_TBL_B_ALL,
//; （１７）入賞期待終了時の出力要求
	{0,		BIN_ELP_CLEAR,	BIN_BLP_ALL,	BIN_SD_CLEAR1},
	B_TBL_B_ALL,
//; （１７）入賞期待終了時の出力要求
	{0,		BIN_ELP_CLEAR,	BIN_BLP_ALL,	BIN_SD_CLEAR1},
	B_TBL_B_WBL1,
//; （１３）入賞期待時の出力要求２
//;;（右回胴回転中の中央ライン(福の神･福の神)表示時）
	{0,		BIN_ELP_WBL,	BIN_BLP_WBL1,	BIN_SD_WBL},
	B_TBL_B_WBL2,
//; （１４）入賞期待時の出力要求３
//;;（左回胴チェリー否表示及び右回胴回転中の上段ライン(ｾﾌﾞﾝ･ｾﾌﾞﾝ)表示時）
	{0,		BIN_ELP_WBL,	BIN_BLP_WBL2,	BIN_SD_WBL},
	B_TBL_B_WBL3,
//; （１５）入賞期待時の出力要求４
//;;（右回胴回転中の上段ライン(福の神･福の神)表示時）
	{0,		BIN_ELP_WBL,	BIN_BLP_WBL3,	BIN_SD_WBL},
	B_TBL_B_WBL4,
//; （１６）入賞期待時の出力要求５
//;;（左回胴チェリー否表示及び右回胴回転中の下段ライン(BAR･BAR)表示時）
	{0,		BIN_ELP_WBL,	BIN_BLP_WBL4,	BIN_SD_WBL},
	B_TBL_B_BBHIT1,
//; （７）役物連続作動増加装置入賞時の出力要求１(ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
	{BIN_FLP_BBHIT1,	BIN_ELP_BBHIT1,	BIN_BLP_BBHIT1,	BIN_SD_BBHIT1},
	B_TBL_B_BBHIT2,
//; （８）役物連続作動増加装置入賞時の出力要求２(福の神･福の神･福の神)
	{BIN_FLP_BBHIT2,	BIN_ELP_BBHIT2,	BIN_BLP_BBHIT2,	BIN_SD_BBHIT2},
	B_TBL_B_BBEND,
//; （９）役物連続作動増加装置作動終了時の出力要求
	{BIN_FLP_BBEND,	BIN_ELP_BBEND,	BIN_BLP_BBEND,	BIN_SD_BBEND},
},
};

かっぱ
//; （１０）入賞期待終了時の出力要求
//; （１０）入賞期待終了時の出力要求
//; （１）遊技待機時の出力要求
{33,33,33},
//; （２）役物連続作動増加装置入賞時の出力要求１(ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
{ 8,20,20},
//; （３）役物連続作動増加装置入賞時の出力要求２(かっぱ･かっぱ･かっぱ)
{17, 3,18},
//; （５）役物連続作動増加装置作動終了時の出力要求
{ 4, 3, 1},
//; （１９）回胴回転停止時（点滅パターンａ）の出力要求
{16,17, 4},
//; （２０）回胴回転停止時（点滅パターンｂ）の出力要求
{ 4,13, 4},
//; （２１）回胴回転停止時（点滅パターンｃ）の出力要求
{ 5, 3, 4},
びんびん
//; （１７）入賞期待終了時の出力要求
//; （１７）入賞期待終了時の出力要求
//; （１３）入賞期待時の出力要求２
{2,7,99},
//; （１４）入賞期待時の出力要求３
{12,19,99},
//; （１５）入賞期待時の出力要求４
{8,6,99},
//; （１６）入賞期待時の出力要求５
{16,5,99},
//; （７）役物連続作動増加装置入賞時の出力要求１(ｾﾌﾞﾝ･ｾﾌﾞﾝ･ｾﾌﾞﾝ)
{20,20,20},
//; （８）役物連続作動増加装置入賞時の出力要求２(福の神･福の神･福の神)
{9,7,6},
//; （９）役物連続作動増加装置作動終了時の出力要求
{100,100,100},
#endif

extern void yubiyubi(void);
extern void flash_setup(void);
int cckk;

void sub_m(void)
{

	if(win_deru_ok){
		if(pad_cnt&PAD_START){
			submenu_sts=10;
			hd_inter=0;
			cckk=1;
			pad_shibirenai();
			pikapika=1;
		}
		while(cckk==1){
			submenu_drv();
			card_seq_check(0);
		//	pad_toreruyo(1);
			if(!submenu_sts){
				cckk=2;
			}
			if((auto_on==1)&&(auto_on_s==0)){
				aupd=1;
				auto_on_s=auto_on;
				auto_point=0;
				while(rackwin[1]!=NULL){
					yubiyubi();
					wait(1);
				}
				vol_kill();
			}
			else{
		//		pad_toreruyo(0);
				wait(1);
			}
		}
		if(cckk==2){
		//	pad_toreruyo(0);
			pikapika=0;
			hd_inter=1;
			cckk=0;
		}
//		hd_inter=1;

		if(mode_game==7){	//	フラッシュミュージアム専用 
			flash_setup();
		}
	}

	if (mode_game == 4) {
		if (r_drum.req) {
			drum_point_set(r_drum.drum_no, r_drum.item_no, r_drum.direc);
			while (_WK_REEL[r_drum.drum_no][5] != r_drum.item_no)
				wait(1);
			r_drum.req = 0;
		}
	}

#if 0
	while(1){
		if(pad_cnt&PADL_U)	drum_point_set(0,_WK_REEL[0][5]+1,1);
		if(pad_cnt&PADL_D)	drum_point_set(0,_WK_REEL[0][5]+20,-1);
		wait(1);
	}
#endif
}

void _med_kau(void)
{
	int lp;
	char cr;
	if(_NB_CREDIT_LED==0xFF)	cr=0;
	else						cr=_NB_CREDIT_LED;

	if(win_deru_ok){
		if((mode_game==0) || (mode_game==3)){
			if(auto_on_s){
			 	if((hand_medal+cr)<4){
					if (use_money < 300) {
						hand_medal += 50;
						use_money++;
						bruse_money++;
						jissen_data_set(0xFF);
					}
					med_kau=0;
				}
			}else if(pad_cnt&PAD_SELECT){
				if(!auto_on_s){
					if (use_money < 300) {
						hand_medal += 50;
						use_money++;
						bruse_money++;
						jissen_data_set(0xFF);
						for(lp=0;lp<10;lp++){
							_SE_RET_MEDAL
							if(rnd(3)==1)	wait(3);
							else			wait(5);
						}
					}
				}
				med_kau=0;
			}
		}
	}
}

int warikomi_k(void)
{

	if((mode_game==7)){	//	フラッシュミュージアム専用
		while((mode_game==7) && (quitflag!=TRUE)){	//	フラッシュミュージアム専用
			sub_m();
		}
	}else{
		if(auto_on_s==0)	sub_m();
	}

	if(quitflag==TRUE){
		return(1);
	}
	_med_kau();
	if(auto_on_s) aupd=1;
	return(0);
}


void jissen_data_set(char mode)
{
	int lp;

	bonus_data[bonus_data_p].game_n	=aft_play_brb;
	bonus_data[bonus_data_p].money	=bruse_money;
	bonus_data[bonus_data_p].item	=mode;

	if(mode!=0xFF)	bonus_data_p+=1;

	if(bonus_data_p>9){
		bonus_data_p=9;
		for(lp=0;lp<9;lp++){
			bonus_data[lp].game_n	=bonus_data[lp+1].game_n;
			bonus_data[lp].money	=bonus_data[lp+1].money;
			bonus_data[lp].item		=bonus_data[lp+1].item;
		}
	}
}


void remember_lot_set(void)
{
	int lp;

	if(st_back_p==50){
		for(lp=0;lp<49;lp++){
			st_back[0][lp]=st_back[0][lp+1];
			st_back[1][lp]=st_back[1][lp+1];
			st_back[2][lp]=st_back[2][lp+1];
			st_back[3][lp]=st_back[3][lp+1];
			st_back[4][lp]=st_back[4][lp+1];
			st_back[5][lp]=st_back[5][lp+1];
			st_back[6][lp]=st_back[6][lp+1];
		}
		st_back_p=49;
	}

		st_back[0][st_back_p]=_WK_REEL[0][5];	//	第１回胴番号
		st_back[1][st_back_p]=_WK_REEL[1][5];	//	第２回胴番号
		st_back[2][st_back_p]=_WK_REEL[2][5];	//	第３回胴番号
		st_back[3][st_back_p]=_FL_PUL_PIC1;	//	成立フラグ１
		st_back[4][st_back_p]=_FL_PUL_PIC2;	//	成立フラグ２
		st_back[5][st_back_p]=play_mode;	//	モードフラグ
		st_back[6][st_back_p]=_NB_PLAY_MEDAL;	//	モードフラグ
		st_back_p+=1;

}



int max_end_check(void)
{
/*	プレイ数			play_num	１万プレイ	STR_MAXMES_0
	メダル投入枚数		use_coin	１０万枚	STR_MAXMES_1
	メダル払出し枚数	out_coin	１０万枚	STR_MAXMES_2 */
	int mes_no=0;

	if(mode_game!=0) return(0);

	if(play_num>(10000-1))	mes_no=51;
	if(use_coin>(100000-1))	mes_no=52;
	if(out_coin>(100000-1))	mes_no=53;

	if(mes_no){	/* ゲーム終了 */

		vol_okaeri();
		while(quitflag!=TRUE){
			auto_on=0;
			auto_on_s=0;
			call_mes_panel((0-(320/2))+8,(-16),mes_no);
			while(mesp_p->f_step!=3) wait(1);
			mes_deteimasuka=1;
			pad_shibirenai();
			while(1){
				if(pad_cnt&PAD_ALL){
					break;
				}
				wait(1);
			}
			del_mes_panel();
			mes_deteimasuka=0;
			while(mesp_sts>-1) wait(1);
			submenu_sts=10;
			while(submenu_sts){
				submenu_drv();
				card_seq_check(0);
				wait(1);
			}
		}
		return(1);
	}
	return(0);
}


char mac_n;
char play_n;

void bak_kawa(void)
{
	mac_n=MACHINE_NO;		// 機械番号	0:かっぱ
	play_n=PLAY_MODE;		/* パチスロのゲームモード*/

}
void ret_kawa(void)
{
	MACHINE_NO=mac_n;		// 機械番号	0:かっぱ
	PLAY_MODE=play_n;		/* パチスロのゲームモード*/
}



