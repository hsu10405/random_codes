#include <stdio.h>

int checkString(char *str, char *regex); 

int main() {
    char str[100], regex[100];
    int ret;
   
    printf("Enter regular expression: ");
    scanf("%s", regex);
    printf("Enter string: ");
    scanf("%s", str);

    ret = checkString(str, regex);

    if (ret == 1)
        printf("String fits given regex\n"); 
    else 
        printf("String does not fit regex\n");

    return 0;
}

int checkString(char *str, char *regex) {

    int index = 0;
    char *pointer0;
    char *pointer1; 
    char *pointer2;
    int error = 0;
        pointer0 = strchr(regex, "|");
        pointer1 = strchr(regex, "[");
	pointer2 = strchr(regex, "]");
	if (((int)*pointer1 - (int)*pointer2) == 1 || ((int)*pointer1 - (int)*pointer2 == 0)){
            return 0;
        }
        
        
    for (index = 0; str[index] != '\0'; index++){
        if(((*pointer1 +1)  || (*pointer1 +2) || (*pointer1 + 3)) == str[index]){
        error = 0;
        }
        else{
        error = 1;
        } 
    }
    
    
}


    
