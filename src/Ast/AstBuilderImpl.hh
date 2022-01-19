#ifndef ASTBUILDERIMPL_HH
#define ASTBUILDERIMPL_HH
#include "Ast.hh"
#include "AstBuilder.hh"
#include "location.hh"
#include <memory>

namespace tiger {
class AstBuilderImpl : public AstBuilder
{
public:
  Exp *getRoot() override
  {
    return root.get();
  }
  void setRoot(Exp *r) override
  {
    root.reset(r);
  }

private:
  std::unique_ptr<Exp> root;
};
}// namespace tiger
#endif