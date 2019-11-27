//	ＴＥＮパチスロ ＭＡＩＮ  

#include "common.h"
#include "work.h"


int main(void)
{
	func_mode = MODE_NOP;	//立ち上げ時 
	initSystem();
	SetDispMask(1);			// 表示ON 

	func_mode = MODE_MOVIE;	//立ち上げ時 
//	func_mode = MODE_GAME;	//立ち上げ時 
//	func_mode = MODE_TITLE;	//立ち上げ時 
	mode_init();		//	表示モードの変更 

	shira_yobu();

	auto_load();	//	オートロード 
	while(1){
		mode_init();		//	表示モードの変更 
		switch(func_mode){
			case	MODE_NOP:		//	何もしない 
					func_mode=MODE_MOVIE;
			break;
			case	MODE_MOVIE:
				//	ここでタイトルとセレクトの絵を読み込む
//				load_tims();		/*	テクスチャロード	*/
#ifndef MOVIE_CUT
				movie_main(ST_TITLE); 
				func_mode=MODE_TITLE;
#else
				func_mode=MODE_TITLE;
//				func_mode = MODE_GAME;	//立ち上げ時 
#endif
			break;
			case	MODE_TITLE:
				titleMain();
			break;
			case	MODE_GAME:
				game_main();	//	iteya用
			break;
		}
		wait(1);
	}
}

