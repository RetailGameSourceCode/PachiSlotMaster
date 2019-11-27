/*=============================================================
 *
 *	�ėp�֐�
 *
 *=============================================================*/
#include "common.h"
#include "work.h"

void first_data(void);

int mem_cnt;
void *anm_adr,*atime_adr;

#ifdef DEBUG_FLAG
 int dbg_fnt_flg;
#endif

/*=============================================================
 *
 *	���[�v�֐�
 *
 *=============================================================*/
void loop_func(void)
{

		/*�K�v�ȂƂ������ĂԂ���*/
		switch(func_mode)
		{
		}

		/*��ɌĂԂ���*/
	//	wfadel_inout();	/*�P�x�ω��ɂ��t�F�[�h*/
	//	wfadec_inout();	/*�J���[�t�F�[�h*/
	//	colchg_job();	/*�J���[�`�F���W����*/
	//	win_move_wt();	//
		sound_driver();	/*�T�E���h*/

		cd_read_fast();	/*�b�c���[�h*/


	return;
}



/*=============================================================
 *
 *
 *=============================================================*/
void boot_init(void)
{
}


/*=============================================================
 *
 *
 *=============================================================*/
void start_init(void)
{

}



/*=============================================================
 *	��x�ǂݍ��߂΂��������Z�b�g���܂�
 *
 * in:	void
 *
 * out:	void
 *
 *=============================================================*/
void first_data(void)
{
 RECT vadr;

}


/*-------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/
/*-------------------------------------------------------------------*/



/*=============================================================
 *
 *  �s�h�l�A�o�w�k�A�b�k�s���t���[���o�b�t�@�֓]�����܂�
 *
 * in:
 *		u_short *adr	�]�������C���������A�h���X
 *		int load_type	1 : �P�������]��	//	�P�`
 *						0 : ���ׂē]��
 *=============================================================*/
void tim_load(u_short *adr, int load_type)
{
#define TIM_HEADER 0x0010
#define CLT_HEADER 0x0011
#define PXL_HEADER 0x0012
	register int clt_sw;
	register int lp;
	RECT rct;
	GsIMAGE stim;

	clt_sw=0;
//	if(load_type>=900){
//		adr+=2500;
//		load_type-=900;
//	}


	if(load_type!=0){
		for(lp=1;lp<load_type;lp++){
			switch(*adr){
				case TIM_HEADER:
				case PXL_HEADER:
					adr+=2;	/* �w�b�_�̃X�L�b�v(4byte) */
					GsGetTimInfo((u_long *)adr, &stim);
					adr += stim.pw*stim.ph +6+2;	/* ���̃u���b�N�܂Ői�߂� */
					if((stim.pmode>>3)&0x01)
					{	/* CLUT������Γ]�� */
						adr += stim.cw*stim.ch +6;
					}
					break;
				case CLT_HEADER:
					clt_sw=1;
					adr += 6;		/* (id,flg,bnum)�̃X�L�b�v(12byte) */
					adr++;
					adr++;
					rct.w = *adr;
					adr++;
					rct.h = *adr;
					adr++;
				//	LoadImage(&rct,(u_long *)adr);
				//	while(DrawSync(1)!=0);
					adr += rct.w*rct.h;
				break;
				default:
					return;
			}
		}
	}
	do{
		switch(*adr){
			case TIM_HEADER:
				adr+=2;	/* �w�b�_�̃X�L�b�v(4byte) */
				GsGetTimInfo((u_long *)adr, &stim);
				adr += stim.pw*stim.ph +6+2;	/* ���̃u���b�N�܂Ői�߂� */

				rct.x=stim.px;

				rct.y=stim.py;
				rct.w=stim.pw;
				rct.h=stim.ph;
				LoadImage(&rct,stim.pixel);
				if((stim.pmode>>3)&0x01)
				{	/* CLUT������Γ]�� */
					rct.x=stim.cx;
					rct.y=stim.cy;
					rct.w=stim.cw;
					rct.h=stim.ch;
					LoadImage(&rct,stim.clut);
					while(DrawSync(1)!=0);
					adr += stim.cw*stim.ch +6;
				}
				break;
			case CLT_HEADER:
				clt_sw=1;
			case PXL_HEADER:
				adr += 6;		/* (id,flg,bnum)�̃X�L�b�v(12byte) */
				rct.x = *adr;
				adr++;
				rct.y = *adr;
				clt_sw=0;
				adr++;
				rct.w = *adr;
				adr++;
				rct.h = *adr;
				adr++;
				LoadImage(&rct,(u_long *)adr);
				while(DrawSync(1)!=0);
				adr += rct.w*rct.h;
				break;
			default:
				return;
		}
	}while(load_type==0);
}




