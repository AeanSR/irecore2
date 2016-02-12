/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "clic.h"

int clic_main(int argc, char *argv[])
{
    ic_init();
    ic_setprintcallback( &vprintf );
    ic_printbanner();
    return 0;
}