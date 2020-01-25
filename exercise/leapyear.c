 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
float input_value;
int year

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the number of points: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%d", &year);
	
	/* Is the year a leap year? */
	if (year % 100 == 0 && year % 400 != 0){
		printf("Not a leap year");
	} else {
		if (year % 4 == 0){
			printf("Leap year!");
		} else {
			printf("Not a leap year");
		// }
	}
	return(0);
}