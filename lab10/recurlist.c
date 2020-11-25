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
	if(L == NULL) {
		return;
	}
	printf("%s\n", L->data);
	print_fwd(L->next);
}

void free_list(Node* L) {
	if(L) {
		free_list(L->next);
		free(L);
	}else {
		free(L);
	}
}

bool contains(char* s, Node* L) {
	if(L == NULL) {
		return false;
	}else if(!strcmp(L->data, s)) {
		return true;
	}else if(L->next) {
		return contains(s, L->next);
	}else {
		return false;
	}
}

char* get_ith(int i, Node* L) {
	if(!i) {
		return L->data;
	}else {
		return get_ith(i - 1, L->next);
	}
}

int num_chars(Node* L) {
	if(L == NULL) {
		return 0;
	}else if(L->next) {
		return strlen(L->data) + num_chars(L->next);
	}else {
		return strlen(L->data);
	}
}
