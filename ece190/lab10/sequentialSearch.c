#include<stdio.h>
#include<sys/time.h>

#define MAX_NUMS 10000

int sequentialSearch();

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

    //Do not change this
    printf("Enter the key to search:\n"); 
    scanf("%d", &search_key);

    gettimeofday(&start, NULL);

    //Implement the sequential search algorithm in the sequentialSearch function
    found = sequentialSearch(num, search_key);

    gettimeofday(&end, NULL);

    if (found == 1)
        printf("Key found\n");
    else
        printf("Key not found\n");
    
    ttime = (double)(end.tv_sec + end.tv_usec/1000000.0) - (start.tv_sec + start.tv_usec/1000000.0);
    printf ("Time taken (sec): %g\n", ttime);

    return 0;
}

int sequentialSearch(int arr[], int search_num){
    int i = 0;
    for (i; i <= (MAX_NUMS -1); i++){

       if (arr[i] == search_num){
          return 1;
       }
    }
    return 0;
}

