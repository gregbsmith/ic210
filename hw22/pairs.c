/* pairs.c: Read in x and y values and pair them up.
 * Gregory Smith
 */

#include "stdio.h"
#include "string.h"
#include "stdbool.h"

typedef char cstring[128];

int main(){
	int N = 0;
	printf("N: ");
	scanf("%d", &N);
	double x[N];
	double y[N];
	
	printf("x values: ");
	for(int i = 0; i < N; i++){
		scanf("%lg", &x[i]);
	}
	
	printf("y values: ");
	for(int i = 0; i < N; i++){
		scanf("%lg", &y[i]);
	}
	
	for(int i = 0; i < N; i++){
		printf("(%lg,%lg) ", x[i], y[i]);
	}
	
	printf("\n");
	
	return 0;
}
