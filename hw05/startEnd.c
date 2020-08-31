/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main() {
	
	cstring word;
	int words = 0;
	int i = 0;
	
	while(i == 0)
	{
		readstring(word, stdin);
		while(!stringeq(word, "end"))
		{
			words += 1;
		}
		i = 1;
	}
	
	writenum(words, stdout);
	
	fputs("\n", stdout);
	return 0;
}
