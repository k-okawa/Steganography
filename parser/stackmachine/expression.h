//
// Created by kyohei.okawa on 2021/07/13.
//

#ifndef STEGANOGRAPHY_EXPRESSION_H
#define STEGANOGRAPHY_EXPRESSION_H

class Expression : public ObjBase {
protected:
    Expression() {}
public:
    virtual ~Expression() {}
    virtual Value execute() {
        return Value();
    }
};

class IntLiteralExp : public Expression {
    int m_intValue;
public:
    IntLiteralExp(int i = 0) {
        m_intValue = i;
    }
    virtual ~IntLiteralExp() {}
    virtual Value execute() override;
};

class IdentifierExp : public Expression {
    const char* m_Identity;
public:
    IdentifierExp(const char* ident):
            m_Identity(ident)
    {
    }
    const char* getIdentity() const {
        return m_Identity;
    }
    virtual ~IdentifierExp() {}
    virtual Value execute() override;
};

class FunctionCallExp : public Expression {
    const char* m_Identity;
public:
    FunctionCallExp(const char* ident) :
            m_Identity(ident) {
    }
    const char* getIdentity() const {
        return m_Identity;
    }
    virtual ~FunctionCallExp() {}
    virtual Value execute() override;
};

#endif //STEGANOGRAPHY_EXPRESSION_H
