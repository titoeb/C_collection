 
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
int points;
char grade[2]; 
int last_digit;

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the number of points: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin); 
	
	/* Read the number in the integer temp_celsius */
	sscanf(user_input, "%d", &points);
	
	/* Determine the first part of the grade */
	if (points <= 60){
		grade[0] = 'F';
	} else {
		if (points <= 70){
			grade[0] = 'D';
		} else {
			if (points <= 80){
				grade[0] = 'C';
			} else {
				if (points <= 90){
					grade[0] = 'B';
				} else {
					grade[0] = 'A';
				}
			}
		}
	}
	
	/* Determine the second part of the grade */
	/* First calculate the last digit */
	last_digit = points % 10;
	
	/* Based on this digit put in +, blank or, - */
	if (grade[0] != 'F'){
		if (last_digit <= 3 && last_digit != 0){
			grade[1] = '-';
		} else {
			if (last_digit >= 8 || last_digit == 0){
				grade[1] = '+';
			}
		}
		
	} 
	printf("The grade was %s", grade);
	return(0);
}