#include<stdio.h>
#include "a03-testing.h"
#include<stdlib.h>

int main(int argc , char * argv []){

	int r;
	if (argc < 2){
		r = recSort(NULL, NULL, 0);
		printf("recSort(NULL, NULL, 0): %d\n", r);
		return 0;
	}

	int *f = malloc(sizeof(int) * (argc - 1));

	for(int i = 0; i < (argc - 1); i++){
		f[i] = atoi(argv[i + 1]);
	}


	for(int i = 0; i < (argc - 1); i++){
		printf("%d ", f[i]);
	}
	printf("\n");
	printf("-------\n");

	r = recSort(f, f+argc-1, 1);

	for(int i = 0; i < (argc - 1); i++){
		printf("%d ", f[i]);
	}
	printf("\n");

	printf("recSort(f, f+argc-1, 1): %d \n", r);
	
	free(f);
	return 0;

}
