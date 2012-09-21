#include <stdio.h>

#include "paths.h"

int main()
{
    printf("Testing (0,0) -> (5,1) (5 paths)\n");
    printf("Result: %d\n", count_shortest_paths(0, 0, 5, 1));
    
    printf("Testing (0,0) -> (10,10) (5 paths)\n");
    printf("Result: %d\n", count_shortest_paths(0, 0, 10, 10));
    // Add more test cases here.
    
    return 0;
}
