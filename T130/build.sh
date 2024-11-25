#!/bin/bash

# 清理之前的构建
rm -rf build
mkdir build
cd build

# 运行 cmake 进行配置
cmake ..

# 使用 make 编译项目
make

# 运行生成的可执行文件
./SurroundedRegions