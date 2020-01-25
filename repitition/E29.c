#include<stdio.h>



int schaltjahr(int jahr){
	if(jahr % 4 == 0){
		if(jahr % 100 == 0){
			if(jahr % 400 == 0) return 1;
			else return 0;
 		} else return 1;
	} else return 0;
}	 


int datum2int(int tag, int monat, int jahr){
	int days[12] = {31,28,31,30,31,30, 31, 31, 30, 31, 30, 31};
	if (schaltjahr(jahr) == 1){
		days[1] = 29;
	} 
	for(int i = 0; i < (monat - 1); i++){
		tag += days[i];
	}
	return tag;
}

void int2datum(int tage, int jahr, int* ergebnis){
	int days[12] = {31,28,31,30,31,30, 31, 31, 30, 31, 30, 31};
	if (schaltjahr(jahr) == 1){
		days[1] = 29;
	} 
	if(tage <= 0){
		if(tage == 0){
			ergebnis[0] = 31;
			ergebnis[1] = 12;
			ergebnis[2] = jahr - 1;
			
			return;
		} else {
			int monat = 0;
			while((-tage > days[monat])){
				tage = tage + days[monat];
				monat = monat - 1;
				if(monat == - 1){
					printf("hitting zero!\n");
					 monat = 11;
					jahr--;
					if(schaltjahr(jahr) == 1){
						 days[1] = 29;
						printf("%d ist ein Schaltjahr\n", jahr);
					} else {
						days[1] = 28;
						printf("%d ist kein schaltjahr\n", jahr);
					}
				}
			} 
			ergebnis[0] = days[monat] + tage;
			ergebnis[1] = monat + 1;
			ergebnis[2] = jahr;
			return;
		}
	}
	int monat = 0;
	while((tage > days[monat])){
		tage = tage - days[monat];
		monat++;
		if(monat == 12){
			monat = 0;
			jahr++;
			if(schaltjahr(jahr) == 1) days[1] = 29;
			else days[1] = 28;
		}
	} 
	ergebnis[0] = tage;
	ergebnis[1] = monat + 1;
	ergebnis[2] = jahr;
	return;
}

int main(){
	printf("%d\n", datum2int(1, 3, 2000));
	int res[3];
	int2datum(-366, 2001, res);
	printf("%d %d %d\n", res[0], res[1], res[2]);

	return 0;
}
