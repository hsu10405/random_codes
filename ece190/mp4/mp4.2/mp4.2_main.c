#include "mp4.2.h"

/* argc - the number of arguments you enter at the terminal (argument count)
   argv - the argument vector, which holds pointers to the argument strings
   Refer to the MP handout for details on using argc and argv. */
   
int main(int argc, char *argv[])
{
    /* Allocates static memory for input image array */
    int input_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS];

    int x; /* image width */
    int y; /* image height */
    int max; /* maximum pixel value in image */
    int area; /* area of the square */ 
    int center_x; /* x-coordinate of the center of the square */
    int center_y; /* y-coordinate of the center of the square */
    int num_squares = 0; /* number of squares found in the image */    

    char* imageName; /* Name of image file */
    
    if (argc == 2) /* User has entered 2 arguments */
    {
        imageName = argv[1]; /* image filename */
    }
    else    /* User has only entered 1 file return error message */
    {
        printf("Usage: %s IMAGE_FILE\n", argv[0]);
        return -1;
    }

    /* Read image from a file */
    readImage(imageName, input_image, &x, &y, &max);

    /* find squares in the image array */   
    num_squares = findSquare("v_edge.ppm", "h_edge.ppm", input_image, x, y,
                                 max, &area, &center_x, &center_y);

    if (num_squares == 0) /* No squares were found in the image */
    {
        printf("No square found in given image!\n");
    }
    else /* Squares were found in the image */
    {
        printf("Square Found!\n");
        printf("The Area of the square is %d.\n", area);
        printf("The center of the square is at (%d, %d).\n",center_x,center_y);		
    }
   
    return 0;
}
