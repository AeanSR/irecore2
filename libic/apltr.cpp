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
    if (0 == tok.apl.compare( ".precombat" )) return;
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

enum { VAR, VAR_CD, VAR_RT, CONST, SYNC, AND, OR, NOT, EQ, NE, LT, GT, LE, GE, ADD, SUB, NEG, MUL, DIV };

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
    IC_LOCAL const char* valid_spell_list[] = {
        "battle_cry",
        "berserker_rage",
        "avatar",
        "heroic_leap",
        "potion",
        "storm_bolt",
        "shockwave",
        "bladestorm",
        "bloodbath",
        "thorasus_the_stone_heart_of_draenor",
        "arcane_torrent",
        "blood_fury",
        "berserking",
        "vial_of_convulsive_shadows",
        "scabbard_of_kyanos",
        "bonemaws_big_toe",
        "emberscale_talisman",
        "execute",
        "whirlwind",
        "cleave",
        "colossus_smash",
        "hamstring",
        "mortal_strike",
        "slam",
        "overpower",
        "rend",
        "focused_rage",
        "ravager",
        "bloodthirst",
        "furious_slash",
        "raging_blow",
        "rampage",
        "dragon_roar",
        "avenging_wrath",
        "blade_of_justice",
        "blade_of_wrath",
        "divine_hammer",
        "judgment",
        "crusader_strike",
        "zeal",
        "divine_storm",
        "templars_verdict",
        "execution_sentence",
        "consecration",
        "crusade",
        0,
    };
    IC_LOCAL item_t act_list[] =
    {
        { "auto_attack", "0" },
        { "charge", "0" },
        { "wait", "return", 0 },
        { "heroic_charge", "SPELL(heroic_leap)", 0 }, /* I guess this is a typo. */
        { "primal_gladiators_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "primal_combatants_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "wild_gladiators_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "wild_combatants_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "warmongering_gladiators_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { "warmongering_combatants_badge_of_victory", "SPELL(badge_of_victory)", 0 },
        { 0 }
    };
}

IC_LOCAL int lookup_act( std::string name, std::string& rt ) {
    for (int i = 0; act_list[i].simc; i++) {
        if (0 == name.compare( act_list[i].simc )) return i;
    }
    for (int i = 0; valid_spell_list[i]; i++) {
        if (0 == name.compare( valid_spell_list[i] )) {
            rt = std::string( "SPELL(" ) + valid_spell_list[i] + std::string( ")" );
            return 0x7fffffff;
        }
    }
    return -1;
}

namespace apltr {
    IC_LOCAL std::pair<const char*, int> spell_target_bound[] = {
        {"bladestorm_mh", 0},
        {"bladestorm_oh", 0},
        {"whirlwind", 0},
        {"shockwave", 0},
        {"cleave", 5},
        {"divine_storm", 0},
        {"consecration", 0},
        {"divine_hammer", 0},
        {"zeal", 4},
        {0,0},
    };
    IC_LOCAL const char* talent_list[] = {
        "final_verdict",
        "execution_sentence",
        "consecration",
        "the_fires_of_justice",
        "zeal",
        "greater_judgment",
        "fist_of_justice",
        "repentance",
        "blinding_light",
        "virtues_blade",
        "blade_of_wrath",
        "divine_hammer",
        "justicars_vengeance",
        "eye_for_an_eye",
        "word_of_glory",
        "divine_intervention",
        "divine_steed",
        "seal_of_light",
        "divine_purpose",
        "crusade",
        "holy_wrath",
        "war_machine",
        "endless_rage",
        "fresh_meat",
        "dauntless",
        "overpower",
        "sweeping_strikes",
        "shockwave",
        "storm_bolt",
        "double_time",
        "fervor_of_battle",
        "rend",
        "wrecking_ball",
        "outburst",
        "avatar",
        "furious_charge",
        "warpaint",
        "second_wind",
        "die_by_the_sword",
        "bounding_stride",
        "in_for_the_kill",
        "mortal_combo",
        "massacre",
        "frothing_berserker",
        "bladestorm",
        "bloodbath",
        "frenzy",
        "inner_rage",
        "focused_rage",
        "trauma",
        "titanic_might",
        "carnage",
        "reckless_abandon",
        "dragon_roar",
        "anger_management",
        "opportunity_strikes",
        "ravager",
        0,
    };
    IC_LOCAL const char* stack_buff_list[] = {
        "taste_for_blood",
        "frenzy",
        "rampage",
        "worldbreakers_resolve",
        "cleave",
        "focused_rage",
        "zeal",
        "sanctified_wrath",
        "libram_of_vindication",
        0,
    };
    IC_LOCAL const char* expire_buff_list[] = {
        "taste_for_blood",
        "frenzy",
        "rampage",
        "worldbreakers_resolve",
        "cleave",
        "zeal",
        "libram_of_vindication",
        "avenging_wrath",
        "consecration",
        "the_fires_of_justice",
        "divine_hammer",
        "divine_purpose",
        "crusade",
        "battle_cry",
        "avatar",
        "bladestorm",
        "overpower",
        "ravager",
        "enrage",
        "meat_cleaver",
        "wrecking_ball",
        "massacre",
        "frothing_berserker",
        "bloodbath",
        "dragon_roar",
        "potion",
        "bloodlust",
        0,
    };
    IC_LOCAL const char* cooldown_list[] = {
        "bloodthirst",
        "raging_blow",
        "dragon_roar",
        "cleave",
        "colossus_smash",
        "hamstring",
        "mortal_strike",
        "focused_rage",
        "ravager",
        "battle_cry",
        "berserker_rage",
        "heroic_leap",
        "shockwave",
        "storm_bolt",
        "avatar",
        "bladestorm",
        "bloodbath",
        "judgment",
        "crusader_strike",
        "avenging_wrath",
        "blade_of_justice",
        "execution_sentence",
        "consecration",
        "zeal",
        "divine_hammer",
        "crusade",
        "thorasus_the_stone_heart_of_draenor",
        "arcane_torrent",
        "blood_fury",
        "berserking",
        "vial_of_convulsive_shadows",
        "scabbard_of_kyanos",
        "bonemaws_big_toe",
        "emberscale_talisman",
        "potion",
        "bloodlust",
        0,
    };
    IC_LOCAL const char* stack_debuff_list[] = {
        0,
    };
    IC_LOCAL const char* expire_debuff_list[] = {
        "judgment",
        "execution_sentence",
        "colossus_smash",
        "rend",
        "blade_of_wrath",
        0,
    };
    IC_LOCAL item_t var_list[] =
    {
        { "spell_targets.judgment", "(TALENT_GREATER_JUDGMENT?min(num_enemies,4):1)", 0 },
        { "spell_targets.zeal", "min(num_enemies,zeal_stack)", 0 },

        { "enemies", "num_enemies", 0 },
        { "active_enemies", "num_enemies", 0 },
        { "desired_targets", "num_enemies", 0 },
        { "target.time_to_die", "TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))", 0 },
        { "target.health.pct", "enemy_health_percent(rti)", 0 },
        { "rage", "rti->player.power", 0 },
        { "rage.max", "power_max", 0 },
        { "rage.deficit", "(power_max-rti->player.power)", 0 },
        { "holy_power", "rti->player.power", 0 },
        { "holy_power.max", "power_max", 0 },
        { "holy_power.deficit", "(power_max-rti->player.power)", 0 },
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

        /* wtf are you doing dear collision... */
        { "buff.colossus_smash_up.down", "!UP(colossus_smash_expire(rti->player.target))", 0 },
        { "buff.colossus_smash_up.up", "UP(colossus_smash_expire(rti->player.target))", 0 },
        { "buff.colossus_smash_up.remains", "TO_SECONDS(REMAIN(colossus_smash_expire(rti->player.target)))", 0 },
        { "buff.colossus_smash_up.react", "UP(colossus_smash_expire(rti->player.target))", 0 },
        { "dot.rend.down", "!UP(rend_expire(rti->player.target))", 0 },
        { "dot.rend.up", "UP(rend_expire(rti->player.target))", 0 },
        { "dot.rend.remains", "TO_SECONDS(REMAIN(rend_expire(rti->player.target)))", 0 },
        { "dot.rend.duration", "15", 0 },

        // temporary.
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
        { "bladestorm", "(bladestorm_cd==TIME_OFFSET(FROM_SECONDS(90)))", 0 },
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

IC_LOCAL int runtime_var_constructor( std::string context, std::string name, std::string& rt ) {
    std::stringstream ss( name );
    std::string seg;
    char buf[32];
    std::getline( ss, seg, '.' );
    if (seg == "spell_targets") {
        std::string spell;
        std::getline( ss, spell, '.' );
        for (int i = 0; spell_target_bound[i].first; i++) {
            if (0 == spell.compare( spell_target_bound[i].first )) {
                if (spell_target_bound[i].second) {
                    rt = "min(num_enemies,";
                    rt += _itoa( spell_target_bound[i].second, buf, 10 );
                    rt += ")";
                } else {
                    rt = "num_enemies";
                }
                return 0x7fffffff;
            }
        }
    } else if (seg == "talent") {
        std::string talent;
        std::getline( ss, talent, '.' );
        for (int i = 0; talent_list[i]; i++) {
            if (0 == talent.compare( talent_list[i] )) {
                std::transform(talent.begin(), talent.end(), talent.begin(), ::toupper);
                rt = "TALENT_";
                rt += talent;
                return 0x7fffffff;
            }
        }
    } else if (seg == "buff") {
        std::string buff;
        std::getline( ss, buff, '.' );
        std::string var;
        std::getline( ss, var, '.' );
        if (var == "up") {
            for (int i = 0; expire_buff_list[i]; i++) {
                if (0 == buff.compare( expire_buff_list[i] )) {
                    rt = "UP(";
                    rt += buff;
                    rt += "_expire)";
                    return 0x7fffffff;
                }
            }
            for (int i = 0; stack_buff_list[i]; i++) {
                if (0 == buff.compare( stack_buff_list[i] )) {
                    rt = "(";
                    rt += buff;
                    rt += "_stack>0)";
                    return 0x7fffffff;
                }
            }
        } else if (var == "down") {
            for (int i = 0; expire_buff_list[i]; i++) {
                if (0 == buff.compare( expire_buff_list[i] )) {
                    rt = "!UP(";
                    rt += buff;
                    rt += "_expire)";
                    return 0x7fffffff;
                }
            }
            for (int i = 0; stack_buff_list[i]; i++) {
                if (0 == buff.compare( stack_buff_list[i] )) {
                    rt = "(";
                    rt += buff;
                    rt += "_stack==0)";
                    return 0x7fffffff;
                }
            }
        } else if (var == "react") {
            for (int i = 0; stack_buff_list[i]; i++) {
                if (0 == buff.compare( stack_buff_list[i] )) {
                    rt = buff;
                    rt += "_stack";
                    return 0x7fffffff;
                }
            }
            for (int i = 0; expire_buff_list[i]; i++) {
                if (0 == buff.compare( expire_buff_list[i] )) {
                    rt = "UP(";
                    rt += buff;
                    rt += "_expire)";
                    return 0x7fffffff;
                }
            }
        } else if (var == "remains") {
            for (int i = 0; expire_buff_list[i]; i++) {
                if (0 == buff.compare( expire_buff_list[i] )) {
                    rt = "TO_SECONDS(REMAIN(";
                    rt += buff;
                    rt += "_expire))";
                    return 0x7fffffff;
                }
            }
        } else if (var == "stack") {
            for (int i = 0; stack_buff_list[i]; i++) {
                if (0 == buff.compare( stack_buff_list[i] )) {
                    rt = buff;
                    rt += "_stack";
                    return 0x7fffffff;
                }
            }
        }
    } else if (seg == "cooldown") {
        std::string spell;
        std::getline( ss, spell, '.' );
        std::string var;
        std::getline( ss, var, '.' );
        if (var == "up") {
            for (int i = 0; cooldown_list[i]; i++) {
                if (0 == spell.compare( cooldown_list[i] )) {
                    rt = "UP(";
                    rt += spell;
                    rt += "_cd)";
                    return 0x7fffffff;
                }
            }
        } else if (var == "down") {
            for (int i = 0; cooldown_list[i]; i++) {
                if (0 == spell.compare( cooldown_list[i] )) {
                    rt = "!UP(";
                    rt += spell;
                    rt += "_cd)";
                    return 0x7fffffff;
                }
            }
        } else if (var == "remains") {
            for (int i = 0; cooldown_list[i]; i++) {
                if (0 == spell.compare( cooldown_list[i] )) {
                    rt = "TO_SECONDS(REMAIN(";
                    rt += spell;
                    rt += "_cd))";
                    return 0x7fffffff;
                }
            }
        }
    } else if (seg == "debuff") {
        std::string debuff;
        std::getline( ss, debuff, '.' );
        std::string var;
        std::getline( ss, var, '.' );
        if (var == "up") {
            for (int i = 0; expire_debuff_list[i]; i++) {
                if (0 == debuff.compare( expire_debuff_list[i] )) {
                    rt = "UP(";
                    rt += debuff;
                    rt += "_expire(rti->player.target))";
                    return 0x7fffffff;
                }
            }
            for (int i = 0; stack_debuff_list[i]; i++) {
                if (0 == debuff.compare( stack_debuff_list[i] )) {
                    rt = "(";
                    rt += debuff;
                    rt += "_stack(rti->player.target)>0)";
                    return 0x7fffffff;
                }
            }
        } else if (var == "down") {
            for (int i = 0; expire_debuff_list[i]; i++) {
                if (0 == debuff.compare( expire_debuff_list[i] )) {
                    rt = "!UP(";
                    rt += debuff;
                    rt += "_expire(rti->player.target))";
                    return 0x7fffffff;
                }
            }
            for (int i = 0; stack_debuff_list[i]; i++) {
                if (0 == debuff.compare( stack_debuff_list[i] )) {
                    rt = "(";
                    rt += debuff;
                    rt += "_stack(rti->player.target)==0)";
                    return 0x7fffffff;
                }
            }
        } else if (var == "react") {
            for (int i = 0; stack_debuff_list[i]; i++) {
                if (0 == debuff.compare( stack_debuff_list[i] )) {
                    rt = debuff;
                    rt += "_stack(rti->player.target)";
                    return 0x7fffffff;
                }
            }
            for (int i = 0; expire_debuff_list[i]; i++) {
                if (0 == debuff.compare( expire_debuff_list[i] )) {
                    rt = "UP(";
                    rt += debuff;
                    rt += "_expire(rti->player.target))";
                    return 0x7fffffff;
                }
            }
        } else if (var == "remains") {
            for (int i = 0; expire_debuff_list[i]; i++) {
                if (0 == debuff.compare( expire_debuff_list[i] )) {
                    rt = "TO_SECONDS(REMAIN(";
                    rt += debuff;
                    rt += "_expire(rti->player.target)))";
                    return 0x7fffffff;
                }
            }
        } else if (var == "stack") {
            for (int i = 0; stack_debuff_list[i]; i++) {
                if (0 == debuff.compare( stack_debuff_list[i] )) {
                    rt = debuff;
                    rt += "_stack(rti->player.target)";
                    return 0x7fffffff;
                }
            }
        }
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
    std::string rt;
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
        case VAR_RT:
            str.append( rt );
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
    std::string rt;
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
    if (sync >= 0) {
        cond_node_t* sync_cond = new cond_node_t();
        sync_cond->op = SYNC;
        sync_cond->value = sync;
        if (cond) {
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
        if (action < 0x7fffffff) str.append( act_list[action].ic );
        else str.append( rt );
        str.append( ";" );
    } else {
        if (action < 0x7fffffff) str.append( act_list[action].ic );
        else str.append( rt );
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
            node->op = VAR_RT;
            node->value = runtime_var_constructor( processing_action, t.value, node->rt );
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
                node->action = lookup_act( working->at( vpos ).value, node->rt );
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
    } else {
        auto node = new rule_t;
        node->action = lookup_act( action, node->rt );
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
