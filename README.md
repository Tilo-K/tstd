# TSTD

A C library providing various string manipulation utilities.

## Usage

To use TSTD in your CMake project, you can either build it from source or include it using FetchContent.

### Integration with FetchContent

Add the following to your CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.20)

project(myproj C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        tstd
        GIT_REPOSITORY https://github.com/Tilo-K/tstd.git
        GIT_TAG main
)

FetchContent_MakeAvailable(tstd)

add_executable(myapp src/main.c)

target_link_libraries(myapp PRIVATE tstd)
```