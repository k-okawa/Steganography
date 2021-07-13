%{
#include "stackmachine/proc.h"
#define YYDEBUG 1
extern char *yytext;
int yyerror(char const *str){
    extern int gLine;
    fprintf(stderr,"%s, line: %d, near %s\n",str, gLine, yytext);
    return 0;
}
%}
%require "3.2"
%language "c++"
%define api.parser.class {PlnParser}
%define api.namespace {palan}
%code requires {
#include "stackmachine/proc.h"
int yylex(palan::PlnParser::semantic_type* yylval);
}
%define api.value.type  variant
%token IDENTIFIER INT_LITERAL DMP  INT_TYPE SEMICOLON
%token LC RC LP RP
%type <Expression*> expression intliteral_expression identifier_expression postfix_expression
%type <StatementList*> statement_list
%type <Statement*>  dump_statement expression_statement compound_statement statement
%type <Declaration*> declaration
%type <DeclarationList*> declaration_list
%type <Root*> root
%type <ParameterList*> parameter_list
%%
root
    :declaration_list
    {
        $$ = StackMachine::get()->addRootDeclarationList($1);
    }
    ;
declaration_list
    :declaration
    {
        $$ = StackMachine::get()->createDeclarationList($1);
    }
    |declaration_list declaration
    {
        $$ = StackMachine::get()->createDeclarationList($1,$2);
    }
    ;
declaration
    :INT_TYPE identifier_expression LP parameter_list RP compound_statement
    {
        $$ = StackMachine::get()->createIntFunctionDeclaration($2,$6);
    }
    ;
parameter_list
    :/*empty*/
    {
        $$ = StackMachine::get()->createParameterList();
    }
    ;
statement_list
    :statement
    {
        $$ = StackMachine::get()->createStatementList($1);
    }
    |statement_list statement
    {
        $$ = StackMachine::get()->createStatementList($1,$2);
    }
statement
    :dump_statement
    |compound_statement
    |expression_statement
expression_statement
    :expression SEMICOLON
    {
        $$ = StackMachine::get()->createExpressionStm($1);
    }
    ;
dump_statement
    :DMP expression SEMICOLON
    {
        $$ = StackMachine::get()->createDumpStm($2);
    }
    ;
compound_statement
    :LC RC
    {
        $$ = StackMachine::get()->createCompoundStatement();
    }
    |LC statement_list RC
    {
        $$ = StackMachine::get()->createCompoundStatement($2);
    }
    ;
expression
    :intliteral_expression
    |identifier_expression
    |postfix_expression
    ;
postfix_expression
    : identifier_expression LP  RP
    {
        $$ = StackMachine::get()->createFunctionCallExp($1);
    }
    ;
identifier_expression
    : IDENTIFIER
    {
        $$ = StackMachine::get()->createIdentifierExp(yytext);
    }
    ;
intliteral_expression
    : INT_LITERAL
    {
       $$ = StackMachine::get()->createIntLiteralExp(yytext);
    }
    ;
%%