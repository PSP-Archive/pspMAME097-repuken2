
rem ���� mingw �� mame�����̓z�Ɠ����ł��B���� 'm68kmake.exe' ��(DJGPP �͎~�߂�) mame_mingw �ŃR���p�C�����Ă݂܂����B
rem �R���p�C���� �umy_ming.bat���v�i���̃t�@�C���j�ugcc -O1 m68kmake.c -o m68kmake���v �Ƒł��܂����B

rem �v�����X�W�̏ꍇwinbootdir�̕W���́AC:\WINDOWS�ł��B(OS����ꂽ�t�H���_��)

rem PATH=%winbootdir%;%winbootdir%\COMMAND;C:\DJGPP\BIN
rem DJGPP=c:\DJGPP\DJGPP.ENV

rem PATH=%winbootdir%;%winbootdir%\COMMAND;C:\MAMEDEV\mingw\BIN;C:\MAMEDEV\mingw\mingw32\bin;C:\DJGPP\BIN
set PATH=%winbootdir%;%winbootdir%\COMMAND;C:\mingw\BIN
set DJGPP=c:\DJGPP\DJGPP.ENV

