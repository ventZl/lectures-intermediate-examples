cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(example LANGUAGES CXX)

if (WIN32)
    set(CMAKE_CXX_FLAGS "/W4 /EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wno-unused-parameter")
endif()

include(CTest)
add_subdirectory(../catch2 catch2)


add_executable(diamond_problem diamond_problem.cpp)

add_executable(diamond_problem_exposed diamond_problem_exposed.cpp)
