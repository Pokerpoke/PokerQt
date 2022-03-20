project(PokerQt)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_compile_options(-Wall)

################################################################################
# qt
################################################################################
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
################################################################################
# add sub directory
################################################################################
add_subdirectory(base)
add_subdirectory(gui)
add_subdirectory(tests)
