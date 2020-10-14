/* Gregory Smith
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
typedef char cstring[128];

int main(){
	printf("How many numbers? ");
	int numbers = 0;
	scanf(" %d", &numbers);
	int theArray[numbers];
	printf("Enter %d numbers: ", numbers);
	for(int i = 0; i < numbers; i++){
		scanf(" %d", &theArray[i]);
	}
	for(int i = 1; i <= numbers; i++){
		printf("%d\n", theArray[numbers - i]);
	}
	return 0;
}
