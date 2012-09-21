#include<stdio.h>

int main()
{
   int iray[5];
   int* ipoint = &iray[0];
   int i;
   for(i = 0; i < 100; i++)
   {
      *ipoint = i;
       printf("%p\n", ipoint);
       ipoint = ipoint + 1;
   }

   for(i = 0; i < 5; i++)
   {
      printf("%d\n", iray[i]);
   }
   return 0;
}
