//
// Created by kyohei.okawa on 2021/07/06.
//

#include "PngStegano.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>


void PngStegano::insert(std::string imagePath, std::string str){
    std::vector<char> insertStr = str2Byte(str);
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_UNCHANGED);

    if(image.rows * image.cols * 3 < insertStr.size() * 8) {
        std::cerr << "image size is not enough" << std::endl;
        return;
    }

    // 対象色取得
    std::vector<uchar*> target;
    for(int y = 0; y < image.rows; y++) {
        auto* ptr = image.ptr<cv::Vec4b>(y);
        for(int x = 0; x < image.cols; x++) {
            for(int i = 0; i < 3; i++) {
                target.push_back(&(ptr[x][i]));
            }
            if(target.size() >= insertStr.size() * 8) {
                break;
            }
        }
    }

    // 暗号挿入
    int current = 0;
    for(int i = 0; i < insertStr.size(); i++) {
        for(int j = 0; j < 8; j++) {
            uchar a = insertStr[i] >> j & 0x01;
            if(a == 0x01) {
                // bit on
                *target[current++] |= a;
            } else {
                // bit off
                *target[current++] &= ~0x01;
            }
        }
    }

    cv::imwrite(imagePath, image);
}

std::vector<char> PngStegano::load(std::string imagePath){
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_UNCHANGED);

    std::vector<char> bitVec;
    int currentBitIdx = 0;
    char byte = 0x00;
    int counter = 0;
    for(int y = 0; y < image.rows; y++) {
        auto* ptr = image.ptr<cv::Vec4b>(y);
        for(int x = 0; x < image.cols; x++) {
            for(int i = 0; i < 3; i++) {
                setUnderBit(byte, ptr[x][i], currentBitIdx, bitVec);
                counter++;
            }
        }
    }

    if(bitVec.size() < 2) {
        return std::vector<char>();
    }

    if(!(bitVec[0] == '$' && bitVec[1] == '$')) {
        return std::vector<char>();
    }

    std::vector<char> ret;
    int matchCount = 0;
    for(int i = 2; i < bitVec.size(); i++) {
        if(bitVec[i] == '$') {
            matchCount++;
            if(matchCount >= 2) break;
        } else {
            if(matchCount > 0){
                matchCount--;
            }
        }
        ret.push_back(bitVec[i]);
    }

    if(matchCount < 2) {
        return std::vector<char>();
    }

    ret.erase(ret.begin() + ret.size() - 1);
    return ret;
}

void PngStegano::setUnderBit(char &byte, uchar &target, int &bitIndex, std::vector<char> &bitVec) {
    byte |= (target & 0x01) << bitIndex;
    bitIndex++;
    if(bitIndex >= 8) {
        bitIndex = 0;
        bitVec.push_back(byte);
        byte = 0x00;
    }
}