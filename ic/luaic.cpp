/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
    */

#include "gic.h"

extern "C"{
#define LUA_BUILD_AS_DLL
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
};

jmp_buf panic_backpoint;

// When something bad happens..
extern "C" int Panic(lua_State *L) {
    const char * msg = lua_tostring(L, 1);
    gic::printf("Panic error:\n%s\n", msg);
    longjmp(panic_backpoint, 1); // long jump to avoid abort crashes.
    return 1;
}

extern "C" int lua_print(lua_State* L) {
    int nargs = lua_gettop(L);

    for (int i = 1; i <= nargs; i++) {
        gic::printf("%s", luaL_tolstring(L, i, NULL));
        if (i != nargs){
            gic::printf("\t");
        }
    }
    gic::printf("\n");

    return 0;
}

static const struct luaL_Reg printlib[] = {
    { "print", lua_print },
    { NULL, NULL }
};

const char* str_param_list[] = {
    "actions",
    "simc_actions",
    "rng_engine",
    "trinket1",
    "trinket2",
    "mh_enchant",
    "oh_enchant",
    "mh_type",
    "oh_type",
    "race",
    0,
};

extern "C" int Silence(lua_State* L) {
    if (!lua_gettop(L)) return 0;
    int mode = lua_toboolean(L, 1);
    ic_setprintcallback(mode ? &vprintf : &gic::vgicprintf);
    return 0;
}

// Set a sim parameter.
extern "C" int SetParam(lua_State* L) {
    int n = lua_gettop(L);
    if (n != 2){
        std::string emsg = "wrong number arguments, expected 2, given ";
        emsg += n;
        lua_pushlstring(L, emsg.c_str(), emsg.length());
        lua_error(L);
    }
    if (!lua_isstring(L, 1)){
        lua_pushliteral(L, "expected string for argument 1");
        lua_error(L);
    }
    const char* key = lua_tostring(L, 1);
    const char* value = lua_tostring(L, 2); // casting by lua.
    ic_setparam(key, value); // just throw into libic... so easy.
    return 0;
}

// Get a sim parameter current value.
extern "C" int GetParam(lua_State *L) {
    int n = lua_gettop(L);
    if (n != 1){
        std::string emsg = "wrong number arguments, expected 1, given ";
        emsg += n;
        lua_pushlstring(L, emsg.c_str(), emsg.length());
        lua_error(L);
    }
    if (!lua_isstring(L, 1)){
        lua_pushliteral(L, "expected string");
        lua_error(L);
    }
    const char* key = lua_tostring(L, 1);
    const char* value = ic_getparam(key);
    lua_pushstring(L, value); // lua will do the casting / nil filling.
    return 1;
}

// Get default APL as string.
extern "C" int GetDefaultAPL(lua_State *L) {
    std::string apl = ic_defaultapl();
    lua_pushlstring(L, apl.c_str(), apl.length());
    return 1;
}

// Translate SimC-style APL to IreCore-style.
extern "C" int TranslateAPL(lua_State *L) {
    if (!lua_gettop(L)) return 0;
    std::string apl = ic_apltranslate_s(lua_tostring(L, 1));
    lua_pushlstring(L, apl.c_str(), apl.length());
    return 1;
}

// Start a sim.
extern "C" int Run(lua_State *L){
    float dps, dpsr, dpse, sim_time;
    int ret = ic_runsim(&dps, &dpsr, &dpse, &sim_time);
    lua_pushnumber(L, dps);
    lua_pushnumber(L, dpsr);
    lua_pushnumber(L, dpse);
    if (!atoi(ic_getparam("developer_debug")))
        if (ret >= 0){
            QSettings history;
            qulonglong iterations = history.value("statistics/iterations", 0).toULongLong();
            qulonglong cputime = history.value("statistics/cputime", 0).toULongLong();
            qulonglong combatlength = history.value("statistics/combatlength", 0).toULongLong();
            iterations += atoi(ic_getparam("iterations"));
            cputime += (qulonglong)(sim_time * 1000);
            combatlength += (qulonglong)(atof(ic_getparam("max_length")) * atoi(ic_getparam("iterations")));
            history.setValue("statistics/iterations", iterations);
            history.setValue("statistics/cputime", cputime);
            history.setValue("statistics/combatlength", combatlength);
        }

    return 3;
}

#define lua_nregister(L, f) lua_register(L, #f, f)
void gic::run_scripts(){
    lua_State *L = luaL_newstate();
    if (!L) abort();
    luaL_openlibs(L);

    lua_atpanic(L, Panic);

    lua_nregister(L, Silence);
    lua_nregister(L, SetParam);
    lua_nregister(L, GetParam);
    lua_nregister(L, GetDefaultAPL);
    lua_nregister(L, TranslateAPL);
    lua_nregister(L, Run);

    lua_getglobal(L, "_G");
    luaL_setfuncs(L, printlib, 0);
    lua_pop(L, 1);

    QString script = ui.txtScript->toPlainText();

    if (setjmp(panic_backpoint)){
        ic_setprintcallback(&gic::vgicprintf);
        gic::printq(QApplication::translate("gicClass", "Error occured while script executing.") + "\n");
        QMetaObject::invokeMethod(ui.btnRun, "setDisabled", Q_ARG(bool, false));
        return;
    }
    gic::set_parameters();
    luaL_loadstring(L, script.toLocal8Bit());
    lua_call(L, 0, 0);
    lua_close(L);
    ic_setprintcallback(&gic::vgicprintf);
    QMetaObject::invokeMethod(ui.btnRun, "setDisabled", Q_ARG(bool, false));
    usage_statistics();
    return;
}