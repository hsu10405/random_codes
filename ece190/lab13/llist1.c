#include <stdio.h>
#include <stdlib.h>


typedef struct node_t
{
    int data;
    struct node_t *next;
} node;

void remove_duplicates(node * head);

// Fucnction to append nodes to the Linked list.
void append(node **head,int data)
{   
		
    node *temp,*n;

    temp = (node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    n = *head;

    if(*head==NULL)
    {   
        *head=temp;
    }
    else
    {  
        while(n->next !=NULL)
	{  
	    n=n->next;
	}
	
	n->next=temp;
    }
}


void printList(node *head)
{
    node *n = head;
 
    while(n != NULL)
    {
	printf("%d # ",n->data);
	n = n->next;
    }
    printf("\n");
}


int main()
{
    node* head = NULL;

    append(&head,10);
    append(&head,10);
    append(&head,20);
    append(&head,30);
    append(&head,30);
    append(&head,30);
    append(&head,40);
    append(&head,50);
    append(&head,60);

    printf("Before:\n");
    printList(head);

    remove_duplicates(head);
    
    printf("After:\n");
    printList(head);

    return 0;
}

void remove_duplicates(node * head)
{
//we need to check the data in the next node is the same in the in the current node

         node *temp = NULL;
         node *temp2 = NULL;
         temp = head;
         temp2 = head->next;
    while(temp->next != NULL){
        if (temp->data == temp->next->data){
            //storing the pointers
            temp->next = temp2->next; //temp holds the next nodes pointer to the next next node
            //free the next node
            free(temp2);
            //store the next next pointer to the current pointer
            temp2 = temp->next;
            
            
            
        }
        else{
            //shift to the next node
            temp2 = temp2->next;
            temp = temp->next;
        }
    }

}
