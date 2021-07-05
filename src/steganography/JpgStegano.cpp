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
    std::vector<std::byte> data = FileUtil::Read(imagePath);
    FileUtil::Write(data, imagePath);
}

std::vector<std::byte> JpgStegano::Load(std::string imagePath) {
    std::vector<std::byte> ret;
    return ret;
}