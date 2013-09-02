#include <stdio.h>
int factorials();

void main(){
int x;
scanf("%d", &x);
x = factorials(x);
printf("%d\n", x);
}

int factorials(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n*factorials(n-1);
}
