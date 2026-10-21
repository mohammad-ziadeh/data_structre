cmake_minimum_required(VERSION 4.3)
project(data_structre)

set(CMAKE_CXX_STANDARD 20)

add_executable(factorial recursion/factorial.cpp)
add_executable(fibonacci recursion/fibonacci.cpp)
add_executable(sum recursion/sum.cpp)
add_executable(vector_demo vector/vector.cpp)

