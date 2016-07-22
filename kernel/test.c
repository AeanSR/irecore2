/*
    kernel compile test
*/

#define CLASS CLASS_DEATHKNIGHT
#define SPEC SPEC_FROST_DK
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
#define shatteredhand_mh 0
#define shatteredhand_oh 0
#define razorice_mh 1
#define razorice_oh 1
#define fallen_crusader_mh 0
#define fallen_crusader_oh 0
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
//#define trinket_worldbreakers_resolve 220
//#define trinket_discordant_chorus 20564
//#define trinket_empty_drinking_horn 259
#define trinket_unending_hunger 54
//#define trinket_spores_of_alacrity 2304
//#define trinket_bonemaws_big_toe 1767
//#define trinket_emberscale_talisman 1767
#define trinket_gronntooth_war_horn 1152
//#define trinket_libram_of_vindication 314
#define ENEMY_IS_DEMONIC 1

#define TALENT_TIER1 2
#define TALENT_TIER2 2
#define TALENT_TIER3 2
#define TALENT_TIER4 2
#define TALENT_TIER5 2
#define TALENT_TIER6 2
#define TALENT_TIER7 2

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
if(((power_max-rti->player.power)>20.000000f))SPELL(arcane_torrent);
if((!TALENT_BREATH_OF_SINDRAGOSA||breath_of_sindragosa_duration))SPELL(blood_fury);
SPELL(berserking);
SPELL(thorasus_the_stone_heart_of_draenor);
if(((TO_SECONDS(REMAIN(pillar_of_frost_cd))<5.000000f)&&(TO_SECONDS(REMAIN(thorasus_the_stone_heart_of_draenor_cd))<10.000000f)))SPELL(potion);
SPELL(pillar_of_frost);
SPELL(obliteration);
if((rti->player.power>=80.000000f))SPELL(breath_of_sindragosa);
if(breath_of_sindragosa_duration){
{
SPELL(glacial_advance);
if((UP(killing_machine_expire)||(num_enemies>=4.000000f)))SPELL(frostscythe);
if(UP(killing_machine_expire))SPELL(obliterate);
if((num_enemies>=2.000000f))SPELL(remorseless_winter);
SPELL(obliterate);
if(TALENT_FROZEN_PULSE)SPELL(frostscythe);
if(TALENT_FROZEN_PULSE)SPELL(howling_blast);
}
if(!UP(frost_fever_expire(rti->player.target)))SPELL(howling_blast);
SPELL(horn_of_winter);
SPELL(empower_rune_weapon);
SPELL(hungering_rune_weapon);
if(UP(rime_expire))SPELL(howling_blast);
return;
}
{
if(!UP(frost_fever_expire(rti->player.target)))SPELL(howling_blast);
if(UP(rime_expire))SPELL(howling_blast);
if((rti->player.power>=80.000000f))SPELL(frost_strike);
{
SPELL(glacial_advance);
if((UP(killing_machine_expire)||(num_enemies>=4.000000f)))SPELL(frostscythe);
if(UP(killing_machine_expire))SPELL(obliterate);
if((num_enemies>=2.000000f))SPELL(remorseless_winter);
SPELL(obliterate);
if(TALENT_FROZEN_PULSE)SPELL(frostscythe);
if(TALENT_FROZEN_PULSE)SPELL(howling_blast);
}
if((TALENT_BREATH_OF_SINDRAGOSA&&(TO_SECONDS(REMAIN(breath_of_sindragosa_cd))>15.000000f)))SPELL(frost_strike);
if(!TALENT_BREATH_OF_SINDRAGOSA)SPELL(frost_strike);
if((TALENT_BREATH_OF_SINDRAGOSA&&(TO_SECONDS(REMAIN(breath_of_sindragosa_cd))>15.000000f)))SPELL(horn_of_winter);
if((TALENT_BREATH_OF_SINDRAGOSA&&(TO_SECONDS(REMAIN(breath_of_sindragosa_cd))>15.000000f)))SPELL(empower_rune_weapon);
if((TALENT_BREATH_OF_SINDRAGOSA&&(TO_SECONDS(REMAIN(breath_of_sindragosa_cd))>15.000000f)))SPELL(hungering_rune_weapon);
if(!TALENT_BREATH_OF_SINDRAGOSA)SPELL(horn_of_winter);
if(!TALENT_BREATH_OF_SINDRAGOSA)SPELL(empower_rune_weapon);
if(!TALENT_BREATH_OF_SINDRAGOSA)SPELL(hungering_rune_weapon);
}
}

int main(){
    float result;
    sim_iterate( &result, 5171, 4313 + 250, 2148 + 125, 751, 1504, 0 );
    int state_size = sizeof( struct runtime_state_t );
    printf( "result: %.3f\nmax queue length: %d\nruntime state size: %d\n", result, maxqueuelength, state_size );
}
