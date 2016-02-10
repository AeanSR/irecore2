/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#ifndef LIBIC_H_INCLUDED
#define LIBIC_H_INCLUDED

#include <cstdarg>

#ifndef IC_API
#ifdef __cplusplus
#define IC_API extern "C"
#else
#define IC_API extern
#endif
#endif

typedef int (__cdecl* printcb_t)(const char * a, va_list b);


#endif