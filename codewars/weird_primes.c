#include<stdio.h>
#include<stdlib.h>
#include<string.h>


long long gcd(long long a, long long b){
	if(b == ((long long) 0))
		return a;
	else
		gcd(b, a % b);
}

long long *a(long long n){
	long long *out = malloc(sizeof(long long) * ((int) n));
	long long pos;
	out[0] = 7;
	for(pos = 2; pos <= n; pos++){
		out[pos - 1] = out[pos - 2] + gcd(pos, out[pos - 2]);	
	}
	return out;
}

long long *g(long long n){
	long long *inter = a(n);
	long long *result = malloc(sizeof(long long) * ((int) n));
	result[0] = 1;
	for(long long i = 0; i < n; i++){
		result[i + 1] =  inter[i + 1] - inter[i];
	}

	free(inter);
	return result;

}
long long countOnes(long long n) {
	long long *res = g(n);
	long long count_ones = 0;	
	for(long long i = 0; i < n; i++){
		if(res[i] == (long long) 0){
			count_ones++;
		}
	}
	return count_ones;
}


int main(){
	printf("The result is: ");
	long long *result = g(25);
	for(long long i = 0; i < 25; i++){
		printf("%lld ", *(result + i));
	}
	
	long long count_ones = 	countOnes(25);
	printf("The number of ones is:");
	printf(" %lld\n", count_ones);
	printf("\n");

	free(result);
}
