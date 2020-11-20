/* linked list header file
 * Gregory Smith
 */

#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char cstring[128];

typedef struct Node{
	cstring data;
	struct Node* next;
} Node;

Node* add2front(char* s, Node* L);

void print_fwd(Node* L);

void free_list(Node* L);

bool contains(char* s, Node* L);

char* get_ith(int i, Node* L);

int num_chars(Node* L);

#endif
