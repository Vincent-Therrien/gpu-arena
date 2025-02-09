#include <cmath>
#include <chrono>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <thread>

#ifndef CACHE_LINE_SIZE
#define CACHE_LINE_SIZE 128
#endif

void exponential_partial_sum(const std::vector<float> &a, int chunk, int n_elements, std::vector<float> &results)
{
    int start = chunk * n_elements;
    int end = std::min(start + n_elements, (int)a.size());
    for (int i = start; i < end; i++) {
        results[chunk * CACHE_LINE_SIZE] += exp(a[i]);
    }
}

void modify_elements(std::vector<float> &a, int chunk, int n_elements, float exponential_sum)
{
    int start = chunk * n_elements;
    int end = std::min(start + n_elements, (int)a.size());
    for (int i = start; i < end; i++) {
        a[i] = exp(a[i]) / exponential_sum;
    }
}

void parallel_softmax(std::vector<float> &a, int n_threads)
{
    std::vector<std::thread> threads;
    std::vector<float> exponential_sums;
    exponential_sums.resize(n_threads * CACHE_LINE_SIZE);
    int n_elements = (a.size() + n_threads - 1) / n_threads;

    // Calculate the sum e raised to the power of all elements
    for (int t = 0; t < n_threads; t++) {
        threads.emplace_back(exponential_partial_sum, std::ref(a), t, n_elements, std::ref(exponential_sums));
    }

    float exponential_sum = 0.0;
    for (int t = 0; t < n_threads; t++) {
        threads[t].join();
        exponential_sum += exponential_sums[t * CACHE_LINE_SIZE];
    }

    // Modify elements in place.
    threads.clear();
    for (int t = 0; t < n_threads; t++) {
        threads.emplace_back(modify_elements, std::ref(a), t, n_elements, exponential_sum);
    }

    for (int t = 0; t < n_threads; t++) {
        threads[t].join();
    }
}

double task_3(int n, int n_threads)
{
    std::vector<float> a;
    a.resize(n);
    for (unsigned int i = 0; i < n; i++) {
        a[i] = (((float)rand() / RAND_MAX) - 0.5) * 2.0;
    }
    auto begin = std::chrono::steady_clock::now();
    parallel_softmax(a, n_threads);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
}
