#include "common.h"
#include "work.h"


/******************************************************************************
*** void circle_move(short c, short s, short *x, short *y)					***
*** 	指定した角度への移動量を求める										***
***			引数　：short c		角度（上を０とした右回りの値：単位 °）		***
***					short sdx	Ｘ軸移動量（代入した数が最高値）の１０倍値	***
***					short sdy	Ｙ軸移動量（代入した数が最高値）の１０倍値	***
***					short *x	Ｘ座標の移動量								***
***					short *y	Ｙ座標の移動量								***
**
*			戻り値：なし													***
*******************************************************************************/
void circle_move(short c, short sdx, short sdy, short *x, short *y)
{
	long	a;
	long	tx, ty;

	c%=361;

	a = ((long)(((c + 360) % 360)+360) * (long)4096) / (long)360;

	if((sdx != 0) || (csin(a) != 0))
		tx = (long)sdx / (long)10 * csin(a) / (long)4096;
	else tx = 0;
	if((sdy != 0) || (ccos(a) != 0))
		ty = (long)sdy / (long)10 * ccos(a) / (long)4096;
	else ty = 0;

	*x = (short)tx;
	*y = (short)ty;
}

/*=============================================================
 *
 *	0~max-1	の乱数を返します(max < 32767)
 *
 *=============================================================*/
long rnd(long max)
{
	long r;
	if(!max)	max=1;
	r = rand()%max;
	return(r);
}



//	画面切り替え集
//	void	btl_rect_ef0(int writex,int writey,int mastx,int masty)
//	動作	左下と右上から斜めに転送
//	writex	書き込むフレームバッファの座標
//	writey	
//	mastx	転送元のフレームバッファの座標
//	masty	
//	
void rect_ef0(int writex,int writey,int mastx,int masty)
{
	int	loop1,loop2;
	int	mx0,my0;
	int	mx1,my1;
	int	wx0,wy0;
	int	wx1,wy1;
	int	x0,y0;
	int	x1,y1;
	int	x2,y2;
	int	x3,y3;

	RECT	efct1={0,0,1,1};
	RECT	efct2={0,0,1,1};

	mx0=mastx+0;
	my0=masty+239;

	mx1=mastx+319;
	my1=masty+1;

	wx0=0;
	wy0=writey+239;

	wx1=319;
	wy1=writey+1;

	while(mx0<mastx+320){
		efct1.x=mx0;
		efct1.y=my0;
		efct2.x=mx1;
		efct2.y=my1;
		for(x0=wx0,y0=wy0,x1=wx1,y1=wy1;x0<writex+320 && y0<writey+240;x0++,y0++,x1--,y1--){
			MoveImage(&efct1,x0,y0);
//			while(DrawSync(1)!=0);	/**/
			MoveImage(&efct2,x1,y1);
//			while(DrawSync(1)!=0);	/**/
			efct1.x +=1;
			efct1.y +=1;
			efct2.x -=1;
			efct2.y -=1;
		}
		if(my0==masty+1){
			mx0 +=2;
			wx0 +=2;
			mx1 -=2;
			wx1 -=2;
		}
		else{
			my0-=2;
			wy0-=2;
			my1+=2;
			wy1+=2;
		}
	}

}


//	動作	左下から斜めに２回に分けて転送
void	rect_ef1(int writex,int writey,int mastx,int masty)
{

	int	loop1,loop2;
	int	mx,my;
	int	wx,wy;
	int	x0,y0;
	int	x1,y1;
	int	x2,y2;
	int	x3,y3;

	RECT	efct={0,0,1,1};


	mx=0;
	my=masty+239;
	wx=0;
	wy=writey+239;

	while(mx<320){
		efct.x=mx;
		efct.y=my;
		for(x0=wx,y0=wy;x0<320 && y0<writey+240;x0++,y0++){
			MoveImage(&efct,x0,y0);
//			while(DrawSync(1)!=0);	/**/
			efct.x +=1;
			efct.y +=1;
		}
		if(my==masty+1){
			mx +=2;
			wx +=2;
		}
		else{
			my-=2;
			wy-=2;
		}
	}

	mx=0;
	my=masty+238;
	wx=0;
	wy=writey+238;
	while(mx<320){
		efct.x=mx;
		efct.y=my;
		for(x0=wx,y0=wy;x0<320 && y0<writey+240;x0++,y0++){
			MoveImage(&efct,x0,y0);
//			while(DrawSync(1)!=0);	/**/
			efct.x +=1;
			efct.y +=1;
		}
		if(my==masty){
			mx +=2;
			wx +=2;
		}
		else{
			my-=2;
			wy-=2;
		}
	}

}


//	void	btl_rect_ef2(int writex,int writey,int mastx,int masty)
//	動作	上下から同時に転送
void	rect_ef2(int writex,int writey,int mastx,int masty)
{
	int	loop1,loop2;
	int	x,y;
	int	xr,yr;
	int	xl,yl;

	RECT	efct1={0,0,320,1};
	RECT	efct2={0,0,320,1};


	efct1.y=masty;
	efct2.y=masty+239;

	yr=writey;
	yl=writey+239;
	for(loop1=0;loop1<120;loop1++,yr+=2,yl-=2,efct2.y-=2,efct1.y+=2){
		MoveImage(&efct2,0,yl);
		while(DrawSync(1)!=0);
		MoveImage(&efct1,0,yr);
		while(DrawSync(1)!=0);
		wait_nw(1);
//		wait(1);
	}

}

//	void	btl_rect_ef3(int writex,int writey,int mastx,int masty)
//	動作	左右に１ラインずつ別れる転送
void	rect_ef3(int writex,int writey,int mastx,int masty)
{
	int	loop1,loop2;
	int	x,y;
	int	xr,yr;
	int	xl,yl;

	RECT	efct={0,0,2,1};
	RECT	rectLR[240];


//	efct.x	= 320;
//	efct.y	= 256;
//	efct.w	= 2;
//	efct.h	= 1;

	for(loop1=0,y=0;loop1<240;loop1+=1,y+=1){
		rectLR[loop1].x=0;
		rectLR[loop1].y=writey+y;
		rectLR[loop1].w=320;
		rectLR[loop1].h=1;
	}

	/* 偶数は左へ */
	for(loop1=0;loop1<40;loop1++){
		wait_nw(2);
//		wait_nw(3);
		for(x=0;x<240;x+=2){
			rectLR[x].x +=2;
			rectLR[x].w -=2;
			MoveImage(&rectLR[x],0,rectLR[x].y);
//			while(DrawSync(1)!=0);
			MoveImage(&efct,rectLR[x].w,rectLR[x].y);
//			while(DrawSync(1)!=0);
		}
		for(x=1,xr=0;x<239;x+=2){
			rectLR[x].w -=2;
			MoveImage(&rectLR[x],320-rectLR[x].w,rectLR[x].y);
//			while(DrawSync(1)!=0);
			MoveImage(&efct,320-(rectLR[x].w+2),rectLR[x].y);
//			while(DrawSync(1)!=0);
		}
	}

	for(loop1=0,y=0;loop1<240;loop1+=1,y+=1){
		if((y%2)==0)	rectLR[loop1].x=0;
		else			rectLR[loop1].x=320-2;
		rectLR[loop1].y=masty+y;
		rectLR[loop1].w=2;
		rectLR[loop1].h=1;
	}

	/* 偶数は右へ */
	for(loop1=0;loop1<79;loop1++){
//		wait_nw(2);
		for(y=0;y<240;y+=1){
			if((y%2)==1)	rectLR[y].x -=4;
			rectLR[y].w +=4;
			MoveImage(&rectLR[y],rectLR[y].x,writey+y);
//			while(DrawSync(1)!=0);
		}
	}

}

//	void	btl_rect_ef4(int writex,int writey,int mastx,int masty)
//	動作	ぐるぐる回りながら転送
void	rect_ef4(int writex,int writey,int mastx,int masty)
{
#if 0
	int	x;
	int	y;
	int	xx;
	int	yy;
	int	x_end;
	int	y_end;

	RECT	efct={304,496,16,16};

	x=-16;
//	x=0;
	y=writey;


	for(x_end=20,y_end=14;x_end>0;x_end-=1,y_end-=1){
		for(xx=0;xx<x_end;xx++){
			if(0<=x)	MoveImage(&efct,x,y);
//			while(DrawSync(1)!=0);
			x+=16;
			if(xx%2)	wait_nw(1);
		}
		for(yy=0;yy<y_end;yy++){
			MoveImage(&efct,x,y);
//			while(DrawSync(1)!=0);
			y+=16;
			if(xx%2)	wait_nw(1);
		}
		x_end-=1;
		for(xx=0;xx<x_end;xx++){
			MoveImage(&efct,x,y);
//			while(DrawSync(1)!=0);
			x-=16;
			if(xx%2)	wait_nw(1);
		}
		y_end-=1;
		for(yy=0;yy<y_end;yy++){
			MoveImage(&efct,x,y);
//			while(DrawSync(1)!=0);
			y-=16;
			if(xx%2)	wait_nw(1);
		}
	}

#endif
}


//	void	btl_rect_ef5(int writex,int writey,int mastx,int masty)
//	動作	上下から同時に転送
void	rect_ef5(int writex,int writey,int mastx,int masty)
{
#if 0
	int	loop1,loop2;
	int	x,y;
	int	xr,yr;
	int	xl,yl;

	RECT	efct={288,496,32,1};


	efct.h	= 1;

	yr=writey;
	yl=writey+239;
	for(loop1=0;loop1<120;loop1++,yr+=2,yl-=2){
		for(loop2=0,xr=0;loop2<10;loop2++,xr+=32){
			MoveImage(&efct,xr,yr);
			while(DrawSync(1)!=0);
			MoveImage(&efct,xr,yl);
			while(DrawSync(1)!=0);
		}
		wait_nw(1);
	}

#endif
}


void fream_harf(short x,short y,short w,short h,short mx,short my)
{
#if 0
	RECT	moto;
	RECT	saki;

	int lp1,lp2;


	moto.x=x;
	moto.y=y;
	moto.w=1;
	moto.h=h;

	saki.x=x;
	saki.y=y;
	saki.w=1;
	saki.h=h;

	for(moto.x=x+1 ,saki.x=x ,lp1=0;lp1<w/4;moto.x+=2 ,saki.x+=1 ,lp1+=1){
		MoveImage(&moto,saki.x,saki.y);
		while(DrawSync(1)!=0);
	}

	moto.x=x;
	moto.y=y;
	moto.w=w/4;
	moto.h=1;

	saki.x=mx;
	saki.y=my;
	for(moto.y=y+1 ,saki.y=my ,lp1=0;lp1<h/2;moto.y+=2 ,saki.y+=1 ,lp1+=1){
		MoveImage(&moto,saki.x,saki.y);
		while(DrawSync(1)!=0);
	}

#endif
}



//	引数は総て偶数で 
//	動作	ランダムで範囲内を消去
void rect_ef00(int mastx,int masty,int wide,int high)
{
#if 0
	int	loop1,loop2;
	int	writex,writey;
	int	mx0,my0;
	int	mx1,my1;
	int	mx2,my2;
	int	wx0,wy0;
	int	wx1,wy1;
	int	wx2,wy2;
	int	x0,y0;
	int	x1,y1;
	int	x2,y2;
	int lr;
	int cnt,count;

	RECT	efct1={0,0,1,1};
	RECT	efct2={0,0,1,1};
	RECT	efct3={0,0,1,1};


	lr=0;

	writex=mastx;
	writey=(actframe*240)+masty;

	mx0=mastx+320;
	my0=masty;
	wx0=writex;
	wy0=writey;

	cnt=0;

	while(cnt<5){
		for(y0=wy0,efct1.y=my0;y0<writey+high;y0+=1,efct1.y+=1){
			for(x0=wx0,efct1.x=mx0;x0<writex+wide;x0+=1,efct1.x+=1){
				if((rand()%4)==0){
					MoveImage(&efct1,x0,y0);
//					while(DrawSync(1)!=0);	/**/
				}
			}
		}
//		wait_nw(1);
		cnt++;
	}

	efct1.x=mx0;
	efct1.y=my0;
	efct1.w=wide;
	efct1.h=high;
	MoveImage(&efct1,wx0,wy0);
//	while(DrawSync(1)!=0);	/**/

#endif
}

