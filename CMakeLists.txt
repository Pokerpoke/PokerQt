cmake_minimum_required(VERSION 3.16)

project(PokerQt)

set(CMAKE_CXX_STANDARD 20)

# find_package(GTest REQUIRED)

# add_compile_options(-Wall)

# ##############################################################################
# qt
# ##############################################################################
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS Core Widgets Gui REQUIRED)

# ##############################################################################
# output
# ##############################################################################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ##############################################################################
# include
# ##############################################################################
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
)

# ##############################################################################
# qt designer plugin
# ##############################################################################
option(BUILD_QT_DESIGNER_PLUGINS "Build Qt Designer plugins" ON)

if(BUILD_QT_DESIGNER_PLUGINS)
    set(Qt6_ROOT_DIR ${Qt6_DIR}/../../..)
    set(Qt6_CREATOR_DIR ${Qt6_DIR}/../../../bin)
    set(Qt6_RUNTIME_DIR ${Qt6_DIR}/../../../bin)
    set(Qt6_DESIGNER_PLUGINS_DIR ${Qt6_DIR}/../../../plugins/designer)

    message(STATUS "Qt6_DIR ${Qt6_DIR}")
    message(STATUS "Qt6_RUNTIME_DIR ${Qt6_RUNTIME_DIR}")
    message(STATUS "Qt6_DESIGNER_PLUGINS_DIR ${Qt6_DESIGNER_PLUGINS_DIR}")

    add_subdirectory(qtcreator_plugins)

    install(DIRECTORY res
        DESTINATION ${Qt6_RUNTIME_DIR}
    )
endif()

# ##############################################################################
# add sub directory
# ##############################################################################
add_subdirectory(base)
add_subdirectory(gui)
add_subdirectory(tests)

# ##############################################################################
# install resource files
# ##############################################################################
install(DIRECTORY res
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)