cmake_minimum_required(VERSION 3.14)

project(tiger_compiler)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wno-error=register -g -O0")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ")
set(CMAKE_VERBOSE_MAKEFILE FALSE)
enable_testing()

add_subdirectory(src)
add_subdirectory(unit_test)
add_subdirectory(test)
