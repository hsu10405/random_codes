#include "mp4.1.h"

#define RED 0
#define GREEN 1
#define BLUE 2

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
              int* max)
{
    int number = 0;
    
    int i, j, k = 0;
    
    FILE *pFile = fopen(fileName, "r"); //initialize file pointer

    
    
    fseek(pFile, 3, SEEK_SET); //hopefully increment file pointer to avoid the string "P3"
    fscanf(pFile, "%d", x); /*takes the dimension of the image into array*/
    fscanf(pFile, "%d", y);
    fscanf(pFile, "%d", max); /*takes the maximum pixel into array*/


    for (i = 0; i < *x; i++){
        for (j = 0; j < *y; j++){
            for(k = 0; k < 3; k++){
                fscanf(pFile, "%d", &number);
                    if(number > *max){
                        return -1;
                    }
                image[i][j][k] = number;
            }
         }
    }
   fclose(pFile);
        

/*By now hopefully the number is passed into the array now and we can manipulate it*/
    
    
    return 0;
}



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
               int* size)
{

    int i, j = 0;
    int number = 0;
    FILE *pFile = fopen(fileName, "r");
    
    fscanf(pFile, "%d", size); //pass size back
    for (i = 0; i < *size; i++){
        for (j = 0; j < *size; j++){
            fscanf(pFile, "%d", &number); //stores filter into array
            filter[i][j] = number;
        }
    }
    fclose(pFile);


    return 0;

}


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
                int max)
{

    int filx, fily, currentx, currenty = 0;
    int channel = 0;
    int filtersum= 0;
    int weight = 0;
    

    for (currentx = 0; currentx < fSize; currentx++){
        for (currenty = 0; currenty < fSize; currenty++){
            weight += filter[currentx][currenty];
        }
    }
    int radius = fSize / 2;

    for (currentx = 0; currentx < x; currentx++){
        for (currenty = 0; currenty < y; currenty++){
            for (channel = 0; channel < 3; channel++){
                
                if ((currentx - radius) < 0 || (currenty - radius) < 0 || (currentx + radius + 1) > x || (currenty + radius + 1) > y){
                outImage[currentx][currenty][channel] = inImage[currentx][currenty][channel];
                }
                else{
                   for(filx = 0; filx < fSize; filx++){
                      for(fily = 0; fily < fSize; fily++){
           
                      filtersum += filter[filx][fily] * inImage[currentx - radius + filx][currenty - radius + fily][channel];
                      }
                   }
                
                      if (filtersum < 0){
                          filtersum = 0;
                      }
                      else if (filtersum > max){
                      filtersum = max;
                      }
                      if (weight > 0){
                      filtersum /= weight;
                      }
                   
                   outImage[currentx][currenty][channel] = filtersum;
               }
            filtersum = 0; //reset filtersum   
            
         }
      }
   }  
   //printf("%d\n", radius);
        return 0;    
}


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
               int max)
{
    int i, j, k = 0;
    FILE *pFile = fopen(fileName, "w");
    fprintf(pFile, "P3\n"); //writes P3 to file
    fprintf(pFile, "%d %d\n", x, y);
    fprintf(pFile, "%d\n", max);
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++){
            for(k = 0; k < 3; k++){
                if(k == 2){
                    fprintf(pFile,"%d", image[i][j][k]);
                }
                else{
                    fprintf(pFile, "%d ", image[i][j][k]);
                }
            }
        fprintf(pFile, "\n");
        }
    }
    fclose(pFile); //close file
    return 0;
}
