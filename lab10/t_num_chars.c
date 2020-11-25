/* Lab 10 testing code */

#include <stdio.h>
#include "list.h"

int main() {
  char arr[64][128];
  int size = 0;
  while (scanf(" %s", arr[size]) == 1) {
    ++size;
  }
  printf("list size: %d\n", size);

  Node* L = NULL;
  for (int i=size-1; i >= 0; --i) {
    L = add2front(arr[i], L);
  }

  printf("num_chars: %d\n", num_chars(L));

  return 0;
}
