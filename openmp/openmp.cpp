#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int N = 100000;
    std::vector<float> elements(N, 1.0f);
    float* array = elements.data();
    float sum = 0.0f;

    #pragma omp target data map(to: array[0:N]) map(tofrom: sum)
    {
        #pragma omp target teams distribute parallel for reduction(+:sum)
        for (int i = 0; i < N; ++i) {
            sum += array[i];
        }
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
