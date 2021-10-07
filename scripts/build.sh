#!/bin/bash
################################################################################
# 
# Copyright (c) 2021 Pokerpoke
# 
# @author   Pokerpoke (pokerpoke@qq.com)
# @date     2021-10
# @brief    
# 
# Last Modified:  2021-10-06
# Modified By:    Pokerpoke (pokerpoke@qq.com)
# 
################################################################################

set -e

# get scripts directory
CMAKE_SOURCE_DIR=$(dirname $(readlink -f $0))
# update cmake source path
cd ${CMAKE_SOURCE_DIR}/..
CMAKE_SOURCE_DIR=$(pwd)

if [ ! -d ./build ] 
then
   mkdir build 
fi

cd build && cmake ..  && make -j 10