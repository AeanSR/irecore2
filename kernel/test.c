/*
    kernel compile test
*/

#define CLASS_WARRIOR
#define SPEC_FURY
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
#define power_max 120.0f
#define num_enemies 1
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
#define trinket_vial_of_convulsive_shadows 2033
#define trinket_forgemasters_insignia 181
#define trinket_horn_of_screaming_spirits 2652
#define trinket_scabbard_of_kyanos 2200
#define trinket_badge_of_victory 1456
#define trinket_insignia_of_victory 867
#define trinket_tectus_beating_heart 2304
#define trinket_formidable_fang 1743
#define trinket_draenic_stone 1414
#define trinket_skull_of_war 2120
#define trinket_mote_of_the_mountain 1517
#define trinket_worldbreakers_resolve 220
#define trinket_discordant_chorus 20564
#define trinket_empty_drinking_horn 259
#define trinket_unending_hunger 54
#define trinket_spores_of_alacrity 2304
#define trinket_bonemaws_big_toe 1767
#define trinket_emberscale_talisman 1767
#define trinket_gronntooth_war_horn 1152
#define ENEMY_IS_DEMONIC 1

#define TALENT_TIER1 2
#define TALENT_TIER2 2
#define TALENT_TIER3 3
#define TALENT_TIER4 2
#define TALENT_TIER5 2
#define TALENT_TIER6 2
#define TALENT_TIER7 2

#include "kernel.c"
#include "warrior.c"
#include "fury.c"

void scan_apl( rtinfo_t* rti ) {
    SPELL( avatar );
    SPELL( battle_cry );
    SPELL( heroic_leap );
    SPELL( storm_bolt );
}

int main(){
    float result;
    sim_iterate( &result, 5171, 4313 + 250, 2148 + 125, 751, 1504, 0 );
    int state_size = sizeof( rtinfo_t ) + sizeof( struct class_state_t ) + sizeof( struct spec_state_t );
    state_size += (sizeof( struct class_debuff_t ) + sizeof( struct spec_debuff_t )) * num_enemies;
    printf( "result: %.3f\nmax queue length: %d\nruntime state size: %d\n", result, maxqueuelength, state_size );
}
