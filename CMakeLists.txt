# cmake_minimum_required(VERSION <specify CMake version here>)
project(workspace)

set(CMAKE_CXX_STANDARD 14)

add_executable(workspace
        Test.cpp memory.cpp)
