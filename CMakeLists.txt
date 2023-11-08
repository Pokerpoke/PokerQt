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

option(USE_QT6 "Enable this if you want to use Qt6, instead of Qt5" ON)

set(USE_QT6 ON)

set(QT_REQUIRED_LIBRARIES "")

if(USE_QT6)
    find_package(Qt6 COMPONENTS Core Widgets Gui)

    include_directories(
        ${CMAKE_SOURCE_DIR}
        ${Qt6Core_INCLUDE_DIRS}
        ${Qt6Widgets_INCLUDE_DIRS}
    )

    set(QT_REQUIRED_LIBRARIES Qt6::Core Qt6::Widgets Qt6::Gui)

    add_compile_options(/Zc:__cplusplus)
else(USE_QT6)
    find_package(Qt5 COMPONENTS Core Widgets Gui)

    include_directories(
        ${CMAKE_SOURCE_DIR}
        ${Qt5Core_INCLUDE_DIRS}
        ${Qt5Widgets_INCLUDE_DIRS}
    )

    set(QT_REQUIRED_LIBRARIES Qt5::Core Qt5::Widgets Qt5::Gui)
endif(USE_QT6)

# ##############################################################################
# output
# ##############################################################################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ##############################################################################
# qt designer plugin
# ##############################################################################
option(BUILD_QT_DESIGNER_PLUGINS "Build Qt Designer plugins" OFF)

if(BUILD_QT_DESIGNER_PLUGINS)
    set(Qt_ROOT_DIR ${Qt_DIR}/../../..)
    set(Qt_CREATOR_DIR ${Qt_DIR}/../../../bin)
    set(Qt_RUNTIME_DIR ${Qt_DIR}/../../../bin)
    set(Qt_DESIGNER_PLUGINS_DIR ${Qt_DIR}/../../../plugins/designer)

    message(STATUS "Qt_DIR ${Qt_DIR}")
    message(STATUS "Qt_RUNTIME_DIR ${Qt_RUNTIME_DIR}")
    message(STATUS "Qt_DESIGNER_PLUGINS_DIR ${Qt_DESIGNER_PLUGINS_DIR}")

    add_subdirectory(qtcreator_plugins)

    install(DIRECTORY res
        DESTINATION ${Qt_RUNTIME_DIR}
    )
endif()

# ##############################################################################
# add sub directory
# ##############################################################################
add_subdirectory(base)
if(Qt5_FOUND OR Qt6_FOUND)
    add_subdirectory(gui)
endif()
add_subdirectory(tests)

# ##############################################################################
# install resource files
# ##############################################################################
install(DIRECTORY res
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)