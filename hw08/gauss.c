/* Gregory Smith
 * 235952
 */

#include "ic210.h"
int main(){
	int n = 0;
	int total = 0;
	
	fputs("Enter n: ", stdout);
	n = readnum(stdin);
	
	for(int i = 1; i <= n; i++)
	{
		total += i;
	}
	
	fputs("The sum of numbers from 1 up to ", stdout);
	writenum(n, stdout);
	fputs(" is ", stdout);
	writenum(total, stdout);
	
	fputs("\n", stdout);
	return 0;
}
