#include <stdio.h>


int main(){
	int a = 2049;
	int* int_ptr = &a;
	char* char_ptr = (char*) &a;

	printf("Wert von a: %d\n", a);
	printf("Wert von int_ptr %d\n", *int_ptr);
	printf("Wert von char_ptr %d\n", *char_ptr);
	printf("Wert von char_ptr correct: %d\n", *char_ptr + *(char_ptr + 1) * 256);

	return 0;	
}
