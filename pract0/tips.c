/* Gregory Smith
 * 
 */

#include "ic210.h"

int main(){
	
	cstring cmd;
	char trash;
	double tip = 0;
	cstring CALC = "calc";
	cstring TEST = "test";
	
	cstring SPLIT = "split";
	
	double bill = 0;
	
	fscanf(stdin, "%s", cmd);
	for(int i = 0; i < 2; i++)
		fscanf(stdin, "%c", &trash);
	
	
	//fputs(cmd, stdout);
	//fputc(trash, stdout);
	
	bill = readnum(stdin);
	
	if(stringeq(cmd, TEST)){
		cstring trshstr;
		double payAmnt = 0;
		readstring(trshstr, stdin);
		for(int i = 0; i < 2; i++)
			fscanf(stdin, "%c", &trash);
		payAmnt = readnum(stdin);
		//writenum(payAmnt, stdout);
		tip = payAmnt - bill;
		tip = tip / bill;
		tip = tip * 100;
		fprintf(stdout, "tip %g%%", tip);
	}else{
		cstring splitortip;
		readstring(splitortip, stdin);
		if(stringeq(splitortip, SPLIT)){
			//split
			cstring trshstr;
			int splitWays = 0;
			splitWays = readnum(stdin);
			for(int i = 0; i < 2; i++)
				readstring(trshstr, stdin);
			tip = readnum(stdin);
			tip = tip / 100;
			tip = tip * bill;
			tip = tip + bill;
			tip = tip / splitWays;
			fprintf(stdout, "pay $%g", tip);
		}else{
			//tip
			tip = readnum(stdin);
			tip = tip / 100;
			tip = tip * bill;
			tip = tip + bill;
			fprintf(stdout, "pay $%g", tip);
		}
	}
	
	fputs("\n", stdout);
	return 0;
}
