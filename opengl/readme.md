# Graphics Example OpenGL

OpenGL is an application programming interface designed for computer graphics, but it also supports
general-purpose computing through computing shaders.


## Build

This only works on Linux! Trying to compile on Windows is a waste of time!

```
sudo apt install -y libglew-dev
sudo apt update && sudo apt install -y cmake g++ libglfw3-dev libgl1-mesa-dev xorg-dev
mkdir build
cd build
cmake ..
cmake --build .
./graphics
```

