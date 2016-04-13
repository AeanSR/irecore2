//
//  frost_dk.c
//
//
//  Created by Tianjian Guo on 4/6/16.
//
//

struct spec_state_t{
    struct{
        time_t cd;
    }empower_rune_weapon;
    #define empower_rune_weapon_cd  (rti->player.spec->empower_rune_weapon.cd)
//==================================================================================
    struct{
        time_t cd;
    }pillar_of_frost;
    #define pillar_of_frost_cd  (rti->player.spec->pillar_of_frost.cd)
//==================================================================================
    struct{
        time_t cd;
    }remorseless_winter;
    #define remorseless_winter_cd (rti->player.spec->remorseless_winter.cd)
//==================================================================================
#if (TALENT_HORN_OF_WINTER)
    struct{
        time_t cd;
    }horn_of_winter;
    #define horn_of_winter_cd (rti->player.spec->horn_of_winter.cd)
#else
    #define horn_of_winter_cd (0)
#endif
//==================================================================================
#if (TALENT_HUNGERING_RUNE_WEAPON)
    struct{
        time_t cd;
        time_t expire;
    }hungering_rune_weapon;
    #define hungering_rune_weapon_cd (rti->player.spec->hungering_rune_weapon.cd)
    #define hungering_rune_weapon_expire (rti->player.spec->hungering_rune_weapon.expire)
#else
    #define hungering_rune_weapon_cd (0)
    #define hungering_rune_weapon_expire (0)
#endif
//==================================================================================
#if (TALENT_FROSTSCYTHE)
    struct{
        time_t cd;
    }frostscythe;
    #define frostscythe_cd (rti->player.spec->frostscythe.cd)
#else
    #define frostscythe_cd (0)
#endif
//==================================================================================
#if (TALENT_OBLITERATION)
    struct{
        time_t cd;
        time_t expire;
    }obliteration;
    #define obliteration_cd (rti->player.sepc->obliteration.cd)
    #define obliteration_expire (rti->player.sepc->obliteration.expire)
#else
    #define obliteration_cd (0)
    #define obliteration_expire (0)
#endif
//==================================================================================
#if(TALENT_BREATH_OF_SINDRAGOSA)
    struct{
        time_t cd;
    }breath_of_sindragosa;
    #define breath_of_sindragosa_cd (rti->player.spec->breath_of_sindragosa.cd)
#else
    #define breath_of_sindragosa_cd (0)
#endif
//==================================================================================
#if (TALENT_GLACIAL_ADVANCE)
    struct{
        time_t cd;
    }glacial_advance;
    #define glacial_advance_cd (rti->player.spec->glacial_advance.cd)
#else
    #define glacial_advance_cd (0)
#endif
};
struct class_debuff_t {
//==================================================================================
#if (TALENT_ICY_TALONS)
    struct{
        time_t expire;
    }icy_talons;
    #define icy_talons_expire (rti->player.spec->icy_talons.expire)
#else
    #define icy_talons_expire (0)
#endif
//==================================================================================
#if (TALENT_AVALANCHE)
    struct{
        time_t expire;
    }avalanche;
    #define avalanche_expire(target) (rti->enemy[target].spec->avalanche.expire)
#else
    #define avalanche_expire(target) (0)
#endif
};
struct class_debuff_t {
//==================================================================================
    struct{
        time_t expire;
    }frost_fever;
    #define frost_fever_expire(target) (rti->enemy[target].spec->frost_fever.expire)
//==================================================================================
    struct{
        time expire;
        
    }killing_machine;
    #define killing_machine_expire (rti->player.spec->killing_machine.expire)
//==================================================================================
    struct{
        time expire;
        RPPM_t, proc;
    }rime;
    #define rime_expire (rti->player.spec->rime.expire)
    #defube rime_
};
//Stat&Uitility=====================================================================
float spec_mastery_coefficient( rtinfo_t* rti ){
    return 1.0f; //TODO: find out the coefficient
}
float spec_mastery_increament( rtinfo_t* rti ){
    return 0.0f;
}
float spec_crit_increament( rtinfo_t* rti ){
    return 0.0f; //TODO: killing machine
}
float spec_haste_coefficient( rtinfo_t* rti ){
    return 0.0f; //TODO: some passives
}

float spec_power_gain( rtinfo_t* rti, float power ) {
    return power;
}
float spec_power_check( rtinfo_t* rti, float cost ) {
    return cost;
}
float spec_power_consume( rtinfo_t* rti, float cost ) {

    return cost;//TODO: add runic empowerment & runic corruption
}

k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    k32u dice = round_table_dice2( rti, target_id, attacktype, extra_crit_rate );
    special_procs( rti, attacktype, dice, target_id );
    return dice;
}

k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit - 0.03f + extra_crit_rate;
    if (ATYPE_WHITE_MELEE == attacktype){
        cr += 0.19f;
        if ( c < 0.19f ) return DICE_MISS;
    }

    //TODO: lots of stuff
    if ( c < cr ){
        return DICE_CRIT;
    }
    return DICE_HIT;
}
float deal_damage( rtinfo_t* rti, k32u target_id, float dmg, k32u dmgtype, k32u dice, float extra_crit_bonus, kbool ignore_armor){
    if ( DICE_MISS == dice ) return .0f;
    if ( DTYPE_DIRECT == dmgtype ){
        lprintf( ( "damage %.0f", dmg ) );
        rti->damage_collected += dmg;
        return dmg;
    }
    float cdb = ( 1.0f + extra_crit_bonus ) * 2.0f;
                                                                    dmg *= 1.0f + rti->player.stat.vers;
    if ( UP( thorasus_the_stone_heart_of_draenor_expire ) )         dmg *= 1.0f + legendary_ring * 0.0001f;
    if ( ENEMY_IS_DEMONIC && UP(gronntooth_war_horn_expire ) )      dmg *= 1.1f;
    if ( RACE == RACE_DWARF || RACE == RACE_TAUREN )                cdb *= 1.02f;
    if ( DTYPE_PHYSICAL == dmgtype ){
        if ( !ignore_armor )                                        dmg *= 0.650684f; // 0.680228f @110lvl
    }
    if ( DICE_CRIT == dice )                                        dmg *= cdb;

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
    if( DICE_MISS != dice && ( ATYPE_WHITE_MELEE == attacktype)
       {
           proc_RPPM( rti, &rti->player.spec->killing_machine.proc, 4.5f/* * ( 1.0f + rti->player.stat.haste )*/, routnum_killing_machine_trigger, 0 );
       }
    if( DICE_MISS != dice && ( ATYPE_WHITE_MELEE == attacktype)
       {
           
           //TODO : frozen pulse
       }
//Skills=======================================================================
enum {
    END_OF_COMMON_ROUTNUM = START_OF_CLASS_ROUTNUM - 1,
    routnum_auto_attack_mh,
    routnum_auto_attack_oh,
    routnum_frost_strike_cast,
    routnum_obliterate_cast,
    routnum_howling_blast_cast,
    routnum_frost_fever_tick,
    routnum_frost_fever_cast,
#if(TALENT_ICY_TALONS)
    routnum_icy_talons_expire,
#endif
    routnum_killing_machine_expire,
    routnum_killing_machine_trigger,
    START_OF_WILD_ROUTNUM
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
        lprintf( ( "mh hit" ) );
    }
    if(UP(icy_talons_expire))                    float aspeed = (1.0f + rti->player.stat.haste) * 1.25f;
    else                                         float aspeed = (1.0f + rti->player.stat.haste);
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
        lprintf( ( "oh hit" ) );
    }
    if(UP(icy_talons_expire))                    float aspeed = (1.0f + rti->player.stat.haste) * 1.25f;
    else                                         float aspeed = (1.0f + rti->player.stat.haste);

    if ( UP( enrage_expire ) ) aspeed *= 2.0f;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / aspeed ) ), routnum_auto_attack_oh, rti->player.target );
}
// === Frost Strike ===========================================================
DECL_EVENT( frost_stike_cast ) {
    float d = weapon_dmg(rti, 2.30f * (1.0f + rti->player.stat.mastery ), 1, 0);
#if(TALENT_SHATTERING_STRIKE)
    k32u dice = round_table_dice(rti, target_id, ATYPE_YELLOW_MELEE, 0.3f);
#else
    k32u dice = round_table_dice(rti, target_id, ATYPE_YELLOW_MELEE, 0;
#endif
    deal_damage(rti, target_id, d, DTYPE_FROST, dice, 0, 0);
    d = weapon_dmg(rti, 1.92f * (1.0f + rti->player.stat.mastery ), 1, 1);
    dice = round_table_dice(rti, target_id, ATYPE_YELLOW_MELEE, 0);
    deal_damage(rti, target_id, d, DTYPE_FROST, dice, 0, 0);
    lprintf( ( "frost strike hit" ) );
#if(TALENT_ICY_TALONS)
    eq_enqueue(rti, TIME_OFFSET( 3.0f), routnum_icy_talons_expire,0);
#endif
}
DECL_SPELL( frost_strike ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, 25.0f ) ) return 0
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1);//TODO: check if haste effects GCD
    power_consume(rti, 25.0f);
    eq_enqueue( rti, rti->timestamp, routnum_frost_strike_cast, 0);
    lprintf( ( "frost strike casted" ) );

}
// === icy talons =============================================================
DECL_EVENT( icy_talons_expire ) {
    if( UP (icy_talons_expire))
    {
        icy_talons_expire += FROM_SECONDS( 3.0f );
        lprintf( ( "icy_alons_expire extends to %f sec", TO_SECONDS( TIME_DISTANT( icy_talons_expire ) ) ) );
        eq_enqueue(rti, icy_talons_expire, routnum_icy_talons_expire, 0);
    }
    else
    {
        icy_talons_expire = TIME_OFFSET( 3.0f );
        lprintf( ( "gain icy talons buff" ) );
        eq_enqueue(rti, icy_talons_expire, routnum_icy_talons_expire, 0);
    }
}
// === Obliterate =============================================================
DECL_EVENT( obliterate_cast ) {
    float d = weapon_dmg(rti, 2.58f * (1.0f + rti->player.stat.mastery ), 1, 0);
    if( UP (killing_machine_expire)) {k32u dice = round_table_dice(rti, target_id, ATYPE_YELLOW_MELEE, 1.0f);
                                      killing_machine_expire = rti->timestamp;
                                      eq_enqueue(rti, killing_machine_expire, routnum_killing_machine_expire,0);}//TODO: murderous efficiency
    else                              k32u dice = round_table_dice(rti, target_id, ATYPE_YELLOW_MELEE, 0);
    deal_damage(rti, target_id, d, DTYPE_PHYSICAL, dice, 0,0);
    d = weapon_dmg(rti, 2.58f * (1.0f + rti->player.stat.mastery ), 1, 1);
    dice = round_table_dice(rti, target_id, ATYPE_YELLOW_MELEE, 0);
    deal_damage(rti, target_id, d, DTYPE_PHYSICAL, dice, 0,0);
    lprintf( ( "obliterate hit" ) );
    //Add killing machine
}
DECL_SPELL( obliterate ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 2 ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1);//TODO: check if haste effects GCD
    rune_consume(rti, 2);
    eq_enqueue( rti, rti->timestamp, routnum_obliterate_cast, 0);
    lprintf( ( "obliterate casted" ) );
}
// === howling blast ==========================================================
DECL_EVENT( howling_blast_cast ) {
    float dMain = ap_dmg(rti, 0.3852f);
#if(TALENT_FREEZING_FOG)
    dMain = dMain *2;
#endif
    k32u dice = round_table_dice(rti, target_id, ATYPE_YELLOW_MELEE, 0);
    deal_damage(rti, target_id, d, DTYPE_FROST, dice, 0,0);
    eq_enqueue(rti, rti->timestamp, routnum_frost_fever_cast, 0);
    lprintf( ( "howling blast hit" ) );
    for ( int i = 1; i < num_enemies; i++ ) {
        float dAOE = 0.8f * dMain;
        k32u dice = round_table_dice( rti, i, ATYPE_YELLOW_MELEE, 0 );
        deal_damage( rti, i, dAOE, DTYPE_FROST, dice, 0, 0 );
        eq_enqueue(rti, rti->timestamp, routnum_frost_fever_cast, i);
        lprintf( ( "howling blast aoe hit @tar%d", i ) );
    }
    //add Rime
}
DECL_SPELL( howling_blast ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 1 ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1);//TODO: check if haste effects GCD
    rune_consume(rti, 1);
    eq_enqueue( rti, rti->timestamp, routnum_howling_blast_cast, 0);
    lprintf( ( "howling blast casted" ) );
}
// === frost fever ============================================================
DECL_EVENT( frost_fever_tick ) {
    if(frost_fever_expire( target_id ) < rti->timestamp) return;
    float d = ap_dmg(rti, .473f);
    k32u dice = round_table_dice( rti, target_id, ATYPE_SPELL, 0)//TODO: does this proc trinks?
    deal_damage( rti, target_id, d, DTYPE_FROST, dice, 0, 0);
    lprintf(( "frost fever tick" ));
    if(TIME_DISTANT(frost_fever_expire( target_id)) >= FROM_SECONDS( 3)) {
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS ( 3 ) ), routnum_frost_fever_tick, target_id);
    }
}
DECL_EVENT( frost_fever_cast ) {
    if ( UP( frost_fever_expire( target_id ) ) ) {
        if (REMAIN( frost_fever_expire( target_id ) ) > FROM_SECONDS( .3f*24 )){
            frost_fever_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 1.3f*24 ) );
        } else {
            frost_fever_expire( target_id ) += FROM_SECONDS( 24 );
        }
        lprintf( ( "frost_fever_expire extends to %f sec", TO_SECONDS( TIME_DISTANT( frost_fever_expire( target_id ) ) ) ) );
    } else {
        frost_fever_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 24 ) );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 3 ) ), routnum_frost_fever_tick, target_id );
        lprintf( ( "frost_fever start" ) );
    }
}
// === killing machine =======================================================
DECL_EVENT( killing_machine_expire ) {
    if ( killing_machine_expire == rti->timestamp ) {
        lprintf( ( "smackthat expire" ) );
    }
}
DECL_EVENT( killing_machine_trigger ) {
    killing_machine_expire = TIME_OFFSET( FROM_SECONDS(10.0f));
    eq_enqueue(rti,killing_machine_expire,routnum_killing_machine_expire,0);
}

                                 
                                 
