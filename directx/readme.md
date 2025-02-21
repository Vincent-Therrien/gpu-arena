# DirectX

DirectX is a collection of APIs developed by Microsoft to handle graphics, sound effects, and other
multimedia tasks. This project uses Direct3D for graphics and DirectCompute for GPGPU. It works
only on Windows `:(`.

DirectX uses the HLSL shading language.


## Graphics

The directory `graphics` is a self-contained C++ project that uses Direct3D to open a window and
display simple graphics. Direct3D uses HLSL (High-Level Shader Language) to write shaders.

The following snippet shows how to build and run it. This only works on Windows!

```
cd graphics
mkdir build
cd build
cmake ..
cmake --build . --config Release
Release\graphics.exe
```


## Computing Example

The directory `computing` is a self-contained C++ project that uses DirectCompute to accelerate
parallel computations.

The following snippet shows how to build and run it. This only works on Windows!

```
cd computing
mkdir build
cd build
cmake ..
cmake --build . --config Release
copy ..\sum.hlsl Release\sum.hlsl
cd Release
Release\computing.exe
```
