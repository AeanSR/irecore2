/**
    IreCore kernel - Deathknight Class Abstraction

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/* class state infos. */
struct class_state_t {
    struct {
        k32u ready;
        time_t cd[3];
    } rune;
    #define rune_max     (6)
    #define rune_ready   (rti->player.class->rune.ready)
    #define rune_cd(seq) (rti->player.class->rune.cd[seq])
};
struct class_debuff_t {

};

void rune_reactive( rtinfo_t* rti ) {
    if ( rune_ready >= rune_max - 3 ) return;
    rune_ready ++;
}
kbool rune_check( rtinfo_t* rti, k32u count ) {
    if ( rune_ready >= count ) return 1;
    return 0;
}
void rune_consume( rtinfo_t* rti, k32u count ) {
    assert( rune_ready >= count );
    rune_ready -= count;
}
float rune_charge_rate( rtinfo_t* rti ) {
    float rate = 1.0f + rti->player.stat.haste;
    return rate;
}
void on_time_elapsed( rtinfo_t* rti, time_t last_time ) {

}
time_t check_point( rtinfo_t* rti ) {

    return 0;
}


/* Event list. */
enum {
    END_OF_COMMON_ROUTNUM = START_OF_CLASS_ROUTNUM - 1,

    START_OF_SPEC_ROUTNUM,
};


void spec_routine_entries( rtinfo_t* rti, _event_t e );
void class_routine_entries( rtinfo_t* rti, _event_t e ) {
    if( e.routine >= START_OF_SPEC_ROUTNUM ) {
        spec_routine_entries( rti, e );
    }
    else switch( e.routine ) {

    default:
        lprintf( ( "wild class routine entry %d", e.routine ) );
        assert( 0 );
    }
}

void spec_module_init( rtinfo_t* rti );

void class_module_init( rtinfo_t* rti ) {
    spec_module_init( rti );
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id );

void class_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    spec_special_procs( rti, attacktype, dice, target_id );
}
