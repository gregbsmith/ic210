/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef char cstring[128];

// sorts an array of 6 ints
void sort(int* read);

// returns true if an array of 6 ints is in order, false otherwise
bool isOrdered(int* read);

int main() {
	printf("Enter 6 numbers: ");
	int read[6];
	for(int i = 0; i < 6; i++) {
		scanf("%d", &read[i]);
	}
	sort(read);
	for(int i = 0; i < 6; i++) {
		printf("%d\n", read[5 - i]);
	}
	return 0;
}

void sort(int* read) {
	bool order = isOrdered(read);
	while(!order) {
		for(int i = 0; i < 6; i++) {
			if(read[i] > read[i + 1]) {
				int sto = read[i];
				read[i] = read[i + 1];
				read[i + 1] = sto;
			}
		}
		order = isOrdered(read);
	}
}

bool isOrdered(int* read) {
	bool order = true;
	
	for(int i = 0; i < 5; i++) {
		if(read[i] > read[i + 1]) {
			order = false;
		}
	}
	
	return order;
}
