/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main() {
	
	fputs("Permissions: ", stdout);
	char first = readchar(stdin);
	char second = readchar(stdin);
	char third = readchar(stdin);
	
	int d1 = first - 48;
	int d2 = second - 48;
	int d3 = third - 48;
	
	int user1 = 0;
	int user2 = 0;
	int user3 = 0;
	
	int group1 = 0;
	int group2 = 0;
	int group3 = 0;
	
	int other1 = 0;
	int other2 = 0;
	int other3 = 0;
	
	user1 = d1 / 4;
	d1 = d1 % 4;
	
	user2 = d1 / 2;
	d1 = d1 % 2;
	
	user3 = d1;
	
	group1 = d2 / 4;
	d2 = d2 % 4;
	
	group2 = d2 / 2;
	d2 = d2 % 2;
	
	group3 = d2;
	
	other1 = d3 / 4;
	d3 = d3 % 4;
	
	other2 = d3 / 2;
	d3 = d3 % 2;
	
	other3 = d3;
	
	
	fputs("\nUser:\nread    ", stdout);
	writenum(user1, stdout);
	fputs("\nwrite   ", stdout);
	writenum(user2, stdout);
	fputs("\nexecute ", stdout);
	writenum(user3, stdout);
	fputs("\n\n", stdout);
	
	fputs("Group:\nread    ", stdout);
	writenum(group1, stdout);
	fputs("\nwrite   ", stdout);
	writenum(group2, stdout);
	fputs("\nexecute ", stdout);
	writenum(group3, stdout);
	fputs("\n\n", stdout);
	
	fputs("Other:\nread    ", stdout);
	writenum(other1, stdout);
	fputs("\nwrite   ", stdout);
	writenum(other2, stdout);
	fputs("\nexecute ", stdout);
	writenum(other3, stdout);
	
	fputs("\n", stdout);
	return 0;
}
