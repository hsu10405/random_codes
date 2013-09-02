#include <stdio.h>

void findSquare(int image[][][], *x, *y, *max){
	int current_x = 0;
	int current_y = 0;
	int square_counter = 0;
	int square_x = 0;
	int square_y = 0;
	int color_channel = 0;
	int length = 1;
	
	for (current_x; current_x < *x; current_x++){
		for (current_y = 0; curent_y < *y; current_y++){
			for (color_channel = 0; color_channel < 3; color_channel++){
				if (image[current_x][current_y][channel] != 0){ //if the image at current point is not zero (e.g. we hit the side), we need to see if it's the egde of a square
					while (image[current_x + lenth][current_y][color_channel] == 0){
						if (image[current_x + length][current_y + length][color_channel] != 0){ //if we hit a number (potentially edge of another grid or hit the other side
						break;
						length++; //increment the square length
						}
					}
					if ((image[current_x + 1][current_y][color_channel == 0 ||
						image[current_x - 1][current_y][color_channel == 0) &&
						(image[current_x][current_y + 1][color_channel == 0 ||
						image[current_x][current_y - 1][color_channel == 0)){
							square_counter++; //we found a square
						}
						length = 1; //reset length
					}
				}
			}
		}
						/*since we assume we started on the edge of the square, we need to make sure that the point we are currently on and the diagonal point are on the edge. 
						 * if there are other point lying next to the current point, then we say the point we have is not a square but somewhere in the rectangle
					}
