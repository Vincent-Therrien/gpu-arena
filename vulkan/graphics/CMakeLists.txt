cmake_minimum_required(VERSION 3.10)
project(Vulkan_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Find GLFW
find_package(glfw3 REQUIRED)

# Find GLM
find_package(glm REQUIRED)

# Create the executable
add_executable(graphics main.cpp)

# Link libraries
target_link_libraries(graphics Vulkan::Vulkan glfw)

# Include GLM
target_include_directories(graphics PRIVATE ${GLM_INCLUDE_DIRS})
target_compile_definitions(graphics PRIVATE ${GLM_DEFINITIONS})