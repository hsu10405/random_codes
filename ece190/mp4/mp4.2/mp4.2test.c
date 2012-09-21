#include "mp4.1.h"
#include "mp4.2.h"

#define CHANNEL 2

int FilterImage();
int WriteImage();

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
               int x, int y, int max, int* area, int* center_x, int* center_y)
{

    int ver_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS];
    int hor_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS];
    
    //int overlay_image[x][y][CHANNEL];
    
    int ver_filter[3][3] = {{-1, 2, -1},
                            {-1, 2, -1},
                            {-1, 2, -1}};
    
    int hor_filter[3][3] = {{-1, -1, -1},
                            {2, 2, 2},
                            {-1, -1, -1}};
    /*
    int current_x = 0;
    int current_y = 0;
    int square_counter = 0;
    int channel = 0;
    int hor_length = 0;
    int ver_length = 0;
    */
    int number_of_squares = 0; //by default, the number is 0
    
    
FilterImage(image,
            ver_image,
            ver_filter,
            x,
            y,
            3,
            max);

FilterImage(image,
            hor_image,
            hor_filter,
            x,
            y,
            3,
            max);

/*now the finding the square part*/
    
    for (currentx = 0; currentx < x; currentx++){
		for (currenty = 0; currenty < y; currenty++){
			for (channel = 0; channel < 3; channel++){
                            if(ver_image[currentx][currenty][channel] != 0){
                                hor_length++;
                                while(ver_image[currentx + hor_length][currenty][channel] == 0){
                                     hor_length++;
                                }
                            }
                            if(hor_image[currentx][currenty][channel] != 0){
                                ver_length++;
                                while(hor_image[currentx][currenty + ver_length][channel] == 0){
                                     ver_length++;
                                }
                            }
                            if(hor_length == ver_length){
                                *area = hor_length * ver_length;
                                *center_x = currentx + (hor_length / 2);
                                *center_y = currenty + (ver_length / 2);
                                number_of_squares = 1;
                            }
                            else{
                                ver_length = 0;
                                hor_length = 0;
                            }
                    }
                }
            }
        }










WriteImage(vEdge_Filename,
           ver_image,
           x,
           y,
           max);

WriteImage(hEdge_Filename,
           hor_image,
           x,
           y,
           max);

    return number_of_squares;				

}
int WriteImage(char* fileName,
               int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS],
               int x,
               int y,
               int max)
{
    int currentx, currenty, channel = 0;
    FILE *pFile = fopen(fileName, "w");
    fprintf(pFile, "P3\n"); //writes P3 to file
    fprintf(pFile, "%d %d\n", x, y);
    fprintf(pFile, "%d\n", max);
    for (currentx = 0; currentx < x; currentx++){
        for (currenty = 0; currenty < y; currenty++){
            for(channel = 0; channel < 3; channel++){
                if(channel == 2){
                    fprintf(pFile,"%d", image[currentx][currenty][channel]);
                }
                else{
                    fprintf(pFile, "%d ", image[currentx][currenty][channel]);
                }
            }
        fprintf(pFile, "\n");
        }
    }
    fclose(pFile); //close file
    return 0;
}

int FilterImage(int inImage[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][NUM_CHANNELS],
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
    
