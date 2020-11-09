/* distinct.c: Printing the number of different protocols
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
bool before(cstring a, cstring b);
void selection_sort(cstring* data, int size);
int first_index(cstring* data, int size, int start);
void swap(cstring* a, cstring* b);


int main() {
	printf("What file? ");
	cstring fname;
	scanf("%s", fname);
	
	FILE* fin = fopen(fname, "r");
	
	int lines = 0;
	fscanf(fin, "%d", &lines);
	
	cstring prots[lines];
	
	for(int i = 0; i < lines; i++) {
		for(int j = 0; j < 4; j++) {
			cstring trash;
			fscanf(fin, "%s", trash);
		}
		fscanf(fin, " %s", prots[i]);
		cstring trash;
		fscanf(fin, "%s", trash);
	}
	
	selection_sort(prots, lines);
	int distincts = 1;
	for(int i = 0; i < lines - 1; i++) {
		if(strcmp(prots[i], prots[i + 1])) {
			distincts++;
		}
	}
	
	printf("%d", distincts);
	
	fclose(fin);
	return 0;
}

bool before(cstring a, cstring b) {
	return strcmp(a, b) < 0;
}

void selection_sort(cstring* data, int size) {
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

int first_index(cstring* data, int size, int start) {
	int firsti = start;
	for(int i = start+1; i < size; ++i) {
		if(before(data[i], data[firsti])) {
			firsti = i;
		}
	}
	return firsti;
}

void swap(cstring* pa, cstring* pb) {
	cstring a;
	strcpy(a, *pa);
	// cstring a = *pa;
	strcpy(*pa, *pb);
	// *pa = *pb;
	strcpy(*pb, a);
	// *pb = a;
}
