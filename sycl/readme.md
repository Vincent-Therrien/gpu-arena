# SYCL

SYCL lets you write hardware-accelerated instructions into regular C++ code instead of manually
delegating these computations to kernels. Intel seems to be the only major player supporting it.

This project does not work. I obtain the error described at
https://github.com/intel/llvm/issues/15910. In theory it could compile if I reinstalled the compiler
toolchain `¯\_(ツ)_/¯`


## Build

I completed the following steps to build the example, but it does not work yet.

Visit the page https://www.intel.com/content/www/us/en/developer/tools/oneapi/base-toolkit-download.html
to download oneAPI and execute the following commands:

On Linux, run the following commands:

```
source /opt/intel/oneapi/setvars.sh
icpx main.cpp -o main.exe
```

On Windows, run the following commands:

```
"C:\Program Files (x86)\Intel\oneAPI\setvars.bat"
icx -fsycl main.cpp -o main.exe
```

I get the following error message:

```
>icx -fsycl main.cpp -o main.exe
Intel(R) oneAPI DPC++/C++ Compiler for applications running on Intel(R) 64, Version 2024.2.0 Build 20240602
Copyright (C) 1985-2024 Intel Corporation. All rights reserved.

In file included from gpu-arena\sycl\main.cpp:3:
In file included from C:\Program Files (x86)\Intel\oneAPI\compiler\2024.2\include\sycl\CL\sycl.hpp:11:
In file included from C:\Program Files (x86)\Intel\oneAPI\compiler\2024.2\include\sycl\sycl.hpp:25:
In file included from C:\Program Files (x86)\Intel\oneAPI\compiler\2024.2\include\sycl\accessor.hpp:11:
In file included from C:\Program Files (x86)\Intel\oneAPI\compiler\2024.2\include\sycl\access\access.hpp:14:
In file included from C:\Program Files (x86)\Intel\oneAPI\compiler\2024.2\include\sycl\CL\__spirv\spirv_ops.hpp:25:
In file included from C:\Program Files (x86)\Intel\oneAPI\compiler\2024.2\include\sycl\CL\__spirv\spirv_types.hpp:25:
C:\Program Files (x86)\Intel\oneAPI\compiler\2024.2\include\sycl\detail\defines.hpp(15,10): fatal error: 'climits' file not found
   15 | #include <climits>
      |          ^~~~~~~~~
1 error generated.
```
