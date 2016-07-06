call pack_release.bat

:: Update the qt_dir as necessary
set qt_dir=E:\Qt\5.7\msvc2015

copy "%VS140COMNTOOLS%..\..\VC\redist\x86\Microsoft.VC140.CRT"\vcruntime140.dll release\vcruntime140.dll
copy "%VS140COMNTOOLS%..\..\VC\redist\x86\Microsoft.VC140.CRT"\msvcp140.dll release\msvcp140.dll
copy %qt_dir%\bin\Qt5Core.dll release\Qt5Core.dll
copy %qt_dir%\bin\Qt5GUI.dll release\Qt5GUI.dll
copy %qt_dir%\bin\Qt5Widgets.dll release\Qt5Widgets.dll
copy %qt_dir%\bin\Qt5Network.dll release\Qt5Network.dll
copy %qt_dir%\bin\Qt5PrintSupport.dll release\Qt5PrintSupport.dll
copy %qt_dir%\plugins\platforms\qwindows.dll release\platforms\qwindows.dll
copy lua\lua53.dll release\lua53.dll
copy %windir%\SYSWOW64\ssleay32.dll release\ssleay32.dll
copy %windir%\SYSWOW64\libeay32.dll release\libeay32.dll
copy irecrash\SMTPEmail\SMTPEmail.dll release\SMTPEmail.dll