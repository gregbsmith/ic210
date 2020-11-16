/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef char cstring[128];

typedef struct{
	cstring fname;
	cstring lname;
	int score;
} Player;

void swap(Player* pa, Player* pb);
void selection_sort(Player* data, int size);
bool before(Player a, Player b);

int main() {
	printf("filename: ");
	cstring file;
	scanf("%s", file);
	
	FILE* fin = fopen(file, "r");
	int distinct = 0;
	int entries = 0;
	fscanf(fin, " %d\n", &entries);
	Player list[entries];
	
	for(int i = 0; i < entries; i++) {
		fscanf(fin, " %s %s %d\n", list[i].fname, list[i].lname,
								   &list[i].score);
	}
	fclose(fin);
	
	selection_sort(list, entries);
	
	for(int i = 0; i < entries - 1; i++) {
		if(strcmp(list[i].fname, list[i + 1].fname) ||
		   strcmp(list[i].lname, list[i + 1].lname)) {
			distinct++;
		}
	}
	
	Player distlist[distinct];
	
	int distind = 1;
	distlist[0] = list[0];
	for(int i = 0; i < entries - 1; i++) {
		if(strcmp(list[i].fname, list[i + 1].fname) != 0 ||
		   strcmp(list[i].lname, list[i + 1].lname) != 0 ) {
			distlist[distind] = list[i + 1];
			distind++;
		}
	}
	
	for(int i = 0; i <= distinct; i++) {
		printf("%s %s %d\n", distlist[i].fname, distlist[i].lname,
							 distlist[i].score);
	}
	
	return 0;
}

bool before(Player a, Player b) {
	if((strcmp(a.lname, b.lname) < 0) ||
	   (strcmp(a.lname, b.lname) == 0 && strcmp(a.fname, b.fname) < 0)
	  ) {
		return true;
	}else if(!strcmp(a.lname, b.lname) && !strcmp(a.fname, b.fname)) {
		return a.score > b.score;
	}else {
		return false;
	}
}

void selection_sort(Player* data, int size) {
	for(int i = 0; i < size - 1; i++) {
		int nexti = i;
		for(int j = i + 1; j < size; j++) {
			if(before(data[j], data[nexti])) {
				nexti = j;
			}
		}
		swap(&data[i], &data[nexti]);
	}
}

void swap(Player* pa, Player* pb) {
	Player a = *pa;
	*pa = *pb;
	*pb = a;
}
