#include<stdio.h>
#include<stdlib.h>

int main(){
	int number = 1993;
	int *ptr = &number;
	int **dbl_ptr = &ptr;
	int ***trp_ptr = &dbl_ptr;

	printf("The value is %d\n", *ptr);
	printf("The adress of number is %p or %p\n", ptr, &number);
	printf("The value pointer is %p or %p\n", &ptr, dbl_ptr);
	printf("The value ot the pointer  on the pointer is %p or %p\n", &dbl_ptr, trp_ptr);
	printf("The adress of the triple pointer is %p\n", &trp_ptr);

	// Getting all values out of triple pointer!
	printf("3 %p\n", trp_ptr);	
	printf("2 %p\n", *trp_ptr);
	printf("1 %p\n", **trp_ptr);	
	printf("0 %d\n", ***trp_ptr);		
	return 0;
}
