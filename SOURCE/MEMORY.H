
#ifndef _MEMORY_H_

#define _MEMORY_H_

extern long mal_size;
extern long mal_msize;
extern void *memalloc(size_t s, void** adr);	//	メモリ確保
extern void memfree(void **adr);		//	メモリ開放

#ifdef DEBUG_FONT
extern long mal_s;
extern void *mal_a;
extern void *mal_l;
extern int mal_c;
extern void *mall[100];

#endif

#endif

