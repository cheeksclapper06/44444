cmake_minimum_required(VERSION 3.29)
project(KP4 C)

set(CMAKE_C_STANDARD 99)

add_executable(KP4 main.c
        functions.h
        calculations.h
        validations.h
)
