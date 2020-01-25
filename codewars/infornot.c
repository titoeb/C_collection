#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long fac(int n){
    if(n == 0){
      return 1;
    } else {
      long long result = 1;
      for (int i = 1; i <= n; i++){
        result *= i;
      }
      return result;
    }
}

double going(int n) {
    printf("n is %d\n", n);
    long double result = 0;
    for(int i = 1; i <= n; i++){
      result += (long double) factorial(i);
    }
    result *= (1.0 / (double) factorial(n));
    return (double) result;
}

int main(int argc, char *argv[]){
	int input = atoi(argv[1]);
	printf("%d: %f\n", input, going(input));
}

