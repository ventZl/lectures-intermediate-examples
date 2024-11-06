cmake_minimum_required(VERSION 3.5)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(example LANGUAGES CXX)

include(CTest)
add_subdirectory(../catch2 catch2)

if (WIN32)
    set(CMAKE_CXX_FLAGS "/W4 /WX /EHsc")
else()
    set(CMAKE_CXX_FLAGS "-Wall")
endif()

add_executable(printer_job_test test.cpp)
target_link_libraries(printer_job_test Catch2WithMain)

add_test(NAME printer_job COMMAND printer_job_test)
