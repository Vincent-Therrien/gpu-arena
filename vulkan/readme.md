# Vulkan

Vulkan is an application programming interface designed for computer graphics, but it also supports
general-purpose computing through computing shaders.

Vulkan uses SPIR-V as its shading language, which is not intended to be human-readable. You can
write the shaders in a human readable language, like GLSL and HLSL, and compile it to SPIR-V before
feeding it to Vulkan. This project uses GLSL.


## Graphics Example

The directory `graphics` is a self-contained C++ project that uses OpenGL and additional libraries
to open a window and display simple graphics. This project is taken from the file
https://github.com/Overv/VulkanTutorial/blob/main/code/15_hello_triangle.cpp from the repository
`VulkanTutorial`, available at https://github.com/Overv/VulkanTutorial/tree/main and licensed under
the licenses CC0-1.0 and CC-BY-SA-4.0.

The following instructions show how to build and run it. This only works on Linux! Use WSL if
necessary!

```
cd graphics
sudo apt install vulkan-tools
sudo apt install libvulkan-dev
sudo apt install vulkan-validationlayers-dev spirv-tools
sudo apt install glslang-tools
sudo apt install libglm-dev
mkdir build
cd build
cmake ..
cmake --build .
glslangValidator -V ../shader.vert -o vertices.spv
glslangValidator -V ../shader.frag -o fragment.spv
./graphics
```


## Computing Example

The directory `computing` is a self-contained C++ project that uses OpenGL to accelerate parallel
computations.

The following instructions show how to build and run it. This only works on Linux! Use WSL if
necessary!

Run the following commands:

```
cd computing

mkdir build
cd build
cmake ..
cmake --build .
./computing
```
