/* Gregory Smith
 * 235952
 */

#include "ic210.h"
double conv2(cstring currency1, cstring currency2, double amnt);
int main(){
	
	cstring curr1;
	cstring curr2;
	cstring conjunction;
	cstring and_;
	cstring to_;
	cstring dollars = "Dollars";
	cstring us = "US";
	cstring canadian = "Canadian";
	cstring yen = "Yen";
	cstring euros = "Euros";
	double amnt1 = 0;
	double amnt2 = 0;
	double new_amnt = 0;
	
	readstring(curr1, stdin);
	amnt1 = readnum(stdin);
	readstring(curr1, stdin);
	if(stringeq(curr1, dollars))
	{
		readstring(curr1, stdin);
	}
	readstring(conjunction, stdin);
	if(stringeq(conjunction, to_))
	{
		readstring(curr2, stdin);
		if(stringeq(curr2, dollars))
		{
			readstring(curr2, stdin);
		}
		
		new_amnt = conv2(curr1, curr2, amnt1);
		writenum(new_amnt, stdout);
		fputs("\n", stdout);
		return 0;
	}
	else
	{
		double amnt3 = 0;
		cstring curr3;
		amnt2 = readnum(stdin);
		readstring(curr2, stdin);
		if(stringeq(curr2, dollars))
		{
			readstring(curr2, stdin);
		}
		readstring(conjunction, stdin);
		if(stringeq(conjunction, and_))
		{
			amnt3 = readnum(stdin);
			readstring(curr3, stdin);
			if(stringeq(curr3, dollars))
			{
				(curr3, stdin);
			}
		}
		
		return 0;
	}
	/*
	double conv2(cstring currency1, cstring currency2, double amnt)
	{
		double EUROS_PER_DOLLAR = .84;
		double YEN_PER_DOLLAR = 105.36;
		double CANADIANS_PER_DOLLAR = 1.31;
		// double EUROS_PER_YEN = EUROS_PER_DOLLAR / YEN_PER_DOLLAR;
		cstring dollars = "Dollars";
		cstring us = "US";
		cstring canadian = "Canadian";
		cstring yen = "Yen";
		cstring euros = "Euros";
		//cstring currency1;
		//cstring currency2;
		//double amnt = 0;
		double new_amnt = 0;
		
	
	
		
		
		//converting us to...
		if(stringeq(currency1, us))
		{
			//converting us to...
		
			//euros:
			if(stringeq(currency2, euros))
			{
				new_amnt = amnt * EUROS_PER_DOLLAR;
				return new_amnt;
			}
			//yen:
			else if(stringeq(currency2, yen))
			{
				//yen:
				new_amnt = amnt * YEN_PER_DOLLAR;
				return new_amnt;
			}
			//canadians:
			else
			{
				//canadians:
				new_amnt = amnt * CANADIANS_PER_DOLLAR;
				return new_amnt;
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
				return new_amnt;
			}
			//us:
			else if(stringeq(currency2, us))
			{
				//us:
				new_amnt = amnt / YEN_PER_DOLLAR;
				return new_amnt;
			}
			//canadians:
			else
			{
				//canadians
				new_amnt = amnt / YEN_PER_DOLLAR;
				new_amnt = new_amnt * CANADIANS_PER_DOLLAR;
				return new_amnt;
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
				return new_amnt;
			}
			//us:
			else if(stringeq(currency2, us))
			{
				//us:
				new_amnt = amnt / EUROS_PER_DOLLAR;
				return new_amnt;
			}
			//canadians:
			else
			{
				new_amnt = amnt / EUROS_PER_DOLLAR;
				new_amnt = new_amnt * CANADIANS_PER_DOLLAR;
				return new_amnt;
			}
		
		}
		//converting canadians to...
		else
		{
			//us:
			if(stringeq(currency1, us))
			{
				new_amnt = amnt / CANADIANS_PER_DOLLAR;
				return new_amnt;
			
			}
			//euros:
			else if(stringeq(currency1, euros))
			{
				new_amnt = amnt / CANADIANS_PER_DOLLAR;
				new_amnt = new_amnt * EUROS_PER_DOLLAR;
				return new_amnt;
			}
			//yen:
			else
			{
				new_amnt = amnt / CANADIANS_PER_DOLLAR;
				new_amnt = new_amnt * YEN_PER_DOLLAR;
				return new_amnt;
			}
		}
	}*/
}

double conv2(cstring currency1, cstring currency2, double amnt)
{
	double EUROS_PER_DOLLAR = .84;
	double YEN_PER_DOLLAR = 105.36;
	double CANADIANS_PER_DOLLAR = 1.31;
	// double EUROS_PER_YEN = EUROS_PER_DOLLAR / YEN_PER_DOLLAR;
	cstring dollars = "Dollars";
	cstring us = "US";
	cstring canadian = "Canadian";
	cstring yen = "Yen";
	cstring euros = "Euros";
	//cstring currency1;
	//cstring currency2;
	//double amnt = 0;
	double new_amnt = 0;
	


	
	
	//converting us to...
	if(stringeq(currency1, us))
	{
		//converting us to...
	
		//euros:
		if(stringeq(currency2, euros))
		{
			new_amnt = amnt * EUROS_PER_DOLLAR;
			return new_amnt;
		}
		//yen:
		else if(stringeq(currency2, yen))
		{
			//yen:
			new_amnt = amnt * YEN_PER_DOLLAR;
			return new_amnt;
		}
		//canadians:
		else
		{
			//canadians:
			new_amnt = amnt * CANADIANS_PER_DOLLAR;
			return new_amnt;
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
			return new_amnt;
		}
		//us:
		else if(stringeq(currency2, us))
		{
			//us:
			new_amnt = amnt / YEN_PER_DOLLAR;
			return new_amnt;
		}
		//canadians:
		else
		{
			//canadians
			new_amnt = amnt / YEN_PER_DOLLAR;
			new_amnt = new_amnt * CANADIANS_PER_DOLLAR;
			return new_amnt;
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
			return new_amnt;
		}
		//us:
		else if(stringeq(currency2, us))
		{
			//us:
			new_amnt = amnt / EUROS_PER_DOLLAR;
			return new_amnt;
		}
		//canadians:
		else
		{
			new_amnt = amnt / EUROS_PER_DOLLAR;
			new_amnt = new_amnt * CANADIANS_PER_DOLLAR;
			return new_amnt;
		}
	
	}
	//converting canadians to...
	else
	{
		//us:
		if(stringeq(currency1, us))
		{
			new_amnt = amnt / CANADIANS_PER_DOLLAR;
			return new_amnt;
		
		}
		//euros:
		else if(stringeq(currency1, euros))
		{
			new_amnt = amnt / CANADIANS_PER_DOLLAR;
			new_amnt = new_amnt * EUROS_PER_DOLLAR;
			return new_amnt;
		}
		//yen:
		else
		{
			new_amnt = amnt / CANADIANS_PER_DOLLAR;
			new_amnt = new_amnt * YEN_PER_DOLLAR;
			return new_amnt;
		}
	}
}
