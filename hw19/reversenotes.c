/* Gregory Smith
 * notes from class on october 14
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
	// this will be changed to cycle through the array and reverse the
	// order without creating another array
	// then the array will be printed in order
	
	for(int i = 0; i < numbers/2; i++){
		int sto = theArray[i];					// think about the stuff moving in a zigzag down the lines
		theArray[i] = theArray[numbers - i - 1]; // [variable - i - 1] needs to appear somewhere
		theArray[numbers - i - 1] = sto;
	}
	
	for(int i = 0; i < numbers; i++){
		printf("%d\n", theArray[i]);
	}
	return 0;
}
