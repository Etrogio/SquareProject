#include <stdio.h>
#include <math.h>
//#include <unistd.h>
#include <io.h>
#include "../headers/AdvMath.h"
#include "../headers/SquareSolver.h"
#include "../headers/RootTestSquareEquation.h"

const char *PATH_TO_TEST = "C:/CodeBlocksPrograms/SquareProject/RootTest.txt";

void rootTestSuccess(void)
{
    printf("Success!\n");
}

void rootTestError(enum NumofRoots      num_of_solv, double      x1, double      x2,
                   enum NumofRoots corr_num_of_solv, double corr_x1, double corr_x2)
{
    printf("Failed!\n"
           "NumofSolv = %d, x1 = %lg, x2 = %lg.\n"
           "Expected: NumofSolv = %d, x1 = %lg, x2 = %lg.\n",
           num_of_solv, x1, x2, corr_num_of_solv, corr_x1, corr_x2);
}

void oneRootTest(double a, double b, double c,
          enum NumofRoots corr_num_of_solv, double corr_x1, double corr_x2)
{
    double x1 = 0, x2 = 0;
    enum NumofRoots num_of_solv = squareSolver(a, b, c, &x1, &x2);

    if ((num_of_solv == Infinity_Roots) &&
        (num_of_solv == corr_num_of_solv))
    {
        rootTestSuccess();
        return;
    }
    if (num_of_solv == Infinity_Roots)
    {
        rootTestError(     num_of_solv,      x1,      x2,
                      corr_num_of_solv, corr_x1, corr_x2);
        return;
    }

    if ((num_of_solv == Zero_Roots) &&
        (num_of_solv == corr_num_of_solv))
    {
        rootTestSuccess();
        return;
    }
    if (num_of_solv == Zero_Roots)
    {
        rootTestError(     num_of_solv,      x1,      x2,
                      corr_num_of_solv, corr_x1, corr_x2);
        return;
    }

    if (num_of_solv == One_Root)
    {
        if ((equalDouble(x1, corr_x1)) &&
            (num_of_solv == corr_num_of_solv))
        {
            rootTestSuccess();
            return;
        }
        else
        {
            rootTestError(     num_of_solv,      x1,      x2,
                          corr_num_of_solv, corr_x1, corr_x2);
            return;
        }
    }

    if (num_of_solv == Two_Roots)
    {
        if ((num_of_solv == corr_num_of_solv) &&
            (equalDouble(x1, corr_x1))    &&
            (equalDouble(x2, corr_x2)))
        {
            rootTestSuccess();
            return;
        }
        else
        {
            rootTestError(     num_of_solv,      x1,      x2,
                          corr_num_of_solv, corr_x1, corr_x2);
            return;
        }
    }
}

int checkFileLine(FILE *testfile)
{
    char ch = 'a';

    while (ch != '\n')
    {
        fscanf(testfile, "%c", &ch);
        if (feof(testfile)) return 0;
    }

    return 0;
}

void rootTest(void)
{
    int temp_corr_num_of_solv = 0;
    enum NumofRoots corr_num_of_solv = Zero_Roots;

    double a = NAN;
    double b = NAN;
    double c = NAN;

    double corr_x1 = NAN;
    double corr_x2 = NAN;

    int num_of_test = 1;
    int num_of_fscan = 0;

    if (!access(PATH_TO_TEST, 3))
    {
        FILE *testfile = fopen(PATH_TO_TEST, "r");

        while (1)
        {
            num_of_fscan = fscanf(testfile, "%lg %lg %lg %d %lg %lg",
                    &a, &b, &c, &temp_corr_num_of_solv, &corr_x1, &corr_x2);

            switch(temp_corr_num_of_solv)
            {
                case -1:
                    corr_num_of_solv = Infinity_Roots;
                    break;
                case 0:
                    corr_num_of_solv = Zero_Roots;
                    break;
                case 1:
                    corr_num_of_solv = One_Root;
                    break;
                case 2:
                    corr_num_of_solv = Two_Roots;
                    break;
            }

            if (num_of_fscan != 6)
            {
                if (checkFileLine(testfile))
                {
                    break;
                }
            }
            else
            {
                printf("Test ?%d: ", num_of_test);

                num_of_test++;

                oneRootTest(a, b, c, corr_num_of_solv, corr_x1, corr_x2);
            }

            if (feof(testfile)) break;
        }

        fclose(testfile);
    }
    else
    {
        printf("File isn't exist.\n");
        assert(0);
    }

}
