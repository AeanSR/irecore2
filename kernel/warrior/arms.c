/**
    IreCore kernel - Arms Specialization

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
struct spec_state_t {
    struct {
        time_t cd;
        time_t expire;
        k32u stack;
    } cleave;
#define cleave_cd     (rti->player.spec->cleave.cd)
#define cleave_expire (rti->player.spec->cleave.expire)
#define cleave_stack  (rti->player.spec->cleave.stack)
    struct {
        time_t cd;
    } colossus_smash;
#define colossus_smash_cd (rti->player.spec->colossus_smash.cd)
    struct {
        time_t cd;
    } hamstring;
#define hamstring_cd (rti->player.spec->hamstring.cd)
    struct {
        time_t cd;
        k32u charge;
    } mortal_strike;
#define mortal_strike_cd     (rti->player.spec->mortal_strike.cd)
#define mortal_strike_charge (rti->player.spec->mortal_strike.charge)
#define mortal_strike_maxcharge (TALENT_MORTAL_COMBO ? 2 : 1)
#if (TALENT_OVERPOWER)
    struct {
        time_t expire;
        RPPM_t proc;
    } overpower;
#define overpower_expire (rti->player.spec->overpower.expire)
#else
#define overpower_expire (0)
#endif
#if (TALENT_FOCUSED_RAGE)
    struct {
        time_t cd;
        k32u stack;
    } focused_rage;
#define focused_rage_cd    (rti->player.spec->focused_rage.cd)
#define focused_rage_stack (rti->player.spec->focused_rage.stack)
#else
#define focused_rage_cd    (0)
#define focused_rage_stack (0)
#endif
#if (TALENT_RAVAGER)
    struct {
        time_t cd;
        time_t expire;
    } ravager;
#define ravager_cd     (rti->player.spec->ravager.cd)
#define ravager_expire (rti->player.spec->ravager.expire)
#else
#define ravager_cd     (0)
#define ravager_expire (0)
#endif
};
struct spec_debuff_t {
    struct {
        time_t expire;
        float increament;
    } colossus_smash;
#define colossus_smash_expire(target) (rti->enemy[target].spec->colossus_smash.expire)
#if (TALENT_REND)
    struct {
        time_t expire;
        time_t last_tick;
    } rend;
#define rend_expire(target) (rti->enemy[target].spec->rend.expire)
#else
#define rend_expire(target) (0)
#endif
#if (TALENT_TRAUMA)
    struct {
        time_t dot_start;
        float pool;
        float ticks;
    } trauma;
#endif
};

float spec_str_coefficient( rtinfo_t* rti ) {
    return 1.0f;
}

float spec_mastery_coefficient( rtinfo_t* rti ) {
    return 2.0f;
}

float spec_mastery_increament( rtinfo_t* rti ) {
    return 0.0f;
}

float spec_crit_increament( rtinfo_t* rti ) {
    return 0.0f;
}

float spec_haste_coefficient( rtinfo_t* rti ) {
    return 1.0f;
}

float spec_haste_increament( rtinfo_t* rti ) {
    return 0.0f;
}

k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate;
    if ( ATYPE_WHITE_MELEE == attacktype ) {

    }
    if ( ATYPE_YELLOW_MELEE == attacktype ) {
        if ( UP( battle_cry_expire ) ) cr += 1.0f;
    }
    if ( c < cr ) {
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
    if ( DTYPE_DIRECT == dmgtype ) {
        lprintf( ( "damage %.0f", dmg ) );
        rti->damage_collected += dmg;
        return dmg;
    }
    float cdb = ( 1.0f + extra_crit_bonus ) * 2.0f;
    dmg *= 1.0f + rti->player.stat.vers;
    if ( UP( colossus_smash_expire( target_id ) ) )             dmg *= rti->enemy[target_id].spec->colossus_smash.increament;
    if ( UP( avatar_expire ) )                                  dmg *= 1.2f;
    if ( UP( thorasus_the_stone_heart_of_draenor_expire ) )     dmg *= 1.0f + legendary_ring * 0.0001f;
    if ( ENEMY_IS_DEMONIC && UP( gronntooth_war_horn_expire ) ) dmg *= 1.1f;
    if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )            cdb *= 1.02f;
    if ( DTYPE_PHYSICAL == dmgtype ) {
        if ( !ignore_armor )                                        dmg *= 0.594043f; // 0.680228f @110lvl
    }
    if ( DICE_CRIT == dice )                                    dmg *= cdb;
    if ( DICE_CRIT   == dice ) {
        lprintf( ( "damage *%.0f*", dmg ) );
    } else {
        lprintf( ( "damage %.0f", dmg ) );
    }
    rti->damage_collected += dmg;
    return dmg;
}

float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand ) {
    float dmg = ( float )MH_LOW;
    dmg += uni_rng( rti ) * ( MH_HIGH - MH_LOW );
    dmg += ( normalized ? normalized_weapon_speed[MH_TYPE] : MH_SPEED ) * rti->player.stat.ap / 3.5f;
    dmg *= weapon_multiplier;
    if ( MH_TYPE == WEAPON_2H ) dmg *= 1.1f;
    return dmg;
}

float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap;
    if ( MH_TYPE == WEAPON_2H ) dmg *= 1.1f;
    return dmg;
}

float spec_power_gain( rtinfo_t* rti, float power ) {
    /* do nothing */
}

/* Power check with dauntless. */
float spec_power_check( rtinfo_t* rti, float cost ) {
    if ( TALENT_DAUNTLESS ) cost *= 0.8f;
    if ( TALENT_DEADLY_CALM && UP( battle_cry_expire ) ) cost *= 0.0f;
    return ( float )( int )( cost );
}

/* Power consume with dauntless. */
#if (TALENT_ANGER_MANAGEMENT)
void anger_management_count( rtinfo_t* rti, float rage );
#endif
void trigger_tactician( rtinfo_t* rti );
float spec_power_consume( rtinfo_t* rti, float cost ) {
    if ( uni_rng( rti ) < 0.0065f * cost ) {
        trigger_tactician( rti );
    }
    if ( TALENT_DAUNTLESS ) cost *= 0.8f;
    if ( TALENT_DEADLY_CALM && UP( battle_cry_expire ) ) cost *= 0.0f;
    cost = ( float )( int )( cost );
#if (TALENT_ANGER_MANAGEMENT)
    anger_management_count( rti, cost );
#endif
    return cost;
}

/* event list. */
enum {
    END_OF_CLASS_ROUTNUM = START_OF_SPEC_ROUTNUM - 1,
    routnum_auto_attack,
    routnum_cleave_expire,
    routnum_cleave_cd,
    routnum_cleave_cast,
    routnum_colossus_smash_cd,
    routnum_colossus_smash_expire,
    routnum_colossus_smash_trigger,
    routnum_colossus_smash_cast,
    routnum_execute_cast,
    routnum_hamstring_cast,
    routnum_hamstring_cd,
    routnum_mortal_strike_charge,
    routnum_mortal_strike_cast,
    routnum_slam_cast,
    routnum_tactician_trigger,
    routnum_whirlwind_cast,
#if (TALENT_OVERPOWER)
    routnum_overpower_trigger,
    routnum_overpower_expire,
    routnum_overpower_cast,
#endif
#if (TALENT_REND)
    routnum_rend_tick,
    routnum_rend_cast,
#endif
#if (TALENT_FOCUSED_RAGE)
    routnum_focused_rage_cd,
#endif
#if (TALENT_TRAUMA)
    routnum_trauma_tick,
#endif
#if (TALENT_OPPORTUNITY_STRIKES)
    routnum_opportunity_strikes_trigger,
#endif
#if (TALENT_RAVAGER)
    routnum_ravager_tick,
    routnum_ravager_cast,
    routnum_ravager_cd,
#endif
    START_OF_WILD_ROUTNUM,
};

void trigger_opportunity_strikes( rtinfo_t* rti, k32u target_id );
void trigger_trauma( rtinfo_t* rti, float dmg, k32u target_id );

// === auto-attack ============================================================
DECL_EVENT( auto_attack ) {
    float d = weapon_dmg( rti, 1.0f, 0, 0 );
    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 );
    float r = 5.95f * MH_SPEED;
    if ( dice == DICE_CRIT ) r *= 2.25f;
    power_gain( rti, r );
    lprintf( ( "mh hit" ) );

#if defined(trinket_worldbreakers_resolve)
    if ( UP( colossus_smash_cd ) && uni_rng( rti ) < trinket_worldbreakers_resolve * 0.0001f ) {
        colossus_smash_cd = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_colossus_smash_cd, 0 );
    }
#endif

    float aspeed = 1.0f + rti->player.stat.haste;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( MH_SPEED / aspeed ) ), routnum_auto_attack, rti->player.target );
}

// === battle cry =============================================================
void spec_spell_battle_cry( rtinfo_t* rti ) {

}

// === berserker rage =========================================================
void spec_berserker_rage_cast( rtinfo_t* rti ) {

}

// === cleave =================================================================
DECL_EVENT( cleave_cd ) {
    if ( cleave_cd == rti->timestamp ) {
        lprintf( ( "cleave cd" ) );
    }
}
DECL_EVENT( cleave_expire ) {
    if ( cleave_expire == rti->timestamp ) {
        cleave_stack = 0;
        lprintf( ( "cleave expire" ) );
    }
}
DECL_EVENT( cleave_cast ) {
    k32u c = 0;
    cleave_expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    cleave_stack = 1;
    eq_enqueue( rti, cleave_expire, routnum_cleave_expire, 0 );
    float d = weapon_dmg( rti, 0.9f, 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_opportunity_strikes( rti, target_id );
    for( int i = 0; c < 5 && i < num_enemies; i++ ) {
        if ( i == target_id ) continue;
        d = weapon_dmg( rti, 0.9f, 1, 0 );
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        trigger_opportunity_strikes( rti, i );
        cleave_stack ++;
        lprintf( ( "cleave hit @tar%d", i ) );
    }
    lprintf( ( "cleave stack %d", cleave_stack ) );
}
DECL_SPELL( cleave ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( cleave_cd > rti->timestamp ) return 0;
    if ( !power_check( rti, 10.0f ) ) return 0;
    power_consume( rti, 10.0f );
    cleave_cd = TIME_OFFSET( FROM_SECONDS( 6 ) );
    eq_enqueue( rti, cleave_cd, routnum_cleave_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_cleave_cast, rti->player.target );
    lprintf( ( "cast cleave" ) );
    return 1;
}

// === colossus smash =========================================================
DECL_EVENT( colossus_smash_cd ) {
    if ( colossus_smash_cd == rti->timestamp ) {
        lprintf( ( "colossus_smash cd" ) );
    }
}
DECL_EVENT( colossus_smash_expire ) {
    if ( colossus_smash_expire( target_id ) == rti->timestamp ) {
        rti->enemy[target_id].spec->colossus_smash.increament = 1.0f;
        lprintf( ( "colossus_smash expire @tar%d", target_id ) );
    }
}
DECL_EVENT( colossus_smash_trigger ) {
    colossus_smash_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 8.0f + ( TALENT_TITANIC_MIGHT ? 16.0f : 0.0f ) ) );
    rti->enemy[target_id].spec->colossus_smash.increament = 1.0f + ( 0.15f + rti->player.stat.mastery ) * ( TALENT_TITANIC_MIGHT ? 0.8f : 1.0f );
    lprintf( ( "colossus_smash start @tar%d", target_id ) );
}
DECL_EVENT( colossus_smash_cast ) {
    float d = weapon_dmg( rti, 2.02f * ( 1.0f + rti->player.stat.mastery ), 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_colossus_smash_trigger, target_id );
    trigger_opportunity_strikes( rti, target_id );
    lprintf( ( "colossus_smash hit" ) );
}
DECL_SPELL( colossus_smash ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( colossus_smash_cd > rti->timestamp ) return 0;
    colossus_smash_cd = TIME_OFFSET( FROM_SECONDS( 45 ) );
    eq_enqueue( rti, colossus_smash_cd, routnum_colossus_smash_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_colossus_smash_cast, rti->player.target );
    lprintf( ( "cast colossus_smash" ) );
    return 1;
}

// === execute ================================================================
float execute_extra_rage_cost( rtinfo_t* rti ) {
    float r = 30.0f;
    if ( TALENT_DAUNTLESS ) r *= 0.8f;
    if ( TALENT_DEADLY_CALM && UP( battle_cry_expire ) ) r *= 0.0f;
    return ( float )( ( int )r );
}
DECL_EVENT( execute_cast ) {
    float r = min( rti->player.power, execute_extra_rage_cost( rti ) );
    if ( TALENT_DAUNTLESS ) r /= 0.8f;
    if ( TALENT_DEADLY_CALM && UP( battle_cry_expire ) ) r = 30.0f;
    float multiplier = 1.0f + r / 10.0f;
    power_consume( rti, r );
    float d = weapon_dmg( rti, 1.62f, 1, 0 ) * multiplier;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_opportunity_strikes( rti, target_id );
    lprintf( ( "execute hit" ) );
    if ( TALENT_SWEEPING_STRIKES ) {
        for ( int i = 0; i < num_enemies; i++ ) {
            if ( i == target_id ) continue;
            d = weapon_dmg( rti, 1.62f, 1, 0 ) * multiplier;
            dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
            deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
            lprintf( ( "execute sweepstrike" ) );
            break;
        }
        // sweepstrike execute wont proc opportunity strikes, while sweepstrike mortal strike will.
    }
}
DECL_SPELL( execute ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( enemy_health_percent( rti ) > 20.0f ) return 0;
    if ( !power_check( rti, 10.0f ) ) return 0;
    power_consume( rti, 10.0f );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_execute_cast, rti->player.target );
    lprintf( ( "cast execute" ) );
    return 1;
}

// === hamstring ==============================================================
DECL_EVENT( hamstring_cd ) {
    lprintf( ( "hamstring cd" ) );
}
DECL_EVENT( hamstring_cast ) {
    float d = weapon_dmg( rti, 0.05f, 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_opportunity_strikes( rti, target_id );
    lprintf( ( "hamstring hit" ) );
}
DECL_SPELL( hamstring ) {
    if ( hamstring_cd > rti->timestamp ) return 0;
    if ( !power_check( rti, 10.0f ) ) return 0;
    power_consume( rti, 10.0f );
    hamstring_cd = TIME_OFFSET( FROM_SECONDS( 1 ) );
    eq_enqueue( rti, hamstring_cd, routnum_hamstring_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_hamstring_cast, rti->player.target );
    lprintf( ( "cast hamstring" ) );
    return 1;
}

// === mortal strike ==========================================================
DECL_EVENT( mortal_strike_charge ) {
    if ( mortal_strike_cd == rti->timestamp && mortal_strike_charge < mortal_strike_maxcharge ) {
        mortal_strike_charge ++;
        lprintf( ( "mortal_strike charge %d", mortal_strike_charge ) );
        if ( mortal_strike_charge < mortal_strike_maxcharge ) {
            mortal_strike_cd = TIME_OFFSET( FROM_SECONDS( 6.0f / ( 1.0f + rti->player.stat.haste ) ) );
            eq_enqueue( rti, mortal_strike_cd, routnum_mortal_strike_charge, 0 );
        }
    }
}
DECL_EVENT( mortal_strike_cast ) {
    float multiplier = 1.0f + 0.5f * focused_rage_stack;
#if (TALENT_FOCUSED_RAGE)
    focused_rage_stack = 0;
#endif
    float d = weapon_dmg( rti, 3.27f, 1, 0 ) * multiplier;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_opportunity_strikes( rti, target_id );
    lprintf( ( "mortal_strike hit" ) );
    if ( TALENT_SWEEPING_STRIKES ) {
        for ( int i = 0; i < num_enemies; i++ ) {
            if ( i == target_id ) continue;
            d = weapon_dmg( rti, 3.27f, 1, 0 ) * multiplier;
            dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
            deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
            trigger_opportunity_strikes( rti, i );
            lprintf( ( "mortal_strike sweepstrike" ) );
            break;
        }
    }
}
DECL_SPELL( mortal_strike ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( mortal_strike_charge == 0 ) return 0;
    if ( !power_check( rti, 20.0f ) ) return 0;
    power_consume( rti, 20.0f );
    if ( TALENT_IN_FOR_THE_KILL && enemy_health_percent( rti ) <= 20.0f ) {
        power_gain( rti, 20.0f );
    }
    mortal_strike_charge --;
    if ( !UP( mortal_strike_cd ) ) {
        mortal_strike_cd = TIME_OFFSET( FROM_SECONDS( 6.0f / ( 1.0f + rti->player.stat.haste ) ) );
        eq_enqueue( rti, mortal_strike_cd, routnum_mortal_strike_charge, 0 );
    }
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_mortal_strike_cast, rti->player.target );
    lprintf( ( "cast mortal_strike" ) );
    return 1;
}

// === slam ===================================================================
DECL_EVENT( slam_cast ) {
    float d = weapon_dmg( rti, 1.7f, 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_opportunity_strikes( rti, target_id );
    trigger_trauma( rti, final_dmg, target_id );
#if (t18_2pc)
    if ( uni_rng( rti ) < 0.3f ) {
        mortal_strike_charge = min( ( int )mortal_strike_maxcharge, ( int )mortal_strike_charge + 1 );
        if ( mortal_strike_charge == mortal_strike_maxcharge ) mortal_strike_cd = rti->timestamp;
    }
#endif
    lprintf( ( "slam hit" ) );
}
DECL_SPELL( slam ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, ( t18_4pc ? 10.0f : 15.0f ) ) ) return 0;
    power_consume( rti, ( t18_4pc ? 10.0f : 15.0f ) );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_slam_cast, rti->player.target );
    lprintf( ( "cast slam" ) );
    return 1;
}

// === tactician ==============================================================
DECL_EVENT( tactician_trigger ) {
    mortal_strike_charge = min( ( int )mortal_strike_maxcharge, ( int )mortal_strike_charge + 1 );
    if ( mortal_strike_charge == mortal_strike_maxcharge ) mortal_strike_cd = rti->timestamp;
    if ( UP( colossus_smash_cd ) ) {
        colossus_smash_cd = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_colossus_smash_cd, 0 );
    }
}
void trigger_tactician( rtinfo_t* rti ) {
    eq_enqueue( rti, rti->timestamp, routnum_tactician_trigger, 0 );
}

// === whirlwind ==============================================================
DECL_EVENT( whirlwind_cast ) {
    float multiplier = 1.0f;
    if ( UP( cleave_expire ) ) {
        cleave_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_cleave_expire, 0 );
        multiplier += 0.2f * cleave_stack;
    }
    for( int i = 0; i < num_enemies; i++ ) {
        float final_dmg = 0.0f;
        float d = weapon_dmg( rti, 0.72f, 1, 0 ) * multiplier * ( TALENT_FERVOR_OF_BATTLE && i == target_id ? 1.5f : 1.0f );
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.72f, 1, 0 ) * multiplier * ( TALENT_FERVOR_OF_BATTLE && i == target_id ? 1.5f : 1.0f );
        dice = round_table_dice2( rti, i, ATYPE_YELLOW_MELEE, 0 ); // dice without procs.
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.72f, 1, 0 ) * multiplier * ( TALENT_FERVOR_OF_BATTLE && i == target_id ? 1.5f : 1.0f );
        dice = round_table_dice2( rti, i, ATYPE_YELLOW_MELEE, 0 ); // dice without procs.
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        lprintf( ( "whirlwind hit @tar%d", i ) );
        trigger_trauma( rti, final_dmg, i );
        trigger_opportunity_strikes( rti, i );
    }
}
DECL_SPELL( whirlwind ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, 25.0f ) ) return 0;
    power_consume( rti, 25.0f );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_whirlwind_cast, rti->player.target );
    lprintf( ( "cast whirlwind" ) );
    return 1;
}

// === overpower ==============================================================
#if (TALENT_OVERPOWER)
DECL_EVENT( overpower_expire ) {
    if ( overpower_expire == rti->timestamp ) {
        lprintf( ( "overpower expire" ) );
    }
}
DECL_EVENT( overpower_trigger ) {
    overpower_expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    eq_enqueue( rti, overpower_expire, routnum_overpower_expire, 0 );
    lprintf( ( "overpower trigger" ) );
}
DECL_EVENT( overpower_cast ) {
    float d = weapon_dmg( rti, 3.75f, 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0.6f );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_opportunity_strikes( rti, target_id );
    lprintf( ( "overpower hit" ) );
}
DECL_SPELL( overpower ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !UP( overpower_expire ) ) return 0;
    if ( !power_check( rti, 10.0f ) ) return 0;
    power_consume( rti, 10.0f );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_overpower_cast, rti->player.target );
    overpower_expire = rti->timestamp;
    eq_enqueue( rti, rti->timestamp, routnum_overpower_expire, 0 );
    lprintf( ( "cast overpower" ) );
    return 1;
}
#else
DECL_SPELL( overpower ) {
    return 0;
}
#endif

// === rend ===================================================================
#if (TALENT_REND)
DECL_EVENT( rend_tick ) {
    float mult = TO_SECONDS( rti->timestamp - rti->enemy[target_id].spec->rend.last_tick ) / 3.0f;
    mult = min( 1.0f, mult );
    if ( mult < 1.0f && rend_expire( target_id ) > rti->timestamp ) {
        eq_enqueue( rti, rti->enemy[target_id].spec->rend.last_tick + FROM_SECONDS( 3 ), routnum_rend_tick, target_id );
        return; // last tick canceled if extended.
    }
    if ( rend_expire( target_id ) < rti->timestamp ) return; // last tick evaluates as equal.
    float d = ap_dmg( rti, 1.08f );
    d *= mult;
    if ( d <= 0.0f ) return;
    k32u dice = round_table_dice2( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    rti->enemy[target_id].spec->rend.last_tick = rti->timestamp;
    lprintf( ( "rend tick" ) );
    if ( TIME_DISTANT( rend_expire( target_id ) ) >= FROM_SECONDS( 3 ) ) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 3 ) ), routnum_rend_tick, target_id );
    } else if ( UP( rend_expire( target_id ) ) ) {
        eq_enqueue( rti, rend_expire( target_id ), routnum_rend_tick, target_id );
    }
}
DECL_EVENT( rend_cast ) {
    if ( UP( rend_expire( target_id ) ) ) {
        rend_expire( target_id ) = TIME_OFFSET( min( ( k32u )( FROM_SECONDS( 15 ) + TIME_DISTANT( rend_expire( target_id ) ) ), ( k32u )FROM_SECONDS( 19.5 ) ) );
        lprintf( ( "rend_expire extends to %f sec", TO_SECONDS( TIME_DISTANT( rend_expire( target_id ) ) ) ) );
    } else {
        rend_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 15 ) );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 3 ) ), routnum_rend_tick, target_id );
        lprintf( ( "rend start" ) );
    }
    trigger_opportunity_strikes( rti, target_id ); // rend will proc opportunity strikes on apply, but wont on ticks.
}
DECL_SPELL( rend ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, 15.0f ) ) return 0;
    power_consume( rti, 15.0f );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_rend_cast, rti->player.target );
    lprintf( ( "cast rend" ) );
    return 1;
}
#else
DECL_SPELL( rend ) {
    return 0;
}
#endif

// === bladestorm =============================================================
#if (TALENT_BLADESTORM)
void spec_bladestorm_tick( rtinfo_t* rti ) {
    for( int i = 0; i < num_enemies; i++ ) {
        float d = weapon_dmg( rti, 1.45f, 1, 0 );
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        trigger_opportunity_strikes( rti, i );
        lprintf( ( "bladestorm tick @tar%d", i ) );
    }
}
#endif

// === focused rage ===========================================================
#if (TALENT_FOCUSED_RAGE)
DECL_EVENT( focused_rage_cd ) {
    lprintf( ( "focused_rage cd" ) );
}
DECL_SPELL( focused_rage ) {
    if ( focused_rage_cd > rti->timestamp ) return 0;
    if ( !power_check( rti, 15.0f ) ) return 0;
    power_consume( rti, 15.0f );
    focused_rage_cd = TIME_OFFSET( FROM_SECONDS( 1.5f ) );
    eq_enqueue( rti, focused_rage_cd, routnum_focused_rage_cd, 0 );
    focused_rage_stack = min( 3, ( int )focused_rage_stack + 1 );
    lprintf( ( "cast focused_rage stack %d", focused_rage_stack ) );
    return 1;
}
#else
DECL_SPELL( focused_rage ) {
    return 0;
}
#endif

// === trauma =================================================================
#if (TALENT_TRAUMA)
DECL_EVENT( trauma_tick ) {
    if ( rti->enemy[target_id].spec->trauma.ticks < 1.0f ) return;
    if ( rti->enemy[target_id].spec->trauma.dot_start + FROM_SECONDS( 8.0f - 2.0f * rti->enemy[target_id].spec->trauma.ticks ) != rti->timestamp ) return;
    float dmg = rti->enemy[target_id].spec->trauma.pool / rti->enemy[target_id].spec->trauma.ticks;
    rti->enemy[target_id].spec->trauma.pool -= dmg;
    deal_damage( rti, target_id, dmg, DTYPE_DIRECT, DICE_HIT, 0, 0 );
    lprintf( ( "trauma ticks" ) );
    rti->enemy[target_id].spec->trauma.ticks -= 1.0f;
    if ( rti->enemy[target_id].spec->trauma.ticks >= 1.0f )
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 2 ) ), routnum_trauma_tick, target_id );
}
#endif
void trigger_trauma( rtinfo_t* rti, float dmg, k32u target_id ) {
#if (TALENT_TRAUMA)
    rti->enemy[target_id].spec->trauma.pool += dmg * 0.2f;
    if ( rti->enemy[target_id].spec->trauma.ticks < 1.0f ) {
        rti->enemy[target_id].spec->trauma.dot_start = rti->timestamp;
        rti->enemy[target_id].spec->trauma.ticks = 3.0f;
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 2 ) ), routnum_trauma_tick, target_id );
        lprintf( ( "trauma apply @tar%d", target_id ) );
    } else {
        float new_ticks = 3.0f - rti->enemy[target_id].spec->trauma.ticks;
        rti->enemy[target_id].spec->trauma.ticks = 3.0f;
        rti->enemy[target_id].spec->trauma.dot_start += FROM_SECONDS( new_ticks * 2 );
        lprintf( ( "trauma @tar%d extends", target_id ) );
    }
#endif
}

// === anger management =======================================================
#if (TALENT_ANGER_MANAGEMENT)
void anger_management_count( rtinfo_t* rti, float rage ) {
    time_t cdr = FROM_SECONDS( max( rage, 0.0f ) * 0.1f );
    cdr = min( ( int )battle_cry_cd, ( int )cdr );
    battle_cry_cd -= cdr;
}
#endif

// === opportunity strikes ====================================================
#if (TALENT_OPPORTUNITY_STRIKES)
DECL_EVENT( opportunity_strikes_trigger ) {
    float d = weapon_dmg( rti, 1.6f, 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    lprintf( ( "opportunity_strikes hit" ) );
}
#endif
void trigger_opportunity_strikes( rtinfo_t* rti, k32u target_id ) {
#if (TALENT_OPPORTUNITY_STRIKES)
    if ( uni_rng( rti ) < mix( 0.6f, 0.0f, enemy_health_percent( rti ) * 0.01f ) ) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1.0f ) ), routnum_opportunity_strikes_trigger, target_id );
    }
#endif
}


// === ravager ================================================================
#if (TALENT_RAVAGER)
DECL_EVENT( ravager_cd ) {
    if ( ravager_expire == rti->timestamp ) {
        lprintf( ( "ravager cd" ) );
    }
}
DECL_EVENT( ravager_tick ) {
    for( int i = 0; i < num_enemies; i++ ) {
        float d = ap_dmg( rti, 2.5f );
        k32u dice = round_table_dice2( rti, i, ATYPE_YELLOW_MELEE, 0 ); // dice without procs. TODO: does ravager procs?
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        lprintf( ( "ravager tick" ) );
    }
    if ( REMAIN( ravager_expire ) > FROM_SECONDS( 0.5f ) ) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_ravager_tick, 0 );
    } else {
        lprintf( ( "ravager expire" ) );
    }
}
DECL_EVENT( ravager_cast ) {
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_ravager_tick, 0 );
    lprintf( ( "ravager cast" ) );
}
DECL_SPELL( ravager ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( ravager_cd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_ravager_cast, 0 );
    ravager_cd = TIME_OFFSET( FROM_SECONDS( 60 ) );
    ravager_expire = TIME_OFFSET( FROM_SECONDS( 7 ) );
    eq_enqueue( rti, ravager_cd, routnum_ravager_cd, 0 );
    lprintf( ( "cast ravager" ) );
    return 1;
}
#else
DECL_SPELL( ravager ) {
    return 0;
}
#endif


void spec_routine_entries( rtinfo_t* rti, _event_t e ) {
    switch( e.routine ) {
        HOOK_EVENT( auto_attack );
        HOOK_EVENT( cleave_expire );
        HOOK_EVENT( cleave_cd );
        HOOK_EVENT( cleave_cast );
        HOOK_EVENT( colossus_smash_cd );
        HOOK_EVENT( colossus_smash_expire );
        HOOK_EVENT( colossus_smash_trigger );
        HOOK_EVENT( colossus_smash_cast );
        HOOK_EVENT( execute_cast );
        HOOK_EVENT( hamstring_cast );
        HOOK_EVENT( hamstring_cd );
        HOOK_EVENT( mortal_strike_charge );
        HOOK_EVENT( mortal_strike_cast );
        HOOK_EVENT( tactician_trigger );
        HOOK_EVENT( slam_cast );
        HOOK_EVENT( whirlwind_cast );
#if (TALENT_OVERPOWER)
        HOOK_EVENT( overpower_trigger );
        HOOK_EVENT( overpower_expire );
        HOOK_EVENT( overpower_cast );
#endif
#if (TALENT_REND)
        HOOK_EVENT( rend_tick );
        HOOK_EVENT( rend_cast );
#endif
#if (TALENT_FOCUSED_RAGE)
        HOOK_EVENT( focused_rage_cd );
#endif
#if (TALENT_TRAUMA)
        HOOK_EVENT( trauma_tick );
#endif
#if (TALENT_OPPORTUNITY_STRIKES)
        HOOK_EVENT( opportunity_strikes_trigger );
#endif
#if (TALENT_RAVAGER)
        HOOK_EVENT( ravager_tick );
        HOOK_EVENT( ravager_cast );
        HOOK_EVENT( ravager_cd );
#endif
    default:
        lprintf( ( "wild spec routine entry %d, last defined routnum %d", e.routine, START_OF_WILD_ROUTNUM - 1 ) );
        assert( 0 );
    }
}

void spec_module_init( rtinfo_t* rti ) {
    power_gain( rti, 15.0f ); // charge!
    mortal_strike_charge = mortal_strike_maxcharge;
    eq_enqueue( rti, rti->timestamp, routnum_auto_attack, 0 );
#if (TALENT_OVERPOWER)
    initialize_rppm( rti->player.spec->overpower.proc );
#endif
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    if ( DICE_MISS != dice && ( ATYPE_WHITE_MELEE == attacktype || ATYPE_YELLOW_MELEE == attacktype ) ) {
#if (TALENT_OVERPOWER)
        proc_RPPM( rti, &rti->player.spec->overpower.proc, 5.0f * ( 1.0f + rti->player.stat.haste ), routnum_overpower_trigger, target_id );
#endif
    }
}
