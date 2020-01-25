#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned long long ull;

ull Fibnumber(ull n){
	if (n == 0)
		return (unsigned long long) 0;
	if (n == 1)
 		return (unsigned long long) 1;
        
	ull past = 0; 
   	ull current = 1;
        ull tmp;
	for(int i = 2; i <= n; i++){
		tmp = current;		
		current = current + past;
		past = tmp;
	}
	return current;
}
unsigned long long* productFib(ull prod) {
	ull n = 0;
	ull fib1 = 0;
	ull fib2 = 0;
	while ((fib1 * fib2) < prod){
		fib1 = Fibnumber(n);
		fib2 = Fibnumber(n + 1);
		n++;
	}
   	ull* result = malloc(sizeof(ull) * 3);
	result[0] = fib1;
	result[1] = fib2;
	result[2] = (fib1 * fib2 == prod);
 return result;
}

int main(){
	for(ull i = 0; i < 40; i++){
		printf("%lld ", Fibnumber(i));
	}
	printf("\n");
	ull *result = productFib(89 * 144 - 3);
	printf("%lld, %lld, %lld\n", result[0], result[1], result[2]);
}
