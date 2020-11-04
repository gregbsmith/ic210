/* battle.c
 * Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "unistd.h"

typedef char cstring[128];

int play(char** map, int x1, int x2, int y1, int y2, int rows, int columns);

int main() {
	cstring board;
	printf("Filename: ");
	scanf("%s", board);
	FILE* fin = fopen(board, "r");
	int rows = 0;
	int columns = 0;
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	
	fscanf(fin, "%d rows %d columns\n", &rows, &columns);
	fscanf(fin, "(%d,%d)\n", &x1, &y1);
	fscanf(fin, "(%d,%d)\n", &x2, &y2);
	// printf("%d %d %d %d %d %d\n", rows, columns, x1, y1, x2, y2);
	
	char** map = calloc(rows, sizeof(char*));
	for(int i = 0; i < rows; i++) {
		map[i] = calloc(columns, sizeof(char));
	}
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			map[i][j] = '?';
		}
	}
	printf("\n");
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	int rounds = 0;
	int subs = 2;
	
	bool hit = false;
	
	while(subs) {
		printf("Target: ");
		
		// fflush(stdin);
		int guessx = 0;
		int guessy = 0;
		scanf("\n(%d,%d)", &guessx, &guessy);
		
			if(guessx == x1 && guessy == y1) {
				hit = true;
				x1 = x2;
				y1 = y2;
				subs--;
			}else if(guessx == x2 && guessy == y2) {
				hit = true;
				x2 = x1;
				y2 = y1;
				subs--;
			}else {
				hit = false;
			}
			if(hit) {
				map[guessx][guessy] = 'X';
				printf("Hit!\n\n");
			}else {
				map[guessx][guessy] = '.';
				printf("Miss!\n\n");
			}
			rounds++;
			for(int i = 0; i < rows; i++) {
				for(int j = 0; j < columns; j++) {
					printf("%c", map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		
	}
	
	// int rounds = play(map, x1, y1, x2, y2, rows, columns);
	printf("Sunk in %d rounds\n", rounds);
	
	
	for(int i = 0; i < rows; i++) {
		free(map[i]);
	}
	free(map);
	fclose(fin);
	return 0;
	/*
	 * got a segmentation fault on this :/
	char brd[4][10];
	for(int i = 0; i < 4; i++) {
		for(int j = 0; i < 10; j++) {
			brd[i][j] = '?';
		}
	}
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j <10; j++) {
			printf("%c", brd[i][j]);
		}
		printf("\n");
	}
	*/
}

int play(char** map, int x1, int x2, int y1, int y2, int rows, int columns) {
	int rounds = 0;
	int subs = 2;
	
	bool hit = false;
	
	while(subs) {
		printf("Target: ");
		//fflush(stdin);
		int guessx = 0;
		int guessy = 0;
		scanf("\n(%d,%d)", &guessx, &guessy);
		
			if(guessx == x1 && guessy == y1) {
				hit = true;
				x1 = x2;
				y1 = y2;
				subs--;
			}else if(guessx == x2 && guessy == y2) {
				hit = true;
				x2 = x1;
				y2 = y1;
				subs--;
			}else {
				hit = false;
			}
			if(hit) {
				map[guessx][guessy] = 'X';
				printf("Hit!\n");
			}else {
				map[guessx][guessy] = '.';
				printf("Miss!\n");
			}
			rounds++;
			for(int i = 0; i < rows; i++) {
				for(int j = 0; j < columns; j++) {
					printf("%c", map[i][j]);
				}
				printf("\n");
			}
		
	}
	
	
	return rounds;
}
