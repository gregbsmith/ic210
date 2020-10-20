/* Warmup program to practice int array functions.
 * YOUR NAME HERE
 * Note, you should not change main(), just write the definitions for
 * these functions.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef char cstring[128];
// fills in the array with integers read from stdin
void read(int* array, int size);

// prints the array to stdout, lined up with dashes and
// corresponding capital letters underneath
void print(int* array, int size);

// returns 1 if the array elements are in ascending (non-decreasing)
// order, and otherwise returns 0.
bool is_ordered(int* array, int size);

int main(){
	//ascii value of A is 65
	int A = 65;
	int moves = 0;
	printf("Welcome to PutInOrder!\nEnter board description.\n");
	bool done = false;
	int size = 0;
	scanf(" N = %d : ", &size);
	int arr[size];
	read(arr, size);
	print(arr, size);
	
	while(!done){
		char swp1;
		char swp2;
		int hold = 0;
		cstring command;
		printf("command: ");
		scanf("%s", command);
		if(strcmp(command, "swap") != 0){
			printf("Unknown move \"%s\"\n", command);
			//fflush(stdout);
		}else{
			scanf(" %c %c", &swp1, &swp2);
			int swap1 = ((int) swp1) - A;
			int swap2 = ((int) swp2) - A;
			hold = arr[swap1];
			arr[swap1] = arr[swap2];
			arr[swap2] = hold;
			moves++;
			done = is_ordered(arr, size);
		}
		print(arr, size);
		// moves++;
		// done = is_ordered(arr, size);
	}
	//print(arr, size);
	printf("%d points! (%d moves)\n", moves * 3, moves);
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
