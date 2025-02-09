# CPU

Run the tasks on multi-core CPUs.


## C++ Version


### Build

- Install [cmake](https://cmake.org/) on your system.
- Install [clang](`https://clang.llvm.org/`) on your system (yes, even if you are on W*ndows! No
  one uses VSC on my watch.)
- Navigate in the `cpp` directory.
- Create a `build` subdirectory.
- Navigate in the `build` subdirectory.
- Run the command `cmake --build .`.


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
