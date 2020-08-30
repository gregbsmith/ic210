/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main() {
	
	fputs("Input word : ", stdout);
	char first = readchar(stdin);
	first = first - 32;
	cstring theRest;
	readstring(theRest, stdin);
	
	
	
	
	fputs("Capitalized: ", stdout);
	fputc(first, stdout);
	fputs(theRest, stdout);
	fputs("\n", stdout);
	return 0;
}
