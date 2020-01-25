#include <stdio.h>


int main(){

	int* b = NULL;
	printf("Wert von b: %p\n", b);
	printf("Adresse von b: %p\n",&b);
	printf("What is in there? %d\n", *b);

	return 0;
}
