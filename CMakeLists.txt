cmake_minimum_required(VERSION 3.0)
project(my_language C)

set(CMAKE_C_STANDARD 11)

add_executable(my_language main.c
        src/parser.c
        src/spliter.c
        src/print.c
        src/finder.c
        src/var.c
        src/pop.c
        src/append.c
)

