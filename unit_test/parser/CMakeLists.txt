add_executable(
  parser_test 
  parser_test.cc
)
include_directories(${PROJECT_SOURCE_DIR}/include)
target_link_libraries(
  parser_test
        parser
        lexer
        yy_driver
  gtest_main
)
include(GoogleTest)

gtest_discover_tests(parser_test)
