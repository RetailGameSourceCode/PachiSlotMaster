#ifndef _TASK2_H_
#define _TASK2_H_

extern	short	task_cnt;	//	登録されているタスク数

/*	タスク　*/
#define TASK_MAX 64

int	taskMode;

/* タスク構造体 */
struct _TASK{
	long	_step;			/* タスクの中はswitchで分岐するでしょうから それ用に専用で */
	long	twork[8];		/* 汎用ワーク */
	u_short	wait;			/* ウェイトタイム */
	u_short	flg;			/* システム予約 タスク登録済みフラグ*/
	void	*adr;			/* システム予約	呼出し関数のアドレス */
	struct _TASK *mother;	/* システム予約 親タスク*/
	struct _TASK *before;	/* システム予約 直前リスト*/
	struct _TASK *next;		/* システム予約 次リスト*/
};
typedef struct _TASK TASK;

/*　タスク　*/
TASK tcb[TASK_MAX];		/*タスク*/
TASK *tcb_top;			/*タスクトップ*/
TASK *tcb_last;			/*タスクラスト*/



void _mode_chg(int chgmode);
/* モードを切り替えます & return */
#define mode_chg(chgmode) _mode_chg(chgmode); return

void _task_wait(TASK *task_pt, u_short time);
/* ウエイトタイムセット & return */
#define task_wait(task_pt,time)	_task_wait(task_pt,time); return

void _task_kill(TASK *task_pt);
/* タスク（自分）の解放 & return */
#define task_kill(task_pt)		_task_kill(task_pt); return
/* タスク（他人）の解放 */
#define ottask_kill(task_pt)	_task_kill(task_pt)

void _task_call(TASK *task_pt, void *adr);
/* タスク関数コール & return */
#define task_call(task_pt,adr)	_task_call(task_pt,adr); return

void _task_return(TASK *task_pt);
/* タスク関数リターン & return */
#define task_return(task_pt)	_task_return(task_pt); return

/* タスクの登録 */
TASK *task_make(void *task_adr);
TASK *child_make(void *task_adr, TASK *mom);

void task_sleep(TASK *task_pt);
void task_wakeup(TASK *task_pt);

void task_init(void);
void task_drv(void);


#endif

