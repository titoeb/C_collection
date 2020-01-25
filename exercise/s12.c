#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char input[1000];
	char chr[127] = {0};
	int length;
	int c;
	int iter = 0;

	/* Read in the string */
	while((c = getchar()) != '\n'){
		input[iter] = c;		
		++iter;
	}
	if(iter > 1){
		input[iter] = '\0';
		/* Count all chars in the input */
		length = strlen(input) - 1;
		for (iter = 0; iter <= length; ++iter){
			/* Use the number of the char to identfy at which position of chr it has to be */
			++chr[(int) input[iter]];	
		}	
	}
	


	/* Print out the chars that exist */
	for (iter = 0; iter <= 127; ++iter){
		if (iter < 40){
			printf("<CTRL> %d : %d\n", iter, chr[iter]);	
		} else {
			printf("%c : %d\n", iter, chr[iter]);

		}
	}
}
