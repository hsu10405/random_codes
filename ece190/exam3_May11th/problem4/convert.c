#include<stdio.h>

#define MAXLENGTH 100

int convert(char* str1, char*str2)
{   
    char temp1 = 0;
    
    int index, index2 = 0;
    int counter = 0;
    for(index = 0; str1[index] != '\0'; index++){
        if(str2[index] != str1[index]){
            while(str2[index] != str1[index2] && str1[index2] != '\0'){
                 index2++;
            }
        temp1 = str1[index2];
        str1[index2] = str1[index];
        str1[index] = temp1;
        index2 = 0;
        counter++;
    }
    }
    return counter;
            
}

int main()
{
	char str1[MAXLENGTH];		
	char str2[MAXLENGTH];

	int numberOfSwaps = 0;	

	printf("Enter String1: ");
	scanf("%s",&str1);
	printf("Enter String2: ");
	scanf("%s",&str2);

	numberOfSwaps = convert(str1,str2);

	printf("Number of swaps: %d\n",numberOfSwaps);
	return 0;
}

