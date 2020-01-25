#include<stdio.h>


int main(){
	double coef[32];
	double x;
	int pos = 0;
	int res = scanf("%lg", &coef[pos]);
	while(res != EOF){
		pos++;
		res = scanf("%lg", &coef[pos]);
	}
	printf("Bitte stellen zur Auswerung angeben: ");
	scanf("%lg", &x);
	double result;
	if(pos > 1){
		result = coef[pos];
		for(int i = (pos - 1); i >= 0; i--){
			result = coef[i] + x * result;
		}
	} else {
		result = coef[pos - 1];
	}
	printf("Wert des Polynoms an der Stelle %g: %g\n", x, result);
		

	return 0;
}
