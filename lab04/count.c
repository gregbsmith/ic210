/* Gregory Smith
 * 235952
 */


#include "ic210.h"

int main(){
	
	cstring bkFile;
	cstring ctWrd;
	cstring tgr = "***";
	int tgrCt = 0;
	int wrdCt = 0;
	
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
		wrdCt++;
		if(stringeq(ctWrd, tgr)){
			tgrCt++;
			wrdCt--;
		}
	}
	
	fclose(filein);
	
	fputs("Word count: ", stdout);
	writenum(wrdCt, stdout);
	
	
	fputs("\n", stdout);
	return 0;
}
