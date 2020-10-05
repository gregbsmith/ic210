/* Gregory Smith
 * 235952
 */

/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef char cstring[128];

int rolldie();
int firstthrowdice();
int subthrowdice(int setPt);
int craps(int seed);

int main(){
	int bestseed = 0;
	int bestgames = 0;
	for(int i = 0; i < 5; i ++){
		int gameswon = craps(i);
		if(gameswon > bestgames){
			bestseed = i;
		}
	}
	
	fprintf(stdout, "%d\n", bestseed);
	return 0;
}

int craps(int seed){
	
	srand(seed);
	int throw = 0;
	int setPt = 0;
	int playerWins = 0;
	int winning = 1;
	
	throw = firstthrowdice();
	setPt = throw;
	while(throw > 0){
		throw = subthrowdice(setPt);
	}
	if(throw == 0){
		playerWins++;
	}else{
		winning == 0;
	}
	
	while(winning){
		throw = firstthrowdice();
		setPt = throw;
		while(throw > 0){
			throw = subthrowdice(setPt);
		}
		if(throw == 0){
			playerWins++;
		}else{
			winning == 0;
		}
	}
	return playerWins;
}

int rolldie(){
	int r = 1 + rand() % 8;
	while(r > 6){
		r = 1 + rand() % 8;
	}
	return r;
}

int firstthrowdice(){
	//house wins if roll is 2, 3, or 12
	//player wins if roll is 7 or 11
	//return -1 if house wins
	// return 0 if player wins
	int TWO = 2;
	int THREE = 3;
	int TWELVE = 12;
	int SEVEN = 7;
	int ELEVEN = 11;
	int r1 = rolldie();
	int r2 = rolldie();
	int ttl = r1 + r2;
	if(ttl == TWO || ttl == THREE || ttl == TWELVE){
		return -1;
	}else if(ttl == 7 || ttl == 11){
		return 0;
	}
	return ttl;
}

int subthrowdice(int setPt){
	// player wins if throws setPt, loses throwing 7
	// return 0 if player wins
	// return -1 if house wins
	int SEVEN = 7;
	
	int r1 = rolldie();
	int r2 = rolldie();
	int ttl = r1 + r2;
	if(ttl == 7){
		return -1;
	}else if(ttl == setPt){
		return 0;
	}
	return ttl;
}
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef char cstring[128];

int rolldie();
int firstthrowdice();
int subthrowdice(int setPt);


int main(){
	int bestWins = 0;
	int bestSeed;
	for(int i = INT_MIN + 1; i < INT_MAX - 1; i++){
		int throw = 0;
		int setPt = 0;
		int seed = i;
		int winning = 1;
		int playerWins = 0;
		srand(seed);
		
		throw = firstthrowdice();
		setPt = throw;
		while(throw > 0){
			throw = subthrowdice(setPt);
		}
		if(throw == 0){
			playerWins++;
		}else{
			winning = 0;
		}
		
		while(winning){
			throw = firstthrowdice();
			setPt = throw;
			while(throw > 0){
				throw = subthrowdice(setPt);
			}
			if(throw == 0){
				playerWins++;
			}else{
				winning = 0;
			}
		}
		if(playerWins > bestWins){
			bestSeed = i;
			bestWins = playerWins;
		}
	}
	fprintf(stdout, "%d seed\n%d wins\n", bestSeed, bestWins);
	return 0;
}

int rolldie(){
	int r = 1 + rand() % 8;
	while(r > 6){
		r = 1 + rand() % 8;
	}
	return r;
}

int firstthrowdice(){
	//house wins if roll is 2, 3, or 12
	//player wins if roll is 7 or 11
	int TWO = 2;
	int THREE = 3;
	int TWELVE = 12;
	int SEVEN = 7;
	int ELEVEN = 11;
	int r1 = rolldie();
	int r2 = rolldie();
	int ttl = r1 + r2;
	fprintf(stdout, "Player rolled %d + %d = %d ", r1, r2, ttl);
	if(ttl == TWO || ttl == THREE || ttl == TWELVE){
		fprintf(stdout, "House wins!\n");
		return -1;
	}else if(ttl == 7 || ttl == 11){
		fprintf(stdout, "Player wins!\n");
		return 0;
	}
	fprintf(stdout, "roll again\n");
	return ttl;
}

int subthrowdice(int setPt){
	// player wins if throws setPt, loses throwing 7
	int SEVEN = 7;
	
	int r1 = rolldie();
	int r2 = rolldie();
	int ttl = r1 + r2;
	fprintf(stdout, "Player rolled %d + %d = %d ", r1, r2, ttl);
	if(ttl == 7){
		fprintf(stdout, "House wins!\n");
		return -1;
	}else if(ttl == setPt){
		fprintf(stdout, "Player wins!\n");
		return 0;
	}
	fprintf(stdout, "roll again\n");
	return ttl;
}
