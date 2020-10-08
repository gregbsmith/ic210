/* cantor.c: Printing out the Cantor set in one line
 * Gregory Smith
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
typedef char cstring[128];
void repeat(cstring s, int count);
void cantor_row(int length);

int main(){
	int size = 0;
	printf("size: ");
	scanf(" %d", &size);
	printf("Width-%d Cantor set:\n", size);
	cantor_row(size);
	printf("\n");
	return 0;
}


void repeat(cstring s, int count){
	//base case
	if(count == 1){
		printf("%s", s);
	}else{//recursive case
		printf("%s", s);
		count--;
		repeat(s, count);
	}
}

void cantor_row(int length){
	if(length > 1){
		cantor_row(length / 3);
		repeat("_", length / 3);
		cantor_row(length / 3);
	}else{
		printf("X");
	}
}
