# Vulkan

Vulkan is an application programming interface designed for computer graphics, but it also supports
general-purpose computing through computing shaders.

Vulkan uses SPIR-V as its shading language, which is not intended to be human-readable. You can
write the shaders in a human readable language, like GLSL and HLSL, and compile it to SPIR-V before
feeding it to Vulkan. This project uses GLSL.


## Graphics Example

The directory `graphics` is a self-contained C++ project that uses OpenGL and additional libraries
to open a window and display simple graphics.

The following instructions show how to build and run it. This only works on Linux! Use WSL if
necessary!

```
cd graphics
sudo apt install vulkan-tools
sudo apt install libvulkan-dev
sudo apt install vulkan-validationlayers-dev spirv-tools
mkdir build
cd build
cmake ..
cmake --build .
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
