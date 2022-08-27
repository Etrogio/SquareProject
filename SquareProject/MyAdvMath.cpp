#include <math.h>
//#include "MyAdvMath.h"

const double MINDIF = 1e-20;

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
