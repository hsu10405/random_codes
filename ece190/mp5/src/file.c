/*! File module

    Provides level loading functionality through a function that creates a game from a
    level file.  Also provides a function for destroying the game instance for use during
    teardown.
*/

#include "game.h"
#include "file.h"

#include <stdio.h>
#include <stdlib.h>

game * create_game(const char * file_name)
/*! Load an input level file with given file_name with format specified in levels/README.txt,
    and transform the serialized data within into a game data structure, specified in game.h
    Return a pointer to the game instance on success, NULL on failure.

    Note that error handling is not required for credit, but may help with testing.

    The game and structures it points to should be allocated with the malloc family of
    functions.  Make sure to take advantage of allocation functions provided by the game module.
*/
{
    FILE *pFile = fopen(file_name, "r"); //opens the file
    
    if (pFile == NULL){
    
        return NULL; //if the file is not there, return failure
    }
    //otherwise
    int row = 0;
    int column = 0;
    float delay_per_game = 0;
    float food_prob = 0;
    int grow_segment = 0;
    char board_layout;
    
    //passing the value from file to variables

    fscanf(pFile,"%d", &row);
    fscanf(pFile,"%d", &column);
    fscanf(pFile,"%f", &delay_per_game);
    fscanf(pFile,"%f", &food_prob);
    fscanf(pFile,"%d", &grow_segment);
	
 
    if (row == 0 || column == 0){
        return NULL;
    }
    //pass the variable into the struct
    game *pGame;
    cell *pCell;
	
    pGame = malloc(sizeof(game)); //creates a space for game
    pGame->board = create_board(row, column); //create board

    int current_row, current_col = 0; //initialize board scanner counter

    pCell = pGame->board->cells; //copy cell pointer

    for(current_row = 0; current_row < row; current_row++){
		for (current_col = 0; current_col < column; current_col++){
			fscanf(pFile, " %c", &board_layout);
			if(board_layout == 'X'){
				*pCell = CELL_WALL;
			}
			if(board_layout == '-'){
				*pCell = CELL_OPEN;
			}
			if(board_layout == 'n' || board_layout == 's' || board_layout == 'e' || board_layout == 'w' ) {
				*pCell = CELL_SNAKE;
                if(board_layout == 'n'){
				    pGame->human_snake = create_snake(pGame->board, current_row, current_col, NORTH, grow_segment);
                }
                if(board_layout == 's'){
				    pGame->human_snake = create_snake(pGame->board, current_row, current_col, SOUTH, grow_segment);
                }
                if(board_layout == 'e'){
				    pGame->human_snake = create_snake(pGame->board, current_row, current_col, EAST, grow_segment);
                }
                if(board_layout == 'w'){
				    pGame->human_snake = create_snake(pGame->board, current_row, current_col, WEST, grow_segment);
                }
			}
			if(board_layout == 'N' || board_layout == 'S' || board_layout == 'E' || board_layout == 'W' ) {
				*pCell = CELL_SNAKE;
                if(board_layout == 'N'){
				    pGame->computer_snake = create_snake(pGame->board, current_row, current_col, NORTH, grow_segment);
                }
                if(board_layout == 'S'){
				    pGame->computer_snake = create_snake(pGame->board, current_row, current_col, SOUTH, grow_segment);
                }
                if(board_layout == 'E'){
				    pGame->computer_snake = create_snake(pGame->board, current_row, current_col, EAST, grow_segment);
                }
                if(board_layout == 'W'){
				    pGame->computer_snake = create_snake(pGame->board, current_row, current_col, WEST, grow_segment);
                }
			}
			pCell++;
		
    	}
	}
    //filling out the remaining variables
    pGame->time_step = delay_per_game;
    pGame->food_probability = food_prob;
    pGame->growth_per_food = grow_segment;
	
    fclose(pFile); //close the file

    
    return pGame; //pass the pointer to game
}

void destroy_game(game * cur_game)
/*! Deallocate any memory acquired with malloc associated with the given game instance.
    This includes any substructures the game data structure contains.  Make sure to take
    advantage of deallocation functions provided by the game module. */
{
    //destroy the sub structs (snake, board)
    //destroy human snake first
    
	destroy_snake(cur_game->human_snake);
	destroy_snake(cur_game->computer_snake);
	
    //destroy board
    
    destroy_board(cur_game->board);
	
	//Destroy game
	free(cur_game);
}
