/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#ifndef DBC_H
#define DBC_H

#ifndef IC_LOCAL
#define IC_LOCAL
#endif

#ifdef __cplusplus
#define IC_EXTERN extern "C"
#else
#define IC_EXTERN extern
#endif

enum {
    ITEMCLASS_WEAPON = 2,
    WEAPONSUBCLASS_AXE_1H = 0,
    WEAPONSUBCLASS_AXE_2H = 1,
    WEAPONSUBCLASS_BOW = 2,
    WEAPONSUBCLASS_GUN = 3,
    WEAPONSUBCLASS_MACE_1H = 4,
    WEAPONSUBCLASS_MACE_2H = 5,
    WEAPONSUBCLASS_POLEARM = 6,
    WEAPONSUBCLASS_SWORD_1H = 7,
    WEAPONSUBCLASS_SWORD_2H = 8,
    WEAPONSUBCLASS_WARGLAIVE = 9,
    WEAPONSUBCLASS_STAFF = 10,
    WEAPONSUBCLASS_BEAR_CLAW = 11,
    WEAPONSUBCLASS_CAT_CLAW = 12,
    WEAPONSUBCLASS_FIST_WEAPON = 13,
    WEAPONSUBCLASS_MISC = 14,
    WEAPONSUBCLASS_DAGGER = 15,

    ITEMCLASS_GEM = 3,

    ITEMCLASS_GEAR = 4,
    GEARSUBCLASS_MISC = 0,
    GEARSUBCLASS_CLOTH = 1,
    GEARSUBCLASS_LEATHER = 2,
    GEARSUBCLASS_MAIL = 3,
    GEARSUBCLASS_PLATE = 4,
    GEARSUBCLASS_COSMETIC = 5,
};

typedef struct {
    int id;
    int item_class;
    int item_subclass;
    int gem_enchant;
} _dbc_item_t;

typedef struct {
    int id;
    int prop[3];
    int value[3];
} _dbc_enchant_t;

IC_EXTERN IC_LOCAL float _dbc_combat_ratings_mult[];
IC_EXTERN IC_LOCAL _dbc_enchant_t _dbc_enchant_data[];
IC_EXTERN IC_LOCAL _dbc_item_t _dbc_item_data[];

#endif
