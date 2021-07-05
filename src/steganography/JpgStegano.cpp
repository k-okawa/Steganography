//
// Created by kyohei.okawa on 2021/07/05.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "./JpgStegano.h"
#include "../utils/fileutil.h"

void JpgStegano::Insert(std::string imagePath, std::string str) {
    std::vector<char> data = FileUtil::Read(imagePath);
    std::vector<char> insert = Str2Byte(str);

    FileUtil::Write(data, imagePath);
}

std::vector<char> JpgStegano::Load(std::string imagePath) {
    std::vector<char> ret;
    return ret;
}