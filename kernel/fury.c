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
    struct {
        time_t expire;
        k32u stack;
    } taste_for_blood;
    #define taste_for_blood_expire (rti->player.class->spec->taste_for_blood.expire)
    #define taste_for_blood_stack  (rti->player.class->spec->taste_for_blood.stack)
    struct {
        time_t expire;
    } meat_cleaver;
    #define meat_cleaver_expire (rti->player.class->spec->meat_cleaver.expire)
#if (TALENT_WRECKING_BALL)
    struct {
        time_t expire;
        RPPM_t proc;
    } wrecking_ball;
    #define wrecking_ball_expire (rti->player.class->spec->wrecking_ball.expire)
#else
    #define wrecking_ball_expire (0)
#endif
#if (TALENT_MASSACRE)
    struct {
        time_t expire;
    } massacre;
    #define massacre_expire (rti->player.class->spec->massacre.expire)
#else
    #define massacre_expire (0)
#endif
#if (TALENT_FROTHING_BERSERKER)
    struct {
        time_t expire;
    } frothing_berserker;
    #define frothing_berserker_expire (rti->player.class->spec->frothing_berserker.expire)
#else
    #define frothing_berserker_expire (0)
#endif
#if (TALENT_MEAT_GRINDER)
    struct {
        time_t expire;
    } meat_grinder;
    #define meat_grinder_expire (rti->player.class->spec->meat_grinder.expire)
#else
    #define meat_grinder_expire (0)
#endif
#if (TALENT_FRENZY)
    struct {
        time_t expire;
        k32u stack;
    } frenzy;
    #define frenzy_expire (rti->player.class->spec->frenzy.expire)
    #define frenzy_stack  (rti->player.class->spec->frenzy.stack)
#else
    #define frenzy_expire (0)
    #define frenzy_stack  (0)
#endif
#if (TALENT_INNER_RAGE)
    struct {
        time_t cd;
    } raging_blow;
    #define raging_blow_cd (rti->player.class->spec->raging_blow.cd)
#else
    #define raging_blow_cd (0)
#endif
#if (TALENT_DRAGON_ROAR)
    struct {
        time_t cd;
        time_t expire;
    } dragon_roar;
    #define dragon_roar_cd     (rti->player.class->spec->dragon_roar.cd)
    #define dragon_roar_expire (rti->player.class->spec->dragon_roar.expire)
#else
    #define dragon_roar_cd     (0)
    #define dragon_roar_expire (0)
#endif
#if (t17_4pc)
    struct {
        time_t expire;
        k32u stack;
    } t17p4;
    #define rampage_expire (rti->player.class->spec->t17p4.expire)
    #define rampage_stack  (rti->player.class->spec->t17p4.stack)
#else
    #define rampage_expire (0)
    #define rampage_stack  (0)
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

float spec_crit_increament( rtinfo_t* rti ){
    float crit = 0.0f;
    if ( UP( rampage_expire ) ) {
        crit += 0.06f * rampage_stack;
    return crit;
}

float spec_haste_coefficient( rtinfo_t* rti ){
    float coeff = 1.0f;
    coeff *= 1.0f + frenzy_stack * 0.05f;
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
        if ( c < 0.19f ) return DICE_MISS;
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
        if ( UP( dragon_roar_expire ) )                             dmg *= 1.2f;
        if ( UP( frothing_berserker_expire ) )                      dmg *= 1.1f;
        if ( UP( thorasus_the_stone_heart_of_draenor_expire ) )     dmg *= 1.0f + legendary_ring * 0.0001f;
        if ( ENEMY_IS_DEMONIC && UP(gronntooth_war_horn_expire ) )  dmg *= 1.1f;
    //  if ( SOME_ARTIFACT_TRAITS && UP( battle_cry_expire ) )      cdb *= 1.0f + 0.1f * SOME_ARTIFACT_TRAITS;
        if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )            cdb *= 1.02f;
    if (DTYPE_PHYSICAL == dmgtype){
        if ( !ignore_armor )                                        dmg *= 0.650684f; // 0.680228f @110lvl
    }
        if ( DICE_CRIT   == dice )                                  dmg *= cdb;
    if ( DICE_CRIT   == dice ){
        lprintf( ( "damage *%.0f*", dmg ) );
    } else {
        lprintf( ( "damage %.0f", dmg ) );
    }
    rti->damage_collected += dmg;
    return dmg;
}

float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand ) {
    float dmg = ( float )weapon[offhand].low;
    dmg += uni_rng( rti ) * ( weapon[offhand].high - weapon[offhand].low );
    dmg += ( normalized ? normalized_weapon_speed[weapon[offhand].type] : weapon[offhand].speed ) * rti->player.stat.ap / 3.5f;
    dmg *= weapon_multiplier;
    if ( weapon[offhand].type == WEAPON_1H ) dmg *= 1.3f; // TODO: check if SMF need both weapon to be 1h when go live.
    if ( offhand ) dmg *= ( ( OH_TYPE == WEAPON_1H ) ? 1.2f : 1.0f ) * 0.5f;
    return dmg;
}

float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap;
    if ( MH_TYPE == WEAPON_1H ) dmg *= 1.3f;
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
    routnum_furious_slash_cast,
    routnum_taste_for_blood_trigger,
    routnum_taste_for_blood_expire,
    routnum_meat_cleaver_expire,
    routnum_meat_cleaver_trigger,
    routnum_raging_blow_cast,
    routnum_rampage_cast_1,
    routnum_rampage_cast_2,
    routnum_rampage_cast_3,
    routnum_rampage_cast_4,
    routnum_whirlwind_cast,
#if (TALENT_WRECKING_BALL)
    routnum_wrecking_ball_trigger,
    routnum_wrecking_ball_expire,
#endif
#if (TALENT_MASSACRE)
    routnum_massacre_trigger,
    routnum_massacre_expire,
#endif
#if (TALENT_FROTHING_BERSERKER)
    routnum_frothing_berserker_trigger,
    routnum_frothing_berserker_expire,
#endif
#if (TALENT_MEAT_GRINDER)
    routnum_meat_grinder_trigger,
    routnum_meat_grinder_expire,
#endif
#if (TALENT_FRENZY)
    routnum_frenzy_trigger,
    routnum_frenzy_expire,
#endif
#if (TALENT_INNER_RAGE)
    routnum_raging_blow_cd,
#endif
#if (TALENT_DRAGON_ROAR)
    routnum_dragon_roar_cast,
    routnum_dragon_roar_expire,
    routnum_dragon_roar_cd,
#endif
#if (t17_4pc)
    routnum_rampage_expire,
    routnum_rampage_refresh,
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
    aspeed *= 1.0f + 0.06f * rampage_stack;
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
    aspeed *= 1.0f + 0.06f * rampage_stack;
#endif
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / aspeed ) ), routnum_auto_attack_oh, rti->player.target );
}

// === battle cry =============================================================
void spec_spell_battle_cry( rtinfo_t* rti ) {
#if (t17_4pc)
    eq_enqueue( rti, rti->timestamp, routnum_rampage_refresh, 0 );
#endif
}
#if (t17_4pc)
DECL_EVENT( rampage_expire ) {
    lprintf( ( "rampage(t17p4) expire" ) );
    rampage_stack = 0;
    refresh_crit( rti );
}

DECL_EVENT( rampage_refresh ) {
    if ( rampage_stack == 0 ) {
        rampage_expire = TIME_OFFSET( FROM_SECONDS( 14 ) );
        eq_enqueue( rti, rampage_expire, routnum_rampage_expire, target_id );
    }
    rampage_stack++;
    refresh_crit( rti );
    if ( rampage_stack < 10 )
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_rampage_refresh, target_id );
}
#endif

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
    kbool have_crit = 0;
    float d = weapon_dmg( rti, 3.5f, 1, 0 );
    float cr = 0.15f * taste_for_blood_stack;
    if ( TALENT_FRESH_MEAT && enemy_health_percent( rti ) > 80.0f ) cr += 0.3f;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, cr );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    if ( DICE_CRIT == dice ) {
        have_crit = 1;
    }
    power_gain( rti, 10.0f );
    lprintf( ( "bloodthirst hit" ) );
    if ( UP( meat_cleaver_expire ) ){
        k32u c = 0;
        for( int i = 0; c < 4 && i < num_enemies; i++ ) {
            if ( i == target_id ) continue;
            c++;
            d = weapon_dmg( rti, 3.5f, 1, 0 );
            dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, cr );
            deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
            if ( DICE_CRIT == dice ) {
                have_crit = 1;
            }
            power_gain( rti, 3.0f );
        }
        lprintf( ( "bloodthirst multi-hit" ) );
        meat_cleaver_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_meat_cleaver_expire, 0 );
    }
    if ( have_crit ) {
        if ( UP( taste_for_blood_expire ) ) {
            taste_for_blood_expire = rti->timestamp;
            eq_enqueue( rti, rti->timestamp, routnum_taste_for_blood_expire, 0 );
        }
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
    }
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
    if ( MH_TYPE == WEAPON_1H ) d *= 1.15f; // TODO: check if SMF need both weapon to be 1h when go live.
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
#if (TALENT_MASSACRE)
    if ( DICE_CRIT == dice ) // TODO: see if massacre triggers from off-hand execute when go live.
        eq_enqueue( rti, rti->timestamp, routnum_massacre_trigger, 0 );
#endif
    d = weapon_dmg( rti, 5.0f, 1, 1 );
    if ( OH_TYPE == WEAPON_1H ) d *= 1.15f;
    dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    lprintf( ( "execute hit" ) );
}
DECL_SPELL( execute ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, 25.0f ) ) return 0;
    if ( enemy_health_percent( rti ) > 20.0f ) return 0;
    power_consume( rti, 25.0f );
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_execute_cast, rti->player.target );
    lprintf( ( "cast execute" ) );
    return 1;
}

// === furious slash ==========================================================
DECL_EVENT( furious_slash_cast ) {
    float d = weapon_dmg( rti, 2.0f, 1, 1 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, ( t18_2pc ? 0.5f : 0.0f ) );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, ( t18_2pc ? 0.12f : 0.0f ) , 0 );
    eq_enqueue( rti, rti->timestamp, routnum_taste_for_blood_trigger, 0 );
#if (TALENT_FRENZY)
    eq_enqueue( rti, rti->timestamp, routnum_frenzy_trigger, 0 );
#endif
    lprintf( ( "furious_slash hit" ) );
}
DECL_EVENT( taste_for_blood_expire ) {
    if ( taste_for_blood_expire == rti->timestamp ) {
        taste_for_blood_stack = 0;
        lprintf( ( "taste_for_blood expire" ) );
    }
}
DECL_EVENT( taste_for_blood_trigger ) {
    taste_for_blood_expire == TIME_OFFSET( FROM_SECONDS( 8 ) );
    eq_enqueue( rti, taste_for_blood_expire, routnum_taste_for_blood_expire, 0 );
    taste_for_blood_stack = min( 6, taste_for_blood_stack + 1 );
    lprintf( ( "taste_for_blood stack %d", taste_for_blood_stack ) );
}
DECL_SPELL( furious_slash ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_furious_slash_cast, rti->player.target );
    lprintf( ( "cast furious_slash" ) );
    return 1;
}

// === meat cleaver ===========================================================
DECL_EVENT( meat_cleaver_expire ) {
    if ( meat_cleaver_expire == rti->timestamp ) {
        lprintf( ( "meat_cleaver expire" ) );
    }
}
DECL_EVENT( meat_cleaver_trigger ) {
    meat_cleaver_expire == TIME_OFFSET( FROM_SECONDS( 60 ) );
    eq_enqueue( rti, meat_cleaver_expire, routnum_meat_cleaver_expire, 0 );
    lprintf( ( "meat_cleaver trigger" ) );
}

// === raging blow ============================================================
DECL_EVENT( raging_blow_cast ) {
    float d = weapon_dmg( rti, 2.3f * ( TALENT_INNER_RAGE ? 2.0f : 1.0f ), 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    if ( t17_2pc && DICE_CRIT == dice && uni_rng( rti ) < 0.2 ) {
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, target_id );
    }
    d = weapon_dmg( rti, 2.3f * ( TALENT_INNER_RAGE ? 2.0f : 1.0f ), 1, 1 );
    dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    if ( t17_2pc && DICE_CRIT == dice && uni_rng( rti ) < 0.2 ) {
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, target_id );
    }
    power_gain( rti, 5.0f );
    lprintf( ( "raging_blow hit" ) );
}
#if (TALENT_INNER_RAGE)
DECL_EVENT( raging_blow_cd ) {
    lprintf( ( "raging_blow cd" ) );
}
#endif
DECL_SPELL( raging_blow ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( TALENT_INNER_RAGE ) {
        if ( raging_blow_cd > rti->timestamp ) return 0;
    } else {
        if ( !UP( enrage_expire ) ) return 0;
    }
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_raging_blow_cast, rti->player.target );
#if (TALENT_INNER_RAGE)
    raging_blow_cd = TIME_OFFSET( FROM_SECONDS( 4.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, raging_blow_cd, routnum_raging_blow_cd, 0 );
#endif
    lprintf( ( "cast raging_blow" ) );
    return 1;
}

// === rampage ================================================================
DECL_EVENT( rampage_cast_1 ) {
    k32u multihit_signal = 0;
#if (TALENT_MEAT_GRINDER)
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
#endif
    float d = weapon_dmg( rti, 0.6f, 1, 0 ) * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_MILLISECONDS( 200 ) ), routnum_rampage_cast_2, target_id + multihit_signal );
    lprintf( ( "rampage 1st hit" ) );
}
DECL_EVENT( rampage_cast_2 ) {
    k32u multihit_signal = 0;
#if (TALENT_MEAT_GRINDER)
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
#endif
    float d = weapon_dmg( rti, 1.8f, 1, 1 ) * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_MILLISECONDS( 333 ) ), routnum_rampage_cast_3, target_id + multihit_signal );
    lprintf( ( "rampage 2nd hit" ) );
}
DECL_EVENT( rampage_cast_3 ) {
    k32u multihit_signal = 0;
#if (TALENT_MEAT_GRINDER)
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
#endif
    float d = weapon_dmg( rti, 1.2f, 1, 0 ) * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_MILLISECONDS( 667 ) ), routnum_rampage_cast_4, target_id + multihit_signal );
    lprintf( ( "rampage 3rd hit" ) );
}
DECL_EVENT( rampage_cast_4 ) {
    k32u multihit_signal = 0;
#if (TALENT_MEAT_GRINDER)
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
#endif
    float d = weapon_dmg( rti, 3.0f, 1, 1 ) * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    d = weapon_dmg( rti, 1.8f, 1, 0 ) * ( multihit_signal ? 0.5f : 1.0f );
    dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    lprintf( ( "rampage 4/5th hit" ) );
}
DECL_SPELL( rampage ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !UP( massacre_expire ) ){
        if ( !power_check( rti, (TALENT_CARNAGE) ? 65.0f : 85.0f ) ) return 0;
        power_consume( rti, (TALENT_CARNAGE) ? 65.0f : 85.0f );
    }
    gcd_start( rti, FROM_SECONDS( 2.0f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_rampage_cast_1, rti->player.target );
#if (TALENT_MEAT_GRINDER)
    if ( UP( meat_grinder_expire ) ){
        k32u c = 0;
        for( int i = 0; c < 4 && i < num_enemies; i++ ) {
            if ( i == rti->player.target ) continue;
            c++;
            // we need to transfer some extra info to event routine ( here to decrease rampage damage to its half ).
            // dirty hack via manipulating target_id, not elegant, but space efficient.
            eq_enqueue( rti, rti->timestamp, routnum_rampage_cast_1, rti->player.target + num_enemies );
        }
        meat_grinder_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_meat_grinder_expire, 0 );
    }
#endif
    lprintf( ( "cast rampage" ) );
    return 1;
}

// === whirlwind ==============================================================
DECL_EVENT( whirlwind_cast ) {
    float multiplier = 1.0f;
#if (TALENT_WRECKING_BALL)
    if ( UP( wrecking_ball_expire ) ) {
        wrecking_ball_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_wrecking_ball_expire, 0 );
        multiplier *= 3.0f;
    }
#endif
    for( int i = 0; i < num_enemies; i++ ){
        float d = weapon_dmg( rti, 0.48f, 1, 0 ) * multiplier;
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 1 ) * multiplier;
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 0 ) * multiplier;
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 1 ) * multiplier;
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 0 ) * multiplier;
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 1 ) * multiplier;
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        lprintf( ( "whirlwind hit @tar%d", i ) );
    }
    eq_enqueue( rti, rti->timestamp, routnum_meat_cleaver_trigger, 0 );
#if (TALENT_MEAT_GRINDER)
    eq_enqueue( rti, rti->timestamp, routnum_meat_grinder_trigger, 0 );
#endif
}
DECL_SPELL( whirlwind ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !UP( wrecking_ball_expire ) ){
        if ( !power_check( rti, 10.0f ) ) return 0;
        power_consume( rti, 10.0f );
    }
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_whirlwind_cast, rti->player.target );
    lprintf( ( "cast whirlwind" ) );
    return 1;
}

// === wrecking ball ==========================================================
#if (TALENT_WRECKING_BALL)
DECL_EVENT( wrecking_ball_expire ) {
    if ( wrecking_ball_expire == rti->timestamp ) {
        lprintf( ( "wrecking_ball expire" ) );
    }
}
DECL_EVENT( wrecking_ball_trigger ) {
    wrecking_ball_expire == TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, wrecking_ball_expire, routnum_wrecking_ball_expire, 0 );
    lprintf( ( "wrecking_ball trigger" ) );
}
#endif

// === massacre ===============================================================
#if (TALENT_MASSACRE)
DECL_EVENT( massacre_expire ) {
    if ( massacre_expire == rti->timestamp ) {
        lprintf( ( "massacre expire" ) );
    }
}
DECL_EVENT( massacre_trigger ) {
    massacre_expire == TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, massacre_expire, routnum_massacre_expire, 0 );
    lprintf( ( "massacre trigger" ) );
}
#endif

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

// === meat grinder ===========================================================
#if (TALENT_MEAT_GRINDER)
DECL_EVENT( meat_grinder_expire ) {
    if ( meat_grinder_expire == rti->timestamp ) {
        lprintf( ( "meat_grinder expire" ) );
    }
}
DECL_EVENT( meat_grinder_trigger ) {
    meat_grinder_expire == TIME_OFFSET( FROM_SECONDS( 60 ) );
    eq_enqueue( rti, meat_grinder_expire, routnum_meat_grinder_expire, 0 );
    lprintf( ( "meat_grinder trigger" ) );
}
#endif

// === frenzy =================================================================
#if (TALENT_FRENZY)
DECL_EVENT( frenzy_expire ) {
    if ( frenzy_expire == rti->timestamp ) {
        frenzy_stack = 0;
        lprintf( ( "frenzy expire" ) );
    }
}
DECL_EVENT( frenzy_trigger ) {
    frenzy_expire == TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, frenzy_expire, routnum_frenzy_expire, 0 );
    frenzy_stack = min( 3, frenzy_stack + 1 );
    lprintf( ( "frenzy stack %d", frenzy_stack ) );
}
#endif

// === dragon roar ============================================================
#if (TALENT_DRAGON_ROAR)
DECL_EVENT( dragon_roar_cd ) {
    if ( dragon_roar_cd == rti->timestamp ) {
        lprintf( ( "dragon_roar cd" ) );
    }
}
DECL_EVENT( dragon_roar_cast ) {
    float d = ap_dmg( rti, 1.98f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 1 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 1 );
    dragon_roar_expire == TIME_OFFSET( FROM_SECONDS( 6 ) );
    eq_enqueue( rti, dragon_roar_expire, routnum_dragon_roar_expire, 0 );
    lprintf( ( "dragon_roar hit/trigger" ) );
}
DECL_EVENT( dragon_roar_expire ) {
    if ( dragon_roar_expire == rti->timestamp ) {
        lprintf( ( "dragon_roar expire" ) );
    }
}
DECL_SPELL( dragon_roar ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( dragon_roar_cd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_dragon_roar_cast, 0 );
    dragon_roar_cd = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, dragon_roar_cd, routnum_dragon_roar_cd, 0 );
    lprintf( ( "cast dragon_roar" ) );
    return 1;
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
        HOOK_EVENT( furious_slash_cast );
        HOOK_EVENT( taste_for_blood_trigger );
        HOOK_EVENT( taste_for_blood_expire );
        HOOK_EVENT( meat_cleaver_expire );
        HOOK_EVENT( meat_cleaver_trigger );
        HOOK_EVENT( raging_blow_cast );
        HOOK_EVENT( rampage_cast_1 );
        HOOK_EVENT( rampage_cast_2 );
        HOOK_EVENT( rampage_cast_3 );
        HOOK_EVENT( rampage_cast_4 );
        HOOK_EVENT( whirlwind_cast );
#if (TALENT_WRECKING_BALL)
        HOOK_EVENT( wrecking_ball_trigger );
        HOOK_EVENT( wrecking_ball_expire );
#endif
#if (TALENT_MASSACRE)
        HOOK_EVENT( massacre_trigger );
        HOOK_EVENT( massacre_expire );
#endif
#if (TALENT_FROTHING_BERSERKER)
        HOOK_EVENT( frothing_berserker_trigger );
        HOOK_EVENT( frothing_berserker_expire );
#endif
#if (TALENT_MEAT_GRINDER)
        HOOK_EVENT( meat_grinder_trigger );
        HOOK_EVENT( meat_grinder_expire );
#endif
#if (TALENT_FRENZY)
        HOOK_EVENT( frenzy_trigger );
        HOOK_EVENT( frenzy_expire );
#endif
#if (TALENT_INNER_RAGE)
        HOOK_EVENT( raging_blow_cd );
#endif
#if (TALENT_DRAGON_ROAR)
        HOOK_EVENT( dragon_roar_cast );
        HOOK_EVENT( dragon_roar_expire );
        HOOK_EVENT( dragon_roar_cd );
#endif
#if (t17_4pc)
        HOOK_EVENT( rampage_expire );
        HOOK_EVENT( rampage_refresh );
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
#if (TALENT_WRECKING_BALL)
    initialize_rppm( rti->player.class->spec->wrecking_ball.proc );
#endif
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    if ( DICE_MISS != dice && ( ATYPE_WHITE_MELEE == attacktype || ATYPE_YELLOW_MELEE == attacktype ) ) {
#if (TALENT_WRECKING_BALL)
        proc_RPPM( rti, &rti->player.class->spec->wrecking_ball.proc, 5.0f * ( 1.0f + rti->player.stat.haste ), routnum_wrecking_ball_trigger, target_id );
#endif
    }
#if defined(trinket_worldbreakers_resolve)
    if ( ATYPE_WHITE_MELEE == attacktype ){
        eq_enqueue( rti, rti->timestamp, routnum_worldbreakers_resolve_trigger, target_id );
    }
#endif
}
