//
// Created by Yuan on 2021/10/21.
//

#ifndef PARSER_YY_PARSER_HH
#define PARSER_YY_PARSER_HH

#include <string>
#include <vector>
#include "driver.hh"
#include "parser.hh"

namespace tiger {
    class YYDriver : public Driver {
    public:
        YYDriver(FILE *input, std::string filename) :
                source_file_name(std::move(filename)), source_file(input) ,parser{*this}{
            location.initialize(&source_file_name);
        }

        int run() override {
            if (int pre = pre_parse())
                return pre;
            int successful = parser.parse();
            post_parse();
            return successful;
        }

        FILE *getSourceFile() override {
            return source_file;
        }
        yy::location& getLocation() override{
            return location;
        }


    private:
        std::string source_file_name;
        FILE *source_file;
// Whether to generate parser debug traces.
        yy::parser parser;
        yy::location location{};

        int pre_parse();

        int post_parse();


    };
}

#endif //PARSER_YY_PARSER_HH
