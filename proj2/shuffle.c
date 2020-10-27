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
	
	// declaring characters used for suits
	// this code was given on the IC210 website
	char CLUB[]    = "\u2663"; // ♣
	char DIAMOND[] = "\u2666"; // ♦
	char HEART[]   = "\u2665"; // ♥
	char SPADE[]   = "\u2660"; // ♠
	
	int seed = 0;
	
	
	fputs("Seed: ", stdout);
	fscanf(stdin, " %d", &seed);
	
	if(seed != 0) {
		srand(seed);
	}
	
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
	//int FTY_NINE = 59;
	//int FTY_TWO = 52;
	
	// the following 4 for loops populate the deck
	// in numerical order
	for(int i = 0; i < 13; i++) {
		deck[i] = 102 + i;
	}
	
	for(int i = 13; i < 26; i++) {
		deck[i] = 202 + i - 13;
	}
	
	for(int i = 26; i < 39; i++) {
		deck[i] = 302 + i - 26;
	}
	
	for(int i = 39; i < 52; i++) {
		deck[i] = 402 + i - 39;
	}
	
	// this for loop actually shuffles the deck
	for(int i = 51; i >= 0; i--) {
		int j = rand() % (i + 1);
		int sto = deck[i];
		deck[i] = deck[j];
		deck[j] = sto;
	}
	
	return;
}
