#include<stdio.h>

int main(){
	printf("Bitte geben sie eine Zahl ein! \n");
	char zeichen;
	zeichen = getchar();
	printf("The char was %c\n", zeichen);
	return 0;
}
