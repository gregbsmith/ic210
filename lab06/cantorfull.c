/* cantorfull.c: Printing out the Cantor set in many lines
 * Gregory Smith
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
typedef char cstring[128];
void repeat(cstring s, int count);
void cantor_row(int length, int level);
int numRows(int j);

int main(){
	int size = 0;
	int row = 0;
	int numberRows = 0;
	bool cont = 1;
	printf("size: ");
	scanf(" %d", &size);
	printf("Width-%d Cantor set:\n", size);
	numberRows = numRows(size);
	while(row < numberRows){
		
		cantor_row(size, row);
		printf("\n");
		row++;
	}
	
	return 0;
}

void cantor_row(int length, int level){
	if(level == 0){
		repeat("X", length);
	}else if(length > 1){
		cantor_row(length / 3, level - 1);
		repeat("_", length / 3);
		cantor_row(length / 3, level - 1);
	}
	return;
}

int numRows(int j){
	int i = 0;
	while(j > 0){
		j = j/3;
		i++;
	}
	return i;
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

