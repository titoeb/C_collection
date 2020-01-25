 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
int grade;

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the number of points: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%d", &grade);
	
	if (grade <= 60){
		printf("F");
	} else {
		if (grade <= 70){
			printf("D");
		} else {
			if (grade <= 80){
				printf("C");
			} else {
				if (grade <= 90){
					printf("B");
				} else {
					printf("A");
				}
			}
		}
	}
	 
	return(0);
}