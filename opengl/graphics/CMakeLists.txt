cmake_minimum_required(VERSION 3.20)
project(graphics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIRS})

add_library(glad
    STATIC
    "C:/lib/glad/src/glad.c"
)
target_include_directories(glad
    PRIVATE
    "C:/lib/glad/include"
)
set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)

add_executable(graphics main.cpp "C:/lib/glad/src/glad.c")
add_dependencies(graphics glad)
target_link_libraries(graphics PRIVATE ${GLFW_LIBRARY} opengl32 glad)
target_include_directories(graphics PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(graphics PRIVATE "C:/lib/glad/include")
