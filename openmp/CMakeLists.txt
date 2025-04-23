cmake_minimum_required(VERSION 3.20)
project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(OpenMP)

add_executable(main openmp.cpp)
