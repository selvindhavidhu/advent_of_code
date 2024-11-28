cmake_minimum_required (VERSION 3.20)

set(PROJECT_NAME "aoc2023")
project ("${PROJECT_NAME}" VERSION 1.0.0 LANGUAGES C)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)

# Add source to this project's executable.
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/lib)
file(GLOB all_SRCS 
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.h")

include(compiler_flags.cmake)

add_executable(${PROJECT_NAME} ${all_SRCS})