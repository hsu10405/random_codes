/*This code should read a line and print out the alphanumeric characters only. However, it does not behave as specified. Fix the code. There are no syntax errors. Look for logic errors. */
#include<stdio.h>
int main()
{
	char echo= '0';
	while(echo != '\n'){
	 scanf("%c", &echo);
	 if((echo >= 'a' && echo <= 'z') || (echo >= 'A' && echo <= 'Z') || (echo >= '0' && echo <= '9') || (echo == ' '))
	 	printf("%c",echo);
        }
	return 0;
}
