# Modern Compiler Implementation in C++
[![CMake](https://github.com/JasonNFS/Modern-Compiler-Implementation-in-cpp/actions/workflows/cmake.yml/badge.svg)](https://github.com/JasonNFS/Modern-Compiler-Implementation-in-cpp/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/JasonNFS/Modern-Compiler-Implementation-in-cpp/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/JasonNFS/Modern-Compiler-Implementation-in-cpp/actions/workflows/codeql-analysis.yml)

This is a c++ 17/20 implementation of book 
[Modern Compiler Implementation in C](https://www.cs.princeton.edu/~appel/modern/c/).
Still in working, any question or suggestion are welcome :)

Lexer ✅ | Parser ✅ | AST ☑️ | Semantic ☑️ | IR ☑️ | Back End ☑️
<!--
![](https://progress-bar.dev/20/?title=Lexer->Parser&width=500&color=008800)
-->

## Build
```bash
mkdir build
cd build && cmake ..
cmake --build .
ctest # run unit test and regression test.
```
## Implementation
### Lexer & parser
Lexer use flex to implement the token scanner. Parser use Bison to implement 
the context free grammer.


