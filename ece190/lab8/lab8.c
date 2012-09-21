#include <stdio.h>
#include <math.h>


float get_distance(float, float, float, float);

int main()
{
    float x1_in, y1_in, x2_in, y2_in;
    float distance = 0.0;

    printf("Enter the x value for point 1: "); /* user input*/
    scanf("%f",&x1_in);
    printf("Enter the y value for point 1: ");
    scanf("%f",&y1_in);
    printf("Enter the x value for point 2: ");
    scanf("%f",&x2_in);
    printf("Enter the y value for point 2: ");
    scanf("%f",&y2_in);

    distance = get_distance(x1_in, y1_in, x2_in, y2_in); /* calling function */

    printf("Euclidean distance = %f\n",distance);

    return 0;
}
float get_distance(float ax,float ay, float bx, float by){
    float x_diff, y_diff, e_distance;

    x_diff = bx - ax;
    y_diff = by - ay;
    e_distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));

    return e_distance;
    
}
