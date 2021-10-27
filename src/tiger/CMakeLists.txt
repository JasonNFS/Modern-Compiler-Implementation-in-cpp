add_library(yy_driver
        yy_driver.cpp
        )
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(tiger
        tiger.cpp
        )
target_link_libraries(tiger
        parser
        lexer
        yy_driver
        )
