cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap
        inc/push_swap.h
        src/main.c
        src/list_push_swap.c
        src/error_ps.c
        src/cheak.c
        src/add_index.c
        src/markup.c)