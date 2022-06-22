cmake_minimum_required(VERSION 3.16)

project(PokerQt)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

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
include_directories(${CMAKE_SOURCE_DIR})

# ##############################################################################
# add sub directory
# ##############################################################################
add_subdirectory(base)
add_subdirectory(gui)
add_subdirectory(tests)
