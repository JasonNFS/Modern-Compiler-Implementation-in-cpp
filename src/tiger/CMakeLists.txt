add_library(yy_driver
        YYDriver.cpp
        )
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(tiger
        tiger.cpp
        )
target_link_libraries(tiger
        parser
        lexer
        yy_driver
        ast
        )
