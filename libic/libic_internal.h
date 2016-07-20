/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
    */

#ifndef LIBIC_INTL_H_INCLUDED
#define LIBIC_INTL_H_INCLUDED

#define IC_INTL

#define _CRT_SECURE_NO_WARNINGS
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif
#include <cstdio>
#include <cstdlib>
#include <string>
#include <chrono>
#include <random>
#include <unordered_map>
#include <intrin.h>
#include "util.h"
#include "libic.h"

struct raidbuff_t {
    int flask;
    int food;
    int potion;
    int bloodlust;
};

struct ic_computedevice_t {
    int id;
    cl_device_id device_id;
    cl_context context;
    cl_command_queue queue;
    char* platform_name;
    char* device_name;
    ic_computedevice_t() : platform_name( 0 ), device_name( 0 ), context( 0 ), queue( 0 ) { }
};

struct config_t {
    cl_uint gear_str;
    cl_uint gear_crit;
    cl_uint gear_haste;
    cl_uint gear_mastery;
    cl_uint gear_vers;
    raidbuff_t raidbuff;
    cl_uint seed;
    std::string apl;
    std::string simc_actions;
    int spec;
    int iterations;
    float vary_combat_length;
    float max_length;
    float initial_health_percentage;
    float death_pct;
    float power_max;
    int num_enemies;
    int plate_specialization;
    int race;
    float mh_speed;
    float oh_speed;
    int mh_low, mh_high;
    int oh_low, oh_high;
    int mh_type;
    int oh_type;
    int talent;
    int rng_engine;
    int strict_gcd;
    int sync_melee;
    int wbr_never_expire;
    int default_actions;
    int archmages_incandescence;
    int archmages_greater_incandescence;
    int legendary_ring;
    int t17_2pc;
    int t17_4pc;
    int t18_2pc;
    int t18_4pc;
    int thunderlord_mh;
    int thunderlord_oh;
    int bleeding_hollow_mh;
    int bleeding_hollow_oh;
    int shattered_hand_mh;
    int shattered_hand_oh;
    int razorice_mh;
    int razorice_oh;
    int fallen_crusader_mh;
    int fallen_crusader_oh;
    int trinket1;
    int trinket2;
    int trinket1_ilvl;
    int trinket2_ilvl;
    int enemy_is_demonic;
    int opencl_device_id;
    int developer_debug;
    ic_printcb_t printcb;
    struct {
        char* kernel_str;
        char* entry_str;
        char* common_str;
        char* warrior_str;
        char* arms_str;
        char* fury_str;
        char* paladin_str;
        char* retribution_str;
        char* deathknight_str;
        char* frost_dk_str;
    } kernel;
    FILE* output_file;
    std::vector<ic_computedevice_t> device_list;
    unsigned long long last_signature;
    config_t() {
        memset( this, 0, sizeof *this );
        srand( ( unsigned int ) time( NULL ) );
        rng_engine = 32;
        strict_gcd = 1;
        sync_melee = 1;
        wbr_never_expire = 1;
        apl = "";
        simc_actions = "";
        iterations = 50000;
        vary_combat_length = 20.0f;
        max_length = 450.0f;
        initial_health_percentage = 100.0f;
        power_max = 100.0f;
        num_enemies = 1;
        mh_speed = 1.5f;
        oh_speed = 1.5f;
        mh_type = 2;
        oh_type = 2;
        printcb = &vprintf;
        device_list.clear();
    }
};

IC_LOCAL int cbprintf( const char* format, ... );
// apltr
IC_LOCAL int fapltr( std::string& input_file, std::string& output );
IC_LOCAL int sapltr( std::string& input, std::string& output );
#endif