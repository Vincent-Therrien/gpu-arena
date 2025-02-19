#include <chrono>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <thread>

#ifndef CACHE_LINE_SIZE
#define CACHE_LINE_SIZE 128 // Pad the result vector to avoid false sharing.
#endif

/// @brief Computations carried out by each thread.
/// @param a
/// @param chunk
/// @param n_elements
/// @param results
void partial_sum(const std::vector<float> &a, int chunk, int n_elements, std::vector<float> &results)
{
    int start = chunk * n_elements;
    int end = std::min(start + n_elements, (int)a.size());
    for (int i = start; i < end; i++) {
        results[chunk * CACHE_LINE_SIZE] += a[i];
    }
}

/// @brief  Dispatching
/// @param a
/// @param n_threads
void parallel_sum(std::vector<float> &a, int n_threads)
{
    std::vector<std::thread> threads;
    std::vector<float> results;

    if (n_threads == 1) {
        results.resize(1);
        partial_sum(std::ref(a), 0, a.size(), std::ref(results));
    }
    else {
        results.resize(n_threads * CACHE_LINE_SIZE);
        for (int t = 0; t < n_threads; t++) {
            int n_elements = (a.size() + n_threads - 1) / n_threads;
            threads.emplace_back(partial_sum, std::ref(a), t, n_elements, std::ref(results));
        }

        float result = 0.0;
        for (int t = 0; t < n_threads; t++) {
            threads[t].join();
            result += results[t * CACHE_LINE_SIZE];
        }
    }
}

double task_1(int n, int n_threads)
{
    std::vector<float> a;
    a.resize(n);
    for (unsigned int i = 0; i < n; i++) {
        a[i] = (((float)rand() / RAND_MAX) - 0.5) * 2.0;
    }
    auto begin = std::chrono::steady_clock::now();
    parallel_sum(a, n_threads);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
}
