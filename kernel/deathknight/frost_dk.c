//
//  frost_dk.c
//  
//
//  Created by Tianjian Guo on 4/6/16.
//
//

struct spec_state_t{
//==================================================================================
    struct {
    } frost_strike;
//==================================================================================
    struct {
    }howling_blast;
//==================================================================================
    struct{
    }obliterate;
//==================================================================================
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
    }rime;
    #define rime_expire (rti->player.spec->rime.expire)
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

k32u round_table_dice( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    k32u dice = round_table_dice2( rti, target_id, attacktype, extra_crit_rate );
    special_procs( rti, attacktype, dice, target_id );
    return dice;
}

k32u round_table_dice2( rtinfo_t* rti, k32u target_id, k32u attacktype, float extra_crit_rate ) {
    float c = uni_rng( rti );
    float cr = rti->player.stat.crit + extra_crit_rate;
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
};
// === auto-attack ============================================================
//TODO:icy talons, frozen pulse
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
    float aspeed = 1.0f + rti->player.stat.haste;
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
    float aspeed = 1.0f + rti->player.stat.haste;
    if ( UP( enrage_expire ) ) aspeed *= 2.0f;
    eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( weapon[1].speed / aspeed ) ), routnum_auto_attack_oh, rti->player.target );
}
// === Frost Strike ===========================================================
DECL_EVENT( frost_stike_cast ) {
    float d = weapon_dmg(rti, 2.30f * (1.0f + rti->player.stat.mastery ), 1, 0) + weapon_dmg(rti, 1.90f * (1.0f + rti->player.stat.mastery ), 1, 0);
    k32u dice = round_table_dice(rti, target_id, ATYPE_SPELL, 0);
    deal_damage(rti, target_id, d, DTYPE_FROST, dice, 0,0s);
    lprintf( ( "frost strike hit" ) );
    //Add Icy Talon
}
DECL_SPELL( frost_strike ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !power_check( rti, 25.0f ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1);//TODO: check if haste effects DCD
    spec_power_consume(rti, 25f);
    eq_enqueue( rti, rti->timestamp, routnum_frost_strike_cast, 0);
    lprintf( ( "frost strike casted" ) );
    
}
// === Obliterate =============================================================
DECL_EVENT( obliterate_cast ) {
    float d = weapon_dmg(rti, 2.58f * (1.0f + rti->player.stat.mastery ), 1, 0) + weapon_dmg(rti, 1.2.58f * (1.0f + rti->player.stat.mastery ), 1, 0);
    k32u dice = round_table_dice(rti, target_id, ATYPE_SPELL, 0);
    deal_damage(rti, target_id, d, DTYPE_FROST, dice, 0,0);
    lprintf( ( "obliterate hit" ) );
    //Add killing machine
}
DECL_SPELL( obliterate ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 2 ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1);//TODO: check if haste effects DCD
    rune_consume(rti, 2);
    eq_enqueue( rti, rti->timestamp, routnum_obliterate_cast, 0);
    lprintf( ( "obliterate casted" ) );
}
// === howling blast ==========================================================
DECL_EVENT( howling_blast_cast ) {
    float dMain = ap_dmg(rti, 0.3852f);
    k32u dice = round_table_dice(rti, target_id, ATYPE_SPELL, 0);
    deal_damage(rti, target_id, d, DTYPE_FROST, dice, 0,0);
    eq_enqueue(rti, rti->timestamp, routnum_frost_fever_cast, 0);
    lprintf( ( "howling blast hit" ) );
    for ( int i = 1; i < num_enemies; i++ ) {
        float dAOE = ap_dmg(rti, 0.305f);
        k32u dice = round_table_dice( rti, i, ATYPE_SPELL, 0 );
        deal_damage( rti, i, dAOE, DTYPE_FROST, dice, 0, 0 );
        eq_enqueue(rti, rti->timestamp, routnum_frost_fever_cast, i);
        lprintf( ( "howling blast aoe hit @tar%d", i ) );
    }

    //add Rime
    //add freezing fog
}
DECL_SPELL( howling_blast ) {
    if ( rti->player.gcd > rti->timestamp ) return 0;
    if ( !rune_check( rti, 2 ) ) return 0;
    gcd_start( rti, FROM_SECONDS( 1.5f ), 1);//TODO: check if haste effects DCD
    rune_consume(rti, 1);
    eq_enqueue( rti, rti->timestamp, routnum_howling_blast_cast, 0);
    lprintf( ( "howling blast casted" ) );
}
// === frost fever ============================================================
DECL_EVENT( frost_fever_tick) {
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

        frost_fever_expire( target_id ) += TIME_OFFSET( FROM_SECONDS( ((frost_fever_expire( target_id )-(rti->timestamp)) > .3*24 ? 1.3*24 : rend_expire-rti.timestamp+24)); // TODO: how rend extends?
        lprintf( ( "frost_fever_expire_expire extends to %f sec", TO_SECONDS( TIME_DISTANT( frost_fever_expire( target_id ) ) ) ) );
    } else {
        frost_fever_expire( target_id ) = TIME_OFFSET( FROM_SECONDS( 15 ) );
        eq_enqueue( rti, TIME_OFFSET( FROM_SECONDS( 3 ) ), routnum_frost_fever_tick, target_id );
        lprintf( ( "rend start" ) );
}