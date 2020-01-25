#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char **double_ptr;
	char *ptr_array[5];

	char eins[8] = "eins";
	char zwei[8] = "zwei";
	char drei[8] = "drei";
	char vier[8] = "vier";
	char fuenf[8] = "fuenf";

	ptr_array[0] = eins;
	ptr_array[1] = zwei;
	ptr_array[2] = drei;
	ptr_array[3] = vier;
	ptr_array[4] = fuenf;

	double_ptr = ptr_array;

	printf("Test: %s\n", double_ptr[3]);
	printf("Test: %c\n", double_ptr[3][3]);
	printf("Test: %c\n", *double_ptr[3]);
	printf("Test: %c\n", *(double_ptr[3] + 3));

	return 0;
}
