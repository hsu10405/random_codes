#include <stdio.h>
#include <stdlib.h>
void destroy_search_tree();

typedef struct tree_node{
    int distance;
    /* pointers to the four child nodes: N, S, E, W */
    struct tree_node * branches[4];
} tree_node;
int main(){
    int i = 0;
    /* create some tree */
    tree_node *root=calloc(1, sizeof(tree_node));
    for(i = 0; i < 4; i++){
        root->branches[i] = calloc(1, sizeof(tree_node));
    }
    for(i = 0; i < 4; i++){
    root->branches[1]->branches[i] = calloc(1, sizeof(tree_node));
    }
    destroy_search_tree(root);
    return 0;
}

void destroy_search_tree(tree_node * node){
    //base case:at last node

    if (node->branches[0] == NULL){
        return;
    }
    destroy_search_tree(node->branches[0]);
    free(node->branches[0]);
    if (node->branches[1] == NULL){
        return;
    }
    destroy_search_tree(node->branches[1]);
    free(node->branches[1]);
    if (node->branches[2] == NULL){
        return;
    }
    destroy_search_tree(node->branches[2]);
    free(node->branches[2]);
    if (node->branches[3] == NULL){
        return;
    }
    destroy_search_tree(node->branches[3]);
    free(node->branches[3]);
    return;
    free(node);
}
