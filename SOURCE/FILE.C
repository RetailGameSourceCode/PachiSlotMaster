//=============================================================
//  読み込みファイル情報
//
//=============================================================
#include "common.h"

#if READ_MODE == 2
/*=============================================================
	ＤＯＳのファイルから読むためのデータ
=============================================================	*/
FILE_INFO fileinfo[] = {
	{"C:\\SLOT\\DATA\\SELECT\\SELS.TIM"},	// 周辺画面用 
	{"C:\\SLOT\\DATA\\SUBMENU\\SUBM.TIM"},	// サブメニュー用 

	{"C:\\SLOT\\DATA\\FONT\\FONT.TIM"},		/*	フォント	*/
	{"C:\\SLOT\\DATA\\BASE\\KAP_A.TIC"},
	{"C:\\SLOT\\DATA\\BASE\\BIN_A.TIC"},
	{"C:\\SLOT\\DATA\\SOUND\\KAPS.TIC"},
	{"C:\\SLOT\\DATA\\SOUND\\BINS.TIC"},

	{"C:\\SLOT\\DATA\\SOUND\\K_SELECT.VB"},
	{"C:\\SLOT\\DATA\\SOUND\\K_SELECT.VH"},
	{"C:\\SLOT\\DATA\\SOUND\\K_SELECT.SEQ"},

	{"C:\\SLOT\\DATA\\SOUND\\OPENING.VB"},
	{"C:\\SLOT\\DATA\\SOUND\\OPENING.VH"},
	{"C:\\SLOT\\DATA\\SOUND\\OPENING.SEQ"},
};
#endif

#if READ_MODE == 1
//=============================================================
//ＣＤからファイル名で読むためのデータ
//=============================================================
FILE_INFO fileinfo[] = {
};

#endif

#if READ_MODE == 0
//=============================================================
//ＣＤから絶対セクタで読むためのデータ
//=============================================================
FILE_INFO fileinfo[] =
{
	{SELS_TIM,SELS_TIM_SZ},	// 周辺画面用 
	{SUBM_TIM,SUBM_TIM_SZ},	// サブメニュー用 
	{FONT_TIM,FONT_TIM_SZ},
	{KAP_A_TIC ,KAP_A_TIC_SZ },
	{BIN_A_TIC ,BIN_A_TIC_SZ },
	{KAPS_TIC ,KAPS_TIC_SZ },
	{BINS_TIC ,BINS_TIC_SZ },

	{K_SELECT_VB ,K_SELECT_VB_SZ },
	{K_SELECT_VH ,K_SELECT_VH_SZ },
	{K_SELECT_SEQ ,K_SELECT_SEQ_SZ },

	{OPENING_VB ,OPENING_VB_SZ },
	{OPENING_VH ,OPENING_VH_SZ },
	{OPENING_SEQ ,OPENING_SEQ_SZ },

};

#endif





