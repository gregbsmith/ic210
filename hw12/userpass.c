/* Gregory Smith
 * 235952
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char cstring[128];

int main(){
	
	cstring YES = "yes";
	cstring NO = "no";
	
	cstring SUPE = "supe";
	cstring BEATARMY = "beatarmy";
	cstring BBQ = "bbq";
	cstring BRISKET = "brisket";
	
	cstring uName;
	cstring uPass;
	
	fputs("Username: ", stdout);
	fscanf(stdin, "%s",uName);
	fputs("Password: ", stdout);
	fscanf(stdin, "%s", uPass);
	
	if((strcmp(uName, SUPE) == 0 && strcmp(uPass, BEATARMY) == 0) ||
		(strcmp(uName, BBQ) == 0 && strcmp(uPass, BRISKET) == 0)){
		fputs(YES, stdout);
	}else{
		fputs(NO, stdout);
	}
	
	fputs("\n", stdout);
	return 0;
}
