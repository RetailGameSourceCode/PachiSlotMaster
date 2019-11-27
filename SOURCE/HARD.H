

#ifndef _HARDWARE_H_

#define _HARDWARE_H_

#define DRUM_MAX (3)

#define POFS (0x500)
#define MOFS (-0x500)
#define DZERO_F	(0)
#define DRUM_ARIMASU drum_arimasu
#define ZOOM_LEVEL	zoom_level


#define KYOUTAI_SP_MAX (35)
extern SPRITE_OBJECT	*kyoutai_sp[KYOUTAI_SP_MAX];
#define LAMP_SP_MAX (40)
extern SPRITE_OBJECT	*lamp_sp[LAMP_SP_MAX];
extern void ramp_hikare(void);


int drum_set(short cnt, int mode, u_long mod_adr);
void drum_end(void);
void move_dice_view(void);
void light_init(void);
void drum_spin(void);
extern int drum_roll_set(int d_no,int r_no,int mode);

extern void hard_all_kill(void);

void kyoutai_set(int sw);
void hardware_inter(void);
extern void kyoutai_move(void);
extern void digital_set(void);
extern char	drum_arimasu;
extern int hd_inter;
extern void sub_m(void);
extern void _med_kau(void);
extern void jissen_data_set(char mode);
extern int warikomi_k(void);
extern void drum_point_set(int d_no,int r_no,int mode);
extern void remember_lot_set(void);

extern short zom;
extern char auto_on_s;
extern int cckk;

extern void bak_kawa(void);
extern void ret_kawa(void);


#endif
