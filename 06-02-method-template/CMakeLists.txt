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

add_executable(serializer serializer.cpp)
add_executable(serializer_done serializer_done.cpp)


add_executable(example_test test.cpp)
target_link_libraries(example_test Catch2WithMain)

add_test(NAME example_test COMMAND example_test)
