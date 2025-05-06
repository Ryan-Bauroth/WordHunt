cmake_minimum_required(VERSION 3.31)
project(WordHunt)

set(CMAKE_CXX_STANDARD 20)

add_executable(WordHunt main.cpp
        BucketSolver.cpp
        BucketSolver.h)
