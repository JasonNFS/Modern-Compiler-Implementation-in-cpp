//
// Created by KYG on 2022/01/18.
//

#ifndef TIGER_COMPILER_AST_HH
#define TIGER_COMPILER_AST_HH
#include "location.hh"
namespace tiger {
class Exp
{
protected:
  yy::location location;

public:
  explicit Exp(yy::location l) : location(l) {}
  virtual yy::location getLocation()
  {
    return location;
  }
  virtual ~Exp() = default;
};
class NumberExp : public Exp
{
public:
  using NumberType = int;

private:
  int value;

public:
  NumberExp(yy::location l, NumberType val) : Exp{ l }, value{ val } {}
  NumberType getVal()
  {
    return value;
  }
};
class NilExp : public Exp
{
public:
  NilExp(yy::location l) : Exp(l) {}
};
}// namespace tiger
#endif// TIGER_COMPILER_AST_HH
