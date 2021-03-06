
#ifndef _KAPPA_H_

#define _KAPPA_H_

//EIGHT_PORT	IN0_PORT;	//EQU	080H		; ���̓|�[�g�@�O
//;BIT 0		�P�������{�^���X�C�b�`	 	 	H
//;    1		�Q�������{�^���X�C�b�` 	 	 	H
//;    2		�R�������{�^���X�C�b�`		 	H
//;    3		�V�Z���_�����o�Z���T�[�M��	 	H
//;    4		���Z�{�^���X�C�b�`		 	H
//;    5		�񓷉�]�n�����u�X�C�b�`	 	H
//;    6		�ݒ�p�L�[�X�C�b�`		 	H
//;    7		�Ŏ~�����X�C�b�`		 	H
//EIGHT_PORT	IN1_PORT;	//EQU	081H		; ���̓|�[�g�@�P
//;BIT 0		�������ߐؑփX�C�b�`		 	H
//;    1		�G���[�����X�C�b�`		 	H
//;    2		�Ŏ~�ؑփX�C�b�`		 	H
//;    3		�ݒ�{�^���X�C�b�`		 	H
//;    4		�V�Z���_�������Z���T�[�P�i��j	 	L
//;    5		�V�Z���_�������Z���T�[�Q�i��j	 	L
//;    6		���g�p				 	NC
//;    7		�O���Ŏ~�߉����M��		 	L
//EIGHT_PORT	IN2_PORT;	//EQU	082H		; ���̓|�[�g�@�Q
//;BIT 0		��P�񓷃Z���T�[		 	L
//;    1		��Q�񓷃Z���T�[		 	L
//;    2		��R�񓷃Z���T�[		 	L
//;    3		���g�p                    	NC
//;    4		���g�p				 	NC
//;    5		�{�̒�~�{�^����P��		 	L
//;    6		�{�̒�~�{�^����Q��		 	L
//;    7		�{�̒�~�{�^����R��		 	L
//EIGHT_PORT	IN3_PORT;	//EQU	083H		; ���̓|�[�g�@�R
//;BIT 0�`7	�n�[�h�E�F�A�����P�i���ʌ��j	 	H

//EIGHT_PORT	OUT0_PORT;	//EQU	080H	; �o�̓|�[�g�@�O
//;BIT 0		��P�񓷃��[�^�[�ӂR		 	H
//;    1		��P�񓷃��[�^�[�ӂQ		 	H
//;    2		��P�񓷃��[�^�[�ӂP		 	H
//;    3		��P�񓷃��[�^�[�ӂO		 	H
//;    4		�V�Z���_�������M��			H
//;    5		�V�Z���_�����o�M��      		H
//;    6		�𕨘A���쓮���u�{������M��		H
//;    7		�𕨘A���쓮�������u�{������M��	H
//EIGHT_PORT	OUT3_PORT;	//EQU	083H	; �o�̓|�[�g�@�R
//;BIT 0		��Q�񓷃��[�^�[�ӂR		 	H
//;    1		��Q�񓷃��[�^�[�ӂQ		 	H
//;    2		��Q�񓷃��[�^�[�ӂP		 	H
//;    3		��Q�񓷃��[�^�[�ӂO		 	H
//;    4		�V�Z���_���u���b�J�[		 	H
//;    5		�E�G�C�g�\�������v		 	H
//;    6		���g�p				 	NC
//;    7		�V�Z���_�����o���u�쓮�M��	 	H
//EIGHT_PORT	OUT4_PORT;	//EQU	084H	; �o�̓|�[�g�@�S
//;BIT 0		��R�񓷃��[�^�[�ӂR		 	H
//;    1		��R�񓷃��[�^�[�ӂQ		 	H
//;    2		��R�񓷃��[�^�[�ӂP		 	H
//;    3		��R�񓷃��[�^�[�ӂO		 	H
//;    4		�ėV�Z�\�������v				H
//;    5		�V�Z��ԕ\�������v�P			H
//;    6		�V�Z��ԕ\�������v�Q			H
//;    7		�V�Z��ԕ\�������v�R			H
//EIGHT_PORT	OUT8_PORT;	//EQU	088H	; �o�̓|�[�g�@�W
//;BIT 0		�k�d�c�Z�O�����g��		 	H
//;    1		�k�d�c�Z�O�����g��		 	H
//;    2		�k�d�c�Z�O�����g��		 	H
//;    3		�k�d�c�Z�O�����g��		 	H
//;    4		�k�d�c�Z�O�����g��		 	H
//;    5		�k�d�c�Z�O�����g��		 	H
//;    6		�k�d�c�Z�O�����g��		 	H
//;    7		�k�d�c�Z�O�����g�o		 	H


#define SD_CLEAR0	1	// ���ʉ��S�`�����l���N���A
#define SD_BBEND	2	// �𕨘A���쓮�������u�쓮�I����
#define SD_START	3	// �񓷉�]�J�n��
//
#define SD_INCO		4	 //�V�Z���_��������
#define SD_STOP		5	 //�񓷒�~��t��
#define SD_R_STOP	6	 //�񓷒�~��
#define SD_WAIT		7	 //�񓷉�]�s��
#define SD_PAY		8	 //�V�Z���_�����o��
//
#define SD_CLEAR1	9	 //���ʉ��T�`�����l���N���A
#define SD_WBL		10	 //�𕨘A���쓮���u�E�𕨘A���쓮�������u���܊��҉�
#define SD_REPLAY	11	 //�ėV�Z�쓮��
#define SD_BB		12	 //�𕨘A���쓮�������u�쓮��
#define SD_RB		13	 //�𕨘A���쓮���u�쓮��
//
#define SD_BBHIT1	14	 //�𕨘A���쓮�������u���܉��P
#define SD_BBHIT2	15	 //�𕨘A���쓮�������u���܉��Q
#define SD_ALARM	16	 //����ُ�x��

void slot_main(void);

#endif

