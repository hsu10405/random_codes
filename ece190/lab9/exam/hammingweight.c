#include<stdio.h>

int bitCount (int value); 

int main()
{
   int a, hweight;

   printf("Enter the number: ");
   scanf("%d",&a);
   
   /*function call*/
    hweight = bitCount(a);

   printf("Hamming weight: %d\n", hweight);

   return 0;
}

int bitCount (int value) 
{
   int bitshift = 0;
   int bitcount = 0;
   int i = 0;
   for (i = 0; i < value; i++){
      
    if(value >= 0){ 
      if (value = 1){
         bitcount += 1;
         value >> 1; 
        }
      
      else{
        value >> 1;
        }
    }
      else{
      return -1;
 }
    return bitcount;
}
}
