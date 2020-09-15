/* readppm.c: Program to read a ppm file and print out the pixel values
 * Gregory Smith
 */


#include "ic210.h"

int main(){
	cstring file;
	cstring trash1;
	fputs("Input file: ", stdout);
	readstring(file, stdin);
	
	stream fin = fopen(file, "r");
	
	int width = 0;
	int height = 0;
	int high = 0;
	
	fscanf(fin, "%s %i %i %i", trash1, &width, &height, &high);
	
	//fprintf(stdout, "%i %i", width, height);
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			int red = 0;
			int green = 0;
			int blue = 0;
			fscanf(fin, "%i %i %i", &red, &green, &blue);
			fprintf(stdout, "row %i, col %i: r%i g%i b%i\n",
			i, j, red, green, blue);
		}
	}
	
	fclose(fin);
	fputs("\n", stdout);
	return 0;
}
