:: ugly batch + abuse of git commit count, but works great for me.

<NUL set /p=#define GIT_VER > VersionNo.h
for /f %%i in ('git describe --long --always --tags') do set TAGNAME=%%i
echo %TAGNAME:~0,-9% >> VersionNo.h
echo #define STR2(v) #v >> VersionNo.h
echo #define STR(v) STR2(v) >> VersionNo.h
echo #define STRFILEVER STR(GIT_VER) >> VersionNo.h 