#ifndef MP42_H
#define MP42_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mp4.1.h"

#define MAX_IMAGE_SIZE 200
#define NUM_CHANNELS 3
#define RED 0
#define GREEN 1
#define BLUE 2


/* findSquare takes an input image array looking for a square, returning
   information regarding the square found  
   INPUTS:
        vEdge_Filename: name of the output file for the vertical edge image  
        hEdge_Filename: name of the output file for the horizontal edge image
        image: 3 dimensional array holding the image as read from file
        x: x-dim of image
        y: y-dim of image
        max: max pixel value				
   OUTPUTS:
        area: area of the square
        center_x: x-coordinate of center of the square
        center_y: y-coordinate of center of the square
   RETURNS:
        number of squares found (e.g., 0 if none found, 1 if 1 square found */
int findSquare(char* vEdge_Filename, char* hEdge_Filename,
               int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS],
               int x, int y, int max, int* area, int* center_x, int* center_y);

#endif
