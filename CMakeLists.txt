cmake_minimum_required(VERSION 3.28)
project(Kalkulator_RPN)

set(CMAKE_CXX_STANDARD 26)

add_executable(Kalkulator_RPN main.cpp
        kalkulator_rpn.cpp
        kalkulator_rpn.h)
