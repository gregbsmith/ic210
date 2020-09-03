/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main(){
	int year = 0;
	bool leap = 0;
	//fputs("What is your favorite leap year? ", stdout);
	//year = readnum(stdin);
	
	while(!leap)
	{
		fputs("What is your favorite leap year? ", stdout);
		year = readnum(stdin);
		
		if(((year % 4 == 0) && (year % 100 != 0)) ||
			(year % 400 == 0))
		{
			fputs("Yes, ", stdout);
			writenum(year, stdout);
			fputs(" was a good year.", stdout);
			leap = true;
		}
		else
		{
			writenum(year, stdout);
			fputs(" is not a leap year!\n", stdout);
		}
	}
	
	fputs("\n", stdout);
	return 0;
}
