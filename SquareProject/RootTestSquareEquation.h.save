#ifndef ROOTTESTSQUAREEQUATION_H_INCLUDED
#define ROOTTESTSQUAREEQUATION_H_INCLUDED

/*!
    This function prints "Success!"
*/
void RootTestSuccess(void);

/*!
    This function displays error, correct answer
    and roots from SquareSolver.
*/
void RootTestError(enum NUMOFROOTS      NumofSolv, double      x1, double      x2,
                   enum NUMOFROOTS Corr_NumofSolv, double Corr_x1, double Corr_x2);

/*!
    This function tests the SquareSolver comparing correct roots
    and solve from SquareSolver
*/
void OneRootTest(double a, double b, double c,
          enum NUMOFROOTS Corr_NumofSolv, double Corr_x1, double Corr_x2);

/*!
    This function checks the line of file whether it is correct
    and skips this line if not.
*/
int CheckFileLine(FILE* Testfile);

/*!
    Full test.
    This function reads test file and tests the SquareSolver;
*/
void RootTest(void);

#endif // ROOTTESTSQUAREEQUATION_H_INCLUDED
