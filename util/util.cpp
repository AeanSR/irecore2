/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "util.h"
#include <cmath>

IC_LOCAL const char* trinket_list[] = {
    "none",
    "vial_of_convulsive_shadows",
    "forgemasters_insignia",
    "horn_of_screaming_spirits",
    "scabbard_of_kyanos",
    "badge_of_victory",
    "insignia_of_victory",
    "tectus_beating_heart",
    "formidable_fang",
    "draenic_stone",
    "skull_of_war",
    "mote_of_the_mountain",
    "worldbreakers_resolve",
    "discordant_chorus",
    "empty_drinking_horn",
    "unending_hunger",
    "spores_of_alacrity",
    "bonemaws_big_toe",
    "emberscale_talisman",
    "gronntooth_war_horn",
    0
};

IC_LOCAL const char* race_str_param[] = {
    "none",
    "human",
    "dwarf",
    "gnome",
    "nightelf_day",
    "nightelf_night",
    "draenei",
    "worgen",
    "orc",
    "troll",
    "tauren",
    "undead",
    "bloodelf",
    "goblin",
    "pandaren",
    0
};

IC_LOCAL int trinket_scaling( int trinket, int itemlvl ) {
    if (trinket == 1) {
        switch (itemlvl) {
        case 670: return 1537;
        case 676: return 1627;
        case 685: return 1767;
        case 691: return 1870;
        case 700: return 2033;
        case 706: return 2150;
        default:  return ( int ) ( 2033.0 * approx_scale_coeff_cr( 700, itemlvl ) );
        }
    } else if (trinket == 2) {
        switch (itemlvl) {
        case 670: return 137;
        case 676: return 145;
        case 685: return 157;
        case 691: return 167;
        case 700: return 181;
        case 706: return 192;
        default:  return ( int ) ( 181.0 * approx_scale_coeff_cr( 700, itemlvl ) );
        }
    } else if (trinket == 3) {
        switch (itemlvl) {
        case 670: return 2004;
        case 676: return 2122;
        case 685: return 2304;
        case 691: return 2439;
        case 700: return 2652;
        case 706: return 2804;
        default:  return ( int ) ( 2652.0 * approx_scale_coeff_cr( 700, itemlvl ) );
        }
    } else if (trinket == 4) {
        switch (itemlvl) {
        case 665: return 2200;
        default:  return ( int ) ( 2200.0 * approx_scale_coeff( 665, itemlvl ) );
        }
    } else if (trinket == 5) {
        switch (itemlvl) {
        case 620: return 456;
        case 626: return 483;
        case 660: return 728;
        case 670: return 727;
        case 680: return 798;
        case 700: return 1057;
        case 710: return 1160;
        default:  return ( int ) ( 1160.0 * approx_scale_coeff_cr( 710, itemlvl ) );
        }
    } else if (trinket == 6) {
        switch (itemlvl) {
        case 620: return 543;
        case 626: return 575;
        case 660: return 867;
        case 670: return 866;
        case 680: return 951;
        case 700: return 1007;
        case 710: return 1104;
        default:  return ( int ) ( 1104.0 * approx_scale_coeff( 710, itemlvl ) );
        }
    } else if (trinket == 7) {
        switch (itemlvl) {
        case 655: return 1743;
        case 661: return 1843;
        case 670: return 2004;
        case 676: return 2122;
        case 685: return 2304;
        case 691: return 2439;
        default:  return ( int ) ( 2304.0 * approx_scale_coeff_cr( 685, itemlvl ) );
        }
    } else if (trinket == 8) {
        switch (itemlvl) {
        case 655: return 1743;
        default:  return ( int ) ( 1743.0 * approx_scale_coeff_cr( 655, itemlvl ) );
        }
    } else if (trinket == 9) {
        switch (itemlvl) {
        case 620: return 771;
        case 640: return 931;
        case 655: return 1069;
        case 670: return 1229;
        case 685: return 1414;
        case 700: return 1627;
        case 715: return 1870;
        default:  return ( int ) ( 1414.0 * approx_scale_coeff( 685, itemlvl ) );
        }
    } else if (trinket == 10) {
        switch (itemlvl) {
        case 640: return 1396;
        case 655: return 1604;
        case 670: return 1844;
        case 685: return 2120;
        case 700: return 2440;
        case 715: return 2804;
        default:  return ( int ) ( 2804.0 * approx_scale_coeff_cr( 715, itemlvl ) );
        }
    } else if (trinket == 11) {
        switch (itemlvl) {
        case 640: return 1517;
        case 646: return 1604;
        default:  return ( int ) ( 1517.0 * approx_scale_coeff_cr( 640, itemlvl ) );
        }
    } else if (trinket == 12) {
        itemlvl -= 15; /** Due to blizzard's bug! */
        switch (itemlvl) {
        case 705: return 220;
        case 711: return 232;
        case 720: return 253;
        case 726: return 267;
        case 735: return 290;
        case 741: return 307;
        default:  return ( int ) ( 290.0 * approx_scale_coeff( 735, itemlvl ) );
        }
    } else if (trinket == 13) {
        switch (itemlvl) {
        case 700: return 20564;
        case 706: return 21744;
        case 715: return 23632;
        case 721: return 24981;
        case 730: return 27172;
        case 736: return 28757;
        default:  return ( int ) ( 27172.0 * approx_scale_coeff( 730, itemlvl ) );
        }
    } else if (trinket == 14) {
        switch (itemlvl) {
        case 700: return 259;
        case 706: return 274;
        case 715: return 298;
        case 721: return 315;
        case 730: return 342;
        case 736: return 362;
        default:  return ( int ) ( 342.0 * approx_scale_coeff( 730, itemlvl ) );
        }
    } else if (trinket == 15) {
        switch (itemlvl) {
        case 695: return 54;
        case 701: return 57;
        case 710: return 62;
        case 716: return 65;
        case 725: return 71;
        case 731: return 75;
        default:  return ( int ) ( 71.0 * approx_scale_coeff( 725, itemlvl ) );
        }
    } else if (trinket == 16) {
        switch (itemlvl) {
        case 685: return 2304;
        case 705: return 2778;
        case 630: return 1383;
        case 636: return 1461;
        case 615: return 1200;
        case 600: return 1043;
        case 570: return 791;
        case 550: return 657;
        case 530: return 543;
        default:  return ( int ) ( 1383.0 * approx_scale_coeff_cr( 630, itemlvl ) );
        }
    } else if (trinket == 17) {
        switch (itemlvl) {
        case 685: return 1767;
        case 705: return 2130;
        case 630: return 1060;
        case 636: return 1120;
        case 615: return 920;
        case 600: return 800;
        case 570: return 607;
        case 550: return 503;
        case 530: return 417;
        default:  return ( int ) ( 1060.0 * approx_scale_coeff_cr( 630, itemlvl ) );
        }
    } else if (trinket == 18) {
        switch (itemlvl) {
        case 685: return 1767;
        case 705: return 2130;
        case 630: return 1060;
        case 636: return 1120;
        case 615: return 920;
        case 600: return 800;
        case 570: return 607;
        case 550: return 503;
        case 530: return 417;
        default:  return ( int ) ( 1060.0 * approx_scale_coeff_cr( 630, itemlvl ) );
        }
    } else if (trinket == 19) {
        return 1152;
    } else return 0;
}

IC_LOCAL int trinket_from_id( int id ) {
    switch (id) {
    case 113969: return 1;
    case 113983: return 2;
    case 119193: return 3;
    case 118882: return 4;
    case 115159: case 119936: case 111232: case 115759: case 125041: case 125518: case 126632: case 126155: case 124867: case 125344: case 125981: case 126458: return 5;
    case 115160: case 119937: case 111233: case 115760: case 125042: case 125519: case 126633: case 126156: case 124868: case 125345: case 125982: case 126459: return 6;
    case 113645: return 7;
    case 114613: return 8;
    case 109262: case 122601: case 122602: case 122603: case 122604: case 128023: case 128024: return 9;
    case 112318: return 10;
    case 116292: return 11;
    case 124523: return 12;
    case 124237: return 13;
    case 124238: return 14;
    case 124236: return 15;
    case 110014: return 16;
    case 110012: return 17;
    case 110013: return 18;
    case 133595: return 19;
    default: return 0;
    }
}

IC_LOCAL double combat_ratings_mult( int itemlvl ) {
    if (itemlvl > 1300) itemlvl = 1300;
    if (itemlvl < 1) itemlvl = 1;
    return _dbc_combat_ratings_mult[itemlvl - 1];
}

IC_LOCAL double approx_scale_coeff( int current_itemlvl, int new_itemlvl ) {
    return pow( 1.15, ( new_itemlvl - current_itemlvl ) / 15.0 );
}

IC_LOCAL double approx_scale_coeff_cr( int current_itemlvl, int new_itemlvl ) {
    return approx_scale_coeff( current_itemlvl, new_itemlvl ) * combat_ratings_mult( new_itemlvl ) / combat_ratings_mult( current_itemlvl );
}

IC_LOCAL _dbc_item_t* _dbc_item_data_end() {
    static _dbc_item_t* end = 0;
    if (!end) {
        end = _dbc_item_data;
        while (end->id) end++;
    }
    return end;
}

IC_LOCAL _dbc_enchant_t* _dbc_enchant_data_end() {
    static _dbc_enchant_t* end = 0;
    if (!end) {
        end = _dbc_enchant_data;
        while (end->id) end++;
    }
    return end;
}

template <typename T>
struct _dbc_comp {
    bool operator() ( const T& lhs, const T& rhs ) {
        return lhs.id < rhs.id;
    }
    bool operator() ( const T& s, int i ) {
        return s.id < i;
    }
    bool operator() ( int i, const T& s ) {
        return i < s.id;
    }
};

IC_LOCAL int dbc_query_weapon_type( int itemid ) {
    auto rec = std::equal_range( _dbc_item_data, _dbc_item_data_end(), itemid, _dbc_comp<_dbc_item_t>() );
    if (rec.first->id != itemid) return WEAPONSUBCLASS_MISC;
    if (rec.first->item_class != ITEMCLASS_WEAPON) return WEAPONSUBCLASS_MISC;
    return rec.first->item_subclass;
}

IC_LOCAL int dbc_query_armor_type( int itemid ) {
    auto rec = std::equal_range( _dbc_item_data, _dbc_item_data_end(), itemid, _dbc_comp<_dbc_item_t>() );
    if (rec.first->id != itemid) return WEAPONSUBCLASS_MISC;
    if (rec.first->item_class != ITEMCLASS_GEAR) return GEARSUBCLASS_MISC;
    return rec.first->item_subclass;
}

IC_LOCAL int dbc_query_enchantment_prop( int enchant_id, int prop_idx ) {
    if (prop_idx >= 3 || prop_idx < 0) return 0;
    auto rec = std::equal_range( _dbc_enchant_data, _dbc_enchant_data_end(), enchant_id, _dbc_comp<_dbc_enchant_t>() );
    if (rec.first->id != enchant_id) return 0;
    return rec.first->prop[prop_idx];
}

IC_LOCAL int dbc_query_enchantment_value( int enchant_id, int prop_idx ) {
    if (prop_idx >= 3 || prop_idx < 0) return 0;
    auto rec = std::equal_range( _dbc_enchant_data, _dbc_enchant_data_end(), enchant_id, _dbc_comp<_dbc_enchant_t>() );
    if (rec.first->id != enchant_id) return 0;
    return rec.first->value[prop_idx];
}

IC_LOCAL int dbc_query_gem_prop( int itemid, int prop_idx ) {
    if (prop_idx >= 3 || prop_idx < 0) return 0;
    auto rec = std::equal_range( _dbc_item_data, _dbc_item_data_end(), itemid, _dbc_comp<_dbc_item_t>() );
    if (rec.first->id != itemid) return 0;
    if (rec.first->item_class != ITEMCLASS_GEM) return 0;
    if (rec.first->gem_enchant == 0) return 0;
    return dbc_query_enchantment_prop( rec.first->gem_enchant, prop_idx );
}

IC_LOCAL int dbc_query_gem_value( int itemid, int prop_idx ) {
    if (prop_idx >= 3 || prop_idx < 0) return 0;
    auto rec = std::equal_range( _dbc_item_data, _dbc_item_data_end(), itemid, _dbc_comp<_dbc_item_t>() );
    if (rec.first->id != itemid) return 0;
    if (rec.first->item_class != ITEMCLASS_GEM) return 0;
    if (rec.first->gem_enchant == 0) return 0;
    return dbc_query_enchantment_value( rec.first->gem_enchant, prop_idx );
}
