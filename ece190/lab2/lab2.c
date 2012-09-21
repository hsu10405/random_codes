/* This is a simple program that prints a simple series starting from 256.
   The series depends on the value of the variable a which is 256 in this case.
   Hence in this case the series looks like 256,16,4,2,1. */
#include <stdio.h>
#include <math.h>

int main()
{
    int a = 256;
    int square_root_a;
    printf("%d\n", a); // Print initial value of a

repeat:
    square_root_a = sqrt(a);
    if (square_root_a >= 2)
    {
        printf("%d\n", square_root_a);
        a = square_root_a;
        goto repeat; // Go back to label "repeat" to keep iterating
    }
    else
   {	
       printf("%d\n", 1); // Print 1 to complete the series
   }   
    return 0;
}
