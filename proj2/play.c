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

// prints out the first hand and puts the cards in the arrays for
// each player's hands
void first_hand(int* deck, int* pHand, int* dHand, int* pA, int* dA);

// gives the score of a hand
// needs value for aces in case over 21 with ace,
// will subtract 10 from score & decrease num aces by 1
int score(int* hand, int* size, int* aces);
// gives the score of a single card
int onescore(int val);

// prints 1 card
// if val is 0, prints "   "; if val is 1, prints " **"
void card(int c);

// player hits. returns false if busts
bool plHit(int* deck, int* pHand, int* pHsize, int* pA,
					 int* dHand, int* dHsize, int* dA);

// dealer hits. returns 0 if bust, 1 if >= 17, 2 if under 17
int dlHit(int* deck, int* pHand, int* pHsize, int* pA,
					 int* dHand, int* dHsize, int* dA);

// prints the board following a player standing and says what dealer
// does
// void plStand(int* pHand, int* pHsize, int* dHand, int* dHsize);
// void plBust(int* pHand, int* pHsize, int* dHand, int* dHsize);

void play(int* deck, int seed);

int main() {
	int seed = 0;
	
	
	fputs("Seed: ", stdout);
	fscanf(stdin, " %d", &seed);
	
	if(seed) {
		srand(seed);
	}
	
	int* deck = calloc(52, sizeof(int));
	play(deck, seed);
}

void play(int* deck, int seed) {
	
	// declaring characters used for suits
	// this code was given on the IC210 website
	char CLUB[]    = "\u2663"; // ♣
	char DIAMOND[] = "\u2666"; // ♦
	char HEART[]   = "\u2665"; // ♥
	char SPADE[]   = "\u2660"; // ♠
	int* pHand = calloc(20, sizeof(int));
	int* dHand = calloc(20, sizeof(int));
	// sizes of player and dealer hands
	// this way we know how many cards each has
	int dHsize = 2;
	int pHsize = 2;
	
	// pointers to the number of aces that each has for scoring purposes
	int pA = 0;
	int dA = 0;
	char hs;
	bool pbust = false;
	
	shuffle(deck, seed);
	bool player = true;
	first_hand(deck, pHand, dHand, &pA, &dA);
	printf("Hit or stand? [h/s] ");
	scanf("%c\n", &hs);
	player = hs == 'h';
	while(player) {
		player = plHit(deck, pHand, &pHsize, &pA, dHand, &dHsize, &dA);
		pbust = !player;
		if(player) {
			printf("Hit or stand? [h/s] ");
			scanf("%c\n", &hs);
			player = hs == 'h';
		}
	}
	if(pbust) {
		// plBust(pHand, pHsize, dHand, dHsize);
		printf("Player busts!\n\n");
		
		printf("\n\n Player Dealer\n");
		printf("| ");
		card(deck[51]);
		printf("  | ");
		card(deck[50]);
		printf("  |\n");
		printf("| ");
		card(deck[49]);
		printf("  | ");
		card(deck[48]);
		printf("  |\n");
		
		int lines = 0;
	
		if(pHsize > dHsize) {
			lines = pHsize - 2;
		}else if(dHsize > pHsize) {
			lines = dHsize - 2;
		}
		
		for(int i = 0; i < lines; i++) {
			printf("| ");
			if(pHsize > i + 2) {
				card(pHand[i + 2]);
			}else {
				card(0);
			}
			printf("  | ");
			if(dHsize > i+ 2) {
				card(dHand[i + 2]);
			}else {
				card(0);
			}
			printf("  |\n");
		}
		
		
	}else {
		
		bool dBust = false;
		bool dealer = score(dHand, &dHsize, &dA) < 17;
		while(dealer) {
			int res = dlHit(deck, pHand, &pHsize, &pA, dHand, &dHsize, &dA);
			dBust = res == 0;
			dealer = res == 2;
			if(res == 0) {
				// bust
				printf("Dealer busts!\n");
			}else if(res == 1) {
				// dealer stand
				printf("Dealer stands.\n");
			}else if(res == 2) {
				// dealer hits
				printf("Dealer hits.\n");
			}
		}
	}
	int pscr = score(dHand, &dHsize, &dA);
	int dscr = score(dHand, &dHsize, &dA);
	printf("Final scores: Player %d, Dealer %d.\n", pscr, dscr);
	if(pscr > dscr) {
		printf("Player wins!\n");
	}else if (dscr > pscr) {
		printf("Dealer wins!\n");
	}else {
		printf("Push! Play again.\n");
		shuffle(deck, 1);
		play(deck, seed);
	}
	
	free(pHand);
	free(dHand);
	free(deck);
	// printf("\n");
	return;
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

void first_hand(int* deck, int* pHand, int* dHand, int* pA, int* dA) {
	printf(" Player Dealer\n");
	printf("| ");
	card(deck[51]);
	printf("  | ");
	card(deck[50]);
	printf("  |\n");
	printf("| ");
	card(deck[49]);
	printf("  |  **  |\n");
	
	pHand[0] = deck[51];
	dHand[0] = deck[50];
	pHand[1] = deck[49];
	dHand[1] = deck[48];
}

int score(int* hand, int* size, int* aces) {
	int score = 0;
	for(int i = 0; i < *size; i++) {
		score += onescore(hand[i]);
	}
	if(score > 21 && *aces > 0) {
		score = score - 10;
		*aces--;
	}
	return score;
}

int onescore(int val) {
	int score = val % 100;
	if(score > 11) {
		score = 10;
	}
	return score;
}

void card(int c) {
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
	return;
}

bool plHit(int* deck, int* pHand, int* pHsize, int* pA,
					 int* dHand, int* dHsize, int* dA) {
	printf("\n\n Player Dealer\n");
	printf("| ");
	card(deck[51]);
	printf("  | ");
	card(deck[50]);
	printf("  |\n");
	printf("| ");
	card(deck[49]);
	printf("  |  **  |\n");
	
	for(int i = 2; i < *pHsize; i ++) {
		printf("| ");
		card(pHand[i]);
		printf("  |      |\n");
	}
	
	int offset = 51 - *pHsize;
	printf("| ");
	card(deck[offset]);
	printf("  |      |\n");
	
	pHand[*pHsize] = deck[offset];
	*pHsize++;
	
	int sc = score(pHand, pHsize, pA);
	
	return sc <= 21;
	
}

int dlHit(int* deck, int* pHand, int* pHsize, int* pA,
					 int* dHand, int* dHsize, int* dA) {
	printf("\n\n Player Dealer\n");
	printf("| ");
	card(deck[51]);
	printf("  | ");
	card(deck[50]);
	printf("  |\n");
	printf("| ");
	card(deck[49]);
	printf("  | ");
	card(deck[48]);
	printf("  |\n");
	dHand[*dHsize] = deck[51 - (*pHsize + *dHsize)];
	
	int lines = 0;
	
	if(pHsize > dHsize) {
		lines = *pHsize - 2;
	}else if(dHsize > pHsize) {
		lines = *dHsize - 2;
	}
	
	for(int i = 0; i < lines; i++) {
		printf("| ");
		if(*pHsize > i + 2) {
			card(pHand[i + 2]);
		}else {
			card(0);
		}
		printf("  | ");
		if(*dHsize > i+ 2) {
			card(dHand[i + 2]);
		}else {
			card(0);
		}
		printf("  |\n");
	}
	
	int sc = score(dHand, dHsize, dA);
	// 0 = bust
	// 1 = stand
	// 2 = hit
	
	if(sc > 21) {
		return 0;
	}else if(sc < 17) {
		return 2;
	}else {
		return 1;
	}
}

