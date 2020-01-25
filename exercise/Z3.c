#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


void prim_zerl(int number);
int is_prime(int number);

int main(int argc, char *argv[]){
	if (atoi(argv[1]) > UINT_MAX){
		printf("The number is too high! \n");
		return 1;
	} 
	
	prim_zerl(atoi(argv[1]));	
}

int is_prime(int number){
	int iter = 0;
	int max_check = sqrt(number);	
	if (number % 2 == 0){
		if (number == 2){
			return 1;		
		} else {
			return 0;	
		}
	}
	
	for (iter = 3; iter <= max_check; iter += 2){
		if (number % iter == 0){
			return 0;		
		}
	}	
	return 1;
}

void prim_zerl(int number){
	int iter = 2;
	printf("%d: ", number);
	while(iter <= number){
		if(number % iter == 0 && is_prime(iter) == 1){
			printf("%d ", iter);
			number /= iter;
		} else {
			++iter;		
		}	
	}
	printf("\n");
}
