// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 15 "parser.y"

#define LOC(J, L) J["loc"] = { lexer.cur_fid, (int)L.begin.line, (int)L.begin.column, (int)L.end.line, (int)L.end.column }
#define LOC_BE(J, B, E) J["loc"] = { lexer.cur_fid, (int)B.begin.line, (int)B.begin.column, (int)E.end.line, (int)E.end.column }

#line 44 "PlnParser.cpp"




#include "PlnParser.hpp"


// Unqualified %code blocks.
#line 21 "parser.y"

#include "PlnLexer.h"

int yylex(	palan::PlnParser::semantic_type* yylval,
			palan::PlnParser::location_type* location,
			PlnLexer& lexer);

#line 61 "PlnParser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 30 "parser.y"
namespace palan {
#line 154 "PlnParser.cpp"

  /// Build a parser object.
  PlnParser::PlnParser (PlnLexer &lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg)
  {}

  PlnParser::~PlnParser ()
  {}

  PlnParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  PlnParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_declaration: // declaration
        value.copy< Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< DeclarationList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_identifier_expression: // identifier_expression
      case symbol_kind::S_intliteral_expression: // intliteral_expression
        value.copy< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< ParameterList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_root: // root
        value.copy< Root* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_dump_statement: // dump_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.copy< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.copy< StatementList* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  PlnParser::symbol_kind_type
  PlnParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  PlnParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  PlnParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_declaration: // declaration
        value.move< Declaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< DeclarationList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_identifier_expression: // identifier_expression
      case symbol_kind::S_intliteral_expression: // intliteral_expression
        value.move< Expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< ParameterList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_root: // root
        value.move< Root* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_dump_statement: // dump_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< Statement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< StatementList* > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  PlnParser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  PlnParser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  PlnParser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  PlnParser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  PlnParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  PlnParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  PlnParser::symbol_kind_type
  PlnParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  PlnParser::symbol_kind_type
  PlnParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  PlnParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  PlnParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  PlnParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  PlnParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  PlnParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  PlnParser::symbol_kind_type
  PlnParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  PlnParser::stack_symbol_type::stack_symbol_type ()
  {}

  PlnParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.YY_MOVE_OR_COPY< DeclarationList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_identifier_expression: // identifier_expression
      case symbol_kind::S_intliteral_expression: // intliteral_expression
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< ParameterList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_root: // root
        value.YY_MOVE_OR_COPY< Root* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_dump_statement: // dump_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.YY_MOVE_OR_COPY< StatementList* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  PlnParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
        value.move< Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< DeclarationList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_identifier_expression: // identifier_expression
      case symbol_kind::S_intliteral_expression: // intliteral_expression
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< ParameterList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_root: // root
        value.move< Root* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_dump_statement: // dump_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< StatementList* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  PlnParser::stack_symbol_type&
  PlnParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< DeclarationList* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_identifier_expression: // identifier_expression
      case symbol_kind::S_intliteral_expression: // intliteral_expression
        value.copy< Expression* > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< ParameterList* > (that.value);
        break;

      case symbol_kind::S_root: // root
        value.copy< Root* > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_dump_statement: // dump_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.copy< Statement* > (that.value);
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.copy< StatementList* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  PlnParser::stack_symbol_type&
  PlnParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_declaration: // declaration
        value.move< Declaration* > (that.value);
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        value.move< DeclarationList* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_identifier_expression: // identifier_expression
      case symbol_kind::S_intliteral_expression: // intliteral_expression
        value.move< Expression* > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< ParameterList* > (that.value);
        break;

      case symbol_kind::S_root: // root
        value.move< Root* > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_dump_statement: // dump_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< Statement* > (that.value);
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< StatementList* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  PlnParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  PlnParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  PlnParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  PlnParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  PlnParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  PlnParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  PlnParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  PlnParser::debug_level_type
  PlnParser::debug_level () const
  {
    return yydebug_;
  }

  void
  PlnParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  PlnParser::state_type
  PlnParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  PlnParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  PlnParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  PlnParser::operator() ()
  {
    return parse ();
  }

  int
  PlnParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, lexer));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< Declaration* > ();
        break;

      case symbol_kind::S_declaration_list: // declaration_list
        yylhs.value.emplace< DeclarationList* > ();
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_identifier_expression: // identifier_expression
      case symbol_kind::S_intliteral_expression: // intliteral_expression
        yylhs.value.emplace< Expression* > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< ParameterList* > ();
        break;

      case symbol_kind::S_root: // root
        yylhs.value.emplace< Root* > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_dump_statement: // dump_statement
      case symbol_kind::S_compound_statement: // compound_statement
        yylhs.value.emplace< Statement* > ();
        break;

      case symbol_kind::S_statement_list: // statement_list
        yylhs.value.emplace< StatementList* > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: declaration_list
#line 47 "parser.y"
    {
        yylhs.value.as < Root* > () = StackMachine::get()->addRootDeclarationList(yystack_[0].value.as < DeclarationList* > ());
    }
#line 877 "PlnParser.cpp"
    break;

  case 3: // declaration_list: declaration
#line 53 "parser.y"
    {
        yylhs.value.as < DeclarationList* > () = StackMachine::get()->createDeclarationList(yystack_[0].value.as < Declaration* > ());
    }
#line 885 "PlnParser.cpp"
    break;

  case 4: // declaration_list: declaration_list declaration
#line 57 "parser.y"
    {
        yylhs.value.as < DeclarationList* > () = StackMachine::get()->createDeclarationList(yystack_[1].value.as < DeclarationList* > (),yystack_[0].value.as < Declaration* > ());
    }
#line 893 "PlnParser.cpp"
    break;

  case 5: // declaration: INT_TYPE identifier_expression LP parameter_list RP compound_statement
#line 63 "parser.y"
    {
        yylhs.value.as < Declaration* > () = StackMachine::get()->createIntFunctionDeclaration(yystack_[4].value.as < Expression* > (),yystack_[0].value.as < Statement* > ());
    }
#line 901 "PlnParser.cpp"
    break;

  case 6: // parameter_list: %empty
#line 69 "parser.y"
    {
        yylhs.value.as < ParameterList* > () = StackMachine::get()->createParameterList();
    }
#line 909 "PlnParser.cpp"
    break;

  case 7: // statement_list: statement
#line 75 "parser.y"
    {
        yylhs.value.as < StatementList* > () = StackMachine::get()->createStatementList(yystack_[0].value.as < Statement* > ());
    }
#line 917 "PlnParser.cpp"
    break;

  case 8: // statement_list: statement_list statement
#line 79 "parser.y"
    {
        yylhs.value.as < StatementList* > () = StackMachine::get()->createStatementList(yystack_[1].value.as < StatementList* > (),yystack_[0].value.as < Statement* > ());
    }
#line 925 "PlnParser.cpp"
    break;

  case 9: // statement: dump_statement
#line 83 "parser.y"
     { yylhs.value.as < Statement* > () = yystack_[0].value.as < Statement* > (); }
#line 931 "PlnParser.cpp"
    break;

  case 10: // statement: compound_statement
#line 84 "parser.y"
     { yylhs.value.as < Statement* > () = yystack_[0].value.as < Statement* > (); }
#line 937 "PlnParser.cpp"
    break;

  case 11: // statement: expression_statement
#line 85 "parser.y"
     { yylhs.value.as < Statement* > () = yystack_[0].value.as < Statement* > (); }
#line 943 "PlnParser.cpp"
    break;

  case 12: // expression_statement: expression SEMICOLON
#line 88 "parser.y"
    {
        yylhs.value.as < Statement* > () = StackMachine::get()->createExpressionStm(yystack_[1].value.as < Expression* > ());
    }
#line 951 "PlnParser.cpp"
    break;

  case 13: // dump_statement: DMP expression SEMICOLON
#line 94 "parser.y"
    {
        yylhs.value.as < Statement* > () = StackMachine::get()->createDumpStm(yystack_[1].value.as < Expression* > ());
    }
#line 959 "PlnParser.cpp"
    break;

  case 14: // compound_statement: LC RC
#line 100 "parser.y"
    {
        yylhs.value.as < Statement* > () = StackMachine::get()->createCompoundStatement();
    }
#line 967 "PlnParser.cpp"
    break;

  case 15: // compound_statement: LC statement_list RC
#line 104 "parser.y"
    {
        yylhs.value.as < Statement* > () = StackMachine::get()->createCompoundStatement(yystack_[1].value.as < StatementList* > ());
    }
#line 975 "PlnParser.cpp"
    break;

  case 16: // expression: intliteral_expression
#line 109 "parser.y"
     { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 981 "PlnParser.cpp"
    break;

  case 17: // expression: identifier_expression
#line 110 "parser.y"
     { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 987 "PlnParser.cpp"
    break;

  case 18: // expression: postfix_expression
#line 111 "parser.y"
     { yylhs.value.as < Expression* > () = yystack_[0].value.as < Expression* > (); }
#line 993 "PlnParser.cpp"
    break;

  case 19: // postfix_expression: identifier_expression LP RP
#line 115 "parser.y"
    {
        yylhs.value.as < Expression* > () = StackMachine::get()->createFunctionCallExp(yystack_[2].value.as < Expression* > ());
    }
#line 1001 "PlnParser.cpp"
    break;

  case 20: // identifier_expression: IDENTIFIER
#line 121 "parser.y"
    {
        yylhs.value.as < Expression* > () = StackMachine::get()->createIdentifierExp(lexer.YYText());
    }
#line 1009 "PlnParser.cpp"
    break;

  case 21: // intliteral_expression: INT_LITERAL
#line 127 "parser.y"
    {
       yylhs.value.as < Expression* > () = StackMachine::get()->createIntLiteralExp(lexer.YYText());
    }
#line 1017 "PlnParser.cpp"
    break;


#line 1021 "PlnParser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  PlnParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  PlnParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  PlnParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // PlnParser::context.
  PlnParser::context::context (const PlnParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  PlnParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  PlnParser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  PlnParser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char PlnParser::yypact_ninf_ = -4;

  const signed char PlnParser::yytable_ninf_ = -1;

  const signed char
  PlnParser::yypact_[] =
  {
       5,     7,    14,     5,    -4,    -4,     6,    -4,    -4,    -4,
       8,     9,    -3,    -4,    -4,     0,    -4,     4,    -4,    -4,
      -4,    -4,    11,    -4,    10,    -4,    15,    -4,    -4,    -4,
      12,    -4,    -4
  };

  const signed char
  PlnParser::yydefact_[] =
  {
       0,     0,     0,     2,     3,    20,     0,     1,     4,     6,
       0,     0,     0,     5,    21,     0,    14,     0,     7,    11,
       9,    10,     0,    18,    17,    16,     0,    15,     8,    12,
       0,    13,    19
  };

  const signed char
  PlnParser::yypgoto_[] =
  {
      -4,    -4,    -4,    18,    -4,    -4,    -2,    -4,    -4,    13,
      16,    -4,    24,    -4
  };

  const signed char
  PlnParser::yydefgoto_[] =
  {
       0,     2,     3,     4,    10,    17,    18,    19,    20,    21,
      22,    23,    24,    25
  };

  const signed char
  PlnParser::yytable_[] =
  {
       5,    14,    15,     5,    14,    12,    16,     5,    14,    15,
       5,     1,    12,    27,     7,    28,     9,    12,    29,    11,
      30,     8,    31,    32,    13,     6,     0,     0,     0,     0,
       0,    26
  };

  const signed char
  PlnParser::yycheck_[] =
  {
       3,     4,     5,     3,     4,     8,     9,     3,     4,     5,
       3,     6,     8,     9,     0,    17,    10,     8,     7,    11,
      10,     3,     7,    11,    11,     1,    -1,    -1,    -1,    -1,
      -1,    15
  };

  const signed char
  PlnParser::yystos_[] =
  {
       0,     6,    13,    14,    15,     3,    24,     0,    15,    10,
      16,    11,     8,    21,     4,     5,     9,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    22,     9,    18,     7,
      10,     7,    11
  };

  const signed char
  PlnParser::yyr1_[] =
  {
       0,    12,    13,    14,    14,    15,    16,    17,    17,    18,
      18,    18,    19,    20,    21,    21,    22,    22,    22,    23,
      24,    25
  };

  const signed char
  PlnParser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     6,     0,     1,     2,     1,
       1,     1,     2,     3,     2,     3,     1,     1,     1,     3,
       1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const PlnParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_LITERAL", "DMP", "INT_TYPE", "SEMICOLON", "LC", "RC", "LP", "RP",
  "$accept", "root", "declaration_list", "declaration", "parameter_list",
  "statement_list", "statement", "expression_statement", "dump_statement",
  "compound_statement", "expression", "postfix_expression",
  "identifier_expression", "intliteral_expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  PlnParser::yyrline_[] =
  {
       0,    46,    46,    52,    56,    62,    69,    74,    78,    83,
      84,    85,    87,    93,    99,   103,   109,   110,   111,   114,
     120,   126
  };

  void
  PlnParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  PlnParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  PlnParser::symbol_kind_type
  PlnParser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11
    };
    // Last valid token kind.
    const int code_max = 266;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 30 "parser.y"
} // palan
#line 1552 "PlnParser.cpp"

#line 131 "parser.y"


namespace palan
{
void PlnParser::error(const location_type& l, const string& m)
{

}
}
