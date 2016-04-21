/**
    IreCore kernel - Paladin Class Abstraction

    *** EDIT AT YOUR OWN RISK! ***
    All kernel source goes here exposed to the air, for your convenience to edit.
    But it is NOT recommended if you are not definitely sure how to edit.

    Copyright (C) 2014-2016 Aean <v#aean.net>
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

/* Tier 1 */
#define TALENT_FINAL_VERDICT        (TALENT_TIER1 == 1)
#define TALENT_EXECUTION_SENTENCE   (TALENT_TIER1 == 2)
#define TALENT_CONSECRATION         (TALENT_TIER1 == 3)

/* Tier 2 */
#define TALENT_THE_FIRES_OF_JUSTICE (TALENT_TIER2 == 1)
#define TALENT_ZEAL                 (TALENT_TIER2 == 2)
#define TALENT_GREATER_JUDGMENT     (TALENT_TIER2 == 3)

/* Tier 3 */
#define TALENT_FIST_OF_JUSTICE      (TALENT_TIER3 == 1)
#define TALENT_REPENTANCE           (TALENT_TIER3 == 2)
#define TALENT_BLINDING_LIGHT       (TALENT_TIER3 == 3)

/* Tier 4 */
#define TALENT_VIRTUES_BLADE        (TALENT_TIER4 == 1)
#define TALENT_BLADE_OF_WRATH       (TALENT_TIER4 == 2)
#define TALENT_DIVINE_HAMMER        (TALENT_TIER4 == 3)

/* Tier 5 */
#define TALENT_JUSTICARS_VENGEANCE  (TALENT_TIER5 == 1)
#define TALENT_EYE_FOR_AN_EYE       (TALENT_TIER5 == 2)
#define TALENT_WORD_OF_GLORY        (TALENT_TIER5 == 3)

/* Tier 6 */
#define TALENT_DIVINE_INTERVENTION  (TALENT_TIER6 == 1)
#define TALENT_DIVINE_STEED         (TALENT_TIER6 == 2)
#define TALENT_SEAL_OF_LIGHT        (TALENT_TIER6 == 3)

/* Tier 7 */
#define TALENT_BLESSINGS_OF_JUSTICE (TALENT_TIER7 == 1)
#define TALENT_HOLY_WRATH           (TALENT_TIER7 == 2)
#define TALENT_EQUALITY             (TALENT_TIER7 == 3)

/*
    Paladin only have one DPS Spec, so all models goes into retribution.c
    paladin.c will be a great template for new class modules since this module is empty.
*/

/* class state infos. */
struct class_state_t {
};
struct class_debuff_t {
};

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
