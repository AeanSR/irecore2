/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "auth.h"
#define MACROCAT( x, y ) MACROCAT1 ( x, y )
#define MACROCAT1( x, y ) x##y
#define SEED ((unsigned)(0x55555555 ^ ((((int)__TIME__[0] * 100) + ((int)__TIME__[1] * 10) + ((int)__TIME__[3] * 1)) * (((int)__TIME__[4] * 100) + ((int)__TIME__[6] * 10) + ((int)__TIME__[7] * 1)))))
#define REC(x) ((x) * 214013UL + 2531011UL)
#define RAND_0 REC(SEED)
#define RAND_1 REC(RAND_0)
#define RAND_2 REC(RAND_1)
#define RAND_3 REC(RAND_2)
#define RAND_4 REC(RAND_3)
#define RAND_5 REC(RAND_4)
#define RAND_6 REC(RAND_5)
#define RAND_7 REC(RAND_6)
#define RAND_8 REC(RAND_7)
#define RAND_9 REC(RAND_8)
#define RAND_10 REC(RAND_9)
#define RAND_11 REC(RAND_10)
#define RAND_12 REC(RAND_11)
#define RAND_13 REC(RAND_12)
#define RAND_14 REC(RAND_13)
#define RAND_15 REC(RAND_14)
#define RAND_16 REC(RAND_15)
#define RAND_17 REC(RAND_16)
#define RAND_18 REC(RAND_17)
#define RAND_19 REC(RAND_18)
#define RAND_20 REC(RAND_19)
#define RAND_21 REC(RAND_20)
#define RAND_22 REC(RAND_21)
#define RAND_23 REC(RAND_22)
#define RAND_24 REC(RAND_23)
#define RAND_25 REC(RAND_24)
#define RAND_26 REC(RAND_25)
#define RAND_27 REC(RAND_26)
#define RAND_28 REC(RAND_27)
#define RAND_29 REC(RAND_28)
#define RAND_30 REC(RAND_29)
#define RAND_31 REC(RAND_30)
#define RAND(n) (MACROCAT(RAND_, n)&0xFFUL)
#define MSTRLEN_APP(str) (str "\x20\x1f\x1e\x1d\x1c\x1b\x1a\x19\x18\x17\x16\x15\x14\x13\x12\x11\x10\xf\xe\xd\xc\xb\xa\x9\x8\x7\x6\x5\x4\x3\x2\x1")
#define MSTRLEN(str) ((int)(MSTRLEN_APP(str)[0x20]))
#define CH(str,n) ((str "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0")[n])
#define ENCH(str,n) (CH(str,n) ^ RAND(n))
#define ENCRYPT(str) {\
ENCH(str,0),ENCH(str,1),ENCH(str,2),ENCH(str,3),ENCH(str,4),\
ENCH(str,5),ENCH(str,6),ENCH(str,7),ENCH(str,8),ENCH(str,9),\
ENCH(str,10),ENCH(str,11),ENCH(str,12),ENCH(str,13),ENCH(str,14),\
ENCH(str,15),ENCH(str,16),ENCH(str,17),ENCH(str,18),ENCH(str,19),\
ENCH(str,20),ENCH(str,21),ENCH(str,22),ENCH(str,23),ENCH(str,24),\
ENCH(str,25),ENCH(str,26),ENCH(str,27),ENCH(str,28),ENCH(str,29),\
ENCH(str,30),ENCH(str,31)}
char decrypted[32];
char* SMTP_HOST(){
    const char encrypted[32] = ENCRYPT(ICC_SMTP_HOST);
    unsigned r = SEED;
    for (int i = 0; i < 32; i++){
        r = REC(r);
        int xorbase = r&0xFFUL;
        decrypted[i] = encrypted[i] ^ xorbase;
    }
    return decrypted;
}
char* SMTP_USER(){
    const char encrypted[32] = ENCRYPT(ICC_USER_NAME);
    unsigned r = SEED;
    for (int i = 0; i < 32; i++){
        r = REC(r);
        int xorbase = r&0xFFUL;
        decrypted[i] = encrypted[i] ^ xorbase;
    }
    return decrypted;
}
char* SMTP_PASS(){
    const char encrypted[32] = ENCRYPT(ICC_PASSWORD);
    unsigned r = SEED;
    for (int i = 0; i < 32; i++){
        r = REC(r);
        int xorbase = r&0xFFUL;
        decrypted[i] = encrypted[i] ^ xorbase;
    }
    return decrypted;
}

void STR_CLEAR(){
    for (int i = 0; i < 32; i++){
        decrypted[i] = 0;
    }
}