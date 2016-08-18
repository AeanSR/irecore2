/*
    kernel compile test
*/

#define CLASS CLASS_WARRIOR
#define SPEC SPEC_FURY
#define STRICT_GCD 1
#define SYNC_MELEE 1
#define RNG_MWC64X
#define vary_combat_length 20.0f
#define max_length 450.0f
#define initial_health_percentage 100.0f
#define death_pct 0.0f
#define iterations 1
#define power_max 5.0f
#define num_enemies 1
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
#define shatteredhand_mh 0
#define shatteredhand_oh 0
#define razorice_mh 1
#define razorice_oh 1
#define fallen_crusader_mh 0
#define fallen_crusader_oh 0

#define ENEMY_IS_DEMONIC 1

#define TALENT_TIER1 2
#define TALENT_TIER2 2
#define TALENT_TIER3 2
#define TALENT_TIER4 2
#define TALENT_TIER5 2
#define TALENT_TIER6 2
#define TALENT_TIER7 2

#define ARTIFACT_TRAITS_0 1
#define ARTIFACT_TRAITS_1 1
#define ARTIFACT_TRAITS_2 1
#define ARTIFACT_TRAITS_3 1
#define ARTIFACT_TRAITS_4 1
#define ARTIFACT_TRAITS_5 1
#define ARTIFACT_TRAITS_6 1
#define ARTIFACT_TRAITS_7 1
#define ARTIFACT_TRAITS_8 1
#define ARTIFACT_TRAITS_9 1
#define ARTIFACT_TRAITS_10 1
#define ARTIFACT_TRAITS_11 1
#define ARTIFACT_TRAITS_12 1
#define ARTIFACT_TRAITS_13 1
#define ARTIFACT_TRAITS_14 1
#define ARTIFACT_TRAITS_15 1
#define ARTIFACT_TRAITS_16 1
#define ARTIFACT_TRAITS_17 1
#define ARTIFACT_TRAITS_18 1
#define ARTIFACT_TRAITS_19 1
#define ARTIFACT_TRAITS_20 1
#define ARTIFACT_TRAITS_21 1
#define ARTIFACT_TRAITS_22 1
#define ARTIFACT_TRAITS_23 1
#define ARTIFACT_TRAITS_24 1
#define ARTIFACT_TRAITS_25 1


#include "kernel.c"
#include "common.c"
#if (CLASS == CLASS_WARRIOR)
#include "warrior/warrior.c"
#elif (CLASS == CLASS_PALADIN)
#include "paladin/paladin.c"
#elif (CLASS == CLASS_DEATHKNIGHT)
#include "deathknight/deathknight.c"
#endif
#if (SPEC == SPEC_ARMS)
#include "warrior/arms.c"
#elif (SPEC == SPEC_FURY)
#include "warrior/fury.c"
#elif (SPEC == SPEC_RETRIBUTION)
#include "paladin/retribution.c"
#elif (SPEC == SPEC_FROST_DK)
#include "deathknight/frost_dk.c"
#endif
#include "entry.c"

void scan_apl( rtinfo_t* rti ) {
if((((0.000000f>25.000000f)&&(0>45.000000f))||!0))SPELL(heroic_leap);
if((((enemy_health_percent(rti)<20.000000f)&&UP(battle_cry_expire))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<=30.000000f)))SPELL(potion);
if(((((65535<90.000000f)&&(0>2.000000f))&&(num_enemies==1.000000f))||(65535<5.000000f))){
if(((rti->player.power==100.000000f)||UP(massacre_expire)))SPELL(rampage);
if(((TALENT_OUTBURST&&(TO_SECONDS(REMAIN(dragon_roar_cd))==0.000000f))&&!UP(enrage_expire)))SPELL(berserker_rage);
if(((!TALENT_BLOODBATH&&((TO_SECONDS(REMAIN(battle_cry_cd))<1.000000f)||(TO_SECONDS(REMAIN(battle_cry_cd))>10.000000f)))||(TALENT_BLOODBATH&&(TO_SECONDS(REMAIN(bloodbath_cd))==0.000000f))))SPELL(dragon_roar);
if(UP(dragon_roar_expire))SPELL(avatar);
if(UP(dragon_roar_expire))SPELL(bloodbath);
if(UP(dragon_roar_expire))SPELL(battle_cry);
if(!UP(enrage_expire))SPELL(rampage);
if((TALENT_FRENZY&&(!UP(frenzy_expire)||(TO_SECONDS(REMAIN(frenzy_expire))<=3.000000f))))SPELL(furious_slash);
if((((UP(enrage_expire)&&(!TALENT_MASSACRE&&!TALENT_INNER_RAGE))||(TALENT_MASSACRE&&!UP(enrage_expire)))||(UP(enrage_expire)&&(TALENT_MASSACRE&&!TALENT_INNER_RAGE))))SPELL(execute);
if(!TALENT_INNER_RAGE)SPELL(bloodthirst);
if((!TALENT_INNER_RAGE&&UP(wrecking_ball_expire)))SPELL(whirlwind);
if(UP(enrage_expire))SPELL(raging_blow);
if((UP(wrecking_ball_expire)&&UP(enrage_expire)))SPELL(whirlwind);
if((((UP(enrage_expire)&&!TALENT_FRENZY)||TALENT_FRENZY)||TALENT_MASSACRE))SPELL(execute);
if(!UP(enrage_expire))SPELL(bloodthirst);
SPELL(raging_blow);
SPELL(bloodthirst);
SPELL(furious_slash);
return;
}
if((((TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<15.000000f)&&(TALENT_BLADESTORM&&(!0||(num_enemies==1.000000f))))||!TALENT_BLADESTORM))SPELL(battle_cry);
if(((UP(battle_cry_expire)||(TO_SECONDS(REMAIN(battle_cry_cd))>60.000000f))||(TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))<30.000000f)))SPELL(avatar);
if(UP(battle_cry_expire))SPELL(blood_fury);
if(UP(battle_cry_expire))SPELL(berserking);
if((rti->player.power<(power_max-40.000000f)))SPELL(arcane_torrent);
if(((num_enemies==2.000000f)||(num_enemies==3.000000f))){
if(!UP(meat_cleaver_expire))SPELL(whirlwind);
if(((!UP(enrage_expire)||((rti->player.power==100.000000f)&&0.000000f))||UP(massacre_expire)))SPELL(rampage);
if(!UP(enrage_expire))SPELL(bloodthirst);
if((TALENT_INNER_RAGE&&(num_enemies==2.000000f)))SPELL(raging_blow);
if((num_enemies>2.000000f))SPELL(whirlwind);
SPELL(dragon_roar);
SPELL(bloodthirst);
}
if((num_enemies>3.000000f)){
if((!UP(enrage_expire)||(rti->player.power<50.000000f)))SPELL(bloodthirst);
{
if(((bladestorm_cd==TIME_OFFSET(FROM_SECONDS(90)))&&((TO_SECONDS(REMAIN(enrage_expire))>2.000000f)&&(((0>90.000000f)||!0)||(num_enemies>num_enemies)))))SPELL(battle_cry);
if(((TO_SECONDS(REMAIN(enrage_expire))>2.000000f)&&(((0>90.000000f)||!0)||(num_enemies>num_enemies))))SPELL(bladestorm);
}
SPELL(whirlwind);
SPELL(dragon_roar);
SPELL(bloodthirst);
}
{
if(((rti->player.power==100.000000f)||UP(massacre_expire)))SPELL(rampage);
if(((TALENT_OUTBURST&&(TO_SECONDS(REMAIN(dragon_roar_cd))==0.000000f))&&!UP(enrage_expire)))SPELL(berserker_rage);
if(((!TALENT_BLOODBATH&&((TO_SECONDS(REMAIN(battle_cry_cd))<1.000000f)||(TO_SECONDS(REMAIN(battle_cry_cd))>10.000000f)))||(TALENT_BLOODBATH&&(TO_SECONDS(REMAIN(bloodbath_cd))==0.000000f))))SPELL(dragon_roar);
if(UP(dragon_roar_expire))SPELL(avatar);
if(UP(dragon_roar_expire))SPELL(bloodbath);
if(UP(dragon_roar_expire))SPELL(battle_cry);
if(!UP(enrage_expire))SPELL(rampage);
if((TALENT_FRENZY&&(!UP(frenzy_expire)||(TO_SECONDS(REMAIN(frenzy_expire))<=3.000000f))))SPELL(furious_slash);
if((((UP(enrage_expire)&&(!TALENT_MASSACRE&&!TALENT_INNER_RAGE))||(TALENT_MASSACRE&&!UP(enrage_expire)))||(UP(enrage_expire)&&(TALENT_MASSACRE&&!TALENT_INNER_RAGE))))SPELL(execute);
if(!TALENT_INNER_RAGE)SPELL(bloodthirst);
if((!TALENT_INNER_RAGE&&UP(wrecking_ball_expire)))SPELL(whirlwind);
if(UP(enrage_expire))SPELL(raging_blow);
if((UP(wrecking_ball_expire)&&UP(enrage_expire)))SPELL(whirlwind);
if((((UP(enrage_expire)&&!TALENT_FRENZY)||TALENT_FRENZY)||TALENT_MASSACRE))SPELL(execute);
if(!UP(enrage_expire))SPELL(bloodthirst);
SPELL(raging_blow);
SPELL(bloodthirst);
SPELL(furious_slash);
}
}

int main(){
    float result;
    sim_iterate( &result, 5171, 4313 + 250, 2148 + 125, 751, 1504, 0 );
    int state_size = sizeof( struct runtime_state_t );
    printf( "result: %.3f\nmax queue length: %d\nruntime state size: %d\n", result, maxqueuelength, state_size );
}
