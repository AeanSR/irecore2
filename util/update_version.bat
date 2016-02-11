echo #define GIT_VER     \> VersionNo.h
git describe --abbrev=0 --always --tags --dirty=-mod>> VersionNo.h
echo #define STR2(v) #v >> VersionNo.h
echo #define STR(v) STR2(v) >> VersionNo.h
echo #define STRFILEVER STR(GIT_VER) >> VersionNo.h 