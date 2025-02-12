cmake_minimum_required(VERSION 3.10)
project(DirectCompute_Project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the source files
set(SOURCES main.cpp)

# Define the executable
add_executable(computing ${SOURCES})

# Link against DirectX 11 libraries
target_link_libraries(computing d3d11 d3dcompiler)

# Copy the compute shader to the output directory
add_custom_command(TARGET computing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/sum.hlsl
        $<TARGET_FILE_DIR:computing>/sum.hlsl
)
