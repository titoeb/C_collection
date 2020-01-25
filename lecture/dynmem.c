#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *chr_ptr;
	int n = 13;

	chr_ptr = (char *)malloc(sizeof(char) * 64); 
	/* Wir verwenden den sizeof-operator hier damit auch wenn die groesse von char auf verschiedenen Systemen variiert, der Quellcode 	immer noch compiliert. */

	/* Check whether memory allocation did work */
	if(chr_ptr == NULL){
		printf("OUT OF MEMORY FAILURE!!! \n");
		return 1;
	}

	
	strcpy(chr_ptr, "Das hier ist ein super String!");
	printf("Inhalt des Speichers: %s \n", chr_ptr);
	printf("Inhalt an der Stelle %d: %c\n", n , chr_ptr[n]);

	free(chr_ptr);
	return 0;
}
