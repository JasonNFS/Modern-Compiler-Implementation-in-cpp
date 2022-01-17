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
#line 20 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"

#include "driver.hh"

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
#line 108 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 330 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
        break;

      case symbol_kind::S_NUMBER: // "number"
#line 108 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 336 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
        break;

      case symbol_kind::S_STRINGV: // "stringv"
#line 108 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 342 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
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
  case 2: // exp: "number"
#line 115 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {std::cout<<"NUMBER expr found\n";}
#line 614 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 3: // exp: binary_op
#line 116 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
              {std::cout<<"binary_op expr found\n";}
#line 620 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 4: // exp: if_exp
#line 117 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
           {std::cout<<"if_expr found\n";}
#line 626 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 5: // exp: for_exp
#line 118 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {std::cout<<"for_exp found\n";}
#line 632 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 6: // exp: let_exp
#line 119 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 638 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 7: // exp: while_exp
#line 120 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 644 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 8: // exp: fcall
#line 121 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 650 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 9: // exp: "nil"
#line 122 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
        {}
#line 656 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 10: // exp: "stringv"
#line 123 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 662 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 11: // exp: record_value
#line 124 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 {}
#line 668 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 12: // exp: break
#line 125 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 674 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 13: // exp: array_value
#line 126 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 680 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 14: // exp: lvalue
#line 127 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
           {}
#line 686 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 15: // exp: "(" expl ")"
#line 128 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 692 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 16: // exp: "(" ")"
#line 129 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 698 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 17: // expl: exp
#line 133 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
      {}
#line 704 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 18: // expl: expl ";" exp
#line 134 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 710 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 19: // decs: %empty
#line 138 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
        {}
#line 716 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 20: // decs: decs dec
#line 139 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 722 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 21: // dec: vardec
#line 142 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
         {}
#line 728 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 22: // dec: tydec
#line 143 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
         {}
#line 734 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 23: // dec: fundec
#line 144 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 740 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 24: // tydec: "type" type_id "=" ty
#line 148 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                        {}
#line 746 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 25: // ty: type_id
#line 151 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 752 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 26: // ty: "{" "}"
#line 152 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 758 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 27: // ty: "{" tyfields "}"
#line 153 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                    {}
#line 764 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 28: // ty: "array" "of" type_id
#line 154 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                        {}
#line 770 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 29: // tyfield: "identifier" ":" type_id
#line 157 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                         {}
#line 776 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 30: // tyfields: tyfield
#line 160 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
          {}
#line 782 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 31: // tyfields: tyfields "," tyfield
#line 161 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                       {}
#line 788 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 32: // type_id: "identifier"
#line 164 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 794 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 33: // type_id: "int"
#line 165 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
         {}
#line 800 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 34: // type_id: "string"
#line 166 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
            {}
#line 806 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 35: // vardec: "var" "identifier" ":=" exp
#line 170 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                          {
    std::cout<<"Got vardec:\n";
  }
#line 814 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 36: // vardec: "var" "identifier" ":" type_id ":=" exp
#line 173 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                       {}
#line 820 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 37: // fundec: "function" "identifier" "(" tyfields ")" "=" exp
#line 177 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                               {}
#line 826 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 38: // fundec: "function" "identifier" "(" ")" "=" exp
#line 178 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                       {}
#line 832 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 39: // fundec: "function" "identifier" "(" tyfields ")" ":" type_id "=" exp
#line 179 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                                            {}
#line 838 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 40: // fundec: "function" "identifier" "(" ")" ":" type_id "=" exp
#line 180 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                                   {}
#line 844 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 41: // lvalue: "identifier"
#line 184 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 850 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 42: // lvalue: lvalue1
#line 185 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
           {}
#line 856 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 43: // lvalue1: id_brack
#line 189 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 862 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 44: // lvalue1: "identifier" "." "identifier"
#line 190 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                               {}
#line 868 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 45: // lvalue1: lvalue1 "." "identifier"
#line 191 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {}
#line 874 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 46: // lvalue1: lvalue1 "[" exp "]"
#line 192 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                        {}
#line 880 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 47: // id_brack: type_id "[" exp "]"
#line 195 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {}
#line 886 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 48: // array_value: id_brack "of" exp
#line 199 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                    {}
#line 892 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 49: // fcall: "identifier" "(" ")"
#line 204 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                      {}
#line 898 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 50: // fcall: "identifier" "(" args ")"
#line 205 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {}
#line 904 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 51: // args: exp
#line 208 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
      {}
#line 910 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 52: // args: exp "," args
#line 209 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                 {}
#line 916 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 53: // binary_op: exp "|" exp
#line 215 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
             {}
#line 922 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 54: // binary_op: exp "&" exp
#line 216 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 928 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 55: // binary_op: exp "=" exp
#line 217 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 934 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 56: // binary_op: exp ":=" exp
#line 218 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 940 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 57: // binary_op: exp "<>" exp
#line 219 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 946 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 58: // binary_op: exp "<" exp
#line 220 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 952 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 59: // binary_op: exp "<=" exp
#line 221 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 958 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 60: // binary_op: exp ">" exp
#line 222 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 964 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 61: // binary_op: exp ">=" exp
#line 223 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                {}
#line 970 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 62: // binary_op: exp "+" exp
#line 224 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 976 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 63: // binary_op: exp "-" exp
#line 225 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 982 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 64: // binary_op: exp "*" exp
#line 226 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 988 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 65: // binary_op: exp "/" exp
#line 227 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
               {}
#line 994 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 66: // binary_op: "-" exp
#line 228 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                     {std::cout<<"neg found\n";}
#line 1000 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 70: // field_assigns: field_assigns "," field_assign
#line 237 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                   {}
#line 1006 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 71: // field_assign: "identifier" "=" exp
#line 240 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                     {}
#line 1012 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 72: // if_exp: "if" exp "then" exp
#line 244 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                  {std::cout<<"if_then found!"<<std::endl;}
#line 1018 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 73: // if_exp: "if" exp "then" exp "else" exp
#line 245 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                            {std::cout<<"if_then_else found!\n";}
#line 1024 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 74: // while_exp: "while" exp "do" exp
#line 249 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                   {}
#line 1030 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 75: // for_exp: "for" "identifier" ":=" exp "to" exp "do" exp
#line 253 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                                        {}
#line 1036 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 76: // break: "break"
#line 257 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
        {}
#line 1042 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;

  case 77: // let_exp: "let" decs "in" expl "end"
#line 261 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"
                       {}
#line 1048 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"
    break;


#line 1052 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"

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
  "exp", "expl", "decs", "dec", "tydec", "ty", "tyfield", "tyfields",
  "type_id", "vardec", "fundec", "lvalue", "lvalue1", "id_brack",
  "array_value", "fcall", "args", "binary_op", "record_value",
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

  const signed char parser::yytable_ninf_ = -33;

  const short
  parser::yypact_[] =
  {
     203,   -55,   203,   203,   -39,   -55,   -55,   -55,   -55,   147,
     203,    60,   -55,   -55,   101,    29,   -55,    72,     3,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    -8,   249,
      12,     9,   -55,   352,    -5,   -55,   175,   -20,   -55,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,    21,   203,   203,    20,   203,   203,   203,   203,
      55,   -16,   203,    57,   -55,   -55,   -55,   -55,   -55,   203,
     -55,   289,    76,   -55,   372,   380,   380,   380,   380,   380,
     380,   399,   204,    77,    77,   -55,   -55,   -55,    91,    50,
     -55,   312,   332,   -55,   352,   229,   352,    49,   -14,   -55,
      96,    -7,    89,   352,   203,   -55,   203,   -55,    87,   -55,
     -55,   203,   203,   203,   -16,    47,   -55,    38,   -55,   352,
     -55,   352,   269,   352,    99,   116,    71,   -55,   -55,     1,
      98,   -55,    66,   203,   203,   -16,   -55,    65,   203,   -16,
     -16,    59,    92,   352,   352,   -55,   -55,   352,   113,   -55,
     203,   -16,   -55,   203,   352,   120,   352,   203,   352
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     9,     0,     0,     0,    76,    19,    34,    33,     0,
       0,    41,     2,    10,     0,     0,    14,    42,    43,    13,
       8,     3,    11,     4,     7,     5,    12,     6,     0,     0,
       0,     0,    16,    17,     0,    66,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    22,    21,    23,    15,     0,
      49,    51,     0,    44,    56,    55,    57,    60,    61,    58,
      59,    54,    53,    63,    62,    64,    65,    68,     0,     0,
      69,     0,     0,    45,    48,    72,    74,     0,     0,    32,
       0,     0,     0,    18,     0,    50,     0,    67,     0,    47,
      46,     0,     0,     0,     0,     0,    77,     0,    52,    71,
      70,    73,     0,    35,     0,     0,     0,    24,    25,     0,
       0,    30,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,    75,    36,    28,    27,    38,     0,    29,
       0,     0,    31,     0,    37,     0,    40,     0,    39
  };

  const signed char
  parser::yypgoto_[] =
  {
     -55,     0,    82,   -55,   -55,   -55,   -55,     4,    19,   -54,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,    43,   -55,   -55,
     -55,    40,   -55,   -55,   -55,   -55,   -55
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    33,    34,    31,    64,    65,   127,   131,   132,    15,
      66,    67,    16,    17,    18,    19,    20,    72,    21,    22,
      89,    90,    23,    24,    25,    26,    27
  };

  const short
  parser::yytable_[] =
  {
      14,    57,    28,    29,     7,     8,    30,   100,   113,    56,
      35,   116,    60,    61,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   114,   138,    73,    62,    68,    63,    99,
      48,    49,    50,    51,    59,    69,    71,    69,   139,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   125,    91,    92,    87,    94,    95,    96,    97,
     124,   128,    52,   112,    53,    93,    88,     7,     8,   103,
     129,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     126,   145,   150,   130,   107,   148,   149,    48,    49,    50,
      51,    36,    99,   -32,   108,   -32,   151,   155,   141,   146,
      98,    38,   102,    37,    71,   136,   119,    54,   105,   142,
     142,   121,   122,   123,   106,    55,   130,    50,    51,   115,
     117,   134,   135,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    88,   143,   144,   140,   153,   130,   147,    48,
      49,    50,    51,   157,   101,   137,   152,   118,   120,     0,
     154,     0,     0,   156,     1,     2,     0,   158,     3,     0,
       4,     0,     5,     6,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    32,
       0,     0,     1,     2,     0,    10,     3,     0,     4,     0,
       5,     6,    11,    12,    13,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    70,     0,     0,
       1,     2,     0,    10,     3,     0,     4,     0,     5,     6,
      11,    12,    13,     7,     8,     0,     0,    40,    41,    42,
      43,    44,    45,    46,     9,     0,     0,     0,     0,   111,
       0,    10,    48,    49,    50,    51,     0,     0,    11,    12,
      13,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    58,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,   133,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,     0,     0,   104,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,   109,     0,
      48,    49,    50,    51,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,   110,     0,
      48,    49,    50,    51,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,   -33,    40,    41,    42,    43,    44,
      45,    46,    47,   -33,   -33,   -33,   -33,   -33,   -33,     0,
      48,    49,    50,    51,     0,     0,     0,     0,    48,    49,
      50,    51,    40,    41,    42,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51
  };

  const short
  parser::yycheck_[] =
  {
       0,     9,     2,     3,    20,    21,    45,    61,    22,     6,
      10,    18,     3,     4,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    37,    23,    45,    17,    32,    19,    45,
      38,    39,    40,    41,    22,    42,    36,    42,    37,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     5,    53,    54,    34,    56,    57,    58,    59,
     114,   115,    33,    14,    35,    45,    45,    20,    21,    69,
      32,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      33,   135,    23,    45,    34,   139,   140,    38,    39,    40,
      41,    31,    45,    33,    44,    35,    37,   151,    32,    34,
      45,     0,    45,    43,   104,    34,   106,    35,    32,    44,
      44,   111,   112,   113,    23,    43,    45,    40,    41,    23,
      31,    22,     6,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    45,   133,   134,    37,    23,    45,   138,    38,
      39,    40,    41,    23,    62,   126,   142,   104,   108,    -1,
     150,    -1,    -1,   153,     7,     8,    -1,   157,    11,    -1,
      13,    -1,    15,    16,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,     7,     8,    -1,    38,    11,    -1,    13,    -1,
      15,    16,    45,    46,    47,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
       7,     8,    -1,    38,    11,    -1,    13,    -1,    15,    16,
      45,    46,    47,    20,    21,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    31,    -1,    -1,    -1,    -1,    10,
      -1,    38,    38,    39,    40,    41,    -1,    -1,    45,    46,
      47,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    44,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    23,    24,    25,    26,    27,    28,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41
  };

  const signed char
  parser::yystos_[] =
  {
       0,     7,     8,    11,    13,    15,    16,    20,    21,    31,
      38,    45,    46,    47,    50,    58,    61,    62,    63,    64,
      65,    67,    68,    71,    72,    73,    74,    75,    50,    50,
      45,    52,    32,    50,    51,    50,    31,    43,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    38,    39,
      40,    41,    33,    35,    35,    43,     6,     9,    12,    22,
       3,     4,    17,    19,    53,    54,    59,    60,    32,    42,
      32,    50,    66,    45,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    34,    45,    69,
      70,    50,    50,    45,    50,    50,    50,    50,    45,    45,
      58,    51,    45,    50,    44,    32,    23,    34,    44,    36,
      36,    10,    14,    22,    37,    23,    18,    31,    66,    50,
      70,    50,    50,    50,    58,     5,    33,    55,    58,    32,
      45,    56,    57,    12,    22,     6,    34,    57,    23,    37,
      37,    32,    44,    50,    50,    58,    34,    50,    58,    58,
      23,    37,    56,    23,    50,    58,    50,    23,    50
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    54,    55,    55,    55,    55,    56,
      57,    57,    58,    58,    58,    59,    59,    60,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    63,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    73,    74,    75
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     3,     0,
       2,     1,     1,     1,     4,     1,     2,     3,     3,     3,
       1,     3,     1,     1,     1,     4,     6,     7,     6,     9,
       8,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     4,     3,     1,
       3,     3,     4,     6,     4,     8,     1,     5
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   115,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   133,   134,   138,
     139,   142,   143,   144,   148,   151,   152,   153,   154,   157,
     160,   161,   164,   165,   166,   170,   173,   177,   178,   179,
     180,   184,   185,   189,   190,   191,   192,   195,   199,   204,
     205,   208,   209,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   232,   233,   236,
     237,   240,   244,   245,   249,   253,   257,   261
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
#line 1769 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.cpp"

#line 267 "/Users/kyg/Documents/gits/Modern-Compiler-Implementation-in-cpp/src/parser/parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
