cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(example LANGUAGES CXX)

if (WIN32)
    set(CMAKE_CXX_FLAGS "/W4 /WX /wd4100 /EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wno-unused-parameter")
endif()

include(CTest)
add_subdirectory(../catch2 catch2)

add_executable(virtual_inheritance virtual_inheritance.cpp)

add_executable(virtual_inheritance_selectivity virtual_inheritance_selectivity.cpp)
