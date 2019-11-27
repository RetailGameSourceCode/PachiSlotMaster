/*=============================================================
 *	ＣＤからデータを読みます
 *
 *=============================================================*/

#include "common.h"
#include "work.h"

#if	DEBUG_MODE==1

#define	NopERR	0
#define	NopELS	1
#define	LocERR	2
#define	LocELS	3
#define	ReadNG	4
#define	ReadERR	5
#define	CDDEF	6

#endif

#define CDREAD_MAX 16	/*ネストは１６*/

int	cd_err[8];	/*ＣＤリードエラー*/

/**************************************************
*	ＣＤリード
***************************************************/
/*
*	WAIT対応ＣＤリード
*/
typedef struct{
	CdlLOC	pos;	/*開始セクタ位置	*/
	int sectors;	/*読み込みセクタ数	*/
	u_long *buf;	/*読み込みバッファ	*/
	char mode;		/*0:READ 1:SEEK*/
}CDREAD_FACTOR;
static CDREAD_FACTOR cdrfac[CDREAD_MAX];	/*cd_read_fastで参照する変数*/
int	read_stat;			/*cd_read_fastの処理状態(1:read go 0:NOP)*/
int read_que;
int next_que;


/*=============================================================
 *	ＣＤからデータを読みます
 *	CdControlF()を使用したバックグラウンドデータリード
 *	（ＷＡＩＴ関数に入れる）
 *
 *	(IN)	CDREAD_FACTOR	cdrfac[]　に情報がセットされていること
 *
 *=============================================================*/
void cd_read_fast(void)
{
	int	ret;
	u_char result[8];	/*最も最近に終了したコマンドのステータス*/

#if	DEBUG_MODE==1
/*
	FntPrint("read_stat(%d)\n",read_stat);
	FntPrint("NopERR(%d)\n",cd_err[NopERR]);
	FntPrint("NopELS(%d)\n",cd_err[NopELS]);
	FntPrint("LocERR(%d)\n",cd_err[LocERR]);
	FntPrint("LocELS(%d)\n",cd_err[LocELS]);
	FntPrint("ReadNG(%d)\n",cd_err[ReadNG]);
	FntPrint("ReadERR(%d)\n",cd_err[ReadERR]);
	FntPrint("CDDEF(%d)\n",cd_err[CDDEF]);
*/
#endif
	switch (read_stat) {
		case	0 :		/* 何もしていない状態 */
			break;
		case	1 :		/* 今の状態を見る */
			CdControlF(CdlNop, 0);
			read_stat++;
			break;
		case	2:		/*CdlCompleteになるのを待つ*/
			if ((ret = CdSync(1, result)) == CdlComplete) {
				read_stat++;
			}
			else if(ret == CdlDiskError){
				read_stat = 1;	/*戻る*/
#if DEBUG_MODE==1
				cd_err[NopERR]++;	/*Nop ERR*/
#endif
			}
			else{
				;
#if DEBUG_MODE==1
				cd_err[NopELS]++;	/*Nop ELS*/
#endif
			}
			break;
		case	3 :		/* コマンド：シークのターゲット位置を設定 */
			CdControlF(CdlSetloc, (u_char *)&cdrfac[read_que].pos);
			read_stat++;
			break;
		case	4 :		/* ＷＡＩＴ：ヘッド移動 */
			if ((ret = CdSync(1, result)) == CdlComplete) {
				if(cdrfac[read_que].mode){
					cdrfac[read_que].buf = NULL;
					read_que = (read_que+1)&0x0f;	/*ＱＵＥぽいんたを次に*/
					if(cdrfac[read_que].buf == NULL)
					{
						read_stat = 0;		/* 終了 ＮＯＰ状態に戻す */
					}
					else
					{
						read_stat = 1;		/* 別のデータをリード */
					}
				}else{
					read_stat++;
				}
			}
			else if (ret == CdlDiskError) {
				read_stat = 1;	/*戻る*/
#if DEBUG_MODE==1
				cd_err[LocERR]++;	/*Loc ERR*/
#endif
			}
			else{
				;
#if DEBUG_MODE==1
				cd_err[LocELS]++;	/*Loc ELS*/
#endif
			}
			break;
		case	5 :		/* コマンド：データリード */
			if (CdRead(cdrfac[read_que].sectors,cdrfac[read_que].buf,CdlModeSpeed) == 0) {
				/*CdlSetlocでの設定は、リードの実行によりキャンセルされる*/
				/*リード中にエラーが発生した場合正常なリトライは望めないので*/
				/*先頭からの処理に戻す(10/01)*/
				read_stat = 1;	/*戻る*/
#if DEBUG_MODE==1
				cd_err[ReadNG]++;	/*Read NG*/
#endif
			}
			else {
				read_stat++;
			}
			break;
		case	6 :		/* ＷＡＩＴ	：データリード */
			if ((ret = CdReadSync(1, result)) == 0) {
				cdrfac[read_que].buf = NULL;
				read_que = (read_que+1)&0x0f;	/*ＱＵＥぽいんたを次に*/
				if(cdrfac[read_que].buf == NULL)
				{
					read_stat = 0;		/* 終了 ＮＯＰ状態に戻す */
				}
				else
				{
					read_stat = 1;		/* 別のデータをリード */
				}
			}
			else if (ret == -1) {	/*リードエラー*/
				read_stat = 1;
#if DEBUG_MODE==1
				cd_err[ReadERR]++;	/*Read ERR*/
#endif
			}
			break;
		default :
#if DEBUG_MODE==1
			cd_err[CDDEF]++;	/*CD DEF*/
#endif
			break;
	}
	return;
}


/*=============================================================
 *	ファイルをＣＤからリードしてメモリ上に配置します
 *	読み込みが終わるまでブロックします（待ちます）
 *
 *in:
 *	enum fnum file	ファイル情報構造体id
 *	void *radr		読み込みメインメモリアドレス
 *					読み込みはセクタ単位で行われるのでセクタの倍数分
 *					(2048byte(0x800)の倍数)確保しておいてください
 *					NULLなら内部でmallocして、メモリを割り当てます
 *out:
 *	void *			読み込んだメモリのトップアドレス
 *
 *=============================================================*/
void *datafile_read(enum fnum file, void *radr)
{
	radr = cdread(file,radr);
	cdread_wait();
	return radr;
}


/*=============================================================
 *	ファイルをＣＤからリードしてメモリ上に配置します
 *	読み込みが終わるまで待たずにリターンします
 *	読み込みの終了は cdread_wait() で待ちます
 *	続けて１６ファイルまで一度にエントリーできます
 *
 *in:
 *	enum fnum file	ファイル情報構造体id
 *	void *radr		読み込みメインメモリアドレス
 *					読み込みはセクタ単位で行われるのでセクタの倍数分
 *					(2048byte(0x800)の倍数)確保しておいてください
 *					NULLなら内部でmallocして、メモリを割り当てます
 *out:
 *	void *			読み込んだメモリのトップアドレス
 *
 *=============================================================*/
void *cdread(enum fnum file, void *radr)
{

#if READ_MODE==2
//	xa_stop(1);
	radr = PCfileread(fileinfo[file].fname,radr);
	return radr;
#endif

#if READ_MODE==1
	CdlFILE finfo;	/*ファイル情報*/
	CdlFILE *rinf;
#endif

	while(cdrfac[next_que].buf != NULL){
		cdread_wait();			/*もうＱＵＥが一杯なら待つ*/
	}
//	xa_stop(1);

#if READ_MODE==1
	/* ファイル名でシーク */
	do{
		rinf = CdSearchFile( &finfo, fileinfo[file].fname );
	}while((rinf==0) || (rinf==-1));

	cdrfac[next_que].sectors = (finfo.size + 2047) / 2048;	/* 読み込みセクタ数 */
	cdrfac[next_que].pos = finfo.pos;						/* 開始セクタ位置   */
	if(radr == NULL){
		radr = memalloc((finfo.size+2047)&0xfffff800, (void**)&radr);
	}
#endif

#if READ_MODE==0
	/*絶対位置でシーク*/
	cdrfac[next_que].sectors = (fileinfo[file].size + 2047) / 2048;	/*読み込みセクタ数*/
	CdIntToPos(fileinfo[file].fpos, &cdrfac[next_que].pos);	/*分：秒：セクタ取得*/
	if(radr == NULL){
		radr = memalloc((fileinfo[file].size+2047)&0xfffff800, (void**)&radr);
	}
#endif
	cdrfac[next_que].buf = radr;	/* 読み込みバッファ */
	cdrfac[next_que].mode = 0;	/* 読み込みモード */
	read_stat = 1;					/* ＣＤからのリードをリクエスト */

	next_que = (next_que+1)&0x0f;	/*ＱＵＥぽいんたを次に*/

	return radr;
}


void *cdseek(enum fnum file, void *radr)
{

#if READ_MODE==2
//	xa_stop(1);
//	radr = PCfileread(fileinfo[file].fname,radr);
//	return radr;
#endif

#if READ_MODE==1
	CdlFILE finfo;	/*ファイル情報*/
	CdlFILE *rinf;
#endif

	while(cdrfac[next_que].buf != NULL){
		cdread_wait();			/*もうＱＵＥが一杯なら待つ*/
	}
//	xa_stop(1);

#if READ_MODE==1
	/* ファイル名でシーク */
	do{
		rinf = CdSearchFile( &finfo, fileinfo[file].fname );
	}while((rinf==0) || (rinf==-1));

	cdrfac[next_que].sectors = (finfo.size + 2047) / 2048;	/* 読み込みセクタ数 */
	cdrfac[next_que].pos = finfo.pos;						/* 開始セクタ位置   */
	if(radr == NULL){
		radr = memalloc((finfo.size+2047)&0xfffff800, (void**)&radr);
	}
#endif

#if READ_MODE==0
	/*絶対位置でシーク*/
	cdrfac[next_que].sectors = (fileinfo[file].size + 2047) / 2048;	/*読み込みセクタ数*/
	CdIntToPos(fileinfo[file].fpos, &cdrfac[next_que].pos);	/*分：秒：セクタ取得*/
	if(radr == NULL){
		radr = memalloc((fileinfo[file].size+2047)&0xfffff800, (void**)&radr);
	}
#endif
	cdrfac[next_que].buf = radr;	/* 読み込みバッファ */
	cdrfac[next_que].mode = 1;	/* シークモード */
	read_stat = 1;					/* ＣＤからのリードをリクエスト */

	next_que = (next_que+1)&0x0f;	/*ＱＵＥぽいんたを次に*/

	return radr;
}




/*=============================================================
 *	ＣＤからのリードが終了するまで待ちます
 *
 *in:
 *	void
 *out:
 *	void
 *
 *=============================================================*/
void cdread_wait(void)
{
	/*読み込み終了まで待つ*/
	while(read_stat != 0){
		wait(1);	/*この中のcd_read_fastで読み込まれる*/
	}
}

//	描き込みなしの待ち
void cdread_wait_nw(void)
{
	/*読み込み終了まで待つ*/
	while(read_stat != 0){
		wait_nw(1);	/*この中のcd_read_fastで読み込まれる*/
	}
}


/*=============================================================
 *	ＣＤリードの初期化をします
 *	すべてのＣＤリード前に呼ぶ
 *
 *in:
 *	void
 *out:
 *	void
 *
 *=============================================================*/
void cdread_init(void)
{
	int i;

	read_stat = 0;		/*cd_read_fastの処理状態(1:read go 0:NOP)*/
	read_que = 0;
	next_que = 0;
	for(i=0; i<CDREAD_MAX; i++){
		cdrfac[i].buf = NULL;
	}

#if DEBUG_MODE==1
	memset ( cd_err,0, sizeof(cd_err) );
#endif
}


/*=============================================================
 *	ＣＤからのリードが終了しているかチェックします
 *  外でウエイトする
 *in:
 *	void
 *out:
 *	int	:0=リード終了,1=リード中
 *
 *=============================================================*/
int cdread_stat(void)
{
	return((read_stat)? 1: 0);
}

