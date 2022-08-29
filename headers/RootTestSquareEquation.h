#ifndef ROOTTESTSQUAREEQUATION_H_INCLUDED
#define ROOTTESTSQUAREEQUATION_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "AdvMath.h"
#include "SquareSolver.h"

/*!
    This function prints "Success!"
*/
void rootTestSuccess(void);

/*!
    This function displays error, correct answer
    and roots from SquareSolver.
*/
void rootTestError(enum NumofRoots      num_of_solv, double      x1, double      x2,
                   enum NumofRoots corr_num_of_solv, double corr_x1, double corr_x2);

/*!
    This function tests the SquareSolver comparing correct roots
    and solve from SquareSolver
*/
void oneRootTest(double a, double b, double c,
          enum NumofRoots corr_num_of_solv, double corr_x1, double corr_x2);

/*!
    This function checks the line of file whether it is correct
    and skips this line if not.
*/
int checkFileLine(FILE *testfile);

/*!
    Full test.
    This function reads test file and tests the SquareSolver;
*/
void rootTest(void);

#endif // ROOTTESTSQUAREEQUATION_H_INCLUDED
