#include <stdio.h>
#include "../headers/InOutPut.h"


void clearBuf(void)
{
    while (getchar() != '\n') continue;
}

void chooseOption(void)
{
    printf("\nChoose the option:\n"
               "1) Solve square equation.\n"
               "2) Root test.\n"
               "0) Exit.\n");
}

void greetings(void)
{
    printf("Hello, darkness, my old friend.\n"
           "This program can solve the square equation\n"
           "of type a*x^2 + b*x + c = 0.\n"
           "Also it can take tests, \n"
           "but this feature only for devops.\n"
           "That is, for me. :)\n"
           "P.S. meow\n");
}
