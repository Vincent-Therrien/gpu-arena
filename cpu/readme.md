# CPU

Algorithm acceleration with multi-threading on CPUs.

Most projects in this repository demonstrate how to use GPUs (graphics processing units), which
excel at processing **large** amounts of ideally **weakly dependent** data. GPUs are inadequate for
many situations, in which case you can fall back on CPUs (central processing units). This repository
contains programs written in C++ and Rust to show how to use threads to accelerate algorithms.


## C++ Version

This project uses the class `std::thread` to implement multithreading. It's also possible to use
the function `pthread_create` to launch threads.


### Build the Project

- Install [cmake](https://cmake.org/) on your system.
- Install [clang](`https://clang.llvm.org/`) on your system (yes, even if you are on W*ndows!)
- Navigate in the `cpp` directory.
- Create a `build` subdirectory.
- Navigate in the `build` subdirectory.
- Run the command `cmake ..`.
- Run the command `cmake --build . --config Release`.

**Note**: The option `--config Release` is important because it instructs cmake to add optimization
flags. Without them, the compiler will not optimize aggressively enough and you might notice that
multithreading *decreases* performances instead of improving them.


### Usage

Run:

```
# Linux
./build/Debug/cpu <task> <n> <iterations> <threads>

# On the OS that begins with the letter W
build\Debug\cpu.exe <task> <n> <iterations> <threads>
```

where:

- `<task>` is an integer ranging from 1 to 3, inclusively, that designates the task to execute
  (refer to the [root readme file](https://github.com/Vincent-Therrien/gpu-arena/tree/main) to view
  the tasks).
- `<n>` is the dimension of the input data.
- `<iterations>` is the number of times that the computation must be repeated. The execution time
  reported by the program is the arithmetic mean of the duration of all iterations.
- `<threads>` is the number of threads.


## Rust Version

This project uses the standard modules `std::thread` and `std::sync::Arc` to implement
multithreading.


### Build

- Install [cargo](https://doc.rust-lang.org/stable/cargo/) on your system.
- Run the command `cargo build --release`.


### Usage

Run the command:

```
# Linux
./target/release/cpu --task <t> --n <n> --iterations <i> --thread <c>

# Windows
target\release\cpu --task <t> --n <n> --iterations <i> --thread <c>
```

where

- `<t>` is an integer ranging from 1 to 3, inclusively, that designates the task to execute
  (refer to the [root readme file](https://github.com/Vincent-Therrien/gpu-arena/tree/main) to view
  the tasks). Default: 1
- `<n>` is the dimension of the input data. Default: 1000
- `<i>` is the number of times that the computation must be repeated. The execution time reported
  by the program is the arithmetic mean of the duration of all iterations. Default: 1
- `<c>` is the number of threads. Default: 1
