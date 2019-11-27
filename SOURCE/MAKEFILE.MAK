#CC_SW = -O3 -Xn512 -c
CC_SW = -O2 -g -Xn512 -c -comments-c++
CC_SW0 = -O0 -g -Xn512 -c -comments-c++
CC_SW1 = -O1 -g -Xn512 -c -comments-c++
CC_SW3 = -O1 -g -Xn1024 -c -comments-c++

#all:
#	ccpsx -g -Xo$80010000 main.c -omain.cpe,main.sym
#	ccpsx -g -Xo$80010000 work.c -owork.o

OBJS =  obj\st.obj obj\main.obj obj\debug.obj obj\work.obj obj\sprite.obj \
	obj\init.obj obj\memory.obj obj\draw.obj obj\pad.obj obj\dosfile.obj \
	obj\file.obj obj\cdread.obj obj\func.obj obj\add.obj obj\sound.obj \
	obj\gameread.obj obj\game.obj obj\dobj.obj obj\hard.obj \
	obj\kapbin.obj obj\select.obj obj\kkffnt.obj obj\submenu.obj \
	obj\title.obj obj\window.obj obj\status.obj obj\toggles.obj \
	obj\hawk.obj obj\stream.obj obj\saveload.obj obj\unlock.obj \
	obj\detect.obj obj\cross.obj obj\reach.obj obj\flash.obj

COMMON_INC =	csw.h \
		cd.hd \
		first.hd \
		func.h \
		dosfile.h \
		draw.h \
		debug.h \
		typedef.h \
		sprite.h \
		memory.h \
		pad.h \
		file.h \
		cdread.h \
		add.h \
		init.h \
		sound.h \
		dobj.h \
		hard.h \
		game.h \
		kapbin.h \
		moji.h \
		gameread.h \
		savedata.h \
		saveload.h \
		teisu.h	\
		kawa.h

main.cpe : $(OBJS)
	psylink /n512 /c /m /v @linkfile.lnk,main.cpe,main.sym,main.map


obj\st.obj : st.c
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\main.obj : main.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\debug.obj : debug.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\dosfile.obj : dosfile.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\draw.obj : draw.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\sprite.obj : sprite.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\work.obj : work.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\init.obj : init.c common.h work.h first.hd $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\memory.obj : memory.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\pad.obj : pad.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\file.obj : file.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\cdread.obj : cdread.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\func.obj : func.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\add.obj : add.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\sound.obj : sound.c common.h work.h kaps.hd bins.hd \
				kapseq.hd binseq.hd $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\gameread.obj : gameread.c tmd1.h common.h work.h bin_a.hd bin_d.hd tmd1.h\
				$(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\game.obj : game.c tmd1.h common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\dobj.obj : dobj.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\hard.obj : hard.c common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\kapbin.obj : kapbin.c common.h work.h kapbin.h \
				 savedata.h sldata.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\select.obj : select.c select.h common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\kkffnt.obj : kkffnt.c kkffnt.h common.h work.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\title.obj : title.c title.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\window.obj : window.c window.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\submenu.obj : submenu.c window.h submenu.h $(COMMON_INC)
	ccpsx $(CC_SW0) $&.c -o obj\$&.obj

obj\status.obj : status.c submenu.h window.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\toggles.obj : toggles.c window.h submenu.h binreach.h kapreach.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\hawk.obj : hawk.c window.h submenu.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\stream.obj : stream.c $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\saveload.obj : saveload.c $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\unlock.obj : unlock.c window.h submenu.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\detect.obj : detect.c window.h submenu.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\cross.obj : cross.c window.h submenu.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\reach.obj : reach.c window.h submenu.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

obj\flash.obj : flash.c window.h submenu.h $(COMMON_INC)
	ccpsx $(CC_SW) $&.c -o obj\$&.obj

load:

#	pqbload ..\data\kkk.tim 80200000

