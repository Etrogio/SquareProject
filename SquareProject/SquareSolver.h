#ifndef SQUARESOLVER_H_INCLUDED
#define SQUARESOLVER_H_INCLUDED

#include <stdlib.h>
#include "MyAdvMath.h"
#include "UniversUseful.h"
#include "SquareSolver.h"



/*!
    Function LinearSolver returns the number of the roots
    of the linear equation of the form a*x + b = 0 and
    records the value if there is only one root.

    \param[in]  a, b The coefficients of the linear equation.
    \param[out]    x The root of the linear equation.
    \return          The number of roots.
*/
int LinearSolver(double a, double b, double* x);

/*!
    Function SquareSolver returns the number of the roots from the obtained values
    of the coefficients of the square equation and records their values
    if there are two or one root.

    \param[in]   a, b, c The coefficients of square equation.
    \param[out]   x1, x2 The roots of square equation.
    \return              The number of roots.
*/
int SquareSolver(double a, double b, double c, double* x1, double* x2);

/*!
    Function ScanCoeff accepts coefficients, clears the buffer and
    checks the input for correctness.

    \param[out] a, b, c The coefficients of the square equation.
*/
void ScanCoeff(double* a, double* b, double* c);

/*!
    Function OutSolv displays the number of roots
    and their values if they exist.

    \param[in]      a The number of roots of the square equation.
    \param[in] x1, x2 The roots of square equation if they exist.
*/
void OutSolv(int a, double* x1, double* x2);

void FullSquareEquationSolver(void);

const int INFINITY_ROOTS = -1;

void ScanCoeff(double* a, double* b, double* c)
{
    int NumofScan = 0;

    do
    {
        printf("Enter coefficients: ");
        NumofScan = scanf("%lg %lg %lg", &*a, &*b, &*c);
        ClearBuf();
    } while (!(isfinite(*a) && isfinite(*b) &&
               isfinite(*c)) || (NumofScan != 3));
}

void OutSolv(int a, double* x1, double* x2)
{
    switch (a)
    {
        case 0:
            printf("There aren't any roots.\n");
            break;
        case 1:
            printf("The single root is %lg.\n", *x1);
            break;
        case 2:
            printf("There are two roots: %lg and %lg.\n", *x1, *x2);
            break;
        case INFINITY_ROOTS:
            printf("The root is any number.\n");
            break;
        default:
            printf("Error");
            abort();
            break;
    }
}

int LinearSolver(double a, double b, double* x)
{
    if (DoubleEqual(a, 0.0))
    {
        return (DoubleEqual(b, 0.0)) ? INFINITY_ROOTS : 0;
    }
    else   // a != 0
    {
        *x = (DoubleEqual(b, 0.0)) ? 0 : -b / a;
        return 1;
    }
}

int SquareSolver(double a, double b, double c, double* x1, double* x2)
{
    if (DoubleEqual(a, 0.0))
    {
        return LinearSolver(b, c, x1);
    }
    else  //a != 0
    {
        if (DoubleEqual(b, 0.0))
        {
            if (DoubleEqual(c, 0.0))
            {
                *x1 = 0;
                return 1;
            }
            else  //a != 0  b == 0  c != 0
            {
                if ((-c/a)>0)
                {
                    *x1 = -sqrt(-c/a);
                    *x2 = -*x1;
                    return 2;
                }
                else return 0;
            }
        }
        else       //a != 0  b != 0
        {
            if (DoubleEqual(c, 0.0))
            {
                *x2 = MAXDouble(-b/a, 0.0);
                *x1 = MINDouble(-b/a, 0.0);
                return 2;
            }
        }
    }
    double d = b*b - 4*a*c;
    if (d<0)
    {
        return 0;
    }
    else if (d>0)
    {
        double sqrt_d = sqrt(d);
        *x1 = (-b-sqrt_d) / (2*a);
        *x2 = (-b+sqrt_d) / (2*a);
        return 2;
    }
    else
    {
        *x1 = -b / (2*a);
        return 1;
    };
};

void FullSquareEquationSolver(void)
{
    double a  = NAN,
           b  = NAN,
           c  = NAN,
           x1 = NAN,
           x2 = NAN;
    int NumofSolv = 0;

    ScanCoeff(&a, &b, &c);
    NumofSolv = SquareSolver(a, b, c, &x1, &x2);
    OutSolv(NumofSolv, &x1, &x2);
}


#endif // SQUARESOLVER_H_INCLUDED
