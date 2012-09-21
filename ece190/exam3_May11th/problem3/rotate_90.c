#include <stdio.h>
#define RED 0
#define GREEN 1
#define BLUE 2

void rotate(int image[200][200][3],
           int* x,
           int* y,
           int* max);
int main()
{
    int x, y, max;
    int image[200][200][3];
    rotate(image,
           &x,
           &y,
           &max);
    return 0;    
}
void rotate(int image[200][200][3],
           int* x,
           int* y,
           int* max)
{
    int image_out[*x][*y][3];
    int currentx, currenty, channel = 0;

    for (currentx = 0; currentx < *x; currentx++){
        for (currenty = 0; currenty < *y; currenty++){
            for (channel = 0; channel < 3; channel++){
                
                 image_out[currenty][currentx][channel] = image[currentx][currenty][channel]; //rotating image
             }
        }
    }
 
    //writing file

    FILE *pFile = fopen("rotate.ppm", "w");

    fprintf(pFile, "P3\n"); //write p3
    fprintf(pFile, "%d  %d\n", *x, *y);
    fprintf(pFile, "%d\n", *max);
    
    
    for (currentx = 0; currentx < *x; currentx++){
        for (currenty = 0; currenty < *y; currenty++){
            for (channel = 0; channel < 3; channel++){
                 if(channel == 2){
                     fprintf(pFile, "%d\n", image_out[currentx][currenty][channel]);
                 }
                 fprintf(pFile, "%d %d ", image_out[currentx][currenty][channel]);
            }
        }
    }
    
   fclose(pFile);
}
