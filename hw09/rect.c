/* Gregory Smith
 * 235952
 */
#include "ic210.h"
int main(){
	fputs("Height: ", stdout);
	int height = readnum(stdin);
	fputs("Width: ", stdout);
	int width = readnum(stdin);
	fputs("Offset: ", stdout);
	int offset = readnum(stdin);
	
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < offset; j++)
		{
			fputs(" ", stdout);
		}
		
		if(i == 0 || i == height - 1)
		{
			for(int k = 0; k < width; k++)
			{
				fputs("*", stdout);
			}
			fputs("\n", stdout);
		}
		else
		{
			for(int m = 0; m < width; m++)
			{
				if(m == 0 || m == width - 1)
				{
					fputs("*", stdout);
				}
				else
				{
					fputs(" ", stdout);
				}
			}
			fputs("\n", stdout);
		}
	}
	return 0;
}
