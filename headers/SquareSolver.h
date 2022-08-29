#ifndef SQUARESOLVER_H_INCLUDED
#define SQUARESOLVER_H_INCLUDED

#include <assert.h>
#include "AdvMath.h"

enum NumofRoots
{
    Infinity_Roots = -1,
    Zero_Roots = 0,
    One_Root = 1,
    Two_Roots = 2
};

/*!
    This function checks whether any of coefficients is zero and
    if it is, calculates roots through simplified formulas.
*/
enum NumofRoots isCoeffZero(double a, double b, double c, double *x1, double *x2);

/*!
    Function LinearSolver returns the number of the roots
    of the linear equation of the form a*x + b = 0 and
    records the value if there is only one root.

    \param[in]  a, b The coefficients of the linear equation.
    \param[out]    x The root of the linear equation.
    \return          The number of roots.
*/
enum NumofRoots linearSolver(double a, double b, double *x);

/*!
    Function SquareSolver returns the number of the roots from the obtained values
    of the coefficients of the square equation and records their values
    if there are two or one root.

    \param[in]   a, b, c The coefficients of square equation.
    \param[out]   x1, x2 The roots of square equation.
    \return              The number of roots.
*/
enum NumofRoots squareSolver(double a, double b, double c, double *x1, double *x2);

/*!
    Function ScanCoeff accepts coefficients, clears the buffer and
    checks the input for correctness.

    \param[out] a, b, c The coefficients of the square equation.
*/
void scanCoeff(double *a, double *b, double *c);

/*!
    Function OutSolv displays the number of roots
    and their values if they exist.

    \param[in]      a The number of roots of the square equation.
    \param[in] x1, x2 The roots of square equation if they exist.
*/
void outSolv(enum NumofRoots a, double x1, double x2);

/*!
    This function gets coefficients, solves the equation and
    outputs the answer.
*/
void fullSquareEquationSolver(void);

#endif // SQUARESOLVER_H_INCLUDED
