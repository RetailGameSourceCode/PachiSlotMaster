vabsplit BIN_SE.VAB
vabsplit KAP_SE.VAB
vabsplit SE.VAB
vabsplit K_SELECT.VAB
vabsplit OPENING.VAB

cd bin
vabsplit BINBIN.VAB
copy BINBIN.VB ..\BINBIN1.VB
copy BINBIN.VH ..\BINBIN1.VH
call aa.bat
cd..
cd kap
vabsplit KAPAPA.VAB
copy KAPAPA.VB ..\KAPAPA1.VB
copy KAPAPA.VH ..\KAPAPA1.VH
call aa.bat
cd..

combine BINS BINS.TIC > err1
combine KAPS KAPS.TIC > err2
combine TIT TITS.TIC > err3
combine SEL SELS.TIC > err4

copy BINS.TIC ..\..\data\sound
copy KAPS.TIC ..\..\data\sound
REM copy TITS.TIC ..\..\data\sound
REM copy SELS.TIC ..\..\data\sound
copy SE.VH ..\first
copy SE.VB ..\first

copy K_SELECT.VB ..\..\data\sound
copy K_SELECT.VH ..\..\data\sound
copy K_SELECT.SEQ ..\..\data\sound

copy OPENING.VB ..\..\data\sound
copy OPENING.VH ..\..\data\sound
copy OPENING.SEQ ..\..\data\sound

copy *.HD ..\..\source
