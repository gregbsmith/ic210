/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef char cstring[128];

// takes a pointer to a heap-based array of 52 ints as an argument,
// modifies the array so that it contains
// the shuffled int values of a deck of cards 
int* shuffle(int* deck, int s);
void printcards(int* deck);

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
	
	if(seed) {
		srand(seed);
	}
	
	int* deck = calloc(52, sizeof(int));
	shuffle(deck, seed);
	printcards(deck);
	/*
	for(int i = 0; i < 52; i++) {
		printf("%d\n", deck[i]);
	}
	*/
	
	free(deck);
	
	return 0;
}

int* shuffle(int* deck, int s) {
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
	if(s) {
		for(int i = 51; i >= 0; i--) {
			int j = rand() % (i + 1);
			int sto = deck[i];
			deck[i] = deck[j];
			deck[j] = sto;
		}
	}
	
	return deck;
}

void printcards(int* deck) {
	
	char CLUB[]    = "\u2663"; // ♣
	char DIAMOND[] = "\u2666"; // ♦
	char HEART[]   = "\u2665"; // ♥
	char SPADE[]   = "\u2660"; // ♠
	
	for(int i = 0; i < 52; i++) {
		int c = deck[i];
		if(c % 100 != 10) {
			if(c % 100 == 11) {
				printf(" J");
			}else if(c % 100 == 12) {
				printf(" Q");
			}else if(c % 100 == 13) {
				printf(" K");
			}else if(c % 100 == 14) {
				printf(" A");
			}else {
				printf(" %d", c % 100);
			}
		}else {
			printf("%d", c % 100);
		}
		
		if(c / 100 == 1) {
			printf("%s", CLUB);
		}else if(c / 100 == 2) {
			printf("%s", DIAMOND);
		}else if(c / 100 == 3) {
			printf("%s", HEART);
		}else if(c / 100 == 4) {
			printf("%s", SPADE);
		}
		
		printf("\n");
	}
	return;
}
