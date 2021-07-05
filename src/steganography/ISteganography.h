//
// Created by kyohei.okawa on 2021/07/05.
//

#ifndef STEGANOGRAPHY_ISTEGANOGRAPHY_H
#define STEGANOGRAPHY_ISTEGANOGRAPHY_H

class ISteganography {
public:
    virtual void Insert(std::string imagePath, std::string str) = 0;
    virtual std::vector<std::byte> Load(std::string imagePath) = 0;
};

#endif //STEGANOGRAPHY_ISTEGANOGRAPHY_H
