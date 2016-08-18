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
#define power_max 100.0f
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

}

int main(){
    float result;
    sim_iterate( &result, 5171, 4313 + 250, 2148 + 125, 751, 1504, 0 );
    int state_size = sizeof( struct runtime_state_t );
    printf( "result: %.3f\nmax queue length: %d\nruntime state size: %d\n", result, maxqueuelength, state_size );
}
