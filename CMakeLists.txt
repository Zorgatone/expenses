cmake_minimum_required(VERSION 3.22)
project(expenses C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(my_gmtime STATIC source/my_gmtime/my_gmtime.cpp source/my_gmtime/my_gmtime.h)

set_target_properties(my_gmtime PROPERTIES LINKER_LANGUAGE CXX)

add_executable(expenses source/main.c
        source/entry/entry.c
        source/entry/entry.h
        source/my_gmtime/my_gmtime.h)

set_target_properties(expenses PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(expenses PUBLIC m
        my_gmtime)
