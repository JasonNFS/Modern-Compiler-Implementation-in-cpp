#ifndef PARSER_DRIVER_H
#define PARSER_DRIVER_H
#include "parser.hh"
#include <cstdio>

namespace tiger {
    /// Driver should be able to prepare resources for lexer and
    /// run parser & lexer through class: Driver::run().
    class Driver {
    public:
        /// run parser
        virtual int run() = 0;

        virtual yy::location& getLocation() = 0;

        virtual FILE *getSourceFile() = 0;

        virtual ~Driver() = default;
    };
}
#endif//PARSER_DRIVER_H
