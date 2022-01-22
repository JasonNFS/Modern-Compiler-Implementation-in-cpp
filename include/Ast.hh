//
// Created by KYG on 2022/01/18.
//

#ifndef TIGER_COMPILER_AST_HH
#define TIGER_COMPILER_AST_HH
#include "location.hh"
#include <memory>
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
class BinaryOpExp : public Exp
{
public:
  enum class OpType {
    plus,
    minus
  };

public:
  BinaryOpExp(yy::location l, Exp *lhs, Exp *rhs, OpType op) : Exp(l), lhs(lhs), rhs(rhs), op_code(op) {}
  Exp *getLhs()
  {
    return lhs.get();
  }
  Exp *getRhs()
  {
    return rhs.get();
  }
  OpType GetOpCode()
  {
    return op_code;
  }

private:
  std::unique_ptr<Exp> lhs;
  std::unique_ptr<Exp> rhs;
  OpType op_code;
};
class IfExp : public Exp
{
public:
  IfExp(yy::location l, Exp *if_exp, Exp *then_exp, Exp *else_exp)
    : Exp(l), if_exp(if_exp), then_exp(then_exp), else_exp(else_exp) {}
  Exp *GetIfExp() { return if_exp.get(); }
  Exp *GetThenExp() { return then_exp.get(); }
  Exp *GetElseExp() { return else_exp.get(); }

private:
  std::unique_ptr<Exp> if_exp, then_exp, else_exp;
};
}// namespace tiger
#endif// TIGER_COMPILER_AST_HH
