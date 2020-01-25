#include<stdio.h>


int permtest(const unsigned int* p, int laenge){
	int count[laenge + 1];

	for(int i = 0; i <= laenge; i++){
		count[i] = 0;		
	}

	for(int i = 0; i < laenge; i++){
		count[p[i]]++;		
	}
	for(int i = 1; i <= laenge; i++){
		if (count[i] == 0){
			return 0;
		}		
	}
	return 1;
}

int main(){
	const unsigned int test[] = {1,5,2,4,3};
	printf("%d\n", permtest(test, 5));
	return 0;
}
