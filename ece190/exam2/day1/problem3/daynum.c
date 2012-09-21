/* Problem 3: Count the Days */
#include <stdio.h>
#include <math.h>

/* function definition goes here */
int daynum(int month, int day, int year)
{ 
    int yeartemp = year;
    month -= 1;
    int sum = 0;
    /* put your code here to implement the daynum function */
do{
sum += 1;
yeartemp--;
}
while(year!=0)

year = year * 365;

if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8)|| (month == 10)|| (month == 12)){
    int m1 = 0;
    int m2 = 0;
    for (m; m <= month, m ++){
    if ((month == 4) || (month == 6)) || (month == 9) || (month == 11){
    
    m2 = month * 30;
    month -= 1;    
    }
    if (month == 2){
    m2 += 28;
    month -= 1;
    }
    m1 = month * 31;
    month -= 1;
    }
}
else{
return -1
}
sum = m1 + m2 + m3 + day + yeartemp

return -1;
}

/* the main function gets input from the user and calls your function.
   you should not modify this function. */
int main()
{
    int day, month, year;
    int numdays;
    	
    printf("Enter the month: ");
    scanf("%d",&month);
    printf("Enter the day: ");
    scanf("%d",&day);
    printf("Enter the year: ");
    scanf("%d",&year);

    /* function call: */
    numdays = daynum(month,day,year);
    
    printf("Number of days : %d\n",numdays);

    return 0;
}

