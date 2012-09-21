/*! AI module

    Implements the Artifical Intelligence of the computer controlled snake by
    providing a function that determines the computer's next move based on the
    current game state.
    
    The AI's goal is simply to find the shortest path to the nearest food, and to
    then follow that path.  If food is inaccessible, then the AI's goal is to avoid
    hitting walls.
*/

#include "ai.h"

#include <limits.h>
#include <stdlib.h>

void find_food(board * cur_board, int * distance_map, int row, int col,
               int distance, int * closest_distance)
/*! Given a board (data structure specified in game.h), a starting row and column,
    and a given path distance traveled, recursively search the board to find the
    shortest path to food.  The closest_distance input/output parameter indicates
    the closest distance to food found thus far.  When closer food is found, update
    closest_distance to reflect that.

    The distance map parameter is an array of integers corresponding to the board
    cell array.  In order for the search of large boards to finish in a reasonable
    amount of time, each entry in the distance map should be updated with the shortest
    path distance found to the corresponding cell thus far and a branch of the search
    should be ignored if it finds a path to a cell that is as long or longer than the
    shortest distance recorded in the distance map for that cell. (because that
    search is going to produce the same or worse results)
*/
{
    /*
    if(*board_cell(cur_board, row, col) == CELL_SNAKE || *board_cell(cur_board, row, col) == CELL_WALL){
        return;
    }
    if(board_cell(cur_board, row, col) == NULL){
        return;
    }
    //base case = food found
    if(*board_cell(cur_board, row, col) == CELL_FOOD){
        distance_map[cur_board->cols * row + col] = distance;
        *closest_distance = distance;
        return;
    }
    
    if(*board_cell(cur_board, row, col) == CELL_OPEN && (cur_board->rows - row) > 0 && (cur_board->cols - col) > 0){
    //then i need to update the distance_map
    distance++; //increment the distance
    if(distance_map[cur_board->cols * row + col] > distance){
    distance_map[cur_board->cols * row + col] = distance;//  
    } 
    if(row - 1 >= 0 && *board_cell(cur_board, row -1, col) != CELL_SNAKE && *board_cell(cur_board, row -1, col) != CELL_WALL){
    //Case north
        find_food(cur_board, distance_map, row - 1, col, distance, closest_distance);
    }
    //Case south
    if(row + 1 <= cur_board->rows && *board_cell(cur_board, row + 1, col) != CELL_SNAKE && *board_cell(cur_board, row + 1, col) != CELL_WALL){
        find_food(cur_board, distance_map, row + 1, col, distance, closest_distance);
    }
    if(col - 1 >= 0 && *board_cell(cur_board, row, col - 1) != CELL_SNAKE && *board_cell(cur_board, row, col - 1) != CELL_WALL){
    //Case West
    find_food(cur_board, distance_map, row, col - 1, distance, closest_distance);
    }
    if(col + 1 <= cur_board->cols && *board_cell(cur_board, row, col + 1) != CELL_SNAKE && *board_cell(cur_board, row, col + 1) != CELL_WALL){
    //Case East
    find_food(cur_board, distance_map, row, col + 1, distance, closest_distance);
    }
    return;
    }
    return;
    */
    
}

int food_distance(board * cur_board, int * distance_map, int row, int col)
/*! Given a board (data structure defined in game.h), a distance map (format defined
    in find_food) which is only allocated, not initialized, and a starting row and
    column, retuif(heading_north < heading_south){
        cur_snake->heading = NORTH;
    }rn the closest path distance to food.
    If no food is found, return INT_MAX (defined in limits.h,
    see http://uw714doc.sco.com/en/man/html.4/limits.4.html )
*/
{
    /* This code is complete; you should not need to modify it */
    int index, distance = INT_MAX;
    for (index = 0; index < cur_board->rows * cur_board->cols; index++)
    {
        distance_map[index] = INT_MAX;
    }
    find_food(cur_board, distance_map, row, col, 0, &distance);
    return distance;
}

void avoid_walls(board * cur_board, snake * cur_snake)
/*! Given a board and a snake (see game.h for data structure definitions)
    modify the heading of the given snake to avoid crashing into walls or
    snakes, if possible.
    This function assumes that no food is in reach of the given snake.
*/
{
    /* This code is complete; you should not need to modify it */
    int row = cur_snake->head->row;
    int col = cur_snake->head->col;
    if (*board_cell(cur_board, row + 1, col) == CELL_OPEN)
    {
        cur_snake->heading = SOUTH;
    }
    else if (*board_cell(cur_board, row - 1, col) == CELL_OPEN)
    {
        cur_snake->heading = NORTH;
    }
    else if (*board_cell(cur_board, row, col + 1) == CELL_OPEN)
    {
        cur_snake->heading = EAST;
    }
    else if (*board_cell(cur_board, row, col - 1) == CELL_OPEN)
    {
        cur_snake->heading = WEST;
    }
    else
    {
        /* We're blocked off; nothing we can do */
    }
}

void ai_move(game * cur_game)
/*! Given a game state (game data structure defined in game.h), determine the
    computer's next move.  For each cell adjacent to the snake head, search for
    food.  If food is found, change the computer snake's heading to go to the cell
    that has the closest distance to food. (If two or more cells have the shortest
    distance, then you are free to choose one of them)

    If no food is found, then simply call the avoid_walls function.
*/
{
    /*
    int distance_map[cur_game->board->rows * cur_game->board->cols];
    int heading_north;
    int heading_south;
    int heading_east;
    int heading_west;
    snake * cur_snake = cur_game->computer_snake;
    heading_north = food_distance(cur_game->board, distance_map, cur_game->computer_snake->head->row - 1, cur_game->computer_snake->head->col);
    heading_south = food_distance(cur_game->board, distance_map, cur_game->computer_snake->head->row + 1, cur_game->computer_snake->head->col);
    heading_east = food_distance(cur_game->board, distance_map, cur_game->computer_snake->head->row, cur_game->computer_snake->head->col + 1);
    heading_west = food_distance(cur_game->board, distance_map, cur_game->computer_snake->head->row, cur_game->computer_snake->head->col -1);
    if(heading_north < heading_south){
        cur_snake->heading = NORTH;
    }
    if(heading_south < heading_north){
        cur_snake->heading = SOUTH;
    }
    if(heading_east < heading_west){
        cur_snake->heading = EAST;
    }
    if(heading_west < heading_east){
        cur_snake->heading = WEST;
    }
    */    
    avoid_walls(cur_game->board, cur_game->computer_snake); //basic stuff
}
