#include <chrono>
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <thread>

/// @brief Perfor a matrix multiplication with tiling to avoid false sharing.
/// @param a
/// @param b
/// @param c
/// @param chunk
/// @param n_elements
void partial_mul(
    std::vector<std::vector<float>> &a,
    std::vector<std::vector<float>> &b,
    std::vector<std::vector<float>> &c,
    int chunk,
    int n_elements
) {
    int N = a.size();
    int TILE_SIZE = 32;
    for (int i = chunk; i < N; i += TILE_SIZE) {
        for (int j = 0; j < N; j += TILE_SIZE) {
            for (int k = 0; k < N; k += TILE_SIZE) {
                for (int ii = i; ii < std::min(i + TILE_SIZE, N); ++ii) {
                    for (int jj = j; jj < std::min(j + TILE_SIZE, N); ++jj) {
                        double sum = 0.0;
                        for (int kk = k; kk < std::min(k + TILE_SIZE, N); ++kk) {
                            sum += a[ii][kk] * b[kk][jj];
                        }
                        c[ii][jj] += sum;
                    }
                }
            }
        }
    }
}

void parallel_mat_mul(
    std::vector<std::vector<float>> &a,
    std::vector<std::vector<float>> &b,
    std::vector<std::vector<float>> &c,
    int n_threads
) {
    std::vector<std::thread> threads;
    int n_elements = (a.size() + n_threads - 1) / n_threads;
    for (int t = 0; t < n_threads; t++) {
        threads.emplace_back(partial_mul, std::ref(a), std::ref(b), std::ref(c), t, n_elements);
    }
    for (int t = 0; t < n_threads; t++) {
        threads[t].join();
    }
}

double task_2(int n, int n_threads) {
    std::vector<std::vector<float>> a; // Input
    std::vector<std::vector<float>> b; // Input
    std::vector<std::vector<float>> c; // Result
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for (unsigned int i = 0; i < n; i++) {
        a[i].resize(n);
        b[i].resize(n);
        c[i].resize(n);
        for (unsigned int j = 0; j < n; j++) {
            a[i][j] = (((float)rand() / RAND_MAX) - 0.5) * 2.0;
            b[i][j] = (((float)rand() / RAND_MAX) - 0.5) * 2.0;
        }
    }
    auto begin = std::chrono::steady_clock::now();
    parallel_mat_mul(a, b, c, n_threads);
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
}
