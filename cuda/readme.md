# CUDA

CUDA is a GPU programming framework by Nvidia that works only on their GPUs. You can find more
information at https://developer.nvidia.com/cuda-toolkit. This project uses CUDA to acceleration
sum reduction.

CUDA was released in 2007 and is currently used in several machine learning projects, like PyTorch
and Tensorflow. It is efficient and convenient to use, but since it is restricted to Nvidia GPUs,
some projects look into alternatives to develop cross-platform applications. For instance, llama.cpp
(https://github.com/ggml-org/llama.cpp) uses multiple GPU backends to support other platforms in
addition to Nvidia GPUs.


## Build

On linux, run the following commands:

```
sudo apt install nvidia-cuda-toolkit
mkdir build
cd build
nvcc ../main.cu -o main
./main
```


On Windows, download CUDA from https://developer.nvidia.com/cuda-downloads and run the following
commands:

```
mkdir build
cd build
nvcc ..\main.cu -o main
main.exe
```
