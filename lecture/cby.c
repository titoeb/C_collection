#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int add(int num1, int num2);

int main(){
int a = 4;
int b = 7;
printf("%d and %d is %d\n", a,b,add(a,b));

}

int add(int num1, int num2){
	return num1 + num2;
}


