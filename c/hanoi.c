#include <stdio.h>

int hanoi(int size, int from, int to, int other) {
    int moves;

    if (size == 1) {
	printf("Move disc of size 1 from %d to %d\n", from, to);
	return 1;
    }

    moves = hanoi(size-1, from, other, to);
    printf("Move disc of size %d from %d to %d\n", size, from, to);
    moves += hanoi(size-1, other, to, from);
    return moves + 1;
}

int main() {
    int i;

    scanf("%d", &i);
    hanoi(i, 1, 3, 2);
    /*
    for (i=1; i<10; i++) {
	printf("----\n");
	hanoi(i, 1, 3, 2);
    }
    */
}
