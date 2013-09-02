#include <stdio.h>
#include <ctype.h>

// prototypling.
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[]){
	int index = 0;

	for(index = 0; index < argc; index++){
		print_letters(argv[index]);
	}
}

void print_letters(char arg[]){
	int index = 0;

	for(index = 0; arg[index] != '\0'; index++){
		char ch = arg[index];

		if(can_print_it(ch)){
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

int can_print_it(char ch){
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[]){
	print_arguments(argc, argv);
	return 0;
}