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
mkdir release_libic\x64
mkdir release_libic\kernel
mkdir release_libic\kernel\warrior
mkdir release_libic\kernel\paladin
mkdir release_libic\include

:: Nolib release.
xcopy profile release_nolib\profile /I
copy irecore.exe release_nolib\irecore.exe
copy irecrash\irecrash.exe release_nolib\irecrash.exe
copy kernel\kernel.c release_nolib\kernel\kernel.c
copy kernel\entry.c release_nolib\kernel\entry.c
copy kernel\common.c release_nolib\kernel\common.c
copy kernel\warrior\warrior.c release_nolib\kernel\warrior\warrior.c
copy kernel\warrior\arms.c release_nolib\kernel\warrior\arms.c
copy kernel\warrior\fury.c release_nolib\kernel\warrior\fury.c
copy kernel\paladin\paladin.c release_nolib\kernel\paladin\paladin.c
copy kernel\paladin\retribution.c release_nolib\kernel\paladin\retribution.c
copy ic\gic_zh.qm release_nolib\gic_zh.qm
copy irecrash\icc_zh.qm release_nolib\icc_zh.qm
copy LICENSE release_nolib\LICENSE

:: Normal release.
xcopy profile release\profile /I
copy irecore.exe release\irecore.exe
copy irecrash\irecrash.exe release\irecrash.exe
copy kernel\kernel.c release\kernel\kernel.c
copy kernel\entry.c release\kernel\entry.c
copy kernel\common.c release\kernel\common.c
copy kernel\warrior\warrior.c release\kernel\warrior\warrior.c
copy kernel\warrior\arms.c release\kernel\warrior\arms.c
copy kernel\warrior\fury.c release\kernel\warrior\fury.c
copy kernel\paladin\paladin.c release\kernel\paladin\paladin.c
copy kernel\paladin\retribution.c release\kernel\paladin\retribution.c
copy ic\gic_zh.qm release\gic_zh.qm
copy irecrash\icc_zh.qm release\icc_zh.qm
copy LICENSE release\LICENSE

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
copy libic\Win32\libic.lib release_libic\Win32\libic.lib
copy libic\x64\libic.lib release_libic\x64\libic.lib