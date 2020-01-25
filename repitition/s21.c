#include<stdio.h>

int days[12] = {31,28,31,30,31,30, 31, 31, 30, 31, 30, 31};


int datum2int(int tag, int monat){
	for(int i = 0; i < (monat - 1); i++){
		tag += days[i];
	}
	return tag;
}

void int2datum(int tage, int* ergebnis){
	if(tage <= 0){
		if(tage == 0){
			ergebnis[0] = 31;
			ergebnis[1] = 12;
			return;
		} else {
			int monat = 12;
			while((-tage > days[monat])){
				tage = tage + days[monat];
				monat = monat - 1;
				if(monat == - 1){
					printf("hitting zero!\n");
					 monat = 11;
				}
			} 
			ergebnis[0] = days[monat] + tage;
			ergebnis[1] = monat + 1;
			return;
		}
	}
	int monat = 0;
	while((tage > days[monat])){
		tage = tage - days[monat];
		monat = (monat + 1) % 12;
	} 
	ergebnis[0] = tage;
	ergebnis[1] = monat + 1;
	return;
}

int main(){
	printf("%d\n", datum2int(11, 2));
	int res[2];
	int2datum(-364, res);
	printf("%d %d\n", res[0], res[1]);

	return 0;
}
