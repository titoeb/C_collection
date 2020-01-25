#include<stdio.h>

int main(){
	int number_1, number_2;
	printf("Please type in two integers seperated by a space: \n");
	scanf("%d %d", &number_1, &number_2);
	printf("The result of the multiplication of the numbers %d and %d is %d\n", number_1, number_2, number_1 * number_2);

	return (0);
}
