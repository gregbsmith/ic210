/* large.c: Printing the 10 largest connections
 * Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef char cstring[128];

// selection_sort functions from unit 7 notes
bool before(int a, int b);
void selection_sort(int* data, int size);
int first_index(int* data, int size, int start);
void swap(int* a, int* b);


int main() {
	printf("What file? ");
	cstring fname;
	scanf("%s", fname);
	
	FILE* fin = fopen(fname, "r");
	
	int lines = 0;
	fscanf(fin, "%d", &lines);
	
	int sizes[lines];
	
	for(int i = 0; i < lines; i++) {
		for(int j = 0; j < 5; j++) {
			cstring trash;
			fscanf(fin, "%s", trash);
		}
		fscanf(fin, " %d", &sizes[i]);
	}
	
	selection_sort(sizes, lines);
	int prints = 10;
	if(lines < 10) {
		prints = lines;
	}
	for(int i = 0; i < prints; i++) {
		printf("%d\n", sizes[i]);
	}
	
	fclose(fin);
	return 0;
}

bool before(int a, int b) {
	return a > b;
}

void selection_sort(int* data, int size) {
	for(int i = 0; i < size - 1; i++) {
		int nexti = i;
		for(int j = i + 1; j < size; j++) {
			if(before(data[j], data[nexti])) {
				nexti = j;
			}
		}
		swap(&data[i], &data[nexti]);
	}
}

int first_index(int* data, int size, int start) {
	int firsti = start;
	for(int i = start+1; i < size; ++i) {
		if(before(data[i], data[firsti])) {
			firsti = i;
		}
	}
	return firsti;
}

void swap(int* pa, int* pb) {
	int a = *pa;
	*pa = *pb;
	*pb = a;
}
