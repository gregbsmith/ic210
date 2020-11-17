/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef char cstring[128];

typedef struct {
	cstring name;
	int tickets[4];
} Person;

int main() {
	printf("How many people? ");
	int ppl = 0;
	scanf(" %d", &ppl);
	Person People[ppl];
	for(int i = 0; i < ppl; i++) {
		printf("Person %d name: ", i + 1);
		scanf(" %s", People[i].name);
		printf("Person %d tickets: ", i + 1);
		for(int j = 0; j < 4; j++) {
			scanf(" %d", &People[i].tickets[j]);
		}
	}
	int winticket = 0;
	printf("Winning ticket: ");
	scanf(" %d", &winticket);
	
	int winners[5];
	
	for(int i = 0; i < 5; i++) {
		winners[i]= -1;
	}
	
	int windex = 0;
	for(int i = 0; i < ppl; i++) {
		for(int j = 0; j < 4; j++) {
			if(People[i].tickets[j] == winticket) {
				winners[windex] = i;
				windex++;
			}
		}
	}
	
	for(int i = 0; i < 4; i++) {
		if(winners[i] != -1 && winners[i] != winners[i+1]) {
			printf("%s won!\n", People[winners[i]].name);
		}
	}
	
	return 0;
}
