/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef char cstring[128];


int main() {
	
	int N = 0;
	int magic_num = 0;
	int run_sum = 0;
	bool is_magic = true;
	
	printf("size: ");
	scanf("%d", &N);
	
	int square[N][N];
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &square[i][j]);
		}
	}
	
	for(int i = 0; i < N; i++) {
		magic_num += square[0][i];
	}
	
	run_sum = 0;
	for(int i = 0; i < N; i++) {
		run_sum = 0;
		for(int j = 0; j < N; j++) {
			run_sum += square[i][j];
		}
		if(run_sum != magic_num) {
			is_magic = false;
		}
	}
	
	run_sum = 0;
	
	for(int i = 0; i < N; i++) {
		run_sum = 0;
		for(int j = 0; j < N; j++) {
			run_sum += square[j][i];
		}
		if(run_sum != magic_num) {
			is_magic = false;
		}
	}
	
	run_sum = 0;
	for(int i = 0; i < N; i++) {
		run_sum += square[i][i];
	}
	if(run_sum != magic_num) {
		is_magic = false;
	}
	
	run_sum = 0;
	for(int i = N; i > 0; i--) {
		for(int j = 0; j < N; j++) {
			if(j == N - i) {
				run_sum += square[i - 1][i - 1];
			}
		}
	}
	if(run_sum != magic_num) {
		is_magic = false;
	}
	
	if(is_magic) {
		printf("All sums equal %d\n", magic_num);
	}else {
		printf("Not magic\n");
	}
	
	
	/*
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d\n", square[i][j]);
		}
	}
	*/
	
	return 0;
}

