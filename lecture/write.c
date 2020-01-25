#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
	FILE *dateiZeiger = fopen("einText.txt", "w");
	fprintf(dateiZeiger, "Hier ist eine kleiner, super toller Text!\n");
	
	fclose(dateiZeiger);
}
