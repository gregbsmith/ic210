/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main(){
	
	cstring YES = "yes";
	cstring NO = "no";
	
	cstring SUPE = "supe";
	cstring BEATARMY = "beatarmy";
	cstring ROCHE = "bbq";
	cstring EMACS = "brisket";
	
	cstring uName;
	cstring uPass;
	
	fputs("Username: ", stdout);
	readstring(uName, stdin);
	fputs("Password: ", stdout);
	readstring(uPass, stdin);
	
	if((stringeq(uName, SUPE) && stringeq(uPass, BEATARMY)) || (stringeq(uName, ROCHE) && stringeq(uPass, EMACS))){
		fputs(YES, stdout);
	}else{
		fputs(NO, stdout);
	}
	
	fputs("\n", stdout);
	return 0;
}
