/* Gregory Smith
 */
 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef char cstring[128];

bool before(int a, int b);
bool isOrdered(int* arr, int size);
void sort(int* arr, int size);

int main() {
	
	int nums[10];
	for(int i = 0; i < 10; i++) {
		scanf("%d", &nums[i]);
	}
	
	int numOdds = 0;
	int numEvens = 0;
	
	for(int i = 0; i < 10; i++) {
		if(nums[i] % 2) {
			numOdds++;
		}else {
			numEvens++;
		}
	}
	
	int odds[numOdds];
	int evens[numEvens];
	
	int oddIndex = 0;
	int evenIndex = 0;
	
	for(int i = 0; i < 10; i++) {
		if(nums[i] % 2) {
			odds[oddIndex] = nums[i];
			oddIndex++;
		}else {
			evens[evenIndex] = nums[i];
			evenIndex++;
		}
	}
	
	sort(evens, numEvens);
	sort(odds, numOdds);
	
	for(int i = 0; i < numOdds; i++) {
		printf("%d ", odds[i]);
	}
	for(int i = 0; i < numEvens; i++) {
		printf("%d ", evens[i]);
	}
	printf("\n");
	
	return 0;
}


void sort(int* arr, int size) {
	bool order = isOrdered(arr, size);
	while(!order) {
		for(int i = 0; i < size - 1; i++) {
			if(before(arr[i + 1], arr[i])) {
				int sto = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = sto;
			}
		}
		order = isOrdered(arr, size);
	}
}

bool before (int a, int b) {
	if(a < b) {
		return true;
	}else {
		return false;
	}
}

bool isOrdered(int* arr, int size) {
	bool inorder = true;
	
	for(int i = 0; i < size - 1; i++) {
		if(before(arr[i + 1], arr[i])) {
			inorder = false;
		}
	}
	
	return inorder;
}
