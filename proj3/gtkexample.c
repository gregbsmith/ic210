/* IC210 Spring 2020
 * Example program to draw a line on an 800x800 window using GTK+
 */

#include <stdio.h>
#include <gtk/gtk.h>

typedef struct {
  int x;
  int y;
} Point;

/* This is the function that opens the window once GTK starts up. */
void activate (GtkApplication* app, gpointer user_data);

/* This is the function that actually draws the lines (or anything else).
 * It gets called when the window is displayed to the user.  */
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

int main () {
  // you have to make an "application" that has some arbitrary name
  GtkApplication *app = gtk_application_new ("my.awesome.app", G_APPLICATION_FLAGS_NONE);

  // make an array of two points to draw a line between
  Point ends[5] = {{200, 400}, {700, 300}, {300, 500}, {100, 600}, {500, 100}};

  // tell GTK what function to call when the application starts
  // Notice we pass ends as the last argument, which is passed along
  // eventually as the user_data parameter to on_draw_event.
  g_signal_connect(app, "activate", G_CALLBACK(activate), ends);

  // this line is printed just BEFORE the window pops up.
  printf("start\n");

  // show the actual window and wait until the user closes it...
  g_application_run (G_APPLICATION (app), 0, NULL);

  // this line is printed just AFTER the window pops up.
  printf("done\n");

  // cleanup time
  g_object_unref(app);

  return 0;
}

/* This is the function that actually draws the lines (or anything else).
 * It gets called when the window is displayed to the user.
 * For THIS program, we assume the last argument user_data will be an
 * array of two point structs.
 */
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  printf("draw event start\n");
  printf("drawing segment\n");
  // set the line color to blue and line width to 2 points
  cairo_set_source_rgb(cr, 0,0,255);
  cairo_set_line_width(cr, 2.0);

  // cast the user_data to an array of Points.
  Point* pts = (Point*) user_data;

  for(int i = 0; i < 5 - 1; i++) {
      // to draw, you move the "cursor" somewhere first...
      cairo_move_to(cr, pts[i].x, pts[i].y);

      // and then call cairo_line_to to draw a line to wherever you want
      cairo_line_to(cr, pts[i + 1].x, pts[i + 1].y);

      // the path you made isn't actually drawn until you call cairo_stroke.
      cairo_stroke(cr);
    }
  printf("draw event end\n");
}

/* This is the function that opens the window once GTK starts up. */
void activate (GtkApplication* app, gpointer user_data) {
  printf("activate start\n");
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
  g_signal_connect(G_OBJECT(drawing_area), "draw",
            G_CALLBACK(on_draw_event), user_data);

  // well you don't want your beautiful window to be hidden do you?
  gtk_widget_show_all(window);
  printf("activate end\n");
}
