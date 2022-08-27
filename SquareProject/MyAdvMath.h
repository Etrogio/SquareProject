#ifndef MYADVMATH_H_INCLUDED
#define MYADVMATH_H_INCLUDED

#include <math.h>

const double MINDIF = 1e-20;

/*!
    Function MAXDouble returns the largest of two double numbers.

    \param[in] a, b The two double numbers.
    \return         The largest number.
*/
double MAXDouble(double a, double b);

/*!
    Function MINDouble returns the smallest of two double numbers.

    \param[in] a, b Two double numbers.
    \return         The smallest number.
*/
double MINDouble(double a, double b);

/*!
    Function DoubleEqual checks
    whether two double numbers are equal.

    \param[in] a, b Two double numbers.
    \return         True if equal and false if not equal.
*/
bool DoubleEqual(double a, double b);

double MAXDouble(double a, double b)
{
    return (a > b) ? a : b;
}

double MINDouble(double a, double b)
{
    return (a < b) ? a : b;
}

bool DoubleEqual(double a, double b)
{
    return fabs(a - b) < MINDIF;
}


#endif // MYADVMATH_H_INCLUDED
