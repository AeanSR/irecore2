/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
    */

#include "gic.h"

trinket_ladder_t::trinket_ladder_t(){
    list.clear();
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Vial of Convulsive Shadows" ), 113969, 670, 334, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Vial of Convulsive Shadows" ), 113969, 676, 354, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Vial of Convulsive Shadows" ), 113969, 685, 385, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Vial of Convulsive Shadows" ), 113969, 691, 407, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Vial of Convulsive Shadows" ), 113969, 700, 443, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Vial of Convulsive Shadows" ), 113969, 706, 468, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Forgemaster's Insignia" ), 113983, 670, 335, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Forgemaster's Insignia" ), 113983, 676, 355, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Forgemaster's Insignia" ), 113983, 685, 386, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Forgemaster's Insignia" ), 113983, 691, 408, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Forgemaster's Insignia" ), 113983, 700, 444, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Forgemaster's Insignia" ), 113983, 706, 469, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Horn of Screaming Spirits" ), 119193, 670, 283, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Horn of Screaming Spirits" ), 119193, 676, 299, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Horn of Screaming Spirits" ), 119193, 685, 325, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Horn of Screaming Spirits" ), 119193, 691, 344, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Horn of Screaming Spirits" ), 119193, 700, 374, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Horn of Screaming Spirits" ), 119193, 706, 395, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Scabbard of Kyanos" ), 118882, 665, 0, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Wild Gladiator's Badge of Victory" ), 124867, 700, 355, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Wild Combatant's Badge of Victory" ), 125041, 670, 244, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Primal Combatant's Badge of Victory" ), 119936, 620, 153, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Wild Gladiator's Insignia of Victory" ), 124868, 700, 0, 0, 0, 0, 0, 355, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Wild Combatant's Insignia of Victory" ), 125042, 670, 0, 0, 0, 0, 0, 244, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Primal Combatant's Insignia of Victory" ), 119937, 620, 0, 0, 0, 0, 0, 153, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Tectus' Beating Heart" ), 113645, 655, 216, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Tectus' Beating Heart" ), 113645, 661, 228, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Tectus' Beating Heart" ), 113645, 670, 248, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Tectus' Beating Heart" ), 113645, 676, 262, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Tectus' Beating Heart" ), 113645, 685, 285, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Tectus' Beating Heart" ), 113645, 691, 302, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bottle of Infesting Spores" ), 113658, 655, 228, 134, 0, 0, 0, 134, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bottle of Infesting Spores" ), 113658, 661, 241, 141, 0, 0, 0, 141, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bottle of Infesting Spores" ), 113658, 670, 262, 154, 0, 0, 0, 154, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bottle of Infesting Spores" ), 113658, 676, 277, 163, 0, 0, 0, 163, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bottle of Infesting Spores" ), 113658, 685, 301, 177, 0, 0, 0, 177, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bottle of Infesting Spores" ), 113658, 691, 319, 187, 0, 0, 0, 187, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Formidable Fang" ), 114613, 655, 112, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Grandiose Carnage" ), 114552, 645, 183, 0, 0, 183, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Draenic Philosopher's Stone" ), 109262, 620, 0, 0, 0, 97, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Stone of Wind" ), 122601, 640, 0, 0, 0, 0, 0, 175, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Stone of the Earth" ), 122602, 655, 0, 0, 0, 0, 0, 201, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Stone of the Water" ), 122603, 670, 0, 0, 0, 0, 0, 231, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Stone of Fire" ), 122604, 685, 0, 0, 0, 0, 0, 265, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Stone of the Wilds" ), 128023, 700, 0, 0, 0, 0, 0, 305, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Stone of the Elements" ), 128024, 715, 0, 0, 0, 0, 0, 351, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Skull of War" ), 112318, 640, 171, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Skull of War" ), 112318, 655, 196, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Skull of War" ), 112318, 670, 225, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Skull of War" ), 112318, 685, 259, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Skull of War" ), 112318, 700, 298, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Skull of War" ), 112318, 715, 343, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Mote of the Mountain" ), 116292, 640, 175, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Mote of the Mountain" ), 116292, 646, 185, 0, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Storage House Key" ), 116317, 655, 201, 0, 0, 0, 201, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Storage House Key" ), 116317, 661, 212, 0, 0, 0, 212, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Worldbreaker's Resolve" ), 124523, 705, 0, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Worldbreaker's Resolve" ), 124523, 711, 0, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Worldbreaker's Resolve" ), 124523, 720, 0, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Worldbreaker's Resolve" ), 124523, 726, 0, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Worldbreaker's Resolve" ), 124523, 735, 0, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Worldbreaker's Resolve" ), 124523, 741, 0, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Discordant Chorus" ), 124237, 700, 397, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Discordant Chorus" ), 124237, 706, 420, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Discordant Chorus" ), 124237, 715, 456, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Discordant Chorus" ), 124237, 721, 482, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Discordant Chorus" ), 124237, 730, 525, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Discordant Chorus" ), 124237, 736, 555, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Empty Drinking Horn" ), 124238, 700, 397, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Empty Drinking Horn" ), 124238, 706, 420, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Empty Drinking Horn" ), 124238, 715, 456, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Empty Drinking Horn" ), 124238, 721, 482, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Empty Drinking Horn" ), 124238, 730, 525, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Empty Drinking Horn" ), 124238, 736, 555, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unending Hunger" ), 124236, 695, 0, 758, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unending Hunger" ), 124236, 701, 0, 800, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unending Hunger" ), 124236, 710, 0, 871, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unending Hunger" ), 124236, 716, 0, 922, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unending Hunger" ), 124236, 725, 0, 1003, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unending Hunger" ), 124236, 731, 0, 1060, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Rumbling Pebble" ), 124235, 690, 271, 0, 0, 271, 271, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Rumbling Pebble" ), 124235, 696, 286, 0, 0, 286, 286, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Rumbling Pebble" ), 124235, 705, 312, 0, 0, 312, 312, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Rumbling Pebble" ), 124235, 711, 329, 0, 0, 329, 329, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Rumbling Pebble" ), 124235, 720, 359, 0, 0, 359, 359, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Rumbling Pebble" ), 124235, 726, 379, 0, 0, 379, 379, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Spores of Alacrity" ), 110014, 685, 147, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Spores of Alacrity" ), 110014, 705, 177, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Spores of Alacrity" ), 110014, 630, 88, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Spores of Alacrity" ), 110014, 636, 93, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bonemaw's Big Toe" ), 110012, 685, 177, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bonemaw's Big Toe" ), 110012, 705, 213, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bonemaw's Big Toe" ), 110012, 630, 106, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Bonemaw's Big Toe" ), 110012, 636, 112, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Emberscale Talisman" ), 110013, 685, 177, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Emberscale Talisman" ), 110013, 705, 213, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Emberscale Talisman" ), 110013, 630, 106, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Emberscale Talisman" ), 110013, 636, 112, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Mote of Corruption" ), 110010, 685, 265, 0, 0, 265, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Mote of Corruption" ), 110010, 705, 319, 0, 0, 319, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Mote of Corruption" ), 110010, 630, 159, 0, 0, 159, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Mote of Corruption" ), 110010, 636, 168, 0, 0, 168, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Fires of the Sun" ), 110011, 685, 265, 0, 0, 0, 265, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Fires of the Sun" ), 110011, 705, 319, 0, 0, 0, 319, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Fires of the Sun" ), 110011, 630, 159, 0, 0, 0, 159, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Fires of the Sun" ), 110011, 636, 168, 0, 0, 0, 168, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unquenchable Doomfire Censer" ), 128153, 685, 265, 133, 0, 133, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Unquenchable Doomfire Censer" ), 128153, 691, 281, 140, 0, 140, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Fetid Salivation" ), 128148, 685, 265, 0, 265, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Fetid Salivation" ), 128148, 691, 281, 0, 281, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Mark of Supreme Doom" ), 124546, 705, 187, 0, 0, 0, 0, 0, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Chipped Soul Prism" ), 124545, 705, 187, 187, 187, 187, 187, 187, 1 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Gronntooth War Horn" ), 133595, 715, 140, 140, 140, 0, 0, 0, 0, 0 ) );
    list.push_back( trinket_profile_t( QApplication::translate( "gicClass", "Gronntooth War Horn(Demon)" ), 133595, 715, 140, 140, 140, 0, 0, 0, 0, 1 ) );
    std::stable_sort(list.begin(), list.end(), [](const trinket_profile_t& t1, const trinket_profile_t& t2){return t1.itemlvl > t2.itemlvl;});
    int s = list.size();
    for(int i = 0; i < s; i++){
        if(list[i].upgrade){
            list[i].upgrade = 0;
            trinket_profile_t g1(list[i]);
            trinket_profile_t g2(list[i]);
            g1.upgrade = 5;
            g2.upgrade = 10;
            g1.itemlvl += 5;
            g2.itemlvl += 10;
            g1.name = g1.name + "(+5)";
            g2.name = g2.name + "(+10)";
            g1.crit = (int)(((double) g1.crit) * approx_scale_coeff_cr(list[i].itemlvl, g1.itemlvl));
            g1.mastery = (int)(((double) g1.mastery) * approx_scale_coeff_cr(list[i].itemlvl, g1.itemlvl));
            g1.haste = (int)(((double) g1.haste) * approx_scale_coeff_cr(list[i].itemlvl, g1.itemlvl));
            g1.mult = (int)(((double) g1.mult) * approx_scale_coeff_cr(list[i].itemlvl, g1.itemlvl));
            g1.vers = (int)(((double) g1.vers) * approx_scale_coeff_cr(list[i].itemlvl, g1.itemlvl));
            g1.str = (int)(((double) g1.str) * approx_scale_coeff(list[i].itemlvl, g1.itemlvl));
            g2.crit = (int)(((double) g2.crit) * approx_scale_coeff_cr(list[i].itemlvl, g2.itemlvl));
            g2.mastery = (int)(((double) g2.mastery) * approx_scale_coeff_cr(list[i].itemlvl, g2.itemlvl));
            g2.haste = (int)(((double) g2.haste) * approx_scale_coeff_cr(list[i].itemlvl, g2.itemlvl));
            g2.mult = (int)(((double) g2.mult) * approx_scale_coeff_cr(list[i].itemlvl, g2.itemlvl));
            g2.vers = (int)(((double) g2.vers) * approx_scale_coeff_cr(list[i].itemlvl, g2.itemlvl));
            g2.str = (int)(((double) g2.str) * approx_scale_coeff(list[i].itemlvl, g2.itemlvl));
            list.push_back(g2);
            list.push_back(g1);
        }
    }
}

std::vector<trinket_profile_t>& trinket_ladder(){
    static trinket_ladder_t tl;
    return tl.list;
}