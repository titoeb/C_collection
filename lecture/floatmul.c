#include<stdio.h>

int main(){
	float number_1, number_2;
	printf("Please type in two floating point numbers separated by space to multiply: \n");
	scanf("%f %f", &number_1, &number_2);
	printf("The result of multiplying %f with %f is %f\n", number_1, number_2, number_1 * number_2);
	return 0;
}
