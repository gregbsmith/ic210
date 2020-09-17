/* gray.c: Program to convert a ppm file to grayscale
 * Gregory Smith
 */

#include "ic210.h"

int main(){
	cstring inFile;
	cstring outFile;
	fputs("Input file: ", stdout);
	readstring(inFile, stdin);
	fputs("Output file: ", stdout);
	readstring(outFile, stdin);
	
	//stream proj = fopen("proj01files.tgz", "r");
	
	stream fin = fopen(inFile, "r");
	if(!fin){
		//error
		return 1;
	}
	
	fputs("\n", stdout);
	return 0;
}
