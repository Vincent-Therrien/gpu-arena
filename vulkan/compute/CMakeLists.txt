cmake_minimum_required(VERSION 3.10)
project(Vulkan_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Find GLFW
find_package(glfw3 REQUIRED)

# Create the executable
add_executable(compute main.cpp)

# Link libraries
target_link_libraries(compute Vulkan::Vulkan glfw)
