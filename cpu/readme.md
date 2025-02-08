# CPU

Implement the tasks in Rust and run them on multi-core CPUs.


## Build

- Install [cargo](https://doc.rust-lang.org/stable/cargo/) on your system.
- Run the command `cargo build --release`.


## Usage

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
