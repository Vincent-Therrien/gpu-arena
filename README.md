# gpu-arena

- [English (en)](#a-guided-tour-of-gpu-frameworks)
- [Français (fr)](#visite-guidée-de-cadres-logiciels-pour-gpu)


## A Guided Tour of GPU Frameworks

Learn to select the best GPU framework for your use case. Each directory of this project is a
self-contained example that shows how to (1) install the framework, (2) build the example, and (3)
execute it. With the exception of the `cpu` directory, all examples are intended to run on GPUs.


### Index

- [CPU](cpu/readme.md): A baseline example intended to run on a multi-core **CPU**.
- [OpenCL](opencl/readme.md):


### Tasks

Each example can execute the following tasks:

1. Calculate the sum of elements in a 1D array.
2. Multiply two matrices.
3. Softmax function on a 1D array.

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

