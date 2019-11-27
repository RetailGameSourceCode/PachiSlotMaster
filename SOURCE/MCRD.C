#include <libapi.h>
#include <sys/types.h>
#include <sys/file.h>
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>
#include <libmcrd.h>

#include "../inc/debug.h"
#include "../inc/macro.h"
#include "../inc/struct.h"
#include "../inc/global.h"

/*------------------------------------------------------------------------------*/
u_long			cmds;
u_long			result;
static u_long	cbcmds;
static u_long	cbresult;

static void SS_mcd_callback(unsigned long cmds, unsigned long result)
{
	cbcmds = cmds;
	cbresult = result;
}


/*------------------------------------------------------------------------------*/
/* メモリカードイニシャライズ */
void SS_mcd_init(void)
{
	MemCardInit(0);
	MemCardStart();
}


/*------------------------------------------------------------------------------*/
/* メモリカード終了 */
void SS_mcd_end(void)
{
	MemCardStop();
	MemCardEnd();
}


/*------------------------------------------------------------------------------*/
/* メモリカード状態 */
int SS_mcd_status(int mcp)
{
	int				r1, ret;

	MemCardAccept((mcp - 1) * 0x10);
	MemCardSync(0, &cmds, &result);
	r1 = result;
	switch(r1){
		case McErrNewCard:
			MemCardExist((mcp - 1) * 0x10);
			MemCardSync(0, &cmds, &result);
			ret = result;
		break;
		default:
			ret = r1;
		break;
	}
	return(ret);
}


/*------------------------------------------------------------------------------*/
/* メモリカード状態(ニューカードチェック) */
int SS_mcd_status2(int mcp, int mode)
{
	int				ret = 0;

	if(mode == 1){
		cbresult = 0;
		MemCardExist((mcp - 1) * 0x10);
		MemCardCallback(SS_mcd_callback);
	}
	else if(mode == 2){
		cbresult = 0;
		MemCardCallback(0);
	}
	else if(mode == 0){
		if(cbcmds == McFuncExist){
			ret = cbresult;
			cbresult = cbcmds = -1;
			MemCardExist((mcp - 1) * 0x10);
		}
	}

	return(ret);
}


/*------------------------------------------------------------------------------*/
/* メモリカードロード */
int SS_mcd_load(int mcp, char *name)
{
	int				r1, ret;

	MemCardExist((mcp - 1) * 0x10);
	MemCardSync(0, &cmds, &result);
	r1 = result;
	switch(r1){
		case McErrNone:
			MemCardReadFile((mcp - 1) * 0x10, name, (u_long *)SS_MCD_ADRS, 0, 0x2000);
			MemCardSync(0, &cmds, &result);
			ret = result;
		break;
		default:
			ret = r1;
		break;
	}
	return(ret);
}


/*------------------------------------------------------------------------------*/
/* メモリカードセーブ */
int SS_mcd_save(int mcp, char *name)
{
	int				r1, r2, r3, ret;

	MemCardExist((mcp - 1) * 0x10);
	MemCardSync(0, &cmds, &result);
	r1 = result;
	switch(r1){
		case McErrNone:
			MemCardWriteFile((mcp - 1) * 0x10, name, (u_long *)SS_MCD_ADRS, 0, 0x2000);
			MemCardSync(0, &cmds, &result);
			r2 = result;
			switch(r2){
				case McErrFileNotExist:		/* 新規 */
					r3 = MemCardCreateFile((mcp - 1) * 0x10, name, 1);
					switch(r3){
						case McErrNone:
							MemCardWriteFile((mcp - 1) * 0x10, name, (u_long *)SS_MCD_ADRS, 0, 0x2000);
							MemCardSync(0, &cmds, &result);
							ret = result;
						break;
						default:
							ret = r3;
						break;
					}
				break;
				default:
					ret = r2;
				break;
			}
		break;
		default:
			ret = r1;
		break;
	}
	return(ret);
}


/*------------------------------------------------------------------------------*/
/* メモリカードデリート */
int SS_mcd_delete(int mcp, char *name)
{
	int				r1, ret;

	MemCardExist((mcp - 1) * 0x10);
	MemCardSync(0, &cmds, &result);
	r1 = result;
	switch(r1){
		case McErrNone:
			MemCardDeleteFile((mcp - 1) * 0x10, name);
			MemCardSync(0, &cmds, &result);
			ret = result;
		break;
		default:
			ret = r1;
		break;
	}
	return(ret);
}


/*------------------------------------------------------------------------------*/
/* メモリカードフォーマット */
int SS_mcd_format(int mcp)
{
	int				r1, ret;

	MemCardExist((mcp - 1) * 0x10);
	MemCardSync(0, &cmds, &result);
	r1 = result;
	switch(r1){
		case McErrNone:
			MemCardFormat((mcp - 1) * 0x10);
			MemCardSync(0, &cmds, &result);
			ret = result;
		break;
		default:
			ret = r1;
		break;
	}
	return(ret);
}
