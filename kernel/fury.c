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
    coeff *= 1.0f + ( trinket_worldbreakers_resolve * worldbreakers_resolve_stack ) * 0.0001;
#endif
    return coeff;
}

k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate;
    special_procs( rti, attacktype, target_id );
    if (ATYPE_WHITE_MELEE == attacktype){
        cr += 0.19f;
        cr += 0.24f;
        if ( c < 0.19f ) return DICE_MISS;
        if ( c < 0.19f + 0.24f ) return DICE_GLANCE; // TODO: does legion melee glance?
    }
    if (ATYPE_YELLOW_MELEE == attacktype){
        // TODO: battle shout
    }
    if ( c < cr ){
#if (thunderlord_mh)
        if ( UP( rti->player.class->enchant_mh.expire ) && rti->player.class->enchant_mh.extend ) {
            rti->player.class->enchant_mh.extend --;
            rti->player.class->enchant_mh.expire += FROM_SECONDS( 2 );
            eq_enqueue( rti, rti->player.class->enchant_mh.expire, routnum_enchant_mh_expire, target_id );
        }
#endif
#if (thunderlord_oh)
        if ( UP( rti->player.class->enchant_oh.expire ) && rti->player.enchant_oh.extend ) {
            rti->player.class->enchant_oh.extend --;
            rti->player.class->enchant_oh.expire += FROM_SECONDS( 2 );
            eq_enqueue( rti, rti->player.class->enchant_oh.expire, routnum_enchant_oh_expire, target_id );
        }
#endif
        return DICE_CRIT;
    }
    return DICE_HIT;
}

float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor ) {
    if (DTYPE_DIRECT == dmgtype){
        lprintf( ( "damage %.0f", dmg ) );
        rti->damage_collected += dmg;
        return dmg;
    }
    float cdb = ( 1.0f + extra_crit_bonus ) * ( ( RACE == RACE_DWARF || RACE == RACE_TAUREN ) ? 2.04f : 2.0f );
                                                                    dmg *= 1.0f + rti->player.stat.vers;
    //  if ( UP( enrage_expire ) )                                  dmg *= 1.0f + rti->player.stat.mastery;
    //  if ( UP( avatar_expire ) )                                  dmg *= 1.2f;
        if ( UP( thorasus_the_stone_heart_of_draenor_expire ) )     dmg *= 1.0f + legendary_ring * 0.0001f;
        if ( ENEMY_IS_DEMONIC && UP(gronntooth_war_horn_expire ) )  dmg *= 1.1f;
    //  if ( SOME_ARTIFACT_TRAITS && UP( battleshout_expire ) )     cdb *= 1.1f * SOME_ARTIFACT_TRAITS;
    if (DTYPE_PHYSICAL == dmgtype){
        if ( !ignore_armor )                                        dmg *= 0.650684f; // 0.680228 @110lvl
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
#if defined(trinket_worldbreakers_resolve)
    routnum_worldbreakers_resolve_expire,
    routnum_worldbreakers_resolve_trigger,
#endif
    START_OF_WILD_ROUTNUM,
};

// === Auto-attack ============================================================
DECL_EVENT( auto_attack_mh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 0 );

    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 );
    if ( dice == DICE_MISS ) {
        /* Miss */
        lprintf( ( "mh miss" ) );
    } else {
        power_gain( rti, 1.4f * weapon[0].speed );
        lprintf( ( "mh hit" ) );
    }

    float aspeed = 1.0f + rti->player.stat.haste;
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
        power_gain( rti, 1.4f * weapon[1].speed * 0.5f );
        lprintf( ( "oh hit" ) );
    }

    float aspeed = 1.0f + rti->player.stat.haste;
#if (t17_4pc)
    aspeed *= 1.0f + 0.06f * rti->player.rampage.stack;
#endif
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / aspeed ) ), routnum_auto_attack_oh, rti->player.target );
}


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

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u target_id ) {
#if defined(trinket_worldbreakers_resolve)
    if ( ATYPE_WHITE_MELEE == attacktype ){
        eq_enqueue( rti, rti->timestamp, routnum_worldbreakers_resolve_trigger, target_id );
    }
#endif
}
