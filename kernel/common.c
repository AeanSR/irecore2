/**
    IreCore kernel - Common Abstraction

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/* race list */
#define RACE_NONE 0
#define RACE_HUMAN 1
#define RACE_DWARF 2
#define RACE_GNOME 3
#define RACE_NIGHTELF_DAY 4
#define RACE_NIGHTELF_NIGHT 5
#define RACE_DRAENEI 6
#define RACE_WORGEN 7
#define RACE_ORC 8
#define RACE_TROLL 9
#define RACE_TAUREN 10
#define RACE_UNDEAD 11
#define RACE_BLOODELF 12
#define RACE_GOBLIN 13
#define RACE_PANDAREN 14

/* class list */
#define CLASS_WARRIOR 0
#define CLASS_DEATHKNIGHT 1
#define CLASS_PALADIN 2

#define SPEC_ARMS 0
#define SPEC_FURY 1
#define SPEC_FROST_DK 2
#define SPEC_UNHOLY 3
#define SPEC_RETRIBUTION 4

/* race base strength */
deviceonly( __constant ) k32s racial_base_str[] = {
    0, 0, 5, -5, -4, -4, 66, 3, 3, 1, 5, -1, -3, -3, 0,
};

/* proc state. */
typedef struct {
    time_t cd;
} ICD_t;
typedef struct {
    time_t lasttimeattemps;
    time_t lasttimeprocs;
} RPPM_t;

/* weapon type list */
#define WEAPON_2H 0
#define WEAPON_1H 1
#define WEAPON_DAGGER 2

/* weapon info */
typedef struct weapon_t {
    float speed;
    k32u low;
    k32u high;
    k32u type;
} weapon_t;
deviceonly( __constant ) weapon_t weapon[] = {
    {
        MH_SPEED,
        MH_LOW,
        MH_HIGH,
        MH_TYPE,
    },
    {
        OH_SPEED,
        OH_LOW,
        OH_HIGH,
        OH_TYPE,
    },
};

/* normalized weapon speed lut */
deviceonly( __constant ) float normalized_weapon_speed[] = {
    3.3f,
    2.4f,
    1.7f,
};


/* common state infos. */
struct common_state_t {
#if (BUFF_POTION == 1)
    struct {
        time_t expire;
        time_t cd;
    } potion;
#define potion_expire (rti->player.common->potion.expire)
#define potion_cd     (rti->player.common->potion.cd)
#else
#define potion_expire (0)
#define potion_cd     (0)
#endif
#if (BUFF_BLOODLUST == 1)
    struct {
        time_t expire;
        time_t cd;
    } bloodlust;
#define bloodlust_expire (rti->player.common->bloodlust.expire)
#define bloodlust_cd     (rti->player.common->bloodlust.cd)
#else
#define bloodlust_expire (0)
#define bloodlust_cd     (0)
#endif
#if (RACE == RACE_BLOODELF)
    time_t arcane_torrent;
#define arcane_torrent_cd (rti->player.common->arcane_torrent)
#else
#define arcane_torrent_cd (0)
#endif
#if (RACE == RACE_TROLL)
    struct {
        time_t cd;
        time_t expire;
    } berserking;
#define berserking_cd     (rti->player.common->berserking.cd)
#define berserking_expire (rti->player.common->berserking.expire)
#else
#define berserking_cd     (0)
#define berserking_expire (0)
#endif
#if (RACE == RACE_ORC)
    struct {
        time_t cd;
        time_t expire;
    } blood_fury;
#define blood_fury_cd     (rti->player.common->blood_fury.cd)
#define blood_fury_expire (rti->player.common->blood_fury.expire)
#else
#define blood_fury_cd     (0)
#define blood_fury_expire (0)
#endif
#if (RACE == RACE_UNDEAD)
    ICD_t           touch_of_the_grave;
#endif
#if defined(trinket_gronntooth_war_horn)
    struct {
        time_t expire;
        RPPM_t proc;
    } gronntooth_war_horn;
#define gronntooth_war_horn_expire (rti->player.common->gronntooth_war_horn.expire)
#else
#define gronntooth_war_horn_expire (0)
#endif
};
struct common_debuff_t {

};

/* proc rate processor */
void proc_ICD( rtinfo_t* rti, ICD_t* state, float chance, time_t cooldown, k32u routnum, k32u target_id ) {
    if ( ( !state->cd || state->cd <= rti->timestamp ) && uni_rng( rti ) < chance ) {
        state->cd = TIME_OFFSET( cooldown );
        eq_enqueue( rti, rti->timestamp, routnum, target_id );
    }
}
void proc_PPM( rtinfo_t* rti, float PPM, weapon_t* weapon, k32u routnum, k32u target_id ) {
    if ( uni_rng( rti ) < ( PPM * weapon->speed / 60.0f ) ) {
        eq_enqueue( rti, rti->timestamp, routnum, target_id );
    }
}
void proc_RPPM( rtinfo_t* rti, RPPM_t* state, float RPPM, k32u routnum, k32u target_id ) {
    if ( state->lasttimeattemps == rti->timestamp ) return;
    float proc = RPPM * min( TO_SECONDS( rti->timestamp - state->lasttimeattemps ), 10.0f ) / 60.0f;
    state->lasttimeattemps = rti->timestamp;
    proc *= max( 1.0f, 1.0f + ( min( TO_SECONDS( rti->timestamp - state->lasttimeprocs ), 1000.0f ) / ( 60.0f / RPPM ) - 1.5f ) * 3.0f );
    if ( uni_rng( rti ) < proc ) {
        eq_enqueue( rti, rti->timestamp, routnum, target_id );
        state->lasttimeprocs = rti->timestamp;
    }
}

/* Power gain. */
float spec_power_gain( rtinfo_t* rti, float power );
void power_gain( rtinfo_t* rti, float power ) {
    power = spec_power_gain( rti, power );
    rti->player.power = min( power_max, rti->player.power + power );
}

/* Power check. */
float spec_power_check( rtinfo_t* rti, float cost );
kbool power_check( rtinfo_t* rti, float cost ) {
    cost = spec_power_check( rti, cost );
    if ( cost <= rti->player.power ) return 1;
    return 0;
}

/* Power consume. */
float spec_power_consume( rtinfo_t* rti, float cost );
void power_consume( rtinfo_t* rti, float cost ) {
    assert( power_check( rti, cost ) ); /* Power should suffice. */
    cost = spec_power_consume( rti, cost );
    rti->player.power -= cost;
}

float spec_str_coefficient( rtinfo_t* rti );

/* stat processor */
void refresh_str( rtinfo_t* rti ) {
    float fstr = ( float ) rti->player.stat.gear_str;
    k32u str;
    float coeff = spec_str_coefficient( rti );
    if ( PLATE_SPECIALIZATION ) coeff *= 1.05f;
    str = convert_uint_rtz( fstr * coeff );
    fstr = 10233; /* Base str @lvl 110. */ // TODO: this may vary between classes. Pal confirmed.
    fstr += racial_base_str[RACE]; /* Racial str. */
    str += convert_uint_rtz( fstr * coeff );
    rti->player.stat.str = str;
}

void refresh_ap( rtinfo_t* rti ) {
    k32u ap = rti->player.stat.str;
    if ( UP( blood_fury_expire ) ) ap += 2243;
    rti->player.stat.ap = ap;
}

float spec_mastery_coefficient( rtinfo_t* rti );
float spec_mastery_increament( rtinfo_t* rti );

void refresh_mastery( rtinfo_t* rti ) {
    float mastery = ( float ) rti->player.stat.gear_mastery;
    if ( RACE == RACE_HUMAN ) mastery = floor( mastery * 1.02f );
    mastery = spec_mastery_coefficient( rti ) * ( 0.08f + mastery / 35000 ) + spec_mastery_increament( rti );
    rti->player.stat.mastery = mastery;
}

float spec_crit_increament( rtinfo_t* rti );

void refresh_crit( rtinfo_t* rti ) {
    float crit = ( float ) rti->player.stat.gear_crit;
    if ( RACE == RACE_HUMAN ) crit = floor( crit * 1.02f );
    crit = 0.05f + crit / 35000 + spec_crit_increament( rti );
    if ( ( RACE == RACE_NIGHTELF_DAY ) || ( RACE == RACE_BLOODELF ) || ( RACE == RACE_WORGEN ) )
        crit += 0.01f;
    rti->player.stat.crit = crit;
}

float spec_haste_coefficient( rtinfo_t* rti );
float spec_haste_increament( rtinfo_t* rti );

void refresh_haste( rtinfo_t* rti ) {
    float haste = ( float ) rti->player.stat.gear_haste;
    if ( RACE == RACE_HUMAN ) haste = floor( haste * 1.02f );
    haste = 1.0f + haste / 32500;
    if ( ( RACE == RACE_NIGHTELF_NIGHT ) || ( RACE == RACE_GOBLIN ) || ( RACE == RACE_GNOME ) )
        haste *= 1.01f;
    if ( UP( berserking_expire ) ) haste *= 1.15f;
    if ( UP( bloodlust_expire ) ) haste *= 1.3f;
    haste *= spec_haste_coefficient( rti );
    haste += spec_haste_increament( rti );
    rti->player.stat.haste = haste - 1.0f;
}

void refresh_vers( rtinfo_t* rti ) {
    float vers = ( float ) rti->player.stat.gear_vers;
    if ( RACE == RACE_HUMAN ) vers = floor( vers * 1.02f );
    vers = vers / 40000;
    rti->player.stat.vers = vers;
}

float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand );

float ap_dmg( rtinfo_t* rti, float ap_multiplier );

enum {
    ATYPE_WHITE_MELEE,
    ATYPE_YELLOW_MELEE,
    ATYPE_SPELL,
    DTYPE_DIRECT,
    DTYPE_PHYSICAL,
    DTYPE_SHADOW,
    DTYPE_FIRE,
    DTYPE_FROST,
    DTYPE_HOLY,
};
enum {
    DICE_MISS,
    DICE_CRIT,
    DICE_HIT,
};

void special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id );

k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate );
k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate );

float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor );

/* Event list. */
#define DECL_EVENT( name ) void event_##name ( rtinfo_t* rti, k32u target_id )
#define HOOK_EVENT( name ) case routnum_##name: event_##name( rti, e.target_id ); break;
#define DECL_SPELL( name ) int spell_##name ( rtinfo_t* rti )
#define SPELL( name ) safemacro(if(spell_##name ( rti )) return;)
#define SPELL_ALIAS( alias, origin, condition ) int spell_##alias ( rtinfo_t* rti ) { if (condition) return spell_##origin ( rti ); else return 0; }
enum {
    START_OF_COMMON_ROUTNUM = 0,
    routnum_gcd_expire,
#if (BUFF_POTION == 1)
    routnum_potion_start,
    routnum_potion_cd,
    routnum_potion_expire,
#endif
#if (BUFF_BLOODLUST == 1)
    routnum_bloodlust_cast,
    routnum_bloodlust_expire,
#endif
#if (RACE == RACE_BLOODELF)
    routnum_arcane_torrent_cd,
    routnum_arcane_torrent_execute,
#endif
#if (RACE == RACE_TROLL)
    routnum_berserking_start,
    routnum_berserking_expire,
    routnum_berserking_cd,
#endif
#if (RACE == RACE_ORC)
    routnum_blood_fury_start,
    routnum_blood_fury_expire,
    routnum_blood_fury_cd,
#endif
#if (RACE == RACE_UNDEAD)
    routnum_touch_of_the_grave_trigger,
#endif
#if defined(trinket_gronntooth_war_horn)
    routnum_gronntooth_war_horn_trigger,
    routnum_gronntooth_war_horn_expire,
#endif
    START_OF_CLASS_ROUTNUM,
};

// === General Cooldown =======================================================
void gcd_start( rtinfo_t* rti, time_t length, kbool scale_haste ) {
    if ( scale_haste ) length = length / ( 1.0f + rti->player.stat.haste );
    rti->player.gcd = TIME_OFFSET( max( length, FROM_SECONDS( 0.75 ) ) );
    eq_enqueue( rti, rti->player.gcd, routnum_gcd_expire, 0 );
}

DECL_EVENT( gcd_expire ) {
    /* Do nothing. */
}

// === potion =================================================================
#if (BUFF_POTION == 1)
DECL_EVENT( potion_expire ) {
    lprintf( ( "potion end" ) );
    rti->player.stat.gear_str -= 1000;
    refresh_str( rti );
    refresh_ap( rti );
}

DECL_EVENT( potion_cd ) {
    lprintf( ( "potion cd" ) );
}

DECL_EVENT( potion_start ) {
    lprintf( ( "potion start" ) );
    rti->player.stat.gear_str += 1000;
    refresh_str( rti );
    refresh_ap( rti );
    potion_expire = TIME_OFFSET( FROM_SECONDS( 25 ) );
    eq_enqueue( rti, potion_expire, routnum_potion_expire, target_id );
}

DECL_SPELL( potion ) {
    if ( potion_cd > rti->timestamp ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_potion_start, 0 );
    if ( rti->timestamp == FROM_SECONDS( 0 ) ) {
        potion_cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
        eq_enqueue( rti, potion_cd, routnum_potion_cd, 0 );
    } else {
        potion_cd = rti->expected_combat_length + 1;
    }
    return 1;
}
#else
DECL_SPELL( potion ) {
    return 0;
}
#endif

// === bloodlust ==============================================================
#if (BUFF_BLOODLUST == 1)
DECL_EVENT( bloodlust_expire ) {
    lprintf( ( "blodlust end" ) );
    refresh_haste( rti );
}

DECL_EVENT( bloodlust_cast ) {
    bloodlust_expire = TIME_OFFSET( FROM_SECONDS( 30 ) );
    eq_enqueue( rti, bloodlust_expire, routnum_bloodlust_expire, 0 );
    bloodlust_cd = TIME_OFFSET( FROM_SECONDS( 600 ) );
    eq_enqueue( rti, bloodlust_cd, routnum_bloodlust_cast, 0 );
    refresh_haste( rti );
    lprintf( ( "bloodlust start" ) );
}
#endif

// === enchants ===============================================================


// === racial traits ==========================================================
#if (RACE == RACE_BLOODELF)
DECL_EVENT( arcane_torrent_cd ) {
    lprintf( ( "arcane_torrent ready" ) );
}
DECL_EVENT( arcane_torrent_execute ) {
    lprintf( ( "cast arcane_torrent" ) );
}

DECL_SPELL( arcane_torrent ) {
    if ( arcane_torrent_cd > rti->timestamp ) return 0;
    if ( rti->player.gcd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    arcane_torrent_cd = TIME_OFFSET( FROM_SECONDS( 90 ) ); // 120->90 patch 6.2.2
    eq_enqueue( rti, arcane_torrent_cd, routnum_arcane_torrent_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_arcane_torrent_execute, 0 );
    if ( CLASS == CLASS_WARRIOR ) power_gain( rti, 15.0f );
    if ( CLASS == CLASS_DEATHKNIGHT ) power_gain( rti, 20.0f );
    // retpal gain nothing.
    lprintf( ( "cast arcane_torrent" ) );
    return 1;
}
#else
DECL_SPELL( arcane_torrent ) {
    return 0;
}
#endif

#if (RACE == RACE_TROLL)
DECL_EVENT( berserking_cd ) {
    lprintf( ( "berserking ready" ) );
}
DECL_EVENT( berserking_start ) {
    lprintf( ( "berserking start" ) );
    refresh_haste( rti );
}
DECL_EVENT( berserking_expire ) {
    lprintf( ( "berserking expire" ) );
    refresh_haste( rti );
}

DECL_SPELL( berserking ) {
    if ( berserking_cd > rti->timestamp ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_berserking_start, 0 );
    berserking_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, berserking_expire, routnum_berserking_expire, 0 );
    berserking_cd = TIME_OFFSET( FROM_SECONDS( 180 ) );
    eq_enqueue( rti, berserking_cd, routnum_berserking_cd, 0 );
    lprintf( ( "cast berserking" ) );
    return 1;
}
#else
DECL_SPELL( berserking ) {
    return 0;
}
#endif

#if (RACE == RACE_ORC)
DECL_EVENT( blood_fury_cd ) {
    lprintf( ( "blood_fury ready" ) );
}
DECL_EVENT( blood_fury_start ) {
    lprintf( ( "blood_fury start" ) );
    refresh_ap( rti );
}
DECL_EVENT( blood_fury_expire ) {
    lprintf( ( "blood_fury expire" ) );
    refresh_ap( rti );
}

DECL_SPELL( blood_fury ) {
    if ( blood_fury_cd > rti->timestamp ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_blood_fury_start, 0 );
    blood_fury_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, blood_fury_expire, routnum_blood_fury_expire, 0 );
    blood_fury_cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, blood_fury_cd, routnum_blood_fury_cd, 0 );
    lprintf( ( "cast blood_fury" ) );
    return 1;
}
#else
DECL_SPELL( blood_fury ) {
    return 0;
}
#endif
#if (RACE == RACE_UNDEAD)
DECL_EVENT( touch_of_the_grave_trigger ) {
    // old data for 6.2.0
    //float d = 1932.0f;
    //d += uni_rng( rti ) * ( 2244.0f - 1932.0f );
    float d = 0.5f * rti->player.stat.ap; // To avoid SMF bonus.
    d *= 2.0f; // 2015.11.19 hotfix
    deal_damage( rti, target_id, d, DTYPE_SHADOW, DICE_HIT, 0, 0 );
}
#endif

// === trinkets ===============================================================
#if defined(trinket_gronntooth_war_horn)
DECL_EVENT( gronntooth_war_horn_trigger ) {
    if ( !UP( gronntooth_war_horn_expire ) ) {
        rti->player.stat.gear_str += trinket_gronntooth_war_horn;
        refresh_str( rti );
        refresh_ap( rti );
    }
    gronntooth_war_horn_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, gronntooth_war_horn_expire, routnum_gronntooth_war_horn_expire, target_id );
    lprintf( ( "gronntooth_war_horn trigger" ) );
}
DECL_EVENT( gronntooth_war_horn_expire ) {
    if ( gronntooth_war_horn_expire == rti->timestamp ) {
        lprintf( ( "gronntooth_war_horn expire" ) );
        gronntooth_war_horn_expire = 0;
        rti->player.stat.gear_str -= trinket_gronntooth_war_horn;
        refresh_str( rti );
        refresh_ap( rti );
    }
}
#endif

void class_routine_entries( rtinfo_t* rti, _event_t e );

void routine_entries( rtinfo_t* rti, _event_t e ) {
    if ( e.routine >= START_OF_CLASS_ROUTNUM ) {
        class_routine_entries( rti, e );
    } else switch ( e.routine ) {
            HOOK_EVENT( gcd_expire );
#if (BUFF_BLOODLUST == 1)
            HOOK_EVENT( bloodlust_cast );
            HOOK_EVENT( bloodlust_expire );
#endif
#if (BUFF_POTION == 1)
            HOOK_EVENT( potion_start );
            HOOK_EVENT( potion_cd );
            HOOK_EVENT( potion_expire );
#endif
#if (RACE == RACE_BLOODELF)
            HOOK_EVENT( arcane_torrent_cd );
            HOOK_EVENT( arcane_torrent_execute );
#endif
#if (RACE == RACE_TROLL)
            HOOK_EVENT( berserking_start );
            HOOK_EVENT( berserking_expire );
            HOOK_EVENT( berserking_cd );
#endif
#if (RACE == RACE_ORC)
            HOOK_EVENT( blood_fury_start );
            HOOK_EVENT( blood_fury_expire );
            HOOK_EVENT( blood_fury_cd );
#endif
#if (RACE == RACE_UNDEAD)
            HOOK_EVENT( touch_of_the_grave_trigger );
#endif
#if defined(trinket_gronntooth_war_horn)
            HOOK_EVENT( gronntooth_war_horn_trigger );
            HOOK_EVENT( gronntooth_war_horn_expire );
#endif
        default:
            lprintf( ( "wild common routine entry %d", e.routine ) );
            assert( 0 );
        }
}

#define initialize_rppm( proc ) safemacro(proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 ))

void class_module_init( rtinfo_t* rti );

void module_init( rtinfo_t* rti ) {
    class_module_init( rti );

    refresh_str( rti );
    refresh_ap( rti );
    refresh_crit( rti );
    refresh_haste( rti );
    refresh_mastery( rti );
    refresh_vers( rti );

    lprintf( ( "Raid buffed str %d", rti->player.stat.str ) );
    lprintf( ( "Raid buffed ap %d", rti->player.stat.ap ) );
    lprintf( ( "Raid buffed crit %f", rti->player.stat.crit ) );
    lprintf( ( "Raid buffed haste %f", rti->player.stat.haste ) );
    lprintf( ( "Raid buffed mastery %f", rti->player.stat.mastery ) );
    lprintf( ( "Raid buffed vers %f", rti->player.stat.vers ) );

#if (BUFF_BLOODLUST == 1)
    eq_enqueue( rti, rti->timestamp, routnum_bloodlust_cast, 0 );
#endif
#if (BUFF_POTION == 1)
    spell_potion( rti );
#endif
#if defined(trinket_gronntooth_war_horn)
    initialize_rppm( rti->player.common->gronntooth_war_horn.proc );
#endif // defined
}

void class_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id );

void special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    if ( DICE_MISS != dice ) {
#if (RACE == RACE_UNDEAD)
        proc_ICD( rti, &rti->player.common->touch_of_the_grave, 0.2f, FROM_SECONDS( 15 ), routnum_touch_of_the_grave_trigger, target_id );
#endif
        if ( ATYPE_WHITE_MELEE == attacktype || ATYPE_YELLOW_MELEE == attacktype ) {
#if defined(trinket_gronntooth_war_horn)
            proc_RPPM( rti, &rti->player.common->gronntooth_war_horn.proc, 1.5f, routnum_gronntooth_war_horn_trigger, target_id );
#endif
        }
    }
    class_special_procs( rti, attacktype, dice, target_id );
}
