#ifndef _KAWA_H_
#define _KAWA_H_

// hawk.c 
extern	char	start_flag;	// �����X�^�[�g�t���O 

// toggles.c 
extern	signed	char	yn_sts;		// -1:�X���[�v0:�I��1:�͂�2:������
extern			char	hawk_setting;	// �ډ��������v�ݒ蒆 
extern	signed	char	mr_light[3][21];	// �~�j���[������� 
extern	void	set_mesp_val(int, int, int);
extern	signed	char	mesp_sts;	// -1:�X���[�v0:�ғ���
// �h�����R���R���p 
typedef struct {
	char	req;
	char	drum_no;
	char	item_no;
	char	direc;
} ROLL_DRUM;
extern	ROLL_DRUM	r_drum;


// flash.c 
extern	char	flash_no;		// �t���b�V���ԍ� 

// detect.c 
extern	short	det_val[3][3];	// [������O��][�v���C���^���o������] 
extern	void	call_detect_result(void);
extern	char	result_call;

// unlock.c
extern	char	rankin_no;		// �����L���O���� 0~9�F���� ����ȏ�F�����N�O 

// cross.c 
/*
short	bingo_poll[3][4];// �q���t���O������ [��][��] *
/*	���F	0-��m����	1-���m����	2-�a�h�f��
	���F	0-15������	1-10or8��	2-���񓷂���	3-�ėV�Y
*/
//short	bingo_get[3][4];// �q���Q�b�g�� [��][��] *
extern	short	cross_poll[4];
extern	short	cross_get[4];
extern	short	playnum_cross;	// �v���C�񐔁m�n *
extern	short	replaynum_cross;
extern	short	det_play_num;	// �ݒ蔻�ʃ��[�h�ł̔��ʃv���C�� 
extern	short	out_koya_coin;	// �ݒ蔻�ʃ��[�h�ł̏��𑍕��o������ 
extern	short	detplay_get_num;// ���ʃv���C�ł̏����l���� 

// title.c 
void	t_option(WINDOW *);
extern	char	quitflag;
extern	char	retryflag;

// submenu.c 
short	submenu_drv(void);	// ���j���[�p�l���h���C�o 
void	init_kawas(int);	// ��㑤�̕ϐ��������� 
void	make_setting_data(SETTING_DATA *);		// �ݒ�Z�[�u�p�f�[�^�쐬 
void	restore_setting_data(SETTING_DATA *);	// �ݒ�Z�[�u�p�f�[�^�W�J 
void	retry_initial(void);	// ��蒼���p�C�j�V�����C�Y 

extern	WINDOW	*mesp_p;	// ���b�Z�[�W�p�l���p 
typedef	struct	{
	short	u,v;
	short	u0, v0;
	short	tw, th;
	short	cx, cy;
	short	mode;
	short	page;
	short	rate;
}	TEX_INF;
//	�|���̏�K�����o	
typedef	struct {
	TEX_INF		tp;
	POLY_FT4	*pp;
	short		x, y;
	short		w, h;
	short		r,g,b;
}	POL_MEMB;
//	�w�J�[�\��	
typedef	struct {
	POL_MEMB	pm;
	short		dx, dy;	// �ړI�n 
	short		vx, vy;	// ���x 
}	F_CUR;
typedef	struct	{
	F_CUR		fcur;
	SPRITE_OBJECT	*lrcur;
	int			work[8];
	short		step;
	signed char	titleF;
	signed char	exitF;
	signed char	loadF;
	signed char	cp_fir;			// �T�u���j���[�b�o 
	signed char	cp_ddw;			// �f�[�^�\���E�B���h�E�b�o 
	signed char	cp_cfg;			// �R���t�B�O�b�o 
	signed char	cp_aut;			// �I�[�g�ݒ�b�o 
	signed char	cp_flg;			// �t���O�ݒ�b�o 
	signed char	cp_opt;			// �I�v�V�����b�o 
	signed char	cp_mem;			//  
	char		cp_sts;			// �X�e�[�^�X�E�B���h�E�ԍ� 
	char		cur_win;		// �J�����g�E�B���h�E 
	char		sethawk;		// �ډ��������v�ݒ蒆�t���O 
	signed char	cash_rate;		// �������~�P�O 
}	SUBMENU;
extern	SUBMENU	*swp;		// �T�u���j���[�����f�[�^���[�N 


extern	char	push_type;

#endif
