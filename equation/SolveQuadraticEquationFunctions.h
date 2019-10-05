//
// Created by Илья on 05.10.2019.
//

#ifndef EQUATION_MAIN_HEADER_H
#define EQUATION_MAIN_HEADER_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

struct complexNumber{
    double realPart;
    double complexPart;
};

const int INFINITE = 3;

const double EPSILON = 0.0000000001;


int solveQuadraticEquation (double a, double b, double c, complexNumber* rootOne, complexNumber* rootTwo);


int solveLinearEquation (double a, double b, double* rootLinear);


int isEqual (double numberOne, double numberTwo);


int rootComplex(double a, double b, double c, complexNumber* rootOne, complexNumber* rootTwo);

#endif //EQUATION_MAIN_HEADER_H
