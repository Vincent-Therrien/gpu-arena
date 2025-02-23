# Vulkan

Vulkan is an API designed for computer graphics, but it also supports general-purpose computing
through compute shaders. Vulkan uses SPIR-V as its shading language, which is not intended to be
human-readable. You can write the shaders in a human readable language, like GLSL and HLSL, and
compile it to SPIR-V before feeding it to Vulkan. This project uses GLSL and the compiler
`glslangValidator`.

Note: The Website https://vulkan-tutorial.com/ is a **much** better resource to learn Vulkan! This
current repository aims at providing simple comparisons between GPU programming APIs, so it only
provides simple examples.


## Graphics Example

The directory `graphics` is a self-contained C++ project that uses Vulkan and additional libraries
to open a window and display simple graphics. This project is based on the file
https://github.com/Overv/VulkanTutorial/blob/main/code/15_hello_triangle.cpp from the repository
`VulkanTutorial`, available at https://github.com/Overv/VulkanTutorial/tree/main and licensed under
the licenses CC0-1.0 and CC-BY-SA-4.0.

The following instructions show how to build and run it. This only works on Linux! Use WSL if
necessary!

```
cd graphics
sudo apt install vulkan-tools
sudo apt install libvulkan-dev
sudo apt install vulkan-validationlayers-dev spirv-tools
sudo apt install libglm-dev
mkdir build
cd build
cmake ..
cmake --build .
glslangValidator -V ../shader.vert -o vertices.spv
glslangValidator -V ../shader.frag -o fragment.spv
./graphics
```


## Computing Example

Vulkan *can* be used for general-purpose computing, but I've found it really impractical. The file
https://github.com/SaschaWillems/Vulkan/blob/master/examples/computeheadless/computeheadless.cpp is
a minimal example that shows how to use Vulkan for computations. It's more than 600 lines long!

Vulkan has never been intended to be beginner-friendly; it's made for high performances and aimed
at motivated users. Fortunately, the project Kompute (https://kompute.cc/), which is built atop
Vulkan, lets you easily create and run compute shaders. It can be used with a C++ or Python
interface; this repository uses Python (I just updated the example from the page
https://kompute.cc/).

To try Kompute, run the following commands on Linux or WSL:

```
cd compute
sudo apt install spirv-tools  # Install glslangValidator
pip install kp  # Install kompute, use a virtual environment ideally.
python3 compute.py
```
