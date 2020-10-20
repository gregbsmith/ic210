/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
typedef char cstring[128];
int main(){
	double* numbers = calloc(1, sizeof(double));
	int size = 1;
	double read = 0;
	cstring readstr;
	
	while(scanf("%lg", &read)){
		//scanf("%lg", &read);
		numbers[size - 1] = read;
		size++;
		numbers = realloc(numbers, size * sizeof(double));
	}
	
	scanf("%s", readstr);
	
	if(strcmp(readstr, "below") == 0){
		for(int i = 0; i < size; i++){
			if(numbers[i] < 0){
				printf("%lg\n", numbers[i]);
			}
		}
	}else{
		for(int i = 0; i < size; i++){
			if(numbers[i] > 0){
				printf("%lg\n", numbers[i]);
			}
		}
	}
	
	free(numbers);
	
	return 0;
}
