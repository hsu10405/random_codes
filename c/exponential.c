#include <stdio.h>

int exponential();

int main(){
    int base, power = 0;
    int answer = 0;

    printf("enter base\n");
    scanf("%d", &base);
    printf("enter power\n");
    scanf("%d", &power);
    answer = exponential(base, power);

    printf("the answer of %d ^ %d is %d\n", base, power, answer);

    return 0;
}


int exponential(int base, int power){


    if(power == 0){
        return 1;
    }
    else{
        return base*exponential(base, power--);
    }

}
