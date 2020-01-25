#include<stdio.h>

int main(){
	int count = 0;
	double sum = 0;
	double input;
	int res;
	
	res = scanf("%lf", &input);
	while(res != EOF){
		if((res != 1)){
			printf("Fehler bei der Einabe\n");
			break;
		} else {
			count++;
			sum+= input;
		}
		res = scanf("%lf", &input);
	}
	if(count > 0)	
		printf("Lösung: %lf\n", sum / count);
	return 0;
}
