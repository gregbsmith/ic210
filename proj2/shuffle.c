/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef char cstring[128];

// takes a pointer to a heap-based array of 52 ints as an argument,
// modifies the array so that it contains
// the shuffled int values of a deck of cards 
void shuffle(int* deck);

int main() {
	
	int seed = 0;
	
	
	fputs("Enter seed value: ", stdout);
	fscanf(stdin, " %d", &seed);
	
	srand(seed);
	
	int* deck = calloc(52, sizeof(int));
	shuffle(deck);
	
	for(int i = 0; i < 52; i++) {
		printf("%d\n", deck[i]);
	}
	
	free(deck);
	
	return 0;
}

void shuffle(int* deck) {
	// 59 is important because RAND_MAX % 59 is 54
	int FTY_NINE = 59;
	int FTY_TWO = 52;
	for(int i = 0; i < FTY_TWO; i++) {
		
	}
	
	return;
}
