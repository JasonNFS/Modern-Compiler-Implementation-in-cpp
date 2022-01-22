include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(tiger)
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(Ast)
add_subdirectory(Utils)

