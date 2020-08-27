/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main() {
	double fields = 0;
	int miles = 0;
	int feet = 0;
	double inches = 0;
	
	fputs("How many football fields? ", stdout);
	fields = readnum(stdin);
	
	miles = (int) ( ( fields * 300) / 5280 );
	feet = (int) ( ( fields * 300 ) - ( miles * 5280) );
	inches = ((fields * 300) - (miles * 5280) - (feet)) * 12;
	
	writenum(miles, stdout);
	fputs(" miles ", stdout);
	
	writenum(feet, stdout);
	fputs(" feet ", stdout);
	
	writenum(inches, stdout);
	fputs(" inches", stdout);
	
	fputs("\n", stdout);
	return 0;
	
}
	
