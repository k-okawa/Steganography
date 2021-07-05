//
// Created by kyohei.okawa on 2021/07/05.
//

#ifndef STEGANOGRAPHY_BASESTEGANOGRAPHY_H
#define STEGANOGRAPHY_BASESTEGANOGRAPHY_H

#include <string>

class BaseSteganography {
public:
    virtual void Insert(std::string imagePath, std::string str) = 0;
    virtual std::vector<char> Load(std::string imagePath) = 0;

    std::vector<char> Str2Byte(std::string str) {
        std::vector<char> bytes(str.begin(), str.end());
        bytes.push_back('\0');
        return bytes;
    }
};

#endif //STEGANOGRAPHY_BASESTEGANOGRAPHY_H