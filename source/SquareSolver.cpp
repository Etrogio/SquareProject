#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../headers/AdvMath.h"
#include "../headers/InOutPut.h"
#include "../headers/SquareSolver.h"

enum NumofRoots linearSolver(double a, double b, double *x)
{
    if (equalDouble(a, 0))
    {
        return (equalDouble(b, 0)) ? Infinity_Roots : Zero_Roots;
    }
    else
    {
        *x = (equalDouble(b, 0)) ? 0 : -b / a;
        return One_Root;
    }
}

void scanCoeff(double *a, double *b, double *c)
{
    int num_of_scan = 0;

    do
    {
        printf("Enter coefficients: ");
        num_of_scan = scanf("%lg %lg %lg", a, b, c);
        clearBuf();
    } while (num_of_scan != 3);
}

void outSolv(enum NumofRoots a, double x1, double x2)
{
    switch (a)
    {
        case Zero_Roots:
            printf("There aren't any roots.\n");
            break;
        case One_Root:
            printf("The single root is %lg.\n", x1);
            break;
        case Two_Roots:
            printf("There are two roots: %lg and %lg.\n", x1, x2);
            break;
        case Infinity_Roots:
            printf("The root is any number.\n");
            break;
        default:
            assert(0);
            break;
    }
}

enum NumofRoots isCoeffZero(double a, double b, double c, double *x1, double *x2)
{
    if (equalDouble(a, 0))
    {
        return linearSolver(b, c, x1);
    }

    if (equalDouble(b, 0))
    {
        if (equalDouble(c, 0))
        {
            *x1 = 0;
            return One_Root;
        }
        else  //a != 0  b == 0  c != 0
        {
            if ((-c / a) > 0)
            {
                *x1 = -sqrt(-c / a);
                *x2 = -*x1;

                return Two_Roots;
            }
            else return Zero_Roots;
        }
    }

    if (equalDouble(c, 0))
        {
            *x2 = maxDouble(-b / a, 0.0);
            *x1 = minDouble(-b / a, 0.0);

            return Two_Roots;
        }
}


enum NumofRoots squareSolver(double a, double b, double c, double *x1, double *x2)
{
    if ((a == 0) || (b == 0) || (c == 0))
    {
        return isCoeffZero(a, b, c, x1, x2);
    }
    else
    {
        double discriminant = b*b - 4*a*c;

        if (discriminant < 0)
        {
            return Zero_Roots;
        }
        else if (discriminant > 0)
        {
            double sqrt_discriminant = sqrt(discriminant);

            *x1 = (-b-sqrt_discriminant) / (2*a);
            *x2 = (-b+sqrt_discriminant) / (2*a);

            return Two_Roots;
        }
        else
        {
            *x1 = -b / (2*a);
            return One_Root;
        }
    }
};

void fullSquareEquationSolver(void)
{
    double a  = NAN;
    double b  = NAN;
    double c  = NAN;

    double x1 = NAN;
    double x2 = NAN;

    enum NumofRoots num_of_solv = Zero_Roots;

    scanCoeff(&a, &b, &c);
    num_of_solv = squareSolver(a, b, c, &x1, &x2);
    outSolv(num_of_solv, x1, x2);
}
