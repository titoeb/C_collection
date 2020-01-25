#include <stdio.h>

int main(){
	int jahr;
	printf("Bitte geben sie eine Jahreszahl ein:\n");
	scanf("%d", &jahr);
	if (jahr % 2 == 0){
		if (jahr % 4 == 0){
			printf("Sommerspiele\n");
		} else {
			printf("Winterspiele\n");		
		}
	} else {
		printf("Keine Spiele\n");	
	}
}
