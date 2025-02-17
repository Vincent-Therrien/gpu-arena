gpu-arena
=========

- `English (en) <#a-guided-tour-of-gpu-frameworks>`_
- `Français (fr) <#visite-guidée-de-cadres-logiciels-pour-processeurs-graphiques>`_


A Guided Tour of GPU Programming Frameworks
+++++++++++++++++++++++++++++++++++++++++++

Self-contained projects that show how to install a GPU programming framework, build
GPU-accelerated programs, and execute them. Refer to the ``readme`` file in each subdirectory for
more information.

**Note**: The projects are minimalist examples, not complete tutorials. The ``readme`` files in each
subdirectory provide references to more detailed resources.


Project Index
-------------

+------------------------------------------+----------------------------+-------------------------------------------+---------------+
| Framework                                | Applications               | Devices                                   | Operating     |
|                                          +----------+-----------------+-----+-------+-------+-----+---------------+ Systems       +
|                                          | Graphics | General-purpose | CPU |Nvidia | Intel | AMD | Apple Silicon |               |
+==========================================+==========+=================+=====+=======+=======+=====+===============+===============+
|`OpenGL <opengl/readme.md>`__             | Y        | Y               | N   | Y     | Y     | Y   | N             | Any           |
|                                          |          |                 |     |       |       |     |               | (deprecated   |
|                                          |          |                 |     |       |       |     |               | on Mac)       |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`DirectX <directx/readme.md>`__           | Y        | Y               | N   | Y     | Y     | Y   | N             | Windows       |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`Vulkan <vulkan/readme.md>`__             | Y        | Y               | N   | Y     | Y     | Y   | N             | Any           |
|                                          |          |                 |     |       |       |     |               | (deprecated   |
|                                          |          |                 |     |       |       |     |               | on Mac)       |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`Metal <metal/readme.md>`__               | Y        | Y               | N   | N     | N     | N   | Y             | Mac           |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`WebGPU <webgpu/readme.md>`__             | Y        | Y               | N   | Y     | Y     | Y   | Y             | Any           |
|                                          |          |                 |     |       |       |     |               |               |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`CUDA <cuda/readme.md>`__                 | N        | Y               | N   | Y     | N     | N   | N             | Windows,      |
|                                          |          |                 |     |       |       |     |               | Linux         |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+
|`OpenCL <opencl/readme.md>`__             | N        | Y               | Y   | Y     | Y     | Y   | Y             | Any           |
|                                          |          |                 |     |       |       |     |               | (deprecated   |
|                                          |          |                 |     |       |       |     |               | on Mac)       |
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


Benchmarking
------------

Run the Python script ``benchmark.py`` to compare the performances of a project:

.. code:: bash
   # Linux
   python3 benchmark.py

   # OS that begins with the letter W
   py benchmark.py


Visite guidée de cadres logiciels pour processeurs graphiques
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
