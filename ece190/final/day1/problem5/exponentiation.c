#include "exponentiation.h"

int exponentiation(int x, int y)
{

        //base case : y = 0
    if (y == 0){
        return 1;
    }
    return x * exponentiation(x, y - 1); 

}
