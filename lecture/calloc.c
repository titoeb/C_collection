#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int* dings;
	int *bums;
	int laenge = 16;
	int i = 0;
	int j = 0;
	int n = 12;
	
	dings = (int*) malloc(laenge* sizeof(int));
	bums = (int*) calloc(laenge, sizeof(int));

	if (dings == NULL || bums == NULL){
		printf("Ran out of memory!\n");
		return 1;
	}

	while (i < n){
		dings[i] = i + 100;
		*(bums + i) = i;
		i++;
	}

	printf("Content of the pointer: \n");
	while(j < laenge){
		printf("%d \t", dings[j]);
		printf("%d \n", bums[j]);
		j++;
	}

	free(dings);
	free(bums);

	return 0;
}
