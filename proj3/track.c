/* track.c: GPS tracks program main program
 * Gregory Smith
 * This is where you will write your main() for the entire project.
 */

#define _XOPEN_SOURCE
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "gps.h"

typedef struct {
	time_t time;
	struct gpsco coor;
}Waypoint;

typedef struct Node {
	Waypoint data;
	struct Node* next;
}Node;

typedef char cstring[128];

// returns pointer to link list with new node @ front
Node* add2front(Waypoint w, Node* oldlist);

void cmd(cstring c, Node* L);

int main() {
	
	cstring file;
	printf("File: ");
	scanf(" %s", file);
	Node* L = NULL;
	
	FILE* fin = fopen(file, "r");
	
	if(!fin) {
		printf("Error: %s not found.\n", file);
		return 1;
	}
	
	printf("Opened %s with ", file);
	
	bool gpx = 0;
	int fnlen = strlen(file);
	if(file[fnlen - 4] == '.' && file[fnlen - 3] == 'g' &&
	file[fnlen - 2] == 'p' && file[fnlen - 1] == 'x') {
		gpx = 1;
	}
	
	if(gpx) {
		printf("it's a gpx\n");
	}else {
		
		int num_points = 0;
		fscanf(fin, " %d", &num_points);
		printf("%d waypoints\n", num_points);
		
		Waypoint w_cur;
		double lat_cur;
		double long_cur;
		struct tm tm_cur;
		
		while(fscanf(fin, " %lg %lg", &lat_cur, &long_cur) == 2) {
			// printf("While loop starts\n");
			
			fscanf(fin, " 20%d-%d-%d %d:%d:%d", &tm_cur.tm_year,
			&tm_cur.tm_mon, &tm_cur.tm_mday, &tm_cur.tm_hour,
			&tm_cur.tm_min, &tm_cur.tm_sec);
			
			tm_cur.tm_mon --;
			tm_cur.tm_year += 100;
			tm_cur.tm_isdst = 0;
			w_cur.time = mktime(&tm_cur);
			w_cur.coor = make_gps(lat_cur, long_cur);
			L = add2front(w_cur, L);
		}
	}
	
	cstring command;
	printf("command: ");
	scanf(" %s", command);
	
	while(strcmp(command, "quit")) {
		cmd(command, L);
		printf("command: ");
		scanf(" %s", command);
	}
	
	free(L);
	fclose(fin);
	return 0;
}

Node* add2front(Waypoint w, Node* oldlist) {
	Node* temp = calloc(1, sizeof(Node));
	temp->data = w;
	temp->next = oldlist;
	return temp;
}

void cmd(cstring c, Node* L) {
	if(!strcmp(c, "stats")) {
		printf("stats\n");
	}else if(!strcmp(c, "landmarks")) {
		printf("landmarks\n");
	}else if(!strcmp(c, "fastest")) {
		printf("fastest\n");
	}else if(!strcmp(c, "linked")) {
		printf("yes\n");
	}else if(!strcmp(c, "visual")) {
		printf("visual\n");
	}
	
	return;
}
