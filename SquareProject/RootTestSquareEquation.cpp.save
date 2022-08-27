#include <stdio.h>
#include <math.h>
#include "MyAdvMath.h"
#include "SquareSolver.h"
#include "RootTestSquareEquation.h"

void RootTestSuccess(void)
{
    printf("Success!\n");
}

void RootTestError(enum NUMOFROOTS  NumofSolv, double      x1, double      x2,
               enum NUMOFROOTS Corr_NumofSolv, double Corr_x1, double Corr_x2)
{
    printf("Failed!\n\
        NumofSolv = %d, x1 = %lg, x2 = %lg.\n\
        Expected: NumofSolv = %d, x1 = %lg, x2 = %lg.\n",
            NumofSolv, x1, x2, Corr_NumofSolv, Corr_x1, Corr_x2);
}

void OneRootTest(double a, double b, double c,
          enum NUMOFROOTS Corr_NumofSolv, double Corr_x1, double Corr_x2)
{
    double x1 = 0, x2 = 0;
    enum NUMOFROOTS NumofSolv = SquareSolver(a, b, c, &x1, &x2);

    if ((NumofSolv == INFINITYROOTS) &&
        (NumofSolv == Corr_NumofSolv))
    {
        RootTestSuccess();
        return;
    }
    if (NumofSolv == INFINITYROOTS)
    {
        RootTestError(     NumofSolv,      x1,      x2,
                  Corr_NumofSolv, Corr_x1, Corr_x2);
        return;
    }

    if ((NumofSolv == ZERO) &&
        (NumofSolv == Corr_NumofSolv))
    {
        RootTestSuccess();
        return;
    }
    if (NumofSolv == ZERO)
    {
        RootTestError(     NumofSolv,      x1,      x2,
                  Corr_NumofSolv, Corr_x1, Corr_x2);
        return;
    }

    if (NumofSolv == ONE)
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

    if (NumofSolv == TWO)
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

void RootTest(void)
{
    enum NUMOFROOTS Corr_NumofSolv = ZERO;
    double a = NAN, b = NAN, c = NAN;
    double Corr_x1 = NAN, Corr_x2 = NAN;
    int count = 1;
    int NumofFscan = 0;

    FILE *Testfile;
    Testfile = fopen("RootTest.txt", "r");

    while (1)
    {

        NumofFscan = fscanf(Testfile, "%lg %lg %lg %d %lg %lg",
              &a, &b, &c, &Corr_NumofSolv, &Corr_x1, &Corr_x2);
        if (NumofFscan != 6)
        {
            if (CheckFileLine(Testfile)) break;
        }
        else
        {
            printf("Test ¹%d: ", count);
            count = count + 1;
            OneRootTest(a, b, c, Corr_NumofSolv, Corr_x1, Corr_x2);
        }
    }

    fclose(Testfile);
}
