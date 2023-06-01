aux_source_directory(. EXECUTABLE)

include_directories(${CMAKE_SOURCE_DIR})

foreach(T_FILE_NAME ${EXECUTABLE})
    get_filename_component(EXECUTABLE_NAME ${T_FILE_NAME} NAME_WE)
    
    add_executable(${EXECUTABLE_NAME} ${T_FILE_NAME})
    target_link_libraries(
        ${EXECUTABLE_NAME}
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
        ${PROJECT_NAME}_base
        # GTest::GTest
        # GTest::Main
    )
    # gtest_discover_tests(${EXECUTABLE_NAME})
endforeach()