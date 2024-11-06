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

add_executable(stream_writer stream_writer.cpp)
target_link_libraries(stream_writer Catch2WithMain)

add_test(NAME stream_writer COMMAND stream_writer)

add_executable(file_writer file_writer.cpp)
target_link_libraries(file_writer Catch2WithMain)

add_test(NAME file_writer COMMAND file_writer)
