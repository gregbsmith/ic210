/* Gregory Smith
 * 
 */

#include "ic210.h"

int main(){
	
	cstring file;
	double income = 0;
	
	cstring NOT_U = "% This is not you!\n";
	cstring IS_U = "% This is you! You owe $";
	
	double perc = 0;
	double oldPerc = 0;
	double lower = 0;
	double upper = 0;
	double tax = 0;
	
	
	fscanf(stdin, "%s $%lg", file, &income);
	//fputs(file, stdout);
	//writenum(income, stdout);
	
	stream fin = fopen(file, "r");
	if(!fin){
		fputs("File not found!\n", stdout);
		return 0;
	}
	
	
	while(!feof(fin)){
		fscanf(fin, "%lg%%	$%lg to $%lg", &perc, &lower, &upper);
		if(perc == oldPerc)
			return 0;
		writenum(perc, stdout);
		if(income >= lower &&
			income <= upper){
				tax = (perc / 100) * income;
				fputs(IS_U, stdout);
				writenum(tax, stdout);
				fputs("\n", stdout);
			}else{
				fputs(NOT_U, stdout);
			}
			oldPerc = perc;
	}
	
	return 0;
}
