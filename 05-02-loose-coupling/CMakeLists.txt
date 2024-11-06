cmake_minimum_required(VERSION 3.5)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(example LANGUAGES CXX)

include(CTest)
add_subdirectory(../catch2 catch2)

if (WIN32)
    set(CMAKE_CXX_FLAGS "/W4 /WX /EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wno-unused-parameter")
endif()

add_executable(loose_coupling loose_coupling.cpp)
add_custom_command(TARGET loose_coupling POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/data.csv" ${CMAKE_CURRENT_BINARY_DIR})

add_executable(example_test test.cpp)
target_link_libraries(example_test Catch2WithMain)

add_test(NAME example_test COMMAND example_test)
