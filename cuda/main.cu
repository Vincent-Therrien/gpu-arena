#include <iostream>
#include <cuda_runtime.h>

#define N 1024  // Array size (must be a power of 2 for reduction)
#define THREADS_PER_BLOCK 256

// CUDA kernel to sum array elements using parallel reduction
__global__ void sumReduction(float *input, float *output) {
    __shared__ float sharedData[THREADS_PER_BLOCK];

    int tid = threadIdx.x;
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    // Load elements into shared memory
    sharedData[tid] = (idx < N) ? input[idx] : 0.0f;
    __syncthreads();

    // Perform parallel reduction
    for (int s = blockDim.x / 2; s > 0; s >>= 1) {
        if (tid < s) {
            sharedData[tid] += sharedData[tid + s];
        }
        __syncthreads();
    }

    // Store result from each block
    if (tid == 0) {
        output[blockIdx.x] = sharedData[0];
    }
}

// Host function to launch kernel
float sumArrayOnGPU(float *h_array) {
    float *d_array, *d_partialSums;
    int numBlocks = (N + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;

    cudaMalloc(&d_array, N * sizeof(float));
    cudaMalloc(&d_partialSums, numBlocks * sizeof(float));

    cudaMemcpy(d_array, h_array, N * sizeof(float), cudaMemcpyHostToDevice);

    // Launch kernel
    sumReduction<<<numBlocks, THREADS_PER_BLOCK>>>(d_array, d_partialSums);

    // Copy partial sums back to host
    float *h_partialSums = new float[numBlocks];
    cudaMemcpy(h_partialSums, d_partialSums, numBlocks * sizeof(float), cudaMemcpyDeviceToHost);

    // Final sum on CPU
    float totalSum = 0.0f;
    for (int i = 0; i < numBlocks; i++) {
        totalSum += h_partialSums[i];
    }

    // Cleanup
    cudaFree(d_array);
    cudaFree(d_partialSums);
    delete[] h_partialSums;

    return totalSum;
}

// CPU code
int main() {
    float h_array[N];
    for (int i = 0; i < N; i++) {
        h_array[i] = 1.0f;
    }
    float sum = sumArrayOnGPU(h_array);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
