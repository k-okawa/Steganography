%{
#include "PlnParser.hpp"
#include "PlnLexer.h"

using std::cout;
using std::endl;
using std::string;

using namespace palan;

#undef YY_DECL
#define YY_DECL int PlnLexer::yylex(PlnParser::semantic_type& lval, PlnParser::location_type& loc)
#define YY_USER_ACTION	loc.columns(yyleng);

enum {
    LP = PlnParser::token::LP,
    RP = PlnParser::token::RP,
    LC = PlnParser::token::LC,
    RC = PlnParser::token::RC,
    SEMICOLON = PlnParser::token::SEMICOLON,
    DMP = PlnParser::token::DMP,
    INT_TYPE = PlnParser::token::INT_TYPE,
    INT_LITERAL = PlnParser::token::INT_LITERAL,
    IDENTIFIER = PlnParser::token::IDENTIFIER,
};

static string& unescape(string& str);

%}
%option c++
%option yyclass="PlnLexer"
%option noyywrap

COMMENT1	\/\/[^\n]*\n
%%
%{
	loc.begin.filename = &filenames[cur_fid];
	loc.end.filename = &filenames[cur_fid];
	loc.step();
%}

{COMMENT1}	{ loc.lines(); loc.step(); }
<INITIAL>{
    "("     return LP;
    ")"     return RP;
    "{"     return LC;
    "}"     return RC;
    ";"     return SEMICOLON;
    "dump"     return DMP;
    "int"       return INT_TYPE;
    [1-9][0-9]* {
        return INT_LITERAL;
    }
    [A-Za-z_][A-Za-z_0-9]* {
        return IDENTIFIER;
    }
    [ \t]+		{ loc.step(); }
    \r\n|\r|\n	{ loc.lines(); loc.step(); }
    .	{
	    	cerr << "Lexer: Unrecognized char \"" << yytext[0] << "\"" << endl;
	    	loc.step();
	    }
}

%%

int yylex(PlnParser::semantic_type* yylval, PlnParser::location_type* location, PlnLexer& lexer)
{
	return lexer.yylex(*yylval, *location);
}
inline int hexc(int c)
{
	if (c>='0' && c<='9') return c-'0';
	if (c>='a' && c<='f') return 10+c-'a';
	if (c>='A' && c<='F') return 10+c-'A';
	return -1;
}
static string& unescape(string& str)
{
	int sz = str.size();
	int d=0;
	for (int s=0; s<sz; ++s,++d) {
		if (str[s] != '\\') {
			str[d] = str[s];
			continue;
		}

		++s;

		switch(str[s]) {
			case 'a': str[d] = '\a'; break;
			case 'b': str[d] = '\b'; break;
			case 'n': str[d] = '\n'; break;
			case 'r': str[d] = '\r'; break;
			case 't': str[d] = '\t'; break;
			case 'v': str[d] = '\v'; break;
			case '0': str[d] = '\0'; break;
			case 'x': {
				int h1 = hexc(str[s+1]), h2 = hexc(str[s+2]);
				if (h1 >= 0 && h2 >= 0) {
					str[d] = 16*h1 + h2; s+=2;
				} else {
					str[d] = 'x';
				}
			} break;
			default: str[d] = str[s];
		} /* switch */
	}
	str.resize(d);
	return str;
}
void PlnLexer::set_filename(const string& filename)
{
	filenames.push_back(filename);
	cur_fid = filenames.size()-1;
}