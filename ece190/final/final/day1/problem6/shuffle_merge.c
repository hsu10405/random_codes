#include "shuffle_merge.h"


node* ShuffleMerge(node* list1, node* list2)
{
    if(list1 != NULL && list2 == NULL){
        return list1;
    }
    if(list1 == NULL && list2 != NULL){
        return list2;
    }
    node * walk1 = list1; //list 1 pointer
    node * walk2 = list2; //list 2 pointer
    node * temp1 = list1->next;
    node * temp2 = list2->next;

    while(walk1->next != NULL && walk2->next != NULL){
        walk1->next = walk2;
        walk2->next = temp1;
        walk1 = temp1;
        walk2 = temp2;
        temp1 =  temp1->next;
        temp2 = temp2->next;
    }
    //case 1 list1 < list2
    if(walk1->next == NULL && walk2->next != NULL){
       //temp2 = walk2->next; 
       walk1->next = walk2;
       
    }
    if(walk1->next != NULL && walk2->next == NULL){
        
       temp1 = walk1->next;
       walk1->next = walk2;
       walk2->next = temp1;
       temp1 = walk1->next;
        
    }
    if(walk1->next == NULL && walk2->next == NULL){
        walk1->next = walk2;
    }
    return list1;

}
