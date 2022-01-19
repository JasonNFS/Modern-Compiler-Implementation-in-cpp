#include <vector>
#include <cstdio>
#include <map>
#include <string>

using namespace std::string_literals;
namespace tigertest{
/// open a temp file for reading. Caller ought to close it.
FILE *string2file(const std::string &str);

}// namespace tigertest