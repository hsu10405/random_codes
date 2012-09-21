#include<stdio.h>

void swap_wrong (int x, int y);
void swap(int *px, int *py);  //function declaration

int main()
{
   int x = 10;
   int y = 20;
   
   printf("After calling swap_wrong\n");
   swap_wrong(x,y);
   printf("Swapped x: %d\n",x);
   printf("Swapped y: %d\n",y);

   /*call swap();*/

   printf("After calling swap\n");
   printf("Swapped x: %d\n",x);
   printf("Swapped y: %d\n",y);
   
   return 0;
}


void swap_wrong (int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

/*function definition*/
void swap(int *px, int *py)
{

}
