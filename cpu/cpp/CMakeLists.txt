cmake_minimum_required(VERSION 3.20)
project(cpu LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(cpu cpu.cpp)
