// A Bison parser, made by GNU Bison 3.8.2.

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





#include "parser.hh"


// Unqualified %code blocks.
#line 21 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"

#include "Driver.hh"

#line 50 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"


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

namespace yy {
#line 142 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"

  /// Build a parser object.
  parser::parser (tiger::Driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRINGV: // "stringv"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
      case symbol_kind::S_exp: // exp
        value.YY_MOVE_OR_COPY< tiger::Exp* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRINGV: // "stringv"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
      case symbol_kind::S_exp: // exp
        value.move< tiger::Exp* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRINGV: // "stringv"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_unit: // unit
      case symbol_kind::S_exp: // exp
        value.copy< tiger::Exp* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRINGV: // "stringv"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_unit: // unit
      case symbol_kind::S_exp: // exp
        value.move< tiger::Exp* > (that.value);
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
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
        switch (yykind)
    {
      case symbol_kind::S_IDENTIFIER: // "identifier"
#line 111 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 350 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
        break;

      case symbol_kind::S_NUMBER: // "number"
#line 111 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 356 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
        break;

      case symbol_kind::S_STRINGV: // "stringv"
#line 111 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 362 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
        break;

      case symbol_kind::S_unit: // unit
#line 111 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < tiger::Exp* > (); }
#line 368 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
        break;

      case symbol_kind::S_exp: // exp
#line 111 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < tiger::Exp* > (); }
#line 374 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
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

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

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
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRINGV: // "stringv"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_unit: // unit
      case symbol_kind::S_exp: // exp
        yylhs.value.emplace< tiger::Exp* > ();
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
  case 2: // unit: exp
#line 116 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {
        std::cout << "found unit:";
        if(yystack_[0].value.as < tiger::Exp* > ())
            drv.getAstBuilder().setRoot(yystack_[0].value.as < tiger::Exp* > ());
        
    }
#line 656 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 3: // exp: "number"
#line 125 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
   {
    std::cout<<"NUMBER expr found "<<yyla.location<<"\n";
    yylhs.value.as < tiger::Exp* > () = drv.getAstBuilder().buildNumberExp(yyla.location,yystack_[0].value.as < int > ());
    //$$ = new tiger::NumberExp{yyla.location,
    //    static_cast<typename tiger::NumberExp::NumberType>($1)};
   }
#line 667 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 4: // exp: binary_op
#line 131 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
              {std::cout<<"binary_op expr found\n";}
#line 673 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 5: // exp: if_exp
#line 132 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
           {std::cout<<"if_expr found\n";}
#line 679 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 6: // exp: for_exp
#line 133 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {std::cout<<"for_exp found\n";}
#line 685 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 7: // exp: let_exp
#line 134 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 691 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 8: // exp: while_exp
#line 135 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 697 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 9: // exp: fcall
#line 136 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 703 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 10: // exp: "nil"
#line 137 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
        {}
#line 709 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 11: // exp: "stringv"
#line 138 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 715 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 12: // exp: record_value
#line 139 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 {}
#line 721 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 13: // exp: break
#line 140 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 727 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 14: // exp: array_value
#line 141 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 733 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 15: // exp: lvalue
#line 142 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
           {}
#line 739 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 16: // exp: "(" expl ")"
#line 143 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 745 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 17: // exp: "(" ")"
#line 144 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 751 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 18: // expl: exp
#line 148 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
      {}
#line 757 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 19: // expl: expl ";" exp
#line 149 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 763 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 20: // decs: %empty
#line 153 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
        {}
#line 769 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 21: // decs: decs dec
#line 154 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 775 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 22: // dec: vardec
#line 157 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
         {}
#line 781 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 23: // dec: tydec
#line 158 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
         {}
#line 787 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 24: // dec: fundec
#line 159 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 793 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 25: // tydec: "type" type_id "=" ty
#line 163 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                        {}
#line 799 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 26: // ty: type_id
#line 166 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 805 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 27: // ty: "{" "}"
#line 167 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 811 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 28: // ty: "{" tyfields "}"
#line 168 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                    {}
#line 817 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 29: // ty: "array" "of" type_id
#line 169 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                        {}
#line 823 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 30: // tyfield: "identifier" ":" type_id
#line 172 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                         {}
#line 829 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 31: // tyfields: tyfield
#line 175 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 835 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 32: // tyfields: tyfields "," tyfield
#line 176 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                       {}
#line 841 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 33: // type_id: "identifier"
#line 179 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 847 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 34: // type_id: "int"
#line 180 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
         {}
#line 853 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 35: // type_id: "string"
#line 181 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 859 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 36: // vardec: "var" "identifier" ":=" exp
#line 185 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                          {
    std::cout<<"Got vardec:\n";
  }
#line 867 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 37: // vardec: "var" "identifier" ":" type_id ":=" exp
#line 188 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                       {}
#line 873 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 38: // fundec: "function" "identifier" "(" tyfields ")" "=" exp
#line 192 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                               {}
#line 879 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 39: // fundec: "function" "identifier" "(" ")" "=" exp
#line 193 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                       {}
#line 885 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 40: // fundec: "function" "identifier" "(" tyfields ")" ":" type_id "=" exp
#line 194 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                                            {}
#line 891 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 41: // fundec: "function" "identifier" "(" ")" ":" type_id "=" exp
#line 195 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                                   {}
#line 897 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 42: // lvalue: "identifier"
#line 199 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 903 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 43: // lvalue: lvalue1
#line 200 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
           {}
#line 909 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 44: // lvalue1: id_brack
#line 204 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 915 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 45: // lvalue1: "identifier" "." "identifier"
#line 205 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                               {}
#line 921 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 46: // lvalue1: lvalue1 "." "identifier"
#line 206 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {}
#line 927 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 47: // lvalue1: lvalue1 "[" exp "]"
#line 207 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                        {}
#line 933 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 48: // id_brack: type_id "[" exp "]"
#line 210 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {}
#line 939 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 49: // array_value: id_brack "of" exp
#line 214 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                    {}
#line 945 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 50: // fcall: "identifier" "(" ")"
#line 219 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                      {}
#line 951 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 51: // fcall: "identifier" "(" args ")"
#line 220 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {}
#line 957 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 52: // args: exp
#line 223 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
      {}
#line 963 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 53: // args: exp "," args
#line 224 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 {}
#line 969 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 54: // binary_op: exp "|" exp
#line 230 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 975 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 55: // binary_op: exp "&" exp
#line 231 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 981 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 56: // binary_op: exp "=" exp
#line 232 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 987 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 57: // binary_op: exp ":=" exp
#line 233 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 993 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 58: // binary_op: exp "<>" exp
#line 234 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 999 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 59: // binary_op: exp "<" exp
#line 235 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 1005 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 60: // binary_op: exp "<=" exp
#line 236 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 1011 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 61: // binary_op: exp ">" exp
#line 237 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 1017 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 62: // binary_op: exp ">=" exp
#line 238 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 1023 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 63: // binary_op: exp "+" exp
#line 239 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 1029 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 64: // binary_op: exp "-" exp
#line 240 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 1035 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 65: // binary_op: exp "*" exp
#line 241 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 1041 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 66: // binary_op: exp "/" exp
#line 242 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 1047 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 67: // binary_op: "-" exp
#line 243 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                     {std::cout<<"neg found\n";}
#line 1053 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 71: // field_assigns: field_assigns "," field_assign
#line 252 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                   {}
#line 1059 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 72: // field_assign: "identifier" "=" exp
#line 255 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                     {}
#line 1065 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 73: // if_exp: "if" exp "then" exp
#line 259 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                  {std::cout<<"if_then found!"<<std::endl;}
#line 1071 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 74: // if_exp: "if" exp "then" exp "else" exp
#line 260 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {std::cout<<"if_then_else found!\n";}
#line 1077 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 75: // while_exp: "while" exp "do" exp
#line 264 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                   {}
#line 1083 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 76: // for_exp: "for" "identifier" ":=" exp "to" exp "do" exp
#line 268 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                        {}
#line 1089 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 77: // break: "break"
#line 272 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
        {}
#line 1095 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 78: // let_exp: "let" decs "in" expl "end"
#line 276 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                       {}
#line 1101 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;


#line 1105 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"

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
      yy_lac_discard_ ("error recovery");
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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "var", "type", "array", "of",
  "nil", "if", "then", "else", "while", "do", "for", "to", "break", "let",
  "in", "end", "function", "string", "int", ":=", "=", "<>", ">", ">=",
  "<", "<=", "&", "|", "(", ")", "{", "}", "[", "]", ":", "-", "+", "*",
  "/", ";", ".", ",", "identifier", "number", "stringv", "NEG", "$accept",
  "unit", "exp", "expl", "decs", "dec", "tydec", "ty", "tyfield",
  "tyfields", "type_id", "vardec", "fundec", "lvalue", "lvalue1",
  "id_brack", "array_value", "fcall", "args", "binary_op", "record_value",
  "field_assigns", "field_assign", "if_exp", "while_exp", "for_exp",
  "break", "let_exp", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
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
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
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
  parser::yysyntax_error_ (const context& yyctx) const
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


  const signed char parser::yypact_ninf_ = -55;

  const signed char parser::yytable_ninf_ = -34;

  const short
  parser::yypact_[] =
  {
     152,   -55,   152,   152,   -18,   -55,   -55,   -55,   -55,    64,
     152,    57,   -55,   -55,    38,   321,    71,   -55,    73,    28,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    -8,
     198,    43,     9,   -55,   321,    34,   -55,   110,    49,   -55,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,    22,   152,   152,    52,   152,   152,   152,
     152,    56,   -16,   152,    70,   -55,   -55,   -55,   -55,   -55,
     152,   -55,   258,    87,   -55,   341,   349,   349,   349,   349,
     349,   349,   368,   153,   -34,   -34,   -55,   -55,   -55,    97,
      39,   -55,   281,   301,   -55,   321,   178,   321,   238,   -13,
     -55,    99,    -7,    93,   321,   152,   -55,   152,   -55,    82,
     -55,   -55,   152,   152,   152,   -16,    48,   -55,    -9,   -55,
     321,   -55,   321,   218,   321,   106,   123,    29,   -55,   -55,
       2,    95,   -55,    59,   152,   152,   -16,   -55,    55,   152,
     -16,   -16,    41,    88,   321,   321,   -55,   -55,   321,   113,
     -55,   152,   -16,   -55,   152,   321,   114,   321,   152,   321
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    10,     0,     0,     0,    77,    20,    35,    34,     0,
       0,    42,     3,    11,     0,     2,     0,    15,    43,    44,
      14,     9,     4,    12,     5,     8,     6,    13,     7,     0,
       0,     0,     0,    17,    18,     0,    67,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    23,    22,    24,    16,
       0,    50,    52,     0,    45,    57,    56,    58,    61,    62,
      59,    60,    55,    54,    64,    63,    65,    66,    69,     0,
       0,    70,     0,     0,    46,    49,    73,    75,     0,     0,
      33,     0,     0,     0,    19,     0,    51,     0,    68,     0,
      48,    47,     0,     0,     0,     0,     0,    78,     0,    53,
      72,    71,    74,     0,    36,     0,     0,     0,    25,    26,
       0,     0,    31,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,    76,    37,    29,    28,    39,     0,
      30,     0,     0,    32,     0,    38,     0,    41,     0,    40
  };

  const signed char
  parser::yypgoto_[] =
  {
     -55,   -55,     0,    75,   -55,   -55,   -55,   -55,    -3,    16,
     -54,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    40,   -55,
     -55,   -55,    35,   -55,   -55,   -55,   -55,   -55
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    14,    34,    35,    32,    65,    66,   128,   132,   133,
      16,    67,    68,    17,    18,    19,    20,    21,    73,    22,
      23,    90,    91,    24,    25,    26,    27,    28
  };

  const short
  parser::yytable_[] =
  {
      15,    58,    29,    30,     7,     8,    51,    52,   101,   114,
      36,   117,    61,    62,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   130,   115,   139,    63,    31,    64,   100,
      49,    50,    51,    52,    57,    70,   131,    72,    39,   140,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   126,    92,    93,    88,    95,    96,    97,
      98,   125,   129,   137,   151,    60,    69,    89,     7,     8,
     104,     1,     2,   108,   131,     3,    70,     4,   152,     5,
       6,   127,   146,   109,     7,     8,   149,   150,    37,   147,
     -33,   142,   -33,   100,    74,     9,    33,    94,   156,   143,
      38,    99,    10,   143,    53,    72,    54,   120,    55,    11,
      12,    13,   122,   123,   124,   103,    56,     1,     2,   106,
     107,     3,   116,     4,   118,     5,     6,    89,   135,   136,
       7,     8,   141,   131,   144,   145,   154,   158,   102,   148,
     153,     9,    71,   138,   121,   119,     0,     0,    10,     0,
       0,   155,     0,     0,   157,    11,    12,    13,   159,     1,
       2,     0,     0,     3,     0,     4,     0,     5,     6,     0,
       0,     0,     7,     8,     0,     0,    41,    42,    43,    44,
      45,    46,    47,     9,     0,     0,     0,     0,   112,     0,
      10,    49,    50,    51,    52,     0,     0,    11,    12,    13,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      59,     0,     0,     0,     0,     0,    49,    50,    51,    52,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
     134,     0,     0,     0,     0,     0,    49,    50,    51,    52,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,     0,   113,     0,     0,     0,    49,    50,    51,    52,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,     0,     0,     0,     0,     0,    49,    50,    51,    52,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,     0,     0,     0,     0,     0,    49,    50,    51,    52,
       0,     0,   105,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,     0,     0,     0,   110,     0,    49,
      50,    51,    52,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,     0,     0,     0,   111,     0,    49,
      50,    51,    52,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,     0,     0,     0,     0,     0,    49,
      50,    51,    52,   -34,    41,    42,    43,    44,    45,    46,
      47,    48,   -34,   -34,   -34,   -34,   -34,   -34,     0,    49,
      50,    51,    52,     0,     0,     0,     0,    49,    50,    51,
      52,    41,    42,    43,    44,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    50,    51,    52
  };

  const short
  parser::yycheck_[] =
  {
       0,     9,     2,     3,    20,    21,    40,    41,    62,    22,
      10,    18,     3,     4,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    32,    37,    23,    17,    45,    19,    45,
      38,    39,    40,    41,     6,    42,    45,    37,     0,    37,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     5,    54,    55,    34,    57,    58,    59,
      60,   115,   116,    34,    23,    22,    32,    45,    20,    21,
      70,     7,     8,    34,    45,    11,    42,    13,    37,    15,
      16,    33,   136,    44,    20,    21,   140,   141,    31,    34,
      33,    32,    35,    45,    45,    31,    32,    45,   152,    44,
      43,    45,    38,    44,    33,   105,    35,   107,    35,    45,
      46,    47,   112,   113,   114,    45,    43,     7,     8,    32,
      23,    11,    23,    13,    31,    15,    16,    45,    22,     6,
      20,    21,    37,    45,   134,   135,    23,    23,    63,   139,
     143,    31,    32,   127,   109,   105,    -1,    -1,    38,    -1,
      -1,   151,    -1,    -1,   154,    45,    46,    47,   158,     7,
       8,    -1,    -1,    11,    -1,    13,    -1,    15,    16,    -1,
      -1,    -1,    20,    21,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    31,    -1,    -1,    -1,    -1,    10,    -1,
      38,    38,    39,    40,    41,    -1,    -1,    45,    46,    47,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    38,    39,    40,    41,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    44,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    23,    24,    25,    26,    27,    28,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41
  };

  const signed char
  parser::yystos_[] =
  {
       0,     7,     8,    11,    13,    15,    16,    20,    21,    31,
      38,    45,    46,    47,    50,    51,    59,    62,    63,    64,
      65,    66,    68,    69,    72,    73,    74,    75,    76,    51,
      51,    45,    53,    32,    51,    52,    51,    31,    43,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    38,
      39,    40,    41,    33,    35,    35,    43,     6,     9,    12,
      22,     3,     4,    17,    19,    54,    55,    60,    61,    32,
      42,    32,    51,    67,    45,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    34,    45,
      70,    71,    51,    51,    45,    51,    51,    51,    51,    45,
      45,    59,    52,    45,    51,    44,    32,    23,    34,    44,
      36,    36,    10,    14,    22,    37,    23,    18,    31,    67,
      51,    71,    51,    51,    51,    59,     5,    33,    56,    59,
      32,    45,    57,    58,    12,    22,     6,    34,    58,    23,
      37,    37,    32,    44,    51,    51,    59,    34,    51,    59,
      59,    23,    37,    57,    23,    51,    59,    51,    23,    51
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    55,    56,    56,    56,    56,
      57,    58,    58,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    65,
      66,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    74,    75,    76
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     3,
       0,     2,     1,     1,     1,     4,     1,     2,     3,     3,
       3,     1,     3,     1,     1,     1,     4,     6,     7,     6,
       9,     8,     1,     1,     1,     3,     3,     4,     4,     3,
       3,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     4,     3,
       1,     3,     3,     4,     6,     4,     8,     1,     5
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   116,   116,   124,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   148,   149,
     153,   154,   157,   158,   159,   163,   166,   167,   168,   169,
     172,   175,   176,   179,   180,   181,   185,   188,   192,   193,
     194,   195,   199,   200,   204,   205,   206,   207,   210,   214,
     219,   220,   223,   224,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   247,   248,
     251,   252,   255,   259,   260,   264,   268,   272,   276
  };

  void
  parser::yy_stack_print_ () const
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
  parser::yy_reduce_print_ (int yyrule) const
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


} // yy
#line 1814 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"

#line 282 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
