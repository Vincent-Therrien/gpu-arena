cmake_minimum_required(VERSION 3.10)
project(OpenGL_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLFW
find_package(glfw3 REQUIRED)

# Find GLEW
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLEW REQUIRED glew)

# Add the executable
add_executable(computing main.cpp)

# Include directories
target_include_directories(computing PRIVATE ${GLEW_INCLUDE_DIRS})
target_include_directories(computing PRIVATE ${GLFW3_INCLUDE_DIRS})

# Link libraries
target_link_libraries(computing PRIVATE ${GLEW_LIBRARIES} glfw OpenGL::GL)
