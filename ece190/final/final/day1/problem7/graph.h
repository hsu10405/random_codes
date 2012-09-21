#include <stdio.h>
#include <stdlib.h>

typedef struct neighbor_t  /*the node which forms the part of the neighbor linked list; */
{
        char vertex_character;
            struct neighbor_t *next;
} neighbor;

typedef struct vertex_t  /*Node which forms the vertex*/
{
        char vertex_character;
            neighbor *next;
                struct vertex_t *down;
} vertex;

void printLinkedList(vertex *start);
vertex* createLinkedList(int array[][100], int size);
void deallocate(vertex *);
vertex* createVertex(char character);
neighbor* createNeighbor(char character);
void deallocate(vertex *start);
vertex* createLinkedList(int array[][100], int size);
