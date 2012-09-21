#include<stdio.h>
#include<sys/time.h>

#define MAX_NUMS 10000
void selectionSort();
int binarySearch();
int main() 
{
    int found = 0;
    int i = 0;
    int number;
    FILE *fp = fopen("input.txt", "r"); /* fp gets the pointer to the file */

    //Use this array to store the elements read from output.txt
    int num[MAX_NUMS]; // Array of MAX_NUMS numbers. Usually dynamic memory is preferred.
                   // But for this lab, array is fine.
    //Search key
    int search_key;

    //Variables for time measurement
    double ttime;
    struct timeval start, end;


    /*
     *
     *Code to read numbers from output.txt to the array num
     *
     */
    while (fscanf(fp, "%d", &number) != EOF && i < MAX_NUMS)
    {
    num[i] = number;
    i++;
    }
    fclose(fp);

    selectionSort(num);

    //Do not change this
    printf("Enter the key to search:\n"); 
    scanf("%d", &search_key);

    gettimeofday(&start, NULL);

    //Implement the binary search algorithm in the binarySearch function
    found = binarySearch(num, search_key);

    gettimeofday(&end, NULL);

    if (found == 1)
        printf("Key found\n");
    else
        printf("Key not found\n");
    
    ttime = (double)(end.tv_sec + end.tv_usec/1000000.0) - (start.tv_sec + start.tv_usec/1000000.0);
    printf ("Time taken (sec): %g\n", ttime);

    return 0;
}

int binarySearch(int arr[], int num){
    int m = 0;
    int l = 0;
    int r = MAX_NUMS - 1;
   
    do{
        m = (l + r) / 2;

        if (num == arr[m]){
            return 1;
        }
        else if (num < arr[m]){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
     }
     while (l <= r);

    return 0;

}
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

