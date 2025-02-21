# OpenCL

OpenCL is a framework to accelerate programs across heterogeneous platforms, like GPUs, but also
CPUs, DSPs, and FPGAs. This project uses the Rust library `ocl` to compile the example, but you
can use it with other languages.

OpenCL uses the OpenCL C language, which is based on C99.


## Build

Run:

```
cargo run
```

Cargo and the OpenCL runtime must be installed on your system. To install cargo, refer to
https://doc.rust-lang.org/cargo/getting-started/installation.html. For OpenCL, install the driver
package of your GPU manufacturer.
