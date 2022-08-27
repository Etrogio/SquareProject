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
#include "RootTestSquareEquation.h" //Test with comparing roots
#include "TXLib.h"

int main(void)
{
    int option = 0;

    printf("Hello, darkness, my old friend.\n"
           "This program can solve the square equation\n"
           "of type a*x^2 + b*x + c = 0.\n"
           "Also it can take tests, \n"
           "but this feature only for devops.\n"
           "That is, for me. :)\n"
           "P.S. meow\n");

    while (1)
    {
        printf("\nChoose the option:\n"
               "1) Solve square equation.\n"
               "2) Root test.\n"
               "0) Exit.\n");
        if (scanf("%d", &option) != 1)
        {
            ClearBuf();
        }
        else
        {
            switch(option)
            {
                case 1:
                    FullSquareEquationSolver();
                    break;
                case 2:
                    RootTest();
                    break;
                case 0:
                    return 0;
                default:
                    abort();
            }
        }
    }
    return 0;
}
