//
// Created by kyohei.okawa on 2021/07/05.
//

#ifndef STEGANOGRAPHY_BASESTEGANOGRAPHY_H
#define STEGANOGRAPHY_BASESTEGANOGRAPHY_H

#include <vector>
#include <string>

class BaseSteganography {
public:
    virtual void insert(std::string imagePath, std::string str) = 0;
    virtual std::vector<char> load(std::string imagePath) = 0;

    std::vector<char> str2Byte(std::string str);
};

#endif //STEGANOGRAPHY_BASESTEGANOGRAPHY_H
