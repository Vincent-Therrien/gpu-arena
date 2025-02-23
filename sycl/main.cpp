// This code is not functional yet! I have not managed to compile it with oneAPI.

#include <CL/sycl.hpp>
#include <iostream>

int main() {
    sycl::queue q; // Create a SYCL queue (chooses a default device)

    std::cout << "Running on: " << q.get_device().get_info<sycl::info::device::name>() << "\n";

    const int N = 1024;
    std::vector<int> data(N, 1); // Initialize array with 1s

    {
        sycl::buffer<int, 1> buf(data.data(), sycl::range<1>(N));
        q.submit([&](sycl::handler &h) {
            sycl::accessor acc(buf, h, sycl::write_only, sycl::no_init);
            h.parallel_for(sycl::range<1>(N), [=](sycl::id<1> i) {
                acc[i] = i[0]; // Set each element to its index
            });
        });
    } // Buffer goes out of scope -> Data is copied back

    std::cout << "First 10 elements: ";
    for (int i = 0; i < 10; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
