# OpenGL

OpenGL is an application programming interface designed for computer graphics, but it also supports
general-purpose computing through computing shaders.


## Graphics Example

You need to install the GLFW library to manage windows:


### Download the Dependencies

```
# On Linux:
sudo apt install libglfw3-dev

# On Windows:
#  1. Download the library at https://github.com/glfw/glfw/releases
#  2. Place the files in a standard location, like C:\lib\GLFW
```


### Configure

```
mkdir build
cd build

# Linux:
cmake ..

# Windows:
cmake -DGLFW_INCLUDE_DIR="C:/lib/glfw/include" -DGLFW_LIBRARY="C:/lib/glfw/lib/glfw3.lib" ..
# You may have to replace `vc2022` by another version.
```


### Build

```
cmake --build . --config Release
```


### Run

```
# Linux:
./Release/graphics

# Windows:
Release\graphics.exe
```


## Computing Example
