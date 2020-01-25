 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
float input_value;
int cents;
int quarters, dimes, nickels, pennies;

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the number of points: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%f", &input_value);
	
	/*Convert the amount to cents */
	cents = input_value * 100;
	
	/* Number of quarters */
	quarters = cents / 25;
	cents = cents % 25;
	
	/* Number of dimes */
	dimes = cents / 10;
	cents = cents % 10;
	
	/* Number of nickels */
	nickels = cents / 5;
	pennies = cents % 5;
	
	printf("%d quarters, %d dimes, %d nickels, %d pennies ", quarters, dimes, nickels, pennies);
	return(0);
}