#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct array{
	long long *numbers;
	long long length;
	long long cur_pos; 
};


struct array *create_array(int len){
	struct array *out = malloc(sizeof(struct array));
	out->numbers = malloc(sizeof(long long) * len);
	out->length = len;
	out->cur_pos = 0;
	return out;
}

int is_prime(long long candidate){
	if(candidate % 2 == 0){
		if(candidate == 2) return 1;
		else return 0;
	}
	for(long long i = 3; i < sqrt(candidate); i+= 2){
		if(candidate % i == 0) return 0;
	}
	return 1;
}

void append_array(struct array *input, long long number){

	if(input->cur_pos >= input->length - 1){
		input->numbers = realloc(input->numbers, input->length * 2);
		input->length *= 2;
	}

	input->numbers[input->cur_pos] = number;
	input->cur_pos++;

	return;
}

long long array_max(struct array *input){
	long long max = input->numbers[0];
	for(long long i = 1; i < input->cur_pos; i++){
		if(input->numbers[i] > max) max = input->numbers[i];
	}
	return max;
}


long long larg_prim_fac(long long number){
	struct array *factors = create_array(100);
	long long cur_num = 2;
	while(number > 1){
		if(number % cur_num == 0){
			append_array(factors, cur_num);	
			number/= cur_num;
		} else {
		
		cur_num++;
		while(!is_prime(cur_num)) cur_num++;
		}		
	}
	long long out = array_max(factors);
	free(factors->numbers);
	free(factors);
	return(out);
}



int main(){
	long long test = 600851475143;
	long long result = larg_prim_fac(test);
	printf("The largest prime factor of %lld is %lld\n", test, result);
}
