//
// Created by kyohei.okawa on 2021/07/06.
//

#ifndef STEGANOGRAPHY_PNGSTEGANO_H
#define STEGANOGRAPHY_PNGSTEGANO_H

#include <opencv2/core/hal/interface.h>
#include "BaseSteganography.h"

class PngStegano : BaseSteganography {
public:
    void insert(std::string imagePath, std::string str);
    std::vector<char> load(std::string imagePath);

private:
    void setUnderBit(char& byte, uchar& target, int& bitIndex, std::vector<char>& bitVec);
};


#endif //STEGANOGRAPHY_PNGSTEGANO_H
