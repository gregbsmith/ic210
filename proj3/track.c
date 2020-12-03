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
#include <gtk/gtk.h> // #include statement from gtkexample.c
#include <libxml/parser.h> // #include statement from xmlexample.c
#include "gps.h"

typedef char cstring[128];

typedef struct {
	cstring name;
	struct gpsco coor;
	double shortest_distance;
}Landmark;

typedef struct {
	time_t time;
	struct gpsco coor;
}Waypoint;

typedef struct Node {
	Waypoint data;
	struct Node* next;
}Node;

// the struct definition of Point and the prototypes of activate
// and on_draw_event are from the gtkexample.c file
typedef struct {
  int x;
  int y;
} Point;

// visual is the function called by cmd when "visual" is entered
// into the terminal
void visual(Node* L, int numpts);

// called by cmd when "landmarks" is entered
void landmarks(Node* L, int numpts);

// returns pointer to link list with new node @ front
Node* add2front(Waypoint w, Node* oldlist);

void cmd(cstring c, Node* L, int numpts);

void stats(Node* L);

/* This is the function that opens the window once GTK starts up.
 		from gtkexample.c*/
void activate (GtkApplication* app, gpointer user_data);

/* This is the function that actually draws the lines (or anything else).
 * It gets called when the window is displayed to the user. from gtkexample.c */
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

int main() {

	cstring file;
	printf("File: ");
	scanf(" %s", file);
	Node* L = NULL;
	int num_points = 0;

	bool gpx = 0;
	int fnlen = strlen(file);
	if(file[fnlen - 4] == '.' && file[fnlen - 3] == 'g' &&
	file[fnlen - 2] == 'p' && file[fnlen - 1] == 'x') {
		gpx = 1;
	}

	if(gpx) {
		// printf("it's a gpx\n");
		xmlDoc* fin = xmlReadFile(file, NULL, 0);

		if(!fin) {
			printf("Error: %s not found.\n", file);
			return 1;
		}
		printf("Opened %s with ", file);

		xmlNode* root = xmlDocGetRootElement(fin);
		xmlNode* child = root->children->next;
		while(strcmp("trk", (char*)child->name)) {
			child = child->next;
		}
		// printf("\nshould say trk: %s\n", (char*)child->name);

		child = child->children->next;

		while(strcmp("trkseg", (char*)child->name)) {
			child = child->next;
		}
		// printf("\nshould say trkseg: %s\n", (char*)child->name);

		xmlNode* trkseg = child;

		// printf("\nshould say trkseg: %s\n", (char*)trkseg->name);

		xmlNode* trkpt = trkseg->children->next;

		while(trkpt != NULL && !strcmp("trkpt", (char*)trkpt->name)) {
			xmlAttr* lat = trkpt->properties;
			xmlAttr* lon = trkpt->properties->next;
			// printf("\n%s %s \n", (char*)lat->children->content, (char*)lon->children->content);
			cstring lat_str;
			strcpy(lat_str, (char*)lat->children->content);
			cstring lon_str;
			strcpy(lon_str, (char*)lon->children->content);
			double latitude = 0;
			double longitude = 0;
			sscanf(lat_str, "%lg", &latitude);
			sscanf(lon_str, "%lg", &longitude);
			// printf("\n%lg\n%lg\n", latitude, longitude);

			xmlNode* x_time = trkpt->children->next;
			while(strcmp("time", (char*)x_time->name)) {
				x_time = x_time->next;
			}
			// printf("\nshould say time: %s\n", (char*)x_time->name);
			cstring time_str = "";
			strcpy(time_str, (char*)x_time->children->content);
			//printf("\n%s\n", time_str);

			Waypoint w_cur;
			struct tm tm_cur;

			// 2016-09-16T20:01:03Z
			strptime(time_str, "%Y-%m-%eT%H:%M:%SZ", &tm_cur);
			tm_cur.tm_isdst = 0;

			w_cur.time = mktime(&tm_cur);
			// printf("\n%d\n", (int)w_cur.time);
			w_cur.coor = make_gps(latitude, longitude);
			L = add2front(w_cur, L);


			trkpt = trkpt->next->next;
			num_points++;
		}

		printf("%d waypoints\n", num_points);
		xmlFreeDoc(fin);
	}else {

		FILE* fin = fopen(file, "r");

		if(!fin) {
			printf("Error: %s not found.\n", file);
			return 1;
		}
		printf("Opened %s with ", file);
		fscanf(fin, " %d", &num_points);
		//printf("%d waypoints\n", num_points);
		num_points = 0;
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
			num_points++;
		}

		fclose(fin);
		printf("%d waypoints\n", num_points);
		// printf("%d %d\n", (int)L->data.time, (int)L->next->data.time);
	}

	cstring command;
	printf("command: ");
	scanf(" %s", command);

	while(strcmp(command, "quit")) {
		cmd(command, L, num_points);
		printf("command: ");
		scanf(" %s", command);
	}

	free(L);
	return 0;
}

Node* add2front(Waypoint w, Node* oldlist) {
	Node* temp = calloc(1, sizeof(Node));
	temp->data = w;
	temp->next = oldlist;
	return temp;
}

void cmd(cstring c, Node* L, int numpts) {
	if(!strcmp(c, "stats")) {
		// printf("stats\n");
		stats(L);
	}else if(!strcmp(c, "landmarks")) {
		// printf("landmarks\n");
		landmarks(L, numpts);
	}else if(!strcmp(c, "fastest")) {
		printf("fastest\n");
	}else if(!strcmp(c, "linked")) {
		printf("yes\n");
	}else if(!strcmp(c, "visual")) {
		visual(L, numpts);
	}else if(!strcmp(c, "gpx")) {
		printf("yuh\n");
	}

	return;
}

// visual is the function called by cmd when "visual" is entered
// into the terminal
void visual(Node* L, int numpts) {
	// line 22 of gtkexample.c
	GtkApplication *app = gtk_application_new ("my.awesome.app", G_APPLICATION_FLAGS_NONE);

	double lo_lat = L->data.coor.latrad;
	double hi_lat = L->data.coor.latrad;
	double lo_lon = L->data.coor.lonrad;
	double hi_lon = L->data.coor.lonrad;

	Node* temp = L;
	while(temp != NULL) {
		if(temp->data.coor.latrad < lo_lat) {
			lo_lat = temp->data.coor.latrad;
		}else if(temp->data.coor.latrad > hi_lat) {
			hi_lat = temp->data.coor.latrad;
		}
		if(temp->data.coor.lonrad < lo_lon) {
			lo_lon = temp->data.coor.lonrad;
		}else if(temp->data.coor.lonrad > hi_lon) {
			hi_lon = temp->data.coor.lonrad;
		}
		temp = temp->next;
	}

	double lat_diff = hi_lat - lo_lat;
	double lon_diff = hi_lon - lo_lon;
	Point ends[numpts];
	double lat_factor = 799 / lat_diff;
	double lon_factor = 799 / lon_diff;
	temp = L;
	int arrind = 0;
	while(temp != NULL) {
		ends[arrind].x = (int) ((temp->data.coor.lonrad - lo_lon) * lon_factor);
		ends[arrind].y = 799 - (int) ((temp->data.coor.latrad - lo_lat) * lat_factor);
		arrind++;
		temp = temp->next;
	}

	/* for(int i = 0; i < numpts; i++) {
		printf("%d:	%d	%d\n", i, ends[i].x, ends[i].y);
	} */

	// line 30 of gtkexample.c
	g_signal_connect(app, "activate", G_CALLBACK(activate), ends);

	// printf("start\n");

  // line 36 of gtkexample.c
  g_application_run (G_APPLICATION (app), 0, NULL);

  // printf("done\n");

	//line 46 of gtkexample.c
	g_object_unref(app);
}

void stats(Node* L) {
	double dist = 0;
	time_t firsttime = L->data.time;
	time_t lasttime = 0;
	Node* temp = L;
	while(temp->next) {
		dist += gps_dist(temp->data.coor, temp->next->data.coor);
		temp = temp->next;
		if(!temp->next) {
			lasttime = temp->data.time;
		}
	}
	double total_time = difftime(firsttime, lasttime);
	int hours = (int) total_time / 3600;
	int seconds = (int) total_time % 3600;
	int minutes = seconds / 60;
	seconds = seconds % 60;
	printf("Total time: ");
	if(hours) {
		printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
	}else if(minutes) {
		printf("%d minutes, %d seconds\n", minutes, seconds);
	}else {
		printf("%d seconds\n", seconds);
	}

	printf("Total distance: %lg miles\n", dist);

	double speed = dist / (total_time / 3600);
	double pace = (total_time / 60) / dist;
	int pace_min = (int) pace;
	double pace_sec = (pace - (double) pace_min) * 60;

	printf("Average speed: %lg mph\n", speed);
	printf("Average pace: %d minutes, %lg seconds per mile\n", pace_min, pace_sec);
}

void landmarks(Node* L, int numpts) {
	cstring landFile;
	scanf(" %s", landFile);
	FILE* landfin = fopen(landFile, "r");
	if(landfin == NULL) {
		printf("Landmarks file %s not found\n", landFile);
		fclose(landfin);
		return;
	}
	int numMarks = 0;
	fscanf(landfin, " %d", &numMarks);
	//printf("%d\n", numMarks);
	Landmark marks[numMarks];

	for(int i = 0; i < numMarks; i++) {
		double lat_temp = 0;
		double lon_temp = 0;
		cstring name;
		fscanf(landfin, " %lg %lg %s", &lat_temp, &lon_temp, name);
		marks[i].coor = make_gps(lat_temp, lon_temp);
		strcpy(marks[i].name, name);
	}
	fclose(landfin);

	/*
	for(int i = 0; i < numMarks; i++) {
		printf("%lg %lg %s\n", marks[i].coor.latrad, marks[i].coor.lonrad, marks[i].name);
	}
	*/

	double shortdistances[numMarks];

	for(int i = 0; i < numMarks; i++) {
		shortdistances[i] = gps_dist(L->data.coor, marks[i].coor);
	}

	for(int i = 0; i < numMarks; i++) {
		Node* temp = L;
		while (temp != NULL) {
			double new_dist = gps_dist(temp->data.coor, marks[i].coor);
			if(new_dist < shortdistances[i]) {
				shortdistances[i] = new_dist;
			}
			temp = temp->next;
		}
	}

	for(int i = 0; i < numMarks; i++) {
		marks[i].shortest_distance = shortdistances[i];
	}
	for(int i = 0; i < numMarks - 1; i++) {
		for(int j = i; j < numMarks - 1; j++){
			if(marks[j].shortest_distance > marks[j + 1].shortest_distance) {
				Landmark temp = marks[j];
				marks[j] = marks[j + 1];
				marks[j + 1] = temp;
			}
		}
	}

	for(int i = numMarks - 1; i > 0; i--) {
		for(int j = i; j > 0; j--) {
			if(marks[j].shortest_distance < marks[j - 1].shortest_distance) {
				Landmark temp = marks[j];
				marks[j] = marks[j - 1];
				marks[j - 1] = temp;
			}
		}
	}

	for(int i = 0; i < numMarks; i++) {
		printf("%s %lg miles\n", marks[i].name, marks[i].shortest_distance);
	}

}

void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  // set the line color to blue and line width to 2 points
  cairo_set_source_rgb(cr, 0,0,255);
  cairo_set_line_width(cr, 2.0);

  // cast the user_data to an array of Points.
  Point* pts = (Point*) user_data;


  // to draw, you move the "cursor" somewhere first...
  cairo_move_to(cr, pts[0].x, pts[0].y);

  // and then call cairo_line_to to draw a line to wherever you want
  cairo_line_to(cr, pts[1].x, pts[1].y);

  // the path you made isn't actually drawn until you call cairo_stroke.
  cairo_stroke(cr);

}

/* This is the function that opens the window once GTK starts up. */
void activate (GtkApplication* app, gpointer user_data) {
  // create the window and give it a title
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title (GTK_WINDOW (window), "Map");

  // make a drawing canvas inside the window
  GtkWidget *drawing_area = gtk_drawing_area_new ();
  gtk_widget_set_size_request (drawing_area, 800, 800);
  gtk_container_add(GTK_CONTAINER(window), drawing_area);

  // tell GTK what function to call to draw the window
  // Notice we pass along the user_data, which for this program
  // will be an array of two Point structs.
	for(int i = 0; i < (sizeof(user_data) / sizeof(Point)) - 1; i++) {
		Point cur_seg[2] = {(Point)*user_data[i], (Point)*user_data[i + 1]};
		g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), cur_seg);
	}

  // well you don't want your beautiful window to be hidden do you?
  gtk_widget_show_all(window);
}
