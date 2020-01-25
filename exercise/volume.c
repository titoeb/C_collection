
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
float diameter;
float volume;
const float PI = 3.14159265358;

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the diameter of the sphere: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%f", &diameter);
	
	/* Calculate the size of the sphere */
	volume = (4.0 / 3.0) * PI * diameter * diameter * diameter;
	
	/* Return the output */ 
	printf("The volume is %f", volume);
	
}