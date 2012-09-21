#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *p = (char*)malloc(sizeof(char)*10); 
    // Assign some value to p
    strcpy(p, "Hello");

    char *name = (char*)malloc(sizeof(char)*11);
    // Assign some value to name
    strcpy(name, "Bye");
    
    memcpy (p,name,sizeof(char)*10); // Problem begins here
    
    return 0;
}
