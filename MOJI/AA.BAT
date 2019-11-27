copy %1.txt work
cd work
call zen1.bat %1
call zen2.bat %1
call zen3.bat %1
call jis2tim.bat %1
copy ___%1.txt ..
cd..
ftdt ___%1.txt %1.txt %1.bin %1.h
copy %1.bin ..\mastdata\first
copy %1.h ..\source\MOJI.H
