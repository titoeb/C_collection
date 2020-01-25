#include <stdio.h>
#include <string.h>


int main(void){
	char line[100];
	int length;
	int iter;
	int number;
	int pot_2 = 1;
	/* read in binary number */
	fgets(line, sizeof(line), stdin);
	length = strlen(line) - 1;

	/* Check the input for numbers except 0,1 */
	for (iter = (length - 1); iter >= 0; --iter){
		if (!(line[iter] == 49 || line[iter] == 48)){
			printf("Fehler bei der Eingabe!\n");
			return 1;		
		}
	} 

	/* Calculate decimal number */
	for (iter = (length - 1); iter >= 0; --iter){
		number += (line[iter] - 48) * pot_2;
		pot_2 *= 2;
	} 

	printf("Dezimal: %d\n", number);
}
