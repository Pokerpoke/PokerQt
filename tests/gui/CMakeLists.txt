aux_source_directory(. EXECUTABLE)

include_directories(${CMAKE_SOURCE_DIR})

foreach(T_FILE_NAME ${EXECUTABLE})
    get_filename_component(EXECUTABLE_NAME ${T_FILE_NAME} NAME_WE)

    qt_add_executable(${EXECUTABLE_NAME}
        ${T_FILE_NAME}
    )

    target_link_libraries(
        ${EXECUTABLE_NAME}
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
        ${PROJECT_NAME}_base
        ${PROJECT_NAME}_gui
        ${QT_REQUIRED_LIBRARIES}
    )

    set_target_properties(${EXECUTABLE_NAME}
        PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_PREFIX}"
    )

    install(TARGETS ${EXECUTABLE_NAME}
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        BUNDLE DESTINATION ${CMAKE_INSTALL_PREFIX}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}
    )

    set(deploy_tool_options_arg "")

    if(APPLE)
        set(deploy_tool_options_arg --hardened-runtime)
    elseif(WIN32)
        set(deploy_tool_options_arg --no-compiler-runtime)
    endif()

    set(executable_path "${CMAKE_INSTALL_PREFIX}/${EXECUTABLE_NAME}")

    if(WIN32)
        set(executable_path "${executable_path}.exe")
    endif(WIN32)

    message(STATUS "executable_path: ${executable_path}")

    qt_generate_deploy_script(
        TARGET ${EXECUTABLE_NAME}
        OUTPUT_SCRIPT deploy_script
        CONTENT "
qt_deploy_runtime_dependencies(
    EXECUTABLE \"${executable_path}\"
    DEPLOY_TOOL_OPTIONS \"${deploy_tool_options_arg}\"
    # BIN_DIR ${CMAKE_INSTALL_PREFIX}
    # PLUGINS_DIR ${CMAKE_INSTALL_PREFIX}/plugins
    NO_TRANSLATIONS
    VERBOSE
)")

    install(SCRIPT ${deploy_script})
endforeach()