# CUDA

CUDA is a GPU programming framework by Nvidia that works only on their GPUs.


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
