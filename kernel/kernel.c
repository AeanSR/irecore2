/**
    IreCore kernel - Compute Frame

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#define SHOW_LOG

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
double floor( double x );
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
#define FROM_MILLISECONDS( msec ) ((time_t)convert_uint_rtp((float)(msec)))
#define TO_SECONDS( timestamp ) (convert_float_rtp((k32u)timestamp) * 0.001f)
#define TIME_OFFSET( time ) ((time_t)((k32s)rti->timestamp + (k32s)time))
#define TIME_DISTANT( time ) ((time_t)max((k32s)(time) - (k32s)(rti->timestamp), 0))
#define UP( time_to_check ) ((time_to_check) > rti->timestamp )
#define REMAIN( time_to_check ) ((time_t)max(((k32s)(time_to_check) - (k32s)rti->timestamp), 0))

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
    _event_t event[EQ_SIZE];
} event_queue_t;
hostonly(
    static k32u maxqueuelength = 0;
)

typedef struct stat_t {
    k32u gear_str;
    k32u gear_crit;
    k32u gear_haste;
    k32u gear_mastery;
    k32u gear_vers;
    float crit;
    float haste;
    float mastery;
    float vers;
    k32u str;
    k32u ap;
} stat_t;

/* Player struct, filled by the class module. */
typedef struct {
    float power;
    stat_t stat;
    struct common_state_t* common;
    struct class_state_t* class;
    struct spec_state_t* spec;
    time_t gcd;
    k32u target;
    kbool busy;
    kbool trinket_active;
} player_t;

typedef struct {
    struct common_debuff_t* common;
    struct class_debuff_t* class;
    struct spec_debuff_t* spec;
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
} rtinfo_t;

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
/** Routine number 0xFFFFFFFF indicates the end of simulation. */
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
    k32u i = rti->eq.count + 1;
    _event_t* p = rti->eq.event - 1;

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
        rti->eq.count ++;
        return &p[i];
    }

    return 0;
}

/* EQ will call this function when time elapsed. */
void on_time_elapsed( rtinfo_t* rti, time_t last_time );

/* EQ will visit check point timestamp. */
time_t check_point( rtinfo_t* rti );

/* Execute the top priority. */
int eq_execute( rtinfo_t* rti ) {
    k32u i, child;
    _event_t min, last;
    _event_t* p = rti->eq.event - 1;

    assert( rti->eq.count ); /* Empty check. */
    assert( rti->eq.count <= EQ_SIZE ); /* Not zero but negative? */
    assert( rti->timestamp <= p[1].time ); /* Time won't go back. */

    /* When time elapse, trigger a full scanning at APL. */
    if ( rti->timestamp < p[1].time ) {
        if ( !rti->player.busy )
            if ( !STRICT_GCD || !UP( rti->player.gcd ) ) /* Strict GCD: Do not scan APL if GCD is up. */
                scan_apl( rti ); /* This may change p[1]. */

        /* Check again. */
        assert( rti->eq.count );
        assert( rti->eq.count <= EQ_SIZE );
        assert( rti->timestamp <= p[1].time );
    }

    min = p[1];

    time_t check = check_point( rti );
    if ( !UP( check ) || min.time <= check ) { /* Check point is not valid. */
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
    } else {  /* Check point inserted between now and min. */
        time_t last_time = rti->timestamp;
        rti->timestamp = check; /* Jump to check point first. */
        on_time_elapsed( rti, last_time );
        return 1;
    }
    /* Now 'min' contains the top priority. Execute it. */
    if ( min.routine == EVENT_END_SIMULATION ) /* Finish the simulation here. */
        return 0;

    if ( rti->timestamp != min.time ) {
        time_t last_time = rti->timestamp;
        rti->timestamp = min.time;
        on_time_elapsed( rti, last_time );
    }

    routine_entries( rti, min );

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

    /* Class module initializer. */
    module_init( rti );

    eq_enqueue( rti, rti->expected_combat_length, EVENT_END_SIMULATION, 0 );
}

// APL helper.
#define cycle_targets(v) safemacro( k32u t = rti->player.target; for( rti->player.target = 0; rti->player.target < num_enemies; rti->player.target++ ) { v; } rti->player.target = t; )
