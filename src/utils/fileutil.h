//
// Created by kyohei.okawa on 2021/07/05.
//

#ifndef STEGANOGRAPHY_FILEUTIL_H
#define STEGANOGRAPHY_FILEUTIL_H

#include <stdio.h>
#include <fstream>
#include <iostream>

namespace FileUtil {

    std::vector<char> read(std::string path) {
        std::ifstream ifs(path, std::ios::binary);
        if (ifs.fail()) {
            std::cerr << "Failed to open file" << std::endl;
            return std::vector<char>();
        }


        ifs.seekg(0, std::ios::end);
        long long int size = ifs.tellg();
        ifs.seekg(0);

        char *data = new char[size];
        ifs.read(data, size);
        std::vector<char> ret;
        for(int i = 0; i < size; i++) {
            ret.push_back(data[i]);
        }
        delete[] data;

        ifs.close();
        return ret;
    }

    void write(std::vector<char> data, std::string path) {
        std::ofstream fout(path, std::ios::out | std::ios::binary | std::ios::trunc);

        if (fout.fail()) {
            std::cerr << "Failed to open file" << std::endl;
            return;
        }

        for(int i = 0; i < data.size(); i++) {
            fout.write((char *)&data[i], sizeof(char));
        }

        fout.close();
    }

}

#endif //STEGANOGRAPHY_FILEUTIL_H
