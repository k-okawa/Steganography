cmake_minimum_required(VERSION 3.19)
project(Steganography)

set(CMAKE_CXX_STANDARD 17)

# Lua
set(lua_path ${CMAKE_CURRENT_SOURCE_DIR}/lib/lua)
file( GLOB_RECURSE lua_sources ${lua_path}/src/*.c )
list( REMOVE_ITEM lua_sources
        ${lua_path}/src/lua.c
        ${lua_path}/src/luac.c
        )

include_directories(${lua_path}/src)
add_executable(Steganography main.cpp src/utils/argparse.h src/steganography/BaseSteganography.h src/steganography/JpgStegano.h src/steganography/JpgStegano.cpp src/utils/fileutil.h src/steganography/BaseSteganography.cpp src/utils/fileutil.cpp src/steganography/PngStegano.cpp src/steganography/PngStegano.h src/lua/LuaEngine.cpp src/lua/LuaEngine.h ${lua_sources})

# OpenCv　参考 https://blog.yucchiy.com/2014/09/16/clion-opencv/
find_package(OpenCV REQUIRED)
target_link_libraries(Steganography ${OpenCV_LIBS})