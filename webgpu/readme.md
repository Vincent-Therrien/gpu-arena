# WebGPU

WebGPU is a GPU API that can use Vulkan, DirectX, or Metal as its backend, making it truly
multi-platform. It uses the WGSL shading language.

WebGPU has some limitations. For instance, it only supports 32-bit values, so you have to find weird
workarounds to use FP16 numbers. The project burn (https://github.com/tracel-ai/burn) uses WebGPU
to accelerate computations because it is cross-platform, but it sometimes uses SPIR-V to perform
some optimizations. But maybe the specification will evolve to support that more easily.

Relevant links:

- WebGPU specification: https://www.w3.org/TR/webgpu/
- wgpu (Rust library): https://github.com/gfx-rs/wgpu


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
compute shader. This code is not optimized! It should use sum reduction, but it uses fixed-length
instead. Refer to the `opengl` compute example in this repository or the file
https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf to see how to program sum
reduction.

To run the example, execute the following instructions:

```
cd compute
cargo run
```
