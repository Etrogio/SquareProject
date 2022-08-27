#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "MyAdvMath.h"
#include "UniversUseful.h"
#include "SquareSolver.h"

enum NUMOFROOTS LinearSolver(double a, double b, double* x)
{
    if (DoubleEqual(a, 0.0))
    {
        return (DoubleEqual(b, 0.0)) ? INFINITYROOTS : ZERO;
    }
    else   // a != 0
    {
        *x = (DoubleEqual(b, 0.0)) ? 0 : -b / a;
        return ONE;
    }
}

void ScanCoeff(double* a, double* b, double* c)
{
    int NumofScan = 0;

    do
    {
        printf("Enter coefficients: ");
        NumofScan = scanf("%lg %lg %lg", a, b, c);
        ClearBuf();
    } while (!(isfinite(*a) && isfinite(*b) &&
               isfinite(*c)) || (NumofScan != 3));
}

void OutSolv(enum NUMOFROOTS a, double* x1, double* x2)
{
    switch (a)
    {
        case ZERO:
            printf("There aren't any roots.\n");
            break;
        case ONE:
            printf("The single root is %lg.\n", *x1);
            break;
        case TWO:
            printf("There are two roots: %lg and %lg.\n", *x1, *x2);
            break;
        case INFINITYROOTS:
            printf("The root is any number.\n");
            break;
        default:
            printf("Error");
            abort();
            break;
    }
}

enum NUMOFROOTS IsCoeffZero(double a, double b, double c, double* x1, double* x2)
{
    if (DoubleEqual(a, 0.0))
    {
        return LinearSolver(b, c, x1);
    }

    if (DoubleEqual(b, 0.0))
    {
        if (DoubleEqual(c, 0.0))
        {
            *x1 = 0;
            return ONE;
        }
        else  //a != 0  b == 0  c != 0
        {
            if ((-c/a)>0)
            {
                *x1 = -sqrt(-c/a);
                *x2 = -*x1;
                return TWO;
            }
            else return ZERO;
        }
    }

    if (DoubleEqual(c, 0.0))
        {
            *x2 = MAXDouble(-b/a, 0.0);
            *x1 = MINDouble(-b/a, 0.0);
            return TWO;
        }
}


enum NUMOFROOTS SquareSolver(double a, double b, double c, double* x1, double* x2)
{
    if ((a == 0) || (b == 0) || (c == 0))
    {
        return IsCoeffZero(a, b, c, x1, x2);
    }
    else
    {
        double d = b*b - 4*a*c;
        if (d<0)
        {
            return ZERO;
        }
        else if (d>0)
        {
            double sqrt_d = sqrt(d);
            *x1 = (-b-sqrt_d) / (2*a);
            *x2 = (-b+sqrt_d) / (2*a);
            return TWO;
        }
        else
        {
            *x1 = -b / (2*a);
            return ONE;
        }
    }
};

void FullSquareEquationSolver(void)
{
    double a  = NAN,
           b  = NAN,
           c  = NAN,
           x1 = NAN,
           x2 = NAN;
    enum NUMOFROOTS NumofSolv = ZERO;

    ScanCoeff(&a, &b, &c);
    NumofSolv = SquareSolver(a, b, c, &x1, &x2);
    OutSolv(NumofSolv, &x1, &x2);
}
