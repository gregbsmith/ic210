/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "unistd.h"

typedef char cstring[128];

int main() {
	printf("Enter 5 names: ");
	cstring names[5];
	
	for(int i = 0; i < 5; i++) {
		scanf(" %s", names[i]);
	}
	
	char ch;
	
	printf("Letter: ");
	scanf("\n%c", &ch);
	
	
	cstring found = "not found";
	
	for(int i = 0; i < 5; i++) {
		if((int)names[i][0] == (int)ch) {
			strcpy(found, names[i]);
			printf("%s", found);
			printf("\n");
			return 0;
		}
	}
	
	printf("%s\n", found);
	return 0;
}
