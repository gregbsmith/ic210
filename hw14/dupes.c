/* Gregory Smith
 * 235952
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char cstring[128];

int dupes(double x, double y, double z);

int main(){
	
	double x = 0;
	double y = 0;
	double z = 0;
	int cont_ = 0;
	
	fputs("Enter three distinct numbers: ", stdout);
	fscanf(stdin, " %lg %lg %lg", &x, &y, &z);
	cont_ = dupes(x, y, z);
	while(cont_ != 0){
		fprintf(stdout, "Enter three distinct numbers: ");
		fscanf(stdin, " %lg %lg %lg", &x, &y, &z);
		cont_ = dupes(x, y, z);
	}
	
	//fputs("\n", stdout);
	return 0;
}

int dupes(double x, double y, double z){
	if(x == y && x == z && z == y){
		fputs("There were 3 duplicates. Try again.\n", stdout);
		return 3;
	}else if(x == y || x == z || z== y){
		fputs("There were 2 duplicates. Try again.\n", stdout);
		return 2;
	}
	return 0;
}
