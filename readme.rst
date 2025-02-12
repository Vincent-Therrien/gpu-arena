gpu-arena
=========

- `English (en) <#a-guided-tour-of-gpu-frameworks>`_
- `Français (fr) <#visite-guidée-de-cadres-logiciels-pour-processeurs-graphiques>`_


A Guided Tour of GPU Programming Frameworks
+++++++++++++++++++++++++++++++++++++++++++

Programming GPUs is challenging - learn how to do it here.

This repository comprises self-contained projects that show how to install a GPU programming
framework, build a GPU-accelerated program, and execute it. Refer to the `readme` file in each
subdirectory for the instructions.


Framework Index
---------------

+------------------------------------------+----------------------------+-----------+-----------------------------------+
| Framework                                | Applications               | OS        | Devices                           |
|                                          +----------+-----------------+           +-----+-------+-------+-----+-------+
|                                          | Graphics | General-purpose |           | CPU |Nvidia | Intel | AMD | Apple |
+==========================================+==========+=================+===========+=====+=======+=======+=====+=======+
|:ref:`CPU<cpu/readme.md>`                 | N        | Y               | Any       | Y   | N     | N     | N   | N     |
+------------------------------------------+----------+-----------------+-----------+-----+-------+-------+-----+-------+
|:ref:`OpenGL<opengl/readme.md>`           | Y        | Y               | Any       | Y   | Y     | Y     | Y   | N     |
+------------------------------------------+----------+-----------------+-----------+-----+-------+-------+-----+-------+
|:ref:`DirectX<directx/readme.md>`         | Y        | Y               | Windows   | Y   | Y     | Y     | Y   | N     |
+------------------------------------------+----------+-----------------+-----------+-----+-------+-------+-----+-------+


Computing Tasks
---------------

Each project in this repository can execute the following tasks:

1. Calculate the sum of elements in a 1D array.
2. Multiply two matrices.
3. Calculate a Softmax function on a 1D array.


Benchmarking
------------

Run the Python script `benchmark.py` to measure the performances of a project:

```
# Linux
python3 benchmark.py

# OS that begins with the letter W
py benchmark.py
```


Visite guidée de cadres logiciels pour processeurs graphiques
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
