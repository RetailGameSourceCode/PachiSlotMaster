
#ifndef _FUNC_H_

#define _FUNC_H_

void boot_init(void);
void start_init(void);
void first_data(void);

void tim_load(u_short *adr, int load_type);
void tim_load_fis(u_short *adr, int load_type,int point);


#endif

