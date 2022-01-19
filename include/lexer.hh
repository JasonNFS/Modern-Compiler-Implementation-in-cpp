#ifndef PARSER_LEXER_HH
#define PARSER_LEXER_HH
#include "parser.hh"
#include "Driver.hh"
// Give Flex the prototype of yylex we want ...
// #define YY_DECL yy::parser::symbol_type yylex()
// ... and declare it for the parser's sake.
// YY_DECL;
void initialize_lexer(tiger::Driver &drv);
#endif //PARSER_LEXER_HH
