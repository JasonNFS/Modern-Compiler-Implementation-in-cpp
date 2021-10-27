
add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/src/parser/parser.cpp ${PROJECT_SOURCE_DIR}/include/parser.hh
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser.yy
        COMMAND bison -o ${PROJECT_SOURCE_DIR}/src/parser/parser.cpp
            --header=${PROJECT_SOURCE_DIR}/include/parser.hh ${CMAKE_CURRENT_SOURCE_DIR}/parser.yy
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/location.hh ${PROJECT_SOURCE_DIR}/include/location.hh
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_library(parser
        ${PROJECT_SOURCE_DIR}/src/parser/parser.cpp
        )

include_directories(${PROJECT_SOURCE_DIR}/include)