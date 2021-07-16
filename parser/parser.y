%skeleton "lalr1.cc"
%require "3.2"
%defines
%define api.parser.class {PlnParser}
%parse-param	{ PlnLexer &lexer }
%lex-param		{ PlnLexer &lexer }

%code requires
{
#include "stackmachine/proc.h"
class PlnLexer;
}

%code top
{
#define LOC(J, L) J["loc"] = { lexer.cur_fid, (int)L.begin.line, (int)L.begin.column, (int)L.end.line, (int)L.end.column }
#define LOC_BE(J, B, E) J["loc"] = { lexer.cur_fid, (int)B.begin.line, (int)B.begin.column, (int)E.end.line, (int)E.end.column }
}

%code
{
#include "PlnLexer.h"

int yylex(	palan::PlnParser::semantic_type* yylval,
			palan::PlnParser::location_type* location,
			PlnLexer& lexer);
}

%locations
%define api.namespace {palan}
%define parse.error	verbose
%define api.value.type	variant

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
        $$ = StackMachine::get()->createIdentifierExp(lexer.YYText());
    }
    ;
intliteral_expression
    : INT_LITERAL
    {
       $$ = StackMachine::get()->createIntLiteralExp(lexer.YYText());
    }
    ;
%%

namespace palan
{
void PlnParser::error(const location_type& l, const string& m)
{

}
}