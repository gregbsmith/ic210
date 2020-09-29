/* Gregory Smith
 * p3.c: treasure map
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char cstring[128];

int main(){
	cstring filename;
	int readIn;
	cstring SP = " ";
	cstring STR = "*";
	cstring cX = "X";
	cstring printThing;
	int printNum = 1;
	int nX = 88;
	int N = 78;
	int Q = 81;
	int S = 83;
	int B = 66;
	int row = 0;
	int col = 0;
	int xRow = 0;
	int xCol = 0;
	fprintf(stdout, "Filename: ");
	fscanf(stdin, " %s", filename);
	
	FILE* fin = fopen(filename, "r");
	
	fscanf(fin, "%d", &readIn);
	
	while(readIn != Q){
		if(readIn == N){
			strcpy(printThing, "\n");
		}else if(readIn == nX){
			strcpy(printThing, cX);
			xRow = row;
			xCol = col;
		}else if(readIn == S){
			strcpy(printThing, STR);
			fscanf(fin, "%d", &printNum);
		}else{
			//readIn is B
			strcpy(printThing, SP);
			fscanf(fin, "%d", &printNum);
		}
		
		for(int i = 0; i < printNum; i++){
			fprintf(stdout, "%s", printThing);
		}
		
		row++;
		col++;
		printNum = 1;
		fscanf(fin, "%d", &readIn);
	}
	
	fprintf(stdout, "The treasure is at row %i and col %i", xRow, xCol);
	
	
	fprintf(stdout, "\n");
	return 0;
}
