/* Gregory Smith
 * 235952
 * 
 */

#include "ic210.h"

int main() {
	
	char first = '0';
	char second = '0';
	char third = '0';
	char fourth = '0';
	int total = 0;
	
	fputs("Enter a 4-bit binary number: ", stdout);
	
	first = readchar(stdin);
	second = readchar(stdin);
	third = readchar(stdin);
	fourth = readchar(stdin);
	
	int fi = first - 48;
	int s = second - 48;
	int t = third - 48;
	int fo = fourth - 48;
	
	total = (8 * fi) + (4 * s) + (2 * t) + (fo);
	
	fputs("In decimal ", stdout);
	writenum(fi, stdout);
	writenum(s, stdout);
	writenum(t, stdout);
	writenum(fo, stdout);
	fputs(" = ", stdout);
	writenum(total, stdout);
	
	fputs("\n", stdout);
	return 0;
}
