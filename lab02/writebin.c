/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main() {
	
	int input = 0;
	int b1 = 0;
	int b2 = 0;
	int b3 = 0;
	int b4 = 0;
	
	fputs("Enter a number between 0 and 15: ", stdout);
	input = readnum(stdin);
	int input_save = input;
	
	b1 = input / 8;
	input = input % 8;
	
	b2 = input / 4;
	input = input % 4;
	
	b3 = input / 2;
	input = input % 2;
	
	b4 = input;
	
	writenum(input_save, stdout);
	fputs(" in binary is ", stdout);
	writenum(b1, stdout);
	writenum(b2, stdout);
	writenum(b3, stdout);
	writenum(b4, stdout);
	
	
	fputs("\n", stdout);
	return 0;
}
