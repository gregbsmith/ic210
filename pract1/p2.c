/* Gregory Smith
 * p2.c: flight times
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char cstring[128];

int main(){
	
	cstring filename;
	cstring fltNum;
	int deptHr = 0;
	int deptMin = 0;
	int arrHr = 0;
	int arrMin = 0;
	int ttlHrs = 0;
	int ttlMin = 0;
	int hiHrs = 0;
	int hiMin = 0;
	int loHrs = 999999999;
	int loMin = 999999999;
	cstring hiFltNum;
	cstring loFltNum;
	cstring END = "END";
	cstring trash;
	fprintf(stdout, "Filename: ");
	fscanf(stdin, " %s", filename);
	
	FILE* fin = fopen(filename, "r");
	
	if(!fin){
		fprintf(stdout, "File not found!\n");
		return 0;
	}
	
	//fscanf(fin, " %s %i%s%i - %i%s%i", hiFltNum, &deptHr, &deptMin, &arrHr, &arrMin);
	//fscanf(fin, "%s%d%s%d%s%d%s%i", hiFltNum, &deptHr, trash, &deptMin, trash, &arrHr, trash, &arrMin);
	fscanf(fin, " %s ", hiFltNum);
	fscanf(fin, "%d", &deptHr);
	fscanf(fin, ":");
	fscanf(fin, "%d", &deptMin);
	fscanf(fin, " - ");
	fscanf(fin, "%d", &arrHr);
	fscanf(fin, ":");
	fscanf(fin, "%d", &arrMin);

	
	
	if(arrMin < deptMin){
		arrMin = arrMin + 60;
	}
	
	if(arrHr < deptHr){
		arrHr = arrHr + 24;
	}
	
	hiHrs = arrHr - deptHr;
	hiMin = arrMin - deptMin;
	
	while(strcmp(fltNum, END)){
		
		fscanf(fin, " %s ", fltNum);
		fscanf(fin, "%d", &deptHr);
		fscanf(fin, ":");
		fscanf(fin, "%d", &deptMin);
		fscanf(fin, " - ");
		fscanf(fin, "%d", &arrHr);
		fscanf(fin, ":");
		fscanf(fin, "%d", &arrMin);
		
		if(arrMin < deptMin){
			arrMin = arrMin + 60;
		}
		
		if(arrHr < deptHr){
			arrHr = arrHr + 24;
		}
		ttlHrs = arrHr - deptHr;
		ttlMin = arrMin - deptMin;
		
		if((ttlHrs > hiHrs) ||
		((ttlHrs == hiHrs) && (ttlMin > hiMin))){
			hiHrs = ttlHrs;
			hiMin = ttlMin;
			strcpy(hiFltNum, fltNum);
		}else if((ttlHrs < loHrs) ||
		((ttlHrs == loHrs) && (ttlMin < loMin))){
			loHrs = ttlHrs;
			loMin = ttlMin;
			strcpy(loFltNum, fltNum);
		}
	}
	
	fprintf(stdout, "Longest: %s with %i hours and %i minutes\n",
			hiFltNum, hiHrs, hiMin);
	fprintf(stdout, "Shortest: %s with %i hours and %i minutes",
			loFltNum, loHrs, loMin);
	
	fprintf(stdout, "\n");
	return 0;
}
