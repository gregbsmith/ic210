/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main(){
	cstring grFile;
	fputs("Filename: ", stdout);
	readstring(grFile, stdin);
	
	cstring hiName;
	double hiGrade = 0;
	
	cstring nName;
	double nGrade = 0;
	int header = 0;
	double hw = 0;
	double quiz = 0;
	double exam = 0;
	
	stream filein = fopen(grFile, "r");
	header = readnum(filein);
	
	for(int i = 0; i < 4; i++){
		readstring(nName, filein);
	}
	
	for(int i = 0; i < header; i++){
		readstring(nName, filein);
		hw = readnum(filein);
		quiz = readnum(filein);
		exam = readnum(filein);
		nGrade = (.2 * hw) + (.2 * quiz) + (.6 * exam);
		if(nGrade > hiGrade){
			hiGrade = nGrade;
			strcpy(hiName, nName);
		}
	}
	
	fclose(filein);
	
	fputs(hiName, stdout);
	fputs(" has the highest grade of ", stdout);
	writenum(hiGrade, stdout);
	
	fputs("\n", stdout);
	return 0;
}
