:: Update the qt_dir as necessary
set qt_dir=E:\Qt\5.5\msvc2013

rd /S /Q release
rd /S /Q release_nolib
mkdir release
mkdir release\profile
mkdir release\platforms
mkdir release_nolib
mkdir release_nolib\profile

:: Nolib release.
xcopy profile release_nolib\profile /I
copy irecore.exe release_nolib\irecore.exe
copy kernel.c release_nolib\kernel.c
copy ic\gic_zh.qm release_nolib\gic_zh.qm
copy LICENSE release_nolib\LICENSE
copy lua\lua53.dll release_nolib\lua53.dll
copy %windir%\SYSWOW64\ssleay32.dll release_nolib\ssleay32.dll
copy %windir%\SYSWOW64\libeay32.dll release_nolib\libeay32.dll

:: Normal release.
xcopy profile release\profile /I
copy irecore.exe release\irecore.exe
copy kernel.c release\kernel.c
copy ic\gic_zh.qm release\gic_zh.qm
copy LICENSE release\LICENSE
copy %windir%\SYSWOW64\msvcr120.dll release\msvcr120.dll
copy %windir%\SYSWOW64\msvcp120.dll release\msvcp120.dll
copy %qt_dir%\bin\Qt5Core.dll release\Qt5Core.dll
copy %qt_dir%\bin\Qt5GUI.dll release\Qt5GUI.dll
copy %qt_dir%\bin\Qt5Widgets.dll release\Qt5Widgets.dll
copy %qt_dir%\bin\Qt5Network.dll release\Qt5Network.dll
copy %qt_dir%\plugins\platforms\qwindows.dll release\platforms\qwindows.dll
copy lua\lua53.dll release\lua53.dll
copy %windir%\SYSWOW64\ssleay32.dll release\ssleay32.dll
copy %windir%\SYSWOW64\libeay32.dll release\libeay32.dll
:: ICU is no longer needed since irecore-620-50?
:: copy %qt_dir%\bin\icuin53.dll release\icuin53.dll
:: copy %qt_dir%\bin\icuuc53.dll release\icuuc53.dll
:: copy icudt53_min.dll release\icudt53.dll