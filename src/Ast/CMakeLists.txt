add_library(ast
        AstBuilderImpl.cpp
        )
target_link_libraries(ast
        utils
)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

