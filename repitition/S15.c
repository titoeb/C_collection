#include<stdio.h>

unsigned long ggT (unsigned long a, unsigned long b){
	if (a >= 0){
		if (b > 0) return ggT(b, a % b);
		if(b == 0) return a;
		else {
			printf("B was negative! Ending execution and returning 0\n");
			return 0;
		}
	} else {
		printf("A was negative! Ending execution and returning 0\n");
		return 0;
	}
}
