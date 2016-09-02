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

/* artifact traits */
#define ATRAIT_ODYNS_FURY           (ARTIFACT_TRAITS_0)
#define ATRAIT_BATTLE_SCARS         (ARTIFACT_TRAITS_1)
#define ATRAIT_BLOODCRAZE           (ARTIFACT_TRAITS_2)
#define ATRAIT_DEATHDEALER          (ARTIFACT_TRAITS_3)
#define ATRAIT_FOCUS_IN_CHAOS       (ARTIFACT_TRAITS_4)
#define ATRAIT_HELYAS_WRATH         (ARTIFACT_TRAITS_5)
#define ATRAIT_JUGGERNAUT           (ARTIFACT_TRAITS_6)
#define ATRAIT_ODYNS_CHAMPION       (ARTIFACT_TRAITS_7)
#define ATRAIT_RAGE_OF_THE_VALARJAR (ARTIFACT_TRAITS_8)
#define ATRAIT_RAGING_BERSERKER     (ARTIFACT_TRAITS_9)
#define ATRAIT_SENSE_DEATH          (ARTIFACT_TRAITS_10)
#define ATRAIT_THIRST_FOR_BATTLE    (ARTIFACT_TRAITS_11)
#define ATRAIT_TITANIC_POWER        (ARTIFACT_TRAITS_12)
#define ATRAIT_UNCONTROLLED_RAGE    (ARTIFACT_TRAITS_13)
#define ATRAIT_UNRIVALED_STRENGTH   (ARTIFACT_TRAITS_14)
#define ATRAIT_UNSTOPPABLE          (ARTIFACT_TRAITS_15)
#define ATRAIT_WILD_SLASHES         (ARTIFACT_TRAITS_16)
#define ATRAIT_WRATH_AND_FURY       (ARTIFACT_TRAITS_17)

deviceonly( __constant ) float atrait_raging_berserker_lut[] =   { 0.000f, 0.010f, 0.020f, 0.030f, 0.040f, 0.050f, 0.060f };
deviceonly( __constant ) float atrait_unrivaled_strength_lut[] = { 0.000f, 0.050f, 0.100f, 0.150f, 0.200f, 0.250f, 0.300f };
deviceonly( __constant ) float atrait_deathdealer_lut[] =        { 0.000f, 0.030f, 0.060f, 0.100f, 0.130f, 0.160f, 0.200f };
deviceonly( __constant ) float atrait_unstoppable_lut[] =        { 0.000f, 0.030f, 0.060f, 0.090f, 0.120f, 0.150f, 0.180f };
deviceonly( __constant ) float atrait_titanic_power_lut[] =      { 0.000f, 0.050f, 0.055f, 0.060f, 0.065f, 0.070f, 0.075f,
                                                                   0.080f, 0.085f, 0.090f, 0.095f, 0.100f, 0.105f, 0.110f,
                                                                   0.115f, 0.120f, 0.125f, 0.130f, 0.135f, 0.140f, 0.145f };
deviceonly( __constant ) float atrait_uncontrolled_rage_lut[] =  { 0.000f, 5.000f, 10.00f, 15.00f, 20.00f, 25.00f, 30.00f };
deviceonly( __constant ) float atrait_wild_slashes_lut[] =       { 0.000f, 0.070f, 0.140f, 0.210f, 0.280f, 0.350f, 0.420f };
deviceonly( __constant ) float atrait_wrath_and_fury_lut[] =     { 0.000f, 0.050f, 0.100f, 0.150f, 0.200f, 0.250f, 0.300f };

/* spec state infos. */
struct spec_state_t {
    struct {
        time_t cd;
    } bloodthirst;
#define bloodthirst_cd (rti->player.spec->bloodthirst.cd)
    struct {
        time_t expire;
    } enrage;
#define enrage_expire (rti->player.spec->enrage.expire)
    struct {
        time_t cd;
    } rampage;
#define rampage_cd (rti->player.spec->rampage.cd)
    struct {
        time_t expire;
        k32u stack;
    } taste_for_blood;
#define taste_for_blood_expire (rti->player.spec->taste_for_blood.expire)
#define taste_for_blood_stack  (rti->player.spec->taste_for_blood.stack)
    struct {
        time_t expire;
    } meat_cleaver;
#define meat_cleaver_expire (rti->player.spec->meat_cleaver.expire)
#if (TALENT_WRECKING_BALL)
    struct {
        time_t expire;
        RPPM_t proc;
    } wrecking_ball;
#define wrecking_ball_expire (rti->player.spec->wrecking_ball.expire)
#else
#define wrecking_ball_expire (0)
#endif
#if (TALENT_MASSACRE)
    struct {
        time_t expire;
    } massacre;
#define massacre_expire (rti->player.spec->massacre.expire)
#else
#define massacre_expire (0)
#endif
#if (TALENT_FROTHING_BERSERKER)
    struct {
        time_t expire;
    } frothing_berserker;
#define frothing_berserker_expire (rti->player.spec->frothing_berserker.expire)
#else
#define frothing_berserker_expire (0)
#endif
#if (TALENT_BLOODBATH)
    struct {
        time_t expire;
        time_t cd;
    } bloodbath;
#define bloodbath_expire (rti->player.spec->bloodbath.expire)
#define bloodbath_cd     (rti->player.spec->bloodbath.cd)
#else
#define bloodbath_expire (0)
#define bloodbath_cd     (0)
#endif
#if (TALENT_FRENZY)
    struct {
        time_t expire;
        k32u stack;
    } frenzy;
#define frenzy_expire (rti->player.spec->frenzy.expire)
#define frenzy_stack  (rti->player.spec->frenzy.stack)
#else
#define frenzy_expire (0)
#define frenzy_stack  (0)
#endif
#if (TALENT_INNER_RAGE)
    struct {
        time_t cd;
    } raging_blow;
#define raging_blow_cd (rti->player.spec->raging_blow.cd)
#else
#define raging_blow_cd (0)
#endif
#if (TALENT_DRAGON_ROAR)
    struct {
        time_t cd;
        time_t expire;
    } dragon_roar;
#define dragon_roar_cd     (rti->player.spec->dragon_roar.cd)
#define dragon_roar_expire (rti->player.spec->dragon_roar.expire)
#else
#define dragon_roar_cd     (0)
#define dragon_roar_expire (0)
#endif
#if (ATRAIT_ODYNS_FURY)
    struct {
        time_t cd;
    } odyns_fury;
#define odyns_fury_cd (rti->player.spec->odyns_fury.cd)
#else
#define odyns_fury_cd (0)
#endif
#if (ATRAIT_JUGGERNAUT)
    struct {
        time_t expire;
        k32u stack;
    } juggernaut;
#define juggernaut_expire (rti->player.spec->juggernaut.expire)
#define juggernaut_stack  (rti->player.spec->juggernaut.stack)
#else
#define juggernaut_expire (0)
#define juggernaut_stack  (0)
#endif
#if (ATRAIT_ODYNS_CHAMPION)
    struct {
        time_t expire;
    } odyns_champion;
#define odyns_champion_expire (rti->player.spec->odyns_champion.expire)
#else
#define odyns_champion_expire (0)
#endif
#if (ATRAIT_RAGE_OF_THE_VALARJAR)
    struct {
        time_t expire;
        k32u stack;
    } berserking_;
    struct {
        time_t expire;
        ICD_t proc;
    } berserking_driver;
#define berserking_driver_expire (rti->player.spec->berserking_driver.expire)
#define berserking__expire (rti->player.spec->berserking_.expire)
#define berserking__stack  (rti->player.spec->berserking_.stack)
#else
#define berserking_driver_expire (0)
#define berserking__expire (0)
#define berserking__stack  (0)
#endif
#if (ATRAIT_SENSE_DEATH)
    struct {
        time_t expire;
    } sense_death;
#define sense_death_expire (rti->player.spec->sense_death.expire)
#else
#define sense_death_expire (0)
#endif
};
struct spec_debuff_t {
#if (TALENT_BLOODBATH)
    struct {
        time_t dot_start;
        float pool;
        float ticks;
    } bloodbath;
#endif
#if (ATRAIT_ODYNS_FURY)
    struct {
        time_t expire;
    } odyns_fury;
#define odyns_fury_expire(target) (rti->enemy[target].spec->odyns_fury.expire)
#else
#define odyns_fury_expire(target) (0)
#endif
};

/* check point to trace cooldown */
time_t spec_check_point( rtinfo_t* rti ) {
    time_t cp = rti->expected_combat_length;
    if ( UP( bloodthirst_cd ) ) cp = min( cp, bloodthirst_cd );
    if ( UP( rampage_cd ) )     cp = min( cp, rampage_cd );
    if ( UP( bloodbath_cd ) )   cp = min( cp, bloodbath_cd );
    if ( UP( raging_blow_cd ) ) cp = min( cp, raging_blow_cd );
    if ( UP( dragon_roar_cd ) ) cp = min( cp, dragon_roar_cd );
    if ( UP( odyns_fury_cd ) )  cp = min( cp, odyns_fury_cd );
    return cp;
}

/* Reimplemented power gain. */
#if (TALENT_FROTHING_BERSERKER)
void frothing_berserker_trigger( rtinfo_t* rti );
#endif
float spec_power_gain( rtinfo_t* rti, float power ) {
    int frothing = 1;
    frothing &= rti->player.power < 100.0f;
    frothing &= rti->player.power + power >= 100.0f;
#if (TALENT_FROTHING_BERSERKER)
    if( frothing ) frothing_berserker_trigger( rti );
#endif
    return power;
}

float spec_power_check( rtinfo_t* rti, float cost ) {
    return cost;
}

float spec_power_consume( rtinfo_t* rti, float cost ) {
    return cost;
}

float spec_str_coefficient( rtinfo_t* rti ) {
    return 1.0f;
}

float spec_mastery_coefficient( rtinfo_t* rti ) {
    return 1.4f;
}

float spec_mastery_increament( rtinfo_t* rti ) {
    float mastery = 0.0f;
    if ( ATRAIT_RAGING_BERSERKER ) mastery += atrait_raging_berserker_lut[ATRAIT_RAGING_BERSERKER];
    return mastery;
}

float spec_crit_increament( rtinfo_t* rti ) {
    float crit = 0.0f;
    if ( UP( berserking__expire ) ) crit += 0.03f * berserking__stack;
    return crit;
}

float spec_haste_coefficient( rtinfo_t* rti ) {
    float coeff = 1.0f;
    coeff *= 1.0f + frenzy_stack * 0.04f;
    return coeff;
}

float spec_haste_increament( rtinfo_t* rti ) {
    return 0.0f;
}

k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate;
    if ( ATYPE_WHITE_MELEE == attacktype ) {
        cr += ( ATRAIT_FOCUS_IN_CHAOS && UP( enrage_expire ) ) ? 0.0f : 0.19f;
        if ( c < 0.19f ) return DICE_MISS;
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
    dmg *= 1.0f + atrait_titanic_power_lut[ATRAIT_TITANIC_POWER];
    if ( UP( enrage_expire ) )                                  dmg *= 1.0f + rti->player.stat.mastery;
    if ( UP( avatar_expire ) )                                  dmg *= 1.2f;
    if ( UP( dragon_roar_expire ) )                             dmg *= 1.2f;
    if ( UP( frothing_berserker_expire ) )                      dmg *= 1.1f;
    if ( ENEMY_IS_DEMONIC && UP( gronntooth_war_horn_expire ) ) dmg *= 1.1f;
    if ( UP( battle_cry_expire ) )                              cdb *= 1.0f + atrait_unrivaled_strength_lut[ATRAIT_UNRIVALED_STRENGTH];
    if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )            cdb *= 1.02f;
    if ( DTYPE_PHYSICAL == dmgtype ) {
        if ( !ignore_armor )                                    dmg *= 0.680228f; // @110lvl
    }
    if ( DICE_CRIT   == dice )                                  dmg *= cdb;
    if ( DICE_CRIT   == dice ) {
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
    if ( offhand ) dmg *= 0.5f;
    return dmg;
}

float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap;
    return dmg;
}

/* event list. */
enum {
    END_OF_CLASS_ROUTNUM = START_OF_SPEC_ROUTNUM - 1,
    routnum_auto_attack_mh,
    routnum_auto_attack_oh,
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
#if (TALENT_BLOODBATH)
    routnum_bloodbath_start,
    routnum_bloodbath_expire,
    routnum_bloodbath_tick,
#endif
#if (TALENT_FRENZY)
    routnum_frenzy_trigger,
    routnum_frenzy_expire,
#endif
#if (TALENT_DRAGON_ROAR)
    routnum_dragon_roar_cast,
    routnum_dragon_roar_expire,
#endif
#if (ATRAIT_ODYNS_FURY)
    routnum_odyns_fury_cast,
    routnum_odyns_fury_tick,
#endif
#if (ATRAIT_JUGGERNAUT)
    routnum_juggernaut_trigger,
    routnum_juggernaut_expire,
#endif
#if (ATRAIT_ODYNS_CHAMPION)
    routnum_odyns_champion_trigger,
    routnum_odyns_champion_expire,
#endif
#if (ATRAIT_RAGE_OF_THE_VALARJAR)
    routnum_berserking_driver_trigger,
    routnum_berserking_driver_tick,
    routnum_berserking__trigger,
    routnum_berserking__expire,
#endif
#if (ATRAIT_SENSE_DEATH)
    routnum_sense_death_trigger,
    routnum_sense_death_expire,
#endif
    START_OF_WILD_ROUTNUM,
};

// === auto-attack ============================================================
DECL_EVENT( auto_attack_mh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 0 );

    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    float final_dmg = deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, rti->player.target );
    if ( dice == DICE_MISS ) {
        /* Miss */
        lprintf( ( "mh miss" ) );
    } else {
        power_gain( rti, 1.4f * weapon[0].speed * ( TALENT_ENDLESS_RAGE ? 1.3f : 1.0f ) );
        lprintf( ( "mh hit" ) );
    }

    float aspeed = 1.0f + rti->player.stat.haste;
    if ( UP( enrage_expire ) ) aspeed *= 2.0f;
    if ( UP( berserking__expire ) ) aspeed *= 1.0f + 0.03f * berserking__stack;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[0].speed / aspeed ) ), routnum_auto_attack_mh, rti->player.target );
}

DECL_EVENT( auto_attack_oh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 1 );
    k32u dice = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    float final_dmg = deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, rti->player.target );
    if ( dice == DICE_MISS ) {
        /* Miss */
        lprintf( ( "oh miss" ) );
    } else {
        power_gain( rti, 1.4f * weapon[1].speed * 0.5f * ( TALENT_ENDLESS_RAGE ? 1.3f : 1.0f ) );
        lprintf( ( "oh hit" ) );
    }

    float aspeed = 1.0f + rti->player.stat.haste;
    if ( UP( enrage_expire ) ) aspeed *= 2.0f;
    if ( UP( berserking__expire ) ) aspeed *= 1.0f + 0.03f * berserking__stack;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / aspeed ) ), routnum_auto_attack_oh, rti->player.target );
}

// === battle cry =============================================================
void spec_spell_battle_cry( rtinfo_t* rti ) {
#if (ATRAIT_HELYAS_WRATH)
    battle_cry_cd = AHEAD( battle_cry_cd, FROM_SECONDS( 10 ) );
#endif
}

// === berserker rage =========================================================
void spec_berserker_rage_cast( rtinfo_t* rti ) {
    if ( TALENT_OUTBURST )
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
}

// === bloodthirst ============================================================
DECL_EVENT( bloodthirst_cast ) {
    float multiplier = ( ATRAIT_THIRST_FOR_BATTLE ) ? 1.15f : 1.0f;
    float d = weapon_dmg( rti, 2.25f, 1, 0 ) * multiplier;
    float cr = 0.15f * taste_for_blood_stack;
    if ( TALENT_FRESH_MEAT && enemy_health_percent( rti ) > 80.0f ) cr += 0.3f;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, cr );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
    if ( DICE_CRIT == dice ) {
        if ( UP( taste_for_blood_expire ) ) {
            taste_for_blood_expire = rti->timestamp;
            eq_enqueue( rti, rti->timestamp, routnum_taste_for_blood_expire, 0 );
        }
        eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
    }
    power_gain( rti, 10.0f );
    lprintf( ( "bloodthirst hit" ) );
    if ( UP( meat_cleaver_expire ) ) {
        k32u c = 0;
        for( int i = 0; c < 4 && i < num_enemies; i++ ) {
            if ( i == target_id ) continue;
            c++;
            d = weapon_dmg( rti, 2.25f, 1, 0 ) * multiplier * 0.5f;
            dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, cr );
            final_dmg = deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
            trigger_dots( rti, final_dmg, i );
        }
        lprintf( ( "bloodthirst multi-hit" ) );
        meat_cleaver_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_meat_cleaver_expire, 0 );
    }
}
DECL_SPELL( bloodthirst ) {
    if ( MH_TYPE != WEAPON_2H ) return 0;
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( bloodthirst_cd > rti->timestamp ) return 0;
    bloodthirst_cd = TIME_OFFSET( FROM_SECONDS( 4.5f / ( 1.0f + rti->player.stat.haste ) ) );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_bloodthirst_cast, rti->player.target );
    trigger_offensive_abilities( rti );
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
    enrage_expire = TIME_OFFSET( FROM_SECONDS( 4 ) );
    eq_enqueue( rti, enrage_expire, routnum_enrage_expire, 0 );
    lprintf( ( "enrage trigger" ) );
}

// === execute ================================================================
DECL_EVENT( execute_cast ) {
    float multiplier = 1.0f + 0.05f * juggernaut_stack;
    float d = weapon_dmg( rti, 4.65f, 1, 0 ) * multiplier;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, atrait_deathdealer_lut[ATRAIT_DEATHDEALER] );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
#if (TALENT_MASSACRE)
    kbool have_crit = ( DICE_CRIT == dice );
#endif
    d = weapon_dmg( rti, 4.65f, 1, 1 ) * multiplier;
    dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, atrait_deathdealer_lut[ATRAIT_DEATHDEALER] );
    final_dmg += deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
#if (TALENT_MASSACRE)
    have_crit = have_crit || ( DICE_CRIT == dice );
    if ( have_crit )
        eq_enqueue( rti, rti->timestamp, routnum_massacre_trigger, 0 );
#endif
#if (ATRAIT_JUGGERNAUT)
    eq_enqueue( rti, rti->timestamp, routnum_juggernaut_trigger, 0 );
#endif
#if (ATRAIT_RAGE_OF_THE_VALARJAR)
    proc_ICD( rti, &rti->player.spec->berserking_driver.proc, 0.1f, FROM_SECONDS( 15 ), routnum_berserking_driver_trigger, 0 );
#endif
#if (ATRAIT_SENSE_DEATH)
    if ( uni_rng( rti ) < 0.15f ) {
        eq_enqueue( rti, rti->timestamp, routnum_sense_death_trigger, 0 );
    }
#endif
    lprintf( ( "execute hit" ) );
}
DECL_SPELL( execute ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( enemy_health_percent( rti ) > 20.0f ) return 0;
    if ( !UP( sense_death_expire ) ) {
        if ( !power_check( rti, 25.0f ) ) return 0;
        power_consume( rti, 25.0f );
    } else {
        sense_death_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_sense_death_expire, 0 );
    }
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_execute_cast, rti->player.target );
    trigger_offensive_abilities( rti );
    lprintf( ( "cast execute" ) );
    return 1;
}

// === furious slash ==========================================================
DECL_EVENT( furious_slash_cast ) {
    float multiplier = 1.0f + atrait_wild_slashes_lut[ATRAIT_WILD_SLASHES];
    float d = weapon_dmg( rti, 2.8f, 1, 1 ) * multiplier;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
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
    taste_for_blood_expire = TIME_OFFSET( FROM_SECONDS( 8 ) );
    eq_enqueue( rti, taste_for_blood_expire, routnum_taste_for_blood_expire, 0 );
    taste_for_blood_stack = min( 6, ( int )taste_for_blood_stack + 1 );
    lprintf( ( "taste_for_blood stack %d", taste_for_blood_stack ) );
}
DECL_SPELL( furious_slash ) {
    if ( MH_TYPE != WEAPON_2H ) return 0;
    if ( rti->player.gcd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_furious_slash_cast, rti->player.target );
    trigger_offensive_abilities( rti );
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
    meat_cleaver_expire = TIME_OFFSET( FROM_SECONDS( 20 ) );
    eq_enqueue( rti, meat_cleaver_expire, routnum_meat_cleaver_expire, 0 );
    lprintf( ( "meat_cleaver trigger" ) );
}

// === raging blow ============================================================
DECL_EVENT( raging_blow_cast ) {
    float multiplier = 1.0f + atrait_wrath_and_fury_lut[ATRAIT_WRATH_AND_FURY];
    float d = weapon_dmg( rti, 1.53f * ( TALENT_INNER_RAGE ? 2.5f : 1.0f ), 1, 0 ) * multiplier;
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    d = weapon_dmg( rti, 1.53f * ( TALENT_INNER_RAGE ? 2.5f : 1.0f ), 1, 1 ) * multiplier;
    dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    final_dmg += deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
    power_gain( rti, 5.0f );
    lprintf( ( "raging_blow hit" ) );
}
DECL_SPELL( raging_blow ) {
    if ( MH_TYPE != WEAPON_2H ) return 0;
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( TALENT_INNER_RAGE ) {
        if ( raging_blow_cd > rti->timestamp ) return 0;
    } else {
        if ( !UP( enrage_expire ) ) return 0;
    }
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_raging_blow_cast, rti->player.target );
#if (TALENT_INNER_RAGE)
    raging_blow_cd = TIME_OFFSET( FROM_SECONDS( 4.5f / ( 1.0f + rti->player.stat.haste ) ) );
#endif
    trigger_offensive_abilities( rti );
    lprintf( ( "cast raging_blow" ) );
    return 1;
}

// === rampage ================================================================
DECL_EVENT( rampage_cast_1 ) {
    k32u multihit_signal = 0;
    float multiplier = 1.0f + atrait_unstoppable_lut[ATRAIT_UNSTOPPABLE];
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
    float d = weapon_dmg( rti, 0.5f, 1, 0 ) * multiplier * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
    eq_enqueue( rti, rti->timestamp, routnum_enrage_trigger, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_MILLISECONDS( 200 ) ), routnum_rampage_cast_2, target_id + multihit_signal );
#if (ATRAIT_ODYNS_CHAMPION)
    if ( uni_rng( rti ) < 0.1f ) {
        eq_enqueue( rti, rti->timestamp, routnum_odyns_champion_trigger, 0 );
    }
#endif
#if (ATRAIT_RAGE_OF_THE_VALARJAR)
    proc_ICD( rti, &rti->player.spec->berserking_driver.proc, 0.1f, FROM_SECONDS( 15 ), routnum_berserking_driver_trigger, 0 );
#endif
    lprintf( ( "rampage 1st hit" ) );
}
DECL_EVENT( rampage_cast_2 ) {
    k32u multihit_signal = 0;
    float multiplier = 1.0f + atrait_unstoppable_lut[ATRAIT_UNSTOPPABLE];
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
    float d = weapon_dmg( rti, 1.5f, 1, 1 ) * multiplier * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
    eq_enqueue( rti, TIME_OFFSET( FROM_MILLISECONDS( 333 ) ), routnum_rampage_cast_3, target_id + multihit_signal );
    lprintf( ( "rampage 2nd hit" ) );
}
DECL_EVENT( rampage_cast_3 ) {
    k32u multihit_signal = 0;
    float multiplier = 1.0f + atrait_unstoppable_lut[ATRAIT_UNSTOPPABLE];
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
    float d = weapon_dmg( rti, 1.0f, 1, 0 ) * multiplier * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
    eq_enqueue( rti, TIME_OFFSET( FROM_MILLISECONDS( 667 ) ), routnum_rampage_cast_4, target_id + multihit_signal );
    lprintf( ( "rampage 3rd hit" ) );
}
DECL_EVENT( rampage_cast_4 ) {
    k32u multihit_signal = 0;
    float multiplier = 1.0f + atrait_unstoppable_lut[ATRAIT_UNSTOPPABLE];
    if ( target_id >= num_enemies ) {
        multihit_signal = num_enemies;
        target_id -= num_enemies;
    }
    float d = weapon_dmg( rti, 3.0f, 1, 1 ) * multiplier * ( multihit_signal ? 0.5f : 1.0f );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    float final_dmg = deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    d = weapon_dmg( rti, 1.75f, 1, 0 ) * multiplier * ( multihit_signal ? 0.5f : 1.0f );
    dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
    final_dmg += deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
    trigger_dots( rti, final_dmg, target_id );
    lprintf( ( "rampage 4/5th hit" ) );
}
DECL_SPELL( rampage ) {
    if ( MH_TYPE != WEAPON_2H ) return 0;
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( UP( rampage_cd ) ) return 0;
    if ( !UP( massacre_expire ) ) {
        if ( !power_check( rti, ( TALENT_CARNAGE ) ? 70.0f : 85.0f ) ) return 0;
        power_consume( rti, ( TALENT_CARNAGE ) ? 70.0f : 85.0f );
    } else {
#if (TALENT_MASSACRE)
        massacre_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_massacre_expire, 0 );
#endif
    }
    gcd_start( rti, FROM_SECONDS( min( 1.5f, 2.0f / ( 1.0f + rti->player.stat.haste ) ) ), 0 );
    eq_enqueue( rti, rti->timestamp, routnum_rampage_cast_1, rti->player.target );
    rampage_cd = TIME_OFFSET( FROM_SECONDS( 1.5f ) );
    if ( UP( meat_cleaver_expire ) ) {
        k32u c = 0;
        for( int i = 0; c < 4 && i < num_enemies; i++ ) {
            if ( i == rti->player.target ) continue;
            c++;
            // we need to transfer some extra info to event routine ( here to decrease rampage damage to its half ).
            // dirty hack via manipulating target_id, not elegant, but space efficient.
            eq_enqueue( rti, rti->timestamp, routnum_rampage_cast_1, rti->player.target + num_enemies );
        }
        meat_cleaver_expire = rti->timestamp;
        eq_enqueue( rti, rti->timestamp, routnum_meat_cleaver_expire, 0 );
    }
    trigger_offensive_abilities( rti );
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
    for( int i = 0; i < num_enemies; i++ ) {
        float d = weapon_dmg( rti, 0.48f, 1, 0 ) * multiplier;
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        float final_dmg = deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 1 ) * multiplier;
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 0 ) * multiplier;
        dice = round_table_dice2( rti, i, ATYPE_YELLOW_MELEE, 0 ); // dice without procs.
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 1 ) * multiplier;
        dice = round_table_dice2( rti, i, ATYPE_YELLOW_MELEE, 0 ); // dice without procs.
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 0 ) * multiplier;
        dice = round_table_dice2( rti, i, ATYPE_YELLOW_MELEE, 0 ); // dice without procs.
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 0.48f, 1, 1 ) * multiplier;
        dice = round_table_dice2( rti, i, ATYPE_YELLOW_MELEE, 0 ); // dice without procs.
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        trigger_dots( rti, final_dmg, i );
        lprintf( ( "whirlwind hit @tar%d", i ) );
    }
    eq_enqueue( rti, rti->timestamp, routnum_meat_cleaver_trigger, 0 );
}
DECL_SPELL( whirlwind ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_whirlwind_cast, rti->player.target );
    trigger_offensive_abilities( rti );
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
    wrecking_ball_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
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
    massacre_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
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
        float d = weapon_dmg( rti, 1.45f, 1, 0 );
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        float final_dmg = deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        d = weapon_dmg( rti, 1.45f, 1, 1 );
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        final_dmg += deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 0 );
        trigger_dots( rti, final_dmg, i );
        lprintf( ( "bladestorm tick @tar%d", i ) );
    }
}
#endif

// === bloodbath ==============================================================
#if (TALENT_BLOODBATH)
DECL_EVENT( bloodbath_tick ) {
    if ( rti->enemy[target_id].spec->bloodbath.ticks < 1.0f ) return;
    if ( rti->enemy[target_id].spec->bloodbath.dot_start + FROM_SECONDS( 8.0f - 2.0f * rti->enemy[target_id].spec->bloodbath.ticks ) != rti->timestamp ) return;
    float dmg = rti->enemy[target_id].spec->bloodbath.pool / rti->enemy[target_id].spec->bloodbath.ticks;
    rti->enemy[target_id].spec->bloodbath.pool -= dmg;
    deal_damage( rti, target_id, dmg, DTYPE_DIRECT, DICE_HIT, 0, 0 );
    lprintf( ( "bloodbath ticks" ) );
    rti->enemy[target_id].spec->bloodbath.ticks -= 1.0f;
    if ( rti->enemy[target_id].spec->bloodbath.ticks >= 1.0f )
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 2 ) ), routnum_bloodbath_tick, target_id );
}
void trigger_bloodbath( rtinfo_t* rti, float dmg, k32u target_id ) {
    rti->enemy[target_id].spec->bloodbath.pool += dmg * 0.4f;
    if ( rti->enemy[target_id].spec->bloodbath.ticks < 1.0f ) {
        rti->enemy[target_id].spec->bloodbath.dot_start = rti->timestamp;
        rti->enemy[target_id].spec->bloodbath.ticks = 3.0f;
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 2 ) ), routnum_bloodbath_tick, target_id );
        lprintf( ( "bloodbath apply @tar%d", target_id ) );
    } else {
        float new_ticks = 3.0f - rti->enemy[target_id].spec->bloodbath.ticks;
        rti->enemy[target_id].spec->bloodbath.ticks = 3.0f;
        rti->enemy[target_id].spec->bloodbath.dot_start += FROM_SECONDS( new_ticks * 2 );
        lprintf( ( "bloodbath @tar%d extends", target_id ) );
    }
}
DECL_EVENT( bloodbath_expire ) {
    lprintf( ( "bloodbath expire" ) );
}
DECL_EVENT( bloodbath_start ) {
    lprintf( ( "bloodbath start" ) );
}
DECL_SPELL( bloodbath ) {
    if ( bloodbath_cd > rti->timestamp ) return 0;
    bloodbath_expire = TIME_OFFSET( FROM_SECONDS( 8 ) );
    eq_enqueue( rti, bloodbath_expire, routnum_bloodbath_expire, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_bloodbath_start, 0 );
    bloodbath_cd = TIME_OFFSET( FROM_SECONDS( 30 ) );
    return 1;
}
#else
DECL_SPELL( bloodbath ) {
    return 0;
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
    frenzy_expire = TIME_OFFSET( FROM_SECONDS( 10 ) );
    eq_enqueue( rti, frenzy_expire, routnum_frenzy_expire, 0 );
    frenzy_stack = min( 3, ( int )frenzy_stack + 1 );
    lprintf( ( "frenzy stack %d", frenzy_stack ) );
}
#endif

// === dragon roar ============================================================
#if (TALENT_DRAGON_ROAR)
DECL_EVENT( dragon_roar_cast ) {
    for ( int i = 0; i < num_enemies; i++ ) {
        float d = ap_dmg( rti, 1.50f );
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 1 );
        float final_dmg = deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0, 1 );
        trigger_dots( rti, final_dmg, i );
    }
    dragon_roar_expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
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
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_dragon_roar_cast, 0 );
    dragon_roar_cd = TIME_OFFSET( FROM_SECONDS( 25 ) );
    lprintf( ( "cast dragon_roar" ) );
    trigger_offensive_abilities( rti );
    return 1;
}
#else
DECL_SPELL( dragon_roar ) {
    return 0;
}
#endif

// === odyns fury =============================================================
#if (ATRAIT_ODYNS_FURY)
DECL_EVENT( odyns_fury_cast ) {
    for( int i = 0; i < num_enemies; i++ ) {
        float d = weapon_dmg( rti, 2.50f, 1, 0 );
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        float final_dmg = deal_damage( rti, i, d, DTYPE_FIRE, dice, 0, 0 );
        d = weapon_dmg( rti, 2.50f, 1, 1 );
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        final_dmg += deal_damage( rti, i, d, DTYPE_FIRE, dice, 0, 0 );
        trigger_dots( rti, final_dmg, i );
        odyns_fury_expire( i ) = TIME_OFFSET( FROM_SECONDS( 4 ) );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_odyns_fury_tick, i );
    }
    lprintf( ( "odyns_fury hit/trigger" ) );
}
DECL_EVENT( odyns_fury_tick ) {
    if ( rti->timestamp <= odyns_fury_expire( target_id ) ) {
        float d = ap_dmg( rti, 1.0f );
        k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
        float final_dmg = deal_damage( rti, target_id, d, DTYPE_FIRE, dice, 0, 0 );
        trigger_dots( rti, final_dmg, target_id );
        if ( TIME_OFFSET( FROM_SECONDS( 1 ) ) <= odyns_fury_expire( target_id ) )
            eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_odyns_fury_tick, target_id );
        lprintf( ( "odyns_fury tick" ) );
    }
}
DECL_SPELL( odyns_fury ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( odyns_fury_cd > rti->timestamp ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_odyns_fury_cast, 0 );
    odyns_fury_cd = TIME_OFFSET( FROM_SECONDS( 45 ) );
    lprintf( ( "cast odyns_fury" ) );
    trigger_offensive_abilities( rti );
    return 1;
}
#else
DECL_SPELL( odyns_fury ) {
    return 0;
}
#endif

// === juggernaut =============================================================
#if (ATRAIT_JUGGERNAUT)
DECL_EVENT( juggernaut_expire ) {
    if ( juggernaut_expire == rti->timestamp ) {
        juggernaut_stack = 0;
        lprintf( ( "juggernaut expire" ) );
    }
}
DECL_EVENT( juggernaut_trigger ) {
    juggernaut_expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    eq_enqueue( rti, juggernaut_expire, routnum_juggernaut_expire, 0 );
    juggernaut_stack = min( 99, ( int )juggernaut_stack + 1 );
    lprintf( ( "juggernaut stack %d", juggernaut_stack ) );
}
#endif

// === odyns champion =========================================================
#if (ATRAIT_ODYNS_CHAMPION)
DECL_EVENT( odyns_champion_expire ) {
    if ( odyns_champion_expire == rti->timestamp ) {
        lprintf( ( "odyns_champion expire" ) );
    }
}
DECL_EVENT( odyns_champion_trigger ) {
    odyns_champion_expire = TIME_OFFSET( FROM_SECONDS( 6 ) );
    eq_enqueue( rti, odyns_champion_expire, routnum_odyns_champion_expire, 0 );
    lprintf( ( "odyns_champion trigger" ) );
}
#endif

// === rage of the valarjar ===================================================
#if (ATRAIT_RAGE_OF_THE_VALARJAR)
DECL_EVENT( berserking__expire ) {
    if ( berserking__expire == rti->timestamp ) {
        berserking__stack = 0;
        refresh_crit( rti );
        lprintf( ( "berserking_ expire" ) );
    }
}
DECL_EVENT( berserking__trigger ) {
    berserking__expire = TIME_OFFSET( FROM_SECONDS( 3 ) );
    eq_enqueue( rti, berserking__expire, routnum_berserking__expire, 0 );
    berserking__stack = min( 12, ( int )berserking__stack + 1 );
    refresh_crit( rti );
    lprintf( ( "berserking_ stack %d", berserking__stack ) );
}
DECL_EVENT( berserking_driver_tick ) {
    if ( rti->timestamp <= berserking_driver_expire ) {
        eq_enqueue( rti, rti->timestamp, routnum_berserking__trigger, 0 );
        if ( TIME_OFFSET( FROM_SECONDS( 1 ) ) <= berserking_driver_expire )
            eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_berserking_driver_tick, 0 );
        lprintf( ( "berserking_driver tick" ) );
    }
}
DECL_EVENT( berserking_driver_trigger ) {
    berserking_driver_expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1 ) ), routnum_berserking_driver_tick, 0 );
    lprintf( ( "rage of the valarjar trigger" ) );
}
#endif

// === sense death ============================================================
#if (ATRAIT_SENSE_DEATH)
DECL_EVENT( sense_death_expire ) {
    if ( sense_death_expire == rti->timestamp ) {
        lprintf( ( "sense_death expire" ) );
    }
}
DECL_EVENT( sense_death_trigger ) {
    sense_death_expire = TIME_OFFSET( FROM_SECONDS( 12 ) );
    eq_enqueue( rti, sense_death_expire, routnum_sense_death_expire, 0 );
    lprintf( ( "sense_death trigger" ) );
}
#endif

void trigger_offensive_abilities( rtinfo_t* rti ) {
    if ( UP( odyns_champion_expire ) ) {
        battle_cry_cd     = AHEAD( battle_cry_cd    , FROM_SECONDS( 2 ) );
        berserker_rage_cd = AHEAD( berserker_rage_cd, FROM_SECONDS( 2 ) );
        heroic_leap_cd    = AHEAD( heroic_leap_cd   , FROM_SECONDS( 2 ) );
#if (TALENT_SHOCKWAVE)
        shockwave_cd      = AHEAD( shockwave_cd     , FROM_SECONDS( 2 ) );
#endif
#if (TALENT_STORM_BOLT)
        storm_bolt_cd     = AHEAD( storm_bolt_cd    , FROM_SECONDS( 2 ) );
#endif
#if (TALENT_AVATAR)
        avatar_cd         = AHEAD( avatar_cd        , FROM_SECONDS( 2 ) );
#endif
#if (TALENT_BLADESTORM)
        bladestorm_cd     = AHEAD( bladestorm_cd    , FROM_SECONDS( 2 ) );
#endif
        bloodthirst_cd    = AHEAD( bloodthirst_cd   , FROM_SECONDS( 2 ) );
        rampage_cd        = AHEAD( rampage_cd       , FROM_SECONDS( 2 ) );
#if (TALENT_BLOODBATH)
        bloodbath_cd      = AHEAD( bloodbath_cd     , FROM_SECONDS( 2 ) );
#endif
#if (TALENT_INNER_RAGE)
        raging_blow_cd    = AHEAD( raging_blow_cd   , FROM_SECONDS( 2 ) );
#endif
#if (TALENT_DRAGON_ROAR)
        dragon_roar_cd    = AHEAD( dragon_roar_cd   , FROM_SECONDS( 2 ) );
#endif
#if (ATRAIT_ODYNS_FURY)
        odyns_fury_cd     = AHEAD( odyns_fury_cd    , FROM_SECONDS( 2 ) );
#endif
    }
}

void trigger_dots( rtinfo_t* rti, float dmg, k32u target_id ) {
#if (TALENT_BLOODBATH)
    if ( dmg <= 0.0f ) return;
    if ( UP( bloodbath_expire ) ) trigger_bloodbath( rti, dmg, target_id );
#endif
}

void spec_routine_entries( rtinfo_t* rti, _event_t e ) {
    switch( e.routine ) {
        HOOK_EVENT( auto_attack_mh );
        HOOK_EVENT( auto_attack_oh );
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
#if (TALENT_BLOODBATH)
        HOOK_EVENT( bloodbath_start );
        HOOK_EVENT( bloodbath_expire );
        HOOK_EVENT( bloodbath_tick );
#endif
#if (TALENT_FRENZY)
        HOOK_EVENT( frenzy_trigger );
        HOOK_EVENT( frenzy_expire );
#endif
#if (TALENT_DRAGON_ROAR)
        HOOK_EVENT( dragon_roar_cast );
        HOOK_EVENT( dragon_roar_expire );
#endif
#if (ATRAIT_ODYNS_FURY)
        HOOK_EVENT( odyns_fury_cast );
        HOOK_EVENT( odyns_fury_tick );
#endif
#if (ATRAIT_JUGGERNAUT)
        HOOK_EVENT( juggernaut_expire );
        HOOK_EVENT( juggernaut_trigger );
#endif
#if (ATRAIT_ODYNS_CHAMPION)
        HOOK_EVENT( odyns_champion_expire );
        HOOK_EVENT( odyns_champion_trigger );
#endif
#if (ATRAIT_RAGE_OF_THE_VALARJAR)
        HOOK_EVENT( berserking_driver_trigger );
        HOOK_EVENT( berserking_driver_tick );
        HOOK_EVENT( berserking__trigger );
        HOOK_EVENT( berserking__expire );
#endif
#if (ATRAIT_SENSE_DEATH)
        HOOK_EVENT( sense_death_trigger );
        HOOK_EVENT( sense_death_expire );
#endif
    default:
        lprintf( ( "wild spec routine entry %d, last defined routnum %d", e.routine, START_OF_WILD_ROUTNUM - 1 ) );
        assert( 0 );
    }
}

void spec_module_init( rtinfo_t* rti ) {
    power_gain( rti, 15.0f + atrait_uncontrolled_rage_lut[ATRAIT_UNCONTROLLED_RAGE] ); // charge!
    eq_enqueue( rti, rti->timestamp, routnum_auto_attack_mh, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( SYNC_MELEE ? 0 : 0.5 ) ), routnum_auto_attack_oh, 0 );
#if (TALENT_WRECKING_BALL)
    initialize_rppm( rti->player.spec->wrecking_ball.proc );
#endif
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    if ( DICE_MISS != dice && ( ATYPE_WHITE_MELEE == attacktype || ATYPE_YELLOW_MELEE == attacktype ) ) {
#if (TALENT_WRECKING_BALL)
        proc_RPPM( rti, &rti->player.spec->wrecking_ball.proc, 3.0f * ( 1.0f + rti->player.stat.haste ), routnum_wrecking_ball_trigger, target_id );
#endif
    }
}
