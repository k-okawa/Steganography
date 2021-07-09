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

 # src
file( GLOB_RECURSE src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(Steganography main.cpp ${src} ${lua_sources})

# OpenCv　参考 https://blog.yucchiy.com/2014/09/16/clion-opencv/
find_package(OpenCV REQUIRED)
target_link_libraries(Steganography ${OpenCV_LIBS})