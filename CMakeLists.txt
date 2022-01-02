cmake_minimum_required(VERSION 3.20)
project(libtorch_test)

set(CMAKE_CXX_STANDARD 17)
include(FindCUDA/select_compute_arch)
CUDA_DETECT_INSTALLED_GPUS(INSTALLED_GPU_CCS_1)
string(STRIP "${INSTALLED_GPU_CCS_1}" INSTALLED_GPU_CCS_2)
string(REPLACE " " ";" INSTALLED_GPU_CCS_3 "${INSTALLED_GPU_CCS_2}")
string(REPLACE "." "" CUDA_ARCH_LIST "${INSTALLED_GPU_CCS_3}")
SET(CMAKE_CUDA_ARCHITECTURES ${CUDA_ARCH_LIST})

# set(Torch_DIR /root/Softwares/libtorch/share/cmake/Torch)
find_package(Torch REQUIRED)

add_executable(libtorch_test libtorch_test.cpp)
target_link_libraries(libtorch_test ${TORCH_LIBRARIES})

# set_property(TARGET libtorch_test PROPERTY CMAKE_CUDA_ARCHITECTURES all)