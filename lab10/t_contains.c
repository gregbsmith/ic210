/* Lab 10 testing code */

#include <stdio.h>
#include <string.h>
#include "list.h"

int main() {
  char arr[64][128];
  int size = 0;
  while (scanf(" %s", arr[size]) == 1 && strcmp(arr[size],"---") != 0) {
    ++size;
  }

  printf("list size: %d\n", size);

  Node* L = NULL;
  for (int i=size-1; i >= 0; --i) {
    L = add2front(arr[i], L);
  }

  char s[128];
  while (scanf(" %s", s) == 1) {
    char* tf = contains(s, L) ? "true" : "false";
    printf("contains \"%s\": %s\n", s, tf);
  }

  return 0;
}
