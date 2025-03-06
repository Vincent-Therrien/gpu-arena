# Triton

Triton is a high-level GPU programming API developed by OpenAI that targets neural network
acceleration. It uses decorators in Python code to mark computations to accelerate. Since it uses
CUDA as a backend, it is only supported on Nvidia GPUs. Also, it only works on Linux / WSL (as of
March 2025). This project implements sum reduction and a softmax function.

Relevant links:

- OpenAI blog post: https://openai.com/index/triton/
- Github repository: https://github.com/triton-lang/triton

Run the following commands to try Triton.

```
pip install numpy
pip install torch
pip install triton
python3 main.py
```
