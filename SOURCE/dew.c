void replay_master(int mode)
{
	char abunai[2]={12,6};

if(mode_game!=1) return;
bb_setting();

	switch(mode){
		case  0:	/* �������b�Z�[�W */
			switch(rep_step[mode]){
				case 0:
					if(_FL_ACTION&(0x01<<BT_BB)){	/* �r�b�O�������I */
						rep_step[1]=0;
						rep_step[2]=0;
						rep_step[mode]+=1;
						bb_kitakana=2;
						ran_f=0;
						pan_f=0;
						rep_no=0;
						pad_stop_oshitekure(1);	//  1:�菇�ɏ]���ă��v���C�͂����̗��K�����܂��傤
						pad_stop_oshitekure(2);	//  2:�Q��ڂ̂i�`�b�Q�[���܂ł͏�����_���܂�
						if(!MACINE)	pad_stop_oshitekure(3);	//  3:�������͍��E���E�E�ł�
						else		pad_stop_oshitekure(4);	//  4:�������͍��E�E�E���ł�
					}else{
						return;
					}
				case 1:
					rl_ligh(0,0,0,0);
					if(_FL_ACTION&_JAC){	/* �i�`�b������ */
						pad_stop_oshitekure(10);	//10:�i�`�b�Q�[�����������܂�
						rep_no=99;
						rep_step[mode]=2;
					}else{
						if(_FL_ACTION&(0x01<<BT_BB)){	/* �r�b�O�I���H */
							switch(rep_no){
								case 0:
								//	pad_stop_oshitekure(1);	//  1:�菇�ɏ]���ă��v���C�͂����̗��K�����܂��傤
								//	pad_stop_oshitekure(2);	//  2:�Q��ڂ̂i�`�b�Q�[���܂ł͏�����_���܂�
								//	if(!MACINE)	pad_stop_oshitekure(3);	//  3:�������͍��E���E�E�ł�
								//	else		pad_stop_oshitekure(4);	//  4:�������͍��E�E�E���ł�
								break;
							}
						}else{	/* �a�a�I��� */
							rl_ligh(0,0,0,0);
							call_unlock_resulut();
							while((rackwin[0]!=NULL) || (rackwin[3]!=NULL)) wait(1);
							bb_kitakana=0;
							bb_setting();
						}
					}
				break;
				case 2:	/* �i�`�b���ҋ@ */
					if(!(_FL_ACTION&_JAC)){	/* �i�`�b�I�� */
						if((1<_NB_COUNT_LED2) && (_NB_COUNT_LED2<4)){	/* �܂��]�͂��� */
							rep_step[mode]=1;
							rep_no=0;
						//	pad_stop_oshitekure(1);	//  1:�菇�ɏ]���ă��v���C�͂����̗��K�����܂��傤
							pad_stop_oshitekure(2);	//  2:�Q��ڂ̂i�`�b�Q�[���܂ł͏�����_���܂�
							if(!MACINE)	pad_stop_oshitekure(3);	//  3:�������͍��E���E�E�ł�
							else		pad_stop_oshitekure(4);	//  4:�������͍��E�E�E���ł�
						//	replay_master(0);
						}else{
							if(_FL_ACTION&(0x01<<BT_BB)){	/* �r�b�O�I���H */
								if(abunai[MACINE]<_NB_COUNT_LED1){	/* �����ɗ]�T�L�� */
									rep_no=1;
									if(!ran_f){
										ran_f=1;
										if(!MACINE)	pad_stop_oshitekure(12);	//12:���v���C�͂��������܂��������́@�E�E���E���ł�
										else		pad_stop_oshitekure(11);	//11:���v���C�͂��������܂��������́@���E���E�E�ł�
									}
								}else{	/* �s���`�I */
									if(!pan_f){
										pad_stop_oshitekure(13);	//13:�p���N��������邽�߂ɏ���_���ɐ؂�ւ��܂�
										if(!MACINE)	pad_stop_oshitekure(3);	// 3:�������͍��E���E�E�ł�
										else		pad_stop_oshitekure(4);	// 4:�������͍��E�E�E���ł�
										pan_f=1;
									}
									rep_no=2;
								}
							}else{	/* �Q�[���I���f�[�^�\�� */
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
		case  1:	/* ���_���������̏��� */
			if(_NB_PLAY_MEDAL==3){	//	�V�Z���_���R������Ă�
				switch(rep_step[mode]){
					case 0:
						rep_step[mode]+=1;
						switch(rep_no){
							case 0:	/* �ʏ� */
							case 2:	/* �������ƈ�� �V�Z�񐔎c��킸�� */
								if(!MACINE){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(19); //19:�����[���̂P�X�Ԗڂ̌���_���܂�
									rl_ligh(0,19,19,1);
								}else{
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(5); // 5:�����[���̍��������܂��_���܂�
									rl_ligh(0,13,19,1);
								}
							break;
							case 1:	/* �������ƈ�� �V�Z�񐔗]�T�L�� */
								if(!MACINE){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(29); //29:�E���[���̂P�Q�Ԗڂ̂q�d�f��_���܂�
									rl_ligh(2,12,12,1);
								}else{
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(5); // 5:�����[���̍��������܂��_���܂�
									rl_ligh(0,13,19,1);
								}
							break;
						}
					break;
				}
			}
		break;
		case  2:	/* �񓷉�]�� */
			switch(rep_step[2]){
				case 0:
					switch(rep_no){
						case 0:	/* �ʏ� */
						case 2:	/* �������ƈ�� �V�Z�񐔎c��킸�� */
							if(!MACINE){
								if(_WK_REEL[0][0]==0){
									if(atarisou(CHERRY,0)){	/* �`�F���[������H */
										rl_ligh(0,0,0,0);
									//	pad_stop_oshitekure(50); //50:�E�E�����[���͂ǂ��ł������̂œK���Ɏ~�߂܂��傤
										pad_stop_oshitekure(7);	// 7:���E�E���[���͂ǂ��ł������̂œK���Ɏ~�߂܂��傤
										rep_step[2]=99;
									}else{
										rl_ligh(0,0,0,0);
										pad_stop_oshitekure(22);	//22:�����[���̂P�Q�Ԗڂ̂q�d�f��_���܂�
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
								//	pad_stop_oshitekure(7);	// 7:���E�E���[���͂ǂ��ł������̂œK���Ɏ~�߂܂��傤
									pad_stop_oshitekure(50); //50:�E�E�����[���͂ǂ��ł������̂œK���Ɏ~�߂܂��傤
									rep_step[2]=99;
								}else if((_WK_REEL[1][0]==0) || (_WK_REEL[2][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
						case 1:	/* �������ƈ�� �V�Z�񐔗]�T�L�� */
							if(!MACINE){
								if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									pad_stop_oshitekure(22);	//22:�����[���̂P�Q�Ԗڂ̂q�d�f��_���܂�
									rl_ligh(1,12,12,1);
									rep_step[2]=1;
								}else if((_WK_REEL[0][0]==0) || (_WK_REEL[1][0]==0)){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}else{
								if(_WK_REEL[0][0]==0){
									rl_ligh(0,0,0,0);
									if(atarisou(CHERRY,0)){	/* �`�F���[������H */
										pad_stop_oshitekure(7);	// 7:���E�E���[���͂ǂ��ł������̂œK���Ɏ~�߂܂��傤
										rep_step[2]=99;
									}else{
										pad_stop_oshitekure(9);	// 9:�����[���́A�ǂ��ł������̂œK���Ɏ~�߂܂��傤
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
				case 1:	/* �Q�񓷖ڒ�~���̏��� */
					switch(rep_no){
						case 0:	/* �ʏ� */
						case 2:	/* �������ƈ�� �V�Z�񐔎c��킸�� */
							if(!MACINE){
								if(_WK_REEL[1][0]==0){
									rl_ligh(0,0,0,0);
									if(atarisou(KAP_FRUIT1,0)){	/* ���e���p�C */
										pad_stop_oshitekure(27);	//27:�E���[���̂P�O�Ԗڂ̌���_���܂�
										rl_ligh(2,10,10,1);
										rep_step[2]=99;
									}else{
										pad_stop_oshitekure(8);	// 8:�E���[���́A�ǂ��ł������̂œK���Ɏ~�߂܂��傤
										rep_step[2]=99;
									}
								}else if(_WK_REEL[2][0]==0){
									rl_ligh(0,0,0,0);
									rep_step[2]=99;
								}
							}
						break;
						case 1:	/* �������ƈ�� �V�Z�񐔗]�T�L�� */
							if(!MACINE){
								if(_WK_REEL[1][0]==0){
									rl_ligh(0,0,0,0);
									/* �ӉZ �� */
									if(atarisou((KAP_FRUIT),0)){ /* �������[�`�H */
										pad_stop_oshitekure(17);	//17:�����[���̂P�R�Ԗڂ̂��イ���_���܂�
										rl_ligh(0,13,13,1);
									}else	if(atarisou(KAP_RB,1)){ /* �i�`�b��*/
										pad_stop_oshitekure(20);	//20:�����[���̂P�S�Ԗڂ̎����P�R�Ԗڂ̂��イ���_���܂�
										rl_ligh(0,13,14,1);
									}else	if(atarisou(KAP_RB,2)){ /* �i�`�b�E��*/
										pad_stop_oshitekure(15);	//15:�����[���̂P�O�Ԗڂ̂Ђ傤�����_���܂�
										rl_ligh(0,10,10,1);
									}else	if(atarisou(KAP_RB,3)){ /* �i�`�b�E��*/
										pad_stop_oshitekure(18);	//18:�����[���̂P�T�Ԗڂ̂��イ���_���܂�
										rl_ligh(0,15,15,1);
									}else{	/* ����ȊO */
										pad_stop_oshitekure(21);	//21:�����[���̂P�O�Ԗڂ̂Ђ傤���񂩔Ԗڂ̂Ђ傤�����_���܂�
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
									if(atarisou(BIN_SRB|BIN_FRUIT2,0)){	/* ���ƃe���p�C */
										pad_stop_oshitekure(6);	// 6:�E���[���̐Ԃ������܂��_���܂�
										rl_ligh(2,6,7,1);
										rep_step[2]=2;
									}else{
										pad_stop_oshitekure(8);	// 8:�E���[���́A�ǂ��ł������̂œK���Ɏ~�߂܂��傤
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
						case 0:	/* �ʏ� */
						case 2:	/* �������ƈ�� �V�Z�񐔎c��킸�� */
						break;
						case 1:	/* �������ƈ�� �V�Z�񐔗]�T�L�� */
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