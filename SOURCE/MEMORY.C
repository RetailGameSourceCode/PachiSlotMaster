#include "common.h"
#include "work.h"

/*=============================================================
 *
 *	ƒƒ‚ƒŠ‚ğŠm•Û‚µ‚Ü‚·
 *
 *=============================================================*/
long mal_size;
long mal_msize;

#ifdef DEBUG_FONT
long mal_s;
void *mal_a;
void *mal_l;

int mal_c=0;
void *mall[100];
#endif

void *memalloc(size_t s, void** adr)
{
	if(*adr == NULL){
		*adr = (void *)malloc2(s+8);
		mem_cnt+=1;
	}

#ifdef	DEBUG_FONT
	else{
		while(1){
			FntPrint(dbg_flg.fnt[0],"malloc err!!\n");
			FntPrint(dbg_flg.fnt[0],"malloc err!!\n");
			FntPrint(dbg_flg.fnt[0],"malloc err!!\n");
			draw_rq=0;
			wait(1);
		}
	}
#endif
//	if(mal_chk){
//		mal_cnt++;
//	}

#ifdef	DEBUG_FONT
		mal_a=*adr;
		mal_s=s+8;
		if((mal_a+s+8)>mal_l)	mal_l=mal_a+s+8;
		mall[mal_c]=*adr;
		mal_c=(mal_c+1)%20;
#endif

	if(*adr == NULL){
		while(1){
#ifdef	DEBUG_FONT
			FntPrint(dbg_flg.fnt[0],"malloc err!!\n");
			FntPrint(dbg_flg.fnt[0],"malloc err!!\n");
			FntPrint(dbg_flg.fnt[0],"malloc err!!\n");
#endif
			draw_rq=0;
			wait(1);
		}
	}
	memset(*adr,0,s+8);	//	ƒƒ‚ƒŠ“à‚ğƒNƒŠƒA‚·‚é

#if	DEBUG_MODE==1
	mal_size+=s;
	if(mal_size>mal_msize)	mal_msize=mal_size;

#endif
	return *adr;
}


/*=============================================================
 *
 *	ƒƒ‚ƒŠ‚ğ‰ğ•ú‚µ‚Ü‚·
 *
 *=============================================================*/
void memfree(void **adr)
{
#ifdef	DEBUG_FONT
	if(!mem_cnt){
		while(1){
			FntPrint(dbg_flg.fnt[0],"free err!!\n");
			FntPrint(dbg_flg.fnt[0],"free err!!\n");
			FntPrint(dbg_flg.fnt[0],"free err!!\n");
			wait(1);
		}
	}
#endif
	if(*adr!=NULL){
		free2(*adr);
		mem_cnt-=1;
//		if(mal_chk){
//			mal_cnt--;
//		}
		*adr=NULL;
	}

#ifdef	DEBUG_FONT
	else{
		while(1){
			FntPrint(dbg_flg.fnt[0],"NULL free err!!\n");
			FntPrint(dbg_flg.fnt[0],"NULL free err!!\n");
			FntPrint(dbg_flg.fnt[0],"NULL free err!!\n");
			FntPrint(dbg_flg.fnt[0],"%x\n",adr);
			if(pad_cnt&PAD_START)	break;
			draw_rq=0;
			wait(1);
		}
	}
#endif
}


