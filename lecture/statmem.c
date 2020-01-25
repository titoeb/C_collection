#include <stdio.h>

void eins();
void zwei();
void drei();

int main(){
	int a = 4;
	int b = 96;
	char blubb[31];

	printf("MAIN! \n");
	printf("Adresse von a: \t \t %lu \n", (long unsigned) &a);
	printf("Adresse von b: \t \t %lu \n", (long unsigned) &b);
	printf("Adresse von c: \t \t %lu \n", (long unsigned) &blubb);

	eins();
	drei();
}



void eins(){

	int a = 4;
	int b = 96;
	char blubb[31];

	printf("Eins! \n");
	printf("Adresse von a: \t \t %lu \n", (long unsigned) &a);
	printf("Adresse von b: \t \t %lu \n", (long unsigned) &b);
	printf("Adresse von c: \t \t %lu \n", (long unsigned) &blubb);
	zwei();
	return;
}
void zwei(){
	int a = 4;
	int b = 96;
	char blubb[31];

	printf("Zwei! \n");
	printf("Adresse von a: \t \t %lu \n", (long unsigned) &a);
	printf("Adresse von b: \t \t %lu \n", (long unsigned) &b);
	printf("Adresse von c: \t \t %lu \n", (long unsigned) &blubb);

	
	return;

}
void drei(){
	int a = 4;
	int b = 96;
	char blubb[31];

	printf("Drei! \n");
	printf("Adresse von a: \t \t %lu \n", (long unsigned) &a);
	printf("Adresse von b: \t \t %lu \n", (long unsigned) &b);
	printf("Adresse von c: \t \t %lu \n", (long unsigned) &blubb);
	return;

}

