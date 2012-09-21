#include "graph.h"

int main()
{
    FILE *fptr;
    int array[100][100], size;
    fptr = fopen("graph.txt", "r");
    if (fptr == NULL)
    {
        printf("Error: open file failed\n");
        return -1;
    }

    fscanf(fptr, "%d", &size);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            fscanf(fptr, "%d", &array[i][j]);

    /*creates the linked list for graph and returns
    a pointer to the start of linked list*/
    vertex *start = createLinkedList(array, size);
    if (start == NULL)
    {
        printf("createLinkedList() returned NULL\n");
        fclose(fptr);
        return -1;
    }

    /*prints the linked list given the start pointer
    this has been implemented already*/
    printLinkedList(start);

    /*deallocates all the linked list memory*/
    deallocate(start);

    fclose(fptr);

    return 0;
}
