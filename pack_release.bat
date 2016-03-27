:: Update the qt_dir as necessary
set qt_dir=E:\Qt\5.5\msvc2013

rd /S /Q release
rd /S /Q release_nolib
rd /S /Q release_libic
mkdir release
mkdir release\profile
mkdir release\kernel
mkdir release\platforms
mkdir release_nolib
mkdir release_nolib\kernel
mkdir release_nolib\profile
mkdir release_libic
mkdir release_libic\Win32
mkdir release_libic\kernel
mkdir release_libic\include

:: Nolib release.
xcopy profile release_nolib\profile /I
copy irecore.exe release_nolib\irecore.exe
copy kernel\kernel.c release_nolib\kernel\kernel.c
copy kernel\warrior.c release_nolib\kernel\warrior.c
copy kernel\arms.c release_nolib\kernel\arms.c
copy kernel\fury.c release_nolib\kernel\fury.c
copy ic\gic_zh.qm release_nolib\gic_zh.qm
copy LICENSE release_nolib\LICENSE

:: Normal release.
xcopy profile release\profile /I
copy irecore.exe release\irecore.exe
copy kernel\kernel.c release\kernel\kernel.c
copy kernel\warrior.c release\kernel\warrior.c
copy kernel\arms.c release\kernel\arms.c
copy kernel\fury.c release\kernel\fury.c
copy ic\gic_zh.qm release\gic_zh.qm
copy LICENSE release\LICENSE
copy %windir%\SYSWOW64\msvcr120.dll release\msvcr120.dll
copy %windir%\SYSWOW64\msvcp120.dll release\msvcp120.dll
copy %qt_dir%\bin\Qt5Core.dll release\Qt5Core.dll
copy %qt_dir%\bin\Qt5GUI.dll release\Qt5GUI.dll
copy %qt_dir%\bin\Qt5Widgets.dll release\Qt5Widgets.dll
copy %qt_dir%\bin\Qt5Network.dll release\Qt5Network.dll
copy %qt_dir%\bin\Qt5PrintSupport.dll release\Qt5PrintSupport.dll
copy %qt_dir%\plugins\platforms\qwindows.dll release\platforms\qwindows.dll
copy lua\lua53.dll release\lua53.dll
copy %windir%\SYSWOW64\ssleay32.dll release\ssleay32.dll
copy %windir%\SYSWOW64\libeay32.dll release\libeay32.dll
copy qcplib\qcustomplot1.dll release\qcustomplot1.dll

:: libic release
copy libic\README.MD release_libic\README.MD
copy libic\LICENSE release_libic\LICENSE
copy libic\libic.h release_libic\include\libic.h
copy kernel\kernel.c release_libic\kernel\kernel.c
copy kernel\warrior.c release_libic\kernel\warrior.c
copy kernel\arms.c release_libic\kernel\arms.c
copy kernel\fury.c release_libic\kernel\fury.c
copy libic\libic.lib release_libic\Win32\libic.lib