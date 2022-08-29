#include <math.h>
#include "../headers/AdvMath.h"

double maxDouble(double a, double b)
{
    return (a > b) ? a : b;
}

double minDouble(double a, double b)
{
    return (a < b) ? a : b;
}

bool equalDouble(double a, double b)
{
    return fabs(a - b) < MIN_DIF;
}
