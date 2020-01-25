#include<stdio.h>	

long long maxNumber(long long n);

int main(){
	printf("The result was %lld\n",maxNumber(213));
}

long long maxNumber(long long n)
{
	// Calculate the number of digits
	long long run_num;
	run_num = n;
	int digits = 0;
	while(run_num > 0){
		++digits;
     		run_num /= 10;
	}

	// Store the digits in an array of int
	int numbers[digits];
	run_num = n;
	printf("Before sorting:\n");
	for(int i = 0; i < digits; ++i){
		numbers[i] = run_num % 10;
		run_num /= 10;
		printf("%d\n", numbers[i]);
	}
	
	// order the array
	int tmp;
	int repl = 1;
	while(repl == 1){
		repl = 0;
		for(int iter = 0; iter < (digits - 1); ++iter){
			if (numbers[iter] < numbers[iter + 1]){
				tmp = numbers[iter];
				numbers[iter] = numbers[iter + 1];
				numbers[iter + 1] = tmp;
				repl = 1;		
			}	
		}
	}	
	printf("After Sorting:\n");
	for(int i = 0; i < digits; ++i){
		printf("%d\n", numbers[i]);	
	}
	
	long long cur_digit = 1;
	long long output_num = 0;
	for(int i = (digits - 1); i >= 0; --i){
		output_num += cur_digit * numbers[i];
		cur_digit *= 10;
	}
	// make number from array

	return output_num; 
}
