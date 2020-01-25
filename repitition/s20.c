#include<stdio.h>

int days[12] = {31,28,31,30,31,30, 31, 31, 30, 31, 30, 31};


int datum2int(int tag, int monat){
	for(int i = 0; i < (monat - 1); i++){
		tag += days[i];
	}
	return tag;
}

void int2datum(int tage, int* ergebnis){
	int monat = 0;
	while((tage > days[monat])){
		tage = tage - days[monat];
		monat++;
	}
	ergebnis[0] = tage;
	ergebnis[1] = monat + 1;
	return;
}

int main(){
	printf("%d\n", datum2int(11, 2));
	int res[2];
	int2datum(365, res);
	printf("%d %d\n", res[0], res[1]);

	return 0;
}
