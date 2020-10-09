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
bool cantor_row(int length, int level);

int main(){
	int size = 0;
	int row = 0;
	bool cont = 1;
	printf("size: ");
	scanf(" %d", &size);
	printf("Width-%d Cantor set:\n", size);
	while(cont){
		
		cont = cantor_row(size, row);
		printf("\n");
		row++;
	}
	
	return 0;
}

bool cantor_row(int length, int level){
	if(level == 0){
		repeat("X", length);
		if(length == 1){
			return false;
		}else{
			return true;
		}
	}else if(length > 1){
		cantor_row(length / 3, level - 1);
		repeat("_", length / 3);
		cantor_row(length / 3, level - 1);
		return true;
	}else{
		printf("X");
		return false;
	}
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

