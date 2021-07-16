//
// Created by kyohei.okawa on 2021/07/13.
//

#include "proc.h"

Value::Value()
{
    m_type = ValueType::voidVal;
    intV = 0;
}

Value::Value(bool b)
{
    m_type = ValueType::boolVal;
    boolV = b;
}

Value::Value(int i)
{
    m_type = ValueType::intVal;
    intV = i;
}

Value::Value(double d)
{
    m_type = ValueType::doubleVal;
    doubleV = d;
}

Value::Value(std::string s) {
    m_type = ValueType::stringVal;
    stringV = s;
}

Value::Value(const Value& other)
{
    *this = other;
}

Value& Value::operator=(const Value& other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}