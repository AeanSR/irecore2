/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "libic_internal.h"

const int base10[] = { 1000000, 100000, 10000, 1000, 100, 10, 1 };
#define TALENT_TIER(tier) ((talent / base10[tier - 1]) % 10)

config_t& config(){
    static config_t c;
    return c;
}
