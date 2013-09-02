#include <stdio.h>

int main(int argc, char *argv[]){
	// create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank", "Mary",
		"John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int index = 0;

	//first way using indexing
	for(index = 0; index < count; index++){
		printf("%s has %d years alive.\n",
		names[index], ages[index]);
	}

	printf("---\n");

	// setup the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	// second way using pointers
	for(index = 0; index < count; index++){
		printf("%s is %d years old.\n", 
			*(cur_name+index), *(cur_age+index));
	}

	printf("---\n");

	// third way, pointer are just arrays
	for(index = 0; index < count; index++){
		printf("%s is %d years old again.\n",
			cur_name[index], cur_age[index]);
	}

	printf("---\n");

	// fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages;
			(cur_age - ages) < count;
			cur_name++, cur_age++){
		printf("%s lived %d years old for far.\n",
			*cur_name, *cur_age);
	}

	return 0;

}