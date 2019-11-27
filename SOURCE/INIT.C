
#include "common.h"
#include "work.h"

//	void *anm_adr,*atime_adr;

#include "libmcrd.h"

void initSystem(void)
{
	int i;
	void *lda;

	ResetCallback();

	InitHeap2((u_long*)HEAP_TOP,HEAP_SIZE);	//	ヒープ領域の設定

	CdInit();		/* CD-ROMｻﾌﾞｼｽﾃﾑの初期化 */
	cdread_init();	/*すべてのＣＤリード前に呼ぶ*/

	sound_init();	/* サウンドシステムの初期化と開始 */

	MemCardInit(0);	/* mcrd使用開始*/
	pad_init();		/* パッドの初期化 */

	ChangeClearPAD(0);	/*cmanにない コントローラドライバの設定 */
						/* 0:垂直帰線割り込みクリアフラグ */

//	MemCardInit(0);	/* mcrd使用開始*/
	ResetGraph(0);		// 描画エンジンの初期化
	GsInitGraph(DSPW,DSPH,DSPM,DSPD,DSPV);	//	グラフィックスシステムの初期化
	vramclear(0,0,0);
	draw_flag = 0;
	for(i = 0; i < 2; i++){	/* OTの初期化 */
		ot[i].length = OT_LENGTH;
		ot[i].point  = 0;
		ot[i].offset = 0;
		ot[i].org    = ottag[i];
		ot[i].tag    = ottag[i] + OT_SIZE - 1;
	}
	GsDefDispBuff(DSPX0,DSPY0,DSPX1,DSPY1);
	draw_rq = 0;

//	初期化するものを入れる 開始
	func_mode=MODE_NOP;
	disp_mode=0;

	sprobj_init();	//	スプライト
	dobj_init();
	poly_init();
	ffnt_init(1024-64,0,256,480);		/* ＦＦＮＴ初期化 */

	dispxy_set(0-(DSPW/2),(DSPW/2),0-(DSPH/2),(DSPH/2));	//	画面端座標セット
//	mal_size=0;		//	mallocで確保してるメモリのサイズ
//	mal_msize=0;	//	mallocで確保した最大瞬間値

	game_init();	//	ゲームに使うパラメータ初期化


//	初期化するものを入れる 終了

	/* V-sync時のコールバック関数の設定 */
	vcount=0;		//	ＶＳＹＮＣカウント
	movie_on=0;

	VSyncCallback(cbvsync);	

	draw_init();	//	描画モードの初期化

	GsInit3D();		// Init 3D system /* ３Dシステム初期化 */

#if	DEBUG_MODE==1
	dbgflg_clr();	//	デバッグ用フラグのクリア
#endif

#ifdef DOS_READ
	PCinit();		//	PCファイルシステムを初期化する*/
#endif
	mem_cnt=0;

//	フォント用文字データ
//	変化しないのであれば、ずっと持っておく
	lda = datafile_read(FONT_TIM_N,NULL);
	tim_load((void *)(lda+TIM_TEXT),0);
	DrawSync(0);
	memcpy(&fnt_data[0],lda,BIN_TEXT_SIZE);
	VSync(1);
//	ＳＥのセット
	se_vab_set(lda+VH_SE,lda+VB_SE,2);	//	共通のＳＥ
	VSync(1);
	memfree((void**)&lda);
	mem_cnt=0;

	load_tims();

}


int wawa=0;
void cbvsync(void)		//	Ｖ－ＳＹＮＣコールバック関数
{
#ifdef DEBUG_POLL
		pollhost();	/*ＣＤ焼く時は必ず外して！*/
#endif

	if(draw_flag){
		//	描画許可の時に描画
		GsSwapDispBuff();

		GsSortClear(BG_R,BG_G,BG_B, &ot[actframe]);

		DrawOTag((u_long *)(ot[actframe].org+OT_SIZE-1));
		draw_flag = 0;

#if	DEBUG_MODE==1
	debug_vsync();
#endif
		draw_init();	//アクティブバッファＩＤの切り替えとＯＴクリア
	}
//	time_check();	//	時間を計る

	pad_read();
	pad_callback();

//	if(wind_w==0){
	if(auto_on_s==1){
		ffnt_drv();		/* ＦＦＮＴ表示更新ドライバ */
		window_drv();
		toggles_drv();
		ffnt_drv();		/* ＦＦＮＴ表示更新ドライバ */
	}
//		draw();
//	}
	hardware_inter();	//	ゲーム中のハードウェア制御（スロット等）

	cd_read_fast();	/*ＣＤリード*/
//	sound_driver();	/*サウンド 中身なし・・・ＸＡ使わないからね*/
	sound_vsync();
	vcount++;
}

char wind_w;
void game_init(void)	//	ゲームに使うパラメータ初期化
{
	memset(&tot, 0,sizeof(SAVE1));	//	トータルデータのクリア
	memset(&kbr, 0,sizeof(SAVE2));	//	ゲームデータのクリア
	memset(&gwk, 0,sizeof(GAME_WK));	//	ゲームデータのクリア
	wind_w=0;
	mal_chk=0;
	mal_cnt=0;
	hardware_init();
	init_kawas(0);
	volume=0x7f;
	vol_set_five();
}


void draw_init(void)	//	ＤＲＡＷ初期化
{
	if(!draw_rq){
		//ダブルバッファのうちどちらがアクティブか？
		actframe = GsGetActiveBuff();
		//GPUパケット生成アドレスをエリアの先頭に設定
		GsSetWorkBase((PACKET *)gpu_packet[actframe]);
		//OTの内容をクリア
		ClearOTagR((u_long *)ot[actframe].org, OT_SIZE);
	}
}

//	ＶＲＡＭ ＡＬＬクリアー
void vramclear(int r,int g,int b)
{
	RECT rct;

	setRECT(&rct,0,0,1024,512);
	ClearImage(&rct,r,g,b);
	while(DrawSync(1));
}


void video320(void)
{
	RECT rct;

	if(disp_mode!=320){
		setRECT(&rct,0,8,320,240-16);
		ClearImage(&rct,0,0,0);
		while(DrawSync(1));
		GsInitGraph2(DSPW,DSPH,DSPM,DSPD,DSPV);	//	グラフィックスシステムの初期化
		GsInit3D();/* 画面座標系を3Dと同じにする */
		GsDefDispBuff2(DSPX0,DSPY0,DSPX1,DSPY1);
		GsSetClip2D(&rct);
		dispxy_set( -160,160,-120,120 );	/*画面端座標セット*/
#ifdef	DEBUG_FONT
		dbg_fntset();
#endif
		wait(1);
		disp_mode=320;
	}
}

void video512(void)
{
	RECT rct;

	if(disp_mode!=512){
		setRECT(&rct,0,8,512,480-8);
		ClearImage(&rct,0,0,0);
		while(DrawSync(1));
		GsInitGraph2(512,480,DSPM_INTER,DSPD,DSPV);/**/
		GsInit3D();/* 画面座標系を3Dと同じにする */
		GsDefDispBuff2(0,0,0,0);	//ダブルバッファの定義
		dispxy_set( -256,256,-240,240 );	/*画面端座標セット*/
		GsSetClip2D(&rct);
#ifdef	DEBUG_FONT
		dbg_fntset();
#endif
		wait(1);
		disp_mode=512;
	}
}

void video640(void)
{
	RECT rct;
	if(disp_mode!=640){
		setRECT(&rct,0,8,640,480-8);
		ClearImage(&rct,0,0,0);
		while(DrawSync(1));
		GsInitGraph2(640,480,DSPM_INTER,DSPD,DSPV);/**/
		GsInit3D();/* 画面座標系を3Dと同じにする */
		GsDefDispBuff2(0,0,0,0);	//ダブルバッファの定義
		dispxy_set( -320,320,-240,240 );	/*画面端座標セット*/
		GsSetClip2D(&rct);
#ifdef	DEBUG_FONT
		dbg_fntset();
#endif
		wait(1);
		disp_mode=640;
	}
}

void video640_2(void)
{
	RECT rct;
	if(disp_mode!=640){
		setRECT(&rct,0,8,640,480-8);
		ClearImage(&rct,0xff,0xff,0xff);
		while(DrawSync(1));
		GsInitGraph2(640,480,DSPM_INTER,DSPD,DSPV);/**/
		GsInit3D();/* 画面座標系を3Dと同じにする */
		GsDefDispBuff2(0,0,0,0);	//ダブルバッファの定義
		dispxy_set( -320,320,-240,240 );	/*画面端座標セット*/
		GsSetClip2D(&rct);
#ifdef	DEBUG_FONT
		dbg_fntset();
#endif
		wait(1);
		disp_mode=640;
	}
}

void video480(void)
{
	RECT rct;
	if(disp_mode!=480){
		setRECT(&rct,0,8,480,240-8);
		ClearImage(&rct,0,0,0);
		while(DrawSync(1));
		GsInitGraph2(480,240,DSPM_INTER,DSPD,DSPV);/**/
		GsInit3D();/* 画面座標系を3Dと同じにする */
		GsDefDispBuff2(0,0,0,0);	//ダブルバッファの定義
		dispxy_set( -240,240,-160,160 );	/*画面端座標セット*/
		GsSetClip2D(&rct);
#ifdef	DEBUG_FONT
		dbg_fntset();
#endif
		wait(1);
		disp_mode=480;
	}
}

void mode_init(void)
{
	switch(func_mode){
		case	MODE_NOP:
		break;
		case	MODE_MOVIE:
		case	MODE_TITLE:
		case	MODE_GAME:
			video320();
		break;
		default:
#ifdef	DEBUG_FONT
	FntPrint(dbg_flg.fnt[0],"FUNC MODE ERROR  %d",func_mode);
	FntPrint(dbg_flg.fnt[0],"FUNC MODE ERROR  %d",func_mode);
	FntPrint(dbg_flg.fnt[0],"FUNC MODE ERROR  %d",func_mode);
#endif
		break;
	}
}

