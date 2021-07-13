//
// Created by kyohei.okawa on 2021/07/13.
//

#ifndef STEGANOGRAPHY_COMMON_H
#define STEGANOGRAPHY_COMMON_H

#define MAX_TOKEN_LEN 255

inline string clampToken(const char* ext) {
    string str(ext);
    if(str.size() > MAX_TOKEN_LEN) {
        str.erase(MAX_TOKEN_LEN);
    }
    return str;
}

class ObjBase {
protected:
    ObjBase(){}
public :
    virtual ~ObjBase(){}
};

#endif //STEGANOGRAPHY_COMMON_H
