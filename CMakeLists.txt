cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(snake)

file(GLOB_RECURSE SRC_FILES_snake src/*.cpp)
add_executable(snake ${SRC_FILES_snake})
target_compile_options(snake PRIVATE -std=c++14 -g -Wall -Werror)
target_include_directories(snake PRIVATE src)
target_link_libraries(snake sfml-system sfml-window sfml-graphics)

