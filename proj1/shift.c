/* shift.c: Program to combine images and shift the position of the foreground
 * Gregory Smith
 */

#include "ic210.h"

int main(){
	cstring foregroundFile;
	cstring backgroundFile;
	cstring outputFile;
	
	cstring fTrash;
	cstring bTrash;
	
	int rs = 0;
	int cs = 0;
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
	fputs("Row shift: ", stdout);
	rs = readnum(stdin);
	fputs("Column shift: ", stdout);
	cs = readnum(stdin);
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
	
	if((bWidth - cs < fWidth) || (bHeight - rs < fHeight)){
		fputs("Error: The foreground goes past the background\n", stdout);
		return 3;
	}
	
	
	
	FILE *fp;
	fp = fopen(outputFile, "w");
	fprintf(fp, "%s\n%i %i\n%i\n", bTrash, bWidth, bHeight, bHi);
	
	
	for(int i = 0; i < bHeight; i++){
		for(int j = 0; j < bWidth; j++){
			int red = 0;
			int green = 0;
			int blue = 0;
			if((i >= rs && i < (fHeight + rs)) && (j >= cs && j < (fWidth + cs))){
				
				fscanf(fFin, "%i %i %i", &red, &green, &blue);
				
				if(red <= 50 && blue <=50 && green >= 230){
					fscanf(bFin, " %i %i %i", &red, &green, &blue);
					fprintf(fp, "%i %i %i", red, green, blue);
				}else{
					fprintf(fp, "%i %i %i", red, green, blue);
					fscanf(bFin, " %i %i %i", &red, &green, &blue);
				}
			}else{
				fscanf(bFin, " %i %i %i", &red, &green, &blue);
				fprintf(fp, "%i %i %i", red, green, blue);
			}
			
			
			if(bWidth - 1 == j){
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
	
	fputs("\n", stdout);
	return 0;
}
