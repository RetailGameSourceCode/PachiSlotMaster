void replay_master(int mode)
{
	char abunai[2]={12,6};

if(mode_game!=1) return;
bb_setting();

	switch(mode){
		case  0:	/* ‰ŠúƒƒbƒZ[ƒW */
			switch(rep_step[mode]){
				case 0:
					if(_FL_ACTION&(0x01<<BT_BB)){	/* ƒrƒbƒO‚ª—ˆ‚½I */
						rep_step[1]=0;
						rep_step[2]=0;
						rep_step[mode]+=1;
						bb_kitakana=2;
						ran_f=0;
						pan_f=0;
						rep_no=0;
						pad_stop_oshitekure(1);	//  1:è‡‚É]‚Á‚ÄƒŠƒvƒŒƒC‚Í‚¸‚µ‚Ì—ûK‚ğ‚µ‚Ü‚µ‚å‚¤
						pad_stop_oshitekure(2);	//  2:‚Q‰ñ–Ú‚Ì‚i‚`‚bƒQ[ƒ€‚Ü‚Å‚Í¬–ğ‚ğ‘_‚¢‚Ü‚·
						if(!MACINE)	pad_stop_oshitekure(3);	//  3:‰Ÿ‚µ‡‚Í¶E’†E‰E‚Å‚·
						else		pad_stop_oshitekure(4);	//  4:‰Ÿ‚µ‡‚Í¶E‰EE’†‚Å‚·
					}else{
						return;
					}
				case 1:
					rl_ligh(0,0,0,0);
					if(_FL_ACTION&_JAC){	/* ‚i‚`‚b‚ª—ˆ‚½ */
						pad_stop_oshitekure(10);	//10:‚i‚`‚bƒQ[ƒ€‚ğÁ‰»‚µ‚Ü‚·
						rep_no=99;
						rep_step[mode]=2;
					}else{
						if(_FL_ACTION&(0x01<<BT_BB)){	/* ƒrƒbƒOI—¹H */
							switch(rep_no){
								case 0:
								//	pad_stop_oshitekure(1);	//  1:è‡‚É]‚Á‚ÄƒŠƒvƒŒƒC‚Í‚¸‚µ‚Ì—ûK‚ğ‚µ‚Ü‚µ‚å‚¤
								//	pad_stop_oshitekure(2);	//  2:‚Q‰ñ–Ú‚Ì‚i‚`‚bƒQ[ƒ€‚Ü‚Å‚Í¬–ğ‚ğ‘_‚¢‚Ü‚·
								//	if(!MACINE)	pad_stop_oshitekure(3);	//  3:‰Ÿ‚µ‡‚Í¶E’†E‰E‚Å‚·
								//	else		pad_stop_oshitekure(4);	//  4:‰Ÿ‚µ‡‚Í¶E‰EE’†‚Å‚·
								break;
							}
						}else{	/* ‚a‚aI‚í‚è */
							rl_ligh(0,0,0,0);
							call_unlock_resulut();
							while((rackwin[0]!=NULL) || (rackwin[3]!=NULL)) wait(1);
							bb_kitakana=0;
							bb_setting();
						}
					}
				break;
				case 2:	/* ‚i‚`‚b’†‘Ò‹@ */
					if(!(_FL_ACTION&_JAC)){	/* ‚i‚`‚bI—¹ */
						if((1<_NB_COUNT_LED2) && (_NB_COUNT_LED2<4)){	/* ‚Ü‚¾—]—Í‚ ‚è */
							rep_step[mode]=1;
							rep_no=0;
						//	pad_stop_oshitekure(1);	//  1:è‡‚É]‚Á‚ÄƒŠƒvƒŒƒC‚Í‚¸‚µ‚Ì—ûK‚ğ‚µ‚Ü‚µ‚å‚¤
							pad_stop_oshitekure(2);	//  2:‚Q‰ñ–Ú‚Ì‚i‚`‚bƒQ[ƒ€‚Ü‚Å‚Í¬–ğ‚ğ‘_‚¢‚Ü‚·
							if(!MACINE)	pad_stop_oshitekure(3);	//  3:‰Ÿ‚µ‡‚Í¶E’†E‰E‚Å‚·
							else		pad_stop_oshitekure(4);	//  4:‰Ÿ‚µ‡‚Í¶E‰EE’†‚Å‚·
						//	replay_master(0);
						}else{
							if(_FL_ACTION&(0x01<<BT_BB)){	/* ƒrƒbƒOI—¹H */
								if(abunai[MACINE]<_NB_COUNT_LED1){	/* ¬–ğ‚É—]—T—L‚è */
									rep_no=1;
									if(!ran_f){
										ran_f=1;
										if(!MACINE)	pad_stop_oshitekure(12);	//12:ƒŠƒvƒŒƒC‚Í‚¸‚µ‚ğ‚µ‚Ü‚·‰Ÿ‚µ‡‚Í@‰EE’†E¶‚Å‚·
										else		pad_stop_oshitekure(11);	//11:ƒŠƒvƒŒƒC‚Í‚¸‚µ‚ğ‚µ‚Ü‚·‰Ÿ‚µ‡‚Í@¶E’†E‰E‚Å‚·
									}
								}else{	/* ƒsƒ“ƒ`I */
									if(!pan_f){
										pad_stop_oshitekure(13);	//13:ƒpƒ“ƒN‚ğ‰ñ”ğ‚·‚é‚½‚ß‚É¬–ğ‘_‚¢‚ÉØ‚è‘Ö‚¦‚Ü‚·
										if(!MACINE)	pad_stop_oshitekure(3);	// 3:‰Ÿ‚µ‡‚Í¶E’†E‰E‚Å‚·
										else		pad_stop_oshitekure(4);	// 4:‰Ÿ‚µ‡‚Í¶E‰EE’†‚Å‚·
										pan_f=1;
									}
									rep_no=2;
								}
							}else{	/* ƒQ[ƒ€I—¹ƒf[ƒ^•\¦ */
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
		case  1:	/* ƒƒ_ƒ‹“Š“ü‚Ìˆ— */
			if(_NB_PLAY_MEDAL==3){	//	—V‹Zƒƒ_ƒ‹‚R–‡“ü‚ê‚Ä‚é
				switch(rep_step[mode]){
					case 0:
						rep_step[mode]+=1;
						switch(rep_no){
							case 0:	/* ’Êí */
							case 2:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”c‚è‚í‚¸‚© */
								if(!MACINE){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(19); //19:¶ƒŠ[ƒ‹‚Ì‚P‚X”Ô–Ú‚ÌŒ‚ğ‘_‚¢‚Ü‚·
									rl_ligh(0,19,19,1);
								}else{
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(5); // 5:¶ƒŠ[ƒ‹‚Ì•‚¢‚©‚½‚Ü‚è‚ğ‘_‚¢‚Ü‚·
									rl_ligh(0,13,19,1);
								}
							break;
							case 1:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”—]—T—L‚è */
								if(!MACINE){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(29); //29:‰EƒŠ[ƒ‹‚Ì‚P‚Q”Ô–Ú‚Ì‚q‚d‚f‚ğ‘_‚¢‚Ü‚·
									rl_ligh(2,12,12,1);
								}else{
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(5); // 5:¶ƒŠ[ƒ‹‚Ì•‚¢‚©‚½‚Ü‚è‚ğ‘_‚¢‚Ü‚·
									rl_ligh(0,13,19,1);
								}
							break;
						}
					break;
				}
			}
		break;
		case  2:	/* ‰ñ“·‰ñ“] */
			switch(rep_step[2]){
				case 0:
					switch(rep_no){
						case 0:	/* ’Êí */
						case 2:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”c‚è‚í‚¸‚© */
							if(!MACINE){
								if(_WK_REEL[0][0]==0){
									if(atarisou(CHERRY,0)){	/* ƒ`ƒFƒŠ[‚ ‚½‚èH */
										rl_ligh(0,0,0,0);
									//	pad_stop_oshitekure(50); //50:‰EE’†ƒŠ[ƒ‹‚Í‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
										pad_stop_oshitekure(7);	// 7:’†E‰EƒŠ[ƒ‹‚Í‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
										rep_step[2]=99;
									}else{
										rl_ligh(0,0,0,0);
										pad_stop_oshitekure(22);	//22:’†ƒŠ[ƒ‹‚Ì‚P‚Q”Ô–Ú‚Ì‚q‚d‚f‚ğ‘_‚¢‚Ü‚·
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
								//	pad_stop_oshitekure(7);	// 7:’†E‰EƒŠ[ƒ‹‚Í‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
									pad_stop_oshitekure(50); //50:‰EE’†ƒŠ[ƒ‹‚Í‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
									rep_step[2]=99;
								}else if((_WK_REEL[1][0]==0) || (_WK_REEL[2][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
						case 1:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”—]—T—L‚è */
							if(!MACINE){
								if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(22);	//22:’†ƒŠ[ƒ‹‚Ì‚P‚Q”Ô–Ú‚Ì‚q‚d‚f‚ğ‘_‚¢‚Ü‚·
									rl_ligh(1,12,12,1);
									rep_step[2]=1;
								}else if((_WK_REEL[0][0]==0) || (_WK_REEL[1][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}else{
								if(_WK_REEL[0][0]==0){
									rl_ligh(0,0,0,0);
									if(atarisou(CHERRY,0)){	/* ƒ`ƒFƒŠ[‚ ‚½‚èH */
										pad_stop_oshitekure(7);	// 7:’†E‰EƒŠ[ƒ‹‚Í‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
										rep_step[2]=99;
									}else{
										pad_stop_oshitekure(9);	// 9:’†ƒŠ[ƒ‹‚ÍA‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
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
				case 1:	/* ‚Q‰ñ“·–Ú’â~‚Ìˆ— */
					switch(rep_no){
						case 0:	/* ’Êí */
						case 2:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”c‚è‚í‚¸‚© */
							if(!MACINE){
								if(_WK_REEL[1][0]==0){
									rl_ligh(0,0,0,0);
									if(atarisou(KAP_FRUIT1,0)){	/* ğƒeƒ“ƒpƒC */
										pad_stop_oshitekure(27);	//27:‰EƒŠ[ƒ‹‚Ì‚P‚O”Ô–Ú‚ÌŒ‚ğ‘_‚¢‚Ü‚·
										rl_ligh(2,10,10,1);
										rep_step[2]=99;
									}else{
										pad_stop_oshitekure(8);	// 8:‰EƒŠ[ƒ‹‚ÍA‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
										rep_step[2]=99;
									}
								}else if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
						case 1:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”—]—T—L‚è */
							if(!MACINE){
								if(_WK_REEL[1][0]==0){
									rl_ligh(0,0,0,0);
									/* ŒÓ‰Z ğ */
									if(atarisou((KAP_FRUIT),0)){ /* ¬–ğƒŠ[ƒ`H */
										pad_stop_oshitekure(17);	//17:¶ƒŠ[ƒ‹‚Ì‚P‚R”Ô–Ú‚Ì‚«‚ã‚¤‚è‚ğ‘_‚¢‚Ü‚·
										rl_ligh(0,13,13,1);
									}else	if(atarisou(KAP_RB,1)){ /* ‚i‚`‚b‰¡*/
										pad_stop_oshitekure(20);	//20:¶ƒŠ[ƒ‹‚Ì‚P‚S”Ô–Ú‚Ìğ‚©‚P‚R”Ô–Ú‚Ì‚«‚ã‚¤‚è‚ğ‘_‚¢‚Ü‚·
										rl_ligh(0,13,14,1);
									}else	if(atarisou(KAP_RB,2)){ /* ‚i‚`‚b‰Eª*/
										pad_stop_oshitekure(15);	//15:¶ƒŠ[ƒ‹‚Ì‚P‚O”Ô–Ú‚Ì‚Ğ‚å‚¤‚½‚ñ‚ğ‘_‚¢‚Ü‚·
										rl_ligh(0,10,10,1);
									}else	if(atarisou(KAP_RB,3)){ /* ‚i‚`‚b‰E«*/
										pad_stop_oshitekure(18);	//18:¶ƒŠ[ƒ‹‚Ì‚P‚T”Ô–Ú‚Ì‚«‚ã‚¤‚è‚ğ‘_‚¢‚Ü‚·
										rl_ligh(0,15,15,1);
									}else{	/* ‚»‚êˆÈŠO */
										pad_stop_oshitekure(21);	//21:¶ƒŠ[ƒ‹‚Ì‚P‚O”Ô–Ú‚Ì‚Ğ‚å‚¤‚½‚ñ‚©”Ô–Ú‚Ì‚Ğ‚å‚¤‚½‚ñ‚ğ‘_‚¢‚Ü‚·
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
									if(atarisou(BIN_SRB|BIN_FRUIT2,0)){	/* ¬’Æƒeƒ“ƒpƒC */
										pad_stop_oshitekure(6);	// 6:‰EƒŠ[ƒ‹‚ÌÔ‚¢‚©‚½‚Ü‚è‚ğ‘_‚¢‚Ü‚·
										rl_ligh(2,6,7,1);
										rep_step[2]=2;
									}else{
										pad_stop_oshitekure(8);	// 8:‰EƒŠ[ƒ‹‚ÍA‚Ç‚±‚Å‚à‚¢‚¢‚Ì‚Å“K“–‚É~‚ß‚Ü‚µ‚å‚¤
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
						case 0:	/* ’Êí */
						case 2:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”c‚è‚í‚¸‚© */
						break;
						case 1:	/* ¬–ğ‚ ‚Æˆê‰ñ —V‹Z‰ñ”—]—T—L‚è */
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