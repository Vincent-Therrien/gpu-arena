# OpenGL

OpenGL is an application programming interface designed for computer graphics, but it also supports
general-purpose computing through computing shaders.


## Graphics Example

The directory `graphics` is a self-contained C++ project that uses OpenGL and additional libraries
to open a window and display simple graphics.

The following snippet shows how to build and run it. This only works on Linux! Use WSL if necessary!

```
cd graphics
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

The following snippet shows how to build and run it. This only works on Linux! Use WSL if necessary!

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
