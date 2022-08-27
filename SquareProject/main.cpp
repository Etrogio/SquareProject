/*!
    \file
    \brief   This program solves square equation of the form
             a*x^2 + b*x + c = 0.
    \author  Etrogio
    \version 1.0
    \date    August 2022

    The program requests coefficients of equation
    with a check for the correctness of the input.
    Then it calculates and displays the roots and their number.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MyAdvMath.h"
#include "UniversUseful.h"
#include "SquareSolver.h"
//This header includes all above files for solving square equation
#include "RootTestSquareEquation.h" //Test with comparing roots
#include "TXLib.h"

int main(void)
{
    RootTest();

    return 0;
}
