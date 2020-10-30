#include <stdio.h>
#include <string.h>
#include "vote_functions.h"

void get_names(char* c1, char* c2) {
	printf("Candidate names: ");
	scanf(" %s %s", c1, c2);
	return;
}

bool update_counts(char* input, char* c1, int* ct1,
char* c2, int*ct2) {
	char* END = "END";
	if(!strcmp(input, END)) {
		return false;
	}else if(!strcmp(input, c1)) {
		*ct1++;
	}else if(!strcmp(input, c2)) {
		*ct2++;
	}
	return true;
}

void display_results(char* c1, int ct1, char* c2, int ct2) {
	if(ct1 == ct2) {
		printf("Tie!\n");
	}else if (ct1 > ct2) {
		printf("%s wins with %d of %d votes\n", c1, ct1, ct1 + ct2);
	}else if (ct2 > ct1) {
		printf("%s wins with %d of %d votes\n", c2, ct2, ct1 + ct2);
	}
	return ;
}
