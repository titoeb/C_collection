#include<stdio.h>
#include<stdlib.h>


int next(int *ptr, int len, int start_pos){
	int i;
	for(i = start_pos; i < len; i++){
		if(ptr[i] > 0){
			return i;
		}
	}
	return 0;
}

int dblLinear(int n){
	printf("input values was %d\n", n);
	int len = n * 10;
	int last_len;
 	int *values = calloc(len, sizeof(int));
	if(values == NULL){
		printf("Could not allocate the memory!\n");
		return -1;
	}
	values[1]++;
	int val1, val2;
	int cur_val= 0;
	for(int i = 1; i <= n; i++){
		cur_val = next(values, len, cur_val + 1);
		val1 = 2 * cur_val + 1;
		val2 = 3 * cur_val + 1;
		//printf("Cur val is %d and val 1 is %d and val 2 is %d\n", cur_val, val1, val2);
		if (val2 >= (len - 1)){
			last_len = len;
			len = len * 2;
			values = realloc(values, sizeof(int) * len);
			if(values == NULL){
				printf("Could not allocate the memory!\n");
				return -1;
			}
			for(int i = last_len - 1; i < len; i++){
				values[i] = 0;		
			}
			
		}
		//printf("highest value %d, len %d\n", val2, len);
		values[val1]++;
		values[val2]++;
	}

	//printf("Survived the calculation!\n");
	// return the nth value
	int result = -1;
	int count = 0;
	for(int i = 1; i < len; i++){
		if(values[i] > 0){
			count++;
			//printf("%dth number was %d\n", count, i);
		}
		if(count > n){
			result = i;
			if(values != NULL){
				free(values);
			}
			break;
		}
	}
	return result;
}

int main(int argc, char *argv[]){
	int num  = atoi(argv[1]);
	 printf("u(%d) = %d \n", num, dblLinear(num));
	
	return 0;

}
