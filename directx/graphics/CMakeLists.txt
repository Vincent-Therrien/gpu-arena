cmake_minimum_required(VERSION 3.10)
project(DirectX_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(graphics main.cpp)

target_link_libraries(graphics d3d11 dxgi d3dcompiler)
set_target_properties(graphics PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
