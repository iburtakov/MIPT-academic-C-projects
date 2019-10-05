//
// Created by Илья on 05.10.2019.
//
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "SolveQuadraticEquationFunctions.h"

void UT_solveQuadraticEquation(void)
{
    bool checker[5] = {1, 1, 1, 1, 1}; //if OK => true

    //#1 Two complex roots
    //#2 One real root
    //#3 Two real roots
    //#4 INFINITE roots

    complexNumber rootOne = {0.0, 0.0};
    complexNumber rootTwo = {0.0, 0.0};
    int numberOfRoots;

    double enterCheckCoefficients[4][3] = {{1.0, 2.0, 3.0},
                                           {1, 2, 1},
                                           {1, 1, -2},
                                           {0, 0, 0}};

    double answerCheckRoots[4][4] = {{-1.0, sqrt(2), -1.0, -sqrt(2)},
                                     {-1.0, 0.0,     0.0,  0.0},
                                     {-2.0,  0.0,     1.0, 0.0},
                                     {0.0,  0.0,     0.0,  0.0}};

    int answerCheckNumberOfRoots[4] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++)
    {
            rootOne = {0.0, 0.0};
            rootTwo = {0.0, 0.0};

            numberOfRoots = solveQuadraticEquation
                    (enterCheckCoefficients[i][0],
                    enterCheckCoefficients[i][1],
                    enterCheckCoefficients[i][2], &rootOne, &rootTwo);


            if (!(numberOfRoots == answerCheckNumberOfRoots[i] &&
                    isEqual(rootOne.realPart, answerCheckRoots[i][0]) && isEqual(rootOne.complexPart, answerCheckRoots[i][1])
                    &&
                    isEqual(rootTwo.realPart, answerCheckRoots[i][2]) && isEqual(rootTwo.complexPart, answerCheckRoots[i][3])))
            {
                checker[i] = 0;
            }
    }

    for (int i = 0; i < 4; i++)
    {
        if (checker[i] == 0)
        {
            printf("ERROR occured in part #%d\n", i);
        }
    }
}