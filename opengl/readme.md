# OpenGL

OpenGL is an application programming interface designed for computer graphics, but it also supports
general-purpose computing through computing shaders. OpenGL uses GLSL to write shaders.

Relevant links:

- History of OpenGL: https://www.khronos.org/opengl/wiki/History_of_OpenGL
- Rendering pipeline: https://www.khronos.org/opengl/wiki/Rendering_Pipeline_Overview
- Compute shaders: https://www.khronos.org/opengl/wiki/Compute_Shader


## Graphics Example

The directory `graphics` is a self-contained C++ project that uses OpenGL and additional libraries
to open a window and display simple graphics.

The following instructions show how to build and run it. This only works on Linux! Use WSL if
necessary!

1. Download the GLAD library at https://glad.dav1d.de/. GLAD is used to load OpenGL functions.
2. Place the files `glad.h` and `glad.c` in the `graphics` directory.
3. Run the following commands:

```
cd graphics
mkdir include && mv glad.h include/glad.h  # Place the GLAD header in an include directory.
mkdir src && mv glad.h src/glad.c  # Place the GLAD source file in a source directory.
sudo apt install -y libglew-dev
sudo apt update && sudo apt install -y cmake g++ libglfw3-dev libgl1-mesa-dev xorg-dev
mkdir build
cd build
cmake ..
cmake --build .
./graphics
```

This project displays a 3D rotating triangle. You can modify the file `graphics/main.cpp` to
understand how it works.


## Computing Example

The directory `computing` is a self-contained C++ project that uses OpenGL to accelerate parallel
computations. The program computes the sum of elements in an array through sum reduction.

The following instructions show how to build and run it. This only works on Linux! Use WSL if
necessary!

Run the following commands:

```
cd computing
sudo apt install -y libglew-dev
sudo apt update && sudo apt install -y cmake g++ libglfw3-dev libgl1-mesa-dev xorg-dev
mkdir build
cd build
cmake ..
cmake --build .
./computing
```
