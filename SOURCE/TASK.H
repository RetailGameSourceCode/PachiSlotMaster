
#ifndef _TASK_H_

#define _TASK_H_


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


void task_sleep(TASK *task_pt);
void task_wakeup(TASK *task_pt);

void task_init(void);
void task_drv(void);


#endif

