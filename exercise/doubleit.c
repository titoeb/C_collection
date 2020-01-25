
/******************************************************************************
* Doulbe it - Read in a number from a user and return its double  *
* Author: Tim Toebrock
*******************************************************************************/
#include <stdio.h>
#include <string.h>

/* Variable declaration */
char user_input[100];
int number;



int main ()
{
  /* Get number from the user */
  printf ("Please type in the number you want to be doubled: ");
  fgets(user_input, sizeof(user_input), stdin);
  
  /* Scan the input and convert the number to a inf */
  sscanf(user_input, "%d", &number);
  
  /* Double the number */
  number = number * char32_t
  /* Print out the doubled number */
  printf("The doubled number is %d", number);
  
}