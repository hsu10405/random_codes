#include "graph.h"

vertex* createVertex(char character)
{
    /*Implement Me!*/

    /*Allocate memory for one new vertex and
    initialize the "node_character" field with
    the input parameter "character"*/
    vertex * node = malloc(sizeof(vertex)); //creates memory space for vertex
    if(node == NULL){
        return NULL;
    }
    node->vertex_character = character; //filling information
    
    /*Initialize the fields next and down to NULL*/


    /*Return value: 
        -> a pointer to the new vertex
        -> NULL if allocation fails*/

    return node; //return next vertex pointer

}

neighbor* createNeighbor(char character)
{
    /*Implement Me!*/

    /*Allocate memory for one new neighbor and
    initialize the "node_character" field with
    the input parameter "character"*/
    neighbor * node = malloc(sizeof(neighbor));
    if(node == NULL){
        return NULL;
    }
    /*Initialize the field next to NULL*/
    node->vertex_character = character; //filling information

    /*Return value: 
        -> a pointer to the new neighbor 
        -> NULL if allocation fails*/

    return node;
}

void deallocate(vertex *start)
{
    vertex * node = start;
   
    if(node->down != NULL){
        deallocate(node->down);
    }
    if(node->next != NULL){
    neighbor * node2 = node->next;
    neighbor * next_node2 = node2->next;
        while(next_node2 != NULL){
            free(node2);
            node2 = next_node2;
            next_node2 = next_node2->next;
        }
        free(node2);
    }
    free(node);

    /*"start" represents the start of the linked list.
    Deallocate all the memory allocated*/ 
   
    /*After freeing set the "start" variable to NULL*/

}
    
vertex* createLinkedList(int array[][100], int size)
{
    /*Creates a linked list that represents the graph 
    using the information in array. array[i][j] == 1
    means that there is an edge from i to j. size
    represents the number of nodes in the array*/

    /*Each node is represented by a character. More
    specifically row 0 in the array representation is
    represented by character 'A', row 1 by 'B'. Refer  
    to the figure given in the problem.*/ 

    /*This function uses the helper functions "createVertex()"
    and "createNeighbor()". You need to implement them.*/ 

    /*DO NOT CHANGE THIS*/

    vertex *start = NULL, *prev = NULL;
    neighbor *nbr;

    for (int i = 0; i < size; ++i)
    {
        /*create a new vertex and initialize
        with the character i + 'A' */
        vertex *newNode = createVertex(i + 'A');
        if (newNode == NULL)
        {
            printf("createVertex() returned NULL\n");
            return NULL;
        }

        if (prev != NULL)
            prev->down = newNode;

        if (start == NULL)
            start = newNode;

        for (int j = 0; j < size; ++j)
        {
            if (array[i][j] == 1) /*meaning there is an edge from i to j*/
            {
                /*create a new neighbor node and
                initialize with the character j + 'A'*/
                neighbor *newNeighbor = createNeighbor(j + 'A');
                if (newNeighbor == NULL)
                {
                    printf("createNeighbor() returned NULL\n");
                    return NULL;
                }

                if (newNode->next == NULL)
                {
                    newNode->next = newNeighbor;
                    nbr = newNeighbor;
                }
                else
                {
                    nbr->next = newNeighbor;
                    nbr = nbr->next;
                }
            }
        }

        prev = newNode;
    }

    return start;
}
