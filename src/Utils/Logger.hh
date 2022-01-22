#ifndef LOGGER_HH
#define LOGGER_HH
#include <iostream>
#include <ostream>
namespace tiger {
class Logger
{
public:
  static Logger a_logger;

public:
  virtual ~Logger() = default;
  Logger(std::ostream &out = std::cout) : out{ out } {};
  virtual void log(const std::string &msg)
  {
    out << msg;
  }

private:
  std::ostream &out;
};
}// namespace tiger

#endif