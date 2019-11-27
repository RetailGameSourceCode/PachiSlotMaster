//	PAGE 80
//	TITLE	[ �����ݶл� ]
//;	*********************************************************
//;	*	�T�~�[�������					*
//;	*		�񓷎��V�Z�@�@���C���b�o�t�v���O����	*
//;	*							*
//;	*		�^�����F�r���r���J�~�T�}		*
//;	*********************************************************
//;
//; �w�𕨘A���쓮�������u�쓮���y�і𕨘A���쓮���u�쓮���x���w�{�[�i�X�Q�[���x�Ɨ��L���܂��B
//; �w�𕨘A���쓮�������u�x���w�a�a�x�Ɨ��L���Ă���ꍇ������܂��B
//; �w�𕨘A���쓮���u�x���w�q�a�x�Ɨ��L���Ă���ꍇ������܂��B
//; �w�㕔�����v�E���ʃ����v�E�o�b�N�����v�x���w�e�탉���v�x�Ɨ��L���܂��B
//;
//;	*************************************************
//;	*	�q�`�l�A�h���X��`			*
//;	*************************************************
//;
//@RAM		EQU	8000H 		; �q�`�l�̈�̐擪
//@STACK		EQU	8200H		; �X�^�b�N�|�C���^
//@STACK1		EQU	8180H		; ���X�^�b�N�|�C���^
//
//;	*************************************************
//;	*	���̓|�[�g�A�h���X��`			*
//;	*************************************************
//;
//@IN0_PORT	EQU	080H		; ���̓|�[�g�@�O
//@IN1_PORT	EQU	081H		; ���̓|�[�g�@�P
//@IN2_PORT	EQU	082H		; ���̓|�[�g�@�Q
//@IN3_PORT	EQU	083H		; ���̓|�[�g�@�R
//;@IN4_PORT	EQU	084H		; ���̓|�[�g�@�S
//;@IN5_PORT	EQU	085H		; ���̓|�[�g�@�T
//;@IN6_PORT	EQU	086H		; ���̓|�[�g�@�U
//
//;	*************************************************
//;	*	�o�̓|�[�g�A�h���X��`			*
//;	*************************************************
//;
//@OUT0_PORT	EQU	080H		; �o�̓|�[�g�@�O
//;@OUT1_PORT	EQU	081H		; �o�̓|�[�g�@�P
//;@OUT2_PORT	EQU	082H		; �o�̓|�[�g�@�Q
//@OUT3_PORT	EQU	083H		; �o�̓|�[�g�@�R
//@OUT4_PORT	EQU	084H		; �o�̓|�[�g�@�S
//;@OUT5_PORT	EQU	085H		; �o�̓|�[�g�@�T
//;@OUT6_PORT	EQU	086H		; �o�̓|�[�g�@�U
//;@OUT7_PORT	EQU	087H		; �o�̓|�[�g�@�V
//@OUT8_PORT	EQU	088H		; �o�̓|�[�g�@�W
//
//@SOUND_PORT	EQU	0FF18H		; ���ʉ��ԍ��@�o�̓|�[�g
//
//;	*************************************************
//;	*	�V�Z��Ԓ�`				*
//;	*************************************************
//;
//@_RP		EQU	00000001B	; �ėV�Z�쓮��
//@BT_RP		EQU	0		; �ėV�Z�쓮���i�r�b�g�ԍ��j
//
//@_RB		EQU	00000010B	; �𕨘A���쓮���u�쓮��
//@BT_RB		EQU	1		; �𕨘A���쓮���u�쓮���i�r�b�g�ԍ��j
//
//@_BB		EQU	00000100B	; �𕨘A���쓮�������u�쓮��
//@BT_BB		EQU	2		; �𕨘A���쓮�������u�쓮���i�r�b�g�ԍ��j
//
//@_BB1		EQU	00001000B	; (���ݥ���ݥ����)���܂ɂ��
//					;;�𕨘A���쓮�������u�쓮��
//@BT_BB1		EQU	3		; (���ݥ���ݥ����)���܂ɂ��
//					;;�𕨘A���쓮�������u�쓮���i�r�b�g�ԍ��j
//
//@_BB2		EQU	00010000B	; (���̐_����̐_����̐_)���܂ɂ��
//					;;�𕨘A���쓮�������u�쓮��
//;@BT_BB2		EQU	4		; (���̐_����̐_����̐_)���܂ɂ��
//					;;�𕨘A���쓮�������u�쓮���i�r�b�g�ԍ��j
//
//@_BNS		EQU	00000110B	; �{�[�i�X�Q�[��
//
//@_JAC		EQU	00000010B	; �𕨗V�Z��
//
//	PAGE
//;	*************************************************
//;	*	���܉񐔁E�V�Z�񐔒�`			*
//;	*************************************************
//;
//@J_WIN		EQU	8		; �𕨘A���쓮���u�쓮���̖𕨓��܉�
//@J_MAX		EQU	12		; �𕨘A���쓮���u�쓮���̖𕨗V�Z��
//@B_WIN		EQU	3		; �𕨘A���쓮�������u�쓮����
//					;;�𕨘A���쓮���u���܉�
//@B_MAX		EQU	30		; �𕨘A���쓮�������u�쓮����
//					;;��ʗV�Z��
//
//@BBCHG		EQU	6		; �𕨘A���쓮�������u�쓮���̌��ʉ��؂�ւ��V�Z��
//
//;	*************************************************
//;	*	�^�C�}��`				*
//;	*************************************************
//;
//
//; �����v�_�ŗp
//
//@TM_LP105	EQU	56		; 105.0336 ms
//
//; �O���M���o�͗p
//
//@TM_COUNT	EQU	54		; 101.2824 ms
//
//; �ėV�Z�쓮�ɂ��V�Z���_�����������p
//
//@TM_REPLAY1	EQU	280		; 525.1680 ms
//@TM_REPLAY2	EQU	56		; 105.0336 ms
//
//; �����{�^������ɂ��V�Z���_�����������p
//
//@TM_BET_IN	EQU	56		; 105.0336 ms
//
//; �V�Z�ҋ@���̕\���ҋ@�p
//
//@TM_BACK_OFF	EQU	31990		; 60000.4440 ms
//
//; �񓷒�~��t�҂��p
//
//@TM_STOPWAIT	EQU	108		; 202.5648 ms
//
//; �񓷎�����~�p
//
//@TM_AUTOSTOP	EQU	31990		; 60000.4440 ms
//
//; �P��̗V�Z���ԊǗ��p
//
//@TM_GAME	EQU	2187		; 4101.9372 ms
//
//; �V�Z���_�������Z���T�[�p
//
//@TM_INSERT1	EQU	82		; 153.7992 ms
//@TM_INSERT2	EQU	27		;  50.6412 ms
//@TM_INSERT3	EQU	82		; 153.7992 ms
//
//; �V�Z���_�����o���u����p
//
//@TM_HOPPER1	EQU	100		;   187.5600 ms
//@TM_HOPPER2	EQU	94		;   176.3064 ms
//@TM_HOPPER3	EQU	5332		; 10000.6992 ms
//
//; �V�Z���_�������������Z�p
//
//@TM_CREDIT	EQU	38		; 71.2728 ms
//
//; �O���Ŏ~�߉����M���p
//
//@TM_RESET	EQU	23		; 43.1388 ms
//
//; �V�Z���_�����o�Z���T�[�`�F�b�N�p
//
//@TM_HOPPER4	EQU	7		; 13.1292 ms
//
//	PAGE
//;	*************************************************
//;	*	���̓|�[�g��`				*
//;	*************************************************
//;
//
//; ���̓|�[�g�O (@IN0_PORT)		�@�@�@	     ACTIVE
//;BIT 0		�P�������{�^���X�C�b�`	 	 	H
//;    1		�Q�������{�^���X�C�b�` 	 	 	H
//;    2		�R�������{�^���X�C�b�`		 	H
//;    3		�V�Z���_�����o�Z���T�[�M��	 	H
//;    4		���Z�{�^���X�C�b�`		 	H
//;    5		�񓷉�]�n�����u�X�C�b�`	 	H
//;    6		�ݒ�p�L�[�X�C�b�`		 	H
//;    7		�Ŏ~�����X�C�b�`		 	H
//
//@IN0_POSI	EQU	11111111B	; ���̓|�[�g�O���_���r�b�g
//
//; ���̓|�[�g�P (@IN1_PORT)		�@�@�@	     ACTIVE
//;BIT 0		�������ߐؑփX�C�b�`		 	H
//;    1		�G���[�����X�C�b�`		 	H
//;    2		�Ŏ~�ؑփX�C�b�`		 	H
//;    3		�ݒ�{�^���X�C�b�`		 	H
//;    4		�V�Z���_�������Z���T�[�P�i��j	 	L
//;    5		�V�Z���_�������Z���T�[�Q�i��j	 	L
//;    6		���g�p				 	NC
//;    7		�O���Ŏ~�߉����M��		 	L
//
//@IN1_POSI	EQU	00001111B	; ���̓|�[�g�P���_���r�b�g
//
//; ���̓|�[�g�Q (@IN2_PORT)		�@�@�@	     ACTIVE
//;BIT 0		��P�񓷃Z���T�[		 	L
//;    1		��Q�񓷃Z���T�[		 	L
//;    2		��R�񓷃Z���T�[		 	L
//;    3		���g�p                    	 	NC
//;    4		���g�p				 	NC
//;    5		�{�̒�~�{�^����P��		 	L
//;    6		�{�̒�~�{�^����Q��		 	L
//;    7		�{�̒�~�{�^����R��		 	L
//
//@IN2_POSI	EQU	00000000B	; ���̓|�[�g�Q���_���r�b�g
//
//; ���̓|�[�g�R (@IN3_PORT)		�@�@�@	     ACTIVE
//;BIT 0�`7	�n�[�h�E�F�A�����P�i���ʌ��j	 	H
//
//; ���̓|�[�g�S (@IN4_PORT)		�@�@�@	     ACTIVE
//;BIT 0�`5	�n�[�h�E�F�A�����P�i��ʌ��j	 	H
//;    6		���g�p�i�O�ɌŒ�j		 	NC
//;    7		���g�p�i�O�ɌŒ�j		 	NC
//
//; ���̓|�[�g�T (@IN5_PORT)		�@�@�@	     ACTIVE
//;BIT 0�`7	�n�[�h�E�F�A�����Q�i���ʌ��j	 	H
//
//; ���̓|�[�g�U (@IN6_PORT)		�@�@�@	     ACTIVE
//;BIT 0�`5	�n�[�h�E�F�A�����Q�i��ʌ��j		H
//;    6		���g�p�i�O�ɌŒ�j			NC
//;    7		���g�p�i�O�ɌŒ�j		 	NC
//
//	PAGE
//;	*************************************************
//;	*    �o�̓|�[�g��`				*
//;	*************************************************
//;
//
//; �o�̓|�[�g�O (@OUT0_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		��P�񓷃��[�^�[�ӂR		 	H
//;    1		��P�񓷃��[�^�[�ӂQ		 	H
//;    2		��P�񓷃��[�^�[�ӂP		 	H
//;    3		��P�񓷃��[�^�[�ӂO		 	H
//;    4		�V�Z���_�������M��			H
//;    5		�V�Z���_�����o�M��      		H
//;    6		�𕨘A���쓮���u�{������M��		H
//;    7		�𕨘A���쓮�������u�{������M��	H
//
//; �o�̓|�[�g�P (@OUT1_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		��Q�񓷃��[�^�[�ӂR		 	H
//;    1		��Q�񓷃��[�^�[�ӂQ		 	H
//;    2		��Q�񓷃��[�^�[�ӂP		 	H
//;    3		��Q�񓷃��[�^�[�ӂO		 	H
//;    4		�V�Z���_���u���b�J�[		 	H
//;    5		�E�G�C�g�\�������v		 	H
//;    6		���g�p				 	NC
//;    7		�V�Z���_�����o���u�쓮�M��	 	H
//
//; �o�̓|�[�g�Q (@OUT2_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		��R�񓷃��[�^�[�ӂR		 	H
//;    1		��R�񓷃��[�^�[�ӂQ		 	H
//;    2		��R�񓷃��[�^�[�ӂP		 	H
//;    3		��R�񓷃��[�^�[�ӂO		 	H
//;    4		�ėV�Z�\�������v	         	H
//;    5		�V�Z��ԕ\�������v�P 		      	H
//;    6		�V�Z��ԕ\�������v�Q		       	H
//;    7		�V�Z��ԕ\�������v�R		       	H
//
//; �o�̓|�[�g�R (@OUT3_PORT) : @OUT4_PORT BIT0~5 ON   ACTIVE
//;BIT 0		�k�d�c�Z�O�����g��		 	H
//;    1		�k�d�c�Z�O�����g��		 	H
//;    2		�k�d�c�Z�O�����g��		 	H
//;    3		�k�d�c�Z�O�����g��		 	H
//;    4		�k�d�c�Z�O�����g��		 	H
//;    5		�k�d�c�Z�O�����g��		 	H
//;    6		�k�d�c�Z�O�����g��		 	H
//;    7		�k�d�c�Z�O�����g�o		 	H
//;
//
//	PAGE
//; �o�̓|�[�g�S (@OUT4_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		�k�d�c�f�W�b�g�P		 	H
//;		�i�V�Z���_�����o�����\���k�d�c���ʌ��j
//;    1		�k�d�c�f�W�b�g�Q                 	H
//;		�i�V�Z���_�����o�����\���k�d�c��ʌ��j
//;    2		�k�d�c�f�W�b�g�R	         	H
//;		�i�V�Z���_�����������\���k�d�c���ʌ��j
//;    3		�k�d�c�f�W�b�g�S		       	H
//;		�i�V�Z���_�����������\���k�d�c��ʌ��j
//;    4		�k�d�c�f�W�b�g�T		  	H
//;		�i�񐔕\���k�d�c�P���ʌ��j
//;    5		�k�d�c�f�W�b�g�U		 	H
//;		�i�񐔕\���k�d�c�P��ʌ��j
//;    6		�k�d�c�f�W�b�g�V		 	H
//;		�i�񐔕\���k�d�c�Q�j
//;    7		�T�E���h�f�[�^���b�`		 	H
//
//; �o�̓|�[�g�T (@OUT5_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		�L�����C�������v�P 			H
//;		�i��T���C���^�E�オ��j
//;    1		�L�����C�������v�Q			H
//;		�i��R���C���^���i�j
//;    2		�L�����C�������v�R 			H
//;		�i��P���C���^�����j
//;    3		�L�����C�������v�S 		 	H
//;		�i��Q���C���^��i�j
//;    4		�L�����C�������v�T		 	H
//;		�i��S���C���^�E������j
//;    5		���ʃ����v�P�i���j		       	H
//;    6		���ʃ����v�Q�i���j		       	H
//;    7		���ʃ����v�R�i�E�j		       	H
//
//; �o�̓|�[�g�U (@OUT6_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		�㕔�����v�P�i���[�j		 	H
//;    1		�㕔�����v�Q		 	 	H
//;    2		�㕔�����v�R		 	 	H
//;    3		�㕔�����v�S		 	 	H
//;    4		�㕔�����v�T		 	 	H
//;    5		�㕔�����v�U		 	 	H
//;    6		�㕔�����v�V		 	 	H
//;    7		�㕔�����v�W�i�E�[�j	 	 	H
//
//; �o�̓|�[�g�V (@OUT7_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		��~�{�^���k�d�c�P�i�ԁj	 	H
//;    1		��~�{�^���k�d�c�Q�i�ԁj 	 	H
//;    2		��~�{�^���k�d�c�R�i�ԁj 		H
//;    3		��~�{�^���k�d�c�S�i�΁j 		H
//;    4		��~�{�^���k�d�c�T�i�΁j 		H
//;    5		��~�{�^���k�d�c�U�i�΁j 		H
//;    6		�V�Z���_�������\�������v 	 	H
//;    7		�o�b�N�����v�X�i��R�񓷏�j		H
//
//; �o�̓|�[�g�W (@OUT8_PORT)		�@�@�@�@�@�@ ACTIVE
//;BIT 0		�o�b�N�����v�P�i��P�񓷉��j 		H
//;    1		�o�b�N�����v�Q�i��P�񓷒��j 		H
//;    2		�o�b�N�����v�R�i��P�񓷏�j		H
//;    3		�o�b�N�����v�S�i��Q�񓷉��j		H
//;    4		�o�b�N�����v�T�i��Q�񓷒��j		H
//;    5		�o�b�N�����v�U�i��Q�񓷏�j		H
//;    6		�o�b�N�����v�V�i��R�񓷉��j	 	H
//;    7		�o�b�N�����v�W�i��R�񓷒��j		H
//
//	PAGE
//	ORG	0000H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0300-001					*
//;*	�@�\	      : �v���O�����J�n					*
//;*	Ӽޭ�ٖ�      : M_PRG_START					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : MS_RAM_CHK,MS_PCT_ON,MS_RANK_SET		*
//;*		      : M_POWER_ON�i�W�����v�j,MS_RKER_CHK,MS_BB_SET	*
//;*		      : M_MAIN�i�W�����v�j				*
//;************************************************************************
//;
//M_PRG_START:
//	LD	SP,@STACK1		; ���X�^�b�N�|�C���^  �Z�b�g
//	IM	0			; ���荞�݃��[�h�O  �Z�b�g
//	JP	M_PRG_START1		; <����>
//
//	ORG	0008H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0303-001					*
//;*	�@�\	      : ���[�N�E�e�[�u���̃A�h���X�Z�b�g		*
//;*	Ӽޭ�ٖ�      : S_ADDR_SET					*
//;*	�������Ұ�    : HL = ���[�N�E�e�[�u���̃A�h���X			*
//;*		      : A  = �I�t�Z�b�g					*
//;*	�o�����Ұ�    :	HL = HL + A					*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,HL						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//S_ADDR_SET:
//	ADD	A,L
//	LD	L,A			; �k���W�X�^�ɂ`���W�X�^�����Z
//	RET	NC			; �L�����[����H�D�D�m�n
//
//	INC	H			; �g���W�X�^�ɂP���Z
//
//	RET
//
//	DEFS	3			; // ���g�p
//
//	PAGE
//	ORG	0010H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0304-001					*
//;*	�@�\	      : ���̓|�[�g�O���x���`�F�b�N			*
//;*	Ӽޭ�ٖ�      : S_IN0_CHK					*
//;*	�������Ұ�    : B = �`�F�b�N����				*
//;*	�o�����Ұ�    :	Zflag OFF = ���͂���				*
//;*		      : A = ���̓r�b�g					*
//;*		      : Cflag OFF					*
//;*	�ی�ڼ޽�     :	B						*
//;*	�j��ڼ޽�     :	A						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//S_IN0_CHK:
//	LD	A,(_PT_IN0_OLD)
//	AND	B			; ���̓|�[�g�O���x���`�F�b�N
//
//	RET
//
//	DEFS	3			; // ���g�p
//
//	ORG	0018H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0305-001					*
//;*	�@�\	      : �q�`�l������					*
//;*	Ӽޭ�ٖ�      : S_RAM_CLEAR					*
//;*	�������Ұ�    : HL = �q�`�l�������e�[�u��			*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//S_RAM_CLEAR:
//	LD	E,(HL)
//	INC	HL
//	LD	D,(HL)			; �q�`�l�������擪�A�h���X�@�Z�b�g
//	INC	HL
//
//	LD	B,(HL)			; �q�`�l�������͈͉��ʌ��@�Z�b�g
//	INC	HL
//
//	JR	S_RAM_CLEAR1		; <����>
//
//	PAGE
//	ORG	0020H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0306-001					*
//;*	�@�\	      : �V�Z���_���u���b�J�[�n�e�e			*
//;*	Ӽޭ�ٖ�      : S_BLOCKER_OFF					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	HL						*
//;*	�j��ڼ޽�     :							*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//S_BLOCKER_OFF:
//	PUSH	HL
//	LD	HL,_PT_OUT1		; �V�Z���_���u���b�J�[  �n�e�e <�ԋp���>
//	RES	4,(HL)
//	JR	S_BLOCKER_OFF1		; <����>
//
//	ORG	0028H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0307-001					*
//;*	�@�\	      : �V�Z���_���u���b�J�[�n�m			*
//;*	Ӽޭ�ٖ�      : S_BLOCKER_ON					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	HL						*
//;*	�j��ڼ޽�     :							*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//S_BLOCKER_ON:
//	PUSH	HL
//	LD	HL,_PT_OUT1		; �V�Z���_���u���b�J�[  �n�m <�ʉߏ��>
//	SET	4,(HL)
//	JR	S_BLOCKER_ON1		; <����>
//
//	PAGE
//	ORG	0030H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0308-001					*
//;*	�@�\	      : �E�H�b�`�h�b�O�N���A				*
//;*	Ӽޭ�ٖ�      : S_WATCH_CLEAR					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	HL						*
//;*	�j��ڼ޽�     :							*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//S_WATCH_CLEAR:
//	PUSH	HL
//	LD	HL,0FF22H
//	LD	(HL),0			; �E�H�b�`�h�b�O��~
//	JR	S_WATCH_CLEAR1		; <����>
//
//	ORG	0038H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0309-001					*
//;*	�@�\	      : �e�탉���v�E���ʉ��f�[�^�Z�b�g�P		*
//;*	Ӽޭ�ٖ�      : S_LPSD_SET					*
//;*	�������Ұ�    : �iA = �e�탉���v�E���ʉ��o�͗v���j		*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	BC,DE,HL					*
//;*	�j��ڼ޽�     :							*
//;*	�g�pӼޭ��    : SS_LPSD_SET					*
//;************************************************************************
//;
//S_LPSD_SET:
//	PUSH	HL
//	PUSH	DE
//	PUSH	BC
//
//	DI				; ���荞�݋֎~
//
//	CALL	SS_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�Q
//
//	EI				; ���荞�݋���
//
//	POP	BC
//	POP	DE
//	POP	HL
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0305-001					*
//;*	�@�\	      : �q�`�l������  �i�����j				*
//;*	Ӽޭ�ٖ�      : S_RAM_CLEAR					*
//;************************************************************************
//;
//S_RAM_CLEAR1:
//	LD	C,(HL)			; �q�`�l�������͈͏�ʌ��@�Z�b�g
//
//	LD	A,B
//	AND	A			; �q�`�l�������͈͉��ʌ����O�H
//	JR	Z,S_RAM_CLEAR2		;   �x�d�r
//
//	INC	C			; �q�`�l�������͈͏�ʌ��@�{�P
//
//	XOR	A
//S_RAM_CLEAR2:
//	LD	(DE),A			; �q�`�l������
//	INC	DE			; ���̂q�`�l�A�h���X�@�Z�b�g
//	DJNZ	S_RAM_CLEAR2		; �Q�T�U�o�C�g���I���H�D�D�m�n
//
//	DEC	C			; �S�o�C�g�I���H
//	JR	NZ,S_RAM_CLEAR2		;   �m�n
//
//	RET
//
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0306-001					*
//;*	�@�\	      : �V�Z���_���u���b�J�[�n�e�e  �i�����j		*
//;*	Ӽޭ�ٖ�      : S_BLOCKER_OFF					*
//;************************************************************************
//;
//S_BLOCKER_OFF1:
//	LD	L,LOW _PT_OUT7
//	RES	6,(HL)			; �V�Z���_�������\�������v�����@�Z�b�g
//	POP	HL
//
//	RET
//
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0307-001					*
//;*	�@�\	      : �V�Z���_���u���b�J�[�n�m  �i�����j		*
//;*	Ӽޭ�ٖ�      : S_BLOCKER_ON					*
//;************************************************************************
//;
//S_BLOCKER_ON1:
//	LD	L,LOW _PT_OUT7
//	SET	6,(HL)			; �V�Z���_�������\�������v�_���@�Z�b�g
//	POP	HL
//
//	RET
//
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0308-001					*
//;*	�@�\	      : �E�H�b�`�h�b�O�N���A  �i�����j			*
//;*	Ӽޭ�ٖ�      : S_WATCH_CLEAR					*
//;************************************************************************
//;
//S_WATCH_CLEAR1:
//	LD	(HL),80H		; �E�H�b�`�h�b�O�N��
//	POP	HL
//
//	RET
//
//	DEFS	3			; // ���g�p
//
//	PAGE
//	ORG	0066H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0310-001					*
//;*	�@�\	      : �d�f����					*
//;*			�i�m�l�h�j					*
//;*	Ӽޭ�ٖ�      : N_POWER_DOWN					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	A,BC,DE,HL,BC',DE',HL'				*
//;*	�j��ڼ޽�     :							*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//N_POWER_DOWN:
//	PUSH	AF			; �`�e���W�X�^�ޔ�
//
//	XOR	A
//	LD	(0FF22H),A		; �E�H�b�`�h�b�O��~
//	LD	(0FF30H),A		; ���荞�ݒ�~
//
//	LD	A,I			; �d�f���̊��荞�݋֎~�^����ԁ@�ۑ�
//	PUSH	AF			; // �e���W�@BIT2 ON   ���荞�݋���
//					; //              OFF  ���荞�݋֎~
//	PUSH	BC
//	PUSH	DE
//	PUSH	HL
//	EXX
//	PUSH	BC
//	PUSH	DE
//	PUSH	HL			; �g�p���W�X�^�ޔ��i�`�e���W�X�^�ȊO�j
//
//	LD	(_BF_STACK),SP		; �X�^�b�N�|�C���^�ۑ�
//
//	LD	HL,_FL_GAME_STS
//	SET	6,(HL)			; �d�f�����ς݃t���O�@�Z�b�g
//
//	XOR	A
//	LD	DE,_WK_SUM_CHK
//	LD	(DE),A			; �`�F�b�N�T���@�N���A
//
//	LD	HL,@RAM
//	LD	BC,2
//N_POWER_DOWN1:
//	ADD	A,(HL)			; �q�`�l�`�F�b�N�T���Z�o
//	INC	HL			;;(8000H - 81FFH)
//	DJNZ	N_POWER_DOWN1		; �Q�T�U�o�C�g�Z�o�I���H�D�D�m�n
//
//	DEC	C			; �S�o�C�g�Z�o�I���H
//	JR	NZ,N_POWER_DOWN1	;   �m�n
//
//	NEG				; �Q�̕␔�f�[�^�ɂ���
//					;;�i���Z��O�ɂȂ�l�j
//	LD	(DE),A			; �`�F�b�N�T���@�Z�b�g
//
//	LD	A,1
//	LD	(0FF14H),A		; �q�`�l�������݋֎~
//
//N_POWER_DOWN2:
//	JR	N_POWER_DOWN2		; ���Z�b�g�҂�
//
//	DEFS	7			; // ���g�p
//
//	PAGE
//	ORG	00A4H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0311-001					*
//;*	�@�\	      : �E�H�b�`�h�b�O����				*
//;*			�i�o�b�s�O�j					*
//;*	Ӽޭ�ٖ�      : I_WATCH_ERROR					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	E						*
//;*	�g�pӼޭ��    : SS_ERROR_STOP�i�W�����v�j			*
//;************************************************************************
//;
//I_WATCH_ERROR:
//	LD	E,4FH			; �h�d�R�h�\���v��  �Z�b�g
//	JR	SS_ERROR_STOP
//
//	PAGE
//	ORG	00A8H
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0312-001					*
//;*	�@�\	      : ���荞�ݏ���					*
//;*			�i�o�b�s�P�j					*
//;*	Ӽޭ�ٖ�      : I_INTR						*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�ی�ڼ޽�     :	A,BC,DE,HL					*
//;*	�j��ڼ޽�     :							*
//;*	�g�pӼޭ��    : SS_ERROR_STOP�i�W�����v�j,IS_IN_READ		*
//;*		      : IS_TIME_COUNT,S_ADDR_SET,IS_REEL_CTL		*
//;*		      : IS_COUNTER_OUT,IS_LPSD_OUT			*
//;************************************************************************
//;
//I_INTR:
//	PUSH	AF			; ���W�X�^�@�ޔ�
//	PUSH	BC
//	PUSH	DE
//	PUSH	HL
//
//	LD	HL,8
//	ADD	HL,SP
//	LD	E,(HL)
//	INC	HL
//	LD	D,(HL)			; �߂�Ԓn�Z�b�g
//	LD	HL, - PRG_END		; // �v���O�����ŏI�A�h���X  �Z�b�g
//	ADD	HL,DE			; �߂�Ԓn����H
//	JR	NC,I_INTR1		; �@�x�d�r
//
//	LD	E,4FH			; �h�d�R�h�\���v��  �Z�b�g
//	JR	SS_ERROR_STOP
//I_INTR1:
//	CALL	IS_IN_READ		; ���̓|�[�g�O�`�Q�ǂݍ���
//
//	CALL	IS_TIME_COUNT		; �^�C�}�v��
//
//	LD	C,3			; �񓷔ԍ��@�Z�b�g
//I_INTR2:
//	LD	HL,_WK_REEL1 - 8
//	LD	A,C
//	ADD	A,A
//	ADD	A,A
//	ADD	A,A			; �񓷐���f�[�^�q�`�l
//					;;�A�h���X�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	CALL	IS_REEL_CTL		; �񓷋쓮����
//
//	DEC	C			; �S�񓷏I���H
//	JR	NZ,I_INTR2		;   �m�n
//
//	CALL	IS_COUNTER_OUT		; �O���M���o��
//
//	CALL	IS_LPSD_OUT		; �����v�i�k�d�c�j�\���E���ʉ��o��
//
//	LD	HL,_PT_OUT8
//	LD	BC,9*100H OR @OUT8_PORT
//I_INTR3:
//	LD	A,(HL)
//	OUT	(C),A			; �o�̓|�[�g�i�O�`�W�j�o��
//	DEC	HL
//	DEC	C			; ���̏o�̓|�[�g�A�h���X�@�Z�b�g
//	DJNZ	I_INTR3			; �o�͏I���H�D�D�m�n
//
//	POP	HL			; ���W�X�^���A
//	POP	DE
//	POP	BC
//
//	LD	A,1
//	LD	(0FF34H),A		; ���荞�݋���
//
//	POP	AF
//	EI
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0313-001					*
//;*	�@�\	      : ���A�s�\�G���[����				*
//;*	Ӽޭ�ٖ�      : SS_ERROR_STOP					*
//;*	�������Ұ�    : E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	E						*
//;*	�j��ڼ޽�     :	A,BC,D,HL					*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//SS_ERROR_STOP:
//	DI				; ���荞�݋֎~
//
//	XOR	A
//	LD	BC,9*100H OR @OUT0_PORT
//SS_ERROR_STOP1:
//	OUT	(C),A			; �o�̓|�[�g�i�O�`�W�j�n�e�e
//	INC	C			; ���̏o�̓|�[�g�A�h���X�@�Z�b�g
//	DJNZ	SS_ERROR_STOP1		; �o�͏I���H�D�D�m�n
//
//	LD	A,@SD_CLEAR0		; ���ʉ��S����ٸر�v���@�Z�b�g
//	LD	(@SOUND_PORT),A		; ���ʉ��f�[�^�@�o��
//
//	LD	A,10000000B
//	OUT	(@OUT4_PORT),A		; �T�E���h�f�[�^���b�`�@�n�m
//
//	XOR	A
//	OUT	(@OUT4_PORT),A		; �T�E���h�f�[�^���b�`�@�n�e�e
//
//	LD	D,79H			; �G���[�\���i��ʌ��j�@�Z�b�g
//	LD	HL,201H
//	LD	C,@OUT4_PORT
//SS_ERROR_STOP2:
//	OUT	(C),A			; �k�d�c�f�W�b�g  �n�e�e
//
//	DEC	C			; // C = @OUT3_PORT
//	OUT	(C),D			; �G���[��ʌ��\���o��
//
//	INC	C			; // C = @OUT4_PORT
//	OUT	(C),H			; �k�d�c�f�W�b�g�Q  �n�m
//
//SS_ERROR_STOP3:
//	DJNZ	SS_ERROR_STOP3		; �\���E�G�C�g�I���H�D�D�m�n
//
//	OUT	(C),A			; �k�d�c�f�W�b�g  �n�e�e
//
//	DEC	C			; // C = @OUT3_PORT
//	OUT	(C),E			; �G���[���ʌ��\���o��
//
//	INC	C			; // C = @OUT4_PORT
//	OUT	(C),L			; �k�d�c�f�W�b�g�P  �n�m
//
//SS_ERROR_STOP4:
//	DJNZ	SS_ERROR_STOP4		; �\���E�G�C�g�I���H�D�D�m�n
//
//	JR	SS_ERROR_STOP2
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0314-001					*
//;*	�@�\	      : �e�탉���v�E���ʉ��f�[�^�Z�b�g�Q		*
//;*	Ӽޭ�ٖ�      : SS_LPSD_SET					*
//;*	�������Ұ�    : A = �e�탉���v�E���ʉ��o�͗v��			*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,C,DE,HL					*
//;*	�g�pӼޭ��    : S_ADDR_SET,SS_DATA_SET				*
//;************************************************************************
//;
//SS_LPSD_SET:
//	AND	A			; �o�͗v������H
//	RET	Z			;   �m�n
//
//	LD	HL,TBL_LPSD_REQ - 4
//	ADD	A,A			; �e�탉���v�E���ʉ��o�͗v��
//	ADD	A,A			;;�e�[�u���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	EX	DE,HL
//
//	LD	A,(DE)
//	AND	A			; �㕔�����v�o�͗v���H
//	JR	Z,SS_LPSD_SET1		;   �m�n
//
//; �㕔�����v�\������
//
//	LD	HL,TBL_FLASH_DATA - 2	; �㕔�����v�����e�[�u���@�Z�b�g
//	LD	C,LOW _WK_FLASH_LP	; �㕔�����v����f�[�^�q�`�l�A�h���X���ʁ@�Z�b�g
//	CALL	SS_DATA_SET		; �`�����l���f�[�^�Z�b�g
//
//SS_LPSD_SET1:
//	INC	DE
//	LD	A,(DE)
//	AND	A			; ���ʃ����v�o�͗v���H
//	JR	Z,SS_LPSD_SET2		;   �m�n
//
//; ���ʃ����v�\������
//
//	LD	HL,TBL_EFFECT_DATA - 2	; ���ʃ����v�����e�[�u���@�Z�b�g
//	LD	C,LOW _WK_EFFECT_LP	; ���ʃ����v����f�[�^�q�`�l�A�h���X���ʁ@�Z�b�g
//	CALL	SS_DATA_SET		; �`�����l���f�[�^�Z�b�g
//
//SS_LPSD_SET2:
//	INC	DE
//	LD	A,(DE)
//	AND	A			; �o�b�N�����v�o�͗v���H
//	JR	Z,SS_LPSD_SET3		;   �m�n
//
//; �o�b�N�����v�\������
//
//	LD	HL,TBL_BACK_DATA - 2	; �o�b�N�����v�����e�[�u���@�Z�b�g
//	LD	C,LOW _WK_BACK_LP	; �o�b�N�����v����f�[�^�q�`�l�A�h���X���ʁ@�Z�b�g
//	CALL	SS_DATA_SET		; �`�����l���f�[�^�Z�b�g
//
//SS_LPSD_SET3:
//	INC	DE
//	LD	A,(DE)
//	AND	A			; ���ʉ��o�͗v���H
//	RET	Z			;   �m�n
//
//; ���ʉ��o�͏���
//
//	LD	(@SOUND_PORT),A		; ���ʉ��f�[�^�@�o��
//
//	LD	A,(_PT_OUT4)
//	SET	7,A
//	OUT	(@OUT4_PORT),A		; �T�E���h�f�[�^���b�`�@�n�m
//
//	RES	7,A
//	OUT	(@OUT4_PORT),A		; �T�E���h�f�[�^���b�`�@�n�e�e
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0315-001					*
//;*	�@�\	      : �`�����l���f�[�^�Z�b�g				*
//;*	Ӽޭ�ٖ�      : SS_DATA_SET					*
//;*	�������Ұ�    :	A = �e�탉���v�f�[�^�ԍ�			*
//;*		      : HL = �e�탉���v�����e�[�u��			*
//;*		      :	C = �e�탉���v����f�[�^�q�`�l�A�h���X����	*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,HL						*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//SS_DATA_SET:
//	LD	B,HIGH @RAM		; <�q�`�l��ʃA�h���X>
//	LD	(BC),A			; �f�[�^�ԍ�  �Z�b�g
//
//	ADD	A,A
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	INC	BC
//	LD	A,1
//	LD	(BC),A			; �����f�[�^�����l�i���P�j  �Z�b�g
//
//	INC	BC
//	LD	A,(HL)
//	LD	(BC),A			; ���s�A�h���X����  �Z�b�g
//
//	INC	BC
//	INC	HL
//	LD	A,(HL)
//	LD	(BC),A			; ���s�A�h���X���  �Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0316-001					*
//;*	�@�\	      : ���̓|�[�g�O�`�Q�ǂݍ���			*
//;*	Ӽޭ�ٖ�      : IS_IN_READ					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	DE						*
//;*	�j��ڼ޽�     :	A,BC,HL						*
//;*	�g�pӼޭ��    : IS_LEVEL_UP					*
//;************************************************************************
//;
//IS_IN_READ:
//	LD	HL,_PT_IN0_OLD
//	LD	BC,@IN0_POSI*100H +@IN0_PORT	; ���̓|�[�g�O���_���r�b�g�f�[�^�E
//						;;���̓|�[�g�O�A�h���X�@�Z�b�g
//	CALL	IS_LEVEL_UP			; ���̓|�[�g���x���f�[�^�E
//						;;�����オ��f�[�^�Z�b�g
//	LD	A,D
//	AND	E
//	LD	(HL),A				; ���̓|�[�g�O
//						;;����������f�[�^�Z�b�g
//	INC	HL
//	LD	B,@IN1_POSI			; ���̓|�[�g�P���_���r�b�g�f�[�^�@�Z�b�g
//	CALL	IS_LEVEL_UP			; ���̓|�[�g���x���f�[�^�E
//						;;�����オ��f�[�^�Z�b�g
//	LD	B,@IN2_POSI			; ���̓|�[�g�Q���_���r�b�g�f�[�^�@�Z�b�g
//	CALL	IS_LEVEL_UP			; ���̓|�[�g���x���f�[�^�E
//						;;�����オ��f�[�^�Z�b�g
//	RET
//
//	PAGE
//;********************************************************************************
//;*	�Ǘ��ԍ�      : S-0317-001						*
//;*	�@�\	      : ���̓|�[�g���x���f�[�^�E�����オ��f�[�^�Z�b�g		*
//;*	Ӽޭ�ٖ�      : IS_LEVEL_UP						*
//;*	�������Ұ�    : B = ���̓|�[�g���_���r�b�g�f�[�^			*
//;*		      : C = ���̓|�[�g�A�h���X					*
//;*		      : HL = ���̓|�[�g�f�[�^�q�`�l�A�h���X			*
//;*	�o�����Ұ�    :	C = ���̓|�[�g�A�h���X					*
//;*		      :	D = �O��̓��̓|�[�g���x���f�[�^			*
//;*		      : E = ����ƑO��̓��̓|�[�g���x���ω��r�b�g�f�[�^	*
//;*		      : HL = ���̓|�[�g�f�[�^�q�`�l�A�h���X			*
//;*	�ی�ڼ޽�     :	B							*
//;*	�j��ڼ޽�     :	A,C,DE,HL						*
//;*	�g�pӼޭ��    : 							*
//;********************************************************************************
//;
//IS_LEVEL_UP:
//	IN	A,(C)
//	LD	D,(HL)			; �O��̓��̓|�[�g���x���f�[�^�@�Z�b�g
//	LD	(HL),A			; ���̓|�[�g���x���f�[�^�@�Z�b�g
//	XOR	D
//	LD	E,A			; ����ƑO��̓��̓|�[�g���x���ω�
//					;;�r�b�g�f�[�^  �Z�b�g
//	LD	A,D
//	XOR	B
//	AND	E
//	INC	HL			; // HL = _PT_IN?_UP
//	LD	(HL),A			; ���̓|�[�g�����オ��
//					;;�f�[�^�@�Z�b�g
//	INC	HL
//	INC	C			; ���̓��̓|�[�g�A�h���X�@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0318-001					*
//;*	�@�\	      : �^�C�}�v��					*
//;*	Ӽޭ�ٖ�      : IS_TIME_COUNT					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,DE,HL					*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//; �Q�o�C�g�^�C�}�v��
//
//IS_TIME_COUNT:
//	LD	HL,_TM2_AUTOSTOP
//	LD	B,@TM2_NUM		; �Q�o�C�g�^�C�}��  �Z�b�g
//IS_TIME_COUNT1:
//	LD	E,(HL)			; �^�C�}�l�ǂݍ���
//	INC	HL
//	LD	D,(HL)
//
//	LD	A,D
//	OR	E			; �^�C�}�l���O�H
//	JR	Z,IS_TIME_COUNT2	; �@�x�d�r
//
//	DEC	DE			; �^�C�}�l�P���Z
//	LD	(HL),D
//	DEC	HL
//	LD	(HL),E
//	INC	HL
//
//IS_TIME_COUNT2:
//	INC	HL			; ���̃^�C�}�A�h���X�@�Z�b�g
//	DJNZ	IS_TIME_COUNT1		; �Q�o�C�g�^�C�}�v���I���H�D�D�m�n
//
//; �P�o�C�g�^�C�}�v��
//
//	LD	B,@TM1_NUM		; �P�o�C�g�^�C�}��  �Z�b�g
//IS_TIME_COUNT3:
//	LD	A,(HL)
//	AND	A			; �^�C�}�l���O�H
//	JR	Z,IS_TIME_COUNT4	; �@�x�d�r
//
//	DEC	(HL)			; �^�C�}�P���Z
//IS_TIME_COUNT4:
//	INC	HL			; ���̃^�C�}�A�h���X�@�Z�b�g
//	DJNZ	IS_TIME_COUNT3		; �P�o�C�g�^�C�}�v���I���H�D�D�m�n
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0319-001					*
//;*	�@�\	      : �񓷋쓮����					*
//;*	Ӽޭ�ٖ�      : IS_REEL_CTL					*
//;*	�������Ұ�    : C = �񓷔ԍ�					*
//;*			HL = �񓷐���f�[�^�q�`�l�A�h���X		*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	C						*
//;*	�j��ڼ޽�     :	A,B,DE,HL					*
//;*	�g�pӼޭ��    : IS_PULSE_OUT,S_ADDR_SET				*
//;************************************************************************
//;
//; # = ���䒆�̉񓷔ԍ� (= 3,2,1)
//;
//IS_REEL_CTL:
//	LD	D,H
//	LD	E,L			; // DE = _WK_REEL# + 0
//
//; ��~���i��ԁ��O�j
//
//	LD	A,(HL)			; // HL = _WK_REEL# + 0
//	AND	A			; ��~���H
//	RET	Z			; �@�x�d�r
//
//; �������i��ԁ��P�j
//
//	DEC	A			; �������H
//	JR	NZ,IS_REEL_CTL2		;   �m�n
//
//	INC	HL			; // HL = _WK_REEL# + 1
//	DEC	(HL)			; �������p���X�J�E���^  �|�P
//	RET	NZ			; �J�E���g�I���H�D�D�m�n
//
//	DEC	HL			; // HL = _WK_REEL# + 0
//	CALL	IS_PULSE_OUT		; �񓷋쓮�p���X�Z�b�g
//
//	INC	HL
//	INC	HL			; // HL = _WK_REEL# + 2
//	DEC	(HL)			; �����J�E���^�@�|�P
//	JR	Z,IS_REEL_CTL1		; �J�E���g�I���H�D�D�x�d�r
//
//	LD	A,(HL)			; // HL = _WK_REEL# + 2
//	LD	HL,TBL_PULSE_UP - 1
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(HL)			; �����J�E���g�l�@���o��
//
//	INC	DE			; // DE = _WK_REEL# + 1
//	LD	(DE),A			; �������p���X�J�E���^�@�Z�b�g
//
//	RET
//
//IS_REEL_CTL1:
//	LD	A,2			; // DE = _WK_REEL# + 0
//	LD	(DE),A			; �葬��ԁ@�Z�b�g
//
//	RET
//
//; �葬���i��ԁ��Q�j
//
//IS_REEL_CTL2:
//	DEC	A			; �葬���H
//	JR	NZ,IS_REEL_CTL5		;   �m�n
//
//	CALL	IS_PULSE_OUT		; �񓷋쓮�p���X�Z�b�g
//
//	LD	A,(_PT_IN2_UP)
//	LD	B,C
//IS_REEL_CTL3:
//	RRCA				; ����񓷂̉񓷃Z���T�[�H
//	DJNZ	IS_REEL_CTL3		;   �m�n
//
//	INC	HL
//	INC	HL
//	INC	HL			; // HL = _WK_REEL# + 3
//
//	JR	NC,IS_REEL_CTL4		; �񓷃Z���T�[�ʉ߁H�D�D�m�n
//
//	LD	(HL),0FFH		; �񓷃Z���T�[�ʉ߃t���O�@�Z�b�g
//	INC	HL			; // HL = _WK_REEL# + 4
//	LD	(HL),20		 	; �P�}���̃X�e�b�v��  �Z�b�g
//	INC	HL			; // HL = _WK_REEL# + 5
//					; // B = 0
//	LD	(HL),B			; �}���ԍ��O  �Z�b�g
//
//	RET
//
//IS_REEL_CTL4:
//	INC	HL			; // HL = _WK_REEL# + 4
//	DEC	(HL)			; �P�}���̃X�e�b�v���@�|�P
//	RET	NZ			; �P�}�����������H�D�D�m�n
//
//	LD	(HL),19		 	; �P�}���̃X�e�b�v��  �Z�b�g
//	INC	HL			; // HL = _WK_REEL# + 5
//	INC	(HL)			; �}���ԍ��@�{�P
//
//	RET
//
//; �����J�n�i��ԁ��R�j
//
//IS_REEL_CTL5:
//	DEC	A			; �����J�n�H
//	JR	NZ,IS_REEL_CTL7		;   �m�n
//
//	CALL	IS_PULSE_OUT		; �񓷋쓮�p���X�Z�b�g
//
//	LD	A,4
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	PUSH	HL			; // HL = _WK_REEL# + 4
//
//	DEC	(HL)			; �P�}���̃X�e�b�v���@�|�P
//	JR	NZ,IS_REEL_CTL6		; �P�}�����������H�D�D�m�n
//
//	LD	(HL),19		 	; �P�}���̃X�e�b�v��  �Z�b�g
//	INC	HL			; // HL = _WK_REEL# + 5
//	INC	(HL)			; �}���ԍ��@�{�P
//
//	LD	A,(HL)
//	SUB	21			; �}���ԍ��Q�O�ȉ��H
//	JR	C,IS_REEL_CTL6		;   �x�d�r
//
//	LD	(HL),A			; �}���ԍ��C���i�O�`�Q�O�j
//
//	JR	NZ,IS_REEL_CTL6		; �}���ԍ��O�ɏC���H�D�D�m�n
//
//	DEC	HL			; // HL = _WK_REEL# + 4
//	INC	(HL)			; �P�}���̃X�e�b�v���C��
//
//IS_REEL_CTL6:
//	POP	HL
//	LD	A,(HL)			; // HL = _WK_REEL# + 4
//	CP	17			; ��~�J�n�X�e�b�v�H
//	RET	NC			; �@�m�n
//
//	INC	HL			; // HL = _WK_REEL# + 5
//	LD	A,(HL)
//	INC	HL			; // HL = _WK_REEL# + 6
//	CP	(HL)			; ��~�}���ʒu�H
//	RET	NZ			; �@�m�n
//
//	LD	L,LOW _PT_OUT0 - 1
//	LD	A,C			; �񓷔ԍ��@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	A,(HL)
//	OR	0FH
//	LD	(HL),A			; �������p���X�f�[�^  �Z�b�g
//					;;�i�S���n�m�j
//
//	EX	DE,HL			; // HL = _WK_REEL# + 0
//	LD	(HL),4			; ������ԁ@�Z�b�g
//
//	INC	HL			; // HL = _WK_REEL# + 1
//	LD	(HL),214		; �������p���X�J�E���^�@�Z�b�g
//
//	RET
//
//; �������i��ԁ��S�j
//
//IS_REEL_CTL7:
//	INC	HL			; // HL = _WK_REEL# + 1
//	DEC	(HL)			; �������p���X�J�E���^  �|�P
//	RET	NZ			; �J�E���g�I���H�D�D�m�n
//
//	LD	L,LOW _PT_OUT0 - 1
//	LD	A,C			; �񓷔ԍ��@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	A,(HL)
//	AND	0F0H
//	LD	(HL),A			; �쓮�p���X�@�N���A
//
//	XOR	A			; // DE = _WK_REEL# + 0
//	LD	(DE),A			; ��~��ԁ@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0320-001					*
//;*	�@�\	      : �񓷋쓮�p���X�Z�b�g				*
//;*	Ӽޭ�ٖ�      : IS_PULSE_OUT					*
//;*	�������Ұ�    : C = �񓷔ԍ�					*
//;*			HL = �񓷐���f�[�^�q�`�l�A�h���X		*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	C,HL						*
//;*	�j��ڼ޽�     :	A,B						*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//; # = ���䒆�̉񓷔ԍ� (= 3,2,1)
//;
//IS_PULSE_OUT:
//	PUSH	HL
//
//	LD	A,7
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//					; // HL = _WK_REEL# + 7
//	INC	(HL)			; �񓷋쓮�p���X�f�[�^�����p
//	LD	A,(HL)			;;�J�E���^�@�{�P
//	AND	111B
//	LD	HL,TBL_REEL_PULSE
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	B,(HL)			; �񓷋쓮�p���X�f�[�^�@���o��
//
//	LD	HL,_PT_OUT0 - 1
//	LD	A,C			; �񓷔ԍ��@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	A,(HL)
//	AND	0F0H
//	OR	B
//	LD	(HL),A			; �񓷋쓮�p���X�f�[�^�@�Z�b�g
//
//	POP	HL
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0321-001					*
//;*	�@�\	      : �O���M���o��					*
//;*	Ӽޭ�ٖ�      : IS_COUNTER_OUT					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,HL						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//IS_COUNTER_OUT:
//
//; �V�Z���_�������M���y�їV�Z���_�����o�M���@�o��
//
//	LD	HL,_TM1_OUT_CNT
//	LD	A,(HL)
//	AND	A			; �O���M���o�͎��ԏI���H
//	RET	NZ			; �@�m�n
//
//	LD	(HL),@TM_COUNT		; �O���M���o�͎��ԁ@�Z�b�g
//
//	LD	BC,200H			; // B = 2 (IN & OUT) , C = 0
//	LD	L,LOW _CT_MEDAL_IN 	; // HL = _CT_MEDAL_IN
//IS_COUNTER_OUT2:
//	LD	A,(HL)
//	AND	A			; �O���M���o�͗v������H
//	JR	Z,IS_COUNTER_OUT3	; �@�m�n
//
//	DEC	(HL)
//	SET	6,C			; �Y������o�̓f�[�^�r�b�g�@�n�m
//IS_COUNTER_OUT3:
//	RRC	C
//	INC	HL			; ���̏o�̓f�[�^�q�`�l�A�h���X�@�Z�b�g
//					; // HL = _CT_MEDAL_OUT
//	DJNZ	IS_COUNTER_OUT2		; �o�̓f�[�^���I���H�D�D�m�n
//
//	LD	L,LOW _PT_OUT0
//	LD	A,C
//	OR	11001111B
//	AND	(HL)			; �o�̓r�b�g�n�m�^�n�e�e�̔��]
//	XOR	C
//	LD	(HL),A			; �V�Z���_�������M���y�їV�Z���_��
//					;;���o�M���o�̓f�[�^�@�Z�b�g
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0300-001					*
//;*	�@�\	      : �v���O�����J�n  �i�����j			*
//;*	Ӽޭ�ٖ�      : M_PRG_START					*
//;************************************************************************
//;
//M_PRG_START1:
//
//; �q�n�l�̃T���`�F�b�N
//
//	XOR	A
//	LD	HL,M_PRG_START
//	LD	BC,1CH
//M_PRG_START2:
//	ADD	A,(HL)			; �q�n�l�`�F�b�N�T���Z�o
//	INC	HL			;;(0000H - 1BFFH)
//	DJNZ	M_PRG_START2		; �Q�T�U�o�C�g�Z�o�I���H�D�D�m�n
//
//	DEC	C			; �S�o�C�g�Z�o�I���H
//	JR	NZ,M_PRG_START2		;   �m�n
//
//	AND	A			; �q�n�l�`�F�b�N�T������H
//	JR	Z,M_PRG_START4		;   �x�d�r
//
//M_PRG_START3:
//	JR	M_PRG_START3    	; �������[�v�i�q�n�l�ُ�j
//
//; �b�o�t�E���Ӄf�o�C�X�����ݒ�
//
//M_PRG_START4:
//	LD	HL,TBL_AMUSE_SET	; �k�d�P�O�W�O�`������
//					;;�e�[�u��  �Z�b�g
//	LD	B,29			; �ݒ萔�@�Z�b�g
//	LD	D,0FFH
//M_PRG_START5:
//	LD	E,(HL)
//	INC	HL
//	LD	A,(HL)			; // DE = �A�h���X
//	INC	HL
//	LD	(DE),A			; �f�[�^�Z�b�g
//	DJNZ	M_PRG_START5		; �ݒ�I���H�D�D�m�n
//
//; ���ʉ�����
//
//	LD	A,@SD_CLEAR0		; ���ʉ��S����ٸر�v���@�Z�b�g
//
//	LD	(@SOUND_PORT),A		;;���ʉ��f�[�^�@�o��
//
//	LD	A,10000000B
//	OUT	(@OUT4_PORT),A		; �T�E���h�f�[�^���b�`�@�n�m
//
//	XOR	A
//	OUT	(@OUT4_PORT),A		; �T�E���h�f�[�^���b�`�@�n�e�e
//
//; �ݒ�l�ύX�E�q�`�l�������E�d�f���A�̊e���[�h�I��
//
//	IN	A,(@IN0_PORT)
//	BIT	6,A			; �ݒ�p�L�[�X�C�b�`�n�m�H
//	JR	Z,M_PRG_START7		; �@�m�n
//
//	LD	SP,@STACK		; �X�^�b�N�|�C���^�@�Z�b�g
//
//	LD	HL,_NB_RANK
//	LD	A,(HL)
//	DEC	A
//	CP	6			; �ݒ�l�@����͈́H
//	JR	C,M_PRG_START6		; �@�x�d�r
//
//	LD	A,(TBL_INIT_RANK)
//	LD	(HL),A			; �ݒ�l�i�����j�@�Z�b�g
//
//M_PRG_START6:
//	CALL	MS_RAM_CHK		; �q�`�l�`�F�b�N�E������
//
//	CALL	MS_PCT_ON		; �o�b�s�O�^�o�b�s�P�^�C�}�N��
//
//	EI				; ���荞�݋���
//
//	CALL	MS_RANK_SET		; �ݒ�l�ύX
//
//	DI				; ���荞�݋֎~
//
//	CALL	MS_RAM_CHK		; �q�`�l�`�F�b�N�E������
//
//	JR	M_PRG_START8
//
//M_PRG_START7:
//	IN	A,(@IN1_PORT)
//	BIT	3,A			; �ݒ�{�^���X�C�b�`�@�n�m�H
//	JR	Z,M_POWER_ON		; �@�m�n
//	LD	SP,@STACK		; �X�^�b�N�|�C���^�@�Z�b�g
//
//	CALL	MS_RKER_CHK		; �ݒ�l�G���[�`�F�b�N
//
//	CALL	MS_RAM_CHK		; �q�`�l�`�F�b�N�E������
//
//	CALL	MS_PCT_ON		; �o�b�s�O�^�o�b�s�P�^�C�}�N��
//
//M_PRG_START8:
//	EI				; ���荞�݋���
//
//	CALL	MS_BB_SET		; �𕨘A���쓮�������u�쓮�I����̐ݒ�
//
//	JP	M_MAIN
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0301-001					*
//;*	�@�\	      : �d�f���A					*
//;*	Ӽޭ�ٖ�      : M_POWER_ON					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL,BC',DE',HL'				*
//;*	�g�pӼޭ��    : MS_RKER_CHK,S_RAM_CLEAR,MS_PCT_ON,MS_BB_SET	*
//;*		      : SS_ERROR_STOP�i�W�����v�j			*
//;************************************************************************
//;
//M_POWER_ON:
//	LD	A,(_FL_GAME_STS)
//	AND	01000000B		; �d�f�����ς݁H
//	JR	Z,M_POWER_ON3		; �@�m�n
//
//	LD	HL,(_BF_STACK)
//	LD	DE,81C2H		; // @STACK - 62
//	SBC	HL,DE			; �ۑ��X�^�b�N�̃A�h���X�͈͊O�H
//	JR	C,M_POWER_ON3		;   �x�d�r
//
//	XOR	A
//	LD	HL,@RAM
//	LD	BC,2
//M_POWER_ON1:
//	ADD	A,(HL)			; �q�`�l�`�F�b�N�T���Z�o
//	INC	HL			;;(8000H - 81FFH)
//	DJNZ	M_POWER_ON1		; �Q�T�U�o�C�g�Z�o�I���H�D�D�m�n
//
//	DEC	C			; �S�o�C�g�Z�o�I���H
//	JR	NZ,M_POWER_ON1		;   �m�n
//
//	AND	A			; �q�`�l�`�F�b�N�T������H
//	JR	NZ,M_POWER_ON3		;   �m�n
//
//	LD	SP,(_BF_STACK)	 	; �X�^�b�N�|�C���^���A
//
//	CALL	MS_RKER_CHK		; �ݒ�l�G���[�`�F�b�N
//
//	LD	HL,TBL_RAM_CLEAR1	; �d�f���A���̂q�`�l�������p
//					;;�e�[�u���@�Z�b�g
//	RST	S_RAM_CLEAR		; �q�`�l������ <808FH - 81BFH>
//
//	CALL	MS_PCT_ON		; �o�b�s�O�^�o�b�s�P�^�C�}�N��
//
//	CALL	MS_BB_SET		; �𕨘A���쓮�������u�쓮�I����̐ݒ�
//
//	IN	A,(@IN0_PORT)
//	LD	(_PT_IN0_OLD),A		; ���̓|�[�g�O���x���f�[�^�@�Z�b�g
//
//	IN	A,(@IN1_PORT)
//	LD	(_PT_IN1_OLD),A		; ���̓|�[�g�P���x���f�[�^�@�Z�b�g
//
//	IN	A,(@IN2_PORT)
//	LD	(_PT_IN2_OLD),A		; ���̓|�[�g�Q���x���f�[�^�@�Z�b�g
//
//	LD	HL,_FL_GAME_STS
//	SET	1,(HL)			; �A�������A�v���t���O�@�Z�b�g
//	RES	6,(HL)			; �d�f�����ς݃t���O�@�N���A
//
//	POP	HL			; �g�p���W�X�^���A�i�`�e���W�X�^�ȊO�j
//	POP	DE
//	POP	BC
//	EXX
//	POP	HL
//	POP	DE
//	POP	BC
//
//	POP	AF			; �d�f���̊��荞�݋֎~�^����ԁ@���A
//					; // �e���W�@BIT2 ON   ���荞�݋���
//					; //              OFF  ���荞�݋֎~
//	JP	PO,M_POWER_ON2		; ���荞�݋��H�D�D�m�n
//
//	POP	AF			; �`�e���W�X�^���A
//
//	EI				; ���荞�݋���
//
//	RETN
//
//M_POWER_ON2:
//	POP	AF			; �`�e���W�X�^���A
//	RETN
//
//; �d�f�G���[
//
//M_POWER_ON3:
//	LD	E,06H			; �h�d�P�h�\���v��  �Z�b�g
//	JP	SS_ERROR_STOP
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0302-004					*
//;*	�@�\	      : �V�Z�i�s���C��					*
//;*	Ӽޭ�ٖ�      : M_MAIN						*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,HL						*
//;*	�g�pӼޭ��    : MS_STOP_LED,S_RAM_CLEAR,MS_RAM_SET,MS_GAME_SET	*
//;*		      : MS_BNSCT_DSP,S_BLOCKER_ON			*
//;*		      : MS_RANK_DSP,S_WATCH_CLEAR,MS_HOPPER_CHK		*
//;*		      : MS_CREDIT_CHK,MS_CANCEL_CHK,MS_INSERT_CHK	*
//;*		      : MS_START_CHK,S_BLOCKER_OFF,MS_AUTO_IN		*
//;*		      : MS_SCOUNT_OUT,MS_RKER_CHK,MS_ALL_LOT		*
//;*		      : MS_WAIT_CHK,MS_REEL_READY,MS_REEL_START		*
//;*		      : MS_HIT_SET,MS_RLSTOP_SET,MS_RLERR_CHK		*
//;*		      : MS_RLFIX_CHK,MS_STOP_CHK,MS_PIC_CTL		*
//;*		      : MS_RLSTP_CHK,MS_WIN_JUDGE,MS_WIN_PAY		*
//;*		      : MS_GAME_CHK					*
//;************************************************************************
//
//; �V�Z������
//
//M_MAIN:
//	LD	B,00111000B		; ��~�{�^���k�d�c�_���v���@�Z�b�g
//	CALL	MS_STOP_LED		; ��~�{�^���k�d�c�\��
//
//	LD	HL,@TM_BACK_OFF
//	LD	(_TM2_BACK_OFF),HL	; �V�Z�ҋ@���̕\���ҋ@���ԁ@�Z�b�g
//
//	LD	HL,TBL_RAM_CLEAR2	; �V�Z�J�n���̂q�`�l�������p
//					;;�e�[�u���@�Z�b�g
//	RST	S_RAM_CLEAR		; �q�`�l������ <808FH - 81E9H>
//
//	DI				; ���荞�݋֎~
//
//	LD	HL,81EAH		; �q�`�l�������擪�A�h���X�@�Z�b�g
//	LD	BC,22*100H		; �q�`�l�������͈́@�Z�b�g
//					; < ���荞�ݎ��ő�X�^�b�N�g�p�ʁ{�Q�o�C�g >
//M_MAIN1:
//	LD	(HL),C			; �q�`�l������ <81EAH - 81FFH>
//	INC	HL			; ���̂q�`�l�A�h���X�@�Z�b�g
//	DJNZ	M_MAIN1			; �q�`�l�������I���H�D�D�m�n
//
//	EI				; ���荞�݋���
//
//	CALL	MS_RAM_SET		; �q�`�l�����f�[�^�Z�b�g
//
//	CALL	MS_GAME_SET		; �V�Z�J�n�Z�b�g
//
//	CALL	MS_BNSCT_DSP		; �V�Z�񐔕\��
//
//	LD	A,(_FL_ACTION)
//	RRCA				; �ėV�Z�쓮���H
//	JR	C,M_MAIN5		;   �x�d�r
//
//; �ėV�Z�쓮���ȊO�̗V�Z���_�������A�񓷉�]�n�����u�@��t����
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//M_MAIN2:
//
//;	�V�Z�ҋ@���̕\������
//
//	LD	HL,(_TM2_BACK_OFF)
//	LD	A,H
//	OR	L			; �V�Z�ҋ@�\�����ԁH
//	JR	NZ,M_MAIN3		;   �m�n
//
//	LD	HL,_WK_BACK_LP
//	LD	(HL),A			; �o�b�N�����v�\���v���@�N���A
//	LD	L,LOW _PT_OUT7
//	RES	7,(HL)			; �o�b�N�����v�����@�Z�b�g
//	INC	HL			; // HL = _PT_OUT8
//	LD	(HL),A
//
//M_MAIN3:
//	CALL	MS_RANK_DSP		; �ݒ�l�\��
//
//M_MAIN4:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_HOPPER_CHK		; �V�Z���_�����o�Z���T�[�`�F�b�N
//
//	CALL	MS_CREDIT_CHK		; �����{�^���`�F�b�N
//
//	CALL	MS_CANCEL_CHK		; ���Z�{�^���`�F�b�N
//
//	CALL	MS_INSERT_CHK		; �V�Z���_�������`�F�b�N
//
//	LD	A,(_NB_PLAY_MEDAL)
//	AND	A			; �V�Z���_���Ȃ��H
//	JR	Z,M_MAIN2		;   �x�d�r
//
//	CALL	MS_START_CHK		; �񓷉�]�n�����u�`�F�b�N
//					; // �i�n�[�h�E�F�A�����ǂݍ��݁E�ۑ��j
//	JR	NC,M_MAIN4		; ��t�H�D�D�m�n
//
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	JR	M_MAIN7
//
//; �ėV�Z�쓮���̗V�Z���_����������
//
//M_MAIN5:
//	CALL	MS_AUTO_IN		; �V�Z���_����������
//
//; �ėV�Z�쓮���̉񓷉�]�n�����u  ��t����
//
//M_MAIN6:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_HOPPER_CHK		; �V�Z���_�����o�Z���T�[�`�F�b�N
//
//	CALL	MS_START_CHK		; �񓷉�]�n�����u�`�F�b�N
//					; // �i�n�[�h�E�F�A�����ǂݍ��݁E�ۑ��j
//	JR	NC,M_MAIN6		; ��t�H�D�D�m�n
//
//; ���I
//
//M_MAIN7:
//	CALL	MS_SCOUNT_OUT		; �O���M���o�͗v��
//
//	CALL	MS_RKER_CHK		; �ݒ�l�G���[�`�F�b�N
//
//	CALL	MS_ALL_LOT		; ���I
//
//; �񓷉�]�ҋ@
//
//M_MAIN8:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_WAIT_CHK		; �ŒZ�V�Z���ԃ`�F�b�N
//					; // �i�񓷉�]�s���E�E�G�C�g�\���j
//	JR	NC,M_MAIN8		; �񓷉�]���H�D�D�m�n
//
//; �񓷉�]�J�n
//
//	CALL	MS_REEL_READY		; �񓷉�]�J�n����
//
//	LD	A,11100000B		; �S�񓷉�]�r�b�g  �Z�b�g
//
//M_MAIN9:
//	CALL	MS_REEL_START		; �񓷉�]�J�n
//
//	LD	B,00111000B		; ��~�{�^���k�d�c�_���v���@�Z�b�g
//	CALL	MS_STOP_LED		; ��~�{�^���k�d�c�\��
//
//; �񓷉�]��
//
//M_MAIN10:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_HIT_SET		; ���܊��Ҏ��̏o�̓Z�b�g
//
//	CALL	MS_RLSTOP_SET		; �񓷒�~���̏o�̓Z�b�g
//
//	CALL	MS_RLERR_CHK		; �񓷉�]�G���[�`�F�b�N
//	JR	C,M_MAIN9		; �񓷍ċN���H�D�D�x�d�r
//
//	CALL	MS_RLFIX_CHK		; �񓷒葬�`�F�b�N
//	JR	NC,M_MAIN10		; �葬�H�D�D�m�n
//
//	CALL	MS_STOP_CHK	 	; �񓷒�~��t�`�F�b�N
//
//	CALL	C,MS_PIC_CTL		; �񓷒�~��t�H�D�D�x�d�r
//					; �}���g��������
//
//	CALL	MS_RLSTP_CHK		; �S�񓷒�~�`�F�b�N
//	JR	NZ,M_MAIN10		; �S�񓷒�~�H�D�D�m�n
//
//; ���ܔ���
//
//	CALL	MS_WIN_JUDGE		; ���ܔ���
//
//	CALL	MS_WIN_PAY		; ���܂ɂ��V�Z���_�����o��
//
//	CALL	MS_GAME_CHK		; �V�Z�I���`�F�b�N
//
//	JP	M_MAIN
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0322-001					*
//;*	�@�\	      : �q�`�l�`�F�b�N�E������				*
//;*	Ӽޭ�ٖ�      : MS_RAM_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : SS_ERROR_STOP�i�W�����v�j			*
//;************************************************************************
//;
//MS_RAM_CHK:
//	POP	DE			; �߂�Ԓn  �ޔ�
//
//	LD	HL,8001H		; �q�`�l�������擪�A�h���X  �Z�b�g
//	LD	BC,01FFH		; �q�`�l�������͈�  �Z�b�g
//MS_RAM_CHK1:
//	LD	A,55H			; �`�F�b�N�f�[�^�@��������
//	LD	(HL),A
//	CP	(HL)			; 01010101B �`�F�b�N�@����H
//	JR	NZ,MS_RAM_CHK2		; �@�m�n
//
//	CPL				; �`�F�b�N�f�[�^�@��������
//	LD	(HL),A
//	SUB	(HL)			; 10101010B �`�F�b�N�@����H
//	JR	NZ,MS_RAM_CHK2		; �@�m�n
//
//	LD	(HL),A			; ������
//	INC	HL
//	DEC	BC
//	LD	A,B
//	OR	C			; �`�F�b�N�I���H
//	JR	NZ,MS_RAM_CHK1		;   �m�n
//
//	PUSH	DE			; �߂�Ԓn  ���A
//
//	LD	HL,0FFFH
//	LD	(_NB_COUNT_LED1),HL	; �񐔕\���k�d�c�P�A�Q�@����
//
//	RET
//
//MS_RAM_CHK2:
//	LD	E,5BH			; �h�d�Q�h�\���v��  �Z�b�g
//	JP	SS_ERROR_STOP
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0323-001					*
//;*	�@�\	      : �o�b�s�O�^�o�b�s�P�^�C�}�N��			*
//;*	Ӽޭ�ٖ�      : MS_PCT_ON					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_PCT_ON:
//	LD	A,80H
//	LD	(0FF22H),A		; �E�H�b�`�h�b�O�N�� <�o�b�s�O>
//	LD	(0FF30H),A		; ���荞�݋N�� <�o�b�s�P>
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0324-001					*
//;*	�@�\	      : �ݒ�l�ύX					*
//;*	Ӽޭ�ٖ�      : MS_RANK_SET					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,DE,HL					*
//;*	�g�pӼޭ��    : S_WATCH_CLEAR					*
//;************************************************************************
//;
//MS_RANK_SET:
//	LD	DE,_NB_CREDIT_LED
//	LD	A,0FFH
//	LD	(DE),A			; �V�Z���_�����������\��  ����
//
//	LD	HL,_NB_RANK
//	LD	B,(HL)			; �ݒ�l�@���o��
//
//	INC	DE			; // DE = _NB_PAY_LED
//	LD	L,LOW _PT_IN1_UP
//MS_RANK_SET1:
//	LD	A,B
//	OR	0F0H
//	LD	(DE),A			; �ݒ�l�\��
//
//MS_RANK_SET2:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_PT_IN0_UP)
//  	BIT	5,A			; �񓷉�]�n�����u�X�C�b�`�@�n�m�H
//	JR	NZ,MS_RANK_SET3		; �@�x�d�r
//
//	BIT	3,(HL)			; �ݒ�{�^���X�C�b�`�@�n�m�H
//	JR	Z,MS_RANK_SET2		; �@�m�n
//
//	RES	3,(HL)			; �ݒ�{�^���X�C�b�`�����オ��
//					;;�f�[�^�@�N���A
//	INC	B			; �ݒ�l�@�{�P
//	LD	A,6
//	CP	B			; �ݒ�l  ���@�U�H
//	JR	NC,MS_RANK_SET1		; �@�m�n
//
//	LD	B,1			; �ݒ�l�@���@�P
//	JR	MS_RANK_SET1
//
//MS_RANK_SET3:
//	LD	A,0F0H
//	LD	(DE),A			; �ݒ�l�\��  �N���A
//
//MS_RANK_SET4:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_PT_IN0_DOWN)
//	BIT	6,A			; �ݒ�p�L�[�X�C�b�`�@�n�e�e�H
//	JR	Z,MS_RANK_SET4		; �@�m�n
//
//	LD	L,LOW _NB_RANK
//	LD	(HL),B			; �ݒ�l�@�Z�b�g
//
//	XOR	A
//	LD	(DE),A			; �V�Z���_�����o�������\��  �N���A
//	DEC	DE			; // DE = _NB_CREDIT_LED
//	LD	(DE),A			; �V�Z���_�����������\���@�N���A
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0325-001					*
//;*	�@�\	      : �ݒ�l�G���[�`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_RKER_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,E						*
//;*	�g�pӼޭ��    : SS_ERROR_STOP�i�W�����v�j			*
//;************************************************************************
//;
//MS_RKER_CHK:
//	LD	A,(_NB_RANK)
//	DEC	A
//	CP	6			; �ݒ�l�@����͈́H
//	RET	C			; �@�x�d�r
//
//	LD	E,7DH			; �h�d�U�h�\���v��  �Z�b�g
//	JP	SS_ERROR_STOP
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0326-001					*
//;*	�@�\	      : �𕨘A���쓮�������u�쓮�I����̐ݒ�		*
//;*	Ӽޭ�ٖ�      : MS_BB_SET					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,HL						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_BB_SET:
//	IN	A,(@IN1_PORT)
//	AND	00000101B		; // b0 = �������ߐؑփX�C�b�`
//	LD	B,A			; // b2 = �Ŏ~�ؑփX�C�b�`
//	LD	HL,_FL_GAME_STS
//	LD	A,(HL)
//	AND	11111010B
//	OR	B
//	LD	(HL),A			; �𕨘A���쓮�������u�쓮�I����̐ݒ�
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0327-001					*
//;*	�@�\	      : �q�`�l�����f�[�^�Z�b�g				*
//;*	Ӽޭ�ٖ�      : MS_RAM_SET					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	C = �O��V�Z�̗V�Z���_������			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	BC,DE,HL					*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_RAM_SET:
//;
//; ��~�}���f�[�^�����f�[�^�@�Z�b�g
//;
//	LD	BC,12
//	LD	HL,TBL_INIT_PIC
//	LD	DE,_WK_ALL_PIC1
//	LDIR				; ��~�}���f�[�^�����l�@�Z�b�g
//;
//; ���̑������f�[�^�@�Z�b�g
//;
//	LD	HL,_FL_STOP_LP
//	LD	(HL),11100000B		; �񓷒�~�t���O������
//
//	LD	L,LOW _FL_GAME_STS
//	RES	5,(HL)			; �V�Z���_�����E�t���O�@�N���A
//	SET	7,(HL)			; ���Z�C�����t���O�@�Z�b�g
//					; // BC = 0
//	LD	(_BF_STOP_CTL),BC	; ��~�ʒu����p�e�[�u��
//					;;�ۑ��p�o�b�t�@�@�N���A
//
//	LD	L,LOW _NB_PLAY_MEDAL	; // B = 0
//	LD	C,(HL)			; // �i�O��V�Z�̗V�Z���_�������@�ۑ��j
//	LD	(HL),B			; �V�Z���_������  �N���A
//
//	LD	L,LOW _NB_STOP_ORDER	; // B = 0
//	LD	(HL),B			; �񓷒�~���ԁ@�N���A
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0328-005					*
//;*	�@�\	      : �V�Z�J�n�Z�b�g					*
//;*	Ӽޭ�ٖ�      : MS_GAME_SET					*
//;*	�������Ұ�    : C = �O��V�Z�̗V�Z���_������			*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	C						*
//;*	�j��ڼ޽�     :	A,DE,HL						*
//;*	�g�pӼޭ��    : S_LPSD_SET					*
//;************************************************************************
//;
//MS_GAME_SET:
//	LD	HL,_FL_WIN
//	LD	A,(HL)
//	LD	(HL),0			; ���܃t���O  �N���A
//
//	EX	DE,HL
//	INC	DE			; // DE = _FL_ACTION
//	BIT	@BT_RP,A		; �ėV�Z�\���H
//	JR	Z,MS_GAME_SET1		;   �m�n
//
//; �ėV�Z�쓮�J�n����  �Z�b�g
//
//	LD	HL,@TM_REPLAY1
//	LD	(_TM2_REPLAY_ML),HL	; �V�Z���_����������
//					;;�ҋ@���ԁ@�Z�b�g
//
//	LD	A,C			; // �i�O��V�Z�̗V�Z���_�������j
//	LD	(_NB_REP_MEDAL),A	; ���������V�Z���_�������@�Z�b�g
//
//	LD	A,@SET_REPLAY		; �ėV�Z�쓮���̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	EX	DE,HL			; // HL = _FL_ACTION
//	SET	@BT_RP,(HL)		; �ėV�Z�쓮�t���O  �Z�b�g
//
//	RET
//
//; �𕨘A���쓮���u�쓮�J�n����  �Z�b�g
//
//MS_GAME_SET1:
//	BIT	@BT_RB,A		; �q�a���܁H
//	JR	Z,MS_GAME_SET2		;   �m�n
//
//	LD	L,LOW _PT_OUT0		; �𕨘A���쓮���u�{������M���o�͂n�m
//	SET	6,(HL)
//
//	LD	L,LOW _PT_OUT2
//	SET	5,(HL)			; �V�Z��ԕ\�������v�P�_���@�Z�b�g
//
//	LD	HL,@J_WIN*100H OR @J_MAX; �q�a�쓮���̖𕨓��܉�  �Z�b�g
//	LD	(_CT_BONUS_PLAY),HL	; �q�a�쓮���̖𕨗V�Z�񐔁@�Z�b�g
//	LD	A,@SET_RB		; �𕨘A���쓮���u�쓮����
//					;;�o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	EX	DE,HL			; // HL = _FL_ACTION
//	SET	@BT_RB,(HL)		; �𕨘A���쓮���u�쓮�t���O  �Z�b�g
//
//	RET
//
//; �𕨘A���쓮�������u�쓮�J�n����  �Z�b�g
//
//MS_GAME_SET2:
//	BIT	@BT_BB,A		; �a�a���܁H
//	RET	Z			;   �m�n
//
//	LD	L,LOW _PT_OUT0		; �𕨘A���쓮�������u
//	SET	7,(HL)			;;�{������M���o�͂n�m
//
//	LD	L,LOW _PT_OUT2
//	SET	7,(HL)			; �V�Z��ԕ\�������v�R�_���@�Z�b�g
//	SET	6,(HL)			; �V�Z��ԕ\�������v�Q�_���@�Z�b�g
//
//	LD	HL,@B_WIN*100H OR @B_MAX; �a�a�쓮���̈�ʗV�Z�񐔁@�Z�b�g
//	LD	(_CT_BIG_PLAY),HL	; �a�a�쓮���̂q�a���܉�  �Z�b�g
//
//					; // DE = _FL_ACTION
//	LD	(DE),A			; �𕨘A���쓮�������u�쓮�t���O  �Z�b�g
//
//	BIT	@BT_BB1,A
//	LD	A,@SET_BB1		; �𕨘A���쓮�������u�쓮����
//					;;�o�͗v���P�@�Z�b�g
//	JR	NZ,MS_GAME_SET3		; (���ݥ���ݥ����)���܁H�D�D�x�d�r
//
//	INC     A			; �𕨘A���쓮�������u�쓮����
//					;;�o�͗v���Q�@�Z�b�g
//					; // A = @SET_BB2
//MS_GAME_SET3:
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0329-001					*
//;*	�@�\	      : �{�[�i�X�Q�[���`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_BNS_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    : Zflag OFF = �{�[�i�X�Q�[��			*
//;*		      : Zflag ON = ���̑�				*
//;*		      : A = �{�[�i�X�Q�[���r�b�g			*
//;*	�ی�ڼ޽�     : 						*
//;*	�j��ڼ޽�     : A						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_BNS_CHK:
//	LD	A,(_FL_ACTION)
//	AND	@_BNS			; �{�[�i�X�Q�[���`�F�b�N
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0330-001					*
//;*	�@�\	      : �V�Z���_�����o�Z���T�[�`�F�b�N			*
//;*	Ӽޭ�ٖ�      : MS_HOPPER_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    : 						*
//;*	�ی�ڼ޽�     : 						*
//;*	�j��ڼ޽�     : A,BC,DE,HL					*
//;*	�g�pӼޭ��    : S_WATCH_CLEAR,S_IN0_CHK,S_BLOCKER_OFF		*
//;*			MS_HPERR_SET,S_BLOCKER_ON			*
//;************************************************************************
//;
//MS_HOPPER_CHK:
//	LD	DE,_TM1_PAY
//	LD	A,@TM_HOPPER4		; �V�Z���_�����o�Z���T�[
//	LD	(DE),A			;;�`�F�b�N���ԁ@�Z�b�g
//	LD	HL,_PT_OUT1
//	LD	C,(HL)			; �V�Z���ٕ��o�ݻ������O�V�Z����
//					;;��ۯ����Ԉꎞ�ۑ�
//MS_HOPPER_CHK1:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	B,00001000B		; �V�Z���_�����o�Z���T�[�M��
//					;;�`�F�b�N�v��
//	RST	S_IN0_CHK		; ���̓|�[�g�O���x���`�F�b�N
//	JR	Z,MS_HOPPER_CHK2	; �V�Z���_�����o�Z���T�[�n�m�H�D�D�m�n
//
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	LD	L,LOW _FL_GAME_STS	; �񓷉�]�n�����u
//	RES	3,(HL)			;;��t���t���O�@�N���A
//
//	LD	A,(DE)			; // DE = _TM1_PAY
//	AND	A			; �`�F�b�N���ԏI���H
//	JR	NZ,MS_HOPPER_CHK1	;   �m�n
//
//	LD	D,0DCH			; �h�g�b�h�\���v���@�Z�b�g
//	CALL	MS_HPERR_SET		; �V�Z���_�����o�G���[�Z�b�g
//
//MS_HOPPER_CHK2:
//	BIT	4,C			; �V�Z���ٕ��o�ݻ������O�V�Z����
//					;;��ۯ����Ԋm�F�v���@�Z�b�g
//	RET	Z			; �V�Z������ۯ���n�m�H�D�D�m�n
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0331-003					*
//;*	�@�\	      : �V�Z���_�����o�G���[�Z�b�g			*
//;*	Ӽޭ�ٖ�      : MS_HPERR_SET					*
//;*	�������Ұ�    : D = �G���[�\���f�[�^				*
//;*	�o�����Ұ�    : 						*
//;*	�ی�ڼ޽�     : 						*
//;*	�j��ڼ޽�     : A,B,DE,HL					*
//;*	�g�pӼޭ��    : S_LPSD_SET,S_WATCH_CLEAR			*
//;************************************************************************
//;
//MS_HPERR_SET:
//	LD	HL,_WK_FLASH_LP		; �G���[��������
//	LD	B,(HL)			;;�㕔�����v�\���@�ޔ�
//
//	LD	L,LOW _NB_PAY_LED
//	LD	E,(HL)			; �V�Z���_�����o�������\��  �ޔ�
//
//	LD	(HL),D			; �G���[�\��  �Z�b�g
//
//	LD	A,@SET_ALARM		; �V�Z���_�����o�G���[��������
//					;;�o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//MS_HPERR_SET1:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_PT_IN1_UP)
//	AND	00001010B		; �G���[�����H
//	JR	Z,MS_HPERR_SET1		; �@�m�n
//					; // HL = _NB_PAY_LED
//	LD	(HL),E			; �V�Z���_�����o�������\��  ���A
//
//	LD	A,@SET_ACLEAR		; �V�Z���_�����o�G���[��������
//					;;�o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//; �V�Z���_�����o�G���[�������̏㕔�����v�E���ʃ����v�E���ʉ����A
//
//	LD	A,B			; �G���[�������̏㕔�����v�\���@���A
//	LD	DE,@ERREC_LP		; �G���[���A���̏o�͔ԍ��@�Z�b�g
//	LD	B,@ERREC_CT		; �G���[���A���̏o�͔ԍ��������@�Z�b�g
//
//MS_HPERR_SET2:
//	INC	D			; ���A�p�o�͗v���ԍ��@�Z�b�g
//	INC	E			; �㕔�����v�o�͗v���ԍ��@�Z�b�g
//
//	DEC	B			; �㕔�����v�\���Ȃ��H
//	RET	Z			;   �x�d�r
//
//	CP	E			; �㕔�����v�p�^�[���o�͒��H
//	JR	NZ,MS_HPERR_SET2	;   �m�n
//
//	LD	A,D			; ���A����o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0332-001					*
//;*	�@�\	      : �����{�^���`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_CREDIT_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : MS_STOPSW_CHK,MS_SENSOR_CHK,S_IN0_CHK		*
//;*		      : MS_JAC_CHK,S_BLOCKER_OFF,MS_BET_IN,S_BLOCKER_ON	*
//;************************************************************************
//;
//MS_CREDIT_CHK:
//	LD	HL,_FL_GAME_STS
//	BIT	4,(HL)			; �V�Z���_���������u�g�p���H
//	RET	NZ			;   �m�n
//
//	CALL	MS_STOPSW_CHK		; ��~�{�^���`�F�b�N
//	RET	NZ			; ��~�{�^���@���쒆�H�D�D�x�d�r
//
//	CALL	MS_SENSOR_CHK		; �V�Z���_�������Z���T�[�`�F�b�N
//	RET	NZ			; ���͂���H�D�D�x�d�r
//
//	LD	B,00110000B		; �񓷉�]�n�����u�E���Z�{�^��
//					;;�X�C�b�`�@�`�F�b�N�v��
//	RST	S_IN0_CHK		; ���̓|�[�g�O���x���`�F�b�N
//	RET	NZ			; ���̑��̓��͂���H�D�D�x�d�r
//
//;	�����{�^���`�F�b�N
//
//	LD	DE,(_PT_IN0_OLD)	; // D = (_PT_IN0_UP), E = (_PT_IN0_OLD)
//	LD	A,D
//	XOR	E
//	AND	00000111B		; �����{�^���p�����쒆�H
//	RET	NZ			;�@ �x�d�r
//
//	LD	A,D			; // D = (_PT_IN0_UP)
//	AND	00000111B
//	LD	BC,3			; // B = 0,C = 3
//MS_CREDIT_CHK1:
//	INC	B			; �����{�^���v�������@�Z�b�g
//	RRCA
//	JR	C,MS_CREDIT_CHK2	; �����{�^�����͂���H�D�D�x�d�r
//	DEC	C
//	RET	Z			; ���ׂĂ̓����{�^���`�F�b�N�����H�D�D�x�d�r
//	JR	MS_CREDIT_CHK1
//
//MS_CREDIT_CHK2:
//
//	CALL	MS_JAC_CHK		; �𕨗V�Z�`�F�b�N
//	JR	Z,MS_CREDIT_CHK3	; �𕨗V�Z���H�D�D�m�n
//	LD	B,1			; �����{�^���v���������P���@�Z�b�g
//
//MS_CREDIT_CHK3:
//	LD	DE,_NB_PLAY_MEDAL
//	LD	A,(DE)
//	CP	B			; �V�Z���ٖ������������ݗv�������H
//	RET	Z			;   �x�d�r
//
//	JR	C,MS_CREDIT_CHK4	; �V�Z���ٖ������������ݗv�������H�D�D�m�n
//
//;	�V�Z���_�������������{�^���v�������@���̏���
//
//	BIT	7,(HL)			; ���Z�C�����t���O����H
//					; // HL = _FL_GAME_STS
//	RET	Z			;   �m�n
//
//	RES	3,(HL)			; �񓷉�]�n�����u
//					;;��t���t���O�@�N���A
//	RES	5,(HL)			; �V�Z���_�����E�t���O�@�N���A
//
//	LD	L,LOW _NB_CREDIT_LED	; // A = �V�Z���_������
//	ADD	A,(HL)			; �����������Z
//	DAA
//	LD	(HL),A
//	XOR	A			; // DE = _NB_PLAY_MEDAL
//	LD	(DE),A			; �V�Z���_�������@�N���A
//					; // �����v�������������{�^���v������
//	JR	MS_CREDIT_CHK5
//
//;	�V�Z���_�������������{�^���v�������@���̏���
//
//MS_CREDIT_CHK4:
//	LD	A,(_NB_CREDIT_LED)
//	AND	A			; �V�Z���_��������������H
//	RET	Z			; �@�m�n
//
//	RES	3,(HL)			; �񓷉�]�n�����u
//					;;��t���t���O�@�N���A
//					; // HL = _FL_GAME_STS
//	LD	A,B			; // B = �����{�^���v������
//	EX	DE,HL
//	SUB	(HL)			; // HL = _NB_PLAY_MEDAL
//	LD	B,A			; �����v�������������{�^���v������
//					;;              �|  �V�Z���_������
//	LD	L,LOW _NB_CREDIT_LED
//
//	CP	(HL)			; �V�Z���ْ��������������v�������H
//	JR	C,MS_CREDIT_CHK5	;   �x�d�r
//
//	LD	B,(HL)			; �����v���������V�Z���_����������
//
//;	��������
//
//MS_CREDIT_CHK5:
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	CALL	MS_BET_IN		; ��������
//
//	CALL	MS_JAC_CHK		; �𕨗V�Z�`�F�b�N
//	RET	NZ			; �𕨗V�Z���H�D�D�x�d�r
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0333-001					*
//;*	�@�\	      : ��~�{�^���`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_STOPSW_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Zflag OFF = �{�̒�~�{�^���n�m�i���쒆�j	*
//;*		      :	Cflag OFF					*
//;*		      : A = �{�̒�~�{�^���f�[�^(XXX00000B)		*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_STOPSW_CHK:
//	LD	A,(_PT_IN2_OLD)
//	CPL
//	AND	11100000B		; ��~�{�^���`�F�b�N
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0334-001					*
//;*	�@�\	      : �V�Z���_�������Z���T�[�`�F�b�N			*
//;*	Ӽޭ�ٖ�      : MS_SENSOR_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Zflag OFF = �V�Z���_�������Z���T�[���͂���	*
//;*		      : A = �V�Z���_�������Z���T�[�f�[�^(00XX0000B)	*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_SENSOR_CHK:
//	LD	A,(_PT_IN1_OLD)
//	CPL
//	AND	00110000B		; �V�Z���_�������Z���T�[�`�F�b�N
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0335-001					*
//;*	�@�\	      : �𕨗V�Z�`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_JAC_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    : Zflag OFF = �𕨗V�Z				*
//;*		      : Zflag ON = ���̑��̗V�Z				*
//;*	�ی�ڼ޽�     : 						*
//;*	�j��ڼ޽�     : A						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_JAC_CHK:
//	LD	A,(_FL_ACTION)
//	AND	@_JAC			; �𕨗V�Z�`�F�b�N
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0336-001					*
//;*	�@�\	      : ��������					*
//;*	Ӽޭ�ٖ�      : MS_BET_IN					*
//;*	�������Ұ�    : B = �����v������				*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B						*
//;*	�g�pӼޭ��    : S_WATCH_CLEAR,MS_MEDAL_INC,MS_CREDIT_DEC	*
//;************************************************************************
//;
//MS_BET_IN:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_TM1_BET_ML)
//	AND	A			; �V�Z���_�������ҋ@���H
//	JR	NZ,MS_BET_IN		; �@�x�d�r
//
//	CALL	MS_MEDAL_INC		; �V�Z���_���P�����Z
//
//	CALL	MS_CREDIT_DEC		; �V�Z���_�����������P�����Z
//
//	LD	A,@TM_BET_IN
//	LD	(_TM1_BET_ML),A		; �V�Z���_�������ҋ@����  �Z�b�g
//
//	DJNZ	MS_BET_IN		; �����v�����������I���H�D�D�m�n
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0337-001					*
//;*	�@�\	      : �V�Z���_���P�����Z				*
//;*	Ӽޭ�ٖ�      : MS_MEDAL_INC					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Zflag ON = �V�Z���_�����E			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,C,DE,HL					*
//;*	�g�pӼޭ��    : S_LPSD_SET,S_ADDR_SET,S_BLOCKER_OFF		*
//;************************************************************************
//;
//MS_MEDAL_INC:
//	XOR	A
//	LD	HL,_WK_WIN_LP
//	LD	(HL),A			; ���܎��L�����C�������v
//					;;�_�Ńf�[�^�@�N���A
//	INC	HL			; // HL = _WK_WINBACK_LP
//	LD	(HL),A			; ���܎��o�b�N�����v�X�_��
//					;;�f�[�^�@�N���A
//	INC	HL			; // HL = _WK_WINBACK_LP+1
//	LD	(HL),A			; ���܎��o�b�N�����v�P�`�W�_��
//					;;�f�[�^�@�N���A
//	LD	(_NB_PAY_LED),A		; �V�Z���_�����o�������\���@�N���A
//
//	LD	A,@SET_INCO		; �V�Z���_����������
//					;;�o�͗v��  �Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	LD	L,LOW _NB_PLAY_MEDAL
//	INC	(HL)			; �V�Z���_�������@�{�P
//
//	LD	A,(HL)			; // HL = _NB_PLAY_MEDAL
//	LD	C,A			; // �V�Z���_�������ꎞ�ۑ�
//	LD	HL,TBL_LINE_LP - 1	; �L�����C�������v�_��
//					;;�e�[�u���v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	DE,_PT_OUT5
//	DI				; ���荞�݋֎~
//	LD	A,(DE)
//	AND	11100000B
//	OR	(HL)
//	LD	(DE),A			; �L�����C�������v�_��
//	EI				; ���荞�݋���
//
//	LD	HL,_NB_REP_MEDAL	; �V�Z���_��������������
//	LD	D,(HL)			;;�V�Z���_�����E����  �Z�b�g
//
//	LD	A,(_FL_ACTION)
//	BIT	@BT_RP,A		; �ėV�Z�쓮���H
//	JR	NZ,MS_MEDAL_INC1	;   �x�d�r
//
//	LD	D,3			; �V�Z���_�����E�����R��  �Z�b�g
//
//	AND	@_JAC			; �𕨗V�Z���H
//	JR	Z,MS_MEDAL_INC1		; �@�m�n
//
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	LD	D,1			; �V�Z���_�����E�����P��  �Z�b�g
//
//MS_MEDAL_INC1:
//	LD	A,C			; // C = (_NB_PLAY_MEDAL)
//	CP	D			; �V�Z���_���������E�H
//	RET	NZ			; �@�m�n <�[���t���O�@�n�e�e>
//
//	LD	L,LOW _FL_GAME_STS
//	SET	5,(HL)			; �V�Z���_�����E�t���O�@�Z�b�g
//
//	RET				; <�[���t���O�@�n�m>
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0338-001					*
//;*	�@�\	      : �V�Z���_�����������P�����Z			*
//;*	Ӽޭ�ٖ�      : MS_CREDIT_DEC					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	A = �V�Z���_�����������\���f�[�^		*
//;*			DE = �V�Z���_�����������\���f�[�^�q�`�l�A�h���X	*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,DE						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_CREDIT_DEC:
//	LD	DE,_NB_CREDIT_LED
//	LD	A,(DE)
//	SUB	1			; �V�Z���_�����������@�|�P
//	DAA				; �P�O�i�ϊ�
//	LD	(DE),A
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0339-001					*
//;*	�@�\	      : ���Z�{�^���`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_CANCEL_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,DE,HL					*
//;*	�g�pӼޭ��    : MS_JAC_CHK,MS_STOPSW_CHK,S_IN0_CHK,S_BLOCKER_ON	*
//;*		      : S_BLOCKER_OFF,MS_1MEDAL_PAY,MS_CREDIT_DEC	*
//;************************************************************************
//;
//MS_CANCEL_CHK:
//	CALL	MS_JAC_CHK		; �𕨗V�Z�`�F�b�N
//	RET	NZ			; �𕨗V�Z���H�D�D�x�d�r
//
//	CALL	MS_STOPSW_CHK		; ��~�{�^���`�F�b�N
//	RET	NZ			; ��~�{�^���@���쒆�H�D�D�x�d�r
//
//	LD	B,00100111B		; �񓷉�]�n�����u�E�����{�^��
//					;;�X�C�b�`�@�`�F�b�N�v��
//	RST	S_IN0_CHK		; ���̓|�[�g�O���x���`�F�b�N
//	RET	NZ			; ���̑��̓��͂���H�D�D�x�d�r
//
//	LD	HL,_PT_IN0_UP
//	BIT	4,(HL)			; ���Z�{�^���X�C�b�`�@�n�m�H
//	RET	Z			; �@�m�n
//
//	RES	4,(HL)			; ���Z�{�^���X�C�b�`�����オ��
//					;;�f�[�^�@�N���A
//; ���Z�{�^����t
//
//	LD	L,LOW _FL_GAME_STS	; �񓷉�]�n�����u
//	RES	3,(HL)			;;��t���t���O�@�N���A
//
//	LD	DE,_NB_CREDIT_LED
//
//	BIT	4,(HL)			; �V�Z���_���������u�g�p���H
//	JR	Z,MS_CANCEL_CHK1	; �@�x�d�r
//
//; �V�Z���_���������u�ێg�p������g�p���ւ̐ؑւ�
//
//	RES	4,(HL)			; �V�Z���_���������u�ێg�p�t���O  �N���A
//
//	XOR	A			; // DE = _NB_CREDIT_LED
//	LD	(DE),A			; �V�Z���_�����������\���@�N���A
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//	RET
//
//; �V�Z���_���������u�g�p������ێg�p���ւ̐ؑւ�
//
//MS_CANCEL_CHK1:
//	SET	4,(HL)			; �V�Z���_���������u�ێg�p�t���O�@�Z�b�g
//	RES	7,(HL)			; ���Z�C�����t���O�@�N���A
//
//	LD	A,(DE)			; // DE = _NB_CREDIT_LED
//	AND	A			; �V�Z���_��������������H
//	JR	NZ,MS_CANCEL_CHK2	; �@�x�d�r
//
//; �V�Z���_�����������Ȃ��̏ꍇ
//
//	DEC	A			; // A = 0FFH , DE = _NB_CREDIT_LED
//	LD	(DE),A			; �V�Z���_�����������\���@����
//
//	BIT	5,(HL)			; �V�Z���_�����E���H
//	RET	Z			;   �m�n
//
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	RET
//
//; �V�Z���_��������������̏ꍇ
//
//MS_CANCEL_CHK2:
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//MS_CANCEL_CHK3:
//	CALL	MS_1MEDAL_PAY		; �V�Z���_���P�����o��
//
//	CALL	MS_CREDIT_DEC		; �V�Z���_�����������P�����Z
//
//	AND	A			; �V�Z���_��������������H
//	JR	NZ,MS_CANCEL_CHK3	; �@�x�d�r
//
//	DEC	A			; // A = 0FFH , DE = _NB_CREDIT_LED
//	LD	(DE),A			; �V�Z���_�����������\���@����
//
//	LD	A,(_FL_GAME_STS)
//	BIT	5,A			; �V�Z���_�����E���H
//	RET	NZ			;   �x�d�r
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0340-001					*
//;*	�@�\	      : �V�Z���_���P�����o��				*
//;*	Ӽޭ�ٖ�      : MS_1MEDAL_PAY					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : S_WATCH_CLEAR,S_IN0_CHK,MS_HPERR_SET		*
//;************************************************************************
//;
//MS_1MEDAL_PAY:
//	LD	HL,@TM_HOPPER3
//	LD	(_TM2_HE_CHK),HL	; �V�Z���_�����o���u
//					;;�쓮����  �Z�b�g
//	LD	HL,_PT_OUT1
//	SET	7,(HL)			; �V�Z���_�����o���u�쓮�J�n
//
//; �V�Z���_�����o�Z���T�[�M���n�e�e���̏���
//
//MS_1MEDAL_PAY1:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	BC,(_TM2_HE_CHK)
//	LD	A,B
//	OR	C			; �V�Z���_�����o���u�쓮���Ԓ��߁H
//	JR	Z,MS_1MEDAL_PAY3	; �@�x�d�r
//
//	LD	B,00001000B		; �V�Z���_�����o�Z���T�[�M��
//					;;�`�F�b�N�v��
//	RST	S_IN0_CHK		; ���̓|�[�g�O���x���`�F�b�N
//	JR	Z,MS_1MEDAL_PAY1	; �V�Z���_�����o�Z���T�[�ʉߊJ�n�H�D�D�m�n
//
//; �V�Z���_�����o�Z���T�[�M���n�e�e���n�m���̏���
//
//	LD	DE,_TM1_PAY
//	LD	A,@TM_HOPPER1		; �V�Z���_�����o�Z���T�[
//	LD	(DE),A			;;�`�F�b�N���ԁ@�Z�b�g
//
//; �V�Z���_�����o�Z���T�[�M���n�m���̏���
//
//MS_1MEDAL_PAY2:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	BC,(_TM2_HE_CHK)
//	LD	A,B
//	OR	C			; �V�Z���_�����o���u�쓮���Ԓ��߁H
//	JR	Z,MS_1MEDAL_PAY3	; �@�x�d�r
//
//	LD	A,(DE)			; // DE = _TM1_PAY
//	AND	A			; �V�Z���_���l�܂�H
//	JR	Z,MS_1MEDAL_PAY4	; �@�x�d�r
//
//	LD	B,00001000B		; �V�Z���_�����o�Z���T�[�M��
//					;;�`�F�b�N�v��
//	RST	S_IN0_CHK		; ���̓|�[�g�O���x���`�F�b�N
//	JR	NZ,MS_1MEDAL_PAY2	; �V�Z���_�����o�Z���T�[�ʉߏI���H�D�D�m�n
//
//; �V�Z���_�����o�Z���T�[�M���n�m���n�e�e���̏���
//
//	LD	A,(DE)			; // DE = _TM1_PAY
//	CP	@TM_HOPPER2		; �V�Z���_�����o�������H
//	JR	NC,MS_1MEDAL_PAY1	;   �x�d�r
//
//					; // HL = _PT_OUT1
//	RES	7,(HL)			; �V�Z���_�����o���u�쓮��~
//
//	RET
//
//	PAGE
//; �V�Z���_�����o�G���[����
//
//MS_1MEDAL_PAY3:
//	LD	D,0DAH			; �h�g�d�h�\���v��  �Z�b�g
//	JR	MS_1MEDAL_PAY5
//
//MS_1MEDAL_PAY4:
//	LD	D,0DBH			; �h�g�o�h�\���v���@�Z�b�g
//
//MS_1MEDAL_PAY5:
//					; // HL = _PT_OUT1
//	RES	7,(HL)			; �V�Z���_�����o���u�쓮��~
//
//	CALL	MS_HPERR_SET		; �V�Z���_�����o�G���[�Z�b�g
//
//	JR	MS_1MEDAL_PAY
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0341-001					*
//;*	�@�\	      : �V�Z���_�������`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_INSERT_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,C,HL						*
//;*	�g�pӼޭ��    : MS_SENSOR_CHK,S_WATCH_CLEAR,MS_MEDAL_INC	*
//;*		      : S_BLOCKER_OFF,S_LPSD_SET,S_BLOCKER_ON		*
//;************************************************************************
//;
//MS_INSERT_CHK:
//	LD	HL,_PT_OUT1
//	BIT	4,(HL)			; �V�Z���_���u���b�J�[�n�e�e�H
//	RET	Z			; �@�x�d�r
//
//	CALL	MS_SENSOR_CHK		; �V�Z���_�������Z���T�[�`�F�b�N
//	RET	Z			; �ʉ߂���H�D�D�m�n
//
//; �V�Z���_�������Z���T�[�ʉ߃`�F�b�N�J�n
//
//	LD	L,LOW _FL_GAME_STS	; �񓷉�]�n�����u
//	RES	3,(HL)			;;��t���t���O�@�N���A
//
//	CP	00010000B		; �V�Z���ٓ����ݻ��P�ʉߊJ�n�H
//	JP	NZ,MS_INSERT_CHK10	;   �m�n <�V�Z���_���s���ʉ�>
//
//; �V�Z���_�������Z���T�[�P�ʉߏ���
//
//	LD	L,LOW _TM1_MEDAL1	; �V�Z���_�������Z���T�[�P
//	LD	(HL),@TM_INSERT1	;;�ʉ߃`�F�b�N����  �Z�b�g
//
//MS_INSERT_CHK1:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_SENSOR_CHK		; �V�Z���_�������Z���T�[�`�F�b�N
//	CP	00110000B		; �V�Z���ٓ����ݻ��P�E�Q�ʉ߁H
//	JR	Z,MS_INSERT_CHK2	; �@�x�d�r
//
//	CP	00000000B		; �V�Z���ٓ����ݻ��M���n�e�e�H
//	RET	Z			;   �x�d�r
//
//	CP	00010000B		; �V�Z���ٓ����ݻ��P�ʉߒ��H
//	JR	NZ,MS_INSERT_CHK10	;   �m�n <�V�Z���_���s���ʉ�>
//
//	LD	A,(HL)			; // HL = _TM1_MEDAL1
//	AND	A			; �V�Z���ٓ����ݻ��P�ʉߎ��Ԓ��߁H
//	JR	Z,MS_INSERT_CHK8	;   �x�d�r <�V�Z���_���ؗ�>
//
//	JR	MS_INSERT_CHK1
//
//; �V�Z���_�������Z���T�[�P�E�Q�ʉߏ���
//
//MS_INSERT_CHK2:
//	LD	L,LOW _TM1_MEDAL2	; �V�Z���_�������Z���T�[�Q
//	LD	(HL),@TM_INSERT3	;;�ʉ߃`�F�b�N����  �Z�b�g
//
//MS_INSERT_CHK3:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_SENSOR_CHK		; �V�Z���_�������Z���T�[�`�F�b�N
//	CP	00100000B		; �V�Z���ٓ����ݻ��Q�ʉߊJ�n�H
//	JR	Z,MS_INSERT_CHK4	;   �x�d�r
//
//	CP	00110000B		; �V�Z���ٓ����ݻ��P�E�Q�ʉߒ��H
//	JR	NZ,MS_INSERT_CHK10	;   �m�n <�V�Z���_���s���ʉ�>
//
//	LD	A,(HL)			; // HL = _TM1_MEDAL2
//	CP	@TM_INSERT2		; �V�Z���ٓ����ݻ��Q�ʉߎ��Ԓ��߁H
//	JR	C,MS_INSERT_CHK8	;   �x�d�r <�V�Z���_���ؗ�>
//
//	LD	A,(_TM1_MEDAL1)
//	AND	A			; �V�Z���ٓ����ݻ��P�ʉߎ��Ԓ��߁H
//	JR	Z,MS_INSERT_CHK8	;   �x�d�r <�V�Z���_���ؗ�>
//
//	JR	MS_INSERT_CHK3
//
//; �V�Z���_�������Z���T�[�Q�ʉߏ���
//
//MS_INSERT_CHK4:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_SENSOR_CHK		; �V�Z���_�������Z���T�[�`�F�b�N
//
//	JR	Z,MS_INSERT_CHK5	; �V�Z���ٓ����ݻ��ʉߏI���H�D�D�x�d�r
//
//	CP	00100000B		; �V�Z���ٓ����ݻ��Q�ʉߒ��H
//	JR	NZ,MS_INSERT_CHK10	;   �m�n <�V�Z���_���s���ʉ�>
//
//	LD	A,(HL)			; // HL = _TM1_MEDAL2
//	AND	A			; �V�Z���ٓ����ݻ��Q�ʉߎ��Ԓ��߁H
//	JR	Z,MS_INSERT_CHK8	;   �x�d�r <�V�Z���_���ؗ�>
//
//	JR	MS_INSERT_CHK4
//
//; �V�Z���_���ʉ߃Z�b�g
//
//MS_INSERT_CHK5:
//	LD	L,LOW _FL_GAME_STS
//	RES	7,(HL)			; ���Z�C�����t���O�@�N���A
//	BIT	5,(HL)			; �V�Z���_�����E�H
//	JR	NZ,MS_INSERT_CHK6	; �@�x�d�r
//
//	CALL	MS_MEDAL_INC		; �V�Z���_���P�����Z
//
//	RET	NZ			; �V�Z���_�����E�H�D�D�m�n
//
//	LD	HL,_FL_GAME_STS
//	BIT	4,(HL)			; �V�Z���_���������u�g�p���H
//	JR	Z,MS_INSERT_CHK7	; �@�x�d�r
//
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	RET
//
//MS_INSERT_CHK6:
//	LD	A,@SET_INCO		; �V�Z���_����������
//					;;�o�͗v��  �Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	LD	L,LOW _NB_CREDIT_LED
//	LD	A,(HL)
//	ADD	A,1
//	DAA
//	LD	(HL),A			; �V�Z���_�����������@�{�P
//
//MS_INSERT_CHK7:
//	LD	L,LOW _NB_CREDIT_LED
//	LD	A,(HL)
//	CP	50H 			; �V�Z���_�������������E�H
//	RET	C			; �@�m�n
//
//	LD	(HL),50H		; �V�Z���_�����������T�O���@�Z�b�g
//
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	RET
//
//; �V�Z���_�������G���[�����i�V�Z���_���ؗ��j
//
//MS_INSERT_CHK8:
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	LD	L,LOW _NB_PAY_LED
//	LD	C,(HL)			; �V�Z���_�����o�������\��  �ޔ�
//
//	LD	(HL),0CAH		; �h�b�d�h�\��  �Z�b�g
//
//MS_INSERT_CHK9:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	CALL	MS_SENSOR_CHK		; �V�Z���_�������Z���T�[�`�F�b�N
//
//	JR	NZ,MS_INSERT_CHK9	; �V�Z���_���ؗ������H�D�D�m�n
//
//	LD	(HL),C			; �V�Z���_�����o�������\��  ���A
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//	RET
//
//; �V�Z���_�������G���[�����i�V�Z���_���s���ʉ߁j
//
//MS_INSERT_CHK10:
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	LD	L,LOW _NB_PAY_LED
//	LD	C,(HL)			; �V�Z���_�����o�������\��  �ޔ�
//
//	LD	(HL),0CBH		; �h�b�o�h�\��  �Z�b�g
//
//MS_INSERT_CHK11:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_PT_IN1_UP)
//	AND	00001010B		; �G���[�����H
//	JR	Z,MS_INSERT_CHK11	; �@�m�n
//
//	LD	(HL),C			; �V�Z���_�����o�������\��  ���A
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0342-001					*
//;*	�@�\	      : �񓷉�]�n�����u�`�F�b�N			*
//;*	Ӽޭ�ٖ�      : MS_START_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Cflag ON = ��t					*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,E,HL					*
//;*	�g�pӼޭ��    : MS_STOPSW_CHK,S_IN0_CHK,MS_IN_OUT_DOWN		*
//;************************************************************************
//;
//MS_START_CHK:
//	CALL	MS_STOPSW_CHK		; ��~�{�^���`�F�b�N
//	JR	NZ,MS_START_CHK2	; ��~�{�^���@���쒆�H�D�D�x�d�r
//					; �i�L�����[�t���O  �n�e�e�j
//
//	LD	B,00010111B		; ���Z�{�^���E�����{�^��
//					;;�X�C�b�`�@�`�F�b�N�v��
//	RST	S_IN0_CHK		; ���̓|�[�g�O���x���`�F�b�N
//	JR	NZ,MS_START_CHK2	; ���̑��̓��͂���H�D�D�x�d�r
//					; �i�L�����[�t���O  �n�e�e�j
//
//	LD	HL,(_PT_IN0_OLD)	; // H = (_PT_IN0_UP),L = (_PT_IN0_OLD)
//	LD	A,H
//	XOR	L
//	BIT	5,A			; �񓷉�]�n�����u�����p��ON��ԁH
//	JR	NZ,MS_START_CHK2	;   �x�d�r <�L�����[�t���O  �n�e�e>
//
//	LD	HL,_FL_GAME_STS		; �񓷉�]�n�����u
//	SET	3,(HL)			;;��t���t���O�@�Z�b�g
//
//	LD	L,LOW _PT_IN0_UP
//	BIT	5,(HL)			; �񓷉�]�n�����u�X�C�b�`�@�n�m�H
//	RET	Z			;   �m�n
//
//	LD	L,LOW _NB_PLAY_MEDAL	; �V�Z���_�����������@�Z�b�g
//	LD	E,(HL)
//MS_START_CHK1:
//	CALL	MS_IN_OUT_DOWN		; �������̍������J�E���^�X�V
//	DEC	E
//	JR	NZ,MS_START_CHK1	; �����������I���H�D�D�m�n
//
//; �񓷉�]�n�����u��t�i�n�[�h�E�F�A�����ǂݍ��݁j
//
//	LD	BC,11000000B*100H OR @IN3_PORT
//
//	DI				; ���荞�݋֎~
//
//	IN	L,(C)
//	INC	C
//	IN	A,(C)			; �n�[�h�E�F�A�����P�ǂݍ���
//	OR	B			; �n�[�h�E�F�A�����P
//					;;��ʂQ�r�b�g�@�n�m
//	LD	H,A
//
//	LD	(_BF_RAND1),HL		; ��ʗV�Z�}�����I�p�����ۑ�<49152 - 65535>
//
//	INC	C
//	IN	L,(C)
//	INC	C
//	IN	A,(C)			; �n�[�h�E�F�A�����Q�ǂݍ���
//	OR	B			; �n�[�h�E�F�A�����Q
//					;;��ʂQ�r�b�g �n�m
//	LD	H,A
//
//	LD	(_BF_RAND2),HL		; �𕨗V�Z�}�����I�p�����ۑ�<49152 - 65535>
//
//	EI				; ���荞�݋���
//
//	SCF				; �L�����[�t���O  �n�m
//
//MS_START_CHK2:
//	LD	HL,_FL_GAME_STS		; �񓷉�]�n�����u
//	RES	3,(HL)			;;��t���t���O�@�N���A
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0343-001					*
//;*	�@�\	      : �������̍������J�E���^�X�V			*
//;*	Ӽޭ�ٖ�      : MS_IN_OUT_DOWN					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    : 						*
//;*	�ی�ڼ޽�     : 						*
//;*	�j��ڼ޽�     : A,BC,HL						*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//MS_IN_OUT_DOWN:
//	LD	A,(_FL_ACTION)
//	AND	@_BNS OR @_RP		; �{�[�i�X�Q�[�����ėV�Z�쓮���H
//	RET	NZ			; �@�x�d�r
//
//	LD	HL,TBL_IN_OUT - 1	; �X�Βl�f�[�^�e�[�u���@�Z�b�g
//	LD	A,(_NB_RANK)		; �ݒ�l�@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	C,(HL)			; �X�Βl�@�Z�b�g
//	LD	B,0
//
//	LD	HL,(_CT_IN_OUT)		; �������J�E���^�@�Z�b�g
//	LD	A,H
//	CPL
//	AND	A
//	SBC	HL,BC			; �������J�E���^�@�|�@�X�Βl
//	OR	H
//	RLCA				; �������J�E���^�͈͊O�H
//	JR	C,MS_IN_OUT_DOWN1	; �@�m�n
//
//	LD	HL,8000H		; �������J�E���^�̍ŏ��l�@�Z�b�g
//
//MS_IN_OUT_DOWN1:
//	LD	(_CT_IN_OUT),HL		; �������J�E���^�X�V
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0344-001					*
//;*	�@�\	      : �V�Z���_����������				*
//;*	Ӽޭ�ٖ�      : MS_AUTO_IN					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,HL						*
//;*	�g�pӼޭ��    : S_WATCH_CLEAR,MS_MEDAL_INC			*
//;************************************************************************
//;
//MS_AUTO_IN:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	HL,(_TM2_REPLAY_ML)
//	LD	A,H
//	OR	L			; �V�Z���_�����������ҋ@���H
//	JR	NZ,MS_AUTO_IN		; �@�x�d�r
//
//	LD	HL,_PT_OUT2
//	SET	4,(HL)			; �ėV�Z�\�������v�_���@�Z�b�g
//
//	CALL	MS_MEDAL_INC		; �V�Z���_���P�����Z
//
//	RET	Z			; �V�Z���_�����E�H�D�D�x�d�r
//
//	LD	HL,@TM_REPLAY2
//	LD	(_TM2_REPLAY_ML),HL	; �V�Z���_����������
//					;;�ҋ@����  �Z�b�g
//	JR	MS_AUTO_IN
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0345-002					*
//;*	�@�\	      : �O���M���o�͗v��				*
//;*	Ӽޭ�ٖ�      : MS_SCOUNT_OUT					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,E,HL					*
//;*	�g�pӼޭ��    : MS_JAC_CHK,SS_ERROR_STOP�i�W�����v�j		*
//;************************************************************************
//;
//MS_SCOUNT_OUT:
//
//; �V�Z���_�����������`�F�b�N
//
//	LD	B,1			; �V�Z���_���`�F�b�N���P���@�Z�b�g
//
//	CALL	MS_JAC_CHK		; �𕨗V�Z�`�F�b�N
//	JR	NZ,MS_SCOUNT_OUT1	; �𕨗V�Z���H�D�D�x�d�r
//
//	LD	B,3			; �V�Z���_���`�F�b�N���R���@�Z�b�g
//
//MS_SCOUNT_OUT1:
//	LD	A,(_NB_PLAY_MEDAL)
//	DEC	A
//	CP	B			; �V�Z���_����������͈́H
//	JR	C,MS_SCOUNT_OUT2	;   �x�d�r
//
//	LD	E,66H			; �h�d�S�h�\���v��  �Z�b�g
//	JP	SS_ERROR_STOP
//
//; �V�Z���_�������M���񐔁@�Z�b�g
//
//MS_SCOUNT_OUT2:
//	LD	HL,_FL_ACTION
//	BIT	@BT_RP,(HL)		; �ėV�Z�쓮���H
//	RET	NZ			; �@�x�d�r
//
//	LD	L,LOW _CT_MEDAL_IN
//	INC	A			; // A = (_NB_PLAY_MEDAL)
//	ADD	A,A
//
//	DI				; ���荞�݋֎~
//
//	ADD	A,(HL)
//	LD	(HL),A			; �V�Z���_�������M��
//					;;�o�͉�  �Z�b�g
//	EI				; ���荞�݋���
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0346-001					*
//;*	�@�\	      : �ŒZ�V�Z���ԃ`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_WAIT_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Cflag ON = �񓷉�]����				*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,HL						*
//;*	�g�pӼޭ��    : S_LPSD_SET					*
//;************************************************************************
//;
//MS_WAIT_CHK:
//	LD	HL,(_TM2_GAME)
//	LD	A,H
//	OR	L			; �ŒZ�V�Z���Ԍo�߁H
//
//	LD	HL,_PT_OUT1
//	JR	NZ,MS_WAIT_CHK1		; �@�m�n
//
//	RES	5,(HL)			; �E�G�C�g�\�������v�����@�Z�b�g
//
//	LD	HL,@TM_GAME
//	LD	(_TM2_GAME),HL		; �ŒZ�V�Z����  �Z�b�g
//
//	SCF				; �L�����[�t���O�@�n�m
//
//	RET
//
//MS_WAIT_CHK1:
//	LD	A,(HL)			; // HL = _PT_OUT1
//	AND	00100000B		; �E�G�C�g�\�������v�_�����H
//	RET	NZ			;   �x�d�r <�L�����[�t���O  �n�e�e>
//
//	SET	5,(HL)			; �E�G�C�g�\�������v�_���@�Z�b�g
//
//	LD	A,@SET_WAIT		; �񓷉�]�s���̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	AND	A			; �L�����[�t���O  �n�e�e
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0347-001					*
//;*	�@�\	      : �񓷉�]�J�n����				*
//;*	Ӽޭ�ٖ�      : MS_REEL_READY					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,HL						*
//;*	�g�pӼޭ��    : S_LPSD_SET,S_ADDR_SET				*
//;************************************************************************
//;
//; # = ���䒆�̉񓷔ԍ� (= 3,2,1)
//;
//MS_REEL_READY:
//	LD	A,@SET_START		; �񓷉�]�J�n���̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	LD	B,3			; �񓷐�  �Z�b�g
//	LD	HL,_WK_REEL1 + 7
//MS_REEL_READY1:
//	INC	(HL)
//	INC	(HL)
//	INC	(HL)
//	INC	(HL)			; �񓷋쓮�p���X�f�[�^
//					;;�����p�J�E���^�@�{�S
//	RES	0,(HL)			; �񓷉�]�J�n���̗㎥�o�͂P���@�Z�b�g
//
//	LD	A,_WK_REEL2 - _WK_REEL1	; // A = 8
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	DJNZ	MS_REEL_READY1		; �S�񓷏I���H�D�D�m�n
//
//	LD	HL,@TM_AUTOSTOP
//	LD	(_TM2_AUTOSTOP),HL	; �񓷎�����~���ԁ@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0348-001					*
//;*	�@�\	      : �񓷉�]�J�n					*
//;*	Ӽޭ�ٖ�      : MS_REEL_START					*
//;*	�������Ұ�    : A = ��]�J�n��(XXX00000B)			*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//; # = �Z�b�g���̉񓷔ԍ� (= 3,2,1)
//;
//MS_REEL_START:
//	LD	HL,_WK_REEL3
//	LD	DE,_WK_REEL2-_WK_REEL1	; // E = 8 , D = 0
//	LD	BC,0301H		; �񓷐� �Z�b�g
//					; // C = 1
//	DI				; ���荞�݋֎~
//MS_REEL_START1:
//	RLCA				; ��]�J�n�񓷁H
//	JR	NC,MS_REEL_START2	; �@�m�n
//
//	PUSH	HL			; // HL = _WK_REEL# + 0
//	LD	(HL),C			; ������ԁ@�Z�b�g
//	INC	HL			; // HL = _WK_REEL# + 1
//	LD	(HL),C			; �񓷋쓮�p���X�o�͎��ԁ@������
//	INC	HL			; // HL = _WK_REEL# + 2
//	LD	(HL),18 + 1		; �������̉񓷋쓮�p���X�ؑւ��񐔁@�Z�b�g
//	INC	HL			; // HL = _WK_REEL# + 3
//	LD	(HL),D			; �葬���̉񓷃Z���T�[�ʉ߃t���O�@������
//	INC	HL			; // HL = _WK_REEL# + 4
//	LD	(HL),20			; �P�}���̃X�e�b�v�ԍ��@������
//	INC	HL			; // HL = _WK_REEL# + 5
//	LD	(HL),D			; �}���ԍ��i�ʉ߈ʒu�p�j�@������
//	POP	HL
//
//MS_REEL_START2:
//	AND	A			; <�L�����[�t���O�@�n�e�e>
//	SBC	HL,DE			; ���̉񓷐���f�[�^�q�`�l�A�h���X�@�Z�b�g
//	DJNZ	MS_REEL_START1		; �S�񓷃Z�b�g�I���H�D�D�m�n
//
//	EI				; ���荞�݋���
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0349-001					*
//;*	�@�\	      : �񓷉�]�G���[�`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_RLERR_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Cflag ON = �񓷍ċN��				*
//;*		      : A = �ċN���񓷃r�b�g				*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//; # = �`�F�b�N���̉񓷔ԍ� (= 1,2,3)
//;
//MS_RLERR_CHK:
//	LD	HL,_WK_REEL1
//	LD	DE,_WK_REEL2-_WK_REEL1	; // DE = 8
//	LD	BC,320H			; �񓷐��y�э��񓷃r�b�g  �Z�b�g
//					; // C = ���񓷉񓷃r�b�g  �Z�b�g
//MS_RLERR_CHK1:
//	LD	A,(HL)			; // HL = _WK_REEL# + 0
//	CP	2			; �񓷒葬��]���H
//	JR	NZ,MS_RLERR_CHK2	; �@�m�n
//
//	PUSH	HL
//	LD	A,5			; �}���ԍ��i�ʉ߈ʒu�p�j
//					;;�v��  �Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(HL)			; // HL = _WK_REEL# + 5
//	POP	HL
//	CP	23			; �񓷃Z���T�[�ʉߍς݁H
//					; �i23 = �P�񓷐}�����{�o���I���S�l�j
//	JR	C,MS_RLERR_CHK2		; �@�x�d�r
//
//	LD	A,C			; �ċN���񓷃r�b�g�@�Z�b�g
//
//	SCF				; �L�����[�t���O  �n�m
//
//	RET
//
//MS_RLERR_CHK2:
//	SLA	C			; ���񓷂̉񓷃r�b�g  �Z�b�g
//	ADD	HL,DE
//	DJNZ	MS_RLERR_CHK1		; �S�񓷏I���H�D�D�m�n
//
//	RET				; <�L�����[�t���O  �n�e�e>
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0350-001					*
//;*	�@�\	      : �񓷒葬�`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_RLFIX_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Cflag ON = �񓷒�~�\�i�S�񓷃Z���T�[�ʉ߁j	*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,DE,HL						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_RLFIX_CHK:
//	LD	HL,_WK_REEL1 + 3
//	LD	DE,_WK_REEL2-_WK_REEL1	; // DE = 8
//	LD	A,(HL)
//	ADD	HL,DE			; // HL = _WK_REEL2 + 3
//	AND	(HL)
//	ADD	HL,DE			; // HL = _WK_REEL3 + 3
//	AND	(HL)			; �S�񓷃Z���T�[�ʉ߁H
//	RET	Z			;   �m�n <�L�����[�t���O  �n�e�e>
//
//	SCF				; �L�����[�t���O�@�n�m
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0351-001					*
//;*	�@�\	      : �񓷒�~��t�`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_STOP_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Cflag ON=�񓷒�~��t				*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : S_IN0_CHK,MS_STOPSW_CHK,MS_STOP_LED,S_LPSD_SET	*
//;************************************************************************
//;
//MS_STOP_CHK:
//	LD	A,(_TM1_STOP)
//	AND	A			; �񓷒�~��t�҂��H
//	RET	NZ			;   �x�d�r < �L�����[�t���O�@�n�e�e >
//
//; ������~���f
//
//	LD	HL,(_TM2_AUTOSTOP)
//	LD	A,H
//	OR	L			; �񓷎�����~���ԁH
//
//
//	LD	HL,_FL_STOP_LP
//
//	JR	NZ,MS_STOP_CHK2		; �@�m�n
//
//	LD	BC,320H			; �񓷐��y�э��񓷃r�b�g�@�Z�b�g
//MS_STOP_CHK1:
//	LD	A,C
//	AND	(HL)			; �񓷉�]���H
//	JR	NZ,MS_STOP_CHK5		; �@�x�d�r
//
//	SLA	C			; ���̉񓷃r�b�g  �Z�b�g
//	DJNZ	MS_STOP_CHK1		; �S�񓷏I���H�D�D�m�n
//
//	AND	A			; �L�����[�t���O  �n�e�e
//
//	RET
//
//; ��~�{�^�����f
//
//MS_STOP_CHK2:
//	LD	B,00110111B		; �񓷉�]�n�����u�E���Z�{�^���E
//					;;�����{�^���X�C�b�`�`�F�b�N�v��
//	RST	S_IN0_CHK		; ���̓|�[�g�O���x���`�F�b�N
//	JR	NZ,MS_STOP_CHK4		; ���̑��̓��͂���H�D�D�x�d�r
//
//	LD	A,(HL)			; // HL = _FL_STOP_LP
//
//	CPL
//	LD	B,A
//
//	CALL	MS_STOPSW_CHK		; ��~�{�^���`�F�b�N
//	AND	B			; ��t�ςݒ�~�{�^�����쒆�H
//	JR	NZ,MS_STOP_CHK4		;�@ �x�d�r
//
//	LD	DE,(_PT_IN2_OLD)	; // D = (_PT_IN2_UP), E = (_PT_IN2_OLD)
//	LD	A,D
//	XOR	E
//	CPL
//	AND	11100000B		; ��~�{�^���p�����쒆�H
//	JR	NZ,MS_STOP_CHK4		;�@ �x�d�r
//
//	LD	A,D			; // D = (_PT_IN2_UP)
//	AND	(HL)			; // HL = _FL_STOP_LP
//	LD	D,A			; ��~�{�^����t�t���O�@�Z�b�g
//	LD	BC,320H			; �񓷐��y�э��񓷃r�b�g�@�Z�b�g
//MS_STOP_CHK3:
//	LD	A,C
//	AND	D			; ��~�{�^����t�H
//	JR	NZ,MS_STOP_CHK5		;   �x�d�r
//
//	SLA	C			; ���̉񓷃r�b�g�@�Z�b�g
//	DJNZ	MS_STOP_CHK3		; �S�񓷏I���H�D�D�m�n
//
//	LD	A,(HL)			; // HL = _FL_STOP_LP
//	RRCA
//	RRCA
//	CPL
//	AND	00111000B
//	LD	B,A
//	LD	A,(HL)			; // HL = _FL_STOP_LP
//	RLCA
//	RLCA
//	RLCA
//	AND	00000111B
//	OR	B
//
//	LD	B,A			; ��~�{�^���k�d�c�_���v���@�Z�b�g
//	CALL	MS_STOP_LED		; ��~�{�^���k�d�c�\��
//
//	AND	A			; �L�����[�t���O  �n�e�e
//
//	RET
//
//MS_STOP_CHK4:
//	LD	B,00111000B		; ��~�{�^���k�d�c�_���v���@�Z�b�g
//	CALL	MS_STOP_LED		; ��~�{�^���k�d�c�\��
//
//	AND	A			; �L�����[�t���O  �n�e�e
//
//	RET
//
//; ��~��t����
//
//MS_STOP_CHK5:
//	LD	A,C			; �񓷃r�b�g�@�Z�b�g
//	XOR	(HL)			; // HL = _FL_STOP_LP
//	LD	(HL),A			; �񓷒�~�t���O�@�Z�b�g
//
//	LD	L,LOW _NB_STOP_ORDER
//	INC	(HL)			; �񓷒�~���ԁ@�{�P
//	INC	HL			; // HL = _NB_STOP_REEL
//	LD	A,4
//	SUB	B
//	LD	(HL),A			; ��~�񓷔ԍ��@�Z�b�g
//
//	LD	B,00111000B		; ��~�{�^���k�d�c�_���v���@�Z�b�g
//	CALL	MS_STOP_LED		; ��~�{�^���k�d�c�\��
//
//	LD	A,@TM_STOPWAIT
//	LD	(_TM1_STOP),A		; �񓷒�~��t�ҋ@���ԁ@�Z�b�g
//
//	LD	A,@SET_STOP		; ��~�{�^����t����
//					;;�o�͗v��  �Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	SCF				; �L�����[�t���O  �n�m
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0352-001					*
//;*	�@�\	      : �S�񓷒�~�`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_RLSTP_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	Zflag ON = �S�񓷒�~				*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,DE,HL						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_RLSTP_CHK:
//	LD	HL,_WK_REEL1
//	LD	DE,_WK_REEL2-_WK_REEL1	; // DE = 8
//	LD	A,(HL)
//	ADD	HL,DE			; // HL = _WK_REEL2 + 0
//	OR	(HL)
//	ADD	HL,DE			; // HL = _WK_REEL3 + 0
//	OR	(HL)			; �S�񓷒�~�`�F�b�N
//
//	RET				; �[���t���O�@�n�m�^�n�e�e
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0353-003					*
//;*	�@�\	      : ���ܔ���					*
//;*	Ӽޭ�ٖ�      : MS_WIN_JUDGE					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,HL						*
//;*	�g�pӼޭ��    : MS_BNS_CHK,MS_LINE_JUDGE,S_RAM_CLEAR		*
//;*		      : S_WATCH_CLEAR					*
//;************************************************************************
//;
//MS_WIN_JUDGE:
//	LD	HL,TBL_WIN_CTL1		; �𕨘A���쓮�������u���쓮��
//					;;��ʗV�Z���܏����e�[�u���@�Z�b�g
//
//	CALL	MS_BNS_CHK		; �{�[�i�X�Q�[���`�F�b�N
//	JR	Z,MS_WIN_JUDGE1		; �{�[�i�X�Q�[���H�D�D�m�n
//
//	LD	HL,TBL_WIN_CTL2		; �𕨘A���쓮�������u�쓮��
//					;;��ʗV�Z���܏����e�[�u���@�Z�b�g
//	AND	@_JAC			; �𕨗V�Z���H
//	JR	Z,MS_WIN_JUDGE1		;   �m�n
//
//	LD	HL,TBL_WIN_CTL3		; �𕨗V�Z���܏����e�[�u���@�Z�b�g
//
//MS_WIN_JUDGE1:
//	LD	A,(_NB_PLAY_MEDAL)
//	ADD	A,A
//	DEC	A
//	LD	B,A			; �L�����C����  �Z�b�g
//MS_WIN_JUDGE2:
//	PUSH	HL
//	CALL	MS_LINE_JUDGE		; �P���C�����ܔ���
//	POP	HL
//
//	DJNZ	MS_WIN_JUDGE2		; �S�L�����C���I���H�D�D�m�n
//
//	LD	A,(_FL_WIN)
//	BIT	@BT_BB,A		; �a�a���܁H
//	JR	Z,MS_WIN_JUDGE3		;   �m�n
//
//	DI				; ���荞�݋֎~
//
//	LD	HL,TBL_RAM_CLEAR3	; �𕨘A���쓮�������u���܎���
//					;;�q�`�l�������e�[�u���@�Z�b�g
//	RST	S_RAM_CLEAR		; �q�`�l������ <8062H - 808EH>
//
//	EI				; ���荞�݋���
//
//MS_WIN_JUDGE3:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_WK_FLASH_LP)
//	CP	@FLP_BBHIT1		;
//	JR	NC,MS_WIN_JUDGE3	; �@�x�d�r
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0354-001					*
//;*	�@�\	      : �P���C�����ܔ���				*
//;*	Ӽޭ�ٖ�      : MS_LINE_JUDGE					*
//;*	�������Ұ�    : B = ���胉�C���ԍ�				*
//;*		      : HL = ���܏����e�[�u��				*
//;*	�o�����Ұ�    :	E = �G���[�\���f�[�^�i���ʌ��j			*
//;*	�ی�ڼ޽�     :	B						*
//;*	�j��ڼ޽�     :	A,C,DE,HL					*
//;*	�g�pӼޭ��    : SS_ERROR_STOP�i�W�����v�j,S_LPSD_SET,S_ADDR_SET	*
//;************************************************************************
//;
//MS_LINE_JUDGE:
//	LD	C,(HL)			; ����}����  �Z�b�g
//	INC	HL
//
//MS_LINE_JUDGE1:
//	LD	A,B			; ���胉�C���ԍ�  �Z�b�g
//	ADD	A,(HL)
//	LD	D,HIGH @RAM		; <�q�`�l��ʃA�h���X>
//	LD	E,A
//	INC	HL
//	LD	A,(DE)			; ��~�}���f�[�^�@�Z�b�g
//	AND	(HL)			; ���܁A���͕\������H
//	JR	Z,MS_LINE_JUDGE3	;   �m�n
//
//	LD	C,A			; ���ܐ}���f�[�^�@�Z�b�g
//	INC	HL
//	LD	E,(HL)
//	LD	A,(DE)			; �R��΂��}���f�[�^�@�Z�b�g
//	AND	C
//	LD	E,6DH			; �h�d�T�h�\���v��  �Z�b�g
//	JP	NZ,SS_ERROR_STOP	; �R��΂��}�������܁H�D�D�x�d�r
//
//	INC	HL
//	LD	E,LOW _FL_WIN
//	LD	A,(DE)
//	OR	(HL)
//	LD	(DE),A			; ���܃t���O  �Z�b�g
//
//	INC	HL
//	LD	A,(HL)			; ���܎��̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	INC	HL
//	LD	A,(HL)			; �P���C���̗V�Z���_�����o������  �Z�b�g
//
//	INC	HL
//	LD	C,(HL)			; �o�b�N�����v���܃��C���\��
//					;;�T�[�`�|�C���^�@�Z�b�g
//
//	LD	HL,_NB_PAY_MEDAL	; ���̑��̃��C����
//	ADD	A,(HL)			;;�V�Z���_�����o�����������Z
//	CP	15			; �V�Z���_�����o�����v�P�T���ȏ�H
//	JR	C,MS_LINE_JUDGE2	; �@�m�n
//
//	LD	A,15			; �V�Z���_�����o�����v�P�T���ɕ␳
//
//MS_LINE_JUDGE2:
//	LD	(HL),A			; �V�Z���_�����o�������@�Z�b�g
//
//	LD	A,B			; ���胉�C���ԍ�  �Z�b�g
//	LD	HL,TBL_WIN_LINE-1	; �L�����C�������v���܃��C��
//					;;�\���e�[�u���v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(HL)
//	LD	HL,_WK_WIN_LP
//	OR	(HL)			; ���܎��L�����C�������v
//	LD	(HL),A			;;�_�Ńf�[�^�@�Z�b�g
//
//	LD	HL,TBL_WINBACK_LINE-2	; �o�b�N�����v���܃��C���\��
//					;;�e�[�u���v���@�Z�b�g
//	LD	A,B			; ���胉�C���ԍ��@�Z�b�g
//	ADD	A,A
//	ADD	A,C			; �o�b�N�����v���܃��C���\��
//					;;�T�[�`�|�C���^���Z
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	A,(HL)			; �o�b�N�����v�X�_�ŗp
//					;;�f�[�^�@�Z�b�g
//	INC	HL
//	LD	C,(HL)			; �o�b�N�����v�P�`�W�_�ŗp
//					;;�f�[�^�@�Z�b�g
//	LD	HL,_WK_WINBACK_LP
//	OR	(HL)
//	LD	(HL),A			; ���܎��o�b�N�����v�X�_��
//					;;�f�[�^�@�Z�b�g
//	LD	A,C
//	INC	HL
//	OR	(HL)
//	LD	(HL),A			; ���܎��o�b�N�����v�P�`�W�_��
//					;;�f�[�^�@�Z�b�g
//	RET
//
//MS_LINE_JUDGE3:
//	LD	A,6			; ���̓��ܐ}������v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	DEC	C			; ����I���H
//	JR	NZ,MS_LINE_JUDGE1	;   �m�n
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0355-003					*
//;*	�@�\	      : ���܂ɂ��V�Z���_�����o��			*
//;*	Ӽޭ�ٖ�      : MS_WIN_PAY					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,DE,HL						*
//;*	�g�pӼޭ��    : MS_BNS_CHK,S_LPSD_SET,MS_IN_OUT_UP		*
//;*		      : S_WATCH_CLEAR,MS_1MEDAL_PAY			*
//;************************************************************************
//;
//MS_WIN_PAY:
//
//; �㕔�����v�E���ʃ����v�\���y�їV�Z���_�����o�M���񐔃Z�b�g
//
//	LD	HL,_NB_PAY_MEDAL	; �V�Z���_�����o�������@�Z�b�g
//	LD	A,(HL)
//	AND	A			; �V�Z���_�����o������H
//	RET	Z			;   �m�n
//
//	CALL	MS_BNS_CHK		; �{�[�i�X�Q�[���`�F�b�N
//	JR	NZ,MS_WIN_PAY1		; �{�[�i�X�Q�[���H�D�D�x�d�r
//
//	LD	A,@SET_PAYSTART		; ���܂ɂ��V�Z���_�����o��
//					;;�J�n���̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//MS_WIN_PAY1:
//	LD	DE,_CT_MEDAL_OUT
//
//	DI				; ���荞�݋֎~
//
//	LD	A,(DE)
//	ADD	A,(HL)
//	ADD	A,(HL)
//	LD	(DE),A			; �V�Z���_�����o�M���񐔁@�Z�b�g
//
//	EI				; ���荞�݋���
//
//; �V�Z���_�����o�����[�h�I��
//MS_WIN_PAY2:
//	CALL	MS_IN_OUT_UP		; ���o�����̍������J�E���^�X�V
//
//	LD	HL,_FL_GAME_STS
//	BIT	4,(HL)			; �V�Z���_���������u�ێg�p���H
//	JR	NZ,MS_WIN_PAY4		; �@�x�d�r
//
//	LD	A,(_NB_CREDIT_LED)
//	CP	50H			; �V�Z���_�������������E�H
//	JR	NC,MS_WIN_PAY4		; �@�x�d�r
//
//; �V�Z���_�����������T�O�������̎��͗V�Z���_���������u�ɉ��Z
//
//	LD	L,LOW _TM1_CREDIT	; �V�Z���_����������
//	LD	(HL),@TM_CREDIT		;;���Z�ҋ@���ԁ@�Z�b�g
//
//MS_WIN_PAY3:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(HL)			; // HL = _TM1_CREDIT
//	AND	A			; �V�Z���_�������������Z�҂��H
//	JR	NZ,MS_WIN_PAY3		;   �x�d�r
//
//	LD	L,LOW _NB_CREDIT_LED
//	LD	A,(HL)
//	ADD	A,1
//	DAA
//	LD	(HL),A			; �V�Z���_�����������@�{�P
//
//	JR	MS_WIN_PAY5
//
//; �V�Z���_�����o���u����̗V�Z���_�����o��
//
//MS_WIN_PAY4:
//	CALL	MS_1MEDAL_PAY		; �V�Z���_���P�����o��
//
//MS_WIN_PAY5:
//	LD	A,@SET_PAY		; ���܂ɂ��V�Z���_���P��
//					;;���o�����̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	LD	HL,_NB_PAY_LED
//	LD	A,(HL)
//	ADD	A,1
//	DAA
//	LD	(HL),A			; �V�Z���_�����o�������\���@�{�P
//
//	LD	L,LOW _NB_PAY_MEDAL
//	DEC	(HL)			; �V�Z���_�����o�������@�|�P
//	JR	NZ,MS_WIN_PAY2		; �V�Z���_�����o���I���H�D�D�m�n
//
//	LD	A,(_WK_FLASH_LP)	; �V�Z���_�������o�����̏㕔�����v
//					;;�p�^�[���m�F�v���@�Z�b�g
//	CP	@FLP_PAY		; �p�^�[���o�͒��H
//	RET	NZ			;   �m�n
//
//	LD	A,@SET_PAYEND		; ���܂ɂ��V�Z���_�����o���I����
//					;;�̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	RET
//
//	PAGE
//;*************************************************************************
//;*	�Ǘ��ԍ�      : S-0356-001					 *
//;*	�@�\	      : ���o�����̍������J�E���^�X�V 			 *
//;*	Ӽޭ�ٖ�      : MS_IN_OUT_UP					 *
//;*	�������Ұ�    : 						 *
//;*	�o�����Ұ�    : 						 *
//;*	�ی�ڼ޽�     : 						 *
//;*	�j��ڼ޽�     : A,HL						 *
//;*	�g�pӼޭ��    : MS_BNS_CHK					 *
//;*************************************************************************
//;
//MS_IN_OUT_UP:
//	CALL	MS_BNS_CHK		; �{�[�i�X�Q�[���`�F�b�N
//	RET	NZ			; �{�[�i�X�Q�[���H�D�D�x�d�r
//
//	LD	HL,_CT_IN_OUT + 1
//	LD	A,(HL)
//	CPL
//	INC	(HL)			; �������J�E���^�@�{�P
//	AND	(HL)
//	RLCA				; �������J�E���^�͈͊O�H
//	RET	NC			; �@�m�n
//
//	LD	(HL),7FH
//	DEC	HL
//	LD	(HL),0FFH		; �������J�E���^�ɍő�l�@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0357-005					*
//;*	�@�\	      : �V�Z�I���`�F�b�N				*
//;*	Ӽޭ�ٖ�      : MS_GAME_CHK					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,HL						*
//;*	�g�pӼޭ��    : S_LPSD_SET,S_WATCH_CLEAR,MS_1MEDAL_PAY		*
//;*		      : MS_CREDIT_DEC,S_RAM_CLEAR,M_MAIN�i�W�����v�j	*
//;************************************************************************
//;
//MS_GAME_CHK:
//	LD	HL,_FL_ACTION
//
//	LD	A,(HL)
//	RRCA				; �ėV�Z�쓮���H
//	JR	NC,MS_GAME_CHK1		;   �m�n
//
//; �ėV�Z�쓮�I������
//					; // HL = _FL_ACTION
//	LD	(HL),0			; �ėV�Z�쓮�t���O  �N���A
//
//	LD	L,LOW _PT_OUT2
//	RES	4,(HL)			; �ėV�Z�\�������v�����@�Z�b�g
//
//	RET
//
//MS_GAME_CHK1:
//	RRCA				; �q�a�쓮���H
//	JR	NC,MS_GAME_CHK6		;   �m�n
//
//; �𕨘A���쓮���u�쓮���̖𕨗V�Z�񐔃`�F�b�N
//
//	LD	L,LOW _CT_BONUS_WIN
//
//	LD	A,(_WK_WIN_LP)
//	AND	100B			; �𕨓��܂���H
//	JR	Z,MS_GAME_CHK3		;   �m�n
//
//	DEC	(HL)			; �q�a�쓮���̖𕨓��܉񐔁@�|�P
//	JR	Z,MS_GAME_CHK4		; �𕨓��܉񐔏I���H�D�D�x�d�r
//
//MS_GAME_CHK3:
//	DEC	HL			; // HL = _CT_BONUS_PLAY
//	DEC	(HL)			; �q�a�쓮���̖𕨗V�Z�񐔁@�|�P
//	RET	NZ			; �𕨗V�Z�񐔏I���H�D�D�m�n
//
//; �𕨘A���쓮���u�쓮�I������
//
//MS_GAME_CHK4:
//
//	LD	L,LOW _PT_OUT0		; �𕨘A���쓮���u
//	RES	6,(HL)			;;�{������M���o�́@�n�e�e
//
//	LD	L,LOW _PT_OUT2
//	RES	5,(HL)			; �V�Z��ԕ\�������v�P�����@�Z�b�g
//
//	LD	L,LOW _FL_ACTION	; �𕨘A���쓮���u
//	RES	@BT_RB,(HL)		;;�쓮�t���O  �N���A
//
//	BIT	@BT_BB,(HL)		; �a�a�쓮���H
//	JR	NZ,MS_GAME_CHK5		;   �x�d�r
//
//	LD	HL,0FFFH
//	LD	(_NB_COUNT_LED1),HL	; �񐔕\���k�d�c�P�A�Q�@����
//
//	LD	A,@SET_RBEND		; �𕨘A���쓮���u�쓮�I������
//					;;�o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	RET
//
//; �𕨘A���쓮�������u�쓮���̖𕨘A���쓮���u�쓮�I������
//
//MS_GAME_CHK5:
//	LD	C,(HL)			; �쓮�t���O�@�ޔ�
//	LD	L,LOW _CT_BIG_WIN
//	DEC	(HL)			; �a�a�쓮���̂q�a���܉񐔁@�|�P
//	JR	Z,MS_GAME_CHK7		; ���܉񐔏I���H�D�D�x�d�r
//
//	DEC	HL			; // HL = _CT_BIG_PLAY
//	LD	A,(HL)			; �a�a�쓮���̈�ʗV�Z�񐔁@�Z�b�g
//	AND	A			; �V�Z�񐔏I���H
//	JR	Z,MS_GAME_CHK7		; �@�x�d�r
//
//	LD	B,@SET_BB1		; �𕨘A���쓮�������u�쓮����
//					;;�o�͗v���P�@�Z�b�g
//	BIT	@BT_BB1,C		; (���ݥ���ݥ����)�m�F�v���Z�b�g
//	JR	NZ,MS_GAME_CHK16	; �m�F�v���}���ɂ��a�a�쓮���H�x�d�r
//
//	INC	B			; �𕨘A���쓮�������u�쓮����
//					;;�o�͗v���Q�@�Z�b�g
//					; // B = @SET_BB2
//MS_GAME_CHK16:
//	CP	@BBCHG+1		; �a�a�쓮���R�ɐ؂�ւ��H
//					; // A = (_CT_BIG_PLAY)
//	JR	NC,MS_GAME_CHK18	;   �m�n
//
//MS_GAME_CHK17:
//	LD	B,@SET_BB3		; �𕨘A���쓮�������u�쓮����
//					;;�o�͗v���R�@�Z�b�g
//MS_GAME_CHK18:
//	LD	A,B
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	RET
//
//MS_GAME_CHK6:
//	RRCA				; �a�a�쓮���H
//	RET	NC      		;   �m�n
//
//; �𕨘A���쓮�������u�V�Z�񐔃`�F�b�N
//
//	LD	L,LOW _CT_BIG_PLAY
//	DEC	(HL)			; �a�a�쓮���̈�ʗV�Z�񐔁@�|�P
//	LD	A,(HL)
//
//	LD	L,LOW _FL_WIN
//	BIT	@BT_RB,(HL)		; �q�a���܁H
//	RET	NZ			;   �x�d�r
//
//	CP	@BBCHG			; �a�a�쓮���R�ɐ؂�ւ��H
//					; // A = (_CT_BIG_PLAY)
//	JR	Z,MS_GAME_CHK17		;   �x�d�r
//
//	AND	A
//	RET	NZ			; �V�Z�񐔏I���H�D�D�m�n
//
//	PAGE
//;  �𕨘A���쓮�������u�쓮�I������
//
//MS_GAME_CHK7:
//	XOR	A
//	LD	(_FL_ACTION),A		; �쓮�t���O  �N���A
//
//	LD	(_NB_PAY_LED),A		; �V�Z���_�����o�������\���@�N���A
//
//	LD	HL,0FFFH
//	LD	(_NB_COUNT_LED1),HL	; �񐔕\���k�d�c�P�A�Q�@����
//
//	LD	(_WK_WIN_LP),A		; ���܎��L�����C�������v
//					;;�_�Ńf�[�^�@�N���A
//
//	LD	HL,_PT_OUT5
//	DI				; ���荞�݋֎~
//	LD	A,(HL)
//	AND	11100000B
//	LD	(HL),A			; �L�����C�������v�����@�Z�b�g
//	EI				; ���荞�݋���
//
//	LD	L,LOW _PT_OUT2
//	RES	6,(HL)			; �V�Z��ԕ\�������v�Q�A�R�����@�Z�b�g
//	RES	7,(HL)
//
//	LD	A,@SET_BBEND		; �𕨘A���쓮�������u�쓮�I������
//					;;�o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//MS_GAME_CHK8:
//	RST 	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_WK_FLASH_LP)	; �a�a�쓮�I�����̏㕔�����v
//							;;�p�^�[���m�F�v���@�Z�b�g
//	CP	@FLP_BBEND		; �p�^�[���o�͒��H
//	JR	Z,MS_GAME_CHK8		;   �x�d�r
//
//	LD	L,LOW _PT_OUT0		; �𕨘A���쓮�������u
//	RES	7,(HL)			;;�{������M���o�́@�n�e�e
//
//; �𕨘A���쓮�������u�쓮�I����̃��[�h�I��
//
//	LD	L,LOW _FL_GAME_STS
//	BIT	0,(HL)			; �������Z�H
//	JR	Z,MS_GAME_CHK10		; �@�m�n
//
//	BIT	4,(HL)			; �V�Z���_���������u�g�p���H
//	JR	NZ,MS_GAME_CHK10	; �@�m�n
//
//; �������Z
//
//MS_GAME_CHK9:
//	LD	A,(_NB_CREDIT_LED)
//	AND	A			; �V�Z���_��������������H
//	JR	Z,MS_GAME_CHK10		; �@�m�n
//
//	CALL	MS_1MEDAL_PAY		; �V�Z���_���P�����o��
//
//	CALL	MS_CREDIT_DEC		; �V�Z���_�����������P�����Z
//
//	JR	MS_GAME_CHK9
//
//; �ł��~��
//
//MS_GAME_CHK10:
//	LD	HL,_FL_GAME_STS
//	BIT	2,(HL)			; �ł��~�ߎ��������H
//	JR	Z,MS_GAME_CHK14		; �@�x�d�r
//
//	LD	L,LOW _NB_COUNT_LED1
//	LD	(HL),0EEH		; �ł��~�ߕ\���@�Z�b�g
//
//	LD	L,LOW _TM1_RESET
//
//MS_GAME_CHK11:
//	LD	(HL),@TM_RESET		; �O���Ŏ~�߉����M��
//					;;���͎���  �Z�b�g
//MS_GAME_CHK12:
//	RST 	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_PT_IN0_UP)
//	RLCA				; �Ŏ~�����X�C�b�`  �n�m�H
//	JR	C,MS_GAME_CHK13		;   �x�d�r
//
//	LD	A,(_PT_IN1_UP)
//	AND	00001010B		; �װ��������,�ݒ����ݽ���  �n�m�H
//	JR	NZ,MS_GAME_CHK13	; �@�x�d�r
//
//	LD	A,(_PT_IN1_OLD)
//	RLCA				; �O���Ŏ~�߉����M�����͂���H
//	JR	C,MS_GAME_CHK11		; �@�m�n
//
//	LD	A,(HL)			; // HL = _TM1_RESET
//	AND	A			; �O���Ŏ~�߉����M�����͎��ԏI���H
//	JR	NZ,MS_GAME_CHK12	;   �m�n
//
//MS_GAME_CHK13:
//	LD	L,LOW _NB_COUNT_LED1
//	LD	(HL),0FFH		; �񐔕\���k�d�c�P�@����
//
//; �𕨘A���쓮�������u�쓮�I�����̂q�`�l������
//
//MS_GAME_CHK14:
//	LD	SP,@STACK		; �X�^�b�N�|�C���^�@�Z�b�g
//
//	LD	HL,TBL_RAM_CLEAR2	; �𕨘A���쓮�������u�쓮�I������
//					;;�q�`�l�������e�[�u���@�Z�b�g
//	RST	S_RAM_CLEAR		; �q�`�l������ <808FH - 81E9H>
//
//	DI				; ���荞�݋֎~
//
//	LD	HL,_FL_GAME_STS
//	LD	A,(HL)
//	AND	00010101B
//	LD	(HL),A			; �V�Z��ԃt���O�s�K�v
//					;;�r�b�g�@�N���A
//	LD	HL,TBL_RAM_CLEAR4	; �𕨘A���쓮�������u�쓮�I������
//					;;�q�`�l�������e�[�u���@�Z�b�g
//	RST	S_RAM_CLEAR		; �q�`�l������ <800DH - 808EH>
//
//	LD	HL,81EAH		; �q�`�l�������擪�A�h���X�@�Z�b�g
//	LD	BC,22*100H		; �q�`�l�������͈́@�Z�b�g
//					; < ���荞�ݎ��ő�X�^�b�N�g�p�ʁ{�Q�o�C�g >
//MS_GAME_CHK15:
//	LD	(HL),C			; �q�`�l������ <81EAH - 81FFH>
//	INC	HL			; ���̂q�`�l�A�h���X�@�Z�b�g
//	DJNZ	MS_GAME_CHK15		; �q�`�l�������I���H�D�D�m�n
//
//	EI				; ���荞�݋���
//
//	JP	M_MAIN
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0500-004					*
//;*	�@�\	      : ���I						*
//;*	Ӽޭ�ٖ�      : MS_ALL_LOT					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,DE,HL					*
//;*	�g�pӼޭ��    : MS_JAC_CHK,MS_JAC_LOT,MS_BB_LOT,MS_INSIDE_LOT	*
//;*		      : MS_NORMAL_LOT					*
//;************************************************************************
//;
//MS_ALL_LOT:
//	CALL	MS_JAC_CHK		; �𕨗V�Z�`�F�b�N
//	JR	Z,MS_ALL_LOT1		; �𕨗V�Z���H�D�D�m�n
//
//	CALL	MS_JAC_LOT		; �𕨗V�Z�}�����I
//
//	RET
//
//; ��ʗV�Z�}�����I�p�m���e�[�u���Z�b�g
//
//MS_ALL_LOT1:
//	LD	HL,TBL_PIC_LOT - @LOT_MEDAL - @LOT_RANK
//	LD	DE,@LOT_MEDAL		; ��ʗV�Z�}�����I�p
//					;;�m���e�[�u��  �Z�b�g
//	LD	A,(_NB_PLAY_MEDAL)
//	LD	B,A			; �V�Z���_�������@�ǂݍ���
//MS_ALL_LOT2:
//	ADD	HL,DE			; �V�Z���_�������ɉ�����
//					;;�e�[�u���ύX
//	DJNZ	MS_ALL_LOT2		; �ύX�I���H�D�D�m�n
//
//	LD	E,@LOT_RANK		; // D = 0
//
//	LD	A,(_NB_RANK)
//	LD	B,A			; �ݒ�l�@�ǂݍ���
//MS_ALL_LOT3:
//	ADD	HL,DE			; �ݒ�l�ɉ������e�[�u���ύX
//	DJNZ	MS_ALL_LOT3		; �ύX�I���H�D�D�m�n
//
//	EX	DE,HL
//
//	LD	HL,(_BF_RAND1)		; ��ʗV�Z�}�����I�p�����ǂݍ���<49152 - 65535>
//
//	LD	A,(_FL_ACTION)
//	AND	@_BB			; �a�a�쓮���H
//	JR	Z,MS_ALL_LOT4		;   �m�n
//
//	CALL	MS_BB_LOT		; �𕨘A���쓮�������u�쓮��
//					;;��ʗV�Z�}�����I
//	RET
//
//MS_ALL_LOT4:
//	LD	A,(_FL_PUL_PIC2)
//	AND	@BB OR @RB		; �������V�Z�H
//	JR	Z,MS_ALL_LOT5		;   �m�n
//
//	CALL	MS_INSIDE_LOT		; �������V�Z�}�����I
//
//	RET
//
//MS_ALL_LOT5:
//	CALL	MS_NORMAL_LOT		; �𕨘A���쓮�������u���쓮��
//					;;��ʗV�Z�}�����I
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0501-003					*
//;*	�@�\	      : �𕨗V�Z�}�����I				*
//;*	Ӽޭ�ٖ�      : MS_JAC_LOT					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	BC,DE,HL					*
//;*	�g�pӼޭ��    : MS_LOT_SET					*
//;************************************************************************
//;
//MS_JAC_LOT:
//	LD	C,@NM_JHIT		; �𕨓��I�p�}���f�[�^�ԍ��@�Z�b�g
//
//	LD	HL,(_BF_RAND2)		; �𕨗V�Z�}�����I�p�����ǂݍ���<49152 - 65535>
//	LD	DE,(TBL_JAC_LOT)	; �𕨗V�Z�}�����I�p�m��
//					;;�e�[�u��  �Z�b�g
//	ADD	HL,DE			; �𕨓��I�H
//	JR	C,MS_JAC_LOT1		; �@�x�d�r
//
//	DEC	C			; �͂���p�}���f�[�^�ԍ��@�Z�b�g
//					; // C = @NM_JHIT-1
//MS_JAC_LOT1:
//	LD	B,4			; �}���f�[�^�ۑ���  �Z�b�g
//	CALL	MS_LOT_SET		; �����݁E�R��΂��}���f�[�^�ۑ�
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0502-001					*
//;*	�@�\	      : �����݁E�R��΂��}���f�[�^�ۑ�			*
//;*	Ӽޭ�ٖ�      : MS_LOT_SET					*
//;*	�������Ұ�    : C = �}���f�[�^�ԍ�				*
//;*		      : B = �}���f�[�^�ۑ���				*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//MS_LOT_SET:
//	LD	A,C
//	ADD	A,A			; // 2A
//	ADD	A,A			; // 4A
//	LD	HL,TBL_PICTURE_SET - 4	; �����݁E�R��΂��}���e�[�u���v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	DE,_FL_PUL_PIC1
//
//	LD	C,B
//	LD	B,0
//	LDIR				; �����݁E�R��΂��}���f�[�^�@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0503-001					*
//;*	�@�\	      : �𕨘A���쓮�������u�쓮����ʗV�Z�}�����I	*
//;*	Ӽޭ�ٖ�      : MS_BB_LOT					*
//;*	�������Ұ�    : �i HL = ����(C000H�`FFFFH) �j			*
//;*		      : DE = �m���e�[�u��				*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	HL						*
//;*	�j��ڼ޽�     :	BC,DE						*
//;*	�g�pӼޭ��    : MS_LOT_JUDGE,MS_LOT_SET				*
//;************************************************************************
//;
//MS_BB_LOT:
//	EX	DE,HL
//	LD	BC,@LOT_BB
//	ADD	HL,BC				; �𕨘A���쓮�������u�쓮��
//						;;��ʗV�Z�m���e�[�u��  �Z�b�g
//	EX	DE,HL
//
//	LD	BC,@BB_PLAY*100H OR @NM_BBPLAY	; �𕨘A���쓮���u�y��
//						;;��ʓ��ܐ}�����I�v���@�Z�b�g
//						; <B = ���I�}�����AC = �}���f�[�^�ԍ�>
//	CALL	MS_LOT_JUDGE			; ���I����
//
//	LD	B,4				; �}���f�[�^�ۑ���  �Z�b�g
//	CALL	MS_LOT_SET			; �����݁E�R��΂��}���f�[�^�ۑ�
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0504-001					*
//;*	�@�\	      : ���I����					*
//;*	Ӽޭ�ٖ�      : MS_LOT_JUDGE					*
//;*	�������Ұ�    : HL = ���I���					*
//;*		      : DE = �m���e�[�u��				*
//;*		      : B = ���I�}����					*
//;*		      : C = �}���f�[�^�ԍ�				*
//;*	�o�����Ұ�    :	Cflag ON = ������				*
//;*		      : Cflag OFF = �͂���				*
//;*		      : HL = ���I���					*
//;*		      : DE = �m���e�[�u��				*
//;*		      : C = �}���f�[�^�ԍ�				*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_LOT_JUDGE:
//	PUSH	BC
//	LD	A,(DE)
//	LD	C,A			; �m���f�[�^�i���ʌ��j  �Z�b�g
//	INC	DE
//	LD	A,(DE)
//	LD	B,A			; �m���f�[�^�i��ʌ��j  �Z�b�g
//	INC	DE
//
//	ADD	HL,BC			; ���I�H
//	POP	BC
//	RET	C			;   �x�d�r <�L�����[�t���O>
//
//	INC	C			; �}���f�[�^�ԍ�  �{�P
//
//	DJNZ	MS_LOT_JUDGE		; ���I�}�����I���H�D�D�m�n
//
//	RET				; <�L�����[�t���O�@�n�e�e>
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0505-001					*
//;*	�@�\	      : �������V�Z�}�����I				*
//;*	Ӽޭ�ٖ�      : MS_INSIDE_LOT					*
//;*	�������Ұ�    : �i HL = ����(C000H�`FFFFH) �j			*
//;*		      :	�i DE = �m���e�[�u�� �j				*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	B						*
//;*	�g�pӼޭ��    : MS_FRUIT_LOT,MS_LOT_SET				*
//;************************************************************************
//;
//MS_INSIDE_LOT:
//	CALL	MS_FRUIT_LOT		; ��ʓ��ܐ}�����I
//
//	LD	B,2			; �}���f�[�^�ۑ���  �Z�b�g
//	CALL	MS_LOT_SET		; �����݁E�R��΂��}���f�[�^�ۑ�
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0506-001					*
//;*	�@�\	      : ��ʓ��ܐ}�����I				*
//;*	Ӽޭ�ٖ�      : MS_FRUIT_LOT					*
//;*	�������Ұ�    : �iHL = ���I����j				*
//;*		      : DE = �m���e�[�u��				*
//;*	�o�����Ұ�    : Cflag ON = ������				*
//;*		      : Cflag OFF = �͂���				*
//;*		      : HL = ���I���					*
//;*		      : DE = �m���e�[�u��				*
//;*		      : C = �}���f�[�^�ԍ�				*
//;*	�ی�ڼ޽�     : HL						*
//;*	�j��ڼ޽�     : A,BC,DE						*
//;*	�g�pӼޭ��    : MS_LOT_JUDGE					*
//;************************************************************************
//;
//MS_FRUIT_LOT:
//	LD	A,(_CT_IN_OUT + 1)
//	RLCA					; �������J�E���^�͐��H
//	JR	NC,MS_FRUIT_LOT1		; �@�x�d�r
//
//	LD	BC,@LOT_IN_OUT
//	EX	DE,HL
//	ADD	HL,BC				; ����Ғl�E�����Ғl�e�[�u���ؑւ�
//	EX	DE,HL
//
//MS_FRUIT_LOT1:
//	LD	BC,@NB_FRUIT*100H OR @NM_FRUIT	; ���I�v���@�Z�b�g
//						; <B = ���I�}�����AC = �}���f�[�^�ԍ�>
//	CALL	MS_LOT_JUDGE			; ���I����
//
//	RET					; <�L�����[�t���O>
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0507-001					*
//;*	�@�\	      : �𕨘A���쓮�������u���쓮����ʗV�Z�}�����I	*
//;*	Ӽޭ�ٖ�      : MS_NORMAL_LOT					*
//;*	�������Ұ�    : �i HL = ����(C000H�`FFFFH) �j			*
//;*		      : �i DE = �m���e�[�u�� �j				*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	BC						*
//;*	�g�pӼޭ��    : MS_FRUIT_LOT,MS_LOT_JUDGE,MS_LOT_SET		*
//;************************************************************************
//;
//MS_NORMAL_LOT:
//	CALL	MS_FRUIT_LOT			; ��ʓ��ܐ}�����I
//	JR	C,MS_NORMAL_LOT1		; ���I�H�D�D�x�d�r
//
//	LD	BC,@NB_BONUS*100H OR @NM_BONUS	; �𕨘A���쓮�������u�y��
//						;;�𕨘A���쓮���u���I�v���@�Z�b�g
//						; <B = ���I�}�����AC = �}���f�[�^�ԍ�>
//	CALL	MS_LOT_JUDGE			; ���I����
//	JR	C,MS_NORMAL_LOT1		; ���I�H�D�D�x�d�r
//
//	LD	C,@NM_NFAIL			; �͂���p�}���f�[�^�ԍ��@�Z�b�g
//
//MS_NORMAL_LOT1:
//	LD	B,4				; �}���f�[�^�ۑ���  �Z�b�g
//	CALL	MS_LOT_SET			; �����݁E�R��΂��}���f�[�^�ۑ�
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0600-001					*
//;*	�@�\	      : �}���g��������					*
//;*	Ӽޭ�ٖ�      : MS_PIC_CTL					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL,HL',DE'				*
//;*	�g�pӼޭ��    : MS_RLDAT_SET,S_ADDR_SET,MS_CREJ_CTL,MS_REJ3_CTL	*
//;*		      : MS_PUL_CTL,MS_REJ2_CTL,MS_SPPOINT_SET		*
//;*		      : MS_STOPPIC_SET					*
//;************************************************************************
//;
//MS_PIC_CTL:
//	LD	A,5			; �}���ԍ��i�ʉ߈ʒu�p�j
//					;;�v���@�Z�b�g
//	CALL	MS_RLDAT_SET		; �񓷏��f�[�^�Z�b�g
//
//	LD	A,(HL)			; // HL = _WK_REEL# + 5 (#=1,2,3)
//	CP	21			; �}���ԍ��i�ʉ߈ʒu�p�j �� �Q�O�H
//	JR	C,MS_PIC_CTL1		;   �m�n
//
//	SUB	21			; �}���ԍ��C���i�O�`�Q�O�j
//MS_PIC_CTL1:
//	LD	L,LOW _NB_STOP_REEL
//	LD	B,(HL)			; ��~�񓷔ԍ��@�Z�b�g
//
//	INC	HL			; // HL = _BF_PICTURE
//	LD	(HL),A			; �񓷒�~��t���}���ԍ��@�ۑ�
//
//	INC	HL			; // HL = _NB_REJECT
//	LD	(HL),0			; �R��΂��R�}���@�N���A
//
//	INC	HL			; // HL = _FL_STOP_PNT
//	LD	(HL),11111000B		; ��~�\�ʒu�t���O������
//
//	LD	HL,TBL_PICTURE_ARG - 27	; �񓷐}���z��e�[�u���v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	XOR	A
//	LD	DE,27
//MS_PIC_CTL2:
//	ADD	A,5			; ��~�񓷂ɉ�����
//	ADD	HL,DE			;;�񓷐}���z��e�[�u�������炷
//	DJNZ	MS_PIC_CTL2		; ���炵�I���H�D�D�m�n
//
//	EXX				; <�\���W�X�^�@���@�����W�X�^>
//
//	LD	HL,TBL_LINE_SEARCH - 5	; �L�����C�������e�[�u��
//					;;�v��  �Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	EX	DE,HL
//	EXX				; <�����W�X�^�@���@�\���W�X�^>
//
//	LD	A,2			; �񓷐}���z��e�[�u�����@�Z�b�g
//	LD	DE,_WK_REEL_PIC1
//MS_PIC_CTL3:
//	LD	C,7			; // B=0
//	LDIR				; �񓷐}���f�[�^�@�Z�b�g
//
//	LD	C,81 - 7
//	ADD	HL,BC			; ���̉񓷐}���z��e�[�u���@�Z�b�g
//	DEC	A			; �񓷐}���f�[�^�P�A�Q�Z�b�g�I���H
//	JR	NZ,MS_PIC_CTL3		;   �m�n
//
//	CALL	MS_CREJ_CTL		; �`�F���[�R��΂�����
//
//	CALL	MS_REJ3_CTL		; ��R��~���̏R��΂�����
//
//	CALL	MS_PUL_CTL		; �����ݐ���
//
//	CALL	MS_REJ2_CTL		; ��Q��~���̏R��΂�����
//
//	CALL	MS_SPPOINT_SET		; ��~�ʒu  �Z�b�g
//
//	CALL	MS_STOPPIC_SET		; ��~�}��  �Z�b�g
//
//	RET
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0601-001					*
//;*	�@�\	      : �񓷏��f�[�^�Z�b�g				*
//;*	Ӽޭ�ٖ�      : MS_RLDAT_SET					*
//;*	�������Ұ�    : A = �񓷏�񌟍��ԍ�				*
//;*	�o�����Ұ�    :	HL = �񓷐���f�[�^�q�`�l�A�h���X		*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,HL						*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//MS_RLDAT_SET:
//	LD	HL,_WK_REEL1 - 8	; �w��̉񓷐���f�[�^
//					;;�q�`�l�A�h���X�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(_NB_STOP_REEL)	; ��~�񓷔ԍ�  �Z�b�g
//	ADD	A,A			; //  * 8  (8=_WK_REEL2-_WK_REEL1)
//	ADD	A,A
//	ADD	A,A
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0602-001					*
//;*	�@�\	      : �`�F���[�R��΂�����				*
//;*	Ӽޭ�ٖ�      : MS_CREJ_CTL					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,HL						*
//;*	�g�pӼޭ��    : MS_REJPUL1_CTL					*
//;************************************************************************
//;
//MS_CREJ_CTL:
//	LD	A,(_NB_STOP_REEL)
//	DEC	A			; ���񓷁H
//	RET	NZ			;   �m�n
//
//	LD	HL,TBL_CHERRY_REJ	; �`�F���[�R��΂�
//					;;����e�[�u��  �Z�b�g
//	LD	B,1			; �����  �Z�b�g
//	CALL	MS_REJPUL1_CTL		; ���I�}�������݁E�R��΂�����
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0603-001					*
//;*	�@�\	      : ���I�}�������݁E�R��΂�����			*
//;*	Ӽޭ�ٖ�      : MS_REJPUL1_CTL					*
//;*	�������Ұ�    : HL= �����݁E�R��΂�����e�[�u��  	    	*
//;*		      : B = �����					*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	C,HL						*
//;*	�j��ڼ޽�     :	A,B,DE						*
//;*	�g�pӼޭ��    : MS_REJPUL2_CTL,S_ADDR_SET			*
//;************************************************************************
//;
//MS_REJPUL1_CTL:
//	PUSH	HL
//	PUSH	BC
//
//	LD	D,HIGH @RAM		; <�q�`�l��ʃA�h���X>
//	LD	E,(HL)
//	INC	HL
//	LD	A,(DE)
//	LD	C,A			; ���I�������݁E�R��΂�
//					;;�}���f�[�^  �Z�b�g
//
//	CALL	MS_REJPUL2_CTL		; �����݁E�R��΂�����
//
//	POP	BC
//	POP	HL
//
//	LD	A,11			; ���̐���e�[�u���v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	DJNZ	MS_REJPUL1_CTL		; ����񐔏I���H�D�D�m�n
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0604-001					*
//;*	�@�\	      : �����݁E�R��΂�����				*
//;*	Ӽޭ�ٖ�      : MS_REJPUL2_CTL					*
//;*	�������Ұ�    : DE'= �L�����C�������e�[�u��  			*
//;*		      :	HL = �����݁E�R��΂�����e�[�u��		*
//;*		      :	C  = �����݁E�R��΂��}���f�[�^			*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	DE'						*
//;*	�j��ڼ޽�     :	A,BC,DE,HL,HL',BC'				*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_REJPUL2_CTL:
//;
//;    �S�L�����C���ꊇ����
//;
//	LD	D,HIGH @RAM		; <�q�`�l��ʃA�h���X>
//	LD	E,(HL)			; // DE = _WK_ALL_PIC#
//	LD	A,(DE)			; // A = ��~�}���f�[�^�i�S�L�����C���p�j
//	AND	C			; // C = �����݁E�R��΂��}���f�[�^
//	INC	HL			; // (HL) = ����}��
//	AND	(HL)			; �S�L�����C����ɐ���}������H
//	RET	Z			;   �m�n
//;
//;    �e�L�����C������
//;
//	LD	A,(_NB_REJECT)
//	CP	4			; �R��΂��R�}�����E�H
//	RET	NC			;   �x�d�r
//
//	LD	E,A			; �R��΂��R�}���@�Z�b�g
//
//	INC	HL
//	LD	A,(HL)			; // A = �񓷐}���q�`�l�A�h���X����
//	INC	HL
//
//	EXX				; <�\���W�X�^�@���@�����W�X�^>
//	LD	B,HIGH @RAM		; <�q�`�l��ʃA�h���X>
//	LD	C,A			; �񓷐}���f�[�^�@�Z�b�g
//	EXX				; <�����W�X�^�@���@�\���W�X�^>
//
//	LD	A,(HL)			; // A = ��~�}���q�`�l�A�h���X����
//	INC	HL
//
//	EXX				; <�\���W�X�^�@���@�����W�X�^>
//	LD	H,HIGH @RAM		; <�q�`�l��ʃA�h���X>
//	LD	L,A			; ��~�}���f�[�^  �Z�b�g
//	EXX				; <�����W�X�^�@���@�\���W�X�^>
//
//	LD	A,(HL)			; �����݁E�R��΂��t���O�@�Z�b�g
//	INC	HL
//	CP	11111000B		; �R��΂�����H
//	JR	Z,MS_REJPUL2_CTL1	;   �x�d�r
//
//	LD	E,0FFH			; �R��΂��R�}���@������
//MS_REJPUL2_CTL1:
//	LD	A,(_FL_STOP_PNT)
//	RRCA
//	RRCA
//	RRCA
//	LD	B,A			; ��~�\�ʒu�f�[�^  �Z�b�g
//
//	LD	A,5			; ����R�}��  �Z�b�g
//MS_REJPUL2_CTL2:
//	PUSH	AF			; ����R�}���@�ޔ�
//
//	EXX				; <�\���W�X�^�@���@�����W�X�^>
//	PUSH	HL			; ��~�}���f�[�^�@�ޔ�
//	PUSH	DE			; �L�����C�������e�[�u���@�ޔ�
//	PUSH	BC			; �񓷐}���f�[�^�@�ޔ�
//	EXX				; <�����W�X�^�@���@�\���W�X�^>
//
//	SRL	B			; �R��΂��ʒu�H
//	JR	NC,MS_REJPUL2_CTL6	;   �x�d�r
//
//	PUSH	HL			; �����݁E�R��΂�����e�[�u���@�ޔ�
//	PUSH	BC			; �R��΂��ʒu�f�[�^�@�ޔ�
//
//	LD	A,(_NB_PLAY_MEDAL)
//	ADD	A,A
//	DEC	A
//	LD	B,A			; �L�����C����  �Z�b�g
//
//MS_REJPUL2_CTL3:
//
//	EXX				; <�\���W�X�^�@���@�����W�X�^>
//	LD	A,(DE)			; �L�����C�������f�[�^  �Z�b�g
//	INC	DE			; �L�����C�������e�[�u���@�{�P
//	ADD	A,C
//	LD	C,A
//	LD	A,(BC)			; �L�����C���ɉ������񓷐}���f�[�^�@�Z�b�g
//	AND	(HL)			; �i�񓷐}���jAND�i��~�}���j
//	INC	L			; ���̒�~�}���f�[�^�q�`�l�A�h���X�@�Z�b�g
//	EXX				; <�����W�X�^�@���@�\���W�X�^>
//
//	AND	(HL)			; �i�񓷐}���jAND�i��~�}���j
//					;; AND�i����}���j
//	AND	C			; �����݁E�R��΂��H
//	JR	Z,MS_REJPUL2_CTL4	;   �m�n
//
//	INC	E			; �R��΂��R�}���@�{�P
//	LD	A,E
//	CP	5			; �R��΂��R�}�����E�`�F�b�N
//	JR	MS_REJPUL2_CTL5		; <���E�@���@�L�����[�t���O�n�e�e>
//
//MS_REJPUL2_CTL4:
//	INC	HL			; �����C���̐���}���@�Z�b�g
//	DJNZ	MS_REJPUL2_CTL3		; �L�����C�����I���H�D�D�m�n
//
//MS_REJPUL2_CTL5:
//	POP	BC			; �R��΂��ʒu�f�[�^�@���A
//	POP	HL			; �����݁E�R��΂�����e�[�u���@���A
//
//MS_REJPUL2_CTL6:
//	RR	D			; �����݁E�R��΂��ʒu  �Z�b�g
//
//	EXX				; <�\���W�X�^�@���@�����W�X�^>
//	POP	BC			; �񓷐}���f�[�^�@���A
//	INC	C			; ���R�}�̉񓷐}���@�Z�b�g
//	POP	DE			; �L�����C�������e�[�u���@���A
//	POP	HL			; ��~�}���f�[�^�@���A
//	EXX				; <�����W�X�^�@���@�\���W�X�^>
//
//	POP	AF			; ����R�}���@���A
//	DEC	A			; ����R�}���@�|�P
//	JR	NZ,MS_REJPUL2_CTL2	; ����R�}���I���H�D�D�m�n
//
//	LD	A,D
//	AND	11111000B		; �����݁E�R��΂�����H
//	RET	Z			;   �m�n
//
//	DEC	HL
//	XOR	(HL)			; ��~�\�ʒu�f�[�^  �Z�b�g
//	LD	HL,_FL_STOP_PNT
//	AND	(HL)
//	LD	(HL),A			; ��~�\�ʒu�t���O  �Z�b�g
//
//	LD	BC,500H			; ����R�}��  �Z�b�g
//					;;�R��΂��R�}���@�N���A
//MS_REJPUL2_CTL7:
//	RLCA				; ��~�\�ʒu�H
//	JR	C,MS_REJPUL2_CTL8	;   �x�d�r
//
//	INC	C			; �R��΂��R�}���@�{�P
//MS_REJPUL2_CTL8:
//	DJNZ	MS_REJPUL2_CTL7		; ����R�}���I���H�D�D�m�n
//
//	DEC	HL			; // HL = _NB_REJECT
//	LD	(HL),C			; �R��΂��R�}���@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0605-001					*
//;*	�@�\	      : ��R��~���̏R��΂�����			*
//;*	Ӽޭ�ٖ�      : MS_REJ3_CTL					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,HL						*
//;*	�g�pӼޭ��    : MS_REJPUL1_CTL					*
//;************************************************************************
//;
//MS_REJ3_CTL:
//	LD	A,(_NB_STOP_ORDER)
//	CP	3			; ��R��~���H
//	RET	NZ			;   �m�n
//
//	LD	HL,TBL_ETC_REJ		; ��R��~����
//					;;�R��΂�����e�[�u��  �Z�b�g
//	LD	B,2			; �����  �Z�b�g
//	CALL	MS_REJPUL1_CTL		; ���I�}�������݁E�R��΂�����
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0606-001					*
//;*	�@�\	      : �����ݐ���					*
//;*	Ӽޭ�ٖ�      : MS_PUL_CTL					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	B,HL						*
//;*	�g�pӼޭ��    : MS_REJPUL1_CTL					*
//;************************************************************************
//;
//MS_PUL_CTL:
//	LD	HL,TBL_ALL_PUL		; �����ݐ���e�[�u��  �Z�b�g
//	LD	B,2			; �����  �Z�b�g
//	CALL	MS_REJPUL1_CTL		; ���I�}�������݁E�R��΂�����
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0607-002					*
//;*	�@�\	      : ��Q��~���̏R��΂�����			*
//;*	Ӽޭ�ٖ�      : MS_REJ2_CTL					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,HL						*
//;*	�g�pӼޭ��    : MS_REJPUL1_CTL					*
//;************************************************************************
//;
//MS_REJ2_CTL:
//	LD	A,(_FL_STOP_LP)
//	AND	11100000B
//	CP	00100000B		; ���񓷂̂݉�]���H
//	RET	NZ			;   �m�n
//
//	LD	HL,TBL_EXT_REJ		; ��Q��~����
//							;;�R��΂�����e�[�u��  �Z�b�g
//	LD	B,2			; �����  �Z�b�g
//	CALL	MS_REJPUL1_CTL		; ���I�}�������݁E�R��΂�����
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0608-001					*
//;*	�@�\	      : ��~�ʒu�Z�b�g					*
//;*	Ӽޭ�ٖ�      : MS_SPPOINT_SET					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :	B = ���炵�R�}���i�P�`�T�j			*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    : S_ADDR_SET,MS_RLDAT_SET				*
//;************************************************************************
//;
//MS_SPPOINT_SET:
//	LD	HL,(_BF_STOP_CTL)
//	LD	A,H
//	OR	L			; ��~�ʒu����p�e�[�u���g�p�H
//	JR	NZ,MS_SPPOINT_SET6	;   �x�d�r
//
//	LD	A,(_FL_STOP_LP)
//	AND	11100000B
//	CP	11000000B		; ���񓷂���P��~�H
//	JP	NZ,MS_SPPOINT_SET14	;   �m�n
//
//; ��~�ʒu����p�e�[�u���g�p���̒�~�ʒu����
//
//; �m��~�ʒu����p�e�[�u���I���n
//
//	LD	HL,TBL_STOP_SELECT	; ���I�}���ʒ�~�ʒu����p�e�[�u��
//					;;�����e�[�u���@�Z�b�g
//MS_SPPOINT_SET1:
//	LD	B,(HL)			; ������������ݐ}��
//					;;�f�[�^�P�@�Z�b�g
//	INC	HL
//	LD	C,(HL)			; ������������ݐ}��
//					;;�f�[�^�Q�@�Z�b�g
//	INC	HL
//	LD	E,(HL)
//	INC	HL
//	LD	D,(HL)			; ��~�ʒu����p�e�[�u���I�𒊑I�p
//	INC	HL			;;�m���e�[�u���@�Z�b�g
//
//	LD	A,(_FL_PUL_PIC1)	; �����ݐ}���f�[�^�P�@�ǂݍ���
//	CP	B			; �������e��v�H
//	JR	NZ,MS_SPPOINT_SET1	;   �m�n
//
//	LD	A,(_FL_PUL_PIC2)	; �����ݐ}���f�[�^�Q�@�ǂݍ���
//	SUB	C			; �������e��v�H
//	JR	NZ,MS_SPPOINT_SET1	;   �m�n
//
//	EX	DE,HL			; ��~�ʒu����p�e�[�u���I�𒊑I�p
//					;;�m���e�[�u���@����
//; �m���񓷎��̐���n
//
//	LD	E,(HL)
//	INC	HL			; ��~�ʒu����p�e�[�u�������l
//	LD	D,(HL)			;;�ꎞ�ۑ�
//
//	LD	B,A			; �p�^�[���ԍ������l�@�Z�b�g
//					; //A = 0
//
//	LD	A,R			; �q���W�X�^�ǂݍ���
//	OR	10000000B
//
//MS_SPPOINT_SET2:
//	INC	HL			; �e�[�u���I�𒊑I�m���f�[�^�@�Z�b�g
//	INC	B			; �e�[�u���p�^�[���ԍ��@�{�P
//
//	ADD	A,(HL)			; �e�[�u���p�^�[�����I�H
//	JR	NC,MS_SPPOINT_SET2	;   �m�n
//
//MS_SPPOINT_SET3:
//	LD	H,D			; ��~�ʒu����p�e�[�u�������l
//	LD	L,E			;;�ꎞ���o��
//
//MS_SPPOINT_SET4:
//	LD	A,22			; �e�[�u���p�^�[���ڍs�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	DJNZ	MS_SPPOINT_SET4		; �e�[�u���p�^�[���I���I���H�D�D�m�n
//
//	LD	B,(HL)			; �I���w��e�[�u���p�^�[���ԍ��@�Z�b�g
//	INC	HL
//
//	PUSH	HL
//
//	LD	A,(_BF_PICTURE)		; �񓷒�~��t���}���ԍ���
//					;;�������f�[�^�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(HL)
//	POP	HL
//	CP	11001000B		; �w��e�[�u���ֈڍs�H
//	JR	NC,MS_SPPOINT_SET3	;   �x�d�r
//
//	LD	(_BF_STOP_CTL),HL	; ��~�ʒu����p�e�[�u���@�Z�b�g
//
//	LD	BC,500H
//MS_SPPOINT_SET5:
//	SUB	40
//	RR	C			; �e�[�u���ɂ���~�w��ʒu�r�b�g�@�Z�b�g
//	DJNZ	MS_SPPOINT_SET5		; ��~�w��ʒu�r�b�g�Z�b�g�I���H�D�D�m�n
//
//	LD	A,(_FL_STOP_PNT)
//	AND	C			; �e�[�u����~�w��ʒu�ɒ�~�\�H
//	JR	NZ,MS_SPPOINT_SET16	;   �x�d�r
//
//	JR	MS_SPPOINT_SET15
//
//; �m���񓷂̐���n
//
//MS_SPPOINT_SET6:
//	LD	A,(_NB_STOP_REEL)
//	CP	2			; ���񓷒�~���H
//	JR	NZ,MS_SPPOINT_SET9	;   �m�n
//
//					; // HL = (_BF_STOP_CTL)
//	LD	A,(_BF_PICTURE)		; �񓷒�~��t���}���ԍ���
//					;;�������f�[�^�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(HL)			; ��~�ʒu����p�e�[�u���@�Z�b�g
//
//MS_SPPOINT_SET7:
//	SUB	40			; �f�[�^�C��
//	JR	NC,MS_SPPOINT_SET7	; �C���I���H�D�D�m�n
//
//	ADD	A,40
//
//	LD	BC,500H			; �R�}���@�Z�b�g
//MS_SPPOINT_SET8:
//	SUB	8
//	RR	C			; �e�[�u���ɂ���~�w��ʒu�r�b�g�@�Z�b�g
//	DJNZ	MS_SPPOINT_SET8		; ��~�w��ʒu�r�b�g�Z�b�g�I���H�D�D�m�n
//
//	LD	A,(_FL_STOP_PNT)
//	AND	C			; �e�[�u����~�w��ʒu�ɒ�~�\�H
//	JR	NZ,MS_SPPOINT_SET16	;   �x�d�r
//
//	JR	MS_SPPOINT_SET15
//
//; �m�E�񓷂̐���n
//
//MS_SPPOINT_SET9:
//	LD	E,00000100B		; �e�[�u����~�w��ʒu�����r�b�g
//					;;�����l�@�Z�b�g
//MS_SPPOINT_SET10:
//	LD	BC,4			; ���~�ߗp���炵�ϐ������l�y�ђ�~
//					;;�\�ʒu�����r�b�g�����l�@�Z�b�g
//MS_SPPOINT_SET11:
//	LD	A,B
//	CP	5			; �T�R�}�������I���H
//	JR	Z,MS_SPPOINT_SET13	;   �x�d�r
//
//	LD	A,(_BF_PICTURE)		; �񓷒�~��t���}���ԍ��@���o��
//	ADD	A,B			; ��~�}���ԍ�  �Z�b�g
//	CP	21			; ��~�}���ԍ�  ���@�Q�O�H
//	JR	C,MS_SPPOINT_SET12	; �@�m�n
//
//	SUB	21			; ��~�}���ԍ��C���i�O�`�Q�O�j
//
//MS_SPPOINT_SET12:
//	INC	B			; ���炵�R�}���@�{�P
//	SLA	C			; ��~�\�ʒu�����r�b�g�@�Z�b�g
//
//	LD	HL,(_BF_STOP_CTL)	; ��~�ʒu����p�e�[�u���@���o��
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(HL)
//	AND	E			; �e�[�u����~�w��ʒu�H
//	JR	Z,MS_SPPOINT_SET11	;   �m�n
//
//	LD	A,(_FL_STOP_PNT)
//	AND	C			; ��~�\�ʒu�H
//	JR	NZ,MS_SPPOINT_SET20	;   �x�d�r
//
//MS_SPPOINT_SET13:
//	SRL	E			; �e�[�u����~�w��ʒu�����r�b�g�@�Z�b�g
//	JR	NC,MS_SPPOINT_SET10	; ��~�w��ʒu�����I���H�D�D�m�n
//
//	JR	MS_SPPOINT_SET18
//
//; ���~�ߎ��y�эő�����ݎ��̒�~�ʒu����
//
//MS_SPPOINT_SET14:
//	LD	A,(_FL_PUL_PIC1)
//	AND	@_PIC1			; �}���P�Q���I�H
//	JR	NZ,MS_SPPOINT_SET18	;   �x�d�r
//
//	LD	A,(_FL_PUL_PIC2)
//	AND	@_PIC2			; �}���Q�Q���I�H
//	JR	NZ,MS_SPPOINT_SET18	;   �x�d�r
//
//; �m���~�ߎ��̒�~�ʒu����n
//
//MS_SPPOINT_SET15:
//	LD	A,(_FL_STOP_PNT)	; ��~�\�ʒu�t���O�@�Z�b�g
//
//MS_SPPOINT_SET16:
//	RRCA
//	RRCA
//	RRCA
//	LD	B,0			; ���~�ߗp���炵�R�}��
//					;;�����l�@�Z�b�g
//MS_SPPOINT_SET17:
//	INC	B			; ���炵�R�}���@�{�P
//	RRCA				; ��~�\�ʒu�H
//	JR	NC,MS_SPPOINT_SET17	;   �m�n
//
//	JR	MS_SPPOINT_SET20
//
//; �m�ő�����ݎ��̒�~�ʒu����n
//
//MS_SPPOINT_SET18:
//	LD	A,(_FL_STOP_PNT)	; ��~�\�ʒu�t���O�@�Z�b�g
//	LD	B,6			; �ő�����ݗp���炵�R�}�������l  �Z�b�g
//
//MS_SPPOINT_SET19:
//	DEC	B			; ���炵�R�}���@�|�P
//	RLCA				; ��~�\�ʒu�H
//	JR	NC,MS_SPPOINT_SET19	;   �m�n
//
//MS_SPPOINT_SET20:
//	XOR	A			; �񓷋쓮��Ԕԍ��v���@�Z�b�g
//	CALL	MS_RLDAT_SET		; �񓷏��f�[�^�Z�b�g
//
//	PUSH	HL
//	LD	A,6			; �}���ԍ��i��~�ʒu�p�j�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	A,(_BF_PICTURE)		; �񓷒�~��t���}���ԍ��@���o��
//	ADD	A,B			; ��~�}���ԍ�  �Z�b�g
//	CP	21			; ��~�}���ԍ�  ���@�Q�O�H
//	JR	C,MS_SPPOINT_SET21	; �@�m�n
//
//	SUB	21			; ��~�}���ԍ��C���i�O�`�Q�O�j
//
//MS_SPPOINT_SET21:
//	LD	(HL),A			; �}���ԍ��i��~�ʒu�p�j  �Z�b�g
//
//	POP	HL
//	LD	(HL),3			; �񓷌����J�n���  �Z�b�g
//
//	RET
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0609-001					*
//;*	�@�\	      : ��~�}���Z�b�g					*
//;*	Ӽޭ�ٖ�      : MS_STOPPIC_SET					*
//;*	�������Ұ�    : B = ���炵�R�}���i�P�`�T�j			*
//;*		      :	DE'= �L�����C�������e�[�u��			*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL,DE'					*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//MS_STOPPIC_SET:
//	LD	A,B			; ���炵�R�}���ɉ������񓷐}���f�[
//	LD	HL,_WK_REEL_PIC1 - 1	;;�^�P�q�`�l�A�h���X�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	EX	DE,HL
//
//	LD	HL,_WK_STOP_PIC1	; ��~�}���f�[�^�P�q�`�l�A�h���X�@�Z�b�g
//
//	LD	BC,0			; ��~�}���f�[�^�i�S�L�����C���j�@�N���A
//
//	LD	A,(_NB_PLAY_MEDAL)
//	ADD	A,A
//	DEC	A			; �L�����C����  �Z�b�g
//
//MS_STOPPIC_SET1:
//	PUSH	AF
//	PUSH	HL
//
//	EXX				; <�\���W�X�^�@���@�����W�X�^>
//	LD	A,(DE)			; �L�����C���Ή��f�[�^  �Z�b�g
//	INC	DE			; �L�����C�������e�[�u���@�{�P
//	EXX				; <�����W�X�^�@���@�\���W�X�^>
//
//	ADD	A,E
//	LD	E,A			; �L�����C���ɉ�����
//	LD	A,(DE)			;;�񓷐}���f�[�^�P�@�Z�b�g
//	AND	(HL)			; �i�񓷐}���f�[�^�P�jAND�i��~�}���f�[�^�P�j
//	LD	(HL),A			; ��~�}���f�[�^�P�i�e�L�����C���j�@�Z�b�g
//
//	OR	B
//	LD	B,A			; ��~�}���f�[�^�P�i�S�L�����C���j�ꎞ�ۑ�
//
//	PUSH	DE
//
//	LD	A,7
//	ADD	A,E			; �񓷐}���f�[�^�Q�q�`�l�A�h���X
//	LD	E,A			;;�i���ʁj�@�Z�b�g
//
//	LD	A,5			; ��~�}���f�[�^�Q�i�e�L�����C���j
//					;;�q�`�l�A�h���X�v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	A,(DE)			; �L�����C���ɉ�����
//					;;�񓷐}���f�[�^�Q�@�Z�b�g
//	AND	(HL)			; �i�񓷐}���f�[�^�Q�jAND�i��~�}���f�[�^�Q�j
//	LD	(HL),A			; ��~�}���f�[�^�Q�i�e�L�����C���j�@�Z�b�g
//
//	OR	C
//	LD	C,A			; ��~�}���f�[�^�Q�i�S�L�����C���j�ꎞ�ۑ�
//
//	POP	DE
//
//	POP	HL			; �����C���̒�~�}���f�[�^�P�i�e�L
//	INC	HL			;;�����C���j�q�`�l�A�h���X�@�Z�b�g
//
//	POP	AF
//	DEC	A			; �L�����C�����@�|�P
//	JR	NZ,MS_STOPPIC_SET1	; �L�����C�����I���H�D�D�m�n
//
//	LD	L,LOW _WK_ALL_PIC1
//	LD	(HL),B			; ��~�}���f�[�^�P�i�S�L�����C���j�@�Z�b�g
//	INC	HL			; // HL = _WK_ALL_PIC2
//	LD	(HL),C			; ��~�}���f�[�^�Q�i�S�L�����C���j�@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0700-001					*
//;*	�@�\	      : �����v�i�k�d�c�j�\���E���ʉ��o��		*
//;*	Ӽޭ�ٖ�      : IS_LPSD_OUT					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,DE,HL					*
//;*	�g�pӼޭ��    :	IS_LED_OUT,IS_LINE_OUT,IS_LAMP_OUT		*
//;*		      : IS_POWERON_RET					*
//;************************************************************************
//;
//;
//; �W�ʂ�̏o�̓p�^�[��
//;
//IS_LPSD_OUT:
//	XOR	A
//	OUT	(@OUT3_PORT),A				; �o�̓|�[�g�R  �n�e�e
//	OUT	(@OUT4_PORT),A				; �o�̓|�[�g�S  �n�e�e
//
//; �\���ؑւ�
//
//	LD	HL,_FL_LED_CHANGE
//	LD	A,(HL)
//	CP	2
//	RRA
//	LD	(HL),A					; �\���ؑւ��t���O  �Z�b�g
//
//	AND	01111111B
//	LD	L,LOW _PT_OUT4
//	LD	(HL),A					; �k�d�c�f�W�b�g�f�[�^  �Z�b�g
//
//	LD	DE,_NB_PAY_LED
//	RRCA						; �o�̓p�^�[���P�H
//	JR	NC,IS_LPSD_OUT1				; �@�m�n
//
//; �o�̓p�^�[���P
//; 	�V�Z���_�����o�����\���k�d�c���ʌ�
//; 	���܃��C���\���i�L�����C�������v�A�o�b�N�����v�j
//							; // DE = _NB_PAY_LED
//	LD	A,(DE)					; �V�Z���_�����o�����\���k�d�c
//							;;���ʌ��\���v��  �Z�b�g
//	CALL	IS_LED_OUT				; �k�d�c�\��
//
//	CALL	IS_LINE_OUT				; ���܃��C���\��
//
//	LD	HL,_FL_GAME_STS
//	BIT	3,(HL)					; �񓷉�]�n�����u��t���H
//	RET	Z					;   �m�n
//
//	LD	L,LOW _PT_OUT3
//	SET	7,(HL)					; �h�b�g�\��  �Z�b�g
//
//	RET
//
//IS_LPSD_OUT1:
//	RRCA						; �o�̓p�^�[���Q�H
//	JR	NC,IS_LPSD_OUT2				;   �m�n
//
//; �o�̓p�^�[���Q
//; 	�V�Z���_�����o�����\���k�d�c��ʌ�
//
//	LD	A,(DE)					; // DE = _NB_PAY_LED
//	RRCA
//	RRCA
//	RRCA
//	RRCA						; �V�Z���_�����o�����\���k�d�c
//							;;��ʌ��\���v��  �Z�b�g
//	CALL	IS_LED_OUT				; �k�d�c�\��
//
//	RET
//
//IS_LPSD_OUT2:
//	DEC	DE					; // DE = _NB_CREDIT_LED
//	RRCA						; �o�̓p�^�[���R�H
//	JR	NC,IS_LPSD_OUT3				;   �m�n
//
//; �o�̓p�^�[���R
//; 	�V�Z���_�����������\���k�d�c���ʌ�
//							; // DE = _NB_CREDIT_LED
//	LD	A,(DE)					; �V�Z���_�����������\���k�d�c
//							;;���ʌ��\���v��  �Z�b�g
//	CALL	IS_LED_OUT				; �k�d�c�\��
//
//	RET
//
//IS_LPSD_OUT3:
//	RRCA						; �o�̓p�^�[���S�H
//	JR	NC,IS_LPSD_OUT4				;   �m�n
//
//; �o�̓p�^�[���S
//; 	�V�Z���_�����������\���k�d�c��ʌ�
//
//	LD	A,(DE)					; // DE = _NB_CREDIT_LED
//	RRCA
//	RRCA
//	RRCA
//	RRCA						; �V�Z���_�����������\���k�d�c
//							;;��ʌ��\���v��  �Z�b�g
//	CALL	IS_LED_OUT				; �k�d�c�\��
//
//	RET
//
//IS_LPSD_OUT4:
//	LD	E,LOW _NB_COUNT_LED1			; // D = HIGH @RAM
//	RRCA						; �o�̓p�^�[���T�H
//	JR	NC,IS_LPSD_OUT5				;   �m�n
//
//; �o�̓p�^�[���T
//; 	�񐔕\���k�d�c�P���ʌ�
//; 	�㕔�����v
//
//	LD	A,(DE)					; �񐔕\���k�d�c�P
//							;;���ʌ��\���v��  �Z�b�g
//	CALL	IS_LED_OUT				; �k�d�c�\��
//
//	LD	L,LOW _WK_FLASH_LP			; �㕔�����v����f�[�^�q�`�l
//							;;�A�h���X���ʁ@�Z�b�g
//	LD	BC,LOW _PT_OUT6				; �o�̓|�[�g�U�f�[�^�ۑ��r�b�g�y��
//							;;�q�`�l�A�h���X���ʁ@�Z�b�g
//	CALL	IS_LAMP_OUT				; �e�탉���v�\��
//
//	RET
//
//IS_LPSD_OUT5:
//	RRCA						; �o�̓p�^�[���U�H
//	JR	NC,IS_LPSD_OUT6				;   �m�n
//
//; �o�̓p�^�[���U
//; 	�񐔕\���k�d�c�P��ʌ�
//; 	���ʃ����v
//
//	LD	A,(DE)					; // DE = _NB_COUNT_LED1
//	RRCA
//	RRCA
//	RRCA
//	RRCA						; �񐔕\���k�d�c�P
//							;;��ʌ��\���v��  �Z�b�g
//	CALL	IS_LED_OUT				; �k�d�c�\��
//
//	LD	L,LOW _WK_EFFECT_LP			; ���ʃ����v����f�[�^�q�`�l
//							;;�A�h���X���ʁ@�Z�b�g
//	LD	BC,00011111B*100H OR LOW _PT_OUT5	; �o�̓|�[�g�T�f�[�^�ۑ��r�b�g�y��
//							;;�q�`�l�A�h���X���ʁ@�Z�b�g
//	CALL	IS_LAMP_OUT				; �e�탉���v�\��
//
//	RET
//
//IS_LPSD_OUT6:
//	INC	DE					; // DE = _NB_COUNT_LED2
//	RRCA						; �o�̓p�^�[���V�H
//	JR	NC,IS_LPSD_OUT7				;   �m�n
//
//; �o�̓p�^�[���V
//; 	�񐔕\���k�d�c�Q
//; 	�o�b�N�����v
//							; // DE = _NB_COUNT_LED2
//	LD	A,(DE)					; �񐔕\���k�d�c�Q
//							;;�\���v���@�Z�b�g
//	CALL	IS_LED_OUT				; �k�d�c�\��
//
//	LD	L,LOW _WK_BACK_LP			; �o�b�N�����v����f�[�^�q�`�l
//							;;�A�h���X���ʁ@�Z�b�g
//	LD	BC,LOW _PT_OUT8				; �o�̓|�[�g�W�f�[�^�ۑ��r�b�g�y��
//							;;�q�`�l�A�h���X���ʁ@�Z�b�g
//	CALL	IS_LAMP_OUT				; �e�탉���v�\��
//
//	RET
//
//IS_LPSD_OUT7:
//
//; �o�̓p�^�[���W
//
//	CALL	IS_POWERON_RET				; �A�����E�㕔�����v�E���ʃ����v
//							;;�d�f���A����
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0701-001					*
//;*	�@�\	      : �k�d�c�\��					*
//;*	Ӽޭ�ٖ�      : IS_LED_OUT					*
//;*	�������Ұ�    : A = �k�d�c�\���f�[�^				*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,HL						*
//;*	�g�pӼޭ��    : S_ADDR_SET					*
//;************************************************************************
//;
//IS_LED_OUT:
//	AND	0FH
//	LD	HL,TBL_SEG_DATA
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	A,(HL)			; �k�d�c�Z�O�����g�f�[�^�̎��o��
//	LD	(_PT_OUT3),A		; �k�d�c�Z�O�����g�f�[�^�@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0702-001					*
//;*	�@�\	      : ���܃��C���\��					*
//;*	Ӽޭ�ٖ�      : IS_LINE_OUT					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,HL						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//IS_LINE_OUT:
//	LD	HL,_TM1_WIN_LP
//	LD	A,(HL)
//	AND	A			; �_���^�����@�ؑւ��H
//	RET	NZ			; �@�m�n
//
//	LD	A,(_WK_WIN_LP)
//	AND	A			; ���܂���H
//	RET	Z			; �@�m�n
//
//	LD	(HL),@TM_LP105		; ���܃��C���_�Ŏ��ԁ@�Z�b�g
//
//	LD	L,LOW _PT_OUT5
//	XOR	(HL)			; �_���^�����@�ؑւ�
//	LD	(HL),A			; �L�����C�������v
//					;;�_�ŕ\���@�Z�b�g
//	LD	A,(_WK_BACK_LP)
//	AND	A			; �o�b�N�����v�\���v������H
//	RET	NZ			;   �x�d�r
//
//	LD	BC,(_WK_WINBACK_LP)
//	LD	A,C
//	LD	L,LOW _PT_OUT7
//	XOR	(HL)			; �_���^�����@�ؑւ�
//	LD	(HL),A			; �o�b�N�����v�X
//					;;�_�ŕ\���@�Z�b�g
//	LD	A,B
//	INC	HL			; // HL = _PT_OUT8
//	XOR	(HL)			; �_���^�����@�ؑւ�
//	LD	(HL),A			; �o�b�N�����v�P�`�W
//					;;�_�ŕ\���@�Z�b�g
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0703-001					*
//;*	�@�\	      : �e�탉���v�\��					*
//;*	Ӽޭ�ٖ�      : IS_LAMP_OUT					*
//;*	�������Ұ�    : L = �e�탉���v����f�[�^�q�`�l�A�h���X����	*
//;*		      :	B = �o�̓|�[�g�f�[�^�ۑ��r�b�g			*
//;*		      :	C = �o�̓|�[�g�f�[�^�q�`�l�A�h���X����		*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	BC						*
//;*	�j��ڼ޽�     :	A,DE,HL						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//IS_LAMP_OUT:
//	LD	H,HIGH @RAM
//	LD	A,(HL)
//	AND	A			; �\���v������H
//	RET	Z			;   �m�n
//
//	INC	HL			; // HL = _WK_????_LP + 1
//	DEC	(HL)			; �\�����ԏI���H
//	RET	NZ			;   �m�n
//
//	INC	HL			; // HL = _WK_????_LP + 2
//	LD	E,(HL)
//	INC	HL			; // HL = _WK_????_LP + 3
//	LD	D,(HL)			; �\���f�[�^�A�h���X  �Z�b�g
//
//IS_LAMP_OUT1:
//	LD	A,(DE)
//	AND	A			; �㕔���ߖ��͌������߂̕\���I���H
//					; // A = @LP_END ?
//	JR	NZ,IS_LAMP_OUT2		;   �m�n
//
//; �㕔�����v�E���ʃ����v�\���I���i�S�����j
//
//	DEC	HL
//	DEC	HL
//	DEC	HL			; // HL = _WK_????_LP + 0
//	LD	(HL),A			; �\���v��  �N���A
//	JR	IS_LAMP_OUT9
//
//IS_LAMP_OUT2:
//	INC	A			; �o�b�N�����v�̕\���I�������H
//	JR	NZ,IS_LAMP_OUT3		;   �m�n
//
//; �o�b�N�����v�\���I���i�S�_���j
//
//	LD	(_WK_BACK_LP),A		; �\���v��  �N���A
//	LD	L,LOW _PT_OUT7
//	SET	7,(HL)			; �o�b�N�����v�X�_���@�Z�b�g
//	CPL				; �o�b�N�����v�P�`�W�_���@�Z�b�g
//					; // A = 11111111B
//	JR	IS_LAMP_OUT9
//
//IS_LAMP_OUT3:
//	INC	A			; �\���J��Ԃ��H
//	JR	NZ,IS_LAMP_OUT5		;   �m�n
//
//; �\���J��Ԃ��E���s�[�g
//
//IS_LAMP_OUT4:
//	EX	DE,HL
//	INC	HL
//	LD	A,(HL)
//	INC	HL
//	LD	H,(HL)
//	LD	L,A			; �߂���s�A�h���X  ���o��
//	EX	DE,HL
//	JR	IS_LAMP_OUT1
//
//IS_LAMP_OUT5:
//	INC	A			; �\�����s�[�g�H
//	JR	NZ,IS_LAMP_OUT6		;   �m�n
//
//; ���s�[�g�񐔌��Z
//
//	INC	HL			; // HL = _WK_????_LP + 4
//	DEC	(HL)			; ���s�[�g�񐔁@�|�P
//	DEC	HL			; // HL = _WK_????_LP + 3
//	JR	NZ,IS_LAMP_OUT4		; ���s�[�g�I���H�D�D�m�n
//
//	INC	DE
//	INC	DE
//	INC	DE			; ���̕\���f�[�^�A�h���X�@�Z�b�g
//	JR	IS_LAMP_OUT1
//
//IS_LAMP_OUT6:
//	INC	A			; �\���f�[�^�H
//	JR	NZ,IS_LAMP_OUT7		;   �x�d�r
//
//; ���s�[�g�񐔁@�Z�b�g
//
//	INC	HL			; // HL = _WK_????_LP + 4
//	INC	DE
//	LD	A,(DE)
//	LD	(HL),A			; ���s�[�g�񐔁@�Z�b�g
//	INC	DE
//	DEC	HL			; // HL = _WK_????_LP + 3
//
//; �\���f�[�^�@�Z�b�g
//
//IS_LAMP_OUT7:
//	LD	A,(DE)
//	PUSH	AF			; �\���f�[�^�t���O�Ҕ�
//	AND	00111111B		; �\�����ԃf�[�^�@�Z�b�g
//	INC	DE
//	INC	DE
//					; // HL = _WK_????_LP + 3
//	LD	(HL),D			; ���s�A�h���X�i��ʁj�@�Z�b�g
//	DEC	HL			; // HL = _WK_????_LP + 2
//	LD	(HL),E			; ���s�A�h���X�i���ʁj�@�Z�b�g
//	DEC	HL			; // HL = _WK_????_LP + 1
//	LD	(HL),A			; �\�����ԃf�[�^  �Z�b�g
//
//	POP	AF			; �\���f�[�^�t���O���A
//	AND	11000000B		; �o�b�N�����v�̕\�������H
//	JR	Z,IS_LAMP_OUT8		;   �m�n
//
//	AND	10000000B		; �o�b�N�����v�X�f�[�^���o��
//	LD	L,LOW _PT_OUT7
//	RES	7,(HL)
//	OR	(HL)			; �\���f�[�^�@�Z�b�g
//	LD	(HL),A			; �o�̓|�[�g�f�[�^�@�Z�b�g
//
//IS_LAMP_OUT8:
//	DEC	DE
//	LD	A,(DE)			; �o�̓f�[�^���o��
//
//; �\���o�́@�Z�b�g
//
//IS_LAMP_OUT9:
//	LD	E,A
//
//	LD	L,C			; // H = HIGH @RAM
//	LD	A,(HL)
//	AND	B
//	OR	E			; �\���f�[�^�@�Z�b�g
//	LD	(HL),A			; �o�̓|�[�g�f�[�^�@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0704-003      				*
//;*	�@�\	      : �A�����E�㕔�����v�E���ʃ����v�d�f���A����	*
//;*	Ӽޭ�ٖ�      : IS_POWERON_RET					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,DE,HL					*
//;*	�g�pӼޭ��    : SS_LPSD_SET					*
//;************************************************************************
//;
//IS_POWERON_RET:
//	LD	HL,_FL_GAME_STS
//	BIT	1,(HL)			; �A�������A�v������H
//	RET	Z			;   �m�n
//
//	RES	1,(HL)			; �A�������A�v���t���O�@�N���A
//
//	LD	A,(_WK_FLASH_LP)	; �d�f���̏㕔�����v�\���@�Z�b�g
//	LD	DE,@POWON_LP		; �d�f���A���̏o�͗v���ԍ��@�Z�b�g
//	LD	B,@POWON_CT		; �d�f���A���̏o�͗v���ԍ��������@�Z�b�g
//
//IS_POWERON_RET1:
//	INC	D			; ���A�p�o�͗v���ԍ��@�Z�b�g
//	INC	E			; �㕔�����v�o�͗v���ԍ��@�Z�b�g
//
//	DEC	B			; �㕔�����v�\���Ȃ��H
//	RET	Z			;   �x�d�r
//
//	CP	E			; �㕔�����v�p�^�[���o�͒��H
//	JR	NZ,IS_POWERON_RET1	;   �m�n
//
//	LD	A,D			; ���A����o�͗v���@�Z�b�g
//	CALL	SS_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�Q
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0705-001					*
//;*	�@�\	      : ��~�{�^���k�d�c�\��				*
//;*	Ӽޭ�ٖ�      : MS_STOP_LED					*
//;*	�������Ұ�    : B = ��~�{�^���k�d�c�_���r�b�g�f�[�^		*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :	B						*
//;*	�j��ڼ޽�     :	A,DE						*
//;*	�g�pӼޭ��    : 						*
//;************************************************************************
//;
//MS_STOP_LED:
//	LD	DE,_PT_OUT7
//	LD	A,(DE)
//	AND	00111111B
//	CP	B			; ��~�{�^���k�d�c�\���؂�ւ��H
//	RET	Z			;   �m�n
//
//	DI				; ���荞�݋֎~
//
//	LD	A,(DE)
//	AND	11000000B
//	OR	B
//	LD	(DE),A			; ��~�{�^���k�d�c�\��
//
//	EI				; ���荞�݋���
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0706-003					*
//;*	�@�\	      : �V�Z�񐔕\��					*
//;*	Ӽޭ�ٖ�      : MS_BNSCT_DSP					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,BC,HL						*
//;*	�g�pӼޭ��    : MS_BNS_CHK,S_ADDR_SET				*
//;************************************************************************
//;
//MS_BNSCT_DSP:
//	CALL	MS_BNS_CHK		; �{�[�i�X�Q�[���H
//	RET	Z			;   �m�n
//
//	LD	BC,(_CT_BIG_PLAY)	; �a�a�쓮���̗V�Z�񐔋y�тa�a
//					;;�쓮���̂q�a���܉�  �Z�b�g
//	RRCA
//	RRCA				; �a�a�쓮���̈�ʗV�Z�H
//	JR	NC,MS_BNSCT_DSP1	; �@�x�d�r
//
//	LD	HL,_CT_BONUS_WIN
//	LD	C,(HL)			; �q�a�쓮���̖𕨓��܉�  �Z�b�g
//	RRCA				; �a�a�쓮���H
//	JR	C,MS_BNSCT_DSP1		; �@�x�d�r
//
//	LD	B,0EH			; �h��.�h�\���v���@�Z�b�g
//
//MS_BNSCT_DSP1:
//	LD	A,C
//	LD	HL,TBL_BONUS_DSP - 1	; �V�Z�񐔕\���e�[�u���v���@�Z�b�g
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//	LD	C,(HL)
//	LD	(_NB_COUNT_LED1),BC	; �񐔕\���k�d�c�P�A�Q�\���@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0707-001					*
//;*	�@�\	      : �ݒ�l�\��					*
//;*	Ӽޭ�ٖ�      : MS_RANK_DSP					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    :							*
//;*	�ی�ڼ޽�     :							*
//;*	�j��ڼ޽�     :	A,B,HL						*
//;*	�g�pӼޭ��    : MS_BNS_CHK,S_BLOCKER_OFF,S_WATCH_CLEAR		*
//;*		      : S_BLOCKER_ON					*
//;************************************************************************
//;
//MS_RANK_DSP:
//	CALL	MS_BNS_CHK		; �{�[�i�X�Q�[���`�F�b�N
//	RET	NZ			; �{�[�i�X�Q�[���H�D�D�x�d�r
//
//	LD	HL,_PT_IN0_UP
//	BIT	6,(HL)			; �ݒ�p�L�[�X�C�b�`�n�m�H
//	RET	Z			; �@�m�n
//
//	RST	S_BLOCKER_OFF		; �V�Z���_���u���b�J�[�n�e�e<�ԋp���>
//
//	LD	L,LOW _NB_PAY_LED
//	LD	B,(HL)			; �V�Z���_�����o�������\���@�ۑ�
//
//	LD	A,(_NB_RANK)
//	OR	0F0H
//	LD	(HL),A			; �ݒ�l�\��
//
//; �����N�\��
//
//MS_RANK_DSP1:
//	RST	S_WATCH_CLEAR		; �E�H�b�`�h�b�O�N���A
//
//	LD	A,(_PT_IN0_DOWN)
//	BIT	6,A			; �ݒ�p�L�[�X�C�b�`�n�m�H
//	JR	Z,MS_RANK_DSP1		; �@�x�d�r
//
//	LD	(HL),B			; �V�Z���_�����o�������\��  ���A
//
//	RST	S_BLOCKER_ON		; �V�Z���_���u���b�J�[�n�m<�ʉߏ��>
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0708-005					*
//;*	�@�\	      : ���܊��Ҏ��̏o�̓Z�b�g				*
//;*	Ӽޭ�ٖ�      : MS_HIT_SET					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    : 						*
//;*	�ی�ڼ޽�     : 						*
//;*	�j��ڼ޽�     : A,B,DE,HL					*
//;*	�g�pӼޭ��    : MS_BNS_CHK,S_LPSD_SET				*
//;************************************************************************
//;
//MS_HIT_SET:
//	CALL	MS_BNS_CHK		; �{�[�i�X�Q�[���`�F�b�N
//	RET	NZ			; �{�[�i�X�Q�[���H�D�D�x�d�r
//
//	LD	A,(_NB_STOP_ORDER)
//	CP	2			; ��Q�A���͑�R��~���H
//	RET	C			;   �m�n
//
//	LD	HL,_FL_WBL
//	JR	Z,MS_HIT_SET1		; ��Q��~�H�D�D�x�d�r
//
//; ��R��~���̏���
//
//	LD	A,(HL)			; // HL = _FL_WBL
//	AND	A			; ���܊��Ҏ��̕\������H
//	RET	Z			;   �m�n
//
//	LD	(HL),0			; ���܊��ҕ\���t���O�@�N���A
//
//	LD	A,(_WK_EFFECT_LP)	; ���܊��Ҏ��̌��ʃ����v
//					;;�p�^�[���m�F�v���@�Z�b�g
//	CP	@ELP_WBL       		; �p�^�[���o�͒��H
//	RET	NZ       		;   �m�n
//
//	LD	A,@SET_WBLEND		; ���܊��Ҏ��̏o�͏I���v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//	RET
//
//; ��Q��~���̏���
//
//MS_HIT_SET1:
//	LD	A,(_TM1_STOP)
//	AND	A			; �񓷒�~��t�҂��H
//	RET	NZ			;   �x�d�r
//
//	LD	A,(HL)			; // HL = _FL_WBL
//	AND	A			; ���܊��Ҏ��̕\���ς݁H
//	RET	NZ			;   �x�d�r
//
//	LD	L,LOW _WK_ALL_PIC2
//	LD	A,(HL)			; ��~�}���f�[�^�Q�i�S�L�����C���j�@�Z�b�g
//	AND	@BB OR @RB		; ���Y�}���\���H
//	RET	Z			;  �m�n
//
//	LD	A,@SET_WBLSTART		; ���܊��Ҏ��̏o�͗v���@�Z�b�g
//	DEC	HL			; ��~�}���f�[�^�P�i�S�L�����C���j�@�Z�b�g
//					; // HL = _WK_ALL_PIC1
//	BIT	@BT_CHERRY,(HL)		; �`�F���[�\���H
//	JR	NZ,MS_HIT_SET5		;   �x�d�r
//
//	LD	L,LOW _FL_STOP_LP	; �񓷒�~�t���O�@�Z�b�g
//	BIT	7,(HL)			; �E�񓷉�]���H
//	JR	Z,MS_HIT_SET5		;   �m�n
//
//	LD	DE,TBL_HIT_SET-1	; ���܊��ҕ\���p�^�[���e�[�u���@�Z�b�g
//	LD	L,LOW _WK_STOP_PIC2-1
//MS_HIT_SET2:
//	INC	HL			; // HL = _WK_STOP_PIC2+0�`+4
//	LD	A,(HL)			; ��~�}���f�[�^�Q�i�e�L�����C���j�@�Z�b�g
//	LD	B,@BNSPT		; �{�[�i�X�}�����@�Z�b�g
//MS_HIT_SET3:
//	INC	DE
//	RRCA				; ���Y�}�������I���H
//	JR	C,MS_HIT_SET4		;   �x�d�r
//
//	DJNZ	MS_HIT_SET3		; ���̃��C���H�D�D�m�n
//
//	JR	MS_HIT_SET2
//
//MS_HIT_SET4:
//	LD	A,(DE)			; �o�͗v���ԍ��@�Z�b�g
//MS_HIT_SET5:
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	LD	L,LOW _FL_WBL
//	LD	(HL),0FFH		; ���܊��ҕ\���t���O�@�Z�b�g
//
//	RET
//
//	PAGE
//;************************************************************************
//;*	�Ǘ��ԍ�      : S-0709-001					*
//;*	�@�\	      : �񓷒�~���̏o�̓Z�b�g				*
//;*	Ӽޭ�ٖ�      : MS_RLSTOP_SET					*
//;*	�������Ұ�    : 						*
//;*	�o�����Ұ�    : 						*
//;*	�ی�ڼ޽�     : 						*
//;*	�j��ڼ޽�     : A,B,DE,HL					*
//;*	�g�pӼޭ��    : S_ADDR_SET,S_LPSD_SET				*
//;************************************************************************
//;
//MS_RLSTOP_SET:
//	LD	B,00001000B		; �񓷃r�b�g�@�Z�b�g
//	LD	HL,_WK_REEL1 - 8	; �񓷐���f�[�^�q�`�l�A�h���X
//					;;�����l�@�Z�b�g
//MS_RLSTOP_SET1:
//	SRL	B			; �S�񓷃`�F�b�N�I���H
//	RET	C			;   �x�d�r
//
//	LD	A,_WK_REEL2-_WK_REEL1	; ���̉񓷐���f�[�^�q�`�l�A�h���X
//					;;�v���@�Z�b�g
//					; // A = 8
//	RST	S_ADDR_SET		; ���[�N�E�e�[�u���̃A�h���X�Z�b�g
//
//	LD	A,(HL)			; // HL = _WK_REEL# + 0
//	CP	4			; �񓷂S���㎥���H
//	JR	NZ,MS_RLSTOP_SET1	;   �m�n
//
//	LD	DE,_FL_STOP_LP
//	LD	A,(DE)
//	AND	B			; �񓷒�~���o�͍ς݁H
//	JR	NZ,MS_RLSTOP_SET1	;   �x�d�r
//
//	LD	A,(DE)			; // DE = _FL_STOP_LP
//	OR	B
//	LD	(DE),A			; �񓷒�~�t���O�@�Z�b�g
//
//	LD	A,@SET_R_STOP		; �񓷒�~���̏o�͗v���@�Z�b�g
//	RST	S_LPSD_SET		; �e�탉���v�E���ʉ��f�[�^�Z�b�g�P
//
//	RET
//
//PRG_END:
//
//	DEFS	59			; ���g�p
//
//	PAGE
//	ORG	1000H
//;	*************************************************
//;	*                          			*
//;	*	�q�n�l�萔�f�[�^�̈�			*
//;	*                          			*
//;	*************************************************
//;
//;	*************************************************
//;	*    �k�d�P�O�W�O�`������			*
//;	*************************************************
//;
//TBL_AMUSE_SET:
//;
//; �c�d�e�a�@�����f�o�C�X���W�X�^�A�h���X���ʁA�ݒ�f�[�^
//;
//; �����q�`�l
//	DEFB	14H	,00H	; ACT
//
//; �v���O���}�u�����ʃv���X�P�[��
//	DEFB	00H	,00H	; COS
//
//; ���Z�b�g�^���荞�݃R���g���[��
//	DEFB	02H	,00H	; IVAH
//	DEFB	04H	,05H	; IVAL
//	DEFB	06H	,00H	; URP
//
//; �A�h���X�f�R�[�_
//	DEFB	08H	,00H	; IDC
//
//; �p���������o�̓|�[�g
//	DEFB	16H	,00H	; PIC
//	DEFB	18H	,00H	; DOA
//	DEFB	19H	,00H	; DOB
//	DEFB	1AH	,0FFH	; DCA
//	DEFB	1BH	,00H	; DCB
//
//; �v���O���}�u���J�E���^�^�^�C�}�i�o�b�s�O�j
//	DEFB	22H	,00H	; PTC0
//	DEFB	23H	,11H	; PTM0
//	DEFB	24H	,07H	; CGT0
//	DEFB	25H	,1EH	; IC0
//	DEFB	27H	,00H	; PC0
//	DEFB	1CH	,0E8H	; DAL0
//	DEFB	1DH	,03H	; DAH0
//	DEFB	26H	,01H	; IFC0
//
//; �v���O���}�u���J�E���^�^�^�C�}�i�o�b�s�P�j
//	DEFB	30H	,00H	; PTC1
//	DEFB	31H	,19H	; PTM1
//	DEFB	32H	,00H	; CGT1
//	DEFB	33H	,1EH	; IC1
//	DEFB	35H	,05H	; PC1
//	DEFB	2AH	,51H	; DAL1
//	DEFB	2BH	,12H	; DAH1
//	DEFB	34H	,01H	; IFC1
//
//; �E�H�b�`�h�b�O�^�C�}
//	DEFB	3AH	,00H	; WDTC
//	DEFB	3CH	,00H	; WDTM
//
//	PAGE
//;	*************************************************
//;	*    �ݒ�l�i�����j				*
//;	*************************************************
//;
//TBL_INIT_RANK:
//	DEFB	6		; �ݒ�l�@�U
//
//;	*************************************************
//;	*    �q�`�l������				*
//;	*************************************************
//;
//; �P�s�ځF�q�`�l�������擪�A�h���X
//; �Q�s�ځF�q�`�l�������͈�
//;
//TBL_RAM_CLEAR1:			; �d�f���A���̂q�`�l�������p
//	DEFW	808FH		; _CT_BIG_WIN + 1
//	DEFW	305		; 808FH �` 81BFH
//
//TBL_RAM_CLEAR2:			; �V�Z�J�n���E�𕨘A���쓮�������u�쓮�I������
//				;;�q�`�l�������p
//	DEFW	808FH		; _CT_BIG_WIN + 1
//	DEFW	347		; 808FH �` 81E9H
//
//TBL_RAM_CLEAR3:			; �𕨘A���쓮�������u���܎��̂q�`�l�������p
//	DEFW	8062H		; _BF_RAND1
//	DEFW	45		; 8062H �` 808EH
//
//TBL_RAM_CLEAR4:			; �𕨘A���쓮�������u�쓮�I������
//				;;�q�`�l�������p
//	DEFW	800DH		; _NB_PAY_LED
//	DEFW	130		; 800DH �` 808EH
//
//	PAGE
//;	*************************************************
//;	*    �񓷋쓮�p���X				*
//;	*************************************************
//;
//TBL_REEL_PULSE:			; 1-2���@�쓮�p���X�@�f�[�^
//	DEFB	0011B
//	DEFB	0010B
//	DEFB	0110B
//	DEFB	0100B
//	DEFB	1100B
//	DEFB	1000B
//	DEFB	1001B
//	DEFB	0001B
//
//;	*************************************************
//;	*    �񓷗����オ��p�^�[��			*
//;	*************************************************
//;
//TBL_PULSE_UP:			; �񓷎n���i�����j�^�C�}���荞�݉�
//	DEFB	1,2,2,2,2,3,3,3,3,4,5,6,7,8,9,10,11,100
//
//;	*************************************************
//;	*    �L�����C�������v�_��			*
//;	*************************************************
//;
//TBL_LINE_LP:			; �o�̓r�b�g
//	DEFB	100B		; �P��
//	DEFB	1110B		; �Q��
//	DEFB	11111B		; �R��
//
//;	*************************************************
//;	*    �V�Z�O�k�d�c�Z�O�����g			*
//;	*************************************************
//;
//TBL_SEG_DATA:			; �k�d�c�Z�O�����g�@�o�̓r�b�g�f�[�^
//	DEFB	00111111B	; 0
//	DEFB	00000110B	; 1
//	DEFB	01011011B	; 2
//	DEFB	01001111B	; 3
//	DEFB	01100110B	; 4
//	DEFB	01101101B	; 5
//	DEFB	01111101B	; 6
//	DEFB	00000111B	; 7
//	DEFB	01111111B	; 8
//	DEFB	01101111B	; 9
//	DEFB	01111001B	; E
//	DEFB	01110011B	; P
//	DEFB	00111001B	; C
//	DEFB	01110110B	; H
//	DEFB	11111100B	; b.
//				;;�i�ł��~�ߎ����́A�𕨘A���쓮�������u���쓮����
//				;;�𕨘A���쓮���u�쓮���̕\���j
//	DEFB	00000000B	; blank
//
//	PAGE
//;	*************************************************
//;	*	�}���f�[�^��`				*
//;	*************************************************
//;
//@_PIC1		EQU	00111111B	; �}���P�Q
//@_PIC2		EQU	00000111B	; �}���Q�Q
//
//; �}���P�Q
//
//@FRUIT1  	EQU	00000001B	; (�R��R��R)
//@FRUIT2  	EQU	00000010B	; (���Â�����Â�����Â�)
//@REPLAY  	EQU	00000100B	; (��ޥ��ޥ���)
//@CHERRY  	EQU	00001000B	; (��ذ��|��|)
//@SRB     	EQU	00010000B	; (���Â�����Â��BAR)
//@JAC     	EQU	00100000B	; (��ذ���ޥ���)
//
//@FRUIT		EQU	00000011B	; (�R��R��R)�A(���Â�����Â�����Â�)
//
//@BT_CHERRY	EQU	3		; (��ذ��|��|)�@�r�b�g�ԍ�
//
//; �}���Q�Q
//
//@BB1     	EQU	00000001B	; (���ݥ���ݥ����)
//@BB2     	EQU	00000010B	; (���̐_����̐_����̐_)
//@RB      	EQU	00000100B	; (BAR�BAR�BAR)
//
//@BB		EQU	00000011B	; (���ݥ���ݥ����)�A(���̐_����̐_����̐_)
//
//@BNSPT		EQU	3		; �}���Q�Q�g�p�r�b�g��
//
//	PAGE
//;	*************************************************
//;	*	�񓷐}���z��				*
//;	*************************************************
//;
//TBL_PICTURE_ARG:
//
//;	*************************************************
//;	*	�}���z��P				*
//;	*************************************************
//;
//; ���񓷂̐}���z��
//
//	DEFB	@FRUIT2 OR @SRB			; 0
//	DEFB	@REPLAY				; 1
//	DEFB	0				; 2
//	DEFB	@FRUIT1				; 3
//	DEFB	@FRUIT1				; 4
//	DEFB	@FRUIT2 OR @SRB			; 5
//	DEFB	@REPLAY				; 6
//	DEFB	@FRUIT1				; 7
//	DEFB	@FRUIT1				; 8
//	DEFB	0				; 9
//	DEFB	@FRUIT2 OR @SRB			; 10
//	DEFB	@REPLAY				; 11
//	DEFB	@FRUIT1				; 12
//	DEFB	0				; 13
//	DEFB	@CHERRY OR @JAC			; 14
//	DEFB	0				; 15
//	DEFB	@FRUIT2 OR @SRB			; 16
//	DEFB	@REPLAY				; 17
//	DEFB	0				; 18
//	DEFB	@CHERRY OR @JAC			; 19
//	DEFB	0				; 20
//
//	DEFB	@FRUIT2 OR @SRB			; 0
//	DEFB	@REPLAY				; 1
//	DEFB	0				; 2
//	DEFB	@FRUIT1				; 3
//	DEFB	@FRUIT1				; 4
//	DEFB	@FRUIT2 OR @SRB			; 5
//
//	PAGE
//; ���񓷂̐}���z��
//
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 0
//	DEFB	@FRUIT2 OR @CHERRY OR @SRB	; 1
//	DEFB	@CHERRY				; 2
//	DEFB	@CHERRY				; 3
//	DEFB	@CHERRY				; 4
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 5
//	DEFB	@FRUIT2 OR @CHERRY OR @SRB	; 6
//	DEFB	@CHERRY				; 7
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 8
//	DEFB	@FRUIT2 OR @CHERRY OR @SRB	; 9
//	DEFB	@CHERRY				; 10
//	DEFB	@FRUIT2 OR @CHERRY OR @SRB	; 11
//	DEFB	@CHERRY				; 12
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 13
//	DEFB	@FRUIT2 OR @CHERRY OR @SRB	; 14
//	DEFB	@FRUIT1 OR @CHERRY		; 15
//	DEFB	@CHERRY				; 16
//	DEFB	@CHERRY				; 17
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 18
//	DEFB	@FRUIT2 OR @CHERRY OR @SRB	; 19
//	DEFB	@CHERRY				; 20
//
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 0
//	DEFB	@FRUIT2 OR @CHERRY OR @SRB	; 1
//	DEFB	@CHERRY				; 2
//	DEFB	@CHERRY				; 3
//	DEFB	@CHERRY				; 4
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 5
//
//	PAGE
//; �E�񓷂̐}���z��
//
//	DEFB	@FRUIT2 OR @CHERRY		; 0
//	DEFB	@CHERRY OR @SRB			; 1
//	DEFB	@FRUIT2 OR @CHERRY		; 2
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 3
//	DEFB	@CHERRY				; 4
//	DEFB	@FRUIT2 OR @CHERRY		; 5
//	DEFB	@CHERRY				; 6
//	DEFB	@CHERRY				; 7
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 8
//	DEFB	@FRUIT1 OR @CHERRY		; 9
//	DEFB	@FRUIT2 OR @CHERRY		; 10
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 11
//	DEFB	@FRUIT1 OR @CHERRY		; 12
//	DEFB	@FRUIT2 OR @CHERRY		; 13
//	DEFB	@CHERRY				; 14
//	DEFB	@CHERRY				; 15
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 16
//	DEFB	@CHERRY OR @SRB			; 17
//	DEFB	@FRUIT2 OR @CHERRY		; 18
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 19
//	DEFB	@CHERRY				; 20
//
//	DEFB	@FRUIT2 OR @CHERRY		; 0
//	DEFB	@CHERRY OR @SRB			; 1
//	DEFB	@FRUIT2 OR @CHERRY		; 2
//	DEFB	@REPLAY OR @CHERRY OR @JAC	; 3
//	DEFB	@CHERRY				; 4
//	DEFB	@FRUIT2 OR @CHERRY		; 5
//
//	PAGE
//;	*************************************************
//;	*	�}���z��Q				*
//;	*************************************************
//;
//; ���񓷂̐}���z��
//
//	DEFB	0			; 0
//	DEFB	0			; 1
//	DEFB	@BB2			; 2
//	DEFB	0			; 3
//	DEFB	0			; 4
//	DEFB	0			; 5
//	DEFB	0			; 6
//	DEFB	0			; 7
//	DEFB	0			; 8
//	DEFB	@BB2			; 9
//	DEFB	0			; 10
//	DEFB	0			; 11
//	DEFB	0			; 12
//	DEFB	@BB1			; 13
//	DEFB	0			; 14
//	DEFB	@RB			; 15
//	DEFB	0			; 16
//	DEFB	0			; 17
//	DEFB	@RB			; 18
//	DEFB	0			; 19
//	DEFB	@BB1			; 20
//
//	DEFB	0			; 0
//	DEFB	0			; 1
//	DEFB	@BB2			; 2
//	DEFB	0			; 3
//	DEFB	0			; 4
//	DEFB	0			; 5
//
//	PAGE
//; ���񓷂̐}���z��
//
//	DEFB	0			; 0
//	DEFB	0			; 1
//	DEFB	0			; 2
//	DEFB	0			; 3
//	DEFB	@RB			; 4
//	DEFB	0			; 5
//	DEFB	0			; 6
//	DEFB	@BB2			; 7
//	DEFB	0			; 8
//	DEFB	0			; 9
//	DEFB	0			; 10
//	DEFB	0			; 11
//	DEFB	0			; 12
//	DEFB	0			; 13
//	DEFB	0			; 14
//	DEFB	0			; 15
//	DEFB	0			; 16
//	DEFB	0			; 17
//	DEFB	0			; 18
//	DEFB	0			; 19
//	DEFB	@BB1			; 20
//
//	DEFB	0			; 0
//	DEFB	0			; 1
//	DEFB	0			; 2
//	DEFB	0			; 3
//	DEFB	@RB			; 4
//	DEFB	0			; 5
//
//	PAGE
//; �E�񓷂̐}���z��
//
//	DEFB	0			; 0
//	DEFB	@RB			; 1
//	DEFB	0			; 2
//	DEFB	0			; 3
//	DEFB	0			; 4
//	DEFB	0			; 5
//	DEFB	@BB2			; 6
//	DEFB	@BB2			; 7
//	DEFB	0			; 8
//	DEFB	0			; 9
//	DEFB	0			; 10
//	DEFB	0			; 11
//	DEFB	0			; 12
//	DEFB	0			; 13
//	DEFB	0			; 14
//	DEFB	0			; 15
//	DEFB	0			; 16
//	DEFB	@RB			; 17
//	DEFB	0			; 18
//	DEFB	0			; 19
//	DEFB	@BB1			; 20
//
//	DEFB	0			; 0
//	DEFB	@RB			; 1
//	DEFB	0			; 2
//	DEFB	0			; 3
//	DEFB	0			; 4
//	DEFB	0			; 5
//
//	PAGE
//;	*************************************************
//;	*	�L�����C������   			*
//;	*************************************************
//;
//TBL_LINE_SEARCH:
//; ���񓷁i�T���C�����j
//	DEFB	01H,01H,0FEH,02H,0FEH
//; ���񓷁i�T���C�����j
//	DEFB	01H,01H,0FEH,01H,00H
//; �E�񓷁i�T���C�����j
//	DEFB	01H,01H,0FEH,00H,02H
//
//;	*************************************************
//;	*	��~�}���f�[�^�����l			*
//;	*************************************************
//;
//TBL_INIT_PIC:
//	DEFB	@_PIC1					; ��~�}���f�[�^�P�i�S�L�����C���j�p
//	DEFB	@_PIC2					; ��~�}���f�[�^�Q�i�S�L�����C���j�p
//
//	DEFB	@_PIC1,@_PIC1,@_PIC1,@_PIC1,@_PIC1	; ��~�}���f�[�^�P�i�e�L�����C���j�p
//	DEFB	@_PIC2,@_PIC2,@_PIC2,@_PIC2,@_PIC2	; ��~�}���f�[�^�Q�i�e�L�����C���j�p
//
//	PAGE
//;	*************************************************
//;	*	�𕨗V�Z�}�����I�p�m��			*
//;	*************************************************
//;
//TBL_JAC_LOT:
//	DEFW	14745		; 1/1.11
//
//;	*************************************************
//;	*	���I�p�m���e�[�u���ύX��`		*
//;	*************************************************
//@LOT_RANK	EQU	32	; �ݒ�ʕύX�p�o�C�g��
//@LOT_MEDAL	EQU	192	; �V�Z���_���ʕύX�p�o�C�g��
//				; // = @LOT_RANK�~�U
//@LOT_BB		EQU	24	; �a�a�쓮����ʗV�Z�ύX�p�o�C�g��
//@LOT_IN_OUT	EQU	12	; �������J�E���^�ɂ��
//				;;�ύX�p�o�C�g��
//@NB_FRUIT	EQU	4	; �a�a���쓮����ʗV�Z��
//				;;��ʓ��ܐ}�����I��
//@BB_PLAY	EQU	4	; �a�a�쓮����ʗV�Z��
//				;;�}�����I��
//@NB_BONUS	EQU	2	; �a�a���쓮����ʗV�Z��
//				;;�a�a�E�q�a���I��
//
//;	*************************************************
//;	*	��ʗV�Z�}�����I�p�m��			*
//;	*************************************************
//;
//TBL_PIC_LOT:
//
//;	*************************************************
//;	*	�V�Z���_���P�������^�ݒ�l�P�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	   7		; 1/ 2340.57	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	 647		; 1/   25.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	  80		; 1/  204.80	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	 710		; 1/   23.08	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	 600		; 1/   27.31	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	   8    	; 1/ 2048.00	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���P�������^�ݒ�l�Q�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	   7		; 1/ 2340.57	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	 647		; 1/   25.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	  80		; 1/  204.80	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	 710		; 1/   23.08	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	 600		; 1/   27.31	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	   8    	; 1/ 2048.00	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���P�������^�ݒ�l�R�̊m��	*
//;	*************************************************
//sssssssssssssssssssssssssssssssssssssss
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	   7		; 1/ 2340.57	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	 647		; 1/   25.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	  80		; 1/  204.80	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	 710		; 1/   23.08	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	 600		; 1/   27.31	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	   8    	; 1/ 2048.00	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���P�������^�ݒ�l�S�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	   7		; 1/ 2340.57	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	 647		; 1/   25.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	  80		; 1/  204.80	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	 710		; 1/   23.08	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	 600		; 1/   27.31	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	   8    	; 1/ 2048.00	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���P�������^�ݒ�l�T�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	   7		; 1/ 2340.57	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	 647		; 1/   25.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	  80		; 1/  204.80	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	 710		; 1/   23.08	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	 600		; 1/   27.31	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	   8    	; 1/ 2048.00	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���P�������^�ݒ�l�U�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	   7		; 1/ 2340.57	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	 647		; 1/   25.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	  80		; 1/  204.80	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	 710		; 1/   23.08	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  11    	; 1/ 1489.45	�𕨘A���쓮�������u�쓮�}��
//	DEFW	   6		; 1/ 2730.67	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	 600		; 1/   27.31	(��ذ��|��|)
//	DEFW	   1		; 1/16384.00	(�R��R��R)
//	DEFW	   8    	; 1/ 2048.00	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���Q�������^�ݒ�l�P�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	  37		; 1/  442.81	(��ذ��|��|)
//	DEFW	   3		; 1/ 5461.33	(�R��R��R)
//	DEFW	1229		; 1/   13.33	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  23    	; 1/  712.35	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	 300		; 1/   54.61	(��ذ��|��|)
//	DEFW	  50		; 1/  327.68	(�R��R��R)
//	DEFW	1330		; 1/   12.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  23		; 1/  712.35	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	3400		; 1/    4.82	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	  20		; 1/  819.20	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���Q�������^�ݒ�l�Q�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	  37		; 1/  442.81	(��ذ��|��|)
//	DEFW	   3		; 1/ 5461.33	(�R��R��R)
//	DEFW	1229		; 1/   13.33	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  24    	; 1/  682.67	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	 300		; 1/   54.61	(��ذ��|��|)
//	DEFW	  50		; 1/  327.68	(�R��R��R)
//	DEFW	1330		; 1/   12.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  24		; 1/  682.67	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	3400		; 1/    4.82	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	  21		; 1/  780.19	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���Q�������^�ݒ�l�R�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	  37		; 1/  442.81	(��ذ��|��|)
//	DEFW	   3		; 1/ 5461.33	(�R��R��R)
//	DEFW	1229		; 1/   13.33	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  25    	; 1/  655.36	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	 300		; 1/   54.61	(��ذ��|��|)
//	DEFW	  50		; 1/  327.68	(�R��R��R)
//	DEFW	1330		; 1/   12.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  25		; 1/  655.36	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	3400		; 1/    4.82	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	  22		; 1/  744.73	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���Q�������^�ݒ�l�S�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	  37		; 1/  442.81	(��ذ��|��|)
//	DEFW	   3		; 1/ 5461.33	(�R��R��R)
//	DEFW	1229		; 1/   13.33	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  26    	; 1/  630.15	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	 300		; 1/   54.61	(��ذ��|��|)
//	DEFW	  50		; 1/  327.68	(�R��R��R)
//	DEFW	1330		; 1/   12.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  26		; 1/  630.15	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	3400		; 1/    4.82	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	  23		; 1/  712.35	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���Q�������^�ݒ�l�T�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	  37		; 1/  442.81	(��ذ��|��|)
//	DEFW	   3		; 1/ 5461.33	(�R��R��R)
//	DEFW	1229		; 1/   13.33	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  27    	; 1/  606.81	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	 300		; 1/   54.61	(��ذ��|��|)
//	DEFW	  50		; 1/  327.68	(�R��R��R)
//	DEFW	1330		; 1/   12.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  27		; 1/  606.81	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	3400		; 1/    4.82	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	  24		; 1/  682.67	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���Q�������^�ݒ�l�U�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	  37		; 1/  442.81	(��ذ��|��|)
//	DEFW	   3		; 1/ 5461.33	(�R��R��R)
//	DEFW	1229		; 1/   13.33	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  30    	; 1/  546.13	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	 300		; 1/   54.61	(��ذ��|��|)
//	DEFW	  50		; 1/  327.68	(�R��R��R)
//	DEFW	1330		; 1/   12.32	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  30		; 1/  546.13	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  17		; 1/  963.76	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	3400		; 1/    4.82	(��ذ��|��|)
//	DEFW	  20		; 1/  819.20	(�R��R��R)
//	DEFW	  25		; 1/  655.36	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���R�������^�ݒ�l�P�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	 201		; 1/   81.51	(��ذ��|��|)
//	DEFW	   4		; 1/ 4096.00	(�R��R��R)
//	DEFW	1793		; 1/    9.14	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  47		; 1/  348.60	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  25		; 1/  655.36	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	1000		; 1/   16.38	(��ذ��|��|)
//	DEFW	 100		; 1/  163.84	(�R��R��R)
//	DEFW	1795		; 1/    9.13	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  47		; 1/  348.60	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  25		; 1/  655.36	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	9970		; 1/    1.64	(��ذ��|��|)
//	DEFW	  30		; 1/  546.13    (�R��R��R)
//	DEFW	  30		; 1/  546.13	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���R�������^�ݒ�l�Q�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	 201		; 1/   81.51	(��ذ��|��|)
//	DEFW	   4		; 1/ 4096.00	(�R��R��R)
//	DEFW	1793		; 1/    9.14	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  49		; 1/  334.37	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  25		; 1/  655.36	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	1000		; 1/   16.38	(��ذ��|��|)
//	DEFW	 100		; 1/  163.84	(�R��R��R)
//	DEFW	1795		; 1/    9.13	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  49		; 1/  334.37	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  25		; 1/  655.36	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	9970		; 1/    1.64	(��ذ��|��|)
//	DEFW	  30		; 1/  546.13    (�R��R��R)
//	DEFW	  31		; 1/  528.52	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���R�������^�ݒ�l�R�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	 201		; 1/   81.51	(��ذ��|��|)
//	DEFW	   4		; 1/ 4096.00	(�R��R��R)
//	DEFW	1793		; 1/    9.14	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  52		; 1/  315.08	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  25		; 1/  655.36	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	1000		; 1/   16.38	(��ذ��|��|)
//	DEFW	 100		; 1/  163.84	(�R��R��R)
//	DEFW	1795		; 1/    9.13	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  52		; 1/  315.08	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  25		; 1/  655.36	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	9970		; 1/    1.64	(��ذ��|��|)
//	DEFW	  30		; 1/  546.13    (�R��R��R)
//	DEFW	  32		; 1/  512.00	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���R�������^�ݒ�l�S�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	 201		; 1/   81.51	(��ذ��|��|)
//	DEFW	   4		; 1/ 4096.00	(�R��R��R)
//	DEFW	1793		; 1/    9.14	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  55		; 1/  297.89	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  26		; 1/  630.15	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	1000		; 1/   16.38	(��ذ��|��|)
//	DEFW	 100		; 1/  163.84	(�R��R��R)
//	DEFW	1795		; 1/    9.13	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  55		; 1/  297.89	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  26		; 1/  630.15	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	9970		; 1/    1.64	(��ذ��|��|)
//	DEFW	  30		; 1/  546.13    (�R��R��R)
//	DEFW	  33		; 1/  496.48	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���R�������^�ݒ�l�T�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	 201		; 1/   81.51	(��ذ��|��|)
//	DEFW	   4		; 1/ 4096.00	(�R��R��R)
//	DEFW	1793		; 1/    9.14	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  60		; 1/  273.07	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  26		; 1/  630.15	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	1000		; 1/   16.38	(��ذ��|��|)
//	DEFW	 100		; 1/  163.84	(�R��R��R)
//	DEFW	1795		; 1/    9.13	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  60		; 1/  273.07	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  26		; 1/  630.15	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	9970		; 1/    1.64	(��ذ��|��|)
//	DEFW	  30		; 1/  546.13    (�R��R��R)
//	DEFW	  34		; 1/  481.88	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*	�V�Z���_���R�������^�ݒ�l�U�̊m��	*
//;	*************************************************
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i����Ғl�j ******
//
//	DEFW	 201		; 1/   81.51	(��ذ��|��|)
//	DEFW	   4		; 1/ 4096.00	(�R��R��R)
//	DEFW	1793		; 1/    9.14	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  68		; 1/  240.94	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  45		; 1/  364.09	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u���쓮����ʗV�Z�i�����Ғl�j ******
//
//	DEFW	1000		; 1/   16.38	(��ذ��|��|)
//	DEFW	 100		; 1/  163.84	(�R��R��R)
//	DEFW	1795		; 1/    9.13	(���Â�����Â�����Â�)
//	DEFW	2245		; 1/    7.30	�ėV�Z�쓮�}��
//
//	DEFW	  68		; 1/  240.94	�𕨘A���쓮�������u�쓮�}��
//	DEFW	  45		; 1/  364.09	�𕨘A���쓮���u�쓮�}��
//
//;****** �𕨘A���쓮�������u�쓮����ʗV�Z ********************
//
//	DEFW	9970		; 1/    1.64	(��ذ��|��|)
//	DEFW	  30		; 1/  546.13    (�R��R��R)
//	DEFW	  35		; 1/  468.11	(���Â�����Â�����Â�)
//	DEFW	4710		; 1/    3.48	�𕨘A���쓮���u�쓮�}��
//
//	PAGE
//;	*************************************************
//;	*    	�X�Βl					*
//;	*************************************************
//;
//TBL_IN_OUT:
//	DEFB	 96		; �ݒ�P�@�O�D�R�V�T�O
//	DEFB	 96		; �ݒ�Q�@�O�D�R�V�T�O
//	DEFB	 96		; �ݒ�R�@�O�D�R�V�T�O
//	DEFB	 96		; �ݒ�S�@�O�D�R�V�T�O
//	DEFB	 96		; �ݒ�T�@�O�D�R�V�T�O
//	DEFB	 96		; �ݒ�U�@�O�D�R�V�T�O
//
//	PAGE
//;	*************************************************
//;	*	�}�����I�p�f�[�^�ԍ�	 		*
//;	*************************************************
//;
//@NM_BONUS	EQU	1	; �a�a���쓮����ʗV�Z��
//				;;�a�a�E�q�a�쓮�}�����I�J�n�p
//@NM_BBPLAY	EQU	8	; �a�a�쓮����ʗV�Z�����I�J�n�p
//@NM_FRUIT	EQU	3	; �a�a���쓮����ʗV�Z��
//				;;��ʓ��ܐ}�����I�J�n�p
//@NM_NFAIL	EQU	7	; �a�a���쓮����ʗV�Z���͂���p
//@NM_JHIT	EQU	13	; �𕨗V�Z���I�p
//
//	PAGE
//;	*************************************************
//;	*	�����݁E�R��΂��}��	 		*
//;	*************************************************
//;
//TBL_PICTURE_SET:
//
//;	�a�a���쓮����ʗV�Z��
//
//;	�i1�j(���ݥ���ݥ����)�A(���̐_����̐_����̐_)�p�f�[�^�r�b�g
//
//	DEFB	0				; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @REPLAY OR @FRUIT	; �R��΂��}���f�[�^�P
//	DEFB	@BB				; �����ݐ}���f�[�^�Q
//	DEFB	@RB				; �R��΂��}���f�[�^�Q
//
//;	�i2�j(BAR�BAR�BAR)�p�f�[�^�r�b�g
//
//	DEFB	0				; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @REPLAY OR @FRUIT	; �R��΂��}���f�[�^�P
//	DEFB	@RB				; �����ݐ}���f�[�^�Q
//	DEFB	@BB				; �R��΂��}���f�[�^�Q
//
//;	�i3�j(��ذ��|��|)�p�f�[�^�r�b�g
//
//	DEFB	@CHERRY				; �����ݐ}���f�[�^�P
//	DEFB	@REPLAY OR @FRUIT		; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i4�j(�R��R��R)�p�f�[�^�r�b�g
//
//	DEFB	@FRUIT1				; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @REPLAY OR @FRUIT2	; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i5�j(���Â�����Â�����Â�)�p�f�[�^�r�b�g
//
//	DEFB	@FRUIT2				; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @REPLAY OR @FRUIT1	; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i6�j(��ޥ��ޥ���)���I�p�f�[�^�r�b�g
//
//	DEFB	@REPLAY				; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @FRUIT		; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i7�j��ʗV�Z�͂���p�f�[�^�r�b�g
//
//	DEFB	0				; �����ݐ}���f�[�^�P
//	DEFB	@REPLAY OR @CHERRY OR @FRUIT	; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//	PAGE
//;�a�a�쓮����ʗV�Z��
//;	�i8�j(��ذ��|��|)�p�f�[�^�r�b�g
//
//	DEFB	@CHERRY				; �����ݐ}���f�[�^�P
//	DEFB	@REPLAY OR @FRUIT OR @SRB	; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i9�j(�R��R��R)�p�f�[�^�r�b�g
//
//	DEFB	@FRUIT1				; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @REPLAY OR @FRUIT2 OR @SRB	; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i10�j(���Â�����Â�����Â�)�p�f�[�^�r�b�g
//
//	DEFB	@FRUIT2				; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @REPLAY OR @FRUIT1 OR @SRB	; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i11�j(��ޥ��ޥ���)�A(���Â�����Â��BAR)�p�f�[�^�r�b�g
//
//	DEFB	@REPLAY	OR @SRB			; �����ݐ}���f�[�^�P
//	DEFB	@CHERRY OR @FRUIT		; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�i12�j�͂���p�f�[�^�r�b�g
//
//	DEFB	0				; �����ݐ}���f�[�^�P
//	DEFB	@_PIC1 XOR @JAC			; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//;	�𕨗V�Z��
//
//;	�i13�j�𕨗V�Z(��ذ���ޥ���)�A(��ޥ��ޥ���)�p�f�[�^�r�b�g
//
//	DEFB	@REPLAY OR @JAC			; �����ݐ}���f�[�^�P
//	DEFB	@FRUIT OR @SRB			; �R��΂��}���f�[�^�P
//	DEFB	0				; �����ݐ}���f�[�^�Q
//	DEFB	@_PIC2				; �R��΂��}���f�[�^�Q
//
//	PAGE
//;	*************************************************
//;	*	�����݁E�R��΂�����			*
//;	*************************************************
//;
//;
//; �`�F���[�R��΂�����
//
//TBL_CHERRY_REJ:
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^�P�����p
//
//	DEFB	LOW _WK_ALL_PIC1	; ��~�}���f�[�^�P�i�S�L�����C���j�����p
//
//	DEFB	@CHERRY			; ����}���f�[�^�i�S�L�����C���j
//
//	DEFB	LOW _WK_REEL_PIC1	; �񓷐}���f�[�^�P�����p
//
//	DEFB	LOW _WK_STOP_PIC1	; ��~�}���f�[�^�P�i�e�L�����C���j�����p
//
//	DEFB	11111000B		; �R��΂��t���O
//
//	DEFB	@CHERRY			; ��P���C���̐���}���f�[�^
//	DEFB	@CHERRY			; ��Q���C���̐���}���f�[�^
//	DEFB	@CHERRY			; ��R���C���̐���}���f�[�^
//	DEFB	@CHERRY			; ��S���C���̐���}���f�[�^
//	DEFB	@CHERRY			; ��T���C���̐���}���f�[�^
//
//	PAGE
//; ��R��~���̏R��΂�����
//
//TBL_ETC_REJ:
//
//; �}���P�Q�̏R��΂��p�@(�R��R��R)�A(���Â�����Â�����Â�)�A(��ޥ��ޥ���)
//;;                      �y��(���Â�����Â��BAR)
//
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^�P�����p
//
//	DEFB	LOW _WK_ALL_PIC1	; ��~�}���f�[�^�P�i�S�L�����C���j�����p
//
//	DEFB	@REPLAY OR @FRUIT OR @SRB; ����}���f�[�^�i�S�L�����C���j
//
//	DEFB	LOW _WK_REEL_PIC1	; �񓷐}���f�[�^�P�����p
//
//	DEFB	LOW _WK_STOP_PIC1	; ��~�}���f�[�^�P�i�e�L�����C���j�����p
//
//	DEFB	11111000B		; �R��΂��t���O
//
//	DEFB	@FRUIT OR @REPLAY OR @SRB; ��P���C���̐���}���f�[�^
//	DEFB	@FRUIT OR @REPLAY OR @SRB; ��Q���C���̐���}���f�[�^
//	DEFB	@FRUIT OR @REPLAY OR @SRB; ��R���C���̐���}���f�[�^
//	DEFB	@FRUIT OR @REPLAY OR @SRB; ��S���C���̐���}���f�[�^
//	DEFB	@FRUIT OR @REPLAY OR @SRB; ��T���C���̐���}���f�[�^
//
//; �}���Q�Q�̏R��΂��p
//
//	DEFB	LOW _FL_REJ_PIC2	; �R��΂��}���f�[�^�Q�����p
//
//	DEFB	LOW _WK_ALL_PIC2	; ��~�}���f�[�^�Q�i�S�L�����C���j�����p
//
//	DEFB	@_PIC2			; ����}���f�[�^�i�S�L�����C���j
//
//	DEFB	LOW _WK_REEL_PIC2	; �񓷐}���f�[�^�Q�����p
//
//	DEFB	LOW _WK_STOP_PIC2	; ��~�}���f�[�^�Q�i�e�L�����C���j�����p
//
//	DEFB	11111000B		; �R��΂��t���O
//
//	DEFB	@_PIC2			; ��P���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��Q���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��R���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��S���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��T���C���̐���}���f�[�^
//
//	PAGE
//; ��Q��~���̏R��΂�����
//
//; �}���P�Q�̏R��΂��p�@(���Â�����Â�����Â�)�A(��ޥ��ޥ���)�y��(���Â�����Â��BAR)
//TBL_EXT_REJ:
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^�P�����p
//
//	DEFB	LOW _WK_ALL_PIC1	; ��~�}���f�[�^�P�i�S�L�����C���j�����p
//
//	DEFB	@FRUIT2	OR @REPLAY OR @SRB	; ����}���f�[�^�i�S�L�����C���j
//
//	DEFB	LOW _WK_REEL_PIC1	; �񓷐}���f�[�^�P�����p
//
//	DEFB	LOW _WK_STOP_PIC1	; ��~�}���f�[�^�P�i�e�L�����C���j�����p
//
//	DEFB	11111000B		; �R��΂��t���O
//
//	DEFB	@SRB    		; ��P���C���̐���}���f�[�^
//	DEFB	@REPLAY		 	; ��Q���C���̐���}���f�[�^
//	DEFB	@FRUIT2	OR @REPLAY	; ��R���C���̐���}���f�[�^
//	DEFB	0			; ��S���C���̐���}���f�[�^
//	DEFB	@REPLAY OR @SRB		; ��T���C���̐���}���f�[�^
//
//; �}���Q�Q�̏R��΂��p�@(���̐_����̐_����̐_)
//
//	DEFB	LOW _FL_REJ_PIC2	; �R��΂��}���f�[�^�P�����p
//
//	DEFB	LOW _WK_ALL_PIC2	; ��~�}���f�[�^�P�i�S�L�����C���j�����p
//
//	DEFB	@BB2    		; ����}���f�[�^�i�S�L�����C���j
//
//	DEFB	LOW _WK_REEL_PIC2	; �񓷐}���f�[�^�P�����p
//
//	DEFB	LOW _WK_STOP_PIC2	; ��~�}���f�[�^�P�i�e�L�����C���j�����p
//
//	DEFB	11111000B		; �R��΂��t���O
//
//	DEFB	0	    		; ��P���C���̐���}���f�[�^
//	DEFB	@BB2     		; ��Q���C���̐���}���f�[�^
//	DEFB	0			; ��R���C���̐���}���f�[�^
//	DEFB	0			; ��S���C���̐���}���f�[�^
//	DEFB	0			; ��T���C���̐���}���f�[�^
//
//	PAGE
//; �����ݐ���
//
//TBL_ALL_PUL:
//
//; �}���P�Q�̈����ݗp
//
//	DEFB	LOW _FL_PUL_PIC1	; �����ݐ}���f�[�^�P�����p
//
//	DEFB	LOW _WK_ALL_PIC1	; ��~�}���f�[�^�P�i�S�L�����C���j�����p
//
//	DEFB	@_PIC1			; ����}���f�[�^�i�S�L�����C���j
//
//	DEFB	LOW _WK_REEL_PIC1	; �񓷐}���f�[�^�P�����p
//
//	DEFB	LOW _WK_STOP_PIC1	; ��~�}���f�[�^�P�i�e�L�����C���j�����p
//
//	DEFB	00000000B		; �����݃t���O
//
//	DEFB	@_PIC1		 	; ��P���C���̐���}���f�[�^
//	DEFB	@_PIC1		 	; ��Q���C���̐���}���f�[�^
//	DEFB	@_PIC1		 	; ��R���C���̐���}���f�[�^
//	DEFB	@_PIC1		 	; ��S���C���̐���}���f�[�^
//	DEFB	@_PIC1		 	; ��T���C���̐���}���f�[�^
//
//; �}���Q�Q�̈����ݗp
//
//	DEFB	LOW _FL_PUL_PIC2	; �����ݐ}���f�[�^�Q�����p
//
//	DEFB	LOW _WK_ALL_PIC2	; ��~�}���f�[�^�Q�i�S�L�����C���j�����p
//
//	DEFB	@_PIC2			; ����}���f�[�^�i�S�L�����C���j
//
//	DEFB	LOW _WK_REEL_PIC2	; �񓷐}���f�[�^�Q�����p
//
//	DEFB	LOW _WK_STOP_PIC2	; ��~�}���f�[�^�Q�i�e�L�����C���j�����p
//
//	DEFB	00000000B		; �����݃t���O
//
//	DEFB	@_PIC2			; ��P���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��Q���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��R���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��S���C���̐���}���f�[�^
//	DEFB	@_PIC2			; ��T���C���̐���}���f�[�^
//
//	PAGE
//;	*************************************************
//;	*     ���I�}���ʒ�~�ʒu����p�e�[�u������  	*
//;	*************************************************
//;
//TBL_STOP_SELECT:
//
//; �i�P�j�@�𕨘A���쓮�������u���I���y��
//;;      �@�𕨘A���쓮�������u�������V�Z���̂͂��ꎞ
//
//	DEFB	0			; �����ݐ}���f�[�^�P�����p
//	DEFB	@BB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT1		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�e�[�u��
//
//; �i�Q�j�@�𕨘A���쓮�������u�������V�Z����(��ޥ��ޥ���)���I��
//
//	DEFB	@REPLAY			; �����ݐ}���f�[�^�P�����p
//	DEFB	@BB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT5		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���T�e�[�u��
//
//; �i�R�j�@�𕨘A���쓮�������u�������V�Z����(�R��R��R)���I��
//
//	DEFB	@FRUIT1			; �����ݐ}���f�[�^�P�����p
//	DEFB	@BB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT3		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���R�e�[�u��
//
//; �i�S�j�@�𕨘A���쓮�������u�������V�Z����(���Â�����Â�����Â�)���I��
//
//	DEFB	@FRUIT2			; �����ݐ}���f�[�^�P�����p
//	DEFB	@BB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT4		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���S�e�[�u��
//
//; �i�T�j�@�𕨘A���쓮�������u�������V�Z����(��ذ��|��|)���I��
//
//	DEFB	@CHERRY			; �����ݐ}���f�[�^�P�����p
//	DEFB	@BB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT2		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���Q�e�[�u��
//
//; �i�U�j�@�𕨘A���쓮�������u���쓮���̖𕨘A���쓮���u���I���y��
//;;	�@�𕨘A���쓮���u�������V�Z���̂͂��ꎞ
//
//	DEFB	0			; �����ݐ}���f�[�^�P�����p
//	DEFB	@RB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT6		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���U�e�[�u��
//
//; �i�V�j�@�𕨘A���쓮���u�������V�Z����(��ޥ��ޥ���)���I��
//
//	DEFB	@REPLAY			; �����ݐ}���f�[�^�P�����p
//	DEFB	@RB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT5		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���T�e�[�u��
//
//; �i�W�j�@�𕨘A���쓮���u�������V�Z����(�R��R��R)���I��
//
//	DEFB	@FRUIT1			; �����ݐ}���f�[�^�P�����p
//	DEFB	@RB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT8		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���W�e�[�u��
//
//	PAGE
//; �i�X�j�@�𕨘A���쓮���u�������V�Z����(���Â�����Â�����Â�)���I��
//
//	DEFB	@FRUIT2			; �����ݐ}���f�[�^�P�����p
//	DEFB	@RB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT4		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���S�e�[�u��
//
//; �i�P�O�j�@�𕨘A���쓮���u�������V�Z����(��ذ��|��|)���I��
//
//	DEFB	@CHERRY			; �����ݐ}���f�[�^�P�����p
//	DEFB	@RB			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT7		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���V�e�[�u��
//
//; �i�P�P�j�@��ʗV�Z����(��ޥ��ޥ���)���I��
//
//	DEFB	@REPLAY			; �����ݐ}���f�[�^�P�����p
//	DEFB	0			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT12		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�Q�e�[�u��
//
//; �i�P�Q�j�@��ʗV�Z����(�R��R��R)���I��
//
//	DEFB	@FRUIT1			; �����ݐ}���f�[�^�P�����p
//	DEFB	0			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT10		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�O�e�[�u��
//
//; �i�P�R�j�@��ʗV�Z����(���Â�����Â�����Â�)���I��
//
//	DEFB	@FRUIT2			; �����ݐ}���f�[�^�P�����p
//	DEFB	0			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT11		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�P�e�[�u��
//
//; �i�P�S�j  ��ʗV�Z����(��ذ��|��|)���I��
//
//	DEFB	@CHERRY			; �����ݐ}���f�[�^�P�����p
//	DEFB	0			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT9		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���X�e�[�u��
//
//; �i�P�T�j�@�͂��ꎞ
//
//	DEFB	0			; �����ݐ}���f�[�^�P�����p
//	DEFB	0			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT13		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�R�e�[�u��
//
//; �i�P�U�j�@�𕨘A���쓮�������u�쓮���̈�ʗV�Z����(��ޥ��ޥ���)�A(���Â�����Â��BAR)���I��
//
//	DEFB	@REPLAY OR @SRB		; �����ݐ}���f�[�^�P�����p
//	DEFB	0			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT14		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�S�e�[�u��
//
//; �i�P�V�j�@�𕨗V�Z����(��ޥ��ޥ���)�A(��ذ���ޥ���)���I��
//
//	DEFB	@REPLAY OR @JAC		; �����ݐ}���f�[�^�P�����p
//	DEFB	0			; �����ݐ}���f�[�^�Q�����p
//
//	DEFW	TBL_STOP_LOT13		; ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�R�e�[�u��
//
//	PAGE
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P     *
//;	*************************************************
//;
//TBL_STOP_LOT1:
//	DEFW	TBL_STOP_CTL1 - 22	; �𕨘A���쓮�������u���I���y��
//					;;�𕨘A���쓮�������u�������V�Z���̂͂��ꎞ
//
//	DEFB	6			; �p�^�[���P�@���@�@�U�^�P�Q�W
//	DEFB	12			; �p�^�[���Q�@���@�P�Q�^�P�Q�W
//	DEFB	12			; �p�^�[���R�@���@�P�Q�^�P�Q�W
//	DEFB	27			; �p�^�[���S�@���@�Q�V�^�P�Q�W
//	DEFB	1			; �p�^�[���T�@���@�@�P�^�P�Q�W
//	DEFB	22			; �p�^�[���U�@���@�Q�Q�^�P�Q�W
//	DEFB	12			; �p�^�[���V�@���@�P�Q�^�P�Q�W
//	DEFB	5			; �p�^�[���W�@���@�@�T�^�P�Q�W
//	DEFB	12			; �p�^�[���X�@���@�P�Q�^�P�Q�W
//	DEFB	19			; �p�^�[���P�O���@�P�X�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���Q     *
//;	*************************************************
//;
//TBL_STOP_LOT2:
//	DEFW	TBL_STOP_CTL2 - 22	; �𕨘A���쓮�������u�������V�Z����
//					;;(��ذ�-�-)���I��
//					;;
//
//	DEFB	64			; �p�^�[���P�@���@�U�S�^�P�Q�W
//	DEFB	63			; �p�^�[���Q�@���@�U�R�^�P�Q�W
//	DEFB	1			; �p�^�[���R�@���@�@�P�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���R     *
//;	*************************************************
//;
//TBL_STOP_LOT3:
//	DEFW	TBL_STOP_CTL3 - 22	; �𕨘A���쓮�������u�������V�Z����
//					;;(�R��R��R)���I��
//					;;
//
//	DEFB	46			; �p�^�[���P�@���@�S�U�^�P�Q�W
//	DEFB	46			; �p�^�[���Q�@���@�S�U�^�P�Q�W
//	DEFB	36			; �p�^�[���R�@���@�R�U�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���S     *
//;	*************************************************
//;
//TBL_STOP_LOT4:
//	DEFW	TBL_STOP_CTL4 - 22	; �������V�Z����(���Â�����Â�����Â�)���I��
//
//	DEFB	64			; �p�^�[���P�@���@�U�S�^�P�Q�W
//	DEFB	64			; �p�^�[���Q�@���@�U�S�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���T     *
//;	*************************************************
//;
//TBL_STOP_LOT5:
//	DEFW	TBL_STOP_CTL5 - 22	; �������V�Z����(��ޥ��ޥ���)���I��
//
//	DEFB	98			; �p�^�[���P�@���@�X�W�^�P�Q�W
//	DEFB	30			; �p�^�[���Q�@���@�R�O�^�P�Q�W
//
//
//	PAGE
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���U     *
//;	*************************************************
//;
//TBL_STOP_LOT6:
//	DEFW	TBL_STOP_CTL6 - 22	; �𕨘A���쓮�������u���쓮����
//					;;�𕨘A���쓮���u���I���y�і�
//					;;�A���쓮���u�������V�Z���̂͂��ꎞ
//
//	DEFB	26			; �p�^�[���P�@���@�Q�U�^�P�Q�W
//	DEFB	59			; �p�^�[���Q�@���@�T�X�^�P�Q�W
//	DEFB	3			; �p�^�[���R�@���@�@�R�^�P�Q�W
//	DEFB	3			; �p�^�[���S�@���@�@�R�^�P�Q�W
//	DEFB	34			; �p�^�[���T�@���@�R�S�^�P�Q�W
//	DEFB	3			; �p�^�[���U�@���@�@�R�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���V     *
//;	*************************************************
//;
//TBL_STOP_LOT7:
//	DEFW	TBL_STOP_CTL7 - 22	; �𕨘A���쓮���u�������V�Z����
//					;;(��ذ��|��|)���I��
//
//	DEFB	64			; �p�^�[���P�@���@�U�S�^�P�Q�W
//	DEFB	63			; �p�^�[���Q�@���@�U�R�^�P�Q�W
//	DEFB	1			; �p�^�[���R�@���@�@�P�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���W     *
//;	*************************************************
//;
//TBL_STOP_LOT8:
//	DEFW	TBL_STOP_CTL8 - 22	; �𕨘A���쓮���u�������V�Z����
//					;;(�R��R��R)���I��
//
//	DEFB	64			; �p�^�[���P�@���@�U�S�^�P�Q�W
//	DEFB	64			; �p�^�[���Q�@���@�U�S�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���X     *
//;	*************************************************
//;
//TBL_STOP_LOT9:
//	DEFW	TBL_STOP_CTL9 - 22	; ��ʗV�Z����(��ذ��|��|)���I��
//
//	DEFB	124			; �p�^�[���P�@���P�Q�S�^�P�Q�W
//	DEFB	3			; �p�^�[���Q�@���@�@�R�^�P�Q�W
//	DEFB	1			; �p�^�[���R�@���@�@�P�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�O   *
//;	*************************************************
//;
//TBL_STOP_LOT10:
//	DEFW	TBL_STOP_CTL10 - 22	; ��ʗV�Z����(�R��R��R)���I��
//
//	DEFB	20			; �p�^�[���P�@���@�Q�O�^�P�Q�W
//	DEFB	76			; �p�^�[���Q�@���@�V�U�^�P�Q�W
//	DEFB	32			; �p�^�[���R�@���@�R�Q�^�P�Q�W
//
//
//	PAGE
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�P   *
//;	*************************************************
//;
//TBL_STOP_LOT11:
//	DEFW	TBL_STOP_CTL11 - 22	; ��ʗV�Z����(���Â�����Â�����Â�)
//					;;���I��
//
//	DEFB	64			; �p�^�[���P�@���@�U�S�^�P�Q�W
//	DEFB	64			; �p�^�[���Q�@���@�U�S�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�Q   *
//;	*************************************************
//;
//TBL_STOP_LOT12:
//	DEFW	TBL_STOP_CTL12 - 22	; ��ʗV�Z����(��ޥ��ޥ���)���I��
//
//	DEFB	64			; �p�^�[���P�@���@�U�S�^�P�Q�W
//	DEFB	64			; �p�^�[���Q�@���@�U�S�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�R   *
//;	*************************************************
//;
//TBL_STOP_LOT13:
//	DEFW	TBL_STOP_CTL13 - 22	; �͂��ꎞ�y�і𕨗V�Z����(��ޥ��ޥ���)
//					;;�A(��ذ���ޥ���)���I��
//
//	DEFB	3			; �p�^�[���P�@���@�@�R�^�P�Q�W
//	DEFB	36			; �p�^�[���Q�@���@�R�U�^�P�Q�W
//	DEFB	3			; �p�^�[���R�@���@�@�R�^�P�Q�W
//	DEFB	24			; �p�^�[���S�@���@�Q�S�^�P�Q�W
//	DEFB	10			; �p�^�[���T�@���@�P�O�^�P�Q�W
//	DEFB	8			; �p�^�[���U�@���@�@�W�^�P�Q�W
//	DEFB	3			; �p�^�[���V�@���@�@�R�^�P�Q�W
//	DEFB	12			; �p�^�[���W�@���@�P�Q�^�P�Q�W
//	DEFB	6			; �p�^�[���X�@���@�@�U�^�P�Q�W
//	DEFB	14			; �p�^�[���P�O���@�P�S�^�P�Q�W
//	DEFB	9			; �p�^�[���P�P���@�@�X�^�P�Q�W
//
//
//;	*************************************************
//;	*    ��~�ʒu����p�e�[�u���I�𒊑I�p�m���P�S   *
//;	*************************************************
//;
//TBL_STOP_LOT14:
//	DEFW	TBL_STOP_CTL14 - 22	; �𕨘A���쓮�������u�쓮���̈�ʗV�Z����
//					;;(��ޥ��ޥ���)�A(���Â�����Â��BAR)���I��
//
//	DEFB	127			; �p�^�[���P�@���P�Q�V�^�P�Q�W
//	DEFB	1			; �p�^�[���Q�@���@�@�P�^�P�Q�W
//
//
//	PAGE
//;	*****************************************************************
//;	*	�𕨘A���쓮�������u���I���y��				*
//;	*	�𕨘A���쓮�������u�������V�Z���̂͂��ꎞ		*
//;	*****************************************************************
//;
//TBL_STOP_CTL1:
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	01101001B		; 0
//	DEFB	01000100B		; 1
//	DEFB	00000000B		; 2
//	DEFB	11010000B		; 3
//	DEFB	11011110B		; 4
//	DEFB	10100101B		; 5
//	DEFB	01111100B		; 6
//	DEFB	01010110B		; 7
//	DEFB	00110000B		; 8
//	DEFB	00000101B		; 9
//	DEFB	11100110B		; 10
//	DEFB	11100000B		; 11
//	DEFB	10010101B		; 12
//	DEFB	01010000B		; 13
//	DEFB	00101000B		; 14
//	DEFB	00011101B		; 15
//	DEFB	10111000B		; 16
//	DEFB	11100100B		; 17
//	DEFB	01010110B		; 18
//	DEFB	00101000B		; 19
//	DEFB	00000100B		; 20
//
//; �p�^�[���Q
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	01011000B		; 0
//	DEFB	00101010B		; 1
//	DEFB	00100000B		; 2
//	DEFB	11010000B		; 3
//	DEFB	11011001B		; 4
//	DEFB	10110100B		; 5
//	DEFB	01111000B		; 6
//	DEFB	01010010B		; 7
//	DEFB	00110000B		; 8
//	DEFB	00000100B		; 9
//	DEFB	11101001B		; 10
//	DEFB	11101000B		; 11
//	DEFB	10010010B		; 12
//	DEFB	01100100B		; 13
//	DEFB	00110000B		; 14
//	DEFB	00000001B		; 15
//	DEFB	11000000B		; 16
//	DEFB	11011100B		; 17
//	DEFB	01110010B		; 18
//	DEFB	01000000B		; 19
//	DEFB	00010100B		; 20
//
//; �p�^�[���R
//	DEFB	4			; �I���w��e�[�u�����p�^�[���S
//	DEFB	01100000B		; 0
//	DEFB	00110100B		; 1
//	DEFB	00000000B		; 2
//	DEFB	11100000B		; 3
//	DEFB	11100000B		; 4
//	DEFB	11000000B		; 5
//	DEFB	10010100B		; 6
//	DEFB	01100001B		; 7
//	DEFB	00110000B		; 8
//	DEFB	00000010B		; 9
//	DEFB	11101001B		; 10
//	DEFB	11100000B		; 11
//	DEFB	11011100B		; 12
//	DEFB	11010000B		; 13
//	DEFB	11001100B		; 14
//	DEFB	11101110B		; 15
//	DEFB	11000000B		; 16
//	DEFB	11100100B		; 17
//	DEFB	01011100B		; 18
//	DEFB	01001000B		; 19
//	DEFB	00011100B		; 20
//
//	PAGE
//; �p�^�[���S
//	DEFB	5			; �I���w��e�[�u�����p�^�[���T
//	DEFB	01100000B		; 0
//	DEFB	00101010B		; 1
//	DEFB	00000000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11011000B		; 4
//	DEFB	11011100B		; 5
//	DEFB	11001000B		; 6
//	DEFB	11001100B		; 7
//	DEFB	11010000B		; 8
//	DEFB	11001100B		; 9
//	DEFB	11001000B		; 10
//	DEFB	11101000B		; 11
//	DEFB	11100000B		; 12
//	DEFB	11011100B		; 13
//	DEFB	11010000B		; 14
//	DEFB	11010100B		; 15
//	DEFB	11001000B		; 16
//	DEFB	11100100B		; 17
//	DEFB	11101100B		; 18
//	DEFB	11000000B		; 19
//	DEFB	10001100B		; 20
//
//; �p�^�[���T
//	DEFB	6			; �I���w��e�[�u�����p�^�[���U
//	DEFB	00011000B		; 0
//	DEFB	11010110B		; 1
//	DEFB	11010000B		; 2
//	DEFB	10100000B		; 3
//	DEFB	11001101B		; 4
//	DEFB	01010100B		; 5
//	DEFB	00101110B		; 6
//	DEFB	00000100B		; 7
//	DEFB	11011000B		; 8
//	DEFB	01110110B		; 9
//	DEFB	01001101B		; 10
//	DEFB	00011000B		; 11
//	DEFB	11011110B		; 12
//	DEFB	10000000B		; 13
//	DEFB	01110000B		; 14
//	DEFB	01001100B		; 15
//	DEFB	11011000B		; 16
//	DEFB	10101110B		; 17
//	DEFB	11001101B		; 18
//	DEFB	01010000B		; 19
//	DEFB	00101110B		; 20
//
//; �p�^�[���U
//	DEFB	7			; �I���w��e�[�u�����p�^�[���V
//	DEFB	11011000B		; 0
//	DEFB	11101100B		; 1
//	DEFB	11101000B		; 2
//	DEFB	10110000B		; 3
//	DEFB	10001000B		; 4
//	DEFB	11001000B		; 5
//	DEFB	00101100B		; 6
//	DEFB	00010000B		; 7
//	DEFB	11011000B		; 8
//	DEFB	11001100B		; 9
//	DEFB	11001000B		; 10
//	DEFB	11100000B		; 11
//	DEFB	11101000B		; 12
//	DEFB	11100000B		; 13
//	DEFB	11011100B		; 14
//	DEFB	11010000B		; 15
//	DEFB	11001000B		; 16
//	DEFB	11010100B		; 17
//	DEFB	11101000B		; 18
//	DEFB	11101000B		; 19
//	DEFB	11100100B		; 20
//
//	PAGE
//; �p�^�[���V
//	DEFB	8			; �I���w��e�[�u�����p�^�[���W
//	DEFB	11010000B		; 0
//	DEFB	11101010B		; 1
//	DEFB	11101000B		; 2
//	DEFB	10110000B		; 3
//	DEFB	11011000B		; 4
//	DEFB	11001100B		; 5
//	DEFB	00101100B		; 6
//	DEFB	00010001B		; 7
//	DEFB	11011000B		; 8
//	DEFB	01010001B		; 9
//	DEFB	00101000B		; 10
//	DEFB	00100010B		; 11
//	DEFB	11100000B		; 12
//	DEFB	11011100B		; 13
//	DEFB	11010000B		; 14
//	DEFB	11001100B		; 15
//	DEFB	11100000B		; 16
//	DEFB	11010000B		; 17
//	DEFB	11001000B		; 18
//	DEFB	11100000B		; 19
//	DEFB	11011100B		; 20
//
//; �p�^�[���W
//	DEFB	9			; �I���w��e�[�u�����p�^�[���X
//	DEFB	00010000B		; 0
//	DEFB	11010100B		; 1
//	DEFB	11001000B		; 2
//	DEFB	11011000B		; 3
//	DEFB	11011000B		; 4
//	DEFB	11001000B		; 5
//	DEFB	11101100B		; 6
//	DEFB	11100000B		; 7
//	DEFB	11011000B		; 8
//	DEFB	11010010B		; 9
//	DEFB	11001100B		; 10
//	DEFB	11101000B		; 11
//	DEFB	11000010B		; 12
//	DEFB	10010000B		; 13
//	DEFB	01100100B		; 14
//	DEFB	00110010B		; 15
//	DEFB	11001000B		; 16
//	DEFB	10101000B		; 17
//	DEFB	11001100B		; 18
//	DEFB	01110000B		; 19
//	DEFB	01000010B		; 20
//
//; �p�^�[���X
//	DEFB	10			; �I���w��e�[�u�����p�^�[���P�O
//	DEFB	01000100B		; 0
//	DEFB	00010000B		; 1
//	DEFB	11101000B		; 2
//	DEFB	11100000B		; 3
//	DEFB	10110000B		; 4
//	DEFB	10000100B		; 5
//	DEFB	01010000B		; 6
//	DEFB	01000000B		; 7
//	DEFB	00010100B		; 8
//	DEFB	11010000B		; 9
//	DEFB	11001000B		; 10
//	DEFB	11100100B		; 11
//	DEFB	11011000B		; 12
//	DEFB	11011100B		; 13
//	DEFB	11001000B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11100100B		; 16
//	DEFB	11011000B		; 17
//	DEFB	11010000B		; 18
//	DEFB	01111100B		; 19
//	DEFB	01100000B		; 20
//
//	PAGE
//; �p�^�[���P�O
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	00111100B		; 0
//	DEFB	00010000B		; 1
//	DEFB	11101000B		; 2
//	DEFB	11100000B		; 3
//	DEFB	10110000B		; 4
//	DEFB	10000010B		; 5
//	DEFB	01010100B		; 6
//	DEFB	01000000B		; 7
//	DEFB	00010100B		; 8
//	DEFB	11010000B		; 9
//	DEFB	11001000B		; 10
//	DEFB	11100010B		; 11
//	DEFB	11101000B		; 12
//	DEFB	11100000B		; 13
//	DEFB	11011100B		; 14
//	DEFB	11010000B		; 15
//	DEFB	11001100B		; 16
//	DEFB	11011000B		; 17
//	DEFB	11010000B		; 18
//	DEFB	11001100B		; 19
//	DEFB	01110000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�𕨘A���쓮�������u�������V�Z����			*
//;	*	(��ذ�-�-)���I��					*
//;	*****************************************************************
//;
//TBL_STOP_CTL2:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	11100100B		; 0
//	DEFB	11010000B		; 1
//	DEFB	11010000B		; 2
//	DEFB	11001001B		; 3
//	DEFB	11011000B		; 4
//	DEFB	11010010B		; 5
//	DEFB	11001100B		; 6
//	DEFB	11010000B		; 7
//	DEFB	10110110B		; 8
//	DEFB	10000000B		; 9
//	DEFB	01110000B		; 10
//	DEFB	01001001B		; 11
//	DEFB	00011000B		; 12
//	DEFB	11100000B		; 13
//	DEFB	11011010B		; 14
//	DEFB	11000000B		; 15
//	DEFB	10010100B		; 16
//	DEFB	01100000B		; 17
//	DEFB	00110000B		; 18
//	DEFB	00000100B		; 19
//	DEFB	11001000B		; 20
//
//; �p�^�[���Q
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	11011000B		; 0
//	DEFB	11010101B		; 1
//	DEFB	11001000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11001110B		; 4
//	DEFB	11001100B		; 5
//	DEFB	11001100B		; 6
//	DEFB	11001100B		; 7
//	DEFB	11100000B		; 8
//	DEFB	10100100B		; 9
//	DEFB	01111000B		; 10
//	DEFB	01101000B		; 11
//	DEFB	01000000B		; 12
//	DEFB	00011000B		; 13
//	DEFB	11000001B		; 14
//	DEFB	10011010B		; 15
//	DEFB	01101000B		; 16
//	DEFB	00111101B		; 17
//	DEFB	00000100B		; 18
//	DEFB	11001000B		; 19
//	DEFB	11001100B		; 20
//
//; �p�^�[���R
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	01011000B		; 0
//	DEFB	01001100B		; 1
//	DEFB	00100000B		; 2
//	DEFB	10111000B		; 3
//	DEFB	10001000B		; 4
//	DEFB	01011000B		; 5
//	DEFB	00101100B		; 6
//	DEFB	00000100B		; 7
//	DEFB	11010000B		; 8
//	DEFB	11001100B		; 9
//	DEFB	11001001B		; 10
//	DEFB	11101000B		; 11
//	DEFB	11100000B		; 12
//	DEFB	11011110B		; 13
//	DEFB	11010000B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11100000B		; 16
//	DEFB	11011100B		; 17
//	DEFB	11101000B		; 18
//	DEFB	11100000B		; 19
//	DEFB	10001100B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�𕨘A���쓮�������u�������V�Z����			*
//;	*	(�R��R��R)���I��					*
//;	*****************************************************************
//;
//TBL_STOP_CTL3:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	01000100B		; 0
//	DEFB	00010000B		; 1
//	DEFB	11101000B		; 2
//	DEFB	11100000B		; 3
//	DEFB	10110000B		; 4
//	DEFB	10000100B		; 5
//	DEFB	01010010B		; 6
//	DEFB	01000000B		; 7
//	DEFB	00010100B		; 8
//	DEFB	11101010B		; 9
//	DEFB	11101000B		; 10
//	DEFB	11100100B		; 11
//	DEFB	11011010B		; 12
//	DEFB	11010000B		; 13
//	DEFB	11001000B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11100100B		; 16
//	DEFB	11011010B		; 17
//	DEFB	10101000B		; 18
//	DEFB	01111100B		; 19
//	DEFB	01110010B		; 20
//
//; �p�^�[���Q
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	11011000B		; 0
//	DEFB	11101100B		; 1
//	DEFB	11101000B		; 2
//	DEFB	10111000B		; 3
//	DEFB	10001000B		; 4
//	DEFB	01011000B		; 5
//	DEFB	00101100B		; 6
//	DEFB	00011100B		; 7
//	DEFB	10001000B		; 8
//	DEFB	01011000B		; 9
//	DEFB	01001010B		; 10
//	DEFB	00011000B		; 11
//	DEFB	11011000B		; 12
//	DEFB	11010000B		; 13
//	DEFB	11001100B		; 14
//	DEFB	11001100B		; 15
//	DEFB	11001000B		; 16
//	DEFB	11011100B		; 17
//	DEFB	11001100B		; 18
//	DEFB	11001000B		; 19
//	DEFB	11100100B		; 20
//
//; �p�^�[���R
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	01100000B		; 0
//	DEFB	00110010B		; 1
//	DEFB	00000000B		; 2
//	DEFB	11100000B		; 3
//	DEFB	11011000B		; 4
//	DEFB	11010100B		; 5
//	DEFB	11001000B		; 6
//	DEFB	11001100B		; 7
//	DEFB	11010000B		; 8
//	DEFB	11101000B		; 9
//	DEFB	11101100B		; 10
//	DEFB	11011000B		; 11
//	DEFB	10001100B		; 12
//	DEFB	01010000B		; 13
//	DEFB	00101000B		; 14
//	DEFB	00000100B		; 15
//	DEFB	10111000B		; 16
//	DEFB	10001100B		; 17
//	DEFB	11010110B		; 18
//	DEFB	10100000B		; 19
//	DEFB	01111100B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�������V�Z����(���Â�����Â�����Â�)���I��		*
//;	*****************************************************************
//;
//TBL_STOP_CTL4:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	00001110B		; 0
//	DEFB	01111000B		; 1
//	DEFB	01110000B		; 2
//	DEFB	01000000B		; 3
//	DEFB	00010000B		; 4
//	DEFB	00001100B		; 5
//	DEFB	11101000B		; 6
//	DEFB	01101000B		; 7
//	DEFB	00111000B		; 8
//	DEFB	00001000B		; 9
//	DEFB	00000000B		; 10
//	DEFB	10100000B		; 11
//	DEFB	10001000B		; 12
//	DEFB	01011100B		; 13
//	DEFB	00101000B		; 14
//	DEFB	00100000B		; 15
//	DEFB	00011000B		; 16
//	DEFB	10001000B		; 17
//	DEFB	01110000B		; 18
//	DEFB	01000000B		; 19
//	DEFB	00010100B		; 20
//
//; �p�^�[���Q
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	00001100B		; 0
//	DEFB	01010000B		; 1
//	DEFB	00111000B		; 2
//	DEFB	00001000B		; 3
//	DEFB	00101000B		; 4
//	DEFB	00001100B		; 5
//	DEFB	01101000B		; 6
//	DEFB	00111000B		; 7
//	DEFB	00001000B		; 8
//	DEFB	00101000B		; 9
//	DEFB	00000000B		; 10
//	DEFB	11001000B		; 11
//	DEFB	10100000B		; 12
//	DEFB	10000100B		; 13
//	DEFB	01010000B		; 14
//	DEFB	00111000B		; 15
//	DEFB	00001000B		; 16
//	DEFB	10100000B		; 17
//	DEFB	10000000B		; 18
//	DEFB	01010000B		; 19
//	DEFB	00101010B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�������V�Z����(��ޥ��ޥ���)���I��			*
//;	*****************************************************************
//;
//TBL_STOP_CTL5:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	00011000B		; 0
//	DEFB	11011000B		; 1
//	DEFB	10000000B		; 2
//	DEFB	01010000B		; 3
//	DEFB	00000000B		; 4
//	DEFB	00001000B		; 5
//	DEFB	10100100B		; 6
//	DEFB	01111000B		; 7
//	DEFB	01101000B		; 8
//	DEFB	00010000B		; 9
//	DEFB	00010000B		; 10
//	DEFB	11001000B		; 11
//	DEFB	11000000B		; 12
//	DEFB	10010000B		; 13
//	DEFB	00111100B		; 14
//	DEFB	00110000B		; 15
//	DEFB	10100000B		; 16
//	DEFB	10110000B		; 17
//	DEFB	10001000B		; 18
//	DEFB	01010000B		; 19
//	DEFB	00000000B		; 20
//
//; �p�^�[���Q
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	00101000B		; 0
//	DEFB	00011100B		; 1
//	DEFB	10010000B		; 2
//	DEFB	10011000B		; 3
//	DEFB	01101000B		; 4
//	DEFB	00111000B		; 5
//	DEFB	00001100B		; 6
//	DEFB	10100000B		; 7
//	DEFB	01111000B		; 8
//	DEFB	01101000B		; 9
//	DEFB	00111000B		; 10
//	DEFB	00001000B		; 11
//	DEFB	10100000B		; 12
//	DEFB	01111000B		; 13
//	DEFB	01101100B		; 14
//	DEFB	01000000B		; 15
//	DEFB	00100000B		; 16
//	DEFB	11100000B		; 17
//	DEFB	10110000B		; 18
//	DEFB	10000000B		; 19
//	DEFB	01010000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�𕨘A���쓮�������u���쓮���̖𕨘A���쓮���u���I��	*
//;	*	�y�і𕨘A���쓮���u�������V�Z���̂͂��ꎞ		*
//;	*****************************************************************
//;
//TBL_STOP_CTL6:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	11101000B		; 0
//	DEFB	11100100B		; 1
//	DEFB	11010000B		; 2
//	DEFB	11010000B		; 3
//	DEFB	11001110B		; 4
//	DEFB	11010000B		; 5
//	DEFB	11010000B		; 6
//	DEFB	11011100B		; 7
//	DEFB	11010000B		; 8
//	DEFB	11001100B		; 9
//	DEFB	11101000B		; 10
//	DEFB	11000000B		; 11
//	DEFB	10010110B		; 12
//	DEFB	01100000B		; 13
//	DEFB	00110000B		; 14
//	DEFB	00000100B		; 15
//	DEFB	11100000B		; 16
//	DEFB	11100100B		; 17
//	DEFB	11010110B		; 18
//	DEFB	11010000B		; 19
//	DEFB	11101000B		; 20
//
//; �p�^�[���Q
//	DEFB	4			; �I���w��e�[�u�����p�^�[���S
//	DEFB	11011000B		; 0
//	DEFB	11010100B		; 1
//	DEFB	11010000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11001100B		; 4
//	DEFB	11001000B		; 5
//	DEFB	11001000B		; 6
//	DEFB	11001100B		; 7
//	DEFB	11011000B		; 8
//	DEFB	11010110B		; 9
//	DEFB	11001100B		; 10
//	DEFB	11100000B		; 11
//	DEFB	11011110B		; 12
//	DEFB	01111000B		; 13
//	DEFB	01010000B		; 14
//	DEFB	00101100B		; 15
//	DEFB	00010000B		; 16
//	DEFB	11011110B		; 17
//	DEFB	11011000B		; 18
//	DEFB	11101000B		; 19
//	DEFB	11101000B		; 20
//
//; �p�^�[���R
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	00010000B		; 0
//	DEFB	10101000B		; 1
//	DEFB	01111100B		; 2
//	DEFB	01100000B		; 3
//	DEFB	00110000B		; 4
//	DEFB	00000000B		; 5
//	DEFB	11000100B		; 6
//	DEFB	10010000B		; 7
//	DEFB	01100000B		; 8
//	DEFB	00110000B		; 9
//	DEFB	00000100B		; 10
//	DEFB	11100000B		; 11
//	DEFB	11101000B		; 12
//	DEFB	11100000B		; 13
//	DEFB	11011100B		; 14
//	DEFB	11010000B		; 15
//	DEFB	11001000B		; 16
//	DEFB	10101000B		; 17
//	DEFB	01111100B		; 18
//	DEFB	01110000B		; 19
//	DEFB	01000000B		; 20
//
//	PAGE
//; �p�^�[���S
//	DEFB	5			; �I���w��e�[�u�����p�^�[���T
//	DEFB	10101000B		; 0
//	DEFB	01111100B		; 1
//	DEFB	01010000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	01010010B		; 4
//	DEFB	00101100B		; 5
//	DEFB	00000100B		; 6
//	DEFB	11011000B		; 7
//	DEFB	11010000B		; 8
//	DEFB	11001001B		; 9
//	DEFB	11001000B		; 10
//	DEFB	11101000B		; 11
//	DEFB	11100010B		; 12
//	DEFB	11001100B		; 13
//	DEFB	11010100B		; 14
//	DEFB	11001110B		; 15
//	DEFB	11001000B		; 16
//	DEFB	11011100B		; 17
//	DEFB	11001110B		; 18
//	DEFB	11001000B		; 19
//	DEFB	11011100B		; 20
//
//; �p�^�[���T
//	DEFB	6			; �I���w��e�[�u�����p�^�[���U
//	DEFB	10001000B		; 0
//	DEFB	01010000B		; 1
//	DEFB	00101000B		; 2
//	DEFB	00000000B		; 3
//	DEFB	11011010B		; 4
//	DEFB	11011000B		; 5
//	DEFB	11101100B		; 6
//	DEFB	11011100B		; 7
//	DEFB	11011000B		; 8
//	DEFB	11001000B		; 9
//	DEFB	11001010B		; 10
//	DEFB	11101000B		; 11
//	DEFB	11101000B		; 12
//	DEFB	11011000B		; 13
//	DEFB	11011100B		; 14
//	DEFB	11001100B		; 15
//	DEFB	11001000B		; 16
//	DEFB	11011100B		; 17
//	DEFB	11010100B		; 18
//	DEFB	11001000B		; 19
//	DEFB	10110100B		; 20
//
//; �p�^�[���U
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	01100000B		; 0
//	DEFB	00110100B		; 1
//	DEFB	00000000B		; 2
//	DEFB	11010000B		; 3
//	DEFB	11001000B		; 4
//	DEFB	10110010B		; 5
//	DEFB	10000100B		; 6
//	DEFB	01010000B		; 7
//	DEFB	00110000B		; 8
//	DEFB	00000100B		; 9
//	DEFB	11101010B		; 10
//	DEFB	11101000B		; 11
//	DEFB	11100100B		; 12
//	DEFB	11011000B		; 13
//	DEFB	11010000B		; 14
//	DEFB	11001110B		; 15
//	DEFB	11101000B		; 16
//	DEFB	11100100B		; 17
//	DEFB	11011000B		; 18
//	DEFB	10101000B		; 19
//	DEFB	01111000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�𕨘A���쓮���u�������V�Z����(��ذ��|��|)���I��	*
//;	*****************************************************************
//;
//TBL_STOP_CTL7:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	11100110B		; 0
//	DEFB	11011000B		; 1
//	DEFB	11010000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11011000B		; 4
//	DEFB	11010100B		; 5
//	DEFB	11001100B		; 6
//	DEFB	11101000B		; 7
//	DEFB	10111100B		; 8
//	DEFB	11011000B		; 9
//	DEFB	11000000B		; 10
//	DEFB	10011000B		; 11
//	DEFB	01101000B		; 12
//	DEFB	00111100B		; 13
//	DEFB	10000000B		; 14
//	DEFB	01010000B		; 15
//	DEFB	01000100B		; 16
//	DEFB	00010000B		; 17
//	DEFB	11101000B		; 18
//	DEFB	00011100B		; 19
//	DEFB	11101000B		; 20
//
//; �p�^�[���Q
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	11100000B		; 0
//	DEFB	11011110B		; 1
//	DEFB	11001000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11001100B		; 4
//	DEFB	11010100B		; 5
//	DEFB	11001100B		; 6
//	DEFB	11011100B		; 7
//	DEFB	11001000B		; 8
//	DEFB	10111000B		; 9
//	DEFB	10010001B		; 10
//	DEFB	01110000B		; 11
//	DEFB	01000000B		; 12
//	DEFB	00010010B		; 13
//	DEFB	10101000B		; 14
//	DEFB	10011100B		; 15
//	DEFB	01101000B		; 16
//	DEFB	00111100B		; 17
//	DEFB	00100100B		; 18
//	DEFB	11100000B		; 19
//	DEFB	11101101B		; 20
//
//; �p�^�[���R
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	10001000B		; 0
//	DEFB	01011100B		; 1
//	DEFB	00101000B		; 2
//	DEFB	00000000B		; 3
//	DEFB	01111000B		; 4
//	DEFB	01010000B		; 5
//	DEFB	00110100B		; 6
//	DEFB	00010010B		; 7
//	DEFB	11011000B		; 8
//	DEFB	11101100B		; 9
//	DEFB	11101010B		; 10
//	DEFB	11100000B		; 11
//	DEFB	11011000B		; 12
//	DEFB	11011000B		; 13
//	DEFB	11011100B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11001000B		; 16
//	DEFB	11011100B		; 17
//	DEFB	11101000B		; 18
//	DEFB	11100000B		; 19
//	DEFB	10110100B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�𕨘A���쓮���u�������V�Z����(�R��R��R)���I��		*
//;	*****************************************************************
//;
//TBL_STOP_CTL8:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	11011000B		; 0
//	DEFB	11010101B		; 1
//	DEFB	11001000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11011010B		; 4
//	DEFB	11010000B		; 5
//	DEFB	11001100B		; 6
//	DEFB	10111100B		; 7
//	DEFB	10001000B		; 8
//	DEFB	01011110B		; 9
//	DEFB	00101100B		; 10
//	DEFB	00011000B		; 11
//	DEFB	11000010B		; 12
//	DEFB	10010000B		; 13
//	DEFB	01100100B		; 14
//	DEFB	00110000B		; 15
//	DEFB	00000000B		; 16
//	DEFB	10110100B		; 17
//	DEFB	11010000B		; 18
//	DEFB	11101000B		; 19
//	DEFB	11100100B		; 20
//
//; �p�^�[���Q
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	10010100B		; 0
//	DEFB	01100000B		; 1
//	DEFB	00110000B		; 2
//	DEFB	00000000B		; 3
//	DEFB	01100001B		; 4
//	DEFB	00110100B		; 5
//	DEFB	00000110B		; 6
//	DEFB	11100000B		; 7
//	DEFB	11011101B		; 8
//	DEFB	11101000B		; 9
//	DEFB	11101000B		; 10
//	DEFB	11100100B		; 11
//	DEFB	11011000B		; 12
//	DEFB	11010000B		; 13
//	DEFB	11001000B		; 14
//	DEFB	11001010B		; 15
//	DEFB	11100100B		; 16
//	DEFB	11011000B		; 17
//	DEFB	10101000B		; 18
//	DEFB	01111100B		; 19
//	DEFB	11000010B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	��ʗV�Z����(��ذ��|��|)���I��				*
//;	*****************************************************************
//;
//TBL_STOP_CTL9:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	11100000B		; 0
//	DEFB	11011100B		; 1
//	DEFB	11010000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11011110B		; 4
//	DEFB	11010000B		; 5
//	DEFB	11001000B		; 6
//	DEFB	11001100B		; 7
//	DEFB	10100000B		; 8
//	DEFB	10001000B		; 9
//	DEFB	01011100B		; 10
//	DEFB	00101000B		; 11
//	DEFB	00001110B		; 12
//	DEFB	01000000B		; 13
//	DEFB	00010000B		; 14
//	DEFB	11000101B		; 15
//	DEFB	10010000B		; 16
//	DEFB	00010000B		; 17
//	DEFB	00110100B		; 18
//	DEFB	00000000B		; 19
//	DEFB	11100110B		; 20
//
//; �p�^�[���Q
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	11100100B		; 0
//	DEFB	11011000B		; 1
//	DEFB	11001100B		; 2
//	DEFB	11001100B		; 3
//	DEFB	11001000B		; 4
//	DEFB	11001000B		; 5
//	DEFB	11010000B		; 6
//	DEFB	11001000B		; 7
//	DEFB	11001100B		; 8
//	DEFB	10111000B		; 9
//	DEFB	10010000B		; 10
//	DEFB	11100100B		; 11
//	DEFB	11101000B		; 12
//	DEFB	11100100B		; 13
//	DEFB	11101000B		; 14
//	DEFB	11101000B		; 15
//	DEFB	11100100B		; 16
//	DEFB	00111000B		; 17
//	DEFB	00001000B		; 18
//	DEFB	11001100B		; 19
//	DEFB	11001000B		; 20
//
//; �p�^�[���R
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	01111010B		; 0
//	DEFB	01010000B		; 1
//	DEFB	01000000B		; 2
//	DEFB	10110100B		; 3
//	DEFB	10000010B		; 4
//	DEFB	01010000B		; 5
//	DEFB	00101000B		; 6
//	DEFB	10101000B		; 7
//	DEFB	11001100B		; 8
//	DEFB	11011010B		; 9
//	DEFB	11101000B		; 10
//	DEFB	11101100B		; 11
//	DEFB	11011010B		; 12
//	DEFB	11011000B		; 13
//	DEFB	11001000B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11100100B		; 16
//	DEFB	11011010B		; 17
//	DEFB	11010000B		; 18
//	DEFB	11001100B		; 19
//	DEFB	10110000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	��ʗV�Z����(�R��R��R)���I��				*
//;	*****************************************************************
//;
//TBL_STOP_CTL10:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	00101100B		; 0
//	DEFB	00000000B		; 1
//	DEFB	10001100B		; 2
//	DEFB	01011110B		; 3
//	DEFB	00101001B		; 4
//	DEFB	00010000B		; 5
//	DEFB	11010000B		; 6
//	DEFB	11001000B		; 7
//	DEFB	11010100B		; 8
//	DEFB	00101010B		; 9
//	DEFB	00100000B		; 10
//	DEFB	11100100B		; 11
//	DEFB	10110010B		; 12
//	DEFB	01111000B		; 13
//	DEFB	01010000B		; 14
//	DEFB	00111010B		; 15
//	DEFB	00001100B		; 16
//	DEFB	10100000B		; 17
//	DEFB	10110010B		; 18
//	DEFB	10000100B		; 19
//	DEFB	01010001B		; 20
//
//; �p�^�[���Q
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	10010010B		; 0
//	DEFB	10001100B		; 1
//	DEFB	01001100B		; 2
//	DEFB	10010100B		; 3
//	DEFB	10110001B		; 4
//	DEFB	10000000B		; 5
//	DEFB	01010000B		; 6
//	DEFB	00110110B		; 7
//	DEFB	00000000B		; 8
//	DEFB	11101100B		; 9
//	DEFB	11101100B		; 10
//	DEFB	11100010B		; 11
//	DEFB	11011101B		; 12
//	DEFB	11010000B		; 13
//	DEFB	11001000B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11001010B		; 16
//	DEFB	11011100B		; 17
//	DEFB	11010000B		; 18
//	DEFB	11001000B		; 19
//	DEFB	11101000B		; 20
//
//; �p�^�[���R
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	01110000B		; 0
//	DEFB	00101010B		; 1
//	DEFB	00000000B		; 2
//	DEFB	10100100B		; 3
//	DEFB	10001010B		; 4
//	DEFB	01011000B		; 5
//	DEFB	11001000B		; 6
//	DEFB	11001000B		; 7
//	DEFB	11100100B		; 8
//	DEFB	01110010B		; 9
//	DEFB	01001000B		; 10
//	DEFB	00011100B		; 11
//	DEFB	11011000B		; 12
//	DEFB	11010010B		; 13
//	DEFB	11001000B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11001100B		; 16
//	DEFB	11001010B		; 17
//	DEFB	11010000B		; 18
//	DEFB	10100100B		; 19
//	DEFB	01111000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	��ʗV�Z����(���Â�����Â�����Â�)���I��		*
//;	*****************************************************************
//;
//TBL_STOP_CTL11:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	10100000B		; 0
//	DEFB	10011100B		; 1
//	DEFB	01101000B		; 2
//	DEFB	00111000B		; 3
//	DEFB	00001100B		; 4
//	DEFB	10100000B		; 5
//	DEFB	10001000B		; 6
//	DEFB	01011000B		; 7
//	DEFB	00101000B		; 8
//	DEFB	00100100B		; 9
//	DEFB	11100000B		; 10
//	DEFB	10110000B		; 11
//	DEFB	10000100B		; 12
//	DEFB	01010000B		; 13
//	DEFB	01001000B		; 14
//	DEFB	00011000B		; 15
//	DEFB	10110000B		; 16
//	DEFB	10000100B		; 17
//	DEFB	01010000B		; 18
//	DEFB	00111000B		; 19
//	DEFB	00001000B		; 20
//
//; �p�^�[���Q
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	00000000B		; 0
//	DEFB	01110000B		; 1
//	DEFB	01000110B		; 2
//	DEFB	00010101B		; 3
//	DEFB	00110000B		; 4
//	DEFB	00000100B		; 5
//	DEFB	01110000B		; 6
//	DEFB	01000000B		; 7
//	DEFB	00010100B		; 8
//	DEFB	00110000B		; 9
//	DEFB	00000100B		; 10
//	DEFB	11011100B		; 11
//	DEFB	10101000B		; 12
//	DEFB	01111100B		; 13
//	DEFB	01110000B		; 14
//	DEFB	01000000B		; 15
//	DEFB	00010100B		; 16
//	DEFB	10101000B		; 17
//	DEFB	01111110B		; 18
//	DEFB	01100101B		; 19
//	DEFB	00110000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	��ʗV�Z����(��ޥ��ޥ���)���I��				*
//;	*****************************************************************
//;
//TBL_STOP_CTL12:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	10111000B		; 0
//	DEFB	10010100B		; 1
//	DEFB	01100000B		; 2
//	DEFB	00110000B		; 3
//	DEFB	00010000B		; 4
//	DEFB	10110000B		; 5
//	DEFB	01111100B		; 6
//	DEFB	01010000B		; 7
//	DEFB	01000100B		; 8
//	DEFB	00010000B		; 9
//	DEFB	11011000B		; 10
//	DEFB	10100000B		; 11
//	DEFB	01111000B		; 12
//	DEFB	01110000B		; 13
//	DEFB	01000000B		; 14
//	DEFB	00100000B		; 15
//	DEFB	11000000B		; 16
//	DEFB	10001100B		; 17
//	DEFB	01100000B		; 18
//	DEFB	00101000B		; 19
//	DEFB	00000000B		; 20
//
//; �p�^�[���Q
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	00101000B		; 0
//	DEFB	00100000B		; 1
//	DEFB	10110000B		; 2
//	DEFB	10001000B		; 3
//	DEFB	01010000B		; 4
//	DEFB	00101000B		; 5
//	DEFB	00010100B		; 6
//	DEFB	10101000B		; 7
//	DEFB	01111000B		; 8
//	DEFB	01110000B		; 9
//	DEFB	01000000B		; 10
//	DEFB	00010000B		; 11
//	DEFB	11010000B		; 12
//	DEFB	11101000B		; 13
//	DEFB	11101100B		; 14
//	DEFB	11100000B		; 15
//	DEFB	11011000B		; 16
//	DEFB	11010000B		; 17
//	DEFB	10100000B		; 18
//	DEFB	10001000B		; 19
//	DEFB	01011000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�͂��ꎞ�y�і𕨗V�Z����				*
//;	*	(��ޥ��ޥ���)�A(��ذ���ޥ���)���I��			*
//;	*****************************************************************
//;
//TBL_STOP_CTL13:
//
//; �p�^�[���P
//	DEFB	3			; �I���w��e�[�u�����p�^�[���R
//	DEFB	01110100B		; 0
//	DEFB	01000000B		; 1
//	DEFB	00010100B		; 2
//	DEFB	11010000B		; 3
//	DEFB	11001100B		; 4
//	DEFB	11100000B		; 5
//	DEFB	10001001B		; 6
//	DEFB	01011000B		; 7
//	DEFB	00101000B		; 8
//	DEFB	00001010B		; 9
//	DEFB	11001101B		; 10
//	DEFB	11001000B		; 11
//	DEFB	11001000B		; 12
//	DEFB	11101010B		; 13
//	DEFB	11100100B		; 14
//	DEFB	11011100B		; 15
//	DEFB	11010000B		; 16
//	DEFB	01111000B		; 17
//	DEFB	01101100B		; 18
//	DEFB	00111000B		; 19
//	DEFB	00001000B		; 20
//
//; �p�^�[���Q
//	DEFB	4			; �I���w��e�[�u�����p�^�[���S
//	DEFB	01100010B		; 0
//	DEFB	00101000B		; 1
//	DEFB	00001100B		; 2
//	DEFB	11001100B		; 3
//	DEFB	11010010B		; 4
//	DEFB	10101000B		; 5
//	DEFB	01111000B		; 6
//	DEFB	01010000B		; 7
//	DEFB	00110100B		; 8
//	DEFB	00000001B		; 9
//	DEFB	11001110B		; 10
//	DEFB	11001100B		; 11
//	DEFB	10010000B		; 12
//	DEFB	01101000B		; 13
//	DEFB	00111010B		; 14
//	DEFB	00011000B		; 15
//	DEFB	11000100B		; 16
//	DEFB	10001010B		; 17
//	DEFB	01011000B		; 18
//	DEFB	00101100B		; 19
//	DEFB	00000000B		; 20
//
//; �p�^�[���R
//	DEFB	5			; �I���w��e�[�u�����p�^�[���T
//	DEFB	11100000B		; 0
//	DEFB	11011100B		; 1
//	DEFB	11010010B		; 2
//	DEFB	11001000B		; 3
//	DEFB	11101000B		; 4
//	DEFB	11100000B		; 5
//	DEFB	11011100B		; 6
//	DEFB	01011001B		; 7
//	DEFB	00101010B		; 8
//	DEFB	00011100B		; 9
//	DEFB	11011000B		; 10
//	DEFB	10100010B		; 11
//	DEFB	01111100B		; 12
//	DEFB	01010100B		; 13
//	DEFB	01000100B		; 14
//	DEFB	00010000B		; 15
//	DEFB	11010010B		; 16
//	DEFB	11001100B		; 17
//	DEFB	01101000B		; 18
//	DEFB	00111001B		; 19
//	DEFB	00100000B		; 20
//
//	PAGE
//; �p�^�[���S
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	01101100B		; 0
//	DEFB	00110000B		; 1
//	DEFB	00000000B		; 2
//	DEFB	01010110B		; 3
//	DEFB	10001000B		; 4
//	DEFB	01011000B		; 5
//	DEFB	00101000B		; 6
//	DEFB	00000000B		; 7
//	DEFB	10000100B		; 8
//	DEFB	01010000B		; 9
//	DEFB	00111000B		; 10
//	DEFB	00100100B		; 11
//	DEFB	11001000B		; 12
//	DEFB	10001000B		; 13
//	DEFB	01100000B		; 14
//	DEFB	00101000B		; 15
//	DEFB	00000100B		; 16
//	DEFB	10110000B		; 17
//	DEFB	10000000B		; 18
//	DEFB	01010100B		; 19
//	DEFB	00101000B		; 20
//
//; �p�^�[���T
//	DEFB	6			; �I���w��e�[�u�����p�^�[���U
//	DEFB	00001000B		; 0
//	DEFB	11001100B		; 1
//	DEFB	11011000B		; 2
//	DEFB	11010000B		; 3
//	DEFB	11001100B		; 4
//	DEFB	01101000B		; 5
//	DEFB	01000000B		; 6
//	DEFB	00010000B		; 7
//	DEFB	11010010B		; 8
//	DEFB	01010100B		; 9
//	DEFB	11010000B		; 10
//	DEFB	11101010B		; 11
//	DEFB	11010100B		; 12
//	DEFB	11001000B		; 13
//	DEFB	01011000B		; 14
//	DEFB	00101100B		; 15
//	DEFB	00000010B		; 16
//	DEFB	11001100B		; 17
//	DEFB	11100000B		; 18
//	DEFB	01101000B		; 19
//	DEFB	00111000B		; 20
//
//; �p�^�[���U
//	DEFB	7			; �I���w��e�[�u�����p�^�[���V
//	DEFB	00000100B		; 0
//	DEFB	11101000B		; 1
//	DEFB	11100110B		; 2
//	DEFB	11011001B		; 3
//	DEFB	11010000B		; 4
//	DEFB	00000000B		; 5
//	DEFB	11011000B		; 6
//	DEFB	11010010B		; 7
//	DEFB	11001001B		; 8
//	DEFB	11100100B		; 9
//	DEFB	00010000B		; 10
//	DEFB	11010000B		; 11
//	DEFB	11001100B		; 12
//	DEFB	11101000B		; 13
//	DEFB	01101000B		; 14
//	DEFB	00111000B		; 15
//	DEFB	00010000B		; 16
//	DEFB	10101100B		; 17
//	DEFB	01111000B		; 18
//	DEFB	01100000B		; 19
//	DEFB	00110000B		; 20
//
//	PAGE
//; �p�^�[���V
//	DEFB	8			; �I���w��e�[�u�����p�^�[���W
//	DEFB	00111000B		; 0
//	DEFB	00001001B		; 1
//	DEFB	01010000B		; 2
//	DEFB	00001010B		; 3
//	DEFB	00000000B		; 4
//	DEFB	10001100B		; 5
//	DEFB	01011000B		; 6
//	DEFB	00101000B		; 7
//	DEFB	00100100B		; 8
//	DEFB	11100000B		; 9
//	DEFB	00010010B		; 10
//	DEFB	11010000B		; 11
//	DEFB	11101000B		; 12
//	DEFB	11100100B		; 13
//	DEFB	11011000B		; 14
//	DEFB	11010000B		; 15
//	DEFB	11001100B		; 16
//	DEFB	11001000B		; 17
//	DEFB	11011010B		; 18
//	DEFB	10011100B		; 19
//	DEFB	01101000B		; 20
//
//; �p�^�[���W
//	DEFB	9			; �I���w��e�[�u�����p�^�[���X
//	DEFB	01011100B		; 0
//	DEFB	00101000B		; 1
//	DEFB	00001010B		; 2
//	DEFB	11101010B		; 3
//	DEFB	11100000B		; 4
//	DEFB	00111000B		; 5
//	DEFB	00001100B		; 6
//	DEFB	11001000B		; 7
//	DEFB	11011010B		; 8
//	DEFB	11001000B		; 9
//	DEFB	11001100B		; 10
//	DEFB	11101000B		; 11
//	DEFB	11100000B		; 12
//	DEFB	11011000B		; 13
//	DEFB	11010100B		; 14
//	DEFB	11001000B		; 15
//	DEFB	11010100B		; 16
//	DEFB	11001000B		; 17
//	DEFB	11101000B		; 18
//	DEFB	10111000B		; 19
//	DEFB	10001000B		; 20
//
//; �p�^�[���X
//	DEFB	10			; �I���w��e�[�u�����p�^�[���P�O
//	DEFB	01000000B		; 0
//	DEFB	00010100B		; 1
//	DEFB	11010000B		; 2
//	DEFB	11001000B		; 3
//	DEFB	10101100B		; 4
//	DEFB	01111000B		; 5
//	DEFB	01101000B		; 6
//	DEFB	00111100B		; 7
//	DEFB	00001000B		; 8
//	DEFB	11001000B		; 9
//	DEFB	11010100B		; 10
//	DEFB	11001010B		; 11
//	DEFB	11100000B		; 12
//	DEFB	11011000B		; 13
//	DEFB	11010100B		; 14
//	DEFB	11101100B		; 15
//	DEFB	11100000B		; 16
//	DEFB	11011100B		; 17
//	DEFB	10101100B		; 18
//	DEFB	01111000B		; 19
//	DEFB	01100110B		; 20
//
//	PAGE
//; �p�^�[���P�O
//	DEFB	11			; �I���w��e�[�u�����p�^�[���P�P
//	DEFB	11011100B		; 0
//	DEFB	11011000B		; 1
//	DEFB	11101100B		; 2
//	DEFB	10111100B		; 3
//	DEFB	10001000B		; 4
//	DEFB	01011000B		; 5
//	DEFB	00101000B		; 6
//	DEFB	00011000B		; 7
//	DEFB	11010100B		; 8
//	DEFB	11001000B		; 9
//	DEFB	11001000B		; 10
//	DEFB	11001100B		; 11
//	DEFB	11001000B		; 12
//	DEFB	11101100B		; 13
//	DEFB	11101000B		; 14
//	DEFB	11100000B		; 15
//	DEFB	11011100B		; 16
//	DEFB	11010000B		; 17
//	DEFB	11001000B		; 18
//	DEFB	11001100B		; 19
//	DEFB	11100000B		; 20
//
//; �p�^�[���P�P
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	11001101B		; 0
//	DEFB	11101000B		; 1
//	DEFB	11100110B		; 2
//	DEFB	11011000B		; 3
//	DEFB	11010010B		; 4
//	DEFB	11001000B		; 5
//	DEFB	11011000B		; 6
//	DEFB	10101000B		; 7
//	DEFB	01111000B		; 8
//	DEFB	01010110B		; 9
//	DEFB	11001100B		; 10
//	DEFB	11001000B		; 11
//	DEFB	11001110B		; 12
//	DEFB	11101100B		; 13
//	DEFB	11100100B		; 14
//	DEFB	11011010B		; 15
//	DEFB	11010000B		; 16
//	DEFB	11001100B		; 17
//	DEFB	11100000B		; 18
//	DEFB	11011000B		; 19
//	DEFB	11010000B		; 20
//
//	PAGE
//;	*****************************************************************
//;	*	�𕨘A���쓮�������u�쓮���̈�ʗV�Z����		*
//;	*	(��ޥ��ޥ���)�A(���Â�����Â��BAR)���I��		*
//;	*****************************************************************
//;
//TBL_STOP_CTL14:
//
//; �p�^�[���P
//	DEFB	2			; �I���w��e�[�u�����p�^�[���Q
//	DEFB	00000000B		; 0
//	DEFB	10100100B		; 1
//	DEFB	10010000B		; 2
//	DEFB	01100000B		; 3
//	DEFB	00110000B		; 4
//	DEFB	00000000B		; 5
//	DEFB	10100100B		; 6
//	DEFB	10001000B		; 7
//	DEFB	01011000B		; 8
//	DEFB	00101000B		; 9
//	DEFB	00000000B		; 10
//	DEFB	11001000B		; 11
//	DEFB	10101000B		; 12
//	DEFB	01111000B		; 13
//	DEFB	01010000B		; 14
//	DEFB	01000100B		; 15
//	DEFB	00010000B		; 16
//	DEFB	10101100B		; 17
//	DEFB	01111000B		; 18
//	DEFB	01010000B		; 19
//	DEFB	00110100B		; 20
//
//; �p�^�[���Q
//	DEFB	1			; �I���w��e�[�u�����p�^�[���P
//	DEFB	11001100B		; 0
//	DEFB	11101000B		; 1
//	DEFB	11100000B		; 2
//	DEFB	11011000B		; 3
//	DEFB	11010000B		; 4
//	DEFB	11001000B		; 5
//	DEFB	11011100B		; 6
//	DEFB	11010000B		; 7
//	DEFB	11001000B		; 8
//	DEFB	11010000B		; 9
//	DEFB	11001000B		; 10
//	DEFB	10110000B		; 11
//	DEFB	11010000B		; 12
//	DEFB	11001000B		; 13
//	DEFB	11101000B		; 14
//	DEFB	11100000B		; 15
//	DEFB	11011100B		; 16
//	DEFB	11010000B		; 17
//	DEFB	11001000B		; 18
//	DEFB	11011000B		; 19
//	DEFB	11010000B		; 20
//
//	PAGE
//;	*************************************************
//;	*	���܏���		 		*
//;	*************************************************
//;
//TBL_WIN_CTL1:
//
//; �𕨘A���쓮�������u���쓮���̈�ʗV�Z
//
//; ����}����
//	DEFB	7
//
//; (��ذ�-�-)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@CHERRY			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	00000000B		; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	2			; ���o������
//	DEFB	10			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; (�R��R��R)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@FRUIT1			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	00000000B		; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	15			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; (���Â�����Â�����Â�)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@FRUIT2			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	00000000B		; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	8       		; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; �ėV�Z�쓮�}��(��ޥ��ޥ���)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@REPLAY			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	@_RP			; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	0			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//	PAGE
//; �𕨘A���쓮�������u�쓮�}��(���ݥ���ݥ����)
//	DEFB	LOW _WK_STOP_PIC2-1	; ��~�}���f�[�^
//	DEFB	@BB1			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC2	; �R��΂��}���f�[�^
//	DEFB	@_BB OR @_BB1		; ���܃t���O
//	DEFB	@SET_BBHIT1		; ���܎��̏o�͗v��
//	DEFB	15			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; �𕨘A���쓮�������u�쓮�}��(���̐_����̐_����̐_)
//	DEFB	LOW _WK_STOP_PIC2-1	; ��~�}���f�[�^
//	DEFB	@BB2			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC2	; �R��΂��}���f�[�^
//	DEFB	@_BB OR @_BB2		; ���܃t���O
//	DEFB	@SET_BBHIT2		; ���܎��̏o�͗v��
//	DEFB	15			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; �𕨘A���쓮���u�쓮�}��(BAR�BAR�BAR)
//	DEFB	LOW _WK_STOP_PIC2-1	; ��~�}���f�[�^
//	DEFB	@RB			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC2	; �R��΂��}���f�[�^
//	DEFB	@_RB			; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	15			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//	PAGE
//TBL_WIN_CTL2:
//
//; �𕨘A���쓮�������u�쓮���̈�ʗV�Z
//
//; ����}����
//	DEFB	4
//; (��ذ�-�-)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@CHERRY			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	00000000B		; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	7			; ���o������
//	DEFB	10			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; (�R��R��R)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@FRUIT1			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	00000000B		; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	15			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; (���Â�����Â�����Â�)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@FRUIT2			; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	00000000B		; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	8       		; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//; �𕨘A���쓮���u�쓮�}��(��ޥ��ޥ���)�A(���Â�����Â��BAR)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@REPLAY OR @SRB 		; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	@_RB			; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	2			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//TBL_WIN_CTL3:
//
//; �𕨗V�Z
//
//; ����}����
//	DEFB	1
//; (��ޥ��ޥ���)�A(��ذ���ޥ���)
//	DEFB	LOW _WK_STOP_PIC1-1	; ��~�}���f�[�^
//	DEFB	@REPLAY	OR @JAC		; �}���r�b�g
//	DEFB	LOW _FL_REJ_PIC1	; �R��΂��}���f�[�^
//	DEFB	00000000B		; ���܃t���O
//	DEFB	0			; ���܎��̏o�͗v��
//	DEFB	15			; ���o������
//	DEFB	0			; �o�b�N�����v���܃��C��
//					;;�\���T�[�`�|�C���^
//
//	PAGE
//;	*************************************************
//;	*    �L�����C�������v���܃��C���\��		*
//;	*************************************************
//;
//TBL_WIN_LINE:			; ���܃��C���\���p�^�[���o�̓r�b�g
//	DEFB	00100B		; ��P���C���^����
//	DEFB	01000B		; ��Q���C���^��i
//	DEFB	00010B		; ��R���C���^���i
//	DEFB	10000B		; ��S���C���^�E������
//	DEFB	00001B		; ��T���C���^�E�オ��
//
//;	*************************************************
//;	*    �o�b�N�����v���܃��C���\��			*
//;	*************************************************
//;
//TBL_WINBACK_LINE:			; ���܃��C���\���p�^�[���o�̓r�b�g
//;	�R�񓷊m�胉���v
//	DEFB	00000000B,10010010B	; ��P���C���^����
//	DEFB	10000000B,00100100B	; ��Q���C���^��i
//	DEFB	00000000B,01001001B	; ��R���C���^���i
//	DEFB	00000000B,01010100B	; ��S���C���^�E������
//	DEFB	10000000B,00010001B	; ��T���C���^�E�オ��
//
//;	�P�񓷊m�胉���v
//	DEFB	00000000B,00000010B	; ��P���C���^����
//	DEFB	00000000B,00000100B	; ��Q���C���^��i
//	DEFB	00000000B,00000001B	; ��R���C���^���i
//	DEFB	00000000B,00000100B	; ��S���C���^�E������
//	DEFB	00000000B,00000001B	; ��T���C���^�E�オ��
//
//	PAGE
//;	*************************************************
//;	*    	�V�Z�񐔕\���i�P�O�i�f�[�^�j		*
//;	*************************************************
//;
//TBL_BONUS_DSP:
//	DEFB	0F1H,0F2H,0F3H,0F4H,0F5H,0F6H,0F7H,0F8H,0F9H,10H
//	DEFB	11H,12H,13H,14H,15H,16H,17H,18H,19H,20H
//	DEFB	21H,22H,23H,24H,25H,26H,27H,28H,29H,30H
//oooooooooooooooooooooooooooooooooooooooooooooo
//;	****************************************************
//;	*  	���܊��Ҏ��̏o�͗v���}��	  	   *
//;	****************************************************
//;
//TBL_HIT_SET:
//;�������C��
//	DEFB	@SET_WBLSTART	; (���ݥ����)
//	DEFB	@SET_WBLSTART1	; (���̐_����̐_)
//	DEFB	@SET_WBLSTART	; (BAR�BAR)
//;��i���C��
//	DEFB	@SET_WBLSTART2	; (���ݥ����)
//	DEFB	@SET_WBLSTART3	; (���̐_����̐_)
//	DEFB	@SET_WBLSTART	; (BAR�BAR)
//;���i���C��
//	DEFB	@SET_WBLSTART	; (���ݥ����)
//	DEFB	@SET_WBLSTART	; (���̐_����̐_)
//	DEFB	@SET_WBLSTART4	; (BAR�BAR)
//;�E�����胉�C��
//	DEFB	@SET_WBLSTART	; (���ݥ����)
//	DEFB	@SET_WBLSTART	; (���̐_����̐_)
//	DEFB	@SET_WBLSTART	; (BAR�BAR)
//;�E�オ�胉�C��
//	DEFB	@SET_WBLSTART	; (���ݥ����)
//	DEFB	@SET_WBLSTART	; (���̐_����̐_)
//	DEFB	@SET_WBLSTART	; (BAR�BAR)
//
//;	*************************************************
//;	*    	�d�f���A���y�уG���[��������		*
//;	*    	�e�탉���v�E���ʉ��o�͗v��  �ԍ���`	*
//;	*************************************************
//;
//@ERREC_LP	EQU	0102H		; �V�Z���_�����o�G���[���A�m�F�p�̏o�͔ԍ�
//					; // = @SET_ALARM*100H OR @FLP_ALARM
//@ERREC_CT	EQU	5+1		; �V�Z���_�����o�G���[���A�m�F�p�̏o�͔ԍ�������
//
//@POWON_LP	EQU	0001H	    	; �d�f���A���̏o�͗v���ԍ�
//					; // = (@SET_ALARM-1)*100H OR (@FLP_ALARM-1)
//@POWON_CT	EQU	5+1		; �d�f���A���̏o�͗v���ԍ�������
//
//	PAGE
//
//;	*********************************************************
//;	*  	�e�탉���v�E���ʉ��o�͗v��  �ԍ���`		*
//;	*********************************************************
//;
//; �i�P�j�V�Z���_�����o�G���[�������̏o�͗v��
//@SET_ALARM	EQU	1
//
//; �i�Q�j(���ݥ���ݥ����)���܂ɂ��𕨘A���쓮�������u�쓮���̏o�͗v��
//;;      �i�𕨘A���쓮�������u�쓮���̈�ʗV�Z�񐔂��c��V��̗V�Z�I���܂Łj
//@SET_BB1	EQU	2
//
//; �i�R�j(���̐_����̐_����̐_)���܂ɂ��𕨘A���쓮�������u�쓮���̏o�͗v��
//;;      �i�𕨘A���쓮�������u�쓮���̈�ʗV�Z�񐔂��c��V��̗V�Z�I���܂Łj
//;@SET_BB2	EQU	3
//
//; �i�S�j�𕨘A���쓮�������u�쓮���̏o�͗v��
//;;      �i�𕨘A���쓮�������u�쓮���̈�ʗV�Z�񐔂��c��V��̗V�Z�I������
//;;       �𕨘A���쓮�������u�쓮�I�����܂Łj
//@SET_BB3	EQU	4
//
//; �i�T�j�𕨘A���쓮���u�쓮���̏o�͗v��
//@SET_RB		EQU	5
//
//; �i�U�j���܂ɂ��V�Z���_�����o���J�n���̏o�͗v��
//@SET_PAYSTART	EQU	6
//
//; �i�V�j�𕨘A���쓮�������u���܎��̏o�͗v���P(���ݥ���ݥ����)
//@SET_BBHIT1	EQU	7
//
//; �i�W�j�𕨘A���쓮�������u���܎��̏o�͗v���Q(���̐_����̐_����̐_)
//@SET_BBHIT2	EQU	8
//
//; �i�X�j�𕨘A���쓮�������u�쓮�I�����̏o�͗v��
//@SET_BBEND	EQU	9
//
//; �i�P�O�j�𕨘A���쓮���u�쓮�I�����̏o�͗v��
//@SET_RBEND	EQU	10
//
//; �i�P�P�j�ėV�Z�쓮���̏o�͗v��
//@SET_REPLAY	EQU	11
//
//; �i�P�Q�j���܊��Ҏ��̏o�͗v���P�i���܊��Ҏ��̏o�͗v���Q�`�T�ȊO�̎��j
//@SET_WBLSTART	EQU	12
//
//; �i�P�R�j���܊��Ҏ��̏o�͗v���Q
//;;�i�E�񓷉�]���̒������C��(���̐_����̐_)�\�����j
//@SET_WBLSTART1	EQU	13
//
//; �i�P�S�j���܊��Ҏ��̏o�͗v���R
//;;�i���񓷃`�F���[�ە\���y�щE�񓷉�]���̏�i���C��(���ݥ����)�\�����j
//@SET_WBLSTART2	EQU	14
//
//; �i�P�T�j���܊��Ҏ��̏o�͗v���S
//;;�i�E�񓷉�]���̏�i���C��(���̐_����̐_)�\�����j
//@SET_WBLSTART3	EQU	15
//
//; �i�P�U�j���܊��Ҏ��̏o�͗v���T
//;;�i���񓷃`�F���[�ە\���y�щE�񓷉�]���̉��i���C��(BAR�BAR)�\�����j
//@SET_WBLSTART4	EQU	16
//
//; �i�P�V�j���܊��ҏI�����̏o�͗v��
//@SET_WBLEND	EQU	17
//
//	PAGE
//; �i�P�W�j�V�Z���_���������̏o�͗v��
//@SET_INCO	EQU	18
//
//; �i�P�X�j�񓷉�]�s���̏o�͗v��
//@SET_WAIT	EQU	19
//
//; �i�Q�O�j�񓷉�]�J�n���̏o�͗v��
//@SET_START	EQU	20
//
//; �i�Q�P�j��~�{�^����t���̏o�͗v��
//@SET_STOP	EQU	21
//
//; �i�Q�Q�j�񓷒�~���̏o�͗v��
//@SET_R_STOP	EQU	22
//
//; �i�Q�R�j���܂ɂ��V�Z���_�����o���I�����̏o�͗v��
//@SET_PAYEND	EQU	23
//
//; �i�Q�S�j���܂ɂ��V�Z���_���P�����o�����̏o�͗v��
//@SET_PAY	EQU	24
//
//; �i�Q�T�j�V�Z���_�����o�G���[�������̏o�͗v��
//@SET_ACLEAR	EQU	25
//
//	PAGE
//;	********************************************
//;	*  	�e�탉���v�E���ʉ��o�͗v��  	   *
//;	********************************************
//;
//;	DEFB	�㕔�����v,	���ʃ����v,	�o�b�N�����v,	���ʉ�
//;
//TBL_LPSD_REQ:
//; �i�P�j�V�Z���_�����o�G���[�������̏o�͗v��
//	DEFB	@FLP_ALARM,	@ELP_ALARM,	0,		@SD_ALARM
//
//; �i�Q�j(���ݥ���ݥ����)���܂ɂ��𕨘A���쓮�������u�쓮���̏o�͗v��
//;;      �i�𕨘A���쓮�������u�쓮���̈�ʗV�Z�񐔂��c��V��̗V�Z�I���܂Łj
//	DEFB	@FLP_BB1,	@ELP_BB1,	0,		@SD_BB1
//
//; �i�R�j(���̐_����̐_����̐_)���܂ɂ��𕨘A���쓮�������u�쓮���̏o�͗v��
//;;      �i�𕨘A���쓮�������u�쓮���̈�ʗV�Z�񐔂��c��V��̗V�Z�I���܂Łj
//	DEFB	@FLP_BB2,	@ELP_BB2,	0,		@SD_BB2
//
//; �i�S�j�𕨘A���쓮�������u�쓮���̏o�͗v��
//;;      �i�𕨘A���쓮�������u�쓮���̈�ʗV�Z�񐔂��c��V��̗V�Z�I������
//;;       �𕨘A���쓮�������u�쓮���̍Ō�̗V�Z�܂Łj
//	DEFB	@FLP_BB3,	@ELP_BB3,	0,		@SD_BB3
//
//; �i�T�j�𕨘A���쓮���u�쓮���̏o�͗v��
//	DEFB	@FLP_RB,	@ELP_RB,	0,		@SD_RB
//
//; �i�U�j���܂ɂ��V�Z���_�����o���J�n���̏o�͗v��
//	DEFB	@FLP_PAY,	@ELP_PAY,	0,		0
//
//; �i�V�j�𕨘A���쓮�������u���܎��̏o�͗v���P(���ݥ���ݥ����)
//	DEFB	@FLP_BBHIT1,	@ELP_BBHIT1,	@BLP_BBHIT1,	@SD_BBHIT1
//
//; �i�W�j�𕨘A���쓮�������u���܎��̏o�͗v���Q(���̐_����̐_����̐_)
//	DEFB	@FLP_BBHIT2,	@ELP_BBHIT2,	@BLP_BBHIT2,	@SD_BBHIT2
//
//; �i�X�j�𕨘A���쓮�������u�쓮�I�����̏o�͗v��
//	DEFB	@FLP_BBEND,	@ELP_BBEND,	@BLP_BBEND,	@SD_BBEND
//
//; �i�P�O�j�𕨘A���쓮���u�쓮�I�����̏o�͗v��
//	DEFB	@FLP_CLEAR,	@ELP_CLEAR,	0,		@SD_CLEAR1
//
//; �i�P�P�j�ėV�Z�쓮���̏o�͗v��
//	DEFB	@FLP_REPLAY,	@ELP_REPLAY,	0,		@SD_REPLAY
//
//; �i�P�Q�j���܊��Ҏ��̏o�͗v���P�i���܊��Ҏ��̏o�͗v���Q�`�T�ȊO�̎��j
//	DEFB	0,		@ELP_WBL,	0,		@SD_WBL
//
//; �i�P�R�j���܊��Ҏ��̏o�͗v���Q
//;;�i�E�񓷉�]���̒������C��(���̐_����̐_)�\�����j
//	DEFB	0,		@ELP_WBL,	@BLP_WBL1,	@SD_WBL
//
//; �i�P�S�j���܊��Ҏ��̏o�͗v���R
//;;�i���񓷃`�F���[�ە\���y�щE�񓷉�]���̏�i���C��(���ݥ����)�\�����j
//	DEFB	0,		@ELP_WBL,	@BLP_WBL2,	@SD_WBL
//
//; �i�P�T�j���܊��Ҏ��̏o�͗v���S
//;;�i�E�񓷉�]���̏�i���C��(���̐_����̐_)�\�����j
//	DEFB	0,		@ELP_WBL,	@BLP_WBL3,	@SD_WBL
//
//; �i�P�U�j���܊��Ҏ��̏o�͗v���T
//;;�i���񓷃`�F���[�ە\���y�щE�񓷉�]���̉��i���C��(BAR�BAR)�\�����j
//	DEFB	0,		@ELP_WBL,	@BLP_WBL4,	@SD_WBL
//
//; �i�P�V�j���܊��ҏI�����̏o�͗v��
//	DEFB	0,		@ELP_CLEAR,	@BLP_ALL,	@SD_CLEAR1
//
//	PAGE
//; �i�P�W�j�V�Z���_���������̏o�͗v��
//	DEFB	0,		0,		@BLP_ALL,	@SD_INCO
//
//; �i�P�X�j�񓷉�]�s���̏o�͗v��
//	DEFB	0,		0,		0,		@SD_WAIT
//
//; �i�Q�O�j�񓷉�]�J�n���̏o�͗v��
//	DEFB	0,		0,		0,		@SD_START
//
//; �i�Q�P�j��~�{�^����t���̏o�͗v��
//	DEFB	0,		0,		0,		@SD_STOP
//
//; �i�Q�Q�j�񓷒�~���̏o�͗v��
//	DEFB	0,		0,		0,		@SD_R_STOP
//
//; �i�Q�R�j���܂ɂ��V�Z���_�����o���I�����̏o�͗v��
//	DEFB	@FLP_CLEAR,	@ELP_CLEAR,	0,		0
//
//; �i�Q�S�j���܂ɂ��V�Z���_���P�����o�����̏o�͗v��
//	DEFB	0,		0,		0,		@SD_PAY
//
//; �i�Q�T�j�V�Z���_�����o�G���[�������̏o�͗v��
//	DEFB	@FLP_CLEAR,	@ELP_CLEAR,	0,		@SD_CLEAR0
//
//	PAGE
//;	*************************************************
//;	*	���ʉ��ԍ��@��`			*
//;	*************************************************
//;
//@SD_CLEAR0	EQU	1	; ���ʉ��S�`�����l���N���A
//@SD_BBEND	EQU	2	; �𕨘A���쓮�������u�쓮�I����
//@SD_START	EQU	3	; �񓷉�]�J�n��
//
//@SD_INCO	EQU	4	; �V�Z���_��������
//@SD_STOP	EQU	5	; �񓷒�~��t��
//@SD_R_STOP	EQU	6	; �񓷒�~��
//@SD_WAIT	EQU	7	; �񓷉�]�s��
//@SD_PAY		EQU	8	; �V�Z���_�����o��
//
//@SD_CLEAR1	EQU	9	; ���ʉ��T�`�����l���N���A
//@SD_WBL		EQU	10	; �𕨘A���쓮���u�E�𕨘A���쓮�������u���܊��҉�
//@SD_REPLAY	EQU	11	; �ėV�Z�쓮��
//@SD_BB1		EQU	12	; �𕨘A���쓮�������u�쓮���P
//@SD_BB2		EQU	13	; �𕨘A���쓮�������u�쓮���Q
//@SD_BB3		EQU	14	; �𕨘A���쓮�������u�쓮���R
//@SD_RB		EQU	15	; �𕨘A���쓮���u�쓮��
//
//@SD_BBHIT1	EQU	16	; �𕨘A���쓮�������u���܉��P
//@SD_BBHIT2	EQU	17	; �𕨘A���쓮�������u���܉��Q
//@SD_ALARM	EQU	18	; ����ُ�x��
//
//	PAGE
//;	*************************************************
//;	*	�e�탉���v����y�ѓ_�Œ�  ��`		*
//;	*************************************************
//;
//; ***  ����@��`  ***
//
//@LP_COUNT	EQU	0FCH		; ���s�[�g��
//@LP_REPEAT	EQU	0FDH		; ���s�[�g�i�񐔐����t�J��Ԃ��j
//@LP_LOOP	EQU	0FEH		; �J��Ԃ�
//@BLP_END	EQU	0FFH		; �o�b�N�����v�\���I���i�S�_���j
//@LP_END		EQU	000H		; �㕔�����v�E���ʃ����v�\���I���i�S�����j
//
//@BLP9_OFF	EQU	01000000B	; �o�b�N�����v�f�[�^�g�p���o�b�N�����v�X�����f�[�^
//					;;(�_�Œ��Ƃ̘_���a�Ƃ��Ďg�p)
//@BLP9_ON	EQU	11000000B	; �o�b�N�����v�f�[�^�g�p���o�b�N�����v�X�_���f�[�^
//					;;(�_�Œ��Ƃ̘_���a�Ƃ��Ďg�p)
//
//; ***�@�_�Œ��@��`�@***
//
//@LEN015		EQU	1		; �@  �P�T�D�O�O�S�W������
//@LEN030		EQU	2		; �@  �R�O�D�O�O�X�U������
//;@LEN045	EQU	3		; �@  �S�T�D�O�P�S�S������
//@LEN060		EQU	4		; �@  �U�O�D�O�P�X�Q������
//@LEN075		EQU	5		; �@  �V�T�D�O�Q�S�O������
//@LEN090		EQU	6		; �@  �X�O�D�O�Q�W�W������
//@LEN105		EQU	7		;   �P�O�T�D�O�R�R�U������
//@LEN120		EQU	8		;   �P�Q�O�D�O�R�W�S������
//@LEN135		EQU	9		;   �P�R�T�D�O�S�R�Q������
//@LEN150		EQU	10		;   �P�T�O�D�O�S�W�O������
//;@LEN165	EQU	11		;   �P�U�T�D�O�T�Q�W������
//@LEN180		EQU	12		;   �P�W�O�D�O�T�V�U������
//@LEN195		EQU	13		;   �P�X�T�D�O�U�Q�S������
//@LEN210		EQU	14		;   �Q�P�O�D�O�U�V�Q������
//@LEN225		EQU	15		;   �Q�Q�T�D�O�V�Q�O������
//@LEN240		EQU	16		;   �Q�S�O�D�O�V�U�W������
//@LEN255		EQU	17		;   �Q�T�T�D�O�W�P�U������
//;@LEN270	EQU	18		; �@�Q�V�O�D�O�W�U�S������
//@LEN285		EQU	19		; �@�Q�W�T�D�O�X�P�Q������
//;@LEN300	EQU	20		;   �R�O�O�D�O�X�U�O������
//@LEN315		EQU	21		;   �R�P�T�D�P�O�O�W������
//;@LEN330	EQU	22		;   �R�R�O�D�P�O�T�U������
//;@LEN345	EQU	23		; �@�R�S�T�D�P�P�O�S������
//;@LEN360	EQU	24		;   �R�U�O�D�P�P�T�Q������
//@LEN375		EQU	25		; �@�R�V�T�D�P�Q�O�O������
//;@LEN390	EQU	26		;   �R�X�O�D�P�Q�S�W������
//;@LEN405	EQU	27		;   �S�O�T�D�P�Q�X�U������
//;@LEN420	EQU	28		;   �S�Q�O�D�P�R�S�S������
//@LEN435		EQU	29		;   �S�R�T�D�P�R�X�Q������
//;@LEN450	EQU	30		;   �S�T�O�D�P�S�S�O������
//;@LEN465	EQU	31		;   �S�U�T�D�P�S�W�W������
//;@LEN480	EQU	32		;   �S�W�O�D�P�T�R�U������
//@LEN495		EQU	33      	;   �S�X�T�D�P�T�W�S������
//;@LEN510	EQU	34      	;   �T�P�O�D�P�U�R�Q������
//;@LEN525	EQU	35      	;   �T�Q�T�D�P�U�W�O������
//;@LEN540	EQU	36      	;   �T�S�O�D�P�V�Q�W������
//;@LEN555	EQU	37      	;   �T�T�T�D�P�V�V�U������
//@LEN570		EQU	38      	;   �T�V�O�D�P�W�Q�S������
//;@LEN585	EQU	39      	;   �T�W�T�D�P�W�V�Q������
//;@LEN600	EQU	40      	;   �U�O�O�D�P�X�Q�O������
//;@LEN615	EQU	41      	;   �U�P�T�D�P�X�U�W������
//;@LEN630	EQU	42      	;   �U�R�O�D�Q�O�P�U������
//;@LEN645	EQU	43      	;   �U�S�T�D�Q�O�U�S������
//;@LEN660	EQU	44      	;   �U�U�O�D�Q�P�P�Q������
//;@LEN675	EQU	45      	;   �U�V�T�D�Q�P�U�O������
//;@LEN690	EQU	46      	;   �U�X�O�D�Q�Q�O�W������
//;@LEN705	EQU	47      	;   �V�O�T�D�Q�Q�T�U������
//;@LEN720	EQU	48      	;   �V�Q�O�D�Q�R�O�S������
//;@LEN735	EQU	49      	;   �V�R�T�D�Q�R�T�Q������
//@LEN750		EQU	50      	;   �V�T�O�D�Q�S�O�O������
//;@LEN765	EQU	51      	;   �V�U�T�D�Q�S�S�W������
//;@LEN780	EQU	52      	;   �V�W�O�D�Q�S�X�U������
//;@LEN795	EQU	53      	;   �V�X�T�D�Q�T�S�S������
//@LEN810		EQU	54      	;   �W�P�O�D�Q�T�X�Q������
//;@LEN825	EQU	55      	;   �W�Q�T�D�Q�U�S�O������
//;@LEN840	EQU	56      	;   �W�S�O�D�Q�U�W�W������
//;@LEN855	EQU	57      	;   �W�T�T�D�Q�V�R�U������
//;@LEN870	EQU	58     		;   �W�V�O�D�Q�V�W�S������
//;@LEN885	EQU	59		;   �W�W�T�D�Q�W�R�Q������
//
//	PAGE
//;	*************************************************
//;	*	�㕔�����v�f�[�^�ԍ��@��`		*
//;	*************************************************
//;
//@FLP_CLEAR	EQU	1	; �S����
//@FLP_ALARM	EQU	2	; �p�^�[���P
//@FLP_BB1		EQU	3	; �p�^�[���V��
//@FLP_BB2		EQU	4	; �p�^�[���V��
//@FLP_BB3		EQU	5	; �p�^�[���V��
//@FLP_RB		EQU	6	; �p�^�[���T
//@FLP_PAY		EQU	7	; �p�^�[���R
//@FLP_REPLAY	EQU	8	; �p�^�[���S
//@FLP_BBEND	EQU	9	; �p�^�[���W
//@FLP_BBHIT1	EQU	10      ; �p�^�[���U��
//@FLP_BBHIT2	EQU	11      ; �p�^�[���U��
//
//;	*************************************************
//;	*	�㕔�����v����				*
//;	*************************************************
//;
//TBL_FLASH_DATA:
//	DEFW	TBL_F_CLEAR
//	DEFW	TBL_F_ALARM
//	DEFW	TBL_F_BB1
//	DEFW	TBL_F_BB2
//	DEFW	TBL_F_BB3
//	DEFW	TBL_F_RB
//	DEFW	TBL_F_PAY
//	DEFW	TBL_F_REPLAY
//	DEFW	TBL_F_BBEND
//	DEFW	TBL_F_BBHIT1
//	DEFW	TBL_F_BBHIT2
//
//	PAGE
//;	*************************************************
//;	*	�㕔�����v				*
//;	*************************************************
//;
//
//; ***  �S����  ***
//
//TBL_F_CLEAR:
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//; ***  �V�Z���_�����o�G���[���̕\��  ***
//
//TBL_F_ALARM:
//					;    �㕔�����v		���D�D�_��
//					; ���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN015,00111100B	; ����������������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_F_ALARM		; �J��Ԃ��擪�A�h���X
//
//
//; ***  ���܂ɂ��V�Z���_�����o�����̕\��  ***
//
//TBL_F_PAY:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN060,11100111B	;   �P�@����������������
//	DEFB	@LEN060,11011011B	; �@�Q�@����������������
//	DEFB	@LEN060,10111101B	;   �R�@����������������
//	DEFB	@LEN060,01111110B	;   �S�@����������������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_F_PAY		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �ėV�Z�쓮���̕\��  ***
//
//TBL_F_REPLAY:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//
//	DEFB	@LP_COUNT,6		; ���s�[�g�񐔁��U
//TBL_F_REPLAY_1:
//	DEFB	@LEN060,10000010B	;   �P�@����������������
//	DEFB	@LEN060,01000001B	;   �Q�@����������������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_F_REPLAY_1		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LEN255,00111100B	; �@�R�@����������������
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//; ***  �𕨘A���쓮���u�쓮���̕\��  ***
//
//TBL_F_RB:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN210,10011001B	;   �P�@����������������
//	DEFB	@LEN210,01111110B	;   �Q�@����������������
//	DEFB	@LEN210,11011011B	;   �R�@����������������
//	DEFB	@LEN210,11100111B	;   �S�@����������������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_F_RB		; �J��Ԃ��擪�A�h���X
//
//
//	PAGE
//; ***  �𕨘A���쓮�������u�쓮���P�o�͎��̕\��  ***
//TBL_F_BB1:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN105,00011000B	;   �P�@����������������
//	DEFB	@LEN105,00111100B	;   �Q�@����������������
//	DEFB	@LEN105,01100110B	;   �R�@����������������
//	DEFB	@LEN105,11000011B	;   �S�@����������������
//	DEFB	@LEN105,10000001B	;   �T�@����������������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_F_BB1		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �𕨘A���쓮�������u�쓮���Q�o�͎��̕\��  ***
//TBL_F_BB2:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN105,10100101B	;   �P�@����������������
//	DEFB	@LEN105,01011010B	;   �Q�@����������������
//	DEFB	@LEN210,10100101B	;   �R�@����������������
//	DEFB	@LEN105,00111100B	;   �S�@����������������
//	DEFB	@LEN195,01111110B	;   �T�@����������������
//	DEFB	@LEN105,11111111B	;   �U�@����������������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_F_BB2		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �𕨘A���쓮�������u�쓮���R�o�͎��̕\��  ***
//
//TBL_F_BB3:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN060,00001111B	;   �P�@����������������
//	DEFB	@LEN060,00011110B	;   �Q�@����������������
//	DEFB	@LEN060,00111100B	;   �R�@����������������
//	DEFB	@LEN060,01111000B	;   �S�@����������������
//	DEFB	@LEN060,11110000B	;   �T�@����������������
//	DEFB	@LEN060,01111000B	;   �U�@����������������
//	DEFB	@LEN060,00111100B	;   �V�@����������������
//	DEFB	@LEN060,00011110B	;   �W�@����������������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_F_BB3		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �𕨘A���쓮�������u�쓮�I�����̕\��  ***
//
//TBL_F_BBEND:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN315,11111111B	;   �P�@����������������
//
//	DEFB	@LP_COUNT,16		; ���s�[�g�񐔁��P�U
//TBL_F_BBEND_1:
//	DEFB	@LEN150,01010101B	; �@�Q�@����������������
//	DEFB	@LEN150,10101010B	; �@�R�@����������������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_F_BBEND_1		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//	PAGE
//; ***  �𕨘A���쓮�������u�쓮�}��(���ݥ���ݥ����)���܎��̕\��  ***
//
//TBL_F_BBHIT1:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN750,10011001B	;   �P�@����������������
//	DEFB	@LEN495,01100110B	;   �Q�@����������������
//
//	DEFB	@LP_COUNT,8		; ���s�[�g�񐔁��W
//TBL_F_BBHIT1_1:
//	DEFB	@LEN255,00111100B	; �@�R�@����������������
//	DEFB	@LEN255,11000011B	;   �S�@����������������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_F_BBHIT1_1		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//; ***  �𕨘A���쓮�������u�쓮�}��(���̐_����̐_����̐_)���܎��̕\��  ***
//
//TBL_F_BBHIT2:
//					; �_��   �@�㕔�����v		���D�D�_��
//					; �����@���@�@�@�@�@�@�E	���D�D����
//	DEFB	@LEN810,11111111B	;   �P�@����������������
//	DEFB	@LEN060,00000000B	; �@�Q�@����������������
//
//	DEFB	@LP_COUNT,9       	; ���s�[�g�񐔁��X
//TBL_F_BBHIT2_1:
//	DEFB	@LEN225,01010101B	;   �R�@����������������
//	DEFB	@LEN225,10101010B	;   �S�@����������������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_F_BBHIT2_1		; ���s�[�g�擪�A�h���X
//
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//	PAGE
//;	*************************************************
//;	*	���ʃ����v�f�[�^�ԍ���`		*
//;	*************************************************
//;
//@ELP_CLEAR	EQU	1	; �S����
//@ELP_ALARM	EQU	2	; �p�^�[���P
//@ELP_WBL	EQU	3	; �p�^�[���Q
//@ELP_REPLAY	EQU	4	; �p�^�[���S
//@ELP_BBHIT1	EQU	5	; �p�^�[���U��
//@ELP_BBHIT2	EQU	6	; �p�^�[���U��
//@ELP_PAY	EQU	7	; �p�^�[���R
//@ELP_BB1	EQU	8	; �p�^�[���V��
//@ELP_BB2	EQU	9	; �p�^�[���V��
//@ELP_BB3	EQU	10      ; �p�^�[���V��
//@ELP_RB		EQU	11      ; �p�^�[���T
//@ELP_BBEND	EQU	12      ; �p�^�[���W
//
//;	*************************************************
//;	*	���ʃ����v����				*
//;	*************************************************
//;
//TBL_EFFECT_DATA:
//	DEFW	TBL_E_CLEAR
//	DEFW	TBL_E_ALARM
//	DEFW	TBL_E_WBL
//	DEFW	TBL_E_REPLAY
//	DEFW	TBL_E_BBHIT1
//	DEFW	TBL_E_BBHIT2
//	DEFW	TBL_E_PAY
//	DEFW	TBL_E_BB1
//	DEFW	TBL_E_BB2
//	DEFW	TBL_E_BB3
//	DEFW	TBL_E_RB
//	DEFW	TBL_E_BBEND
//
//	PAGE
//;	*************************************************
//;	*	���ʃ����v				*
//;	*************************************************
//;
//
//; ***  �S����  ***
//
//TBL_E_CLEAR:
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//; ***  �V�Z���_�����o�G���[���̕\��  ***
//
//TBL_E_ALARM:
//					; ���ʃ����v	���D�D�_��
//					; �@�����E	���D�D����
//	DEFB	@LEN015,11100000B	;   ������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_E_ALARM		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �𕨘A���쓮���u�A���͖𕨘A���쓮�������u�쓮�}���̓��܊��Ҏ��̕\��  ***
//
//TBL_E_WBL:
//					; �_�Ł@���ʃ����v	���D�D�_��
//					; �����@�@�����E	���D�D����
//	DEFB	@LEN150,11000000B	;   �P�@�@������
//
//	DEFB	@LP_COUNT,4
//TBL_E_WBL_1:
//	DEFB	@LEN090,01100000B	;   �Q�@�@������
//	DEFB	@LEN090,00000000B	;   �R�@�@������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_E_WBL_1		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//; ***  ���܂ɂ��V�Z���_�����o�����̕\��  ***
//
//TBL_E_PAY:
//					; �_�Ł@���ʃ����v	���D�D�_��
//					; �����@�@�����E	���D�D����
//	DEFB	@LEN060,01000000B	;   �P�@�@������
//	DEFB	@LEN060,10100000B	;   �Q�@�@������
//	DEFB	@LEN060,00000000B	;   �R�@�@������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_E_PAY		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �ėV�Z�쓮���̕\��  ***
//
//TBL_E_REPLAY:
//					; �_�Ł@���ʃ����v	���D�D�_��
//					; �����@�@�����E	���D�D����
//	DEFB	@LP_COUNT,6
//TBL_E_REPLAY_1:
//	DEFB	@LEN060,01000000B	;   �P�@�@������
//	DEFB	@LEN060,10100000B	;   �Q�@�@������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_E_REPLAY_1		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LEN255,11100000B	;   �R�@�@������
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//ooooooooooooooooooooooooooooooooo
//	PAGE
//; ***  �𕨘A���쓮�������u�쓮�}��(���ݥ���ݥ����)���܎��̕\��  ***
//
//TBL_E_BBHIT1:
//					; �_�Ł@���ʃ����v	���D�D�_��
//					; �����@�@�����E	���D�D����
//	DEFB	@LEN570,11100000B	;   �P�@�@������
//	DEFB	@LEN075,00000000B	;   �Q�@�@������
//
//	DEFB	@LP_COUNT,13    	;���s�[�g�񐔁��P�R
//TBL_E_BBHIT1_1:
//	DEFB	@LEN090,10100000B	;   �R�@�@������
//	DEFB	@LEN090,11100000B	; �@�S�@�@������
//	DEFB	@LEN090,00000000B	;   �T�@�@������
//	DEFB	@LEN090,01000000B	; �@�U�@�@������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_E_BBHIT1_1 		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//; ***  �𕨘A���쓮�������u�쓮�}��(���̐_����̐_����̐_)���܎��̕\��  ***
//
//TBL_E_BBHIT2:
//			 		; �_�Ł@���ʃ����v	���D�D�_��
//			  		; �����@�@�����E	���D�D����
//
//	DEFB	@LP_COUNT,16    	; ���s�[�g�񐔁��P�U
//TBL_E_BBHIT2_1:
//	DEFB	@LEN150,10100000B	; �@�P�@�@������
//	DEFB	@LEN150,01000000B	; �@�Q�@�@������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_E_BBHIT2_1		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LEN120,11100000B	; �@�R�@�@������
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//; ***  �𕨘A���쓮�������u�쓮���P�o�͎��̕\��  ***
//
//TBL_E_BB1:
//					; �_�Ł@���ʃ����v	���D�D�_��
//					; �����@�@�����E	���D�D����
//	DEFB	@LEN105,11000000B	; �@�P�@�@������
//	DEFB	@LEN105,00100000B	; �@�Q�@�@������
//	DEFB	@LEN105,01100000B	; �@�R�@�@������
//	DEFB	@LEN105,10000000B	; �@�S�@�@������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_E_BB1		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �𕨘A���쓮�������u�쓮���Q�o�͎��̕\��  ***
//
//TBL_E_BB2:
//			 		; �_�Ł@���ʃ����v	���D�D�_��
//			  		; �����@�@�����E	���D�D����
//	DEFB	@LEN120,10000000B	; �@�P�@�@������
//	DEFB	@LEN120,11000000B	; �@�Q�@�@������
//	DEFB	@LEN120,11100000B	; �@�R�@�@������
//	DEFB	@LEN150,00000000B	; �@�S�@�@������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_E_BB2		; �J��Ԃ��擪�A�h���X
//
//
//	PAGE
//; ***  �𕨘A���쓮�������u�쓮���R�o�͎��̕\��  ***
//
//TBL_E_BB3:
//			 		; �_�Ł@���ʃ����v	���D�D�_��
//			  		; �����@�@�����E	���D�D����
//	DEFB	@LEN240,10100000B	; �@�P�@�@������
//	DEFB	@LEN240,01000000B	; �@�Q�@�@������
//	DEFB	@LEN060,11100000B	; �@�R�@�@������
//	DEFB	@LEN060,00000000B	; �@�S�@�@������
//	DEFB	@LEN060,11100000B	; �@�T�@�@������
//	DEFB	@LEN060,00000000B	; �@�U�@�@������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_E_BB3		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �𕨘A���쓮���u�쓮���̕\��  ***
//
//TBL_E_RB:
//			 		; �_�Ł@���ʃ����v	���D�D�_��
//			  		; �����@�@�����E	���D�D����
//	DEFB	@LEN105,00100000B	; �@�P�@�@������
//	DEFB	@LEN105,00000000B	; �@�Q�@�@������
//	DEFB	@LEN105,00100000B	; �@�R�@�@������
//	DEFB	@LEN105,00000000B	; �@�S�@�@������
//	DEFB	@LEN210,01000000B	; �@�T�@�@������
//	DEFB	@LEN210,10000000B	; �@�U�@�@������
//
//	DEFB	@LP_LOOP		; �J��Ԃ�
//	DEFW	TBL_E_RB		; �J��Ԃ��擪�A�h���X
//
//
//; ***  �𕨘A���쓮�������u�쓮�I�����̕\��  ***
//
//TBL_E_BBEND:
//			 		; �_�Ł@���ʃ����v	���D�D�_��
//			  		; �����@�@�����E	���D�D����
//	DEFB	@LEN435,11100000B	; �@�P�@�@������
//	DEFB	@LEN060,00000000B	; �@�Q�@�@������
//
//	DEFB	@LP_COUNT,3		; ���s�[�g�񐔁��R
//TBL_E_BBEND_1:
//	DEFB	@LEN375,01100000B	; �@�R�@�@������
//	DEFB	@LEN375,11000000B	; �@�S�@�@������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_E_BBEND_1		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LP_COUNT,9		; ���s�[�g�񐔁��X
//TBL_E_BBEND_2:
//	DEFB	@LEN120,10100000B	; �@�T�@�@������
//	DEFB	@LEN120,01000000B	; �@�U�@�@������
//
//	DEFB	@LP_REPEAT		; ���s�[�g
//	DEFW	TBL_E_BBEND_2		; ���s�[�g�擪�A�h���X
//
//	DEFB	@LEN210,00000000B	; �@�V�@�@������
//
//	DEFB	@LP_END			; �I���i�N���A�j
//
//
//	PAGE
//;	*************************************************
//;	*	�o�b�N�����v�f�[�^�ԍ���`		*
//;	*************************************************
//;
//@BLP_ALL	EQU	1	; �S�_��
//@BLP_WBL1	EQU	2 	; �p�^�[���Q��
//@BLP_WBL2	EQU	3 	; �p�^�[���Q��
//@BLP_WBL3	EQU	4 	; �p�^�[���Q��
//@BLP_WBL4	EQU	5 	; �p�^�[���Q��
//@BLP_BBHIT1	EQU	6	; �p�^�[���U��
//@BLP_BBHIT2	EQU	7	; �p�^�[���U��
//@BLP_BBEND	EQU	8	; �p�^�[���W
//
//;	*************************************************
//;	*	�o�b�N�����v����			*
//;	*************************************************
//;
//TBL_BACK_DATA:
//	DEFW	TBL_B_ALL
//	DEFW	TBL_B_WBL1
//	DEFW	TBL_B_WBL2
//	DEFW	TBL_B_WBL3
//	DEFW	TBL_B_WBL4
//	DEFW	TBL_B_BBHIT1
//	DEFW	TBL_B_BBHIT2
//	DEFW	TBL_B_BBEND
//
//	PAGE
//;	*************************************************
//;	*	�o�b�N�����v				*
//;	*************************************************
//;
//
//; ***  �S�_��  ***
//
//TBL_B_ALL:
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//
//; ***  �E�񓷉�]���̒������C��(���̐_����̐_)�\�����̕\��  ***
//
//TBL_B_WBL1:
//						; �_��  �o�b�N�����v	���D�D�_��
//						; �����@�@ �����E	���D�D����
//
//	DEFB	@LP_COUNT,2			; ���s�[�g�񐔁��Q
//TBL_B_WBL1_1:
//	DEFB	@BLP9_ON  OR @LEN060,11111001B	; �@�P	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN060,11111100B	; �@�Q	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN060,11110110B	; �@�R	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN060,11100111B	; �@�S	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN060,11001111B	; �@�T	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN060,11011011B	; �@�U	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@LP_REPEAT			; ���s�[�g
//	DEFW	TBL_B_WBL1_1			; ���s�[�g�擪�A�h���X
//
//	DEFB	@BLP9_ON  OR @LEN150,11111111B	; �@�V	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//
//; ***  ���񓷃`�F���[�ە\���y�щE�񓷉�]���̏�i���C��(���ݥ����)�\�����̕\��  ***
//
//TBL_B_WBL2:
//						; �_��  �o�b�N�����v	���D�D�_��
//						; �����@�@ �����E	���D�D����
//
//	DEFB	@LP_COUNT,4			; ���s�[�g�񐔁��S
//TBL_B_WBL2_1:
//	DEFB	@BLP9_ON  OR @LEN105,11010010B	; �@�P	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN105,11111111B	; �@�Q	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@LP_REPEAT			; ���s�[�g
//	DEFW	TBL_B_WBL2_1			; ���s�[�g�擪�A�h���X
//
//	DEFB	@BLP9_ON  OR @LEN030,11111111B	; �@�R	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//
//	PAGE
//; ***  �E�񓷉�]���̏�i���C��(���̐_����̐_)�\�����̕\��  ***
//
//TBL_B_WBL3:
//						; �_��  �o�b�N�����v	���D�D�_��
//						; �����@�@ �����E	���D�D����
//
//	DEFB	@LP_COUNT,4			; ���s�[�g�񐔁��S
//TBL_B_WBL3_1:
//	DEFB	@BLP9_ON  OR @LEN105,11111100B	; �@�P	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN105,11011011B	; �@�Q	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@LP_REPEAT			; ���s�[�g
//	DEFW	TBL_B_WBL3_1			; ���s�[�g�擪�A�h���X
//
//	DEFB	@BLP9_ON  OR @LEN030,11111111B	; �@�R	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//
//; ***  ���񓷃`�F���[�ە\���y�щE�񓷉�]���̉��i���C��(BAR�BAR)�\�����̕\��  ***
//
//TBL_B_WBL4:
//						; �_��  �o�b�N�����v	���D�D�_��
//						; �����@�@ �����E	���D�D����
//
//	DEFB	@LP_COUNT,2			; ���s�[�g�񐔁��Q
//TBL_B_WBL4_1:
//	DEFB	@BLP9_ON  OR @LEN135,11110110B	; �@�P	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN135,11101101B	; �@�Q	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN135,11011011B	; �@�R	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@LP_REPEAT			; ���s�[�g
//	DEFW	TBL_B_WBL4_1			; ���s�[�g�擪�A�h���X
//
//	DEFB	@BLP9_ON  OR @LEN060,11111111B	; �@�S	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//
//	PAGE
//; ***  �𕨘A���쓮�������u�쓮�}��(���ݥ���ݥ����)���܎��̕\��  ***
//
//TBL_B_BBHIT1:
//						; �_��  �o�b�N�����v	���D�D�_��
//						; �����@�@ �����E	���D�D����
//
//	DEFB	@LP_COUNT,7			; ���s�[�g�񐔁��V
//TBL_B_BBHIT1_1:
//	DEFB	@BLP9_ON  OR @LEN180,10000011B	; �@�P	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN180,00111001B	; �@�Q	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_OFF OR @LEN180,01000100B	; �@�R	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_OFF OR @LEN180,11111110B	; �@�S	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@LP_REPEAT			; ���s�[�g
//	DEFW	TBL_B_BBHIT1_1			; ���s�[�g�擪�A�h���X
//
//	DEFB	@BLP9_OFF OR @LEN285,00000000B	; �@�T	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//
//; ***  �𕨘A���쓮�������u�쓮�}��(���̐_����̐_����̐_)���܎��̕\��  ***
//
//TBL_B_BBHIT2:
//						; �_��  �o�b�N�����v	���D�D�_��
//						; �����@�@ �����E	���D�D����
//
//	DEFB	@LP_COUNT,16			; ���s�[�g�񐔁��P�U
//TBL_B_BBHIT2_1:
//	DEFB	@BLP9_ON  OR @LEN075,10010011B	; �@�P	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_OFF OR @LEN075,11010110B	; �@�Q	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_OFF OR @LEN075,00111100B	; �@�R	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN075,00111001B	; �@�S	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@LP_REPEAT			; ���s�[�g
//	DEFW	TBL_B_BBHIT2_1			; ���s�[�g�擪�A�h���X
//
//	DEFB	@BLP9_OFF OR @LEN120,00000000B	; �@�T	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//	PAGE
//; ***  �𕨘A���쓮�������u�쓮�I�����̕\��  ***
//
//TBL_B_BBEND:
//						; �_��  �o�b�N�����v	���D�D�_��
//						; �����@�@ �����E	���D�D����
//
//	DEFB	@LP_COUNT,10    		; ���s�[�g�񐔁��P�O
//TBL_B_BBEND_1:
//	DEFB	@BLP9_OFF OR @LEN255,10101010B	; �@�P	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP9_ON  OR @LEN255,01010101B	; �@�Q	 �ぜ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@LP_REPEAT			; ���s�[�g
//	DEFW	TBL_B_BBEND_1			; ���s�[�g�擪�A�h���X
//
//	DEFB	@BLP9_OFF OR @LEN015,00000000B	;   �R	 �せ����
//						;	 ��������
//						;	 ��������
//
//	DEFB	@BLP_END			; �I���i�Z�b�g�j
//
//
//	PAGE
//;	*************************************************
//;	*	�q�n�l�`�F�b�N�T���p			*
//;	*************************************************
//;
//	DEFB	019H
//
//;;
//	ORG	1C00H
//;	*************************************************
//;	*	�^�����A��Ж��A�S���Җ��A���t		*
//;	*************************************************
//;
//	DEFB	'�����ݶл�'		; �^����
//
//	ORG	1C10H
//	DEFB	'�а ��޼��޲��'	; ��Ж�
//
//	ORG	1C30H
//	DEFB	'��� �ݽ�'		; �S���Җ�
//
//	ORG	1C40H
//	DEFB	'1998/05/12'		; ���t
//
//	ORG	1F00H
//;	*************************************************
//;	*	�k�d�P�O�W�O�`�Ǘ��G���A		*
//;	*************************************************
//;
//	DEFB	68H,63H,65H,54H
//	DEFB	2EH,45H,2EH,4CH
//
//	DEFW	0			; PCS
//
//	DEFW	PRG_END - 1		; PCE
//
//	DEFW	0
//
//	DEFW	0
//
//	DEFB	00H			; RSS (512BYTE)
//
//	ORG	1FFFH
//	DEFB	0
//
//	PAGE
//;	*************************************************
//;	*	�q�`�l�̈����				*
//;	*************************************************
//
//; �V�Z��ԃt���O
//;_FL_GAME_STS
//;BIT 0		�𕨘A���쓮�������u�쓮�I�����������Z���[�h
//;    1		�A�������A�v��
//;    2		�𕨘A���쓮�������u�쓮�I�����ł��~�߃��[�h
//;    3		�񓷉�]�n�����u��t����
//;    4		�V�Z���_���������u�ێg�p
//;    5		�V�Z���_�����E
//;    6		�d�f�����ς�
//;    7		���Z�C������
//
//; �񓷐���f�[�^ (#=1,2,3)
//;_WK_REEL#
//;	  + 0	�񓷋쓮��Ԕԍ�
//;	  + 1	�񓷋쓮�p���X�o�͎���
//;	  + 2	�������̉񓷋쓮�p���X�ؑւ���
//;	  + 3	�葬���̉񓷃Z���T�[�ʉ߃t���O
//;	  + 4	�P�}���̃X�e�b�v�ԍ�
//;	  + 5	�}���ԍ��i�ʉ߈ʒu�p�j
//;	  + 6	�}���ԍ��i��~�ʒu�p�j
//;	  + 7   �񓷋쓮�p���X�f�[�^�����p�J�E���^
//
//; �㕔�����v����f�[�^
//;_WK_FLASH_LP
//;	  + 0	�㕔�����v�ԍ�
//;	  + 1	�\�����ԃf�[�^
//;	  + 2	���s�A�h���X�@����
//;	  + 3	���s�A�h���X�@���
//;	  + 4   ���s�[�g��
//
//; ���ʃ����v����f�[�^
//;_WK_EFFECT_LP
//;	  + 0	���ʃ����v�ԍ�
//;	  + 1	�\�����ԃf�[�^
//;	  + 2	���s�A�h���X�@����
//;	  + 3	���s�A�h���X�@���
//;	  + 4   ���s�[�g��
//
//; �o�b�N�����v����f�[�^
//;_WK_BACK_LP
//;	  + 0	�o�b�N�����v�ԍ�
//;	  + 1	�\�����ԃf�[�^
//;	  + 2	���s�A�h���X�@����
//;	  + 3	���s�A�h���X�@���
//;	  + 4   ���s�[�g��
//
//	PAGE
//	ORG	8000H
//;	*************************************************
//;	*	�q�`�l������				*
//;	*************************************************
//;
//
//; �ݒ�l
//
//_NB_RANK	DEFS	1		; �ݒ�l�f�[�^�i�P�|�U�j
//
//; �V�Z���
//
//_FL_GAME_STS	DEFS	1		; �V�Z��ԃt���O
//
//; ���̓f�[�^
//
//_PT_IN0_OLD	DEFS	1		; ���̓|�[�g�O���x���f�[�^
//_PT_IN0_UP	DEFS	1		; ���̓|�[�g�O�����オ��f�[�^
//_PT_IN0_DOWN	DEFS	1		; ���̓|�[�g�O����������f�[�^
//_PT_IN1_OLD	DEFS	1		; ���̓|�[�g�P���x���f�[�^
//_PT_IN1_UP	DEFS	1		; ���̓|�[�g�P�����オ��f�[�^
//_PT_IN2_OLD	DEFS	1		; ���̓|�[�g�Q���x���f�[�^
//_PT_IN2_UP	DEFS	1		; ���̓|�[�g�Q�����オ��f�[�^
//
//; �\��
//
//_FL_LED_CHANGE	DEFS	1		; �\���ؑւ��t���O
//
//_NB_COUNT_LED1	DEFS	1		; �񐔕\���f�[�^�P
//_NB_COUNT_LED2	DEFS	1		; �񐔕\���f�[�^�Q
//_NB_CREDIT_LED	DEFS	1		; �V�Z���_�����������\���f�[�^
//_NB_PAY_LED	DEFS	1		; �V�Z���_�����o�������\���f�[�^
//
//_WK_FLASH_LP	DEFS	5		; �㕔�����v����f�[�^
//
//_WK_EFFECT_LP	DEFS	5		; ���ʃ����v����f�[�^
//
//_WK_BACK_LP	DEFS	5		; �o�b�N�����v����f�[�^
//
//_FL_WBL		DEFS	1		; ���܊��ҕ\���t���O
//
//_FL_STOP_LP	DEFS	1		; �񓷒�~�t���O
//
//_WK_WIN_LP	DEFS	1		; ���܎��L�����C�������v�_�Ńf�[�^
//_WK_WINBACK_LP	DEFS	2		; ���܎��o�b�N�����v�_�Ńf�[�^
//
//; �o�̓f�[�^
//
//_PT_OUT0	DEFS	1		; �o�̓|�[�g�O�f�[�^
//_PT_OUT1	DEFS	1		; �o�̓|�[�g�P�f�[�^
//_PT_OUT2	DEFS	1		; �o�̓|�[�g�Q�f�[�^
//_PT_OUT3	DEFS	1		; �o�̓|�[�g�R�f�[�^
//_PT_OUT4	DEFS	1		; �o�̓|�[�g�S�f�[�^
//_PT_OUT5	DEFS	1		; �o�̓|�[�g�T�f�[�^
//_PT_OUT6	DEFS	1		; �o�̓|�[�g�U�f�[�^
//_PT_OUT7	DEFS	1		; �o�̓|�[�g�V�f�[�^
//_PT_OUT8	DEFS	1		; �o�̓|�[�g�W�f�[�^
//
//; �Q�o�C�g�^�C�}
//@TM2_NUM	EQU	5		; �Q�o�C�g�^�C�}��
//_TM2_AUTOSTOP	DEFS	2		; �񓷎�����~����
//_TM2_HE_CHK	DEFS	2		; �V�Z���_�����o���u�쓮����
//_TM2_REPLAY_ML	DEFS	2		; �V�Z���_�����������ҋ@����
//_TM2_GAME	DEFS	2		; �ŒZ�V�Z����
//_TM2_BACK_OFF	DEFS	2		; �V�Z�ҋ@���̕\���ҋ@����
//
//; �P�o�C�g�^�C�}
//@TM1_NUM	EQU	9		; �P�o�C�g�^�C�}��
//_TM1_BET_ML	DEFS	1		; �V�Z���_�������ҋ@����
//_TM1_OUT_CNT	DEFS	1		; �O���M���o�͎���
//_TM1_STOP	DEFS	1		; �񓷒�~��t�ҋ@����
//_TM1_CREDIT	DEFS	1		; �V�Z���_�������������Z�ҋ@����
//_TM1_PAY	DEFS	1		; �V�Z���_�����o�Z���T�[�`�F�b�N����
//_TM1_WIN_LP	DEFS	1		; ���܃��C���_�Ŏ���
//_TM1_RESET	DEFS	1		; �O���Ŏ~�߉����M�����͎���
//_TM1_MEDAL1	DEFS	1		; �V�Z���_�������Z���T�[�P�ʉ߃`�F�b�N����
//_TM1_MEDAL2	DEFS	1		; �V�Z���_�������Z���T�[�Q�ʉ߃`�F�b�N����
//
//	PAGE
//; ��
//
//_WK_REEL1	DEFS	8		; ���񓷐���f�[�^
//_WK_REEL2	DEFS	8		; ���񓷐���f�[�^
//_WK_REEL3	DEFS	8		; �E�񓷐���f�[�^
//
//; �V�Z���_���J�E���^
//
//_CT_MEDAL_IN	DEFS	1		; �V�Z���_�������M���o�͉�
//_CT_MEDAL_OUT	DEFS	1		; �V�Z���_�����o�M���o�͉�
//
//; �V�Z���_������
//
//_NB_PLAY_MEDAL	DEFS	1		; �V�Z���_�������f�[�^
//_NB_PAY_MEDAL	DEFS	1		; �V�Z���_�����o�������f�[�^
//
//_NB_REP_MEDAL	DEFS	1		; ���������V�Z���_�������f�[�^
//
//; �d�f
//
//_WK_SUM_CHK	DEFS	1		; �q�`�l�`�F�b�N�T���f�[�^
//
//_BF_STACK	DEFS	2		; �X�^�b�N�|�C���^�ꎞ�ۑ��o�b�t�@
//
//; ���܁E�쓮�t���O
//
//_FL_WIN		DEFS	1		; ���܃t���O
//
//_FL_ACTION	DEFS	1		; �쓮�t���O
//
//; ���I
//
//_CT_IN_OUT	DEFS	2		; �������J�E���^
//
//_BF_RAND1	DEFS	2		; ��ʗV�Z�}�����I�p�����ۑ��o�b�t�@
//_BF_RAND2	DEFS	2		; �𕨗V�Z�}�����I�p�����ۑ��o�b�t�@
//
//_FL_PUL_PIC1	DEFS	1 		; �����ݐ}���f�[�^�P
//_FL_REJ_PIC1	DEFS	1 		; �R��΂��}���f�[�^�P
//_FL_PUL_PIC2	DEFS	1 		; �����ݐ}���f�[�^�Q
//_FL_REJ_PIC2	DEFS	1 		; �R��΂��}���f�[�^�Q
//
//; �񓷐}����~����
//
//_NB_STOP_ORDER	DEFS	1		; �񓷒�~���ԃf�[�^
//_NB_STOP_REEL	DEFS	1		; ��~�񓷔ԍ��f�[�^
//_BF_PICTURE	DEFS	1		; �񓷒�~��t���}���ԍ��ۑ��p�o�b�t�@
//_NB_REJECT	DEFS	1		; �R��΂��R�}���f�[�^
//_FL_STOP_PNT	DEFS	1		; ��~�\�ʒu�t���O
//
//_WK_REEL_PIC1	DEFS	7		; �񓷐}���f�[�^�P�i�V�}�����j
//_WK_REEL_PIC2	DEFS	7		; �񓷐}���f�[�^�Q�i�V�}�����j
//
//_WK_ALL_PIC1	DEFS	1		; ��~�}���f�[�^�P�i�S�L�����C���j
//_WK_ALL_PIC2	DEFS	1		; ��~�}���f�[�^�Q�i�S�L�����C���j
//_WK_STOP_PIC1	DEFS	5		; ��~�}���f�[�^�P�i�e�L�����C���j
//_WK_STOP_PIC2	DEFS	5		; ��~�}���f�[�^�Q�i�e�L�����C���j
//
//_BF_STOP_CTL	DEFS	2		; ��~�ʒu����p�e�[�u���ۑ��p�o�b�t�@
//
//; �𕨘A���쓮���u�y�і𕨘A���쓮�������u�p�J�E���^
//
//_CT_BONUS_PLAY	DEFS	1		; �𕨘A���쓮���u�쓮���̖𕨗V�Z��
//_CT_BONUS_WIN 	DEFS	1		; �𕨘A���쓮���u�쓮���̖𕨓��܉�
//_CT_BIG_PLAY	DEFS	1		; �𕨘A���쓮�������u�쓮���̈�ʗV�Z��
//_CT_BIG_WIN	DEFS	1		; �𕨘A���쓮�������u�쓮����
//					;;�𕨘A���쓮���u���܉�
//
//	END
//
