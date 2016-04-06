/**
    IreCore kernel - Warrior Class Abstraction

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/* Tier 1 */
#define TALENT_WAR_MACHINE         ((SPEC == SPEC_FURY) && (TALENT_TIER1 == 1))
#define TALENT_ENDLESS_RAGE        ((SPEC == SPEC_FURY) && (TALENT_TIER1 == 2))
#define TALENT_FRESH_MEAT          ((SPEC == SPEC_FURY) && (TALENT_TIER1 == 3))
#define TALENT_DAUNTLESS           ((SPEC == SPEC_ARMS) && (TALENT_TIER1 == 1))
#define TALENT_OVERPOWER           ((SPEC == SPEC_ARMS) && (TALENT_TIER1 == 2))
#define TALENT_SWEEPING_STRIKES    ((SPEC == SPEC_ARMS) && (TALENT_TIER1 == 3))

/* Tier 2 */
#define TALENT_SHOCKWAVE           (TALENT_TIER2 == 1)
#define TALENT_STORM_BOLT          (TALENT_TIER2 == 2)
#define TALENT_DOUBLE_TIME         (TALENT_TIER2 == 3)

/* Tier 3 */
#define TALENT_FERVOR_OF_BATTLE    ((SPEC == SPEC_ARMS) && (TALENT_TIER3 == 1))
#define TALENT_REND                ((SPEC == SPEC_ARMS) && (TALENT_TIER3 == 2))
#define TALENT_WRECKING_BALL       ((SPEC == SPEC_FURY) && (TALENT_TIER3 == 1))
#define TALENT_OUTBURST            ((SPEC == SPEC_FURY) && (TALENT_TIER3 == 2))
#define TALENT_AVATAR              (TALENT_TIER3 == 3)

/* Tier 4 */
#define TALENT_FURIOUS_CHARGE      ((SPEC == SPEC_FURY) && (TALENT_TIER4 == 1))
#define TALENT_WARPAINT            ((SPEC == SPEC_FURY) && (TALENT_TIER4 == 3))
#define TALENT_SECOND_WIND         ((SPEC == SPEC_ARMS) && (TALENT_TIER4 == 1))
#define TALENT_DIE_BY_THE_SWORD    ((SPEC == SPEC_ARMS) && (TALENT_TIER4 == 3))
#define TALENT_BOUNDING_STRIDE     (TALENT_TIER4 == 2)

/* Tier 5 */
#define TALENT_IN_FOR_THE_KILL     ((SPEC == SPEC_ARMS) && (TALENT_TIER5 == 1))
#define TALENT_MORTAL_COMBO        ((SPEC == SPEC_ARMS) && (TALENT_TIER5 == 2))
#define TALENT_MASSACRE            ((SPEC == SPEC_FURY) && (TALENT_TIER5 == 1))
#define TALENT_FROTHING_BERSERKER  ((SPEC == SPEC_FURY) && (TALENT_TIER5 == 2))
#define TALENT_BLADESTORM          (TALENT_TIER5 == 3)

/* Tier 6 */
#define TALENT_MEAT_GRINDER        ((SPEC == SPEC_FURY) && (TALENT_TIER6 == 1))
#define TALENT_FRENZY              ((SPEC == SPEC_FURY) && (TALENT_TIER6 == 2))
#define TALENT_INNER_RAGE          ((SPEC == SPEC_FURY) && (TALENT_TIER6 == 3))
#define TALENT_FOCUSED_RAGE        ((SPEC == SPEC_ARMS) && (TALENT_TIER6 == 1))
#define TALENT_TRAUMA              ((SPEC == SPEC_ARMS) && (TALENT_TIER6 == 2))
#define TALENT_TITANIC_MIGHT       ((SPEC == SPEC_ARMS) && (TALENT_TIER6 == 3))

/* Tier 7 */
#define TALENT_CARNAGE             ((SPEC == SPEC_FURY) && (TALENT_TIER7 == 1))
#define TALENT_RECKLESS_ABANDON    ((SPEC == SPEC_FURY) && (TALENT_TIER7 == 2))
#define TALENT_DRAGON_ROAR         ((SPEC == SPEC_FURY) && (TALENT_TIER7 == 3))
#define TALENT_ANGER_MANAGEMENT    ((SPEC == SPEC_ARMS) && (TALENT_TIER7 == 1))
#define TALENT_OPPORTUNITY_STRIKES ((SPEC == SPEC_ARMS) && (TALENT_TIER7 == 2))
#define TALENT_RAVAGER             ((SPEC == SPEC_ARMS) && (TALENT_TIER7 == 3))

/* class state infos. */
struct class_state_t {
    struct {
        time_t expire;
        time_t cd;
    } battle_cry;
    #define battle_cry_expire (rti->player.class->battle_cry.expire)
    #define battle_cry_cd     (rti->player.class->battle_cry.cd)
    struct {
        time_t cd;
    } berserker_rage;
    #define berserker_rage_cd (rti->player.class->berserker_rage.cd)
    struct {
        time_t cd;
    } heroic_leap;
    #define heroic_leap_cd (rti->player.class->heroic_leap.cd)
#if (TALENT_SHOCKWAVE)
    struct {
        time_t cd;
    } shockwave;
    #define shockwave_cd (rti->player.class->shockwave.cd)
#else
    #define shockwave_cd (0)
#endif
#if (TALENT_STORM_BOLT)
    struct {
        time_t cd;
    } storm_bolt;
    #define storm_bolt_cd (rti->player.class->storm_bolt.cd)
#else
    #define storm_bolt_cd (0)
#endif
#if (TALENT_AVATAR)
    struct {
        time_t expire;
        time_t cd;
    } avatar;
    #define avatar_expire (rti->player.class->avatar.expire)
    #define avatar_cd     (rti->player.class->avatar.cd)
#else
    #define avatar_expire (0)
    #define avatar_cd     (0)
#endif
#if (TALENT_BLADESTORM)
    struct {
        time_t cd;
        time_t expire;
        time_t tick_interval;
    } bladestorm;
    #define bladestorm_expire (rti->player.class->bladestorm.expire)
    #define bladestorm_cd     (rti->player.class->bladestorm.cd)
#else
    #define bladestorm_expire (0)
    #define bladestorm_cd     (0)
#endif
};
struct class_debuff_t {
};

void on_time_elapsed( rtinfo_t* rti, time_t last_time ) {

}
time_t check_point( rtinfo_t* rti ) {
#if (TALENT_ANGER_MANAGEMENT) // when battle cry cd varies a lot, use check point instead of events to track.
    return battle_cry_cd;
#endif
    return 0;
}

/* Event list. */
enum {
    END_OF_COMMON_ROUTNUM = START_OF_CLASS_ROUTNUM - 1,
    routnum_battle_cry_start,
    routnum_battle_cry_expire,
    routnum_battle_cry_cd,
    routnum_berserker_rage_cd,
    routnum_heroic_leap_cast,
    routnum_heroic_leap_cd,
#if (TALENT_SHOCKWAVE)
    routnum_shockwave_cd,
    routnum_shockwave_cast,
#endif
#if (TALENT_STORM_BOLT)
    routnum_storm_bolt_cd,
    routnum_storm_bolt_cast,
#endif
#if (TALENT_AVATAR)
    routnum_avatar_start,
    routnum_avatar_expire,
    routnum_avatar_cd,
#endif
#if (TALENT_BLADESTORM)
    routnum_bladestorm_tick,
    routnum_bladestorm_cd,
#endif
    START_OF_SPEC_ROUTNUM,
};

// === battle cry =============================================================
DECL_EVENT( battle_cry_cd ) {
    if ( battle_cry_cd == rti->timestamp ) {
        lprintf( ( "battle_cry cd" ) );
    }
}
DECL_EVENT( battle_cry_expire ) {
    lprintf( ( "battle_cry expire" ) );
}
DECL_EVENT( battle_cry_start ) {
    if ( TALENT_RECKLESS_ABANDON ) power_gain( rti, 100.0f );
    lprintf( ( "battle_cry start" ) );
}
void spec_spell_battle_cry( rtinfo_t* rti );
DECL_SPELL( battle_cry ) {
    if ( battle_cry_cd > rti->timestamp ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_battle_cry_start, 0 );
    battle_cry_expire = TIME_OFFSET( FROM_SECONDS( 5 ) );
    eq_enqueue( rti, battle_cry_expire, routnum_battle_cry_expire, 0 );
    battle_cry_cd = TIME_OFFSET( FROM_SECONDS( 60 ) ); // TODO: some traits would decrease cd?
    spec_spell_battle_cry( rti ); // this may modify cd!
    if ( !TALENT_ANGER_MANAGEMENT ) eq_enqueue( rti, battle_cry_cd, routnum_battle_cry_cd, 0 ); // when battle cry cd varies a lot, use check point instead of events to track.
    return 1;
}

// === berserker rage =========================================================
DECL_EVENT( berserker_rage_cd ) {
    lprintf( ( "berserker_rage cd" ) );
}
void spec_berserker_rage_cast( rtinfo_t* rti );
DECL_SPELL( berserker_rage ) {
    if ( berserker_rage_cd > rti->timestamp ) return 0;
    spec_berserker_rage_cast( rti );
    berserker_rage_cd = TIME_OFFSET( FROM_SECONDS( (TALENT_OUTBURST) ? 90 : 60 ) );
    eq_enqueue( rti, berserker_rage_cd, routnum_berserker_rage_cd, 0 );
    lprintf( ( "cast berserker_rage" ) );
    return 1;
}

// === heroic leap ============================================================
DECL_EVENT( heroic_leap_cd ) {
    lprintf( ( "heroic_leap cd" ) );
}
DECL_EVENT( heroic_leap_cast ) {
    float d = ap_dmg( rti, 0.624f );
    for ( int i = 0; i < num_enemies; i++ ) {
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        lprintf( ( "heroic_leap hit" ) );
    }
}
DECL_SPELL( heroic_leap ) {
    if ( heroic_leap_cd > rti->timestamp ) return 0;
    eq_enqueue( rti, rti->timestamp, routnum_heroic_leap_cast, 0 );
    heroic_leap_cd = TIME_OFFSET( FROM_SECONDS( (TALENT_BOUNDING_STRIDE) ? 30 : 45 ) );
    eq_enqueue( rti, heroic_leap_cd, routnum_heroic_leap_cd, 0 );
    return 1;
}

// === shockwave ==============================================================
#if (TALENT_SHOCKWAVE)
DECL_EVENT( shockwave_cd ) {
    lprintf( ( "shockwave cd" ) );
}
DECL_EVENT( shockwave_cast ) {
    float d = ap_dmg( rti, 0.95f );
    for ( int i = 0; i < num_enemies; i++ ) {
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        lprintf( ( "shockwave hit" ) );
    }
}
DECL_SPELL( shockwave ) {
    if ( shockwave_cd > rti->timestamp ) return 0;
    if ( rti->player.gcd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_shockwave_cast, 0 );
    shockwave_cd = TIME_OFFSET( FROM_SECONDS( ( num_enemies >= 3 ) ? 20 : 40 ) );
    eq_enqueue( rti, shockwave_cd, routnum_shockwave_cd, 0 );
    return 1;
}
#else
DECL_SPELL( shockwave ) {
    return 0;
}
#endif

// === storm bolt =============================================================
#if (TALENT_STORM_BOLT)
DECL_EVENT( storm_bolt_cd ) {
    lprintf( ( "storm_bolt cd" ) );
}
DECL_EVENT( storm_bolt_cast ) {
    float d = ap_dmg( rti, 2.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    lprintf( ( "storm_bolt hit" ) );
}
DECL_SPELL( storm_bolt ) {
    if ( storm_bolt_cd > rti->timestamp ) return 0;
    if ( rti->player.gcd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_storm_bolt_cast, rti->player.target );
    storm_bolt_cd = TIME_OFFSET( FROM_SECONDS( 30 ) );
    eq_enqueue( rti, storm_bolt_cd, routnum_storm_bolt_cd, 0 );
    return 1;
}
#else
DECL_SPELL( storm_bolt ) {
    return 0;
}
#endif

// === avatar =================================================================
#if (TALENT_AVATAR)
DECL_EVENT( avatar_cd ) {
    lprintf( ( "avatar cd" ) );
}
DECL_EVENT( avatar_expire ) {
    lprintf( ( "avatar expire" ) );
}
DECL_EVENT( avatar_start ) {
    lprintf( ( "avatar start" ) );
}
DECL_SPELL( avatar ) {
    if ( avatar_cd > rti->timestamp ) return 0;
    avatar_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, avatar_expire, routnum_avatar_expire, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_avatar_start, 0 );
    avatar_cd = TIME_OFFSET( FROM_SECONDS( 90 ) );
    eq_enqueue( rti, avatar_cd, routnum_avatar_cd, 0 );
    return 1;
}
#else
DECL_SPELL( avatar ) {
    return 0;
}
#endif

// === bladestorm =============================================================
#if (TALENT_BLADESTORM)
DECL_EVENT( bladestorm_cd ) {
    if ( bladestorm_cd == rti->timestamp ) {
        lprintf( ( "bladestorm ready" ) );
    }
}
void spec_bladestorm_tick( rtinfo_t* rti );
DECL_EVENT( bladestorm_tick ) {
    spec_bladestorm_tick( rti );
    if ( bladestorm_expire > rti->timestamp + FROM_MILLISECONDS( 6 ) ) {
        eq_enqueue( rti, TIME_OFFSET( rti->player.class->bladestorm.tick_interval ), routnum_bladestorm_tick, target_id );
    } else {
        rti->player.busy = 0;
        lprintf( ( "bladestorm expire" ) );
    }
}
DECL_SPELL( bladestorm ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( bladestorm_cd > rti->timestamp ) return 0;
    bladestorm_cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
    rti->player.class->bladestorm.tick_interval = FROM_SECONDS( 1.0f / ( 1.0f + rti->player.stat.haste ) );
    bladestorm_expire = TIME_OFFSET( 6 * rti->player.class->bladestorm.tick_interval );
    rti->player.busy = 1; /* keep player busy during bladestorm to avoid actions. */
    eq_enqueue( rti, bladestorm_cd, routnum_bladestorm_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_bladestorm_tick, 0 );
    lprintf( ( "cast bladestorm" ) );
    return 1;
}
#else
DECL_SPELL( bladestorm ) {
    return 0;
}
#endif

void spec_routine_entries( rtinfo_t* rti, _event_t e );

void class_routine_entries( rtinfo_t* rti, _event_t e ) {
    if( e.routine >= START_OF_SPEC_ROUTNUM ) {
        spec_routine_entries( rti, e );
    }
    else switch( e.routine ) {
        HOOK_EVENT( battle_cry_start );
        HOOK_EVENT( battle_cry_expire );
        HOOK_EVENT( battle_cry_cd );
        HOOK_EVENT( berserker_rage_cd );
        HOOK_EVENT( heroic_leap_cast );
        HOOK_EVENT( heroic_leap_cd );
#if (TALENT_SHOCKWAVE)
        HOOK_EVENT( shockwave_cd );
        HOOK_EVENT( shockwave_cast );
#endif
#if (TALENT_STORM_BOLT)
        HOOK_EVENT( storm_bolt_cd );
        HOOK_EVENT( storm_bolt_cast );
#endif
#if (TALENT_AVATAR)
        HOOK_EVENT( avatar_start );
        HOOK_EVENT( avatar_expire );
        HOOK_EVENT( avatar_cd );
#endif
#if (TALENT_BLADESTORM)
        HOOK_EVENT( bladestorm_tick );
        HOOK_EVENT( bladestorm_cd );
#endif
    default:
        lprintf( ( "wild class routine entry %d", e.routine ) );
        assert( 0 );
    }
}

void spec_module_init( rtinfo_t* rti );

void class_module_init( rtinfo_t* rti ) {
    spec_module_init( rti );
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id );

void class_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    spec_special_procs( rti, attacktype, dice, target_id );
}
