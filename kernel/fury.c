/**
    IreCore kernel - Fury Specialization

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/* spec state infos. */
struct spec_state_t{
    struct {
        time_t cd;
    } bloodthirst;
    #define bloodthirst_cd (rti->player.class->spec->bloodthirst.cd)
    struct {
        time_t expire;
    } enrage;
    #define enrage_expire (rti->player.class->spec->enrage.expire)
#if (TALENT_FROTHING_BERSERKER)
    struct {
        time_t expire;
    } frothing_berserker;
    #define frothing_berserker_expire (rti->player.class->spec->frothing_berserker.expire)
#else
    #define frothing_berserker_expire (0)
#endif
#if defined(trinket_worldbreakers_resolve)
    struct {
        time_t expire;
        k32u   stack;
        k32u   target;
    } worldbreakers_resolve;
    #define worldbreakers_resolve_expire (rti->player.class->spec->worldbreakers_resolve.expire)
    #define worldbreakers_resolve_stack  (rti->player.class->spec->worldbreakers_resolve.stack)
#else
    #define worldbreakers_resolve_expire (0)
    #define worldbreakers_resolve_stack  (0)
#endif
};
struct spec_debuff_t{

};

float spec_mastery_coefficient( rtinfo_t* rti ){
    return 1.4f;
}

float spec_mastery_increament( rtinfo_t* rti ){
    return 0.0f;
}

float spec_haste_coefficient( rtinfo_t* rti ){
    float coeff = 1.0f;
#if defined(trinket_worldbreakers_resolve)
    coeff *= 1.0f + ( trinket_worldbreakers_resolve * worldbreakers_resolve_stack ) * 0.0001f;
#endif
    return coeff;
}

k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate;
    if (ATYPE_WHITE_MELEE == attacktype){
        cr += 0.19f;
        cr += 0.24f;
        if ( c < 0.19f ) return DICE_MISS;
        if ( c < 0.19f + 0.24f ) return DICE_GLANCE; // TODO: does legion melee glance?
    }
    if (ATYPE_YELLOW_MELEE == attacktype){
        if ( UP( battle_cry_expire ) ) cr += 1.0f;
    }
    if ( c < cr ){
        return DICE_CRIT;
    }
    return DICE_HIT;
}

k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    k32u dice = round_table_dice2( rti, target_id, attacktype, extra_crit_rate );
    special_procs( rti, attacktype, dice, target_id );
    return dice;
}

float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor ) {
    if ( DICE_MISS == dice ) return .0f;
    if ( DTYPE_DIRECT == dmgtype ){
        lprintf( ( "damage %.0f", dmg ) );
        rti->damage_collected += dmg;
        return dmg;
    }
    float cdb = ( 1.0f + extra_crit_bonus ) * 2.0f;
                                                                    dmg *= 1.0f + rti->player.stat.vers;
        if ( UP( enrage_expire ) )                                  dmg *= 1.0f + rti->player.stat.mastery;
        if ( UP( avatar_expire ) )                                  dmg *= 1.2f;
        if ( UP( frothing_berserker_expire ) )                      dmg *= 1.1f;
        if ( UP( thorasus_the_stone_heart_of_draenor_expire ) )     dmg *= 1.0f + legendary_ring * 0.0001f;
        if ( ENEMY_IS_DEMONIC && UP(gronntooth_war_horn_expire ) )  dmg *= 1.1f;
    //  if ( SOME_ARTIFACT_TRAITS && UP( battle_cry_expire ) )      cdb *= 1.0f + 0.1f * SOME_ARTIFACT_TRAITS;
        if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )            cdb *= 1.02f;
    if (DTYPE_PHYSICAL == dmgtype){
        if ( !ignore_armor )                                        dmg *= 0.650684f; // 0.680228f @110lvl
    }
        if ( DICE_GLANCE == dice )                                  dmg *= 0.75f; // TODO: if glancing exists, what the coeff is?
        if ( DICE_CRIT   == dice )                                  dmg *= cdb;
    if ( DICE_CRIT   == dice ){
        lprintf( ( "damage *%.0f*", dmg ) );
    } else {
        lprintf( ( "damage %.0f", dmg ) );
    }
    rti->damage_collected += dmg;
    return dmg;
}

/* event list. */
enum{
    END_OF_CLASS_ROUTNUM = START_OF_SPEC_ROUTNUM - 1,
    routnum_auto_attack_mh,
    routnum_auto_attack_oh,
    routnum_bloodthirst_cd,
    routnum_bloodthirst_cast,
    routnum_enrage_trigger,
    routnum_enrage_expire,
    routnum_execute_cast,
#if (TALENT_FROTHING_BERSERKER)
    routnum_frothing_berserker_trigger,
    routnum_frothing_berserker_expire,
#endif
#if defined(trinket_worldbreakers_resolve)
    routnum_worldbreakers_resolve_expire,
    routnum_worldbreakers_resolve_trigger,
#endif
    START_OF_WILD_ROUTNUM,
};

// === auto-attack ============================================================
DECL_EVENT( auto_attack_mh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 0 );

    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 );
    if ( dice == DICE_MISS ) {
        /* Miss */
        lprintf( ( "mh miss" ) );
    } else {
        power_gain( rti, 1.4f * weapon[0].speed * ( TALENT_ENDLESS_RAGE ? 1.3f : 1.0f ) );
        lprintf( ( "mh hit" ) );
    }

    float aspeed = 1.0f + rti->player.stat.haste;
    if ( UP( enrage_expire ) ) aspeed *= 2.0f;
#if (t17_4pc)
    aspeed *= 1.0f + 0.06f * rti->player.rampage.stack;
#endif
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[0].speed / aspeed ) ), routnum_auto_attack_mh, rti->player.target );
}

DECL_EVENT( auto_attack_oh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 1 );
    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 );
    if ( dice == DICE_MISS ) {
        /* Miss */
        lprintf( ( "oh miss" ) );
    } else {
        power_gain( rti, 1.4f * weapon[1].speed * 0.5f * ( TALENT_ENDLESS_RAGE ? 1.3f : 1.0f ) );
        lprintf( ( "oh hit" ) );
    }

    float aspeed = 1.0f + rti->player.stat.haste;
    if ( UP( enrage_expire ) ) aspeed *= 2.0f;
#if (t17_4pc)
    aspeed *= 1.0f + 0.06f * rti->player.rampage.stack;
#endif
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / aspeed ) ), routnum_auto_attack_oh, rti->player.target );
}

// === berserker rage =========================================================
void spec_berserker_rage_cast( rtinfo_t* rti ) {
    if (TALENT_OUTBURST)
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
}

// === bloodthirst ============================================================
DECL_EVENT( bloodthirst_cd ) {
    lprintf( ( "bloodthirst cd" ) );
}
DECL_EVENT( bloodthirst_cast ) {
    float d = weapon_dmg( rti, 3.5f, 1, 0 );
    float cr = 0.0f;
    if ( TALENT_FRESH_MEAT && enemy_health_percent( rti ) > 80.0f ) cr += 0.3f;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, cr );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    if ( DICE_CRIT == dice )
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
    power_gain( rti, 10.0f );
    lprintf( ( "bloodthirst hit" ) );
}
DECL_SPELL( bloodthirst ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( bloodthirst_cd > rti->timestamp ) return 0;
    bloodthirst_cd = TIME_OFFSET( FROM_SECONDS( 4.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, bloodthirst_cd, routnum_bloodthirst_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_bloodthirst_cast, rti->player.target );
    lprintf( ( "cast bloodthirst" ) );
    return 1;
}

// === enrage =================================================================
DECL_EVENT( enrage_expire ) {
    if ( enrage_expire == rti->timestamp ) {
        lprintf( ( "enrage expire" ) );
    }
}
DECL_EVENT( enrage_trigger ) {
    enrage_expire = TIME_OFFSET( FROM_SECONDS( 4 ) ); // TODO: does haste decrease enrage duration?
    eq_enqueue( rti, enrage_expire, routnum_enrage_expire, 0 );
    lprintf( ( "enrage trigger" ) );
}

// === execute ================================================================
DECL_EVENT( execute_cast ) {
    float d = weapon_dmg( rti, 5.0f, 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    //if ( TALENT_MASSACRE && DICE_CRIT == dice ) // TODO: see if massacre triggers from off-hand execute when go live.
        // eq_enqueue( rti, rti->timestamp, routnum_massacre_trigger, 0 );
    d = weapon_dmg( rti, 5.0f, 1, 1 );
    dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    lprintf( ( "execute hit" ) );
}
DECL_SPELL( execute ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( power_check( rti, 25.0f ) ) return 0;
    if ( enemy_health_percent( rti ) > 20.0f ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_execute_cast, rti->player.target );
    lprintf( ( "cast execute" ) );
    return 1;
}

// === frothing berserker =====================================================
#if (TALENT_FROTHING_BERSERKER)
DECL_EVENT( frothing_berserker_expire ) {
    if ( frothing_berserker_expire == rti->timestamp ) {
        lprintf( ( "frothing_berserker expire" ) );
    }
}
DECL_EVENT( frothing_berserker_trigger ) {
    frothing_berserker_expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    eq_enqueue( rti, frothing_berserker_expire, routnum_frothing_berserker_expire, 0 );
    lprintf( ( "frothing_berserker trigger" ) );
}
void frothing_berserker_trigger( rtinfo_t* rti ) {
    eq_enqueue( rti, rti->timestamp, routnum_frothing_berserker_trigger, 0 );
}
#endif

// === bladestorm =============================================================
#if (TALENT_BLADESTORM)
void spec_bladestorm_tick( rtinfo_t* rti ) {
    for( int i = 0; i < num_enemies; i++ ) {
        float d = weapon_dmg( rti, 2.88f, 1, 0 );
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 2.88f, 1, 1 );
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        lprintf( ( "bladestorm tick @tar%d", i ) );
    }
}
#endif

// === spec trinket ===========================================================
#if defined(trinket_worldbreakers_resolve)
DECL_EVENT( worldbreakers_resolve_expire ) {
    if ( rti->timestamp == worldbreakers_resolve_expire ) {
        lprintf( ( "worldbreakers_resolve expire" ) );
        worldbreakers_resolve_stack = 0;
        refresh_haste( rti );
    }
}
DECL_EVENT( worldbreakers_resolve_trigger ) {
    worldbreakers_resolve_stack++;
    if ( !WBR_NEVER_EXPIRE ) {
        worldbreakers_resolve_expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
        eq_enqueue( rti, worldbreakers_resolve_expire, routnum_worldbreakers_resolve_expire, 0 );
        if( rti->player.class->spec->worldbreakers_resolve.target != target_id ) { /* Target switched. */
            worldbreakers_resolve_stack = 1;
        }
        rti->player.class->spec->worldbreakers_resolve.target = target_id;
    }
    if ( worldbreakers_resolve_stack > 10 ) {
        worldbreakers_resolve_stack = 10;
    }
    else {
        lprintf( ( "worldbreakers_resolve stack %d", worldbreakers_resolve_stack ) );
        refresh_haste( rti );
    }
}
#endif

void spec_routine_entries( rtinfo_t* rti, _event_t e ) {
    switch( e.routine ) {
        HOOK_EVENT( auto_attack_mh );
        HOOK_EVENT( auto_attack_oh );
        HOOK_EVENT( bloodthirst_cd );
        HOOK_EVENT( bloodthirst_cast );
        HOOK_EVENT( enrage_trigger );
        HOOK_EVENT( enrage_expire );
        HOOK_EVENT( execute_cast );
#if (TALENT_FROTHING_BERSERKER)
        HOOK_EVENT( frothing_berserker_trigger );
        HOOK_EVENT( frothing_berserker_expire );
#endif
#if defined(trinket_worldbreakers_resolve)
        HOOK_EVENT( worldbreakers_resolve_trigger );
        HOOK_EVENT( worldbreakers_resolve_expire );
#endif
    default:
        lprintf( ( "wild spec routine entry %d, last defined routnum %d", e.routine, START_OF_WILD_ROUTNUM - 1 ) );
        assert( 0 );
    }
}

void spec_module_init( rtinfo_t* rti ) {
    static struct spec_state_t spec_state;
    static struct spec_debuff_t spec_debuff[num_enemies];
    rti->player.class->spec = &spec_state;
    for(int i = 0; i < num_enemies; i++){
        rti->enemy[i].class->spec = &spec_debuff[i];
    }

    eq_enqueue( rti, rti->timestamp, routnum_auto_attack_mh, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( SYNC_MELEE ? 0 : 0.5 ) ), routnum_auto_attack_oh, 0 );
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
#if defined(trinket_worldbreakers_resolve)
    if ( ATYPE_WHITE_MELEE == attacktype ){
        eq_enqueue( rti, rti->timestamp, routnum_worldbreakers_resolve_trigger, target_id );
    }
#endif
}
