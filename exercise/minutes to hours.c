 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
int input_minutes;
int partial_hours;
int partial_minutes;

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the number of minutes: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%d", &input_minutes);
	
	/* Calculate the number of hours */
	partial_hours = input_minutes / 60;
	
	/*Calculate the number of hours */
	partial_minutes = input_minutes % 60;
	
	/* Return the output */ 
	printf("Your inputed %d hours and %d minutes", partial_hours, partial_minutes);
	
}