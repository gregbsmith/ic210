/* Gregory Smith
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef char cstring[128];

struct athlete {
	cstring name;
	double time;
};
	

int main() {
	printf("Enter the names and times of two racers:\n");
	struct athlete a;
	struct athlete b;
	
	scanf("%s %lg\n", a.name, &a.time);
	scanf("%s %lg", b.name, &b.time);
	
	if(a.time < b.time) {
		printf("%s won with a time of %lg minutes.\n", a.name, a.time);
	}else {
		printf("%s won with a time of %lg minutes.\n", b.name, b.time);
	}
	
	return 0;
}
