cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(example LANGUAGES CXX)

include(CTest)
add_subdirectory(../catch2 catch2)

if (WIN32)
    set(CMAKE_CXX_FLAGS "/W4 /WX /EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter")
endif()

add_executable(test_dirty test_dirty.cpp)
target_link_libraries(test_dirty Catch2WithMain)

add_test(NAME test_dirty COMMAND test_dirty)

add_executable(test_clean test_clean.cpp)
target_link_libraries(test_clean Catch2WithMain)

add_test(NAME test_clean COMMAND test_clean)
