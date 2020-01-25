#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int* sieve(int below);
void find_n_primes(int number, int give);

int main(int argc, char *argv[]){
	int num_primes = atoi(argv[1]);
	find_n_primes(num_primes, atoi(argv[2]));
}


int* sieve(int below){
	int upper_limit = ((int) sqrt(below)) + 1;

	/* Create array to store 1 if the number is prime, otherwise zero. */
	char is_prime[below];

	/* We first assume that all numbers 2, ... , below - 1 might be primes */
	for(int i = 0; i < below; i++){
		is_prime[i] = 1;
	}

	/* for each number 2, ... , sqrt(below) check whether it is a prime and it it is set all multiples below below to not prime */
	for(int i = 2; i <= upper_limit; i++){
		if(is_prime[i] == 1){
			// All multiples of i have to be set to not prime!
			int num = 2;
			while((i * num)< below){
				is_prime[i * num] = 0;
				++num;
			}
		}
	}
	
	// Count the numbers of primes
	int prime_count = 0;
	for(int i = 2; i < below; i++){
		if(is_prime[i] == 1){
			++prime_count;
		}
	}

	// Allocate array of accordings size
	int *primes = (int*) malloc(sizeof(int) * (prime_count + 1));
	int index = 0;

	// Write the correct numbers in!
	for(int i = 2; i < below; i++){
		if(is_prime[i] == 1){
			primes[index] = i;
			++index;
		}
	}
	
	
	primes[index] = -1;
	return primes;
}


void find_n_primes(int number, int give){
	int primes_found = 0;
	int below = number;
	int number_primes;
	
	int *primes = malloc(sizeof(int) * 1); 
	while(primes_found < number){
	
		// Since we did not find enough primes, double the value below we look for primes
		below *=2;

		// How many primes could find below below?
		number_primes =  (int) (1.25 * ( (below * 1.0) / log(below * 1.0))) + 1;

		// reallocate enough memory
		primes = (int*) realloc(primes, number_primes);

		// Calculate primes
		primes = sieve(below);

		// Count the primes that were found!
		primes_found = 0; 
		while(*(primes + primes_found) >= 0){
			++primes_found;
		}
	}

	if(give <= 0){
		printf("The first %d primes are: ", number);
			primes_found = 0; 
			while(*(primes + primes_found) >= 0 && primes_found < number){
				printf(" %d", *(primes + primes_found));
				++primes_found;
			}
		printf("\n");
	} else {
		if(give > number){
			printf("Only looked for the first %d primes!\n", number);
		} else {
			printf("Prime number %d is %d\n", give, *(primes + give - 1));
		}
	}
		

	free(primes);
}
