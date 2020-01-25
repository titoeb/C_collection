#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void simple_primes(int below);
void sieve(int below);

int main(){
	int number;
	number = 1000;
	printf("%d\n", number);
	simple_primes(number);
	printf("\n");
	printf("Now the sieve!\n");
	sieve(number);
}


void simple_primes(int below){
	int pot_prime, divisor, prime;
	

	if (below < 2){
		printf("Please give higher number");
	} else {
		printf("2 ");
		for (pot_prime = 3; pot_prime <= below; ++pot_prime){
			prime = 1;
			for (divisor = 2; divisor < (((int) sqrt(pot_prime) ) + 1); ++divisor){
				if (pot_prime % divisor == 0){
					prime = 0;
					break;			
				}
			}
			if (prime == 1){
				printf("%d ", pot_prime);
			}
		}
	}
}


void sieve(int below){
	int *const not_prime = malloc((below - 2) * sizeof(int));
	int iter, multiple;

	// Set all values in array to zero
	for (iter = 0; iter <= below - 2; ++iter){
		*(not_prime + iter) = 0;
	}
	
	printf("all values set to zero\n");
	int cur_num = 1;	
	while (cur_num < ((int) sqrt(below))){
		// find first prime 
		iter = cur_num - 1;
		while (*(not_prime + iter) == 1){
			++iter;		
		}	
		//printf("%d\n", cur_num);
		
		cur_num = iter + 2;
		
		// set multiples to not prime
		multiple = 2;	
		while(multiple * cur_num <= (below)){
			*(not_prime + (multiple * cur_num) - 2) = 1;			
			++multiple;
		}
	}
	
	// Print out the prime numbers
	for (iter = 0; iter <= below - 2; ++iter){
		if(*(not_prime + iter) == 0){
			printf("%d ", iter + 2);		
		}
	}
	printf("\n");


}
