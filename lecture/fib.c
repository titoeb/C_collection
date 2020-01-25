#include <stdio.h>
#include <stdlib.h>

int fib(int number);
int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Please provide an input value!\n");
		return 1;
	} 
	if (argc > 2){
		printf("More than one paramter was supplied!\n");
		printf("Only the number %d will be used. \n", atoi(argv[1]));
		fib(atoi(argv[1]));	
	} else {
		fib(atoi(argv[1]));		
	}
}

int fib(int number){
	int iter, cur_num, prev, temp;
	if (number < 1){
		printf("Please provide a higher number!\n");	
		return 1;
	}
	printf("1 ");
	
	if (number > 1){
		printf("1 ");	
	}	
	if (number > 2){
		cur_num = 1;
		prev = 1;
		for (iter = 0; iter < (number - 2); ++iter){
			temp = cur_num;
			cur_num = cur_num + prev;
			prev = temp;
			printf("%d ", cur_num);
		}		
	}	
	
	printf("\n");
	return 0;
	
}
