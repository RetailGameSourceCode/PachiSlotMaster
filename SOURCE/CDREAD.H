
#ifndef _CDREAD_H_

#define _CDREAD_H_

void *datafile_read(enum fnum file, void *radr);
void *cdread(enum fnum file, void *radr);

void cdread_wait(void);
void cdread_wait_nw(void);
void cdread_init(void);

void cd_read_fast(void);

int cdread_stat(void);

extern int	read_stat;			/*cd_read_fastの処理状態(1:read go 0:NOP)*/
extern int	cd_err[8];	/*ＣＤリードエラー*/

#endif

