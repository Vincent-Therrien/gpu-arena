# OpenGL

OpenGL is an application programming interface designed for computer graphics, but it also supports
general-purpose computing through computing shaders. OpenGL uses GLSL to write shaders.


## Graphics Example

The directory `graphics` is a self-contained C++ project that uses OpenGL and additional libraries
to open a window and display simple graphics.

The following instructions show how to build and run it. This only works on Linux! Use WSL if
necessary!

1. Download the GLAD library at https://glad.dav1d.de/.
2. Place the files `glad.h` and `glad.c` in the `graphics` directory.
3. Run the following commands:

```
cd graphics
mkdir include && mv glad.h include/glad.h
mkdir src && mv glad.h src/glad.c
sudo apt install -y libglew-dev
sudo apt update && sudo apt install -y cmake g++ libglfw3-dev libgl1-mesa-dev xorg-dev
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

1. Download the GLAD library at https://glad.dav1d.de/.
2. Place the files `glad.h` and `glad.c` in the `computing` directory.
3. Run the following commands:

```
cd computing
mkdir include && mv glad.h include/glad.h
mkdir src && mv glad.h src/glad.c
sudo apt install -y libglew-dev
sudo apt update && sudo apt install -y cmake g++ libglfw3-dev libgl1-mesa-dev xorg-dev
mkdir build
cd build
cmake ..
cmake --build .
./computing
```
