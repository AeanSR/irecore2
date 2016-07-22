/**
    IreCore kernel - Retribution Specialization

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
    } judgment;
#define judgment_cd     (rti->player.spec->judgment.cd)
    struct {
        time_t cd;
        k32u charge;
    } crusader_strike;
#define crusader_strike_cd        (rti->player.spec->crusader_strike.cd)
#define crusader_strike_charge    (rti->player.spec->crusader_strike.charge)
#define crusader_strike_maxcharge (2)
    struct {
        time_t cd;
        time_t expire;
    } avenging_wrath;
#define avenging_wrath_cd     (rti->player.spec->avenging_wrath.cd)
#define avenging_wrath_expire (rti->player.spec->avenging_wrath.expire)
    struct {
        time_t cd;
    } blade_of_justice;
#define blade_of_justice_cd     (rti->player.spec->blade_of_justice.cd)
#if (TALENT_EXECUTION_SENTENCE)
    struct {
        time_t cd;
    } execution_sentence;
#define execution_sentence_cd (rti->player.spec->execution_sentence.cd)
#else
#define execution_sentence_cd (0)
#endif
#if (TALENT_CONSECRATION)
    struct {
        time_t tick_period;
        time_t expire;
        time_t cd;
    } consecration;
#define consecration_expire (rti->player.spec->consecration.expire)
#define consecration_cd     (rti->player.spec->consecration.cd)
#else
#define consecration_expire (0)
#define consecration_cd     (0)
#endif
#if (TALENT_THE_FIRES_OF_JUSTICE)
    struct {
        time_t expire;
    } the_fires_of_justice;
#define the_fires_of_justice_expire (rti->player.spec->the_fires_of_justice.expire)
#else
#define the_fires_of_justice_expire (0)
#endif
#if (TALENT_ZEAL)
    struct {
        time_t expire;
        k32u stack;
    } zeal;
#define zeal_expire     (rti->player.spec->zeal.expire)
#define zeal_stack      (rti->player.spec->zeal.stack)
#else
#define zeal_expire     (0)
#define zeal_stack      (0)
#endif
#define zeal_cd         (crusader_strike_cd)
#define zeal_charge     (crusader_strike_charge)
#define zeal_maxcharge  (crusader_strike_maxcharge)
#define blade_of_wrath_cd (blade_of_justice_cd)
#if (TALENT_DIVINE_HAMMER)
    struct {
        time_t expire;
        time_t tick_period;
    } divine_hammer;
#define divine_hammer_expire (rti->player.spec->divine_hammer.expire)
#else
#define divine_hammer_expire (0)
#endif
#define divine_hammer_cd (blade_of_justice_cd)
#if (TALENT_DIVINE_PURPOSE)
    struct {
        time_t expire;
    } divine_purpose;
#define divine_purpose_expire (rti->player.spec->divine_purpose.expire)
#else
#define divine_purpose_expire (0)
#endif
#if (TALENT_CRUSADE)
    struct {
        k32u stack;
    } crusade;
#define crusade_stack  (rti->player.spec->crusade.stack)
#else
#define crusade_stack  (0)
#endif
#define crusade_expire (avenging_wrath_expire)
#define crusade_cd     (avenging_wrath_cd)
#if defined(trinket_libram_of_vindication)
    struct {
        time_t expire;
        k32u   stack;
        k32u   target;
    } libram_of_vindication;
#define libram_of_vindication_stack  (rti->player.spec->libram_of_vindication.stack)
#define libram_of_vindication_expire (rti->player.spec->libram_of_vindication.expire)
#else
#define libram_of_vindication_stack  (0)
#define libram_of_vindication_expire (0)
#endif
};

struct spec_debuff_t {
    struct {
        time_t expire;
    } judgment;
#define judgment_expire(target) (rti->enemy[target].spec->judgment.expire)
#if (TALENT_EXECUTION_SENTENCE)
    struct {
        time_t expire;
    } execution_sentence;
#define execution_sentence_expire(target) (rti->enemy[target].spec->execution_sentence.expire)
#else
#define execution_sentence_expire(target) (0)
#endif
#if (TALENT_BLADE_OF_WRATH)
    struct {
        time_t expire;
    } blade_of_wrath;
#define blade_of_wrath_expire(target) (rti->enemy[target].spec->blade_of_wrath.expire)
#else
#define blade_of_wrath_expire(target) (0)
#endif

};

float spec_str_coefficient( rtinfo_t* rti ){
    return 1.0f;
}

float spec_mastery_coefficient( rtinfo_t* rti ) {
    return 3.0f;
}

float spec_mastery_increament( rtinfo_t* rti ) {
    return 0.0f;
}

float spec_crit_increament( rtinfo_t* rti ) {
    return 0.0f;
}

float spec_haste_coefficient( rtinfo_t* rti ) {
    float coeff = 1.0f;
#if (TALENT_CRUSADE)
    if ( UP( avenging_wrath_expire ) ) coeff *= 1.0f + 0.02f * crusade_stack;
#endif
    return coeff;
}

float spec_haste_increament( rtinfo_t* rti ) {
    return 0.0f;
}

k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate;
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
#if (TALENT_CRUSADE)
    if ( UP( avenging_wrath_expire ) )                          dmg *= 1.0f + 0.05f * crusade_stack;
#else
    if ( UP( avenging_wrath_expire ) )                          dmg *= 1.35f;
#endif
    if ( UP( thorasus_the_stone_heart_of_draenor_expire ) )     dmg *= 1.0f + legendary_ring * 0.0001f;
#if defined(trinket_libram_of_vindication)
    if ( UP( libram_of_vindication_expire ) )                   dmg *= 1.0f + trinket_libram_of_vindication * 0.0001f * libram_of_vindication_stack;
#endif
    if ( ENEMY_IS_DEMONIC && UP( gronntooth_war_horn_expire ) ) dmg *= 1.1f;
    if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )            cdb *= 1.02f;
    if ( DTYPE_PHYSICAL == dmgtype ) {
        if ( !ignore_armor )                                    dmg *= 0.594043f; // 0.680228f @110lvl
    }
    if ( DICE_CRIT == dice )                                    dmg *= cdb;
    if ( DICE_CRIT == dice ) {
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
    if ( MH_TYPE == WEAPON_2H ) dmg *= 1.05f;
    return dmg;
}

float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap;
    // if ( MH_TYPE == WEAPON_2H ) dmg *= 1.05f; // TODO: does sword of light increase ap/sp damage?
    return dmg;
}

float spec_power_gain( rtinfo_t* rti, float power ) {
    /* do nothing */
}
float spec_power_check( rtinfo_t* rti, float cost ) {
    return cost;
}
float spec_power_consume( rtinfo_t* rti, float cost ) {
#if (TALENT_CRUSADE)
    crusade_stack = min( crusade_stack + cost, 15.0f );
    refresh_haste( rti );
#endif
    return cost;
}

/* event list. */
enum {
    END_OF_CLASS_ROUTNUM = START_OF_SPEC_ROUTNUM - 1,
    routnum_auto_attack,
    routnum_avenging_wrath_cast,
    routnum_avenging_wrath_expire,
    routnum_avenging_wrath_cd,
    routnum_blade_of_justice_cast,
    routnum_blade_of_justice_cd,
    routnum_judgment_cast,
    routnum_judgment_expire,
    routnum_judgment_cd,
    routnum_crusader_strike_charge,
    routnum_crusader_strike_cast,
    routnum_divine_storm_cast,
    routnum_templars_verdict_cast,
#if (TALENT_EXECUTION_SENTENCE)
    routnum_execution_sentence_cast,
    routnum_execution_sentence_expire,
    routnum_execution_sentence_cd,
#endif
#if (TALENT_CONSECRATION)
    routnum_consecration_cast,
    routnum_consecration_tick,
    routnum_consecration_cd,
#endif
#if (TALENT_THE_FIRES_OF_JUSTICE)
    routnum_the_fires_of_justice_trigger,
    routnum_the_fires_of_justice_expire,
#endif
#if (TALENT_ZEAL)
    routnum_zeal_trigger,
    routnum_zeal_expire,
#endif
#if (TALENT_BLADE_OF_WRATH)
    routnum_blade_of_wrath_tick,
#endif
#if (TALENT_DIVINE_HAMMER)
    routnum_divine_hammer_tick,
#endif
#if (TALENT_JUSTICARS_VENGEANCE)
    routnum_justicars_vengeance_cast,
#endif
#if (TALENT_DIVINE_PURPOSE)
    routnum_divine_purpose_trigger,
    routnum_divine_purpose_expire,
#endif
#if defined(trinket_libram_of_vindication)
    routnum_libram_of_vindication_expire,
    routnum_libram_of_vindication_trigger,
#endif
    START_OF_WILD_ROUTNUM,
};

// === auto-attack ============================================================
DECL_EVENT( auto_attack ) {
    float d = weapon_dmg( rti, 1.0f, 0, 0 );
    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 );
    lprintf( ( "mh hit" ) );

    float aspeed = 1.0f + rti->player.stat.haste;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( MH_SPEED / aspeed ) ), routnum_auto_attack, rti->player.target );
}

// === avenging wrath =========================================================
DECL_EVENT( avenging_wrath_cast ) {
    avenging_wrath_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, avenging_wrath_expire, routnum_avenging_wrath_expire, 0 );
#if (TALENT_CRUSADE)
    crusade_stack = 1;
    refresh_haste( rti );
#endif
    lprintf( ( "avenging_wrath start" ) );
}
DECL_EVENT( avenging_wrath_expire ) {
    if ( avenging_wrath_expire == rti->timestamp ) {
#if (TALENT_CRUSADE)
        crusade_stack = 0;
        refresh_haste( rti );
#endif
        lprintf( ( "avenging_wrath expire" ) );
    }
}
DECL_EVENT( avenging_wrath_cd ) {
    if ( avenging_wrath_cd == rti->timestamp ) {
        lprintf( ( "avenging_wrath cd" ) );
    }
}
DECL_SPELL( __icintl__avenging_wrath ) {
    if ( avenging_wrath_cd > rti->timestamp ) return 0;
    avenging_wrath_cd = TIME_OFFSET( FROM_SECONDS( 120 ) );
    eq_enqueue( rti, avenging_wrath_cd, routnum_avenging_wrath_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_avenging_wrath_cast, 0 );
    lprintf( ( "cast avenging_wrath" ) );
    return 1;
}
SPELL_ALIAS( avenging_wrath, __icintl__avenging_wrath, !TALENT_CRUSADE )
SPELL_ALIAS( crusade,        __icintl__avenging_wrath,  TALENT_CRUSADE )

// === blade of justice =======================================================
DECL_EVENT( blade_of_justice_cd ) {
    if ( blade_of_justice_cd == rti->timestamp ) {
        lprintf( ( "blade_of_justice cd" ) );
    }
}
DECL_EVENT( blade_of_justice_cast ) {
    float d = weapon_dmg( rti, ( TALENT_BLADE_OF_WRATH ? 2.4f : 4.05f ), 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, ( TALENT_BLADE_OF_WRATH ? DTYPE_HOLY : DTYPE_PHYSICAL ), dice, ( TALENT_VIRTUES_BLADE ? 0.5f : 0 ), 0 );
    power_gain( rti, 2.0f );
    lprintf( ( "blade_of_justice hit" ) );
#if (TALENT_BLADE_OF_WRATH)
    if ( UP( blade_of_wrath_expire( target_id ) ) ) {
        k32u ticks_remain = TIME_DISTANT( blade_of_wrath_expire( target_id ) ) / FROM_SECONDS( 2 );
        blade_of_wrath_expire( target_id ) += TIME_OFFSET( FROM_SECONDS( 2 * ( 4 - ticks_remain ) ) );
        lprintf( ( "blade_of_wrath_expire extends to %f sec", TO_SECONDS( TIME_DISTANT( blade_of_wrath_expire( target_id ) ) ) ) );
    } else {
        blade_of_wrath_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 8 ) );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 2 ) ), routnum_blade_of_wrath_tick, target_id );
        lprintf( ( "blade_of_wrath start" ) );
    }
#endif
}
#if (TALENT_BLADE_OF_WRATH)
DECL_EVENT( blade_of_wrath_tick ) {
    if ( blade_of_wrath_expire( target_id ) < rti->timestamp ) return; // last tick evaluates as equal.
    float d = ap_dmg( rti, 0.5f );
    k32u dice = round_table_dice2( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    lprintf( ( "blade_of_wrath tick" ) );
    if ( TIME_DISTANT( blade_of_wrath_expire( target_id ) ) >= FROM_SECONDS( 2 ) ) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 2 ) ), routnum_blade_of_wrath_tick, target_id );
    }
}
#endif
DECL_SPELL( __icintl__blade_of_justice ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( blade_of_justice_cd > rti->timestamp ) return 0;
#if (TALENT_DIVINE_HAMMER)
    rti->player.spec->divine_hammer.tick_period = FROM_SECONDS( 2.0f / ( 1.0f + rti->player.stat.haste ) );
    divine_hammer_expire = TIME_OFFSET( 4 * rti->player.spec->divine_hammer.tick_period );
    blade_of_justice_cd = TIME_OFFSET( FROM_SECONDS( 8.0f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_divine_hammer_tick, ( k32u )divine_hammer_expire );
    power_gain( rti, 1.0f );
#else
    blade_of_justice_cd = TIME_OFFSET( FROM_SECONDS( 12.0f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, rti->timestamp, routnum_blade_of_justice_cast, rti->player.target );
#endif
    eq_enqueue( rti, blade_of_justice_cd, routnum_blade_of_justice_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    lprintf( ( "cast blade_of_justice" ) );
    return 1;
}
SPELL_ALIAS( blade_of_justice, __icintl__blade_of_justice, !TALENT_BLADE_OF_WRATH && !TALENT_DIVINE_HAMMER )
SPELL_ALIAS( blade_of_wrath,   __icintl__blade_of_justice, TALENT_BLADE_OF_WRATH )
SPELL_ALIAS( divine_hammer,    __icintl__blade_of_justice, TALENT_DIVINE_HAMMER )

// === judgment ===============================================================
DECL_EVENT( judgment_cast ) {
    float d = ap_dmg( rti, 2.0f );
    d *= 1.0f + rti->player.stat.mastery;
    float excr = 0.0f;
    if ( TALENT_GREATER_JUDGMENT && enemy_health_percent( rti ) >= 85.0f ) excr += 1.0f;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, excr ); // TODO: does judgment triggers as yellow melee or spell? or both?
    deal_damage( rti, target_id, d, DTYPE_HOLY, dice, 0, 0 );
    if ( TALENT_GREATER_JUDGMENT ) {
        k32u c = 0;
        for ( int i = 0; c < 2 && i < num_enemies; i++ ) {
            if ( i == target_id ) continue;
            c++;
            dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 ); // TODO: does judgment triggers as yellow melee or spell? or both?
            deal_damage( rti, i, d, DTYPE_HOLY, dice, 0, 0 );
            judgment_expire( i ) = TIME_OFFSET( FROM_SECONDS( 6 ) );  // TODO: does this duration scales with haste?
            eq_enqueue( rti, judgment_expire( i ), routnum_judgment_expire, i );
        }
        lprintf( ( "judgment multi-hit" ) );
    }
    judgment_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 6 ) );  // TODO: does this duration scales with haste?
    eq_enqueue( rti, judgment_expire( target_id ), routnum_judgment_expire, target_id );
    lprintf( ( "judgment hit" ) );
}
DECL_EVENT( judgment_expire ) {
    if ( judgment_expire( target_id ) == rti->timestamp ) {
        lprintf( ( "judgment expire" ) );
    }
}
DECL_EVENT( judgment_cd ) {
    if ( judgment_cd == rti->timestamp ) {
        lprintf( ( "judgment cd" ) );
    }
}
// TODO: what if mastery varies while judgment is up?
DECL_SPELL( judgment ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( judgment_cd > rti->timestamp ) return 0;
    judgment_cd = TIME_OFFSET( FROM_SECONDS( 12.0f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, judgment_cd, routnum_judgment_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_judgment_cast, rti->player.target );
    lprintf( ( "cast judgment" ) );
    return 1;
}

// === crusader strike ========================================================
#define crusader_strike_recharge_time (TALENT_THE_FIRES_OF_JUSTICE ? 3.0f : 4.5f)
DECL_EVENT( crusader_strike_charge ) {
    if ( crusader_strike_cd == rti->timestamp && crusader_strike_charge < crusader_strike_maxcharge ) {
        crusader_strike_charge++;
        lprintf( ( "crusader_strike charge %d", crusader_strike_charge ) );
        if ( crusader_strike_charge < crusader_strike_maxcharge ) {
            crusader_strike_cd = TIME_OFFSET( FROM_SECONDS( crusader_strike_recharge_time / ( 1.0f + rti->player.stat.haste ) ) );
            eq_enqueue( rti, crusader_strike_cd, routnum_crusader_strike_charge, 0 );
        }
    }
}
DECL_EVENT( crusader_strike_cast ) {
    float d = weapon_dmg( rti, TALENT_ZEAL ? 2.85f : 1.6f, 1, 0 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    power_gain( rti, 1.0f );
#if (TALENT_THE_FIRES_OF_JUSTICE)
    if ( uni_rng( rti ) < 0.20f ) {
        eq_enqueue( rti, rti->timestamp, routnum_the_fires_of_justice_trigger, 0 );
    }
#endif
#if (TALENT_ZEAL)
    if ( UP( zeal_expire ) ) {
        k32u c = 0;
        for ( int i = 0; c < zeal_stack && i < num_enemies; i++ ) {
            if ( i == target_id ) continue;
            c++;
            d = weapon_dmg( rti, 2.85f, 1, 0 );
            dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
            deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
            // power_gain( rti, 1.0f ); // does chain zeal give power?
        }
        lprintf( ( "zeal multi-hit" ) );
    }
    eq_enqueue( rti, rti->timestamp, routnum_zeal_trigger, 0 );
#endif
#if defined(trinket_libram_of_vindication)
    eq_enqueue( rti, rti->timestamp, routnum_libram_of_vindication_trigger, target_id );
#endif
    lprintf( ( "crusader_strike hit" ) );
}
DECL_SPELL( __icintl__crusader_strike ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( crusader_strike_charge == 0 ) return 0;
    crusader_strike_charge--;
    if ( !UP( crusader_strike_cd ) ) {
        crusader_strike_cd = TIME_OFFSET( FROM_SECONDS( crusader_strike_recharge_time / ( 1.0f + rti->player.stat.haste ) ) );
        eq_enqueue( rti, crusader_strike_cd, routnum_crusader_strike_charge, 0 );
    }
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_crusader_strike_cast, rti->player.target );
    lprintf( ( "cast crusader_strike" ) );
    return 1;
}
SPELL_ALIAS( crusader_strike, __icintl__crusader_strike, !TALENT_ZEAL )
SPELL_ALIAS( zeal,            __icintl__crusader_strike,  TALENT_ZEAL )

// === divine storm ===========================================================
DECL_EVENT( divine_storm_cast ) {
    for ( int i = 0; i < num_enemies; i++ ) {
        float multiplier = TALENT_FINAL_VERDICT ? 1.1f : 1.0f;
        if ( UP( judgment_expire( i ) ) ) multiplier *= 1.0f + 0.5f * rti->player.stat.mastery;
        float d = weapon_dmg( rti, 1.8f, 1, 0 ) * multiplier;
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );  // TODO: does divine storm triggers as yellow melee or spell? or both?
        deal_damage( rti, i, d, DTYPE_HOLY, dice, 0, 0 );
        lprintf( ( "divine_storm hit @tar%d", i ) );
    }
#if (TALENT_DIVINE_PURPOSE)
    if ( uni_rng( rti ) < 0.15f ) {
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_trigger, 0 );
    }
#endif
}
DECL_SPELL( divine_storm ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    float cost = 3.0f;
    if ( UP( divine_purpose_expire ) ) cost = 0.0f;
    else if ( UP( the_fires_of_justice_expire ) ) cost -= 1.0f;
    if ( !power_check( rti, cost ) ) return 0;
    power_consume( rti, cost );
#if (TALENT_DIVINE_PURPOSE)
    if ( UP( divine_purpose_expire ) ) {
        divine_purpose_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_expire, 0 );
    } else
#endif
#if (TALENT_THE_FIRES_OF_JUSTICE)
    if ( UP( the_fires_of_justice_expire ) ) {
        the_fires_of_justice_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_the_fires_of_justice_expire, 0 );
    }
#endif
    ;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_divine_storm_cast, rti->player.target );
    lprintf( ( "cast divine_storm" ) );
    return 1;
}

// === templars verdict =======================================================
DECL_EVENT( templars_verdict_cast ) {
    float multiplier = TALENT_FINAL_VERDICT ? 1.2f : 1.0f;
    if ( UP( judgment_expire( target_id ) ) ) multiplier *= 1.0f + 0.5f * rti->player.stat.mastery;
    float d = weapon_dmg( rti, 3.9f, 1, 0 ) * multiplier;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );  // TODO: does templars_verdict triggers as yellow melee or spell? or both?
    deal_damage( rti, target_id, d, DTYPE_HOLY, dice, 0, 0 );
    lprintf( ( "templars_verdict hit" ) );
#if (TALENT_DIVINE_PURPOSE)
    if ( uni_rng( rti ) < 0.15f ) {
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_trigger, 0 );
    }
#endif
}
DECL_SPELL( templars_verdict ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    float cost = 3.0f;
    if ( UP( divine_purpose_expire ) ) cost = 0.0f;
    else if ( UP( the_fires_of_justice_expire ) ) cost -= 1.0f;
    if ( !power_check( rti, cost ) ) return 0;
    power_consume( rti, cost );
#if (TALENT_DIVINE_PURPOSE)
    if ( UP( divine_purpose_expire ) ) {
        divine_purpose_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_expire, 0 );
    } else
#endif
#if (TALENT_THE_FIRES_OF_JUSTICE)
    if ( UP( the_fires_of_justice_expire ) ) {
        the_fires_of_justice_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_the_fires_of_justice_expire, 0 );
    }
#endif
    ;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_templars_verdict_cast, rti->player.target );
    lprintf( ( "cast templars_verdict" ) );
    return 1;
}

// === execution sentence =====================================================
#if (TALENT_EXECUTION_SENTENCE)
DECL_EVENT( execution_sentence_cast ) {
    execution_sentence_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 8.0f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, execution_sentence_expire( target_id ), routnum_execution_sentence_expire, target_id );
    lprintf( ( "execution_sentence apply @tar%d", target_id ) );
#if (TALENT_DIVINE_PURPOSE)
    if ( uni_rng( rti ) < 0.15f ) {
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_trigger, 0 );
    }
#endif
}
DECL_EVENT( execution_sentence_expire ) {
    if ( execution_sentence_expire( target_id ) == rti->timestamp ) {
        float d = ap_dmg( rti, 16.2f );
        if ( UP( judgment_expire( target_id ) ) ) d *= 1.0f + 0.5f * rti->player.stat.mastery;
        k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 ); // TODO: does execution sentence triggers as yellow melee or spell? or both?
        deal_damage( rti, target_id, d, DTYPE_HOLY, dice, 0, 0 );
        lprintf( ( "execution_sentence explodes @tar%d", target_id ) );
    }
}
DECL_EVENT( execution_sentence_cd ) {
    if ( execution_sentence_cd == rti->timestamp ) {
        lprintf( ( "execution_sentence cd" ) );
    }
}
DECL_SPELL( execution_sentence ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( execution_sentence_cd > rti->timestamp ) return 0;
    float cost = 3.0f;
    if ( UP( divine_purpose_expire ) ) cost = 0.0f;
    else if ( UP( the_fires_of_justice_expire ) ) cost -= 1.0f;
    if ( !power_check( rti, cost ) ) return 0;
    power_consume( rti, cost );
#if (TALENT_DIVINE_PURPOSE)
    if ( UP( divine_purpose_expire ) ) {
        divine_purpose_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_expire, 0 );
    } else
#endif
#if (TALENT_THE_FIRES_OF_JUSTICE)
    if ( UP( the_fires_of_justice_expire ) ) {
        the_fires_of_justice_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_the_fires_of_justice_expire, 0 );
    }
#endif
    ;
    execution_sentence_cd = TIME_OFFSET( FROM_SECONDS( 20.0f / ( 1.0f + rti->player.stat.haste ) ) );
    eq_enqueue( rti, execution_sentence_cd, routnum_execution_sentence_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_execution_sentence_cast, rti->player.target );
    lprintf( ( "cast execution_sentence" ) );
    return 1;
}
#else
DECL_SPELL( execution_sentence ) {
    return 0;
}
#endif

// === consecration ===========================================================
#if (TALENT_CONSECRATION)
DECL_EVENT( consecration_cd ) {
    if ( consecration_cd == rti->timestamp ) {
        lprintf( ( "consecration ready" ) );
    }
}
DECL_EVENT( consecration_tick ) {
    if ( ( k32u )consecration_expire != target_id ) return; // target_id is the distinction of hanging tick events.
    for ( int i = 0; i < num_enemies; i++ ) {
        float d = ap_dmg( rti, 0.45f );
        k32u dice = round_table_dice( rti, i, ATYPE_SPELL, 0 );  // TODO: does consecration triggers as yellow melee or spell? or both?
        deal_damage( rti, i, d, DTYPE_HOLY, dice, 0, 0 );
        lprintf( ( "consecration hit @tar%d", i ) );
    }
    if ( UP( consecration_expire ) ) {
        eq_enqueue( rti, TIME_OFFSET( rti->player.spec->consecration.tick_period ), routnum_consecration_tick, target_id );
    } else {
        lprintf( ( "consecration expire" ) );
    }
}
DECL_EVENT( consecration_cast ) {
    lprintf( ( "consecration start" ) );
}
DECL_SPELL( consecration ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( consecration_cd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    consecration_cd = TIME_OFFSET( FROM_SECONDS( 9.0f / ( 1.0f + rti->player.stat.haste ) ) );
    rti->player.spec->consecration.tick_period = FROM_SECONDS( 1.0f / ( 1.0f + rti->player.stat.haste ) );
    consecration_expire = TIME_OFFSET( 9 * rti->player.spec->consecration.tick_period );
    eq_enqueue( rti, consecration_cd, routnum_consecration_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_consecration_cast, 0 );
    eq_enqueue( rti, TIME_OFFSET( rti->player.spec->consecration.tick_period ), routnum_consecration_tick, ( k32u )consecration_expire );
    lprintf( ( "cast consecration" ) );
    return 1;
}
#else
DECL_SPELL( consecration ) {
    return 0;
}
#endif

// === the fires of justice ===================================================
#if (TALENT_THE_FIRES_OF_JUSTICE)
DECL_EVENT( the_fires_of_justice_expire ) {
    if ( the_fires_of_justice_expire == rti->timestamp ) {
        lprintf( ( "the_fires_of_justice expire" ) );
    }
}
DECL_EVENT( the_fires_of_justice_trigger ) {
    the_fires_of_justice_expire = TIME_OFFSET( FROM_SECONDS( 15 ) );
    eq_enqueue( rti, the_fires_of_justice_expire, routnum_the_fires_of_justice_expire, 0 );
    lprintf( ( "the_fires_of_justice trigger" ) );
}
#endif

// === zeal ===================================================================
#if (TALENT_ZEAL)
DECL_EVENT( zeal_expire ) {
    if ( zeal_expire == rti->timestamp ) {
        zeal_stack = 0;
        lprintf( ( "zeal expire" ) );
    }
}
DECL_EVENT( zeal_trigger ) {
    zeal_expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    zeal_stack = min( (k32u)zeal_stack + 1, (k32u)3 );
    eq_enqueue( rti, zeal_expire, routnum_zeal_expire, 0 );
    lprintf( ( "zeal stack %d", zeal_stack ) );
}
#endif

// === divine hammer ==========================================================
#if (TALENT_DIVINE_HAMMER)
DECL_EVENT( divine_hammer_tick ) {
    if ( ( k32u )divine_hammer_expire != target_id ) return; // target_id is the distinction of hanging tick events.
    for ( int i = 0; i < num_enemies; i++ ) {
        float d = ap_dmg( rti, 0.5f );
        k32u dice = round_table_dice( rti, i, ATYPE_SPELL, 0 );  // TODO: does divine hammer triggers as yellow melee or spell? or both?
        deal_damage( rti, i, d, DTYPE_HOLY, dice, 0, 0 );
        lprintf( ( "divine_hammer hit @tar%d", i ) );
    }
    if ( UP( divine_hammer_expire ) ) {
        eq_enqueue( rti, TIME_OFFSET( rti->player.spec->divine_hammer.tick_period ), routnum_divine_hammer_tick, target_id );
    } else {
        lprintf( ( "divine_hammer expire" ) );
    }
}
#endif

// === justicar's vengeance ===================================================
#if (TALENT_JUSTICARS_VENGEANCE)
DECL_EVENT( justicars_vengeance_cast ) {
    float multiplier = 1.0f;
    if ( UP( judgment_expire( target_id ) ) ) multiplier *= 1.0f + 0.5f * rti->player.stat.mastery;
    float d = ap_dmg( rti, 8.0f, 1, 0 ) * multiplier;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );  // TODO: does justicars vengeance triggers as yellow melee or spell? or both?
    deal_damage( rti, target_id, d, DTYPE_HOLY, dice, 0, 0 );
    lprintf( ( "justicars_vengeance hit" ) );
#if (TALENT_DIVINE_PURPOSE)
    if ( uni_rng( rti ) < 0.15f ) {
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_trigger, 0 );
    }
#endif
}
DECL_SPELL( justicars_vengeance ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    float cost = 5.0f;
    if ( UP( divine_purpose_expire ) ) cost = 0.0f;
    else if ( UP( the_fires_of_justice_expire ) ) cost -= 1.0f;
    if ( !power_check( rti, cost ) ) return 0;
    power_consume( rti, cost );
#if (TALENT_DIVINE_PURPOSE)
    if ( UP( divine_purpose_expire ) ) {
        divine_purpose_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_divine_purpose_expire, 0 );
    } else
#endif
#if (TALENT_THE_FIRES_OF_JUSTICE)
    if ( UP( the_fires_of_justice_expire ) ) {
        the_fires_of_justice_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_the_fires_of_justice_expire, 0 );
    }
#endif
    ;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_justicars_vengeance_cast, rti->player.target );
    lprintf( ( "cast justicars_vengeance" ) );
    return 1;
}
#else
DECL_SPELL( justicars_vengeance ) {
    return 0;
}
#endif

// === divine purpose =========================================================
#if (TALENT_DIVINE_PURPOSE)
DECL_EVENT( divine_purpose_expire ) {
    if ( divine_purpose_expire == rti->timestamp ) {
        lprintf( ( "divine_purpose expire" ) );
    }
}
DECL_EVENT( divine_purpose_trigger ) {
    divine_purpose_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, divine_purpose_expire, routnum_divine_purpose_expire, 0 );
    lprintf( ( "divine_purpose trigger" ) );
}
#endif

// === libram of vindication ==================================================
#if defined(trinket_libram_of_vindication)
DECL_EVENT( libram_of_vindication_expire ) {
    if ( libram_of_vindication_expire == rti->timestamp ) {
        libram_of_vindication_stack = 0;
        lprintf( ( "libram_of_vindication expire" ) );
    }
}
DECL_EVENT( libram_of_vindication_trigger ) {
    libram_of_vindication_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    if (target_id == rti->player.spec->libram_of_vindication.target) {
        libram_of_vindication_stack = min( (k32u)libram_of_vindication_stack + 1, (k32u)3 );
    }else{
        libram_of_vindication_stack = 1;
        rti->player.spec->libram_of_vindication.target = target_id;
    }
    eq_enqueue( rti, libram_of_vindication_expire, routnum_libram_of_vindication_expire, 0 );
    lprintf( ( "libram_of_vindication stack %d", libram_of_vindication_stack ) );
}
#endif


void spec_routine_entries( rtinfo_t* rti, _event_t e ) {
    switch ( e.routine ) {
        HOOK_EVENT( auto_attack );
        HOOK_EVENT( avenging_wrath_cast );
        HOOK_EVENT( avenging_wrath_expire );
        HOOK_EVENT( avenging_wrath_cd );
        HOOK_EVENT( blade_of_justice_cast );
        HOOK_EVENT( blade_of_justice_cd );
        HOOK_EVENT( judgment_cast );
        HOOK_EVENT( judgment_expire );
        HOOK_EVENT( judgment_cd );
        HOOK_EVENT( crusader_strike_cast );
        HOOK_EVENT( crusader_strike_charge );
        HOOK_EVENT( divine_storm_cast );
        HOOK_EVENT( templars_verdict_cast );
#if (TALENT_EXECUTION_SENTENCE)
        HOOK_EVENT( execution_sentence_cast );
        HOOK_EVENT( execution_sentence_expire );
        HOOK_EVENT( execution_sentence_cd );
#endif
#if (TALENT_CONSECRATION)
        HOOK_EVENT( consecration_cast );
        HOOK_EVENT( consecration_tick );
        HOOK_EVENT( consecration_cd );
#endif
#if (TALENT_THE_FIRES_OF_JUSTICE)
        HOOK_EVENT( the_fires_of_justice_trigger );
        HOOK_EVENT( the_fires_of_justice_expire );
#endif
#if (TALENT_ZEAL)
        HOOK_EVENT( zeal_trigger );
        HOOK_EVENT( zeal_expire );
#endif
#if (TALENT_BLADE_OF_WRATH)
        HOOK_EVENT( blade_of_wrath_tick );
#endif
#if (TALENT_DIVINE_HAMMER)
        HOOK_EVENT( divine_hammer_tick );
#endif
#if (TALENT_JUSTICARS_VENGEANCE)
        HOOK_EVENT( justicars_vengeance_cast );
#endif
#if (TALENT_DIVINE_PURPOSE)
        HOOK_EVENT( divine_purpose_trigger );
        HOOK_EVENT( divine_purpose_expire );
#endif
    default:
        lprintf( ( "wild spec routine entry %d, last defined routnum %d", e.routine, START_OF_WILD_ROUTNUM - 1 ) );
        assert( 0 );
    }
}

void spec_module_init( rtinfo_t* rti ) {
    eq_enqueue( rti, rti->timestamp, routnum_auto_attack, 0 );
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {

}
