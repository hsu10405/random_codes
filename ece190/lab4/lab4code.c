/*Lab4 code
 *Group Members:
 *Alexander Hsu, awhsu2
 *Kevin Han, kyhan2
*/

#include <stdio.h>



int main(void) {

    int valid = 0;

    double sides[3];

    while (!valid) {

        valid = 1;

        int i;

        for (i = 1; i < 4; i++) {

            printf("Enter side %d: ", i);



            if (scanf("%lf", sides + i - 1) == 0) {

                char temp[1024];

                fgets(temp, sizeof(temp), stdin); /* clear the input buffer */

                valid = 0;

                break;

            }

            printf("\n");

        }

        

        if (sides[0] > sides[1] + sides[2] || sides[1] > sides[0] + sides[2] || sides[2] > sides[0] + sides[1]) {

            valid = 0;

        } else if (sides[0] < 0 || sides[1] < 0 || sides[2] < 0) {

            valid = 0;

        }



        if (!valid) {

            printf("Invalid input(s). Try again.\n");

        }

    }



    double s = (sides[0] + sides[1] + sides[2]) / 2;

    printf("%lf\n", s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));



    return 0;

}
