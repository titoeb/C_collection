#include <stdio.h>

int datum2int(int tag, int monat){
	int month[12] = {0,31,28,31,30,31,30,31,31,30,31,30};
	int days = tag;
	for (int iter = 0; iter < monat; ++iter){
		days += month[iter];
	}	
	return days;
}

void int2datum(int tage, int* ergebnis){
	int days = 0;
	int month = 0;
	int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};\
	int sum = 0;
	for (int iter = 0; iter < 12; ++iter){
		sum += month_days[iter];
		month_days[iter] = sum;
	}
	for(month = 1; month <= 12; ++month){
		if(tage <= month_days[month - 1]){
			break;
		}
	}
	if (tage <= 31){
		*ergebnis = tage;
		*(ergebnis + 1) = 1;
	} else {
		*ergebnis = tage - month_days[month - 2];
		*(ergebnis + 1) = month;
	}
}


int main(){
	int res[2];
	int2datum(365, &res[0]);
	printf("%d %d\n", res[0], res[1]);
}
