# OpenCL

OpenCL is a specification by Khronos group intended to accelerate programs across heterogeneous
platforms, like GPUs, but also CPUs, DSPs, and FPGAs. This project uses the Rust library `ocl` to
compile the example, but you can use it with other languages. OpenCL uses the OpenCL C language for
its kernels, which is based on C99.

I have two bones to pick with OpenCL:

- OpenCL is stuck in 2011. The last major release (3.0, 2020) defines OpenCL 1.2 (2011) as a
  mandatory baseline. Newer features implemented in OpenCL 2.X releases are optional! Consequently,
  OpenCL is behind competitors in terms of productivity.
- OpenCL has been described as generally slower than CUDA, but you can minimize the difference by
  optimizing your kernels (https://ieeexplore.ieee.org/document/6047190).


## Build

Run:

```
cargo run
```

Cargo and the OpenCL runtime must be installed on your system. To install cargo, refer to
https://doc.rust-lang.org/cargo/getting-started/installation.html. For OpenCL, install the driver
package of your GPU manufacturer.
