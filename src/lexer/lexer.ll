
%{ /* -*- C++ -*- */
#pragma GCC diagnostic ignored "-Wregister"
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "driver.hh"
# include "parser.hh"
# include "lexer.hh"
%}

%option noyywrap nounput noinput batch debug

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type
  make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
  static tiger::Driver *driver;
  //initialize this lexer
  void initialize_lexer(tiger::Driver &drv){
    yyin = drv.getSourceFile();
    yy_flex_debug = false;
  //  driver = &drv;
  }

%}

id    [a-zA-Z_][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%x comment
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.getLocation();
  // Code run each time yylex is called.
  loc.step ();
%}
{blank}+   loc.step ();

"/*"         BEGIN(comment);

<comment>[^*\n]*        /* eat anything that's not a '*' */
<comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<comment>\n             loc.lines (yyleng);
<comment>"*"+"/"        loc.step ();BEGIN(INITIAL);

\n+        loc.lines (yyleng); loc.step ();
var   return yy::parser::make_VAR(loc);
string return yy::parser::make_STRING(loc);
type  return yy::parser::make_TYPE(loc);
array return yy::parser::make_ARRAY(loc);
of    return yy::parser::make_OF(loc);
nil   return yy::parser::make_NIL(loc);
if    return yy::parser::make_IF(loc);
then  return yy::parser::make_THEN(loc);
else  return yy::parser::make_ELSE(loc);
while  return yy::parser::make_WHILE(loc);
do  return yy::parser::make_DO(loc);
for  return yy::parser::make_FOR(loc);
to  return yy::parser::make_TO(loc);
break  return yy::parser::make_BREAK(loc);
let  return yy::parser::make_LET(loc);
in  return yy::parser::make_IN(loc);
end  return yy::parser::make_END(loc);
function  return yy::parser::make_FUNCTION(loc);
\"[^"]*\"  return yy::parser::make_STRINGV(yytext,loc);

":="       return yy::parser::make_ASSIGN (loc);
"=" return yy::parser::make_EQ(loc);
"<>"  return yy::parser::make_NEQ(loc);
">" return yy::parser::make_GT(loc);
">="  return yy::parser::make_GE(loc);
"<"   return yy::parser::make_LT(loc);
"<="  return yy::parser::make_LE(loc);
"&" return yy::parser::make_AND(loc);
"|"   return yy::parser::make_OR(loc);
"("        return yy::parser::make_LPAREN (loc);
")"        return yy::parser::make_RPAREN (loc);
"{"   return yy::parser::make_LBRACE(loc);
"}"   return yy::parser::make_RBRACE(loc);
"["   return yy::parser::make_LBRACK(loc);
"]"   return yy::parser::make_RBRACK(loc);
":"   return yy::parser::make_COLON(loc);
"-"        return yy::parser::make_MINUS  (loc);
"+"        return yy::parser::make_PLUS   (loc);
"*"        return yy::parser::make_STAR   (loc);
"/"        return yy::parser::make_SLASH  (loc);
";"        return yy::parser::make_SEMIC(loc);
"."        return yy::parser::make_DOT(loc);
","        return yy::parser::make_COMMA(loc);

{int}      return make_NUMBER (yytext, loc);
{id}       return yy::parser::make_IDENTIFIER (yytext, loc);
.          {
             throw yy::parser::syntax_error
               (loc, "invalid character: " + std::string(yytext));
}
<<EOF>>    return yy::parser::make_YYEOF (loc);
%%

yy::parser::symbol_type
make_NUMBER (const std::string &s, const yy::parser::location_type& loc)
{
  errno = 0;
  long n = strtol (s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER ((int) n, loc);
}


