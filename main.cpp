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
#include <assert.h>
#include "headers/AdvMath.h"
#include "headers/InOutPut.h"
#include "headers/SquareSolver.h"
#include "headers/RootTestSquareEquation.h" //Test with comparing roots
#include "TXLib.h"

int main(void)
{
    greetings();

    int option = 0;
    while (1)
    {
        chooseOption();

        if (scanf("%d", &option) != 1)
        {
            clearBuf();
        }
        else
        {
            switch(option)
            {
                case 1:
                    fullSquareEquationSolver();
                    break;

                case 2:
                    rootTest();
                    break;

                case 0:
                    return 0;

                default:
                    assert(0);
            }
        }
    }

    return 0;
}
