#include "utils.hh"

FILE* tigertest::string2file(const std::string &str){
  FILE *tmp = tmpfile();
  if (!tmp)
    throw std::runtime_error("open temp file failed!");
  fputs(str.c_str(), tmp);
  rewind(tmp);
  return tmp;
}