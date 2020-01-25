#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>


struct katze{
	char initialen[3];
	int alter;
	char name[64];
};

int main(){
	struct katze krawall = {"KK", 1, "Krawallo Schnurrito Schmuso der Kuschelige"};
	printf("Groesse der Struktur: %lu\n", sizeof(krawall));

	return 0;	
}
