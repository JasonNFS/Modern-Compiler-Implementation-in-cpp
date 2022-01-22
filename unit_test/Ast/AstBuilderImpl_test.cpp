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
TEST(AstBuilder, NilExpr)
{
  std::string number_code = "nil  ";
  auto f = tigertest::string2file(number_code);
  tiger::YYDriver driver{ f, "unknown_tmpfile" };
  int success = driver.run();
  fclose(f);
  EXPECT_EQ(bool(success), bool(0));
  auto ast = driver.getAstBuilder().getRoot();
  auto numberExpr = dynamic_cast<tiger::NilExp *>(ast);
  EXPECT_TRUE(numberExpr != nullptr);
}
TEST(AstBuilder, BinaryOpExpr)
{
  std::string number_code = "3 +4   ";
  auto f = tigertest::string2file(number_code);
  tiger::YYDriver driver{ f, "unknown_tmpfile" };
  int success = driver.run();
  fclose(f);
  EXPECT_EQ(bool(success), bool(0));
  auto ast = driver.getAstBuilder().getRoot();
  auto boExp = dynamic_cast<tiger::BinaryOpExp *>(ast);
  EXPECT_TRUE(boExp != nullptr);
  EXPECT_EQ(boExp->getLocation().begin.column, 1);
  EXPECT_EQ(boExp->getLocation().end.column, 5);
}
TEST(AstBuilder, IfExp)
{
  std::string number_code = "if 1 then 9 else 10  ";
  auto f = tigertest::string2file(number_code);
  tiger::YYDriver driver{ f, "unknown_tmpfile" };
  int success = driver.run();
  fclose(f);
  EXPECT_EQ(success, 0);
  auto ast = driver.getAstBuilder().getRoot();
  EXPECT_TRUE(ast != nullptr);
  auto exp = dynamic_cast<tiger::IfExp *>(ast);
  EXPECT_TRUE(exp != nullptr);
  // auto if_exp = dynamic_cast<tiger::NumberExp *>(exp->GetIfExp());
  // auto then_exp = dynamic_cast<tiger::NumberExp *>(exp->GetThenExp());
  // auto else_exp = dynamic_cast<tiger::NumberExp *>(exp->GetElseExp());
  // EXPECT_TRUE(if_exp && then_exp && else_exp);
  // EXPECT_TRUE(if_exp->getVal() == 1 && then_exp->getVal() == 9 && else_exp->getVal() == 10);
}
TEST(AstBuilder, IfExp_regression)
{
  std::string code = R"(let 

 type any = {any : int}
 var buffer := getchar()

function readint(any: any) : int =
 let var i := 0
     function isdigit(s : string) : int = 
		  ord(buffer)>=ord("0") & ord(buffer)<=ord("9")
     function skipto() =
       while buffer=" " | buffer="\n"
         do buffer := getchar()
  in skipto();
     any.any := isdigit(buffer);
     while isdigit(buffer)
       do (i := i*10+ord(buffer)-ord("0"); buffer := getchar());
     i
 end

 type list = {first: int, rest: list}

 function readlist() : list =
    let var any := any{any=0}
        var i := readint(any)
     in if any.any
         then list{first=i,rest=readlist()}
         else nil
    end

 function merge(a: list, b: list) : list =
   if a=nil then b
   else if b=nil then a
   else if a.first < b.first 
      then list{first=a.first,rest=merge(a.rest,b)}
      else list{first=b.first,rest=merge(a,b.rest)}

 function printint(i: int) =
  let function f(i:int) = if i>0 
	     then (f(i/10); print(chr(i-i/10*10+ord("0"))))
   in if i<0 then (print("-"); f(-i))
      else if i>0 then f(i)
      else print("0")
  end

 function printlist(l: list) =
   if l=nil then print("\n")
   else (printint(l.first); print(" "); printlist(l.rest))

   var list1 := readlist()
   var list2 := (buffer:=getchar(); readlist())


  /* BODY OF MAIN PROGRAM */
 in printlist(merge(list1,list2))
end

)";
  auto f = tigertest::string2file(code);
  tiger::YYDriver driver{ f, "unknown_tmpfile" };
  int success = driver.run();
  fclose(f);
  EXPECT_EQ(success, 0);
}
