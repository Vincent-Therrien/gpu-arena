# Triton

Triton is a high-level GPU programming API that targets neural network acceleration. It uses
decorators in Python code to mark computations to accelerate. Visit
https://openai.com/index/triton/ for more details.

Run the following commands to try Triton. This only works on Linux / WSL and using an Nvidia GPU.

```
pip install numpy
pip install torch
pip install triton
python3 main.py
```

This script demonstrates how to compute a softmax function.
