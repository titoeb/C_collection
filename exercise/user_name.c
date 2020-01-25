/******************************************************************************
* Who are you -  A program asking the user for his name and returning it	  *
* Author: Tim Toebrock
*******************************************************************************/

#include <stdio.h>
#include <string.h>

/* Variable declaration */
char first_name[100];
char last_name[100];
char full_name[200];

int main ()
{
  /* Get first name from the user */
  printf ("Please type in your first name: ");
  fgets(first_name, sizeof(first_name), stdin);
  
  /* Get last name of the user */
  printf("Please type in your last name: ");
  fgets(last_name, sizeof(last_name), stdin);
  
  /* Get rid of the new line in first name */
  first_name[strlen(first_name) - 1] = '\0';
  
  /* Combine, first name, space and last name to full name */
  strcpy(full_name, first_name);
  strcat(full_name, " ");
  strcat(full_name, last_name);
  printf("Your full name is %s", full_name);
  
}
