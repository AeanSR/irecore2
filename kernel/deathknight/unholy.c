//
//  unholy.c
//
//
//  Created by Tianjian Guo on 6/9/16.
//
//
struct spec_state_t {
}
struct class_debuff_t {
}
float spec_mastery_coefficient( rtinfo_t* rti ){
    return 1.0f; //TODO: find out the coefficient
}
float spec_mastery_increament( rtinfo_t* rti ){
    return 0.0f;
}
float spec_crit_increament( rtinfo_t* rti ){
    return 0.0f;
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