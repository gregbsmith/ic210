/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char cstring[128];

typedef struct Node{
	cstring data;
	struct Node* next;
} Node;

Node* add2front(char* s, Node* L);
Node* rmfront(Node* L);

int main() {
	printf("The canvas is blank.\n");
	Node* L = NULL;
	cstring comm;
	cstring color;
	scanf(" %s", comm);
	int x = strcmp(comm, "strip");
	if(strcmp(comm, "strip")) {
		scanf(" %s", color);
	}
	while(x) {
		if(strcmp(comm, "strip")) {
			L = add2front(color, L);
		}else {
			L = rmfront(L);
		}
		
		if(L) {
			printf("The top color is %s.\n", L->data);
		}else {
			printf("The canvas is blank.\n");
		}
		
		scanf(" %s", comm);
		if(strcmp(comm, "strip")) {
			scanf(" %s", color);
		}
		
		if(L || strcmp(comm, "strip")) {
			x = 1;
		}else {
			x = 0;
		}
	}
	free(L);
	return 0;
}

Node* add2front(char* s, Node* L) {
	Node* temp = calloc(1, sizeof(Node));
	strcpy(temp->data, s);
	temp->next = L;
	return temp;
}

Node* rmfront(Node* L) {
	Node* temp = L->next;
	free(L);
	return temp;
}
