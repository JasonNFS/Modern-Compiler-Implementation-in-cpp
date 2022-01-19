#include "YYDriver.hh"
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

namespace {
const std::string &getUsage()
{
  static std::string usage = R"(usage:
    tiger input)";
  return usage;
}

}// namespace
using namespace std;

int main(int argc, char **argv)
{
  auto &logger = std::cout;
  vector<string> args(argv, argv + argc);
  if (argc != 2) {
    logger << getUsage() << '\n';
    return 1;
  }
  FILE *input;
  string filename = args[1];
  if (filename == "-") {
    input = stdin;
  } else {
    input = fopen(filename.c_str(), "r");
    if (!input)
      logger << "input file open failed.\n";
  }
  tiger::YYDriver driver(input, filename);
  int success = driver.run();
  if (success != 0)
    logger << "Parse file " << filename << " with failed!\n";
  else
    logger << "Parse " << filename << " successful!\n";
  return success;
}