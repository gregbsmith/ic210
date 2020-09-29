/* Gregory Smith
 * p1.c: add and square numbers
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char cstring[128];

int main(){
	double a = 0;
	double b = 0;
	double numb = 0;
	cstring comnd;
	cstring ADD = "add";
	cstring variable = "";
	cstring A = "a";
	
	fprintf(stdout, "Values for a and b? ");
	fscanf(stdin, " %lg, %lg", &a, &b);
	fprintf(stdout, "What do you want? ");
	fscanf(stdin, "%s", comnd);
	
	if(!strcmp(comnd, ADD)){
		//command is add
		fscanf(stdin, " %lg to %s", &numb, variable);
		if(!strcmp(variable, A)){
			//variable is A
			a = a + numb;
		}else{
			//variable is B
			b = b + numb;
		}
	}else{
		//command is square
		fscanf(stdin, " %s", variable);
		if(!strcmp(variable, A)){
			//variable is a
			a = a * a;
		}else{
			//variable is b
			b = b * b;
		}
	}
	
	
	
	fprintf(stdout, "a = %lg and b = %lg", a, b);
	fprintf(stdout, "\n");
	
	return 0;
}
