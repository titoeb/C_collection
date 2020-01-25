#include<stdio.h>

double abso(long double input){
	if (input < 0)
		return -input;
	else 
		return input;
}

long double U(long double x){
   double past = 0;
   int count = 2;
   long double collect = x;
   long double x_col = x * x;
   while(past != collect){
     past = collect;
     collect += count * x_col;
     count++;
     x_col *= x;
   }
   
   return collect;
}
double solve(double m)
{
	long double val = 0.5;
	long double result;
	long double max = 1;
	long double min = 0;
	int counter = 0;
	printf("input is %f and current estimate is %lf/n", m, result);
	
	while(abso((long double) m - result) > 1e-12){
		result = U(val);
		if(abso((long double) m - result) > 1e-12 ){
			if (result < m){
				min = val;
				val = 0.5 * (val + max);
			} else {
				max = val;
				val = 0.5 *(val + min);
			}
		} else {
			break;
		}
		counter++;
		printf("now its %f, val is %f, min is %f and max is %f\n", result, val, min, max);		
	}

	return (double) val;
	
}

int main(){
	printf("%lf\n", solve(257121));

}
