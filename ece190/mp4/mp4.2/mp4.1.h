#ifndef MP41_H
#define MP41_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILTER_SIZE 9
#define MAX_IMAGE_SIZE 200
#define NUM_CHANNELS 3
#define RED 0
#define GREEN 1
#define BLUE 2


/* readFilter take an input filter file and extracts relevant data
   INPUTS:
        filterName: name of the filter file located in the local directory
   OUTPUTS:
        filter: 2 dimensional array holding the filter as read from file
        size: dimension of square filter as read from file
   RETURNS:
        0, on success
        -1, on failure */
int readFilter(char* fileName,
               int filter[MAX_FILTER_SIZE][MAX_FILTER_SIZE],
               int* size);

/* readImage takes an input image file and extracts relevant data
   INPUTS:
        fileName: name of the image file located in the local directory
   OUTPUTS:
        image: 3 dimensional array holding the image as read from file
        x: x-dim of image as read from file
        y: y-dim of image as read from file
        max: max pixel value as read from file
   RETURNS:        
        0, on success
        -1, on failure */
int readImage(char* fileName,
              int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS],
              int* x,
              int* y,
              int* max);

/* filterImage takes an image array and passes it through a filter, storing
   the output into another image array
   INPUTS:
        inImage: 3 dimensional array containing the original image
        filter: 2 dimensional array containing the filter
        x: x-dim of image
        y: y-dim of image
        fSize: size of the filter
        max: max pixel value
   OUTPUTS:
        outImage: 3 dimensional array containing the newly filtered image
   RETURNS:        
        0, on success
        -1, on failure */
int filterImage(int inImage[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS],
                int outImage[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS],
                int filter[MAX_FILTER_SIZE][MAX_FILTER_SIZE],
                int x,
                int y,
                int fSize,
                int max);

/* writeImage takes an image array and writes it to an image file
   INPUTS:
        fileName: name of the output file (to be stored in the local directory)
        image: 3 dimensional array holding the image as read from file
        x: x-dim of image
        y: y-dim of image
        max: max pixel value
   OUTPUTS:
        N/A
   RETURNS:        
        0, on success
        -1, on failure */
int writeImage(char* fileName,
               int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS],
               int x,
               int y,
               int max);

#endif
