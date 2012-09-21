#include<stdio.h>
#include<sys/time.h>

#define MAX_NUMS 10000
void selectionSort();
int main() {
    int i = 0;
    int number;
    FILE *fp = fopen("input.txt", "r"); /* fp gets the pointer to the file */
    //Use this array to store the elements read from input.txt
    int num[MAX_NUMS]; // Array of MAX_NUMS numbers. Usually dynamic memory is preferred.
                   // But for this lab, array is fine.

    /*
     *
     *Code to read numbers from input.txt to the array num
     *
     */
    /*
    if (fp == NULL){
    printf("file access error\n");
    }
    else{
    printf("file pointer points to something\n");
    }
    */
    while (fscanf(fp, "%d", &number) != EOF && i < MAX_NUMS)
    {
    num[i] = number;
    i++;
    }
    fclose(fp);
    
   
    
    //Implement the selection sort algorithm in the selectionSort function
    selectionSort(num);

    //Printing elements after sorting. Do not change this.
    for (i = 0; i < MAX_NUMS; i++) {
        printf("%d \n", num[i]);
    }
    
    int arrsz = sizeof(num)/sizeof(int);
    printf("array size is %d \n", arrsz);
    return 0;
}
/*takes an array, do a FOR loop and sort the number by reference*/
void selectionSort(int arr[]){
    int i = 0;
    int j = 0;
    int min = 0;
    int temp = 0;
    for (i = 0; i <= (MAX_NUMS-2); i++){
        min = i;
        for (j = i +1; j <= (MAX_NUMS - 1); j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (i != min){
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        }
    }
}

