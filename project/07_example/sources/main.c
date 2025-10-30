#include <stdio.h>
#include "example.h"

int main (void)
{
    int inputNum = 0;
    int resultNum = 0;
    printf ("Please type your number: ");
    scanf ("%d", &inputNum);
    resultNum = returnValidvalue (inputNum);
    resultNum == -1 ? printf ("Invalid number\n") : printf ("Valid number: %d\n", inputNum);
    return 0;
}