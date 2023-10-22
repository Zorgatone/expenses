cmake_minimum_required(VERSION 3.22)
project(expenses C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Allow include directives without relative paths
include_directories(source)

add_library(my_timegm STATIC source/my_timegm/my_timegm.cpp source/my_timegm/my_timegm.h)

set_target_properties(my_timegm PROPERTIES LINKER_LANGUAGE CXX)

add_executable(expenses source/main.c
        source/entry/entry.c
        source/entry/entry.h
        source/my_timegm/my_timegm.h
        source/time_utils/time_utils.c
        source/time_utils/time_utils.h)

set_target_properties(expenses PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(expenses PUBLIC m
        my_timegm)
