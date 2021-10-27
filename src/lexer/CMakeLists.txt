add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/src/lexer/lexer.cpp
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lexer.ll
        COMMAND flex -o ${PROJECT_SOURCE_DIR}/src/lexer/lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/lexer.ll
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(lexer
        ${PROJECT_SOURCE_DIR}/src/lexer/lexer.cpp
        )

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)