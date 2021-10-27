file(
        COPY regression_test.sh tiger_samples
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(
        NAME regression_test
        COMMAND regression_test.sh $<TARGET_FILE:tiger> tiger_samples
        WORKING_DIRECTOR ${CMAKE_CURRENT_BINARY_DIR}
)
