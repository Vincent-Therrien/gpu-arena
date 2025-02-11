cmake_minimum_required(VERSION 3.10)
project(OpenGL_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLFW
find_package(glfw3 REQUIRED)

# Include directories
include_directories(include)

# Create the executable
add_executable(graphics main.cpp src/glad.c)

# Link libraries
target_link_libraries(graphics glfw OpenGL::GL)
