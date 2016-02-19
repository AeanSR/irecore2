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


IC_API const char* ic_getversion(void);
IC_API void ic_printbanner(void);

typedef int (__cdecl* ic_printcb_t)(const char * format, va_list arglist);
IC_API void ic_setprintcallback(ic_printcb_t cbf);

IC_API void ic_init(void);

IC_API int ic_devicecount(void);
IC_API int ic_deviceinfo(int id, const char** platform_name, const char** device_name);

IC_API void ic_setparam(const char* key, const char* value);
IC_API const char* ic_getparam(const char* key);
IC_API void ic_resetparam(void);

IC_API const char* ic_defaultapl(void);
IC_API const char* ic_apltranslate_s(const char* simc_style);
IC_API const char* ic_apltranslate_f(const char* filename);

IC_API int ic_runsim(float* dps, float* dpsr, float* dpse);
#endif