cmake_minimum_required(VERSION 3.15)
project(exercise2)

set(CMAKE_CXX_STANDARD 11)

add_executable(exercise2
        main.cpp
        zlasdtest/test.cpp
        RandomValues.cpp
        RandomValues.hpp)