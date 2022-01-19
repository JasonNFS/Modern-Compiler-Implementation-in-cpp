#include "YYDriver.hh"
#include "lexer.hh"
using namespace tiger;

int YYDriver::pre_parse()
{
  parser.set_debug_level(false);
  initialize_lexer(*this);
  return 0;
}
int YYDriver::post_parse()
{
  return 0;
}
