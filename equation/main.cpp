
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "SolveQuadraticEquationFunctions.h"
#include "UnitTest.h"

int main ()
{
    printf (" # Enter  3 coefficients \"a b c\" of the quadratic equation (ax^2+bx+c=0)\n\n   ");

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    int coefficientsNumber = scanf (" %lf %lf %lf", &a, &b, &c);
    printf (" \n");

    if (coefficientsNumber != 3)
    {
        printf (" # ERROR\n");
        printf (" # Scanf returned invalid value of inputed coefficients :\n\n   %d\n", coefficientsNumber);
        exit(EXIT_FAILURE);
    }

    assert (!isnan (a));
    assert (!isnan (b));
    assert (!isnan (c));

    complexNumber rootOne    = {0.0, 0.0};
    complexNumber rootTwo    = {0.0, 0.0};

    int numberOfRoots = solveQuadraticEquation(a, b, c, &rootOne, &rootTwo);

    switch (numberOfRoots)
    {
        case 2 :
            printf (" # There are two roots of the quadratic equation :\n\n"
                    "   %lf and %lf\n", rootOne.realPart, rootTwo.realPart);
            break;

        case 1 :
            printf (" # There is one root of the quadratic equation :\n\n"
                    "   %lf\n", rootOne.realPart);
            break;

        case 0 :
            printf (" # There are two complex roots of the quadratic equation\n\n");
            rootComplex(a, b, c, &rootOne, &rootTwo);
            printf ("%f +%fi and %f %fi",
                    rootOne.realPart, rootOne.complexPart, rootTwo.realPart, rootTwo.complexPart);
            break;

        case INFINITE :
            printf (" # There are infinite roots of the quadratic equation\n\n");
            break;

        default :
            printf (" # ERROR\n");
            printf (" # solveQuadraticEquation returned invalid value"
                    " of roots :\n\n   %d\n", numberOfRoots);
            break;
    }
    printf("\n");
    UT_solveQuadraticEquation();
    return 0;
}