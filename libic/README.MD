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
  <tr><td>raidbuff_vers</td><td>integer</td><td>1</td><td>raid buff Versatility, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_sta</td><td>integer</td><td>0</td><td>raid buff Stamina, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_flask</td><td>integer</td><td>0</td><td>use flask(+250 str), 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_food</td><td>integer</td><td>0</td><td>use food(+125 crit rate), 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_potion</td><td>integer</td><td>0</td><td>use potion(+1000 str, twice), 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_bloodlust</td><td>integer</td><td>0</td><td>affected by bloodlust, 0 if down, non-zero if up</td></tr>
  <tr><td>raidbuff_all</td><td>integer</td><td></td><td>toggle all raidbuff parameters(except vers, vers will be set to 1)</td></tr>
  <tr><td>actions</td><td>string</td><td>empty string</td><td>action priority list(irecore style)</td></tr>
  <tr><td>simc_actions</td><td>string</td><td>empty string</td><td>action priority list(simc style)</td></tr>
  </table>
  
`actions` could be set cumulatively by key `actions+`, to append the string. similarly `simc_actions` could be set by `simc_actions+`.

`actions` will be suppressed by `simc_actions` if the latter one is set non empty. both `actions` and `simc_actions` will be suppressed by `default_actions`.

`simc_actions` should contains the key prefix "actions=" or "actions.xxx=", so when set via text configuration interface, we write something like below

    simc_actions=actions=auto_attack
    simc_actions+=actions.single_target+=/bloodthirst,if=...

it looks weired but that is the only way we could process the simc sub action list.

  <table>
  <tr><td>key</td><td>value type</td><td>default</td><td>description</td></tr>
  <tr><td>default_actions</td><td>integer</td><td>0</td><td>use default apl if set non-zero</td></tr>
  <tr><td>vary_combat_length</td><td>real</td><td>20.0</td><td>combat length max variation(%)</td></tr>
  <tr><td>max_length</td><td>real</td><td>450.0</td><td>combat length(seconds)</td></tr>
  <tr><td>initial_health_percentage</td><td>real</td><td>100.0</td><td>initial health percentage of the enemy</td></tr>
  <tr><td>death_pct</td><td>real</td><td>0.0</td><td>death health percentage of the enemy</td></tr>
  <tr><td>rage_max</td><td>real</td><td>100.0</td><td>rage max limit</td></tr>
  <tr><td>num_enemies</td><td>integer</td><td>1</td><td>count of enemies, ranges from 1 to 20</td></tr>
  <tr><td>glyph_of_ragingwind</td><td>integer</td><td>0</td><td>use glyph of ragingwind or not</td></tr>
  <tr><td>plate_specialization</td><td>integer</td><td>0</td><td>if all armors are plate or not</td></tr>
  <tr><td>race</td><td>string</td><td>none</td><td>one of the listed:
  human,dwarf,gnome,nightelf_day,nightelf_night,draenei,worgen,
  orc,troll,tauren,undead,bloodelf,goblin,pandaren</td></tr>
  <tr><td>mh_speed</td><td>real</td><td>1.5</td><td>main hand weapon speed</td></tr>
  <tr><td>oh_speed</td><td>real</td><td>1.5</td><td>off hand weapon speed</td></tr>
  <tr><td>mh_low</td><td>integer</td><td>0</td><td>main hand weapon damage lower bound</td></tr>
  <tr><td>oh_low</td><td>integer</td><td>0</td><td>off hand weapon damage lower bound</td></tr>
  <tr><td>mh_high</td><td>integer</td><td>0</td><td>main hand weapon damage higher bound</td></tr>
  <tr><td>oh_high</td><td>integer</td><td>0</td><td>off hand weapon damage higher bound</td></tr>
  <tr><td>mh_type</td><td>string</td><td>dagger</td><td>main hand weapon type, one of the listed:
  2h,1h,dagger</td></tr>
  <tr><td>oh_type</td><td>string</td><td>dagger</td><td>off hand weapon type, one of the listed:
  2h,1h,dagger</td></tr>
  <tr><td>mh_enchant</td><td>string</td><td>none</td><td>main hand weapon enchantment, one of the listed:
  none,thunderlord,bleedinghollow,shatteredhand</td></tr>
  <tr><td>oh_enchant</td><td>string</td><td>none</td><td>off hand weapon enchantment, one of the listed:
  none,thunderlord,bleedinghollow,shatteredhand</td></tr>
  <tr><td>talent</td><td>integer(7digit)</td><td>0000000</td><td>a 7-digit number, each digit specifies a talent tier(tier 1 ~ 7 from left to right)
  0: not selected
  1: left
  2: middle
  3: right</td></tr>
  <tr><td>archmages_incandescence</td><td>integer</td><td>0</td><td>use 690 legendary ring or not</td></tr>
  <tr><td>archmages_greater_incandescence</td><td>integer</td><td>0</td><td>use 715 legendary ring or not</td></tr>
  <tr><td>legendary_ring</td><td>integer</td><td>0</td><td>the itemlvl of thorasus, 0 if not used</td></tr>
  <tr><td>t17_2pc</td><td>integer</td><td>0</td><td>tier 17 2-pieces special</td></tr>
  <tr><td>t17_4pc</td><td>integer</td><td>0</td><td>tier 17 4-pieces special</td></tr>
  <tr><td>t18_2pc</td><td>integer</td><td>0</td><td>tier 18 2-pieces special</td></tr>
  <tr><td>t18_4pc</td><td>integer</td><td>0</td><td>tier 18 4-pieces special</td></tr>
  <tr><td>trinket1</td><td>string</td><td>none</td><td>first trinket, one of the listed:
none
vial_of_convulsive_shadows
forgemasters_insignia
horn_of_screaming_spirits
scabbard_of_kyanos
badge_of_victory
insignia_of_victory
tectus_beating_heart
formidable_fang
draenic_stone
skull_of_war
mote_of_the_mountain
worldbreakers_resolve
discordant_chorus
empty_drinking_horn
unending_hunger
spores_of_alacrity
bonemaws_big_toe
emberscale_talisman
gronntooth_war_horn</td></tr>
  <tr><td>rng_engine</td><td>string</td><td>lcg32</td><td>rng engine to use, one of the listed:
  mt127
mwc64x
lcg32</td></tr>
  <tr><td>trinket2</td><td>string</td><td>none</td><td>second trinket, same options as `trinket1`</td></tr>
  <tr><td>trinket1_ilvl</td><td>integer</td><td>0</td><td>the itemlvl of first trinket</td></tr>
  <tr><td>trinket2_ilvl</td><td>integer</td><td>0</td><td>the itemlvl of second trinket</td></tr>
  <tr><td>enemy_is_demonic</td><td>integer</td><td>0</td><td>enemy is demonic or not</td></tr>
  <tr><td>strict_gcd</td><td>integer</td><td>1</td><td>strict actions to perform synchornized with general cooldown, to boost the sim performance</td></tr>
  <tr><td>wbr_never_expire</td><td>integer</td><td>1</td><td>assume worldbreaker's resolve never expire, to boost the sim performance</td></tr>
  <tr><td>sync_melee</td><td>integer</td><td>1</td><td>start both hand's wielding simultaneously, to boost the sim performance</td></tr>
  <tr><td>avatar_like_bloodbath</td><td>integer</td><td>0</td><td>treat bloodbath as instantly 30% dmg increase, to boost the sim performance</td></tr>
  <tr><td>output</td><td>string</td><td></td><td>save output informations into a file, specify a file name.</td></tr>
  <tr><td>opencl_device_id</td><td>integer</td><td>0</td><td>to specify which opencl device to use.</td></tr>
  </table>
  
### ic_getparam

    IC_API const char* ic_getparam(const char* key)

param: key name as c string.

return: current value of key as c string.

get current parameter value of key. see `ic_setparam` for parameter list.

if you set value by `ic_setparam` then read that value by `ic_getparam` instantly, the string format may be slightly changed, and the value may be adjusted if it was not appropriate.

(the parameter `output` is not readable. all accumulative parameter is not readable.)

### ic_resetparam

    IC_API void ic_resetparam(void)

param: none

return: none

reset all parameters to default.

(the parameter `output` is not affected.)

### ic_defaultapl

    IC_API const char* ic_defaultapl(void)

param: none

return: a c string containing an irecore style apl.

the apl is generated to fit current sim parameters. the returned apl is not set to the parameter `actions`. you should set it by `ic_setparam` explicitly on demand.

### ic_apltranslate_s

    IC_API const char* ic_apltranslate_s(const char* simc_style)

param: a c string containing a simc style apl.

return a c string containing an irecore style apl.

the input string should have the same format as simc text configuration file. the text of a simc preset profile is suitable for input.

### ic_apltranslate_f

    IC_API const char* ic_apltranslate_f(const char* filename);

param: a c string containing a file name.

return: a c string containing an irecore style apl.

the input file should have the same format as simc text configuration file. a simc preset profile is suitable for input.

### ic_runsim

    IC_API int ic_runsim(float* dps, float* dpsr, float* dpse)

param: three pointers to float, to recieve statistic result.

  * `dps` - mean dps
  * `dpsr` - dps standard variation
  * `dpse` - dps error (95% confident level)

return: `-1` if error occured, `0` if successed.

if any of `dps` `dpsr` `dpse` is not required, just give null pointer and it will be ignored.

