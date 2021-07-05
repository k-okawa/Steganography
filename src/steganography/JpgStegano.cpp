//
// Created by kyohei.okawa on 2021/07/05.
//


#include <string>
#include <vector>
#include "./JpgStegano.h"
#include "../utils/fileutil.h"

void JpgStegano::insert(std::string imagePath, std::string str) {
    std::vector<char> data = FileUtil::read(imagePath);
    std::vector<char> insert = str2Byte(str);

    FileUtil::write(data, imagePath);
}

std::vector<char> JpgStegano::load(std::string imagePath) {
    std::vector<char> ret;
    return ret;
}