#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long sum_primes_below(int below){
	// Create count arrray
	int is_prime[below];
		
	// As all numbers may be primes initallize them all to one!
	for(int i = 0; i < below; i++){
		is_prime[i] = 1;
	}
	
	// main loops
	for(int divisor = 2; divisor < sqrt(below) + 1; divisor++){
		if (is_prime[divisor] == 1){
			for(int mult = 2; mult * divisor < below; mult++){
				is_prime[mult * divisor] = 0;
			}
		}
	}

	// sum up all primes;
	long long sum_primes = 0;
	//printf("The primes are:");
	for(int i = 2; i < below; i++){
		if(is_prime[i] == 1){
		//printf(" %d", i);
		sum_primes += i;
		}
	}
	//printf("\n");
	return sum_primes;
}


int main(){
	int num = 2000000;
	long long res = sum_primes_below(num);
	printf("Sum of primes below %d is %lld\n", num, res);
	return 0;
}

