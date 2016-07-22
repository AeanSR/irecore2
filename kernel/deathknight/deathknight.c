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
/* Tier 1 */
#define TALENT_SHATTERING_STRIKES            ((SPEC == SPEC_FROST_DK) && (TALENT_TIER1 ==1))
#define TALENT_ICY_TALONS                    ((SPEC == SPEC_FROST_DK) && (TALENT_TIER1 ==2))
#define TALENT_MURDEROUS_EFFICIENCY          ((SPEC == SPEC_FROST_DK) && (TALENT_TIER1 ==3))
/* Tier 2 */
#define TALENT_FREEZING_FOG                  ((SPEC == SPEC_FROST_DK) && (TALENT_TIER2 ==1))
#define TALENT_FROZEN_PULSE                  ((SPEC == SPEC_FROST_DK) && (TALENT_TIER2 ==2))
#define TALENT_HORN_OF_WINTER                ((SPEC == SPEC_FROST_DK) && (TALENT_TIER2 ==3))
/* Tier 3 */
#define TALENT_ICECAP                        ((SPEC == SPEC_FROST_DK) && (TALENT_TIER3 ==1))
#define TALENT_HUNGERING_RUNE_WEAPON         ((SPEC == SPEC_FROST_DK) && (TALENT_TIER3 ==2))
#define TALENT_AVALANCHE                     ((SPEC == SPEC_FROST_DK) && (TALENT_TIER3 ==3))
/* Tier 4 */
#define TALENT_ABOMINATIONS_MIGHT            ((SPEC == SPEC_FROST_DK) && (TALENT_TIER4 ==1))
#define TALENT_BLINDING_SLEET                ((SPEC == SPEC_FROST_DK) && (TALENT_TIER4 ==2))
#define TALENT_WINTER_IS_COMING              ((SPEC == SPEC_FROST_DK) && (TALENT_TIER4 ==3))
/* Tier 5 */
#define TALENT_VOLATILE_SHIELDING            ((SPEC == SPEC_FROST_DK) && (TALENT_TIER5 ==1))
#define TALENT_PERMAFROST                    ((SPEC == SPEC_FROST_DK) && (TALENT_TIER5 ==2))
#define TALENT_WHITE_WALKER                  ((SPEC == SPEC_FROST_DK) && (TALENT_TIER5 ==3))
/* Tier 6 */
#define TALENT_FROSTSCYTHE                   ((SPEC == SPEC_FROST_DK) && (TALENT_TIER6 ==1))
#define TALENT_RUNIC_ATTENUATION             ((SPEC == SPEC_FROST_DK) && (TALENT_TIER6 ==2))
#define TALENT_GATHERING_STORM               ((SPEC == SPEC_FROST_DK) && (TALENT_TIER6 ==3))
/* Tier 7 */
#define TALENT_OBLITERATION                  ((SPEC == SPEC_FROST_DK) && (TALENT_TIER7 ==1))
#define TALENT_BREATH_OF_SINDRAGOSA          ((SPEC == SPEC_FROST_DK) && (TALENT_TIER7 ==2))
#define TALENT_GLACIAL_ADVANCE               ((SPEC == SPEC_FROST_DK) && (TALENT_TIER7 ==3))
struct class_state_t {
    struct {
        k32u ready;
        float charge_progress[3];
    } rune;
#define rune_max     (6)
#define rune_ready   (rti->player.class->rune.ready)
#define rune_cd(seq) TIME_OFFSET(rti->player.class->rune.charge_progress[seq] * FROM_SECONDS(10) / rune_charge_rate(rti))
};
struct class_debuff_t {

};

void rune_reactive( rtinfo_t* rti ) {
    if ( rune_ready == rune_max ) {
        return;
    } else if ( rune_ready >= rune_max - 3 ) {
        k32u rune_on_cd = min( ( k32u )( rune_max - rune_ready ), ( k32u )3 );
        rti->player.class->rune.charge_progress[rune_on_cd - 1] = 0.0f;
        rune_ready ++;
    } else {
        rune_ready ++;
    }
}
void rune_reactive_all( rtinfo_t* rti ) {
    rune_ready = rune_max;
    for ( int i = 0; i < 3; i++ ) {
        rti->player.class->rune.charge_progress[i] = 0.0f;
    }
}
kbool rune_check( rtinfo_t* rti, k32u count ) {
    if ( rune_ready >= count ) return 1;
    return 0;
}
void spec_rune_consume( rtinfo_t* rti, k32u amount );
void rune_consume( rtinfo_t* rti, k32u count ) {
    spec_rune_consume( rti, count );
    assert( rune_ready >= count );
    k32u rune_on_cd = min( ( k32u )( rune_max - rune_ready ), ( k32u )3 );
    rune_ready -= count;
    power_gain( rti, count * 10.0f );
    if ( rune_on_cd < 3 ) {
        for ( int i = 0; i < count && i < 3 - rune_on_cd; i++ ) {
            rti->player.class->rune.charge_progress[i + rune_on_cd] = 1.0f;
        }
    }
}
float spec_rune_charge_rate( rtinfo_t* rti );
float rune_charge_rate( rtinfo_t* rti ) {
    float rate = 1.0f + rti->player.stat.haste;
    rate *= spec_rune_charge_rate( rti );
    return rate;
}
void on_time_elapsed( rtinfo_t* rti, time_t last_time ) {
    time_t elapsed = rti->timestamp - last_time;
    float rune_progress = rune_charge_rate( rti ) * ( float )elapsed / ( float )FROM_SECONDS( 10 );
    k32u rune_on_cd = min( ( k32u )( rune_max - rune_ready ), ( k32u )3 );
    k32u rune_locked = rune_max - rune_ready - rune_on_cd;
    k32u rune_actived = 0;
    for ( int i = 0; i < rune_on_cd; i++ ) {
        rti->player.class->rune.charge_progress[i] -= rune_progress;
        if ( rti->player.class->rune.charge_progress[i] <= 0.0f ) rune_actived ++;
    }
    for ( int i = 0; i < 3; i++ ) {
        if ( i + rune_actived < 3 ) {
            rti->player.class->rune.charge_progress[i] = rti->player.class->rune.charge_progress[i + rune_actived];
        } else {
            rti->player.class->rune.charge_progress[i] = ( rune_locked > i + rune_actived - 3 ) ? 1.0f : 0.0f;
        }
    }
    rune_ready += rune_actived;
}
time_t check_point( rtinfo_t* rti ) {
    return rune_cd( 0 );
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

    rune_ready = rune_max;
}

void spec_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id );

void class_special_procs( rtinfo_t* rti, k32u attacktype, k32u dice, k32u target_id ) {
    spec_special_procs( rti, attacktype, dice, target_id );
}
