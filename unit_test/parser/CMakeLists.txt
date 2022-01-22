add_executable(
  parser_test 
  parser_test.cc
)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

target_link_libraries(
  parser_test
        parser
        lexer
        yy_driver
        utils
  gtest_main
)
include(GoogleTest)

gtest_discover_tests(parser_test)
