/**
    IreCore kernel - OpenCL Device Entry

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/* Aggregate state structs. */
struct runtime_state_t {
    rtinfo_t _rti;
    struct common_state_t common_state;
    struct class_state_t class_state;
    struct spec_state_t spec_state;
    struct common_debuff_t common_debuff[num_enemies];
    struct class_debuff_t class_debuff[num_enemies];
    struct spec_debuff_t spec_debuff[num_enemies];
};

/* Single iteration logic. */
deviceonly( __kernel ) void sim_iterate(
    deviceonly( __global ) float* dps_result,
    k32u deterministic_seed,
    k32u gear_str,
    k32u gear_crit,
    k32u gear_haste,
    k32u gear_mastery,
    k32u gear_vers
) { 
    /* Write zero to states. */
    deviceonly( __private ) struct runtime_state_t state = { {0} };

    state._rti.player.stat.gear_str = gear_str;
    state._rti.player.stat.gear_crit = gear_crit;
    state._rti.player.stat.gear_haste = gear_haste;
    state._rti.player.stat.gear_mastery = gear_mastery;
    state._rti.player.stat.gear_vers = gear_vers;
    state._rti.player.common = &state.common_state;
    state._rti.player.class = &state.class_state;
    state._rti.player.spec = &state.spec_state;
    for( int i = 0; i < num_enemies; i++ ) {
        state._rti.enemy[i].common = &state.common_debuff[i];
        state._rti.enemy[i].class = &state.class_debuff[i];
        state._rti.enemy[i].spec = &state.spec_debuff[i];
    }

    sim_init(
        &state._rti,
        ( k32u )deterministic_seed + ( k32u )get_global_id( 0 )
    );

    while( eq_execute( &state._rti ) );

    dps_result[get_global_id( 0 )] = state._rti.damage_collected / TO_SECONDS( state._rti.expected_combat_length );
}
