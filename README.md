# IreCore

IreCore is a World of Warcraft simulator for the purpose of boosting large-scale theorycrafting, for fury warriors, arms warriors, (experimental)retribution paladins and (really experimental)frost deathknights. IreCore is aimed at making the speedup as high as possible. 

IreCore is derived from the [LuaCL project](https://github.com/llxibo/LuaCL) as an initial practice. IreCore Kernel is being developed in OpenCL C for heterogeneous computing.

# How to Setup (for users)
IreCore adopts OpenCL API for computing, thus it could benefit from the most powerful hardwares which support OpenCL.

If your hardware is not listed in IreCore, you should install OpenCL Runtimes or Drivers from your hardware vendor.

If you are using Intel devices (CPU/Integrated GPU/Xeon Phi Coprocessor), get your drivers from [here](https://software.intel.com/en-us/articles/opencl-drivers).

Both NVIDIA GPU supports and AMD GPU supports are included in the corresponding graphic driver.

AMD CPU/APU supports are included in AMD Catalyst Driver. If you are using AMD GPU as well, the CPU/APU support should be already opened. If not, try install [AMD Catalyst Driver](http://support.amd.com/en-us/download) or [AMD APP SDK](http://developer.amd.com/tools-and-sdks/opencl-zone/amd-accelerated-parallel-processing-app-sdk/).

Running on GPU is not recommended currently, especially for users of Windows 7 or older operating system. If you are getting error "Display driver stopped responding and has recovered." or BSoD with bugcheck `0x00000116` `0x00000117` when running on GPU, use [TDR Manipulator](https://forums.geforce.com/default/topic/694754/geforce-drivers/tdr-manipulator-v1-1-02-23-2014-/) to temporarily disable TDR mechanism of Windows, then restart your computer. *It is NOT RECOMMENDED to disable TDR for a long term* since that may cause damage to your hardware.

# How to Build (for developers)
IreCore is built with [the Qt Toolkit](http://qt.io), but still have some dependencies on Windows platform.

To build IreCore, you should first have all of the listed toolkits installed:

* Visual Studio 2015 Community

* [Qt 5.7](http://www.qt.io/download-open-source/), the component `msvc2015 32-bit` `qtcreator` are required at minimum. If you want to have Chinese Simplified localization, `qtlinguist` is required.

* [Visual Studio Add-in 1.2.4 for Qt5](http://www.qt.io/download-open-source/#section-7)

* An OpenCL SDK from your device vendor, it could be one of the listed:

    * Not Recommended: [Intel INDE](https://software.intel.com/en-us/intel-inde)

    * Recommended: [NVIDIA CUDA Toolkit](https://developer.nvidia.com/cuda-downloads)

    * Recommended: [AMD APP SDK](http://developer.amd.com/tools-and-sdks/opencl-zone/amd-accelerated-parallel-processing-app-sdk/)

    * If you selected the Intel INDE, you may need manually configure lib & include directories in VS project.

Open the batch file `pack_release_x86.bat` with a text editor. Edit the directory in the second line to your Qt path. The Qt path should directly contain `bin` `lib` and `include` subfolders.

`set qt_dir=E:\Qt\5.7\msvc2015`

Open the VS solution `ic_2015.sln` and build the solution. A release package will be copied into a `release` folder.

If you have the Qt Linguist installed, you could first release the localization `gic_zh.ts`, `icc_zh.qm` for Chinese Simplified localization.