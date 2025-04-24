# AcceleratedKernels.jl

AcceleratedKernels.jl (https://github.com/JuliaGPU/AcceleratedKernels.jl/tree/main) is a Julia
package for parallel computation on CPU and GPUs. It supports multiple platforms. Visit the page
https://juliagpu.github.io/AcceleratedKernels.jl/stable/ for explanations.

I'd classify AcceleratedKernels.jl as a "high-level" interface similar to Triton because it lets
developers mix CPU and GPU instructions in the same programming language instead of dividing a
program into regular code and kernel code (e.g. C / GLSL). Julia is appreciated in scientific
computing for its simplicity and performance, so support for GPU programming that further enhances
its performance fits nicely with the language.


## Run the Example

- Install Julia if it's not on your system: https://julialang.org/install/.
- Modify the requirements in the file `Project.toml` to target your GPU runtime. I used `CUDA`, but
  you might have to use `oneAPI` or `ROCm`, for instance. Refer to https://juliagpu.github.io/AcceleratedKernels.jl/stable/api/using_backends/
  to view the supported backends.
- Open a terminal in the directory `Project`.
- Install the requirements: enter the REPL by running `julia` in a terminal, type `]`, and run
  `instantiate`.
- Exit the Julia REPL.
- Run `julia src/Project.jl`.
