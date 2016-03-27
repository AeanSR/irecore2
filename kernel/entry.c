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
    deviceonly( __private ) rtinfo_t _rti;
    deviceonly( __private ) struct class_state_t class_state;
    deviceonly( __private ) struct class_debuff_t class_debuff[num_enemies];
    deviceonly( __private ) struct spec_state_t spec_state;
    deviceonly( __private ) struct spec_debuff_t spec_debuff[num_enemies];

    /* Write zero to RTI. */
    _rti = ( rtinfo_t ) { 0 };
    class_state = ( struct class_state_t ) { 0 };
    spec_state = ( struct spec_state_t ) { 0 };

    _rti.player.stat.gear_str = gear_str;
    _rti.player.stat.gear_crit = gear_crit;
    _rti.player.stat.gear_haste = gear_haste;
    _rti.player.stat.gear_mastery = gear_mastery;
    _rti.player.stat.gear_vers = gear_vers;

    _rti.player.class = &class_state;
    _rti.player.spec = &spec_state;
    for( int i = 0; i < num_enemies; i++ ) {
        class_debuff[i] = ( struct class_debuff_t ) { 0 };
        spec_debuff[i] = ( struct spec_debuff_t ) { 0 };
        _rti.enemy[i].class = &class_debuff[i];
        _rti.enemy[i].spec = &spec_debuff[i];
    }

    sim_init(
        &_rti,
        ( k32u )deterministic_seed + ( k32u )get_global_id( 0 )
    );

    while( eq_execute( &_rti ) );

    dps_result[get_global_id( 0 )] = _rti.damage_collected / TO_SECONDS( _rti.expected_combat_length );
}
