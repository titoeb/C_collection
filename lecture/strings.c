#include <stdio.h>

int main(){
	int anzahl = 4;
	char value = 0;
	int iter = 0;
	char werte[anzahl];

	printf("Bitte geben sie %d Zeichen ein!\n", anzahl);
	printf("Bitte jeweils mit ENTER bestaetigen!\n");

	/* Read in values */
	while(iter < anzahl){
		scanf("%c", &value);
		while(getchar() != '\n'){}
			werte[iter] = value;
		iter++;
	}

	/* print out the values */
	iter = 0;
	while(iter < anzahl){
		printf("%c", werte[iter]);
		++iter;		
	}

}
