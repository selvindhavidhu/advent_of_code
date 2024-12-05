cmake_minimum_required (VERSION 3.20)

set(PROJECT_NAME "aoc2024")
project ("${PROJECT_NAME}" VERSION 1.0.0 LANGUAGES C)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)

# Add source to this project's executable.
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/lib)
file(GLOB all_SRCS 
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/day_1/*.c"
    "${PROJECT_SOURCE_DIR}/src/day_1/*.h")

include(compiler_flags.cmake)

add_executable(${PROJECT_NAME} ${all_SRCS} "src/int_list.h" "src/int_list.c" "src/fileop.h" "src/fileop.c")

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:${PROJECT_NAME}>)