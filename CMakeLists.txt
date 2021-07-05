cmake_minimum_required(VERSION 3.19)
project(Steganography)

set(CMAKE_CXX_STANDARD 17)

add_executable(Steganography main.cpp src/utils/argparse.h src/steganography/BaseSteganography.h src/steganography/JpgStegano.h src/steganography/JpgStegano.cpp src/utils/fileutil.h src/steganography/BaseSteganography.cpp src/utils/fileutil.cpp)