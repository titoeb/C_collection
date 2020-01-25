#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	printf("The number of arguments is: %d \n", argc); 
	printf("The first one of them is %s \n",argv[0]);
	
	int i = 0;
	char a[] = "47";
	for (i = 0; i < argc; ++i){
		printf("Argumetnvektor: 1 %s \n", argv[i]);
	}

	printf("Wert von a: %d\n", atoi(a));

	int b = atoi(a);

	printf("Der Wert von b: %d\n", b);
	return 0;

}
