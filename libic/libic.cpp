/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
    */

#include "libic_internal.h"

const int base10[] = { 1000000, 100000, 10000, 1000, 100, 10, 1 };
#define TALENT_TIER(tier) ((config().talent / base10[tier - 1]) % 10)

config_t& config(){
    static config_t c;
    return c;
}

// print info via callback function.
int cbprintf(const char* format, ...){
    va_list vl;
    int ret;
    va_start(vl, format);
    ret = (*config().printcb)(format, vl);
    va_end(vl);
    return ret;
}

void ic_init(){
    if (!config().kernel_str){
        FILE* f = fopen("kernel.c", "rb");
        fseek(f, 0, SEEK_END);
        size_t tell = ftell(f);
        rewind(f);
        config().kernel_str = (char*)calloc(tell + 1, 1);
        fread(config().kernel_str, tell, 1, f);
        fclose(f);
    }
    
}

void ic_setprintcallback(printcb_t cbf){
    config().printcb = cbf;
}
