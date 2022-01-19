#include "gtest/gtest.h"
#include "Ast.hh"
#include "parser.hh"
#include "test_utils/utils.hh"
#include "tiger/YYDriver.hh"
#include <cstddef>
#include <string>
TEST(AstBuilder, NumberExpTest)
{
  std::string number_code = "3";
  auto f = tigertest::string2file(number_code);
  tiger::YYDriver driver{ f, "unknown_tmpfile" };
  int success = driver.run();
  fclose(f);
  EXPECT_EQ(bool(success), bool(0));
  auto ast = driver.getAstBuilder().getRoot();
  auto numberExpr = dynamic_cast<tiger::NumberExp *>(ast);
  EXPECT_TRUE(numberExpr != nullptr);
  EXPECT_TRUE(numberExpr->getVal() == 3);
}