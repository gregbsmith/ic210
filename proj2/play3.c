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
void deal(int* deck);
// take a blank card string and modify for the number
// suit representation of the card
// void getCard(cstring card, int val);

// prints one card in suit representation given an int value of
// a card
void onecard(int c);

// prints the first four cards
void first_hand(int* deck);

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
	// printf("\n");
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

void deal(int* deck) {
	int delrAs = 0;
	int plyrAs = 0;
	char hs;
	int d_ind = 51;
	int cards_dealt = 4;
	first_hand(deck);
	printf("Hit or stand? [h/s] ");
	scanf(" %c", &hs);
	if(hs == 'h') {
		// hit
		bool pl = true;
		while(pl) {
			first_hand(deck);
			for(int i = 3; i < cards_dealt; i++) {
				printf("| ");
				onecard(deck[d_ind - i - 1]);
				printf("  | ");
				onecard(0);
				printf("  |\n");
			}
			cards_dealt++;
			
			
			printf("Hit or stand? [h/s] ");
			scanf(" %c", &hs);
			if(hs != 'h') {
				pl = false;
			}
		}
	}
	// stand
	first_hand(deck);
	if(cards_dealt > 4) {
		for(int i = 3; i < cards_dealt - 1; i++) {
			printf("| ");
			onecard(deck[d_ind - i - 1]);
			printf("  | ");
			onecard(0);
			printf("  |\n");
		}
		sleep(2);
		printf("Dealer hits.\n");
		// sleep(2);
		first_hand(deck);
		printf("| ");
		onecard(deck[d_ind - 4]);
		printf("  | ");
		int dealer_cards = cards_dealt + 1;
		onecard(deck[d_ind - cards_dealt]);
		printf("  |\n");
		for(int i = 4; i < cards_dealt - 1; i++) {
			printf("| ");
			onecard(deck[d_ind - i - 1]);
			printf("  | ");
			onecard(0);
			printf("  |\n");
		}
		
		sleep(2);
		printf("Dealer hits.\n");
		// sleep(2);
		first_hand(deck);
		printf("| ");
		onecard(deck[d_ind - 4]);
		printf("  | ");
		//dealer_cards++;
		
		onecard(deck[d_ind - cards_dealt]);
		
		printf("  |\n");
		printf("| ");
		if(cards_dealt == 5) {
			onecard(0);
		}else {
			onecard(deck[d_ind - 5]);
		}
		printf("  | ");
		onecard(deck[d_ind - dealer_cards]);
		printf("  |\n");
		for(int i = 5; i < cards_dealt - 1; i++) {
			printf("| ");
			onecard(deck[d_ind - i - 1]);
			
			printf("  | ");
			onecard(0);
			printf("  |\n");
		}
		
	}else {
		sleep(2);
		printf("Dealer hits.\n");
		// sleep(2);
		first_hand(deck);
		for(int i = 3; i < cards_dealt; i++) {
			printf("| ");
			onecard(0);
			printf("  | ");
			onecard(deck[d_ind - i - 1]);
			printf("  |\n");
		}
		cards_dealt++;
		sleep(2);
		printf("Dealer hits.\n");
		//sleep(2);
		first_hand(deck);
		for(int i = 3; i < cards_dealt; i++) {
			printf("| ");
			onecard(0);
			printf("  | ");
			onecard(deck[d_ind - i - 1]);
			printf("  |\n");
		}
		cards_dealt++;
	}
	sleep(2);
	printf("Dealer stands.\n");
	
	return;
}

void onecard(int c) {
	char CLUB[]    = "\u2663"; // ♣
	char DIAMOND[] = "\u2666"; // ♦
	char HEART[]   = "\u2665"; // ♥
	char SPADE[]   = "\u2660"; // ♠
	if(!c) {
		printf("   ");
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

/*get card function
void getCard(cstring card, int val) {
	char CLUB[]    = "\u2663"; // ♣
	char DIAMOND[] = "\u2666"; // ♦
	char HEART[]   = "\u2665"; // ♥
	char SPADE[]   = "\u2660"; // ♠
	
	//cstring card = "";
	
	if(val % 100 != 10) {
		//strcat(card, " ");
		if(val % 100 == 11) {
			strcat(card, " J");
		}else if(val % 100 == 12) {
			strcat(card, " Q");
		}else if(val % 100 == 13) {
			strcat(card, " K");
		}else if(val % 100 == 14) {
			strcat(card, " A");
		}else {
			strcat(card, " ");
			char the_array[1];
			the_array[0] = (char)(val % 100);
			strcat(card, the_array);
		}
	}else {
		strcat(card, "10");
		printf("%d", val % 100);
	}
		
	if(val / 100 == 1) {
		strcat(card, CLUB);
	}else if(val / 100 == 2) {
		strcat(card, DIAMOND);
	}else if(val / 100 == 3) {
		strcat(card, HEART);
	}else if(val / 100 == 4) {
		strcat(card, SPADE);
	}
	return;
}
*/

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

int score(int val) {
	if(val % 100 == 14) {
		return 11;
	}else if(val % 100 >= 10) {
		return 10;
	}else {
		return val % 100;
	}
}
