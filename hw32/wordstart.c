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
void findprintfree(char c, Node* L);

int main() {
	Node* L = NULL;
	cstring word;
	cstring END = "END";
	printf("Enter words followed by END:\n");
	scanf(" %s", word);
	while(strcmp(word, END)) {
		L = add2front(word, L);
		scanf(" %s", word);
	}
	
	char lett;
	
	printf("What letter? ");
	scanf(" %c", &lett);
	
	findprintfree(lett, L);
	
	return 0;
}


Node* add2front(char* s, Node* L) {
	Node* temp = calloc(1, sizeof(Node));
	strcpy(temp->data, s);
	temp->next = L;
	return temp;
}

void findprintfree(char c, Node* L) {
	if(L->data[0] == c) {
		printf("%s\n", L->data);
	}
	if(L->next) {
		findprintfree(c, L->next);
	}
	free(L);
}
