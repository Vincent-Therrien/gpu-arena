# gpu-arena

- [English (en)](#a-guided-tour-of-gpu-frameworks)
- [Français (fr)](#visite-guidée-de-cadres-logiciels-pour-gpu)


## A Guided Tour of GPU Frameworks

Programming GPUs is a challenge - learn how to do it here!

Each directory of this project is a self-contained program that shows how to (1) install a GPU
programming framework, (2) build the program, and (3) execute it. With the exception of the `cpu`
directory, all programs are intended to run on GPUs.


### Program Index

- [CPU](cpu/readme.md): A baseline example intended to run on a multi-core **CPU**.
- [OpenCL](opencl/readme.md):


### Tasks

Each example can execute the following tasks:

1. Calculate the sum of elements in a 1D array. Primary example.
2. Multiply two matrices (low-priority).
3. Softmax function on a 1D array (low-priority).

Refer to the `readme` file in each subdirectory for instructions to run the examples.


### Benchmarking

Run the Python script `benchmark.py` to build and execute all examples:

```
# Linux
python3 benchmark.py

# Windows
py benchmark.py
```


## Visite guidée de cadres logiciels pour GPU

