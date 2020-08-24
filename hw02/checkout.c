/* Greg Smith
 * 235952
 */
#include "ic210.h"
int main() {
	cstring	item;
	double	cost;
	int		quan;
	double	ttl;
	
	readstring(item, stdin);
	cost = readnum(stdin);
	quan = readnum(stdin);
	
	ttl = cost * quan;
	
	writenum(quan, stdout);
	fputs(" ", stdout);
	fputs(item, stdout);
	fputs(" cost $", stdout);
	writenum(ttl, stdout);
	fputs("\n", stdout);
	return 0;
	
}
