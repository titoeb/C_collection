#include<stdio.h>

int quersumme(int input){
	int quer = 0;
	while(input > 0){
		quer += input % 10;
		input /= 10;
	}
	return quer;
}

int main(){
	int input;
	int res;
	char line[100];
	fgets(line, sizeof(line), stdin);
	res = sscanf(line, "%d", &input);
	while(res != EOF){
		if((res != 1) | (input < 0)){
			printf("Fehler bei der Eingabe!\n");
		} else{
			printf("Quersumme: %d\n", quersumme(input));
		}
		fgets(line, sizeof(line), stdin);
		res = scanf("%d", &input);
	}
	return 0;
}
