
#ifndef _DOBJ_H_

#define _DOBJ_H_

#define TOD_ATTR	(0)
#define TOD_COORD	(1)
#define TOD_TMDID	(2)
#define TOD_PARENT	(3)
#define TOD_MATRIX	(4)
#define TOD_TMDDATA	(5)
#define TOD_LIGHT	(6)
#define TOD_CAMERA	(7)
#define TOD_OBJCTL	(8)
#define TOD_USER0	(9)
#define TOD_USER1	(10)
#define TOD_USER2	(11)
#define TOD_USER3	(12)
#define TOD_USER4	(13)
#define TOD_SYSFUNC	(15)

#define GsTOD_CREATE	(0)	/*全てのパケットを実行*/
#define GsTOD_NOCREATE	(1)	/*オブジェクトの生成／削除は行なわない*/
#define GsTOD_COORDONLY	(2)	/*座標系の変化のみ実行*/

#define GsOBJ_UNDEF	(0xffffffff)

typedef struct {
	u_short anim_flg;		/* 再生状態 */
	u_short type;			/* 再生種別 */
	u_long cnt;				/* フレーム数カウンター */
	u_long frame_cnt;		/* フレーム数 */
	u_long act_frame;		/* 現在のフレーム */
	u_long *tod_org;		/* TODデータのポインタ保持用 */

	u_long *tod_adr;		/* TODデータのポインタ */
	u_long *tmd_adr;		/* TMDデータのポインタ */
	int *tmd_id;			/* モデリングデータIDリストのポインタ */
	int mode;				/* 再生モード */
}TOD_ANIM;

#define TX 0
#define TY 1
#define TZ 2

#define	TOD_ANIM_END	0	/* 最後まで再生したらそこで停止 */
#define	TOD_ANIM_LOOP	1	/* ループ */
#define	TOD_ANIM_KILL	2	/* 最後まで再生したらそこで終了 */

/*-------------------------------------------------------------*/
void dobj_init(void);
GsDOBJ2 *dobj_make(u_long id);
void dobj_kill(GsDOBJ2 *dobj_pt);
void dobj_idkill(u_long id);
GsDOBJ2 *dobj_search(u_long id);

void dobj_draw(void);

u_long *tmd_search(u_long *tmd_adr, int *tmd_id, u_long id);
u_long *dobj_anim_frame(int cframe, u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode);
u_long *dobj_anim_packet(u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode);

void dobj_anim_init(void);
TOD_ANIM *dobj_anim_set(u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode, u_short type);
void dobj_anim_chg(TOD_ANIM *todanim_pt, u_long *tod_adr, int *tmd_id, u_long *tmd_adr, int mode, u_short type);
void dobj_anim_chg2(TOD_ANIM *todanim_pt, u_long *tod_adr, int mode, u_short type);
void dobj_anim_end(TOD_ANIM *todanim_pt);
void dobj_anim(void);

#endif

