/*===================================================
	option.c
	
	ＴＥＮ	パチスロコレクション
	オプション画面
	
						作ってる人		T. Kawakami
						作り出した日	21st Nov. '98
====================================================*/

/*===========================================================
	オプションメニュー
===========================================================*/
short	option_menu(short *sp) {
	static	TITLE_INF	*tp;
			short		retv = 0;
	
	switch (*sp) {
	case 0:
		tp = (TITLE_INF *)memalloc(sizeof(TITLE_INF), (void **)&tp);
		if (tp != NULL) {
			init_tMenu(tp);
			(*sp)++;
		} else
			retv = -1;
		winp = (WINDOW *)memalloc(sizeof(WINDOW), (void **)&winp);
		if (winp != NULL) {
			makeWin(winp, -40,-20,20,20, 1);
		}
		break;
	case 1:
		key_tMenu(tp);
		tp->notouch++;
		if (tp->notouch > TITLE_SYNC) {
			tp->curN = 4;
			(*sp)++;
		} else if (tp->exitF)
			(*sp)++;
		
		break;
	case 2:
		disposeWin(winp);
		memfree((void **)&winp);
		retv = tp->curN + 1;
		free_tMenu(tp);
		memfree((void **)&tp);
		break;
	default:
	}
	
	return retv;
}

