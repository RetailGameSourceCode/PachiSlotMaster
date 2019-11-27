#include "common.h"
#include "work.h"
#include "tmd1.h"
#include "kap_d.hd"
#include "kap_a.hd"
#include "bin_d.hd"
#include "bin_a.hd"

char slot_narabi[2][3][21]={
{
{
	DK_SEVEN,
	DK_TSUKI,
	DK_KYUURI,
	DK_KAPPA,
	DK_SAKE,
	DK_KYUURI,
	DK_SAKE,
	DK_KYUURI,
	DK_TSUKI,
	DK_OYAKO,
	DK_HYOUTAN,
	DK_SAKE,
	DK_SEVEN,
	DK_TSUKI,
	DK_KYUURI,
	DK_SAKE,
	DK_KYUURI,
	DK_TSUKI,
	DK_OYAKO,
	DK_SAKE,
	DK_HYOUTAN,
},
{
	DK_SEVEN,
	DK_HYOUTAN,
	DK_TSUKI,
	DK_KAPPA,
	DK_KYUURI,
	DK_HYOUTAN,
	DK_TSUKI,
	DK_SAKE,
	DK_OYAKO,
	DK_KYUURI,
	DK_HYOUTAN,
	DK_TSUKI,
	DK_SAKE,
	DK_HYOUTAN,
	DK_KYUURI,
	DK_TSUKI,
	DK_HYOUTAN,
	DK_KAPPA,
	DK_HYOUTAN,
	DK_KYUURI,
	DK_TSUKI,
},
{
	DK_SEVEN,
	DK_TSUKI,
	DK_KAPPA,
	DK_KYUURI,
	DK_SAKE,
	DK_TSUKI,
	DK_KYUURI,
	DK_HYOUTAN,
	DK_OYAKO,
	DK_SAKE,
	DK_TSUKI,
	DK_KYUURI,
	DK_HYOUTAN,
	DK_KAPPA,
	DK_HYOUTAN,
	DK_TSUKI,
	DK_KYUURI,
	DK_HYOUTAN,
	DK_TSUKI,
	DK_SAKE,
	DK_KYUURI,
},
},
{
{
	DB_SEVEN,
	DB_CHERRY,
	DB_BINBOU,
	DB_SUZU,
	DB_KOZUCHI,
	DB_BINBOU,
	DB_CHERRY,
	DB_SEVEN,
	DB_YAMA,
	DB_SUZU,
	DB_KOZUCHI,
	DB_KAMI,
	DB_YAMA,
	DB_YAMA,
	DB_SUZU,
	DB_KOZUCHI,
	DB_YAMA,
	DB_YAMA,
	DB_KAMI,
	DB_SUZU,
	DB_KOZUCHI,
},
{	
	DB_SEVEN,
	DB_KOZUCHI,
	DB_SUZU,
	DB_CHERRY,
	DB_CHERRY,
	DB_YAMA,
	DB_KOZUCHI,
	DB_SUZU,
	DB_CHERRY,
	DB_KOZUCHI,
	DB_CHERRY,
	DB_KOZUCHI,
	DB_SUZU,
	DB_KAMI,
	DB_KOZUCHI,
	DB_SUZU,
	DB_BINBOU,
	DB_CHERRY,
	DB_CHERRY,
	DB_KOZUCHI,
	DB_SUZU,
},
{	
	DB_SEVEN,
	DB_SUZU,
	DB_KOZUCHI,
	DB_BINBOU,
	DB_SUZU,
	DB_CHERRY,
	DB_CHERRY,
	DB_KOZUCHI,
	DB_YAMA,
	DB_SUZU,
	DB_KOZUCHI,
	DB_YAMA,
	DB_SUZU,
	DB_KAMI,
	DB_KAMI,
	DB_KOZUCHI,
	DB_CHERRY,
	DB_SUZU,
	DB_KOZUCHI,
	DB_BINBOU,
	DB_KOZUCHI,
},
},
};

char dig_r[4];



short drum_tex_data[3][6]={
	{0,500,676,0,54,28},
	{0,500,676,0,54,28},
//	{0,500,640,0,70,36},
	{0,500,640,0,70,36},
};

//VERTS *ve[3][21];

void slot_tex_set(int mode)
{
	int lp,lp2;
	VERTEXS *vex;
	VERTEXS *vex2;
	VERTS *ve;

	for(lp2=0;lp2<3;lp2++){
		for(lp=0;lp<21;lp++){
			ve=(VERTS*)&A_TMD[lp2][17+(lp*9)];
			vex=(VERTEXS*)&A_TMD[lp2][647+(lp*2)];
			vex2=(VERTEXS*)&A_TMD[lp2][647+42+(lp*2)];

			vex->vx=(0x0177)+96;
			vex2->vx=(0xfe89)-96;

			//	クラットＹ座標 
			ve->cba=(D_DEF_CLUT_Y<<6);
			//	テクスチャページ 
			ve->tsb=(ve->tsb&0xFFE0)+((D_DEF_TIM_X/64)+((D_DEF_TIM_Y/256)*16));
			//	右上テクスチャ座標 
			ve->u0=(((D_DEF_TIM_X%64)*2)+D_DEF_TIM_W)-4;
			ve->v0=(D_DEF_TIM_Y%256)+(D_DEF_TIM_H*slot_narabi[MACINE][lp2][lp])+2;
			//	右下 
			ve->u1=(((D_DEF_TIM_X%64)*2)+D_DEF_TIM_W)-4;
			ve->v1=(D_DEF_TIM_Y%256)+(D_DEF_TIM_H*(slot_narabi[MACINE][lp2][lp]+1))-3;
			//	左上 
			ve->u2=((D_DEF_TIM_X%64)*2)+4;
			ve->v2=(D_DEF_TIM_Y%256)+(D_DEF_TIM_H*slot_narabi[MACINE][lp2][lp])+2;
			//	左下 
			ve->u3=((D_DEF_TIM_X%64)*2)+4;
			ve->v3=(D_DEF_TIM_Y%256)+(D_DEF_TIM_H*(slot_narabi[MACINE][lp2][lp]+1))-3;
		}
		if(mode){
			GsMapModelingData((u_long *)(&A_TMD[lp2][1]));/* モデリングデータを実アドレスにマッピング */
			drum_set(lp2,0,(u_long)(&A_TMD[lp2][3]));	//	+12はヘッダー部分を飛ばしている
		}
	}
}

extern signed char	submenu_sts;		// サブメニューステップ 
char toggle_start_ok;
//	ゲームに必要なデータの読み込み等
void slot_data_read(void)
{
	int lp,lp2;
	void *lda;

	u_short mfile[2]={KAP_A_TIC_N,BIN_A_TIC_N};

	draw_rq=1;

	kyoutai_set(2);		//	引数２は初回のみ

	if(slf){	//	ロードされてきた時だけ設定
		drum_point_set(0,_WK_REEL[0][5],0);
		drum_point_set(1,_WK_REEL[1][5],0);
		drum_point_set(2,_WK_REEL[2][5],0);
	}else{
		if(mode_game==0){
			if(!koyakucnt_reset){ // ランダム 
				drum_point_set(0,rnd(20),0);
				drum_point_set(1,rnd(20),0);
				drum_point_set(2,rnd(20),0);
				_CT_IN_OUT[0]=rnd(0xFF);
				_CT_IN_OUT[1]=rnd(0xFF);

			}else{	//	リセット 
				if(!MACINE){
					drum_point_set(0,2,0);
					drum_point_set(1,12,0);
					drum_point_set(2,12,0);
				}else{
					drum_point_set(0,15,0);
					drum_point_set(1,4,0);
					drum_point_set(2,1,0);
				}
			}
			remember_lot_set();
		}else{
				if(!MACINE){
					drum_point_set(0,2,0);
					drum_point_set(1,12,0);
					drum_point_set(2,12,0);
				}else{
					drum_point_set(0,15,0);
					drum_point_set(1,4,0);
					drum_point_set(2,1,0);
				}
		}
	}

//	音楽SE
	game_vab_set(1);

	lda = datafile_read(mfile[MACINE],NULL);
	if(!slf){	//	ロードされてきてない時だけ設定
		for(lp=0;lp<4;lp++)	dig_r[lp]=1;		//	違う値を無理矢理入れてやる 
	}
	digital_set();	//	その後、０で初期化 

	tim_load((void *)lda,0);
	VSync(0);
	memfree((void**)&lda);

//	リプレイはずしのフラグをクリアしとく 
	rep_step[0]=0;
	rep_step[1]=0;
	rep_step[2]=0;
	rep_step[3]=0;
	rep_step[4]=0;
	rep_no=0;
	ran_f=0;
	pan_f=0;
	bb_kitakana=0;
	no_start=0;
	muriyari_ateru=0;
	cckk=0;
	if(mode_game==7){	//	ウィンドウ出しておいてあげる 
		submenu_sts=10;
		cckk=1;
	}
}

