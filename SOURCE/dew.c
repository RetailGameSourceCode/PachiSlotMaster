void replay_master(int mode)
{
	char abunai[2]={12,6};

if(mode_game!=1) return;
bb_setting();

	switch(mode){
		case  0:	/* 初期メッセージ */
			switch(rep_step[mode]){
				case 0:
					if(_FL_ACTION&(0x01<<BT_BB)){	/* ビッグが来た！ */
						rep_step[1]=0;
						rep_step[2]=0;
						rep_step[mode]+=1;
						bb_kitakana=2;
						ran_f=0;
						pan_f=0;
						rep_no=0;
						pad_stop_oshitekure(1);	//  1:手順に従ってリプレイはずしの練習をしましょう
						pad_stop_oshitekure(2);	//  2:２回目のＪＡＣゲームまでは小役を狙います
						if(!MACINE)	pad_stop_oshitekure(3);	//  3:押し順は左・中・右です
						else		pad_stop_oshitekure(4);	//  4:押し順は左・右・中です
					}else{
						return;
					}
				case 1:
					rl_ligh(0,0,0,0);
					if(_FL_ACTION&_JAC){	/* ＪＡＣが来た */
						pad_stop_oshitekure(10);	//10:ＪＡＣゲームを消化します
						rep_no=99;
						rep_step[mode]=2;
					}else{
						if(_FL_ACTION&(0x01<<BT_BB)){	/* ビッグ終了？ */
							switch(rep_no){
								case 0:
								//	pad_stop_oshitekure(1);	//  1:手順に従ってリプレイはずしの練習をしましょう
								//	pad_stop_oshitekure(2);	//  2:２回目のＪＡＣゲームまでは小役を狙います
								//	if(!MACINE)	pad_stop_oshitekure(3);	//  3:押し順は左・中・右です
								//	else		pad_stop_oshitekure(4);	//  4:押し順は左・右・中です
								break;
							}
						}else{	/* ＢＢ終わり */
							rl_ligh(0,0,0,0);
							call_unlock_resulut();
							while((rackwin[0]!=NULL) || (rackwin[3]!=NULL)) wait(1);
							bb_kitakana=0;
							bb_setting();
						}
					}
				break;
				case 2:	/* ＪＡＣ中待機 */
					if(!(_FL_ACTION&_JAC)){	/* ＪＡＣ終了 */
						if((1<_NB_COUNT_LED2) && (_NB_COUNT_LED2<4)){	/* まだ余力あり */
							rep_step[mode]=1;
							rep_no=0;
						//	pad_stop_oshitekure(1);	//  1:手順に従ってリプレイはずしの練習をしましょう
							pad_stop_oshitekure(2);	//  2:２回目のＪＡＣゲームまでは小役を狙います
							if(!MACINE)	pad_stop_oshitekure(3);	//  3:押し順は左・中・右です
							else		pad_stop_oshitekure(4);	//  4:押し順は左・右・中です
						//	replay_master(0);
						}else{
							if(_FL_ACTION&(0x01<<BT_BB)){	/* ビッグ終了？ */
								if(abunai[MACINE]<_NB_COUNT_LED1){	/* 小役に余裕有り */
									rep_no=1;
									if(!ran_f){
										ran_f=1;
										if(!MACINE)	pad_stop_oshitekure(12);	//12:リプレイはずしをします押し順は　右・中・左です
										else		pad_stop_oshitekure(11);	//11:リプレイはずしをします押し順は　左・中・右です
									}
								}else{	/* ピンチ！ */
									if(!pan_f){
										pad_stop_oshitekure(13);	//13:パンクを回避するために小役狙いに切り替えます
										if(!MACINE)	pad_stop_oshitekure(3);	// 3:押し順は左・中・右です
										else		pad_stop_oshitekure(4);	// 4:押し順は左・右・中です
										pan_f=1;
									}
									rep_no=2;
								}
							}else{	/* ゲーム終了データ表示 */
								rl_ligh(0,0,0,0);
								call_unlock_resulut();
								while((rackwin[0]!=NULL) || (rackwin[3]!=NULL)) wait(1);
								bb_kitakana=0;
								bb_setting();
							}
						}
					}else{
						rl_ligh(0,0,0,0);
						rep_no=99;
					}
				break;
				case 4:
				break;
			}
			rep_step[1]=0;
			rep_step[2]=0;
		break;
		case  1:	/* メダル投入時の処理 */
			if(_NB_PLAY_MEDAL==3){	//	遊技メダル３枚入れてる
				switch(rep_step[mode]){
					case 0:
						rep_step[mode]+=1;
						switch(rep_no){
							case 0:	/* 通常 */
							case 2:	/* 小役あと一回 遊技回数残りわずか */
								if(!MACINE){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(19); //19:左リールの１９番目の月を狙います
									rl_ligh(0,19,19,1);
								}else{
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(5); // 5:左リールの黒いかたまりを狙います
									rl_ligh(0,13,19,1);
								}
							break;
							case 1:	/* 小役あと一回 遊技回数余裕有り */
								if(!MACINE){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(29); //29:右リールの１２番目のＲＥＧを狙います
									rl_ligh(2,12,12,1);
								}else{
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(5); // 5:左リールの黒いかたまりを狙います
									rl_ligh(0,13,19,1);
								}
							break;
						}
					break;
				}
			}
		break;
		case  2:	/* 回胴回転時 */
			switch(rep_step[2]){
				case 0:
					switch(rep_no){
						case 0:	/* 通常 */
						case 2:	/* 小役あと一回 遊技回数残りわずか */
							if(!MACINE){
								if(_WK_REEL[0][0]==0){
									if(atarisou(CHERRY,0)){	/* チェリーあたり？ */
										rl_ligh(0,0,0,0);
									//	pad_stop_oshitekure(50); //50:右・中リールはどこでもいいので適当に止めましょう
										pad_stop_oshitekure(7);	// 7:中・右リールはどこでもいいので適当に止めましょう
										rep_step[2]=99;
									}else{
										rl_ligh(0,0,0,0);
										pad_stop_oshitekure(22);	//22:中リールの１２番目のＲＥＧを狙います
										rl_ligh(1,12,12,1);
										rep_step[2]=1;
									}
								}else if((_WK_REEL[1][0]==0) || (_WK_REEL[2][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}else{
								if(_WK_REEL[0][0]==0){
									rl_ligh(0,0,0,0);
								//	pad_stop_oshitekure(7);	// 7:中・右リールはどこでもいいので適当に止めましょう
									pad_stop_oshitekure(50); //50:右・中リールはどこでもいいので適当に止めましょう
									rep_step[2]=99;
								}else if((_WK_REEL[1][0]==0) || (_WK_REEL[2][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
						case 1:	/* 小役あと一回 遊技回数余裕有り */
							if(!MACINE){
								if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(22);	//22:中リールの１２番目のＲＥＧを狙います
									rl_ligh(1,12,12,1);
									rep_step[2]=1;
								}else if((_WK_REEL[0][0]==0) || (_WK_REEL[1][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}else{
								if(_WK_REEL[0][0]==0){
									rl_ligh(0,0,0,0);
									if(atarisou(CHERRY,0)){	/* チェリーあたり？ */
										pad_stop_oshitekure(7);	// 7:中・右リールはどこでもいいので適当に止めましょう
										rep_step[2]=99;
									}else{
										pad_stop_oshitekure(9);	// 9:中リールは、どこでもいいので適当に止めましょう
										rep_step[2]=1;
									}
								}else if((_WK_REEL[1][0]==0) || (_WK_REEL[2][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
					}
				break;
				case 1:	/* ２回胴目停止時の処理 */
					switch(rep_no){
						case 0:	/* 通常 */
						case 2:	/* 小役あと一回 遊技回数残りわずか */
							if(!MACINE){
								if(_WK_REEL[1][0]==0){
									rl_ligh(0,0,0,0);
									if(atarisou(KAP_FRUIT1,0)){	/* 酒テンパイ */
										pad_stop_oshitekure(27);	//27:右リールの１０番目の月を狙います
										rl_ligh(2,10,10,1);
										rep_step[2]=99;
									}else{
										pad_stop_oshitekure(8);	// 8:右リールは、どこでもいいので適当に止めましょう
										rep_step[2]=99;
									}
								}else if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
						case 1:	/* 小役あと一回 遊技回数余裕有り */
							if(!MACINE){
								if(_WK_REEL[1][0]==0){
									rl_ligh(0,0,0,0);
									/* 胡瓜 酒 */
									if(atarisou((KAP_FRUIT),0)){ /* 小役リーチ？ */
										pad_stop_oshitekure(17);	//17:左リールの１３番目のきゅうりを狙います
										rl_ligh(0,13,13,1);
									}else	if(atarisou(KAP_RB,1)){ /* ＪＡＣ横*/
										pad_stop_oshitekure(20);	//20:左リールの１４番目の酒か１３番目のきゅうりを狙います
										rl_ligh(0,13,14,1);
									}else	if(atarisou(KAP_RB,2)){ /* ＪＡＣ右↑*/
										pad_stop_oshitekure(15);	//15:左リールの１０番目のひょうたんを狙います
										rl_ligh(0,10,10,1);
									}else	if(atarisou(KAP_RB,3)){ /* ＪＡＣ右↓*/
										pad_stop_oshitekure(18);	//18:左リールの１５番目のきゅうりを狙います
										rl_ligh(0,15,15,1);
									}else{	/* それ以外 */
										pad_stop_oshitekure(21);	//21:左リールの１０番目のひょうたんか番目のひょうたんを狙います
										rl_ligh(0,10,10,1);
										rl_ligh(0,0,0,1);
									}
									rep_step[2]=99;
								}else if(_WK_REEL[0][0]==0){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}else{
								if(_WK_REEL[1][0]==0){
									rl_ligh(0,0,0,0);
									if(atarisou(BIN_SRB|BIN_FRUIT2,0)){	/* 小槌テンパイ */
										pad_stop_oshitekure(6);	// 6:右リールの赤いかたまりを狙います
										rl_ligh(2,6,7,1);
										rep_step[2]=2;
									}else{
										pad_stop_oshitekure(8);	// 8:右リールは、どこでもいいので適当に止めましょう
										rep_step[2]=99;
									}
								}else if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
					}
				break;
				case 2:
					switch(rep_no){
						case 0:	/* 通常 */
						case 2:	/* 小役あと一回 遊技回数残りわずか */
						break;
						case 1:	/* 小役あと一回 遊技回数余裕有り */
							if(!MACINE){
							}else{
								if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
					}
				break;
			}
		break;
	}
}
