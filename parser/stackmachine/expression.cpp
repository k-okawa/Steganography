//
// Created by kyohei.okawa on 2021/07/13.
//

#include "proc.h"

Value IntLiteralExp::execute() {
    return Value(m_intValue);
}

Value IdentifierExp::execute() {
    return Value();
}

Value FunctionCallExp::execute() {
    bool flg = false;
    auto pRoot = StackMachine::get()->getRoot();
    auto pos = pRoot->getDeclList();
    do {
        auto decl = pos->getDecl();
        auto tgt = dynamic_cast<IntFunctionDeclaration*>(decl);
        if (tgt) {
            string str = tgt->getIdentity();
            if (str == m_Identity) {
                flg = true;
                tgt->excute();
                break;
            }
        }
        pos = pos->getNext();
    } while (pos);
    if (!flg) {
        cout << "関数が見つかりません。: " << m_Identity << endl;
        exit(1);
    }
    return Value();
}