//
// Created by kyohei.okawa on 2021/07/13.
//

#ifndef STEGANOGRAPHY_VALUE_H
#define STEGANOGRAPHY_VALUE_H

enum class ValueType {
    voidVal = 0,
    boolVal,
    intVal,
    doubleVal,
};

struct Value {
    ValueType m_type;
    union {
        bool boolV;
        int intV;
        double doubleV;
    };
    explicit Value();
    explicit Value(bool b);
    explicit Value(int i);
    explicit Value(double d);
    Value(const Value& other);
    Value& operator=(const Value& other);
    ~Value() {}
};

#endif //STEGANOGRAPHY_VALUE_H
