/*=====================================================
	teisu.h
	
	ƒpƒ`ƒXƒƒ}ƒXƒ^[Summy SP
		‰¼Ý’è‚Ì’è”’B
	
						ì‚Á‚Ä‚él		T. Kawakami
						ì‚èo‚µ‚½“ú	11th Dec. '98
====================================================*/

#ifndef _TEISU_H_
#define _TEISU_H_

//#define	TEMOTO_MEDAL	hand_medal
#define	MAEKARA_BIG		aft_play_bb
#define	KAISU_BIG		bingo_n_bb
#define	KAISU_REG		bingo_n_rb

#define	FLG_41W			(sw_config & 1) 
#define	FLG_DSPFLAG		((sw_config >> 1) & 1)
#define	FLG_DSPREAC		((sw_config >> 2) & 1)
#define	FLG_DSPDROP		((sw_config >> 3) & 1)
#define	FLG_DSPPINF		((sw_config >> 4) & 1)
#define	FLG_DSPMINI		((sw_config >> 5) & 1)
#define	FLG_DSPSLID		((sw_config >> 6) & 1)
#define	FLG_DSPINFO		((sw_config >> 7) & 1)
#define	FLS_41W			0
#define	FLS_DSPFLAG		1
#define	FLS_DSPREAC		2
#define	FLS_DSPDROP		3
#define	FLS_DSPPINF		4
#define	FLS_DSPMINI		5
#define	FLS_DSPSLID		6
#define	FLS_DSPINFO		7


// play_mode—p‚Ì’l 
#define	GAME_NORMAL	0	// ’ÊíƒQ[ƒ€ 
#define	REACH_BIG	1	// ‚a‚h‚fƒtƒ‰ƒO¬—§Œã 
#define	REACH_REG	2	// ‚q‚d‚fƒtƒ‰ƒO¬—§Œã 
#define	GAME_BIG	3	// ¬–ðƒQ[ƒ€’† 
#define	GAME_JAC	4	// ‚i‚`‚bƒQ[ƒ€’† 

#define	PLAYTIME_HOUR		(game_time/216000)		// ƒvƒŒƒCŽžŠÔiŽžj 
#define	PLAYTIME_MIN		((game_time%216000)/3600)		// ƒvƒŒƒCŽžŠÔi•ªj 
#define	LASTBIG_GET			bb_getcoin_last	// ‘O‰ñ‚a‚h‚f‚Å‚ÌƒQƒbƒg” 

// ¬—§ƒtƒ‰ƒO’B 
#define	FLAG_BIG	(_FL_PUL_PIC2&BB)						// ‚a‚h‚f 
#define	FLAG_REG	(_FL_PUL_PIC2&RB)						// ‚q‚d‚f 
#define	FLAG_YAKU0	(_FL_PUL_PIC1_&FRUIT1)				// 15–‡–ð 
#define	FLAG_YAKU1	(_FL_PUL_PIC1_&FRUIT2)				// 8or10–‡–ð 
#define	FLAG_YAKU2	(_FL_PUL_PIC1_&CHERRY)				// ƒ`ƒFƒŠ[Œn–ð 
#define	FLAG_REP	(_FL_PUL_PIC1_&REPLAY)				// ƒŠƒvƒŒƒC 
#define	FLAG_JIN	(_FL_PUL_PIC1_&(REPLAY | SRB))	// ‚i‚`‚b‚‰‚Ž–ð 
#define	FLAG_JAC	(_FL_PUL_PIC1_&(REPLAY | JAC))	// ‚i‚`‚b–ð 

#define	MACHINE_NO	machine_no
#define	PLAY_MODE	play_mode

//#define	ATARI_FLAG	(FLAG_BIG|FLAG_REG|FLAG_YAKU0|FLAG_YAKU1 \
//					|FLAG_YAKU2|FLAG_REP|FLAG_JIN|FLAG_JAC)

#define	TORIKOBOSHI	torikoboshi	// Žæ‚è‚±‚Ú‚µ‚½ 
#define	REACH_ME	reach_me	// ƒ{[ƒiƒXƒŠ[ƒ`‚É“ü‚Á‚½ƒtƒ‰ƒO 
#define	GRP_Y_FS	wave_max	// ƒOƒ‰ƒt‚xŽ²Å‘åâ‘Î’l 

#define	MESP_NO		mesp_p->work[0]

extern	char	koyakucnt_reset;

#endif
