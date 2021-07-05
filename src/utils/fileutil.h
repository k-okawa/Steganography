//
// Created by kyohei.okawa on 2021/07/05.
//

#ifndef STEGANOGRAPHY_FILEUTIL_H
#define STEGANOGRAPHY_FILEUTIL_H

namespace FileUtil {
    std::vector<char> read(std::string path);
    void write(std::vector<char> data, std::string path);
}

#endif //STEGANOGRAPHY_FILEUTIL_H
