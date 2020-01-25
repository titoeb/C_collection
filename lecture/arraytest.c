#include<stdio.h>

int main(){
	int laenge = 9;
	int breite = 6;
	int hoehe = 12;
	int a[laenge][breite][hoehe];
	printf("The adress of a is \t\t %p\n", a);
	printf("The adress of a[0] is \t\t %p\n", a[0]);
	printf("The adress of a[0][0] is \t %p\n", a[0][0]);
	printf("The adreess of *a is \t\t %p\n", *a);
	printf("The adresss of **a is \t\t %p\n", **a);
}
