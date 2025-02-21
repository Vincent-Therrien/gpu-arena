# WebGPU

WebGPU is a GPU API that can use Vulkan, DirectX, or Metal as its backend, making it truly
multi-platform. It uses the WGSL shading language.


## Graphics Example

The directory `graphics` is a self-contained Rust program that uses the `wgpu` library to display
simple graphics. It is based on the project https://github.com/sotrh/learn-wgpu, licensed under the
MIT license.

To run the example, execute the following instructions:

```
cd graphics
cargo run
```


## Compute Example

The directory `compute` is a self-contained Rust program that uses the `wgpu` library to run
compute shaders. It is based on the project https://github.com/googlefonts/compute-shader-101,
licensed under the MIT license. This current project **sums the elements in an array** with a
compute shader.

To run the example, execute the following instructions:

```
cd compute
cargo run
```
