#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int main(int argc, char *argv[]){
	int upper_limit = atoi(argv[1]);
	int not_primes[upper_limit - 2];

	for(int i = 0; i < (upper_limit - 2); i++){
		not_primes[i] = 0;
	}


	int iter;
	for(int i = 0; i <= sqrt(upper_limit); i++){
		if(not_primes[i] == 0){
			iter = 2;
			while((i + 2) * iter <= upper_limit){ 
				not_primes[(i + 2) * iter - 2] = 1;	
				++iter;
			}
		}
	}

	int number_primes = 0;
	int prime = -1;
	for(int i = 0; i <= upper_limit; i++){
		if (not_primes[i] == 0){
			if(number_primes < 10001){
				++number_primes;
				prime = i + 2;
			} else {
				break;
			}
		}
	}
	printf("%d primes numbers were found and the highest one was %d\n", number_primes, prime);
	return 0;
}
