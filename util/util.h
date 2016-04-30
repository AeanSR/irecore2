/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#ifndef ICUTIL_H_INCLUDED
#define ICUTIL_H_INCLUDED

#include "VersionNo.h"
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#ifndef IC_LOCAL
#define IC_LOCAL
#endif
enum {
    SPEC_ARMS_WARRIOR, SPEC_FURY_WARRIOR,
    SPEC_RET_PALADIN,
};

IC_LOCAL double approx_scale_coeff( int current_itemlvl, int new_itemlvl );
IC_LOCAL double approx_scale_coeff_cr( int current_itemlvl, int new_itemlvl );
extern IC_LOCAL const char* trinket_list[];
extern IC_LOCAL const char* race_str_param[];
IC_LOCAL int trinket_scaling( int trinket, int itemlvl, int spec );
IC_LOCAL int trinket_from_id( int id );

#include "dbc.h"

IC_LOCAL int dbc_query_weapon_type( int itemid );
IC_LOCAL int dbc_query_armor_type( int itemid );
IC_LOCAL int dbc_query_enchantment_prop( int enchant_id, int prop_idx );
IC_LOCAL int dbc_query_enchantment_value( int enchant_id, int prop_idx );
IC_LOCAL int dbc_query_gem_prop( int itemid, int prop_idx );
IC_LOCAL int dbc_query_gem_value( int itemid, int prop_idx );

#endif