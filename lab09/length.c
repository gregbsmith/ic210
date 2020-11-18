/* length.c: Print out the length between first and last episodes
 * Remember, type "make length" to compile this program
 */
#define _XOPEN_SOURCE
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "rss.h"

typedef char cstring[128];

int main() {
  printf("RSS filename: ");
  fflush(stdout);
  char fname[128];
  scanf(" %s", fname);

  // Notice, we call open_rss instead of fopen.
  RssFile* rss = open_rss(fname);
  if (!rss) {
    printf("ERROR: invalid rss file\n");
    return 1;
  }
  
  
  time_t early = 0;
  time_t late = 0;
  int x = 0;
  
  
  while (next_episode(rss)) {
	cstring fdate;
	struct tm temp = {0};
	episode_date(rss, fdate);
	strptime(fdate, "%a, %d %b 20%y %T", &temp);
	time_t timetemp = mktime(&temp);
	if(x == 0 || timetemp > late) {
		late = timetemp;
	}
	if(x == 0 || timetemp < early) {
		early = timetemp;
	}
	x++;
  }
  // printf("%ld %ld\n", early, late);
  
  int length = difftime(late, early);
  int sec = length % 60;
  int day = length / 86400;
  int min = (length / 60) % 60;
  int hour = ((length % 86400) / 3600);
  
  printf("%d days %d hours %d minutes %d seconds\n", day, hour, min, sec);
  
  // It's always good to clean up after yourself.
  close_rss(rss);

  return 0;
}
