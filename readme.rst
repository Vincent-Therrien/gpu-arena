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

The projects are minimal examples, not complete tutorials. The ``readme`` files in each subdirectory
provide references to more detailed resources. Contributions are welcome - you can enrich the
current projects and even add other GPU programming frameworks!


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
|`CPU <cpu/readme.md>`__ (baseline)        | N        | Y               | Y   | N     | N     | N   | N             | Any           | N/A              |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+

- ``*``: The corresponding example is not implemented in the project.


Other Frameworks
----------------

There are even more frameworks that can be used to program GPUs! Below are listed a few of them;
no example is implemented in this repository, but you can follow the links to learn more about
them.

- AcceleratedKernels.jl (https://juliagpu.github.io/AcceleratedKernels.jl/stable/): A Julia project
  that can accelerate parallel computations with CPUs and GPUs. Uses multiple backends (oneAPI,
  ROCm, Metal, CUDA) to improve portability.
- Bend (https://github.com/HigherOrderCO/Bend): a programming language for parallel computing.
- Chapel (https://chapel-lang.org/gpu/): another programming language for parallel computing.
- Mojo (https://www.modular.com/mojo): a programming language for heterogeneous computing.
- oneAPI (https://www.intel.com/content/www/us/en/developer/tools/oneapi/overview.html): A
  software stack for high performance computing by Intel. Based on SYCL, but also adds custom
  extensions to implement new features.
- OpenACC (https://www.openacc.org/): A parallel computing standard
- OpenMP (https://www.openmp.org/): An API for parallel computations that uses directive-based
  programming instead of kernels. Can use CPUs and GPUs. This
  `presentation <https://www.openmp.org/wp-content/uploads/2021-10-20-Webinar-OpenMP-Offload-Programming-Introduction.pdf>`_
  gives an introduction to GPU programming with OpenMP.
- ROCm (https://www.amd.com/fr/products/software/rocm.html): A software stack for high performance
  computing by AMD. Supports OpenCL, HIP, OpenMP.
- Slang (https://www.khronos.org/news/press/khronos-group-launches-slang-initiative-hosting-open-source-compiler-contributed-by-nvidia):
  a shading language and compiler that can target multiple APIs.


Relevant Resources
------------------

Here are other interesting resources to learn GPU programming:

- Lexicon that compares the vocabulary used in different GPU programming frameworks:
  https://github.com/ROCm/HIP/blob/amd-staging/docs/reference/terms.md
- Step-by-step guide that explains how to optimize a GPU-accelerate program (CUDA):
  https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf
- Blog post that explains the history of GPU programming frameworks, focusing on graphics
  applications: https://web.archive.org/web/20250000000000*/https://cohost.org/mcc/post/1406157-i-want-to-talk-about-webgpu


Interesting Projects
--------------------

I found some really promising projects related to GPUs:

- ``rust-gpu`` (https://github.com/Rust-GPU/rust-gpu) enables seamless integration of GPU code into
  Rust code. It's a little like SYCL but for RUST, but in contrast to SYCL, rust-gpu supports both
  general-purpose and graphics applications. The project is not ready for production yet.
- ``burn`` (https://github.com/tracel-ai/burn) is a deep learning framework that uses WebGPU as its
  backend for increased portability. It also uses SPIR-V to perform some optimizations that WebGPU
  does not support.


Improvements
------------

The following points can be implemented to improve the repository:

- Implement an example that uses Metal.
- Make the SYCL example functional.


Benchmarking
------------

Run the Python script ``benchmark.py`` to compare how performances vary depending on the number of
threads running on CPU:

.. code:: bash

   # Linux
   python3 benchmark.py

   # OS that begins with the letter W
   py benchmark.py


Visite guidée de cadres logiciels pour processeurs graphiques
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Ce dépôt contient des projets sans dépendances qui montrent comment installer un cadre logiciel de
programmation de GPU, comment construire des programmes accélérés par GPU, et comment les exécuter.
Cliquez sur les liens dans le tableau ci-dessous pour accéder à des informations supplémentaires
sur chaque projet.

.. note::

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
|                                          |          |                 |     |       |       |     |               | sur Mac)      |SPIR-V            |
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
|`CPU <cpu/readme.md>`__                   | N        | O               | O   | N     | N     | N   | N             | Tous          | N/A              |
+------------------------------------------+----------+-----------------+-----+-------+-------+-----+---------------+---------------+------------------+

- Le signe ``*`` indique que l'exemple correspondant n'est pas inclus dans le projet.


Autres cadriciels
-----------------

Encore d'autres cadriciels sont disponibles pour programmer des GPU! La liste ci-dessous en présente
quelques-uns. Aucun exemple n'est implémenté pour eux dans ce dépôt, mais vous pouvez suivre les
liens pour en apprendre davantage.

- AcceleratedKernels.jl (https://juliagpu.github.io/AcceleratedKernels.jl/stable/): Un projet basé
  sur Julia qui accélère les calculs parallèles avec des CPU et GPU. Utilise plusieurs supports
  dorsaux (oneAPI, ROCm, Metal, CUDA) pour améliorer la portabilité.
- Bend (https://github.com/HigherOrderCO/Bend): un langage de programmation pour le calcul
  parallèle.
- Chapel (https://chapel-lang.org/gpu/): un autre langage de programmation pour le calcul
  parallèle.
- Mojo (https://www.modular.com/mojo): un langage pour calcul hétérogène.
- oneAPI (https://www.intel.com/content/www/us/en/developer/tools/oneapi/overview.html): Une pile
  logicielle pour le calcul haute performance par Intel. Basé sur SYCL, mais utilise aussi des
  extensions spécifiques au projet pour implémenter de nouvelles fonctionnalités.
- OpenACC (https://www.openacc.org/): un standard de calcul parallèle.
- OpenMP (https://www.openmp.org/): Une API pour calculs parallèles qui utilise la programmation
  basée sur les directives au lieu de noyaux. Peut utiliser des CPU et GPU. La
  `présentation <https://www.openmp.org/wp-content/uploads/2021-10-20-Webinar-OpenMP-Offload-Programming-Introduction.pdf>`_
  donne une introduction au calcul sur GPU avec OpenMP.
- ROCm (https://www.amd.com/fr/products/software/rocm.html): Une pile logicielle pour calcule de
  haute performance par AMD. Supporte OpenCL, HIP, OpenMP.
- Slang (https://www.khronos.org/news/press/khronos-group-launches-slang-initiative-hosting-open-source-compiler-contributed-by-nvidia):
  un compilateur et langage de nuanceur qui cible plusieurs API.


Ressources additionnelles
-------------------------

- Lexique qui compare le vocabulaire utilisé par différents outils de programmation de GPU :
  https://github.com/ROCm/HIP/blob/amd-staging/docs/reference/terms.md
- Guide d'optimisation de programme pour GPU (CUDA)
  https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf
- Publication expliquant l'histoire des outils de programmation graphique de GPU :
  https://web.archive.org/web/20250000000000*/https://cohost.org/mcc/post/1406157-i-want-to-talk-about-webgpu


Projets d'intérêt
-----------------

Projets récents en lien avec les GPU :

- ``rust-gpu`` (https://github.com/Rust-GPU/rust-gpu) permet d'intégrer des instructions destinées
  aux GPU dans du code Rust régulier, un peu comme SYCL le permet en C++. Mais rust-gpu supporte,
  en plus, les applications graphiques. Le projet n,est pas encore prêt pour la production.
- ``burn`` (https://github.com/tracel-ai/burn) est un cadriciel d'apprentissage profond qui utilise
  WebGPU pour un portabilité accrue. Il utilise aussi SPIR-V pour appliquer des optimisations non
  supportées par WebGPU.


Améliorations
-------------

Ce dépôt peut être amélioré par les points suivants:

- Ajouter un exemple qui utilise Metal.
- Faire fonctionner l'exemple avec SYCL.


Comparaisons
-------------

Exécutez le script ``benchmark.py`` pour comparer les performances d'un programme utilisant
plusieurs fils d'exécution sur CPU:

.. code:: bash

   # Linux
   python3 benchmark.py

   # OS that begins with the letter W
   py benchmark.py
