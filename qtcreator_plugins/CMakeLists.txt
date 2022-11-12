aux_source_directory(. EXECUTABLE)

include_directories(${CMAKE_SOURCE_DIR})

foreach(T_FILE_NAME ${EXECUTABLE})
    get_filename_component(EXECUTABLE_NAME ${T_FILE_NAME} NAME_WE)
    
    add_library(${EXECUTABLE_NAME} SHARED
        ${T_FILE_NAME}
    )
    target_link_libraries(
        ${EXECUTABLE_NAME}
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
        ${PROJECT_NAME}_base
        ${PROJECT_NAME}_gui
        # GTest::GTest
        # GTest::Main
        Qt6::Core
        Qt6::Widgets
    )
    # gtest_discover_tests(${EXECUTABLE_NAME})

    if(BUILD_QT_DESIGNER_PLUGINS)
        message(STATUS "Qt6_DESIGNER_PLUGINS_DIR " ${EXECUTABLE_NAME} ${Qt6_DESIGNER_PLUGINS_DIR})
        install(TARGETS ${EXECUTABLE_NAME}
            LIBRARY DESTINATION ${Qt6_DESIGNER_PLUGINS_DIR}
            RUNTIME DESTINATION ${Qt6_DESIGNER_PLUGINS_DIR}
            ARCHIVE DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
        )
    endif()
endforeach()