/* gray.c: Program to convert a ppm file to grayscale
 * Gregory Smith
 */

#include "ic210.h"

int main(){
	cstring inFile;
	cstring outFile;
	cstring trash1;
	fputs("Input file: ", stdout);
	readstring(inFile, stdin);
	fputs("Output file: ", stdout);
	readstring(outFile, stdin);
	
	//stream proj = fopen("proj01files.tgz", "r");
	
	stream fin = fopen(inFile, "r");
	if(!fin){
		//error
		fputs("Error: Input file not found\n", stdout);
		return 1;
	}
	
	FILE *fp;
	fp = fopen(outFile, "w");
	
	int width = 0;
	int height = 0;
	int high = 0;
	
	fscanf(fin, "%s %d %d %d", trash1, &width, &height, &high);
	
	fprintf(fp, "%s\n%d %d\n%d\n", trash1, width, height, high);
	
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			int red = 0;
			int green = 0;
			int blue = 0;
			fscanf(fin, "%i %i %i", &red, &green, &blue);
			red = red + green + blue;
			red = red / 3;
			green = red;
			blue = red;
			fprintf(fp, "%i %i %i", red, green, blue);
			
			if(width - 1 == j){
				fprintf(fp, "\n");
			}else{
				fprintf(fp, " ");
			}
			//fprintf(stdout, "row %i, col %i: r%i g%i b%i\n", i, j, red, green, blue);
		}
	}
	
	fprintf(stdout, "Image saved to %s", outFile);
	
	fclose(fp);
	fclose(fin);
	fputs("\n", stdout);
	return 0;
}
