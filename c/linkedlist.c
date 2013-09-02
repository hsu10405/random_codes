#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int val;
    struct node_t *next;
} node;

/*
node *strange_append(node *to, int val);

append(&list, 5);
list = strange_append(list, 5);
*/

void append(node **to, int val) {
    if (*to == NULL) {
	*to = malloc(sizeof(node));
	(*to)->val = val;
	(*to)->next = NULL;
	return;
    }

    append(&((*to)->next), val);
}


const node *find(const node *a, int val) {
    if (!a) return a;
    if (a->val == val) return a;
    return find(a->next, val);
}

/* union merges lists a and b but removes and frees duplicates.
 * union is destructive.
 */
node *union_list(node *a, node *b) {
    node **walk = &a;
    node *tmp;
    

    while ((*walk) != NULL) {
	if (find(b, (*walk)->val)) {
	    /* remove *walk from the list */
	    tmp = *walk;
	    *walk = tmp->next;
	    free(tmp);
	} else {
	    walk = &((*walk)->next);
	}
    }
    *walk = b;
    return a;
}
void reverse(node ** head){
    node **walk = head;
    node *walk2 = NULL;
    node *temp = (*walk)->next;

    while (temp->next != NULL){
        //set the first node to other side
        (*walk)->next = walk2;
        walk2 = *walk; //set on node
        *walk = temp;
        temp = temp->next; //shift the node
    }
    temp->next = *walk;
}
int main() {
    node *list = NULL;
    node *list2 = NULL;
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);
    append(&list, 5);
    append(&list2, 3);
    append(&list2, 6);
    append(&list2, 7);
    append(&list2, 1);
    append(&list2, 8);

    reverse(&list);
    while(list){
        printf("%d", list->val);
        list = list->next;
    }
    /*
    list = union_list(list, list2);
    while (list) {
	    printf("%d ", list->val);
	    list = list->next;
    }
    printf("\n");
    */
}
