#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int is_prime(int number){
	if(number < 2){
		return 0;	
	}
	if(number % 2 == 0){
		if(number == 2)
			return 1;
		else
			return 0;
	}
	for(int i = 3; i < (sqrt(number) + 1); i+=2){
		if(number % i == 0){
			return 0;
		}
	}
	return 1;
	
}

int * prim_fac(int number, int *len){
	*len = 10;
	int found = 0;
	int *output = malloc(sizeof(int) * (*len));
	int cur_num = 2;
	while((number > 1)){
		if(is_prime(cur_num) == 1){
			if (number % cur_num == 0){
				if(found < (*len - 1))
					output[found] = cur_num;
				else{
					*len *= 2;
					output = realloc(output, sizeof(int) * (*len));
				}
				found++;
				number = number / cur_num;
			} else {
				if(cur_num == 2){
					cur_num++;			
				} else {
					cur_num += 2;
				}
			}
		} else {
			cur_num += 2;
		}
	}

	// Write in correct output array
	int *out = malloc(sizeof(int) * found);
	for(int i = 0; i < found; i++)
		out[i] = output[i];
	free(output);
	*len = found;
	return out;
}


int main(int argc, char *argv[]){
	unsigned int number;
	if(argc != 2){
		printf("Falsche Argumentzahl!\n");
		return 1;
	} else {
		number = atoi(argv[1]);
	}	
	int len;
	int *prime_factors = prim_fac(number, &len);
	printf("%d: ", number);
	for(int i = 0; i < len; i++){
		printf(" %d", prime_factors[i]);
		if(i < len - 1);
	}
	return 0;
	
}
