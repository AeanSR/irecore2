//
//  frost_dk.c
//
//
//  Created by Tianjian Guo on 4/6/16.
//
//

struct spec_state_t {
    struct {
        time_t cd;
    } empower_rune_weapon;
#define empower_rune_weapon_cd  (rti->player.spec->empower_rune_weapon.cd)
//==================================================================================
    struct {
        time_t cd;
        time_t expire;
    } pillar_of_frost;
#define pillar_of_frost_cd  (rti->player.spec->pillar_of_frost.cd)
#define pillar_of_frost_expire (rti->player.spec->pillar_of_frost.expire)
//==================================================================================
    struct {
        time_t cd;
        time_t expire;
        k32u stack;
    } remorseless_winter;
#define remorseless_winter_cd (rti->player.spec->remorseless_winter.cd)//9*24% dmg for  secs
#define remorseless_winter_expire (rti->player.spec->remorseless_winter.expire)
#define remorseless_winter_stack (rti->player.spec->remorseless_winter.stack)
//==================================================================================
#if (TALENT_HORN_OF_WINTER)
    struct {
        time_t cd;
    } horn_of_winter;
#define horn_of_winter_cd (rti->player.spec->horn_of_winter.cd)
#else
#define horn_of_winter_cd (0)
#endif
//==================================================================================
#if (TALENT_ICY_TALONS)
    struct {
        time_t expire;
        k32u stack;
    } icy_talons;
#define icy_talons_expire (rti->player.spec->icy_talons.expire)
#define icy_talons_stack (rti->player.spec->icy_talons.stack)
#else
#define icy_talons_expire (0)
#define icy_talons_stack (0)
#endif
//==================================================================================
#if (TALENT_HUNGERING_RUNE_WEAPON)
    struct {
        time_t expire;
    } hungering_rune_weapon;
#define hungering_rune_weapon_cd (empower_rune_weapon_cd)
#define hungering_rune_weapon_expire (rti->player.spec->hungering_rune_weapon.expire)
#else
#define hungering_rune_weapon_cd (empower_rune_weapon_cd)
#define hungering_rune_weapon_expire (0)
#endif
//==================================================================================
#if (TALENT_OBLITERATION)
    struct {
        time_t cd;
        time_t expire;
    } obliteration;
#define obliteration_cd (rti->player.spec->obliteration.cd)
#define obliteration_expire (rti->player.spec->obliteration.expire)
#else
#define obliteration_cd (0)
#define obliteration_expire (0)
#endif
//==================================================================================
#if(TALENT_BREATH_OF_SINDRAGOSA)
    struct {
        time_t cd;
        k32u duration;
    } breath_of_sindragosa;
#define breath_of_sindragosa_cd (rti->player.spec->breath_of_sindragosa.cd)
#define breath_of_sindragosa_duration (rti->player.spec->breath_of_sindragosa.duration)
#else
#define breath_of_sindragosa_cd (0)
#define breath_of_sindragosa_duration (0)
#endif
//==================================================================================
#if (TALENT_GLACIAL_ADVANCE)
    struct {
        time_t cd;
    } glacial_advance;
#define glacial_advance_cd (rti->player.spec->glacial_advance.cd)
#else
#define glacial_advance_cd (0)
#endif
//==================================================================================
    struct {
        time_t expire;
        RPPM_t proc;
    } killing_machine;
#define killing_machine_expire (rti->player.spec->killing_machine.expire)
//==================================================================================
    struct {
        time_t expire;
    } rime;
#define rime_expire (rti->player.spec->rime.expire)
//=================================================================================
#if (t18_2pc)
    struct {
        time_t expire;
    } t18obliteration;
#define t18obliteration_expire (rti->player.spec->t18obliteration.expire)
    struct {
        time_t expire;
    } t18frozen_wake;
#define t18frozen_wake_expire (rti->player.spec->t18frozen_wake.expire)
#else
#define t18obliteration_expire (0)
#define t18frozen_wake_expire (0)
#endif
//==================================================================================
};
struct spec_debuff_t {
//==================================================================================
    struct {
        time_t expire;
    } frost_fever;
#define frost_fever_expire(target) (rti->enemy[target].spec->frost_fever.expire)
//==================================================================================
    struct {
        time_t expire;
        k32u stack;
    } razorice;
#define razorice_expire(target) (rti->enemy[target].spec->razorice.expire)
#define razorice_stack(target) (rti->enemy[target].spec->razorice.stack)
};
//Skills=======================================================================
enum {
    END_OF_CLASS_ROUTNUM = START_OF_SPEC_ROUTNUM - 1,
    routnum_auto_attack_mh,
    routnum_auto_attack_oh,
    routnum_frost_strike_cast,
    routnum_obliterate_cast,
    routnum_howling_blast_cast,
    routnum_frost_fever_cast,
    routnum_frost_fever_tick,
    routnum_killing_machine_expire,
    routnum_killing_machine_trigger,
    routnum_rime_expire,
    routnum_rime_trigger,
    routnum_remorseless_winter_cd,
    routnum_remorseless_winter_cast,
    routnum_remorseless_winter_tick,
    routnum_remorseless_winter_expire,
    routnum_pillar_of_frost_cd,
    routnum_pillar_of_frost_cast,
    routnum_pillar_of_frost_expire,
#if !(TALENT_HUNGERING_RUNE_WEAPON)
    routnum_empower_rune_weapon_cd,
    routnum_empower_rune_weapon_cast,
#endif
#if(TALENT_ICY_TALONS)
    routnum_icy_talons_expire,
    routnum_icy_talons_trigger,
#endif
#if(TALENT_HORN_OF_WINTER)
    routnum_horn_of_winter_cd,
    routnum_horn_of_winter_cast,
#endif
#if(TALENT_HUNGERING_RUNE_WEAPON)
    routnum_hungering_rune_weapon_cd,
    routnum_hungering_rune_weapon_cast,
    routnum_hungering_rune_weapon_tick,
    routnum_hungering_rune_weapon_expire,
#endif
#if(TALENT_FROSTSCYTHE)
    routnum_frostscythe_cast,
#endif
#if(TALENT_OBLITERATION)
    routnum_obliteration_cd,
    routnum_obliteration_expire,
#endif
#if(TALENT_BREATH_OF_SINDRAGOSA)
    routnum_breath_of_sindragosa_cd,
    routnum_breath_of_sindragosa_cast,
    routnum_breath_of_sindragosa_tick,
    routnum_breath_of_sindragosa_expire,
#endif
#if(TALENT_GLACIAL_ADVANCE)
    routnum_glacial_advance_cd,
    routnum_glacial_advance_cast,
#endif
#if(t18_2pc)
    routnum_t18obliteration_cast,
    routnum_t18obliteration_expire,
    routnum_t18frozen_wake_cast,
    routnum_t18frozen_wake_expire,
#endif
#if(razorice_mh || razorice_oh)
    routnum_razorice_expire,
#endif
    START_OF_WILD_ROUTNUM,
};
//Stat&Uitility=====================================================================
float spec_str_coefficient( rtinfo_t* rti ) {
    float coeff = 1.0f;
    if ( UP( pillar_of_frost_expire ) ) coeff *= 1.20f;
    return coeff;
}
float spec_mastery_coefficient( rtinfo_t* rti ) {
    return 1.5f;
}
float spec_mastery_increament( rtinfo_t* rti ) {
    return 0.0f;
}
float spec_crit_increament( rtinfo_t* rti ) {
    return 0.0f;
}
float spec_haste_coefficient( rtinfo_t* rti ) {
    return 1.0f; //TODO: some passives
}
float spec_haste_increament( rtinfo_t* rti ) {
    if( UP( t18obliteration_expire ) )
        return 0.03f;
    else
        return 0.0f;
}

float spec_power_gain( rtinfo_t* rti, float power ) {
    //TODO: upper limit of 100, power_max not defined?
    return power;
}
float spec_power_check( rtinfo_t* rti, float cost ) {
    return cost;
}
float spec_power_consume( rtinfo_t* rti, float cost ) {
    //runic empowerment implementation
    if( uni_rng( rti ) < ( cost / 100 ) )
    {
        rune_reactive( rti );
    }
    return cost;//TODO: check if runic empowerment works this way
}
float spec_rune_charge_rate( rtinfo_t* rti ) {
    return 1.0f;
}
void spec_rune_consume( rtinfo_t* rti, k32u count )
{
    //gathering storm implementation
#if(TALENT_GATHERING_STORM)
    if( UP( remorseless_winter_expire ) )
    {
        remorseless_winter_expire += FROM_SECONDS( count * 0.5f );
        eq_enqueue( rti, remorseless_winter_expire, routnum_remorseless_winter_expire, 0 );
        remorseless_winter_stack += count;
        lprintf( ( "gthering storm triggered" ) );
    }
#endif
}
k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    k32u dice = round_table_dice2( rti, target_id, attacktype, extra_crit_rate );
    special_procs( rti, attacktype, dice, target_id );
    return dice;
}

k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate;
    if ( ATYPE_WHITE_MELEE == attacktype ) {
        cr += 0.19f;
        if ( c < 0.19f ) return DICE_MISS;
    }
    if ( c < cr ) {
        return DICE_CRIT;
    }
    return DICE_HIT;
}
float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor ) {
    if ( DICE_MISS == dice ) return .0f;
    if ( DTYPE_DIRECT == dmgtype ) {
        lprintf( ( "damage %.0f", dmg ) );
        rti->damage_collected += dmg;
        return dmg;
    }
    float cdb;
    if( UP( t18frozen_wake_expire ) )
    {
        cdb = ( 1.0f + extra_crit_bonus + 0.06 ) * 2.0f;
    }
    else
    {
        cdb = ( 1.0f + extra_crit_bonus ) * 2.0f;
    }
    dmg *= 1.0f + rti->player.stat.vers;
    if ( UP( thorasus_the_stone_heart_of_draenor_expire ) )         dmg *= 1.0f + legendary_ring * 0.0001f;
    if ( ENEMY_IS_DEMONIC && UP( gronntooth_war_horn_expire ) )      dmg *= 1.1f;
    if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )                cdb *= 1.02f;
    if ( DTYPE_PHYSICAL == dmgtype ) {
        if ( !ignore_armor )                                        dmg *= 0.594043f; // 0.680228f @110lvl
    }
    if ( DICE_CRIT == dice )                                        dmg *= cdb;
    if( DTYPE_FROST == dmgtype )                                      dmg *= ( 1.0f + rti->player.stat.mastery ); //added mastery
    if( rti->enemy[target_id].spec->razorice.stack > 0 && DTYPE_FROST == dmgtype )
        dmg *= ( 1.0f + 0.02f * rti->enemy[target_id].spec->razorice.stack );
    //TODO: check on razorice later
    //TODO: extra damage
    rti->damage_collected += dmg;
    return dmg;
}
float weapon_dmg( rtinfo_t* rti, float weapon_multiplier, kbool normalized, kbool offhand ) {
    float dmg = ( float )weapon[offhand].low;
    dmg += uni_rng( rti ) * ( weapon[offhand].high - weapon[offhand].low );
    dmg += ( normalized ? normalized_weapon_speed[weapon[offhand].type] : weapon[offhand].speed ) * rti->player.stat.ap / 3.5f;
    dmg *= weapon_multiplier;
    if ( offhand ) dmg *=  0.5f;
    return dmg;
}
float ap_dmg( rtinfo_t* rti, float ap_multiplier ) {
    float dmg = ap_multiplier * rti->player.stat.ap;
    return dmg;
}
void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id )
{
    if( DICE_MISS != dice && ( ATYPE_WHITE_MELEE == attacktype ) )
    {
        proc_RPPM( rti, &rti->player.spec->killing_machine.proc, 6.0f/* * ( 1.0f + rti->player.stat.haste )*/, routnum_killing_machine_trigger, 0 );
    }
}

// === auto-attack ============================================================
DECL_EVENT( auto_attack_mh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 0 );
    k32u diceMH = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, diceMH, 0, 0 );
    if ( diceMH == DICE_MISS ) {
        /* Miss */
        lprintf( ( "mh miss" ) );
    } else {
        lprintf( ( "mh hit" ) );
    }
    //frozen pulse implementation
#if(TALENT_FROZEN_PULSE)
    if( !rune_check( rti, 1 ) )
    {
        for ( int i = 1; i < num_enemies; i++ )
        {
            float d = ap_dmg( rti, 0.72f ); //TODO: potential constant damage
            k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
            deal_damage( rti, i, d, DTYPE_FROST, dice, 0, 0 );
            lprintf( ( "frozen pulse aoe from mh hit @tar%d", i ) );
        }
    }
#endif
    float aspeed = ( 1.0f + rti->player.stat.haste );
#if(TALENT_ICY_TALONS)
    aspeed = aspeed * ( 1 + 0.12f * icy_talons_stack );
#endif
    //Avalanche implementation
#if(TALENT_AVALANCHE)
    if( diceMH == DICE_CRIT && UP( pillar_of_frost_cd ) )
    {
        float d = ap_dmg( rti, 0.75f );
        k32u dice = round_table_dice( rti, rti->player.target, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, rti->player.target, d, DTYPE_FROST, dice, 0, 0 );
        lprintf( ( "avalanche hit caused by mh crit" ) );
    }
#endif
    //runic attenuation implementation
#if(TALENT_RUNIC_ATTENUATION)
    power_gain( rti, 1 );
#endif
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[0].speed / aspeed ) ), routnum_auto_attack_mh, rti->player.target );
    //razorice implementation
#if(razorice_mh)
    {
        float dF = weapon_dmg( rti, 0.1f, 0, 0 );
        deal_damage( rti, target_id, dF, DTYPE_FROST, diceMH, 0, 0 );
        if( UP( razorice_expire( target_id ) ) )
        {
            if( razorice_stack( target_id ) < 5 )
            {
                razorice_stack( target_id ) += 1;
            }
            else
            {
                razorice_stack( target_id ) = 1;
            }
            razorice_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 20.0f ) );
            eq_enqueue( rti , razorice_expire( target_id ), routnum_razorice_expire, rti->player.target );
        }

    }
#endif
}
DECL_EVENT( auto_attack_oh ) {
    float d = weapon_dmg( rti, 1.0f, 0, 1 );
    k32u diceOH = round_table_dice( rti, rti->player.target, ATYPE_WHITE_MELEE, 0 );
    deal_damage( rti, rti->player.target, d, DTYPE_PHYSICAL, diceOH, 0, 0 );
    if ( diceOH == DICE_MISS ) {
        /* Miss */
        lprintf( ( "oh miss" ) );
    } else {
        lprintf( ( "oh hit" ) );
    }
    //frozen pulse implementation
#if(TALENT_FROZEN_PULSE)
    if( !rune_check( rti, 1 ) )
    {
        for ( int i = 1; i < num_enemies; i++ ) {
            float d = ap_dmg( rti, 0.72f );
            k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
            deal_damage( rti, i, d, DTYPE_FROST, dice, 0, 0 );
            lprintf( ( "frozen pulse aoe from oh hit @tar%d", i ) );
        }
    }
#endif
    float aspeed = ( 1.0f + rti->player.stat.haste );
    //#if(/*razorice blahblahblah*/)

    //#endif
    //icy talon implementation
#if(TALENT_ICY_TALONS)
    aspeed = aspeed * ( 1 + 0.1f * icy_talons_stack );
#endif
    //Avalanche implementation
#if(TALENT_AVALANCHE)
    if( diceOH == DICE_CRIT && UP( pillar_of_frost_cd ) )
    {
        float d = ap_dmg( rti, 1.0f );
        k32u dice = round_table_dice( rti, rti->player.target, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, rti->player.target, d, DTYPE_FROST, dice, 0, 0 );
        lprintf( ( "avalanche hit caused by oh crit" ) );
    }
#endif
    //runic attenuation implementation
#if(TALENT_RUNIC_ATTENUATION)
    power_gain( rti, 1 );
#endif
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / aspeed ) ), routnum_auto_attack_oh, rti->player.target );
    //razorice
#if(razorice_oh)
    {
        float dF = weapon_dmg( rti, 0.1f, 0, 1 );
        deal_damage( rti, rti->player.target, dF, DTYPE_FROST, diceOH, 0, 0 );
        if( UP( razorice_expire( target_id ) ) )
        {
            if( razorice_stack( target_id ) < 5 )
            {
                razorice_stack( target_id ) += 1;
            }
            else
            {
                razorice_stack( target_id ) = 1;
            }
            razorice_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 20.0f ) );
            eq_enqueue( rti , razorice_expire( target_id ), routnum_razorice_expire, rti->player.target );
        }

    }
#endif
}
// === Frost Strike ===========================================================
//TODO: change damage calculation
DECL_EVENT( frost_strike_cast ) {
    //shattering strikes implementation
#if(TALENT_SHATTERING_STRIKES)
    if( rti->enemy[target_id].spec->razorice.stack == 5 )
    {
        float d = weapon_dmg( rti, 2.65f, 1, 0 ) * 1.5;
        float dOH = weapon_dmg( rti, 2.65f, 1, 1 ) * 1.5;
        k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 ); //TODO: is this a spell
        deal_damage( rti, target_id, d, DTYPE_FROST, dice, 0, 0 );
        deal_damage( rti, target_id, dOH, DTYPE_FROST, dice, 0, 0 );
        rti->enemy[target_id].spec->razorice.stack = 0;//as of Jun 16 2016, on ptr Pre0Patch 7.03, frost strike does damage before consuming the stacks
        lprintf( ( "frost strike hit, consumed 5 stacks of razorice to increase damage by 50 percent" ) );
    }
#endif
    float d = weapon_dmg( rti, 2.25f, 1, 0 );
    float dOH = weapon_dmg( rti, 2.25f, 1, 1 );
    k32u dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 ); //TODO: is this a spell
    deal_damage( rti, target_id, d, DTYPE_FROST, dice, 0, 0 );
    deal_damage( rti, target_id, dOH, DTYPE_FROST, dice, 0, 0 );
    //icecap implementation
#if(TALENT_ICECAP)
    if( dice == DICE_CRIT )
    {
        time_t reduction = min( pillar_of_frost_cd, FROM_SECONDS( 1 ) );
        pillar_of_frost_cd -= reduction;
        eq_enqueue( rti, pillar_of_frost_cd, routnum_pillar_of_frost_cd, 0 );
        lprintf( ( "Icecap triggered by a frost strike crit" ) );
    }
#endif
    lprintf( ( "frost strike hit" ) );
    //obliteration implementation
#if(TALENT_OBLITERATION)
    if( UP( obliteration_expire ) )
    {
        eq_enqueue( rti, rti->timestamp, routnum_killing_machine_trigger, 0 );
        lprintf( ( "killing machine gained from using frost strike duing obliteration" ) );
    }
#endif
    //icy talon implementation
#if(TALENT_ICY_TALONS)
    eq_enqueue( rti, rti->timestamp, routnum_icy_talons_trigger, 0 );
#endif
#if(t18_2pc)
    if( dice == DICE_CRIT )
    {
        eq_enqueue( rti, rti->timestamp, routnum_t18frozen_wake_cast, 0 );
    }
#endif
}
DECL_SPELL( frost_strike ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, 25.0f ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    power_consume( rti, 25.0f );
    eq_enqueue( rti, rti->timestamp, routnum_frost_strike_cast, 0 );
    lprintf( ( "frost strike casted" ) );
    return 1;
}
// === Obliterate =============================================================
DECL_EVENT( obliterate_cast ) {
    float d = weapon_dmg( rti, 3.2f, 1, 0 );
    float dOH = weapon_dmg( rti, 3.2f, 1, 1 );
    k32u dice;
#if defined (trinket_reapers_harvest)
    {   //TODO find scale
        float dF = trinket_reapers_harvest * d / 10000;
        float dFOH = trinket_reapers_harvest * dOH / 10000;
    }
#endif
    //kiling machine implementation
    if( UP ( killing_machine_expire ) ) {
        dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 1.0f );
        deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
        deal_damage( rti, target_id, dOH, DTYPE_PHYSICAL, dice, 0, 0 );
#if defined (trinket_reapers_harvest)
        {
            deal_damage( rti, target_id, dF, DTYPE_FROST, dice, 0, 0 );
            deal_damage( rti, target_id, dFOH, DTYPE_FROST, dice, 0, 0 );
        }
#endif
        time_t tempSave = killing_machine_expire;
        killing_machine_expire = rti->timestamp;
#if (t18_4pc)
        if( .65 > uni_rng( rti ) )
        {
            killing_machine_expire = tempSave;
            lprintf( ( "killing machine buff consumed by obliterate, but not consumed due to t18" ) );
        }
#endif
        eq_enqueue( rti, killing_machine_expire, routnum_killing_machine_expire, 0 );
        lprintf( ( "killing machine buff consumed by obliterate, 100 percent crit chance" ) );
        //murderous efficiency implementation
#if(TALENT_MURDEROUS_EFFICIENCY)
        if( uni_rng( rti ) < 0.5f )
        {
            rune_reactive( rti );
            lprintf( ( "1 rune gained due to murderous efficiency" ) );
            //TODO: check if this is correct in terms of game mechanics and code
        }
#endif
    }
    else {
        dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, target_id, d, DTYPE_PHYSICAL, dice, 0, 0 );
        deal_damage( rti, target_id, dOH, DTYPE_PHYSICAL, dice, 0, 0 );
#if defined (trinket_reapers_harvest)
        {
            deal_damage( rti, target_id, dF, DTYPE_FROST, dice, 0, 0 );
            deal_damage( rti, target_id, dFOH, DTYPE_FROST, dice, 0, 0 );
        }
#endif
    }
    //icecap implementation
#if(TALENT_ICECAP)
    if( dice == DICE_CRIT )
    {
        time_t reduction = min( pillar_of_frost_cd, FROM_SECONDS( 1 ) );
        if( pillar_of_frost_cd - reduction > rti->timestamp ) {
            pillar_of_frost_cd -= reduction;
            eq_enqueue( rti, pillar_of_frost_cd, routnum_pillar_of_frost_cd, 0 );
            lprintf( ( "Icecap triggered by a obliterate crit, cd = %d", pillar_of_frost_cd ) );
        }
    }
#endif
    //rime implementation
    if( uni_rng( rti ) < 0.45f )
    {
        eq_enqueue( rti, rti->timestamp, routnum_rime_trigger, 0 );
        lprintf( ( "rime triggered" ) );
    }
    lprintf( ( "obliterate hit" ) );
#if(t18_2pc)
    if( dice == DICE_CRIT )
    {
        eq_enqueue( rti, rti->timestamp, routnum_t18obliteration_cast, 0 );
    }
#endif
}
DECL_SPELL( obliterate ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
#if(TALENT_OBLITERATION)
    if( UP( obliteration_expire ) )
    {
        if ( !rune_check( rti, 1 ) ) return 0;
        rune_consume( rti, 1 );
        lprintf( ( "only one rune is consumed as obliteration is active" ) );
    }
    else
    {
        if ( !rune_check( rti, 2 ) ) return 0;
        rune_consume( rti, 2 );
    }
#else
    if ( !rune_check( rti, 2 ) ) return 0;
    rune_consume( rti, 2 );
#endif
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );

    eq_enqueue( rti, rti->timestamp, routnum_obliterate_cast, 0 );
    lprintf( ( "obliterate casted" ) );
    return 1;
}
// === howling blast ==========================================================
DECL_EVENT( howling_blast_cast ) {
    float dMain = ap_dmg( rti, 0.50f );
    //freezing fog implementation
#if(TALENT_FREEZING_FOG)
    dMain *= 1.3f;
#endif
    if( UP( rime_expire ) )
    {
        dMain = dMain * 3.0f;
        rime_expire = rti->timestamp;
        eq_enqueue( rti, rime_expire, routnum_rime_expire, 0 );
        lprintf( ( "rime consumed, hella more damage" ) );
    }
    k32u dice = round_table_dice( rti, target_id, ATYPE_SPELL, 0 ); //TODO:is this a spell
    deal_damage( rti, target_id, dMain, DTYPE_FROST, dice, 0, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_frost_fever_cast, 0 );
    lprintf( ( "howling blast hit" ) );
    for ( int i = 1; i < num_enemies; i++ ) {
        float dAOE = 0.85f * dMain;
        k32u dice = round_table_dice( rti, i, ATYPE_SPELL, 0 );
        deal_damage( rti, i, dAOE, DTYPE_FROST, dice, 0, 0 );
        eq_enqueue( rti, rti->timestamp, routnum_frost_fever_cast, i );
        lprintf( ( "howling blast aoe hit @tar%d", i ) );
    }
}
DECL_SPELL( howling_blast ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 1 ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    if( !UP( rime_expire ) )
    {
        rune_consume( rti, 1 );
        lprintf( ( "no rune consumed as rime is up" ) );
    }
    eq_enqueue( rti, rti->timestamp, routnum_howling_blast_cast, 0 );
    lprintf( ( "howling blast casted" ) );
    return 1;
}
// === frost fever ============================================================
//TODO: is there a need to write a frost fever expire?
DECL_EVENT( frost_fever_tick ) {
    if( frost_fever_expire( target_id ) < rti->timestamp ) {
        lprintf( ( "frost fever expireed on tar %d", target_id ) );
        return;
    }
    float d = ap_dmg( rti, .55f );
    //freezing fog implementation
#if(TALENT_FREEZING_FOG)
    d *= 1.5f; // Comment by Aean: '*' or '*=' ?
#endif
    k32u dice = round_table_dice( rti, target_id, ATYPE_SPELL, 0 ); //TODO: does this proc trinks?Is disease a special atype?
    deal_damage( rti, target_id, d, DTYPE_FROST, dice, 0, 0 );
    power_gain( rti, 5 );
    lprintf( ( "frost fever tick on tar %d, grants the dk 5 runic power", target_id ) );
    if( TIME_DISTANT( frost_fever_expire( target_id ) ) >= FROM_SECONDS( 3 ) ) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS ( 3.0f ) ), routnum_frost_fever_tick, target_id );
    }
}
DECL_EVENT( frost_fever_cast ) {
    if ( UP( frost_fever_expire( target_id ) ) ) {
        if ( REMAIN( frost_fever_expire( target_id ) ) > FROM_SECONDS( .3f * 24 ) ) {
            frost_fever_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 1.3f * 24 ) );
        }
        else {
            frost_fever_expire( target_id ) += FROM_SECONDS( 24.0f );
        }
        lprintf( ( "frost_fever_expire extends to %f sec", TO_SECONDS( TIME_DISTANT( frost_fever_expire( target_id ) ) ) ) );
    }
    else {
        frost_fever_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 24.0f ) );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 3.0f ) ), routnum_frost_fever_tick, target_id );
        lprintf( ( "frost_fever start" ) );
    }
}
// === killing machine ========================================================
DECL_EVENT( killing_machine_expire ) {
    if ( killing_machine_expire == rti->timestamp ) {
        lprintf( ( "killing machine gone" ) );
    }
}
DECL_EVENT( killing_machine_trigger ) {
    killing_machine_expire = TIME_OFFSET( FROM_SECONDS( 10.0f ) );
    eq_enqueue( rti, killing_machine_expire, routnum_killing_machine_expire, 0 );
    lprintf( ( "killing machine buff gained" ) );
}
// === Rime ===================================================================
DECL_EVENT( rime_expire ) {
    if ( rime_expire == rti->timestamp ) {
        lprintf( ( "rime wasted" ) );
    }
}
DECL_EVENT( rime_trigger ) {
    rime_expire = TIME_OFFSET( FROM_SECONDS( 15.0f ) );
    eq_enqueue( rti, rime_expire, routnum_rime_expire, 0 );
    lprintf( ( "rime buff gained" ) );
}
// === remorseless winter =====================================================
DECL_SPELL( remorseless_winter ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 1 ) ) return 0;
    if ( remorseless_winter_cd > rti->timestamp ) return 0;
    rune_consume( rti, 1 );
    remorseless_winter_cd = TIME_OFFSET( FROM_SECONDS( 20.0f ) );
    eq_enqueue( rti, remorseless_winter_cd, routnum_remorseless_winter_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_remorseless_winter_cast, 0 );
    remorseless_winter_expire = TIME_OFFSET( FROM_SECONDS ( 8.0f ) );
    eq_enqueue( rti, remorseless_winter_expire, routnum_remorseless_winter_expire, 0 );
    lprintf( ( "remorseless winter casted" ) );
    return 1;
}
DECL_EVENT( remorseless_winter_cast ) {
    remorseless_winter_stack = 0;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 0.0f ) ), routnum_remorseless_winter_tick, 0 );

    lprintf( ( "remorseless winter starts" ) );
}
DECL_EVENT ( remorseless_winter_cd ) {
    if ( remorseless_winter_cd == rti->timestamp ) {
        lprintf( ( "remorseless winter cd" ) );
    }
}
DECL_EVENT( remorseless_winter_tick ) {
    if( remorseless_winter_expire < rti->timestamp ) return;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1.0f ) ), routnum_remorseless_winter_tick, 0 );
    for ( int i = 0; i < num_enemies; i++ ) {
        float d = ap_dmg( rti, .24f ) * ( 1 + ( remorseless_winter_stack * 0.1f ) );
        k32u dice = round_table_dice( rti, i, ATYPE_SPELL, 0 ); //TODO: does this proc trinks?
        deal_damage( rti, i, d, DTYPE_FROST, dice, 0, 0 );
        lprintf( ( "remorseless winter does damage to tar %d", i ) );
    }
}
DECL_EVENT( remorseless_winter_expire ) {
    if( remorseless_winter_expire == rti->timestamp )
        lprintf( ( "remorse winter expired" ) );
}
// === pillar of frost ========================================================
//totally not sure if this is correct // Comment by Aean: good job.
DECL_SPELL( pillar_of_frost ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( pillar_of_frost_cd > rti->timestamp ) return 0;
    pillar_of_frost_cd = TIME_OFFSET( FROM_SECONDS( 60.0f ) ); //TODO: check cd
    eq_enqueue( rti, pillar_of_frost_cd, routnum_pillar_of_frost_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_pillar_of_frost_cast, 0 );
    pillar_of_frost_expire = TIME_OFFSET( FROM_SECONDS ( 20.0f ) );
    eq_enqueue( rti, pillar_of_frost_expire, routnum_pillar_of_frost_expire, 0 );
    lprintf( ( "pillar of frost casted" ) );
    return 1;
}
DECL_EVENT( pillar_of_frost_cast ) {
    refresh_str( rti );
    refresh_ap( rti );
}
DECL_EVENT ( pillar_of_frost_expire )
{
    if( pillar_of_frost_expire == rti->timestamp )
    {
        refresh_str( rti );
        refresh_ap( rti );
        lprintf( ( "pillar of frost expired" ) );
    }
}
DECL_EVENT ( pillar_of_frost_cd ) {
    if ( pillar_of_frost_cd == rti->timestamp ) {
        lprintf( ( "pillar of frost cd" ) );
    }
}
// === empower rune weapon ====================================================
#if !(TALENT_HUNGERING_RUNE_WEAPON)
DECL_SPELL( empower_rune_weapon ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( empower_rune_weapon_cd > rti->timestamp ) return 0;
    empower_rune_weapon_cd = TIME_OFFSET( FROM_SECONDS( 180.0f ) ); //TODO: check cd
    eq_enqueue( rti, empower_rune_weapon_cd, routnum_empower_rune_weapon_cd, 0 );
    eq_enqueue( rti, rti->timestamp, routnum_empower_rune_weapon_cast, 0 );
    lprintf( ( "empower rune weapon casted" ) );
    return 1;
}
DECL_EVENT ( empower_rune_weapon_cd ) {
    if ( empower_rune_weapon_cd == rti->timestamp ) {
        lprintf( ( "empower rune weapon cd" ) );
    }
}
DECL_EVENT ( empower_rune_weapon_cast ) {
    rune_reactive_all( rti );
    power_gain( rti, 25 );
}
#else
DECL_SPELL( empower_rune_weapon ) {
    return 0;
}
#endif

// === icy talons =============================================================
#if (TALENT_ICY_TALONS)
DECL_EVENT ( icy_talons_expire ) {
    if ( icy_talons_expire == rti->timestamp ) {
        lprintf( ( "icy talon buff expired" ) );
        icy_talons_stack = 0;
    }
}
DECL_EVENT ( icy_talons_trigger ) {
    if ( icy_talons_stack < 3 )
    {
        icy_talons_stack++;
    }
    icy_talons_expire = TIME_OFFSET( FROM_SECONDS( 6.0f ) );
    eq_enqueue( rti, rime_expire, routnum_icy_talons_expire, 0 );
    lprintf( ( "icy talon buff gained, stack %d", icy_talons_stack ) );
}
#endif
// === horn of winter =========================================================
#if(TALENT_HORN_OF_WINTER)
DECL_SPELL( horn_of_winter ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( horn_of_winter_cd > rti->timestamp ) return 0;
    horn_of_winter_cd = TIME_OFFSET( FROM_SECONDS( 30.0f ) );
    eq_enqueue( rti, horn_of_winter_cd, routnum_horn_of_winter_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_horn_of_winter_cast, 0 );
    lprintf( ( "horn of winter casted" ) );
    return 1;
}
DECL_EVENT ( horn_of_winter_cd ) {
    if ( horn_of_winter_cd == rti->timestamp ) {
        lprintf( ( "horn of winter cd" ) );
    }
}
DECL_EVENT ( horn_of_winter_cast ) {
    power_gain( rti, 10 );
    rune_reactive( rti );
    rune_reactive( rti );
    //TODO: check if this is correct in terms of game mechanics and code
}
#else
DECL_SPELL( horn_of_winter ) {
    return 0;
}
#endif
// === hungering rune weapon ==================================================
#if(TALENT_HUNGERING_RUNE_WEAPON)
DECL_SPELL( hungering_rune_weapon ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( hungering_rune_weapon_cd > rti->timestamp ) return 0;
    hungering_rune_weapon_cd = TIME_OFFSET( FROM_SECONDS( 180.0f ) ); //TODO: check cd
    eq_enqueue( rti, hungering_rune_weapon_cd, routnum_hungering_rune_weapon_cd, 0 );
    hungering_rune_weapon_expire = TIME_OFFSET( FROM_SECONDS ( 12.0f ) );
    eq_enqueue( rti, hungering_rune_weapon_expire, routnum_hungering_rune_weapon_expire, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_hungering_rune_weapon_cast, 0 );
    lprintf( ( "hungering rune weapon casted" ) );
    return 1;
}
DECL_EVENT ( hungering_rune_weapon_cd ) {
    if ( hungering_rune_weapon_cd == rti->timestamp ) {
        lprintf( ( "hungering rune weapon cd" ) );
    }
}
DECL_EVENT ( hungering_rune_weapon_cast ) {
    eq_enqueue( rti, rti->timestamp, routnum_hungering_rune_weapon_tick, 0 ); //TODO: check if tick 6 or 7 times
}
DECL_EVENT ( hungering_rune_weapon_tick )
{
    if( hungering_rune_weapon_expire < rti->timestamp ) return;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1.5f ) ), routnum_hungering_rune_weapon_tick, 0 );
    rune_reactive( rti );
    power_gain( rti, 5 );
}
DECL_EVENT ( hungering_rune_weapon_expire ) {
    lprintf( ( "hungering rune weapon expired" ) );
}
#else
DECL_SPELL( hungering_rune_weapon ) {
    return 0;
}
#endif

// === frostscythe ============================================================
//TODO: is this only mainhand?
#if (TALENT_FROSTSCYTHE)
DECL_SPELL( frostscythe ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 1 ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_frostscythe_cast, 0 );
    lprintf( ( "frostscythe casted" ) );
    return 1;
}
DECL_EVENT ( frostscythe_cast ) {
    float d = weapon_dmg( rti, 1.2f, 1, 0 ) + weapon_dmg( rti, 1.2f, 1, 1 );
    k32u dice;
    //kiling machine implementation
    if( UP ( killing_machine_expire ) ) {
        lprintf( ( "killing machine buff consumed by frostscythe" ) );
        time_t tempSave = killing_machine_expire;
        killing_machine_expire = rti->timestamp;
#if (t18_4pc)
        if( .65 > uni_rng( rti ) )
        {
            killing_machine_expire = tempSave;
            lprintf( ( "killing machine buff consumed by frostscythe, but not consumed due to t18" ) );
        }
#endif
        dice = round_table_dice( rti, target_id, ATYPE_YELLOW_MELEE, 1.0f ); //TODO: melee or spell
        for ( int i = 0; i < num_enemies; i++ ) {
            deal_damage( rti, i, d, DTYPE_FROST, dice, 1.0f, 0 );
            eq_enqueue( rti, killing_machine_expire, routnum_killing_machine_expire, 0 );
            lprintf( ( "frostscythe hit tar %d", i ) );
        }
    }
    else {
        for ( int i = 0; i < num_enemies; i++ ) {
            dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
            deal_damage( rti, i, d, DTYPE_FROST, dice, 1.0f, 0 );
            lprintf( ( "frostscythe hit tar %d", i ) );
        }
    }
    //icecap implementation
#if(TALENT_ICECAP)
    if( dice == DICE_CRIT )
    {
        time_t reduction = min( pillar_of_frost_cd, FROM_SECONDS( 1 ) );
        pillar_of_frost_cd -= reduction;
        eq_enqueue( rti, pillar_of_frost_cd, routnum_pillar_of_frost_cd, 0 );
        lprintf( ( "Icecap triggered by a frostscythe crit" ) );
    }
#endif
    //murderous efficiency implementation
#if(TALENT_MURDEROUS_EFFICIENCY)
    if( uni_rng( rti ) < 0.5f )
    {
        rune_reactive( rti );
        //TODO: check if this is correct in terms of game mechanics and code
    }
#endif
}
#else
DECL_SPELL( frostscythe ) {
    return 0;
}
#endif
// === obliteration ===========================================================
#if (TALENT_OBLITERATION)
DECL_SPELL( obliteration ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( obliteration_cd > rti->timestamp ) return 0;
    obliteration_cd = TIME_OFFSET( FROM_SECONDS( 90.0f ) ); //TODO: check cd
    eq_enqueue( rti, obliteration_cd, routnum_obliteration_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    obliteration_expire = TIME_OFFSET( FROM_SECONDS ( 8.0f ) );
    eq_enqueue( rti, obliteration_expire, routnum_obliteration_expire, 0 );
    lprintf( ( "obliteration casted" ) );
    return 1;
}
DECL_EVENT( obliteration_expire ) {
    if( obliteration_expire == rti->timestamp )
    {
        lprintf( ( "obliteration expired" ) );
    }
}
DECL_EVENT ( obliteration_cd ) {
    if ( obliteration_cd == rti->timestamp ) {
        lprintf( ( "obliteration cd" ) );
    }
}
#else
DECL_SPELL( obliteration ) {
    return 0;
}
#endif
// === breath of sindragosa ===================================================
#if(TALENT_BREATH_OF_SINDRAGOSA)
DECL_SPELL( breath_of_sindragosa ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( breath_of_sindragosa_cd > rti->timestamp ) return 0;
    breath_of_sindragosa_cd = TIME_OFFSET( FROM_SECONDS( 120.0f ) );
    eq_enqueue( rti, breath_of_sindragosa_cd, routnum_breath_of_sindragosa_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_breath_of_sindragosa_cast, 0 );
    lprintf( ( "breath of sindragosa casted" ) );
    return 1;
}
DECL_EVENT( breath_of_sindragosa_cast ) {
    breath_of_sindragosa_duration = 0;
    for ( int i = 1; i < num_enemies; i++ ) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 0.0f ) ), routnum_breath_of_sindragosa_tick, i );
    }
    lprintf( ( "breath of sindragosa starts" ) );
}
DECL_EVENT ( breath_of_sindragosa_cd ) {
    if ( breath_of_sindragosa_cd == rti->timestamp ) {
        lprintf( ( "breath of sindragosa cd" ) );
    }
}
DECL_EVENT( breath_of_sindragosa_tick ) {
    if( !power_check( rti, 13 ) ) {
        eq_enqueue( rti, rti->timestamp, routnum_breath_of_sindragosa_expire, 0 );
        return;
    }
    breath_of_sindragosa_duration++;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 1.0f ) ), routnum_breath_of_sindragosa_tick, target_id );
    float d = ap_dmg( rti, 1.4f ); //TODO: potential constant damage
    k32u dice = round_table_dice( rti, target_id, ATYPE_SPELL, 0 );
    deal_damage( rti, target_id, d, DTYPE_FROST, dice, 0, 0 );
    for ( int i = 1; i < num_enemies; i++ ) {
        d = d / num_enemies; //TODO: check if correct
        dice = round_table_dice( rti, i, ATYPE_SPELL, 0 );
        deal_damage( rti, i, d, DTYPE_FROST, dice, 0, 0 );
    }
}
DECL_EVENT( breath_of_sindragosa_expire ) {
    breath_of_sindragosa_duration = 0;
    lprintf( ( "breath of sindragosa expired, dealth damage %d times", breath_of_sindragosa_duration ) );
}
#else
DECL_SPELL( breath_of_sindragosa ) {
    return 0;
}
#endif
// === galacial advance =======================================================
#if(TALENT_GLACIAL_ADVANCE)
DECL_SPELL( glacial_advance ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( glacial_advance_cd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 1 ) ) return 0;
    glacial_advance_cd = TIME_OFFSET( FROM_SECONDS( 15.0f ) ); //TODO: check cd
    eq_enqueue( rti, glacial_advance_cd, routnum_glacial_advance_cd, 0 );
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1 );
    eq_enqueue( rti, rti->timestamp, routnum_glacial_advance_cast, 0 );
    lprintf( ( "glacial advance casted" ) );
    return 1;
}
DECL_EVENT ( glacial_advance_cd ) {
    if ( glacial_advance_cd == rti->timestamp ) {
        lprintf( ( "glacial advance cd" ) );
    }
}
DECL_EVENT ( glacial_advance_cast ) {
    float d = ap_dmg( rti, 3.75f );
    for ( int i = 0; i < num_enemies; i++ ) {
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0.0f, 0 );
        dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, d, DTYPE_PHYSICAL, dice, 0.0f, 0 ); // Comment by Aean: why deal twice?
        lprintf( ( "glacial_advance hit @tar %d", i ) );
    }
}
#else
DECL_SPELL( glacial_advance ) {
    return 0;
}
#endif
//tire 18 two piece bonus
#if(t18_2pc)
DECL_EVENT ( t18obliteration_cast )
{
    t18obliteration_expire = TIME_OFFSET( FROM_SECONDS ( 12.0f ) );
    eq_enqueue( rti, t18obliteration_expire, routnum_t18obliteration_expire, 0 );
    lprintf( ( "Obliterate hit with a critical strike, gained the \"obliteration\" buff." ) );
    refresh_haste( rti );
}
DECL_EVENT ( t18obliteration_expire )
{
    if( t18obliteration_expire == rti->timestamp )
    {
        lprintf( ( "Obliteration buff expired(t18)" ) );
    }
    refresh_haste( rti );
}
DECL_EVENT ( t18frozen_wake_cast )
{
    t18frozen_wake_expire = TIME_OFFSET( FROM_SECONDS ( 12.0f ) );
    eq_enqueue( rti, t18obliteration_expire, routnum_t18frozen_wake_expire, 0 );
    lprintf( ( "Frost Strike hit with a critical strike, gained the \"frozen wake\" buff." ) );
}
DECL_EVENT ( t18frozen_wake_expire )
{
    if( t18obliteration_expire == rti->timestamp )
    {
        lprintf( ( "frozen wake buff expired(t18)" ) );
    }
}
#endif
//razorice
DECL_EVENT( razorice_expire )
{
    if( razorice_expire( target_id ) == rti->timestamp )
    {
        razorice_stack( target_id ) = 0;
    }
}
// === initilazation =========================================================================
void spec_routine_entries( rtinfo_t* rti, _event_t e ) {
    switch( e.routine ) {
        HOOK_EVENT( auto_attack_mh );
        HOOK_EVENT( auto_attack_oh );
        HOOK_EVENT( frost_strike_cast );
        HOOK_EVENT( obliterate_cast );
        HOOK_EVENT( howling_blast_cast );
        HOOK_EVENT( frost_fever_cast );
        HOOK_EVENT( frost_fever_tick );
        HOOK_EVENT( killing_machine_expire );
        HOOK_EVENT( killing_machine_trigger );
        HOOK_EVENT( rime_expire );
        HOOK_EVENT( rime_trigger );
        HOOK_EVENT( remorseless_winter_cd );
        HOOK_EVENT( remorseless_winter_cast );
        HOOK_EVENT( remorseless_winter_tick );
        HOOK_EVENT( remorseless_winter_expire );
        HOOK_EVENT( pillar_of_frost_cd );
        HOOK_EVENT( pillar_of_frost_cast );
        HOOK_EVENT( pillar_of_frost_expire );
#if !(TALENT_HUNGERING_RUNE_WEAPON)
        HOOK_EVENT( empower_rune_weapon_cd );
        HOOK_EVENT( empower_rune_weapon_cast );
#endif
#if(TALENT_ICY_TALONS)
        HOOK_EVENT( icy_talons_expire );
        HOOK_EVENT( icy_talons_trigger );
#endif
#if(TALENT_HORN_OF_WINTER)
        HOOK_EVENT( horn_of_winter_cd );
        HOOK_EVENT( horn_of_winter_cast );
#endif
#if(TALENT_HUNGERING_RUNE_WEAPON)
        HOOK_EVENT( hungering_rune_weapon_cd );
        HOOK_EVENT( hungering_rune_weapon_cast );
        HOOK_EVENT( hungering_rune_weapon_tick );
        HOOK_EVENT( hungering_rune_weapon_expire );
#endif
#if(TALENT_FROSTSCYTHE)
        HOOK_EVENT( frostscythe_cast );
#endif
#if(TALENT_OBLITERATION)
        HOOK_EVENT( obliteration_cd );
        HOOK_EVENT( obliteration_expire );
#endif
#if(TALENT_BREATH_OF_SINDRAGOSA)
        HOOK_EVENT( breath_of_sindragosa_cd );
        HOOK_EVENT( breath_of_sindragosa_cast );
        HOOK_EVENT( breath_of_sindragosa_tick );
        HOOK_EVENT( breath_of_sindragosa_expire );
#endif
#if(TALENT_GLACIAL_ADVANCE)
        HOOK_EVENT( glacial_advance_cd );
        HOOK_EVENT( glacial_advance_cast );
#endif
#if(t18_2pc)
        HOOK_EVENT( t18obliteration_cast );
        HOOK_EVENT( t18obliteration_expire );
        HOOK_EVENT( t18frozen_wake_cast );
        HOOK_EVENT( t18frozen_wake_expire );
#endif
#if(razorice_mh || razorice_oh)
        HOOK_EVENT( razorice_expire );
#endif
    default:
        lprintf( ( "wild spec routine entry %d, last defined routnum %d", e.routine, START_OF_WILD_ROUTNUM - 1 ) );
        assert( 0 );
    }
}
void spec_module_init( rtinfo_t* rti ) {
    eq_enqueue( rti, rti->timestamp, routnum_auto_attack_mh, 0 );
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( SYNC_MELEE ? 0 : 0.5 ) ), routnum_auto_attack_oh, 0 );
    initialize_rppm( rti->player.spec->killing_machine.proc );
}



