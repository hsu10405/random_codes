#include <stdio.h>
#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));

    x[9] = 10;
   
    printf("%d\n",x[9]);
   
    free(x);
    return;
}

int main(void)
{
    f();
    return 0;
}
