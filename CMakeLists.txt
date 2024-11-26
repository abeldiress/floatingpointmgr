cmake_minimum_required(VERSION 3.10)
project(FloatingPointManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_subdirectory(tests)
add_subdirectory(benchmarks)

add_executable(FloatingPointManager main.cpp src/FloatingPointManager.cpp)
