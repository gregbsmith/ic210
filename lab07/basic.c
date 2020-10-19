/* Warmup program to practice int array functions.
 * YOUR NAME HERE
 * Note, you should not change main(), just write the definitions for
 * these functions.
 */

#include <stdio.h>
#include <stdbool.h>

// fills in the array with integers read from stdin
void read(int* array, int size);

// prints the array to stdout, lined up with dashes and
// corresponding capital letters underneath
void print(int* array, int size);

// returns 1 if the array elements are in ascending (non-decreasing)
// order, and otherwise returns 0.
bool is_ordered(int* array, int size);

int main(){
	
	int size;
	scanf(" N = %i :", &size);
	
	return 0;
}

void read(int* array, int size){
	for(int i = 0; i < size; i++){
		scanf("%d", &array[i]);
	}
	return;
}

void print(int* array, int size){
	// ascii value of 'A' is 65dec
	int A = 65;
	
	for(int i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i < size; i++){
		printf("--");
	}
	
	printf("-\n");
	
	for(int i = 0; i < size; i++){
		printf(" %c", (char)(A + i));
	}
	
	printf("\n");
	
	return;
	
}

bool is_ordered(int* array, int size){
	int last = array[0];
	for(int i = 0; i < size; i++){
		if(array[i] < last){
			return false;
		}
		last = array[i];
	}
	return true;
}
