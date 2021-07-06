//
// Created by kyohei.okawa on 2021/07/05.
//

#include "BaseSteganography.h"

std::vector<char> BaseSteganography::str2Byte(std::string str) {
    str = "$$" + str + "$$";
    std::vector<char> bytes(str.begin(), str.end());
    bytes.push_back('\0');
    return bytes;
}