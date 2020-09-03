/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main(){
	
	double EUROS_PER_DOLLAR = .84;
	double YEN_PER_DOLLAR = 105.36;
	double CANADIANS_PER_DOLLAR = 1.31;
	// double EUROS_PER_YEN = EUROS_PER_DOLLAR / YEN_PER_DOLLAR;
	cstring dollars = "Dollars";
	cstring us = "US";
	cstring canadian = "Canadian";
	cstring yen = "Yen";
	cstring euros = "Euros";
	cstring currency1;
	cstring currency2;
	double amnt = 0;
	double new_amnt = 0;
	readstring(currency1, stdin);
	
	
	amnt = readnum(stdin);
	readstring(currency1, stdin);
	if(stringeq(currency1, dollars))
	{
		readstring(currency1, stdin);
	}
	readstring(currency2, stdin);
	readstring(currency2, stdin);
	if(stringeq(currency2, dollars))
	{
		readstring(currency2, stdin);
	}
	if(stringeq(currency1, currency2))
	{
		writenum(amnt, stdout);
		fputs("\n", stdout);
		return 0;
	}
	
	//converting us to...
	if(stringeq(currency1, us))
	{
		//converting us to...
		
		//euros:
		if(stringeq(currency2, euros))
		{
			new_amnt = amnt * EUROS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		//yen:
		else if(stringeq(currency2, yen))
		{
			//yen:
			new_amnt = amnt * YEN_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		//canadians:
		else
		{
			//canadians:
			new_amnt = amnt * CANADIANS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		
		
	}
	//converting yen to...
	else if(stringeq(currency1, yen))
	{
		//converting yen to...
		
		//euros:
		if(stringeq(currency2, euros))
		{
			new_amnt = amnt / YEN_PER_DOLLAR;
			new_amnt = new_amnt * EUROS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		//us:
		else if(stringeq(currency2, us))
		{
			//us:
			new_amnt = amnt / YEN_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		//canadians:
		else
		{
			//canadians
			new_amnt = amnt / YEN_PER_DOLLAR;
			new_amnt = new_amnt * CANADIANS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		
	}
	//converting euros to...
	else if(stringeq(currency1, euros))
	{
		//converting euros to...
		
		//yen:
		if(stringeq(currency2, yen))
		{
			new_amnt = amnt / EUROS_PER_DOLLAR;
			new_amnt = new_amnt * YEN_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		//us:
		else if(stringeq(currency2, us))
		{
			//us:
			new_amnt = amnt / EUROS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		//canadians:
		else
		{
			new_amnt = amnt / EUROS_PER_DOLLAR;
			new_amnt = new_amnt * CANADIANS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		
	}
	//converting canadians to...
	else
	{
		//us:
		if(stringeq(currency1, us))
		{
			new_amnt = amnt / CANADIANS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
			
		}
		//euros:
		else if(stringeq(currency1, euros))
		{
			new_amnt = amnt / CANADIANS_PER_DOLLAR;
			new_amnt = new_amnt * EUROS_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
		//yen:
		else
		{
			new_amnt = amnt / CANADIANS_PER_DOLLAR;
			new_amnt = new_amnt * YEN_PER_DOLLAR;
			writenum(new_amnt, stdout);
			fputs("\n", stdout);
			return 0;
		}
	}
	writenum(new_amnt, stdout);
	fputs("\n", stdout);
	return 0;
}
