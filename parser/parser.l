%{
#include <stdio.h>
#include "parser.tab.hh"

extern int yywrap( void ){ return 1 ; }
%}

%s COMMENT
%s LINE_COMMENT
%%
<INITIAL>{
    "("     return LP;
    ")"     return RP;
    "{"     return LC;
    "}"     return RC;
    ";"     return SEMICOLON;
    "dump"     return DMP;
    "int"       return INT_TYPE;
    "/*"    { BEGIN(COMMENT);}
    [/][/]+ { BEGIN(LINE_COMMENT);}
    [1-9][0-9]* {
        return INT_LITERAL;
    }
    [A-Za-z_][A-Za-z_0-9]* {
        return IDENTIFIER;
    }
    "\n"    {gLine++;}
    [ \t]   ;
    .   { return 0;}
}
<COMMENT>{
    "\n"    {gLine++;}
    "*/" {BEGIN(INITIAL);}
    .   ;
}
<LINE_COMMENT>{
    "\n" { gLine++; BEGIN(INITIAL);}
    .   ;
}
%%

int yylex(PlnParser::semantic_type* yylval, PlnParser::location_type* location, PlnLexer& lexer)
{
	return lexer.yylex(*yylval, *location);
}