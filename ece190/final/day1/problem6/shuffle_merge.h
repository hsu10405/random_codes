#include <stdio.h>
#include <stdlib.h>
 

typedef struct node_t
{
    int data;
    struct node_t *next;
} node;


node* ShuffleMerge(node*, node*);

