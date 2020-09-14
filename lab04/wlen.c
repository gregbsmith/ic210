/* Gregory Smith
 * 235952
 */


#include "ic210.h"

int main(){
	
	cstring bkFile;
	cstring ctWrd;
	cstring tgr = "***";
	int tgrCt = 0;
	double wrdCt = 0;
	double ttlWlen = 0;
	double avWlen = 0;
	
	fputs("Enter a filename: ", stdout);
	readstring(bkFile, stdin);
	
	stream filein = fopen(bkFile, "r");
	
	while(tgrCt < 2){
		readstring(ctWrd, filein);
		if(stringeq(ctWrd, tgr)){
			tgrCt++;
		}
	}
	
	while(tgrCt < 3){
		readstring(ctWrd, filein);
		wrdCt = wrdCt + 1.0;
		if(stringeq(ctWrd, tgr)){
			tgrCt++;
			wrdCt = wrdCt - 1.0;
		}
		else{
			ttlWlen += strlen(ctWrd);
		}
	}
	
	fclose(filein);
	

	avWlen = ttlWlen / wrdCt;
	
	fputs("Average word length: ", stdout);
	writenum(avWlen, stdout);
	
	
	fputs("\n", stdout);
	return 0;
}
