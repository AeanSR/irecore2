/**
    IreCore kernel

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014, 2015 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/*
    TODO list:
    Touch of the Grave (Undead trait) is a mystery. Need more feedbacks since I play nelf only.
    Now implemented as 20%-15s ICD, (0.5*ap) damage scales with enrage, mastery and vers. Do not crit.
*/

#define SHOW_LOG
#define passive_power_regen 0

#if !defined(__OPENCL_VERSION__)
/* Front-end gives these defines. */
#define STRICT_GCD 1
#define WBR_NEVER_EXPIRE 1
#define AVATAR_LIKE_BLOODBATH 0
#define SYNC_MELEE 1
#define RNG_MWC64X
#define vary_combat_length 20.0f
#define max_length 450.0f
#define initial_health_percentage 100.0f
#define death_pct 0.0f
#define iterations 1
#define power_max 120.0f
#define num_enemies 20
#define GLYPH_OF_RAGINGWIND 1
#define PLATE_SPECIALIZATION 1
#define SINGLE_MINDED 0
#define BUFF_STR_AGI_INT 1
#define BUFF_AP 1
#define BUFF_CRIT 1
#define BUFF_HASTE 1
#define BUFF_MASTERY 1
#define BUFF_MULT 1
#define BUFF_VERS 1
#define BUFF_SP 1
#define BUFF_STA 1
#define BUFF_POTION 1
#define BUFF_BLOODLUST 1
#define RACE RACE_UNDEAD
#define MH_LOW 1659
#define MH_HIGH 2490
#define MH_SPEED 3.6f
#define MH_TYPE WEAPON_2H
#define OH_LOW 1659
#define OH_HIGH 2490
#define OH_SPEED 3.6f
#define OH_TYPE WEAPON_2H
#define TALENT_TIER3 2
#define TALENT_TIER4 1
#define TALENT_TIER6 2
#define TALENT_TIER7 1
#define archmages_incandescence 0
#define archmages_greater_incandescence 0
//#define legendary_ring 2500
#define t17_2pc 0
#define t17_4pc 0
#define t18_2pc 1
#define t18_4pc 1
#define thunderlord_mh 0
#define thunderlord_oh 0
#define bleedinghollow_mh 0
#define bleedinghollow_oh 0
#define shatteredhand_mh 1
#define shatteredhand_oh 1
//#define trinket_vial_of_convulsive_shadows 2033
//#define trinket_forgemasters_insignia 181
//#define trinket_horn_of_screaming_spirits 2652
//#define trinket_scabbard_of_kyanos 2200
//#define trinket_badge_of_victory 1456
//#define trinket_insignia_of_victory 867
//#define trinket_tectus_beating_heart 2304
//#define trinket_formidable_fang 1743
//#define trinket_draenic_stone 1414
//#define trinket_skull_of_war 2120
//#define trinket_mote_of_the_mountain 1517
//#define trinket_worldbreakers_resolve 220
//#define trinket_discordant_chorus 20564
#define trinket_empty_drinking_horn 259
//#define trinket_unending_hunger 54
//#define trinket_spores_of_alacrity 2304
//#define trinket_bonemaws_big_toe 1767
//#define trinket_emberscale_talisman 1767
#define trinket_gronntooth_war_horn 1152
#define ENEMY_IS_DEMONIC 1
#endif /* !defined(__OPENCL_VERSION__) */

/* Debug on Host! */
#if !defined(__OPENCL_VERSION__)
#ifndef _DEBUG
#define _DEBUG
#endif /* _DEBUG */
#endif /* !defined(__OPENCL_VERSION__) */

/* Codes enclosed in 'hostonly' will be discarded at OpenCL devices, and vice versa. */
#if defined(__OPENCL_VERSION__)
#define hostonly(code)
#define deviceonly(code) code
#else
#define hostonly(code) code
#define deviceonly(code)
#endif /* defined(__OPENCL_VERSION__) */
#if defined(_MSC_VER)
#define msvconly(code) code
#else
#define msvconly(code)
#endif /* defined(_MSC_VER) */

/* Macro guard word. */
#define safemacro(v) do{v;}while(0)

/* Std C Library. */
#if !defined(__OPENCL_VERSION__)
int printf( const char* format, ... );
void abort( void );
void* malloc( unsigned long long );
void free( void* );
#define KRNL_STR2(v) #v
#define KRNL_STR(v) KRNL_STR2(v)
#endif /* !defined(__OPENCL_VERSION__) */

/* Diagnostic. */
#if defined(_DEBUG) && !defined(__OPENCL_VERSION__)
#if defined(_MSC_VER)
#define hfuncname __FUNCTION__
#else
#define hfuncname __func__
#endif /* defined(_MSC_VER) */
#define assert(expression) if(!(expression)){ \
        printf("Assertion failed: %s, function %s, file %s, line %d.\n", \
                KRNL_STR(expression),  hfuncname ,__FILE__, __LINE__); \
                abort(); }else
#else
#define assert(expression)
#endif /* defined(_DEBUG) && !defined(__OPENCL_VERSION__) */

/* Unified typename. */
#if defined(__OPENCL_VERSION__)
#define kbool bool
#define k8s char
#define k8u uchar
#define k16s short
#define k16u ushort
#define k32s int
#define k32u uint
#define k64s long
#define k64u ulong
#define K64S_C(num) (num##L)
#define K64U_C(num) (num##UL)
#else
#define kbool int
#define k8s signed char
#define k8u unsigned char
#define k16s short int
#define k16u unsigned short int
#define k32s long int
#define k32u unsigned long int
#define k64s long long int
#define k64u unsigned long long int
#define K64S_C(num) (num##LL)
#define K64U_C(num) (num##ULL)
#define convert_ushort_sat(num) ((num) < 0 ? (k16u)0 : (num) > 0xffff ? (k16u)0xffff : (k16u)(num))
#define convert_ushort_rtp(num) ((k16u)(num) + !!((float)(num) - (float)(k16u)(num)))
#define convert_uint_rtp(num) ((k32u)(num) + !!((float)(num) - (float)(k32u)(num)))
#define convert_uint_rtz(num) ((k32u)(num))
float convert_float_rtp( k64u x ) {
    union {
        k32u u;
        float f;
    } u;
    u.f = ( float )x;
    if( ( k64u )u.f < x && x < K64U_C( 0xffffff8000000000 ) )
        u.u++;
    return u.f;
}
#endif /* defined(__OPENCL_VERSION__) */

/*
    Assumed char is exactly 8 bit.
    Most std headers will pollute the namespace, thus we do not use CHAR_BIT,
    which is defined in <limits.h>.
*/
#define K64U_MSB ( K64U_C( 1 ) << (sizeof(k64u) * 8 - 1) )

/* Unified compile hint. */
#if defined(__OPENCL_VERSION__)
#define kdeclspec(attr) __attribute__((attr))
#define hdeclspec(attr)
#else
#define kdeclspec(attr)
#if defined(_MSC_VER)
#define hdeclspec __declspec
#else
#define hdeclspec(attr) __attribute__((attr))
#endif /* defined(_MSC_VER) */
#endif /* defined(__OPENCL_VERSION__) */

/* get_global_id() on Host. */
#if !defined(__OPENCL_VERSION__)
#if defined(_MSC_VER)
#define htlsvar __declspec(thread)
#else
#define htlsvar __thread
#endif /* defined(_MSC_VER) */
htlsvar int global_idx[3] = {0};
int get_global_id( int dim ) {
    return global_idx[dim];
}
void set_global_id( int dim, int idx ) {
    global_idx[dim] = idx;
}
#endif /* !defined(__OPENCL_VERSION__) */

/* Const Pi. */
#if !defined(M_PI)
#define M_PI 3.14159265358979323846
#endif /* !defined(M_PI) */

/* Math utilities on Host. */
#if !defined(__OPENCL_VERSION__)
double cos( double x );
#define cospi(x) cos( (double)(x) * M_PI )
double sqrt( double x );
double log( double x );
double clamp( double val, double min, double max ) {
    return val < min ? min : val > max ? max : val;
}
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mix(x, y, a) ((x) + (( (y) - (x) ) * (a)))
#define mad_hi(x,y,c) ((k32u)(((k64u)(x) * (k64u)(y)) >> 32) + (c))
#endif /* !defined(__OPENCL_VERSION__) */

/* Seed struct which holds the current state. */
#if defined(RNG_MT127)
typedef struct {
    k32u mt[4]; /* State words. */
    k32u mti;   /* State counter: must be within [0,3]. */
} seed_t;
#elif defined(RNG_MWC64X)
typedef struct {
    k32u x;
    k32u c;
} seed_t;
#else
typedef struct {
    k32u holdrand;
} seed_t;
#endif

typedef k32u time_t;
#define FROM_SECONDS( sec ) ((time_t)convert_uint_rtp((float)(sec) * 1000.0f))
#define FROM_MILLISECONDS( msec ) ((time_t)(msec))
#define TO_SECONDS( timestamp ) (convert_float_rtp((k32u)timestamp) * 0.001f)
#define TIME_OFFSET( time ) ((time_t)((k32s)rti->timestamp + (k32s)time))
#define TIME_DISTANT( time ) ((time_t)max((k32s)(time) - (k32s)(rti->timestamp), 0))
#define UP( time_to_check ) ( rti->player.time_to_check && rti->player.time_to_check > rti->timestamp )
#define REMAIN( time_to_check ) ((time_t)max(((k32s)rti->player.time_to_check - (k32s)rti->timestamp), 0))

/* Event queue. */
#define EQ_SIZE_EXP (num_enemies < 15 ? 7 : 8)
#define EQ_SIZE ((1 << EQ_SIZE_EXP) - 1)
typedef struct {
    time_t time;
    k32u target_id;
    k32u routine;
} _event_t;
typedef struct {
    k32u count;
    time_t power_suffice;
    _event_t event[EQ_SIZE];
} event_queue_t;
hostonly(
    static k32u maxqueuelength = 0;
)

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

deviceonly( __constant ) k32s racial_base_str[] = {
    0, 0, 5, -5, -4, -4, 66, 3, 3, 1, 5, -1, -3, -3, 0,
};

/* Declarations from class modules. */
typedef struct {
    time_t cd;
} ICD_t;
typedef struct {
    time_t lasttimeattemps;
    time_t lasttimeprocs;
} RPPM_t;
typedef struct {
    time_t cd;
} bloodthirst_t;
typedef struct {
    k32u stack;
    time_t expire;
} ragingblow_t;
typedef struct {
    k32u stack;
    time_t expire;
} meatcleaver_t;
typedef struct {
    time_t expire;
} ragingwind_t;
typedef struct {
    time_t expire;
} enrage_t;
typedef struct {
    k32u stack;
    time_t expire;
} bloodsurge_t;
typedef struct {
    time_t expire;
    RPPM_t proc;
} suddendeath_t;
typedef struct {
    time_t cd;
} berserkerrage_t;
typedef struct {
    time_t cd;
    time_t expire;
} recklessness_t;
typedef struct {
    time_t cd;
} stormbolt_t;
typedef struct {
    time_t cd;
} shockwave_t;
typedef struct {
    time_t cd;
} dragonroar_t;
typedef struct {
    time_t cd;
    time_t expire;
} avatar_t;
typedef struct {
    time_t cd;
    time_t expire;
} bloodbath_t;
typedef struct {
    float pool;
    float ticks;
    time_t dot_start;
} bloodbath_dot_t;
typedef struct {
    time_t cd;
    time_t expire;
} bladestorm_t;
typedef struct {
    time_t cd;
    time_t expire;
} ravager_t;
typedef struct {
    time_t cd;
} siegebreaker_t;
typedef struct {
    time_t expire;
    time_t cd;
} potion_t;
typedef struct {
    time_t expire;
    k32u stack;
} rampage_t;
typedef struct {
    time_t expire;
    RPPM_t proc;
} incandescence_t;
typedef struct {
    time_t expire;
    time_t cd;
    float dmg_snapshot;
} thorasus_the_stone_heart_of_draenor_t;
typedef struct {
    time_t expire;
    k32u extend;
    RPPM_t proc;
} thunderlord_t;
typedef struct {
    time_t expire;
    RPPM_t proc;
} bleedinghollow_t;
typedef struct {
    RPPM_t proc;
} shatteredhand_t;
typedef struct {
    time_t expire;
    float ticks;
} shatteredhand_dot_t;
typedef struct {
    time_t cd;
} arcanetorrent_t;
typedef struct {
    time_t cd;
    time_t expire;
} berserking_t;
typedef struct {
    time_t cd;
    time_t expire;
} bloodfury_t;

typedef struct weapon_t {
    float speed;
    k32u low;
    k32u high;
    k32u type;
} weapon_t;

#define WEAPON_2H 0
#define WEAPON_1H 1
#define WEAPON_DAGGER 2

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

deviceonly( __constant ) float normalized_weapon_speed[] = {
    3.3f,
    2.4f,
    1.7f,
};

typedef struct stat_t {
    k32u gear_str;
    k32u gear_crit;
    k32u gear_haste;
    k32u gear_mastery;
    k32u gear_mult;
    k32u gear_vers;
    float crit;
    float haste;
    float mastery;
    float mult;
    float vers;
    k32u str;
    k32u ap;
} stat_t;

/* Player struct, filled by the class module. */
typedef struct {
    float power;
#if (passive_power_regen)
    float power_regen;
#endif
    stat_t stat;
//#if (TALENT_TIER3 != 3)
    bloodthirst_t   bloodthirst;
//#endif
    ragingblow_t    ragingblow;
    enrage_t        enrage;
    bloodsurge_t    bloodsurge;
    berserkerrage_t berserkerrage;
    recklessness_t  recklessness;
    meatcleaver_t   meatcleaver;
#if (GLYPH_OF_RAGINGWIND)
    ragingwind_t    ragingwind;
#endif
#if (TALENT_TIER3 == 2)
    suddendeath_t   suddendeath;
#endif
#if (TALENT_TIER4 == 1)
    stormbolt_t     stormbolt;
#endif
#if (TALENT_TIER4 == 2)
    shockwave_t     shockwave;
#endif
#if (TALENT_TIER4 == 3)
    dragonroar_t    dragonroar;
#endif
#if (TALENT_TIER6 == 1)
    avatar_t        avatar;
#endif
#if (TALENT_TIER6 == 2)
    bloodbath_t     bloodbath;
#endif
#if (TALENT_TIER6 == 3)
    bladestorm_t    bladestorm;
#endif
#if (TALENT_TIER7 == 2)
    ravager_t       ravager;
#endif
#if (TALENT_TIER7 == 3)
    siegebreaker_t  siegebreaker;
#endif
#if (BUFF_POTION == 1)
    potion_t potion;
#endif
#if (t17_4pc)
    rampage_t       rampage;
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
    incandescence_t incandescence;
#endif
#if defined(legendary_ring)
    thorasus_the_stone_heart_of_draenor_t thorasus_the_stone_heart_of_draenor;
#endif
#if (thunderlord_mh)
    thunderlord_t   enchant_mh;
#endif
#if (thunderlord_oh)
    thunderlord_t   enchant_oh;
#endif
#if (bleedinghollow_mh)
    bleedinghollow_t enchant_mh;
#endif
#if (bleedinghollow_oh)
    bleedinghollow_t enchant_oh;
#endif
#if (shatteredhand_mh)
    shatteredhand_t enchant_mh;
#endif
#if (shatteredhand_oh)
    shatteredhand_t enchant_oh;
#endif
#if (RACE == RACE_BLOODELF)
    arcanetorrent_t arcanetorrent;
#endif
#if (RACE == RACE_TROLL)
    berserking_t    berserking;
#endif
#if (RACE == RACE_ORC)
    bloodfury_t     bloodfury;
#endif
#if (RACE == RACE_UNDEAD)
    ICD_t           touch_of_the_grave;
#endif
#if defined(trinket_vial_of_convulsive_shadows)
    struct {
        time_t cd;
        time_t expire;
    } vial_of_convulsive_shadows;
#endif
#if defined(trinket_forgemasters_insignia)
    struct {
        time_t expire;
        k32u stack;
        RPPM_t proc;
    } forgemasters_insignia;
#endif
#if defined(trinket_horn_of_screaming_spirits)
    struct {
        time_t expire;
        RPPM_t proc;
    } horn_of_screaming_spirits;
#endif
#if defined(trinket_scabbard_of_kyanos)
    struct {
        time_t cd;
        time_t expire;
    } scabbard_of_kyanos;
#endif
#if defined(trinket_badge_of_victory)
    struct {
        time_t cd;
        time_t expire;
    } badge_of_victory;
#endif
#if defined(trinket_insignia_of_victory)
    struct {
        time_t expire;
        ICD_t proc;
    } insignia_of_victory;
#endif
#if defined(trinket_tectus_beating_heart)
    struct {
        time_t expire;
        RPPM_t proc;
    } tectus_beating_heart;
#endif
#if defined(trinket_formidable_fang)
    struct {
        time_t expire;
        RPPM_t proc;
    } formidable_fang;
#endif
#if defined(trinket_draenic_stone)
    struct {
        time_t expire;
        ICD_t proc;
    } draenic_stone;
#endif
#if defined(trinket_skull_of_war)
    struct {
        time_t expire;
        ICD_t proc;
    } skull_of_war;
#endif
#if defined(trinket_mote_of_the_mountain)
    struct {
        time_t expire;
        RPPM_t proc;
    } mote_of_the_mountain;
#endif
#if defined(trinket_worldbreakers_resolve)
    struct {
        time_t expire;
        k32u   stack;
        k32u   target;
    } worldbreakers_resolve;
#endif
#if defined(trinket_discordant_chorus)
    RPPM_t discordant_chorus;
#endif
#if defined(trinket_unending_hunger)
    struct {
        time_t expire;
        k32u stack;
        RPPM_t proc;
    } unending_hunger;
#endif
#if defined(trinket_spores_of_alacrity)
    struct {
        time_t expire;
        RPPM_t proc;
    } spores_of_alacrity;
#endif
#if defined(trinket_bonemaws_big_toe)
    struct {
        time_t cd;
        time_t expire;
    } bonemaws_big_toe;
#endif
#if defined(trinket_emberscale_talisman)
    struct {
        time_t cd;
        time_t expire;
    } emberscale_talisman;
#endif
#if defined(trinket_gronntooth_war_horn)
    struct {
        time_t expire;
        RPPM_t proc;
    } gronntooth_war_horn;
#endif
    time_t gcd;
    k32u target;
}
player_t;

typedef struct {
    k32u id;
#if (TALENT_TIER6 == 2)
    bloodbath_dot_t     bloodbath;
#endif
#if (shatteredhand_mh)
    shatteredhand_dot_t enchant_mh;
#endif
#if (shatteredhand_oh)
    shatteredhand_dot_t enchant_oh;
#endif
#if defined(trinket_empty_drinking_horn)
    struct {
        time_t expire;
        k32u stack;
    } empty_drinking_horn;
#endif
} enemy_t;

/* Runtime info struct, each thread preserves its own. */
typedef struct {
    time_t timestamp;
    seed_t seed;
    event_queue_t eq;
    float damage_collected;
    player_t player;
    enemy_t enemy[num_enemies];
    time_t expected_combat_length;

}
rtinfo_t;

/* Formated time print. */
hostonly(
void tprint( rtinfo_t* rti ) {
    printf( "%02d:%02d.%03d ", rti->timestamp / 60000, ( rti->timestamp % 60000 ) / 1000, ( ( rti->timestamp % 60000 ) % 1000 ) );
}
)
#if defined(SHOW_LOG)
#define lprintf(v) hostonly(safemacro({tprint(rti);printf v;printf("\n");}))
#else
#define lprintf(v)
#endif /* defined(SHOW_LOG) */

/* Declaration Action Priority List (APL) */
void scan_apl( rtinfo_t* rti ); /* Implement is generated by front-end. */

/*
    Event routine entries. Each class module implement its own.
    Each type of event should be assigned to a routine number.
    Given routine number 'routine_entries' select the corresponding function to call.
*/
void routine_entries( rtinfo_t* rti, _event_t e );
/** Routine number 0xFF indicates the end of simulation. */
#define EVENT_END_SIMULATION ((k32u)-1)

/*
    Class modules may need an initializer, link it here.
*/
void module_init( rtinfo_t* rti );

/* Initialize RNG */
#if defined(RNG_MT127)
void rng_init( rtinfo_t* rti, k32u seed ) {
    rti->seed.mti = 0; /* Reset counter */
    /* Use a LCG to fill state matrix. See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
    rti->seed.mt[0] = seed & 0xffffffffUL;
    seed = ( 1812433253UL * ( seed ^ ( seed >> 30 ) ) ) + 1;
    rti->seed.mt[1] = seed & 0xffffffffUL;
    seed = ( 1812433253UL * ( seed ^ ( seed >> 30 ) ) ) + 2;
    rti->seed.mt[2] = seed & 0xffffffffUL;
    /* Due to multiple run for same kernel, set thread id into state words to avoid seed overlapping. */
    seed = ( k32u )get_global_id( 0 );
    seed = ( 1812433253UL * ( seed ^ ( seed >> 30 ) ) ) + 3;
    rti->seed.mt[3] = seed & 0xffffffffUL;
}
#elif defined(RNG_MWC64X)
void rng_init( rtinfo_t* rti, k32u seed ) {
    rti->seed.x = seed;
    /* Due to multiple run for same kernel, set thread id into state words to avoid seed overlapping. */
    rti->seed.c = ( k32u )get_global_id( 0 );
}
#else
void rng_init( rtinfo_t* rti, k32u seed ) {
    seed = ( 1812433253UL * ( seed ^ ( seed >> 30 ) ) ) + 1;
    /* Due to multiple run for same kernel, set thread id into state words to avoid seed overlapping. */
    rti->seed.holdrand = seed + ( k32u )get_global_id( 0 );
}
#endif
/* Generate one IEEE-754 single precision float point uniformally distributed in the interval [.0f, 1.0f). */
#if defined(RNG_MT127)
/*
    Minimalist Mersenne Twister for OpenCL
    MT by Makoto Matsumoto, See http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
*/
float uni_rng( rtinfo_t* rti ) {
    k32u y; /* Should be a register. */
    assert( rti->seed.mti < 4 ); /* If not, RNG is uninitialized. */

    /* Concat lower-right and upper-left state bits. */
    y = ( rti->seed.mt[rti->seed.mti] & 0xfffffffeU ) | ( rti->seed.mt[( rti->seed.mti + 1 ) & 3] & 0x00000001U );
    /* Compute next state with the recurring equation. */
    y = rti->seed.mt[rti->seed.mti] = rti->seed.mt[( rti->seed.mti + 2 ) & 3] ^ ( y >> 1 ) ^ ( 0xfa375374U & -( k32s )( y & 0x1U ) );
    /* Increase the counter */
    rti->seed.mti = ( rti->seed.mti + 1 ) & 3;
    /* Tempering */
    y ^= ( y >> 12 );
    y ^= ( y << 7 ) & 0x33555f00U;
    y ^= ( y << 15 ) & 0xf5f78000U;
    y ^= ( y >> 18 );
    /* Mask to IEEE-754 format [1.0f, 2.0f). */
    y = ( ( y & 0x3fffffffU ) | 0x3f800000U );
    return ( *( float* )&y ) - 1.0f; /* Decrease to [.0f, 1.0f). */
}
#elif defined(RNG_MWC64X)
/*
    Part of MWC64X by David Thomas, dt10@imperial.ac.uk
    This is provided under BSD, full license is with the main package.
    See http://www.doc.ic.ac.uk/~dt10/research
*/
float uni_rng( rtinfo_t* rti ) {
    k32u Xn = 4294883355U * rti->seed.x + rti->seed.c;
    k32u Cn = mad_hi( 4294883355U, rti->seed.x, ( k32u )( Xn < rti->seed.c ) );
    rti->seed.x = Xn;
    rti->seed.c = Cn;
    k32u y = Xn ^ Cn;
    /* Mask to IEEE-754 format [1.0f, 2.0f). */
    y = ( ( y & 0x3fffffffU ) | 0x3f800000U );
    return ( *( float* )&y ) - 1.0f; /* Decrease to [.0f, 1.0f). */
}
#else
/*
    Classic 32-bit LCG known as "rand".
*/
float uni_rng( rtinfo_t* rti ) {
    rti->seed.holdrand = rti->seed.holdrand * 214013 + 2531011;
    k32u y = rti->seed.holdrand;
    /* Mask to IEEE-754 format [1.0f, 2.0f). */
    y = ( ( y & 0x3fffffffU ) | 0x3f800000U );
    return ( *( float* )&y ) - 1.0f; /* Decrease to [.0f, 1.0f). */
}
#endif

/* Generate one IEEE-754 single precision float point with standard normal distribution. */
float stdnor_rng( rtinfo_t* rti ) {
    /*
        The max number generated by uni_rng() should equal to:
            as_float( 0x3fffffff ) - 1.0f => as_float( 0x3f7ffffe )
        Thus, we want transform the interval to (.0f, 1.0f], we should add:
            1.0f - as_float( 0x3f7ffffe ) => as_float( 0x34000000 )
        Which is representable by decimal 1.1920929E-7.
        With a minimal value 1.1920929E-7, the max vaule stdnor_rng could give is approximately 5.64666.
    */
    return ( float )( sqrt( -2.0f * log( uni_rng( rti ) + 1.1920929E-7 ) ) * cospi( 2.0f * uni_rng( rti ) ) );
    /*
        To get another individual normally distributed number in pair, replace 'cospi' to 'sinpi'.
        It's simply thrown away here, because of diverge penalty.
        With only one thread in a warp need to recalculate, the whole warp must diverge.
    */
}

/* Enqueue an event into EQ. */
_event_t* eq_enqueue( rtinfo_t* rti, time_t trigger, k32u routine, k32u target_id ) {
    k32u i = ++( rti->eq.count );
    _event_t* p = &( rti->eq.event[-1] );

    assert( rti->eq.count <= EQ_SIZE ); /* Full check. */
    /* Count max queue length on debug. */
    hostonly(
        maxqueuelength = max( maxqueuelength, rti->eq.count );
    )

    /*
        There are two circumstances which could cause the assert below fail:
        1. Devs got something wrong in the class module, enqueued an event happens before 'now'.
        2. Time register is about to overflow, the triggering delay + current timestamp have exceeded the max representable time.
        Since the later circumstance is not a fault, we would just throw the event away and continue quietly.
        When you are exceeding the max time limits, all new events will be thrown, and finally you will get an empty EQ,
        then the empty checks on EQ will fail.
        */
    if ( rti->timestamp <= trigger ) {
        for ( ; i > 1 && p[i >> 1].time > trigger; i >>= 1 )
            p[i] = p[i >> 1];
        p[i] = ( _event_t ) {
            .time = trigger, .routine = routine, .target_id = target_id
        };
        return &p[i];
    }

    return 0;
}

/* Enqueue a power suffice event into EQ. */
void eq_enqueue_ps( rtinfo_t* rti, time_t trigger ) {
    if ( trigger >= rti->timestamp )
        if ( !rti->eq.power_suffice || rti->eq.power_suffice > trigger )
            rti->eq.power_suffice = trigger;
}

/* Power gain. */
void power_gain( rtinfo_t* rti, float power ) {
    rti->player.power = min( power_max, rti->player.power + power );
}

/* Power check. */
kbool power_check( rtinfo_t* rti, float cost ) {
    if ( cost <= rti->player.power ) return 1;
#if (passive_power_regen)
    if ( rti->player.power_regen > 0 )
        eq_enqueue_ps( rti, TIME_OFFSET( FROM_SECONDS( ( cost - rti->player.power ) / rti->player.power_regen ) ) );
#endif
    return 0;
}

#if (TALENT_TIER7 == 1)
void anger_management_count( rtinfo_t* rti, float rage );
#endif

/* Power consume. */
void power_consume( rtinfo_t* rti, float cost ) {
    assert( power_check( rti, cost ) ); /* Power should suffice. */
    rti->player.power -= cost;
#if (TALENT_TIER7 == 1)
    anger_management_count( rti, cost );
#endif
}

/* Execute the top priority. */
int eq_execute( rtinfo_t* rti ) {
    k32u i, child;
    _event_t min, last;
    _event_t* p = &rti->eq.event[-1];

    assert( rti->eq.count ); /* Empty check. */
    assert( rti->eq.count <= EQ_SIZE ); /* Not zero but negative? */
    assert( rti->timestamp <= p[1].time ); /* Time won't go back. */
    assert( !rti->eq.power_suffice || rti->timestamp <= rti->eq.power_suffice ); /* Time won't go back. */

    ///* If time jumps over 1 second, insert a check point (as a power suffice event). */
    //if ( FROM_SECONDS( 1 ) < TIME_DISTANT( p[1].time ) &&
    //        ( !rti->eq.power_suffice || FROM_SECONDS( 1 ) < TIME_DISTANT( rti->eq.power_suffice ) ) )
    //    rti->eq.power_suffice = TIME_OFFSET( FROM_SECONDS( 1 ) );

    /* When time elapse, trigger a full scanning at APL. */
    if ( rti->timestamp < p[1].time
            && ( !rti->eq.power_suffice || rti->timestamp <= rti->eq.power_suffice )
       ) {
        if ( !STRICT_GCD || !UP( gcd ) ) /* Strict GCD: Do not scal APL if GCD is up. */
            scan_apl( rti ); /* This may change p[1]. */

        /* Check again. */
        assert( rti->eq.count );
        assert( rti->eq.count <= EQ_SIZE );
        assert( rti->timestamp <= p[1].time );
        assert( !rti->eq.power_suffice || rti->timestamp <= rti->eq.power_suffice );
    }

    min = p[1];

    if ( !rti->eq.power_suffice || rti->eq.power_suffice >= min.time ) {

        /* Delete from heap. */
        last = p[rti->eq.count--];
        for( i = 1; i << 1 <= rti->eq.count; i = child ) {
            child = i << 1;
            if ( child != rti->eq.count && rti->eq.event[child].time < p[child].time )
                child++;
            if ( last.time > p[child].time )
                p[i] = p[child];
            else
                break;
        }
        p[i] = last;

        /* Now 'min' contains the top priority. Execute it. */
#if ( passive_power_regen )
        power_gain( rti, TO_SECONDS( min.time - rti->timestamp ) * rti->player.power_regen );
#endif
        rti->timestamp = min.time;

        if ( min.routine == EVENT_END_SIMULATION ) /* Finish the simulation here. */
            return 0;

        /* TODO: Some preparations? */
        routine_entries( rti, min );
        /* TODO: Some finishing works? */

    } else {
        /* Invoke power suffice routine. */
#if ( passive_power_regen )
        power_gain( rti, TO_SECONDS( rti->eq.power_suffice - rti->timestamp ) * rti->player.power_regen );
#endif
        rti->timestamp = rti->eq.power_suffice;
        rti->eq.power_suffice = 0;
        /*
            Power suffices would not make any impact, just a reserved APL scanning.
            The scanning will occur when timestamp elapses next time, not immediately.
         */
    }

    return 1;
}

float enemy_health_percent( rtinfo_t* rti ) {
    /*
        What differs from SimulationCraft, OpenCL iterations are totally parallelized.
        It's impossible to determine mob initial health by the results from previous iterations.
        The best solution here is to use a linear mix of time to approximate the health precent,
        which is used in SimC for the very first iteration.
    */
    time_t remainder = max( ( k32u )FROM_SECONDS( 0 ), ( k32u )( rti->expected_combat_length - rti->timestamp ) );
    return mix( death_pct, initial_health_percentage, ( float )remainder / ( float )rti->expected_combat_length );
}

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


void sim_init( rtinfo_t* rti, k32u seed ) {
    /* Analogize get_global_id for CPU. */
    hostonly(
        static int gid = 0;
        set_global_id( 0, gid++ );
    )

    /* RNG. */
    rng_init( rti, seed );

    /* Combat length. */
    assert( vary_combat_length < max_length ); /* Vary can't be greater than max. */
    assert( vary_combat_length + max_length < 2147483.647f );
    rti->expected_combat_length = FROM_SECONDS( max_length + vary_combat_length * clamp( stdnor_rng( rti ) * ( 1.0f / 3.0f ), -1.0f, 1.0f ) );

    /* Construct Enemies. */
    for ( int i = 0; i != num_enemies; i++ ) {
        rti->enemy[i].id = i;
    }

    /* Class module initializer. */
    module_init( rti );

    eq_enqueue( rti, rti->expected_combat_length, EVENT_END_SIMULATION, 0 );

}

/* Single iteration logic. */
deviceonly( __kernel ) void sim_iterate(
    deviceonly( __global ) float* dps_result,
    k32u deterministic_seed,
    k32u gear_str,
    k32u gear_crit,
    k32u gear_haste,
    k32u gear_mastery,
    k32u gear_mult,
    k32u gear_vers
) {
    deviceonly( __private ) rtinfo_t _rti;
    /* Write zero to RTI. */
    _rti = ( rtinfo_t ) {
        0
    };

    _rti.player.stat.gear_str = gear_str;
    _rti.player.stat.gear_crit = gear_crit;
    _rti.player.stat.gear_haste = gear_haste;
    _rti.player.stat.gear_mastery = gear_mastery;
    _rti.player.stat.gear_mult = gear_mult;
    _rti.player.stat.gear_vers = gear_vers;

    sim_init(
        &_rti,
        ( k32u )deterministic_seed + ( k32u )get_global_id( 0 )
    );

    while( eq_execute( &_rti ) );

    dps_result[get_global_id( 0 )] = _rti.damage_collected / TO_SECONDS( _rti.expected_combat_length );
}

/* Class module. */
void refresh_str( rtinfo_t* rti ) {
    float fstr = ( float )rti->player.stat.gear_str;
    k32u str;
    float coeff = 1.0f;
    if ( PLATE_SPECIALIZATION ) coeff *= 1.05f;
    if ( BUFF_STR_AGI_INT ) coeff *= 1.05f;
#if (archmages_incandescence || archmages_greater_incandescence)
    if ( UP( incandescence.expire ) ) coeff *= archmages_greater_incandescence ? 1.15f : 1.1f;
#endif
    str = convert_uint_rtz( fstr * coeff );
    fstr = 1455; /* Base str @lvl 100. */
    fstr += racial_base_str[RACE]; /* Racial str. */
    str += convert_uint_rtz( fstr * coeff );
    rti->player.stat.str = str;
}

void refresh_ap( rtinfo_t* rti ) {
    k32u ap = rti->player.stat.str;
    if ( BUFF_AP ) ap = convert_uint_rtz( ap * 1.1f + 0.5f );
#if (RACE == RACE_ORC)
    if ( UP( bloodfury.expire ) ) ap += 345;
#endif
    rti->player.stat.ap = ap;
}

void refresh_mastery( rtinfo_t* rti ) {
    float mastery = ( float )rti->player.stat.gear_mastery;
#if (bleedinghollow_mh)
    if ( UP( enchant_mh.expire ) ) mastery += 500.0f;
#endif
#if (bleedinghollow_oh)
    if ( UP( enchant_oh.expire ) ) mastery += 500.0f;
#endif
    if ( BUFF_MASTERY ) mastery += 550;
    mastery = 1.4f * ( 0.08f + mastery / 11000 );
    rti->player.stat.mastery = mastery;
}

void refresh_crit( rtinfo_t* rti ) {
    float crit = ( float )rti->player.stat.gear_crit;
#if (thunderlord_mh)
    if ( UP( enchant_mh.expire ) ) crit += 500.0f;
#endif
#if (thunderlord_oh)
    if ( UP( enchant_oh.expire ) ) crit += 500.0f;
#endif
    crit *= 1.05f;
    crit = 0.05f + crit / 11000;
    if ( BUFF_CRIT ) crit += 0.05f;
    if ( ( RACE == RACE_NIGHTELF_DAY ) || ( RACE == RACE_BLOODELF ) || ( RACE == RACE_WORGEN ) )
        crit += 0.01f;
#if (t17_4pc)
    if ( UP( rampage.expire ) ) {
        crit += 0.06f * rti->player.rampage.stack;
    }
#endif
    rti->player.stat.crit = crit;
}

void refresh_haste( rtinfo_t* rti ) {
    float haste = ( float )rti->player.stat.gear_haste;
    haste = 1.0f + haste / 9000;
    if ( BUFF_HASTE ) haste *= 1.05f;
    if ( ( RACE == RACE_NIGHTELF_NIGHT ) || ( RACE == RACE_GOBLIN ) || ( RACE == RACE_GNOME ) )
        haste *= 1.01f;
#if (RACE == RACE_TROLL)
    if ( UP( berserking.expire ) ) haste *= 1.15f;
#endif
    if ( BUFF_BLOODLUST hostonly( && rti->timestamp ) ) if ( ( rti->timestamp % FROM_SECONDS( 600 ) ) < FROM_SECONDS( 30 ) ) haste *= 1.3f;
#if defined(trinket_worldbreakers_resolve)
    haste *= 1.0f + ( trinket_worldbreakers_resolve * rti->player.worldbreakers_resolve.stack ) * 0.0001;
#endif
    rti->player.stat.haste = haste - 1.0f;
}

void refresh_mult( rtinfo_t* rti ) {
    float mult = ( float )rti->player.stat.gear_mult;
    mult = mult / 6600;
    if ( BUFF_MULT ) mult += 0.05f;
    rti->player.stat.mult = mult;
}

void refresh_vers( rtinfo_t* rti ) {
    float vers = ( float )rti->player.stat.gear_vers;
    if ( RACE == RACE_HUMAN ) vers += 100;
    vers = vers / 13000;
    if ( BUFF_VERS ) vers += 0.03f;
    rti->player.stat.vers = vers;
}

float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand ) {
    float dmg = ( float )weapon[offhand].low;
    dmg += uni_rng( rti ) * ( weapon[offhand].high - weapon[offhand].low );
    dmg += ( normalized ? normalized_weapon_speed[weapon[offhand].type] : weapon[offhand].speed ) * rti->player.stat.ap / 3.5f;
    dmg *= weapon_multiplier;
    /* Crazed Berserker */
    if ( offhand ) dmg *= 0.5f * ( SINGLE_MINDED ? 1.5f : 1.25f );
    if ( SINGLE_MINDED ) dmg *= 1.3f;
    return dmg;
}

float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap;
    if ( SINGLE_MINDED ) dmg *= 1.3f;
    return dmg;
}

/* Event list. */
#define DECL_EVENT( name ) void event_##name ( rtinfo_t* rti, k32u target_id )
#define HOOK_EVENT( name ) case routnum_##name: event_##name( rti, e.target_id ); break;
#define DECL_SPELL( name ) int spell_##name ( rtinfo_t* rti )
#define SPELL( name ) safemacro(if(spell_##name ( rti )) return;)
enum {
    routnum_gcd_expire,
    routnum_bloodthirst_execute,
#if (TALENT_TIER3 != 3)
    routnum_bloodthirst_cd,
#endif
    routnum_ragingblow_execute,
    routnum_ragingblow_trigger,
    routnum_ragingblow_expire,
    routnum_whirlwind_execute,
    routnum_meatcleaver_trigger,
    routnum_meatcleaver_expire,
    routnum_enrage_trigger,
    routnum_enrage_expire,
    routnum_execute_execute,
    routnum_wildstrike_execute,
    routnum_bloodsurge_trigger,
    routnum_bloodsurge_expire,
    routnum_auto_attack_mh,
    routnum_auto_attack_oh,
    routnum_berserkerrage_cd,
    routnum_recklessness_cd,
    routnum_recklessness_execute,
    routnum_recklessness_expire,
#if (GLYPH_OF_RAGINGWIND)
    routnum_ragingwind_trigger,
    routnum_ragingwind_expire,
#endif
#if (TALENT_TIER3 == 2)
    routnum_suddendeath_trigger,
    routnum_suddendeath_expire,
#endif
#if (TALENT_TIER4 == 1)
    routnum_stormbolt_execute,
    routnum_stormbolt_cd,
#endif
#if (TALENT_TIER4 == 2)
    routnum_shockwave_execute,
    routnum_shockwave_cd,
#endif
#if (TALENT_TIER4 == 3)
    routnum_dragonroar_execute,
    routnum_dragonroar_cd,
#endif
#if (TALENT_TIER6 == 1)
    routnum_avatar_start,
    routnum_avatar_expire,
    routnum_avatar_cd,
#endif
#if (TALENT_TIER6 == 2)
    routnum_bloodbath_start,
    routnum_bloodbath_cd,
    routnum_bloodbath_expire,
    routnum_bloodbath_tick,
#endif
#if (TALENT_TIER6 == 3)
    routnum_bladestorm_tick,
    routnum_bladestorm_cd,
#endif
#if (TALENT_TIER7 == 2)
    routnum_ravager_tick,
    routnum_ravager_cd,
#endif
#if (TALENT_TIER7 == 3)
    routnum_siegebreaker_execute,
    routnum_siegebreaker_cd,
#endif

#if (BUFF_BLOODLUST == 1)
    routnum_bloodlust_start,
    routnum_bloodlust_end,
#endif
#if (BUFF_POTION == 1)
    routnum_potion_start,
    routnum_potion_cd,
    routnum_potion_expire,
#endif

#if (t17_4pc)
    routnum_rampage_refresh,
    routnum_rampage_expire,
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
    routnum_incandescence_trigger,
    routnum_incandescence_expire,
#endif
#if defined(legendary_ring)
    routnum_thorasus_the_stone_heart_of_draenor_start,
    routnum_thorasus_the_stone_heart_of_draenor_expire,
    routnum_thorasus_the_stone_heart_of_draenor_cd,
#endif
#if (thunderlord_mh || bleedinghollow_mh || shatteredhand_mh)
    routnum_enchant_mh_trigger,
    routnum_enchant_mh_expire,
#endif
#if (shatteredhand_mh)
    routnum_enchant_mh_tick,
#endif
#if (thunderlord_oh || bleedinghollow_oh || shatteredhand_oh)
    routnum_enchant_oh_trigger,
    routnum_enchant_oh_expire,
#endif
#if (shatteredhand_oh)
    routnum_enchant_oh_tick,
#endif
#if (RACE == RACE_BLOODELF)
    routnum_arcanetorrent_cd,
    routnum_arcanetorrent_execute,
#endif
#if (RACE == RACE_TROLL)
    routnum_berserking_start,
    routnum_berserking_expire,
    routnum_berserking_cd,
#endif
#if (RACE == RACE_ORC)
    routnum_bloodfury_start,
    routnum_bloodfury_expire,
    routnum_bloodfury_cd,
#endif
#if (RACE == RACE_UNDEAD)
    routnum_touch_of_the_grave_trigger,
#endif
#if defined(trinket_vial_of_convulsive_shadows)
    routnum_vial_of_convulsive_shadows_expire,
    routnum_vial_of_convulsive_shadows_start,
    routnum_vial_of_convulsive_shadows_cd,
#endif
#if defined(trinket_forgemasters_insignia)
    routnum_forgemasters_insignia_tick,
#endif
#if defined(trinket_horn_of_screaming_spirits)
    routnum_horn_of_screaming_spirits_trigger,
    routnum_horn_of_screaming_spirits_expire,
#endif
#if defined(trinket_scabbard_of_kyanos)
    routnum_scabbard_of_kyanos_expire,
    routnum_scabbard_of_kyanos_start,
    routnum_scabbard_of_kyanos_cd,
#endif
#if defined(trinket_badge_of_victory)
    routnum_badge_of_victory_expire,
    routnum_badge_of_victory_start,
    routnum_badge_of_victory_cd,
#endif
#if defined(trinket_insignia_of_victory)
    routnum_insignia_of_victory_expire,
    routnum_insignia_of_victory_trigger,
#endif
#if defined(trinket_tectus_beating_heart)
    routnum_tectus_beating_heart_trigger,
    routnum_tectus_beating_heart_expire,
#endif
#if defined(trinket_formidable_fang)
    routnum_formidable_fang_trigger,
    routnum_formidable_fang_expire,
#endif
#if defined(trinket_draenic_stone)
    routnum_draenic_stone_expire,
    routnum_draenic_stone_trigger,
#endif
#if defined(trinket_skull_of_war)
    routnum_skull_of_war_expire,
    routnum_skull_of_war_trigger,
#endif
#if defined(trinket_mote_of_the_mountain)
    routnum_mote_of_the_mountain_trigger,
    routnum_mote_of_the_mountain_expire,
#endif
#if defined(trinket_worldbreakers_resolve)
    routnum_worldbreakers_resolve_expire,
    routnum_worldbreakers_resolve_trigger,
#endif
#if defined(trinket_discordant_chorus)
    routnum_discordant_chorus_trigger,
#endif
#if defined(trinket_empty_drinking_horn)
    routnum_empty_drinking_horn_trigger,
    routnum_empty_drinking_horn_expire,
    routnum_empty_drinking_horn_tick,
#endif
#if defined(trinket_unending_hunger)
    routnum_unending_hunger_trigger,
    routnum_unending_hunger_expire,
#endif
#if defined(trinket_spores_of_alacrity)
    routnum_spores_of_alacrity_trigger,
    routnum_spores_of_alacrity_expire,
#endif
#if defined(trinket_bonemaws_big_toe)
    routnum_bonemaws_big_toe_expire,
    routnum_bonemaws_big_toe_start,
    routnum_bonemaws_big_toe_cd,
#endif
#if defined(trinket_emberscale_talisman)
    routnum_emberscale_talisman_expire,
    routnum_emberscale_talisman_start,
    routnum_emberscale_talisman_cd,
#endif
#if defined(trinket_gronntooth_war_horn)
    routnum_gronntooth_war_horn_trigger,
    routnum_gronntooth_war_horn_expire,
#endif
};

enum {
    DMGTYPE_NONE,
    DMGTYPE_BLOODBATH,
    DMGTYPE_MELEE,
    DMGTYPE_ABILITY,
    DMGTYPE_SPECIAL,
};

void special_procs( rtinfo_t* rti, k32u target_id );

k32s deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, float extra_crit_rate, float extra_crit_bonus, kbool ignore_armor ) {
    switch( dmgtype ) {
    case DMGTYPE_NONE:
        if ( UP( enrage.expire ) ) {
            dmg *= 1.15f;
            dmg *= 1.0f + rti->player.stat.mastery;
        }
        dmg *= 1.0f + rti->player.stat.vers;
#if (TALENT_TIER6 == 1)
        if ( UP( avatar.expire ) )
            dmg *= 1.2f;
#endif
#if defined(legendary_ring)
        if ( UP( thorasus_the_stone_heart_of_draenor.expire ) )
            dmg *= 1.0f + legendary_ring * 0.0001;
#endif
#if ENEMY_IS_DEMONIC && defined(trinket_gronntooth_war_horn)
        if ( UP(gronntooth_war_horn.expire ) )
            dmg *= 1.1f;
#endif
    case DMGTYPE_BLOODBATH:
        lprintf( ( "damage %.0f", dmg ) );
        rti->damage_collected += dmg;
        return 0;
        break;
    default: {
        float c = uni_rng( rti );
        if ( dmgtype == DMGTYPE_MELEE && c < 0.19f ) return -1;
        float cr = rti->player.stat.crit - 0.03f + extra_crit_rate + ( dmgtype == DMGTYPE_MELEE ? 0.19f : 0 );
        float cdb = ( 1.0f + extra_crit_bonus ) * ( ( RACE == RACE_DWARF || RACE == RACE_TAUREN ) ? 2.04f : 2.0f );
        kbool ret;
        float fdmg;
#if (TALENT_TIER6 == 2) && !AVATAR_LIKE_BLOODBATH
        float bbcounter = rti->damage_collected;
#endif

        if ( UP( enrage.expire ) ) {
            dmg *= 1.15f;
            dmg *= 1.0f + rti->player.stat.mastery;
        }
        dmg *= 1.0f + rti->player.stat.vers;

        if ( UP( recklessness.expire ) ) {
            if( dmgtype == DMGTYPE_ABILITY ) cr += 0.3f;
            cdb *= 1.1f;
        }

        if ( !ignore_armor )
            dmg *= 0.650684f;
#if (TALENT_TIER6 == 1)
        if ( UP( avatar.expire ) )
            dmg *= 1.2f;
#endif
#if defined(legendary_ring)
        if ( UP( thorasus_the_stone_heart_of_draenor.expire ) )
            dmg *= 1.0f + legendary_ring * 0.0001;
#endif
#if ENEMY_IS_DEMONIC && defined(trinket_gronntooth_war_horn)
        if ( UP(gronntooth_war_horn.expire ) )
            dmg *= 1.1f;
#endif
#if (TALENT_TIER6 == 2) && AVATAR_LIKE_BLOODBATH
        if ( dmgtype == DMGTYPE_ABILITY && UP( bloodbath.expire ) ) {
            dmg *= 1.3f;
        }
#endif

        fdmg = dmg;
        if ( c < cr ) {
            ret = 1;
            fdmg *= cdb;
            lprintf( ( "damage *%.0f*", fdmg ) );
#if (thunderlord_mh)
            if ( UP( enchant_mh.expire ) && rti->player.enchant_mh.extend ) {
                rti->player.enchant_mh.extend --;
                rti->player.enchant_mh.expire += FROM_SECONDS( 2 );
                eq_enqueue( rti, rti->player.enchant_mh.expire, routnum_enchant_mh_expire, target_id );
            }
#endif
#if (thunderlord_oh)
            if ( UP( enchant_oh.expire ) && rti->player.enchant_oh.extend ) {
                rti->player.enchant_oh.extend --;
                rti->player.enchant_oh.expire += FROM_SECONDS( 2 );
                eq_enqueue( rti, rti->player.enchant_oh.expire, routnum_enchant_oh_expire, target_id );
            }
#endif
        } else {
            ret = 0;
            lprintf( ( "damage %.0f", fdmg ) );
        }
        rti->damage_collected += fdmg;

        float mr = rti->player.stat.mult;
        float m = uni_rng( rti );
        if ( m < mr ) {
            c = uni_rng( rti );
            fdmg = dmg * 0.3f;
            if ( c < cr ) {
                fdmg *= cdb;
                lprintf( ( "mult damage *%.0f*", fdmg ) );
            } else {
                lprintf( ( "mult damage %.0f", fdmg ) );
            }
            rti->damage_collected += fdmg;
        }
        m = uni_rng( rti );
        if ( m < mr ) {
            c = uni_rng( rti );
            fdmg = dmg * 0.3f;
            if ( c < cr ) {
                fdmg *= cdb;
                lprintf( ( "mult damage *%.0f*", fdmg ) );
            } else {
                lprintf( ( "mult damage %.0f", fdmg ) );
            }
            rti->damage_collected += fdmg;
        }

#if (TALENT_TIER6 == 2) && !AVATAR_LIKE_BLOODBATH
        if ( dmgtype == DMGTYPE_ABILITY && UP( bloodbath.expire ) ) {
            rti->enemy[target_id].bloodbath.pool += ( rti->damage_collected - bbcounter ) * 0.3f;
            rti->enemy[target_id].bloodbath.ticks = 6.0f;
            if ( rti->enemy[target_id].bloodbath.dot_start < rti->timestamp ) {
                rti->enemy[target_id].bloodbath.dot_start = rti->timestamp;
                eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_bloodbath_tick, target_id );
            }
        }
#endif
        if ( dmgtype == DMGTYPE_ABILITY || dmgtype == DMGTYPE_MELEE )
            special_procs( rti, target_id );
        return ret;
    }
    break;
    }

}

// === General Cooldown =======================================================
void gcd_start ( rtinfo_t* rti, time_t length ) {
    rti->player.gcd = TIME_OFFSET( length );
    eq_enqueue( rti, rti->player.gcd, routnum_gcd_expire, 0 );
}

DECL_EVENT( gcd_expire ) {
    /* Do nothing. */
}

// === Auto-attack ============================================================
DECL_EVENT( auto_attack_mh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 0 );

    k32s ret = deal_damage( rti, rti->player.target, d, DMGTYPE_MELEE, 0, 0, 0 );
    if ( ret == -1 ) {
        /* Miss */
        lprintf( ( "mh miss" ) );
    } else {
        power_gain( rti, 3.5f * weapon[0].speed );
#if (TALENT_TIER3 == 2)
        proc_RPPM( rti, &rti->player.suddendeath.proc, 2.5f * ( 1.0f + rti->player.stat.haste ), routnum_suddendeath_trigger, rti->player.target );
#endif
        if ( ret ) {
            /* Crit */
            lprintf( ( "mh crit" ) );
        } else {
            /* Hit */
            lprintf( ( "mh hit" ) );
        }
    }

#if (t17_4pc)
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[0].speed / ( 1.0f + rti->player.stat.haste
                                  + 0.06f * rti->player.rampage.stack
                                                                  ) ) ), routnum_auto_attack_mh, rti->player.target );
#else
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[0].speed / ( 1.0f + rti->player.stat.haste ) ) ), routnum_auto_attack_mh, rti->player.target );
#endif

#if defined(trinket_worldbreakers_resolve)
    eq_enqueue( rti, rti->timestamp, routnum_worldbreakers_resolve_trigger, rti->player.target );
#endif
}

DECL_EVENT( auto_attack_oh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 1 );
    k32s ret = deal_damage( rti, rti->player.target, d, DMGTYPE_MELEE, 0, 0, 0 );
    if ( ret == -1 ) {
        /* Miss */
        lprintf( ( "oh miss" ) );
    } else {
        power_gain( rti, 3.5f * weapon[1].speed * 0.5f );
#if (TALENT_TIER3 == 2)
        proc_RPPM( rti, &rti->player.suddendeath.proc, 2.5f * ( 1.0f + rti->player.stat.haste ), routnum_suddendeath_trigger, rti->player.target );
#endif
        if ( ret ) {
            /* Crit */
            lprintf( ( "oh crit" ) );
        } else {
            /* Hit */
            lprintf( ( "oh hit" ) );
        }
    }

#if (t17_4pc)
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / ( 1.0f + rti->player.stat.haste
                                  + 0.06f * rti->player.rampage.stack
                                                                  ) ) ), routnum_auto_attack_oh, rti->player.target );
#else
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / ( 1.0f + rti->player.stat.haste ) ) ), routnum_auto_attack_oh, rti->player.target );
#endif

#if defined(trinket_worldbreakers_resolve)
    eq_enqueue( rti, rti->timestamp, routnum_worldbreakers_resolve_trigger, rti->player.target );
#endif
}

// === enrage =================================================================
DECL_EVENT( enrage_trigger ) {
    power_gain( rti, 10.0f );
    rti->player.enrage.expire = TIME_OFFSET( FROM_SECONDS( 8 ) );
    eq_enqueue( rti, rti->timestamp, routnum_ragingblow_trigger, target_id );
    eq_enqueue( rti, rti->player.enrage.expire, routnum_enrage_expire, target_id );
    lprintf( ( "enrage trig" ) );
}

DECL_EVENT( enrage_expire ) {
    if ( rti->player.enrage.expire == rti->timestamp ) {
        lprintf( ( "enrage expire" ) );
    }
}

// === bloodthirst ============================================================
DECL_EVENT( bloodthirst_execute ) {
    float d = weapon_dmg( rti, 0.5f, 1, 0 );

    power_gain( rti, 10.0f );
#if (TALENT_TIER3 != 3)
    rti->player.bloodthirst.cd = TIME_OFFSET( FROM_SECONDS( 4.5 / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->player.bloodthirst.cd, routnum_bloodthirst_cd, target_id );
#endif
    if ( uni_rng( rti ) < 0.2f ) {
        eq_enqueue( rti, rti->timestamp, routnum_bloodsurge_trigger, target_id );
    }

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0.4f, 0, 0 ) ) {
        /* Crit */
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, target_id );
        lprintf( ( "bloodthirst crit" ) );

    } else {
        /* Hit */
        lprintf( ( "bloodthirst hit" ) );
    }

}

#if (TALENT_TIER3 != 3)
DECL_EVENT( bloodthirst_cd ) {
    lprintf( ( "bloodthirst ready" ) );
}
#endif

DECL_SPELL( bloodthirst ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
#if (TALENT_TIER3 != 3)
    if ( rti->player.bloodthirst.cd > rti->timestamp ) return 0;
#endif
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_bloodthirst_execute, rti->player.target );
    lprintf( ( "cast bloodthirst" ) );
    return 1;
}

// === ragingblow =============================================================
DECL_EVENT( ragingblow_execute ) {
    /* Main hand. */
    float d = weapon_dmg( rti, 2.0f, 1, 0 );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "ragingblow crit" ) );
#if (t17_2pc)
        if ( uni_rng( rti ) < 0.2 ) {
            eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, target_id );
        }
#endif
    } else {
        /* Hit */
        lprintf( ( "ragingblow hit" ) );
    }

    /* Off hand. */
    d = weapon_dmg( rti, 2.0, 1, 1 );
    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "ragingblow oh crit" ) );
#if (t17_2pc)
        if ( uni_rng( rti ) < 0.2 ) {
            eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, target_id );
        }
#endif
    } else {
        /* Hit */
        lprintf( ( "ragingblow oh hit" ) );
    }

}

DECL_EVENT( ragingblow_trigger ) {
    rti->player.ragingblow.stack ++;
    rti->player.ragingblow.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    if ( rti->player.ragingblow.stack > 2 ) {
        rti->player.ragingblow.stack = 2;
    }
    eq_enqueue( rti, rti->player.ragingblow.expire, routnum_ragingblow_expire, target_id );
    lprintf( ( "ragingblow stack %d", rti->player.ragingblow.stack ) );
}

DECL_EVENT( ragingblow_expire ) {
    if ( rti->player.ragingblow.expire == rti->timestamp ) {
        rti->player.ragingblow.stack = 0;
        lprintf( ( "ragingblow expire" ) );
    }
}

DECL_SPELL( ragingblow ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !UP( ragingblow.expire ) ) return 0;
    if ( !power_check( rti, 10.0f ) ) return 0;

    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    power_consume( rti, 10.0f );
    rti->player.ragingblow.stack--;
    if ( rti->player.ragingblow.stack == 0 ) {
        rti->player.ragingblow.expire = 0;
        lprintf( ( "ragingblow expire" ) );
    }

    eq_enqueue( rti, rti->timestamp, routnum_ragingblow_execute, rti->player.target );
    if ( UP( meatcleaver.expire ) ) {
        for ( int i = 0; i != num_enemies; i++ ) {
            if ( rti->player.meatcleaver.stack == 0 ) break;
            if ( i == rti->player.target ) continue;
            rti->player.meatcleaver.stack--;
            eq_enqueue( rti, rti->timestamp, routnum_ragingblow_execute, i );
        }
        rti->player.meatcleaver.stack = 0;
        rti->player.meatcleaver.expire = 0;
        lprintf( ( "meatcleaver expire" ) );
    }

#if (GLYPH_OF_RAGINGWIND)
    eq_enqueue( rti, rti->timestamp, routnum_ragingwind_trigger, 0 );
#endif
    lprintf( ( "cast ragingblow" ) );
    return 1;
}

// === meatcleaver ============================================================
DECL_EVENT( meatcleaver_trigger ) {
    rti->player.meatcleaver.stack += 2;
    rti->player.meatcleaver.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    if ( rti->player.meatcleaver.stack > 4 ) {
        rti->player.meatcleaver.stack = 4;
    }
    eq_enqueue( rti, rti->player.meatcleaver.expire, routnum_meatcleaver_expire, target_id );
    lprintf( ( "meatcleaver stack %d", rti->player.meatcleaver.stack ) );
}

DECL_EVENT( meatcleaver_expire ) {
    if ( rti->player.meatcleaver.expire == rti->timestamp ) {
        rti->player.meatcleaver.stack = 0;
        lprintf( ( "meatcleaver expire" ) );
    }
}

// === whirlwind ==============================================================
DECL_EVENT( whirlwind_execute ) {
    float d = weapon_dmg( rti, 0.56f, 1, 0 );
#if (GLYPH_OF_RAGINGWIND)
    if ( rti->player.ragingwind.expire == rti->timestamp ) d *= 1.1f;
#endif
    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "whirlwind crit" ) );

    }
    else {
        /* Hit */
        lprintf( ( "whirlwind hit" ) );
    }
    d = weapon_dmg( rti, 0.56f, 1, 1 );
#if (GLYPH_OF_RAGINGWIND)
    if ( rti->player.ragingwind.expire == rti->timestamp ) d *= 1.1f;
#endif
    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "whirlwind_oh crit" ) );

    }
    else {
        /* Hit */
        lprintf( ( "whirlwind_oh hit" ) );
    }
}

DECL_SPELL( whirlwind ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, 30.0f ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    power_consume( rti, 30.0f );
#if (GLYPH_OF_RAGINGWIND)
    if ( UP( ragingwind.expire ) ) {
        rti->player.ragingwind.expire = rti->timestamp;
        lprintf( ( "ragingwind expire" ) );
    }
#endif
    for ( int i = 0; i != num_enemies; i++ ) {
        eq_enqueue( rti, rti->timestamp, routnum_whirlwind_execute, i );
    }
    eq_enqueue( rti, rti->timestamp, routnum_meatcleaver_trigger, 0 );
    lprintf( ( "cast whirlwind" ) );
    return 1;
}

// === ragingwind =============================================================
#if (GLYPH_OF_RAGINGWIND)
DECL_EVENT( ragingwind_trigger ) {
    rti->player.ragingwind.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    eq_enqueue( rti, rti->player.ragingwind.expire, routnum_ragingwind_expire, target_id );
    lprintf( ( "ragingwind trig" ) );
}

DECL_EVENT( ragingwind_expire ) {
    if ( rti->player.ragingwind.expire == rti->timestamp ) {
        lprintf( ( "ragingwind expire" ) );
    }
}
#endif

// === execute ================================================================
DECL_EVENT( execute_execute ) {
    /* Main hand. */
    float d = weapon_dmg( rti, 3.5f * 1.2f, 1, 0 );
    if ( SINGLE_MINDED ) d *= 1.15f;

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "execute crit" ) );

    } else {
        /* Hit */
        lprintf( ( "execute hit" ) );
    }

    /* Off hand. */
    d = weapon_dmg( rti, 3.5f * 1.2f, 1, 1 );
    if ( SINGLE_MINDED ) d *= 1.15f;

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "execute oh crit" ) );

    } else {
        /* Hit */
        lprintf( ( "execute oh hit" ) );
    }
}

#if (TALENT_TIER3 == 2)
DECL_EVENT( suddendeath_trigger ) {
    rti->player.suddendeath.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.suddendeath.expire, routnum_suddendeath_expire, target_id );
    lprintf( ( "suddendeath trig" ) );
}

DECL_EVENT( suddendeath_expire ) {
    if ( rti->player.suddendeath.expire == rti->timestamp ) {
        lprintf( ( "suddendeath expire" ) );
    }
}
#endif

DECL_SPELL( execute ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
#if (TALENT_TIER3 == 2)
    if ( !UP( suddendeath.expire ) ) {
        if ( enemy_health_percent( rti ) >= 20.0f || !power_check( rti, 30.0f ) ) return 0;
        power_consume( rti, 30.0f );
    } else {
        rti->player.suddendeath.expire = 0;
        eq_enqueue( rti, rti->timestamp, routnum_suddendeath_expire, 0 );
#if (TALENT_TIER7 == 1)
        anger_management_count( rti, 30.0f );
#endif
    }
#else
    if ( enemy_health_percent( rti ) >= 20.0f || !power_check( rti, 30.0f ) ) return 0;
    power_consume( rti, 30.0f );
#endif
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_execute_execute, rti->player.target );
    lprintf( ( "cast execute" ) );
    return 1;
}

// === wildstrike =============================================================
DECL_EVENT( wildstrike_execute ) {
    float d = weapon_dmg( rti, 3.75f, 1, 1 );

#if (t18_2pc)
    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, UP( bloodsurge.expire ) ? 1.0 : 0, UP( bloodsurge.expire ) ? 0.12 : 0, 0 ) ) {
#else
    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
#endif

#if (t18_4pc)
        if( UP( recklessness.cd ) ) {
#if (TALENT_TIER7 == 1)
            rti->player.recklessness.cd = max( rti->player.recklessness.cd - FROM_SECONDS( 30 ), rti->timestamp ); // 25->30 patch 6.2.2
            if( rti->player.recklessness.cd == rti->timestamp )
                eq_enqueue( rti, rti->player.recklessness.cd, routnum_recklessness_cd, target_id );
#else
            rti->player.recklessness.cd = max( rti->player.recklessness.cd - FROM_SECONDS( 30 ), rti->timestamp ); // 25->30 patch 6.2.2
            eq_enqueue( rti, rti->player.recklessness.cd, routnum_recklessness_cd, target_id );
#endif
        }
#endif
        /* Crit */
        lprintf( ( "wildstrike crit" ) );
    }
    else {
        /* Hit */
        lprintf( ( "wildstrike hit" ) );
    }

    if ( UP( bloodsurge.expire ) ) {
        rti->player.bloodsurge.stack--;
        if ( rti->player.bloodsurge.stack == 0 ) {
            rti->player.bloodsurge.expire = 0;
            lprintf( ( "bloodsurge expire" ) );
        }
    }
}

DECL_EVENT( bloodsurge_trigger ) {
    rti->player.bloodsurge.stack = 2;
    rti->player.bloodsurge.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, rti->player.bloodsurge.expire, routnum_bloodsurge_expire, target_id );
    lprintf( ( "bloodsurge trig" ) );
}

DECL_EVENT( bloodsurge_expire ) {
    if ( rti->player.bloodsurge.expire == rti->timestamp ) {
        rti->player.bloodsurge.stack = 0;
        rti->player.bloodsurge.expire = 0;
        lprintf( ( "bloodsurge expire" ) );
    }
}

DECL_SPELL( wildstrike ) {
#if (TALENT_TIER3 == 1)
#define WILDSTRIKE_RAGE_COST 20.0f
#else
#define WILDSTRIKE_RAGE_COST 45.0f
#endif
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !UP( bloodsurge.expire ) ) {
        if ( !power_check( rti, WILDSTRIKE_RAGE_COST ) ) return 0;
        power_consume( rti, WILDSTRIKE_RAGE_COST );
    }
    gcd_start( rti, FROM_SECONDS( 0.75 ) );
    eq_enqueue( rti, rti->timestamp, routnum_wildstrike_execute, rti->player.target );
    lprintf( ( "cast wildstrike" ) );
    return 1;
}

// === bloodlust ==============================================================
#if (BUFF_BLOODLUST == 1)
DECL_EVENT( bloodlust_start ) {
    lprintf( ( "bloodlust start" ) );
    refresh_haste( rti );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 30 ) ), routnum_bloodlust_end, target_id );
}

DECL_EVENT( bloodlust_end ) {
    lprintf( ( "bloodlust end" ) );
    refresh_haste( rti );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 570 ) ), routnum_bloodlust_start, target_id );
}
#endif

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
    rti->player.potion.expire = TIME_OFFSET( FROM_SECONDS( 25 ) );
    eq_enqueue( rti, rti->player.potion.expire, routnum_potion_expire, target_id );

}

DECL_SPELL( potion ) {
    if ( rti->player.potion.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_potion_start, 0 );
    if ( rti->timestamp == FROM_SECONDS( 0 ) ) {
        rti->player.potion.cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
        eq_enqueue( rti, rti->player.potion.cd, routnum_potion_cd, 0 );
    } else {
        rti->player.potion.cd = rti->expected_combat_length + 1;
    }
    return 1;
}
#endif

// === berserkerrage ==========================================================
DECL_EVENT( berserkerrage_cd ) {
    lprintf( ( "berserkerrage ready" ) );
}

DECL_SPELL( berserkerrage ) {
    if ( rti->player.berserkerrage.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    rti->player.berserkerrage.cd = TIME_OFFSET( FROM_SECONDS( 30 ) );
    eq_enqueue( rti, rti->player.berserkerrage.cd, routnum_berserkerrage_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
    lprintf( ( "cast berserkerrage" ) );
    return 1;
}

// === recklessness ===========================================================
DECL_EVENT( recklessness_cd ) {
#if (TALENT_TIER7 == 1)
    if ( rti->player.recklessness.cd < rti->timestamp ) {
        return;
    } else
#endif
        if ( rti->player.recklessness.cd == rti->timestamp ) {
            lprintf( ( "recklessness ready" ) );
        }
#if (TALENT_TIER7 == 1)
#if (t18_4pc)
        else if ( rti->player.recklessness.cd - rti->timestamp > FROM_SECONDS( 25 ) ) {
            eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 5 ) ), routnum_recklessness_cd, target_id );
        }
#endif
        else if ( rti->player.recklessness.cd - rti->timestamp > FROM_MILLISECONDS( 333 ) ) {
            eq_enqueue( rti, ( rti->player.recklessness.cd + rti->timestamp ) / 2, routnum_recklessness_cd, target_id );
        } else {
            eq_enqueue( rti, rti->player.recklessness.cd, routnum_recklessness_cd, target_id );
        }
#endif

}

DECL_EVENT( recklessness_expire ) {
    lprintf( ( "recklessness expire" ) );
}

DECL_EVENT( recklessness_execute ) {
    lprintf( ( "recklessness start" ) );
#if (t17_4pc)
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_rampage_refresh, target_id );
#endif
}

#if (t17_4pc)
DECL_EVENT( rampage_expire ) {
    lprintf( ( "rampage expire" ) );
    rti->player.rampage.stack = 0;
    refresh_crit( rti );
}

DECL_EVENT( rampage_refresh ) {
    if ( rti->player.rampage.stack == 0 ) {
        rti->player.rampage.expire = TIME_OFFSET( FROM_SECONDS( 14 ) );
        eq_enqueue( rti, rti->player.rampage.expire, routnum_rampage_expire, target_id );
    }
    rti->player.rampage.stack++;
    refresh_crit( rti );
    if ( rti->player.rampage.stack < 10 )
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_rampage_refresh, target_id );
}
#endif

DECL_SPELL( recklessness ) {
    if ( rti->player.recklessness.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    rti->player.recklessness.cd = TIME_OFFSET( FROM_SECONDS( 180 ) );
#if (TALENT_TIER7 == 1)
    eq_enqueue( rti, ( rti->player.recklessness.cd + rti->timestamp ) / 2, routnum_recklessness_cd, 0 );
#else
    eq_enqueue( rti, rti->player.recklessness.cd, routnum_recklessness_cd, 0 );
#endif
    rti->player.recklessness.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.recklessness.expire, routnum_recklessness_expire, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_recklessness_execute, 0 );
    lprintf( ( "cast recklessness" ) );
    return 1;
}

// === stormbolt ==============================================================
#if (TALENT_TIER4 == 1)
DECL_EVENT( stormbolt_cd ) {
#if (TALENT_TIER7 == 1)
    if ( rti->player.stormbolt.cd < rti->timestamp ) {
        return;
    } else
#endif
        if ( rti->player.stormbolt.cd == rti->timestamp ) {
            lprintf( ( "stormbolt ready" ) );
        }
#if (TALENT_TIER7 == 1)
        else if ( rti->player.stormbolt.cd - rti->timestamp > FROM_MILLISECONDS( 333 ) ) {
            eq_enqueue( rti, ( rti->player.stormbolt.cd + rti->timestamp ) / 2, routnum_stormbolt_cd, target_id );
        } else {
            eq_enqueue( rti, rti->player.stormbolt.cd, routnum_stormbolt_cd, target_id );
        }
#endif
}

DECL_EVENT( stormbolt_execute ) {
    float d = weapon_dmg( rti, 0.6f * 4.0f, 1, 0 );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "stormbolt crit" ) );

    } else {
        /* Hit */
        lprintf( ( "stormbolt hit" ) );
    }
    d = weapon_dmg( rti, 0.6f * 4.0f, 1, 1 );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "stormbolt_oh crit" ) );

    } else {
        /* Hit */
        lprintf( ( "stormbolt_oh hit" ) );
    }
}

DECL_SPELL( stormbolt ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( rti->player.stormbolt.cd > rti->timestamp ) return 0;
    rti->player.stormbolt.cd = TIME_OFFSET( FROM_SECONDS( 30 ) );
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
#if (TALENT_TIER7 == 1)
    eq_enqueue( rti, ( rti->timestamp + rti->player.stormbolt.cd ) / 2, routnum_stormbolt_cd, rti->player.target );
#else
    eq_enqueue( rti, rti->player.stormbolt.cd, routnum_stormbolt_cd, rti->player.target );
#endif
    eq_enqueue( rti, rti->timestamp, routnum_stormbolt_execute, rti->player.target );
    lprintf( ( "cast stormbolt" ) );
    return 1;
}
#endif

// === shockwave ==============================================================
#if (TALENT_TIER4 == 2)
DECL_EVENT( shockwave_cd ) {
#if (TALENT_TIER7 == 1)
    if ( rti->player.shockwave.cd < rti->timestamp ) {
        return;
    } else
#endif
        if ( rti->player.shockwave.cd == rti->timestamp ) {
            lprintf( ( "shockwave ready" ) );
        }
#if (TALENT_TIER7 == 1)
        else if ( rti->player.shockwave.cd - rti->timestamp > FROM_MILLISECONDS( 333 ) ) {
            eq_enqueue( rti, ( rti->player.shockwave.cd + rti->timestamp ) / 2, routnum_shockwave_cd, target_id );
        } else {
            eq_enqueue( rti, rti->player.shockwave.cd, routnum_shockwave_cd, target_id );
        }
#endif
}

DECL_EVENT( shockwave_execute ) {
    float d = ap_dmg( rti, 1.25f );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "shockwave crit" ) );

    } else {
        /* Hit */
        lprintf( ( "shockwave hit" ) );
    }
}

DECL_SPELL( shockwave ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( rti->player.shockwave.cd > rti->timestamp ) return 0;
    rti->player.shockwave.cd = TIME_OFFSET( FROM_SECONDS( num_enemies >= 3 ? 20 : 40 ) );
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
#if (TALENT_TIER7 == 1)
    eq_enqueue( rti, ( rti->timestamp + rti->player.shockwave.cd ) / 2, routnum_shockwave_cd, 0 );
#else
    eq_enqueue( rti, rti->player.shockwave.cd, routnum_shockwave_cd, 0 );
#endif
    for ( int i = 0; i != num_enemies; i++ ) {
        eq_enqueue( rti, rti->timestamp, routnum_shockwave_execute, i );
    }
    lprintf( ( "cast shockwave" ) );
    return 1;
}
#endif

// === dragonroar =============================================================
#if (TALENT_TIER4 == 3)
DECL_EVENT( dragonroar_cd ) {
#if (TALENT_TIER7 == 1)
    if ( rti->player.dragonroar.cd < rti->timestamp ) {
        return;
    } else
#endif
        if ( rti->player.dragonroar.cd == rti->timestamp ) {
            lprintf( ( "dragonroar ready" ) );
        }
#if (TALENT_TIER7 == 1)
        else if ( rti->player.dragonroar.cd - rti->timestamp > FROM_MILLISECONDS( 333 ) ) {
            eq_enqueue( rti, ( rti->player.dragonroar.cd + rti->timestamp ) / 2, routnum_dragonroar_cd, target_id );
        } else {
            eq_enqueue( rti, rti->player.dragonroar.cd, routnum_dragonroar_cd, target_id );
        }
#endif
}

DECL_EVENT( dragonroar_execute ) {
    float d = ap_dmg( rti, 1.65f );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 1, 0, 1 ) ) {
        /* Crit */
        lprintf( ( "dragonroar crit" ) );

    } else {
        /* Hit */
        lprintf( ( "dragonroar hit" ) );
    }
}

DECL_SPELL( dragonroar ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( rti->player.dragonroar.cd > rti->timestamp ) return 0;
    rti->player.dragonroar.cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
#if (TALENT_TIER7 == 1)
    eq_enqueue( rti, ( rti->timestamp + rti->player.dragonroar.cd ) / 2, routnum_dragonroar_cd, 0 );
#else
    eq_enqueue( rti, rti->player.dragonroar.cd, routnum_dragonroar_cd, 0 );
#endif
    for ( int i = 0; i != num_enemies; i++ ) {
        eq_enqueue( rti, rti->timestamp, routnum_dragonroar_execute, i );
    }
    lprintf( ( "cast dragonroar" ) );
    return 1;
}
#endif

// === ravager ================================================================
#if (TALENT_TIER7 == 2)
DECL_EVENT( ravager_cd ) {
    if ( rti->player.ravager.cd == rti->timestamp ) {
        lprintf( ( "ravager ready" ) );
    }
}

DECL_EVENT( ravager_tick ) {
    float d = ap_dmg( rti, 0.615f );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "ravager crit" ) );

    } else {
        /* Hit */
        lprintf( ( "ravager hit" ) );
    }
    if ( rti->player.ravager.expire > rti->timestamp )
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_ravager_tick, target_id );
}

DECL_SPELL( ravager ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( rti->player.ravager.cd > rti->timestamp ) return 0;
    rti->player.ravager.cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
    rti->player.ravager.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->player.ravager.cd, routnum_ravager_cd, 0 );
    for ( int i = 0; i != num_enemies; i++ ) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_ravager_tick, i );
    }
    lprintf( ( "cast ravager" ) );
    return 1;
}
#endif

// === siegebreaker ===========================================================
#if (TALENT_TIER7 == 3)
DECL_EVENT( siegebreaker_cd ) {
    if ( rti->player.siegebreaker.cd == rti->timestamp ) {
        lprintf( ( "siegebreaker ready" ) );
    }
}

DECL_EVENT( siegebreaker_execute ) {
    float d = weapon_dmg( rti, 4.5f, 1, 0 );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "siegebreaker crit" ) );

    } else {
        /* Hit */
        lprintf( ( "siegebreaker hit" ) );
    }
    d = weapon_dmg( rti, 4.5f, 1, 1 );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "siegebreaker_oh crit" ) );

    } else {
        /* Hit */
        lprintf( ( "siegebreaker_oh hit" ) );
    }
}

DECL_SPELL( siegebreaker ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( rti->player.siegebreaker.cd > rti->timestamp ) return 0;
    rti->player.siegebreaker.cd = TIME_OFFSET( FROM_SECONDS( 45 ) );
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->player.siegebreaker.cd, routnum_siegebreaker_cd, rti->player.target );
    eq_enqueue( rti, rti->timestamp, routnum_siegebreaker_execute, rti->player.target );
    lprintf( ( "cast siegebreaker" ) );
    return 1;
}
#endif

// === bladestorm =============================================================
#if (TALENT_TIER6 == 3)
DECL_EVENT( bladestorm_cd ) {
#if (TALENT_TIER7 == 1)
    if ( rti->player.bladestorm.cd < rti->timestamp ) {
        return;
    } else
#endif
        if ( rti->player.bladestorm.cd == rti->timestamp ) {
            lprintf( ( "bladestorm ready" ) );
        }
#if (TALENT_TIER7 == 1)
        else if ( rti->player.bladestorm.cd - rti->timestamp > FROM_MILLISECONDS( 333 ) ) {
            eq_enqueue( rti, ( rti->player.bladestorm.cd + rti->timestamp ) / 2, routnum_bladestorm_cd, target_id );
        } else {
            eq_enqueue( rti, rti->player.bladestorm.cd, routnum_bladestorm_cd, target_id );
        }
#endif
}

DECL_EVENT( bladestorm_tick ) {
    float d = weapon_dmg( rti, 1.6f, 1, 0 );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "bladestorm crit" ) );

    } else {
        /* Hit */
        lprintf( ( "bladestorm hit" ) );
    }
    d = weapon_dmg( rti, 1.6f, 1, 1 );

    if ( deal_damage( rti, target_id, d, DMGTYPE_ABILITY, 0, 0, 0 ) ) {
        /* Crit */
        lprintf( ( "bladestorm_oh crit" ) );

    } else {
        /* Hit */
        lprintf( ( "bladestorm_oh hit" ) );
    }
    if ( rti->player.bladestorm.expire > rti->timestamp )
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_bladestorm_tick, target_id );
}

DECL_SPELL( bladestorm ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( rti->player.bladestorm.cd > rti->timestamp ) return 0;
    rti->player.bladestorm.cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
    rti->player.bladestorm.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    gcd_start( rti, FROM_SECONDS( 6 ) ); /* stuck gcd during bladestorm to avoid additional checks. */
#if (TALENT_TIER7 == 1)
    eq_enqueue( rti, ( rti->timestamp + rti->player.bladestorm.cd ) / 2, routnum_bladestorm_cd, 0 );
#else
    eq_enqueue( rti, rti->player.bladestorm.cd, routnum_bladestorm_cd, 0 );
#endif
    for( int i = 0; i != num_enemies; i++ ) {
        eq_enqueue( rti, rti->timestamp, routnum_bladestorm_tick, i );
    }
    lprintf( ( "cast bladestorm" ) );
    return 1;
}
#endif

// === avatar =================================================================
#if (TALENT_TIER6 == 1)
DECL_EVENT( avatar_cd ) {
#if (TALENT_TIER7 == 1)
    if ( rti->player.avatar.cd < rti->timestamp ) {
        return;
    } else
#endif
        if ( rti->player.avatar.cd == rti->timestamp ) {
            lprintf( ( "avatar ready" ) );
        }
#if (TALENT_TIER7 == 1)
        else if ( rti->player.avatar.cd - rti->timestamp > FROM_MILLISECONDS( 333 ) ) {
            eq_enqueue( rti, ( rti->player.avatar.cd + rti->timestamp ) / 2, routnum_avatar_cd, target_id );
        } else {
            eq_enqueue( rti, rti->player.avatar.cd, routnum_avatar_cd, target_id );
        }
#endif
}

DECL_EVENT( avatar_start ) {
    rti->player.avatar.expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, rti->player.avatar.expire, routnum_avatar_expire, target_id );
}

DECL_EVENT( avatar_expire ) {
    lprintf( ( "avatar expire" ) );
}

DECL_SPELL( avatar ) {
    if ( rti->player.avatar.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    rti->player.avatar.cd = TIME_OFFSET( FROM_SECONDS( 90 ) );
#if (TALENT_TIER7 == 1)
    eq_enqueue( rti, ( rti->player.avatar.cd + rti->timestamp ) / 2, routnum_avatar_cd, 0 );
#else
    eq_enqueue( rti, rti->player.avatar.cd, routnum_avatar_cd, 0 );
#endif
    eq_enqueue( rti, rti->timestamp, routnum_avatar_start, 0 );
    lprintf( ( "cast avatar" ) );
    return 1;
}
#endif

// === bloodbath ==============================================================
#if (TALENT_TIER6 == 2)
DECL_EVENT( bloodbath_cd ) {
#if (TALENT_TIER7 == 1)
    if ( rti->player.bloodbath.cd < rti->timestamp ) {
        return;
    } else
#endif
        if ( rti->player.bloodbath.cd == rti->timestamp ) {
            lprintf( ( "bloodbath ready" ) );
        }
#if (TALENT_TIER7 == 1)
        else if ( rti->player.bloodbath.cd - rti->timestamp > FROM_MILLISECONDS( 333 ) ) {
            eq_enqueue( rti, ( rti->player.bloodbath.cd + rti->timestamp ) / 2, routnum_bloodbath_cd, target_id );
        } else {
            eq_enqueue( rti, rti->player.bloodbath.cd, routnum_bloodbath_cd, target_id );
        }
#endif
}

DECL_EVENT( bloodbath_start ) {
    rti->player.bloodbath.expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    eq_enqueue( rti, rti->player.bloodbath.expire, routnum_bloodbath_expire, target_id );
}

DECL_EVENT( bloodbath_expire ) {
    lprintf( ( "bloodbath expire" ) );
}

DECL_EVENT( bloodbath_tick ) {
    if ( rti->enemy[target_id].bloodbath.ticks < 1.0f ) return;
    if ( rti->enemy[target_id].bloodbath.dot_start + FROM_SECONDS( 7.0f - rti->enemy[target_id].bloodbath.ticks ) != rti->timestamp ) return;
    float dmg = rti->enemy[target_id].bloodbath.pool / rti->enemy[target_id].bloodbath.ticks;
    rti->enemy[target_id].bloodbath.pool -= dmg;
    deal_damage( rti, target_id, dmg, DMGTYPE_BLOODBATH, 0, 0, 0 );
    lprintf( ( "bloodbath ticks" ) );
    rti->enemy[target_id].bloodbath.ticks -= 1.0f;
    if ( rti->enemy[target_id].bloodbath.ticks >= 1.0f )
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_bloodbath_tick, target_id );
}

DECL_SPELL( bloodbath ) {
    if ( rti->player.bloodbath.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    rti->player.bloodbath.cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
#if (TALENT_TIER7 == 1)
    eq_enqueue( rti, ( rti->player.bloodbath.cd + rti->timestamp ) / 2, routnum_bloodbath_cd, 0 );
#else
    eq_enqueue( rti, rti->player.bloodbath.cd, routnum_bloodbath_cd, 0 );
#endif
    eq_enqueue( rti, rti->timestamp, routnum_bloodbath_start, 0 );
    lprintf( ( "cast bloodbath" ) );
    return 1;
}
#endif

// === legendary ring =========================================================
#if (archmages_incandescence || archmages_greater_incandescence)
DECL_EVENT( incandescence_trigger ) {
    rti->player.incandescence.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.incandescence.expire, routnum_incandescence_expire, target_id );
    refresh_str( rti );
    refresh_ap( rti );
    lprintf( ( "incandescence trigger" ) );
}
DECL_EVENT( incandescence_expire ) {
    if ( rti->player.incandescence.expire == rti->timestamp ) {
        lprintf( ( "incandescence expire" ) );
        refresh_str( rti );
        refresh_ap( rti );
    }
}
#endif
#if defined(legendary_ring)
DECL_EVENT( thorasus_the_stone_heart_of_draenor_start ) {
    rti->player.thorasus_the_stone_heart_of_draenor.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, rti->player.thorasus_the_stone_heart_of_draenor.expire, routnum_thorasus_the_stone_heart_of_draenor_expire, target_id );
    rti->player.thorasus_the_stone_heart_of_draenor.dmg_snapshot = rti->damage_collected;
    lprintf( ( "thorasus the stone heart of draenor start" ) );
}
DECL_EVENT( thorasus_the_stone_heart_of_draenor_expire ) {
    float dmg = rti->damage_collected - rti->player.thorasus_the_stone_heart_of_draenor.dmg_snapshot;
    dmg *= legendary_ring * 0.0001;
    for ( int i = 0; i != num_enemies; i++ ) {
        deal_damage( rti, i, dmg, DMGTYPE_BLOODBATH, 0, 0, 0 );
    }
    lprintf( ( "thorasus the stone heart of draenor expire" ) );
}
DECL_EVENT( thorasus_the_stone_heart_of_draenor_cd ) {
    lprintf( ( "thorasus the stone heart of draenor cd" ) );
}
DECL_SPELL( thorasus_the_stone_heart_of_draenor ) {
    if ( rti->player.thorasus_the_stone_heart_of_draenor.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    rti->player.thorasus_the_stone_heart_of_draenor.cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, rti->player.thorasus_the_stone_heart_of_draenor.cd, routnum_thorasus_the_stone_heart_of_draenor_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_thorasus_the_stone_heart_of_draenor_start, 0 );
    lprintf( ( "cast thorasus the stone heart of draenor" ) );
    return 1;
}
#endif

// === enchants ===============================================================
#if (thunderlord_mh || bleedinghollow_mh || shatteredhand_mh)
DECL_EVENT( enchant_mh_expire ) {
#if (shatteredhand_mh)
	if ( rti->enemy[target_id].enchant_mh.expire == rti->timestamp ) {
#else
	if ( rti->player.enchant_mh.expire == rti->timestamp ) {
#endif
		lprintf( ( "mh enchant expire" ) );
        if ( thunderlord_mh ) refresh_crit( rti );
        if ( bleedinghollow_mh ) refresh_mastery( rti );
    }
}

DECL_EVENT( enchant_mh_trigger ) {
#if (thunderlord_mh)
    rti->player.enchant_mh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->player.enchant_mh.extend = 3;
    refresh_crit( rti );
#endif
#if (bleedinghollow_mh)
    rti->player.enchant_mh.expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    refresh_mastery( rti );
#endif
#if (shatteredhand_mh)
    deal_damage( rti, target_id, 1500.0f, DMGTYPE_SPECIAL, 0, 0, 0 );
    rti->enemy[target_id].enchant_mh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->enemy[target_id].enchant_mh.ticks = 6.0f;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_mh_tick, target_id );
	eq_enqueue( rti, rti->enemy[target_id].enchant_mh.expire, routnum_enchant_mh_expire, target_id );
#else
	eq_enqueue( rti, rti->player.enchant_mh.expire, routnum_enchant_mh_expire, target_id );
#endif
}
#endif

#if (thunderlord_oh || bleedinghollow_oh || shatteredhand_oh)
DECL_EVENT( enchant_oh_expire ) {
#if (shatteredhand_oh)
	if ( rti->enemy[target_id].enchant_oh.expire == rti->timestamp ) {
#else
	if ( rti->player.enchant_oh.expire == rti->timestamp ) {
#endif
        lprintf( ( "oh enchant expire" ) );
        if ( thunderlord_oh ) refresh_crit( rti );
        if ( bleedinghollow_oh ) refresh_mastery( rti );
    }
}

DECL_EVENT( enchant_oh_trigger ) {
#if (thunderlord_oh)
    rti->player.enchant_oh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->player.enchant_oh.extend = 3;
    refresh_crit( rti );
#endif
#if (bleedinghollow_oh)
    rti->player.enchant_oh.expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    refresh_mastery( rti );
#endif
#if (shatteredhand_oh)
    deal_damage( rti, target_id, 1500.0f, DMGTYPE_SPECIAL, 0, 0, 0 );
    rti->enemy[target_id].enchant_oh.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    rti->enemy[target_id].enchant_oh.ticks = 6.0f;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_oh_tick, target_id );
	eq_enqueue( rti, rti->enemy[target_id].enchant_oh.expire, routnum_enchant_oh_expire, target_id );
#else
	eq_enqueue( rti, rti->player.enchant_oh.expire, routnum_enchant_oh_expire, target_id );
#endif
}
#endif

#if (shatteredhand_mh)
DECL_EVENT( enchant_mh_tick ) {
    if ( TIME_OFFSET( FROM_SECONDS( rti->enemy[target_id].enchant_mh.ticks - 1.0f ) ) == rti->enemy[target_id].enchant_mh.expire ) {
        rti->enemy[target_id].enchant_mh.ticks -= 1.0f;
        deal_damage( rti, target_id, 750.0f, DMGTYPE_NONE, 0, 0, 0 );
        if ( rti->enemy[target_id].enchant_mh.ticks >= 1.0f )
            eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_mh_tick, target_id );
    }
}
#endif
#if (shatteredhand_oh)
DECL_EVENT( enchant_oh_tick ) {
    if ( TIME_OFFSET( FROM_SECONDS( rti->enemy[target_id].enchant_oh.ticks - 1.0f ) ) == rti->enemy[target_id].enchant_oh.expire ) {
        rti->enemy[target_id].enchant_oh.ticks -= 1.0f;
        deal_damage( rti, target_id, 750.0f, DMGTYPE_NONE, 0, 0, 0 );
        if ( rti->enemy[target_id].enchant_oh.ticks >= 1.0f )
            eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_enchant_oh_tick, target_id );
    }
}
#endif

// === racial traits ==========================================================
#if (RACE == RACE_BLOODELF)
DECL_EVENT( arcanetorrent_cd ) {
    lprintf( ( "arcanetorrent ready" ) );
}
DECL_EVENT( arcanetorrent_execute ) {
    lprintf( ( "cast arcanetorrent" ) );
}

DECL_SPELL( arcanetorrent ) {
    if ( rti->player.arcanetorrent.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    rti->player.arcanetorrent.cd = TIME_OFFSET( FROM_SECONDS( 90 ) ); // 120->90 patch 6.2.2
    eq_enqueue( rti, rti->player.arcanetorrent.cd, routnum_arcanetorrent_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_arcanetorrent_execute, 0 );
    power_gain( rti, 15.0f );
    lprintf( ( "cast arcanetorrent" ) );
    return 1;
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
    if ( rti->player.berserking.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_berserking_start, 0 );
    rti->player.berserking.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.berserking.expire, routnum_berserking_expire, 0 );
    rti->player.berserking.cd = TIME_OFFSET( FROM_SECONDS( 180 ) );
    eq_enqueue( rti, rti->player.berserking.cd, routnum_berserking_cd, 0 );
    lprintf( ( "cast berserking" ) );
    return 1;
}
#endif

#if (RACE == RACE_ORC)
DECL_EVENT( bloodfury_cd ) {
    lprintf( ( "bloodfury ready" ) );
}
DECL_EVENT( bloodfury_start ) {
    lprintf( ( "bloodfury start" ) );
    refresh_ap( rti );
}
DECL_EVENT( bloodfury_expire ) {
    lprintf( ( "bloodfury expire" ) );
    refresh_ap( rti );
}

DECL_SPELL( bloodfury ) {
    if ( rti->player.bloodfury.cd > rti->timestamp ) return 0;
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_bloodfury_start, 0 );
    rti->player.bloodfury.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, rti->player.bloodfury.expire, routnum_bloodfury_expire, 0 );
    rti->player.bloodfury.cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, rti->player.bloodfury.cd, routnum_bloodfury_cd, 0 );
    lprintf( ( "cast bloodfury" ) );
    return 1;
}
#endif
#if (RACE == RACE_UNDEAD)
DECL_EVENT( touch_of_the_grave_trigger ) {
    // old data for 6.2.0
	//float d = 1932.0f;
    //d += uni_rng( rti ) * ( 2244.0f - 1932.0f );
    float d = 0.5f * rti->player.stat.ap; // To avoid SMF bonus.
    d *= 2.0f; // 2015.11.19 hotfix
	deal_damage( rti, target_id, d, DMGTYPE_NONE, 0, 0, 0 );
}
#endif

// === trinkets ===============================================================
#if defined(trinket_vial_of_convulsive_shadows)
DECL_EVENT( vial_of_convulsive_shadows_cd ) {
    lprintf( ( "convulsiveshadows ready" ) );
}
DECL_EVENT( vial_of_convulsive_shadows_start ) {
    lprintf( ( "convulsiveshadows start" ) );
    rti->player.stat.gear_mult += trinket_vial_of_convulsive_shadows;
    refresh_mult( rti );
}
DECL_EVENT( vial_of_convulsive_shadows_expire ) {
    lprintf( ( "convulsiveshadows expire" ) );
    rti->player.stat.gear_mult -= trinket_vial_of_convulsive_shadows;
    refresh_mult( rti );
}

DECL_SPELL( vial_of_convulsive_shadows ) {
    if ( rti->player.vial_of_convulsive_shadows.cd > rti->timestamp ) return 0;
#if defined(trinket_scabbard_of_kyanos)
    if ( UP( scabbard_of_kyanos.expire ) ) return 0;
#endif
#if defined(trinket_emberscale_talisman)
    if ( UP( emberscale_talisman.expire ) ) return 0;
#endif
#if defined(trinket_bonemaws_big_toe)
    if ( UP( bonemaws_big_toe.expire ) ) return 0;
#endif
#if defined(trinket_badge_of_victory)
    if ( UP( badge_of_victory.expire ) ) return 0;
#endif
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_vial_of_convulsive_shadows_start, 0 );
    rti->player.vial_of_convulsive_shadows.expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, rti->player.vial_of_convulsive_shadows.expire, routnum_vial_of_convulsive_shadows_expire, 0 );
    rti->player.vial_of_convulsive_shadows.cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, rti->player.vial_of_convulsive_shadows.cd, routnum_vial_of_convulsive_shadows_cd, 0 );
    lprintf( ( "cast vial_of_convulsive_shadows" ) );
    return 1;
}
#endif

#if defined(trinket_forgemasters_insignia)
DECL_EVENT( forgemasters_insignia_tick ) {
    if ( rti->player.forgemasters_insignia.stack < 20 ) {
        if ( rti->player.forgemasters_insignia.stack == 0 ) {
            rti->player.forgemasters_insignia.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
            lprintf( ( "forgemasters_insignia start" ) );
        }
        rti->player.forgemasters_insignia.stack++;
        rti->player.stat.gear_mult += trinket_forgemasters_insignia;
        refresh_mult( rti );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 0.5 ) ), routnum_forgemasters_insignia_tick, target_id );
    } else {
        rti->player.forgemasters_insignia.stack = 0;
        rti->player.stat.gear_mult -= 20 * trinket_forgemasters_insignia;
        refresh_mult( rti );
        lprintf( ( "forgemasters_insignia expire" ) );
    }
}

#endif

#if defined(trinket_horn_of_screaming_spirits)
DECL_EVENT( horn_of_screaming_spirits_trigger ) {
    lprintf( ( "horn_of_screaming_spirits start" ) );
    rti->player.stat.gear_mastery += trinket_horn_of_screaming_spirits;
    refresh_mastery( rti );
    rti->player.horn_of_screaming_spirits.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.horn_of_screaming_spirits.expire, routnum_horn_of_screaming_spirits_expire, target_id );
}
DECL_EVENT( horn_of_screaming_spirits_expire ) {
    lprintf( ( "horn_of_screaming_spirits expire" ) );
    rti->player.stat.gear_mastery -= trinket_horn_of_screaming_spirits;
    refresh_mastery( rti );
}
#endif

#if defined(trinket_scabbard_of_kyanos)
DECL_EVENT( scabbard_of_kyanos_cd ) {
    lprintf( ( "scabbard_of_kyanos ready" ) );
}
DECL_EVENT( scabbard_of_kyanos_start ) {
    lprintf( ( "scabbard_of_kyanos start" ) );
    rti->player.stat.gear_str += trinket_scabbard_of_kyanos;
    refresh_str( rti );
    refresh_ap( rti );
}
DECL_EVENT( scabbard_of_kyanos_expire ) {
    lprintf( ( "scabbard_of_kyanos expire" ) );
    rti->player.stat.gear_str -= trinket_scabbard_of_kyanos;
    refresh_str( rti );
    refresh_ap( rti );
}

DECL_SPELL( scabbard_of_kyanos ) {
    if ( rti->player.scabbard_of_kyanos.cd > rti->timestamp ) return 0;
#if defined(trinket_vial_of_convulsive_shadows)
    if ( UP( vial_of_convulsive_shadows.expire ) ) return 0;
#endif
#if defined(trinket_emberscale_talisman)
    if ( UP( emberscale_talisman.expire ) ) return 0;
#endif
#if defined(trinket_bonemaws_big_toe)
    if ( UP( bonemaws_big_toe.expire ) ) return 0;
#endif
#if defined(trinket_badge_of_victory)
    if ( UP( badge_of_victory.expire ) ) return 0;
#endif
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_scabbard_of_kyanos_start, 0 );
    rti->player.scabbard_of_kyanos.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, rti->player.scabbard_of_kyanos.expire, routnum_scabbard_of_kyanos_expire, 0 );
    rti->player.scabbard_of_kyanos.cd = TIME_OFFSET( FROM_SECONDS( 90 ) );
    eq_enqueue( rti, rti->player.scabbard_of_kyanos.cd, routnum_scabbard_of_kyanos_cd, 0 );
    lprintf( ( "cast scabbard_of_kyanos" ) );
    return 1;
}
#endif

#if defined(trinket_emberscale_talisman)
DECL_EVENT( emberscale_talisman_cd ) {
    lprintf( ( "emberscale_talisman ready" ) );
}
DECL_EVENT( emberscale_talisman_start ) {
    lprintf( ( "emberscale_talisman start" ) );
    rti->player.stat.gear_vers += trinket_emberscale_talisman;
    refresh_vers( rti );
}
DECL_EVENT( emberscale_talisman_expire ) {
    lprintf( ( "emberscale_talisman expire" ) );
    rti->player.stat.gear_vers -= trinket_emberscale_talisman;
    refresh_vers( rti );
}

DECL_SPELL( emberscale_talisman ) {
    if ( rti->player.emberscale_talisman.cd > rti->timestamp ) return 0;
#if defined(trinket_vial_of_convulsive_shadows)
    if ( UP( vial_of_convulsive_shadows.expire ) ) return 0;
#endif
#if defined(trinket_scabbard_of_kyanos)
    if ( UP( scabbard_of_kyanos.expire ) ) return 0;
#endif
#if defined(trinket_bonemaws_big_toe)
    if ( UP( bonemaws_big_toe.expire ) ) return 0;
#endif
#if defined(trinket_badge_of_victory)
    if ( UP( badge_of_victory.expire ) ) return 0;
#endif
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_emberscale_talisman_start, 0 );
    rti->player.emberscale_talisman.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, rti->player.emberscale_talisman.expire, routnum_emberscale_talisman_expire, 0 );
    rti->player.emberscale_talisman.cd = TIME_OFFSET( FROM_SECONDS( 90 ) );
    eq_enqueue( rti, rti->player.emberscale_talisman.cd, routnum_emberscale_talisman_cd, 0 );
    lprintf( ( "cast emberscale_talisman" ) );
    return 1;
}
#endif

#if defined(trinket_bonemaws_big_toe)
DECL_EVENT( bonemaws_big_toe_cd ) {
    lprintf( ( "bonemaws_big_toe ready" ) );
}
DECL_EVENT( bonemaws_big_toe_start ) {
    lprintf( ( "bonemaws_big_toe start" ) );
    rti->player.stat.gear_crit += trinket_bonemaws_big_toe;
    refresh_crit( rti );
}
DECL_EVENT( bonemaws_big_toe_expire ) {
    lprintf( ( "bonemaws_big_toe expire" ) );
    rti->player.stat.gear_crit -= trinket_bonemaws_big_toe;
    refresh_crit( rti );
}

DECL_SPELL( bonemaws_big_toe ) {
    if ( rti->player.bonemaws_big_toe.cd > rti->timestamp ) return 0;
#if defined(trinket_vial_of_convulsive_shadows)
    if ( UP( vial_of_convulsive_shadows.expire ) ) return 0;
#endif
#if defined(trinket_scabbard_of_kyanos)
    if ( UP( scabbard_of_kyanos.expire ) ) return 0;
#endif
#if defined(trinket_emberscale_talisman)
    if ( UP( emberscale_talisman.expire ) ) return 0;
#endif
#if defined(trinket_badge_of_victory)
    if ( UP( badge_of_victory.expire ) ) return 0;
#endif
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_bonemaws_big_toe_start, 0 );
    rti->player.bonemaws_big_toe.expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, rti->player.bonemaws_big_toe.expire, routnum_bonemaws_big_toe_expire, 0 );
    rti->player.bonemaws_big_toe.cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, rti->player.bonemaws_big_toe.cd, routnum_bonemaws_big_toe_cd, 0 );
    lprintf( ( "cast bonemaws_big_toe" ) );
    return 1;
}
#endif


#if defined(trinket_badge_of_victory)
DECL_EVENT( badge_of_victory_cd ) {
    lprintf( ( "badge_of_victory ready" ) );
}
DECL_EVENT( badge_of_victory_start ) {
    lprintf( ( "badge_of_victory start" ) );
    rti->player.stat.gear_vers += trinket_badge_of_victory;
    refresh_vers( rti );
}
DECL_EVENT( badge_of_victory_expire ) {
    lprintf( ( "badge_of_victory expire" ) );
    rti->player.stat.gear_vers -= trinket_badge_of_victory;
    refresh_vers( rti );
}

DECL_SPELL( badge_of_victory ) {
    if ( rti->player.badge_of_victory.cd > rti->timestamp ) return 0;
#if defined(trinket_vial_of_convulsive_shadows)
    if ( UP( vial_of_convulsive_shadows.expire ) ) return 0;
#endif
#if defined(trinket_scabbard_of_kyanos)
    if ( UP( scabbard_of_kyanos.expire ) ) return 0;
#endif
#if defined(trinket_emberscale_talisman)
    if ( UP( emberscale_talisman.expire ) ) return 0;
#endif
#if defined(trinket_bonemaws_big_toe)
    if ( UP( bonemaws_big_toe.expire ) ) return 0;
#endif
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.expire ) ) return 0;
#endif
    eq_enqueue( rti, rti->timestamp, routnum_badge_of_victory_start, 0 );
    rti->player.badge_of_victory.expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, rti->player.badge_of_victory.expire, routnum_badge_of_victory_expire, 0 );
    rti->player.badge_of_victory.cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
    eq_enqueue( rti, rti->player.badge_of_victory.cd, routnum_badge_of_victory_cd, 0 );
    lprintf( ( "cast badge_of_victory" ) );
    return 1;
}
#endif

#if defined(trinket_insignia_of_victory)
DECL_EVENT( insignia_of_victory_trigger ) {
    lprintf( ( "insignia_of_victory start" ) );
    rti->player.stat.gear_str += trinket_insignia_of_victory;
    refresh_str( rti );
    refresh_ap( rti );
    rti->player.insignia_of_victory.expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, rti->player.insignia_of_victory.expire, routnum_insignia_of_victory_expire, 0 );
}
DECL_EVENT( insignia_of_victory_expire ) {
    lprintf( ( "insignia_of_victory expire" ) );
    rti->player.stat.gear_str -= trinket_insignia_of_victory;
    refresh_str( rti );
    refresh_ap( rti );
}
#endif

#if defined(trinket_tectus_beating_heart)
DECL_EVENT( tectus_beating_heart_trigger ) {
    lprintf( ( "tectus_beating_heart start" ) );
    rti->player.stat.gear_crit += trinket_tectus_beating_heart;
    refresh_crit( rti );
    rti->player.tectus_beating_heart.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.tectus_beating_heart.expire, routnum_tectus_beating_heart_expire, 0 );
}
DECL_EVENT( tectus_beating_heart_expire ) {
    lprintf( ( "tectus_beating_heart expire" ) );
    rti->player.stat.gear_crit -= trinket_tectus_beating_heart;
    refresh_crit( rti );
}
#endif

#if defined(trinket_formidable_fang)
DECL_EVENT( formidable_fang_trigger ) {
    lprintf( ( "formidable_fang start" ) );
    rti->player.stat.gear_mult += trinket_formidable_fang;
    refresh_mult( rti );
    rti->player.formidable_fang.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.formidable_fang.expire, routnum_formidable_fang_expire, 0 );
}
DECL_EVENT( formidable_fang_expire ) {
    lprintf( ( "formidable_fang expire" ) );
    rti->player.stat.gear_mult -= trinket_formidable_fang;
    refresh_mult( rti );
}
#endif

#if defined(trinket_draenic_stone)
DECL_EVENT( draenic_stone_trigger ) {
    lprintf( ( "draenic_stone start" ) );
    rti->player.stat.gear_str += trinket_draenic_stone;
    refresh_str( rti );
    refresh_ap( rti );
    rti->player.draenic_stone.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, rti->player.draenic_stone.expire, routnum_draenic_stone_expire, 0 );
}
DECL_EVENT( draenic_stone_expire ) {
    lprintf( ( "draenic_stone expire" ) );
    rti->player.stat.gear_str -= trinket_draenic_stone;
    refresh_str( rti );
    refresh_ap( rti );
}
#endif

#if defined(trinket_skull_of_war)
DECL_EVENT( skull_of_war_trigger ) {
    lprintf( ( "skull_of_war start" ) );
    rti->player.stat.gear_crit += trinket_skull_of_war;
    refresh_crit( rti );
    rti->player.skull_of_war.expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, rti->player.skull_of_war.expire, routnum_skull_of_war_expire, 0 );
}
DECL_EVENT( skull_of_war_expire ) {
    lprintf( ( "skull_of_war expire" ) );
    rti->player.stat.gear_crit -= trinket_skull_of_war;
    refresh_crit( rti );
}
#endif

#if defined(trinket_mote_of_the_mountain)
DECL_EVENT( mote_of_the_mountain_trigger ) {
    lprintf( ( "mote_of_the_mountain start" ) );
    rti->player.stat.gear_vers += trinket_mote_of_the_mountain;
    refresh_vers( rti );
    rti->player.mote_of_the_mountain.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.mote_of_the_mountain.expire, routnum_mote_of_the_mountain_expire, 0 );
}
DECL_EVENT( mote_of_the_mountain_expire ) {
    lprintf( ( "mote_of_the_mountain expire" ) );
    rti->player.stat.gear_vers -= trinket_mote_of_the_mountain;
    refresh_vers( rti );
}
#endif

#if defined(trinket_spores_of_alacrity)
DECL_EVENT( spores_of_alacrity_trigger ) {
    lprintf( ( "spores_of_alacrity start" ) );
    rti->player.stat.gear_haste += trinket_spores_of_alacrity;
    refresh_haste( rti );
    rti->player.spores_of_alacrity.expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, rti->player.spores_of_alacrity.expire, routnum_spores_of_alacrity_expire, 0 );
}
DECL_EVENT( spores_of_alacrity_expire ) {
    lprintf( ( "spores_of_alacrity expire" ) );
    rti->player.stat.gear_haste -= trinket_spores_of_alacrity;
    refresh_haste( rti );
}
#endif

#if defined(trinket_worldbreakers_resolve)
DECL_EVENT( worldbreakers_resolve_expire ) {
    if ( rti->timestamp == rti->player.worldbreakers_resolve.expire ) {
        lprintf( ( "worldbreakers_resolve expire" ) );
        rti->player.worldbreakers_resolve.stack = 0;
        refresh_haste( rti );
    }
}
DECL_EVENT( worldbreakers_resolve_trigger ) {
    rti->player.worldbreakers_resolve.stack++;
    if ( !WBR_NEVER_EXPIRE ) {
        rti->player.worldbreakers_resolve.expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
        eq_enqueue( rti, rti->player.worldbreakers_resolve.expire, routnum_worldbreakers_resolve_expire, 0 );
        if( rti->player.worldbreakers_resolve.target != target_id ) { /* Target switched. */
            rti->player.worldbreakers_resolve.stack = 1;
        }
        rti->player.worldbreakers_resolve.target = target_id;
    }
    if ( rti->player.worldbreakers_resolve.stack > 10 ) {
        rti->player.worldbreakers_resolve.stack = 10;
    }
    else {
        lprintf( ( "worldbreakers_resolve stack %d", rti->player.worldbreakers_resolve.stack ) );
        refresh_haste( rti );
    }
}
#endif

#if defined(trinket_discordant_chorus)
DECL_EVENT( discordant_chorus_trigger ) {
    lprintf( ( "discordant chorus trigger" ) );
    for ( int i = 0; i != num_enemies; i++ ) {
        deal_damage( rti, i, 0.5 * trinket_discordant_chorus, DMGTYPE_SPECIAL, 0, 0, 0 );
    }
}
#endif

#if defined(trinket_empty_drinking_horn)
DECL_EVENT( empty_drinking_horn_trigger ) {
    if ( rti->enemy[target_id].empty_drinking_horn.expire >= rti->timestamp ) {
        if ( rti->enemy[target_id].empty_drinking_horn.stack < 30 )
            rti->enemy[target_id].empty_drinking_horn.stack++;
    }
    else {
        rti->enemy[target_id].empty_drinking_horn.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
        rti->enemy[target_id].empty_drinking_horn.stack = 1;
        eq_enqueue( rti, rti->enemy[target_id].empty_drinking_horn.expire, routnum_empty_drinking_horn_expire, target_id );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_empty_drinking_horn_tick, target_id );
    }
    lprintf( ( "empty_drinking_horn stack %d @tar%d", rti->enemy[target_id].empty_drinking_horn.stack, target_id ) );
}
DECL_EVENT( empty_drinking_horn_expire ) {
    rti->enemy[target_id].empty_drinking_horn.stack = 0;
    lprintf( ( "empty_drinking_horn stack %d @tar%d", rti->enemy[target_id].empty_drinking_horn.stack, target_id ) );
}
DECL_EVENT( empty_drinking_horn_tick ) {
    float dmg = trinket_empty_drinking_horn * 0.5; /* Nerfed to half. */
    dmg *= rti->enemy[target_id].empty_drinking_horn.stack;
    deal_damage( rti, target_id, dmg, DMGTYPE_SPECIAL, 0, 0, 1 );
    time_t next_tick = TIME_OFFSET( FROM_SECONDS( 1 ) );
    if ( next_tick <= rti->enemy[target_id].empty_drinking_horn.expire )
        eq_enqueue( rti, next_tick, routnum_empty_drinking_horn_tick, target_id );
}
#endif

#if defined(trinket_unending_hunger)
DECL_EVENT( unending_hunger_trigger ) {
    lprintf( ( "unending_hunger trigger" ) );
    rti->player.unending_hunger.expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, rti->player.unending_hunger.expire, routnum_unending_hunger_expire, target_id );
    if ( !UP( unending_hunger.expire ) ) {
        rti->player.unending_hunger.stack = 1;
        rti->player.stat.gear_str += trinket_unending_hunger;
        refresh_str( rti );
        refresh_ap( rti );
    }
}
DECL_EVENT( unending_hunger_expire ) {
    if ( rti->player.unending_hunger.expire == rti->timestamp ) {
        lprintf( ( "unending_hunger expire" ) );
        rti->player.stat.gear_str -= trinket_unending_hunger * rti->player.unending_hunger.stack;
        rti->player.unending_hunger.stack = 0;
        rti->player.unending_hunger.expire = 0;
        refresh_str( rti );
        refresh_ap( rti );
    }
}
#endif

#if defined(trinket_gronntooth_war_horn)
DECL_EVENT( gronntooth_war_horn_trigger ) {
    if( !UP( gronntooth_war_horn.expire ) ) {
        rti->player.stat.gear_str += trinket_gronntooth_war_horn;
        refresh_str( rti );
        refresh_ap( rti );
    }      
    rti->player.gronntooth_war_horn.expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, rti->player.gronntooth_war_horn.expire, routnum_gronntooth_war_horn_expire, target_id );
    lprintf( ( "gronntooth_war_horn trigger" ) );
}
DECL_EVENT( gronntooth_war_horn_expire ) {
    if ( rti->player.gronntooth_war_horn.expire == rti->timestamp ) {
        lprintf( ( "gronntooth_war_horn expire" ) );
        rti->player.gronntooth_war_horn.expire = 0;
        rti->player.stat.gear_str -= trinket_gronntooth_war_horn;
        refresh_str( rti );
        refresh_ap( rti );
    }
}
#endif

// === anger_management =======================================================
void anger_management_count( rtinfo_t* rti, float rage ) {
    time_t t = FROM_SECONDS( rage / 30.0f );
    if ( UP( recklessness.cd ) ) {
        rti->player.recklessness.cd = max( rti->timestamp, rti->player.recklessness.cd - t );
        if ( rti->player.recklessness.cd == rti->timestamp )
            eq_enqueue( rti, rti->timestamp, routnum_recklessness_cd, 0 );
    }
#if (TALENT_TIER4 == 1)
    if ( UP( stormbolt.cd ) ) {
        rti->player.stormbolt.cd = max( rti->timestamp, rti->player.stormbolt.cd - t );
        if ( rti->player.stormbolt.cd == rti->timestamp )
            eq_enqueue( rti, rti->player.stormbolt.cd, routnum_stormbolt_cd, 0 );
    }
#endif
#if (TALENT_TIER4 == 2)
    if ( UP( shockwave.cd ) ) {
        rti->player.shockwave.cd = max( rti->timestamp, rti->player.shockwave.cd - t );
        if ( rti->player.shockwave.cd == rti->timestamp )
            eq_enqueue( rti, rti->player.shockwave.cd, routnum_shockwave_cd, 0 );
    }
#endif
#if (TALENT_TIER4 == 3)
    if ( UP( dragonroar.cd ) ) {
        rti->player.dragonroar.cd = max( rti->timestamp, rti->player.dragonroar.cd - t );
        if ( rti->player.dragonroar.cd == rti->timestamp )
            eq_enqueue( rti, rti->player.dragonroar.cd, routnum_dragonroar_cd, 0 );
    }
#endif
#if (TALENT_TIER6 == 1)
    if ( UP( avatar.cd ) ) {
        rti->player.avatar.cd = max( rti->timestamp, rti->player.avatar.cd - t );
        if ( rti->player.avatar.cd == rti->timestamp )
            eq_enqueue( rti, rti->player.avatar.cd, routnum_avatar_cd, 0 );
    }
#endif
#if (TALENT_TIER6 == 2)
    if ( UP( bloodbath.cd ) ) {
        rti->player.bloodbath.cd = max( rti->timestamp, rti->player.bloodbath.cd - t );
        if ( rti->player.bloodbath.cd == rti->timestamp )
            eq_enqueue( rti, rti->player.bloodbath.cd, routnum_bloodbath_cd, 0 );
    }
#endif
#if (TALENT_TIER6 == 3)
    if ( UP( bladestorm.cd ) ) {
        rti->player.bladestorm.cd = max( rti->timestamp, rti->player.bladestorm.cd - t );
        if ( rti->player.bladestorm.cd == rti->timestamp )
            eq_enqueue( rti, rti->player.bladestorm.cd, routnum_bladestorm_cd, 0 );
    }
#endif
}

void routine_entries( rtinfo_t* rti, _event_t e ) {
    switch( e.routine ) {
        HOOK_EVENT( gcd_expire );
        HOOK_EVENT( bloodthirst_execute );
        HOOK_EVENT( ragingblow_execute );
        HOOK_EVENT( ragingblow_trigger );
        HOOK_EVENT( ragingblow_expire );
        HOOK_EVENT( whirlwind_execute );
        HOOK_EVENT( meatcleaver_trigger );
        HOOK_EVENT( meatcleaver_expire );
        HOOK_EVENT( enrage_trigger );
        HOOK_EVENT( enrage_expire );
        HOOK_EVENT( execute_execute );
        HOOK_EVENT( wildstrike_execute );
        HOOK_EVENT( bloodsurge_trigger );
        HOOK_EVENT( bloodsurge_expire );
        HOOK_EVENT( auto_attack_mh );
        HOOK_EVENT( auto_attack_oh );
        HOOK_EVENT( recklessness_cd );
        HOOK_EVENT( recklessness_execute );
        HOOK_EVENT( recklessness_expire );
        HOOK_EVENT( berserkerrage_cd );
#if (GLYPH_OF_RAGINGWIND)
        HOOK_EVENT( ragingwind_expire );
        HOOK_EVENT( ragingwind_trigger );
#endif
#if (TALENT_TIER3 == 2)
        HOOK_EVENT( suddendeath_trigger );
        HOOK_EVENT( suddendeath_expire );
#endif
#if (TALENT_TIER3 != 3)
        HOOK_EVENT( bloodthirst_cd );
#endif
#if (TALENT_TIER4 == 1)
        HOOK_EVENT( stormbolt_execute );
        HOOK_EVENT( stormbolt_cd );
#endif
#if (TALENT_TIER4 == 2)
        HOOK_EVENT( shockwave_execute );
        HOOK_EVENT( shockwave_cd );
#endif
#if (TALENT_TIER4 == 3)
        HOOK_EVENT( dragonroar_execute );
        HOOK_EVENT( dragonroar_cd );
#endif
#if (TALENT_TIER6 == 1)
        HOOK_EVENT( avatar_start );
        HOOK_EVENT( avatar_expire );
        HOOK_EVENT( avatar_cd );
#endif
#if (TALENT_TIER6 == 2)
        HOOK_EVENT( bloodbath_start );
        HOOK_EVENT( bloodbath_expire );
        HOOK_EVENT( bloodbath_cd );
        HOOK_EVENT( bloodbath_tick );
#endif
#if (TALENT_TIER6 == 3)
        HOOK_EVENT( bladestorm_tick );
        HOOK_EVENT( bladestorm_cd );
#endif
#if (TALENT_TIER7 == 2)
        HOOK_EVENT( ravager_tick );
        HOOK_EVENT( ravager_cd );
#endif
#if (TALENT_TIER7 == 3)
        HOOK_EVENT( siegebreaker_execute );
        HOOK_EVENT( siegebreaker_cd );
#endif
#if (BUFF_BLOODLUST == 1)
        HOOK_EVENT( bloodlust_start );
        HOOK_EVENT( bloodlust_end );
#endif
#if (BUFF_POTION == 1)
        HOOK_EVENT( potion_start );
        HOOK_EVENT( potion_cd );
        HOOK_EVENT( potion_expire );
#endif
#if (t17_4pc)
        HOOK_EVENT( rampage_refresh );
        HOOK_EVENT( rampage_expire );
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
        HOOK_EVENT( incandescence_trigger );
        HOOK_EVENT( incandescence_expire );
#endif
#if defined(legendary_ring)
        HOOK_EVENT( thorasus_the_stone_heart_of_draenor_start );
        HOOK_EVENT( thorasus_the_stone_heart_of_draenor_expire );
        HOOK_EVENT( thorasus_the_stone_heart_of_draenor_cd );
#endif
#if (thunderlord_mh || bleedinghollow_mh || shatteredhand_mh)
        HOOK_EVENT( enchant_mh_trigger );
        HOOK_EVENT( enchant_mh_expire );
#endif
#if (shatteredhand_mh)
        HOOK_EVENT( enchant_mh_tick );
#endif
#if (thunderlord_oh || bleedinghollow_oh || shatteredhand_oh)
        HOOK_EVENT( enchant_oh_trigger );
        HOOK_EVENT( enchant_oh_expire );
#endif
#if (shatteredhand_oh)
        HOOK_EVENT( enchant_oh_tick );
#endif
#if (RACE == RACE_BLOODELF)
        HOOK_EVENT( arcanetorrent_cd );
        HOOK_EVENT( arcanetorrent_execute );
#endif
#if (RACE == RACE_TROLL)
        HOOK_EVENT( berserking_start );
        HOOK_EVENT( berserking_expire );
        HOOK_EVENT( berserking_cd );
#endif
#if (RACE == RACE_ORC)
        HOOK_EVENT( bloodfury_start );
        HOOK_EVENT( bloodfury_expire );
        HOOK_EVENT( bloodfury_cd );
#endif
#if (RACE == RACE_UNDEAD)
        HOOK_EVENT( touch_of_the_grave_trigger );
#endif
#if defined(trinket_vial_of_convulsive_shadows)
        HOOK_EVENT( vial_of_convulsive_shadows_expire );
        HOOK_EVENT( vial_of_convulsive_shadows_start );
        HOOK_EVENT( vial_of_convulsive_shadows_cd );
#endif
#if defined(trinket_forgemasters_insignia)
        HOOK_EVENT( forgemasters_insignia_tick );
#endif
#if defined(trinket_horn_of_screaming_spirits)
        HOOK_EVENT( horn_of_screaming_spirits_trigger );
        HOOK_EVENT( horn_of_screaming_spirits_expire );
#endif
#if defined(trinket_scabbard_of_kyanos)
        HOOK_EVENT( scabbard_of_kyanos_expire );
        HOOK_EVENT( scabbard_of_kyanos_start );
        HOOK_EVENT( scabbard_of_kyanos_cd );
#endif
#if defined(trinket_badge_of_victory)
        HOOK_EVENT( badge_of_victory_expire );
        HOOK_EVENT( badge_of_victory_start );
        HOOK_EVENT( badge_of_victory_cd );
#endif
#if defined(trinket_insignia_of_victory)
        HOOK_EVENT( insignia_of_victory_expire );
        HOOK_EVENT( insignia_of_victory_trigger );
#endif
#if defined(trinket_tectus_beating_heart)
        HOOK_EVENT( tectus_beating_heart_trigger );
        HOOK_EVENT( tectus_beating_heart_expire );
#endif
#if defined(trinket_formidable_fang)
        HOOK_EVENT( formidable_fang_trigger );
        HOOK_EVENT( formidable_fang_expire );
#endif
#if defined(trinket_draenic_stone)
        HOOK_EVENT( draenic_stone_expire );
        HOOK_EVENT( draenic_stone_trigger );
#endif
#if defined(trinket_skull_of_war)
        HOOK_EVENT( skull_of_war_expire );
        HOOK_EVENT( skull_of_war_trigger );
#endif
#if defined(trinket_mote_of_the_mountain)
        HOOK_EVENT( mote_of_the_mountain_trigger );
        HOOK_EVENT( mote_of_the_mountain_expire );
#endif
#if defined(trinket_worldbreakers_resolve)
        HOOK_EVENT( worldbreakers_resolve_trigger );
        HOOK_EVENT( worldbreakers_resolve_expire );
#endif
#if defined(trinket_discordant_chorus)
        HOOK_EVENT( discordant_chorus_trigger );
#endif
#if defined(trinket_empty_drinking_horn)
        HOOK_EVENT( empty_drinking_horn_trigger );
        HOOK_EVENT( empty_drinking_horn_tick );
        HOOK_EVENT( empty_drinking_horn_expire );
#endif
#if defined(trinket_unending_hunger)
        HOOK_EVENT( unending_hunger_trigger );
        HOOK_EVENT( unending_hunger_expire );
#endif
#if defined(trinket_spores_of_alacrity)
        HOOK_EVENT( spores_of_alacrity_trigger );
        HOOK_EVENT( spores_of_alacrity_expire );
#endif
#if defined(trinket_bonemaws_big_toe)
        HOOK_EVENT( bonemaws_big_toe_expire );
        HOOK_EVENT( bonemaws_big_toe_start );
        HOOK_EVENT( bonemaws_big_toe_cd );
#endif
#if defined(trinket_emberscale_talisman)
        HOOK_EVENT( emberscale_talisman_expire );
        HOOK_EVENT( emberscale_talisman_start );
        HOOK_EVENT( emberscale_talisman_cd );
#endif
#if defined(trinket_gronntooth_war_horn)
        HOOK_EVENT( gronntooth_war_horn_trigger );
        HOOK_EVENT( gronntooth_war_horn_expire );
#endif
    default:
        assert( 0 );
    }
}

void module_init( rtinfo_t* rti ) {
#if (passive_power_regen)
    rti->player.power_regen = 0.0f;
#endif
    rti->player.power = 0.0f;
    eq_enqueue( rti, rti->timestamp, routnum_auto_attack_mh, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( SYNC_MELEE ? 0 : 0.5 ) ), routnum_auto_attack_oh, 0 );

    refresh_str( rti );
    refresh_ap( rti );
    refresh_crit( rti );
    refresh_haste( rti );
    refresh_mastery( rti );
    refresh_mult( rti );
    refresh_vers( rti );

    lprintf( ( "Raid buffed str %d", rti->player.stat.str ) );
    lprintf( ( "Raid buffed ap %d", rti->player.stat.ap ) );
    lprintf( ( "Raid buffed crit %f", rti->player.stat.crit ) );
    lprintf( ( "Raid buffed haste %f", rti->player.stat.haste ) );
    lprintf( ( "Raid buffed mastery %f", rti->player.stat.mastery ) );
    lprintf( ( "Raid buffed mult %f", rti->player.stat.mult ) );
    lprintf( ( "Raid buffed vers %f", rti->player.stat.vers ) );

#if (TALENT_TIER3 == 2)
    rti->player.suddendeath.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.suddendeath.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if (BUFF_BLOODLUST == 1)
    eq_enqueue( rti, hostonly( FROM_MILLISECONDS( 1 ) ) deviceonly( rti->timestamp ), routnum_bloodlust_start, 0 );
#endif
#if (BUFF_POTION == 1)
    SPELL( potion );
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
    rti->player.incandescence.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.incandescence.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if (thunderlord_mh || bleedinghollow_mh || shatteredhand_mh)
    rti->player.enchant_mh.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.enchant_mh.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if (thunderlord_oh || bleedinghollow_oh || shatteredhand_oh)
    rti->player.enchant_oh.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.enchant_oh.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_forgemasters_insignia)
    rti->player.forgemasters_insignia.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.forgemasters_insignia.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_horn_of_screaming_spirits)
    rti->player.horn_of_screaming_spirits.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.horn_of_screaming_spirits.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_tectus_beating_heart)
    rti->player.tectus_beating_heart.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.tectus_beating_heart.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_formidable_fang)
    rti->player.formidable_fang.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.formidable_fang.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_mote_of_the_mountain)
    rti->player.mote_of_the_mountain.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.mote_of_the_mountain.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_discordant_chorus)
    rti->player.discordant_chorus.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.discordant_chorus.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_unending_hunger)
    rti->player.unending_hunger.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.unending_hunger.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_spores_of_alacrity)
    rti->player.spores_of_alacrity.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.spores_of_alacrity.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
#if defined(trinket_gronntooth_war_horn)
    rti->player.gronntooth_war_horn.proc.lasttimeattemps = ( time_t ) - ( k32s )FROM_SECONDS( 10 );
    rti->player.gronntooth_war_horn.proc.lasttimeprocs = ( time_t ) - ( k32s )FROM_SECONDS( 180 );
#endif
}

void special_procs( rtinfo_t* rti, k32u target_id ) {
#if (RACE == RACE_UNDEAD)
    proc_ICD( rti, &rti->player.touch_of_the_grave, 0.2f, FROM_SECONDS( 15 ), routnum_touch_of_the_grave_trigger, target_id );
#endif
#if (archmages_incandescence || archmages_greater_incandescence)
    if ( !UP( incandescence.expire ) ) {
        proc_RPPM( rti, &rti->player.incandescence.proc, 0.92f, routnum_incandescence_trigger, target_id );
    }
#endif
#if (thunderlord_mh)
    proc_RPPM( rti, &rti->player.enchant_mh.proc, 2.5f, routnum_enchant_mh_trigger, target_id );
#elif (bleedinghollow_mh)
    proc_RPPM( rti, &rti->player.enchant_mh.proc, 2.3f, routnum_enchant_mh_trigger, target_id );
#elif (shatteredhand_mh)
    proc_RPPM( rti, &rti->player.enchant_mh.proc, 3.5f * ( 1.0f + rti->player.stat.haste ), routnum_enchant_mh_trigger, target_id );
#endif
#if (thunderlord_oh)
    proc_RPPM( rti, &rti->player.enchant_oh.proc, 2.5f, routnum_enchant_oh_trigger, target_id );
#elif (bleedinghollow_oh)
    proc_RPPM( rti, &rti->player.enchant_oh.proc, 2.3f, routnum_enchant_oh_trigger, target_id );
#elif (shatteredhand_oh)
    proc_RPPM( rti, &rti->player.enchant_oh.proc, 3.5f * ( 1.0f + rti->player.stat.haste ), routnum_enchant_oh_trigger, target_id );
#endif
#if defined(trinket_forgemasters_insignia)
    if ( !UP( forgemasters_insignia.expire ) ) {
        proc_RPPM( rti, &rti->player.forgemasters_insignia.proc, 0.92f, routnum_forgemasters_insignia_tick, target_id );
    }
#endif
#if defined(trinket_horn_of_screaming_spirits)
    if ( !UP( horn_of_screaming_spirits.expire ) ) {
        proc_RPPM( rti, &rti->player.horn_of_screaming_spirits.proc, 0.92f, routnum_horn_of_screaming_spirits_trigger, target_id );
    }
#endif
#if defined(trinket_insignia_of_victory)
    proc_ICD( rti, &rti->player.insignia_of_victory.proc, 0.15f, FROM_SECONDS( 55 ), routnum_insignia_of_victory_trigger, target_id );
#endif
#if defined(trinket_tectus_beating_heart)
    if ( !UP( tectus_beating_heart.expire ) ) {
        proc_RPPM( rti, &rti->player.tectus_beating_heart.proc, 0.92f, routnum_tectus_beating_heart_trigger, target_id );
    }
#endif
#if defined(trinket_formidable_fang)
    if ( !UP( formidable_fang.expire ) ) {
        proc_RPPM( rti, &rti->player.formidable_fang.proc, 0.92f, routnum_formidable_fang_trigger, target_id );
    }
#endif
#if defined(trinket_draenic_stone)
    proc_ICD( rti, &rti->player.draenic_stone.proc, 0.35f, FROM_SECONDS( 55 ), routnum_draenic_stone_trigger, target_id );
#endif
#if defined(trinket_skull_of_war)
    proc_ICD( rti, &rti->player.skull_of_war.proc, 0.15f, FROM_SECONDS( 115 ), routnum_skull_of_war_trigger, target_id );
#endif
#if defined(trinket_mote_of_the_mountain)
    if ( !UP( mote_of_the_mountain.expire ) ) {
        proc_RPPM( rti, &rti->player.mote_of_the_mountain.proc, 0.92f, routnum_mote_of_the_mountain_trigger, target_id );
    }
#endif
#if defined(trinket_discordant_chorus)
    proc_RPPM( rti, &rti->player.discordant_chorus, 6.0f * ( 1.0f + rti->player.stat.haste ), routnum_discordant_chorus_trigger, target_id );
#endif
#if defined(trinket_empty_drinking_horn)
    eq_enqueue( rti, rti->timestamp, routnum_empty_drinking_horn_trigger, target_id );
#endif
#if defined(trinket_unending_hunger)
    proc_RPPM( rti, &rti->player.unending_hunger.proc, 1.0f, routnum_unending_hunger_trigger, target_id );
    if( UP( unending_hunger.expire ) && rti->player.unending_hunger.stack < 20 ) {
        rti->player.unending_hunger.stack++;
        rti->player.stat.gear_str += trinket_unending_hunger;
        refresh_str( rti );
        refresh_ap( rti );
    }
#endif
#if defined(trinket_spores_of_alacrity)
    if ( !UP( spores_of_alacrity.expire ) ) {
        proc_RPPM( rti, &rti->player.spores_of_alacrity.proc, 0.92f, routnum_spores_of_alacrity_trigger, target_id );
    }
#endif
#if defined(trinket_gronntooth_war_horn)
    proc_RPPM( rti, &rti->player.gronntooth_war_horn.proc, 1.5f, routnum_gronntooth_war_horn_trigger, target_id );
#endif
}

/* Helper Macros for better APL writing. */
#if (TALENT_TIER3==0)
#define T30(texpr,fexpr) texpr
#else
#define T30(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER3==1)
#define T31(texpr,fexpr) texpr
#else
#define T31(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER3==2)
#define T32(texpr,fexpr) texpr
#else
#define T32(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER3==3)
#define T33(texpr,fexpr) texpr
#else
#define T33(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER4==0)
#define T40(texpr,fexpr) texpr
#else
#define T40(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER4==1)
#define T41(texpr,fexpr) texpr
#else
#define T41(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER4==2)
#define T42(texpr,fexpr) texpr
#else
#define T42(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER4==3)
#define T43(texpr,fexpr) texpr
#else
#define T43(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER6==0)
#define T60(texpr,fexpr) texpr
#else
#define T60(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER6==1)
#define T61(texpr,fexpr) texpr
#else
#define T61(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER6==2)
#define T62(texpr,fexpr) texpr
#else
#define T62(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER6==3)
#define T63(texpr,fexpr) texpr
#else
#define T63(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER7==0)
#define T70(texpr,fexpr) texpr
#else
#define T70(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER7==1)
#define T71(texpr,fexpr) texpr
#else
#define T71(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER7==2)
#define T72(texpr,fexpr) texpr
#else
#define T72(texpr,fexpr) fexpr
#endif
#if (TALENT_TIER7==3)
#define T73(texpr,fexpr) texpr
#else
#define T73(texpr,fexpr) fexpr
#endif
#if (BUFF_POTION)
#define POTION(texpr,fexpr) texpr
#else
#define POTION(texpr,fexpr) fexpr
#endif
#if (RACE == RACE_BLOODELF)
#define BELF(texpr,fexpr) texpr
#else
#define BELF(texpr,fexpr) fexpr
#endif
#if (RACE == RACE_ORC)
#define ORC(texpr,fexpr) texpr
#else
#define ORC(texpr,fexpr) fexpr
#endif
#if (RACE == RACE_TROLL)
#define TROLL(texpr,fexpr) texpr
#else
#define TROLL(texpr,fexpr) fexpr
#endif
#if (legendary_ring)
#define LEGENDARY(texpr,fexpr) texpr
#else
#define LEGENDARY(texpr,fexpr) fexpr
#endif
#if (trinket_vial_of_convulsive_shadows)
#define TRINKET_VIAL(texpr,fexpr) texpr
#else
#define TRINKET_VIAL(texpr,fexpr) fexpr
#endif
#if (trinket_scabbard_of_kyanos)
#define TRINKET_KYANOS(texpr,fexpr) texpr
#else
#define TRINKET_KYANOS(texpr,fexpr) fexpr
#endif
#if (trinket_badge_of_victory)
#define TRINKET_PVP(texpr,fexpr) texpr
#else
#define TRINKET_PVP(texpr,fexpr) fexpr
#endif
#if (trinket_bonemaws_big_toe)
#define TRINKET_TOE(texpr,fexpr) texpr
#else
#define TRINKET_TOE(texpr,fexpr) fexpr
#endif
#if (trinket_emberscale_talisman)
#define TRINKET_EMBER(texpr,fexpr) texpr
#else
#define TRINKET_EMBER(texpr,fexpr) fexpr
#endif

/* Debug build. */
#if !defined(__OPENCL_VERSION__)
void scan_apl( rtinfo_t* rti ) {

// Translated by apltr.
    if( ( 0.000000f > 5.000000f ) ) {
        T41( SPELL( stormbolt ), 0 );
        return;
    }
    if( ( !UP( enrage.expire ) || ( 0.000000f && ( rti->player.ragingblow.stack < 2.000000f ) ) ) )SPELL( berserkerrage );
    if( ( ( ( num_enemies > 1.000000f ) || !0 ) && ( ( ( T63( 1, 0 ) && ( T63( TO_SECONDS( REMAIN( bladestorm.cd ) ), 0 ) == 0.000000f ) ) || UP( recklessness.expire ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 25.000000f ) ) ) )LEGENDARY( SPELL( thorasus_the_stone_heart_of_draenor ), 0 );
    if( ( ( ( enemy_health_percent( rti ) < 20.000000f ) && UP( recklessness.expire ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) <= 30.000000f ) ) )POTION( SPELL( potion ), 0 );
    if( ( ( ( ( 65535 < 60.000000f ) && ( 0 > 2.000000f ) ) && ( num_enemies == 1.000000f ) ) || ( 65535 < 5.000000f ) ) ) {
        T62( SPELL( bloodbath ), 0 );
        if( ( ( enemy_health_percent( rti ) < 20.000000f ) && 0 ) )SPELL( recklessness );
        if( ( ( rti->player.power > ( power_max - 20.000000f ) ) && ( enemy_health_percent( rti ) > 20.000000f ) ) )SPELL( wildstrike );
        if( ( ( ( !T33( 1, 0 ) && ( rti->player.power < ( power_max - 40.000000f ) ) ) || !UP( enrage.expire ) ) || ( rti->player.ragingblow.stack < 2.000000f ) ) )SPELL( bloodthirst );
        if( ( T62( UP( bloodbath.expire ), 0 ) || ( !T62( 1, 0 ) && ( ( !0 || ( 0 > 60.000000f ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 40.000000f ) ) ) ) )T72( SPELL( ravager ), 0 );
        T73( SPELL( siegebreaker ), 0 );
        if( T32( UP( suddendeath.expire ), 0 ) )SPELL( execute );
        T41( SPELL( stormbolt ), 0 );
        if( UP( bloodsurge.expire ) )SPELL( wildstrike );
        if( ( UP( enrage.expire ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 12.000000f ) ) )SPELL( execute );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T43( SPELL( dragonroar ), 0 );
        SPELL( ragingblow );
        if( ( ( TO_SECONDS( REMAIN( bloodthirst.cd ) ) < 0.500000f ) && ( rti->player.power < 50.000000f ) ) )return;
        if( ( UP( enrage.expire ) && ( enemy_health_percent( rti ) > 20.000000f ) ) )SPELL( wildstrike );
        if( !0 )T63( SPELL( bladestorm ), 0 );
        if( !T33( 1, 0 ) )T42( SPELL( shockwave ), 0 );
        SPELL( bloodthirst );
        return;
    }
    if( ( ( ( ( ( T62( UP( bloodbath.expire ), 0 ) || ( T62( TO_SECONDS( REMAIN( bloodbath.cd ) ), 0 ) > 25.000000f ) ) || !T62( 1, 0 ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 15.000000f ) ) && ( ( T63( 1, 0 ) && ( !0 || ( num_enemies == 1.000000f ) ) ) || !T63( 1, 0 ) ) ) && t18_4pc ) )SPELL( recklessness );
    if( ( ( T71( 1, 0 ) && ( ( T63( 1, 0 ) && ( !0 || ( num_enemies == 1.000000f ) ) ) || !T63( 1, 0 ) ) ) && !t18_4pc ) ) {
        if( ( ( ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) > 140.000000f ) || ( enemy_health_percent( rti ) < 20.000000f ) ) && ( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 15.000000f ) ) ) )SPELL( recklessness );
    }
    if( ( ( !T71( 1, 0 ) && ( ( T63( 1, 0 ) && ( !0 || ( num_enemies == 1.000000f ) ) ) || !T63( 1, 0 ) ) ) && !t18_4pc ) ) {
        if( ( ( ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) > 190.000000f ) || ( enemy_health_percent( rti ) < 20.000000f ) ) && ( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 15.000000f ) ) ) )SPELL( recklessness );
    }
    if( ( ( UP( recklessness.expire ) || ( TO_SECONDS( REMAIN( recklessness.cd ) ) > 60.000000f ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 30.000000f ) ) )T61( SPELL( avatar ), 0 );
    if( ( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) || UP( recklessness.expire ) ) )ORC( SPELL( bloodfury ), 0 );
    if( ( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) || UP( recklessness.expire ) ) )TROLL( SPELL( berserking ), 0 );
    if( ( rti->player.power < ( power_max - 40.000000f ) ) )BELF( SPELL( arcanetorrent ), 0 );
    if( ( num_enemies == 2.000000f ) ) {
        T62( SPELL( bloodbath ), 0 );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T72( SPELL( ravager ), 0 );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T43( SPELL( dragonroar ), 0 );
        {
            if( ( ( TO_SECONDS( REMAIN( enrage.expire ) ) > 6.000000f ) && ( ( ( ( T71( 1, 0 ) && ( 0 > 45.000000f ) ) || ( !T71( 1, 0 ) && ( 0 > 60.000000f ) ) ) || !0 ) || ( num_enemies > num_enemies ) ) ) )SPELL( recklessness );
            if( ( ( TO_SECONDS( REMAIN( enrage.expire ) ) > 6.000000f ) && ( ( ( ( T71( 1, 0 ) && ( 0 > 45.000000f ) ) || ( !T71( 1, 0 ) && ( 0 > 60.000000f ) ) ) || !0 ) || ( num_enemies > num_enemies ) ) ) )T63( SPELL( bladestorm ), 0 );
        }
        if( ( ( !UP( enrage.expire ) || ( rti->player.power < 40.000000f ) ) || !UP( ragingblow.expire ) ) )SPELL( bloodthirst );
        T73( SPELL( siegebreaker ), 0 );
        SPELL( execute );
        if( ( UP( meatcleaver.expire ) || ( enemy_health_percent( rti ) < 20.000000f ) ) )SPELL( ragingblow );
        if( ( !UP( meatcleaver.expire ) && ( enemy_health_percent( rti ) > 20.000000f ) ) )SPELL( whirlwind );
        if( UP( bloodsurge.expire ) )SPELL( wildstrike );
        SPELL( bloodthirst );
        SPELL( whirlwind );
    }
    if( ( num_enemies == 3.000000f ) ) {
        T62( SPELL( bloodbath ), 0 );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T72( SPELL( ravager ), 0 );
        {
            if( ( ( TO_SECONDS( REMAIN( enrage.expire ) ) > 6.000000f ) && ( ( ( ( T71( 1, 0 ) && ( 0 > 45.000000f ) ) || ( !T71( 1, 0 ) && ( 0 > 60.000000f ) ) ) || !0 ) || ( num_enemies > num_enemies ) ) ) )SPELL( recklessness );
            if( ( ( TO_SECONDS( REMAIN( enrage.expire ) ) > 6.000000f ) && ( ( ( ( T71( 1, 0 ) && ( 0 > 45.000000f ) ) || ( !T71( 1, 0 ) && ( 0 > 60.000000f ) ) ) || !0 ) || ( num_enemies > num_enemies ) ) ) )T63( SPELL( bladestorm ), 0 );
        }
        if( ( ( !UP( enrage.expire ) || ( rti->player.power < 50.000000f ) ) || !UP( ragingblow.expire ) ) )SPELL( bloodthirst );
        if( ( rti->player.meatcleaver.stack >= 2.000000f ) )SPELL( ragingblow );
        T73( SPELL( siegebreaker ), 0 );
        SPELL( execute );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T43( SPELL( dragonroar ), 0 );
        if( ( enemy_health_percent( rti ) > 20.000000f ) )SPELL( whirlwind );
        SPELL( bloodthirst );
        if( UP( bloodsurge.expire ) )SPELL( wildstrike );
        SPELL( ragingblow );
    }
    if( ( num_enemies > 3.000000f ) ) {
        T62( SPELL( bloodbath ), 0 );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T72( SPELL( ravager ), 0 );
        if( ( ( rti->player.meatcleaver.stack >= 3.000000f ) && UP( enrage.expire ) ) )SPELL( ragingblow );
        if( ( ( !UP( enrage.expire ) || ( rti->player.power < 50.000000f ) ) || !UP( ragingblow.expire ) ) )SPELL( bloodthirst );
        if( ( rti->player.meatcleaver.stack >= 3.000000f ) )SPELL( ragingblow );
        {
            if( ( ( TO_SECONDS( REMAIN( enrage.expire ) ) > 6.000000f ) && ( ( ( ( T71( 1, 0 ) && ( 0 > 45.000000f ) ) || ( !T71( 1, 0 ) && ( 0 > 60.000000f ) ) ) || !0 ) || ( num_enemies > num_enemies ) ) ) )SPELL( recklessness );
            if( ( ( TO_SECONDS( REMAIN( enrage.expire ) ) > 6.000000f ) && ( ( ( ( T71( 1, 0 ) && ( 0 > 45.000000f ) ) || ( !T71( 1, 0 ) && ( 0 > 60.000000f ) ) ) || !0 ) || ( num_enemies > num_enemies ) ) ) )T63( SPELL( bladestorm ), 0 );
        }
        SPELL( whirlwind );
        T73( SPELL( siegebreaker ), 0 );
        if( T32( UP( suddendeath.expire ), 0 ) )SPELL( execute );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T43( SPELL( dragonroar ), 0 );
        SPELL( bloodthirst );
        if( UP( bloodsurge.expire ) )SPELL( wildstrike );
    }
    {
        T62( SPELL( bloodbath ), 0 );
        if( ( ( enemy_health_percent( rti ) < 20.000000f ) && 0 ) )SPELL( recklessness );
        if( ( ( rti->player.power > ( power_max - 20.000000f ) ) && ( enemy_health_percent( rti ) > 20.000000f ) ) )SPELL( wildstrike );
        if( ( ( ( !T33( 1, 0 ) && ( rti->player.power < ( power_max - 40.000000f ) ) ) || !UP( enrage.expire ) ) || ( rti->player.ragingblow.stack < 2.000000f ) ) )SPELL( bloodthirst );
        if( ( T62( UP( bloodbath.expire ), 0 ) || ( !T62( 1, 0 ) && ( ( !0 || ( 0 > 60.000000f ) ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 40.000000f ) ) ) ) )T72( SPELL( ravager ), 0 );
        T73( SPELL( siegebreaker ), 0 );
        if( T32( UP( suddendeath.expire ), 0 ) )SPELL( execute );
        T41( SPELL( stormbolt ), 0 );
        if( UP( bloodsurge.expire ) )SPELL( wildstrike );
        if( ( UP( enrage.expire ) || ( TO_SECONDS( TIME_DISTANT( rti->expected_combat_length ) ) < 12.000000f ) ) )SPELL( execute );
        if( ( T62( UP( bloodbath.expire ), 0 ) || !T62( 1, 0 ) ) )T43( SPELL( dragonroar ), 0 );
        SPELL( ragingblow );
        if( ( ( TO_SECONDS( REMAIN( bloodthirst.cd ) ) < 0.500000f ) && ( rti->player.power < 50.000000f ) ) )return;
        if( ( UP( enrage.expire ) && ( enemy_health_percent( rti ) > 20.000000f ) ) )SPELL( wildstrike );
        if( !0 )T63( SPELL( bladestorm ), 0 );
        if( !T33( 1, 0 ) )T42( SPELL( shockwave ), 0 );
        SPELL( bloodthirst );
    }

}

void host_kernel_entry() {
    float result;
    sim_iterate( &result, 5171, 4313 + 250, 2148 + 125, 751, 1504, 478, 0 );

    printf( "result: %.3f\nmax queue length: %d\nruntime state size: %d\n", result, maxqueuelength, sizeof( rtinfo_t ) );
}
#endif /* !defined(__OPENCL_VERSION__) */

/*
int main(){
    host_kernel_entry();
}
*/

