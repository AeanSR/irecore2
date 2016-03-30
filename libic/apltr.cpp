/*
    action priority list translator from SimC to IreCore.
    Aeandarian(a.k.a. fhsvengetta) 2015.8.21

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "libic_internal.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdarg>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>

namespace apltr {
    IC_LOCAL std::vector<std::string> source;
    IC_LOCAL int warnings = 0;
    IC_LOCAL int errors = 0;
};
using namespace apltr;

typedef struct {
    std::string apl;
    int line;
    int pos;
    std::string value;
    double valuef;
    int suppress;
} token_t;
IC_LOCAL token_t token( int line, int pos, std::string apl = "", std::string value = "", double valuef = 0 ) {
    token_t tk;
    tk.line = line;
    tk.pos = pos;
    tk.apl = apl;
    tk.value = value;
    tk.valuef = valuef;
    tk.suppress = 0;
    return tk;
}

IC_LOCAL void veprintf( token_t tok, int type, const char* message, va_list vl ) {
    char* p;
    char buffer[4096] = { 0 };
    int pos = tok.pos;
    static const char* typestr[] =
    {
        "warning",
        "error",
        "note",
    };

    if (tok.line < 0) return;
    if (tok.pos < 0) return;
    if (type == 0) warnings++;
    if (type == 1) errors++;

    /*
        Use the same error output format from GCC:
        <filename>:<line>:<offset>: <message>
        < a single line of source code >
        ^   <-- a mark pointing to where error occurred.
        */

    vsnprintf( buffer, 4096, message, vl );
    cbprintf( "\n%s:%d:%u: %s: %s\n",
        tok.apl.c_str(),
        1 + tok.line,
        1U + tok.pos,
        typestr[type],
        buffer );
    strncpy( buffer, source.at( tok.line ).c_str(), 4095 );
    p = buffer;
    if (source.at( tok.line ).length() >= 80) {
        int tail = std::min( tok.pos + 36, ( int ) source.at( tok.line ).length() );
        int head = std::max( tok.pos - 36, 0 );
        head = std::min( head, 4095 );
        pos = tok.pos - head;
        p = &buffer[head];

        if (tail < source.at( tok.line ).length() - 3) {
            p[72] = 0;
            strcat( p, "...\n" );
        } else {
            tail = source.at( tok.line ).length();
        }
        if (head > 0) {
            if (head < 3) {
                p = buffer;
                pos = tok.pos;
            } else {
                p -= 3;
                p[0] = '.';
                p[1] = '.';
                p[2] = '.';
                pos += 3;
            }
        }
    }
    cbprintf( "%s", p );

    int b = 0;
    while (b++ < pos)
        cbprintf( " " );
    cbprintf( "^" );
    cbprintf( "\n" );
}
IC_LOCAL void eprintf( token_t tok, int type, const char* message, ... ) {
    if (0 == tok.apl.compare(".precombat")) return;
    va_list vl;
    va_start( vl, message );
    veprintf( tok, type, message, vl );
    va_end( vl );
}

IC_LOCAL void read_source( const char* filename ) {
    FILE* f = fopen( filename, "rb" );
    if (!f) {
        cbprintf( "apltr: failed to open file \"%s\"\n", filename );
        return;
    }
    while (1) {
        if (feof( f )) break;
        std::string line;
        char ch;
        while ('\n' != ( ch = fgetc( f ) )) {
            if (ch != '\r')
                line.push_back( ch );
            if (feof( f )) break;
        }
        line.push_back( '\n' );
        source.push_back( line );
    }
}

enum { VAR, VAR_CD, CONST, SYNC, AND, OR, NOT, EQ, NE, LT, GT, LE, GE, ADD, SUB, NEG, MUL, DIV };

typedef struct {
    const char* simc;
    const char* ic;
    int type;
} item_t;

typedef struct {
    const char* simc1;
    const char* simc2;
    const char* ic;
    int type;
} item_context_dependent_t;

namespace apltr {
    IC_LOCAL item_t act_list[] =
    {
        { "auto_attack", "0" },
        { "charge", "0" },
        { "wait", "return", 0 },
        { "battle_cry", "SPELL(battle_cry)", 0 },
        { "berserker_rage", "SPELL(berserker_rage)", 0 },
        { "avatar", "SPELL(avatar)", 0 },
        { "heroic_leap", "SPELL(heroic_leap)", 0 },
        { "heroic_charge", "SPELL(heroic_leap)", 0 }, /* I guess this is a typo. */
        { "potion", "SPELL(potion)", 0 },
        { "storm_bolt", "SPELL(storm_bolt)", 0 },
        { "shockwave", "SPELL(shockwave)", 0 },
        { "avatar", "SPELL(avatar)", 0 },
        { "bladestorm", "SPELL(bladestorm)", 0 },
        { "thorasus_the_stone_heart_of_draenor", "SPELL(thorasus_the_stone_heart_of_draenor)", 0 },
        { "arcane_torrent", "SPELL(arcane_torrent)", 0 },
        { "blood_fury", "SPELL(blood_fury)", 0 },
        { "berserking", "SPELL(berserking)", 0 },
        { "vial_of_convulsive_shadows", "SPELL(vial_of_convulsive_shadows)", 0 },
        { "scabbard_of_kyanos", "SPELL(scabbard_of_kyanos)", 0 },
        { "primal_gladiators_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "primal_combatants_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "wild_gladiators_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "wild_combatants_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "warmongering_gladiators_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "warmongering_combatants_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "bonemaws_big_toe", "SPELL(bonemaws_big_toe)", 0 },
        { "emberscale_talisman", "SPELL(emberscale_talisman)", 0 },

        { "execute", "SPELL(execute)", 0 },
        { "whirlwind", "SPELL(whirlwind)", 0 },

        { "cleave", "SPELL(cleave)", 0 },
        { "colossus_smash", "SPELL(colossus_smash)", 0 },
        { "hamstring", "SPELL(hamstring)", 0 },
        { "mortal_strike", "SPELL(mortal_strike)", 0 },
        { "slam", "SPELL(slam)", 0 },
        { "overpower", "SPELL(overpower)", 0 },
        { "rend", "SPELL(rend)", 0 },
        { "focused_rage", "SPELL(focused_rage)", 0 },
        { "ravager", "SPELL(ravager)", 0 },

        { "bloodthirst", "SPELL(bloodthirst)", 0 },
        { "furious_slash", "SPELL(furious_slash)", 0 },
        { "raging_blow", "SPELL(raging_blow)", 0 },
        { "rampage", "SPELL(rampage)", 0 },
        { "dragon_roar", "SPELL(dragon_roar)", 0 },
        { 0 }
    };
}

IC_LOCAL int lookup_act( std::string name ) {
    for (int i = 0; act_list[i].simc; i++) {
        if (0 == name.compare( act_list[i].simc )) return i;
    }
    return -1;
}

namespace apltr {
    IC_LOCAL item_t var_list[] =
    {
        { "spell_targets.bladestorm_mh", "num_enemies", 0 },
        { "spell_targets.cleave", "min(num_enemies,5)", 0 },
        { "spell_targets.whirlwind", "num_enemies", 0 },
        { "enemies", "num_enemies", 0 },
        { "active_enemies", "num_enemies", 0 },
        { "desired_targets", "num_enemies", 0 },
        { "target.time_to_die", "TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))", 0 },
        { "target.health.pct", "enemy_health_percent(rti)", 0 },
        { "rage", "rti->player.power", 0 },
        { "rage.max", "power_max", 0 },
        { "rage.deficit", "(power_max-rti->player.power)", 0 },
        { "gcd", "TO_SECONDS(REMAIN(rti->player.gcd))", 0 },
        { "set_bonus.tier18_4pc", "t18_4pc", 0 },
        { "set_bonus.tier18_2pc", "t18_2pc", 0 },
        { "set_bonus.tier17_4pc", "t17_4pc", 0 },
        { "set_bonus.tier17_2pc", "t17_2pc", 0 },
        { "raid_event.adds.in", "0", 0 },
        { "raid_event.adds.exists", "0", 0 },
        { "raid_event.adds.count", "0", 0 },
        { "raid_event.adds.cooldown", "65535", 0 },
        { "raid_event.movement.in", "0", 0 },
        { "raid_event.movement.exists", "0", 0 },
        { "raid_event.movement.cooldown", "65535", 0 },

        { "cooldown.bloodthirst.up", "UP(bloodthirst_cd)", 0 },
        { "cooldown.bloodthirst.down", "!UP(bloodthirst_cd)", 0 },
        { "cooldown.bloodthirst.remains", "TO_SECONDS(REMAIN(bloodthirst_cd))", 0 },
        { "buff.enrage.down", "!UP(enrage_expire)", 0 },
        { "buff.enrage.up", "UP(enrage_expire)", 0 },
        { "buff.enrage.remains", "TO_SECONDS(REMAIN(enrage_expire))", 0 },
        { "buff.enrage.react", "UP(enrage_expire)", 0 },
        { "buff.taste_for_blood.down", "!UP(taste_for_blood_expire)", 0 },
        { "buff.taste_for_blood.up", "UP(taste_for_blood_expire)", 0 },
        { "buff.taste_for_blood.remains", "TO_SECONDS(REMAIN(taste_for_blood_expire))", 0 },
        { "buff.taste_for_blood.react", "taste_for_blood_stack", 0 },
        { "buff.taste_for_blood.stack", "taste_for_blood_stack", 0 },
        { "buff.meat_cleaver.down", "!UP(meat_cleaver_expire)", 0 },
        { "buff.meat_cleaver.up", "UP(meat_cleaver_expire)", 0 },
        { "buff.meat_cleaver.remains", "TO_SECONDS(REMAIN(meat_cleaver_expire))", 0 },
        { "buff.meat_cleaver.react", "UP(meat_cleaver_expire)", 0 },
        { "buff.wrecking_ball.down", "!UP(wrecking_ball_expire)", 0 },
        { "buff.wrecking_ball.up", "UP(wrecking_ball_expire)", 0 },
        { "buff.wrecking_ball.remains", "TO_SECONDS(REMAIN(wrecking_ball_expire))", 0 },
        { "buff.wrecking_ball.react", "UP(wrecking_ball_expire)", 0 },
        { "buff.massacre.down", "!UP(massacre_expire)", 0 },
        { "buff.massacre.up", "UP(massacre_expire)", 0 },
        { "buff.massacre.remains", "TO_SECONDS(REMAIN(massacre_expire))", 0 },
        { "buff.massacre.react", "UP(massacre_expire)", 0 },
        { "buff.frothing_berserker.down", "!UP(frothing_berserker_expire)", 0 },
        { "buff.frothing_berserker.up", "UP(frothing_berserker_expire)", 0 },
        { "buff.frothing_berserker.remains", "TO_SECONDS(REMAIN(frothing_berserker_expire))", 0 },
        { "buff.frothing_berserker.react", "UP(frothing_berserker_expire)", 0 },
        { "buff.meat_grinder.down", "!UP(meat_grinder_expire)", 0 },
        { "buff.meat_grinder.up", "UP(meat_grinder_expire)", 0 },
        { "buff.meat_grinder.remains", "TO_SECONDS(REMAIN(meat_grinder_expire))", 0 },
        { "buff.meat_grinder.react", "UP(meat_grinder_expire)", 0 },
        { "buff.frenzy.down", "!UP(frenzy_expire)", 0 },
        { "buff.frenzy.up", "UP(frenzy_expire)", 0 },
        { "buff.frenzy.remains", "TO_SECONDS(REMAIN(frenzy_expire))", 0 },
        { "buff.frenzy.react", "frenzy_stack", 0 },
        { "buff.frenzy.stack", "frenzy_stack", 0 },
        { "cooldown.raging_blow.up", "UP(raging_blow_cd)", 0 },
        { "cooldown.raging_blow.down", "!UP(raging_blow_cd)", 0 },
        { "cooldown.raging_blow.remains", "TO_SECONDS(REMAIN(raging_blow_cd))", 0 },
        { "buff.dragon_roar.down", "!UP(dragon_roar_expire)", 0 },
        { "buff.dragon_roar.up", "UP(dragon_roar_expire)", 0 },
        { "buff.dragon_roar.remains", "TO_SECONDS(REMAIN(dragon_roar_expire))", 0 },
        { "buff.dragon_roar.react", "UP(dragon_roar_expire)", 0 },
        { "cooldown.dragon_roar.up", "UP(dragon_roar_cd)", 0 },
        { "cooldown.dragon_roar.down", "!UP(dragon_roar_cd)", 0 },
        { "cooldown.dragon_roar.remains", "TO_SECONDS(REMAIN(dragon_roar_cd))", 0 },
        { "buff.rampage.down", "!UP(rampage_expire)", 0 },
        { "buff.rampage.up", "UP(rampage_expire)", 0 },
        { "buff.rampage.remains", "TO_SECONDS(REMAIN(rampage_expire))", 0 },
        { "buff.rampage.react", "rampage_stack", 0 },
        { "buff.rampage.stack", "rampage_stack", 0 },
        { "buff.worldbreakers_resolve.down", "!UP(worldbreakers_resolve_expire)", 0 },
        { "buff.worldbreakers_resolve.up", "UP(worldbreakers_resolve_expire)", 0 },
        { "buff.worldbreakers_resolve.remains", "TO_SECONDS(REMAIN(worldbreakers_resolve_expire))", 0 },
        { "buff.worldbreakers_resolve.react", "worldbreakers_resolve_stack", 0 },
        { "buff.worldbreakers_resolve.stack", "worldbreakers_resolve_stack", 0 },

        { "cooldown.cleave.up", "UP(cleave_cd)", 0 },
        { "cooldown.cleave.down", "!UP(cleave_cd)", 0 },
        { "cooldown.cleave.remains", "TO_SECONDS(REMAIN(cleave_cd))", 0 },
        { "buff.cleave.down", "!UP(cleave_expire)", 0 },
        { "buff.cleave.up", "UP(cleave_expire)", 0 },
        { "buff.cleave.remains", "TO_SECONDS(REMAIN(cleave_expire))", 0 },
        { "buff.cleave.react", "cleave_stack", 0 },
        { "buff.cleave.stack", "cleave_stack", 0 },
        { "cooldown.colossus_smash.up", "UP(colossus_smash_cd)", 0 },
        { "cooldown.colossus_smash.down", "!UP(colossus_smash_cd)", 0 },
        { "cooldown.colossus_smash.remains", "TO_SECONDS(REMAIN(colossus_smash_cd))", 0 },
        { "cooldown.hamstring.up", "UP(hamstring_cd)", 0 },
        { "cooldown.hamstring.down", "!UP(hamstring_cd)", 0 },
        { "cooldown.hamstring.remains", "TO_SECONDS(REMAIN(hamstring_cd))", 0 },
        { "cooldown.mortal_strike.up", "UP(mortal_strike_cd)", 0 },
        { "cooldown.mortal_strike.down", "!UP(mortal_strike_cd)", 0 },
        { "cooldown.mortal_strike.remains", "TO_SECONDS(REMAIN(mortal_strike_cd))", 0 },
        { "buff.overpower.down", "!UP(overpower_expire)", 0 },
        { "buff.overpower.up", "UP(overpower_expire)", 0 },
        { "buff.overpower.remains", "TO_SECONDS(REMAIN(overpower_expire))", 0 },
        { "buff.overpower.react", "UP(overpower_expire)", 0 },
        { "cooldown.focused_rage.up", "UP(focused_rage_cd)", 0 },
        { "cooldown.focused_rage.down", "!UP(focused_rage_cd)", 0 },
        { "cooldown.focused_rage.remains", "TO_SECONDS(REMAIN(focused_rage_cd))", 0 },
        { "buff.focused_rage.down", "!(focused_rage_stack)", 0 },
        { "buff.focused_rage.up", "!!(focused_rage_stack)", 0 },
        { "buff.focused_rage.react", "focused_rage_stack", 0 },
        { "buff.focused_rage.stack", "focused_rage_stack", 0 },
        { "cooldown.ravager.up", "UP(ravager_cd)", 0 },
        { "cooldown.ravager.down", "!UP(ravager_cd)", 0 },
        { "cooldown.ravager.remains", "TO_SECONDS(REMAIN(ravager_cd))", 0 },
        { "buff.ravager.down", "!UP(ravager_expire)", 0 },
        { "buff.ravager.up", "UP(ravager_expire)", 0 },
        { "buff.ravager.remains", "TO_SECONDS(REMAIN(ravager_expire))", 0 },
        { "buff.ravager.react", "UP(ravager_expire)", 0 },
        { "debuff.colossus_smash.down", "!UP(colossus_smash_expire(rti->player.target))", 0 },
        { "debuff.colossus_smash.up", "UP(colossus_smash_expire(rti->player.target))", 0 },
        { "debuff.colossus_smash.remains", "TO_SECONDS(REMAIN(colossus_smash_expire(rti->player.target)))", 0 },
        { "debuff.colossus_smash.react", "UP(colossus_smash_expire(rti->player.target))", 0 },
        /* wtf are you doing dear collision... */
        { "buff.colossus_smash_up.down", "!UP(colossus_smash_expire(rti->player.target))", 0 },
        { "buff.colossus_smash_up.up", "UP(colossus_smash_expire(rti->player.target))", 0 },
        { "buff.colossus_smash_up.remains", "TO_SECONDS(REMAIN(colossus_smash_expire(rti->player.target)))", 0 },
        { "buff.colossus_smash_up.react", "UP(colossus_smash_expire(rti->player.target))", 0 },
        { "dot.rend.down", "!UP(rend_expire(rti->player.target))", 0 },
        { "dot.rend.up", "UP(rend_expire(rti->player.target))", 0 },
        { "dot.rend.remains", "TO_SECONDS(REMAIN(rend_expire(rti->player.target)))", 0 },
        { "dot.rend.duration", "15", 0 },

        { "talent.war_machine.enabled", "TALENT_WAR_MACHINE", 0 },
        { "talent.endless_rage.enabled", "TALENT_ENDLESS_RAGE", 0 },
        { "talent.fresh_meat.enabled", "TALENT_FRESH_MEAT", 0 },
        { "talent.dauntless.enabled", "TALENT_DAUNTLESS", 0 },
        { "talent.overpower.enabled", "TALENT_OVERPOWER", 0 },
        { "talent.sweeping_strikes.enabled", "TALENT_SWEEPING_STRIKES", 0 },
        { "talent.shockwave.enabled", "TALENT_SHOCKWAVE", 0 },
        { "talent.storm_bolt.enabled", "TALENT_STORM_BOLT", 0 },
        { "talent.double_time.enabled", "TALENT_DOUBLE_TIME", 0 },
        { "talent.fervor_of_battle.enabled", "TALENT_FERVOR_OF_BATTLE", 0 },
        { "talent.rend.enabled", "TALENT_REND", 0 },
        { "talent.wrecking_ball.enabled", "TALENT_WRECKING_BALL", 0 },
        { "talent.outburst.enabled", "TALENT_OUTBURST", 0 },
        { "talent.avatar.enabled", "TALENT_AVATAR", 0 },
        { "talent.furious_charge.enabled", "TALENT_FURIOUS_CHARGE", 0 },
        { "talent.warpaint.enabled", "TALENT_WARPAINT", 0 },
        { "talent.second_wind.enabled", "TALENT_SECOND_WIND", 0 },
        { "talent.die_by_the_sword.enabled", "TALENT_DIE_BY_THE_SWORD", 0 },
        { "talent.bounding_stride.enabled", "TALENT_BOUNDING_STRIDE", 0 },
        { "talent.in_for_the_kill.enabled", "TALENT_IN_FOR_THE_KILL", 0 },
        { "talent.mortal_combo.enabled", "TALENT_MORTAL_COMBO", 0 },
        { "talent.massacre.enabled", "TALENT_MASSACRE", 0 },
        { "talent.frothing_berserker.enabled", "TALENT_FROTHING_BERSERKER", 0 },
        { "talent.bladestorm.enabled", "TALENT_BLADESTORM", 0 },
        { "talent.meat_grinder.enabled", "TALENT_MEAT_GRINDER", 0 },
        { "talent.frenzy.enabled", "TALENT_FRENZY", 0 },
        { "talent.inner_rage.enabled", "TALENT_INNER_RAGE", 0 },
        { "talent.focused_rage.enabled", "TALENT_FOCUSED_RAGE", 0 },
        { "talent.trauma.enabled", "TALENT_TRAUMA", 0 },
        { "talent.titanic_might.enabled", "TALENT_TITANIC_MIGHT", 0 },
        { "talent.carnage.enabled", "TALENT_CARNAGE", 0 },
        { "talent.reckless_abandon.enabled", "TALENT_RECKLESS_ABANDON", 0 },
        { "talent.dragon_roar.enabled", "TALENT_DRAGON_ROAR", 0 },
        { "talent.anger_management.enabled", "TALENT_ANGER_MANAGEMENT", 0 },
        { "talent.opportunity_strikes.enabled", "TALENT_OPPORTUNITY_STRIKES", 0 },
        { "talent.ravager.enabled", "TALENT_RAVAGER", 0 },
        { "cooldown.battle_cry.up", "UP(battle_cry_cd)", 0 },
        { "cooldown.battle_cry.down", "!UP(battle_cry_cd)", 0 },
        { "cooldown.battle_cry.remains", "TO_SECONDS(REMAIN(battle_cry_cd))", 0 },
        { "buff.battle_cry.down", "!UP(battle_cry_expire)", 0 },
        { "buff.battle_cry.up", "UP(battle_cry_expire)", 0 },
        { "buff.battle_cry.remains", "TO_SECONDS(REMAIN(battle_cry_expire))", 0 },
        { "buff.battle_cry.react", "UP(battle_cry_expire)", 0 },
        { "cooldown.berserker_rage.up", "UP(berserker_rage_cd)", 0 },
        { "cooldown.berserker_rage.down", "!UP(berserker_rage_cd)", 0 },
        { "cooldown.berserker_rage.remains", "TO_SECONDS(REMAIN(berserker_rage_cd))", 0 },
        { "cooldown.heroic_leap.up", "UP(heroic_leap_cd)", 0 },
        { "cooldown.heroic_leap.down", "!UP(heroic_leap_cd)", 0 },
        { "cooldown.heroic_leap.remains", "TO_SECONDS(REMAIN(heroic_leap_cd))", 0 },
        { "cooldown.potion.up", "UP(potion_cd)", 0 },
        { "cooldown.potion.down", "!UP(potion_cd)", 0 },
        { "cooldown.potion.remains", "TO_SECONDS(REMAIN(potion_cd))", 0 },
        { "buff.potion.down", "!UP(potion_expire)", 0 },
        { "buff.potion.up", "UP(potion_expire)", 0 },
        { "buff.potion.remains", "TO_SECONDS(REMAIN(potion_expire))", 0 },
        { "buff.potion.react", "UP(potion_expire)", 0 },
        { "cooldown.shockwave.up", "UP(shockwave_cd)", 0 },
        { "cooldown.shockwave.down", "!UP(shockwave_cd)", 0 },
        { "cooldown.shockwave.remains", "TO_SECONDS(REMAIN(shockwave_cd))", 0 },
        { "cooldown.storm_bolt.up", "UP(storm_bolt_cd)", 0 },
        { "cooldown.storm_bolt.down", "!UP(storm_bolt_cd)", 0 },
        { "cooldown.storm_bolt.remains", "TO_SECONDS(REMAIN(storm_bolt_cd))", 0 },
        { "cooldown.avatar.up", "UP(avatar_cd)", 0 },
        { "cooldown.avatar.down", "!UP(avatar_cd)", 0 },
        { "cooldown.avatar.remains", "TO_SECONDS(REMAIN(avatar_cd))", 0 },
        { "buff.avatar.down", "!UP(avatar_expire)", 0 },
        { "buff.avatar.up", "UP(avatar_expire)", 0 },
        { "buff.avatar.remains", "TO_SECONDS(REMAIN(avatar_expire))", 0 },
        { "buff.avatar.react", "UP(avatar_expire)", 0 },
        { "cooldown.bladestorm.up", "UP(bladestorm_cd)", 0 },
        { "cooldown.bladestorm.down", "!UP(bladestorm_cd)", 0 },
        { "cooldown.bladestorm.remains", "TO_SECONDS(REMAIN(bladestorm_cd))", 0 },
        { "buff.bladestorm.down", "!UP(bladestorm_expire)", 0 },
        { "buff.bladestorm.up", "UP(bladestorm_expire)", 0 },
        { "buff.bladestorm.remains", "TO_SECONDS(REMAIN(bladestorm_expire))", 0 },
        { "buff.bladestorm.react", "UP(bladestorm_expire)", 0 },
        { "cooldown.arcane_torrent.up", "UP(arcane_torrent_cd)", 0 },
        { "cooldown.arcane_torrent.down", "!UP(arcane_torrent_cd)", 0 },
        { "cooldown.arcane_torrent.remains", "TO_SECONDS(REMAIN(arcane_torrent_cd))", 0 },
        { "cooldown.berserking.up", "UP(berserking_cd)", 0 },
        { "cooldown.berserking.down", "!UP(berserking_cd)", 0 },
        { "cooldown.berserking.remains", "TO_SECONDS(REMAIN(berserking_cd))", 0 },
        { "buff.berserking.down", "!UP(berserking_expire)", 0 },
        { "buff.berserking.up", "UP(berserking_expire)", 0 },
        { "buff.berserking.remains", "TO_SECONDS(REMAIN(berserking_expire))", 0 },
        { "buff.berserking.react", "UP(berserking_expire)", 0 },
        { "cooldown.blood_fury.up", "UP(blood_fury_cd)", 0 },
        { "cooldown.blood_fury.down", "!UP(blood_fury_cd)", 0 },
        { "cooldown.blood_fury.remains", "TO_SECONDS(REMAIN(blood_fury_cd))", 0 },
        { "buff.blood_fury.down", "!UP(blood_fury_expire)", 0 },
        { "buff.blood_fury.up", "UP(blood_fury_expire)", 0 },
        { "buff.blood_fury.remains", "TO_SECONDS(REMAIN(blood_fury_expire))", 0 },
        { "buff.blood_fury.react", "UP(blood_fury_expire)", 0 },

        { "buff.shattered_defenses.down", "1", 0 },
        { "buff.precise_strikes.down", "1", 0 },
        { 0 }
    };
    IC_LOCAL item_context_dependent_t var_cd_list[] = {
        { "mortal_strike", "charges", "mortal_strike_charge", 0 },
        { "rend", "remains", "TO_SECONDS(REMAIN(rend_expire(rti->player.target)))", 0 },
        { "rend", "duration", "15", 0 },
        { 0 }
    };
    IC_LOCAL item_t sync_cond_list[] = {
        { "colossus_smash", "(colossus_smash_cd==TIME_OFFSET(FROM_SECONDS(45)))", 0 },
        { "avatar", "(avatar_expire==TIME_OFFSET(FROM_SECONDS(20)))", 0 },
        { "battle_cry", "(battle_cry_expire==TIME_OFFSET(FROM_SECONDS(5)))", 0 },
        { "bladestorm", "(bladestorm_cd==TIME_OFFSET(FROM_SECONDS(60)))", 0 },
        { 0 }
    };
}

IC_LOCAL int lookup_var( std::string name ) {
    for (int i = 0; var_list[i].simc; i++) {
        if (0 == name.compare( var_list[i].simc )) return i;
    }
    return -1;
}

IC_LOCAL int lookup_var_context_dependent( std::string context, std::string name ) {
    for (int i = 0; var_cd_list[i].simc1; i++) {
        if (0 == context.compare( var_cd_list[i].simc1 ) && 0 == name.compare( var_cd_list[i].simc2 )) return i;
    }
    return -1;
}

IC_LOCAL int lookup_sync( std::string name ) {
    for (int i = 0; sync_cond_list[i].simc; i++) {
        if (0 == name.compare( sync_cond_list[i].simc )) return i;
    }
    return -1;
}

namespace apltr {
    IC_LOCAL const char* punc_list[] =
    {
        "/",
        ",",
        "=",
        ">",
        ">=",
        "<",
        "<=",
        "!=",
        "+",
        "-",
        "*",
        "%",
        "&",
        "|",
        "!",
        "(",
        ")",
        0
    };
}

IC_LOCAL int lookup_punc( std::string name ) {
    for (int i = 0; punc_list[i]; i++) {
        if (0 == name.compare( punc_list[i] )) return i;
    }
    return -1;
}


IC_LOCAL int is_digit( char c ) {
    return c >= '0' && c <= '9';
}
IC_LOCAL int is_upper( char c ) {
    return c >= 'A' && c <= 'Z';
}
IC_LOCAL int is_lower( char c ) {
    return c >= 'a' && c <= 'z';
}
IC_LOCAL int is_alphabet( char c ) {
    return is_upper( c ) || is_lower( c );
}
IC_LOCAL int is_ident( char c ) {
    return is_alphabet( c ) || is_digit( c ) || c == '_' || c == '.';
}
IC_LOCAL int is_break( char c ) {
    return c == ' ' || c == '\r' || c == '\n' || c == '\t' || c == '\b' || c == EOF;
}

IC_LOCAL double read_const( std::string name ) {
    double value = 0;
    int i;
    for (i = 0; i < name.length(); i++) {
        if (is_digit( name.at( i ) )) {
            value *= 10;
            value += ( double ) ( name.at( i ) - '0' );
        } else break;
    }
    if (i < name.length()) {
        if (name.at( i ) == '.') {
            i++;
            double radix = 1;
            for (; i < name.length(); i++) {
                if (is_digit( name.at( i ) )) {
                    radix *= 0.1;
                    value += radix * ( double ) ( name.at( i ) - '0' );
                } else break;
            }
        }
    }
    return value;
}

struct cond_node_t {
    cond_node_t* lvalue;
    cond_node_t* rvalue;
    int op;
    double value;
    cond_node_t() {
        lvalue = 0;
        rvalue = 0;
        op = 0;
        value = 0;
    }
    void dump( std::string& str ) {
        switch (op) {
        case VAR:
            str.append( var_list[( int ) value].ic );
            break;
        case VAR_CD:
            str.append( var_cd_list[( int ) value].ic );
            break;
        case CONST:
        {
            char buf[32];
            sprintf( buf, "%ff", value );
            str.append( buf );
        }
        break;
        case SYNC:
            str.append( sync_cond_list[( int ) value].ic );
            break;
        case AND:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "&&" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case OR:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "||" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case NOT:
            str.append( "!" );
            lvalue->dump( str );
            break;
        case EQ:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "==" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case NE:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "!=" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case LT:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "<" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case GT:
            str.append( "(" );
            lvalue->dump( str );
            str.append( ">" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case LE:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "<=" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case GE:
            str.append( "(" );
            lvalue->dump( str );
            str.append( ">=" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case ADD:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "+" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case SUB:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "-" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case NEG:
            str.append( "-" );
            lvalue->dump( str );
            break;
        case MUL:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "*" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        case DIV:
            str.append( "(" );
            lvalue->dump( str );
            str.append( "/" );
            rvalue->dump( str );
            str.append( ")" );
            break;
        }
    }
};

struct apl_t;

struct rule_t {
    cond_node_t* cond;
    int action;
    apl_t* run_list;
    int ret_on_call;
    int sync;
    int cycle_targets;
    void dump( std::string& str );
    rule_t() {
        cond = 0;
        action = 0;
        run_list = 0;
        ret_on_call = 0;
        sync = -1;
        cycle_targets = 0;
    }
};

struct apl_t {
    apl_t* next;
    rule_t* item;
    void dump( std::string& str );
    apl_t() {
        next = 0;
        item = 0;
    }
};

void rule_t::dump( std::string& str ) {
    if (action < 0) return;
    if (sync >= 0){
        cond_node_t* sync_cond = new cond_node_t();
        sync_cond->op = SYNC;
        sync_cond->value = sync;
        if (cond){
            cond_node_t* sync_cond_and = new cond_node_t();
            sync_cond_and->op = AND;
            sync_cond_and->lvalue = sync_cond;
            sync_cond_and->rvalue = cond;
            cond = sync_cond_and;
        } else {
            cond = sync_cond;
        }
    }
    if (cycle_targets) {
        str.append( "cycle_targets(\r\n" );
    }
    if (run_list && cond) {
        str.append( "if(" );
        cond->dump( str );
        str.append( "){\r\n" );
        run_list->dump( str );
        if (ret_on_call) {
            str.append( "return;\r\n" );
        }
        str.append( "}" );
    } else if (run_list && !cond) {
        str.append( "{\r\n" );
        run_list->dump( str );
        if (ret_on_call) {
            str.append( "return;\r\n" );
        }
        str.append( "}" );
    } else if (cond) {
        str.append( "if(" );
        cond->dump( str );
        str.append( ")" );
        str.append( act_list[action].ic );
        str.append( ";" );
    } else {
        str.append( act_list[action].ic );
        str.append( ";" );
    }
    str.append( "\r\n" );
    if (cycle_targets) {
        str.append( ");\r\n" );
    }
}
void apl_t::dump( std::string& str ) {
    if (item) {
        item->dump( str );
        if (next) next->dump( str );
    }
}
namespace apltr {
    IC_LOCAL std::map<std::string, std::vector<token_t> > simc_apls;
}

IC_LOCAL void lexer() {
    enum {
        S_BREAK,
        S_IDENT,
        S_CONST,
    };
    int state = S_BREAK;
    std::string memory;
    for (int lno = 0; lno < source.size(); lno++) {
        std::string& line = source.at( lno );
        std::string this_apl;
        if (line[0] == '#') continue; // comment line
        if (strncmp( line.c_str(), "actions", strlen( "actions" ) )) continue; // non apl line
        int pos = strlen( "actions" );
        memory.clear();
        for (; pos < line.length(); pos++) {
            if (is_ident( line[pos] )) memory.push_back( line[pos] );
            else if (line[pos] == '=') {
                // create a new apl;
                simc_apls[memory].clear();
                this_apl = memory;
                memory.clear();
                pos++;
                break;
            } else if (line[pos] == '+' && line.at( pos + 1 ) == '=') {
                // append to a apl;
                this_apl = memory;
                memory.clear();
                pos += 2;
                break;
            } else {
                eprintf( token( lno, pos, "", "" ), 1, "expected apl name or '=' or '+='" );
            }
        }
        if (!memory.empty())eprintf( token( lno, pos, "", "" ), 1, "unexpected line ending" );
        state = S_BREAK;
        for (; pos < line.length(); pos++) {
            switch (state) {
            case S_BREAK:
                if (is_break( line[pos] )) {
                    pos = line.length();
                } else if (line[pos] == '/') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "/" ) );
                } else if (line[pos] == ',') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "," ) );
                } else if (line[pos] == '(') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "(" ) );
                } else if (line[pos] == ')') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, ")" ) );
                } else if (line[pos] == '&') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "&" ) );
                } else if (line[pos] == '|') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "|" ) );
                } else if (line[pos] == '!') {
                    if (pos + 1 < line.length())
                        if (line.at( pos + 1 ) == '=') {
                            pos++;
                            simc_apls[this_apl].push_back( token( lno, pos, this_apl, "!=" ) );
                        } else {
                            simc_apls[this_apl].push_back( token( lno, pos, this_apl, "!" ) );
                        }
                } else if (line[pos] == '+') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "+" ) );
                } else if (line[pos] == '-') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "-" ) );
                } else if (line[pos] == '*') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "*" ) );
                } else if (line[pos] == '%') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "%" ) );
                } else if (line[pos] == '=') {
                    simc_apls[this_apl].push_back( token( lno, pos, this_apl, "=" ) );
                } else if (line[pos] == '>') {
                    if (pos + 1 < line.length())
                        if (line.at( pos + 1 ) == '=') {
                            pos++;
                            simc_apls[this_apl].push_back( token( lno, pos, this_apl, ">=" ) );
                        } else {
                            simc_apls[this_apl].push_back( token( lno, pos, this_apl, ">" ) );
                        }
                } else if (line[pos] == '<') {
                    if (pos + 1 < line.length())
                        if (line.at( pos + 1 ) == '=') {
                            pos++;
                            simc_apls[this_apl].push_back( token( lno, pos, this_apl, "<=" ) );
                        } else {
                            simc_apls[this_apl].push_back( token( lno, pos, this_apl, "<" ) );
                        }
                } else if (is_digit( line[pos] )) {
                    memory.clear();
                    memory.push_back( line[pos] );
                    state = S_CONST;
                } else if (is_alphabet( line[pos] )) {
                    memory.clear();
                    memory.push_back( line[pos] );
                    state = S_IDENT;
                } else {
                    eprintf( token( lno, pos, this_apl, "" ), 1, "unexpected character '%c'(%02X)", line[pos], ( unsigned ) line[pos] );
                }
                break;
            case S_IDENT:
                if (is_ident( line[pos] )) {
                    memory.push_back( line[pos] );
                } else {
                    simc_apls[this_apl].push_back( token( lno, pos - 1, this_apl, memory ) );
                    pos--;
                    state = S_BREAK;
                }
                break;
            case S_CONST:
                if (is_digit( line[pos] ) || line[pos] == '.') {
                    memory.push_back( line[pos] );
                } else {
                    simc_apls[this_apl].push_back( token( lno, pos - 1, this_apl, "", read_const( memory ) ) );
                    pos--;
                    state = S_BREAK;
                }
                break;
            }
        }
    }
}
namespace apltr {
    IC_LOCAL token_t NAL = token( -1, -1, "" );
    IC_LOCAL std::stack<int> mark_stack;
    IC_LOCAL int pos;
    IC_LOCAL int last;
    IC_LOCAL std::string processing_action;
    IC_LOCAL std::vector<token_t>* working;
    IC_LOCAL std::map<std::string, apl_t> ic_apls;
}
#define mark() mark_stack.push(pos)
#define unmark() mark_stack.pop()
#define btm() (pos=mark_stack.top())
#define get() (last=std::max(last,pos),pos<working->size()?working->at(pos++):NAL)


IC_LOCAL cond_node_t* constant() {
    token_t& t = get();
    if (t.value.empty()) {
        auto node = new cond_node_t;
        node->op = CONST;
        node->value = t.valuef;
        return node;
    }
    return 0;
}
IC_LOCAL cond_node_t* variable() {
    token_t& t = get();
    if (!t.value.empty() && -1 == lookup_punc( t.value )) {
        auto node = new cond_node_t;
        node->op = VAR;
        node->value = lookup_var( t.value );
        if (node->value < 0) {
            node->op = VAR_CD;
            node->value = lookup_var_context_dependent( processing_action, t.value );
        }
        if (node->value < 0) {
            if (!t.suppress) eprintf( t, 0, "unknown variable '%s', assumed as constant false", t.value.c_str() );
            node->op = CONST;
            node->value = 0;
            t.suppress = 1;
        }
        return node;
    }
    return 0;
}
IC_LOCAL cond_node_t* logical_expression();
IC_LOCAL cond_node_t* primary_expression() {
    cond_node_t* child;
    mark();
    if (0 != ( child = variable() )) {
        return unmark(), child;
    }
    btm();
    if (0 != ( child = constant() )) {
        return unmark(), child;
    }
    btm();
    if (get().value == "(")
        if (0 != ( child = logical_expression() ))
            if (get().value == ")") {
                return unmark(), child;
            }
    unmark();
    return 0;
}

IC_LOCAL cond_node_t* unary_expression() {
    cond_node_t* child;
    mark();
    std::string op = get().value;
    if (op == "+") {
        if (( child = unary_expression() ) != 0) {
            return unmark(), child;
        }
    } else if (op == "-" || op == "!") {
        if (( child = unary_expression() ) != 0) {
            auto node = new cond_node_t;
            node->lvalue = child;
            node->op = ( op == "-" ? NEG : NOT );
            return unmark(), node;
        }
    }
    btm();
    unmark();
    if (0 != ( child = primary_expression() )) {
        return child;
    }
    return 0;
}

IC_LOCAL cond_node_t* multiplicative_expression() {
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1) {
        if (!( rhs = unary_expression() )) return 0;
        mark();
        if (lhs) {
            auto node = new cond_node_t;
            node->op = ( op == "*" ? MUL : DIV );
            node->lvalue = lhs;
            node->rvalue = rhs;
            lhs = node;
        } else {
            lhs = rhs;
        }
        op = get().value;
        if (op == "*" || op == "%") {
            unmark();
        } else {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL cond_node_t* additive_expression() {
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1) {
        if (!( rhs = multiplicative_expression() )) return 0;
        mark();
        if (lhs) {
            auto node = new cond_node_t;
            node->op = ( op == "+" ? ADD : SUB );
            node->lvalue = lhs;
            node->rvalue = rhs;
            lhs = node;
        } else {
            lhs = rhs;
        }
        op = get().value;
        if (op == "+" || op == "-") {
            unmark();
        } else {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL cond_node_t* relational_expression() {
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1) {
        if (!( rhs = additive_expression() )) return 0;
        mark();
        if (lhs) {
            auto node = new cond_node_t;
            if (op == "=") node->op = EQ;
            if (op == "!=") node->op = NE;
            if (op == "<") node->op = LT;
            if (op == "<=") node->op = LE;
            if (op == ">") node->op = GT;
            if (op == ">=") node->op = GE;
            node->lvalue = lhs;
            node->rvalue = rhs;
            lhs = node;
        } else {
            lhs = rhs;
        }
        op = get().value;
        if (op == "=" || op == "!=" || op == "<" || op == "<=" || op == ">" || op == ">=") {
            unmark();
        } else {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL cond_node_t* logical_expression() {
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1) {
        if (!( rhs = relational_expression() )) return 0;
        mark();
        if (lhs) {
            auto node = new cond_node_t;
            node->op = ( op == "&" ? AND : OR );
            node->lvalue = lhs;
            node->rvalue = rhs;
            lhs = node;
        } else {
            lhs = rhs;
        }
        op = get().value;
        if (op == "&" || op == "|") {
            unmark();
        } else {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL int kv_pair( std::string& key, int& vpos ) {
    std::string tkey;
    int tvpos;
    if (get().value == ",") {
        token_t& t = get();
        tkey = t.value;
        if (get().value == "=") {
            tvpos = pos++;
            if (tvpos >= working->size() || working->at( tvpos ).value == "/" || working->at( tvpos ).value == ",") return 0;
            if (tkey == "name" || tkey == "if" || tkey == "cycle_targets" || tkey == "sync") {

            } else {
                if (!t.suppress) {
                    eprintf( t, 0, "unsupported key '%s', ignored", t.value.c_str() );
                    t.suppress = 1;
                }
            }
            vpos = tvpos;
            key = tkey;
            return 1;
        }
    }
    return 0;
}

IC_LOCAL rule_t* rule_item() {
    std::string action = get().value;
    if (action == "use_item") {
        auto node = new rule_t;
        node->action = -1;
        std::string key;
        int vpos;
        int processed_if = 0;
        int processed_name = 0;
        mark();
        while (kv_pair( key, vpos )) {
            if (key == "name") {
                if (processed_name) {
                    token_t& t = working->at( vpos - 2 );
                    if (!t.suppress) eprintf( t, 0, "name duplicated, overwritten" );
                    t.suppress = 1;
                }
                node->action = lookup_act( working->at( vpos ).value );
                processing_action = working->at( vpos ).value;
                if (node->action < 0) {
                    token_t& t = working->at( vpos );
                    if (!t.suppress) eprintf( t, 0, "unknown item '%s', ignored", t.value.c_str() );
                    t.suppress = 1;
                }
                processed_name = 1;
            } else if (key == "if") {
                if (processed_if) {
                    token_t& t = working->at( vpos - 2 );
                    if (!t.suppress) eprintf( t, 0, "condition duplicated, overwritten" );
                    t.suppress = 1;
                }
                pos = vpos;
                node->cond = logical_expression();
                if (!node->cond) {
                    token_t& t = working->at( vpos );
                    if (!t.suppress) eprintf( t, 1, "cannot build condition tree from here" );
                    t.suppress = 1;
                }
                processed_if = 1;
            } else if (key == "cycle_targets") {
                token_t& t = working->at( vpos );
                if (!t.value.empty()) {
                    if (!t.suppress) eprintf( t, 1, "expected constant number for cycle_targets" );
                    t.suppress = 1;
                }
                node->cycle_targets = t.valuef;
            } else if (key == "sync") {
                token_t& t = working->at( vpos );
                node->sync = lookup_sync( t.value );
                if (node->sync < 0) {
                    if (!t.suppress) eprintf( t, 0, "sync ability not supported, ignored" );
                    t.suppress = 1;
                }
            }
            unmark();
            mark();
        }
        btm();
        unmark();
        return node;
    } else if (action == "call_action_list" || action == "run_action_list") {
        auto node = new rule_t;
        node->action = -1;
        node->ret_on_call = ( action == "call_action_list" ? 0 : 1 );
        std::string key;
        int vpos;
        int processed_if = 0;
        int processed_name = 0;
        processing_action = "";
        mark();
        while (kv_pair( key, vpos )) {
            if (key == "name") {
                if (processed_name) {
                    token_t& t = working->at( vpos - 2 );
                    if (!t.suppress) eprintf( t, 0, "name duplicated, overwritten" );
                    t.suppress = 1;
                }
                if (ic_apls.count( "." + working->at( vpos ).value )) {
                    node->run_list = &ic_apls["." + working->at( vpos ).value];
                    node->action = 0;
                } else {
                    token_t& t = working->at( vpos );
                    if (!t.suppress) eprintf( t, 0, "action list '%s' do not exist, ignored", t.value.c_str() );
                    t.suppress = 1;
                }
                processed_name = 1;
            } else if (key == "if") {
                if (processed_if) {
                    token_t& t = working->at( vpos - 2 );
                    if (!t.suppress) eprintf( t, 0, "condition duplicated, overwritten" );
                    t.suppress = 1;
                }
                pos = vpos;
                node->cond = logical_expression();
                if (!node->cond) {
                    token_t& t = working->at( vpos );
                    if (!t.suppress) eprintf( t, 1, "cannot build condition tree from here" );
                    t.suppress = 1;
                }
                processed_if = 1;
            }  else if (key == "cycle_targets") {
                token_t& t = working->at( vpos );
                if (!t.value.empty()) {
                    if (!t.suppress) eprintf( t, 1, "expected constant number for cycle_targets" );
                    t.suppress = 1;
                }
                node->cycle_targets = t.valuef;
            } else if (key == "sync") {
                token_t& t = working->at( vpos );
                node->sync = lookup_sync( t.value );
                if (node->sync < 0) {
                    if (!t.suppress) eprintf( t, 0, "sync ability not supported, ignored" );
                    t.suppress = 1;
                }
            }
            unmark();
            mark();
        }
        btm();
        unmark();
        return node;
    } else {
        auto node = new rule_t;
        node->action = lookup_act( action );
        if (node->action < 0) {
            pos--;
            token_t& t = get();
            if (!t.suppress) eprintf( t, 0, "unknown action '%s', ignored", t.value.c_str() );
            t.suppress = 1;
        }
        processing_action = action;
        std::string key;
        int vpos;
        int processed_if = 0;
        mark();
        while (kv_pair( key, vpos )) {
            if (key == "name") {
                token_t& t = working->at( vpos - 2 );
                if (!t.suppress) eprintf( t, 0, "unsupported key 'name', ignored" );
                t.suppress = 1;
            } else if (key == "if") {
                if (processed_if) {
                    token_t& t = working->at( vpos - 2 );
                    if (!t.suppress) eprintf( t, 0, "condition duplicated, overwritten" );
                    t.suppress = 1;
                }
                pos = vpos;
                node->cond = logical_expression();
                if (!node->cond) {
                    token_t& t = working->at( vpos );
                    if (!t.suppress) eprintf( t, 1, "cannot build condition tree from here" );
                    t.suppress = 1;
                }
                processed_if = 1;
            }  else if (key == "cycle_targets") {
                token_t& t = working->at( vpos );
                if (!t.value.empty()) {
                    if (!t.suppress) eprintf( t, 1, "expected constant number for cycle_targets" );
                    t.suppress = 1;
                }
                node->cycle_targets = t.valuef;
            } else if (key == "sync") {
                token_t& t = working->at( vpos );
                node->sync = lookup_sync( t.value );
                if (node->sync < 0) {
                    if (!t.suppress) eprintf( t, 0, "sync ability not supported, ignored" );
                    t.suppress = 1;
                }
            }
            unmark();
            mark();
        }
        btm();
        unmark();
        return node;
    }
}

IC_LOCAL apl_t* rule_sequences() {
    apl_t* lhs = 0;
    rule_t* rhs = 0;
    while (1) {
        if (!( rhs = rule_item() )) return new apl_t;
        //if (pos < working->size()){
        //  printf("%d:%s\n", pos, working->at(pos).value.c_str());
        //  eprintf(working->at(pos), 2, "check");
        //}
        mark();
        if (lhs) {
            auto node = new apl_t;
            auto p = lhs;
            while (p->next)p = p->next;
            p->next = node;
            node->item = rhs;
        } else {
            lhs = new apl_t;
            lhs->item = rhs;
        }
        if (get().value == "/") {
            unmark();
        } else {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) {
        lhs = new apl_t;
        lhs->item = rhs;
    }
    return lhs;
}
IC_LOCAL void parser() {
    for (auto i = simc_apls.begin(); i != simc_apls.end(); i++) {
        ic_apls[i->first] = apl_t();
    }
    for (auto i = simc_apls.begin(); i != simc_apls.end(); i++) {
        working = &i->second;
        pos = 0;
        ic_apls[i->first] = *rule_sequences();
    }
}

IC_LOCAL void reset_gv() {
    apltr::errors = 0;
    apltr::warnings = 0;
    apltr::ic_apls.clear();
    apltr::last = 0;
    apltr::pos = 0;
    while (!apltr::mark_stack.empty())
        apltr::mark_stack.pop();
    apltr::simc_apls.clear();
    apltr::source.clear();
    apltr::working = 0;
    apltr::processing_action.clear();
}

IC_LOCAL int fapltr( std::string& input_file, std::string& output ) {
    reset_gv();
    read_source( input_file.c_str() );
    lexer();
    parser();
    ic_apls[""].dump( output );
    cbprintf( "translation complete, %d errors, %d warnings", errors, warnings );
    return 0;
}

IC_LOCAL std::vector<std::string> &split( const std::string &s, char delim, std::vector<std::string> &elems ) {
    std::stringstream ss( s );
    std::string item;
    while (std::getline( ss, item, delim )) {
        item.push_back( '\n' );
        elems.push_back( item );
    }
    return elems;
}


IC_LOCAL std::vector<std::string> split( const std::string &s, char delim ) {
    std::vector<std::string> elems;
    split( s, delim, elems );
    return elems;
}

IC_LOCAL int sapltr( std::string& input, std::string& output ) {
    reset_gv();
    split( input, '\n', source );
    lexer();
    parser();
    ic_apls[""].dump( output );
    cbprintf( "translation complete, %d errors, %d warnings\n", errors, warnings );
    return 0;
}
