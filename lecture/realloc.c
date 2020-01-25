#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	// 
	char* basis;
	char c;
	int i = 0;
	int size = 8;	
	FILE *file_ptr = fopen("text.txt", "r");

	if (file_ptr == NULL){
		printf("Could not find File!");
		return 1;
	}
	
	basis = (char*) malloc(sizeof(char) * size);
	if(basis == NULL){
		printf("Could not allocate memory for basis\n");
		return 1;
	}

	while((c = fgetc(file_ptr)) != EOF){
		if((i+2) == size){
			size = 2 * size;
			basis = realloc(basis, sizeof(char) * size);
			if(basis == NULL){
				printf("Could not alloate new memory for basis\n");
			}
		}
		putchar(c);
		basis[i] = c;
		i++;
	}
	basis[i] = '\0';
	putchar('\n');

	printf("Read-in text: %s\n", basis);

	free(basis);
	return 0;
}
