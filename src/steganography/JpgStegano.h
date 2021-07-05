//
// Created by kyohei.okawa on 2021/07/05.
//

#ifndef STEGANOGRAPHY_JPGSTEGANO_H
#define STEGANOGRAPHY_JPGSTEGANO_H

#include "./BaseSteganography.h"

class JpgStegano : BaseSteganography {
public:
    void Insert(std::string imagePath, std::string str);
    std::vector<char> Load(std::string imagePath);
};

#endif //STEGANOGRAPHY_JPGSTEGANO_H
