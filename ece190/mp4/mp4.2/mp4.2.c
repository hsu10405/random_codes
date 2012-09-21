 #include "mp4.1.h"
#include "mp4.2.h"

#define CHANNEL 3

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

    int ver_image[x][y][CHANNEL];
    int hor_image[x][y][CHANNEL];
    int square[x][y];
    int square_hor[x][y];
    int square_ver[x][y];
    int overlay_image[x][y][CHANNEL]; /*testing purpose*/
    
    int ver_filter[3][3] = {{-1, 2, -1},
                            {-1, 2, -1},
                            {-1, 2, -1}};
    
    int hor_filter[3][3] = {{-1, -1, -1},
                            {2, 2, 2},
                            {-1, -1, -1}};
    
	
    int ver_length = 1; /*the length*/
    int hor_length = 1; /*of the square*/
    
    int number_of_squares = 0; //by default, the number is 0
    int square_temp = 0;
    int square_temp_ver = 0;
    int square_temp_hor = 0;    
    
/*filtering */
    int filx, fily, currentx, currenty = 0;
    int channel = 0;
    int ver_filtersum= 0;
    int hor_filtersum = 0;
    int ver_weight = 0;
    int hor_weight = 0;
    
    int radius = 3 / 2;
    
    for (currentx = 0; currentx < 3; currentx++){
        for (currenty = 0; currenty < 3; currenty++){
            ver_weight += ver_filter[currentx][currenty];
        }
    }
    
    
    for (currentx = 0; currentx < x; currentx++){
        for (currenty = 0; currenty < y; currenty++){
            for (channel = 0; channel < 3; channel++){
                
                if ((currentx - radius) < 0 || (currenty - radius) < 0 || (currentx + radius + 1) > x || (currenty + radius + 1) > y){
                    ver_image[currentx][currenty][channel] = image[currentx][currenty][channel];
                }
                else{
                    for(filx = 0; filx < 3; filx++){
                        for(fily = 0; fily < 3; fily++){
                            
                            ver_filtersum += ver_filter[filx][fily] * image[currentx - radius + filx][currenty - radius + fily][channel];
                        }
                    }
                    
                    if (ver_filtersum < 0){ //checking cases
                        ver_filtersum = 0;
                    }
                    else if (ver_filtersum > max){
                        ver_filtersum = max;
                    }
                    if (ver_weight > 0){
                        ver_filtersum /= ver_weight;
                    }
                    
                    ver_image[currentx][currenty][channel] = ver_filtersum;
                }
                ver_filtersum = 0; //reset ver_filtersum   
                
            }
        }
    }  

    for (currentx = 0; currentx < 3; currentx++){
        for (currenty = 0; currenty < 3; currenty++){
            hor_weight += hor_filter[currentx][currenty];
        }
    }
    
    
    for (currentx = 0; currentx < x; currentx++){
        for (currenty = 0; currenty < y; currenty++){
            for (channel = 0; channel < 3; channel++){
                
                if ((currentx - radius) < 0 || (currenty - radius) < 0 || (currentx + radius + 1) > x || (currenty + radius + 1) > y){
                    hor_image[currentx][currenty][channel] = image[currentx][currenty][channel];
                }
                else{
                    for(filx = 0; filx < 3; filx++){
                        for(fily = 0; fily < 3; fily++){
                            
                            hor_filtersum += hor_filter[filx][fily] * image[currentx - radius + filx][currenty - radius + fily][channel];
                        }
                    }
                    
                    if (hor_filtersum < 0){//checking cases
                        hor_filtersum = 0;
                    }
                    else if (hor_filtersum > max){
                        hor_filtersum = max;
                    }
                    if (hor_weight > 0){
                        hor_filtersum /= hor_weight;
                    }
                    
                    hor_image[currentx][currenty][channel] = hor_filtersum;
                }
                hor_filtersum = 0; //reset hor_filtersum   
                
            }
        }
    }  

    for (currentx = 0; currentx < x; currentx++){ //testing purpsose
        for (currenty = 0; currenty < y; currenty++){
            for (channel = 0; channel < 3; channel++){
                overlay_image[currentx][currenty][channel] = hor_image[currentx][currenty][channel] + ver_image[currentx][currenty][channel];
            }
        }
    }

/*superimposing the pixel for square detection*/
    for (currentx = 3; currentx < (x - 3); currentx++) {
        for (currenty = 3; currenty  < (y - 3); currenty++) {
            for (channel = 0; channel < 3; channel++) {
                square_temp += overlay_image[currentx][currenty][channel];
                square_temp_ver += ver_image[currentx][currenty][channel];
                square_temp_hor += hor_image[currentx][currenty][channel];
            }
            square[currentx][currenty] = square_temp;
            square_ver[currentx][currenty] = square_temp_ver;
            square_hor[currentx][currenty] = square_temp_hor;
            square_temp =0;
            square_temp_ver =0;
            square_temp_hor =0;
        }
    }
    

    
/*now the finding the square part*/
    
    for (currentx = 1; currentx < (x-1); currentx++){
		for (currenty = 1; currenty < (y-1); currenty++){
			if (square[currentx][currenty] != 0){
                while((square_ver[currentx][currenty + hor_length] != square_ver[currentx][currenty]) && ((currenty + hor_length) < y)){
                    hor_length++;
                }
                while (square_hor[currentx + ver_length][currenty] != square_hor[currentx][currenty] && ((currentx + ver_length) < x)) {
                    ver_length++;
                }
                if (ver_length == hor_length) {
                    *area = ver_length * hor_length; /*if the pixels are equal at these locations, then we say it's a square*/
                    *center_x = currenty + (hor_length / 2);
                    *center_y = currentx + (ver_length / 2);
                    number_of_squares = 1;
                }
                else{
                    ver_length = 1;
                    hor_length = 1;
                }
            }
            
            
            
        }
    }
     
/*writing to output*/
    
    
    FILE *pFile = fopen(vEdge_Filename, "w");
    fprintf(pFile, "P3\n"); //writes P3 to file
    fprintf(pFile, "%d %d\n", x, y);
    fprintf(pFile, "%d\n", max);
                                                         
    for (currentx = 0; currentx < x; currentx++){
        for (currenty = 0; currenty < y; currenty++){
            for(channel = 0; channel < 3; channel++){
                if(channel == 2){
                    fprintf(pFile,"%d\n", ver_image[currentx][currenty][channel]);
                }
                else{
                    fprintf(pFile, "%d ", ver_image[currentx][currenty][channel]);
                }
            }
        fprintf(pFile, "\n");
        }
    }
    fclose(pFile); //close file}

    pFile = fopen(hEdge_Filename, "w");
    fprintf(pFile, "P3\n"); //writes P3 to file
    fprintf(pFile, "%d %d\n", x, y);
    fprintf(pFile, "%d\n", max);
                                                         
    for (currentx = 0; currentx < x; currentx++){
        for (currenty = 0; currenty < y; currenty++){
            for(channel = 0; channel < 3; channel++){
                if(channel == 2){
                    fprintf(pFile,"%d\n", hor_image[currentx][currenty][channel]);
                }
                else{
                    fprintf(pFile, "%d ", hor_image[currentx][currenty][channel]);
                }
            }
        fprintf(pFile, "\n");
        }
    }
                                                         
    return number_of_squares;				
}
