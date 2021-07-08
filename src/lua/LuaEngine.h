//
// Created by kyohei.okawa on 2021/07/08.
//

#ifndef STEGANOGRAPHY_LUAENGINE_H
#define STEGANOGRAPHY_LUAENGINE_H

#include <string>
#include "lua.hpp"

class LuaEngine {
public:
    static LuaEngine* getInstance();
    void execString(std::string str);
    void execFile(std::string path);
    void execFunc(std::string funcName);

protected:
    LuaEngine();
    ~LuaEngine();
    void init();

private:
    static LuaEngine* _instance;
    lua_State* _luaState;
};


#endif //STEGANOGRAPHY_LUAENGINE_H
