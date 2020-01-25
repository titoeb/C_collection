#include<stdio.h>

int main(){
	int num;
	int res = scanf("%d", &num);
	while( (res != EOF) & (res == 1)){
		if(num < 0)
			break;
		printf("OKT: %o HEX: %x\n", num, num);
		res = scanf("%d", &num);
	}
	return 0;
}
