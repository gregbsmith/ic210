/* Gregory Smith
 * 235952
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char cstring[128];

int rolldie();

int main(){
	int seed = 0;
	fputs("Enter seed value: ", stdout);
	fscanf(stdin, " %d", &seed);
	//fprintf(stdout, "%d", seed);
	srand(seed);
	
	for(int i = 0; i < 5; i++){
		int r1 = rolldie();
		int r2 = rolldie();
		int ttl = r1 + r2;
		fprintf(stdout, "Player rolled %d + %d = %d\n", r1, r2, ttl);
	}
	
	//fputs("\n", stdout);
	return 0;
}

int rolldie(){
	int r = 1 + rand() % 8;
	while(r > 6){
		r = 1 + rand() % 8;
	}
	return r;
}
