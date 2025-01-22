cmake_minimum_required(VERSION 3.25)

project(PokerQt)

set(CMAKE_CXX_STANDARD 20)

# find_package(GTest REQUIRED)

# add_compile_options(-Wall)
if(QT_INSTALL_DIR)
    list(PREPEND CMAKE_PREFIX_PATH ${QT_INSTALL_DIR})

    message(STATUS "Use qt install in ${QT_INSTALL_DIR}")

    # ##########################################################################
    # qt
    # ##########################################################################
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
endif(QT_INSTALL_DIR)

option(USE_QT6 "Enable this if you want to use Qt6, instead of Qt5" ON)

# set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
if(NOT ${CMAKE_INSTALL_PREFIX})
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
endif()

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(concurrentqueue REQUIRED)
find_package(concurrentqueue REQUIRED)
find_package(bshoshany-thread-pool REQUIRED)

add_definitions(-DSPDLOG_FMT_EXTERNAL)

include_directories(
    ${CMAKE_SOURCE_DIR}/include/
    ${fmt_INCLUDE_DIRS}
    ${spdlog_INCLUDE_DIRS}
    ${concurrentqueue_INCLUDE_DIRS}
    ${bshoshany-thread-pool_INCLUDE_DIRS}
)

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

    # get_target_property(QMAKE_EXE Qt6::qmake IMPORTED_LOCATION)
    # get_filename_component(QT_BIN_DIR"${QMAKE_EXE }" DIRECTORY)

    # find_program(WINDEPLOYQT_ENV_SETUP qtenv2.bat HINTS "${QT_BIN_DIR}")
    # find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_BIN_DIR}")
    qt_standard_project_setup()
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
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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
# install resource files
# ##############################################################################
# set(INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
install(DIRECTORY res
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)

# ##############################################################################
# add sub directory
# ##############################################################################
add_subdirectory(src)
add_subdirectory(tests)