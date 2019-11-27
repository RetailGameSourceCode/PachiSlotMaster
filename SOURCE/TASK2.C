/*------------------------------------------------------
		ファイル名	：TASK2.c

		説明		：タスク処理の実験

		作成履歴	：ver1.0	1998/10/19	Tomy   		new
---------------------------------------------------------*/


#include "common.h"
#include "work.h"

#include "task2.h"


short	task_cnt = 0;	//	登録されているタスク数


/*===================================================================
 *　メインタスクモードを切り替えます
 *
 * in : int	メインタスクの登録（モード）番号
 * out: void
 *
 *=================================================================*/
void _mode_chg(int chgmode)
{
	taskMode = chgmode;
}


/*===================================================================
 *　タスクをＴＣＢの末尾にエントリーします
 *
 * in : void * 登録するタスク関数アドレス
 * out: TASK * エントリーしたＴＣＢへのポインタ(自分では無いことに注意)
 *
 *=================================================================*/
TASK *task_make(void *task_adr) {
	int	t_count = 0;
	
	if (task_cnt >= TASK_MAX) {	// 登録数オーバー
#if DEBUG
		printf("too many task.\n");
#endif
		return NULL;				//	登録却下
	}
	
	//	空きＴＣＢ探し
	while( t_count < TASK_MAX ) {
		if( tcb[t_count].flg ) {	/*使用されているかどうか*/
			t_count++;
		} else {
			break;
		}
	}
	
	if (t_count >= TASK_MAX) {	// 本来は有り得ないのだが
#if DEBUG
		printf("no task space.\n");
#endif
		return NULL;
	}
	
	tcb[t_count].flg = 1;			/*エントリーして*/
	tcb[t_count].adr = task_adr;	/*タスクのアドレス登録*/
	tcb[t_count]._step = 0;
	tcb[t_count].twork[0] = 0;
	tcb[t_count].twork[1] = 0;
	tcb[t_count].twork[2] = 0;
	tcb[t_count].twork[3] = 0;
	tcb[t_count].twork[4] = 0;
	tcb[t_count].twork[5] = 0;
	tcb[t_count].twork[6] = 0;
	tcb[t_count].twork[7] = 0;
	tcb[t_count].mother = NULL;
	
	/*リストへつなぐ*/
	if( tcb_top == NULL )
	{
		/*初めて*/
		tcb_top = &tcb[t_count];
		tcb[t_count].before = NULL;
		tcb[t_count].next = NULL;
	}
	else
	{
		/*２つめ以降*/
		tcb_last->next = &tcb[t_count];
		tcb[t_count].before = tcb_last;
		tcb[t_count].next = NULL;
	}
	tcb_last = &tcb[t_count];
	task_cnt++;
	
	return &tcb[t_count];
}
/*===================================================================
 *　子タスク作成	親の直前に挿入する。
 *
 * in : void * 登録するタスク関数アドレス
 *		TASK * 親のタスクワークポインタ
 * out: TASK * エントリーしたタスクへのポインタ(自分では無いことに注意)
 *
 *=================================================================*/
TASK *child_make(void *task_adr, TASK *mom) {
	TASK *befop = mom->before;
	TASK *nextp = mom;
	int	t_count = 0;
	
	if (task_cnt >= TASK_MAX) {	// 登録数オーバー
#if DEBUG
		printf("too many task.\n");
#endif
		return NULL;				//	登録却下
	}
	
	//	空きＴＣＢ探し
	while( t_count < TASK_MAX ) {
		if( tcb[t_count].flg ) {	/*使用されているかどうか*/
			t_count++;
		} else {
			break;
		}
	}
	if (t_count >= TASK_MAX) {	// 本来は有り得ないのだが
#if DEBUG
		printf("no task space.\n");
#endif
		return NULL;
	}
	
	tcb[t_count].flg = 1;			/*エントリーして*/
	tcb[t_count].adr = task_adr;	/*タスクのアドレス登録*/
	tcb[t_count]._step = 0;
	tcb[t_count].twork[0] = 0;
	tcb[t_count].twork[1] = 0;
	tcb[t_count].twork[2] = 0;
	tcb[t_count].twork[3] = 0;
	tcb[t_count].twork[4] = 0;
	tcb[t_count].twork[5] = 0;
	tcb[t_count].twork[6] = 0;
	tcb[t_count].twork[7] = 0;
	tcb[t_count].mother = mom;
	
	/*リストへつなぐ*/
	if (befop == NULL) {	//	親が先頭だった
		tcb_top = &tcb[t_count];
		tcb[t_count].before = NULL;
	} else {				//	親は先頭でない
		tcb[t_count].before = befop;
		befop->next = &tcb[t_count];
	}
	tcb[t_count].next = mom;
	nextp->before = &tcb[t_count];
	
	task_cnt++;
	
	return &tcb[t_count];
}


/*===================================================================
	関 数 名：	void	 _task_kill(
					TASK *task_pt
				)
	
	処理概要：タスク解放
				自分自身の解放の場合は、task_kill
				タスク処理の一番最後の処理として、この関数を呼ぶように
				別のタスクを殺す場合は、ottask_kill
				
				再帰的に自分を親とするタスクを殺す処理を追加してみる。やばいかも	19th Oct. '98	Tomy

	引　　数：TASK * 解放するタスクポインタ

	戻 り 値：なし

	作成履歴：Ver1.0 1998/10/19 -		Tomy 		New
 *=================================================================*/
void _task_kill(TASK *task_pt) {
	TASK *before_pt;
	TASK *next_pt;
	char	tmp;
	
	if(task_pt->flg) {
		task_pt->flg = 0;		/*エントリーを消して*/
		before_pt = task_pt->before;
		next_pt = task_pt->next;
		
		/*リスト列からはずす*/
		if( before_pt == NULL && next_pt == NULL ) { /*自分しかいない*/
			task_init();
		} else {
			if( before_pt == NULL ) {	// 先頭
				tcb_top = next_pt;
			} else {
				before_pt->next = next_pt;
			}
			
			if( next_pt == NULL ) {		// 末尾
				tcb_last = before_pt;
			} else {
				next_pt->before = before_pt;
			}
		}
		task_cnt--;
		
		//	子タスク探し＆抹消
		if (task_cnt > 0) {	//	登録タスクがまだある
			for (tmp = 0; tmp < TASK_MAX; tmp++) {
				if (tcb[tmp].flg && tcb[tmp].mother == task_pt) {
					ottask_kill(&tcb[tmp]);
				}
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
 *　タスク関連処理を初期化します
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
	
	task_pt = tcb_top;				/*タスクのトップポインタ*/
	while( task_pt != NULL )		/*終わるまで繰り返す*/
	{
		if(!(task_pt->flg & 0x8000))	//	起きてる
		{
			if(task_pt->wait > 1) {
				task_pt->wait--;
			} else {
				task_func = task_pt->adr;
				task_func(task_pt);
			}
		}
		task_pt = task_pt->next;	/*次のタスクへ*/
	}
#if DEBUG_FLAG
FntPrint("TASK=%d\n",task_cnt);/*testtest*/
#endif
}
