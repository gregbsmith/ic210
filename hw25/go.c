#include <stdio.h>
#include <stdlib.h>

// reads a letter into an L array
void readLetter(char** L, int m, int n, FILE* f);

// prints the letters to sdtout
void printLetter(char** L, int m, int n);

int main() {
  FILE* fin = fopen("letters.txt", "r");

  // allocate arrays
  char** L0 = calloc(4, sizeof(char*));
  char** L1 = calloc(4, sizeof(char*));
  char** L2= calloc(4, sizeof(char*));
  char** L3 = calloc(4, sizeof(char*));
  for(int i = 0; i < 4; i++) {
    L0[i] = calloc(7, sizeof(char));
    L1[i] = calloc(7, sizeof(char));
    L2[i] = calloc(7, sizeof(char));
    L3[i] = calloc(7, sizeof(char));
  }
  // Read letters
  readLetter(L0, 4, 7, fin);
  readLetter(L1, 4, 7, fin);
  readLetter(L2, 4, 7, fin);
  readLetter(L3, 4, 7, fin);
  
  // Print letters
  printLetter(L1, 4, 7);
  printLetter(L0, 4, 7);
  printLetter(L2, 4, 7);
  printLetter(L3, 4, 7);
  
  // free everything from the heap
  for (int i = 0; i < 4; i++) {
    free(L0[i]);
    free(L1[i]);
    free(L2[i]);
    free(L3[i]);
  }
  free(L0);
  free(L1);
  free(L2);
  free(L3);

  fclose(fin);

  return 0;
}

void readLetter(char** L, int m, int n, FILE* f) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			L[i][j] = fgetc(f);
		}
    while(fgetc(f) != '\n') { }
  }
}

void printLetter(char** L, int m, int n) {
	for(int i = 0; i < m;i++) {
		for(int j = 0; j < n; j++) {
			printf("%c", L[i][j]);
		}
    printf("\n");
	}
	printf("\n");
}
