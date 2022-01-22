//
// Created by KYG on 2022/01/19.
//

#ifndef TIGER_COMPILER_ASTBUILDER_HH
#define TIGER_COMPILER_ASTBUILDER_HH
#include "Ast.hh"
#include "location.hh"
#include "Utils/Logger.hh"
#include <memory>
namespace tiger {
class AstBuilder
{
public:
  virtual ~AstBuilder() {}
  /**
   *   returned Exp is managed by AstBuilder.
   **/
  virtual Exp *getRoot() = 0;// get root of ast.
  virtual void setRoot(Exp *) = 0;
  virtual NumberExp *BuildNumberExp(yy::location l, NumberExp::NumberType value)
  {
    return new NumberExp(l, value);
  };
  virtual NilExp *BuildNilExp(yy::location l)
  {
    return new NilExp(l);
  };
  virtual BinaryOpExp *BuildBinaryOpExp(yy::location l, Exp *lhs, Exp *rhs, BinaryOpExp::OpType op)
  {
    if (lhs) l.begin = lhs->getLocation().begin;
    if (rhs) l.end = rhs->getLocation().end;
    return new BinaryOpExp(l, lhs, rhs, op);
  }
  virtual IfExp *BuildIfExp(yy::location l, Exp *if_exp, Exp *then_exp, Exp *else_exp = nullptr)
  {
    if (if_exp) l.begin = if_exp->getLocation().begin;
    if (else_exp) l.end = else_exp->getLocation().end;
    return new IfExp(l, if_exp, then_exp, else_exp);
  }
};
}// namespace tiger

#endif// TIGER_COMPILER_ASTBUILDER_HH
