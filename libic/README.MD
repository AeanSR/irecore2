# libic

this is a static library edition of irecore, to embed the simulator into your application.

opencl sdk is not required to build your application with libic. but to run your application with libic, an opencl runtime is required.

don't forget to put kernel source file `kernel.c` (at the root dir of this repo) under the same folder of your application executable.

## API

libic highly dependent static states which are shared between different threads. **no reentrant is guaranteed** for any interface!
  
if you call libic from multiple threads, make sure to protect interfaces with mutex lock!

### ic_getversion

    IC_API const char* ic_getversion(void)

param: none
  
return: a char ptr to a c string, which contains irecore version and compile date. e.g. `623-1 Feb 13 2016`

### ic_printbanner

    IC_API void ic_printbanner(void)
  
param: none
  
return: none
  
print a startup banner via print callback function(see below). the example banner:

    
    IreCore 623-1 Feb 13 2016
    Copyright (C) Aean(fhsvengetta@NGA) 2014-2016
    All rights reserved.
    
    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
    

### ic_setprintcallback

    IC_API void ic_setprintcallback(ic_printcb_t cbf)

param: a function pointer of print callback function
  
return: none
  
set print callback function. the prototype of a printcb is `int __cdecl foo(const char* format, va_list arglist)`, it should works as the cstdlib function `vprintf`.
  
when irecore wants to show some text info, it calls printcb instead of `vprintf`. so you could redirect the text output via manipulating printcb.

### ic_init

    IC_API void ic_init(void)
  
param: none
  
return: none
  
initialize irecore. read the kernel source from file, open the opencl context, and enumerate all available opencl devices.
  
if you do not call `ic_init` explicitly, the initialization will be done when you call `ic_runsim` the first time.
  
### ic_devicecount

    IC_API int ic_devicecount(void)
  
param: none
  
return: the count of available opencl devices.
  
only works when initialized. otherwise always return 0.
  
### ic_deviceinfo

    IC_API int ic_deviceinfo(int id, const char** platform_name, const char** device_name);
  
param:
  
  * `id` - number of the device to query.
  
  * `platform_name` - pointer of a `const char *`, recieve the pointer of a c string, which contains the platform name of the specified device.
  
  * `device_name` - pointer of a `const char *`, recieve the pointer of a c string, which contains the device name of the specified device.

return: `-1` if `id` is out of range. `0` otherwise.
  
if `platform_name` or `device_name` is not required, simply give a null pointer, it will be ignored.

### ic_setparam

    IC_API void ic_setparam(const char* key, const char* value)
  
param: key-value pair to set.
  
return: none
  
set a simulation parameter. `key` specifies what parameter to set, value is the new value, both is c string format.
  
  <table>
  <tr><td>key</td><td>value type</td><td>default</td><td>description</td></tr>
  <tr><td>gear_str</td><td>integer</td><td>0</td><td>gear stat: strength</td></tr>
  <tr><td>gear_crit</td><td>integer</td><td>0</td><td>gear stat: crit rate</td></tr>
  <tr><td>gear_mastery</td><td>integer</td><td>0</td><td>gear stat: mastery rate</td></tr>
  <tr><td>gear_haste</td><td>integer</td><td>0</td><td>gear stat: haste rate</td></tr>
  <tr><td>gear_mult</td><td>integer</td><td>0</td><td>gear stat: multistrike rate</td></tr>
  <tr><td>gear_vers</td><td>integer</td><td>0</td><td>gear stat: versatility rate</td></tr>
  </table>
  
these are gear stat parameters. append `+` or `-` to the key will set the accumulative stat value.
  
e.g. set `gear_str` as `3000`, then set `gear_str+` with a value `200`, the gear stat will be 3200.

  <table>
  <tr><td>key</td><td>value type</td><td>default</td><td>description</td></tr>
  <tr><td>deterministic_seed</td><td>integer</td><td>0</td><td>rng seed, 0 if not deterministic</td></tr>
  <tr><td>iterations</td><td>integer</td><td>50000</td><td>simulation iterations</td></tr>
  <tr><td>raidbuff_str</td><td>integer</td><td>0</td><td>raid buff StrAgiInt, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_ap</td><td>integer</td><td>0</td><td>raid buff Attack Power, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_sp</td><td>integer</td><td>0</td><td>raid buff Spell Power, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_crit</td><td>integer</td><td>0</td><td>raid buff Crit, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_mastery</td><td>integer</td><td>0</td><td>raid buff Mastery, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_haste</td><td>integer</td><td>0</td><td>raid buff Haste, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_mult</td><td>integer</td><td>0</td><td>raid buff Multistrike, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_vers</td><td>integer</td><td>0</td><td>raid buff Versatility, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_sta</td><td>integer</td><td>0</td><td>raid buff Stamina, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_flask</td><td>integer</td><td>0</td><td>use flask(+250 str), 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_food</td><td>integer</td><td>0</td><td>use food(+125 crit rate), 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_potion</td><td>integer</td><td>0</td><td>use potion(+1000 str, twice), 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_bloodlust</td><td>integer</td><td>0</td><td>affected by bloodlust, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_all</td><td>integer</td><td></td><td>toggle all raidbuff parameters(except vers, vers will be set to 1)</td></tr>
  <tr><td>actions</td><td>string</td><td>empty string</td><td>action priority list(irecore style)</td></tr>
  </table>
  
`actions` could be set cumulatively by key `actions+`, to append the string. `actions` will be suppressed by `default_actions`.

  <table>
  <tr><td>key</td><td>value type</td><td>default</td><td>description</td></tr>
  <tr><td>default_actions</td><td>integer</td><td>0</td><td>use default apl if set non-zero</td></tr>
  <tr><td>vary_combat_length</td><td>real</td><td>20.0</td><td>combat length max variation(%)</td></tr>
  <tr><td>max_length</td><td>real</td><td>450.0</td><td>combat length(seconds)</td></tr>
  <tr><td>initial_health_percentage</td><td>real</td><td>100.0</td><td>initial health percentage of the enemy</td></tr>
  <tr><td>death_pct</td><td>real</td><td>0.0</td><td>death health percentage of the enemy</td></tr>
  <tr><td>rage_max</td><td>real</td><td>100.0</td><td>rage max limit</td></tr>
  <tr><td>num_enemies</td><td>integer</td><td>1</td><td>count of enemies, ranges from 1 to 20</td></tr>
  
  </table>
  
