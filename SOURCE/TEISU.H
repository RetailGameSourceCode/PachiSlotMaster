/*=====================================================
	teisu.h
	
	パチスロマスターSummy SP
		仮設定の定数達
	
						作ってる人		T. Kawakami
						作り出した日	11th Dec. '98
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


// play_mode用の値 
#define	GAME_NORMAL	0	// 通常ゲーム 
#define	REACH_BIG	1	// ＢＩＧフラグ成立後 
#define	REACH_REG	2	// ＲＥＧフラグ成立後 
#define	GAME_BIG	3	// 小役ゲーム中 
#define	GAME_JAC	4	// ＪＡＣゲーム中 

#define	PLAYTIME_HOUR		(game_time/216000)		// プレイ時間（時） 
#define	PLAYTIME_MIN		((game_time%216000)/3600)		// プレイ時間（分） 
#define	LASTBIG_GET			bb_getcoin_last	// 前回ＢＩＧでのゲット数 

// 成立フラグ達 
#define	FLAG_BIG	(_FL_PUL_PIC2&BB)						// ＢＩＧ 
#define	FLAG_REG	(_FL_PUL_PIC2&RB)						// ＲＥＧ 
#define	FLAG_YAKU0	(_FL_PUL_PIC1_&FRUIT1)				// 15枚役 
#define	FLAG_YAKU1	(_FL_PUL_PIC1_&FRUIT2)				// 8or10枚役 
#define	FLAG_YAKU2	(_FL_PUL_PIC1_&CHERRY)				// チェリー系役 
#define	FLAG_REP	(_FL_PUL_PIC1_&REPLAY)				// リプレイ 
#define	FLAG_JIN	(_FL_PUL_PIC1_&(REPLAY | SRB))	// ＪＡＣｉｎ役 
#define	FLAG_JAC	(_FL_PUL_PIC1_&(REPLAY | JAC))	// ＪＡＣ役 

#define	MACHINE_NO	machine_no
#define	PLAY_MODE	play_mode

//#define	ATARI_FLAG	(FLAG_BIG|FLAG_REG|FLAG_YAKU0|FLAG_YAKU1 \
//					|FLAG_YAKU2|FLAG_REP|FLAG_JIN|FLAG_JAC)

#define	TORIKOBOSHI	torikoboshi	// 取りこぼした 
#define	REACH_ME	reach_me	// ボーナスリーチに入ったフラグ 
#define	GRP_Y_FS	wave_max	// グラフＹ軸最大絶対値 

#define	MESP_NO		mesp_p->work[0]

extern	char	koyakucnt_reset;

#endif
