#include <stdio.h>


int main(){
	const int a = 123;
	const int *b = &a;
	int *p = &a;
	*p = &a;
	*p = 456;	
	
	printf("Wert von b: %d\n", *b);
	printf("Wert von p: %d\n", *p);
}

