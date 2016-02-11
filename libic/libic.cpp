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

char* exchbuf(){
    static char buf[1024];
    return buf;
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

// print into file.
int vofprintf(const char* a, va_list b){
    int ret = vfprintf(config().output_file, a, b);
    fflush(config().output_file);
    return ret;
}

// API: show version.
const char* ic_getversion(void){
    std::string verstr = STRFILEVER;
    verstr += " ";
    verstr += __DATE__;
    return verstr.c_str();
}

// API: show startup banner.
void ic_printbanner(void){
    cbprintf("\n"
        "IreCore %s\n"
        "Copyright (C) Aean(fhsvengetta@NGA) 2014-2016\n"
        "All rights reserved.\n"
        "\n"
        "IreCore is distributed under the terms of The MIT License.\n"
        "You should have received a copy of the MIT License along with this program.\n"
        "If not, see <http://opensource.org/licenses/mit-license.php>.\n"
        "\n", ic_getversion());
}

// API: set callback function for print.
void ic_setprintcallback(printcb_t cbf){
    config().printcb = cbf;
}


// API: initializer.
void ic_init(void){
    // Load kernel source
    if (!config().kernel_str){
        FILE* f = fopen("kernel.c", "rb");
        fseek(f, 0, SEEK_END);
        size_t tell = ftell(f);
        rewind(f);
        config().kernel_str = (char*)calloc(tell + 1, 1);
        fread(config().kernel_str, tell, 1, f);
        fclose(f);
    }
    // Lookup available devices.
    if (config().device_list.empty()){
        cl_int err;
        cl_uint num;
        std::vector<cl_platform_id> platforms;
        err = clGetPlatformIDs(0, 0, &num);
        if (err != CL_SUCCESS) {
            cbprintf("Unable to get platforms\n");
            abort();
        }
        platforms.resize(num);
        err = clGetPlatformIDs(num, &platforms[0], &num);
        if (err != CL_SUCCESS) {
            cbprintf("Unable to get platform ID\n");
            abort();
        }
        cl_uint device_counter = 0;
        for (size_t platform_id = 0; platform_id < num; platform_id++) {
            size_t dev_c, info_c;
            clGetPlatformInfo(platforms[platform_id], CL_PLATFORM_NAME, 0, NULL, &info_c);
            std::string platname;
            platname.resize(info_c);
            clGetPlatformInfo(platforms[platform_id], CL_PLATFORM_NAME, info_c, &platname[0], 0);

            cl_context_properties prop[] = { CL_CONTEXT_PLATFORM, reinterpret_cast<cl_context_properties>(platforms[platform_id]), 0 };
            cl_context context = clCreateContextFromType(prop, CL_DEVICE_TYPE_ALL, NULL, NULL, NULL);
            if (context == 0) {
                cbprintf("Can't create OpenCL context\n");
                abort();
            }
            clGetContextInfo(context, CL_CONTEXT_DEVICES, 0, NULL, &dev_c);
            std::vector<cl_device_id> devices(dev_c / sizeof(cl_device_id));
            clGetContextInfo(context, CL_CONTEXT_DEVICES, dev_c, &devices[0], 0);
            for (auto i = devices.begin(); i != devices.end(); i++) {
                clGetDeviceInfo(*i, CL_DEVICE_NAME, 0, NULL, &info_c);
                std::string devname;
                devname.resize(info_c);
                clGetDeviceInfo(*i, CL_DEVICE_NAME, info_c, &devname[0], 0);
                ic_computedevice_t icd;
                icd.device_id = i - devices.begin();
                icd.device_name = _strdup(devname.c_str());
                icd.platform_id = platform_id;
                icd.platform_name = _strdup(platname.c_str());
                icd.id = device_counter;
                config().device_list.push_back(icd);
                device_counter++;
            }
            clReleaseContext(context);
        }
    }
}

// API: get device count.
int ic_devicecount(void){
    return config().device_list.size();
}

// API: get device info.
int ic_deviceinfo(int id, const char** platform_name, const char** device_name){
    if (id >= static_cast<int>(config().device_list.size())){
        return -1;
    }
    if (platform_name){
        *platform_name = config().device_list[id].platform_name;
    }
    if (device_name){
        *device_name = config().device_list[id].device_name;
    }
    return 0;
}

// API: set parameters.
void ic_setparam(const char* key, const char* value) {
    if (0 == strcmp(key, "gear_str")) {
        config().gear_str = atoi(value);
        if (config().gear_str < 0) config().gear_str = 0;
    }
    else if (0 == strcmp(key, "gear_crit")) {
        config().gear_crit = atoi(value);
        if (config().gear_crit < 0) config().gear_crit = 0;
    }
    else if (0 == strcmp(key, "gear_mastery")) {
        config().gear_mastery = atoi(value);
        if (config().gear_mastery < 0) config().gear_mastery = 0;
    }
    else if (0 == strcmp(key, "gear_haste")) {
        config().gear_haste = atoi(value);
        if (config().gear_haste < 0) config().gear_haste = 0;
    }
    else if (0 == strcmp(key, "gear_mult")) {
        config().gear_mult = atoi(value);
        if (config().gear_mult < 0) config().gear_mult = 0;
    }
    else if (0 == strcmp(key, "gear_vers")) {
        config().gear_vers = atoi(value);
        if (config().gear_vers < 0) config().gear_vers = 0;
    }
    else if (0 == strcmp(key, "gear_str+")) {
        config().gear_str += atoi(value);
        if (config().gear_str < 0) config().gear_str = 0;
    }
    else if (0 == strcmp(key, "gear_crit+")) {
        config().gear_crit += atoi(value);
        if (config().gear_crit < 0) config().gear_crit = 0;
    }
    else if (0 == strcmp(key, "gear_mastery+")) {
        config().gear_mastery += atoi(value);
        if (config().gear_mastery < 0) config().gear_mastery = 0;
    }
    else if (0 == strcmp(key, "gear_haste+")) {
        config().gear_haste += atoi(value);
        if (config().gear_haste < 0) config().gear_haste = 0;
    }
    else if (0 == strcmp(key, "gear_mult+")) {
        config().gear_mult += atoi(value);
        if (config().gear_mult < 0) config().gear_mult = 0;
    }
    else if (0 == strcmp(key, "gear_vers+")) {
        config().gear_vers += atoi(value);
        if (config().gear_vers < 0) config().gear_vers = 0;
    }
    else if (0 == strcmp(key, "gear_str-")) {
        config().gear_str -= atoi(value);
        if (config().gear_str < 0) config().gear_str = 0;
    }
    else if (0 == strcmp(key, "gear_crit-")) {
        config().gear_crit -= atoi(value);
        if (config().gear_crit < 0) config().gear_crit = 0;
    }
    else if (0 == strcmp(key, "gear_mastery-")) {
        config().gear_mastery -= atoi(value);
        if (config().gear_mastery < 0) config().gear_mastery = 0;
    }
    else if (0 == strcmp(key, "gear_haste-")) {
        config().gear_haste -= atoi(value);
        if (config().gear_haste < 0) config().gear_haste = 0;
    }
    else if (0 == strcmp(key, "gear_mult-")) {
        config().gear_mult -= atoi(value);
        if (config().gear_mult < 0) config().gear_mult = 0;
    }
    else if (0 == strcmp(key, "gear_vers-")) {
        config().gear_vers -= atoi(value);
        if (config().gear_vers < 0) config().gear_vers = 0;
    }
    else if (0 == strcmp(key, "push_stats")) {
        cbprintf("Stat set system has been deprecated and no longer supported.\n");
    }
    else if (0 == strcmp(key, "deterministic_seed")) {
        config().seed = atoi(value);
    }
    else if (0 == strcmp(key, "iterations")) {
        config().iterations = atoi(value);
        if (config().iterations <= 0) config().iterations = 1;
    }
    else if (0 == strcmp(key, "raidbuff_str")) {
        config().raidbuff.str = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_ap")) {
        config().raidbuff.ap = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_sp")) {
        config().raidbuff.sp = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_crit")) {
        config().raidbuff.crit = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_haste")) {
        config().raidbuff.haste = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_mastery")) {
        config().raidbuff.mastery = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_mult")) {
        config().raidbuff.mult = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_vers")) {
        config().raidbuff.vers = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_sta")) {
        config().raidbuff.sta = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_flask")) {
        config().raidbuff.flask = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_food")) {
        config().raidbuff.food = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_potion")) {
        config().raidbuff.potion = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_bloodlust")) {
        config().raidbuff.bloodlust = !!atoi(value);
    }
    else if (0 == strcmp(key, "raidbuff_all")) {
        config().raidbuff.bloodlust = config().raidbuff.flask = config().raidbuff.food = config().raidbuff.potion = config().raidbuff.ap = config().raidbuff.crit = config().raidbuff.haste = config().raidbuff.mastery = config().raidbuff.mult = config().raidbuff.vers = config().raidbuff.sp = config().raidbuff.sta = config().raidbuff.str = !!atoi(value);
        config().raidbuff.vers = 1; /* This cannot be cancelled ingame. */
    }
    else if (0 == strcmp(key, "actions")) {
        config().apl->clear();
        config().apl->append(value);
        config().apl->append("\n");
    }
    else if (0 == strcmp(key, "actions+")) {
        config().apl->append(value);
        config().apl->append("\n");
    }
    else if (0 == strcmp(key, "default_actions")) {
        config().default_actions = !!atoi(value);
    }
    else if (0 == strcmp(key, "vary_combat_length")) {
        config().vary_combat_length = atof(value);
        if (config().vary_combat_length > 100.0f) config().vary_combat_length = 100.0f;
        if (config().vary_combat_length < 0.0f) config().vary_combat_length = 0.0f;
    }
    else if (0 == strcmp(key, "max_length")) {
        config().max_length = atof(value);
        if (config().max_length < 1.0f) config().max_length = 1.0f;
    }
    else if (0 == strcmp(key, "initial_health_percentage")) {
        config().initial_health_percentage = atof(value);
        if (config().initial_health_percentage > 100.0f) config().initial_health_percentage = 100.0f;
        if (config().initial_health_percentage < 0.0f) config().initial_health_percentage = 0.0f;
    }
    else if (0 == strcmp(key, "death_pct")) {
        config().death_pct = atof(value);
        if (config().death_pct > 100.0f) config().death_pct = 100.0f;
        if (config().death_pct < 0.0f) config().death_pct = 0.0f;
    }
    else if (0 == strcmp(key, "rage_max")) {
        config().power_max = atof(value);
        if (config().power_max < 0.0f) config().power_max = 0.0f;
    }
    else if (0 == strcmp(key, "num_enemies")) {
        config().num_enemies = atof(value);
        if (config().num_enemies < 1) config().num_enemies = 1;
    }
    else if (0 == strcmp(key, "glyph_of_ragingwind")) {
        config().glyph_of_ragingwind = atof(value);
    }
    else if (0 == strcmp(key, "plate_specialization")) {
        config().plate_specialization = !!atoi(value);
    }
    else if (0 == strcmp(key, "race")) {
        config().race = -1;
        for (int j = 0; race_str_param[j]; j++) {
            if (0 == strcmp(value, race_str_param[j])) {
                config().race = j;
                break;
            }
        }
        if (config().race == -1) { cbprintf("No such race \"%s\".\n", value); config().race = 0; }
    }
    else if (0 == strcmp(key, "mh_speed")) {
        config().mh_speed = atof(value);
    }
    else if (0 == strcmp(key, "oh_speed")) {
        config().oh_speed = atof(value);
    }
    else if (0 == strcmp(key, "mh_low")) {
        config().mh_low = atoi(value);
        if (config().mh_low < 0) config().mh_low = 0;
    }
    else if (0 == strcmp(key, "mh_high")) {
        config().mh_high = atoi(value);
        if (config().mh_high < 0) config().mh_high = 0;
    }
    else if (0 == strcmp(key, "oh_low")) {
        config().oh_low = atoi(value);
        if (config().oh_low < 0) config().oh_low = 0;
    }
    else if (0 == strcmp(key, "oh_high")) {
        config().oh_high = atoi(value);
        if (config().oh_high < 0) config().oh_high = 0;
    }
    else if (0 == strcmp(key, "mh_type")) {
        if (0 == strcmp(value, "2h")) config().mh_type = 0;
        else if (0 == strcmp(value, "1h")) config().mh_type = 1;
        else if (0 == strcmp(value, "dagger")) config().mh_type = 2;
        else  cbprintf("No such weapon type \"%s\".\n", value);
    }
    else if (0 == strcmp(key, "oh_type")) {
        if (0 == strcmp(value, "2h")) config().oh_type = 0;
        else if (0 == strcmp(value, "1h")) config().oh_type = 1;
        else if (0 == strcmp(value, "dagger")) config().oh_type = 2;
        else  cbprintf("No such weapon type \"%s\".\n", value);
    }
    else if (0 == strcmp(key, "talent")) {
        config().talent = atoi(value);
        if (config().talent < 0 || config().talent > 3333333
            || TALENT_TIER(1) > 3 || TALENT_TIER(2) > 3
            || TALENT_TIER(3) > 3 || TALENT_TIER(4) > 3 || TALENT_TIER(5) > 3
            || TALENT_TIER(6) > 3 || TALENT_TIER(7) > 3) {
            cbprintf("Talent set not vaild.\n");
            config().talent = 0000000;
        }
    }
    else if (0 == strcmp(key, "archmages_incandescence")) {
        config().archmages_incandescence = !!atoi(value);
    }
    else if (0 == strcmp(key, "archmages_greater_incandescence")) {
        config().archmages_greater_incandescence = !!atoi(value);
    }
    else if (0 == strcmp(key, "legendary_ring")) {
        config().legendary_ring = atoi(value);
    }
    else if (0 == strcmp(key, "t17_2pc")) {
        config().t17_2pc = !!atoi(value);
    }
    else if (0 == strcmp(key, "t17_4pc")) {
        config().t17_4pc = !!atoi(value);
    }
    else if (0 == strcmp(key, "t18_2pc")) {
        config().t18_2pc = !!atoi(value);
    }
    else if (0 == strcmp(key, "t18_4pc")) {
        config().t18_4pc = !!atoi(value);
    }
    else if (0 == strcmp(key, "mh_enchant")) {
        config().thunderlord_mh = !strcmp(value, "thunderlord");
        config().bleeding_hollow_mh = !strcmp(value, "bleedinghollow");
        config().shattered_hand_mh = !strcmp(value, "shatteredhand");
        if (strcmp(value, "none") && !config().thunderlord_mh && !config().bleeding_hollow_mh && !config().shattered_hand_mh)
            cbprintf("No such weapon enchant\"%s\".\n", value);
    }
    else if (0 == strcmp(key, "oh_enchant")) {
        config().thunderlord_oh = !strcmp(value, "thunderlord");
        config().bleeding_hollow_oh = !strcmp(value, "bleedinghollow");
        config().shattered_hand_oh = !strcmp(value, "shatteredhand");
        if (strcmp(value, "none") && !config().thunderlord_oh && !config().bleeding_hollow_oh && !config().shattered_hand_oh)
            cbprintf("No such weapon enchant\"%s\".\n", value);
    }
    else if (0 == strcmp(key, "trinket1")) {
        int x;
        for (x = 0; trinket_list[x]; x++) {
            if (0 == strcmp(value, trinket_list[x])) {
                config().trinket1 = x;
                break;
            }
        }
        if (!trinket_list[x]) { cbprintf("No such trinket \"%s\".\n", value); config().trinket1 = 0; return; }
    }
    else if (0 == strcmp(key, "trinket2")) {
        int x;
        for (x = 0; trinket_list[x]; x++) {
            if (0 == strcmp(value, trinket_list[x])) {
                config().trinket2 = x;
                break;
            }
        }
        if (!trinket_list[x]) { cbprintf("No such trinket \"%s\".\n", value); config().trinket2 = 0; return; }
    }
    else if (0 == strcmp(key, "trinket1_ilvl")) {
        config().trinket1_ilvl = atoi(value);
    }
    else if (0 == strcmp(key, "trinket2_ilvl")) {
        config().trinket2_ilvl = atoi(value);
    }
    else if (0 == strcmp(key, "enemy_is_demonic")) {
        config().enemy_is_demonic = !!atoi(value);
    }
    else if (0 == strcmp(key, "rng_engine")) {
        if (0 == strcmp(value, "mt127")) config().rng_engine = 127;
        else if (0 == strcmp(value, "mwc64x")) config().rng_engine = 64;
        else if (0 == strcmp(value, "lcg32")) config().rng_engine = 32;
        else cbprintf("No such rng engine \"%s\".\n", value);
    }
    else if (0 == strcmp(key, "strict_gcd")) {
        config().strict_gcd = !!atoi(value);
    }
    else if (0 == strcmp(key, "wbr_never_expire")) {
        config().wbr_never_expire = !!atoi(value);
    }
    else if (0 == strcmp(key, "sync_melee")) {
        config().sync_melee = !!atoi(value);
    }
    else if (0 == strcmp(key, "avatar_like_bloodbath")) {
        config().avatar_like_bloodbath = !!atoi(value);
    }
    else if (0 == strcmp(key, "support_non_c99")) {
        cbprintf("The option \"support_non_c99\" has been deprecated since irecore-620-49. IreCore should works well on all main-stream platforms now.\n");
    }
    else if (0 == strcmp(key, "output")) {
        if(config().output_file){
            fclose(config().output_file);
            config().output_file = 0;
            config().printcb = &vprintf;
        }
        config().output_file = fopen(value, "wb");
        if(config().output_file){
            config().printcb = &vofprintf;
        }
    }
    else if (0 == strcmp(key, "calculate_scale_factors")) {
        cbprintf("Calculating scale factors via key-value configuration interface has been deprecated and no longer supported.\n");
    }
    else if (0 == strcmp(key, "developer_debug")) {
        config().developer_debug = !!atoi(value);
    }
    else if (0 == strcmp(key, "list_available_devices")) {
        cbprintf("Listing avaliable devices via key-value configuration interface has been deprecated and no longer supported.\n");
    }
    else if (0 == strcmp(key, "opencl_device_id")) {
        config().opencl_device_id = atoi(value);
    }
    else {
        cbprintf("Cannot parse parameter \"%s\".\n", key);
    }
}

// real to string.
char* ftoa(double val, char* dstbuf){
    sprintf(dstbuf, "%f", val);
    return dstbuf;
}

// API: get parameters.
const char* ic_getparam(const char* key){
#define GETI(k) if( 0 == strcmp(key, STR(k))){ return itoa(config().k, exchbuf(), 10); } else
#define GETBUF(k) if( 0 == strcmp(key, "raidbuff_" STR(k))){ return itoa(config().raidbuff.k, exchbuf(), 10); } else
#define GETF(k) if( 0 == strcmp(key, STR(k))){ return ftoa(config().k, exchbuf()); } else
    GETBUF(str)
    GETBUF(ap)
    GETBUF(sp)
    GETBUF(sta)
    GETBUF(crit)
    GETBUF(haste)
    GETBUF(mastery)
    GETBUF(vers)
    GETBUF(mult)
    GETBUF(flask)
    GETBUF(food)
    GETBUF(potion)
    GETBUF(bloodlust)
    GETI(gear_str)
    GETI(gear_crit)
    GETI(gear_haste)
    GETI(gear_mastery)
    GETI(gear_mult)
    GETI(gear_vers)
    GETI(seed)
    GETI(iterations)
    GETF(vary_combat_length)
    GETF(max_length)
    GETF(initial_health_percentage)
    GETF(death_pct)
    GETF(power_max)
    GETI(glyph_of_ragingwind)
    GETI(num_enemies)
    GETI(plate_specialization)
    GETI(single_minded)
    GETF(mh_speed)
    GETF(oh_speed)
    GETI(mh_low)
    GETI(mh_high)
    GETI(oh_low)
    GETI(oh_high)
    GETI(strict_gcd)
    GETI(sync_melee)
    GETI(wbr_never_expire)
    GETI(avatar_like_bloodbath)
    GETI(default_actions)
    GETI(archmages_incandescence)
    GETI(archmages_greater_incandescence)
    GETI(legendary_ring)
    GETI(t17_2pc)
    GETI(t17_4pc)
    GETI(t18_2pc)
    GETI(t18_4pc)
    GETI(trinket1_ilvl)
    GETI(trinket2_ilvl)
    GETI(enemy_is_demonic)
    GETI(opencl_device_id)
    GETI(developer_debug)
    if(0 == strcmp(key, "talent")){
        for(int i = 0; i < 7; i++)
            exchbuf()[i] = TALENT_TIER(i+1);
        exchbuf()[7] = 0;
        return exchbuf();
    } else
    if(0 == strcmp(key, "mh_enchant")){
        if(config().thunderlord_mh) return "thunderlord";
        if(config().bleeding_hollow_mh) return "bleedinghollow";
        if(config().shattered_hand_mh) return "shatteredhand";
        return "none";
    } else
    if(0 == strcmp(key, "oh_enchant")){
        if(config().thunderlord_oh) return "thunderlord";
        if(config().bleeding_hollow_oh) return "bleedinghollow";
        if(config().shattered_hand_oh) return "shatteredhand";
        return "none";
    } else
    if(0 == strcmp(key, "mh_type")){
        const char* typestr[] = { "2h", "1h", "dagger", };
        return typestr[config().mh_type];
    } else
    if(0 == strcmp(key, "oh_type")){
        const char* typestr[] = { "2h", "1h", "dagger", };
        return typestr[config().oh_type];
    } else
    if(0 == strcmp(key, "trinket1")){
        return trinket_list[config().trinket1];
    } else
    if(0 == strcmp(key, "trinket2")){
        return trinket_list[config().trinket2];
    } else
    if(0 == strcmp(key, "race")){
        return race_str_param[config().race];
    } else
    if(0 == strcmp(key, "rng_engine")){
		switch(config().rng_engine){
		case 127: return "mt127";
		case 64: return "mwc64x";
        case 32: default: return "lcg32";
        }
    } else
    if(0 == strcmp(key, "actions")){
        // TODO
    } else

    {
        cbprintf("Cannot parse parameter \"%s\".\n", key);
        return 0;
    }
}

// Vectorized DJBHash.
unsigned strhash(const char* str){
    __m128i xmm0 = _mm_setzero_si128();
    __m128i xmm2 = _mm_set1_epi32(5381);
    __m128i xmm3 = _mm_set1_epi32(0xff);
    __m128i* p = (__m128i*)str;
    __m128i mask;
    int exitflag = 1;
    __m128i xmm1;
    while (exitflag){
        xmm1 = _mm_loadu_si128(p++);
        mask = _mm_cmpeq_epi8(xmm1, xmm0);
        if (_mm_movemask_epi8(mask) & 0xffff){
            mask = _mm_and_si128(mask, _mm_slli_si128(mask, 1));
            mask = _mm_and_si128(mask, _mm_slli_si128(mask, 2));
            mask = _mm_and_si128(mask, _mm_slli_si128(mask, 4));
            mask = _mm_and_si128(mask, _mm_slli_si128(mask, 8));
            xmm1 = _mm_andnot_si128(mask, xmm1);
            exitflag = 0;
        }
        xmm2 = _mm_add_epi32(xmm2, _mm_slli_epi32(xmm2, 5));
        xmm2 = _mm_add_epi32(xmm2, _mm_and_si128(_mm_srli_epi32(xmm1, 24), xmm3));
        xmm2 = _mm_add_epi32(xmm2, _mm_slli_epi32(xmm2, 5));
        xmm2 = _mm_add_epi32(xmm2, _mm_and_si128(_mm_srli_epi32(xmm1, 16), xmm3));
        xmm2 = _mm_add_epi32(xmm2, _mm_slli_epi32(xmm2, 5));
        xmm2 = _mm_add_epi32(xmm2, _mm_and_si128(_mm_srli_epi32(xmm1, 8), xmm3));
        xmm2 = _mm_add_epi32(xmm2, _mm_slli_epi32(xmm2, 5));
        xmm2 = _mm_add_epi32(xmm2, _mm_and_si128(xmm1, xmm3));
    }
    unsigned u[4];
    _mm_storeu_si128((__m128i*)u, xmm2);
    u[0] ^= u[1];
    u[0] ^= u[2];
    u[0] ^= u[3];
    return u[0];
}

