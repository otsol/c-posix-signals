cmake_minimum_required(VERSION 3.23)
project(sovohj_1)
# --- auto-ignore build directory
if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
    file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
endif()

set(CMAKE_C_STANDARD 99)

add_executable(sovohj as1.c)
add_executable(hello_world main.c morse.c morse.h)


target_compile_options(sovohj PRIVATE -Wall -pedantic -Wextra ) #-Werror
target_compile_options(hello_world PRIVATE -Wall -pedantic -Wextra ) #-Werror