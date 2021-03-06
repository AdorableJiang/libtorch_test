# LibTorch_test

This program is designed for verification of your LibTorch deployment. It is highly recommended using it on a [CUDA-capable](https://developer.nvidia.com/cuda-zone) system.

After you have installed LibTorch by either

* [building from source](https://github.com/pytorch/pytorch/blob/master/docs/libtorch.rst#libtorch-c-only),

or

* following the instruction of [INSTALLING C++ DISTRIBUTIONS OF PYTORCH](https://pytorch.org/cppdocs/installing.html) to download a LibTorch ZIP archive,

you can use this program to verify your LibTorch installation.

Clone this repo and

    cd <root-of-LibTorch_test>
    mkdir -p build && cd build

<details open>
  <summary>If you build LibTorch from source, <code>cmake</code> will take care of the rest.</summary>

    cmake ..
</details>

<details open>
  <summary>Or, if you use LibTorch ZIP archive, please specify the absolute (!) path to the unzipped LibTorch distribution.</summary>

    cmake -DCMAKE_PREFIX_PATH=/absolute/path/to/libtorch/share/cmake ..
</details>

Then `make`

    make -j$(nproc)

Now you can run it

    ./libtorch_test

If everything goes well, you should see output like

    LibTorch version: 1.11.0

    The following tensor is generated by cpu
    0.3639  0.0979  0.2400
    0.7631  0.3640  0.7143
    [ CPUFloatType{2,3} ]

    CUDA availability:True
    cuDNN availability:True
    This system has 2 CUDA-capable device(s).

    The following tensor is generated by device cuda:0
    0.6949  0.1144  0.9676
    0.3724  0.5811  0.0785
    [ CUDAFloatType{2,3} ]

    The following tensor is generated by device cuda:1
    0.0096  0.5464  0.3223
    0.0522  0.9954  0.8502
    [ CUDAFloatType{2,3} ]

<!-- For CPU-only devices

    LibTorch version: 1.10.1

    The following tensor is generated by cpu
    0.3269  0.0381  0.6621
    0.7958  0.5940  0.5143
    [ CPUFloatType{2,3} ]

    CUDA availability:False
    This is a CPU-only device. -->
