cmake_minimum_required(VERSION 3.22)
project(FourthTask)

set(CMAKE_CXX_STANDARD 14)

add_executable(FourthTask main.cpp exceptions/SysCallException.cpp exceptions/SysCallException.h)
