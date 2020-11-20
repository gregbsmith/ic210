/* recurlist.c: list.h implementation using recursion
 * Gregory Smith
 */

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef char cstring[128];

Node* add2front(char* s, Node* L) {
	Node* temp = calloc(1, sizeof(Node));
	strcpy(temp->data, s);
	temp->next = L;
	return temp;
}

void print_fwd(Node* L) {
	if(L) {
		printf("%s\n", L->data);
	}
	if(L->next) {
		print_fwd(L->next);
	}
}

void free_list(Node* L) {
	if(L) {
		free_list(L);
		free(L);
	}else {
		free L;
	}
}

bool contains(char* s, Node* L) {
	if(!strcmp(L->data, s)) {
		return true;
	}else if(L) {
		contains(s, L->next);
	}else {
		return false;
	}
}

char* get_ith(int i, Node* L) {
	if(!i) {
		return L->data;
	}else {
		get_ith(i - 1, L->next);
	}
}

int num_chars(Node* L) {
	int n = 0;
	if(L)
}
