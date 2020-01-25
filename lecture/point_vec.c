#include <stdio.h>

int main(){

	char laenge = 4;
	char *vec[laenge];

	char *a = "Eins";
	char *b = "Zwei";
	char *c = "Drei";
	char *d = "Vier";
	int i = 0;

	vec[0] = a;
	vec[1] = b;
	vec[2] = c;
	vec[3] = d;

	while(i < laenge){
		printf("%s\n", vec[i]);
		++i;
	}

}
