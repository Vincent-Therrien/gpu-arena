cmake_minimum_required(VERSION 3.10)
project(Vulkan_Project)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(graphics main.cpp)
target_link_libraries(graphics Vulkan::Vulkan glfw)
