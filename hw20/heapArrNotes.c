/* Gregory Smith
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
typedef char cstring[128];

int main(){
	cstring read;
	cstring convstr;
	int most = 0;
	scanf("%s", read);
	strcpy(convstr, read);
	while(strcmp(read, "DONE") != 0){
		int len = strlen(read);
		int conv = 0;
		for(int i = 0; i < len; i++){
			if(read[i] == 'a'){
				read[i] = '@';
				conv++;
			}else if(read[i] == 'e'){
				read[i] = '3';
				conv++;
			}else if(read[i] == 'i'){
				read[i] = '!';
				conv++;
			}else if(read[i] == 't'){
				read[i] = '+';
				conv++;
			}
			
		}
		
		if(conv > most){
			most = conv;
			strcpy(convstr, read);
		}
		scanf("%s", read);
	}
	
	printf("%d conversions for \"%s\"\n", most, convstr);
}
