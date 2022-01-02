cmake_minimum_required(VERSION 3.16)
project(libtorch_test)

set(CMAKE_CXX_STANDARD 17)

find_package(Torch REQUIRED)

add_executable(libtorch_test libtorch_test.cpp)
target_link_libraries(libtorch_test ${TORCH_LIBRARIES})