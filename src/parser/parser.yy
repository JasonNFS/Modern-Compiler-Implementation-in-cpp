%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
#pragma clang diagnostic ignored "-Wdeprecated-register"
  #include <string>
  #include <iostream>
  #include "Ast.hh"
  namespace tiger {
    class Driver;
  }
}

%code {
#include "Driver.hh"
using namespace tiger;
}
%param { tiger::Driver& drv }

// %code {
//   #define YY_DECL yy::parser::symbol_type yylex()
//   YY_DECL;
// }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full


%define api.token.prefix {TOK_}

// keywords
%token
  VAR "var"
  TYPE "type"
  ARRAY "array"
  OF  "of"
  NIL "nil"
  IF "if"
  THEN "then"
  ELSE "else"
  WHILE "while"
  DO "do"
  FOR "for"
  TO "to"
  BREAK "break"
  LET "let"
  IN "in"
  END "end"
  FUNCTION "function"
  STRING "string"
  INT "int"

%token
  ASSIGN  ":="
  EQ      "="
  NEQ     "<>"
  GT      ">"
  GE      ">="
  LT      "<"
  LE      "<="
  AND     "&"
  OR      "|"
  LPAREN  "("
  RPAREN  ")"
  LBRACE  "{"
  RBRACE  "}"
  LBRACK  "["
  RBRACK  "]"
  COLON   ":"
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  SEMIC   ";"
  DOT     "."
  COMMA   ","
  ;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token <std::string> STRINGV "stringv"
%nterm <tiger::Exp*> exp
%nterm <tiger::Exp*> unit
%nterm <tiger::BinaryOpExp*> binary_op
%nterm <tiger::IfExp*> if_exp

//declare precedence
%precedence OF
%precedence FOR TO DO
%precedence THEN
%precedence ELSE
%left ";"
%nonassoc ":=";
%left "|";
%left "&";
%nonassoc "=" "<>" "<" "<=" ">" ">=";
%left "+" "-";
%left "*" "/";
%precedence NEG;
%precedence "(";
%precedence ")";

%printer { yyo << $$; } <*>;

%%
%start unit;

unit:   exp {
        if($1)
            drv.getAstBuilder().setRoot($1);
    }
    ;
exp:
   NUMBER {$$ = drv.getAstBuilder().BuildNumberExp(yyla.location,$1);}
   |binary_op {$$ = $1;}
   |if_exp {$$ = $1;}
   |for_exp {std::cout<<"for_exp found\n";}
   |let_exp {} 
   |while_exp{}
   |fcall {}
   |NIL {$$ = drv.getAstBuilder().BuildNilExp(yyla.location);}
   |STRINGV {}
   |record_value {}
   |break {};
   |array_value {}
   |lvalue {}
   |"(" expl ")"{}
   |"(" ")" {}
  ;

expl:
  exp {}
  |expl ";" exp {}
  ;

decs:
  %empty{}
  |decs dec {}
  ;
dec:
  vardec {}
  |tydec {}
  |fundec {}
  ;

tydec:
  "type" type_id "=" ty {}
  ;
ty:
  type_id {}
  |"{"  "}" {}
  |"{" tyfields "}" {}
  |"array" "of" type_id {}
  ;
tyfield:
  IDENTIFIER ":" type_id {}
  ;
tyfields:
  tyfield {}
  |tyfields "," tyfield{}
  ;
type_id:
  IDENTIFIER {}
  |"int" {}
  |"string" {}
  ;

vardec:
  VAR IDENTIFIER ":=" exp {
    std::cout<<"Got vardec:\n";
  }
  |VAR IDENTIFIER ":" type_id ":=" exp {}
  ;

fundec:
  FUNCTION IDENTIFIER "(" tyfields ")" "=" exp {}
  |FUNCTION IDENTIFIER "(" ")" "=" exp {}
  |FUNCTION IDENTIFIER "(" tyfields ")" ":" type_id "=" exp {}
  |FUNCTION IDENTIFIER "(" ")" ":" type_id "=" exp {}
  ;

lvalue:
  IDENTIFIER {}
  |lvalue1 {}
  ;

lvalue1:
    id_brack {}
    |IDENTIFIER "." IDENTIFIER {}
    |lvalue1 "." IDENTIFIER {}
    |lvalue1 "[" exp "]"{}
    ;
id_brack:
        type_id "[" exp "]" {}
        ;

array_value:
  id_brack "of" exp {}
  ;


fcall:
  IDENTIFIER "(" ")"  {}
  |IDENTIFIER "(" args ")"  {}
  ;
args:
  exp {}
  | exp "," args {}
  ;



binary_op:
  exp "|" exp{}
  |exp "&" exp {}
  |exp "=" exp {}
  |exp ":=" exp {}
  |exp "<>" exp {}
  |exp "<" exp {}
  |exp "<=" exp {}
  |exp ">" exp {}
  |exp ">=" exp {}
  |exp "+" exp {$$ = drv.getAstBuilder().BuildBinaryOpExp(yyla.location,$1,$3,BinaryOpExp::OpType::plus);}
  |exp "-" exp {}
  |exp "*" exp {}
  |exp "/" exp {}
  |"-" exp %prec NEG {std::cout<<"neg found\n";}
  ;

record_value:
  type_id "{" field_assigns "}"
  |type_id "{" "}"
  ;
field_assigns:
  field_assign
  | field_assigns "," field_assign {}
  ;
field_assign:
  IDENTIFIER "=" exp {}
  ;

if_exp:
  IF exp THEN exp {$$ = drv.getAstBuilder().BuildIfExp(yyla.location,$2,$4);}
  |IF exp THEN exp ELSE exp {$$ = drv.getAstBuilder().BuildIfExp(yyla.location,$2,$4,$6);}
  ;

while_exp:
  WHILE exp DO exp {}
  ;

for_exp:
  FOR IDENTIFIER ":=" exp TO exp DO exp {}
  ;

break:
  BREAK {}
  ;

let_exp:
  LET decs IN expl END {}
  ;

//assign_exp:
//  lvalue ASSIGN exp {}
//  ;
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
