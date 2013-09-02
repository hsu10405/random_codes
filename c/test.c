#include <stdio.h>
typedef struct{
    int rows;
    int cols'
    char * cells;
} board;
void main(){
FILE *pFile = fopen("test.txt", r);

board * pBoard = malloc(sizeof(board));
int currentx, currenty = 0;
board->rows = fscanf(pFile, "%d", &board->rows);
board->cols = fscanf(pFile, "%d", &board->cols);
board->cells = calloc(board->rows * board->cols, sizeof(char));
char *pcells = board->cells;
for(currentx = 0; currentx < board->rows; currentx++){
    for(currenty = 0; currenty < board->cols, currenty++){
        *pCells = fscanf(pFile, " %c", pCells);
	pCells++;
    }
}
}



	
