#ifndef ROOTTESTSQUAREEQUATION_H_INCLUDED
#define ROOTTESTSQUAREEQUATION_H_INCLUDED

#include <stdio.h>
#include "SquareSolver.h"
#include "MyAdvMath.h"

/*!
    This function prints "Success!"
*/
void RootTestSuccess(void);
void RootTestSuccess(void)
{
    printf("Success!\n");
}

/*!
    This function displays error, correct answer
    and roots from SquareSolver
*/
void RootTestError(int      NumofSolv, double      x1, double      x2,
                   int Corr_NumofSolv, double Corr_x1, double Corr_x2);
void RootTestError(int  NumofSolv, double      x1, double      x2,
               int Corr_NumofSolv, double Corr_x1, double Corr_x2)
{
    printf("Failed!\n\
        NumofSolv = %d, x1 = %lg, x2 = %lg.\n\
        Expected: NumofSolv = %d, x1 = %lg, x2 = %lg.\n",
            NumofSolv, x1, x2, Corr_NumofSolv, Corr_x1, Corr_x2);
}

/*!
    This function tests the SquareSolver comparing correct roots
    and solve from SquareSolver
*/
void OneRootTest(double a, double b, double c,
          int Corr_NumofSolv, double Corr_x1, double Corr_x2);
void OneRootTest(double a, double b, double c,
          int Corr_NumofSolv, double Corr_x1, double Corr_x2)
{
    double x1 = 0, x2 = 0;
    int NumofSolv = SquareSolver(a, b, c, &x1, &x2);

    if ((NumofSolv == INFINITY_ROOTS) &&
        (NumofSolv == Corr_NumofSolv))
    {
        RootTestSuccess();
        return;
    }
    else if (NumofSolv == INFINITY_ROOTS)
    {
        RootTestError(     NumofSolv,      x1,      x2,
                  Corr_NumofSolv, Corr_x1, Corr_x2);
        return;
    }

    if ((NumofSolv == 0) &&
        (NumofSolv == Corr_NumofSolv))
    {
        RootTestSuccess();
        return;
    }
    else if (NumofSolv == 0)
    {
        RootTestError(     NumofSolv,      x1,      x2,
                  Corr_NumofSolv, Corr_x1, Corr_x2);
        return;
    }

    if (NumofSolv == 1)
    {
        if ((DoubleEqual(x1, Corr_x1)) &&
           (NumofSolv == Corr_NumofSolv))
        {
            RootTestSuccess();
            return;
        }
        else
        {
            RootTestError(     NumofSolv,      x1,      x2,
                      Corr_NumofSolv, Corr_x1, Corr_x2);
            return;
        }
    }

    if (NumofSolv == 2)
    {
        if ((NumofSolv == Corr_NumofSolv) &&
            (DoubleEqual(x1, Corr_x1)) &&
            (DoubleEqual(x2, Corr_x2)))
        {
            RootTestSuccess();
            return;
        }
        else
        {
            RootTestError(     NumofSolv,      x1,      x2,
                      Corr_NumofSolv, Corr_x1, Corr_x2);
            return;
        }
    }
}

int CheckFileLine(FILE* Testfile);
int CheckFileLine(FILE* Testfile)
{
    char ch = 'a';
    while (ch != '\n')
    {
        fscanf(Testfile, "%c", &ch);
        return feof(Testfile);
    }
    return 0;
}


void RootTest(void);
void RootTest(void)
{
    int Corr_NumofSolv = 0;
    double a = NAN, b = NAN, c = NAN;
    double Corr_x1 = NAN, Corr_x2 = NAN;
    int count = 1;
    int NumofFscan = 0;

    FILE *Testfile;
    Testfile = fopen("RootTest.txt", "r");

    while (1)
    {
        start:

        NumofFscan = fscanf(Testfile, "%lg %lg %lg %d %lg %lg",
              &a, &b, &c, &Corr_NumofSolv, &Corr_x1, &Corr_x2);
        if (NumofFscan != 6)
        {
            if (CheckFileLine(Testfile)) break;
            else goto start;
        }

        printf("Test �%d:", count);
        count = count + 1;
        OneRootTest(a, b, c, Corr_NumofSolv, Corr_x1, Corr_x2);
    }

    fclose(Testfile);
}


#endif // ROOTTESTSQUAREEQUATION_H_INCLUDED
