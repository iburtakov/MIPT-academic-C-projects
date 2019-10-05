#include "SolveQuadraticEquationFunctions.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

int rootComplex (double a, double b, double c, complexNumber* rootOne, complexNumber* rootTwo)
{
    assert(rootOne != nullptr);
    assert(rootTwo != nullptr);
    assert (!isnan (a));
    assert (!isnan (b));
    assert (!isnan (c));

    double discriminant = b * b - 4.0 * a * c;

    assert(!(discriminant >= 0));

    double sqrtDiscriminant = sqrt((-1) * discriminant);

    rootOne->realPart = -b / a / 2.0;
    rootOne->complexPart = sqrtDiscriminant / a / 2.0;

    rootTwo->realPart = -b / a / 2.0;
    rootTwo->complexPart = -sqrtDiscriminant / a / 2.0;

    return 0;
}

int solveQuadraticEquation (double a, double b, double c, complexNumber* rootOne, complexNumber* rootTwo)
{
    assert (rootOne != nullptr);
    assert (rootTwo != nullptr);
    assert (rootOne != rootTwo);
    assert (!isnan (a));
    assert (!isnan (b));
    assert (!isnan (c));

    if (a == 0.0)
    {
        /* bx+c=0 or bx=0 or c=0 or 0=0 */
        return solveLinearEquation (b, c, &rootOne->realPart);
    }

    if (b == 0.0)
    {
        if (c == 0.0)
        {
            /* ax^2=0 */
            rootOne->realPart = 0.0;
            return 1;
        }
        /* ax^2+c=0 */
        if (a * c < 0.0)
        {
            rootOne->realPart = sqrt (- c / a);
            rootTwo->realPart = - rootOne->realPart;
            return 2;
        }
        return 0;
    }

    if (c == 0.0)
    {
        /* ax^2+bx=0 */
        rootTwo->realPart = 0.0;
        return solveLinearEquation (a, b, &(rootOne->realPart)) + 1;
    }
    /* ax^2+bx+c=0 */
    double discriminant = b * b - 4.0 * a * c;

    if (isEqual (discriminant, 0.0))
    {
        rootOne->realPart = - b / a / 2.0;
        return 1;
    }
    if (discriminant > 0.0)
    {
        double sqrtDiscriminant = sqrt (discriminant);

        rootOne->realPart = (- b - sqrtDiscriminant) / a / 2.0;
        rootTwo->realPart = (- b + sqrtDiscriminant) / a / 2.0;

        return 2;
    }
    if (discriminant < 0)
    {
        return rootComplex(a, b, c, rootOne, rootTwo);
    }
}


int solveLinearEquation(double a, double b, double* rootLinear)
{
    assert (rootLinear != nullptr);
    assert (!isnan (a));
    assert (!isnan (b));

    if (isEqual (a, 0.0))
    {
        return INFINITE;
    }
    *rootLinear = - b / a;
    return 1;
}




int isEqual(double numberOne, double numberTwo)
{
    assert (!isnan (numberOne));
    assert (!isnan (numberTwo));

    return fabs (numberOne - numberTwo) < EPSILON;
}
