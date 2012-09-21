// This program is supposed to ask the user for the number of characters to read in from a file specified as a command line argument and read the characters from the
// file while printing out the characters to the screen as they are read. To test your code create a file, or you could use any file you have on your system.
#include<stdio.h>
void readFile(char *fileName, int *x);
int main(int argc, char *argv[])
{
	int x=0;

	readFile(argv[0],&x);
}
void readFile(char *fileName, int *x)
{
	int i=0;
	char c=0;
	printf("Enter the number of characters to read: ");
	scanf("%d",x);
	FILE *fp=fopen("fileName","r");
	for(i=0;i<*x;i++)
	{
		fscanf(fp,"%c",&c);
		printf("%c",c);
	}
}
