get_filename_component(CURRENT_MOD ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(CURRENT_MOD_NAME ${CURRENT_MOD})
set(EXECUTABLE_NAME ${CURRENT_MOD_NAME})

add_definitions(
)

file(GLOB CURRENT_MOD_SRCS *.cc *.h *.ui
    ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME}/${CURRENT_MOD}/*.h
)

qt_add_executable(${CURRENT_MOD_NAME}
    ${CURRENT_MOD_SRCS}
)

target_include_directories(${CURRENT_MOD_NAME} PRIVATE
    ${fmt_INCLUDE_DIRS}
)

target_link_libraries(
    ${CURRENT_MOD_NAME} PRIVATE
    ${CMAKE_THREAD_LIBS_INIT}
    fmt::fmt
    Boost::filesystem
    ${PROJECT_NAME}_base
    ${PROJECT_NAME}_gui
    ${PROJECT_NAME}_plugin_manager
)

set_target_properties(${CURRENT_MOD_NAME}
    PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_PREFIX}"
)

install(TARGETS ${CURRENT_MOD_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}
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

# endif()
install(CODE [[
    file(GET_RUNTIME_DEPENDENCIES
        RESOLVED_DEPENDENCIES_VAR RESOLVED_DEPS
        UNRESOLVED_DEPENDENCIES_VAR UNRESOLVED_DEPS
        LIBRARIES ${CURRENT_MOD_NAME}
        DIRECTORIES ${CURRENT_MOD_NAME}
        PRE_INCLUDE_REGEXES ${CURRENT_MOD_NAME}
        PRE_EXCLUDE_REGEXES "system32"
        POST_INCLUDE_REGEXES ${CURRENT_MOD_NAME}
        POST_EXCLUDE_REGEXES "system32"
    )
    foreach(DEP_LIB ${RESOLVED_DEPS})
        file(INSTALL ${DEP_LIB} DESTINATION ${CMAKE_INSTALL_PREFIX})
    endforeach()
]])