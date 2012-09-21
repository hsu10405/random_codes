/* Name: Alexander Hsu
 * NetID: awhsu2
 * Lab Section: AD9
 *
 * This is a program that computes the taylor expansion approximation of e^x
 * by having the user enters in the value of input and the value of error range.
 * The program will then use the error range to decide how precise the number
 * needs to be in order to satify the error range.
 * */
#include <stdio.h>

double x = 0; /* input */
double err = 0; /* error range */
double err_max = 10; /* maximum error the expansion creates */
double ans = 1; /* the approximate output */
double pwr_sum = 1; /* power sum */
double fct_sum = 1; /* factorial sum */
int n = 0; /* the number of steps needed to approximate the value */

double pwr(); /* Calculates the power per each step. */
double fct(); /* calculates the factorial per each step */

int main()
{
    printf("Enter in the value of x: ");
    scanf("\n %lf", &x);
    printf("Enter in the value of r: ");
    scanf("\n %lf", &err);
    for (n = 1; err <= err_max; n++) 
    {
        pwr(x);
        fct(n);

        ans = ans + (pwr_sum / (double)fct_sum);
        
        err_max = pwr_sum / fct_sum;
        
        if (err_max < 0)
        {
            err_max *= -1;
        }
        
    }
    printf("Number of terms = %d \n", n);
    printf("Answer = %lf \n", ans);
    
    
    return 0;
}

double pwr(double x)
{
    double temp_pwr_sum = 0;
    
    temp_pwr_sum = pwr_sum * x;
        
    pwr_sum = temp_pwr_sum;
    
    return 0; 
}
double fct(int x)
{
        
    fct_sum *= (x);
        
    
    return 0;
}
