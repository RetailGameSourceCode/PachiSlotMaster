
#ifndef _DRUM_H_

#define _DRUM_H_

#define DRUM_MAX (3)

int drum_set(short cnt, int mode, u_long mod_adr);
void drum_end(void);
void move_dice_view(void);
void light_init(void);
void drum_spin(void);


#endif

