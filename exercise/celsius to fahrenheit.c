
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
float temp_celsius;
float temp_fahrenheit;

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the temperature in Celsius: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%f", &temp_celsius);
	
	/* convert the temperature to fahrenheit */
	temp_fahrenheit = (9.0 / 5.0) * temp_celsius + 32.0;
	
	/* Return the output */ 
	printf("The temperature in Fahrenheit is %f", temp_fahrenheit);
	
}