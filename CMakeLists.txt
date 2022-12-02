cmake_minimum_required(VERSION 3.23)
project(sovohj_1)
# --- auto-ignore build directory
if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
    file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
endif()

set(CMAKE_C_STANDARD 99)

add_executable(sovohj main.c)
add_executable(child_exec child_exec.c morse.c morse.h)


target_compile_options(sovohj PRIVATE -Wall -pedantic -Wextra -g ) #-Werror
target_compile_options(child_exec PRIVATE -Wall -pedantic -Wextra -g) #-Werror