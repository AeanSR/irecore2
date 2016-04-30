:: Update the qt_dir as necessary
set qt_dir=E:\Qt\5.6\msvc2015

rd /S /Q release
rd /S /Q release_nolib
rd /S /Q release_libic
mkdir release
mkdir release\profile
mkdir release\kernel
mkdir release\kernel\warrior
mkdir release\kernel\paladin
mkdir release\platforms
mkdir release_nolib
mkdir release_nolib\kernel
mkdir release_nolib\kernel\warrior
mkdir release_nolib\kernel\paladin
mkdir release_nolib\profile
mkdir release_libic
mkdir release_libic\Win32
mkdir release_libic\kernel
mkdir release_libic\kernel\warrior
mkdir release_libic\kernel\paladin
mkdir release_libic\include

:: Nolib release.
xcopy profile release_nolib\profile /I
copy irecore.exe release_nolib\irecore.exe
copy kernel\kernel.c release_nolib\kernel\kernel.c
copy kernel\entry.c release_nolib\kernel\entry.c
copy kernel\common.c release_nolib\kernel\common.c
copy kernel\warrior\warrior.c release_nolib\kernel\warrior\warrior.c
copy kernel\warrior\arms.c release_nolib\kernel\warrior\arms.c
copy kernel\warrior\fury.c release_nolib\kernel\warrior\fury.c
copy kernel\paladin\paladin.c release_nolib\kernel\paladin\paladin.c
copy kernel\paladin\retribution.c release_nolib\kernel\paladin\retribution.c
copy ic\gic_zh.qm release_nolib\gic_zh.qm
copy LICENSE release_nolib\LICENSE

:: Normal release.
xcopy profile release\profile /I
copy irecore.exe release\irecore.exe
copy kernel\kernel.c release\kernel\kernel.c
copy kernel\entry.c release\kernel\entry.c
copy kernel\common.c release\kernel\common.c
copy kernel\warrior\warrior.c release\kernel\warrior\warrior.c
copy kernel\warrior\arms.c release\kernel\warrior\arms.c
copy kernel\warrior\fury.c release\kernel\warrior\fury.c
copy kernel\paladin\paladin.c release\kernel\paladin\paladin.c
copy kernel\paladin\retribution.c release\kernel\paladin\retribution.c
copy ic\gic_zh.qm release\gic_zh.qm
copy LICENSE release\LICENSE
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
copy kernel\entry.c release_libic\kernel\entry.c
copy kernel\common.c release_libic\kernel\common.c
copy kernel\warrior\warrior.c release_libic\kernel\warrior\warrior.c
copy kernel\warrior\arms.c release_libic\kernel\warrior\arms.c
copy kernel\warrior\fury.c release_libic\kernel\warrior\fury.c
copy kernel\paladin\paladin.c release_libic\kernel\paladin\paladin.c
copy kernel\paladin\retribution.c release_libic\kernel\paladin\retribution.c
copy libic\libic.lib release_libic\Win32\libic.lib