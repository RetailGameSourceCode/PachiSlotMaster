
char MS_SPPOINT_SET(void)
{
	int lp,lp2,lp_b,lp2_b;
	int bk;

	if(_BF_STOP_CTL)
		goto MS_SPPOINT_SET6; /* 停止位置決定用テーブル使用？ */

	if((_FL_STOP_LP&0xE0)!=0xC0)
		goto MS_SPPOINT_SET14;	/* 左回胴が第１停止？ */

/* 左回胴から止まったときの処理 */
/*［停止位置決定用テーブル選択］*/
lp=0;
MS_SPPOINT_SET1:
	z_b=TBL_STOP_SELECT[MACINE][lp][0];
	z_c=TBL_STOP_SELECT[MACINE][lp][1];
	lot_set(TBL_STOP_SELECT[MACINE][lp][2]);
lp+=1;
	z_a=_FL_PUL_PIC1;
	if(z_a!=z_b) goto MS_SPPOINT_SET1;
	z_a=_FL_PUL_PIC2;
	if(z_a!=z_c) goto MS_SPPOINT_SET1;

/* 停止位置決定用テーブル選択抽選用確率テーブル 決定 */
/* ［左回胴時の制御] */
	lp_b=lp-1;
	tbl_stop_ctlx(TBL_STOP_LOT[0],0);

	z_b=0;
	srand(VSync(-1));
	bk=rnd(0xFF);
	bk=(bk|0x80);	//＜１２８をたしとく 
MS_SPPOINT_SET2:
	z_b+=1;
	bk+=TBL_STOP_LOT[z_b];
	if(bk<0x100) goto MS_SPPOINT_SET2;
MS_SPPOINT_SET3:
	lp=lp_b;
MS_SPPOINT_SET4:
	tbl_stop_ctlx(TBL_STOP_LOT[0],z_b-1);
	z_b=TBL_STOP_CTLX[0];


MS_SPPOINT_SET5:
MS_SPPOINT_SET6:
MS_SPPOINT_SET7:
MS_SPPOINT_SET8:
MS_SPPOINT_SET9:
MS_SPPOINT_SET10:
MS_SPPOINT_SET11:
MS_SPPOINT_SET12:
MS_SPPOINT_SET13:
MS_SPPOINT_SET14:
MS_SPPOINT_SET15:
MS_SPPOINT_SET16:
MS_SPPOINT_SET17:


}

