#include "mp4.1.h"

/* argc - the number of arguments you enter at the terminal (argument count)
   argv - the argument vector, which holds pointers to the argument strings
   Refer to the MP handout for details on using argc and argv. */
   
int main(int argc, char *argv[])
{
    /* Allocates static memory for input image array */
    int input_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS];

    /* Allocates static memory for output image array */
    int output_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS];

    /* Allocates static memory for filter array */
    int filter[MAX_FILTER_SIZE][MAX_FILTER_SIZE];

    int x; /* image width */
    int y; /* image height */
    int max; /* maximum pixel value in image */
    int fSize; /* Dimension of square frame, 3X3 frame has fSize=3 */
    
    char* filterName; /* Name of filter file */
    char* imageName; /* Name of image file */
    
    if (argc == 3) /* User has entered 3 arguments */
    {
        imageName = argv[1]; /* image filename */
        filterName = argv[2]; /* filter filename */
    }
    else if (argc == 2) /* User has entered only 2 arguments, attempt to use
                           default filter file, "filter.txt" */
    {
        imageName = argv[1];
        filterName = "filter.txt";
    }
    else    /* User has only entered 1 file return error message */
    {
        printf("Usage: %s IMAGE_FILE [FILTER_FILE]\n", argv[0]);
        return -1;
    }

    /* Read image from a file */
    readImage(imageName, input_image, &x, &y, &max);

    /* Read a filter from a file*/   
    readFilter(filterName, filter, &fSize);

    /* Filter the image based on the filter */
    filterImage(input_image, output_image, filter, x, y, fSize, max);

    /* Write image to output.ppm file */
    writeImage("output.ppm", output_image, x, y, max);
    
    return 0;
}
