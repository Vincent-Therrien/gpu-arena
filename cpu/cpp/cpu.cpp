#include <iostream>
#include <string>

#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"

void usage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "cpu <task> <iterations> <n> <threads>" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        usage();
        return 1;
    }
    int task, n, n_threads, iterations;
    try {
        task = stoi(std::string(argv[1]));
        n = stoi(std::string(argv[2]));
        iterations = stoi(std::string(argv[3]));
        n_threads = stoi(std::string(argv[4]));
    }
    catch (...) {
        usage();
        return 1;
    }
    double duration = 0.0;
    for (unsigned int i = 0; i < iterations; i++) {
        if (task == 1) {
            duration += task_1(n, n_threads);
        }
        else if (task == 2) {
            duration += task_2(n, n_threads);
        }
        else if (task == 3) {
            duration += task_3(n, n_threads);
        }
        else {
            usage();
            break;
        }
    }
    std::cout << "Average duration (s): " << duration << std::endl;
}
