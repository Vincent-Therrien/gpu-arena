gpu-arena
=========

- `English (en) <#a-guided-tour-of-gpu-frameworks>`_
- `Français (fr) <#visite-guidée-de-cadres-logiciels-pour-processeurs-graphiques>`_


A Guided Tour of GPU Programming Frameworks
+++++++++++++++++++++++++++++++++++++++++++

Programming GPUs is challenging - learn how to do it here.

This repository comprises self-contained projects that show how to install a GPU programming
framework, build a GPU-accelerated program, and execute it. Refer to the ``readme`` file in each
subdirectory for detailed instructions.


Project Index
-------------

+------------------------------------------+----------------------------+-------------------------------------------+---------------+
| Framework                                | Applications               | Devices                                   | Operating     |
|                                          +----------+-----------------+-----+-------+-------+-----+---------------+ Systems       +
|                                          | Graphics | General-purpose | CPU |Nvidia | Intel | AMD | Apple Silicon |               |
+==========================================+==========+=================+=====+=======+=======+=====+===============+===============+
|`OpenGL <opengl/readme.md>`__             | Y        | Y               | N   | Y     | Y     | Y   | N             | Any           |
|                                          |          |                 |     |       |       |     |               | (legacy       |
|                                          |          |                 |     |       |       |     |               | on Mac)       |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`DirectX <directx/readme.md>`__           | Y        | Y               | N   | Y     | Y     | Y   | N             | Windows       |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`Vulkan <vulkan/readme.md>`__             | Y        | Y               | N   | Y     | Y     | Y   | N             | Any (partial  |
|                                          |          |                 |     |       |       |     |               | on Mac)       |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`Metal <metal/readme.md>`__               | Y        | Y               | N   | N     | N     | N   | Y             | Mac           |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`WebGPU <webgpu/readme.md>`__             | Y        | Y               | N   | Y     | Y     | Y   | Y             | Any           |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`CUDA <cuda/readme.md>`__                 | N        | Y               | N   | Y     | N     | N   | N             | Any           |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`OpenCL <opencl/readme.md>`__             | N        | Y               | Y   | Y     | Y     | Y   | Y             | Any           |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`SYCL <sycl/readme.md>`__                 | N        | Y               | Y   | Y     | Y     | Y   | Y             | Any           |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`Triton <triton/readme.md>`__             | N        | Y               | N   | Y     | N     | Y   | N             | Linux         |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`Bend <bend/readme.md>`__                 | N        | Y               | N   | Y     | N     | N   | N             | Linux, Mac    |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`CPU <cpu/readme.md>`__                   | N        | Y               | Y   | N     | N     | N   | N             | Any           |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+


Computing Tasks
---------------

Each project in this repository can execute the following tasks:

1. Calculate the sum of elements in a 1D array.
2. Multiply two matrices.
3. Calculate a Softmax function on a 1D array.


Benchmarking
------------

Run the Python script ``benchmark.py`` to measure the performances of a project:

.. code:: bash
   # Linux
   python3 benchmark.py

   # OS that begins with the letter W
   py benchmark.py


Visite guidée de cadres logiciels pour processeurs graphiques
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
