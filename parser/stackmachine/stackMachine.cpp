//
// Created by kyohei.okawa on 2021/07/13.
//

#include "proc.h"
#include "../PlnLexer.h"

using palan::PlnParser;

Value Root::execute() {
    FunctionCallExp* pFunc = new FunctionCallExp("main");
    pFunc->execute();
    return Value();
}

StackMachine* g_pStackMachine;

StackMachine::StackMachine() {}
StackMachine::~StackMachine() {
    for (size_t i = 0; i < m_objPool.size(); i++) {
        delete m_objPool[i];
    }
    m_objPool.clear();
}

const char* StackMachine::createFixedString(const char *ext) {
    auto str = clampToken(ext);
    auto it = m_fixedStringPool.insert(str);
    return it.first->c_str();
}

int StackMachine::compile(ifstream& f) {
    m_pRoot = new Root();
    PlnLexer lexer;
    lexer.switch_streams(&f, &cout);

    PlnParser parser(lexer);
    if(parser.parse()) {
        return 1;
    }

    return 0;
}

void StackMachine::execute() {
    if(m_pRoot) {
        m_pRoot->execute();
    }
}

void StackMachine::destroy() {
    if(g_pStackMachine) {
        delete g_pStackMachine;
        g_pStackMachine = nullptr;
    }
}

StackMachine* StackMachine::get() {
    if(!g_pStackMachine) {
        g_pStackMachine = new StackMachine();
    }
    return g_pStackMachine;
}

Expression* StackMachine::createIntLiteralExp(const char *ptr) {
    string str = clampToken(ptr);
    auto pObj = new IntLiteralExp(std::stoi(str));
    m_objPool.push_back(pObj);
    return pObj;
}

Expression* StackMachine::createIdentifierExp(const char *ptr) {
    auto pStr = createFixedString(ptr);
    auto pObj = new IdentifierExp(pStr);
    m_objPool.push_back(pObj);
    return pObj;
}

Expression* StackMachine::createFunctionCallExp(Expression *pIdent) {
    auto tgt = dynamic_cast<IdentifierExp*>(pIdent);
    if(tgt) {
        auto pObj = new FunctionCallExp(tgt->getIdentity());
        m_objPool.push_back(pObj);
        return pObj;
    } else {
        cout << "関数呼び出しが間違っています" << endl;
        exit(1);
    }
    return nullptr;
}

Statement* StackMachine::createDumpStm(Expression *exp) {
    auto pObj = new DumpStm(exp);
    m_objPool.push_back(pObj);
    return pObj;
}

Statement* StackMachine::createExpressionStm(Expression *exp) {
    auto pObj = new ExpressionStm(exp);
    m_objPool.push_back(pObj);
    return pObj;
}

Statement* StackMachine::createCompoundStatement(StatementList *stml) {
    auto pObj = new CompoundStatement(stml);
    m_objPool.push_back(pObj);
    return pObj;
}

StatementList* StackMachine::createStatementList(Statement *stm) {
    auto pObj = new StatementList(stm);
    m_objPool.push_back(pObj);
    return pObj;
}

StatementList* StackMachine::createStatementList(StatementList *stml, Statement *stm) {
    StatementList* pos;
    if(stml == nullptr)
        return createStatementList(stm);
    for (pos = stml; pos->getNext(); pos = pos->getNext());
    pos->setNext(createStatementList(stm));
    return stml;
}

ParameterList* StackMachine::createParameterList() {
    auto ptr = new ParameterList();
    m_objPool.push_back(ptr);
    return ptr;
}

Declaration* StackMachine::createIntFunctionDeclaration(Expression *pExp, Statement *stm) {
    IdentifierExp* pIdent = dynamic_cast<IdentifierExp*>(pExp);
    CompoundStatement* pComp = dynamic_cast<CompoundStatement*>(stm);
    if(pIdent && stm) {
        auto pObj = new IntFunctionDeclaration(pIdent, stm);
        m_objPool.push_back(pObj);
        return pObj;
    }
    else {
        cout << "関数定義が間違っています" << endl;
        exit(1);
    }
    return nullptr;
}

DeclarationList* StackMachine::createDeclarationList(Declaration* decl) {
    auto pObj = new DeclarationList(decl);
    m_objPool.push_back(pObj);
    return pObj;
}

DeclarationList* StackMachine::createDeclarationList(DeclarationList* declList, Declaration* decl) {
    DeclarationList* pos;
    if (declList == nullptr)
        return createDeclarationList(decl);
    for (pos = declList; pos->getNext(); pos = pos->getNext())
        ;
    pos->setNext(createDeclarationList(decl));
    return declList;
}

//ルートへのDeclarationListの追加
Root* StackMachine::addRootDeclarationList(DeclarationList* decl) {
    if (m_pRoot) {
        m_pRoot->setDeclList(decl);
    }
    return m_pRoot;
}
