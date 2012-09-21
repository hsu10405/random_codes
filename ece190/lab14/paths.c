#include "paths.h"
#include <math.h>

int count_shortest_paths(int start_x, int start_y, int end_x, int end_y)

/*! Given starting point (start_x, start_y) and ending coordinates
    (end_x, end_y) on a 2D grid of city blocks, determine the number of
    shortest paths from the start to the end.
*/
{
    int counts = 0;
    int paths = 0;
    //backup y
    int backup = start_y;
    //cycling through y to see if the point hits the y axis
    if (start_y < end_y){
    for(start_y; start_y < end_y;start_y++){
    if(start_x == end_x){
        paths += 1;
        return paths;
    }

    if(start_x > end_x){
        start_x--;
    }
    if(start_x < end_x){
        start_x++;
    }
    counts++;
    start_y = backup; //restore backup
    return(counts + count_shortest_paths(start_x, start_y, end_x, end_y));
    }
    }
    if (start_y > end_y){
    for(start_y; start_y > end_y;start_y--){
    if(start_x == end_x){
        paths += 1;
        return paths;
    }

    if(start_x > end_x){
        start_x--;
    }
    if(start_x < end_x){
        start_x++;
    }
     counts++;
    start_y = backup; //restore backup
    return(counts + count_shortest_paths(start_x, start_y, end_x, end_y));
    }
    }
}
