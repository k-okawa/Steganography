//
// Created by kyohei.okawa on 2021/07/13.
//

#include "proc.h"

Value DumpStm::execute() {
    if (m_expression) {
        auto val = m_expression->execute();
        switch (val.m_type) {
            case ValueType::intVal:
                cout << val.intV << endl;
                break;
        }
    }
    return Value();
}

Value ExpressionStm::execute() {
    if (m_expression) {
        auto val = m_expression->execute();
    }
    return Value();
}


void StatementList::execute() {
    auto pos = this;
    do {
        auto stm = pos->getStm();
        stm->execute();
        pos = pos->getNext();
    } while (pos);

}

Value CompoundStatement::execute() {
    if (m_pStatementList) {
        m_pStatementList->execute();
    }
    return Value();
}