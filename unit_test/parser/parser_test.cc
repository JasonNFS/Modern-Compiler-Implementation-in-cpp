#pragma ide diagnostic ignored "cert-err58-cpp"
#include <vector>
#include "yy_driver.hh"
#include "gtest/gtest.h"
#include <cstdio>
#include <map>

using namespace std::string_literals;
using namespace std;
namespace {
    /// open a temp file for reading. Caller ought to close it.
    FILE *string2file(const std::string &str) {
        FILE *tmp = tmpfile();
        if (!tmp)
            throw runtime_error("open temp file failed!");
        fputs(str.c_str(), tmp);
        rewind(tmp);
        return tmp;
    }
}
TEST(parser, vardec_with_built_in_type) {
    map<string, int> code_result_map = {
            {"nil",                      0},
            {"nil 2",                    1},
            {"(nil;2)",                  0},
            {R"(let
                        var v1 : int := 7
                    in
                        (nil;2)
                    end)", 0}
    };
    for (auto&[code, result]: code_result_map) {
        auto f = string2file(code);
        tiger::YYDriver driver{f, "unknown"};
        int success = driver.run();
        fclose(f);
        EXPECT_EQ(bool(success), bool(result));
    }
}
