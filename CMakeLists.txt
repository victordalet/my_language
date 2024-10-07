cmake_minimum_required(VERSION 3.0)
project(my_language C)

set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(my_language main.c
        src/parser.c
        src/spliter.c
        src/print.c
        src/finder.c
        src/var.c
        src/pop.c
        src/append.c
        src/condition.c
        src/pipeline.c
        src/view.c
)

target_link_libraries(my_language ${SDL2_LIBRARIES})

