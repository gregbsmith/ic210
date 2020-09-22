/* green.c: Program to combine two images using green-screening
 * Gregory Smith
 */

#include "ic210.h"

int main(){
	cstring foregroundFile;
	cstring backgroundFile;
	cstring outputFile;
	
	cstring fTrash;
	cstring bTrash;
	
	int fHi = 0;
	int bHi = 0;
	int fWidth = 0;
	int fHeight = 0;
	int bWidth = 0;
	int bHeight = 0;
	
	fputs("Foreground file: ", stdout);
	readstring(foregroundFile, stdin);
	fputs("Background file: ", stdout);
	readstring(backgroundFile, stdin);
	fputs("Output file: ", stdout);
	readstring(outputFile, stdin);
	
	stream fFin = fopen(foregroundFile, "r");
	stream bFin = fopen(backgroundFile, "r");
	if(!fFin || !bFin){
		fputs("Error: Input file not found\n", stdout);
		return 1;
	}
	
	fscanf(fFin, "%s %d %d %d", fTrash, &fWidth, &fHeight, &fHi);
	fscanf(bFin, "%s %d %d %d", bTrash, &bWidth, &bHeight, &bHi);
	
	
	
	if((fWidth != bWidth) || (fHeight != bHeight)){
		fputs("Error: Images have different sizes\n", stdout);
		return 2;
	}
	
	FILE *fp;
	fp = fopen(outputFile, "w");
	fprintf(fp, "%s\n%i %i\n%i\n", fTrash, fWidth, fHeight, fHi);
	for(int i = 0; i < fHeight; i++){
		for(int j = 0; j < fWidth; j++){
			int red = 0;
			int green = 0;
			int blue = 0;
			fscanf(fFin, "%i %i %i", &red, &green, &blue);
			
			if(!red && !blue && green == fHi){
				fscanf(bFin, " %i %i %i", &red, &green, &blue);
				fprintf(fp, "%i %i %i", red, green, blue);
			}else{
				fprintf(fp, "%i %i %i", red, green, blue);
				fscanf(bFin, " %i %i %i", &red, &green, &blue);
			}
			
			
			if(fWidth - 1 == j){
				fprintf(fp, "\n");
			}else{
				fprintf(fp, " ");
			}
		}
	}
	
	
	
	
	
	fclose(bFin);
	fclose(fFin);
	fclose(fp);	
	fprintf(stdout, "Image saved to %s", outputFile);
	fputs("\n", stdout);
	return 0;
}
