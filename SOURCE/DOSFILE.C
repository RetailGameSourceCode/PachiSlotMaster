#include "common.h"
#include "work.h"

#ifdef DOS_READ

//=============================================================
//	ＤＯＳファイルから読みこみます
//
//in:
//		char *name	読み込むファイル名
//		void *buff	読み込みメインメモリアドレス
//					ＣＤから読む場合と同じようにするためセクタの倍数分
//					(2048byte(0x800)の倍数)確保しておいてください
//					NULLなら内部でmallocして、メモリを割り当てます
//out:
//		void *		読み込んだメモリのトップアドレス
//
//=============================================================
void *PCfileread(char *name,void *buff)
{
 int	ret,fd,len,rbyte;

	fd = PCopen(name,0,0);
	if(fd == -1){
		return NULL;	//error
	}
	len = PClseek(fd,0L,2);	//get file length
	if(buff == NULL){
		//バッファの割り当て
		buff = memalloc((len+2047)&0xfffff800, (void**)&buff);//ＣＤの場合と整合を取るため2048byteの倍数へ
	}
	PClseek(fd,0L,0);	//file top set
	if((rbyte = PCread(fd,buff,len))!=len){
		return NULL;	//error
	}
	ret = PCclose(fd);
	return buff;
}

#endif	//	DOS_READ

