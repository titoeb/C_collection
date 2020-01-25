#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int laenge = 2048;
	int i =	 0;
	char c;
	char in[laenge];
	char *ptr = in;
	FILE *dateiZeiger = fopen("text.txt", "r");

	if (dateiZeiger == NULL){
		printf("Datei nicht gefunden!\n");
		return 1;
	}

	while((i <  laenge) && ((c = fgetc(dateiZeiger)) != EOF )){
		
		if (isspace(c)){}
		else{		
			*ptr = c;
			++ptr;
		}
	}	
	*ptr = '\0';	
	fclose(dateiZeiger);
	printf("%s \n", in);
	return 0;
}
