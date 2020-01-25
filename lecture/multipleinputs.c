#include <stdio.h>

int main(){
	int anzahl = 4;
	int value = 0;
	int iter = 0;
	int werte[anzahl];

	printf("Bitte geben sie %d Zahlen ein!\n", anzahl);
	printf("Bitte jeweils mit ENTER bestaetigen!\n");

	/* Read in values */
	while(iter < anzahl){
		scanf("%d", &value);
		//while(getchar() != '\n'){}
		werte[iter] = value;
		iter++;
	}

	/* print out the values */
	iter = 0;
	while(iter < anzahl){
		printf("%d\n", werte[iter]);
		++iter;		
	}

}
