cmake_minimum_required(VERSION 3.10)



# ==================================
#   Config Compiler (must before project() command)
# ==================================
# CMAKE_C_COMPILER
if(NOT CMAKE_C_COMPILER)
    if (UNIX)
        # set(CMAKE_C_COMPILER /usr/bin/gcc)
        set(CMAKE_C_COMPILER /usr/bin/clang)
    else()
        # set(CMAKE_C_COMPILER /mingw64/bin/gcc)
        set(CMAKE_C_COMPILER /LLVM/bin/clang.exe)
    endif()
endif()
# get_filename_component(CMAKE_C_COMPILER ${CMAKE_C_COMPILER} ABSOLUTE)
message(STATUS "[INFO] C compiler: ${CMAKE_C_COMPILER}")


add_compile_options(-std=c17 -Wall -Werror)

project(happyC LANGUAGES C)

add_subdirectory(app)
