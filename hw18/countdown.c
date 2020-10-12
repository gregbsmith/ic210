// Gregory Smith
// countdown.c: function definitions

#include <stdio.h>

int countdown(int n){
	for(int i = n; i >= 1; i--){
		printf("%d\n", i);
	}
	printf("hooray!\n");
	return 0;
}
