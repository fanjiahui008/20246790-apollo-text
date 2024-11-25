# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(SurroundedRegions)

set(CMAKE_CXX_STANDARD 14)

# 设置输出的可执行文件名
add_executable(SurroundedRegions src/solution.cpp src/main.cpp)

# 包含头文件目录
include_directories(include)