/* temps.c
 * Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef char cstring[128];

int main() {
	int numdays = 0;
	printf("How many days? ");
	scanf(" %d", &numdays);
	
	double temps[numdays];
	
	printf("Enter temperatures\n");
	
	for(int i = 0; i < numdays; i++) {
		scanf(" %lg", &temps[i]);
	}
	
	double av = 0;
	
	for(int i = 0; i < numdays; i++) {
		av = av + temps[i];
	}
	
	av = av / numdays;
	
	int hotdays = 0;
	
	for(int i = 0; i < numdays; i++) {
		if(temps[i] > av) {
			hotdays++;
		}
	}
	
	printf("Average temperature: %lg\n", av);
	printf("%d days were hotter than average", hotdays);
	
	printf("\n");
	return 0;
}
