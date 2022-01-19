//
// Created by KYG on 2022/01/19.
//

#ifndef TIGER_COMPILER_ASTBUILDER_HH
#define TIGER_COMPILER_ASTBUILDER_HH
#include "Ast.hh"
#include "location.hh"
#include <memory>
namespace tiger {
class AstBuilder
{
public:
  virtual ~AstBuilder() {}
  /**
  *   returned Exp is managed by AstBuilder.
  **/
  virtual Exp* getRoot() = 0; // get root of ast.
  virtual void setRoot(Exp*) = 0;
  virtual NumberExp* buildNumberExp(yy::location l,NumberExp::NumberType value) = 0;
};
}

#endif// TIGER_COMPILER_ASTBUILDER_HH
