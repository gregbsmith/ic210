/* Gregory Smith
 * 235952
 */

#include "ic210.h"

int main(){
	cstring name;
	int month;
	int day;
	int year;
	
	int age = 0;
	
	//TODAY (September 14, 2020)
	int sep = 9;
	int s14 = 14;
	int syear = 2020;
	
	fscanf(stdin, "%s %i/%i/%i", name, &month, &day, &year);
	
	if(month < sep){
		age = syear - year;
	}
	else if(month > sep){
		age = syear - year - 1;
	}
	else{
		if(day <= s14){
			age = syear - year;
		}
		else{
			age = syear - year - 1;
		}
	}
	
	fprintf(stdout, "%s is %i years old.", name, age);
	
	printf("\n");
	return 0;
}
