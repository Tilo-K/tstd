cmake_minimum_required(VERSION 4.0)
project(tstd C)

set(CMAKE_C_STANDARD 23)

add_library(tstd STATIC library.c
        string.h
        string.c)


add_executable(test_tstd test/test_main.c)
target_link_libraries(test_tstd tstd)

enable_testing()
add_test(NAME tstd_tests COMMAND test_tstd)