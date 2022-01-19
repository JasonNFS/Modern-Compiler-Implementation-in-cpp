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
        std::cout << "found unit:";
        if($1)
            drv.getAstBuilder().setRoot($1);
        
    }
    ;
exp:
   NUMBER
   {
    std::cout<<"NUMBER expr found "<<yyla.location<<"\n";
    $$ = drv.getAstBuilder().buildNumberExp(yyla.location,$1);
    //$$ = new tiger::NumberExp{yyla.location,
    //    static_cast<typename tiger::NumberExp::NumberType>($1)};
   }
   |binary_op {std::cout<<"binary_op expr found\n";}
   |if_exp {std::cout<<"if_expr found\n";}
   |for_exp {std::cout<<"for_exp found\n";}
   |let_exp {} 
   |while_exp{}
   |fcall {}
   |NIL {$$ = drv.getAstBuilder().buildNilExp(yyla.location);}
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
  |exp "+" exp {}
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
  IF exp THEN exp {std::cout<<"if_then found!"<<std::endl;}
  |IF exp THEN exp ELSE exp {std::cout<<"if_then_else found!\n";}
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
