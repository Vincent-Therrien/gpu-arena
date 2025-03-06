"""
    Build and run multithreaded CPU programs.

    A multithreaded is not necessarily faster than a purely sequential one!
    Multithreading entails some overhead when splitting data and coordinating
    threads, so a single thread often outperforms multiple ones for small
    datasets. This script lets you measure which thread count is most efficient
    for a given dataset size.

    Usage:

    $python3 benchmark.py
"""

import os
import subprocess
import matplotlib.pyplot as plt

BACKEND = "cpu-cpp"  # WHich accelerated program to use (either cpu-cpp or cpu-rust).
TASK = "1"  # Refer to the file `cpu/readme.md`` for a description of each task.
MIN_N = 10_000  # Minimum dataset size.
MAX_N = 10_000_000  # Maximum dataset size.
ITERATIONS = 5  # Number of iterations to perform. The duration is the average of all iterations.
N_THREADS = (1, 2)  # Number of threads to use in each comparison.

durations = {}
for n in N_THREADS:
    durations[n] = []


def cpu_cpp():
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/cpp")
    try:
        subprocess.check_call(["mkdir", "build"])
    except:
        pass
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/cpp/build")
    subprocess.check_call(["cmake", ".."])
    subprocess.check_call(["cmake", "--build", ".", "--config", "Release"])
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/cpp/build/Release")
    files = os.listdir()
    if "cpu.exe" in files:
        program = "cpu.exe"
    else:
        program = "cpu"

    x = []
    n = MIN_N
    while n <= MAX_N:
        print(f"N: {n}")
        x.append(n)
        for t in durations:
            print(f"   t: {t} = ", end = "")
            v = subprocess.run(
                [program, TASK, str(n), str(ITERATIONS), str(t)],
                capture_output = True,
                text = True
            ).stdout
            durations[t].append(float(str(v).split(" ")[-1].rstrip()))
            print(durations[t][-1])
        n *= 10

    fig, ax = plt.subplots()
    for t in N_THREADS:
        ax.plot(x, durations[t], label=f"{t}")
    ax.set(xlabel='Number of data points', ylabel='Duration (s)')
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.legend()
    plt.show()


def cpu_rust():
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/rust")
    x = []
    n = MIN_N
    while n <= MAX_N:
        print(f"N: {n}")
        x.append(n)
        for t in durations:
            print(f"   t: {t} = ", end = "")
            program = [
                "cargo", "run", "--",
                "--task", str(TASK),
                "--n", str(n),
                "--iterations", str(ITERATIONS),
                "--threads", str(t)
            ]
            v = subprocess.run(
                program,
                capture_output = True,
                text = True
            ).stdout
            durations[t].append(float(str(v).split(" ")[-1].rstrip()))
            print(durations[t][-1])
        n *= 10

    fig, ax = plt.subplots()
    for t in N_THREADS:
        ax.plot(x, durations[t], label=f"{t}")
    ax.set(xlabel='Number of data points', ylabel='Duration (s)')
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.legend()
    plt.show()


if BACKEND == "cpu-cpp" or BACKEND == "cpu":
    cpu_cpp()
elif BACKEND == "cpu-rust":
    cpu_rust()
