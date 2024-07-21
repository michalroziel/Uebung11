cmake_minimum_required(VERSION 3.28)
project(Uebung11 C)

set(CMAKE_C_STANDARD 17)

add_executable(Uebung11 ex1/main.c
        ex1/workerDetails.h
        ex1/system.c
        ex1/builder.c
        ex2/matrices.c
        ex2/matrices.h
)
