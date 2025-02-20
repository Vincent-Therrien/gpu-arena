# SYCL

SYCL lets you write hardware-accelerated instructions into regular C++ code instead of manually
delegating these computations to kernels. Intel is the only major player supporting it.

I could not make the example work, oneAPI seems full of bugs.


## Install

Visit the page https://www.intel.com/content/www/us/en/developer/tools/oneapi/base-toolkit-download.html
to download oneAPI and execute the following commands:

Linux:

```
source /opt/intel/oneapi/setvars.sh
icpx main.cpp -o main.exe
```

Windows:

```
"C:\Program Files (x86)\Intel\oneAPI\setvars.bat"
icpx main.cpp -o main.exe
```
