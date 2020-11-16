/* search.c: Print out the title and url for podcasts containing
 * the keyword
 * Remember, type "make search" to compile this program
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "rss.h"

typedef char cstring[128];

// makes a string all lowercase
void lower(cstring word);

int main() {
  printf("RSS filename: ");
  fflush(stdout);
  char fname[128];
  scanf(" %s", fname);
  cstring srch4;
  printf("Search for: ");
  scanf(" %s", srch4);
  
  // Notice, we call open_rss instead of fopen.
  RssFile* rss = open_rss(fname);
  if (!rss) {
    printf("ERROR: invalid rss file\n");
    return 1;
  }

  // printf("First 10 episodes in the file are below.\n");

  // Declare strings to hold the info for each episode
  // Note, we expects titles and urls to (possibly) be very long,
  // but dates won't be as long.
  char title[256];
  char url[256];
  char date[64];
  int matches = 0;
  // int episode_index = 1;
  // loop through the first 10 episodes using next_episode()
  while (next_episode(rss)) {
    // call functions from rss.h to get episode information
    episode_title(rss, title);
    episode_date(rss, date);
	episode_url(rss, url);
	
	if(strstr(title, srch4)) {
		printf("title: %s\n", title);
		printf("  url: %s\n", url);
		matches++;
	}else {
		cstring title2;
		strcpy(title2, title);
		lower(title);
		if(strstr(title, srch4)) {
			printf("title: %s\n", title2);
			printf("  url: %s\n", url);
			matches++;
		}
	}
    // display the information we just looked up
    // printf("\n%d. %s\n", episode_index, title);
    // printf("  date: %s\n", date);
    // printf("  url: %s\n", url);

    //++episode_index;
  }
  if(!matches) {
	  printf("No matches found\n");
  }
  // It's always good to clean up after yourself.
  close_rss(rss);

  return 0;
}

// makes a string all lowercase
void lower(cstring word) {
	for(int i = 0; i < (int)strlen(word); i++) {
		if((int) word[i] >= 65 && (int) word[i] <= 90) {
			word[i] = (char) ( (int) word[i] + 32 );
		}
	}
	return;
}
