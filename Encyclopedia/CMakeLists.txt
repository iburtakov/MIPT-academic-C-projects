cmake_minimum_required(VERSION 3.12)
project(Encyclopedia)

set(CMAKE_CXX_STANDARD 11)

add_executable(Encyclopedia main.cpp FileIO.cpp FileIO.h Sort.cpp UNITTESTS.h)