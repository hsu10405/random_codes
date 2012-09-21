#include "append.h"
/*Append() allocates memory for a new node, copies the input parameter "data"
into the "data" field inside the node struct.  Then the node is added to the 
endof the linked list. */
int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    append(&head1,10);
    append(&head1,10);
    append(&head1,20);
    append(&head1,30);
    append(&head1,40);
    append(&head1,35);


    append(&head2,30);
    append(&head2,30);
    append(&head2,40);
    append(&head2,50);
    append(&head2,60);


    node* head3 = NULL;
    head3 = ShuffleMerge(head1, head2);

    printf("After Shuffle Merge:\n");
    printList(head3);

    return 0;
}

