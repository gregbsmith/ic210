/* carpet.c: Printing out Sierpinski carpet
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
void carpet_row(int width, int row_index);

int main(){
	cstring DIAMOND = "\u2bc1";
	
	printf("size: ");
	int size = 0;
	scanf(" %d", &size);
	printf("Width-%d Sierpinski carpet:\n", size);
	
	for(int i = 0; i < size; i++){
		carpet_row(size, i);
		printf("\n");
	}
	
	
	// Since it's a cstring, you know how to print it!
	//printf("Here is a diamond: %s\n", DIAMOND);
	//printf("%d\n", numRows(9));
	return 0;
}


void carpet_row(int width, int row_index){
	cstring DIAMOND = "\u2bc1";
	
	if(row_index == 0 || row_index == 2){
		repeat(DIAMOND, width);
	}else if(row_index == 1){
		repeat("\u2bc1 \u2bc1", width/3); // I talked with 3/C Henry Cohn about making base cases for row_index as 0, 1, and 2
	}else{
		carpet_row(width/3, row_index % (width/3)); // I helped explain my method to Cohn using mod for recursing to the proper row_index
		
		if(row_index >= width/3 && row_index < (2*width)/3){
			repeat(" ", width/3);
		}else{
			carpet_row(width/3, row_index % (width/3));
		}
		
		carpet_row(width/3, row_index % (width/3));
	}
	/*
	if(row_index == 0 || row_index == width - 1){
		repeat(DIAMOND, width);
		return;
	}else if(row_index >= width/3 && row_index < (2*width)/3){
		carpet_row(width/3, row_index % (width/3));
		carpet_row(width/3, row_index % (width/3));
		carpet_row(width/3, row_index % (width/3));
	}else{
		carpet_row(width/3, row_index % (width/3));
		repeat(" ", width/3);
		carpet_row(width/3, row_index % (width/3));
	}
	
	if(row_index == 0 || row_index == width - 1){
		repeat(DIAMOND, width);
		return;
	}else{
		carpet_row(width/3, row_index % (width/3));
		repeat(" ", width/3);
		carpet_row(width/3, row_index % (width/3));
	}

	if(width == 1 || row_index == 0){
		printf("%s", DIAMOND);
	}else if(row_index < width/3 || row_index >= (2*width)/3){
		carpet_row(width/3, row_index - (width / 3));
		carpet_row(width/3, row_index - (width / 3));
		carpet_row(width/3, row_index - (width / 3));
	}else{
		carpet_row(width/3, row_index - (width / 3));
		repeat(" ", width / 3);
		carpet_row(width/3, row_index - (width / 3));
	}
	*/
	return;
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
