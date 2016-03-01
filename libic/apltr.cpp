/*
    action priority list translator from SimC to IreCore.
    Aeandarian(a.k.a. fhsvengetta) 2015.8.21

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
    */
#define _CRT_SECURE_NO_WARNINGS
#ifdef _MSC_VER
#define snprintf _snprintf
#endif

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

namespace apltr{
    IC_LOCAL std::vector<std::string> source;
    IC_LOCAL int warnings = 0;
    IC_LOCAL int errors = 0;
};
using namespace apltr;

typedef struct
{
    std::string apl;
    int line;
    int pos;
    std::string value;
    double valuef;
    int suppress;
} token_t;
IC_LOCAL token_t token(int line, int pos, std::string apl = "", std::string value = "", double valuef = 0)
{
    token_t tk;
    tk.line = line;
    tk.pos = pos;
    tk.apl = apl;
    tk.value = value;
    tk.valuef = valuef;
    tk.suppress = 0;
    return tk;
}

IC_LOCAL void veprintf(token_t tok, int type, const char* message, va_list vl)
{
    char* p;
    char buffer[1024] = { 0 };
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

    vsnprintf(buffer, 1024, message, vl);
    cbprintf("\n%s:%d:%u: %s: %s\n",
        tok.apl.c_str(),
        1 + tok.line,
        1U + tok.pos,
        typestr[type],
        buffer);
    strncpy(buffer, source.at(tok.line).c_str(), 1023);
    p = buffer;
    if (source.at(tok.line).length() >= 80)
    {
        int tail = std::min(tok.pos + 36, (int)source.at(tok.line).length());
        int head = std::max(tok.pos - 36, 0);
        head = std::min(head, 1023);
        pos = tok.pos - head;
        p = &buffer[head];

        if (tail < source.at(tok.line).length() - 3) {
            p[73] = 0;
            strcat(p, "...");
        }
        else {
            tail = source.at(tok.line).length();
        }
        if (head > 0)
        {
            if (head < 3)
            {
                p = buffer;
                pos = tok.pos;
            }
            else
            {
                p -= 3;
                p[0] = '.';
                p[1] = '.';
                p[2] = '.';
                pos += 3;
            }
        }
    }
    cbprintf("%s", p);

    int b = 0;
    while (b++ < pos)
        cbprintf(" ");
    cbprintf("^");
    cbprintf("\n");
}
IC_LOCAL void eprintf(token_t tok, int type, const char* message, ...)
{
    va_list vl;
    va_start(vl, message);
    veprintf(tok, type, message, vl);
    va_end(vl);
}

IC_LOCAL void read_source(const char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (!f)
    {
        cbprintf("apltr: failed to open file \"%s\"\n", filename);
        return;
    }
    while (1)
    {
        if (feof(f)) break;
        std::string line;
        char ch;
        while ('\n' != (ch = fgetc(f)))
        {
            if (ch != '\r')
                line.push_back(ch);
            if (feof(f)) break;
        }
        line.push_back('\n');
        source.push_back(line);
    }
}

enum { VAR, CONST, AND, OR, NOT, EQ, NE, LT, GT, LE, GE, ADD, SUB, NEG, MUL, DIV };

typedef struct
{
    const char* simc;
    const char* ic;
    int type;
} item_t;

namespace apltr{
    IC_LOCAL item_t act_list[] =
    {
        { "wait", "return", 0 },
        { "bloodthirst", "SPELL(bloodthirst)", 0 },
        { "raging_blow", "SPELL(ragingblow)", 0 },
        { "wild_strike", "SPELL(wildstrike)", 0 },
        { "whirlwind", "SPELL(whirlwind)", 0 },
        { "execute", "SPELL(execute)", 0 },
        { "potion", "POTION(SPELL(potion),0)", 0 },
        { "berserker_rage", "SPELL(berserkerrage)", 0 },
        { "recklessness", "SPELL(recklessness)", 0 },
        { "storm_bolt", "T41(SPELL(stormbolt),0)", 0 },
        { "shockwave", "T42(SPELL(shockwave),0)", 0 },
        { "dragon_roar", "T43(SPELL(dragonroar),0)", 0 },
        { "ravager", "T72(SPELL(ravager),0)", 0 },
        { "siegebreaker", "T73(SPELL(siegebreaker),0)", 0 },
        { "bladestorm", "T63(SPELL(bladestorm),0)", 0 },
        { "avatar", "T61(SPELL(avatar),0)", 0 },
        { "bloodbath", "T62(SPELL(bloodbath),0)", 0 },
        { "arcane_torrent", "BELF(SPELL(arcanetorrent),0)", 0 },
        { "blood_fury", "ORC(SPELL(bloodfury),0)", 0 },
        { "berserking", "TROLL(SPELL(berserking),0)", 0 },
        { "thorasus_the_stone_heart_of_draenor", "LEGENDARY(SPELL(thorasus_the_stone_heart_of_draenor),0)", 0 },
        { "vial_of_convulsive_shadows", "TRINKET_VIAL(SPELL(vial_of_convulsive_shadows),0)", 0 },
        { "scabbard_of_kyanos", "TRINKET_KYANOS(SPELL(scabbard_of_kyanos),0)", 0 },
        { "primal_gladiators_badge_of_victory", "TRINKET_PVP(SPELL(badge_of_victory),0)", 0 },
        { "primal_combatants_badge_of_victory", "TRINKET_PVP(SPELL(badge_of_victory),0)", 0 },
        { "wild_gladiators_badge_of_victory", "TRINKET_PVP(SPELL(badge_of_victory),0)", 0 },
        { "wild_combatants_badge_of_victory", "TRINKET_PVP(SPELL(badge_of_victory),0)", 0 },
        { "warmongering_gladiators_badge_of_victory", "TRINKET_PVP(SPELL(badge_of_victory),0)", 0 },
        { "warmongering_combatants_badge_of_victory", "TRINKET_PVP(SPELL(badge_of_victory),0)", 0 },
        { "bonemaws_big_toe", "TRINKET_TOE(SPELL(bonemaws_big_toe),0)", 0 },
        { "emberscale_talisman", "TRINKET_EMBER(SPELL(emberscale_talisman),0)", 0 },
        { 0 }
    };
}

IC_LOCAL int lookup_act(std::string name)
{
    for (int i = 0; act_list[i].simc; i++)
    {
        if (0 == name.compare(act_list[i].simc)) return i;
    }
    return -1;
}

namespace apltr{
    IC_LOCAL item_t var_list[] =
    {
        { "spell_targets.bladestorm_mh", "num_enemies", 0 },
        { "spell_targets.whirlwind", "num_enemies", 0 },
        { "enemies", "num_enemies", 0 },
        { "active_enemies", "num_enemies", 0 },
        { "desired_targets", "num_enemies", 0 },
        { "buff.enrage.down", "!UP(enrage.expire)", 0 },
        { "buff.enrage.up", "UP(enrage.expire)", 0 },
        { "buff.enrage.remains", "TO_SECONDS(REMAIN(enrage.expire))", 0 },
        { "buff.enrage.react", "UP(enrage.expire)", 0 },
        { "buff.raging_blow.down", "!UP(ragingblow.expire)", 0 },
        { "buff.raging_blow.up", "UP(ragingblow.expire)", 0 },
        { "buff.raging_blow.remains", "TO_SECONDS(REMAIN(ragingblow.expire))", 0 },
        { "buff.raging_blow.react", "rti->player.ragingblow.stack", 0 },
        { "buff.raging_blow.stack", "rti->player.ragingblow.stack", 0 },
        { "cooldown.bloodthirst.up", "UP(bloodthirst.cd)", 0 },
        { "cooldown.bloodthirst.down", "!UP(bloodthirst.cd)", 0 },
        { "cooldown.bloodthirst.remains", "TO_SECONDS(REMAIN(bloodthirst.cd))", 0 },
        { "buff.meat_cleaver.down", "!UP(meatcleaver.expire)", 0 },
        { "buff.meat_cleaver.up", "UP(meatcleaver.expire)", 0 },
        { "buff.meat_cleaver.remains", "TO_SECONDS(REMAIN(meatcleaver.expire))", 0 },
        { "buff.meat_cleaver.react", "rti->player.meatcleaver.stack", 0 },
        { "buff.meat_cleaver.stack", "rti->player.meatcleaver.stack", 0 },
        { "buff.bloodsurge.down", "!UP(bloodsurge.expire)", 0 },
        { "buff.bloodsurge.up", "UP(bloodsurge.expire)", 0 },
        { "buff.bloodsurge.remains", "TO_SECONDS(REMAIN(bloodsurge.expire))", 0 },
        { "buff.bloodsurge.react", "rti->player.bloodsurge.stack", 0 },
        { "buff.bloodsurge.stack", "rti->player.bloodsurge.stack", 0 },
        { "target.time_to_die", "TO_SECONDS(TIME_DISTANT(rti->expected_combat_length))", 0 },
        { "target.health.pct", "enemy_health_percent(rti)", 0 },
        { "rage", "rti->player.power", 0 },
        { "rage.max", "power_max", 0 },
        { "buff.sudden_death.down", "T32(!UP(suddendeath.expire),0)", 0 },
        { "buff.sudden_death.up", "T32(UP(suddendeath.expire),0)", 0 },
        { "buff.sudden_death.remains", "T32(TO_SECONDS(REMAIN(suddendeath.expire)),0)", 0 },
        { "buff.sudden_death.react", "T32(UP(suddendeath.expire),0)", 0 },
        { "talent.unquenchable_thirst.enabled", "T33(1,0)", 0 },
        { "talent.sudden_death.enabled", "T32(1,0)", 0 },
        { "talent.furious_strike.enabled", "T31(1,0)", 0 },
        { "talent.storm_bolt.enabled", "T41(1,0)", 0 },
        { "talent.shockwave.enabled", "T42(1,0)", 0 },
        { "talent.dragon_roar.enabled", "T43(1,0)", 0 },
        { "talent.avatar.enabled", "T61(1,0)", 0 },
        { "talent.bloodbath.enabled", "T62(1,0)", 0 },
        { "talent.bladestorm.enabled", "T63(1,0)", 0 },
        { "talent.anger_management.enabled", "T71(1,0)", 0 },
        { "talent.ravager.enabled", "T72(1,0)", 0 },
        { "talent.siegebreaker.enabled", "T73(1,0)", 0 },
        { "cooldown.berserker_rage.up", "UP(berserkerrage.cd)", 0 },
        { "cooldown.berserker_rage.down", "!UP(berserkerrage.cd)", 0 },
        { "cooldown.berserker_rage.remains", "TO_SECONDS(REMAIN(berserkerrage.cd))", 0 },
        { "cooldown.recklessness.up", "UP(recklessness.cd)", 0 },
        { "cooldown.recklessness.down", "!UP(recklessness.cd)", 0 },
        { "cooldown.recklessness.remains", "TO_SECONDS(REMAIN(recklessness.cd))", 0 },
        { "buff.recklessness.down", "!UP(recklessness.expire)", 0 },
        { "buff.recklessness.up", "UP(recklessness.expire)", 0 },
        { "buff.recklessness.remains", "TO_SECONDS(REMAIN(recklessness.expire))", 0 },
        { "buff.recklessness.react", "UP(recklessness.expire)", 0 },
        { "cooldown.storm_bolt.up", "T41(UP(stormbolt.cd),0)", 0 },
        { "cooldown.storm_bolt.down", "T41(!UP(stormbolt.cd),0)", 0 },
        { "cooldown.storm_bolt.remains", "T41(TO_SECONDS(REMAIN(stormbolt.cd)),0)", 0 },
        { "cooldown.shockwave.up", "T42(UP(shockwave.cd),0)", 0 },
        { "cooldown.shockwave.down", "T42(!UP(shockwave.cd),0)", 0 },
        { "cooldown.shockwave.remains", "T42(TO_SECONDS(REMAIN(shockwave.cd)),0)", 0 },
        { "cooldown.dragon_roar.up", "T43(UP(dragonroar.cd),0)", 0 },
        { "cooldown.dragon_roar.down", "T43(!UP(dragonroar.cd),0)", 0 },
        { "cooldown.dragon_roar.remains", "T43(TO_SECONDS(REMAIN(dragonroar.cd)),0)", 0 },
        { "cooldown.avatar.up", "T61(UP(avatar.cd),0)", 0 },
        { "cooldown.avatar.down", "T61(!UP(avatar.cd),0)", 0 },
        { "cooldown.avatar.remains", "T61(TO_SECONDS(REMAIN(avatar.cd)),0)", 0 },
        { "buff.avatar.down", "T61(!UP(avatar.expire),0)", 0 },
        { "buff.avatar.up", "T61(UP(avatar.expire),0)", 0 },
        { "buff.avatar.remains", "T61(TO_SECONDS(REMAIN(avatar.expire)),0)", 0 },
        { "buff.avatar.react", "T61(UP(avatar.expire),0)", 0 },
        { "cooldown.bloodbath.up", "T62(UP(bloodbath.cd),0)", 0 },
        { "cooldown.bloodbath.down", "T62(!UP(bloodbath.cd),0)", 0 },
        { "cooldown.bloodbath.remains", "T62(TO_SECONDS(REMAIN(bloodbath.cd)),0)", 0 },
        { "buff.bloodbath.down", "T62(!UP(bloodbath.expire),0)", 0 },
        { "buff.bloodbath.up", "T62(UP(bloodbath.expire),0)", 0 },
        { "buff.bloodbath.remains", "T62(TO_SECONDS(REMAIN(bloodbath.expire)),0)", 0 },
        { "buff.bloodbath.react", "T62(UP(bloodbath.expire),0)", 0 },
        { "cooldown.bladestorm.up", "T63(UP(bladestorm.cd),0)", 0 },
        { "cooldown.bladestorm.down", "T63(!UP(bladestorm.cd),0)", 0 },
        { "cooldown.bladestorm.remains", "T63(TO_SECONDS(REMAIN(bladestorm.cd)),0)", 0 },
        { "buff.bladestorm.down", "T63(!UP(bladestorm.expire),0)", 0 },
        { "buff.bladestorm.up", "T63(UP(bladestorm.expire),0)", 0 },
        { "buff.bladestorm.remains", "T63(TO_SECONDS(REMAIN(bladestorm.expire)),0)", 0 },
        { "buff.bladestorm.react", "T63(UP(bladestorm.expire),0)", 0 },
        { "cooldown.ravager.up", "T72(UP(ravager.cd),0)", 0 },
        { "cooldown.ravager.down", "T72(!UP(ravager.cd),0)", 0 },
        { "cooldown.ravager.remains", "T72(TO_SECONDS(REMAIN(ravager.cd)),0)", 0 },
        { "buff.ravager.down", "T72(!UP(ravager.expire),0)", 0 },
        { "buff.ravager.up", "T72(UP(ravager.expire),0)", 0 },
        { "buff.ravager.remains", "T72(TO_SECONDS(REMAIN(ravager.expire)),0)", 0 },
        { "buff.ravager.react", "T72(UP(ravager.expire),0)", 0 },
        { "cooldown.siegebreaker.up", "T73(UP(siegebreaker.cd),0)", 0 },
        { "cooldown.siegebreaker.down", "T73(!UP(siegebreaker.cd),0)", 0 },
        { "cooldown.siegebreaker.remains", "T73(TO_SECONDS(REMAIN(siegebreaker.cd)),0)", 0 },
        { "raid_event.adds.in", "0", 0 },
        { "raid_event.adds.exists", "0", 0 },
        { "raid_event.adds.count", "0", 0 },
        { "raid_event.adds.cooldown", "65535", 0 },
        { "raid_event.movement.in", "0", 0 },
        { "raid_event.movement.exists", "0", 0 },
        { "raid_event.movement.cooldown", "65535", 0 },
        { "set_bonus.tier18_4pc", "t18_4pc", 0 },
        { "set_bonus.tier18_2pc", "t18_2pc", 0 },
        { "set_bonus.tier17_4pc", "t17_4pc", 0 },
        { "set_bonus.tier17_2pc", "t17_2pc", 0 },
        { 0 }
    };
}

IC_LOCAL int lookup_var(std::string name)
{
    for (int i = 0; var_list[i].simc; i++)
    {
        if (0 == name.compare(var_list[i].simc)) return i;
    }
    return -1;
}

namespace apltr{
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

IC_LOCAL int lookup_punc(std::string name)
{
    for (int i = 0; punc_list[i]; i++)
    {
        if (0 == name.compare(punc_list[i])) return i;
    }
    return -1;
}


IC_LOCAL int is_digit(char c)
{
    return c >= '0' && c <= '9';
}
IC_LOCAL int is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}
IC_LOCAL int is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}
IC_LOCAL int is_alphabet(char c)
{
    return is_upper(c) || is_lower(c);
}
IC_LOCAL int is_ident(char c)
{
    return is_alphabet(c) || is_digit(c) || c == '_' || c == '.';
}
IC_LOCAL int is_break(char c)
{
    return c == ' ' || c == '\r' || c == '\n' || c == '\t' || c == '\b' || c == EOF;
}

IC_LOCAL double read_const(std::string name)
{
    double value = 0;
    int i;
    for (i = 0; i < name.length(); i++)
    {
        if (is_digit(name.at(i)))
        {
            value *= 10;
            value += (double)(name.at(i) - '0');
        }
        else break;
    }
    if (i < name.length())
    {
        if (name.at(i) == '.')
        {
            i++;
            double radix = 1;
            for (; i < name.length(); i++)
            {
                if (is_digit(name.at(i)))
                {
                    radix *= 0.1;
                    value += radix * (double)(name.at(i) - '0');
                }
                else break;
            }
        }
    }
    return value;
}

struct cond_node_t
{
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
    void dump(std::string& str)
    {
        switch (op)
        {
        case VAR:
            str.append(var_list[(int)value].ic);
            break;
        case CONST:
        {
            char buf[32];
            snprintf(buf, 31, "%ff", value);
            str.append(buf);
        }
        break;
        case AND:
            str.append("(");
            lvalue->dump(str);
            str.append("&&");
            rvalue->dump(str);
            str.append(")");
            break;
        case OR:
            str.append("(");
            lvalue->dump(str);
            str.append("||");
            rvalue->dump(str);
            str.append(")");
            break;
        case NOT:
            str.append("!");
            lvalue->dump(str);
            break;
        case EQ:
            str.append("(");
            lvalue->dump(str);
            str.append("==");
            rvalue->dump(str);
            str.append(")");
            break;
        case NE:
            str.append("(");
            lvalue->dump(str);
            str.append("!=");
            rvalue->dump(str);
            str.append(")");
            break;
        case LT:
            str.append("(");
            lvalue->dump(str);
            str.append("<");
            rvalue->dump(str);
            str.append(")");
            break;
        case GT:
            str.append("(");
            lvalue->dump(str);
            str.append(">");
            rvalue->dump(str);
            str.append(")");
            break;
        case LE:
            str.append("(");
            lvalue->dump(str);
            str.append("<=");
            rvalue->dump(str);
            str.append(")");
            break;
        case GE:
            str.append("(");
            lvalue->dump(str);
            str.append(">=");
            rvalue->dump(str);
            str.append(")");
            break;
        case ADD:
            str.append("(");
            lvalue->dump(str);
            str.append("+");
            rvalue->dump(str);
            str.append(")");
            break;
        case SUB:
            str.append("(");
            lvalue->dump(str);
            str.append("-");
            rvalue->dump(str);
            str.append(")");
            break;
        case NEG:
            str.append("-");
            lvalue->dump(str);
            break;
        case MUL:
            str.append("(");
            lvalue->dump(str);
            str.append("*");
            rvalue->dump(str);
            str.append(")");
            break;
        case DIV:
            str.append("(");
            lvalue->dump(str);
            str.append("/");
            rvalue->dump(str);
            str.append(")");
            break;
        }
    }
};

struct apl_t;

struct rule_t
{
    cond_node_t* cond;
    int action;
    apl_t* run_list;
    int ret_on_call;
    void dump(std::string& str);
    rule_t() {
        cond = 0;
        action = 0;
        run_list = 0;
        ret_on_call = 0;
    }
};

struct apl_t
{
    apl_t* next;
    rule_t* item;
    void dump(std::string& str);
    apl_t() {
        next = 0;
        item = 0;
    }
};

void rule_t::dump(std::string& str)
{
    if (action < 0) return;
    if (run_list && cond)
    {
        str.append("if(");
        cond->dump(str);
        str.append("){\r\n");
        run_list->dump(str);
        if (ret_on_call) {
            str.append("return;\r\n");
        }
        str.append("}");
    }
    else if (run_list && !cond)
    {
        str.append("{\r\n");
        run_list->dump(str);
        if (ret_on_call) {
            str.append("return;\r\n");
        }
        str.append("}");
    }
    else if (cond)
    {
        str.append("if(");
        cond->dump(str);
        str.append(")");
        str.append(act_list[action].ic);
        str.append(";");
    }
    else
    {
        str.append(act_list[action].ic);
        str.append(";");
    }
    str.append("\r\n");
}
void apl_t::dump(std::string& str)
{
    if (item)
    {
        item->dump(str);
        if (next) next->dump(str);
    }
}
namespace apltr{
    IC_LOCAL std::map<std::string, std::vector<token_t> > simc_apls;
}

IC_LOCAL void lexer()
{
    enum
    {
        S_BREAK,
        S_IDENT,
        S_CONST,
    };
    int state = S_BREAK;
    std::string memory;
    for (int lno = 0; lno < source.size(); lno++)
    {
        std::string& line = source.at(lno);
        std::string this_apl;
        if (line[0] == '#') continue; // comment line
        if (strncmp(line.c_str(), "actions", strlen("actions"))) continue; // non apl line
        int pos = strlen("actions");
        memory.clear();
        for (; pos < line.length(); pos++)
        {
            if (is_ident(line[pos])) memory.push_back(line[pos]);
            else if (line[pos] == '=')
            {
                // create a new apl;
                simc_apls[memory].clear();
                this_apl = memory;
                memory.clear();
                pos++;
                break;
            }
            else if (line[pos] == '+' && line.at(pos + 1) == '=')
            {
                // append to a apl;
                this_apl = memory;
                memory.clear();
                pos += 2;
                break;
            }
            else
            {
                eprintf(token(lno, pos, "", ""), 1, "expected apl name or '=' or '+='");
            }
        }
        if (!memory.empty())eprintf(token(lno, pos, "", ""), 1, "unexpected line ending");
        state = S_BREAK;
        for (; pos < line.length(); pos++)
        {
            switch (state)
            {
            case S_BREAK:
                if (is_break(line[pos]))
                {
                    pos = line.length();
                }
                else if (line[pos] == '/')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "/"));
                }
                else if (line[pos] == ',')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, ","));
                }
                else if (line[pos] == '(')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "("));
                }
                else if (line[pos] == ')')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, ")"));
                }
                else if (line[pos] == '&')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "&"));
                }
                else if (line[pos] == '|')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "|"));
                }
                else if (line[pos] == '!')
                {
                    if (pos + 1 < line.length())
                        if (line.at(pos + 1) == '=')
                        {
                            pos++;
                            simc_apls[this_apl].push_back(token(lno, pos, this_apl, "!="));
                        }
                        else
                        {
                            simc_apls[this_apl].push_back(token(lno, pos, this_apl, "!"));
                        }
                }
                else if (line[pos] == '+')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "+"));
                }
                else if (line[pos] == '-')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "-"));
                }
                else if (line[pos] == '*')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "*"));
                }
                else if (line[pos] == '%')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "%"));
                }
                else if (line[pos] == '=')
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "="));
                }
                else if (line[pos] == '>')
                {
                    if (pos + 1 < line.length())
                        if (line.at(pos + 1) == '=')
                        {
                            pos++;
                            simc_apls[this_apl].push_back(token(lno, pos, this_apl, ">="));
                        }
                        else
                        {
                            simc_apls[this_apl].push_back(token(lno, pos, this_apl, ">"));
                        }
                }
                else if (line[pos] == '<')
                {
                    if (pos + 1 < line.length())
                        if (line.at(pos + 1) == '=')
                        {
                            pos++;
                            simc_apls[this_apl].push_back(token(lno, pos, this_apl, "<="));
                        }
                        else
                        {
                            simc_apls[this_apl].push_back(token(lno, pos, this_apl, "<"));
                        }
                }
                else if (is_digit(line[pos]))
                {
                    memory.clear();
                    memory.push_back(line[pos]);
                    state = S_CONST;
                }
                else if (is_alphabet(line[pos]))
                {
                    memory.clear();
                    memory.push_back(line[pos]);
                    state = S_IDENT;
                }
                else
                {
                    eprintf(token(lno, pos, this_apl, ""), 1, "unexpected character '%c'(%02X)", line[pos], (unsigned)line[pos]);
                }
                break;
            case S_IDENT:
                if (is_ident(line[pos]))
                {
                    memory.push_back(line[pos]);
                }
                else
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, memory));
                    pos--;
                    state = S_BREAK;
                }
                break;
            case S_CONST:
                if (is_digit(line[pos]) || line[pos] == '.')
                {
                    memory.push_back(line[pos]);
                }
                else
                {
                    simc_apls[this_apl].push_back(token(lno, pos, this_apl, "", read_const(memory)));
                    pos--;
                    state = S_BREAK;
                }
                break;
            }
        }
    }
}
namespace apltr{
    IC_LOCAL token_t NAL = token(-1, -1, "");
    IC_LOCAL std::stack<int> mark_stack;
    IC_LOCAL int pos;
    IC_LOCAL int last;
    IC_LOCAL std::vector<token_t>* working;
    IC_LOCAL std::map<std::string, apl_t> ic_apls;
}
#define mark() mark_stack.push(pos)
#define unmark() mark_stack.pop()
#define btm() (pos=mark_stack.top())
#define get() (last=std::max(last,pos),pos<working->size()?working->at(pos++):NAL)


IC_LOCAL cond_node_t* constant()
{
    token_t& t = get();
    if (t.value.empty())
    {
        auto node = new cond_node_t;
        node->op = CONST;
        node->value = t.valuef;
        return node;
    }
    return 0;
}
IC_LOCAL cond_node_t* variable()
{
    token_t& t = get();
    if (!t.value.empty() && -1 == lookup_punc(t.value))
    {
        auto node = new cond_node_t;
        node->op = VAR;
        node->value = lookup_var(t.value);
        if (node->value < 0)
        {
            if (!t.suppress) eprintf(t, 0, "unknown variable '%s', assumed as constant false", t.value.c_str());
            node->op = CONST;
            node->value = 0;
            t.suppress = 1;
        }
        return node;
    }
    return 0;
}
IC_LOCAL cond_node_t* logical_expression();
IC_LOCAL cond_node_t* primary_expression()
{
    cond_node_t* child;
    mark();
    if (0 != (child = variable()))
    {
        return unmark(), child;
    }
    btm();
    if (0 != (child = constant()))
    {
        return unmark(), child;
    }
    btm();
    if (get().value == "(")
        if (0 != (child = logical_expression()))
            if (get().value == ")")
            {
                return unmark(), child;
            }
    unmark();
    return 0;
}

IC_LOCAL cond_node_t* unary_expression()
{
    cond_node_t* child;
    mark();
    std::string op = get().value;
    if (op == "+")
    {
        if ((child = unary_expression()) != 0)
        {
            return unmark(), child;
        }
    }
    else if (op == "-" || op == "!")
    {
        if ((child = unary_expression()) != 0)
        {
            auto node = new cond_node_t;
            node->lvalue = child;
            node->op = (op == "-" ? NEG : NOT);
            return unmark(), node;
        }
    }
    btm();
    unmark();
    if (0 != (child = primary_expression()))
    {
        return child;
    }
    return 0;
}

IC_LOCAL cond_node_t* multiplicative_expression()
{
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1)
    {
        if (!(rhs = unary_expression())) return 0;
        mark();
        if (lhs)
        {
            auto node = new cond_node_t;
            node->op = (op == "*" ? MUL : DIV);
            node->lvalue = lhs;
            node->rvalue = rhs;
            lhs = node;
        }
        else
        {
            lhs = rhs;
        }
        op = get().value;
        if (op == "*" || op == "%")
        {
            unmark();
        }
        else
        {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL cond_node_t* additive_expression()
{
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1)
    {
        if (!(rhs = multiplicative_expression())) return 0;
        mark();
        if (lhs)
        {
            auto node = new cond_node_t;
            node->op = (op == "+" ? ADD : SUB);
            node->lvalue = lhs;
            node->rvalue = rhs;
            lhs = node;
        }
        else
        {
            lhs = rhs;
        }
        op = get().value;
        if (op == "+" || op == "-")
        {
            unmark();
        }
        else
        {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL cond_node_t* relational_expression()
{
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1)
    {
        if (!(rhs = additive_expression())) return 0;
        mark();
        if (lhs)
        {
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
        }
        else
        {
            lhs = rhs;
        }
        op = get().value;
        if (op == "=" || op == "!=" || op == "<" || op == "<=" || op == ">" || op == ">=")
        {
            unmark();
        }
        else
        {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL cond_node_t* logical_expression()
{
    cond_node_t* lhs = 0;
    cond_node_t* rhs = 0;
    std::string op;
    while (1)
    {
        if (!(rhs = relational_expression())) return 0;
        mark();
        if (lhs)
        {
            auto node = new cond_node_t;
            node->op = (op == "&" ? AND : OR);
            node->lvalue = lhs;
            node->rvalue = rhs;
            lhs = node;
        }
        else
        {
            lhs = rhs;
        }
        op = get().value;
        if (op == "&" || op == "|")
        {
            unmark();
        }
        else
        {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs) lhs = rhs;
    return lhs;
}

IC_LOCAL int kv_pair(std::string& key, int& vpos)
{
    std::string tkey;
    int tvpos;
    if (get().value == ",")
    {
        token_t& t = get();
        tkey = t.value;
        if (get().value == "=")
        {
            tvpos = pos++;
            if (tvpos >= working->size() || working->at(tvpos).value == "/" || working->at(tvpos).value == ",") return 0;
            if (tkey == "name" || tkey == "if")
            {

            }
            else
            {
                if (!t.suppress)
                {
                    eprintf(t, 0, "unsupported key '%s', ignored", t.value.c_str());
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

IC_LOCAL rule_t* rule_item()
{
    std::string action = get().value;
    if (action == "use_item")
    {
        auto node = new rule_t;
        node->action = -1;
        std::string key;
        int vpos;
        int processed_if = 0;
        int processed_name = 0;
        mark();
        while (kv_pair(key, vpos)) {
            if (key == "name") {
                if (processed_name) {
                    token_t& t = working->at(vpos - 2);
                    if (!t.suppress) eprintf(t, 0, "name duplicated, overwritten");
                    t.suppress = 1;
                }
                node->action = lookup_act(working->at(vpos).value);
                if (node->action < 0) {
                    token_t& t = working->at(vpos);
                    if (!t.suppress) eprintf(t, 0, "unknown item '%s', ignored", t.value.c_str());
                    t.suppress = 1;
                }
                processed_name = 1;
            }
            else if (key == "if") {
                if (processed_if) {
                    token_t& t = working->at(vpos - 2);
                    if (!t.suppress) eprintf(t, 0, "condition duplicated, overwritten");
                    t.suppress = 1;
                }
                pos = vpos;
                node->cond = logical_expression();
                if (!node->cond) {
                    token_t& t = working->at(vpos);
                    if (!t.suppress) eprintf(t, 1, "cannot build condition tree from here");
                    t.suppress = 1;
                }
                processed_if = 1;
            }
            unmark();
            mark();
        }
        btm();
        unmark();
        return node;
    }
    else if (action == "call_action_list" || action == "run_action_list")
    {
        auto node = new rule_t;
        node->action = -1;
        node->ret_on_call = (action == "call_action_list" ? 0 : 1);
        std::string key;
        int vpos;
        int processed_if = 0;
        int processed_name = 0;
        mark();
        while (kv_pair(key, vpos)) {
            if (key == "name") {
                if (processed_name) {
                    token_t& t = working->at(vpos - 2);
                    if (!t.suppress) eprintf(t, 0, "name duplicated, overwritten");
                    t.suppress = 1;
                }
                if (ic_apls.count("." + working->at(vpos).value)) {
                    node->run_list = &ic_apls["." + working->at(vpos).value];
                    node->action = 0;
                }
                else {
                    token_t& t = working->at(vpos);
                    if (!t.suppress) eprintf(t, 0, "action list '%s' do not exist, ignored", t.value.c_str());
                    t.suppress = 1;
                }
                processed_name = 1;
            }
            else if (key == "if") {
                if (processed_if) {
                    token_t& t = working->at(vpos - 2);
                    if (!t.suppress) eprintf(t, 0, "condition duplicated, overwritten");
                    t.suppress = 1;
                }
                pos = vpos;
                node->cond = logical_expression();
                if (!node->cond) {
                    token_t& t = working->at(vpos);
                    if (!t.suppress) eprintf(t, 1, "cannot build condition tree from here");
                    t.suppress = 1;
                }
                processed_if = 1;
            }
            unmark();
            mark();
        }
        btm();
        unmark();
        return node;
    }
    else {
        auto node = new rule_t;
        node->action = lookup_act(action);
        if (node->action < 0) {
            pos--;
            token_t& t = get();
            if (!t.suppress) eprintf(t, 0, "unknown action '%s', ignored", t.value.c_str());
            t.suppress = 1;
        }
        std::string key;
        int vpos;
        int processed_if = 0;
        mark();
        while (kv_pair(key, vpos)) {
            if (key == "name") {
                token_t& t = working->at(vpos - 2);
                if (!t.suppress) eprintf(t, 0, "unsupported key 'name', ignored");
                t.suppress = 1;
            }
            else if (key == "if") {
                if (processed_if) {
                    token_t& t = working->at(vpos - 2);
                    if (!t.suppress) eprintf(t, 0, "condition duplicated, overwritten");
                    t.suppress = 1;
                }
                pos = vpos;
                node->cond = logical_expression();
                if (!node->cond) {
                    token_t& t = working->at(vpos);
                    if (!t.suppress) eprintf(t, 1, "cannot build condition tree from here");
                    t.suppress = 1;
                }
                processed_if = 1;
            }
            unmark();
            mark();
        }
        btm();
        unmark();
        return node;
    }
}

IC_LOCAL apl_t* rule_sequences()
{
    apl_t* lhs = 0;
    rule_t* rhs = 0;
    while (1)
    {
        if (!(rhs = rule_item())) return new apl_t;
        //if (pos < working->size()){
        //  printf("%d:%s\n", pos, working->at(pos).value.c_str());
        //  eprintf(working->at(pos), 2, "check");
        //}
        mark();
        if (lhs)
        {
            auto node = new apl_t;
            auto p = lhs;
            while (p->next)p = p->next;
            p->next = node;
            node->item = rhs;
        }
        else
        {
            lhs = new apl_t;
            lhs->item = rhs;
        }
        if (get().value == "/")
        {
            unmark();
        }
        else
        {
            btm();
            unmark();
            break;
        }
    }
    if (!lhs)
    {
        lhs = new apl_t;
        lhs->item = rhs;
    }
    return lhs;
}
IC_LOCAL void parser()
{
    for (auto i = simc_apls.begin(); i != simc_apls.end(); i++)
    {
        ic_apls[i->first] = apl_t();
    }
    for (auto i = simc_apls.begin(); i != simc_apls.end(); i++)
    {
        working = &i->second;
        pos = 0;
        ic_apls[i->first] = *rule_sequences();
    }
}

IC_LOCAL void reset_gv(){
    apltr::errors = 0;
    apltr::warnings = 0;
    apltr::ic_apls.clear();
    apltr::last = 0;
    apltr::pos = 0;
    while(!apltr::mark_stack.empty())
        apltr::mark_stack.pop();
    apltr::simc_apls.clear();
    apltr::source.clear();
    apltr::working = 0;
}

IC_LOCAL int fapltr(std::string& input_file, std::string& output)
{
    reset_gv();
    read_source(input_file.c_str());
    lexer();
    parser();
    ic_apls[""].dump(output);
    cbprintf("translation complete, %d errors, %d warnings", errors, warnings);
    return 0;
}

IC_LOCAL std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        item.push_back('\n');
        elems.push_back(item);
    }
    return elems;
}


IC_LOCAL std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

IC_LOCAL int sapltr(std::string& input, std::string& output)
{
    reset_gv();
    split(input, '\n', source);
    lexer();
    parser();
    ic_apls[""].dump(output);
    cbprintf("translation complete, %d errors, %d warnings\n", errors, warnings);
    return 0;
}
