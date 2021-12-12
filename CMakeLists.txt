cmake_minimum_required(VERSION 3.20)
project(Algorithm)

set(CMAKE_CXX_STANDARD 23)

add_executable(Algorithm Sort.cpp
               BigNumberCalculator/BigNumber.cpp BigNumberCalculator/BigNumber.h)
