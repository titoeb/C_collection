#include <stdio.h>
#include <string.h>

int main(){
	char input1[100], input2[100];
	
	/* Read in first string */
	fgets(input1, sizeof(input1), stdin);
	if (strlen(input1) > 50){
		printf("Fehler bei der Eingabe\n");
		return 1;	
	}


	/* remove newline at the end of input 1 */
	input1[strlen(input1) - 1] = '\0';

	/* read in second string */
	fgets(input2, sizeof(input2), stdin);
	if (strlen(input2) > 50){
		printf("Fehler bei der Eingabe\n");
		return 1;	
	}
	
	printf("%s", strcat(input1, input2));
	return 0;
}
