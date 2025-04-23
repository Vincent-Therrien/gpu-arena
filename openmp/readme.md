# OpenMP

OpenMP is a directive-based API, meaning that code intended to run in parallel is flagged with
compiler directive. In C and C++, this is done with `#pragma omp ...` directives. OpenMP is also
compatible with Fortran. The page
https://www.openmp.org/wp-content/uploads/2021-10-20-Webinar-OpenMP-Offload-Programming-Introduction.pdf
presents a quick intro to OpenMP and the page https://enccs.github.io/openmp-gpu/ explains GPU
programming with OpenMP in more detail.

OpenMP contrasts with the other APIs in this repository. In most cases, the CPU and GPU code use
different programming languages. For instance, OpenGL and WebGPU use shading languages
to program GPUs and OpenCL / CUDA use variants of the C programming language. OpenMP integrates
that kind of operation seamlessly into CPU code (I find that it makes it actually most similar to
Triton out of all the other APIs in the repository).


## Build the Example

To build the OpenMP program, run:

```
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

OpenMP comes installed with the compiler, but you may have to ensure that your GPU drivers are up to
date and that there is a CUDA / ACC / OpenCL / ... runtime available on your system to use it. This
program is just a minimal example of array summation.


## Why Is the Example So Small?

The program written in `openmp.cpp` takes 22 lines of C++ code to sum the elements in an array. In
OpenGL, this takes around 145 lines (see the computing example of OpenGL in the repository).

This is because OpenMP lets you flag parallel code and then uses those flags to program the GPU
by itself. In OpenGL / OpenCL / ..., you have to not only write the GPU code, but also:

- set up the computing pipeline and initialize resources,
- check for errors,
- manage memory transfers or mappings between host and device (i.e. GPU) memory,
- clean up resource.

Of course, that makes those APIs more flexible and I tend to see them more often used in large
projects than OpenMP, but in some cases, the simplicity of OpenMP makes it a more logical choice.
