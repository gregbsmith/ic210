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
void deal(int* deck);
// take a blank card string and modify for the number
// suit representation of the card
// void getCard(cstring card, int val);

// prints one card in suit representation given an int value of
// a card
void onecard(int c);
// same as onecard, just used only on the first printing of a card
// also updates player's score and number of aces
void scorecard(int c, int* a, int* s);
// prints the first four cards
void first_hand(int* deck);
// same as above with 2 asteriks for dealer hole card
void first_hand_p(int* deck);

// same as first hand p except updates scores
void first_hand_p_s(int* deck, int* da, int* ds, int* pa, int* ps);
//takes the integer 102-414 value of a card and returns the card's
//blackjack score 2-11
int score(int val);

int main() {
	int seed = 0;
	fputs("Seed: ", stdout);
	fscanf(stdin, " %d", &seed);
	if(seed) {
		srand(seed);
	}
	int* deck = calloc(52, sizeof(int));
	shuffle(deck, seed);
	deal(deck);
	free(deck);
	return 0;
}

int* shuffle(int* deck, int s) {

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

void deal(int* deck) {
	int dA = 0;
	int pA = 0;
	int ds = 0;
	int ps = 0;
	int ind = 47; // decrease this after placing a new card
	first_hand_p_s(deck, dA, ds, pA, ps);
	bool playing = true;
	char hs;
	bool dealerbust = false;
	printf("Hit or stand? [h/s] ");
	scanf(" %c", &hs);
	playing = hs == 'h';
	while(playing) {
		// player hitting
		first_hand_p(deck);
		if(ps > 21) {
			// player busts
		}
	}
	// player stands
	
	while(ds < 17) {
		// dealer hit/stand
		if(ds > 21) {
			//dealer busts
		}
	}
	printf("Final scores: Player %d, Dealer %d.\n", pscr, dscr);
	if(pscr > dscr) {
		printf("Player wins!\n");
	}else if (dscr > pscr) {
		printf("Dealer wins!\n");
	}else {
		printf("Push! Play again.\n");
		shuffle(deck, 1);
		deal(deck);
	}
	return;
}

void scorecard(int c, int* a, int* s) {
	char CLUB[]    = "\u2663"; // ♣
	char DIAMOND[] = "\u2666"; // ♦
	char HEART[]   = "\u2665"; // ♥
	char SPADE[]   = "\u2660"; // ♠
	if(!c) {
		printf("   ");
	}else if (c == 1) {
		printf(" **");
	}else if(c % 100 != 10) {
		if(c % 100 == 11) {
			printf(" J");
			*s += 10;
		}else if(c % 100 == 12) {
			printf(" Q");
			*s += 10;
		}else if(c % 100 == 13) {
			printf(" K");
			*s += 10;
		}else if(c % 100 == 14) {
			printf(" A");
			*s += 11;
			*a++;
		}else {
			printf(" %d", c % 100);
			*s += c % 100;
		}
	}else {
		printf("%d", c % 100);
		*s += 10;
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
	
	//printf("\n");
	
	return;
}

void onecard(int c) {
	char CLUB[]    = "\u2663"; // ♣
	char DIAMOND[] = "\u2666"; // ♦
	char HEART[]   = "\u2665"; // ♥
	char SPADE[]   = "\u2660"; // ♠
	if(!c) {
		printf("   ");
	}else if (c == 1) {
		printf(" **");
	}else if(c % 100 != 10) {
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
	
	//printf("\n");
	
	return;
}

void first_hand(int* deck) {
	printf("\n Player Dealer\n");
	printf("| ");
	onecard(deck[51]);
	printf("  | ");
	onecard(deck[50]);
	printf("  |\n| ");
	onecard(deck[49]);
	printf("  | ");
	onecard(deck[48]);
	printf("  |\n");
}

void first_hand_p(int* deck) {
	printf("\n Player Dealer\n");
	printf("| ");
	onecard(deck[51]);
	printf("  | ");
	onecard(deck[50]);
	printf("  |\n| ");
	onecard(deck[49]);
	printf("  | ");
	onecard(1);
	printf("  |\n");
}

void first_hand_p_s(int* deck, int* da, int* ds, int* pa, int* ps) {
	printf("\n Player Dealer\n");
	printf("| ");
	scorecardcard(deck[51], pa, ps);
	printf("  | ");
	scorecard(deck[50], da, ds);
	printf("  |\n| ");
	scorecard(deck[49], pa, ps);
	printf("  | ");
	onecard(1);
	printf("  |\n");
}

int score(int val) {
	if(val % 100 == 14) {
		return 11;
	}else if(val % 100 >= 10) {
		return 10;
	}else {
		return val % 100;
	}
}
