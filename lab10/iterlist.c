/* iterlist.c: list.h implementation using loops
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
	Node* temp = L;
	while(temp) {
		printf("%s\n", temp->data);
		temp = temp->next;
	}
	free(temp);
}

void free_list(Node* L) {
	while(L) {
		Node* temp = L->next;
		free(L);
		L = temp;
		free(temp);
	}
	free(L);
}

bool contains(char* s, Node* L) {
	Node* temp = L;
	while(temp) {
		if(!strcmp(temp->data, s)) {
			return true;
		}
		temp = temp->next;
	}
	free(temp);
	return false;
}

char* get_ith(int i, Node* L) {
	char* val;
	Node* temp = L;
	for(int j = 0; j <= i; j++) {
		temp = temp->next;
	}
	return temp->data;
}

int num_chars(Node* L) {
	int len = 0;
	Node* temp = L;
	while(temp) {
		len += strlen(temp->data);
		temp = temp->next;
	}
	free(temp);
	return len;
}
