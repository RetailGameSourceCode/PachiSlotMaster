/*=============================================================
 *			タスク
 *
 *=============================================================*/


#include "common.h"
#include "work.h"


/*	タスク　*/
#define TASK_MAX 64

/* タスク構造体 */
struct _TASK{
	long	sw;				/* タスクの中はswitchで分岐するでしょうから それ用に専用で */
	long	twork[8];		/* 汎用ワーク */
	u_short	wait;			/* ウェイトタイム */
	u_short	flg;			/* システム予約 */
	void	*adr;			/* システム予約 */
	struct _TASK *mother;	/* システム予約 */
	struct _TASK *before;	/* システム予約 */
	struct _TASK *next;		/* システム予約 */
};
typedef struct _TASK TASK;

/*　タスク　*/
TASK tcb[TASK_MAX];		/*タスク*/
TASK *tcb_top;			/*タスクトップ*/
TASK *tcb_last;			/*タスクラスト*/




/*===================================================================
 *　メインタスクモードを切り替えます
 *
 * in : int	メインタスクの登録（モード）番号
 * out: void
 *
 *=================================================================*/
void _mode_chg(int chgmode)
{
	mode = chgmode;
}


/*===================================================================
 *　タスクをエントリーします
 *
 * in : void * 登録するタスク関数アドレス
 * out: TASK * エントリーしたタスクへのポインタ(自分では無いことに注意)
 *
 *=================================================================*/
TASK *task_make(void *task_adr)
{
 int task_cnt;

	task_cnt = 0;
	while( task_cnt < TASK_MAX )
	{
		if( tcb[task_cnt].flg )	/*使用されているかどうか*/
		{
			task_cnt++;
		}
		else
		{
			tcb[task_cnt].flg = 1;			/*エントリーして*/
			tcb[task_cnt].adr = task_adr;	/*タスクのアドレス登録*/
			tcb[task_cnt].sw = 0;
			tcb[task_cnt].twork[0] = 0;
			tcb[task_cnt].twork[1] = 0;
			tcb[task_cnt].twork[2] = 0;
			tcb[task_cnt].twork[3] = 0;
			tcb[task_cnt].twork[4] = 0;
			tcb[task_cnt].twork[5] = 0;
			tcb[task_cnt].twork[6] = 0;
			tcb[task_cnt].twork[7] = 0;
			tcb[task_cnt].mother = NULL;

			/*リストへつなぐ*/
			if( tcb_top == NULL )
			{
				/*初めて*/
				tcb_top = &tcb[task_cnt];
				tcb[task_cnt].before = NULL;
				tcb[task_cnt].next = NULL;
			}
			else
			{
				/*２つめ以降*/
				tcb_last->next = &tcb[task_cnt];
				tcb[task_cnt].before = tcb_last;
				tcb[task_cnt].next = NULL;
			}
			tcb_last = &tcb[task_cnt];
			return &tcb[task_cnt];
		}
	}
	return NULL;
}


/*===================================================================
 *　タスクを解放します
 *	自分自身の解放の場合は、task_kill
 *	タスク処理の一番最後の処理として、この関数を呼ぶように
 *	別のタスクを殺す場合は、ottask_kill
 *
 * in : TASK * 解放するタスクポインタ
 * out: void
 *
 *=================================================================*/
void _task_kill(TASK *task_pt)
{
 TASK *before_pt;
 TASK *next_pt;

	if(task_pt->flg)
	{
		task_pt->flg = 0;		/*エントリーを消して*/
		before_pt = task_pt->before;
		next_pt = task_pt->next;

		/*リスト列からはずす*/
		if( before_pt == NULL && next_pt == NULL )
		{
			/*自分しかいない*/
			task_init();
		}
		else
		{
			if( before_pt == NULL )
			{
				tcb_top = next_pt;
			}
			else
			{
				before_pt->next = next_pt;
			}
			if( next_pt == NULL )
			{
				tcb_last = before_pt;
			}
			else
			{
				next_pt->before = before_pt;
			}
		}
	}
}


/*===================================================================
 *　タスクからタスクを呼びます
 *
 * in : TASK * タスクポインタ
 *		void * コールタスク関数
 * out: void
 *
 *=================================================================*/
void _task_call(TASK *task_pt, void *adr)
{
 TASK *call_task;

	call_task = task_make(adr);		/*子をつくって*/
	call_task->mother = task_pt;	/*自分をおぼえさせて*/
	task_sleep(task_pt);			/*寝る*/
}


/*===================================================================
 *　タスクから呼ばれたタスクのリターン
 *
 * in : TASK * タスクポインタ
 * out: void
 *
 *=================================================================*/
void _task_return(TASK *call_task)
{
	task_wakeup(call_task->mother);	/*親を起こして*/
	task_kill(call_task);			/*自分は消滅*/
}


/*===================================================================
 *　タスクのウェイトタイムをセットします
 *	これを使わずに、ただ関数を抜けるだけなら、通常は１です
 *
 * in : TASK * タスクポインタ
 *		u_short	ウェイト時間(フレーム)
 * out: void
 *
 *=================================================================*/
void _task_wait(TASK *task_pt, u_short time)
{
	task_pt->wait = time;
}


/*===================================================================
 *　指定タスクを寝かせます
 *
 * in : TASK * タスクポインタ
 * out: void
 *
 *=================================================================*/
void task_sleep(TASK *task_pt)
{
	task_pt->flg = task_pt->flg | 0x8000;
}


/*===================================================================
 *　指定タスクを起こします
 *
 * in : TASK * タスクポインタ
 * out: void
 *
 *=================================================================*/
void task_wakeup(TASK *task_pt)
{
	task_pt->flg = task_pt->flg & 0x7fff;
}




/*===================================================================
 *　タスクを初期化します
 *
 * in : void
 * out: void
 *
 *=================================================================*/
void task_init(void)
{
 int task_cnt;

	tcb_top = tcb_last = NULL;
	for(task_cnt = 0; task_cnt < TASK_MAX; task_cnt++ )
	{
		tcb[task_cnt].flg = 0;
		tcb[task_cnt].before = NULL;
		tcb[task_cnt].next = NULL;
	}
}


/*===================================================================
 *　登録されたタスクに処理を受け渡します
 *　タスク側は１フレームに１度必ず帰ってくるような
 *　構造にしておいてください
 *	タスクの関数は "void ???????(TASK *pt)" の型でつくってください
 *	引数の"TASK *pt"で、自分のタスクの変数をさわれます
 *
 * in : void
 * out: void
 *
 *=================================================================*/
void (*task_func)(TASK *task_pt);	/*タスクの型宣言*/
void task_drv(void)
{
 register TASK *task_pt;
 int task_cnt;/*testtest*/

	task_cnt = 0;/*testtest*/
	task_pt = tcb_top;				/*タスクのトップポインタ*/
	while( task_pt != NULL )		/*終わるまで繰り返す*/
	{
		if(!(task_pt->flg & 0x8000))
		{
			if(task_pt->wait > 1)
			{
				task_pt->wait--;
			}
			else
			{
				task_func = task_pt->adr;
				task_func(task_pt);
			}
		}
		task_cnt++;/*testtest*/
		task_pt = task_pt->next;	/*次のタスクへ*/
	}
FntPrint("TASK=%d\n",task_cnt);/*testtest*/
}



