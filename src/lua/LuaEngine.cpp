//
// Created by kyohei.okawa on 2021/07/08.
//

#include "LuaEngine.h"

LuaEngine* LuaEngine::_instance = nullptr;

LuaEngine::LuaEngine() {

}

LuaEngine::~LuaEngine() {
    lua_close(_luaState);
    delete _instance;
    _instance = nullptr;
}

LuaEngine* LuaEngine::getInstance() {
    if(_instance == nullptr) {
        _instance = new LuaEngine();
        _instance->init();
    }

    return _instance;
}

void LuaEngine::init() {
    _luaState = luaL_newstate();
    luaL_openlibs(_luaState);
    luaL_dostring(_luaState, "print('hello, lua!')");
}