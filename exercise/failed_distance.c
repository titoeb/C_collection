 
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Variable declaration */
char user_input[100]; 
int start_x, start_y, target_x, target_y; /* starting and end points */
int iter = 0; /*iterator for loops */
int found = 0; /* How many commata where found. */
int posit[5]; /* The position of the commata */
int points_char[4][50]; /* The positions saved as array of chars */
int points[4]; /* The positions saved as array of ints */
int start_pos, end_pos; /* Current position to cut out numbers from user input */

int main ()
{
	/* Get the temperature in Celsius */
	printf("Please type in the startpoint and target points seperated by commata: ");
	
	/* Catch the user input */
	fgets(user_input, sizeof(user_input), stdin);

	/* First element of points is zero, last element is length of the string */
	posit[0] = 0;
	posit[4] = strlen(user_input);
	
	/* Find the positions of the commatas and the starting and end position */
	while (iter < strlen(user_input)){
		if (user_input[iter] == ','){
			posit[found + 1] = iter;
			printf("Found comma at %d \n", iter);
			++found;
		}
		++iter;
	}
	/* Make sure the user inputed three commata */
	if (found < 3){
	    printf("Please input four numbers seperated by three commata");
	    return(1);
	}
	
	/* Now that I have the positions of the commata I can extract the four numbers */
	iter = 1;
	while (iter < 5){
	    start_pos = posit[iter - 1];
	    end_pos = posit[iter];
	    strncpy(points_char[iter], &posit[start_pos], end_pos - start_pos);
        dest[end_pos - start_pos] = '\0';
	    ++iter;
	}

	
	
	/* Return the output */ 

	
}