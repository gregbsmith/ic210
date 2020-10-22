/* substring.c: Read two strings and determine whether one contains the other.
 * Gregory Smith
 */
#include "string.h"
#include "stdio.h"
#include "stdbool.h"
typedef char cstring[128];

bool match(cstring target, cstring test, int offset);

int main(){
	bool have_match = false;
	printf("Target: ");
	cstring target;
	scanf("%s", target);
	printf("Test: ");
	cstring test;
	scanf("%s", test);
	
	for(int i = 0; i < strlen(test); i++){
		if(test[i] == target[0] && strlen(test) - i >= strlen(target)){
			have_match = match(target, test, i);
		}
		if(have_match){
			printf("yes\n");
			return 0;
		}
	}
	printf("no\n");
	
	return 0;
}

bool match(cstring target, cstring test, int offset){
	for(int i = 0; i < strlen(target); i++){
		if(target[i] != test[offset + i]){
			return false;
		}
	}
	return true;
}
