#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_st_prime(int input){
	if(input % 2 == 0){
		if(input != 2)
			return 0;
		else
			return 1;
	}
	for(int i = 3; i < (sqrt(input) + 1); i+= 2){
		if (input % i == 0)
			return 0;
	}
	return 1;
}

int *sieve(int max, int *len){
	// array to save whether number is prime
	int is_prime[max];

	// initialize all numbers to prime except 0, 1;
	is_prime[0] = 0;
	is_prime[1] = 0;
	for(int i = 2; i <= max; i++){
		is_prime[i] = 1;
	}
	
	// Sieve 
	for(int i = 2; i < (sqrt(max) + 1); i++){
		if(is_prime[i] == 1){
			for (int j = i * 2; j < max; j = j + i){
				is_prime[j] = 0;
			}
		}
	}

	// Now collect all numbers from is_primes
	
	// first count them
	*len = 0;
	for(int i = 2; i < max; i++){
		*len += is_prime[i];
	}
	
	// Create dyn array to contain them
	int *primes = malloc(sizeof(int) * (*len));

	// write primes into array
	int pos = 0;
	for(int i = 2; i < max; i++){
		if(is_prime[i] == 1){
			primes[pos] = i;
			pos++;
		}
	}
	return primes;	
}


int main(){
	int len = 0;
	int *primes = sieve(1000, &len);
	for(int i = 0; i < len; i++){
		printf("%d ", primes[i]);
	}
	free(primes);
	printf("\n");
	return 0;
}
