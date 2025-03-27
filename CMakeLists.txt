cmake_minimum_required(VERSION 3.30)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 src/main.c
        src/student.c
        src/file_handler.c
        include/file_handler.h
        include/student.h
        include/utils.h
        src/utils.c)
