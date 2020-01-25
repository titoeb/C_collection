#include<stdio.h>
#include<stdlib.h>


int sub(int a, int b);
int mult(int a, int b);
int add(int a, int b);
void printer(char* s);

int main(){
	int a = 93;
	int b = 23;
	int (*funPoint[3])(int, int);
	int (*add_ptr)(int, int) = NULL;
	void (*print_ptr)(char*) = NULL;

	funPoint[0] = &add;
	funPoint[1] = &mult;
	funPoint[2] = &sub;
	for(int i = 0; i < 3; i++){
		printf("Ergebnis direkt: %d \n", funPoint[i](a,b));
	}

	add_ptr = &add;
	print_ptr = &printer;
	printf("%d\n", add(3,4));
	print_ptr("Cool!");	
}

int add(int a, int b){
	return a + b;
}

void printer(char* s){
	printf("%s\n", s);
	return;
}

int sub(int a, int b){
	return a - b;
}
int mult(int a, int b){
	return a*b;
}
