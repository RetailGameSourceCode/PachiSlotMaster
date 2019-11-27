#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_

extern struct DIRENTRY dirent[15];
extern struct DIRENTRY dirent2[15];
extern char slf; //ÉçÅ[ÉhÇ≥ÇÍÇΩÇ©ÅH
extern long alf;
extern long alf2;
extern char slc;

extern int mc_mode;
extern char slpad_m;
extern char memc_unfm;

extern void save_data_clear(void);
extern void w_init(void);
extern void w_exit(void);
extern int card_seq_check(int);
extern void save_main(int mode);
extern int check_cardf;
extern int uwagaki;

extern void auto_load(void);
extern char aul_ok;

#endif

