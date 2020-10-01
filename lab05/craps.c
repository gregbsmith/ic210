/* Gregory Smith
 * 235952
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char cstring[128];

int rolldie();
int throwdice();

int main(){
	int seed = 0;
	int throw = 0;
	fputs("Enter seed value: ", stdout);
	fscanf(stdin, " %d", &seed);
	//fprintf(stdout, "%d", seed);
	srand(seed);
	/*
	 * for(int i = 0; i < 5; i++){
	 * 	int r1 = rolldie();
	 * 	int r2 = rolldie();
	 * 	int ttl = r1 + r2;
	 * 	fprintf(stdout, "Player rolled %d + %d = %d\n", r1, r2, ttl);
	 * }
	*/
	//fputs("\n", stdout);
	throw = throwdice();
	while(throw > 0){
		throw = throwdice();
	}
	
	return 0;
}

int rolldie(){
	int r = 1 + rand() % 8;
	while(r > 6){
		r = 1 + rand() % 8;
	}
	return r;
}

int throwdice(){
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
