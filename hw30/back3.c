/* Gregory Smith
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* add2front(int val, struct node* oldlist);

int main() {
	int temp;
	
	struct node* list = NULL;
	
	while(scanf(" %d", &temp) && temp != -1) {
		list = add2front(temp, list);
	}
	
	printf("%d\n", list->next->next->data);
	
	return 0;
}

struct node* add2front(int val, struct node* oldlist) {
  struct node* temp = calloc(1, sizeof(struct node));
  temp->data = val;
  temp->next = oldlist;
  return temp;
}
