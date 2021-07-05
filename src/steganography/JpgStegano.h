//
// Created by kyohei.okawa on 2021/07/05.
//

#ifndef STEGANOGRAPHY_JPGSTEGANO_H
#define STEGANOGRAPHY_JPGSTEGANO_H

#include "./BaseSteganography.h"

class JpgStegano : BaseSteganography {
public:
    void insert(std::string imagePath, std::string str);
    std::vector<char> load(std::string imagePath);

private:
    bool isJpg(std::vector<char> data);
    int getSosIndex(std::vector<char> data);
};

#endif //STEGANOGRAPHY_JPGSTEGANO_H
