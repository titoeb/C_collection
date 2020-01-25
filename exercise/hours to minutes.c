 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
int input_minutes;
int input_hours;
int total_minues;

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the number of minutes: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%d", &input_minutes);
	
	/* Get the temperature in Celsius */
	printf("Please type in the number of hours: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%d", &input_hours);
	
	
	/* Calculate the size of the sphere */
	total_minues = input_minutes + 60 * input_hours;
	
	/* Return the output */ 
	printf("The number of minutes is %d", total_minues);
	
}