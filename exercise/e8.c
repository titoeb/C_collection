#include <stdio.h>


int main(){
	int array[9];
	int iter;

	/* Read in the array */
	printf("Please enter a permuation of the numbers 0-9!\n");
	for (iter = 0; iter < 9; ++iter){
		printf("Please enter number %d\n", iter + 1);	
		scanf("%d", &array[iter]);
	}

	/* Check for all numbers */	
	int number;
	int in_here = 0;
	for (number = 1; number < 10; ++number){
		// Check whether the number number is in the array.
		for (iter = 0; iter < 9; ++ iter){
			if (array[iter] == number){
				in_here = 1;
				break;	
			}		
		}
		if (in_here == 0){
			printf("The number %d is missing!\n", number);
			return 0;		
		}
		in_here = 0;
	}
	printf("All numbers are in here!\n");

	
	
		
	return 0;
}

