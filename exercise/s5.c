#include <stdio.h>

int main(){
	char first = 'A';
	char second = 'z';
	int iter;

	/* Give all releveant chars in one line not separated */
	for(iter = first; iter <= second; ++iter){
	printf("%c", iter);	
	}

	printf("\n");
	return 0;
}
