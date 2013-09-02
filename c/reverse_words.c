#include <stdio.h>
void reverse_word();
int main(){
    char word[1000];
    int number = 0;

    scanf("%d", &number);
    reverse_word(word, number);
}
void reverse_word(char *array, int n){

    if(n>0){
        scanf("%s\n", array);
        reverse_word(array, n-1);
        printf("%s\n", array);
    }
    return;
}
