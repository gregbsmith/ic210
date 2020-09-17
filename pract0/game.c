/* Gregory Smith
 */

#include "ic210.h"

int main(){
	
	cstring file;
	int width = 0;
	int position = 0;
	readstring(file, stdin);
	char curr = '.';
	char last = '.';
	int step = 1;
	int count = 1;
	
	stream fin = fopen(file, "r");
	if(!fin){
		fputs("File not found!\n", stdout);
		return 0;
	}
	fscanf(fin, "width = %d", &width);
	//writenum(width, stdout);
	
	fprintf(stdout, "Enter a position between 1 and %d: ", width);
	position = readnum(stdin);
	if(position > width){
		fputs("Invalid position!\n", stdout);
		return 0;
	}
	
	while(!feof(fin)){
		
		curr = readchar(fin);
		if(curr == 'X' && count == position){
			fprintf(stdout, "You died on step %d\n", step);
			return 0;
		}
		if(curr == '.'){
			count ++;
		}
		if(curr == '@' && last == '@'){
			step = step + 1;
			count = 1;
		}
		last = curr;
	}
	fputs("You survived!", stdout);
	
	fputs("\n", stdout);
	return 0;
}
