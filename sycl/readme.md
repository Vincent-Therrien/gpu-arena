# SYCL

SYCL lets you write hardware-accelerated instructions into regular C++ code instead of manually
delegating these computations to kernels. Intel seems to be the only major player supporting it.

I gave up trying to make the example work!


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
icpx main.cpp -o main.exe
```
