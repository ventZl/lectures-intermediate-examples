cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(example LANGUAGES CXX)

include(CTest)
add_subdirectory(../catch2 catch2)

if (WIN32)
    set(CMAKE_CXX_FLAGS "/W4 /WX /EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
endif()

add_executable(dependency_inline dependency_inline.cpp)
target_link_libraries(dependency_inline Catch2WithMain)
add_custom_command(TARGET dependency_inline POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/data.csv" ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME dependency_inline COMMAND dependency_inline)

add_executable(dependency_injected dependency_injected.cpp)
target_link_libraries(dependency_injected Catch2WithMain)

add_test(NAME dependency_injected COMMAND dependency_injected)
