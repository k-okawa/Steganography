//
// Created by kyohei.okawa on 2021/07/05.
//

#include <iostream>
#include <string>
#include <vector>
#include "./JpgStegano.h"
#include "../utils/fileutil.h"
#include "../utils/byteutil.h"

void JpgStegano::insert(std::string imagePath, std::string str) {
    std::vector<char> data = FileUtil::read(imagePath);
    if(!isJpg(data)) {
        std::cerr << "not jpg format" << std::endl;
        return;
    }

    // 画像データの開始地点を検索
    int sosIndex = getSosIndex(data);
    int imgIndex = sosIndex + 0xc + 1;

    int elSize = data.size() - imgIndex - 2;

    // ステガノ対象になるバイトを抽出
    std::vector<char*> targetVec;
    for(int i = imgIndex; i < imgIndex + elSize; i++) {
        targetVec.push_back(&data[i]);
    }

    // 暗号挿入
    std::vector<char> insertStr = str2Byte(str);
    int current = 0;
    for(int i = 0; i < insertStr.size(); i++) {
        for(int j = 0; j < 8; j++) {
            char a = insertStr[i] >> j & 0x01;
            *targetVec[current++] ^= a;
        }
    }

    std::cout << elSize << std::endl;

    FileUtil::write(data, imagePath);
}

bool JpgStegano::isJpg(std::vector<char> data) {
    if(data.size() < 5) {
        return false;
    }

    int size = data.size();
    return data[0] == (char)0xff && data[1] == (char)0xd8 && data[size-2] == (char)0xff && data[size-1] == (char)0xd9;
}

int JpgStegano::getSosIndex(std::vector<char> data) {
    int sosIndex = 0;
    for(int i = 0; i < data.size() - 2; i++) {
        if(data[i] == (char)0xff && data[i+1] == (char)0xda) {
            sosIndex = i;
            break;
        }
    }
    return sosIndex;
}

std::vector<char> JpgStegano::load(std::string imagePath) {
    std::vector<char> ret;
    return ret;
}