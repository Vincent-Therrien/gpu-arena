gpu-arena
=========

- `English (en) <#a-guided-tour-of-gpu-frameworks>`_
- `Français (fr) <#visite-guidée-de-cadres-logiciels-pour-processeurs-graphiques>`_

.. image:: assets/triangle.gif
   :width: 500
   :align: center
   :alt: Demonstration of simple 3D graphics. A colored triangle rotates on its vertical axis in
      front of a black background. The corners of the triangle are red, blue, and green, and the
      center of the triangle are colored in shades of these colors.


A Guided Tour of GPU Programming Frameworks
+++++++++++++++++++++++++++++++++++++++++++

Self-contained projects that show how to install GPU programming frameworks, build
GPU-accelerated programs, and execute them. Click on the links in the index table below to access
the ``readme`` file of each project for more information.

The projects are minimal examples, not complete tutorials! Each ``readme`` file provides references
to more detailed resources. Contributions are welcome - you can enrich the current projects and even
add other GPU programming frameworks!


Project Index
-------------

Click on the links in the leftmost column to access the corresponding subdirectory.  ``Y`` indicates
that the framework supports the application or device. ``N`` indicates that it does not support
them.

+------------------------------------------+----------------------------+-------------------------------------------+---------------+------------------+
| Framework                                | Applications               | Devices                                   | Operating     | Shading / kernel |
|                                          +----------+-----------------+-----+-------+-------+-----+---------------+ Systems       | language         |
|                                          | Graphics | General-purpose | CPU |Nvidia | Intel | AMD | Apple Silicon |               |                  |
+==========================================+==========+=================+=====+=======+=======+=====+===============+===============+==================+
|`OpenGL <opengl/readme.md>`__             | Y        | Y (since        | N   | Y     | Y     | Y   | N             | Any           | GLSL             |
|                                          |          | version 4.3,    |     |       |       |     |               | (deprecated   |                  |
|                                          |          | 2012)           |     |       |       |     |               | on Mac)       |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`Metal <metal/readme.md>`__               | Y*       | Y*              | N   | N     | N     | N   | Y             | Mac / iOS     | MSL              |
|                                          |          |                 |     |       |       |     |               |               |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`DirectX <directx/readme.md>`__           | Y        | Y               | N   | Y     | Y     | Y   | N             | Windows       | HLSL             |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`Vulkan <vulkan/readme.md>`__             | Y        | Y (implemented  | N   | Y     | Y     | Y   | N             | Any           | Anything that    |
|                                          |          | with kompute)   |     |       |       |     |               | (deprecated   | compiles to      |
|                                          |          |                 |     |       |       |     |               | on Mac)       | SPIR-V           |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`WebGPU <webgpu/readme.md>`__             | Y        | Y               | N   | Y     | Y     | Y   | Y             | Any           | WGSL             |
|                                          |          |                 |     |       |       |     |               |               |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`CUDA <cuda/readme.md>`__                 | N        | Y               | N   | Y     | N     | N   | N             | Windows,      | CUDA             |
|                                          |          |                 |     |       |       |     |               | Linux         |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`OpenCL <opencl/readme.md>`__             | N        | Y               | Y   | Y     | Y     | Y   | Y             | Any           | OpenCL C         |
|                                          |          |                 |     |       |       |     |               | (deprecated   |                  |
|                                          |          |                 |     |       |       |     |               | on Mac)       |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`SYCL <sycl/readme.md>`__                 | N        | Y*              | Y   | Y     | Y     | Y   | Y             | Any (CPU-only | C++ extensions   |
|                                          |          |                 |     |       |       |     |               | on Mac)       |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`Triton <triton/readme.md>`__             | N        | Y               | N   | Y     | N     | Y   | N             | Linux         | Decorated Python |
|                                          |          |                 |     |       |       |     |               |               | functions        |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
| `OpenMP <openmp/readme.md>`__            | N        | Y               | Y   | Y     | Y     | Y   | Y             | Any           | Compiler         |
|                                          |          |                 |     |       |       |     |               |               | directives       |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
| `AcceleratedKernels.jl                   | N        | Y               | Y   | Y     | Y     | Y   | Y             | Any           | Julia functions  |
| <AcceleratedKernels.jl/readme.md>`__     |          |                 |     |       |       |     |               |               |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`CPU <cpu/readme.md>`__ (baseline)        | N        | Y               | Y   | N     | N     | N   | N             | Any           | N/A              |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+

- ``*``: The corresponding example is not implemented in the project.


Other Frameworks
----------------

There are even more frameworks that can be used to program GPUs! Below are listed a few of them;
no example is implemented in this repository, but you can follow the links to learn more about
them.

- Bend (https://github.com/HigherOrderCO/Bend): a programming language for parallel computing.
- Chapel (https://chapel-lang.org/gpu/): another programming language for parallel computing.
- Mojo (https://www.modular.com/mojo): a programming language for heterogeneous computing.
- oneAPI (https://www.intel.com/content/www/us/en/developer/tools/oneapi/overview.html): A
  software stack for high performance computing by Intel. Based on SYCL, but also adds custom
  extensions to implement new features.
- OpenACC (https://www.openacc.org/): A parallel computing standard.
- ROCm (https://www.amd.com/fr/products/software/rocm.html): A software stack for high performance
  computing by AMD. Supports OpenCL, HIP, OpenMP.
- Slang (https://www.khronos.org/news/press/khronos-group-launches-slang-initiative-hosting-open-source-compiler-contributed-by-nvidia):
  a shading language and compiler that can target multiple APIs.
- rust-gpu (https://github.com/Rust-GPU/rust-gpu) a framework under development that enables
  seamless integration of GPU code into Rust code. It's a little like SYCL but for Rust instead of
  C++, and in contrast to SYCL, rust-gpu supports both general-purpose AND graphics applications.
  The project is not production-ready as of July 2025.


GPU Projects
------------

Some projects that use GPU programming. Don't hesitate to create a PR if you want to add any!

- Artificial Intelligence:
    - burn (https://github.com/tracel-ai/burn): Deep learning framework that uses WebGPU as its
      backend for increased portability. It also uses SPIR-V to perform some optimizations that
      WebGPU does not support.
    - PyTorch (https://github.com/pytorch/pytorch): Deep learning library that uses CUDA and ROCm for
      GPU acceleration.
    - TensorFlow (https://github.com/tensorflow/tensorflow): Deep learning library that uses CUDA for
      GPU acceleration.
- Graphics:
    - Godot Shaders (https://godotshaders.com/): A collection of shaders that can be used in the
      Godot game engine. It uses a shading language similar to GLSL.
- Physics:
    - FluidX3D (https://github.com/ProjectPhysX/FluidX3D): Computational fluid dynamics software
      implemented with OpenCL.
    - gpu-io (https://github.com/amandaghassaei/gpu-io): A library for running physics simulations in
      a browser. Implemented with WebGL.
    - PixelFlow (https://github.com/diwi/PixelFlow): A physics simulation framework based on Java
      and OpenGL.
- Bioinformatics:
    - genome-spy (https://github.com/genome-spy/genome-spy): Toolkit for analyzing genomic data
      implemented with WebGL.
    - GenomeWorks (https://github.com/NVIDIA-Genomics-Research/GenomeWorks): CUDA-accelerated DNA
      analysis and alignment SDK.
- Cryptography:
    - hashcat (https://github.com/hashcat/hashcat): Software recovery program implemented with
      OpenMP, CUDA, and OpenCL.


Additional Resources
--------------------

- Step-by-step guide that explains how to optimize a GPU-accelerate program (CUDA):
  https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf
- Introduction to CUDA and OpenCL programming: https://parlab.eecs.berkeley.edu/sites/all/parlab/files/CatanzaroIntroToCUDAOpenCL_0.pdf.
  Check the slide 27 for a comparison of the lexicon used in the two frameworks.


Benchmarking
------------

Run the Python script ``benchmark.py`` to compare how performances vary depending on the number of
threads running on CPU:

.. code:: bash

   # Linux
   python3 benchmark.py

   # OS that begins with the letter W
   py benchmark.py


-----


Visite guidée de cadres logiciels pour processeurs graphiques
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Ce dépôt contient des projets sans dépendances qui montrent comment installer un cadre logiciel de
programmation de GPU, comment construire des programmes accélérés par GPU, et comment les exécuter.
Cliquez sur les liens dans le tableau ci-dessous pour accéder à des informations supplémentaires
sur chaque projet.

Ces projets sont des exemples minimalistes et non des tutoriels complets. Les fichiers
``readme`` dans chaque sous-répertoire fournissent des ressources plus détaillées.


Indice des projets
------------------

+------------------------------------------+----------------------------+-------------------------------------------+---------------+------------------+
| Cadre logiciel                           | Applications               | Appareils                                 | Systèmes      | Language de      |
|                                          +----------+-----------------+-----+-------+-------+-----+---------------+ d'exploitation| nuanceurs /      |
|                                          |Graphique | Calculs généraux| CPU |Nvidia | Intel | AMD | Apple Silicon |               | noyaux           |
+==========================================+==========+=================+=====+=======+=======+=====+===============+===============+==================+
|`OpenGL <opengl/readme.md>`__             | O        | O (depuis la    | N   | O     | O     | O   | N             | Tous          | GLSL             |
|                                          |          | version 4.3,    |     |       |       |     |               | (réprouvé     |                  |
|                                          |          | 2012)           |     |       |       |     |               | sur Mac)      |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`DirectX <directx/readme.md>`__           | O        | O               | N   | O     | O     | O   | N             | Windows       | HLSL             |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`Metal <metal/readme.md>`__               | O*       | O*              | N   | N     | N     | N   | O             | Mac / iOS     | MSL              |
|                                          |          |                 |     |       |       |     |               |               |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`Vulkan <vulkan/readme.md>`__             | O        | O (avec         | N   | O     | O     | O   | N             | Tous          | Tous se qui se   |
|                                          |          | kompute)        |     |       |       |     |               | (réprouvé     | compile vers     |
|                                          |          |                 |     |       |       |     |               | sur Mac)      | SPIR-V           |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`WebGPU <webgpu/readme.md>`__             | O        | O               | N   | O     | O     | O   | O             | Tous          | WGSL             |
|                                          |          |                 |     |       |       |     |               |               |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`CUDA <cuda/readme.md>`__                 | N        | O               | N   | O     | N     | N   | N             | Windows,      | CUDA             |
|                                          |          |                 |     |       |       |     |               | Linux         |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`OpenCL <opencl/readme.md>`__             | N        | O               | O   | O     | O     | O   | O             | Tous          | OpenCL C         |
|                                          |          |                 |     |       |       |     |               | (réprouvé     |                  |
|                                          |          |                 |     |       |       |     |               | sur Mac)      |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`SYCL <sycl/readme.md>`__                 | N        | O*              | O   | O     | O     | O   | O             | Tous (CPU     | Extensions C++   |
|                                          |          |                 |     |       |       |     |               | seulement sur |                  |
|                                          |          |                 |     |       |       |     |               | Mac)          |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`Triton <triton/readme.md>`__             | N        | O               | N   | O     | N     | O   | N             | Linux         | Fonctions        |
|                                          |          |                 |     |       |       |     |               |               | Pythons          |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
| `OpenMP <openmp/readme.md>`__            | N        | O               | O   | O     | O     | O   | O             | Tous          | Directives de    |
|                                          |          |                 |     |       |       |     |               |               | compilateur      |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
| `AcceleratedKernels.jl                   | N        | O               | O   | O     | O     | O   | O             | Tous          | Fonctions Julia  |
| <AcceleratedKernels.jl/readme.md>`__     |          |                 |     |       |       |     |               |               |                  |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+
|`CPU <cpu/readme.md>`__                   | N        | O               | O   | N     | N     | N   | N             | Tous          | N/A              |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+

- Le signe ``*`` indique que l'exemple correspondant n'est pas inclus dans le projet.


Autres cadriciels
-----------------

Encore d'autres cadriciels sont disponibles pour programmer des GPU! La liste ci-dessous en présente
quelques-uns. Aucun exemple n'est implémenté pour eux dans ce dépôt, mais vous pouvez suivre les
liens pour en apprendre davantage.

- Bend (https://github.com/HigherOrderCO/Bend): un langage de programmation pour le calcul
  parallèle.
- Chapel (https://chapel-lang.org/gpu/): un autre langage de programmation pour le calcul
  parallèle.
- Mojo (https://www.modular.com/mojo): un langage pour calcul hétérogène.
- oneAPI (https://www.intel.com/content/www/us/en/developer/tools/oneapi/overview.html): Une pile
  logicielle pour le calcul haute performance par Intel. Basé sur SYCL, mais utilise aussi des
  extensions spécifiques au projet pour implémenter de nouvelles fonctionnalités.
- OpenACC (https://www.openacc.org/): un standard de calcul parallèle.
- ROCm (https://www.amd.com/fr/products/software/rocm.html): Une pile logicielle pour calcule de
  haute performance par AMD. Supporte OpenCL, HIP, OpenMP.
- Slang (https://www.khronos.org/news/press/khronos-group-launches-slang-initiative-hosting-open-source-compiler-contributed-by-nvidia):
  un compilateur et langage de nuanceur qui cible plusieurs API.
- rust-gpu (https://github.com/Rust-GPU/rust-gpu) un cadriciel en développement pour intégrer du
  code destiné à un GPU dans du code Rust. Similaire à SYCL mais vise Rust au lieu du C++ et permet
  de développer des applications graphiques. Pas encore prêt pour la production en Juillet 2025.


Projets
-------

Quelques projets qui utilisent des GPU. N'hésitez pas à créer un PR pour en ajouter à la liste :

- Intelligence artificielle :
    - burn (https://github.com/tracel-ai/burn) : Cadriciel d'apprentissage profond qui utilise
      WebGPU pour améliorer la portabilité. Utilise aussi SPIR-V directement pour effectuer certaines
      optimisations que WebGPU ne supporte pas.
    - PyTorch (https://github.com/pytorch/pytorch) : Cadriciel d'apprentissage profond qui utilise
      CUDA et ROCm.
    - TensorFlow (https://github.com/tensorflow/tensorflow) :  Cadriciel d'apprentissage profond
      qui utilise CUDA.
- Graphisme :
    - Godot Shaders (https://godotshaders.com/) : Un ensemble de nuanceurs qui peuvent être utilisés
      avec le moteur de jeu Godot. Ils utilisent un langage de nuanceur proche de GLSL.
- Physique :
    - FluidX3D (https://github.com/ProjectPhysX/FluidX3D): Programme de dynamique des fluides
      réalisé avec OpenCL.
    - gpu-io (https://github.com/amandaghassaei/gpu-io): Bibliothèque de simulation physique
      utilisable dans un navigateur Web. Réalisé avec WebGL.
    - PixelFlow (https://github.com/diwi/PixelFlow): Cadriciel de simulation physique réalisé avec
      Java et OpenGL.
- Bioinformatique :
    - genome-spy (https://github.com/genome-spy/genome-spy) : Outils d'analyse génomique réalisé avec
      WebGL.
    - GenomeWorks (https://github.com/NVIDIA-Genomics-Research/GenomeWorks) : Analyse et alignement
      d'ADN avec CUDA.
- Cryptographie :
    - hashcat (https://github.com/hashcat/hashcat) : Programme de récupération de mots de passe
      réalisé avec OpenMP, CUDA et OpenCL.


Ressources additionnelles
-------------------------

- Guide d'optimisation de programme pour GPU (CUDA) :
  https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf
- Introduction à la programmation sur CUDA et OpenCL : https://parlab.eecs.berkeley.edu/sites/all/parlab/files/CatanzaroIntroToCUDAOpenCL_0.pdf.
  Consultez la diapositive 27 pour une comparaison des lexiques utilisés par chaque cadre logiciel.


Comparaisons
-------------

Exécutez le script ``benchmark.py`` pour comparer les performances d'un programme utilisant
plusieurs fils d'exécution sur CPU:

.. code:: bash

   # Linux
   python3 benchmark.py

   # OS that begins with the letter W
   py benchmark.py
