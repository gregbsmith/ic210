/*	IC210 Lab 1
 * 	GREGORY SMITH 235952
 * 	I talked with Noah Garcia-Galan about this lab
 */

#include "ic210.h"

int main() {
	
	int i;
	
	for (i = 0; i < 4; i = i + 1){
		fputs("And then my heart with pleasure fills,\n", stdout);
		fputs("And dances with daffodils.\n \n", stdout);
	}
	
	fputs("I like 1 flower.\n", stdout);
	
	for (i = 2; i < 6; i = i + 1){
		fputs("I like ", stdout);
		writenum(i, stdout);
		fputs(" flowers.\n", stdout);
	}
	
	fputs("\nAnd then my heart with pleasure fills, and dances with daffodils.\n", stdout);
	
	
	return 0;

}
