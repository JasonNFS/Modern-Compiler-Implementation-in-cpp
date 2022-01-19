add_executable(
  AstBuilderImpl_test 
  AstBuilderImpl_test.cpp
)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/unit_test)


target_link_libraries(
  AstBuilderImpl_test
        parser
        lexer
        yy_driver
        ast
        test_utils
  gtest_main
)
include(GoogleTest)

gtest_discover_tests(AstBuilderImpl_test)
