/*
    kernel compile test
*/

#define CLASS CLASS_WARRIOR
#define SPEC SPEC_FURY
#define STRICT_GCD 1
#define WBR_NEVER_EXPIRE 1
#define AVATAR_LIKE_BLOODBATH 0
#define SYNC_MELEE 1
#define RNG_MWC64X
#define vary_combat_length 20.0f
#define max_length 450.0f
#define initial_health_percentage 100.0f
#define death_pct 0.0f
#define iterations 1
#define power_max 5.0f
#define num_enemies 6
#define GLYPH_OF_RAGINGWIND 1
#define PLATE_SPECIALIZATION 1
#define BUFF_POTION 1
#define BUFF_BLOODLUST 1
#define RACE RACE_UNDEAD
#define MH_LOW 1659
#define MH_HIGH 2490
#define MH_SPEED 3.6f
#define MH_TYPE WEAPON_2H
#define OH_LOW 1659
#define OH_HIGH 2490
#define OH_SPEED 3.6f
#define OH_TYPE WEAPON_2H
#define archmages_incandescence 0
#define archmages_greater_incandescence 0
#define legendary_ring 2500
#define t17_2pc 0
#define t17_4pc 0
#define t18_2pc 1
#define t18_4pc 1
#define thunderlord_mh 0
#define thunderlord_oh 0
#define bleedinghollow_mh 0
#define bleedinghollow_oh 0
#define shatteredhand_mh 1
#define shatteredhand_oh 1
//#define trinket_vial_of_convulsive_shadows 2033
//#define trinket_forgemasters_insignia 181
//#define trinket_horn_of_screaming_spirits 2652
//#define trinket_scabbard_of_kyanos 2200
//#define trinket_badge_of_victory 1456
//#define trinket_insignia_of_victory 867
//#define trinket_tectus_beating_heart 2304
//#define trinket_formidable_fang 1743
//#define trinket_draenic_stone 1414
//#define trinket_skull_of_war 2120
//#define trinket_mote_of_the_mountain 1517
#define trinket_worldbreakers_resolve 220
//#define trinket_discordant_chorus 20564
#define trinket_empty_drinking_horn 259
//#define trinket_unending_hunger 54
//#define trinket_spores_of_alacrity 2304
//#define trinket_bonemaws_big_toe 1767
//#define trinket_emberscale_talisman 1767
//#define trinket_gronntooth_war_horn 1152
//#define trinket_libram_of_vindication 314
#define ENEMY_IS_DEMONIC 1

#define TALENT_TIER1 3
#define TALENT_TIER2 3
#define TALENT_TIER3 3
#define TALENT_TIER4 3
#define TALENT_TIER5 3
#define TALENT_TIER6 3
#define TALENT_TIER7 3

#include "kernel.c"
#include "common.c"
#include "warrior\warrior.c"
#include "warrior\fury.c"
//#include "warrior\arms.c"
//#include "paladin\paladin.c"
//#include "paladin\retribution.c"
#include "entry.c"

void scan_apl( rtinfo_t* rti ) {
if(!UP(enrage_expire))SPELL(berserker_rage);
if((((0.000000f>25.000000f)&&(0>45.000000f))||!0))SPELL(heroic_leap);
if((((num_enemies>1.000000f)||!0)&&(((TALENT_BLADESTORM&&(TO_SECONDS(REMAIN(bladestorm_cd))==0.000000f))||UP(battle_cry_expire))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<25.000000f))))SPELL(thorasus_the_stone_heart_of_draenor);
if((((enemy_health_percent(rti)<20.000000f)&&UP(battle_cry_expire))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<=30.000000f)))SPELL(potion);
if(((((65535<60.000000f)&&(0>2.000000f))&&(num_enemies==1.000000f))||(65535<5.000000f))){
if(((enemy_health_percent(rti)<20.000000f)&&0))SPELL(battle_cry);
if(!UP(enrage_expire))SPELL(bloodthirst);
SPELL(storm_bolt);
if((UP(enrage_expire)||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<12.000000f)))SPELL(execute);
SPELL(dragon_roar);
SPELL(raging_blow);
if(!0)SPELL(bladestorm);
if(!0.000000f)SPELL(shockwave);
SPELL(bloodthirst);
return;
}
if((((TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<15.000000f)&&(TALENT_BLADESTORM&&(!0||(num_enemies==1.000000f))))||!TALENT_BLADESTORM))SPELL(battle_cry);
if((TALENT_ANGER_MANAGEMENT&&((TALENT_BLADESTORM&&(!0||(num_enemies==1.000000f)))||!TALENT_BLADESTORM))){
if(((TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))>140.000000f)||(enemy_health_percent(rti)<20.000000f)))SPELL(battle_cry);
}
if((!TALENT_ANGER_MANAGEMENT&&((TALENT_BLADESTORM&&(!0||(num_enemies==1.000000f)))||!TALENT_BLADESTORM))){
if(((TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))>190.000000f)||(enemy_health_percent(rti)<20.000000f)))SPELL(battle_cry);
}
if(((UP(battle_cry_expire)||(TO_SECONDS(REMAIN(battle_cry_cd))>60.000000f))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<30.000000f)))SPELL(avatar);
if(UP(battle_cry_expire))SPELL(blood_fury);
if(UP(battle_cry_expire))SPELL(berserking);
if((rti->player.power<(power_max-40.000000f)))SPELL(arcane_torrent);
if((num_enemies==2.000000f)){
SPELL(dragon_roar);
{
if(((bladestorm_cd==TIME_OFFSET(FROM_SECONDS(60)))&&((TO_SECONDS(REMAIN(enrage_expire))>4.000000f)&&(((0>60.000000f)||!0)||(num_enemies>num_enemies)))))SPELL(battle_cry);
if(((TO_SECONDS(REMAIN(enrage_expire))>4.000000f)&&(((0>60.000000f)||!0)||(num_enemies>num_enemies))))SPELL(bladestorm);
}
if((!UP(enrage_expire)||(rti->player.power<40.000000f)))SPELL(bloodthirst);
cycle_targets(
SPELL(execute);
);
if((UP(meat_cleaver_expire)||(enemy_health_percent(rti)<20.000000f)))SPELL(raging_blow);
if((!UP(meat_cleaver_expire)&&(enemy_health_percent(rti)>20.000000f)))SPELL(whirlwind);
SPELL(bloodthirst);
SPELL(whirlwind);
}
if((num_enemies==3.000000f)){
{
if(((bladestorm_cd==TIME_OFFSET(FROM_SECONDS(60)))&&((bladestorm_cd==TIME_OFFSET(FROM_SECONDS(60)))&&((TO_SECONDS(REMAIN(enrage_expire))>4.000000f)&&(((0>60.000000f)||!0)||(num_enemies>num_enemies))))))SPELL(battle_cry);
if(((TO_SECONDS(REMAIN(enrage_expire))>4.000000f)&&(((0>60.000000f)||!0)||(num_enemies>num_enemies))))SPELL(bladestorm);
}
if((!UP(enrage_expire)||(rti->player.power<50.000000f)))SPELL(bloodthirst);
if(UP(meat_cleaver_expire))SPELL(raging_blow);
cycle_targets(
SPELL(execute);
);
SPELL(dragon_roar);
if((enemy_health_percent(rti)>20.000000f))SPELL(whirlwind);
SPELL(bloodthirst);
SPELL(raging_blow);
}
if((num_enemies>3.000000f)){
if((UP(meat_cleaver_expire)&&UP(enrage_expire)))SPELL(raging_blow);
if((!UP(enrage_expire)||(rti->player.power<50.000000f)))SPELL(bloodthirst);
{
if(((bladestorm_cd==TIME_OFFSET(FROM_SECONDS(60)))&&((bladestorm_cd==TIME_OFFSET(FROM_SECONDS(60)))&&((bladestorm_cd==TIME_OFFSET(FROM_SECONDS(60)))&&((TO_SECONDS(REMAIN(enrage_expire))>4.000000f)&&(((0>60.000000f)||!0)||(num_enemies>num_enemies)))))))SPELL(battle_cry);
if(((TO_SECONDS(REMAIN(enrage_expire))>4.000000f)&&(((0>60.000000f)||!0)||(num_enemies>num_enemies))))SPELL(bladestorm);
}
SPELL(whirlwind);
SPELL(dragon_roar);
SPELL(bloodthirst);
}
{
if(((enemy_health_percent(rti)<20.000000f)&&0))SPELL(battle_cry);
if(!UP(enrage_expire))SPELL(bloodthirst);
SPELL(storm_bolt);
if((UP(enrage_expire)||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<12.000000f)))SPELL(execute);
SPELL(dragon_roar);
SPELL(raging_blow);
if(!0)SPELL(bladestorm);
if(!0.000000f)SPELL(shockwave);
SPELL(bloodthirst);
}

}

int main(){
    float result;
    sim_iterate( &result, 5171, 4313 + 250, 2148 + 125, 751, 1504, 0 );
    int state_size = sizeof( struct runtime_state_t );
    printf( "result: %.3f\nmax queue length: %d\nruntime state size: %d\n", result, maxqueuelength, state_size );
}
