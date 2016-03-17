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

IC_LOCAL config_t& config(){
    static config_t c;
    return c;
}

IC_LOCAL char* exchbuf(){
    static char buf[1024];
    return buf;
}

// print info via callback function.
IC_LOCAL int cbprintf(const char* format, ...){
    va_list vl;
    int ret;
    va_start(vl, format);
    ret = (*config().printcb)(format, vl);
    va_end(vl);
    return ret;
}

// print into file.
IC_LOCAL int vofprintf(const char* a, va_list b){
    int ret = vfprintf(config().output_file, a, b);
    vprintf(a, b);
    fflush(config().output_file);
    return ret;
}

// API: show version.
const char* ic_getversion(void){
    static std::string verstr;
    verstr = STRFILEVER;
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
void ic_setprintcallback(ic_printcb_t cbf){
    config().printcb = cbf;
}


// API: initializer.
void ic_init(void){
    // Load kernel source
    if (!config().kernel_str){
        FILE* f = fopen("kernel\kernel.c", "rb");
        fseek(f, 0, SEEK_END);
        size_t tell = ftell(f);
        rewind(f);
        config().kernel_str = (char*)calloc(tell + 1, 1);
        fread(config().kernel_str, tell, 1, f);
        fclose(f);
    }
    if (!config().kernel_arms_str){
        FILE* f = fopen("kernel\arms.c", "rb");
        fseek(f, 0, SEEK_END);
        size_t tell = ftell(f);
        rewind(f);
        config().kernel_arms_str = (char*)calloc(tell + 1, 1);
        fread(config().kernel_arms_str, tell, 1, f);
        fclose(f);
    }
    if (!config().kernel_fury_str){
        FILE* f = fopen("kernel\fury.c", "rb");
        fseek(f, 0, SEEK_END);
        size_t tell = ftell(f);
        rewind(f);
        config().kernel_fury_str = (char*)calloc(tell + 1, 1);
        fread(config().kernel_fury_str, tell, 1, f);
        fclose(f);
    }
    // Lookup available devices.
    if (config().device_list.empty()){
        config().device_list.clear();
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
                icd.device_id = *i;
                icd.context = context;
                icd.device_name = _strdup(devname.c_str());
                icd.platform_name = _strdup(platname.c_str());
                icd.id = device_counter;
                config().device_list.push_back(icd);
                device_counter++;
            }
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
        config().apl.clear();
        config().apl=value;
        config().apl.append("\n");
    }
    else if (0 == strcmp(key, "actions+")) {
        config().apl.append(value);
        config().apl.append("\n");
    }
    else if (0 == strcmp(key, "default_actions")) {
        config().default_actions = !!atoi(value);
    }
    else if (0 == strcmp(key, "simc_actions")) {
        config().simc_actions.clear();
        config().simc_actions=value;
        if(!config().simc_actions.empty())
            config().simc_actions.append("\n");
    }
    else if (0 == strcmp(key, "simc_actions+")) {
        config().simc_actions.append(value);
        if(!config().simc_actions.empty())
            config().simc_actions.append("\n");
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
        config().num_enemies = atoi(value);
        if (config().num_enemies < 1) config().num_enemies = 1;
    }
    else if (0 == strcmp(key, "glyph_of_ragingwind")) {
        config().glyph_of_ragingwind = atoi(value);
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
        if (config().output_file){
            fclose(config().output_file);
            config().output_file = 0;
            config().printcb = &vprintf;
        }
        config().output_file = fopen(value, "wb");
        if (config().output_file){
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
IC_LOCAL char* ftoa(double val, char* dstbuf){
    sprintf(dstbuf, "%f", val);
    return dstbuf;
}

// API: get parameters.
const char* ic_getparam(const char* key){
#define GETI(k) if( 0 == strcmp(key, STR(k))){ return _itoa(config().k, exchbuf(), 10); } else
#define GETBUF(k) if( 0 == strcmp(key, "raidbuff_" STR(k))){ return _itoa(config().raidbuff.k, exchbuf(), 10); } else
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
        if (0 == strcmp(key, "talent")){
            for (int i = 0; i < 7; i++)
                exchbuf()[i] = TALENT_TIER(i + 1);
            exchbuf()[7] = 0;
            return exchbuf();
        }
        else if (0 == strcmp(key, "mh_enchant")){
            if (config().thunderlord_mh) return "thunderlord";
            if (config().bleeding_hollow_mh) return "bleedinghollow";
            if (config().shattered_hand_mh) return "shatteredhand";
            return "none";
        }
        else if (0 == strcmp(key, "oh_enchant")){
            if (config().thunderlord_oh) return "thunderlord";
            if (config().bleeding_hollow_oh) return "bleedinghollow";
            if (config().shattered_hand_oh) return "shatteredhand";
            return "none";
        }
        else if (0 == strcmp(key, "mh_type")){
            const char* typestr[] = { "2h", "1h", "dagger", };
            return typestr[config().mh_type];
        }
        else if (0 == strcmp(key, "oh_type")){
            const char* typestr[] = { "2h", "1h", "dagger", };
            return typestr[config().oh_type];
        }
        else if (0 == strcmp(key, "trinket1")){
            return trinket_list[config().trinket1];
        }
        else if (0 == strcmp(key, "trinket2")){
            return trinket_list[config().trinket2];
        }
        else if (0 == strcmp(key, "race")){
            return race_str_param[config().race];
        }
        else if (0 == strcmp(key, "rng_engine")){
            switch (config().rng_engine){
            case 127: return "mt127";
            case 64: return "mwc64x";
            case 32: default: return "lcg32";
            }
        }
        else if (0 == strcmp(key, "actions")){
            return config().apl.c_str();
        }
        else if (0 == strcmp(key, "simc_actions")){
            return config().simc_actions.c_str();
        }
        else {
            cbprintf("Cannot parse parameter \"%s\".\n", key);
            return 0;
        }
}

// API: reset all parameters to default.
void ic_resetparam(void){
    config_t blank;
    blank.device_list = config().device_list;
    blank.kernel_str = config().kernel_str;
    blank.printcb = config().printcb;
    blank.output_file = config().output_file;
    config() = blank;
}

// API: default apl.
const char* ic_defaultapl(void) {
    static std::string apl;
    apl = "if(!UP(enrage.expire)||(REMAIN(bloodthirst.cd)>FROM_SECONDS(3)&&rti->player.ragingblow.stack<2))SPELL(berserkerrage);\n";
    apl.append("if((((num_enemies>1.000000f)||!0)&&(((T63(1,0)&&(T63(TO_SECONDS(REMAIN(bladestorm.cd)),0)==0.000000f))||UP(recklessness.expire))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<25.000000f))))LEGENDARY(SPELL(thorasus_the_stone_heart_of_draenor),0);\n");
    apl.append("if((((enemy_health_percent(rti)<20.000000f)&&UP(recklessness.expire))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<=30.000000f)))POTION(SPELL(potion),0);\n");

    if (0 == strcmp(trinket_list[config().trinket1], "vial_of_convulsive_shadows") || 0 == strcmp(trinket_list[config().trinket2], "vial_of_convulsive_shadows"))
        if (TALENT_TIER(7) == 1) apl.append("if(UP(recklessness.expire)||TIME_DISTANT(rti->expected_combat_length)<FROM_SECONDS(25))SPELL(vial_of_convulsive_shadows);\n");
        else apl.append("SPELL(vial_of_convulsive_shadows);\n");
        if (0 == strcmp(trinket_list[config().trinket1], "bonemaws_big_toe") || 0 == strcmp(trinket_list[config().trinket2], "bonemaws_big_toe"))
            if (TALENT_TIER(7) == 1) apl.append("if(UP(recklessness.expire)||TIME_DISTANT(rti->expected_combat_length)<FROM_SECONDS(25))SPELL(bonemaws_big_toe);\n");
            else apl.append("SPELL(bonemaws_big_toe);\n");
            if (0 == strcmp(trinket_list[config().trinket1], "scabbard_of_kyanos") || 0 == strcmp(trinket_list[config().trinket2], "scabbard_of_kyanos")) apl.append("SPELL(scabbard_of_kyanos);\n");
            if (0 == strcmp(trinket_list[config().trinket1], "emberscale_talisman") || 0 == strcmp(trinket_list[config().trinket2], "emberscale_talisman")) apl.append("SPELL(emberscale_talisman);\n");
            if (0 == strcmp(trinket_list[config().trinket1], "badge_of_victory") || 0 == strcmp(trinket_list[config().trinket2], "badge_of_victory")) apl.append("SPELL(badge_of_victory);\n");

            apl.append("if((((((T62(UP(bloodbath.expire),0)||(T62(TO_SECONDS(REMAIN(bloodbath.cd)),0)>25.000000f))||!T62(1,0))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<15.000000f))&&((T63(1,0)&&(!0||(num_enemies==1.000000f)))||!T63(1,0)))&&t18_4pc))SPELL(recklessness);\n");
            apl.append("if(((T71(1,0)&&((T63(1,0)&&(!0||(num_enemies==1.000000f)))||!T63(1,0)))&&!t18_4pc)){\n");
            apl.append("if((((TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))>140.000000f)||(enemy_health_percent(rti)<20.000000f))&&((T62(UP(bloodbath.expire),0)||!T62(1,0))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<15.000000f))))SPELL(recklessness);\n");
            apl.append("}\n");
            apl.append("if(((!T71(1,0)&&((T63(1,0)&&(!0||(num_enemies==1.000000f)))||!T63(1,0)))&&!t18_4pc)){\n");
            apl.append("if((((TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))>190.000000f)||(enemy_health_percent(rti)<20.000000f))&&((T62(UP(bloodbath.expire),0)||!T62(1,0))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<15.000000f))))SPELL(recklessness);\n");
            apl.append("}\n");
            apl.append("if(((UP(recklessness.expire)||(TO_SECONDS(REMAIN(recklessness.cd))>60.000000f))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<30.000000f)))T61(SPELL(avatar),0);\n");
            apl.append("if(((T62(UP(bloodbath.expire),0)||!T62(1,0))||UP(recklessness.expire)))ORC(SPELL(bloodfury),0);\n");
            apl.append("if(((T62(UP(bloodbath.expire),0)||!T62(1,0))||UP(recklessness.expire)))TROLL(SPELL(berserking),0);\n");
            apl.append("if((rti->player.power<(power_max-40.000000f)))BELF(SPELL(arcanetorrent),0);\n");
            apl.append("if((num_enemies==2.000000f)){\n");
            apl.append("T62(SPELL(bloodbath),0);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||!T62(1,0)))T72(SPELL(ravager),0);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||!T62(1,0)))T43(SPELL(dragonroar),0);\n");
            apl.append("{\n");
            apl.append("if(((TO_SECONDS(REMAIN(enrage.expire))>6.000000f)&&((((T71(1,0)&&(0>45.000000f))||(!T71(1,0)&&(0>60.000000f)))||!0)||(num_enemies>num_enemies))))SPELL(recklessness);\n");
            apl.append("if(((TO_SECONDS(REMAIN(enrage.expire))>6.000000f)&&((((T71(1,0)&&(0>45.000000f))||(!T71(1,0)&&(0>60.000000f)))||!0)||(num_enemies>num_enemies))))T63(SPELL(bladestorm),0);\n");
            apl.append("}\n");
            apl.append("if(((!UP(enrage.expire)||(rti->player.power<40.000000f))||!UP(ragingblow.expire)))SPELL(bloodthirst);\n");
            apl.append("T73(SPELL(siegebreaker),0);\n");
            apl.append("SPELL(execute);\n");
            apl.append("if((UP(meatcleaver.expire)||(enemy_health_percent(rti)<20.000000f)))SPELL(ragingblow);\n");
            apl.append("if((!UP(meatcleaver.expire)&&(enemy_health_percent(rti)>20.000000f)))SPELL(whirlwind);\n");
            apl.append("if(UP(bloodsurge.expire))SPELL(wildstrike);\n");
            apl.append("SPELL(bloodthirst);\n");
            apl.append("SPELL(whirlwind);\n");
            apl.append("}\n");
            apl.append("if((num_enemies==3.000000f)){\n");
            apl.append("T62(SPELL(bloodbath),0);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||!T62(1,0)))T72(SPELL(ravager),0);\n");
            apl.append("{\n");
            apl.append("if(((TO_SECONDS(REMAIN(enrage.expire))>6.000000f)&&((((T71(1,0)&&(0>45.000000f))||(!T71(1,0)&&(0>60.000000f)))||!0)||(num_enemies>num_enemies))))SPELL(recklessness);\n");
            apl.append("if(((TO_SECONDS(REMAIN(enrage.expire))>6.000000f)&&((((T71(1,0)&&(0>45.000000f))||(!T71(1,0)&&(0>60.000000f)))||!0)||(num_enemies>num_enemies))))T63(SPELL(bladestorm),0);\n");
            apl.append("}\n");
            apl.append("if(((!UP(enrage.expire)||(rti->player.power<50.000000f))||!UP(ragingblow.expire)))SPELL(bloodthirst);\n");
            apl.append("if((rti->player.meatcleaver.stack>=2.000000f))SPELL(ragingblow);\n");
            apl.append("T73(SPELL(siegebreaker),0);\n");
            apl.append("SPELL(execute);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||!T62(1,0)))T43(SPELL(dragonroar),0);\n");
            apl.append("if((enemy_health_percent(rti)>20.000000f))SPELL(whirlwind);\n");
            apl.append("SPELL(bloodthirst);\n");
            apl.append("if(UP(bloodsurge.expire))SPELL(wildstrike);\n");
            apl.append("SPELL(ragingblow);\n");
            apl.append("}\n");
            apl.append("if((num_enemies>3.000000f)){\n");
            apl.append("T62(SPELL(bloodbath),0);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||!T62(1,0)))T72(SPELL(ravager),0);\n");
            apl.append("if(((rti->player.meatcleaver.stack>=3.000000f)&&UP(enrage.expire)))SPELL(ragingblow);\n");
            apl.append("if(((!UP(enrage.expire)||(rti->player.power<50.000000f))||!UP(ragingblow.expire)))SPELL(bloodthirst);\n");
            apl.append("if((rti->player.meatcleaver.stack>=3.000000f))SPELL(ragingblow);\n");
            apl.append("{\n");
            apl.append("if(((TO_SECONDS(REMAIN(enrage.expire))>6.000000f)&&((((T71(1,0)&&(0>45.000000f))||(!T71(1,0)&&(0>60.000000f)))||!0)||(num_enemies>num_enemies))))SPELL(recklessness);\n");
            apl.append("if(((TO_SECONDS(REMAIN(enrage.expire))>6.000000f)&&((((T71(1,0)&&(0>45.000000f))||(!T71(1,0)&&(0>60.000000f)))||!0)||(num_enemies>num_enemies))))T63(SPELL(bladestorm),0);\n");
            apl.append("}\n");
            apl.append("SPELL(whirlwind);\n");
            apl.append("T73(SPELL(siegebreaker),0);\n");
            apl.append("if(T32(UP(suddendeath.expire),0))SPELL(execute);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||!T62(1,0)))T43(SPELL(dragonroar),0);\n");
            apl.append("SPELL(bloodthirst);\n");
            apl.append("if(UP(bloodsurge.expire))SPELL(wildstrike);\n");
            apl.append("}\n");
            apl.append("{\n");
            apl.append("T62(SPELL(bloodbath),0);\n");
            apl.append("if(((enemy_health_percent(rti)<20.000000f)&&0))SPELL(recklessness);\n");
            apl.append("if(((rti->player.power>(power_max-20.000000f))&&(enemy_health_percent(rti)>20.000000f)))SPELL(wildstrike);\n");
            apl.append("if((((!T33(1,0)&&(rti->player.power<(power_max-40.000000f)))||!UP(enrage.expire))||(rti->player.ragingblow.stack<2.000000f)))SPELL(bloodthirst);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||(!T62(1,0)&&((!0||(0>60.000000f))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<40.000000f)))))T72(SPELL(ravager),0);\n");
            apl.append("T73(SPELL(siegebreaker),0);\n");
            apl.append("if(T32(UP(suddendeath.expire),0))SPELL(execute);\n");
            apl.append("T41(SPELL(stormbolt),0);\n");
            apl.append("if(UP(bloodsurge.expire))SPELL(wildstrike);\n");
            apl.append("if((UP(enrage.expire)||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<12.000000f)))SPELL(execute);\n");
            apl.append("if((T62(UP(bloodbath.expire),0)||!T62(1,0)))T43(SPELL(dragonroar),0);\n");
            apl.append("SPELL(ragingblow);\n");
            apl.append("if(((TO_SECONDS(REMAIN(bloodthirst.cd))<0.500000f)&&(rti->player.power<50.000000f)))return;\n");
            apl.append("if((UP(enrage.expire)&&(enemy_health_percent(rti)>20.000000f)))SPELL(wildstrike);\n");
            apl.append("if(!0)T63(SPELL(bladestorm),0);\n");
            apl.append("if(!T33(1,0))T42(SPELL(shockwave),0);\n");
            apl.append("SPELL(bloodthirst);\n");
            apl.append("}\n");
            return apl.c_str();
}

// parameter validation.
IC_LOCAL config_t parameters_consistency() {
    config_t blank(config());
    blank.single_minded = (blank.mh_type == 1 && blank.oh_type == 1);
    if (blank.trinket1 == blank.trinket2 && 0 != blank.trinket1) {
        cbprintf("Duplicated trinkets \"%s\" not allowed. Trinket 2 reset to none.\n", trinket_list[blank.trinket2]);
        blank.trinket2 = 0;
    }
    if (blank.mh_high < blank.mh_low) {
        cbprintf("MH Low Damage is higher than MH High Damage, exchanged.\n");
        int t = blank.mh_high;
        blank.mh_high = blank.mh_low;
        blank.mh_low = t;
    }
    if (blank.oh_high < blank.oh_low) {
        cbprintf("OH Low Damage is higher than OH High Damage, exchanged.\n");
        int t = blank.oh_high;
        blank.oh_high = blank.oh_low;
        blank.oh_low = t;
    }
    if (blank.mh_speed <= .0) {
        cbprintf("MH Speed less than or equal to zero, reset to 1.5s.\n");
        blank.mh_speed = 1.5;
    }
    if (blank.oh_speed <= .0) {
        cbprintf("OH Speed less than or equal to zero, reset to 1.5s.\n");
        blank.oh_speed = 1.5;
    }
    if (blank.num_enemies < 1) {
        cbprintf("Num Enemies less than 1, reset to 1.\n");
        blank.num_enemies = 1;
    }
    if (blank.num_enemies > 20) {
        cbprintf("Num Enemies greater than 20, reset to 20.\n");
        blank.num_enemies = 20;
    }
    if (blank.raidbuff.flask) {
        blank.gear_str += 250;
    }
    if (blank.raidbuff.food) {
        blank.gear_crit += 125 * (blank.race == 14 ? 2 : 1);
    }
    if (!blank.default_actions && !blank.simc_actions.empty()) {
        cbprintf("SimC-style APL are set. Start APL translation.\n");
        blank.apl.clear();
        sapltr(blank.simc_actions, blank.apl);
    }
    if (blank.default_actions) {
        blank.apl.clear();
        blank.apl=ic_defaultapl();
    }
    return blank;
}

// prefix mean to minimize rounding error.
IC_LOCAL template <typename T>
T prefix_mean(const T* _data, size_t n) {
    /* Make a copy of _data. */
    std::vector<T> data(_data, _data + n);

    /* Prefix-sum to minimize rounding errors for FP types. */
    for (size_t k = 1; k < data.size(); k += k) {
        for (size_t i = 0; i < data.size(); i += k) {
            auto j = i + k;
            if (j < data.size()) {
                data[i] += data[j];
                i = j;
            }
            else {
                break;
            }
        }
    }

    return data[0] / static_cast<T>(n);
}
IC_LOCAL template <typename T>
T prefix_stddev(const T* _data, size_t n, T mean) {
    /* Make a copy of _data. */
    std::vector<T> data(_data, _data + n);

    for (size_t i = 0; i < data.size(); i++)
        data[i] = (data[i] - mean) * (data[i] - mean);

    /* Prefix-sum to minimize rounding errors for FP types. */
    for (size_t k = 1; k < data.size(); k += k) {
        for (size_t i = 0; i < data.size(); i += k) {
            auto j = i + k;
            if (j < data.size()) {
                data[i] += data[j];
                i = j;
            }
            else {
                break;
            }
        }
    }

    return sqrt(data[0] / static_cast<T>(n));
}

// generate pre-definition to insert into kernel source.
IC_LOCAL std::string generate_predef(config_t& blank) {
    char buffer[256];
    const char* race_str_kernel[] = {
        "RACE_NONE",
        "RACE_HUMAN",
        "RACE_DWARF",
        "RACE_GNOME",
        "RACE_NIGHTELF_DAY",
        "RACE_NIGHTELF_NIGHT",
        "RACE_DRAENEI",
        "RACE_WORGEN",
        "RACE_ORC",
        "RACE_TROLL",
        "RACE_TAUREN",
        "RACE_UNDEAD",
        "RACE_BLOODELF",
        "RACE_GOBLIN",
        "RACE_PANDAREN",
        NULL
    };
    const char* weapon_type_str[] = {
        "WEAPON_2H",
        "WEAPON_1H",
        "WEAPON_DAGGER",
    };
    std::string predef = "";

    predef.append("#define ENEMY_IS_DEMONIC ");
    sprintf(buffer, "%d", !!blank.enemy_is_demonic);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define STRICT_GCD ");
    sprintf(buffer, "%d", !!blank.strict_gcd);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define SYNC_MELEE ");
    sprintf(buffer, "%d", !!blank.sync_melee);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define WBR_NEVER_EXPIRE ");
    sprintf(buffer, "%d", !!blank.wbr_never_expire);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define AVATAR_LIKE_BLOODBATH ");
    sprintf(buffer, "%d", !!blank.avatar_like_bloodbath);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define vary_combat_length ");
    sprintf(buffer, "%ff", blank.vary_combat_length * 0.01 * blank.max_length );
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define max_length ");
    sprintf(buffer, "%ff", blank.max_length);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define initial_health_percentage ");
    sprintf(buffer, "%ff", blank.initial_health_percentage);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define death_pct ");
    sprintf(buffer, "%ff", blank.death_pct);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define power_max ");
    sprintf(buffer, "%ff", blank.power_max);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define num_enemies ");
    sprintf(buffer, "%d", blank.num_enemies);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define GLYPH_OF_RAGINGWIND ");
    sprintf(buffer, "%d", !!blank.glyph_of_ragingwind);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define PLATE_SPECIALIZATION ");
    sprintf(buffer, "%d", !!blank.plate_specialization);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define SINGLE_MINDED ");
    sprintf(buffer, "%d", !!blank.single_minded);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_STR_AGI_INT ");
    sprintf(buffer, "%d", !!blank.raidbuff.str);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_AP ");
    sprintf(buffer, "%d", !!blank.raidbuff.ap);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_CRIT ");
    sprintf(buffer, "%d", !!blank.raidbuff.crit);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_HASTE ");
    sprintf(buffer, "%d", !!blank.raidbuff.haste);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_MASTERY ");
    sprintf(buffer, "%d", !!blank.raidbuff.mastery);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_MULT ");
    sprintf(buffer, "%d", !!blank.raidbuff.mult);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_VERS ");
    sprintf(buffer, "%d", !!blank.raidbuff.vers);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_SP ");
    sprintf(buffer, "%d", !!blank.raidbuff.sp);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_STA ");
    sprintf(buffer, "%d", !!blank.raidbuff.sta);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_POTION ");
    sprintf(buffer, "%d", !!blank.raidbuff.potion);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define BUFF_BLOODLUST ");
    sprintf(buffer, "%d", !!blank.raidbuff.bloodlust);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define RACE ");
    predef.append(race_str_kernel[blank.race]); predef.append("\r\n");

    predef.append("#define MH_LOW ");
    sprintf(buffer, "%d", blank.mh_low);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define MH_HIGH ");
    sprintf(buffer, "%d", blank.mh_high);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define OH_LOW ");
    sprintf(buffer, "%d", blank.oh_low);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define OH_HIGH ");
    sprintf(buffer, "%d", blank.oh_high);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define MH_SPEED ");
    sprintf(buffer, "%ff", blank.mh_speed);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define OH_SPEED ");
    sprintf(buffer, "%ff", blank.oh_speed);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define MH_TYPE ");
    predef.append(weapon_type_str[blank.mh_type]); predef.append("\r\n");

    predef.append("#define OH_TYPE ");
    predef.append(weapon_type_str[blank.oh_type]); predef.append("\r\n");

    predef.append("#define TALENT_TIER3 ");
    sprintf(buffer, "%d", TALENT_TIER(3));
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define TALENT_TIER4 ");
    sprintf(buffer, "%d", TALENT_TIER(4));
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define TALENT_TIER6 ");
    sprintf(buffer, "%d", TALENT_TIER(6));
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define TALENT_TIER7 ");
    sprintf(buffer, "%d", TALENT_TIER(7));
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define archmages_incandescence ");
    sprintf(buffer, "%d", !!blank.archmages_incandescence);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define archmages_greater_incandescence ");
    sprintf(buffer, "%d", !!blank.archmages_greater_incandescence);
    predef.append(buffer); predef.append("\r\n");

    if (blank.legendary_ring){
        predef.append("#define legendary_ring ");
        sprintf(buffer, "%d", (int)(2500.0 * approx_scale_coeff(735, blank.legendary_ring)));
        predef.append(buffer); predef.append("\r\n");
    }

    predef.append("#define t17_2pc ");
    sprintf(buffer, "%d", !!blank.t17_2pc);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define t17_4pc ");
    sprintf(buffer, "%d", !!blank.t17_4pc);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define t18_2pc ");
    sprintf(buffer, "%d", !!blank.t18_2pc);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define t18_4pc ");
    sprintf(buffer, "%d", !!blank.t18_4pc);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define thunderlord_mh ");
    sprintf(buffer, "%d", !!blank.thunderlord_mh);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define thunderlord_oh ");
    sprintf(buffer, "%d", !!blank.thunderlord_oh);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define bleedinghollow_mh ");
    sprintf(buffer, "%d", !!blank.bleeding_hollow_mh);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define bleedinghollow_oh ");
    sprintf(buffer, "%d", !!blank.bleeding_hollow_oh);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define shatteredhand_mh ");
    sprintf(buffer, "%d", !!blank.shattered_hand_mh);
    predef.append(buffer); predef.append("\r\n");

    predef.append("#define shatteredhand_oh ");
    sprintf(buffer, "%d", !!blank.shattered_hand_oh);
    predef.append(buffer); predef.append("\r\n");

    if (blank.rng_engine == 127) predef.append("#define RNG_MT127\r\n");
    else if (blank.rng_engine == 64) predef.append("#define RNG_MWC64X\r\n");

    if (blank.trinket1) {
        predef.append("#define trinket_");
        predef.append(trinket_list[blank.trinket1]);
        predef.append(" ");
        sprintf(buffer, "%d", trinket_scaling(blank.trinket1, blank.trinket1_ilvl));
        predef.append(buffer);
        predef.append("\r\n");
    }
    if (blank.trinket2) {
        predef.append("#define trinket_");
        predef.append(trinket_list[blank.trinket2]);
        predef.append(" ");
        sprintf(buffer, "%d", trinket_scaling(blank.trinket2, blank.trinket2_ilvl));
        predef.append(buffer);
        predef.append("\r\n");
    }

    return predef;
}

// transpose table.
IC_LOCAL std::unordered_map<std::string, cl_program>& clptt(void){
    static std::unordered_map<std::string, cl_program> tt;
    return tt;
}
IC_LOCAL int ttprobe(std::string hashkey, cl_program* p){
    auto i = clptt().find(hashkey);
    if (i != clptt().end()){
        *p = i->second;
        return 1;
    }
    else{
        return 0;
    }
}
IC_LOCAL void ttsave(std::string hashkey, cl_program p){
    clptt()[hashkey] = p;
}

// API: start simulation.
int ic_runsim(float* dps, float* dpsr, float* dpse, float* sim_time){
    auto t1 = std::chrono::high_resolution_clock::now();
    
    ic_init();
    config_t blank = parameters_consistency();
    std::string source(config().kernel_str);
    std::string predef = generate_predef(blank);
    if (config().developer_debug){
        cbprintf("%s\n", predef.c_str());
        if (dps) *dps = 0;
        if (dpsr) *dpsr = 0;
        if (dpse) *dpse = 0;
        if (sim_time) *sim_time = 0;
        return 0;
    }
    cl_device_id device_used = blank.device_list[blank.opencl_device_id].device_id;
    cl_context context = blank.device_list[blank.opencl_device_id].context;
    cl_command_queue queue = blank.device_list[blank.opencl_device_id].queue;

    if (!queue){
        cl_int err;

        cbprintf("Open Device %d: %s\n", blank.opencl_device_id, blank.device_list[blank.opencl_device_id].device_name);

        queue = blank.device_list[blank.opencl_device_id].queue = clCreateCommandQueue(blank.device_list[blank.opencl_device_id].context, device_used, 0, &err);
        if (queue == 0) {
            cbprintf("Can't create command queue %d\n", err);
            return -1;
        }

        cbprintf("OK!\n");
    }

    cl_program program;
    cl_int err;
    char buf[32];
    std::string hashkey = predef + blank.apl + "@" + _itoa(blank.opencl_device_id, buf, 10);
    if (!ttprobe(hashkey, &program)){
        // compile kernel
        cbprintf("JIT ...\n");
        source += config().kernel_arms_str; // todo: select kernel source by spec.
        source = predef + source;
        source += "void scan_apl( rtinfo_t* rti ) {";
        source += blank.apl;
        source += "}\n";
        const char* cptr = source.c_str();
        program = clCreateProgramWithSource(context, 1, &cptr, 0, 0);
        if (program == 0) {
            cbprintf("clCreateProgramWithSource failed.\n");
            return -1;
        }
        if ((err = clBuildProgram(program, 1, &device_used, "-cl-single-precision-constant -cl-denorms-are-zero -cl-fast-relaxed-math", 0, 0)) != CL_SUCCESS) {
            cbprintf("Can't build program\n");
            size_t len;
            char buffer[204800];
            cl_build_status bldstatus;
            cbprintf("\nError %d: Failed to build program executable\n", err);
            err = clGetProgramBuildInfo(program, device_used, CL_PROGRAM_BUILD_STATUS, sizeof(bldstatus), (void*)&bldstatus, &len);
            if (err != CL_SUCCESS)
            {
                cbprintf("Build Status error %d\n", err);
                return -1;
            }
            if (bldstatus == CL_BUILD_SUCCESS) cbprintf("Build Status: CL_BUILD_SUCCESS\n");
            if (bldstatus == CL_BUILD_NONE) cbprintf("Build Status: CL_BUILD_NONE\n");
            if (bldstatus == CL_BUILD_ERROR) cbprintf("Build Status: CL_BUILD_ERROR\n");
            if (bldstatus == CL_BUILD_IN_PROGRESS) cbprintf("Build Status: CL_BUILD_IN_PROGRESS\n");
            err = clGetProgramBuildInfo(program, device_used, CL_PROGRAM_BUILD_OPTIONS, sizeof(buffer), buffer, &len);
            if (err != CL_SUCCESS)
            {
                cbprintf("Build Options error %d\n", err);
                return -1;
            }
            cbprintf("Build Options: %s\n", buffer);
            err = clGetProgramBuildInfo(program, device_used, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
            if (err != CL_SUCCESS)
            {
                cbprintf("Build Log error %d\n", err);
                return -1;
            }
            cbprintf("Build Log:\n%s\n", buffer);
            return -1;
        }
        ttsave(hashkey, program);
    }
    else{
        // already compiled

    }

    if (program == 0) {
        cbprintf("Can't load or build program\n");
        return -1;
    }
    cl_kernel sim_iterate = clCreateKernel(program, "sim_iterate", 0);
    if (sim_iterate == 0) {
        cbprintf("Can't load kernel\n");
        return -1;
    }
    cl_mem cl_res = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(cl_float) * blank.iterations, NULL, NULL);
    if (cl_res == 0) {
        cbprintf("Can't create OpenCL buffer\n");
        return -1;
    }
    float* res = new float[blank.iterations];
    auto t2 = std::chrono::high_resolution_clock::now();


    cl_uint setseed = blank.seed ? blank.seed : rand();
    clSetKernelArg(sim_iterate, 0, sizeof(cl_mem), &cl_res);
    clSetKernelArg(sim_iterate, 1, sizeof(cl_uint), &setseed);
    clSetKernelArg(sim_iterate, 2, sizeof(cl_uint), &blank.gear_str);
    clSetKernelArg(sim_iterate, 3, sizeof(cl_uint), &blank.gear_crit);
    clSetKernelArg(sim_iterate, 4, sizeof(cl_uint), &blank.gear_haste);
    clSetKernelArg(sim_iterate, 5, sizeof(cl_uint), &blank.gear_mastery);
    clSetKernelArg(sim_iterate, 6, sizeof(cl_uint), &blank.gear_mult);
    clSetKernelArg(sim_iterate, 7, sizeof(cl_uint), &blank.gear_vers);

    cbprintf("Sim ...\n");
    size_t work_size = blank.iterations;
    err = clEnqueueNDRangeKernel(queue, sim_iterate, 1, 0, &work_size, 0, 0, 0, 0);


    float ret, dev;

    if (err == CL_SUCCESS) {
        err = clEnqueueReadBuffer(queue, cl_res, CL_TRUE, 0, sizeof(float) * blank.iterations, &res[0], 0, 0, 0);
        if (err != CL_SUCCESS) {
            cbprintf("Can't read back data %d\n", err);
            ret = -1.0;
        }
        else {
            ret = prefix_mean(res, blank.iterations);
            dev = prefix_stddev(res, blank.iterations, ret);
        }
    }
    else {
        cbprintf("Can't run kernel %d\n", err);
        ret = -1.0;
    }
    if (dps) *dps = ret;
    if (dpsr) *dpsr = dev;
    if (dpse) *dpse = 2.0 * dev / sqrt(blank.iterations);


    cbprintf("DPS %.3f\n", ret);
    cbprintf("DPS Range(stddev) %.3f\n", dev);
    cbprintf("DPS Error(95%% conf.) %.3f\n", 2.0 * dev / sqrt(blank.iterations));
    delete[] res;
    clReleaseKernel(sim_iterate);
    clReleaseMemObject(cl_res);

    auto t3 = std::chrono::high_resolution_clock::now();
    float dummy;
    std::chrono::duration<double> time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>( t3 - t1 );
    std::chrono::duration<double> time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>( t3 - t2 );
    cbprintf( "Total elapsed time %.3fs\n", time_span1.count() );
    cbprintf( "Simulation time %.3fs\n", ((sim_time?*sim_time:dummy)=time_span2.count()) );
    cbprintf( "Speedup %dx\n", ( int )( blank.iterations * blank.max_length / time_span2.count() ));

    if (ret < 0.0)
        return -1;
    return 0;
}

const char* ic_apltranslate_s(const char* simc_style){
    std::string input(simc_style);
    static std::string output;
    output.clear();
    sapltr(input, output);
    return output.c_str();
}

const char* ic_apltranslate_f(const char* filename){
    std::string input(filename);
    static std::string output;
    output.clear();
    fapltr(input, output);
    return output.c_str();
}