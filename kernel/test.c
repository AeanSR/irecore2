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
#define num_enemies 6
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

#define ARTIFACT_TRAITS (int [18]){ 1, 2, 3, }

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
