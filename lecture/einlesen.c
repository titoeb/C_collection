#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Adresse{
	int plz;
	int hausnr;
	char strasse[32];
	char ort[32];
	char staat[32];
}

struct Student{
	int matrikenummer;
	char vorname[32];
	char nachname[32];
	struct Adresse addrs;
	struct Student *freund;
}

int getStudents(struct Student studenten[], int maximum);
void printStudents(struct Student studenten[], int anzahl);

int main(){
	int max = 16;
	int anzahl = 0;
	struct Student studenten[max];	
	anzahl = getStudents(studenten, max);
	if(anzahl < 0){
		printf("ABORT!\n");
		return -1;
	} else {
		printStudents(studenten, anzahl);		
	}
	return 0;
}


int getStudents(struct Student studenten[], int maximum){

	FILE *dateiZeiger = fopen("Datenbank.txt", "r");
	int lines = 0;
	if(dateiZeiger == NULL){
		printf("Datei nicht gefunden!");
		return -1;
	}
	while(!feof(dateiZeiger) && lines < maximum){
		fscanf(dateiZeiger, "%s %s %d %s %s %s", student[lines.vorname], );
		++lines;
	}
}
	
