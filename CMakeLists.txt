cmake_minimum_required(VERSION 3.18)

# ==================================
#   Config Compiler (must before project() command)
# ==================================
# CMAKE_C_COMPILER
if(NOT CMAKE_C_COMPILER)
    if (UNIX)
        # set(CMAKE_C_COMPILER /usr/bin/gcc)
        set(CMAKE_C_COMPILER /usr/bin/clang)
    else()
        set(CMAKE_C_COMPILER C:/mingw64/bin/gcc.exe)
        # set(CMAKE_C_COMPILER C:/LLVM/bin/clang.exe)
    endif()
endif()
message(STATUS "[INFO] C compiler: ${CMAKE_C_COMPILER}")


add_compile_options(-std=c1x -Wall -Werror)

project(happyC LANGUAGES C)

add_subdirectory(app)
