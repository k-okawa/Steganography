//
// Created by kyohei.okawa on 2021/07/13.
//


#include "proc.h"

void IntFunctionDeclaration::excute() {
    if (m_pCompoundStatement) {
        m_pCompoundStatement->execute();
    }
}
