/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main(){
	
	double EUROS_PER_DOLLAR = .84;
	double YEN_PER_DOLLAR = 105.36;
	double EUROS_PER_YEN = EUROS_PER_DOLLAR / YEN_PER_DOLLAR;
	cstring dollars = "Dollars";
	cstring yen = "Yen";
	cstring euros = "Euros";
	cstring currency1;
	cstring currency2;
	double amnt = 0;
	double new_amnt = 0;
	readstring(currency1, stdin);
	
	
	amnt = readnum(stdin);
	readstring(currency1, stdin);
	readstring(currency2, stdin);
	
	if(stringeq(currency1, dollars))
	{
		//converting dollars to...
		
		//euros:
		if(stringeq(currency2, euros))
		{
			new_amnt = amnt * EUROS_PER_DOLLAR;
		}
		else
		{
			//yen:
			new_amnt = amnt * YEN_PER_DOLLAR;
		}
		
		
	}
	else if(stringeq(currency1, yen))
	{
		//converting yen to...
		
		//euros:
		if(stringeq(currency2, euros))
		{
			new_amnt = amnt * EUROS_PER_YEN;
		}
		else
		{
			//dollars:
			new_amnt = amnt / YEN_PER_DOLLAR;
		}
		
	}
	else
	{
		//converting euros to...
		
		//yen:
		if(stringeq(currency2, yen))
		{
			new_amnt = amnt / EUROS_PER_YEN;
		}
		else
		{
			//dollars:
			new_amnt = amnt / EUROS_PER_DOLLAR;
		}
		
	}
	
	writenum(new_amnt, stdout);
	fputs("\n", stdout);
	return 0;
}
