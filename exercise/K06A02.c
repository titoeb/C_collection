#include <stdio.h>


int main(){
	int anzahl;
	int number, prev_number, new_number, iter;
	number = 1;
	prev_number = 1;
	printf("Bitte geben sie die Anzahl der Fibonacci Zahlen, die sie moechten!\n");
	scanf("%d", &anzahl);
	printf("1\n1\n");
	for (iter = 3; iter <= anzahl; ++iter){
		new_number = number + prev_number;
		prev_number = number;
		number = new_number;
		printf("%d\n", new_number);
	}
}
