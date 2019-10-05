cmake_minimum_required(VERSION 3.12)
project(equation)

set(CMAKE_CXX_STANDARD 11)

add_executable(equation main.cpp SolveQuadraticEquationFunctions.h SolveQuadraticEquationFunctions.cpp UnitTest.cpp UnitTest.h)