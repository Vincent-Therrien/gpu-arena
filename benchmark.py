"""
    Build and run all programs. If a program fails to build or run, it is
    discarded.

    Usage:

    $python3 benchmark.py
"""

import os
import subprocess
import matplotlib.pyplot as plt

BACKEND = "cpu-rust"
TASK = "1"
MIN_N = 10
MAX_N = 10_000_000
ITERATIONS = 5

if BACKEND == "cpu":
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/cpp")
    try:
        subprocess.check_call(["mkdir", "build"])
    except:
        pass
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/cpp/build")
    subprocess.check_call(["cmake", ".."])
    subprocess.check_call(["cmake", "--build", "."])
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/cpp/build/Debug")
    files = os.listdir()
    if "cpu.exe" in files:
        program = "cpu.exe"
    else:
        program = "cpu"

    x = []
    durations = {1: [], 2: [], 4: [], 8: []}
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
    for t in (1, 2, 4, 8):
        ax.plot(x, durations[t], label=f"{t}")
    ax.set(xlabel='Number of data points', ylabel='Duration (s)')
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.legend()
    plt.show()

elif BACKEND == "cpu-rust":
    os.chdir(os.path.dirname(os.path.abspath(__file__)) + "/cpu/rust")
    x = []
    durations = {1: [], 2: [], 4: [], 8: []}
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
    for t in (1, 2, 4, 8):
        ax.plot(x, durations[t], label=f"{t}")
    ax.set(xlabel='Number of data points', ylabel='Duration (s)')
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.legend()
    plt.show()

